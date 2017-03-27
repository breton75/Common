#ifndef PARSE_PACK_CONFIG
#define PARSE_PACK_CONFIG

int SvArchConfigurator::p_parseConfig()
{
  this->config = new ArchConfiguration;
  
  QBuffer buf = QBuffer(this->cfgData);
  QByteArray data;
  
//  QDataStream ds = QDataStream(this->cfgData, QIODevice::ReadOnly);
  
  quint32 sz;
//  quint32 seek = 0;
  
  buf.seek(0);
  
  /* ip */
  buf.read(&sz, sizeof(sz));
//  seek += sizeof(sz);

//  buf.seek(seek);
  data = buf.read(sz);
  this->config->ip.append(data);
//  seek += sz;
  
  /* port */
  buf.read(&this->config->port, sizeof(this->config->port));
//  seek += sizeof(this->config->port);
  
  /* db_name */
  buf.read(&sz, sizeof(sz));
//  seek += sizeof(sz);
  
  data.clear();
  data = buf.read(sz);
  this->config->db_name.append(data);
//  seek += sz;
  
  /* user_name */
  buf.read(&sz, sizeof(sz));
//  seek += sizeof(sz);
  
  data.clear();
  data = buf.read(sz);
  this->config->user_name.append(data);
  
  
  /* pass */
  buf.read(&sz, sizeof(sz));
//  seek += sizeof(sz);
  
  data.clear();
  data = buf.read(sz);
  this->config->pass.append(data); 
  
  /* list of devices id */
  buf.read(&sz, sizeof(sz));
  
  for(int i = 0; i < sz; i++)
  {
    int dev_id;
    buf.read(&dev_id, sizeof(int));
    this->config->devices.append(dev_id);
  }
  
  /* list of tables id */
  buf.read(&sz, sizeof(sz));
  
  for(int i = 0; i < sz; i++)
  {
    int table_id;
    buf.read(&table_id, sizeof(int));
    this->config->devices.append(table_id);
  }  
  
  /* arch_config */ 
  buf.read(&sz, sizeof(sz));
  
  this->config->arch_config.clear();
  this->config->arch_config = buf.read(sz);  
  
}

int SvArchConfigurator::p_packConfig()
{
  this->config->ip = dlg->editIP->text();
  this->config->port = dlg->editPort->text().toInt();
  this->config->db_name = dlg->editDbName->text();
  this->config->user_name = dlg->editUserName->text();
  this->config->pass = dlg->editPassword->text();
  
  /* this->config->devices - заполняется при добавлении устройств */ 
  /* this->config->tables - заполняется при добавлении таблиц */
  
  QBuffer buf = QBuffer(this->cfgData);
  QByteArray data;
  
//  QDataStream ds = QDataStream(this->cfgData, QIODevice::ReadOnly);
  
  quint32 sz;
//  quint32 seek = 0;
  
  buf.seek(0);
  
  /* ip */
  buf.read(&sz, sizeof(sz));
//  seek += sizeof(sz);

//  buf.seek(seek);
  data = buf.read(sz);
  this->config->ip.append(data);
//  seek += sz;
  
  /* port */
  buf.read(&this->config->port, sizeof(this->config->port));
//  seek += sizeof(this->config->port);
  
  /* db_name */
  buf.read(&sz, sizeof(sz));
//  seek += sizeof(sz);
  
  data.clear();
  data = buf.read(sz);
  this->config->db_name.append(data);
//  seek += sz;
  
  /* user_name */
  buf.read(&sz, sizeof(sz));
//  seek += sizeof(sz);
  
  data.clear();
  data = buf.read(sz);
  this->config->user_name.append(data);
  
  
  /* pass */
  buf.read(&sz, sizeof(sz));
//  seek += sizeof(sz);
  
  data.clear();
  data = buf.read(sz);
  this->config->pass.append(data); 
  
  /* list of devices id */
  buf.read(&sz, sizeof(sz));
  
  for(int i = 0; i < sz; i++)
  {
    int dev_id;
    buf.read(&dev_id, sizeof(int));
    this->config->devices.append(dev_id);
  }
  
  /* list of tables id */
  buf.read(&sz, sizeof(sz));
  
  for(int i = 0; i < sz; i++)
  {
    int table_id;
    buf.read(&table_id, sizeof(int));
    this->config->devices.append(table_id);
  }  
  
  /* arch_config */ 
  buf.read(&sz, sizeof(sz));
  
  this->config->arch_config.clear();
  this->config->arch_config = buf.read(sz);  
  
}


#endif // PARSE_PACK_CONFIG

