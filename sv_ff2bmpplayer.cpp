#include "sv_ff2bmpplayer.h"

#include <QDebug>
#include <QOpenGLWidget>
#include <QPainter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDateTime>
#include <QIcon>
#include <QTextOption>

QPushButton *bnStop1;
QPushButton *bnPlay1;

QString* caption;

SvFF2BMPPlayer::SvFF2BMPPlayer(QString fileName,
                               int width,
                               int height,
                               int posX,
                               int posY,
                               QString camName,
                               int speed)
{
  this->setGeometry(posX, posY, width + 8, height + 28);
  this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  
  this->img = new QImage(width, height, QImage::Format_RGB888);
  this->camName = camName;
  this->fileName = fileName;
  this->speed = speed;
  
  QIcon icon;
  
  /* кнопка стоп */
  bnStop1 = new QPushButton(this);
  bnStop1->setObjectName(QStringLiteral("bnStop1"));
  bnStop1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
  bnStop1->setMinimumSize(QSize(18, 18));
  bnStop1->setMaximumSize(QSize(18, 18));
  bnStop1->setGeometry(4, 4, 18, 18);
  
  icon.addFile(QStringLiteral(":/icons/Icons/png2ico/cross.ico"),
               QSize(16, 16),
               QIcon::Normal,
               QIcon::Off);
  bnStop1->setIcon(icon);
  bnStop1->show();
  
  /* кнопка настройки */
  bnPlay1 = new QPushButton(this);
  bnPlay1->setObjectName(QStringLiteral("bnSettings1"));
  bnPlay1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
  bnPlay1->setMinimumSize(QSize(18, 18));
  bnPlay1->setMaximumSize(QSize(18, 18));
  bnPlay1->setGeometry(24, 4, 18, 18);
//  QIcon icon;
  icon.addFile(QStringLiteral(":/icons/Icons/google/Gears.bmp"),
               QSize(16, 16),
               QIcon::Normal,
               QIcon::Off);
  bnPlay1->setIcon(icon);
  bnPlay1->show();
  
  
  connect(bnStop1, SIGNAL(clicked()), SIGNAL(sigStop()));
  connect(this, SIGNAL(sigStop()), this, SLOT(slotStop()));
  
  connect(bnPlay1, SIGNAL(pressed()), SIGNAL(bnPlay()));
  connect(this, SIGNAL(sigPlay()), this, SLOT(slotPlay())); 
  
  caption = new QString();
  
  ffmpg = new SvFF2BMPDecoder(this->fileName,
                              this->img,
                              caption,
                              this->speed);
  
  connect(ffmpg, SIGNAL(sigImgLoaded()), this, SLOT(repaint()));
  ffmpg->start();
  
}

SvFF2BMPPlayer::~SvFF2BMPPlayer()
{
  
}

void SvFF2BMPPlayer::slotStop()
{

}

void SvFF2BMPPlayer::mouseDoubleClickEvent(QMouseEvent *)
{

}

void SvFF2BMPPlayer::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);
  painter.drawImage(4, 24, *img);
  
  QPen pp;
  pp.setStyle(Qt::SolidLine);
  pp.setColor(Qt::blue);
  pp.setWidth(2);
  
  painter.setPen(pp);

  painter.drawRects(new QRect(2, 2, this->width() - 3, this->height() - 3), 1);
  
  
  pp.setColor(Qt::white);
  painter.setPen(pp);
  
  QFont fnt;
  fnt.setBold(true);
  fnt.setPixelSize(14);
  
  painter.setFont(fnt);
  
  painter.drawText(4,
                   4,
                   this->width() - 12,
                   this->height() - 12,
                   Qt::AlignBottom | Qt::AlignCenter,
                   *caption);

  
}

void SvFF2BMPPlayer::slotplay()
{
  
  ffmpg = new SvFF2BMPDecoder(this->fileName,
                              this->img,
                              caption);
  
  ffmpg->start();
  
  
}

SvFF2BMPDecoder::SvFF2BMPDecoder(QString fileName,
                                 QImage *img,
                                 QString *caption,
                                 int speed)
{
  this->fileName = fileName;
  this->img = img;
//  this->caption = caption;
  this->speed = speed;
  
}

SvFF2BMPDecoder::~SvFF2BMPDecoder()
{
  
}

