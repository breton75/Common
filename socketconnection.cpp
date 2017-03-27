#include "socketconnection.h"
#include "log.h"
#include <QApplication>
//#include <QDataStream>
#include <QDateTime>

using namespace log_ns;
using namespace connection_errors;

SocketConnection::SocketConnection(QObject *parent, 
                                   QString sip, 
                                   quint16 sport) :
  QObject(parent)
{
  this->ip = sip;
  this->port = sport;
  this->connected = false;
  
  this->socket = new QTcpSocket(this);

//  connect(this->socket, SIGNAL(connected()), this, SLOT(slotConnected()));
  connect(this->socket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
  connect(this->socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotError(QAbstractSocket::SocketError)));
  connect(this->socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(slotStateChanged(QAbstractSocket::SocketState)));
  
}

int SocketConnection::_connect()
{
  try
  {
    if (this->ip == "") throw CE_WRONG_IP;
    if (this->port == 0) throw CE_WRONG_PORT;
    
    if (!this->connected)
      {    
        this->socket->connectToHost(this->ip, this->port);
        if (socket->waitForConnected(2000))
          {
            this->connected = true;
            return 0;
          }
        else throw CE_BAD_CONNECTION;
      }
  }
 
  catch (int err)
  {
    switch (err)
    {  
      case CE_BAD_CONNECTION:
        log(m_Err, QString("Can not connect to %1:%2\n").arg(this->ip).arg(this->port));
        break;      
      
      case CE_WRONG_IP:
        log(m_Err, "Wrong IP adress\n");
        break;
        
      case CE_WRONG_PORT:
        log(m_Err, "Wrong port\n");
        break;        
        
      case CE_ALREADY_CONNECTED:
        log(m_Err, QString("Host %1 already connected\n").arg(this->ip));
        break;       
    }
    
    return err;
  }
 
}

void SocketConnection::slotConnected()
{
  this->connected = true;
  log(m_Data, "Connected to " + this->ip + ':' + this->port);
}

void SocketConnection::slotError(QAbstractSocket::SocketError err)
{
    QString strError =
        "Error: " + (err == QAbstractSocket::HostNotFoundError ?
                     "The host was not found." :
                     err == QAbstractSocket::RemoteHostClosedError ?
                     "The remote host is closed." :
                     err == QAbstractSocket::ConnectionRefusedError ?
                     "The connection was refused." :
                     QString(this->socket->errorString())
                    );
    log(m_Err, strError);
}

void SocketConnection::slotReadyRead()
{
//    QDataStream in( this->socket);
//    in.setVersion(QDataStream::Qt_5_2);

    QString str = "";

    int i;
    QByteArray  arrBlock;

    arrBlock = this->socket->readAll();
    arrBlock = arrBlock.toHex();

//    log(m_Info, QString("arrBlock.length() = %1").arg(arrBlock.length()));
//    log(m_Err, QString("%1").arg(sizeof(int)));

    for (i=0; i < arrBlock.size(); i = i+2)
      {
          str = str + arrBlock.at(i) + arrBlock.at(i + 1) + ' ';//
      }

    log(m_Data, "Received data:\n" + str);
}

void SocketConnection::slotStateChanged(QAbstractSocket::SocketState state)
{
  switch (state)
    {
    case QAbstractSocket::UnconnectedState:
      log(m_Err, "Unconnected");
      this->connected = false;
      QApplication::processEvents();
      break;
      
    case QAbstractSocket::HostLookupState:
      log(m_Info, QString("Lokup fo %1").arg(this->ip));
      QApplication::processEvents();
      break;   

    case QAbstractSocket::ConnectingState:
      log(m_Info, QString("Connecting fo %1").arg(this->ip));
      QApplication::processEvents();
      break;
      
    case QAbstractSocket::ConnectedState:
      this->connected = true;
      log(m_Info, QString("Connected to %1").arg(this->ip));
      QApplication::processEvents();
      break;

    case QAbstractSocket::BoundState:
      log(m_Info, QString("Bounded fo %1:%2").arg(this->ip).arg(this->port));
      QApplication::processEvents();
      break; 
      
    case QAbstractSocket::ClosingState:
      log(m_Info, "Closing connection");
      QApplication::processEvents();
      break;       
    }
}

int SocketConnection::send_command(QString command, bool wait_for_answer, QString *answer)

{
  try
  {
    if (!this->connected) { throw CE_NOT_CONNECTED; }
 
    log(m_Data, command);
    
    QByteArray arrBlock;
    arrBlock.append(command);
    this->socket->write(arrBlock);
    
    
  }
  catch (int err)
  {
    
  }
  
}
