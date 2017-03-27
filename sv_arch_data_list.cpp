#include "sv_arch_data_list.h"
#include "sql_fields_defs.h"
#include "log.h"

#include <QMessageBox>

using namespace log_ns;

SvArchDataList* ARCH_DATA_LIST;

SvArchDataList::SvArchDataList(QWidget *parent) :
  QDialog(parent),
  dlg(new Ui::SvArchDataListDialog)
{
  
  dlg->setupUi(this);
  
  connect(dlg->bnSelect, SIGNAL(pressed()), this, SLOT(accept()));
  connect(dlg->bnClose, SIGNAL(pressed()), this, SLOT(reject()));
  
  QStringList lst;
  lst << A_DATA_VARIABLES
      << A_DATA_USERS
      << A_DATA_EMPLOY
      << A_DATA_EMPLOY_MOVEMENT
      << A_DATA_ZONES;
         
  this->t_model = new QStringListModel(lst);
  dlg->listData->setModel(this->t_model);
  
  this->setResult(-1);
  this->setModal(true);
  this->show();
  
}

SvArchDataList::~SvArchDataList()
{
  this->close();
  delete dlg;
}

void SvArchDataList::accept()
{
//  t_id = ;
//  t_dataName = ;
  
  QDialog::accept();
  
}

