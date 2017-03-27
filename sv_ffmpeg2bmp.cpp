#include "sv_ffmpeg2bmp.h"
#include <QDebug>

SvFFMpeg2BMP::SvFFMpeg2BMP(QString media_path,
                           QString media_name,
                           int width,
                           int height,
                           QString path_to_save_frames)
{
  this->media_path = media_path;
  this->media_name = media_name;
  this->img_width = width;
  this->img_height = height;
  this->path_to_save_frames = path_to_save_frames;
  
//  connect(ffmpg, QThread::finished, ffmpg, &QObject::deleteLater);
//  connect(ffmpg, SIGNAL(sigImgLoaded()), this, SLOT(repaint()));
  this->start();
}

SvFFMpeg2BMP::~SvFFMpeg2BMP()
{
  
}

void SvFFMpeg2BMP::run()
{
  int err;
  QTime tte;
  tte.start();
  
  AVCodecContext* codec_context;
  AVCodec* codec;
  AVFormatContext* avfc = NULL;

  int video_stream;
  SwsContext *img_convert_ctx;
  
  AVFrame *origin_frame; // исходный кадр
  AVFrame *scaled_frame; // кадр после преобразования формата и размера
  AVPacket packet; 
//  qDebug() << "before av_register_all  elapsed " << tte.elapsed();
  av_register_all();
//  qDebug() << "after av_register_all  elapsed " << tte.elapsed();
//  av_log_set_level(AV_LOG_QUIET);
  
  /* подключаемся к источнику видео */
  err = avformat_open_input(&avfc, media_path.toUtf8(), NULL, NULL);
  if (err < 0)
  {
    qDebug() << QString("FFMpeg: Unable to open: %1\n").arg(media_path);
    return;
  }
//  else qDebug() << QString("open input OK %1").arg(media_path) << "  elapsed " << tte.elapsed();

  /* ищем информацию о потоке мультимедиа  */
  err = avformat_find_stream_info(avfc, NULL);
  if (err < 0)
  {
    qDebug() << "FFMpeg: Unable to find stream info\n";
    return;
  }
//  else qDebug() << "find stream info OK  elapsed " << tte.elapsed();

  
  /*  */
//  av_dump_format(avfc, 0, media_path.toUtf8(), 0);
  
  /* ищем первый видеопоток в потоке мультимедиа */
  for (video_stream = 0; video_stream < avfc->nb_streams; ++video_stream)
  {
    if (avfc->streams[video_stream]->codec->codec_type == AVMEDIA_TYPE_VIDEO)
      break;
  }
//  qDebug() << "video_stream found  elapsed " << tte.elapsed();
  
  /* если ни один видео поток не найден, то выходим */
  if (video_stream == avfc->nb_streams)
  {
      qDebug() << "FFMpeg: Unable to find video stream\n";
      return;
  }
  else log_ns::log(m_Success, QString("find video stream OK %1  avfc->nb_streams %2").arg(video_stream).arg(/*vdthr->*/avfc->nb_streams));
  
  /* создаем контекст кодека для выбранного видеопотока, ищем декодер и открываем его */
  codec_context = avfc->streams[video_stream]->codec;
//  qDebug() << "codec_context  elapsed " << tte.elapsed();
  
  /* ищем и открываем декодер */
  codec = avcodec_find_decoder(codec_context->codec_id);
  err = avcodec_open2(codec_context, codec, NULL);
  if (err < 0)
  {
    qDebug() << "FFMpeg: Unable to open codec\n";
    quit();
  }
//  else qDebug() << QString(codec->name) + " open codec OK";
/* ЙУХХХХХХХУУУУУУ!!!!!!!!!!!!!*/
  /*********************************************************/
  
  int w = this->img_width  == 0 ? codec_context->width  : this->img_width;
  int h = this->img_height == 0 ? codec_context->height : this->img_height;

  
  img_convert_ctx = 0;
  
  /* готовим буферы для кадров */
  origin_frame = avcodec_alloc_frame();
  scaled_frame = avcodec_alloc_frame();
  
  avpicture_fill((AVPicture *)scaled_frame,  /*AV_PIX_FMT_YUVJ420P */
                 new uint8_t[avpicture_get_size(AV_PIX_FMT_RGB32, w, h)],
                 AV_PIX_FMT_RGB32, //  AV_PIX_FMT_YUVJ420P  AV_PIX_FMT_RGB32 
                 w,
                 h);
  qDebug() << "avpicture_fill  elapsed " << tte.elapsed();
  
  isPlaying = true;
  
  /* имя файла в который будет производиться запись.
     по истечении 1 часа записи имя файла изменяется */
  QString filename;
  
  /* определяем переменные для работы с данными */
  FILE *fout;
  FF2BMPFileHeader file_header;
  FF2BMPFrameHeader frame_header;
  time_t t;    
  
  frame_number = 0;
  
  while (isPlaying & (av_read_frame(avfc, &packet) >= 0))
  {
    
    if (packet.stream_index == video_stream)
    {
      int frame_finished;
      
      qDebug() << "before avcodec_decode_video2  elapsed " << tte.elapsed();
      avcodec_decode_video2(codec_context, origin_frame, &frame_finished, &packet);
//      qDebug() << "after avcodec_decode_video2  elapsed " << tte.elapsed();
      
      if (frame_finished)
      {
        
//        qDebug() << QString("pix_fmt = %1").arg(codec_context->pix_fmt);
        
        /* преобразуем кадр в формат bmp и к нужному размеру */
        img_convert_ctx = sws_getCachedContext(img_convert_ctx,
                                               codec_context->width,
                                               codec_context->height,
                                               codec_context->pix_fmt,
                                               w,
                                               h,
                                               AV_PIX_FMT_RGB32, /*AV_PIX_FMT_YUVJ420P,*/
                                               SWS_BICUBIC, // BICUBIC,
                                               NULL,
                                               NULL,
                                               NULL);
//        qDebug() << "img_convert_ctx  elapsed " << tte.elapsed();
        
        
        sws_scale(img_convert_ctx,
                  origin_frame->data,
                  origin_frame->linesize,
                  0,
                  codec_context->height,
                  scaled_frame->data,
                  scaled_frame->linesize);
        qDebug() << "sws_scale  elapsed " << tte.elapsed();
        
        /* если прошел 1 час записи, то записываем количество кадров,
           и закрываем текущий файл, чтобы открыть новый */
        if(timer.elapsed() >= 3600000)
        {
          fseek(fout, sizeof(file_header.header), 0);
          fwrite(&frame_number, sizeof(frame_number), 1, fout);
          fclose(fout);
          frame_number = 0;
          frame_header.frameTime = 0;
        }
        
        /* если это первый кадр, то сначала открываем файл, и пишем заголовок файла */
        if(!frame_number)
        {
          /* открываем файл для записи */
          filename = path_to_save_frames + QString("%1_%2").arg(media_name).arg(QDateTime::currentDateTime().toString("ddMMyy_hhmmss.zzz")) + ".ff2bmp";
          
          /* формируем заголовок файла */
          time(&file_header.beginTime);
          file_header.framesCount = 0;
          
          fout = fopen(filename.toUtf8(), "wb");
          fwrite(&file_header, sizeof(file_header), 1, fout);
          
          timer.restart();
        }
        
        /* пишем данные кадра */
        
        
        time(&t);
        if(t > frame_header.frameTime)
        {
          frame_number++;
          
          /* формируем описание кадра */
          frame_header.frameNumber = frame_number;
          frame_header.frameWidth = w;
          frame_header.frameHeight = h; 
          frame_header.frame_size = w * h * 4;
          time(&frame_header.frameTime);
          
          /* пишем заголовок кадра и сам кадр */
          fwrite(&frame_header, sizeof(frame_header), 1, fout);
          fwrite(scaled_frame->data[0], frame_header.frame_size, 1, fout);
        }        
//        isPlaying = false;

      }

    av_free_packet(&packet); 
    
  }
}
    
/* если произошел сбой и запись прервалась не пользователем,
 * то пишем в заголовок файла время прерывания записи,
 * и закрываем файл */
if(isPlaying)
{
  if(fout)
  {
    fseek(fout, 8, 0);
    fwrite(&frame_number, sizeof(frame_number), 1, fout);
    
    time_t t;
    time(&t);
    fseek(fout, 20, 0);
    fwrite(&t, sizeof(t), 1, fout);
    fclose(fout);
  }
}
/* если запись остановил пользователь, то пишем в 
 * заголовок файла время остановки записи и закрываем файл */
else
{
  if(fout)
  {
    fseek(fout, 8, 0);
    fwrite(&frame_number, sizeof(frame_number), 1, fout);
    
    time_t t;
    time(&t);
    fseek(fout, 16, 0);
    fwrite(&t, sizeof(t), 1, fout);
    fclose(fout);
  }
}
   
  
//free(&FF2BMPFileHeader);
//free(&FF2BMPFrameHeader);

log_ns::log(m_Data, "finished");

exec();
  
}
