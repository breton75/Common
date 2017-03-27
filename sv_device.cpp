#include "sv_device.h"
#include "ui_device.h"
#include "sv_pgdb.h"
#include "log.h"
#include "sv_dev_model.h"
#include "sv_dev_models_list.h"

#include <QMessageBox>
#include <QDebug>

using namespace log_ns;
using namespace sql_insert_defs;
using namespace sql_select_defs;

SvDevice *DEV_UI;
extern SvPGDB *PGDB;
extern SvDevModelsList *DEVMODELSLIST_UI;
extern SvDevModel* DEVMODEL_UI;

SvDevice::SvDevice(QWidget *parent,
                   QString deviceName,
                   QString ip,
                   int port,
                   QString deviceClass,
                   QString deviceModel,
                   QString deviceBrand,
                   QString libPath,
                   QString description,
                   int locationX,
                   int locationY,
                   int locationZ,
                   int id,
                   int showMode) :
  QDialog(parent),
  Dialog(new Ui::SvDeviceDialog)
{
  
  Dialog->setupUi(this,
                   deviceName,
                   ip,
                   port,
                   deviceModel,
                   deviceClass,
                   deviceBrand,
                   libPath,
                   description,
                   locationX,
                   locationY,
                   locationZ,
                   id,
                   showMode);  
  
  this->showMode = showMode;
  
  connect(Dialog->bnSave, SIGNAL(pressed()), this, SLOT(accept()));
  connect(Dialog->bnCancel, SIGNAL(pressed()), this, SLOT(reject()));
  connect(Dialog->bnNewModel, SIGNAL(pressed()), this, SLOT(slotNewModel()));
  connect(Dialog->bnSelectModel, SIGNAL(pressed()), this, SLOT(slotSelectModel()));
  
  this->setResult(-1);
  this->setModal(true);
  this->show();
  

}

SvDevice::SvDevice(QWidget *parent,
                   int id,
                   int showMode) :
  QDialog(parent),
  Dialog(new Ui::SvDeviceDialog)
{
  
  QSqlQuery* query = new QSqlQuery(PGDB->db);
  PGDB->execSQL(QString(SELECT_FROM_DEVICES_WHERE).arg(id), query);
  
  query->first();
  QSqlRecord rec = query->record();
  
  
  Dialog->setupUi(this,
                   query->value(F_DEVICE_NAME).toString(),
                   query->value(F_DEVICE_IP).toString(),
                   query->value(F_DEVICE_PORT).toInt(),
                   query->value(F_MODEL_NAME).toString(),
                   query->value(F_CLASS_NAME).toString(),
                   query->value(F_BRAND_NAME).toString(),
                   query->value(F_MODEL_LIB).toString(),
                   query->value(F_DEVICE_DESCRIPT).toString(),
                   query->value(F_DEVICE_POSX).toInt(),
                   query->value(F_DEVICE_POSY).toInt(),
                   query->value(F_DEVICE_POSZ).toInt(),
                   query->value(F_DEVICE_ID).toInt(),
                   smEdit);  
  
  this->showMode = showMode;
  
  connect(Dialog->bnSave, SIGNAL(pressed()), this, SLOT(accept()));
  connect(Dialog->bnCancel, SIGNAL(pressed()), this, SLOT(reject()));
  connect(Dialog->bnNewModel, SIGNAL(pressed()), this, SLOT(slotNewModel()));
  connect(Dialog->bnSelectModel, SIGNAL(pressed()), this, SLOT(slotSelectModel()));
  
  this->setResult(-1);
  this->setModal(true);
  this->show();
  

}

SvDevice::~SvDevice()
{
  this->close();
  delete Dialog;
}

