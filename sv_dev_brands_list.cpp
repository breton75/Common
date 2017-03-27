#include "sv_dev_brands_list.h"
#include "sv_pgdb.h"
#include "log.h"
#include "sv_dev_brand.h"

#include <QMessageBox>

using namespace log_ns;
using namespace sql_insert_defs;
using namespace sql_select_defs;

SvDevBrandsListDialog *DEVBRANDSLIST_UI;

extern SvPGDB *PGDB;
extern SvBrand *DEVBRAND_UI;

SvDevBrandsListDialog::SvDevBrandsListDialog(QWidget *parent,
                                             bool showEditDelete,
                                             bool showSelect) :
  QDialog(parent),
  Dialog(new Ui::SvDevBrandsListDialog)
{
  
  Dialog->setupUi(this);
  
  m_dev_brands_list = new QSqlQueryModel();
  setBrandListTable(m_dev_brands_list, Dialog->tblBrandsList);
    
  Dialog->bnEditBrand->setVisible(showEditDelete);
  Dialog->bnDeleteBrand->setVisible(showEditDelete);
  Dialog->bnSelect->setVisible(showSelect);
  
  connect(Dialog->bnSelect, SIGNAL(pressed()), this, SLOT(accept()));
  connect(Dialog->bnClose, SIGNAL(pressed()), this, SLOT(reject()));
  connect(Dialog->bnNewBrand, SIGNAL(pressed()), this, SLOT(slotNewBrand()));
  connect(Dialog->bnClose, SIGNAL(pressed()), this, SLOT(slotEditBrand()));
  connect(Dialog->bnClose, SIGNAL(pressed()), this, SLOT(slotDeleteBrand()));  
  
  this->setResult(-1);
  this->setModal(true);
  this->show();
  

}

SvDevBrandsListDialog::~SvDevBrandsListDialog()
{
  this->close();
  delete Dialog;
}

void SvDevBrandsListDialog::accept()
{
  QSqlRecord r = m_dev_brands_list->record(Dialog->tblBrandsList->currentIndex().row());
  
  t_id = r.value("id").toInt();
  t_brandName = r.value("brand_name").toString();
  t_description = r.value("description").toString();
  
  QDialog::accept();
  
}

void SvDevBrandsListDialog::slotNewBrand()
{
  DEVBRAND_UI = new SvBrand(this);
  connect(DEVBRAND_UI, SIGNAL(accepted()), this, SLOT(on_DEVBRAND_UI_closed()));
  connect(DEVBRAND_UI, SIGNAL(rejected()), this, SLOT(on_DEVBRAND_UI_closed()));
}

void SvDevBrandsListDialog::on_DEVBRAND_UI_closed()
{
  if(DEVBRAND_UI->result() == QDialog::Accepted)
  {
    setBrandListTable(m_dev_brands_list, Dialog->tblBrandsList);
    //m_dev_brands_list->query().execBatch();
//    Dialog->tblBrandsList->c
  }
  DEVBRAND_UI->~SvBrand();

}

void SvDevBrandsListDialog::slotEditBrand()
{
  
}

void SvDevBrandsListDialog::slotDeleteBrand()
{
  
}

int setBrandListTable(QSqlQueryModel* queryModel, QTableView* table)
{
  /* ----------- brand_list -------------*/
  
  QSqlError err = PGDB->execSQL(SELECT_DEV_BRANDS_LIST, queryModel);
  if(err.type() != QSqlError::NoError) return -1;
  
  table->setModel(queryModel);
  
  QStringList headers = QString(DEV_BRANDS_COLUMN_LIST).split(';');
  
  for(int i = 0; i < headers.count(); i++)
    queryModel->setHeaderData(i,  Qt::Horizontal, headers.at(i));

  return 0;
}
