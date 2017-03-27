#include "sv_dev_brand.h"
#include "ui_device.h"
#include "sv_pgdb.h"
#include "log.h"
//#include "sql_select_defs.h"
#include "sv_dev_models_list.h"
//#include <qdebug.h>

#include <QMessageBox>

using namespace log_ns;
using namespace sql_insert_defs;

SvBrand *DEVBRAND_UI;
extern SvPGDB *PGDB;

SvBrand::SvBrand(QWidget *parent,
                 QString brandName,
                 QString description,
                 int id,
                 int showMode) :
  
  QDialog(parent),
  Dialog(new Ui::SvBrandDialog)
{
  
  Dialog->setupUi(this,
                  brandName,
                  description,
                  id,
                  showMode);  
  
  this->showMode = showMode;
  
  connect(Dialog->bnSave, SIGNAL(pressed()), this, SLOT(accept()));
  connect(Dialog->bnCancel, SIGNAL(pressed()), this, SLOT(reject()));
  
  this->setResult(-1);
  this->setModal(true);
  this->show();

}

SvBrand::~SvBrand()
{
  this->close();
  delete Dialog;
}

void SvBrand::accept()
{
  t_id = Dialog->editID->text().toInt();
  t_brandName  = Dialog->editBrandName->text();
  t_description = Dialog->textDescription->toPlainText();
  
  QString s;
  switch(this->showMode)
  {
    case smNew:
    {
      s = QString(INSERT_INTO_DEV_BRANDS)
          .arg(t_brandName)
          .arg(t_description);
      
      break;
    }
      
    case smEdit:
    {
      
      break;
    }
  }
  
  QSqlError err = PGDB->execSQL(s);

  if (err.type() != QSqlError::NoError) QDialog::reject(); // this->setResult(QDialog::Rejected);
  else QDialog::accept(); //this->setResult(QDialog::Accepted);
  
}

