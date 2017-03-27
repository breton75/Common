#ifndef SVFFMPEG2FILE_H
#define SVFFMPEG2FILE_H

#include <QThread>
#include <QImage>
#include <QWidget>
#include <QTime>
#include <QDateTime>
#include <QDebug>
#include <QDir>

class SvFFmpeg2File: public QThread
{
    Q_OBJECT
    
  public:
    explicit SvFFmpeg2File(QString ip,
                           quint16 port,
                           QString media_link,
                           QString path_to_save_file,
                           QString device_name = "",
                           QString user_name = "",
                           QTime file_duaration = QTime(1, 0, 0), // один час
                           QTime total_duration = QTime(0, 0, 0),
                           int reduce_fps = 1,
                           int scale = 1,
                           int codec = 0,
                           QString datetime_format = "ddMMyy_hhmmss",
                           QString file_name_format = "<DATETIME>_<DEVICE_NAME>_<USER_NAME>_<CODEC>",
                           QObject *parent = 0);
    
    ~SvFFmpeg2File();
    
    QString in_path;
    QString out_file;
    
    QString ip;
    quint16 port;
    
    QString user_name;
//    QString password;
    QString path_to_save_file;
    QString device_name;
    QString datetime_format;
    QString file_name_format;
    
    QTime   file_duaration;
    QTime   total_duaration;
    qint32 file_duration_sec;
    qint32 total_duration_sec;
    
    bool single_file;
    
    int scale;
    int codec;
    int reduce_fps;
    
    bool new_file;
    
    virtual void run() Q_DECL_OVERRIDE;
    
    void stopPlaying() { isPlaying = false; }
    
  signals:
    void NewFile();
    
  private:
    bool isPlaying;
    
//  public slots:
    
};


#endif // SVFFMPEG2FILE_H
