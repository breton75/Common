/* 
 * модуль для работы с источниками медиа по протоколу RTSP
 * 
 * протокол обмена RTSP
 * RFC: Real Time Streaming Protocol (RTSP)
 * http://tools.ietf.org/html/rfc2326#page-14 
 * 
 * данные сессии SDP
 * sv_sdpparser.h
 * RFC: SDP: Session Description Protocol
 * https://tools.ietf.org/html/rfc4566#section-5.13 
 * 
*/

#include "sv_rtspclient.h"
#include "sv_sdpparser.h"

SvRTSPClient::SvRTSPClient(QString ip,
                           quint16 port,
                           QString rtsp_link,
                           QString file_save_path,
                           quint16 first_client_port,
                           quint16 last_client_port,
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
  this->first_client_port = first_client_port;
  this->last_client_port = last_client_port;

}

SvRTSPClient::~SvRTSPClient()
{
//  if(loader) this->loader->deleteLater();
  this->deleteLater();
}

int SvRTSPClient::start()
{
// timeWatcher = QTime(0, 0, 0);
 this->rtsp_sequence = 0;
 
 this->tcp = new SvTcpClient(this->ip,
                             this->port);
 
 connect(this, SIGNAL(sig_options()), SLOT(do_options()));
 connect(this, SIGNAL(sig_describe()), SLOT(do_describe()));
 connect(this, SIGNAL(sig_setup()), SLOT(do_setup()));
 connect(this, SIGNAL(sig_play()), SLOT(do_play()));
 connect(this, SIGNAL(sig_stop()), SLOT(do_stop()));  
 
 
 this->udp = new QUdpSocket();
 this->udp->bind(/*QHostAddress(this->ip), */this->first_client_port);
 
 connect(this->udp, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));

 emit sig_options(); 
 
 return 0;

}

/************* получаем поток ******************/

void SvRTSPClient::readPendingDatagrams()
{
//  qDebug() << "1111:  " << this->file_name_format;
  QByteArray readBuffer;
//  QDataStream out(this->file);
  QTime timeWatcher;
  
  while (this->udp->hasPendingDatagrams())
  {
    qDebug() << "timeWatcher.elapsed() " << timeWatcher.elapsed() << " this->msec_duration " << this->msec_duration;
    if(/*this->*/timeWatcher.elapsed() > this->msec_duration)
    {
      this->file->close();
      free(this->file);
      this->new_file = true;    
    }
      
    if(this->new_file)
    {
     qDebug() << "readPendingDatagrams";
      QString fname = QDir(this->file_save_path).canonicalPath() + "/" + this->file_name_format;
      qDebug() << this->file_name_format;
//      fname = this->file_name_format;
      fname = fname.replace("<DATETIME>", QDateTime::currentDateTime().toString(this->datetime_format));
      fname = fname.replace("<DEVICE_NAME>", this->device_name);
      fname = fname.replace("<USER_NAME>", this->user_name);
      fname = fname.replace("<CODEC>", this->rtsp_codec);
      fname = fname + ".varc";
      qDebug() << fname;
      this->file = new QFile(fname);
      if(!this->file->open(QIODevice::WriteOnly| QIODevice::Append))
        return;
      
      this->new_file = false;
      /*this->*/timeWatcher.restart();
    }
    
    readBuffer.resize(this->udp->pendingDatagramSize());
    udp->readDatagram(readBuffer.data(), udp->pendingDatagramSize());
    this->file->write(readBuffer);

    emit this->sigDataReceived();
    
  }
}

