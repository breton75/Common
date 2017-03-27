#ifndef SV_DEVICEBRAND_H
#define SV_DEVICEBRAND_H

#include <QDialog>
#include <QSqlError>
#include <QString>
#include "ui_devicebrand.h"

namespace Ui {
  class SvBrandDialog;
}

class SvBrand : public QDialog
{
    Q_OBJECT
    
  public:
    enum ShowMode { smNew = 0, smEdit = 1 };
                    
    explicit SvBrand(QWidget *parent,
                     QString brandName = "",
                     QString description = "",
                     int id = -1,
                     int showMode = smNew);
    
    ~SvBrand();
    
    int showMode;
    
    int     t_id;
    QString t_brandName;
    QString t_description;
    
  public slots:
    virtual void accept();
    
  private:
    Ui::SvBrandDialog *Dialog;
};

#endif // SV_DEVICEBRAND_H
