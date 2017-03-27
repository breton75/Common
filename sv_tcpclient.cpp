#include "sv_tcpclient.h"
#include "log.h"
#include "sv_secondmeter.h"
#include "sv_socket_defs.h"

#include <QApplication>
#include <QByteArray>
#include <QDataStream>
#include <QDebug>
#include <QFuture>
#include <QProgressDialog>
#include <QMessageBox>

using namespace log_ns;

//QTcpSocket* pClientSocket;

SvTcpClient::SvTcpClient(QString ip,
                         quint16 port,
                         QObject *parent) :
  QObject(parent)
{
  this->ip = ip;
  this->port = port;
  
  this->socket = new QTcpSocket(this);
  connect(this->socket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
  connect(this->socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotSocketError(QAbstractSocket::SocketError)));
  connect(this->socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(slotStateChanged(QAbstractSocket::SocketState)));
  
//  log(m_Info, "Clent runned");
  
}

int SvTcpClient::connectToHost()
{
  try
  {
    if (this->ip == "") throw SOCKET_WRONG_IP;
    if (this->port == 0) throw(SOCKET_WRONG_PORT);
    
    if (!this->connected)
      {    
        this->socket->connectToHost(this->ip, this->port);
        if (this->socket->waitForConnected(2000))
          {
            this->connected = true;
            return SOCKET_OK;
          }
        else return SOCKET_BAD_CONNECTION; // throw(SOCKET_BAD_CONNECTION);
      }
    return 0;
  }
 
  catch (int err)
  {
    switch (err)
    {  
      case SOCKET_BAD_CONNECTION:
        log(m_Err, QString("Can not connect to %1:%2\n").arg(this->ip).arg(this->port));
        break;      
      
      case SOCKET_WRONG_IP:
//        qDebug() << "Wrong IP adress\n";
        log(m_Err, "Wrong IP adress\n");
        break;
        
      case SOCKET_WRONG_PORT:
        log(m_Err, "Wrong port\n");
        break;        
    }
    
    return err;
  }
}

void SvTcpClient::disconnectFromHost()
{
  this->socket->disconnectFromHost();
  this->connected  = false;
}

void SvTcpClient::slotSocketError(QAbstractSocket::SocketError err)
{
  switch (err)
  {
    case QAbstractSocket::ConnectionRefusedError:
      log(m_Info, "ConnectionRefusedError");
      this->connected = false;
      QApplication::processEvents();
      break;
      
    case QAbstractSocket::RemoteHostClosedError :
      log(m_Info, QString("RemoteHostClosedError"));
      QApplication::processEvents();
      break;   
      
    case QAbstractSocket::HostNotFoundError :
      log(m_Info, QString("HostNotFoundError"));
      QApplication::processEvents();
      break; 
      
    case QAbstractSocket::SocketAccessError :
      log(m_Info, QString("SocketAccessError"));
      QApplication::processEvents();
      break; 
      
    case QAbstractSocket::SocketResourceError :
      log(m_Info, QString("SocketResourceError"));
      QApplication::processEvents();
      break; 
      
    case QAbstractSocket::SocketTimeoutError :
      log(m_Info, QString("SocketTimeoutError"));
      QApplication::processEvents();
      break; 
      
    case QAbstractSocket::DatagramTooLargeError :
      log(m_Info, QString("DatagramTooLargeError"));
      QApplication::processEvents();
      break; 
      
    case QAbstractSocket::NetworkError :
      log(m_Info, QString("NetworkError"));
      QApplication::processEvents();
      break; 
      
    case QAbstractSocket::AddressInUseError :
      log(m_Info, QString("AddressInUseError"));
      QApplication::processEvents();
      break; 
      
    case QAbstractSocket::SocketAddressNotAvailableError :
      log(m_Info, QString("SocketAddressNotAvailableError"));
      QApplication::processEvents();
      break; 
      
    case QAbstractSocket::UnsupportedSocketOperationError :
      log(m_Info, QString("UnsupportedSocketOperationError"));
      QApplication::processEvents();
      break; 
      
    case QAbstractSocket::UnfinishedSocketOperationError :
      log(m_Info, QString("UnfinishedSocketOperationError"));
      QApplication::processEvents();
      break; 
      
    case QAbstractSocket::ProxyAuthenticationRequiredError :
      log(m_Info, QString("ProxyAuthenticationRequiredError"));
      QApplication::processEvents();
      break; 
      
    case QAbstractSocket::SslHandshakeFailedError :
      log(m_Info, QString("SslHandshakeFailedError"));
      QApplication::processEvents();
      break; 
      
    case QAbstractSocket::ProxyConnectionRefusedError :
      log(m_Info, QString("ProxyConnectionRefusedError"));
      QApplication::processEvents();
      break; 
      
    case QAbstractSocket::ProxyConnectionClosedError :
      log(m_Info, QString("ProxyConnectionClosedError"));
      QApplication::processEvents();
      break; 
      
    case QAbstractSocket::ProxyConnectionTimeoutError :
      log(m_Info, QString("ProxyConnectionTimeoutError"));
      QApplication::processEvents();
      break; 
      
    case QAbstractSocket::ProxyNotFoundError :
      log(m_Info, QString("ProxyNotFoundError"));
      QApplication::processEvents();
      break;
      
    case QAbstractSocket::ProxyProtocolError :  
      log(m_Info, QString("ProxyProtocolError"));
      QApplication::processEvents();
      break; 
      
    case QAbstractSocket::OperationError :
      log(m_Info, QString("OperationError"));
      QApplication::processEvents();
      break; 
      
    case QAbstractSocket::SslInternalError :
      log(m_Info, QString("SslInternalError"));
      QApplication::processEvents();
      break; 
      
    case QAbstractSocket::SslInvalidUserDataError :
      log(m_Info, QString("SslInvalidUserDataError"));
      QApplication::processEvents();
      break;
      
    case QAbstractSocket::TemporaryError :
      log(m_Info, QString("TemporaryError"));
      QApplication::processEvents();
      break; 
      
    case QAbstractSocket::UnknownSocketError :
      log(m_Info, QString("UnknownSocketError"));
      QApplication::processEvents();
      break;

  }
  
  
//  QString strError =
//        "Error: " + (err == QAbstractSocket::HostNotFoundError ?
//                     "The host was not found." :
//                     err == QAbstractSocket::RemoteHostClosedError ?
//                     "The remote host is closed." :
//                     err == QAbstractSocket::ConnectionRefusedError ?
//                     "The connection was refused." :
//                     (QString(this->socket->errorString()) != "" ? QString(this->socket->errorString()) :
//                      QString(this->socket->errorString()))
//                    );
//    log(m_Err, strError);
}

