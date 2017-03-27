#ifndef SV_ARCH_DATA_LIST_H
#define SV_ARCH_DATA_LIST_H

#include <QDialog>
#include <QString>
#include <QStringListModel>

#include "ui_arch_data_list.h"

namespace Ui {
  class SvArchDataListDialog;
}

class SvArchDataList : public QDialog
{
    Q_OBJECT
    
  public:
                    
    explicit SvArchDataList(QWidget *parent);
    
    ~SvArchDataList();
    
    int     t_id;
    QString t_dataName;
    
    QStringListModel* t_model;
    
  public slots:
    virtual void accept() Q_DECL_OVERRIDE;
    
  private:
    Ui::SvArchDataListDialog *dlg;
};

#endif // SV_ARCH_DATA_LIST_H
