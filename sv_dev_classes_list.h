#ifndef SV_CLASSESLIST_H
#define SV_CLASSESLIST_H

#include <QDialog>
#include <QSqlError>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlQuery>

#include "ui_classeslist.h"

int setClassListTable(QSqlQueryModel* queryModel, QTableView* table);

namespace Ui {
  class SvDevClassesListDialog;
}

class SvDevClassesListDialog : public QDialog
{
    Q_OBJECT
    
  public:
    enum ShowMode { smNew = 0, smEdit = 1 };
                    
    explicit SvDevClassesListDialog(QWidget *parent,
                                    bool showEditDelete = false,
                                    bool showSelect = true);
    
    ~SvDevClassesListDialog();
    
    int     t_id;
    QString t_className;
    QString t_description;
    
    QSqlQueryModel *m_dev_classes_list;
    
  private slots:
    void on_DEVCLASS_UI_closed();
    
  public slots:
    virtual void accept() Q_DECL_OVERRIDE;
    
    void slotNewClass();
    void slotEditClass();
    void slotDeleteClass();
    
  private:
    Ui::SvDevClassesListDialog *Dialog;
};

#endif // SV_CLASSESLIST_H
