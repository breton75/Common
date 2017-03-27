#include "sv_rtspwidget.h"
#include <windows.h>
#include <QApplication>
#include "stdlib.h"
#include <QMap>
#include <QDebug>


#undef main

#include "log.h"


extern "C"
{
    #include "SDL.h"

    #define __STDC_CONSTANT_MACROS
    #include "libavcodec/avcodec.h"
    #include "libavformat/avformat.h"
    #include "libavutil/mathematics.h"
    #include "libavutil/mem.h"
    #include "libavutil/pixfmt.h"
    #include "libswscale/swscale.h"
}
struct dt{
    int num_s;
    bool isRunned;
} dat[2];

#pragma pack(push, 1)
struct videoData
{
    QWindow* rtsp_window_vd;
    QWidget* rtsp_widget_vd;
    
//    AVCodecContext* codec_context_vd;
//    AVCodec* codec_vd;
//    AVFormatContext* avfc_vd;
    SDL_Window *window_vd;
//    SDL_Renderer* renderer_vd;
//    SDL_Texture* bmp_vd;
//    SDL_threadID threadID;
//    SDL_Thread* thread;
//    int video_stream_vd;
//    struct SwsContext* img_convert_context_vd;
    bool isPlaying_vd = true;
    bool isFinished_vd = false;
//    AVFrame* frame_vd;
//    AVPacket packet_vd;
    SDL_Event event_vd;
    
    int num_vd;
    
    QString link_vd;
    QString title_vd;
    
    int posX;
    int posY;
    
} vd[32];
#pragma pack(pop)

QMap<int, SDL_Thread*>sdlThrMap;

using namespace log_ns;

SDL_Event ev;
QMap <int, SvDV*> dvMap;
SvDV *dv, *dv2;

SDL_mutex *mutex;

static int test_thr(void *ptr);
static int runVideo(void *ptr);

int yy = 0;

SvRTSPWidget::SvRTSPWidget(QWidget *parent) : QWidget(parent)
{

}

SvRTSPWidget::~SvRTSPWidget()
{
  vd[this->num].isPlaying_vd = false;
  
  SDL_Event evnt;
  while(vd[!this->num].isFinished_vd) SDL_PollEvent(&evnt);
  SDL_DetachThread(sdlThrMap.value(this->num));
  
  SDL_DestroyWindow(vd[this->num].window_vd);
  SDL_Quit();
  
  this->deleteLater();
}

