#ifndef SV_FFMPEG2FILESETTINGS_H
#define SV_FFMPEG2FILESETTINGS_H

#include <QDialog>
#include <QByteArray>
#include <QBuffer>

#include "ui_ffmpeg2filesettings.h"

namespace Ui {
  class SvFFmpeg2FileSettingsDialog;
}

class SvFFmpeg2FileSettings : public QDialog
{
    Q_OBJECT
    
  public:
    explicit SvFFmpeg2FileSettings(void *deviceName,
                                   void *mediaLink,
                                   void *ip,
                                   void *port,
                                   void* settings = 0);
    ~SvFFmpeg2FileSettings();
    
    
  private:
    Ui::SvFFmpeg2FileSettingsDialog *ff2f;
    FFmpegSettings* p_settings;
    QByteArray* p_data;
    int p_parseConfig();
    int p_packConfig();
    
};

#endif // SV_FFMPEG2FILESETTINGS_H
