
/****************************************************
 *                   SvFFmpeg2File                  *
 * **************************************************/

#include "sv_ffmpeg2file.h"
#include "log.h"
#include <time.h>

using namespace log_ns;

extern "C"
{
//    #define __STDC_CONSTANT_MACROS
    #include "libavcodec/avcodec.h"
    #include "libavformat/avformat.h"
    #include "libavutil/mathematics.h"
    #include "libavutil/mem.h"
    #include "libavutil/pixfmt.h"
    #include "libswscale/swscale.h"
    #include "libavutil/log.h"
//#include "libavutil/timestamp.h"
}

#undef main;


SvFFmpeg2File::SvFFmpeg2File(QString ip,
                             quint16 port,
                             QString media_link,
                             QString path_to_save_file,
                             QString device_name,
                             QString user_name,
                             QTime file_duaration,
                             QTime total_duration,
                             int reduce_fps,
                             int scale,
                             int codec,
                             QString datetime_format,
                             QString file_name_format,
                             QObject *parent)

{
  this->ip = ip;
  this->port = port;
  this->in_path = media_link;

  this->scale = scale;
  this->codec = codec;
  this->reduce_fps = reduce_fps;
  
  this->path_to_save_file = path_to_save_file;
  this->device_name = device_name;
  this->user_name = user_name; 
  this->datetime_format = datetime_format;
  this->file_name_format = file_name_format;
  
  this->file_duaration = file_duaration;
  this->total_duaration = total_duration;
  
  this->file_duration_sec = file_duaration.hour() * 3600 + 
                             file_duaration.minute() * 60 + 
                             file_duaration.second();
  
  this->total_duration_sec = total_duration.hour() * 3600 + 
                             total_duration.minute() * 60 + 
                             total_duration.second();
  
}

SvFFmpeg2File::~SvFFmpeg2File()
{
  this->deleteLater();
}


