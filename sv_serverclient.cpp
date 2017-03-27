#include "sv_serverclient.h"
#include "log.h"
#include "sv_secondmeter.h"

#include <QApplication>
#include <QByteArray>
#include <QDataStream>
#include <QDebug>
#include <QFuture>
#include <QProgressDialog>
#include <QMessageBox>

using namespace log_ns;

SvServerClient::SvServerClient(quint16 incomingPort,
                               QString outcomingIp,
                               quint16 outcomingPort,
                               bool runServer,
                               QObject *parent) :
  QObject(parent)
{
  this->inPort = incomingPort;
  this->outIp = outcomingIp;
  this->outPort = outcomingPort;
  
  this->clientSocket = new QTcpSocket(this);
  connect(this->clientSocket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
  connect(this->clientSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotSocketError(QAbstractSocket::SocketError)));
  connect(this->clientSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(slotClientStateChanged(QAbstractSocket::SocketState)));
  
  log(m_Info, "Clent runned");
  
  
  if(runServer)
  {
    this->serverSocket = new QTcpServer(this);
    connect(this->serverSocket, SIGNAL(acceptError(QAbstractSocket::SocketError)), this, SLOT(slotSocketError(QAbstractSocket::SocketError)));
    connect(this->serverSocket, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));
  }
  
}

int SvServerClient::connectToHost()
{
  try
  {
    if (this->outIp == "") throw SOCKET_WRONG_IP;
    if (this->outPort == 0) throw(SOCKET_WRONG_PORT);
    
    if (!this->connected)
      {    
        this->clientSocket->connectToHost(this->outIp, this->outPort);
        if (this->clientSocket->waitForConnected(2000))
          {
            this->connected = true;
            return SOCKET_OK;
          }
        else return SOCKET_BAD_CONNECTION;// throw(CE_BAD_CONNECTION);
      }
  }
 
  catch (int err)
  {
    switch (err)
    {  
      case SOCKET_BAD_CONNECTION:
        log(m_Err, QString("Can not connect to %1:%2\n").arg(this->outIp).arg(this->outPort));
        break;      
      
      case SOCKET_WRONG_IP:
        log(m_Err, "Wrong IP adress\n");
        break;
        
      case SOCKET_WRONG_PORT:
        log(m_Err, "Wrong port\n");
        break;        
        
      case SOCKET_ALREADY_CONNECTED:
        log(m_Err, QString("Host %1 already connected\n").arg(this->outIp));
        break;       
    }
    
    return err;
  }
 
}

void SvServerClient::disconnectFromHost()
{
  this->clientSocket->disconnectFromHost();
  this->connected  = false;
}

void SvServerClient::slotSocketError(QAbstractSocket::SocketError err)
{
    QString strError =
        "Error: " + (err == QAbstractSocket::HostNotFoundError ?
                     "The host was not found." :
                     err == QAbstractSocket::RemoteHostClosedError ?
                     "The remote host is closed." :
                     err == QAbstractSocket::ConnectionRefusedError ?
                     "The connection was refused." :
                     (QString(this->clientSocket->errorString()) != "" ? QString(this->clientSocket->errorString()) :
                      QString(this->serverSocket->errorString()))
                    );
    log(m_Err, strError);
}

void SvServerClient::slotClientStateChanged(QAbstractSocket::SocketState state)
{
  switch (state)
    {
    case QAbstractSocket::UnconnectedState:
      log(m_Info, "No connection");
      this->connected = false;
      QApplication::processEvents();
      break;
      
    case QAbstractSocket::HostLookupState:
      log(m_Info, QString("Looking up for %1").arg(this->outIp));
      QApplication::processEvents();
      break;   

    case QAbstractSocket::ConnectingState:
      log(m_Info, QString("Connecting to %1").arg(this->outIp));
      QApplication::processEvents();
      break;
      
    case QAbstractSocket::ConnectedState:
      this->connected = true;
      log(m_Info, QString("Connected to %1").arg(this->outIp));
      QApplication::processEvents();
      break;

    case QAbstractSocket::BoundState:
      log(m_Info, QString("Bounded for %1:%2").arg(this->outIp).arg(this->outPort));
      QApplication::processEvents();
      break; 
      
    case QAbstractSocket::ClosingState:
      log(m_Info, "Closing connection");
      QApplication::processEvents();
      break;       
    }
}