void nulll(){
//QWidget* SvRTSPWidget::CreateWidget(QWidget *parent, QString rtsp_link, QString windowTitle, int posX, int posY, int scale, int num)
//{
////  int err;
////  char* fn = "D:/c++/SDL_2/Atomnij_les_01.mp4";
////  char* fn = "rtsp://169.254.1.90/axis-media/media.amp";
  
////  std::string link2 = QString(link1).toStdString();
////  const char* link = link2.c_str();

////  std::string title2 = QString(title1).toStdString();
////  const char* title = title2.c_str(); // windowTitle.toStdString().c_str();

//  link = rtsp_link;
//  title = windowTitle;  
  
//  this->num = num;
////  log_ns::log(m_Data, QString("thread = %1").arg(this->num));
//  /* ининциализируем SDL */
//  if (SDL_Init(SDL_INIT_VIDEO) != 0){
//    qDebug() <<  "SDL (init error): " + QString(SDL_GetError()) + '\n');  
//    return NULL;
//  }
//  else qDebug() << "init OK");
  
//  av_register_all();
  
//  /* 6 */
////  err = avformat_find_stream_info(avfc, NULL);
////  if (err < 0)
////  {
////    qDebug() << "ffmpeg: Unable to find stream info\n");
////    return NULL;
////  }
////  else qDebug() << "find stream info OK");
  
  
//  /* 7 */
////  SDL_Surface* screen = new SDL_Surface();
////  screen =  SDL_SetVideoMode(codec_context->width, codec_context->height, 0, 0);
  
////  if (screen == NULL) {
////      qDebug() << "Couldn't set video mode\n");
////      return NULL;
////  }
////  else qDebug() << "set video mode OK");
  
//  // Create wndow
////  const char* st = title.toStdString().c_str();
//  window = SDL_CreateWindow(title.toStdString().c_str(),
//                            SDL_WINDOWPOS_UNDEFINED,
//                            SDL_WINDOWPOS_UNDEFINED,
//                            0,
//                            0,
//                            SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE); 
//  if (window == NULL)
//  {
//     qDebug() << QString("Could not create window: %1\n").arg(SDL_GetError()));
//     return NULL;
//  }
//   else qDebug() << "create window OK");
  
//  renderer = SDL_CreateRenderer(window,
//                                -1,
//                                SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//  if (renderer == nullptr)
//  {
//    qDebug() << QString("SDL Create Renderer Error: %1\n").arg(SDL_GetError()));
//    return NULL;
//  }
//  else qDebug() << "SDL_CreateRenderer OK");

//  bmp =  SDL_CreateTexture(renderer,
//                           SDL_PIXELFORMAT_YV12,
//                           SDL_TEXTUREACCESS_STATIC,
//                           640,
//                           480);
  
//  if (bmp == nullptr)
//  {
//    qDebug() << "SDL Create Texture Error: " + QString(SDL_GetError()) + '\n');
//    return NULL;
//  }
//  else qDebug() << "SDL_CreateTexture OK"); 
  
  
//  /******** создаем виджет и пихаем в него окно SDL ************/
  
//  //  WId ww, we;
//////  ww = reinterpret_cast<WId*>(window);          reinterpret_cast<WId>
////  ww = (WId)FindWindow(NULL, L"YUV speed test");
////  we = SDL_GetWindowID(window);
////  log(m_Info, QString("* = %1   _ = %2").arg(ww).arg(SDL_GetWindowID(window)));
  
////  const wchar_t* t = /*(LPCWSTR)*/title.toStdWString().c_str();
  
//  /****************************************************/
//  HWND h = FindWindow(NULL, title.toStdWString().c_str());
//  rtsp_window = QWindow::fromWinId((WId)h);
////  w->setPosition(10, 10);

  
////  ui->widget->
//  rtsp_widget = QWidget::createWindowContainer(rtsp_window, parent);
//  rtsp_widget->setParent(parent);
  
////  wdg->setMinimumSize(100, 100);
//  rtsp_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//  rtsp_widget->setGeometry(posX, posY, 648, 504/*codec_context->width / scale, codec_context->height / scale*/);
//  rtsp_widget->show();


  
//  dat[num].num_s = num;
//  dat[num].isRunned = true;
//  int threadReturnValue;
//  SDL_Thread *thread;
//  void* ptr;
//  ptr = (void*)dat;
//  thread = SDL_CreateThread(test_thr, QString("dsdsds%1").arg(num).toStdString().c_str(), (void*)(&dat[num]));
//  if (NULL == test_thr) {
//      qDebug() << "\nSDL_CreateThread failed: %s" << SDL_GetError();
//  } else {
      
////    SDL_WaitThread(thread, &threadReturnValue);
//      qDebug() << "\nThread returned value: " << /*static_cast<dt*>(*/dat[num].num_s;
//  }
  
//  return rtsp_widget;
  
//  /*******************************************/
  
//  return parent;
  
//}
}

void /*QWidget**/ SvRTSPWidget::CreateWidget(/*QWidget *parent,*/ QString rtsp_link, QString windowTitle, int posX, int posY, int scale, int num)
{
//  int err;
//  char* fn = "D:/c++/SDL_2/Atomnij_les_01.mp4";
//  char* fn = "rtsp://169.254.1.90/axis-media/media.amp";
  
//  std::string link2 = QString(link1).toStdString();
//  const char* link = link2.c_str();

//  std::string title2 = QString(title1).toStdString();
//  const char* title = title2.c_str(); // windowTitle.toStdString().c_str();
//log_ns::log(m_Attention, "~SvRTSPWidget OK");
  vd[num].link_vd = rtsp_link;
  vd[num].title_vd = windowTitle;  
  vd[num].posX = posX;
  vd[num].posY = posY;
  vd[num].num_vd = num;
  this->num = num;
  
//  log_ns::log(m_Data, QString("thread = %1").arg(this->num));
  
  if(!yy)
  {  
    /****************** ининциализируем SDL *********************/
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
      qDebug() <<  "SDL (init error): " + QString(SDL_GetError()) + '\n';  
      return /*NULL*/;
    }
    else qDebug() << "init OK";

    av_register_all();
    
    
    if (!mutex) mutex = SDL_CreateMutex();
    if (!mutex)
    {
      qDebug() << "Couldn't create mutex\n";
      return /*NULL*/;
    }
  }
    
  yy++;
  /******************************************/
  
  /* 6 */
