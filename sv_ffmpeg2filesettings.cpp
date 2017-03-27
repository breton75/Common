#include "sv_ffmpeg2filesettings.h"

SvFFmpeg2FileSettings* FF2F_SETTINGS_UI;

SvFFmpeg2FileSettings::SvFFmpeg2FileSettings(void* deviceName,
                                             void* mediaLink,
                                             void* ip,
                                             void* port,
                                             void *settings) :
  ff2f(new Ui::SvFFmpeg2FileSettingsDialog)
{
  
  this->p_data = new QByteArray();
  this->p_data = (QByteArray*)(settings);
  
  this->p_settings = new FFmpegSettings;
  this->p_settings->device_name = *(QString*)deviceName;
  this->p_settings->media_link = *(QString*)(mediaLink);
  this->p_settings->ip = *(QString*)(ip);
  this->p_settings->port = *(quint16*)(port);
  
//  if(this->p_parseConfig()) return;
  
  ff2f->setupUi(this, this->p_settings);
  
  connect(ff2f->bnOk, SIGNAL(pressed()), this, SLOT(accept()));
  connect(ff2f->bnCancel, SIGNAL(pressed()), this, SLOT(reject()));
  
  this->setResult(-1);
  this->setModal(true);
  this->show();
  
}

SvFFmpeg2FileSettings::~SvFFmpeg2FileSettings()
{
  this->close();
  this->deleteLater();
}

int SvFFmpeg2FileSettings::p_parseConfig()
{
 
//  QBuffer buf = QBuffer(this->p_data);
//  QByteArray data;
  
////  QDataStream ds = QDataStream(this->cfgData, QIODevice::ReadOnly);
  
//  quint32 sz;
////  quint32 seek = 0;
  
//  buf.seek(0);
  
//  /* ip */
//  buf.read(&sz, sizeof(sz));
////  seek += sizeof(sz);

////  buf.seek(seek);
//  data = buf.read(sz);
//  this->p_settings->ip.append(data);
////  seek += sz;
  
//  /* port */
//  buf.read(&this->config->port, sizeof(this->config->port));
////  seek += sizeof(this->config->port);
  
//  /* db_name */
//  buf.read(&sz, sizeof(sz));
////  seek += sizeof(sz);
  
//  data.clear();
//  data = buf.read(sz);
//  this->config->db_name.append(data);
////  seek += sz;
  
//  /* user_name */
//  buf.read(&sz, sizeof(sz));
////  seek += sizeof(sz);
  
//  data.clear();
//  data = buf.read(sz);
//  this->config->user_name.append(data);
  
  
//  /* pass */
//  buf.read(&sz, sizeof(sz));
////  seek += sizeof(sz);
  
//  data.clear();
//  data = buf.read(sz);
//  this->p_settings->pass.append(data); 
  
//  /* list of devices id */
//  buf.read(&sz, sizeof(sz));
  
//  for(int i = 0; i < sz; i++)
//  {
//    int dev_id;
//    buf.read(&dev_id, sizeof(int));
//    this->p_settings->devices.append(dev_id);
//  }
  
//  /* list of tables id */
//  buf.read(&sz, sizeof(sz));
  
//  for(int i = 0; i < sz; i++)
//  {
//    int table_id;
//    buf.read(&table_id, sizeof(int));
//    this->p_settings->devices.append(table_id);
//  }  
  
//  /* arch_config */ 
//  buf.read(&sz, sizeof(sz));
  
//  this->p_settings->arch_config.clear();
//  this->p_settings->arch_config = buf.read(sz);  
  
}

int SvFFmpeg2FileSettings::p_packConfig()
{
//  this->p_settings->ip = dlg->editIP->text();
//  this->p_settings->port = dlg->editPort->text().toInt();
//  this->p_settings->db_name = dlg->editDbName->text();
//  this->p_settings->user_name = dlg->editUserName->text();
//  this->p_settings->pass = dlg->editPassword->text();
  
//  /* this->config->devices - заполняется при добавлении устройств */ 
//  /* this->config->tables - заполняется при добавлении таблиц */
  
//  QBuffer buf = QBuffer(this->cfgData);
//  QByteArray data;
  
////  QDataStream ds = QDataStream(this->cfgData, QIODevice::ReadOnly);
  
//  quint32 sz;
////  quint32 seek = 0;
  
//  buf.seek(0);
  
//  /* ip */
//  buf.read(&sz, sizeof(sz));
////  seek += sizeof(sz);

////  buf.seek(seek);
//  data = buf.read(sz);
//  this->p_settings->ip.append(data);
////  seek += sz;
  
//  /* port */
//  buf.read(&this->p_settings->port, sizeof(this->p_settings->port));
////  seek += sizeof(this->config->port);
  
//  /* db_name */
//  buf.read(&sz, sizeof(sz));
////  seek += sizeof(sz);
  
//  data.clear();
//  data = buf.read(sz);
//  this->p_settings->db_name.append(data);
////  seek += sz;
  
//  /* user_name */
//  buf.read(&sz, sizeof(sz));
////  seek += sizeof(sz);
  
//  data.clear();
//  data = buf.read(sz);
//  this->p_settings->user_name.append(data);
  
  
//  /* pass */
//  buf.read(&sz, sizeof(sz));
////  seek += sizeof(sz);
  
//  data.clear();
//  data = buf.read(sz);
//  this->p_settings->pass.append(data); 
  
//  /* list of devices id */
//  buf.read(&sz, sizeof(sz));
  
//  for(int i = 0; i < sz; i++)
//  {
//    int dev_id;
//    buf.read(&dev_id, sizeof(int));
//    this->p_settings->devices.append(dev_id);
//  }
  
//  /* list of tables id */
//  buf.read(&sz, sizeof(sz));
  
//  for(int i = 0; i < sz; i++)
//  {
//    int table_id;
//    buf.read(&table_id, sizeof(int));
//    this->p_settings->devices.append(table_id);
//  }  
  
//  /* arch_config */ 
//  buf.read(&sz, sizeof(sz));
  
//  this->p_settings->arch_config.clear();
//  this->p_settings->arch_config = buf.read(sz);  
  
}