void SvServerClient::sayToServer(QString text)
{
  try
  {
    QByteArray arrBlock;
    switch (this->advancedStream)
    {
      case false:
        arrBlock.append(text);
        break;
        
      case true:
        QDataStream out(&arrBlock, QIODevice::WriteOnly);
        out.setVersion(this->streamVersion);/*QDataStream::Qt_5_3*/
        out << quint16(0) /*<< QTime::currentTime()*/ << text;
        out.device()->seek(0);
        out << quint16(arrBlock.size() - sizeof(quint16));
        
        break;
    }

    this->clientSocket->write(arrBlock);
    log(m_Data, " << " + text);
    
  }
  catch(...)
  {
    log(m_Err, "sayToServer: ");
  }
}

void SvServerClient::slotReadyRead()
{
  try
  {
    QString str;
    
    switch (this->advancedStream)
    {
      case false:
        if (this->clientSocket->bytesAvailable() > 0)
        {
          QByteArray arrBlock = this->clientSocket->readAll();
        
          for (int i=0; i < arrBlock.size(); i++)
          {
            if(showSymbols)
            {

              if((arrBlock.at(i) > 31)) str = str + arrBlock.at(i) + " ";
              else
              {
                str = str + char2hex(arrBlock.at(i));
              }
}
            else
            {
                str = str + char2hex(arrBlock.at(i));
            }
          }
        }

        break;
        
      default:
        
        quint16 dataSize = 0;
        QDataStream in(this->clientSocket);
        
        in.setVersion(this->streamVersion);/*QDataStream::Qt_5_3*/
        for (;;) {
          if (!dataSize)
          {
              if (this->clientSocket->bytesAvailable() < (quint64)sizeof(quint16)) {
                  break;
              }
              in >> dataSize;
          }
          if (this->clientSocket->bytesAvailable() < dataSize) {
              break;
          }
    //      QTime   time;
          
          in >> /*time >>*/ str;

          dataSize = 0;
        }
        
        break;
    }
    
    log(m_Data, /*time.toString() + " " +*/ " >> " + str);
    
    emit sigGotMessage();
  }

  catch(...)
  {
    log(m_Err, "slotReadyRead");  
  }
    
}

void SvServerClient::slotNewConnection()
{
    QTcpSocket* pClientSocket = this->serverSocket->nextPendingConnection();
    connect(pClientSocket, SIGNAL(disconnected()), this, SLOT(slotClientDisconnected()));
    connect(pClientSocket, SIGNAL(readyRead()), this, SLOT(slotReadClient()));

    log(m_Info, "Connected client: " + pClientSocket->peerAddress().toString());
    //this->sendToClient(pClientSocket, "Connected to " + pClientSocket->localAddress().toString());
}

void SvServerClient::slotClientDisconnected()
{
  QTcpSocket* pClientSocket = (QTcpSocket*)sender();
  log(m_Info, QString("Client %1 disconnected").arg(pClientSocket->peerAddress().toString()));
  pClientSocket->close();
}

void SvServerClient::sendToClient(QTcpSocket* pSocket, const QString& str)
{
    QByteArray  arrBlock;
    
    switch (this->advancedStream)
    {
      case false:
        arrBlock.append(str);
        break;
        
      default:
        
        QDataStream out(&arrBlock, QIODevice::WriteOnly);
        out.setVersion(this->streamVersion);/*QDataStream::Qt_5_3*/
        out << quint16(0) << /*QTime::currentTime() <<*/ str;
    
        out.device()->seek(0);
        out << quint16(arrBlock.size() - sizeof(quint16));        
        break;
    }
    
    pSocket->write(arrBlock);
    log(m_Data, " << " + str);
}

