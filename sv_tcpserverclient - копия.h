#ifndef SV_TCPSERVERCLIENT_H
#define SV_TCPSERVERCLIENT_H

#include <QObject>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <QDataStream>

/*** constants ***/
const int dontWait = -1;
const int infinite = 0;

enum SocketErrors
{
  SOCKET_ERROR = -1,
  SOCKET_OK = 0,
  SOCKET_BAD_CONNECTION,
  SOCKET_WRONG_IP,
  SOCKET_WRONG_PORT,
  SOCKET_CONNECTION_FAULT,
  SOCKET_ALREADY_CONNECTED,
  SOCKET_NOT_CONNECTED,
  SOCKET_TIMEOUT,
  SOCKET_AWAITING_CANCELED,
  SOCKET_CONNECTION_CLOSED
};

class SvTcpServer : public QObject
{
    Q_OBJECT

  private:
    
    quint16     nextBlockSize = 0;
    void sendToClient(QTcpSocket* pSocket, const QString& str);
  
  public:
    
    quint16 port = 35580;
    
    SvTcpServer(quint16 port = 35580,
                   bool runServer = false,
                   QObject *parent = 0,
                   bool logRequestData = true,
                   bool showRequestDataInHex = false,
                   bool logResponseData = true,
                   bool showResponseDataInHex = false,
                   bool advancedStream = false,
                   int streamVersion = QDataStream::Qt_5_2);
    
    
    QTcpServer* server;
    bool isRunned = false;
    
    int startServer(quint16 port, QObject* parent = 0);
    void stopServer();

    bool advancedStream = false;
    int streamVersion = QDataStream::Qt_5_2;

    QByteArray last_message;
    bool logRequestData = true;
    bool showRequestDataInHex = false;
    bool logResponseData = true;
    bool showResponseDataInHex = false;

  signals:
    virtual void sigGotMessage();

  public slots:
    virtual void slotNewConnection();
    virtual void slotReadClient   ();
    virtual void slotClientDisconnected();
    
};

class SvTcpClient : public QObject
{
    Q_OBJECT

  private:
    quint16     nextBlockSize = 0;

  public:
    quint16 port;
    QString ip;    
    
    SvTcpClient(QString ip = "",
                quint16 port = 35580,
                bool logRequestData = true,
                bool showRequestDataInHex = false,
                bool logResponseData = true,
                bool showResponseDataInHex = false,
                bool advancedStream = false,
                int streamVersion = QDataStream::Qt_5_2,
                QObject *parent = 0);      
    
    QTcpSocket* socket;
    bool connected = false;
    
    QByteArray responseData = 0;
    quint64 responseSize = 0;
    int responseStatus = -1;
    
    virtual int connectToHost();
    virtual void disconnectFromHost();
    
    bool advancedStream = false;
    int streamVersion = QDataStream::Qt_5_2;
//    bool showSymbols = true;
    
    bool logRequestData = true;
    bool showRequestDataInHex = false;
    bool logResponseData = true;
    bool showResponseDataInHex = false;
//    bool log_requests = true;
//    bool log_responses = true;
    
    
    virtual void sendData(QByteArray* data, int msecWaitForAnswer = dontWait, QObject *parent = 0);
    virtual void sendData(QString text, int msecWaitForAnswer = dontWait, QObject* parent = 0);
    
    /* для отладки таймера */
    virtual void sendData(int msecWaitForAnswer);
    
  signals:
    virtual void sigGotNewData();
  
  private slots:
      virtual void slotReadyRead();
      virtual void slotSocketError(QAbstractSocket::SocketError);
      virtual void slotStateChanged(QAbstractSocket::SocketState state);

};

#endif // SV_TCPSERVERCLIENT_H