void SvDevice::accept()
{
  
  /* делаем всякие проверки вводимых данных */
  if(Dialog->editDevName->text() == "")
  {
    log(m_Critical, "Name of device not set", this);
    Dialog->editDevName->setFocus();
    return;
  }
  
  if(Dialog->editIP->text() == "")
  {
    log(m_Critical, "Incorrect IP address", this);
    Dialog->editIP->setFocus();
    return;
  }  
  
  if((Dialog->editPort->text() == "") || (Dialog->editPort->text().toInt() == 0))
  {
    log(m_Critical, "Incorrect device port", this);
    Dialog->editPort->setFocus();
    return;
  }   
  
  if((Dialog->editClass->text() == "") || (Dialog->editDriver->text() == ""))
  {
    log(m_Critical, "Incorrect device model", this);
    Dialog->bnSelectModel->setFocus();
    return;
  }
  /* конец проверок */
  
  t_id = Dialog->editID->text().toInt();
  t_deviceName = Dialog->editDevName->text();
  t_ip = Dialog->editIP->text();
  t_port = Dialog->editPort->text().toInt();
  t_modelName  = Dialog->editModelName->text();
  t_className  = Dialog->editClass->text();
  t_brandName  = Dialog->editBrand->text();
  t_libPath    = Dialog->editDriver->text();
  t_X = Dialog->sbX->value();
  t_Y = Dialog->sbY->value();
  t_Z = Dialog->sbZ->value();
  t_description = Dialog->textDescription->toPlainText();
  
//  qDebug() << t_id << " " << t_deviceName << " " << t_modelName << " " << t_className << " " << t_X << " " << t_libPath;
  
  QString s;
  QSqlError err;
  switch (this->showMode)
  {
    case smNew:
      s = QString(INSERT_INTO_DEVICES_2)
          .arg(t_deviceName) 
          .arg(t_ip) 
          .arg(t_port)
          .arg(t_modelName) 
          .arg(t_X) 
          .arg(t_Y) 
          .arg(t_Z) 
          .arg(1) 
          .arg(t_description);
      qDebug() << s;
      err = PGDB->execSQL(s);//, new QByteArray, new QByteArray);
      
      break;
      
    smEdit:
      s = QString(UPDATE_DEVICES)
          .arg(t_deviceName) 
          .arg(t_ip) 
          .arg(t_port)
          .arg(t_modelName) 
          .arg(t_X) 
          .arg(t_Y) 
          .arg(t_Z) 
          .arg(1) 
          .arg(t_description);
      qDebug() << s;
      err = PGDB->execSQL(s);
      break;
  }
  
  
  
  
  if (err.type() != QSqlError::NoError) QDialog::reject(); // this->setResult(QDialog::Rejected);
  else QDialog::accept(); // this->setResult(QDialog::Accepted);
  
}

void SvDevice::slotSelectModel()
{
  DEVMODELSLIST_UI = new SvDevModelsList(this, false, true);
  connect(DEVMODELSLIST_UI, SIGNAL(accepted()), this, SLOT(on_DEVMODELSLIST_UI_closed()));
  connect(DEVMODELSLIST_UI, SIGNAL(rejected()), this, SLOT(on_DEVMODELSLIST_UI_closed()));
 }
  
void SvDevice::on_DEVMODELSLIST_UI_closed()
{
  int i = DEVMODELSLIST_UI->result();
  if(i == QDialog::Accepted)
  {
    this->t_model_id = DEVMODELSLIST_UI->t_id;
    Dialog->editModelName->setText(DEVMODELSLIST_UI->t_modelName);
    Dialog->editBrand->setText(DEVMODELSLIST_UI->t_brandName);
    Dialog->editClass->setText(DEVMODELSLIST_UI->t_className);
    Dialog->editDriver->setText(DEVMODELSLIST_UI->t_libPath); 
  }
     
  DEVMODELSLIST_UI->~SvDevModelsList();
  
}

void SvDevice::slotNewModel()
{
  DEVMODEL_UI = new SvDevModel(this);
  connect(DEVMODEL_UI, SIGNAL(accepted()), this, SLOT(on_DEVMODEL_UI_closed()));
  connect(DEVMODEL_UI, SIGNAL(rejected()), this, SLOT(on_DEVMODEL_UI_closed()));
}

void SvDevice::on_DEVMODEL_UI_closed()
{
  if(DEVMODEL_UI ->result() == QDialog::Accepted)
  {
    Dialog->editModelName->setText(DEVMODEL_UI->t_modelName);
    Dialog->editBrand->setText(DEVMODEL_UI->t_brandName);
    Dialog->editClass->setText(DEVMODEL_UI->t_className);
    Dialog->editDriver->setText(DEVMODEL_UI->t_libPath);
  }
  
  DEVMODEL_UI->~SvDevModel();
}
