#include "sv_dev_models_list.h"

#include "sv_pgdb.h"
#include "log.h"
//#include "sql_select_defs.h"
#include "sv_dev_model.h"

#include <QMessageBox>


using namespace log_ns;
using namespace sql_select_defs;
using namespace sql_insert_defs;

SvDevModelsList *DEVMODELSLIST_UI;
extern SvPGDB *PGDB;
extern SvDevModel *DEVMODEL_UI;

SvDevModelsList::SvDevModelsList(QWidget *parent, bool showEditDelete, bool showSelect) :
  QDialog(parent),
  Dialog(new Ui::SvDevModelsListDialog)
{
  
  Dialog->setupUi(this);
    
  Dialog->bnEditModel->setVisible(showEditDelete);
  Dialog->bnDeleteModel->setVisible(showEditDelete);
  Dialog->bnSelect->setVisible(showSelect);
  
  connect(Dialog->bnSelect, SIGNAL(pressed()), this, SLOT(accept()));
  connect(Dialog->bnClose, SIGNAL(pressed()), this, SLOT(reject()));
  connect(Dialog->bnNewModel, SIGNAL(pressed()), this, SLOT(slotNewModel()));
  connect(Dialog->bnEditModel, SIGNAL(pressed()), this, SLOT(slotEditModel()));
  connect(Dialog->bnDeleteModel, SIGNAL(pressed()), this, SLOT(slotDeleteModel()));
  
  m_dev_models_list = new QSqlQueryModel();
  setModelListTable(m_dev_models_list, Dialog->tblModelsList);
  
  this->setResult(-1);
  this->setModal(true);
  this->show();

}

SvDevModelsList::~SvDevModelsList()
{
  this->close();
  delete Dialog;
}

void SvDevModelsList::accept()
{
  QSqlRecord r = m_dev_models_list->record(Dialog->tblModelsList->currentIndex().row());
  
  t_id = r.value("id").toInt();
  t_modelName = r.value("model_name").toString();
  t_className = r.value("class_name").toString();
  t_brandName = r.value("brand_name").toString();
  t_libPath   = r.value("model_lib_path").toString();
  t_default_port = r.value("default_port").toInt();
  t_description = r.value("description").toString();
  
  QDialog::accept();
  
}

void SvDevModelsList::slotNewModel()
{
  DEVMODEL_UI = new SvDevModel(this);
  connect(DEVMODEL_UI, SIGNAL(accepted()), this, SLOT(on_DEVMODEL_UI_closed()));
  connect(DEVMODEL_UI, SIGNAL(rejected()), this, SLOT(on_DEVMODEL_UI_closed()));
}
  
void SvDevModelsList::on_DEVMODEL_UI_closed()
{
  if(DEVMODEL_UI->result() == QDialog::Accepted)
  {
    setModelListTable(m_dev_models_list, Dialog->tblModelsList);
  }
  
  DEVMODEL_UI->~SvDevModel();
  
}

void SvDevModelsList::slotEditModel()
{

}

void SvDevModelsList::slotDeleteModel()
{

}

int setModelListTable(QSqlQueryModel* queryModel, QTableView* table)
{
  /* ----------- model_list -------------*/
  
  QSqlError err = PGDB->execSQL(SELECT_DEV_MODELS_LIST, queryModel);
  if(err.type() != QSqlError::NoError) return -1;
  
  table->setModel(queryModel);
  
  QStringList headers = QString(DEV_MODELS_COLUMN_LIST).split(';');
  
  for(int i = 0; i < headers.count(); i++)
    queryModel->setHeaderData(i,  Qt::Horizontal, headers.at(i));

  return 0;
}