void SvServerClient::sendData(QByteArray* data, int msecWaitForAnswer)
{
//    if(!this->clientSocket->connected()) return;
  
    QByteArray *arrBlock = new QByteArray();
    
    arrBlock->append(*data); // (const char*)data, length);
    
//    this->clientSocket->write(*data);
    
    QString s = "";
    for(int i=0; i<arrBlock->length(); i++) s = s + char2hex(arrBlock->at(i));
      
    log(m_Data, " << " + s);

    if(msecWaitForAnswer == dontWait) return;
    
    /*********************** ждем ответ ***********************/
    SvSecondMeter *t = new SvSecondMeter(msecWaitForAnswer, "Waiting for answer", "Cancel", true);
    
    connect(this, SIGNAL(sigGotNewData()), t, SLOT(slotDone()));
    
    while(t->status == SvSecondMeter::smsRunned) QApplication::processEvents();
    
    switch (t->status)
    {
      case SvSecondMeter::smsCanceled:
        this->clientSocket->abort();
        log(m_Err, QString("Response awaiting was canceled by user at %1").
              arg(t->current_time.toString("hh:mm:ss")));
//        this->responseStatus = SOCKET_AWAITING_CANCELED;
        break;
        
      case SvSecondMeter::smsTimeout:
        this->clientSocket->abort();
        log(m_Err, QString("Response awaiting timeout %1").
              arg(t->current_time.toString("hh:mm:ss")));
//        this->responseStatus = SOCKET_TIMEOUT;
        break;
        
//      case SvSecondMeter::smsDoneOk:
//        this->responseStatus = SOCKET_OK;      
    }
    
    t->~SvSecondMeter();    
}
void SvServerClient::slotReadClient()
{
  QTcpSocket* pClientSocket = (QTcpSocket*)sender();
  QString str = "";
  
  switch (this->advancedStream)
  {
    case false:
      qDebug() << QString("bytesAvailable %1").arg(pClientSocket->bytesAvailable());
      if (pClientSocket->bytesAvailable() > 0)
      {
        QByteArray arrBlock = pClientSocket->readAll();

        for (int i=0; i < arrBlock.size(); i++)
        {
//          log(m_Data, QString("arrBlock[%1]=%2").arg(i).arg(arrBlock.at(i)));
            str = str + char2hex(arrBlock.at(i));

        }
      }
      break;
      
    default:

      QDataStream in(pClientSocket);
      quint16 dataSize = 0;
      
      in.setVersion(this->streamVersion);/*QDataStream::Qt_5_3*/
      for (;;) 
      {
         if (!dataSize) 
         {
             if (pClientSocket->bytesAvailable() < (int)sizeof(quint16)) 
             { break; }
             
             in >> dataSize;
         }
    
         log(m_Data, QString("bytesAvailable=%1   dataSize=%2").arg(pClientSocket->bytesAvailable()).arg(dataSize));
         
         if (pClientSocket->bytesAvailable() < dataSize) 
         {
           log(m_Err, "bytesAvailable < dataSize");  
           break;
         }
    //     QTime   time;
    //     QString str;
    //     in >> /*time >>*/ str;
         in >> str;
         dataSize = 0;
    
      }
      break;
  }  
  qDebug() << "3";
  this->last_message = str/*.toUpper()*/;
  log(m_Data, " >> " + this->last_message);
  this->sendToClient(pClientSocket, this->last_message);
    
  emit this->sigGotMessage();
  
}

int SvServerClient::runServer(quint16 port)
{
  if(this->serverRunned)
  {
    log(m_Err, "Already runned");
    return 0;
  }
  
  this->serverSocket = new QTcpServer(this);
  this->inPort = port;
  if(!this->serverSocket->listen(QHostAddress::Any, this->inPort))
  {
    log(m_Err, "Server not runned");
    this->serverSocket->close();
    return 1;
  }
  
  connect(this->serverSocket, SIGNAL(acceptError(QAbstractSocket::SocketError)), this, SLOT(slotSocketError(QAbstractSocket::SocketError)));
  connect(this->serverSocket, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));
  
  log(m_Info, "Server runned");
  
  return 0;
}

void SvServerClient::stopServer()
{
  this->serverSocket->close();
  this->serverRunned = false;
  log(m_Info, "Server stopped");
}

void SvServerClient::setOutcomingIp(QString ip)
{
  this->outIp = ip;
}

void SvServerClient::setOutcomingPort(quint16 port)
{
  this->outPort = port;  
}

void SvServerClient::setIncomingPort(quint16 port)
{
  this->inPort = port;
}

void SvServerClient::slotOnTimer()
{
  
}