//  err = avformat_find_stream_info(avfc, NULL);
//  if (err < 0)
//  {
//    qDebug() << "ffmpeg: Unable to find stream info\n");
//    return NULL;
//  }
//  else qDebug() << "find stream info OK");
  
  
  /* 7 */
//  SDL_Surface* screen = new SDL_Surface();
//  screen =  SDL_SetVideoMode(codec_context->width, codec_context->height, 0, 0);
  
//  if (screen == NULL) {
//      qDebug() << "Couldn't set video mode\n");
//      return NULL;
//  }
//  else qDebug() << "set video mode OK");
  
  // Create wndow
//  const char* st = title.toStdString().c_str();

  
  /******************************************************/
//  qDebug() << "before create window OK");
    vd[num].window_vd = SDL_CreateWindow(vd[num].title_vd.toStdString().c_str(),
                            posX,
                            posY,
                            320,
                            240,
                            SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE); 
  if (vd[num].window_vd == NULL)
  {
     qDebug() << QString("Could not create window: %1\n").arg(SDL_GetError());
     return /*NULL*/;
  }
   else qDebug() << "create window OK";
  
//  vd[num].renderer_vd = SDL_CreateRenderer(vd[num].window_vd,
//                                -1,
//                                SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//  if (vd[num].renderer_vd == nullptr)
//  {
//    qDebug() << QString("SDL Create Renderer Error: %1\n").arg(SDL_GetError()));
//    return NULL;
//  }
//  else qDebug() << "SDL_CreateRenderer OK");

//  vd[num].bmp_vd =  SDL_CreateTexture(vd[num].renderer_vd,
//                           SDL_PIXELFORMAT_YV12,
//                           SDL_TEXTUREACCESS_STATIC,
//                           640,
//                           480);
  
//  if (vd[num].bmp_vd == nullptr)
//  {
//    qDebug() << "SDL Create Texture Error: " + QString(SDL_GetError()) + '\n');
//    return NULL;
//  }
//  else qDebug() << "SDL_CreateTexture OK"); 
  
  
  /**************************************************************/
  
  
  /******** создаем виджет и пихаем в него окно SDL ************/
  
  //  WId ww, we;
////  ww = reinterpret_cast<WId*>(window);          reinterpret_cast<WId>
//  ww = (WId)FindWindow(NULL, L"YUV speed test");
//  we = SDL_GetWindowID(window);
//  log(m_Info, QString("* = %1   _ = %2").arg(ww).arg(SDL_GetWindowID(window)));
  
//  const wchar_t* t = /*(LPCWSTR)*/title.toStdWString().c_str();
  
  /****************************************************/
//  HWND h = FindWindow(NULL, vd[num].title_vd.toStdWString().c_str());
//  vd[num].rtsp_window_vd = QWindow::fromWinId((WId)h);
////  w->setPosition(10, 10);

  
////  ui->widget->
//  vd[num].rtsp_widget_vd = QWidget::createWindowContainer(vd[num].rtsp_window_vd, parent);
//  vd[num].rtsp_widget_vd->setParent(parent);
  
////  wdg->setMinimumSize(100, 100);
//  vd[num].rtsp_widget_vd->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//  vd[num].rtsp_widget_vd->setGeometry(posX, posY, 320, 240/*codec_context->width / scale, codec_context->height / scale*/);
//  vd[num].rtsp_widget_vd->show();

/*********************************************************/
  

  vd[num].isPlaying_vd = true;
  vd[num].isFinished_vd = false;
  int threadReturnValue;
//  SDL_Thread *thread;
//  void* ptr;
//  ptr = (void*)dat;
  
  
  sdlThrMap.insert(num, SDL_CreateThread(runVideo, QString("dsdsds%1").arg(num).toStdString().c_str(), (void*)(&vd[num])));
  if (NULL == sdlThrMap.value(num)) {
      qDebug() << "\nSDL_CreateThread failed: %s" << SDL_GetError();
  } else {
      
//    vd[num].threadID = SDL_GetThreadID(vd[num].thread);
    qDebug() << "\nThread returned value: " << /*static_cast<dt*>(*/vd[num].num_vd;
  }
  
  
  
  return;
  
