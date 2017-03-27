#include "sv_udpserver.h"
#include <QFile>
//#include "udpemulatestream.h"
#include <QMap>
#include "../Common/log.h"

using namespace log_ns;

///*extern */QByteArray *datagram, *readBuffer;
//QMap<int, UdpEmulateStream*> stream_list;

SvUdpServer::SvUdpServer(quint16 port,
                         QObject *parent) :
  QObject(parent)
{
  
  this->port = port;
  
  this->socket = new QUdpSocket(this);
  this->socket->bind(this->port);

  connect(this->socket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
  
}

void SvUdpServer::readPendingDatagrams()
{
  QFile file("e:/out.mp4");
  if (!file.open(QIODevice::ReadWrite| QIODevice::Append))
    return;
  
  QDataStream out(&file);
  
  while (this->socket->hasPendingDatagrams()) {
      QByteArray *readBuffer;

      readBuffer->resize(this->socket->pendingDatagramSize());
      QHostAddress sender;
      quint16 senderPort;

      socket->readDatagram(readBuffer->data(), readBuffer->size(),
                              &sender, &senderPort);
//      disconnect(this->socket, SIGNAL(readyRead()),
//              this, SLOT(readPendingDatagrams()));
//      datagram = readBuffer;
      out << readBuffer->data();
//      log(m_Duty, "socket->readDatagram");
      emit this->dataReceived();
//      log(m_Duty, "emit this->dataReceived");
      
      
//      processTheDatagram(datagram);
  }
}