void SvTcpClient::slotStateChanged(QAbstractSocket::SocketState state)
{
  switch (state)
    {
    case QAbstractSocket::UnconnectedState:
      log(m_Info, "No connection");
      this->connected = false;
      QApplication::processEvents();
      break;
      
    case QAbstractSocket::HostLookupState:
      log(m_Info, QString("Looking up for %1").arg(this->ip));
      QApplication::processEvents();
      break;   

    case QAbstractSocket::ConnectingState:
      log(m_Info, QString("Connecting to %1").arg(this->ip));
      QApplication::processEvents();
      break;
      
    case QAbstractSocket::ConnectedState:
      this->connected = true;
      log(m_Info, QString("Connected to %1").arg(this->ip));
      QApplication::processEvents();
      break;

    case QAbstractSocket::BoundState:
      log(m_Info, QString("Bounded for %1:%2").arg(this->ip).arg(this->port));
      QApplication::processEvents();
      break; 
      
    case QAbstractSocket::ClosingState:
      log(m_Info, "Closing connection");
      QApplication::processEvents();
      break;       
  
    default:
      log(m_Info, "state ");// + QString("%1").arg(int(state)));
  }
}

void SvTcpClient::slotReadyRead()
{
  try
  {
    QString str;
    
    if (!this->advancedStream)
    {
      if (this->socket->bytesAvailable() > 0)
      {
        responseData = this->socket->readAll();
      
        if(log_responses)
        {
          for (int i=0; i < responseData.size(); i++)
          {
            if(showSymbols)
            {
              if((responseData.at(i) > 31) || 
                 (responseData.at(i) == 10) || 
                  (responseData.at(i) == 13)) 
                 str = str + responseData.at(i);
              else str = str + char2hex(responseData.at(i)) + " ";
            }
            
            else str = str + char2hex(responseData.at(i));
            
          }
        }
      }
        
      else
      {
        responseSize = 0;
        QDataStream in(this->socket);
        
        in.setVersion(this->streamVersion);/*QDataStream::Qt_5_3*/
        for (;;)
        {
          if (!responseSize)
          {
            if (this->socket->bytesAvailable() < (quint64)sizeof(quint64)) break;
            in >> responseSize;
          }
          if (this->socket->bytesAvailable() < responseSize) break;
    //      QTime   time;
          
          responseData = this->socket->readAll();

          if(log_responses)
          {
            QDataStream in1(responseData);
            in1.setVersion(this->streamVersion);
            in1 >> str;
//            in >> responseData;// /*time >>*/ str;
          }

          responseSize = 0;
        }
      }
    }
    
    if(log_responses) log(m_Data, /*time.toString() + " " +*/ " >> " + str);
    
    emit sigGotNewData();
  }

  catch(...)
  {
    log(m_Err, "slotReadyRead error: ");  
  }
    
}

