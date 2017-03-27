#ifndef SV_USERLOGON_H
#define SV_USERLOGON_H

#include <QDialog>
#include <QSqlError>
#include <QTextEdit>
#include <QSqlDatabase>
#include <QDebug>

#include "sv_pgdb.h"

namespace Ui {
  class SvUserLogonDialog;
}

class SvUserLogon : public QDialog
{
    Q_OBJECT
    
  public:
    explicit SvUserLogon(QWidget *parent = 0,
                         bool showHost = true,
                         bool showPort = false,
                         bool showDBName = false,
                         bool showUser = true,
                         bool showPass =true,
                         bool showLog = false,
                         QString host = "169.254.1.1",
                         quint16 port = 5432,
                         QString dbName = "PSSDB",
                         QString user = "",
                         QString pass = "",
                         bool showRole = false,
                         QString role = "postgres");
    ~SvUserLogon();
    
    QString t_host = "";
    quint16 t_port = 5432;
    QString t_dbName = "";
    QString t_user = "";
    QString t_pass = "";
    QString t_role = "";
    
    QTextEdit* get_log();
    
  public slots:
//    virtual void slotConnectToDB();
//    void slotCloseApp();
    
  private slots:
    void accept() Q_DECL_OVERRIDE;
    
  private:
    Ui::SvUserLogonDialog *ulogon;
};

#endif // USERLOGON_H
