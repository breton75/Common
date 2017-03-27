#ifndef SV_BRANDSLIST_H
#define SV_BRANDSLIST_H

#include <QDialog>
#include <QSqlError>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlQuery>

#include "ui_brandslist.h"

int setBrandListTable(QSqlQueryModel* queryModel, QTableView* table);

namespace Ui {
  class SvDevBrandsListDialog;
}

class SvDevBrandsListDialog : public QDialog
{
    Q_OBJECT
    
  public:
    enum ShowMode { smNew = 0, smEdit = 1 };
                    
    explicit SvDevBrandsListDialog(QWidget *parent,
                                   bool showEditDelete = false,
                                   bool showSelect = false);
    
    ~SvDevBrandsListDialog();
    
    int     t_id;
    QString t_brandName;
    QString t_address;
    QString t_email;
    QString t_site;
    QString t_description;
    
    QSqlQueryModel *m_dev_brands_list;
    
  private slots:
    void on_DEVBRAND_UI_closed();
    
  public slots:
    virtual void accept() Q_DECL_OVERRIDE;
    
    void slotNewBrand();
    void slotEditBrand();
    void slotDeleteBrand();

    
  private:
    Ui::SvDevBrandsListDialog *Dialog;
};

#endif // SV_BRANDSLIST_H
