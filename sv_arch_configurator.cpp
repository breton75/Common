#include "sv_arch_configurator.h"

#include <QDebug>

using namespace log_ns;

SvArchConfigurator* ARCH_UI;

extern SvDevicesList* DEVICELIST_UI;
extern SvArchDataList* ARCH_DATA_LIST;
extern SvFFmpeg2FileSettings* FF2F_SETTINGS_UI;
SvSettings *sett;

QSqlQuery* q_dev_list;
QSqlQueryModel* q_dev_model;
int device_id;

QList<int> addedDevices;
QList<int> addedData;

QString media_link;

SvArchConfigurator::SvArchConfigurator(void* PGDB,
//                                       void* configuration,
                                       int deviceId) :
  dlg(new Ui::ArchDialog)
{
  
  dlg->setupUi(this);
  
  connect(dlg->bnSave, SIGNAL(pressed()), this, SLOT(accept()));
  connect(dlg->bnCancel, SIGNAL(pressed()), this, SLOT(reject()));
  
  connect(dlg->bnAddDevice, SIGNAL(pressed()), this, SLOT(slotAddDevice()));
  connect(dlg->bnAddData, SIGNAL(pressed()), this, SLOT(slotAddData()));
  
  connect(dlg->bnDeviceSettings, SIGNAL(pressed()), this, SLOT(slotDeviceSettings()));
  
  connect(this, SIGNAL(finished(int)), this, SLOT(close()));
  
  QString s = QApplication::applicationDirPath() + "/" + QApplication::applicationName() + ".ini";
  sett = new SvSettings(s);

  this->setGeometry(sett->readValue("ARCH_CONGIGURATOR", "Left", 100).toInt(),
                    sett->readValue("ARCH_CONGIGURATOR", "Top", 100).toInt(),
                    sett->readValue("ARCH_CONGIGURATOR", "Width", 480).toInt(),
                    sett->readValue("ARCH_CONGIGURATOR", "Height", 430).toInt());
  
  addedDevices.clear();
  addedData.clear();

  this->setModal(true);
  this->setResult(-1);
  this->show();
  
  this->pgdb = (SvPGDB*)(PGDB);
//  this->cfgData = (QByteArray*)configuration;
  
  this->p_configured_device_id = deviceId;  
  
//  this->p_query_devices = new QSqlQuery(*db);
  this->p_model_devices = new QSqlQueryModel();
  
//  this->p_query_data = new QSqlQuery(*db);
  this->p_model_data = new QSqlQueryModel();

  this->p_tbl_devices = dlg->tblDevices;
  this->p_tbl_data = dlg->tblData;  

  log_ns::log(m_Attention, "dsdsds");
  this->setDeviceListTable();

      
}

SvArchConfigurator::~SvArchConfigurator()
{
  this->close();
  this->deleteLater();
}

void SvArchConfigurator::close()
{ 
  /* если пользователь нажал Cancel, то удаляем добавленные устройства и таблицы */
  if(this->result() != QDialog::Accepted)
  {
    
    if(addedDevices.count() > 0)
    {
      QString s = "";
      for(int i = 0; i < addedDevices.count(); i++)
        s = s + (i == 0 ? "" : ",") + QString("%1").arg(addedDevices.at(i));      
    
      this->pgdb->execSQL(QString(DELETE_FROM_ARCH_WHERE_IN).arg(ARCH_TYPE_DEVICE).arg(s));
    }
    
    if(addedData.count() > 0)
    {
      QString s = "";
      for(int i = 0; i < addedData.count(); i++)
        s = s + (i == 0 ? "" : ",") + QString("%1").arg(addedData.at(i));      
    
      this->pgdb->execSQL(QString(DELETE_FROM_ARCH_WHERE_IN).arg(ARCH_TYPE_DATA).arg(s));
    }
  }
  
  sett->writeValue("ARCH_CONGIGURATOR", "Left", this->geometry().left());
  sett->writeValue("ARCH_CONGIGURATOR", "Top", this->geometry().top());
  sett->writeValue("ARCH_CONGIGURATOR", "Width", this->geometry().width());
  sett->writeValue("ARCH_CONGIGURATOR", "Height", this->geometry().height());
}

