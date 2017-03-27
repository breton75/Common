#ifndef SVDEVICELIST_H
#define SVDEVICELIST_H

#include <QObject>
#include <QtWidgets/QTableView>
#include <QSqlQueryModel>

#include "sv_pgdb.h"
#include "sv_device.h"
#include "ui_devicelist.h"
#include "ui_device.h"

#include "log.h"

using namespace log_ns;
using namespace sql_select_defs;
using namespace sql_insert_defs;

//int setDeviceListTable(QSqlQueryModel* queryModel, QTableView* table);

namespace Ui {
  class SvDeviceListDialog;
}

class SvDevicesList : public QDialog
{
    Q_OBJECT
    
  public:
    explicit SvDevicesList(QWidget *parent,
                           bool showEditDelete = false,
                           bool showSelect = true);
    
    ~SvDevicesList();
    
//    QSqlQueryModel *m_device_list;
    
    int     t_id;
    QString t_deviceName;
    QString t_ip;
    int     t_port;
    int     t_modelId;
    QString t_modelName;
    QString t_className;
    QString t_brandName;
    QString t_libPath;
    int     t_X;
    int     t_Y;
    int     t_Z;
    QString t_description;
    
  public slots:
    virtual void accept() Q_DECL_OVERRIDE;
    
    void slotNewDevice();
    void slotEditDevice();
    void slotDeleteDevice();
    
  private:
    Ui::SvDeviceListDialog *dlg;
    
    QSqlQueryModel* p_model_devices;
    QTableView*     p_tbl_devices;
    
    int setDeviceListTable();
    
  private slots:
    void on_DEV_UI_closed();

};

#endif // SVDEVICELIST_H
