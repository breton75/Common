#ifndef SV_DEVICECLASS_H
#define SV_DEVICECLASS_H

#include <QDialog>
#include <QSqlError>
#include <QString>
#include "ui_deviceclass.h"

namespace Ui {
  class SvClassDialog;
}

class SvDeviceClass : public QDialog
{
    Q_OBJECT
    
  public:
    enum ShowMode { smNew = 0, smEdit = 1 };
                    
    explicit SvDeviceClass(QWidget *parent,
                           QString className = "",
                           QString classLibPath = "",
                           QString description = "",
                           int id = -1,
                           int showMode = smNew);
    
    ~SvDeviceClass();
    
    int     t_id;
    QString t_className;
    QString t_description;
    
    int show_mode;
     
    
  public slots:
    virtual void accept();
    
  signals:
    sigDeviceAdded(int id);
    sigDeviceDeleted(int id);
    
  private:
    Ui::SvClassDialog *Dialog;
};

#endif // SV_DEVICECLASS_H
