#ifndef SVFFMPEG2BMP_H
#define SVFFMPEG2BMP_H

#include <QThread>
#include <QTime>
#include <time.h> 

#include "log.h"

using namespace log_ns;

extern "C"
{
    #define __STDC_CONSTANT_MACROS
    #include "libavcodec/avcodec.h"
    #include "libavformat/avformat.h"
    #include "libavutil/mathematics.h"
    #include "libavutil/mem.h"
    #include "libavutil/pixfmt.h"
    #include "libswscale/swscale.h"
    #include "libavutil/log.h"
}

#undef main;

#pragma pack(push, 1)
struct FF2BMPFileHeader
{
    char header[8] = "FFM2BMP";
    int framesCount = 0;
    time_t beginTime = 0;
    time_t endTime = 0;
    time_t crashTime = 0;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct FF2BMPFrameHeader
{
    int frameNumber;
    int frameWidth;
    int frameHeight;
    int frame_size;
    time_t frameTime;
};
#pragma pack(pop)

class SvFFMpeg2BMP : public QThread
{
    Q_OBJECT
    
  public:
    explicit SvFFMpeg2BMP(QString media_path,
                          QString media_name,
                          int width,
                          int height,
                          QString path_to_save_frames);
    ~SvFFMpeg2BMP();
    
    QString media_path;
    QString media_name;
    int img_width;
    int img_height;
    
    QTime timer;
    int frame_number;
    
    QString path_to_save_frames;
    
    virtual void run() Q_DECL_OVERRIDE;
    
    void stopPlaying() { isPlaying = false; }
    
  signals:
    void sigImgLoaded();
    
  private:
    bool isPlaying;
    
//  public slots:
    
};

#endif // SVFFMPEG2BMP_H
