#include "sv_dev_model.h"
#include "ui_devicemodel.h"
#include "sv_pgdb.h"
#include "log.h"
//#include "sql_select_defs.h"
#include "sv_dev_brand.h"
#include "sv_dev_class.h"
#include "sv_dev_brands_list.h"
#include "sv_dev_classes_list.h"

#include <QMessageBox>

using namespace log_ns;
using namespace sql_insert_defs;

SvDevModel *DEVMODEL_UI;
extern SvPGDB *PGDB;
extern SvBrand *DEVBRAND_UI;
extern SvDeviceClass *DEVCLASS_UI;
extern SvDevBrandsListDialog *DEVBRANDSLIST_UI;
extern SvDevClassesListDialog *DEVCLASSESLIST_UI;

SvDevModel::SvDevModel(QWidget *parent,
                             QString modelName,
                             QString brandName,
                             QString className, 
                             QString libPath,
                             QString description,
                             int dataType,
                             int id,
                             int showMode) :
  QDialog(parent),
  dmDialog(new Ui::SvDeviceModelDialog)
{
  
  dmDialog->setupUi(this,
                    showMode,
                    modelName,
                    className,
                    brandName,
                    libPath,
                    description,
                    dataType,
                    id);  
  
  this->showMode = showMode;
  
  connect(dmDialog->bnOk, SIGNAL(pressed()), this, SLOT(accept()));
  connect(dmDialog->bnCancel, SIGNAL(pressed()), this, SLOT(reject()));
  
  connect(dmDialog->bnNewBrand, SIGNAL(pressed()), this, SLOT(slotNewBrand()));
  connect(dmDialog->bnNewClass, SIGNAL(pressed()), this, SLOT(slotNewClass()));
  connect(dmDialog->bnSelectBrand, SIGNAL(pressed()), this, SLOT(slotSelectBrand()));
  connect(dmDialog->bnSelectClass, SIGNAL(pressed()), this, SLOT(slotSelectClass()));
  connect(dmDialog->bnLibPath, SIGNAL(pressed()), this, SLOT(slotSelectLibPath()));
  
  this->setModal(true);
  this->setResult(-1);
  this->show();
  
}

SvDevModel::~SvDevModel()
{
  this->close();
  delete dmDialog;
}

void SvDevModel::accept()
{
  t_id          = dmDialog->editID->text().toInt();
  t_modelName   = dmDialog->editModelName->text();
  t_brandName   = dmDialog->editBrand->text();
  t_className   = dmDialog->editClass->text();  
  t_libPath     = dmDialog->editLibPath->text();
  t_description = dmDialog->textDescription->toPlainText();
  
  /* делаем всякие проверки вводимых данных */
  if(t_modelName.isEmpty())
  {
    QMessageBox::critical(0, "Error", "Model name not set", QMessageBox::Ok);
    dmDialog->editModelName->setFocus();
    return;
  }
  
  if(t_libPath.isEmpty())
  {
    QMessageBox::critical(0, "Error", "Driver library path not set", QMessageBox::Ok);
    dmDialog->editLibPath->setFocus();
    return;
  }  
  /* конец проверок */  
  
  QString s;
  switch(this->showMode)
  {
    case(smNew):
    {
      s = QString(INSERT_NEW_DEV_MODEL) 
          .arg(t_modelName) 
          .arg(t_className) 
          .arg(t_brandName) 
          .arg(t_libPath) 
          .arg(580)
          .arg(t_description);
    
      break;
    }
      
    case(smEdit):
    {
    
      break;
    }
  }
  
  QSqlError err = PGDB->execSQL(s);

  if(err.type() != QSqlError::NoError) QDialog::reject(); // this->setResult(QDialog::Rejected);
  else QDialog::accept(); // this->setResult(QDialog::Accepted);
  
}

void SvDevModel::slotNewBrand()
{
  DEVBRAND_UI = new SvBrand(this);
  connect(DEVBRAND_UI, SIGNAL(accepted()), this, SLOT(on_DEVBRAND_UI_closed()));
  connect(DEVBRAND_UI, SIGNAL(rejected()), this, SLOT(on_DEVBRAND_UI_closed()));    
}

void SvDevModel::on_DEVBRAND_UI_closed()
{
  if(DEVBRAND_UI->result() == QDialog::Accepted)
  {
    dmDialog->editBrand->setText(DEVBRAND_UI->t_brandName);
    this->t_brandName = DEVBRANDSLIST_UI->t_brandName;
  }
  
  DEVBRAND_UI->~SvBrand();
}


void SvDevModel::slotNewClass()
{
  DEVCLASS_UI = new SvDeviceClass(this);
  connect(DEVCLASS_UI, SIGNAL(accepted()), this, SLOT(on_DEVCLASS_UI_closed()));
  connect(DEVCLASS_UI, SIGNAL(rejected()), this, SLOT(on_DEVCLASS_UI_closed()));  
}

void SvDevModel::on_DEVCLASS_UI_closed()
{
  if(DEVCLASS_UI->result() == QDialog::Accepted)
  {
    dmDialog->editClass->setText(DEVCLASS_UI->t_className);
    this->t_className = DEVCLASS_UI->t_className;
  }
  
  DEVCLASS_UI->~SvDeviceClass();
}

void SvDevModel::slotSelectBrand()
{
  DEVBRANDSLIST_UI = new SvDevBrandsListDialog(this, false, true);
  connect(DEVBRANDSLIST_UI, SIGNAL(accepted()), this, SLOT(on_DEVBRANDSLIST_UI_closed()));
  connect(DEVBRANDSLIST_UI, SIGNAL(rejected()), this, SLOT(on_DEVBRANDSLIST_UI_closed()));  
}
 
void SvDevModel::on_DEVBRANDSLIST_UI_closed()
{
  if(DEVBRANDSLIST_UI->result() == QDialog::Accepted)
  {
    dmDialog->editBrand->setText(DEVBRANDSLIST_UI->t_brandName);
    this->t_brandName = DEVBRANDSLIST_UI->t_brandName;
  }
  DEVBRANDSLIST_UI->~SvDevBrandsListDialog();
}

void SvDevModel::slotSelectClass()
{
  DEVCLASSESLIST_UI = new SvDevClassesListDialog(this, false, true);
  connect(DEVCLASSESLIST_UI, SIGNAL(accepted()), this, SLOT(on_DEVCLASSESLIST_UI_closed()));
  connect(DEVCLASSESLIST_UI, SIGNAL(rejected()), this, SLOT(on_DEVCLASSESLIST_UI_closed()));
}

void SvDevModel::on_DEVCLASSESLIST_UI_closed()
{
  if(DEVCLASSESLIST_UI->result() == QDialog::Accepted)
  {
    dmDialog->editClass->setText(DEVCLASSESLIST_UI->t_className);
    this->t_className = DEVCLASS_UI->t_className;
  }
  
  DEVCLASSESLIST_UI->~SvDevClassesListDialog();
}

void SvDevModel::slotSelectLibPath()
{
  
}


