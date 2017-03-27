#ifndef SVFF2BMPPLAYER_H
#define SVFF2BMPPLAYER_H

#include <QWidget>
#include <QThread>

class SvFF2BMPDecoder;

class SvFF2BMPPlayer: public QWidget
{
      Q_OBJECT
  
  public:
    explicit SvFF2BMPPlayer(QString fileName,
                            int width,
                            int height,
                            int posX,
                            int posY,
                            QString camName,
                            int speed);
    
    ~SvFF2BMPPlayer();

    QImage *img;
    SvFF2BMPDecoder *ffmpg;
    QString camName;
    QString fileName;
    int speed;
    
  protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QMouseEvent *) Q_DECL_OVERRIDE;  
      
  signals:
    void sigStop();
    void sigPlay();
    
    
  public slots:
    virtual void slotStop();
    virtual void slotplay();
};


class SvFF2BMPDecoder: public QThread
{
  Q_OBJECT
  
  public:
    explicit SvFF2BMPDecoder(QString fileName,
                             QImage *img,
                             QString *caption,
                             int speed = 1);
    
    ~SvFF2BMPDecoder();
    
    QString fileName;
    QImage *img;
//    QString caption;
    int speed;
    
    virtual void run() Q_DECL_OVERRIDE;
    
  signals:
    void sigImgLoaded();
    
};

#endif // SVFF2BMPPLAYER_H
