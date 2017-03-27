#include "sv_device_list.h"

extern SvPGDB *PGDB;
SvDevicesList *DEVICELIST_UI;
extern SvDevice *DEV_UI;

SvDevicesList::SvDevicesList(QWidget *parent,
//                             QSqlDatabase* db,
                             bool showEditDelete,
                             bool showSelect) :
  QDialog(parent),
  dlg(new Ui::SvDeviceListDialog)
{
  dlg->setupUi(this);
  
  this->p_model_devices = new QSqlQueryModel();
  this->p_tbl_devices = dlg->tblDeviceList;
  
  setDeviceListTable();
  
  dlg->bnEditClass->setVisible(showEditDelete);
  dlg->bnDeleteClass->setVisible(showEditDelete);
  dlg->bnSelect->setVisible(showSelect);
  
  connect(dlg->bnSelect, SIGNAL(pressed()), this, SLOT(accept()));
  connect(dlg->bnClose, SIGNAL(pressed()), this, SLOT(reject()));
  connect(dlg->bnNewClass, SIGNAL(pressed()), this, SLOT(slotNewDevice()));
  connect(dlg->bnEditClass, SIGNAL(pressed()), this, SLOT(slotEditDevice()));
  connect(dlg->bnDeleteClass, SIGNAL(pressed()), this, SLOT(slotDeleteDevice()));
  
  this->setResult(-1);
  this->setModal(true);
  this->show();
}

SvDevicesList::~SvDevicesList()
{
  this->close();
  delete dlg;
}

void SvDevicesList::accept()
{
  QSqlRecord r = this->p_model_devices->record(dlg->tblDeviceList->currentIndex().row());
  
  t_id = r.value(F_DEVICE_ID).toInt();
  t_deviceName = r.value(F_DEVICE_NAME).toString();
  t_ip = r.value(F_DEVICE_IP).toString();
  t_port = r.value(F_DEVICE_PORT).toInt();
  t_modelId = r.value(F_DEVICE_MODEL_ID).toInt();
  t_modelName = r.value(F_MODEL_NAME).toString();
  t_className = r.value(F_CLASS_NAME).toString();    
  t_brandName = r.value(F_BRAND_NAME).toString();    
  t_libPath = r.value(F_MODEL_LIB).toString();    
  t_X = r.value(F_DEVICE_POSX).toInt();
  t_Y = r.value(F_DEVICE_POSY).toInt();    
  t_Z = r.value(F_DEVICE_POSZ).toInt();    
  t_description = r.value(F_DEVICE_DESCRIPT).toString();
  
  QDialog::accept();
}

void SvDevicesList::slotNewDevice()
{
  DEV_UI = new SvDevice(this);
  connect(DEV_UI, SIGNAL(accepted()), this, SLOT(on_DEV_UI_closed()));
  connect(DEV_UI, SIGNAL(rejected()), this, SLOT(on_DEV_UI_closed()));
}

void SvDevicesList::on_DEV_UI_closed()
{
  if(DEV_UI->result() == QDialog::Accepted)
  {
    this->setDeviceListTable();
  }
  
  DEV_UI->~SvDevice();
}

void SvDevicesList::slotEditDevice()
{
  DEV_UI = new SvDevice(this, this->p_model_devices->query().value(F_DEVICE_ID).toInt());
  connect(DEV_UI, SIGNAL(accepted()), this, SLOT(on_DEV_UI_closed()));
  connect(DEV_UI, SIGNAL(rejected()), this, SLOT(on_DEV_UI_closed()));
}

void SvDevicesList::slotDeleteDevice()
{
  
}


int SvDevicesList::setDeviceListTable(/*QSqlQueryModel* queryModel, QTableView* table*/)
{
  /* ----------- dev_list -------------*/
  
  QSqlError err = PGDB->execSQL(SELECT_DEVICE_LIST, this->p_model_devices);
  if(err.type() != QSqlError::NoError) return -1;
  
  this->p_tbl_devices->setModel(this->p_model_devices);
  
  QStringList headers = QString(DEVICES_COLUMN_LIST).split(';');
  
  for(int i = 0; i < headers.count(); i++)
  {
    this->p_model_devices->setHeaderData(i,  Qt::Horizontal, headers.at(i).section("/", 1, 1));
    this->p_tbl_devices->setColumnHidden(i, !(headers.at(i).section('/', 2, 2) == "true"));
  }

  return 0;
}
