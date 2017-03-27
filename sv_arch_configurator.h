#ifndef SVARCHCONFIGURATOR_H
#define SVARCHCONFIGURATOR_H

#include "ui_arch_configurator.h"
#include "sql_select_defs.h"
#include "sql_fields_defs.h"
#include "log.h"
#include "sv_device_list.h"
#include "sv_pgdb.h"
#include "sv_settings.h"
#include "sv_arch_data_list.h"
#include "sv_ffmpeg2filesettings.h"

#include <QObject>
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtWidgets/QTableView>
#include <QList>
#include <QByteArray>
#include <QBuffer>

//int setDeviceListTable(QSqlDatabase* db,
//                       QSqlQuery *query,
//                       QSqlQueryModel* queryModel,
//                       QTableView* table);

namespace Ui {/**/
  class ArchDialog;
}

struct FF2FileSettings
{
  QString device_name;
  QString ip;
  int  port;
  QString media_link;
  QByteArray settings;
};

struct ArchConfiguration
{
  QString ip;
  int  port;
  QString db_name;
  QString user_name;
  QString pass;
  QList<int> devices;
  QList<int> tables;
  QByteArray arch_config;
};

class SvArchConfigurator : public QDialog
{
    Q_OBJECT
    
  public:
    explicit SvArchConfigurator(void *PGDB,
                                int deviceId);
    ~SvArchConfigurator();
    
    int setDeviceListTable();
    int setDataListTable();
    
  public slots:
    void accept() Q_DECL_OVERRIDE;
    void close() Q_DECL_OVERRIDE;
    
  private:/**/
    Ui::ArchDialog *dlg;
    
    SvPGDB* pgdb;
    ArchConfiguration* config;
    QByteArray* cfgData;
    
    FF2FileSettings ff2f_settings; 
//    QSqlDatabase* p_db;
//    QSqlQuery *p_query_devices;
//    QSqlQuery *p_query_data;
    
    QSqlQueryModel* p_model_devices;
    QSqlQueryModel* p_model_data;
    
    int p_configured_device_id;
    QTableView* p_tbl_devices;
    QTableView* p_tbl_data;

    int p_parseConfig();
    int p_packConfig();
    
  private slots:
    void slotAddDevice();
    void on_DEVICELIST_UI_closed();
    void slotAddData();
    void on_ARCH_DATA_LIST_closed();
    void slotDeviceSettings();
};

#endif // SVARCHCONFIGURATOR_H
