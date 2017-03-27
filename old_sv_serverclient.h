#ifndef SV_SERVERCLIENT_H
#define SV_SERVERCLIENT_H

#include <QObject>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <QDataStream>

class SvServerClient : public QObject
{
    Q_OBJECT

  private:
    
    quint16     nextBlockSize = 0;
      void sendToClient(QTcpSocket* pSocket, const QString& str);
  
  public:
    enum ConnectionErrors {
      CE_BAD_CONNECTION = -1,
      CE_OK = 0,
      CE_WRONG_IP = 1,
      CE_WRONG_PORT = 2,
      CE_CONNECTION_FAULT = 3,
      CE_ALREADY_CONNECTED = 4,
      CE_NOT_CONNECTED = 5
    };
     
    quint16 inPort = 35580;
    quint16 outPort;
    QString outIp;    
    
    QTimer timer;
    
    SvServerClient(quint16 incomingPort = 35580,
                   QString outcomingIp = "",
                   quint16 outcomingPort = 35580,
                   bool runServer = false,
                   QObject *parent = 0);      
    
    QTcpServer* serverSocket;
    bool serverRunned = false;
    int runServer(quint16 port);
    void stopServer();
   
    QTcpSocket* clientSocket;
    bool connected = false;
    
    QString last_message;
    QString who_say;
    bool newConnectionOnSend = false;
    
    void setIncomingPort(quint16 port);
    void setOutcomingIp(QString ip);
    void setOutcomingPort(quint16 port);
    
    virtual int connectToHost();
    virtual void disconnectFromHost();
    
    bool advancedStream = false;
    int streamVersion = QDataStream::Qt_5_3;
    bool showSymbols = false;
    
  signals:
    virtual void sigGotMessage();
  
  private slots:
      virtual void slotReadyRead();
      virtual void slotSocketError(QAbstractSocket::SocketError);
      virtual void slotClientStateChanged(QAbstractSocket::SocketState state);
      virtual void slotOnTimer();

  public slots:
    virtual void slotNewConnection();
    virtual void slotReadClient   ();
    virtual void slotClientDisconnected();
    
    virtual void sayToServer(QString text);
    
};

#endif // SV_SERVERCLIENT_H