void SvRTSPClient::do_options()
{
  /*************** отправляем OPTIONS  **************/
  QString line;
  QString response = "";
  qDebug() << "do_options 1";
  if (!this->tcp->connected)
  {
    int err = this->tcp->connectToHost();  
    if(err != SOCKET_OK)
    {
      emit sigConnectionError(err);
      return;
    }
  }
  
  /*************** формируем команду ****************/

  this->rtsp_sequence++;
  
  line = line = "OPTIONS <RTSP_URL> RTSP/1.0<CRLF>CSeq: <SEQ><CRLF>User-Agent: VLC media player (LIVE555 Streaming Media v2009.04.20)<CRLF><CRLF>";
  line = line.replace(QString("<CRLF>"), QString("\r\n"));
  line = line.replace(QString("<RTSP_URL>"), this->rtsp_link);
  line = line.replace(QString("<SEQ>"), QString("%1").arg(this->rtsp_sequence));
  
  /*************** отправляем команду ****************/
  this->statusInfo.append(line + "\r\n");
  this->tcp->sendData(line, 5000);
  if(this->tcp->responseStatus != SOCKET_OK)
  {
    emit sigConnectionError(this->tcp->responseStatus);
    return;
  }
  qDebug() << "do_options 2";
  /************* запоминаем ответ *****************/
  response = "";
  response.append(this->tcp->responseData);
  this->statusInfo.append(response + "\r\n");

  emit this->sig_describe();
  
  
}

void SvRTSPClient::do_describe()
{
  /*************** отправляем DESCRIBE *****************/
  QString line;
  QString response = "";
  qDebug() << "do_describe 1";
  this->rtsp_sequence++;
  
  line = "DESCRIBE <RTSP_URL> RTSP/1.0<CRLF>CSeq: <SEQ><CRLF>Accept: application/sdp<CRLF>User-Agent: VLC media player (LIVE555 Streaming Media v2009.04.20)<CRLF><CRLF>";
  line = line.replace(QString("<CRLF>"), QString("\r\n"));
  line = line.replace(QString("<RTSP_URL>"), this->rtsp_link);
  line = line.replace(QString("<SEQ>"), QString("%1").arg(this->rtsp_sequence));
  
  /*************** отправляем команду ****************/
  this->statusInfo.append(line + "\r\n");
  this->tcp->sendData(line, 5000);
  if(this->tcp->responseStatus != SOCKET_OK)
  {
    emit sigConnectionError(this->tcp->responseStatus);
    return;
  }

  response.append(this->tcp->responseData);
  this->statusInfo.append(response + "\r\n");
  qDebug() << "do_describe 2";
  /********* парсим ответ SDP (Session Description Protocol) ********/
  
  /* готовим список источников медиа */
  QList<SDP_DESCRIBE> *medialst = new QList<SDP_DESCRIBE>();
  
  /* парсим источники медиа и заполняем список */
  int i = parseSDP_DESCRIBE(response, medialst);
  
  /* если код не равен 200 ОК, то выходим с ошибкой */
  if(i != 200)
  {
    //emit sig...
    return;
  }
  
  /* если источники медиа не найдены, то выходим с ошибкой */
  if(!medialst->count())
  {
    //emit sig...
    return;
  }
  
  /* если источников медиа больше одного, то показываем диалог выбора */
  if(medialst->count() > 1)
  {
    //show dialog
    i = 0; // selected item index
  }
  else i = 0;
  
  this->rtsp_track_id = medialst->at(i).TrackID;
  this->rtsp_transport_protocol = medialst->at(i).Protocol;
  this->rtsp_codec = medialst->at(i).Codec;
  
  emit this->sig_setup();

  
}

void SvRTSPClient::do_setup()
{  
  /*************** отправляем SETUP  **************/
  QString line;
  QString response = "";
  qDebug() << "do_setup 1";
  this->rtsp_sequence++;
  line = "SETUP <RTSP_URL>/<TRACK> RTSP/1.0<CRLF>CSeq: <SEQ><CRLF>Transport: <TRANSPORT><CRLF>User-Agent: VLC media player (LIVE555 Streaming Media v2009.04.20)<CRLF><CRLF>";
  line = line.replace(QString("<CRLF>"), QString("\r\n"));
  line = line.replace(QString("<RTSP_URL>"), this->rtsp_link);
  line = line.replace(QString("<SEQ>"), QString("%1").arg(this->rtsp_sequence));
  line = line.replace(QString("<TRACK>"), this->rtsp_track_id);
  line = line.replace(QString("<TRANSPORT>"), QString("%1;unicast;client_port=%2-%3")
                                                      .arg(this->rtsp_transport_protocol)
                                                      .arg(this->first_client_port)
                                                      .arg(this->last_client_port));
  
  /*************** отправляем команду ****************/
  this->statusInfo.append(line + "\r\n");
  this->tcp->sendData(line, 5000);
  if(this->tcp->responseStatus != SOCKET_OK)
  {
    emit sigConnectionError(this->tcp->responseStatus);
    return;
  } 
  
  /********* парсим ответ SDP (Session Description Protocol) ********/
  response.append(this->tcp->responseData);
  this->statusInfo.append(response + "\r\n");
  
  /* парсим ответ, вытаскиваем идентификатор сессии */
  SDP_SETUP* sdp = new SDP_SETUP;
  int i = parseSDP_SETUP(response, sdp);
  
  /* если код не равен 200 ОК, то выходим с ошибкой */
  if(i != 200)
  {
    //emit sig...
    return;
  }

  this->rtsp_session_id = sdp->Session;
  this->first_server_port = sdp->FirstServerPort;
  this->last_server_port = sdp->LastServerPort;
  
  qDebug() << "do_setup 2";
  emit this->sig_play();
  
  
}