void SvFFmpeg2File::run()
{
  AVOutputFormat *ofmt = NULL;
  AVFormatContext *ifmt_ctx = NULL;
  AVFormatContext *ofmt_ctx = NULL;
  AVPacket pkt;
  int64_t last_pts = 0;
  int64_t last_dts = 0;
  int64_t sum_pts = 0;
  int64_t sum_dts = 0;
  time_t fileTimeWatcher;
  time_t totalTimeWatcher;
  quint64 frame_num;
  
  int ret, i;

  av_register_all();
  
  if ((ret = avformat_open_input(&ifmt_ctx, this->in_path.toStdString().c_str(), 0, 0)) < 0) {
    qDebug() << "Could not open input file " << this->in_path;
    goto end;
  }
  
  if ((ret = avformat_find_stream_info(ifmt_ctx, 0)) < 0)
  {
    qDebug() << "Failed to retrieve input stream information";
    goto end;
  }
  
  av_dump_format(ifmt_ctx, 0, this->in_path.toStdString().c_str(), 0);
  
  this->new_file = true;
//  timeWatcher.start();
  totalTimeWatcher = time(NULL);
  fileTimeWatcher = totalTimeWatcher;
  frame_num;
  
  qDebug() << "start playing";
  
  this->isPlaying = true;
  
  /********** получаем пакеты и пишем их в файл ******************/
  while (isPlaying)
  {
     /**** проверяем, задано ли полное время записи *****/
     if(this->total_duration_sec)
     {
    
        /* если задано полное время записи, то           *
        * проверяем не истекло ли полное время записи        *
        * если истекло, то выходим и закрываем текущий файл  */
    
        if(time(NULL) > totalTimeWatcher + this->total_duration_sec)
        {
          log_ns::log(m_Attention, QString("Total time %1 spent")
                                      .arg(this->total_duaration.toString("hh:mm:ss")));
          break;
        }
      }
    
      
    /****** проверяем не истекло ли время записи текущего файла *****/
//    qDebug() << "elapsed " << timeWatcher.elapsed() << "msec" << this->msec_duration;
//    if(timeWatcher.elapsed() > this->msec_duration)
    if(time(NULL) > fileTimeWatcher + this->file_duration_sec)
    {
      av_write_trailer(ofmt_ctx);
      
//      if(this->single_file) break;
      
      sum_pts += last_pts;
      sum_dts += last_dts;
      
      /* close output */
      if (ofmt_ctx && !(ofmt->flags & AVFMT_NOFILE))
          avio_closep(&ofmt_ctx->pb);
      
      avformat_free_context(ofmt_ctx);
      ofmt_ctx = NULL;
      
      this->new_file = true;
      
    }
      
      
    /******** открываем новый файл для записи **********/
    if(this->new_file)
    {      
     
      QString fname = QDir(this->path_to_save_file).canonicalPath() + "/" + this->file_name_format;
      
//      fname = this->file_name_format;
      fname = fname.replace("<DATETIME>", QDateTime::currentDateTime().toString(this->datetime_format));
      fname = fname.replace("<DEVICE_NAME>", this->device_name);
      fname = fname.replace("<USER_NAME>", this->user_name);
      fname = fname.replace("<CODEC>", "h264");
      fname = fname + ".avi";
      
      this->out_file = fname;

      ofmt_ctx = new AVFormatContext();
      avformat_alloc_output_context2(&ofmt_ctx, NULL, NULL, fname.toStdString().c_str());
      if (!ofmt_ctx)
      {
        qDebug() << "Could not create output context\n";
        ret = AVERROR_UNKNOWN;
        goto end;
      }
      qDebug() << this->out_file;

      ofmt = ofmt_ctx->oformat;
      for (i = 0; i < ifmt_ctx->nb_streams; i++)
      {
        AVStream *in_stream1 = ifmt_ctx->streams[i];
        AVStream *out_stream1 = avformat_new_stream(ofmt_ctx, in_stream1->codec->codec);
        if (!out_stream1)
        {
          qDebug() << "Failed allocating output stream\n";
          ret = AVERROR_UNKNOWN;
          goto end;
        }
        
        ret = avcodec_copy_context(out_stream1->codec, in_stream1->codec);
        if (ret < 0)
        {
          qDebug() << "Failed to copy context from input to output stream codec context\n";
          goto end;
        }
        
        out_stream1->codec->codec_tag = 0;
        if (ofmt_ctx->oformat->flags & AVFMT_GLOBALHEADER)
          out_stream1->codec->flags |= CODEC_FLAG_GLOBAL_HEADER;
      }
      
      
      av_dump_format(ofmt_ctx, 0, this->out_file.toStdString().c_str(), 1);
      if (!(ofmt->flags & AVFMT_NOFILE))
      {
        ret = avio_open(&ofmt_ctx->pb, this->out_file.toStdString().c_str(), AVIO_FLAG_WRITE);
        if (ret < 0)
        {
          qDebug() << "Could not open output file " << this->out_file;
          goto end;
        }
      }
      
      ret = avformat_write_header(ofmt_ctx, NULL);
      if (ret < 0)
      {
        qDebug() << "Error occurred when opening output file\n";
        goto end;
      }
      
      
      this->new_file = false;
//      timeWatcher.restart(); 
      fileTimeWatcher = time(NULL);
      frame_num = 0;
      
      log_ns::log(m_Attention, "file recording " + this->out_file);
    }  
      
    /************* записываем данные ****************/
    AVStream *in_stream, *out_stream;
    
    ret = av_read_frame(ifmt_ctx, &pkt);
    if (ret < 0)
    {
      log_ns::log(m_Attention, "translation refused");
      break;
    }
    
    frame_num++;
    
    in_stream  = ifmt_ctx->streams[pkt.stream_index];
    out_stream = ofmt_ctx->streams[pkt.stream_index];
    
    /* если нужно изменить размер или кодек выходного файла */
    if(0)//(in_stream->codec->codec_type == AVMEDIA_TYPE_VIDEO) &&
//       (this->file_codec || (this->file_frame_scale > 1)))
    {
      if(this->codec)
      {
        
        
        /****** пропускаем кадры, если нужно понизить фпс *******/
        if((this->reduce_fps == 1) || ((this->reduce_fps > 1) && !(frame_num%this->reduce_fps)))    
        {
          
        }
      }
    }
      
    else /* пишем пакет без изменений */
    {
//      log_packet(ofmt_ctx, &pkt, "in");
      pkt.pts = av_rescale_q_rnd(pkt.pts,
                                 in_stream->time_base,
                                 out_stream->time_base,
                                 (AVRounding)(AV_ROUND_NEAR_INF
                                              | AV_ROUND_PASS_MINMAX)) - sum_pts;

      
      pkt.dts = av_rescale_q_rnd(pkt.dts,
                                 in_stream->time_base,
                                 out_stream->time_base,
                                 (AVRounding)(AV_ROUND_NEAR_INF 
                                              | AV_ROUND_PASS_MINMAX)) - sum_dts;
                                               
      
      pkt.duration = av_rescale_q(pkt.duration,
                                  in_stream->time_base,
                                  out_stream->time_base);
      
      last_pts = pkt.pts;
      last_dts = pkt.dts;
      
      pkt.pos = -1;
      
    }

      ret = av_interleaved_write_frame(ofmt_ctx, &pkt);
//      qDebug() << "av_interleaved_write_frame" << frame_num;
      
      if (ret < 0) {
        qDebug() << "Error muxing packet\n";
        break;
      }
    
    av_free_packet(&pkt);

  }
  av_write_trailer(ofmt_ctx);
    
end:
  
  avformat_close_input(&ifmt_ctx);
  
  this->isPlaying = false;
  
  /* close output */
  if (ofmt_ctx && !(ofmt->flags & AVFMT_NOFILE))
      avio_closep(&ofmt_ctx->pb);
  
  avformat_free_context(ofmt_ctx);
  
  if (ret < 0 && ret != AVERROR_EOF)
  {
    qDebug() << "Error occurred: " ;//<< av_err2str(ret));
  }  
 
  log_ns::log(m_Data, "finished");
  
  exec();
}

static void log_packet(const AVFormatContext *fmt_ctx, const AVPacket *pkt, const char *tag)
{
    AVRational *time_base = &fmt_ctx->streams[pkt->stream_index]->time_base;
    
    qDebug() << QString("%1: pts_time:%2 dts_time:%3 ctx.den:%4 ctx.num:%5")
              .arg(tag)
              .arg(pkt->pts)
              .arg(pkt->dts)
              .arg(time_base->den)
              .arg(time_base->num)  << '\n';
}
