#include "sv_rtspclient.h"

SvRTSPClient::SvRTSPClient(QString ip,
                           quint16 port,
                           QString rtsp_link,
                           QString file_save_path,
                           QString device_name,
                           QString user_name,
                           QString datetime_format,
                           QString file_name_format,
                           QTime file_duaration,
                           QObject *parent) : 
  QObject(parent)
{
  this->ip = ip;
  this->port = port;
  this->rtsp_link = rtsp_link;
     
  this->file_save_path = file_save_path;
  this->device_name = device_name;
  this->user_name = user_name; 
  this->datetime_format = datetime_format;
  this->file_name_format = file_name_format;
  this->file_duaration = file_duaration;

}

SvRTSPClient::~SvRTSPClient()
{
  if(loader) this->loader->deleteLater();
  this->deleteLater();
}

SvRTSPClient::start()
{
  if(this->loader)
  {
    this->loader->quit();    
    this->loader->~SvRTSPStreamLoader();
  }
  
  this->loader = new SvRTSPStreamLoader(this->ip,
                                        this->port,
                                        this->rtsp_link,
                                        &this->statusInfo,
                                        this->file_save_path,
                                        this->device_name,
                                        this->user_name,
                                        this->datetime_format,
                                        this->file_name_format,
                                        this->file_duaration,
                                        this);
  
  this->loader->start();  
  
}




/************* получаем поток ******************/

SvRTSPStreamLoader::SvRTSPStreamLoader(QString ip,
                                       quint16 port,
                                       QString file_save_path,
                                       QString device_name,
                                       QString user_name,
                                       QString datetime_format,
                                       QString file_name_format,
                                       QTime file_duaration,
                                       QObject *parent)

{
  this->setParent(parent);
  
  this->ip = ip;
  this->port = port;       
  this->file_save_path = file_save_path;
  this->device_name = device_name;
  this->user_name = user_name; 
  this->datetime_format = datetime_format;
  this->file_name_format = file_name_format;
  this->file_duaration = file_duaration;
  this->msec_duration = file_duaration.hour() * 3600000 + 
                        file_duaration.minute() * 60000 + 
                        file_duaration.second() * 1000;
  
  timeWatcher = QTime(0, 0, 0);
  

  
  
}

SvRTSPStreamLoader::~SvRTSPStreamLoader()
{
  this->deleteLater();
}

void SvRTSPStreamLoader::run()
{
  this->rtsp_sequence = 0;
  
  this->tcp = new SvTcpClient(this->ip,
                              this->port);
  
  connect(this, SIGNAL(sig_options()), SLOT(do_options()));
  connect(this, SIGNAL(sig_describe()), SLOT(do_describe()));
  connect(this, SIGNAL(sig_setup()), SLOT(do_setup()));
  connect(this, SIGNAL(sig_play()), SLOT(do_play()));
  connect(this, SIGNAL(sig_stop()), SLOT(do_stop()));  
  
  udp = new QUdpSocket();
  udp->bind(QHostAddress(this->ip), this->port);
  
  connect(this->udp, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));

  emit sig_options();  
  
  exec();
}

void SvRTSPStreamLoader::readPendingDatagrams()
{
  
  QByteArray readBuffer;
//  QDataStream out(this->file);
  
  while (this->udp->hasPendingDatagrams())
  {
    
    if(timeWatcher.elapsed() > this->msec_duration)
    {
      this->file->close();
      free(this->file);
      this->new_file = true;    
    }
      
    if(this->new_file)
    {
      QString fname = QDir(this->file_save_path).canonicalPath();
      fname += this->file_name_format.replace("<DATETIME>", QTime::currentTime().toString(this->datetime_format));
      fname += this->file_name_format.replace("<DEVICE_NAME>", this->device_name);
      fname += this->file_name_format.replace("<USER_NAME>", this->user_name);
      fname += ".varc";
      
      this->file = new QFile(fname);
      if(!this->file->open(QIODevice::WriteOnly| QIODevice::Append))
        return;
      
      this->new_file = false;
      this->timeWatcher.restart();
    }
    
    readBuffer.resize(this->udp->pendingDatagramSize());
    udp->readDatagram(readBuffer.data(), udp->pendingDatagramSize());
    this->file->write(readBuffer);

    emit this->sigDataReceived();
    
  }
}

void SvRTSPStreamLoader::do_options()
{
  /* ПОДКЛЮЧАЕМСЯ К ХОСТУ  */
  if (!this->tcp->connected)
  {
    int err = this->tcp->connectToHost();  
    if(err != SOCKET_OK)
    {
      emit sigConnectionError(err);
      return;
    }
  }
  
  /* НАЧИНАЕМ ОТПРАВКУ КОМАНД */
  QString *response;
  QString line;

  this->rtsp_sequence++;
  line = "OPTIONS <RTSP_URL> RTSP/1.0<CRLF>CSeq: <SEQ><CRLF>User-Agent: VLC media player (LIVE555 Streaming Media v2009.04.20)<CRLF><CRLF>";
  line = line.replace(QString("<CRLF>"), QString("\r\n"));
  line = line.replace(QString("<RTSP_URL>"), this->rt_stream_name);
  line = line.replace(QString("<SEQ>"), QString("%1").arg(this->rtsp_sequence));
  
  SC->send_command(line, true, answ);

  emit this->sig_describe();
}

void MainWindow::do_describe()
{
  // 2 DESCRIBE
  QString *answ;
  QString line;
  
  this->cam_seq++;
  line = "DESCRIBE rtsp://[IP]/[STREAM] RTSP/1.0[CRLF]CSeq: [SEQ][CRLF]Accept: application/sdp[CRLF]User-Agent: VLC media player (LIVE555 Streaming Media v2009.04.20)[CRLF][CRLF]";
  line = line.replace(QString("[CRLF]"), QString("\r\n"));
  line = line.replace(QString("[IP]"), ui->editIp->text());
  line = line.replace(QString("[STREAM]"), ui->editStreamName->text());
  line = line.replace(QString("[SEQ]"), QString("%1").arg(this->cam_seq));
  
  SC->send_command(line, true, answ);
  
  int i;
  QString str = read_text_from_data(SC->data);  
  i = str.indexOf("a=control:*");
  i = str.indexOf("a=control:", i + 11);
  if ((i == -1) | (str == ""))
  { 
    log(m_Fail, "Wrong answer");  
    return;
  }

  this->cam_track_id = str.mid(i + 10, str.indexOf("\r\n", i) - i - 10);
  
  
  emit this->sig_setup();
}
