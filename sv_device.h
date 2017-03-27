#ifndef SV_DEVICETYPE_H
#define SV_DEVICETYPE_H

#include <QDialog>
#include <QSqlError>
#include <QString>
#include "ui_device.h"

namespace Ui {
  class SvDeviceDialog;
}

class SvDevice : public QDialog
{
    Q_OBJECT
    
  public:
    enum ShowMode { smNew = 0, smEdit = 1 };
                    
    explicit SvDevice(QWidget *parent,
                      QString deviceName = "",
                      QString ip = "",
                      int port = 0,
                      QString deviceClass = "",
                      QString deviceModel = "",
                      QString deviceBrand = "",
                      QString libPath = "",
                      QString description = "",
                      int locationX = 0,
                      int locationY = 0,
                      int locationZ = 0,
                      int id = -1,
                      int showMode = smNew);
    
    explicit SvDevice(QWidget *parent,
                      int id,
                      int showMode = smEdit);    
    
    ~SvDevice();
    
    int showMode;
    
    int     t_id;
    QString t_deviceName;
    QString t_ip;
    int t_port;
    int t_model_id = -1; // модель может быть не выбрана
    QString t_modelName;
    QString t_className;
    QString t_brandName;
    QString t_libPath;
    int     t_X;
    int     t_Y;
    int     t_Z;
    QString t_description;
    
     
  private slots:
    void on_DEVMODELSLIST_UI_closed();
    void on_DEVMODEL_UI_closed();
    
  public slots:
    virtual void accept() Q_DECL_OVERRIDE;
    void slotNewModel();
    void slotSelectModel();
    
  private:
    Ui::SvDeviceDialog *Dialog;

};

#endif // SV_DEVICETYPE_H
