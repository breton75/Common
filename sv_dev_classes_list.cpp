#include "sv_dev_classes_list.h"

#include "sv_pgdb.h"
#include "log.h"
//#include "mkis_sql_defs.h"
#include "sv_dev_class.h"

#include <QMessageBox>


using namespace log_ns;
using namespace sql_select_defs;
using namespace sql_insert_defs;

SvDevClassesListDialog *DEVCLASSESLIST_UI;
extern SvPGDB *PGDB;
extern SvDeviceClass *DEVCLASS_UI;

SvDevClassesListDialog::SvDevClassesListDialog(QWidget *parent, bool showEditDelete, bool showSelect) :
  QDialog(parent),
  Dialog(new Ui::SvDevClassesListDialog)
{
  
  Dialog->setupUi(this);
  
  m_dev_classes_list = new QSqlQueryModel();
  setClassListTable(m_dev_classes_list, Dialog->tblClassesList);
    
  Dialog->bnEditClass->setVisible(showEditDelete);
  Dialog->bnDeleteClass->setVisible(showEditDelete);
  Dialog->bnSelect->setVisible(showSelect);
  
  connect(Dialog->bnSelect, SIGNAL(pressed()), this, SLOT(accept()));
  connect(Dialog->bnClose, SIGNAL(pressed()), this, SLOT(reject()));
  connect(Dialog->bnNewClass, SIGNAL(pressed()), this, SLOT(slotNewClass()));
  connect(Dialog->bnEditClass, SIGNAL(pressed()), this, SLOT(slotEditClass()));
  connect(Dialog->bnDeleteClass, SIGNAL(pressed()), this, SLOT(slotDeleteClass()));
  
  this->setResult(-1);
  this->setModal(true);
  this->show();
  
}

SvDevClassesListDialog::~SvDevClassesListDialog()
{
  this->close();
  delete Dialog;
}

void SvDevClassesListDialog::accept()
{
  QSqlRecord r = m_dev_classes_list->record(Dialog->tblClassesList->currentIndex().row());
  
  t_id = r.value("id").toInt();
  t_className = r.value("class_name").toString();
  t_description = r.value("description").toString();
  
  QDialog::accept();
  
}

void SvDevClassesListDialog::slotNewClass()
{
  DEVCLASS_UI = new SvDeviceClass(this);
  connect(DEVCLASS_UI, SIGNAL(accepted()), this, SLOT(on_DEVCLASS_UI_closed()));
  connect(DEVCLASS_UI, SIGNAL(rejected()), this, SLOT(on_DEVCLASS_UI_closed()));
}

void SvDevClassesListDialog::on_DEVCLASS_UI_closed()
{
  if(DEVCLASS_UI->result() == QDialog::Accepted)
  {
    m_dev_classes_list->query().execBatch();
  }
  
  DEVCLASS_UI->~SvDeviceClass();
  
}

void SvDevClassesListDialog::slotEditClass()
{

}

void SvDevClassesListDialog::slotDeleteClass()
{

}

int setClassListTable(QSqlQueryModel* queryModel, QTableView* table)
{
  /* ----------- classes_list -------------*/
  
  QSqlError err = PGDB->execSQL(SELECT_DEV_CLASSES_LIST, queryModel);
  if(err.type() != QSqlError::NoError) return -1;
  
  table->setModel(queryModel);
  
  QStringList headers = QString(DEV_CLASSES_COLUMN_LIST).split(';');
  
  for(int i = 0; i < headers.count(); i++)
    queryModel->setHeaderData(i,  Qt::Horizontal, headers.at(i));

  return 0;
}