//  return vd[num].rtsp_widget_vd;
  
  /*******************************************/
  
//  return parent;
  
}

static int test_thr(void *ptr)
{
  SDL_Event evnt;
  while(static_cast<dt*>(ptr)->isRunned)
  {
    qDebug() << static_cast<dt*>(ptr)->num_s;
    SDL_PollEvent(&evnt);
    SDL_Delay(1000);
  }
}


void SvRTSPWidget::play()
{
  

  dv = new SvDV();
  dv->moveToThread(dv);
//  dv->codec_context = this->codec_context;
//  dv->avfc = this->avfc;
  dv->renderer = this->renderer;
  dv->bmp = this->bmp;
//  dv->video_stream = this->video_stream;
  dv->num = this->num;
  dv->link = this->link;
  dv->title = this->title;  
  
  connect(dv, QThread::finished, dv, &QObject::deleteLater);
//    connect(&thrDecodeRTSP, &QThread::finished, dv, &QObject::deleteLater);
//    thrDecodeRTSP.start();
//  log_ns::log(m_Attention, ));  
  
  qDebug() << "run thread " << (int)dv->thread();
  dv->run();
  
//  dv->start();  
//  qDebug() << "run thread " << (int)dv->thread();
    

/********************************************************************************/
  
//  dvMap.insert(this->num, new SvDV());
////  dvMap.value(this->num)->moveToThread(&thrDecodeRTSP);
////  dvMap.value(this->num)->codec_context = this->codec_context;
////  dvMap.value(this->num)->avfc = this->avfc;
//  dvMap.value(this->num)->renderer = this->renderer;
//  dvMap.value(this->num)->bmp = this->bmp;
////  dvMap.value(this->num)->video_stream = this->video_stream;
//  dvMap.value(this->num)->num = this->num;
//  dvMap.value(this->num)->link = this->link;
//  dvMap.value(this->num)->title = this->title;  
  
////  connect(&thrDecodeRTSP, QThread::finished, dvMap.value(this->num), &QObject::deleteLater);
//  connect(dvMap.value(this->num), QThread::finished, dvMap.value(this->num), &QObject::deleteLater);
  
////  thrDecodeRTSP.start();
////  dvMap.value(this->num)->doWork();
//  dvMap.value(this->num)->run();
}


void SvRTSPWidget::play2()
{
  
  log_ns::log(m_Data, QString("thread = %1").arg(this->num));
  dv2 = new SvDV();
  dv2->moveToThread(dv2);
//  dv->codec_context = this->codec_context;
//  dv->avfc = this->avfc;
  dv2->renderer = this->renderer;
  dv2->bmp = this->bmp;
//  dv->video_stream = this->video_stream;
  dv2->link = this->link;
  dv2->title = this->title;
  dv2->num = this->num;
  
  connect(dv2, QThread::finished, dv2, &QObject::deleteLater);
  
//    connect(&thrDecodeRTSP, &QThread::finished, dv2, &QObject::deleteLater);
//    thrDecodeRTSP.start();
//  log_ns::log(m_Attention, QString("thread %1").arg((int)dv2->thread()));
  
  qDebug() << "run thread " << (int)dv2->thread();
  dv2->run();  

//  dv2->start();  
//  qDebug() << "run thread " << (int)dv2->thread();  
  
//  dvMap.insert(this->num, new SvDV());
////  dvMap.value(this->num)->moveToThread(&thrDecodeRTSP);
////  dvMap.value(this->num)->codec_context = this->codec_context;
////  dvMap.value(this->num)->avfc = this->avfc;
//  dvMap.value(this->num)->renderer = this->renderer;
//  dvMap.value(this->num)->bmp = this->bmp;
////  dvMap.value(this->num)->video_stream = this->video_stream;
//  dvMap.value(this->num)->num = this->num;
//  dvMap.value(this->num)->link = this->link;
//  dvMap.value(this->num)->title = this->title;  
  
////  connect(&thrDecodeRTSP, QThread::finished, dvMap.value(this->num), &QObject::deleteLater);
//  connect(dvMap.value(this->num), QThread::finished, dvMap.value(this->num), &QObject::deleteLater);
  
////  thrDecodeRTSP.start();
////  dvMap.value(this->num)->doWork();
//  dvMap.value(this->num)->run();
}

