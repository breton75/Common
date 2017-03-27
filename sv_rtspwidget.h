#ifndef SVRTSPWIDGET_H
#define SVRTSPWIDGET_H

#include "SDL.h"
extern "C"
{
    #define __STDC_CONSTANT_MACROS
    #include "libavcodec/avcodec.h"
    #include "libavformat/avformat.h"
    #include "libavutil/mathematics.h"
    #include "libavutil/mem.h"
    #include "libavutil/pixfmt.h"
    #include "libswscale/swscale.h"
}

#include <QWidget>
#include <QWindow>
#include <QThread>

class SvDV;

class SvRTSPWidget : public QWidget
{
    Q_OBJECT
    QThread thrDecodeRTSP;
    
  public:
    explicit SvRTSPWidget(QWidget* parent = 0);
    ~SvRTSPWidget();
    
    virtual void /*QWidget**/ CreateWidget(/*QWidget* parent,*/ QString rtsp_link, QString windowTitle, int posX, int posY, int scale, int num);
    virtual void play();
    virtual void play2();
    virtual void stop();
    
    
    QWindow* rtsp_window;
    QWidget* rtsp_widget;
    
    SDL_Window* sdl_window;
//    SDL_Thread *thread;
    
    // ffmpeg
    AVFormatContext* avfc;
    AVCodecContext* codec_context;
    int video_stream;
    AVCodec* codec;
    struct SwsContext* img_convert_context;
    AVFrame* frame;
    AVPacket packet;
    
    // SDL
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture* bmp;
    SDL_Event event;
    
    QString link;
    QString title;
    
    
    
    int num;
    
    bool isPlaying = false;
    
    
  signals:
    
  public slots:
};

class SvDV : public QThread
{
    Q_OBJECT
    
  public:
//    explicit SvDV(QObject* parent = 0) { }
    
    AVCodecContext* codec_context;
    AVCodec* codec;
    AVFormatContext* avfc;
    SDL_Renderer* renderer;
    SDL_Texture* bmp;
    int video_stream;
    struct SwsContext* img_convert_context;
    bool isPlaying = true;
    AVFrame* frame;
    AVPacket packet;
    SDL_Event event;
    
    int num;
    
    QString link;
    QString title;
    
    void run();
    
  public slots:
//    void doWork();
    
};

#endif // SVRTSPWIDGET_H