void SvRTSPClient::do_play()
{
  /* начинаем трансляцию */
  QString line;
  QString response = "";
  qDebug() << "do_play 1";
  this->rtsp_sequence++;
  line = "PLAY <RTSP_URL>/<TRACK> RTSP/1.0<CRLF>CSeq: <SEQ><CRLF>Session: <SESSION><CRLF>Range: npt=0.000-<CRLF>User-Agent: VLC media player (LIVE555 Streaming Media v2009.04.20)<CRLF><CRLF>";
  line = line.replace(QString("<CRLF>"), QString("\r\n"));
  line = line.replace(QString("<RTSP_URL>"), this->rtsp_link);
  line = line.replace(QString("<SEQ>"), QString("%1").arg(this->rtsp_sequence));
  line = line.replace(QString("<SESSION>"), this->rtsp_session_id);
  line = line.replace(QString("<TRACK>"), this->rtsp_track_id);
  
  /*************** отправляем команду ****************/
  this->statusInfo.append(line + "\r\n");
  this->tcp->sendData(line, 5000);
  if(this->tcp->responseStatus != SOCKET_OK)
  {
    emit sigConnectionError(this->tcp->responseStatus);
    return;
  } 
  
  /********* парсим ответ SDP (Session Description Protocol) ********/
  response.append(this->tcp->responseData);
  this->statusInfo.append(response + "\r\n");
  
  qDebug() << "do_play 2";
  
//  UdpSocketConnection *us;
  
//  us = new UdpSocketConnection(0, 2590, ui->sbStreamCount->value());
////  QIODevice dev(us->out->device());

////  SC->nolog = true;
//  SC->send_command(line, true, answ);
  
//  QString str = read_text_from_data(SC->data);  
//  QString marker = "RTP-Info: url=";
//  int i = str.indexOf(marker);
//  if ((i == -1) | (str == ""))
//  { 
//    log(m_Fail, "Wrong answer");  
//    return;
  }

  void SvRTSPClient::do_stop()
  {
    /* останавливаем трансляцию */
    QString line;
    QString response = "";
    
    this->rtsp_sequence++;
    line = "TEARDOWN <RTSP_URL>/<TRACK> RTSP/1.0<CRLF>CSeq: <SEQ><CRLF>Session: <SESSION><CRLF>User-Agent: VLC media player (LIVE555 Streaming Media v2009.04.20)<CRLF><CRLF>";
    line = line.replace(QString("<CRLF>"), QString("\r\n"));
    line = line.replace(QString("<SEQ>"), QString("%1").arg(this->rtsp_sequence));
    line = line.replace(QString("<SESSION>"), this->rtsp_session_id);
    line = line.replace(QString("<TRACK>"), this->rtsp_track_id);
    
    /*************** отправляем команду ****************/
    this->tcp->sendData(line, 5000);
    if(this->tcp->responseStatus != SOCKET_OK)
    {
      emit sigConnectionError(this->tcp->responseStatus);
      return;
    } 
    
    /********* парсим ответ SDP (Session Description Protocol) ********/
    response.append(this->tcp->responseData);
    this->statusInfo.append(response + "\r\n");
    
    
    
  }
