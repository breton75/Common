/* 
 * функции для разбора протокола SDP 
 * при обмене данными с источниками медиа ресурсов
 *  
 * RFC: SDP: Session Description Protocol
 * https://tools.ietf.org/html/rfc4566#section-5.13 
 * 
*/

#ifndef SV_SDPPARSER
#define SV_SDPPARSER

#include <QList>
#include <QStringList>
#include <QByteArray>
#include <QString>
#include <QDebug>

enum MediaTypes
{
  mtUndefined = -1,
  mtAudio = 0,
  mtVideo = 1
};

struct SDP_DESCRIBE
{
  int     Type;
  quint16 Port;
  QString Protocol;
  QString Codec;
  int     SamplingFreq;
  float   Framerate;
  QString TrackID;
  int     Standart;
};

struct SDP_SETUP
{
  QString Session;
  quint16 FirstServerPort;
  quint16 LastServerPort;
};

int parseSDP_DESCRIBE(QString text, QList<SDP_DESCRIBE>* list);
int parseSDP_SETUP(QString text, SDP_SETUP* sdp);

/******************************************************/

int parseSDP_DESCRIBE(QString text, QList<SDP_DESCRIBE>* list)
{
  /* пока парсинг исходя из того, что
   * источник медиа только один.
   * читать RFC SDP: Session Description Protocol
   */
  
  int i, ret, cnt;
  SDP_DESCRIBE sdp;
    
  sdp.Codec = "";
  sdp.TrackID = "";
  sdp.Framerate = 0;
  sdp.Port = 0;
  sdp.Protocol = "";
  sdp.SamplingFreq = 0;
  sdp.Type = mtUndefined; 
  sdp.Standart = 0;
  
  bool* cnv = new bool;
  QString curLine;
  QString tag;
  int pos1, pos2;
      
  QStringList sdpl = text.split("\r\n");
  
  /* первым делом находим код ответа */
  curLine = sdpl.at(0);
  pos1 = curLine.indexOf(" ");
  pos2 = curLine.indexOf(" ", pos1 + 1);
  ret = curLine.mid(pos1, pos2 - pos1).toInt(cnv, 10);
  
  /* если не равно 200, это ошибка, выходим с ее кодом
   * иначе, присваиваем коду возврата -1 на случай если 
   * функция завершится с ошибкой */
  if(ret != 200) return ret;
  else ret = -1;
  
  /* создаем массив, в котором будем запоминать количество 
   * и номер строки, медиа ресурсов, описанных в text.
   * первый байт количество. затем каждый байт номер строки в sdpl */
  QByteArray b; 
  cnt = 0;
  for(i = 0; i < sdpl.count(); i++)
  {
    if(sdpl.at(i).left(2) == "m=")
    {
      cnt++;
      b.append(char(i));
    }
  }
  b.push_front(char(cnt)); // записываем количество медиа ресурсов

  for(i = 1; i <= cnt; i++)
  {
    
    sdp.Codec = "";
    sdp.TrackID = "";
    sdp.Framerate = 0;
    sdp.Port = 0;
    sdp.Protocol = "";
    sdp.SamplingFreq = 0;
    sdp.Type = mtUndefined; 
    sdp.Standart = 0;
    
    /* начало и конец для блока описания очередного медиа ресурса */
    int begin, end;
    begin = b.at(i);
    if(i == b.at(0)) end = sdpl.count();
    else end = b.at(i + 1);
    
    /* 1. ищем информацию: тип медиа, порт, протокол. тэг m= */
    tag = "m=";
    pos1 = tag.length();

    curLine = sdpl.at(begin);
        
    /* определеяем тип медиа */
    pos2 = curLine.indexOf(" ");
    if(pos2 > pos1)
    {
       
      QString s = curLine.mid(pos1, pos2 - pos1);
      if(s.toLower() == "video") sdp.Type = mtVideo;
      else if(s.toLower() == "audio") sdp.Type = mtAudio;
      
      /* далее порт */
      pos1 = pos2;
      pos2 = curLine.indexOf(" ", pos1 + 1);
      if(pos2 > pos1)
      {
//        qDebug() << "Port " << curLine.mid(pos1 + 1, pos2 - pos1 - 1);
        sdp.Port = curLine.mid(pos1 + 1, pos2 - pos1 - 1).toInt(cnv, 10);
      }
      
      /* далее протокол */
      pos1 = pos2;
      pos2 = curLine.indexOf(" ", pos1 + 1);
      if(pos2 > pos1)
      {
//        qDebug() << "Protocol " << curLine.mid(pos1 + 1, pos2 - pos1 - 1);
        sdp.Protocol = curLine.mid(pos1 + 1, pos2 - pos1 - 1);
      }
      
      /* далее идет номер стандарта, но мы его вытаскиваем далее */
    }
    
    /* 2. ищем информацию о стандарте, кодеке и частоте дискретизации. тэг a=rtpmap: */
    tag = "a=rtpmap:";
    pos1 = tag.length();

    for(int j = begin; j < end; j++)
    {
      curLine = sdpl.at(j);
      
      if(curLine.left(pos1) == tag)
      {
        pos2 = curLine.indexOf(" ", pos1 + 1);
        if(pos2 > pos1)
        {
          /* первым идет номер стандарта */
//          qDebug() << "Standart " << curLine.mid(pos1, pos2 - pos1);
          sdp.Standart = curLine.mid(pos1, pos2 - pos1).toInt(cnv, 10);
          
          /* далее кодек до символа '/' */
          pos1 = pos2;
          pos2 = curLine.indexOf("/", pos1 + 1);
          
          if(pos2 > pos1)
          {
//            qDebug() << "Codec " << curLine.mid(pos1 + 1, pos2 - pos1 - 1);
            sdp.Codec = curLine.mid(pos1 + 1, pos2 - pos1 - 1);
            
            /* и далее частота дискретизации */
            pos1 = pos2;
            pos2 = curLine.length();
            
            if(pos2 > pos1)
            {
//              qDebug() << "SamplingFreq " << curLine.mid(pos1 + 1, pos2 - pos1 - 1);
              sdp.SamplingFreq = curLine.mid(pos1 + 1, pos2 - pos1 - 1).toInt(cnv, 10);
            }
          }
        }
      }
    }
    
    /* ищем информацию о частоте кадров. тэг a=framerate: */
    tag = "a=framerate:";
    pos1 = tag.length();

    for(int j = begin; j < end; j++)
    {
      curLine = sdpl.at(j);
      
      if(curLine.left(pos1) == tag)
      {
        pos2 = curLine.length();
        if(pos2 > pos1)
        {
//          qDebug() << "Framerate " << curLine.mid(pos1, pos2 - pos1);
          sdp.Framerate = curLine.mid(pos1, pos2 - pos1).toFloat(cnv);
        }
      }
    }
    
    /* ищем информацию о пути к медиа. тэг a=control: */
    tag = "a=control:";
    pos1 = tag.length();

    for(int j = begin; j < end; j++)
    {
      curLine = sdpl.at(j);
      
      if(curLine.left(pos1) == tag)
      {
        pos2 = curLine.length();
        if(pos2 > pos1)
        {
//          qDebug() << "TrackID " << curLine.mid(pos1, pos2 - pos1);
          sdp.TrackID = curLine.mid(pos1, pos2 - pos1);
        }
      }
    }
    
    /* заносим заполненную структуру в список */
    list->append(sdp);
    
  }
  
  /* если все ОК, то возвращаем код 200 */
  return 200;
}

