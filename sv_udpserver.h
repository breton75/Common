#ifndef SVUDPSERVER_H
#define SVUDPSERVER_H

#include <QObject>
#include <QUdpSocket>
#include <QIODevice>
#include <QFile>
#include <QDataStream>
#include <QByteArray>

extern QByteArray *datagram;

class SvUdpServer : public QObject
{
    Q_OBJECT
  public:
    explicit SvUdpServer(quint16 port,
                         QObject *parent = 0);
    
    QUdpSocket *socket;
    int port;
    QIODevice *udp_io;
    QFile *file;
    QDataStream *out;
    
  signals:
    void dataReceived();
    
  public slots:
    void readPendingDatagrams();
    
};

#endif // SVUDPSERVER_H
