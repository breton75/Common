#ifndef SVFFMPEG_H
#define SVFFMPEG_H

#include <QThread>
#include <QImage>
#include <QWidget>
#include <QTime>
//#include <QObject>

class Svffmpeg;
    
class SvFFMpegWidget : public QWidget
{
    Q_OBJECT
  public:
    explicit SvFFMpegWidget(QString media_path,
                            int width,
                            int height,
                            int posX,
                            int posY,
                            QString caption,
                            QString path_to_save_frames = "c:/frames/");
    
    ~SvFFMpegWidget();
    
    QImage *img;
    Svffmpeg *ffmpg;
    QString caption;
    
  protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QMouseEvent *) Q_DECL_OVERRIDE;  
      
  signals:
    void sigStop();
    void sigSettings();
    void sigSaveFrame();
    
    
  public slots:
    virtual void slotStop();
    virtual void slotSettings();
    virtual void slotSaveFrame();
    
};

class Svffmpeg : public QThread
{
    Q_OBJECT
    
  public:
    explicit Svffmpeg(QString media_path,
                      QImage *img,
                      int width,
                      int height,
                      QString path_to_save_frames);
    ~Svffmpeg();
    
    QString media_path;
    QImage* img;
    int img_width;
    int img_height;
    
    QString path_to_save_frames;
    
    bool saveframe = false;
    
    virtual void run() Q_DECL_OVERRIDE;
    
    void stopPlaying() { isPlaying = false; }
    
  signals:
    void sigImgLoaded();
    
  private:
    bool isPlaying;
    
//  public slots:
    
};

class SvFFMpegObject: public QObject
{
  Q_OBJECT
    
  public:
    explicit SvFFMpegObject();
    
};


#endif // SVFFMPEG_H