int parseSDP_SETUP(QString text, SDP_SETUP* sdp)
{
  bool* cnv = new bool;
  QString curLine;
  QString tag;
  int pos1, pos2, ret;
      
  QStringList sdpl = text.split("\r\n");
  
  /* первым делом находим код ответа */
  curLine = sdpl.at(0);
  pos1 = curLine.indexOf(" ");
  pos2 = curLine.indexOf(" ", pos1 + 1);
  ret = curLine.mid(pos1, pos2 - pos1).toInt(cnv, 10);
  
  /* если не равно 200, это ошибка, выходим с ее кодом
   * иначе, присваиваем коду возврата -1 на случай если 
   * функция завершится с ошибкой */
  if(ret != 200) return ret;
  else ret = -1;
  
  /* ищем идентификатор сессии. тэг Session: */
  tag = "Session:";
  pos1 = tag.length();

  for(int j = 1; j < sdpl.count(); j++)
  {
    curLine = sdpl.at(j);
    
    if(curLine.left(pos1) == tag)
    {
      pos2 = curLine.length();
      sdp->Session = curLine.mid(pos1, pos2 - pos1).trimmed();
      break;
    }
  }
  
  /* ищем информацию о сессии. тэг Transport: */
  tag = "Transport:";
  pos1 = tag.length();

  for(int j = 1; j < sdpl.count(); j++)
  {
    curLine = sdpl.at(j);
    
    if(curLine.left(pos1) == tag)
    {
      pos1 = curLine.indexOf("server_port=") + QString("server_port=").length();
      pos2 = curLine.indexOf(";", pos1);
      QString s = curLine.mid(pos1, pos2 - pos1);
      int p = s.indexOf("-");
      if(p > 0)
      {
        sdp->FirstServerPort = s.left(p).toInt(cnv, 10);
        sdp->LastServerPort = s.right(s.length() - p - 1).toInt(cnv, 10);
      }
      else
      {
        sdp->FirstServerPort = s.toInt(cnv, 10);
        sdp->LastServerPort = sdp->FirstServerPort;
      }

      break;
    }
  }
  
  /* если все ОК, то возвращаем код 200 */
  return 200;
  
}

#endif // SV_SDPPARSER