void SvRTSPWidget::stop()
{
//  if(dv) dv->isPlaying = false;
//  ev.type = SDL_QUIT;
//  SDL_PushEvent(&ev);
//  dvMap.value(this->num)->isPlaying = false;
  
dat[0].isRunned = false;
dat[1].isRunned = false;
  
}


static int runVideo(void *ptr)
{
//  moveToThread(this);
  
  /****************************************************/
  int err;
//qDebug() << "2");  
  // Register all available file formats and codecs 
//  av_register_all();
//qDebug() << "av_register_all OK");
  /*******************************************************/
  
  videoData* vdthr;
//  vdthr = static_cast<videoData*>(ptr);
  vdthr = (videoData*)(ptr);
  
    AVCodecContext* codec_context_vd;
    AVCodec* codec_vd;
    AVFormatContext* avfc_vd;
//    SDL_Window *window_vd;
    SDL_Renderer* renderer_vd;
    SDL_Texture* bmp_vd;
    
//    SDL_Surface* surf_vd;
    
    int video_stream_vd;
    struct SwsContext* img_convert_context_vd;

    AVFrame* frame_vd;
    AVPacket packet_vd; 
    SDL_Event event_vd;
    
//    int num_vd;
  
  
    
  //  QString link_vd;
  //  QString title_vd;
//  if (SDL_Init(SDL_INIT_VIDEO) != 0){
//    qDebug() <<  "SDL (init error): " + QString(SDL_GetError()) + '\n');  
//    return NULL;
//  }
//  else qDebug() << "init OK");
  
//  av_register_all();
  
//  /*vdthr->*/window_vd = SDL_CreateWindow(vdthr->title_vd.toStdString().c_str(),
//                            vdthr->posX,
//                            vdthr->posY,
//                            320,
//                            240,
//                            SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE); 
//  if (/*vdthr->*/window_vd == NULL)
//  {
//     qDebug() << QString("Could not create window: %1\n").arg(SDL_GetError()));
//     return NULL;
//  }
//   else qDebug() << "create window OK");
  
  /*vdthr->*/renderer_vd = SDL_CreateRenderer(vdthr->window_vd,
                                -1,
                                SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (/*vdthr->*/renderer_vd == nullptr)
  {
    qDebug() << QString("SDL Create Renderer Error: %1\n").arg(SDL_GetError());
    return -1;
  }
  else qDebug() << "SDL_CreateRenderer OK";

  /*vdthr->*/bmp_vd =  SDL_CreateTexture(/*vdthr->*/renderer_vd,
                           SDL_PIXELFORMAT_YV12,
                           SDL_TEXTUREACCESS_STATIC,
                           320,
                           240);
  
  if (/*vdthr->*/bmp_vd == nullptr)
  {
    qDebug() << "SDL Create Texture Error: " << QString(SDL_GetError());
    return NULL;
  }
  else qDebug() << "SDL_CreateTexture OK"; 

  /**************************************************************/
  

  
  
  /* открываем ссылку на потоке мультимедиа и заполняем контекст формата */
  /*vdthr->*/avfc_vd = NULL;
//  const char* link2 = link.toStdString().c_str();
  err = avformat_open_input(&(/*vdthr->*/avfc_vd), vdthr->link_vd.toStdString().c_str(), NULL, NULL);
  if (err < 0)
  {
    qDebug() << QString("FFMpeg: Unable to open input file: %1\n").arg(vdthr->link_vd);
    return -1;
  }
  else qDebug() << QString("open input file OK %1").arg(vdthr->link_vd);

  /* ищем информацию о потоке мультимедиа  */
  err = avformat_find_stream_info(/*vdthr->*/avfc_vd, NULL);
  if (err < 0)
  {
    qDebug() << "FFMpeg: Unable to find stream info\n";
    return -1;
  }
  else qDebug() << "find stream info OK";

  
  /*  */
  av_dump_format(/*vdthr->*/avfc_vd, 0, vdthr->link_vd.toStdString().c_str(), 0);
  
  /* ищем первый видеопоток в потоке мультимедиа */
  for (/*vdthr->*/video_stream_vd = 0; /*vdthr->*/video_stream_vd < /*vdthr->*/avfc_vd->nb_streams; ++/*vdthr->*/video_stream_vd)
  {
    if (/*vdthr->*/avfc_vd->streams[/*vdthr->*/video_stream_vd]->codec->codec_type == AVMEDIA_TYPE_VIDEO)
      break;
  }
  
  /* если ни один видео поток не найден, то выходим */
  if (/*vdthr->*/video_stream_vd == /*vdthr->*/avfc_vd->nb_streams)
  {
      qDebug() << "FFMpeg: Unable to find video stream\n";
      return -1;
  }
  else log(m_Success, QString("find video stream OK %1  avfc_vd->nb_streams %2").arg(/*vdthr->*/video_stream_vd).arg(/*vdthr->*/avfc_vd->nb_streams));
  
  /* создаем контекст кодека для выбранного видеопотока, ищем декодер и открываем его */
  /*vdthr->*/codec_context_vd = /*vdthr->*/avfc_vd->streams[/*vdthr->*/video_stream_vd]->codec;
  
  /*vdthr->*/codec_vd = avcodec_find_decoder(/*vdthr->*/codec_context_vd->codec_id);
  qDebug() << "link_vd " << vdthr->link_vd;
  err = avcodec_open2(/*vdthr->*/codec_context_vd, /*vdthr->*/codec_vd, NULL);
  if (err < 0)
  {
    qDebug() << "FFMpeg: Unable to open codec\n";
    return -1;
  }
  else qDebug() << QString(/*vdthr->*/codec_vd->name) + " open codec OK";
  
  /*********************************************************/
  
  
  
//  /*vdthr->*/img_convert_context_vd = sws_getCachedContext(NULL,
//                                             /*vdthr->*/codec_context_vd->width, /*vdthr->*/codec_context_vd->height,
//                                             /*vdthr->*/codec_context_vd->pix_fmt,
//                                             /*vdthr->*/codec_context_vd->width, /*vdthr->*/codec_context_vd->height,
//                                             PIX_FMT_YUV420P, SWS_BICUBIC,
//                                             NULL, NULL, NULL);
//  if (/*vdthr->*/img_convert_context_vd == NULL)
//  {
      
//    qDebug() << "Cannot initialize the conversion context\n";
//    return -1;
//  }
//  else qDebug() << "conversion context OK");
  
  
  
   /* 9 */
//  vdthr->isPlaying_vd = true;
  /*vdthr->*/frame_vd = avcodec_alloc_frame();
  qDebug() << QString("avcodec_alloc_frame");
  while (vdthr->isPlaying_vd & (av_read_frame(/*vdthr->*/avfc_vd, &/*vdthr->*/packet_vd) >= 0))
  {
    
    if (/*vdthr->*/packet_vd.stream_index == /*vdthr->*/video_stream_vd)
    {
      // Video stream packet
      int frame_finished;
      qDebug() << "1111111 ";
      avcodec_decode_video2(/*vdthr->*/codec_context_vd, /*vdthr->*/frame_vd, &frame_finished, &/*vdthr->*/packet_vd);
//      qDebug() << "before avcodec_decode_video2 " << (int)this->thread();
      if (frame_finished)
      {
//        qDebug() << "before SDL_UpdateYUVTexture " << (int)this->thread();
        SDL_UpdateYUVTexture(/*vdthr->*/bmp_vd,
                             NULL,
                             /*vdthr->*/frame_vd->data[0], /*vdthr->*/frame_vd->linesize[0],
                             /*vdthr->*/frame_vd->data[1], /*vdthr->*/frame_vd->linesize[1],
                             /*vdthr->*/frame_vd->data[2], /*vdthr->*/frame_vd->linesize[2]);
//        qDebug() << "after SDL_UpdateYUVTexture ";
      }
//        qDebug() << "before SDL_RenderCopy " << (int)this->thread();

      while(SDL_TryLockMutex(mutex) != 0) SDL_PollEvent(&/*vdthr->*/event_vd);

      SDL_RenderCopy(/*vdthr->*/renderer_vd, /*vdthr->*/bmp_vd, NULL, NULL);
      SDL_RenderPresent(/*vdthr->*/renderer_vd); 
      
      SDL_UnlockMutex(mutex);
//      qDebug() << "SDL 222222 " << (int)this->thread();
//      exec();
//      log_ns::log(m_Data, QString("thread = %1").arg((int)this->thread()));  
    }
     
    // Free the packet that was allocated by av_read_frame
//    qDebug() << "before av_free_packet " << (int)this->thread();
    av_free_packet(&/*vdthr->*/packet_vd);            
  
    
    // Handling SDL events there
//    qDebug() << "before SDL_PollEvent " << (int)this->thread();
   
////    qDebug() << "after SDL_PollEvent " << (int)this->thread();
    if (SDL_PollEvent(&event_vd))
    {
      switch (event_vd.type)
      {
        case (SDL_QUIT | SDL_USEREVENT):
        {  
          vdthr->isPlaying_vd = false;
//          log_ns::log(m_Data, "SDL_QUIT | SDL_USEREVENT");
//          this->~SvRTSPWidget();
          break;
        }
        
        case SDL_FIRSTEVENT:
        {
          
          qDebug() << "SDL_FIRSTEVENT";
          break;         
        }
        
        case SDL_APP_TERMINATING:
        {
          
          qDebug() << "SDL_APP_TERMINATING";
          break;           
        }
    
        case SDL_WINDOWEVENT:
        {
          
//          log_ns::log(m_Data, "SDL_WINDOWEVENT");
          break;           
        }
          
        case SDL_SYSWMEVENT:
        {
          
          qDebug() << "SDL_SYSWMEVENT";
          break;          
        }
    
        case SDL_LASTEVENT:
        {
          
          qDebug() << "SDL_LASTEVENT";
          break;
        }
          
        case SDL_MOUSEBUTTONDOWN:
        {
//          this->isPlaying = false;
          qDebug() << "SDL_MOUSEBUTTONDOWN";
//          this->~SvRTSPWidget();
          break;
        }          
          
      }
    }
    
//    sws_freeContext(img_convert_context_vd);
    avcodec_close(codec_context_vd);
    avformat_close_input(&avfc_vd);
    
    
//    qDebug() << "eventDispatcher " << (int)this->eventDispatcher();
        
  }
  log_ns::log(m_Data, "exit while"); 
  
  while(SDL_TryLockMutex(mutex) != 0) SDL_PollEvent(&/*vdthr->*/event_vd);
  vdthr->isFinished_vd = true;
  SDL_UnlockMutex(mutex);
  
//  exec();
}


void SvDV::run()
{
//  moveToThread(this);
  
  /****************************************************/
  int err;
//qDebug() << "2");  
  // Register all available file formats and codecs 
//  av_register_all();

  /* открываем ссылку на потоке мультимедиа и заполняем контекст формата */
  avfc = NULL;
//  const char* link2 = link.toStdString().c_str();
  err = avformat_open_input(&avfc, link.toStdString().c_str(), NULL, NULL);
  
  if (err < 0)
  {
    qDebug() << QString("FFMpeg: Unable to open input file: %1\n").arg(link);
    return /*NULL*/;
  }
  else qDebug() << "open input file OK";

  /* ищем информацию о потоке мультимедиа  */
  err = avformat_find_stream_info(avfc, NULL);
  if (err < 0)
  {
    qDebug() << "FFMpeg: Unable to find stream info\n";
    return /*NULL*/;
  }
  else qDebug() << "find stream info OK";

  
  /*  */
  av_dump_format(avfc, 0, link.toStdString().c_str(), 0);
  
  /* ищем первый видеопоток в потоке мультимедиа */
  for (video_stream = 0; video_stream < avfc->nb_streams; ++video_stream)
  {
    if (avfc->streams[video_stream]->codec->codec_type == AVMEDIA_TYPE_VIDEO)
      break;
  }
  
  /* если ни один видео поток не найден, то выходим */
  if (video_stream == avfc->nb_streams)
  {
      qDebug() << "FFMpeg: Unable to find video stream\n";
      return /*NULL*/;
  }
  else log(m_Success, "find video stream OK");
  
  /* создаем контекст кодека для выбранного видеопотока, ищем декодер и открываем его */
  codec_context = avfc->streams[video_stream]->codec;
  codec = avcodec_find_decoder(codec_context->codec_id);
  err = avcodec_open2(codec_context, codec, NULL);
  if (err < 0)
  {
    qDebug() << "FFMpeg: Unable to open codec\n";
    return /*NULL*/;
  }
  else qDebug() << QString(codec->name) + " open codec OK";
  
  /*********************************************************/
  
  
  img_convert_context = sws_getCachedContext(NULL,
                                             codec_context->width, codec_context->height,
                                             codec_context->pix_fmt,
                                             codec_context->width, codec_context->height,
                                             PIX_FMT_YUV420P, SWS_BICUBIC,
                                             NULL, NULL, NULL);
  if (img_convert_context == NULL)
  {
      
    qDebug() << "Cannot initialize the conversion context\n";
    return;
  }
  else qDebug() << "conversion context OK";
  
  
  
   /* 9 */
  isPlaying = true;
  frame = avcodec_alloc_frame();
  while (isPlaying & (av_read_frame(avfc, &packet) >= 0))
  {
//    qDebug() << "1111111 " << (int)this->thread();
    if (packet.stream_index == video_stream)
    {
      // Video stream packet
      int frame_finished;
      
      avcodec_decode_video2(codec_context, frame, &frame_finished, &packet);
//      qDebug() << "before avcodec_decode_video2 " << (int)this->thread();
      if (frame_finished)
      {
//        qDebug() << "before SDL_UpdateYUVTexture " << (int)this->thread();
        SDL_UpdateYUVTexture(bmp,
                             NULL,
                             frame->data[0], frame->linesize[0],
                             frame->data[1], frame->linesize[1],
                             frame->data[2], frame->linesize[2]);
//        qDebug() << "after SDL_UpdateYUVTexture " << (int)this->thread();
      }
//        qDebug() << "before SDL_RenderCopy " << (int)this->thread();
      SDL_RenderCopy(renderer, bmp, NULL, NULL);
      SDL_RenderPresent(renderer); 
//      qDebug() << "SDL 222222 " << (int)this->thread();
//      exec();
//      log_ns::log(m_Data, QString("thread = %1").arg((int)this->thread()));  
    }
     
    // Free the packet that was allocated by av_read_frame
//    qDebug() << "before av_free_packet " << (int)this->thread();
    av_free_packet(&packet);            
  
    
    // Handling SDL events there
//    qDebug() << "before SDL_PollEvent " << (int)this->thread();
//    SDL_PollEvent(&event);
////    qDebug() << "after SDL_PollEvent " << (int)this->thread();
//    if (SDL_PollEvent(&event))
//    {
//      switch (event.type)
//      {
//        case (SDL_QUIT | SDL_USEREVENT):
//        {  
//          this->isPlaying = false;
////          log_ns::log(m_Data, "SDL_QUIT | SDL_USEREVENT");
////          this->~SvRTSPWidget();
//          break;
//        }
        
//        case SDL_FIRSTEVENT:
//        {
          
//          log_ns::log(m_Data, "SDL_FIRSTEVENT");
//          break;         
//        }
        
//        case SDL_APP_TERMINATING:
//        {
          
//          log_ns::log(m_Data, "SDL_APP_TERMINATING");
//          break;           
//        }
    
//        case SDL_WINDOWEVENT:
//        {
          
////          log_ns::log(m_Data, "SDL_WINDOWEVENT");
//          break;           
//        }
          
//        case SDL_SYSWMEVENT:
//        {
          
//          log_ns::log(m_Data, "SDL_SYSWMEVENT");
//          break;          
//        }
    
//        case SDL_LASTEVENT:
//        {
          
//          log_ns::log(m_Data, "SDL_LASTEVENT");
//          break;
//        }
          
//        case SDL_MOUSEBUTTONDOWN:
//        {
////          this->isPlaying = false;
//          log_ns::log(m_Data, "SDL_MOUSEBUTTONDOWN");
////          this->~SvRTSPWidget();
//          break;
//        }          
          
//      }
//    }
    
    qDebug() << "eventDispatcher " << (int)this->eventDispatcher();
        
  } 
  log_ns::log(m_Data, "exit while");  
  
//  exec();
}
