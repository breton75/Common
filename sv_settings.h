#ifndef SVSETTINGS_H
#define SVSETTINGS_H

#include <QApplication>
#include <QObject>
#include <QSettings>
#include <QString>
#include <QTextCodec>
#include <QSize>
#include <QPoint>

namespace AppParams
{
  struct WindowParams
  {
    QSize size;
    QPoint position;
    Qt::WindowState state;
  };

  WindowParams readWindowParams(QObject* parent, QString group_name = "MAIN WINDOW", QString file_name = "");
  void saveWindowParams(QObject* parent, QSize size, QPoint position, int state, QString group_name = "MAIN WINDOW", QString file_name = "");
  
  QVariant readParam(QObject* parent, QString group_name, QString param_name, QVariant default_value = QVariant(), QString file_name = "");
  void saveParam(QObject* parent, QString group_name, QString param_name, QVariant value, QString file_name = "");
  
}


class SvSettings : public QObject
{
    Q_OBJECT
  public:
    explicit SvSettings(QString fileName = "",
                        QObject *parent = 0,
                        QSettings::Format format = QSettings::IniFormat,
                        QString organizationName = "",
                        QString organizationDomain = "",
                        QString setAppName = "");
    
    ~SvSettings();
    
    QSettings *appSettings = 0;
    
    void writeValue(QString GroupName, QString ValueName, QVariant Value);
    void writeValue(QString GroupName, QString ValueName, int Value);
    void writeValue(QString GroupName, QString ValueName, QString Value);
    void writeValue(QString GroupName, QString ValueName, QSize Value);
    void writeValue(QString GroupName, QString ValueName, QPoint Value);
    
//    int readValue(QString GroupName, QString ValueName);
    QVariant readValue(QString GroupName, QString ValueName, QVariant DefaultValue);
    
    QTextCodec* codec;
    
  signals:
    
  public slots:
   
    
};

#endif // SVSETTINGS_H