void SvTcpClient::sendData(QString text, int msecWaitForAnswer, QObject* parent)
{
  QByteArray arrBlock;

  if(!this->advancedStream) arrBlock.append(text);

  else
  {
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(this->streamVersion);/*QDataStream::Qt_5_3*/
    out << quint16(0) /*<< QTime::currentTime()*/ << text;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
  }

  this->socket->write(arrBlock);
  log(m_Data, " << " + text);
  
  if(msecWaitForAnswer == dontWait) return;
  
  /*********************** ждем ответ ***********************/
  this->responseSize = 0;
  this->responseData.clear();
  
  SvSecondMeter *t = new SvSecondMeter(msecWaitForAnswer,
                                       "Waiting for response",
                                       "Cancel",
                                       true,
                                       parent);
  
  connect(this, SIGNAL(sigGotNewData()), t, SLOT(slotDone()));
  
  while((t->status == SvSecondMeter::smsRunned)&&(this->socket->isOpen())) QApplication::processEvents();
  if(!this->socket->isOpen()) t->status = SvSecondMeter::smsUnfinished;
  
  switch (t->status)
  {
    case SvSecondMeter::smsCanceled:
      this->socket->abort();
      log(m_Err, QString("Response awaiting was canceled by user at %1").
            arg(t->current_time.toString("hh:mm:ss")));
      this->responseStatus = SOCKET_AWAITING_CANCELED;
      break;
      
    case SvSecondMeter::smsTimeout:
      this->socket->abort();
      log(m_Err, QString("Response awaiting timeout %1").
            arg(t->current_time.toString("hh:mm:ss")));
      this->responseStatus = SOCKET_TIMEOUT;
      break;
      
    case SvSecondMeter::smsUnfinished:
      log(m_Err, QString("Qwaiting not finished %1").
            arg(t->current_time.toString("hh:mm:ss")));
      this->responseStatus = SOCKET_CONNECTION_CLOSED;
      break;
      
    case SvSecondMeter::smsDoneOk:
      this->responseStatus = SOCKET_OK;      
  }
  
  t->~SvSecondMeter();
  
}

void SvTcpClient::sendData(QByteArray* data, int msecWaitForAnswer, bool showSymbols, QObject* parent)
{
    if(!this->socket->isOpen()) return;
  
    QByteArray *arrBlock = new QByteArray();
    
    arrBlock->append(*data); // (const char*)data, length);
    
    this->socket->write(*data);
    
    if(showSymbols)
    {
      QString s = "";
      for(int i=0; i < arrBlock->length(); i++)
          s = s + char2hex(arrBlock->at(i));
      
      log(m_Data, " << " + s);
    }

    if(msecWaitForAnswer == dontWait) return;
    
    /*********************** ждем ответ ***********************/
    this->responseSize = 0;
    this->responseData.clear();
    
    SvSecondMeter *t = new SvSecondMeter(msecWaitForAnswer,
                                         "Waiting for response",
                                         "Cancel",
                                         true,
                                         parent);
    
    connect(this, SIGNAL(sigGotNewData()), t, SLOT(slotDone()));
    
    while((t->status == SvSecondMeter::smsRunned)&&(this->socket->isOpen())) QApplication::processEvents();
    if(!this->socket->isOpen()) t->status = SvSecondMeter::smsUnfinished;
    
    switch (t->status)
    {
      case SvSecondMeter::smsCanceled:
        this->socket->reset();//abort();
        log(m_Err, QString("Response awaiting was canceled by user at %1").
              arg(t->current_time.toString("hh:mm:ss")));
        this->responseStatus = SOCKET_AWAITING_CANCELED;
        break;
        
      case SvSecondMeter::smsTimeout:
        this->socket->abort();
        log(m_Err, QString("Response awaiting timeout %1").
              arg(t->current_time.toString("hh:mm:ss")));
        this->responseStatus = SOCKET_TIMEOUT;
        break;
        
      case SvSecondMeter::smsUnfinished:
        log(m_Err, QString("Qwaiting not finished %1").
              arg(t->current_time.toString("hh:mm:ss")));
        this->responseStatus = SOCKET_CONNECTION_CLOSED;
        break;
        
      case SvSecondMeter::smsDoneOk:
        this->responseStatus = SOCKET_OK;      
    }
    
    t->~SvSecondMeter();
}

void SvTcpClient::sendData(int msecWaitForAnswer)
{
  try
  {
    /************* для отладки таймера ************/
    
    /*********************** ждем ответ ***********************/
    this->responseSize = 0;
    this->responseData.clear();
    
    SvSecondMeter *t = new SvSecondMeter(msecWaitForAnswer,
                                         "Waiting for response",
                                         "Cancel",
                                         true);
    
//    connect(this, SIGNAL(sigGotNewData()), t, SLOT(slotDone()));
    
    while(t->status == SvSecondMeter::smsRunned) QApplication::processEvents();
    
    switch (t->status)
    {
      case SvSecondMeter::smsCanceled:
//        this->socket->abort();
        log(m_Err, QString("Response awaiting was canceled by user at %1").
              arg(t->current_time.toString("hh:mm:ss")));
        this->responseStatus = SOCKET_AWAITING_CANCELED;
        break;
        
      case SvSecondMeter::smsTimeout:
//        this->socket->abort();
        log(m_Err, QString("Response awaiting timeout %1").
              arg(t->current_time.toString("hh:mm:ss")));
        this->responseStatus = SOCKET_TIMEOUT;
        break;
        
      case SvSecondMeter::smsDoneOk:
        this->responseStatus = SOCKET_OK;      
    }
    
    t->~SvSecondMeter();
  }
  
  catch(...)
  {
    log(m_Err, "sayToServer: ");
  }
}
