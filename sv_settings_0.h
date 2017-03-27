#ifndef SVSETTINGS_H
#define SVSETTINGS_H

#include <QObject>
#include <QSettings>
#include <QString>

class SvSettings : public QObject
{
    Q_OBJECT
  public:
    explicit SvSettings(QString fileName = "",
                        QSettings::Format format = QSettings::IniFormat,
                        QString organizationName = "",
                        QString organizationDomain = "",
                        QString setAppName = "",
                        QObject *parent = 0);
    
    ~SvSettings();
    
    QSettings *appSettings;
    
    virtual void writeValue(QString GroupName, QString ValueName, int Value);
    virtual void writeValue(QString GroupName, QString ValueName, QString Value);
    
//    int readValue(QString GroupName, QString ValueName);
    QVariant readValue(QString GroupName, QString ValueName, QVariant DefaultValue);
    
    
  signals:
    
  public slots:
   
    
};

#endif // SVSETTINGS_H
