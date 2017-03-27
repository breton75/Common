#include "sv_dev_class.h"
#include "sv_pgdb.h"
#include "log.h"
//#include "sql_select_defs.h"
//#include <qdebug.h>

#include <QMessageBox>

using namespace log_ns;
using namespace sql_insert_defs;

SvDeviceClass *DEVCLASS_UI;
extern SvPGDB *PGDB;

SvDeviceClass::SvDeviceClass(QWidget *parent,
                             QString className,
                             QString classLibPath,
                             QString description,
                             int id,
                             int showMode) :
  
  QDialog(parent),
  Dialog(new Ui::SvClassDialog)
{
  
  this->show_mode = showMode;
  
  Dialog->setupUi(this,
                  className,
                  classLibPath,
                  description,
                  id,
                  this->show_mode);  
  
  connect(Dialog->bnSave, SIGNAL(pressed()), this, SLOT(accept()));
  connect(Dialog->bnCancel, SIGNAL(pressed()), this, SLOT(reject()));
  
  this->setResult(-1);
  this->setModal(true);
  this->show();

}

SvDeviceClass::~SvDeviceClass()
{
  this->close();
  delete Dialog;
}

void SvDeviceClass::accept()
{
  
  if(Dialog->editClassName->text() == "")
  {
    log(m_Critical, "Name of device class not set", this);
    Dialog->editClassName->setFocus();
    return;
  }
  
  t_id =  Dialog->editID->text().toInt();
  t_className  = Dialog->editClassName->text();
  t_description = Dialog->textDescription->toPlainText();
  
  QString s;
  switch(this->show_mode)
  {
    case smNew:

      s = QString(INSERT_INTO_DEV_CLASSES) 
          .arg(t_className) 
          .arg(t_description);

      break;

    case smEdit:
      
      break;
  }
  
  QSqlError err = PGDB->execSQL(s) ;
  
  if (err.type() != QSqlError::NoError) QDialog::reject(); // this->setResult(QDialog::Rejected);
  else QDialog::accept(); //this->setResult(QDialog::Accepted);
  
}

