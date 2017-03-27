#ifndef SV_DEVMODEL_H
#define SV_DEVMODEL_H

#include <QDialog>
#include <QSqlError>
#include <QString>

namespace Ui {
  class SvDeviceModelDialog;
}

class SvDevModel : public QDialog
{
    Q_OBJECT
    
  private:

    
  public:
    enum ShowMode { smNew = 0, smEdit = 1 };
    enum DataModel { dtMessage = 0, dtStream = 1 }; 
                    
    explicit SvDevModel(QWidget *parent,
                           QString modelName = "",
                           QString brandName = "",
                           QString className = "", 
                           QString libPath = "",
                           QString description = "",
                           int dataType = dtMessage,
                           int id = -1,
                           int showMode = smNew);
    
    ~SvDevModel();
    
    int showMode;
    
    int     t_id = -1;
    QString t_modelName = "";
    QString t_brandName = "";
    QString t_className = "";
    QString t_libPath = "";
    QString t_description = "";
    int     t_dataType = dtMessage;
    
  private slots:
    void on_DEVBRAND_UI_closed();
    void on_DEVBRANDSLIST_UI_closed();
    
    void on_DEVCLASS_UI_closed();
    void on_DEVCLASSESLIST_UI_closed();
    
    
  public slots:
    virtual void accept() Q_DECL_OVERRIDE;
//    virtual void reject();
    
    virtual void slotNewClass();
    virtual void slotSelectClass();
    
    virtual void slotNewBrand();
    virtual void slotSelectBrand();
    
    virtual void slotSelectLibPath();
    
  private:
    Ui::SvDeviceModelDialog *dmDialog;
};

#endif // SV_DEVMODEL_H
