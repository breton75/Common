#include "sv_settings.h"
#include <QVariant>

SvSettings::SvSettings(QString fileName,
                       QSettings::Format format,
                       QString organizationName,
                       QString organizationDomain,
                       QString setAppName,
                       QObject *parent) :
  QObject(parent)
{
  if (fileName != "")
  {
    this->appSettings = new QSettings(fileName, format);
  }
  else
  {
    this->appSettings = new QSettings();
  }

  
}

SvSettings::~SvSettings()
{
  this->deleteLater();
}

void SvSettings::writeValue(QString GroupName, QString ValueName, int Value)
{
  this->appSettings->beginGroup(GroupName);
  this->appSettings->setValue(ValueName, Value);
  this->appSettings->endGroup();
}

void SvSettings::writeValue(QString GroupName, QString ValueName, QString Value)
{
  this->appSettings->beginGroup(GroupName);
  this->appSettings->setValue(ValueName, Value);
  this->appSettings->endGroup(); 
}

//int SvSettings::readValue(QString GroupName, QString ValueName)
//{
//  int i;
//  this->appSettings.beginGroup(GroupName);
//  i = this->appSettings.value(ValueName, Value);
//  this->appSettings.endGroup(); 
//  return i;
//}

QVariant SvSettings::readValue(QString GroupName, QString ValueName, QVariant DefaultValue)
{
  QVariant v;
  this->appSettings->beginGroup(GroupName);
  v = this->appSettings->value(ValueName, DefaultValue);
  this->appSettings->endGroup(); 
  return v;
}