void SvFF2BMPDecoder::run()
{
  
  FILE *fin;
  fin = fopen(fileName.toUtf8(), "rb");
  
//  fseek(fin, 0, 0);
//  char h[8];
//  fread(&h, 8, 1, fin);
//  if(h != "FFM2BMP"){}
  
  fseek(fin, 8, 0);
  int framesCount;
  fread(&framesCount, 4, 1, fin);
//  qDebug() << "framesCount = " << framesCount;
  
  uint frame_begin = 12 + sizeof(time_t) * 3;
  fseek(fin, frame_begin, 0);
  
  /* начинаем читать кадры */
  while(!feof(fin))
  {
  
    /* номер кадра */
    //  fseek(fin, 16, 0);
    int frameNumber;
    fread(&frameNumber, 4, 1, fin);  
//    qDebug() << "frameNumber = " << frameNumber;    
    
    /* ширина кадра */
    //  fseek(fin, 16, 0);
    int w;
    fread(&w, 4, 1, fin);  
//    qDebug() << "w = " << w;
    
    /* высота кадра */
//      fseek(fin, 24, 0);
    int h;
    fread(&h, 4, 1, fin); 
//    qDebug() << "h = " << h;
    
    /* размер кадра */
    //  fseek(fin, 32, 0);
    uint frame_size;
    fread(&frame_size, 4, 1, fin); 
//    frame_size = w*h;
    qDebug() << "frame_size = " << frame_size;
    
    /* время кадра */
    time_t frame_time;
    fread(&frame_time, 4, 1, fin);
//    qDebug() << "frame_time = " << frame_time;
    
    /* определяем переменные для работы с буфером bmp */
    uint header_size = sizeof(BITMAPFILEHEADER);
    uint info_size = sizeof(BITMAPINFOHEADER);
    //  uint frame_size = w * h * 4;
    
    /* готовим буфер для формирования bmp */
    uchar* bmpBuf = reinterpret_cast<uchar*>(malloc(header_size + info_size + frame_size));
//    qDebug() << "bmpBuf  " << bmpBuf;
    
    /* формируем заголовок bmp */
    BITMAPFILEHEADER bmpheader;
    bmpheader.bfReserved1 = 0;
    bmpheader.bfReserved2 = 0;
    bmpheader.bfOffBits = header_size + info_size;
    bmpheader.bfSize = bmpheader.bfOffBits + frame_size;
    bmpheader.bfType = 0x4d42;
//    qDebug() << "BITMAPFILEHEADER";
    
    // create bmp info
    
    BITMAPINFO bmpinfo;
    bmpinfo.bmiHeader.biSize = info_size;
    bmpinfo.bmiHeader.biWidth = w;
    bmpinfo.bmiHeader.biHeight = -h;
    bmpinfo.bmiHeader.biPlanes = 1;
    bmpinfo.bmiHeader.biBitCount = 32; //32
//    RGBQUAD palett[256];
//    bmpinfo.bmiColors[256];//  = palett;
    bmpinfo.bmiHeader.biCompression = BI_RGB; // ;BI_JPEG
    bmpinfo.bmiHeader.biSizeImage = 0; //frame_size;
    bmpinfo.bmiHeader.biXPelsPerMeter = 100;
    bmpinfo.bmiHeader.biYPelsPerMeter = 100;
    bmpinfo.bmiHeader.biClrUsed = 0;
    bmpinfo.bmiHeader.biClrImportant = 0;
//    qDebug() << "BITMAPINFO";
    
    /* пишем заголовок в буфер bmp */
    memcpy(bmpBuf, &bmpheader, header_size);
    memcpy(bmpBuf + header_size, &bmpinfo.bmiHeader, info_size);
//    qDebug() << "memcpy 1";

    /* определяем начало данных изображения */
    uchar* dataStart = bmpBuf + header_size + info_size;
    
    
//    uchar* data;
    size_t t = fread(dataStart, frame_size, 1, fin);
    qDebug() << "fread " << t;
    
    /* пишем кадр в буфер bmp */
//    memcpy(dataStart, data, frame_size);
//    qDebug() << "memcpy 2";

    if(!img->loadFromData((const uchar*)(bmpBuf), header_size + info_size + frame_size))
        qDebug() << " image not loaded";
    
    else
    {
      *caption = QString("%1").arg(QDateTime::fromTime_t(frame_time).toString("dd.MM.yyyy hh:mm:ss"));
      emit this->sigImgLoaded();
    }
    
    msleep(4000 / speed);
  } 
  
}