void SvArchConfigurator::accept()
{
  
  
  QDialog::accept();
}

int SvArchConfigurator::setDeviceListTable()
{
  /* ----------- dev_list -------------*/
 
  QSqlError err = this->pgdb->execSQL(QString(SELECT_FROM_ARCH_WHERE)
                                                          .arg(ARCH_TYPE_DEVICE)
                                                          .arg(this->p_configured_device_id),
                                      this->p_model_devices);
  
  if(err.type() != QSqlError::NoError) return -1;
  
  this->p_tbl_devices->setModel(this->p_model_devices);
  
  QStringList headers = QString(ARCH_DEVICES_COLUMN_LIST).split(';');
  for(int i = 0; i < headers.count(); i++)
  {
      this->p_model_devices->setHeaderData(i,  Qt::Horizontal, headers.at(i).section("/", 1, 1));
      this->p_tbl_devices->setColumnHidden(i, !(headers.at(i).section('/', 2, 2) == "true"));
  }
  
  return 0;
}

void SvArchConfigurator::slotAddDevice()
{
  DEVICELIST_UI = new SvDevicesList(this);
  connect(DEVICELIST_UI, SIGNAL(accepted()), this, SLOT(on_DEVICELIST_UI_closed()));
  connect(DEVICELIST_UI, SIGNAL(rejected()), this, SLOT(on_DEVICELIST_UI_closed()));
}

void SvArchConfigurator::on_DEVICELIST_UI_closed()
{
  if(DEVICELIST_UI->result() == QDialog::Accepted)
  {
    this->pgdb->execSQL(QString(INSERT_INTO_ARCH_DEVICE).arg(this->p_configured_device_id)
                                                        .arg(ARCH_TYPE_DEVICE)
                                                        .arg(DEVICELIST_UI->t_id));
    addedDevices.append(DEVICELIST_UI->t_id);
    this->setDeviceListTable();
  }
  
  DEVICELIST_UI->~SvDevicesList();
}

void SvArchConfigurator::slotAddData()
{
  ARCH_DATA_LIST = new SvArchDataList(this);
  connect(ARCH_DATA_LIST, SIGNAL(accepted()), this, SLOT(on_ARCH_DATA_LIST_closed()));
  connect(ARCH_DATA_LIST, SIGNAL(rejected()), this, SLOT(on_ARCH_DATA_LIST_closed()));
}

void SvArchConfigurator::on_ARCH_DATA_LIST_closed()
{
  if(ARCH_DATA_LIST->result() == QDialog::Accepted)
  {
//    this->pgdb->execSQL(QString(INSERT_INTO_ARCH_DEVICE).arg(this->p_configured_device_id)
//                                                        .arg(ARCH_TYPE_DEVICE)
//                                                        .arg(DEVICELIST_UI->t_id));
    addedData.append(ARCH_DATA_LIST->t_id);
//    this->setDataListTable();
  }
  
  ARCH_DATA_LIST->~SvArchDataList();
}


void SvArchConfigurator::slotDeviceSettings()
{
  
  this->ff2f_settings.device_name = this->p_model_devices->query().value(F_DEVICE_NAME).toString();
  this->ff2f_settings.media_link = "media link";
  this->ff2f_settings.ip = this->p_model_devices->query().value(F_DEVICE_IP).toString();
  this->ff2f_settings.port = this->p_model_devices->query().value(F_DEVICE_PORT).toInt();
  this->ff2f_settings.settings = this->p_model_devices->query().value(F_DEVICE_ARCH_CONFIG).toByteArray();
  
  FF2F_SETTINGS_UI = new SvFFmpeg2FileSettings(&this->ff2f_settings.device_name,
                                               &this->ff2f_settings.media_link,
                                               &this->ff2f_settings.ip,
                                               &this->ff2f_settings.port,
                                               &this->ff2f_settings.settings);
  
  
}









