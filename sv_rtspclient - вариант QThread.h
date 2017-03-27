#ifndef SVRTSPCLIENT_H
#define SVRTSPCLIENT_H

#include "sv_tcpclient.h"

#include <QObject>
#include <QThread>
#include <QTime>
#include <QStringList>
#include <QUdpSocket>
#include <QFile>
#include <QDir>

class SvRTSPStreamLoader;
class SvRTSPClient : public QObject
{
    Q_OBJECT
  public:
    explicit SvRTSPClient(QString ip,
                          quint16 port,
                          QString rtsp_link = "",
                          QString file_save_path = "",
                          QString device_name = "",
                          QString user_name = "",
                          QString time_format = "ddMMyy_hhmmss",
                          QString file_name_format = "<TIME>_<DEVICE_NAME>_<USER_NAME>",
                          QTime file_duaration = QTime(1, 0, 0), // один час
                          QObject *parent = 0);
    ~SvRTSPClient();
    
    QString ip;
    quint16 port;
    QString rtsp_link;
    
    QString user_name;
//    QString password;
    QString file_save_path;
    QString device_name;
    QString datetime_format;
    QString file_name_format;
    QTime   file_duaration;
    
//    QString rtsp_stream_name;
//    QString rtsp_track_id;
//    quint16 rtsp_sequence;
//    QString rtsp_session_id;
    
    quint16 first_client_port;
    quint16 last_client_port;
    
    QStringList statusInfo;
    
    SvRTSPStreamLoader* loader;
    
    
    
  signals:
    
  public slots:  
    void slotStart();
    void slotStop();

};

class SvRTSPStreamLoader: QThread
{
    Q_OBJECT
    
  public:
    explicit SvRTSPStreamLoader(QString ip,
                                quint16 port,
                                QString rtsp_link,
                                QStringList* statusInfo,
                                QString file_save_path = "",
                                QString device_name = "",
                                QString user_name = "",
                                QString time_format = "ddMMyy_hhmmss",
                                QString file_name_format = "<DATETIME>_<DEVICE_NAME>_<USER_NAME>",
                                QTime file_duaration = QTime(1, 0, 0), // один час
                                QObject *parent = 0);
    
    ~SvRTSPStreamLoader();
    
    QString ip;
    quint16 port = 0;
    QString rtsp_link;
    QString file_save_path = "";
    QString device_name = "";
    QString user_name = "";
    QString datetime_format = "ddMMyy_hhmmss";
    QString file_name_format = "<DATETIME>_<DEVICE_NAME>_<USER_NAME>";
    QTime file_duaration = QTime(1, 0, 0); // 1 час 
    int msec_duration = 3600000; // 1 час
    
    quint16 rtsp_sequence;
    QString rtsp_session_id;
    
    QTime timeWatcher = QTime(0, 0, 0);
    
    QUdpSocket* udp;
    SvTcpClient* tcp;
    
    QFile* file;
    bool new_file = true;
    
    virtual void run(); Q_DECL_OVERRIDE;
    
  signals:
    void sig_options();
    void sig_describe();
    void sig_setup();
    void sig_play();
    void sig_stop();
    
    void sigDataReceived();
    
    void sigConnectionError(int err_code);
    
  public slots:  
    void readPendingDatagrams();
    
    void prepare_to_play();
    void do_options();
    void do_describe();
    void do_setup();
    void do_play();
    void do_stop();
    
};
    

#endif // SVRTSPCLIENT_H
