#include "sv_sqlite.h"
//#include "log.h"

SvSQLITE *SQLITE;

//int CURRENT_USER_ID = -1;
//struct_user_info USER_INFO;

//using namespace log_ns;
//using namespace sql_create_defs;
//using namespace sql_insert_defs;

SvSQLITE::SvSQLITE(QObject *parent, QString fileName) :
  QObject(parent)
{
  this->setParent(parent);
  _db_name = fileName;
}

SvSQLITE::SvSQLITE(SvSQLITE* sqlite, QObject *parent) :
  QObject(parent)
{
  setParent(parent);
  
  if(sqlite)
  {
    _db_name = sqlite->currentDBName();
    _host_name = sqlite->currentHostName();
    _password = sqlite->currentPassword();
    _port = sqlite->currentPort();
    _user_name = sqlite->currentUserName();
  }
}

QSqlError SvSQLITE::connectToDB(QString dbName,
                              QString host,
                              quint16 port,
                              QString userName,
                              QString pass)
{
  try
  {
    db = QSqlDatabase::addDatabase("QSQLITE", "sqlitedb");
    db.setDatabaseName(_db_name);
    
    /* ------- ловим ошибки драйвера ---------*/
    if(!this->db.isValid())
      QSqlDatabase::removeDatabase("sqlitedb");

    /* ------- назначаем параметры подключения ---------*/
//    if(dbName != "") _db_name = dbName; 
//    if(host != "") _host_name = host;
//    if(port) _port = port;
//    if(userName != "") _user_name = userName;
//    if(pass != "") _password = pass;
    
//    this->db.setDatabaseName(this->p_db_name);
//    this->db.setHostName(this->p_host_name);
//    this->db.setPort(this->p_port);
    
//    this->db.setUserName(this->p_user_name);
//    this->db.setPassword(this->p_password);
    
    /* ---------- подключаемся -------------*/
    else
      db.open();
    
    return db.lastError();
    
  }
  catch(...)
  {
//    log(m_Err, "Error in SvPGDB");
  }
}

QSqlError SvSQLITE::connectToDB()
{
  try
  {
    db = QSqlDatabase::addDatabase("QSQLITE", "sqlitedb");
    db.setDatabaseName(_db_name);
    
    /* ------- ловим ошибки драйвера ---------*/
    if(!db.isValid())
      QSqlDatabase::removeDatabase("sqlitedb");

    
//    this->db.setDatabaseName(this->p_db_name);
//    this->db.setHostName(this->p_host_name);
//    this->db.setPort(this->p_port);
    
//    this->db.setUserName(this->p_user_name);
//    this->db.setPassword(this->p_password);
    
    /* ---------- подключаемся -------------*/
    else
      this->db.open();
    
    return this->db.lastError();
    
  }
  catch(...)
  {
//    log(m_Err, "Error in SvPGDB");
  }
}

SvSQLITE::~SvSQLITE()
{
  disconnectFromDb();
//  QSqlError err = this->disconnectFromDb();
//  if(err.type() != QSqlError::NoError)
//    log_ns::log_SQL_error(err);
  
  this->deleteLater();
  
}

void SvSQLITE::setConnectionParams(QString dbName,
                                 QString host,
                                 quint16 port,
                                 QString userName,
                                 QString pass)
{ 
//  if(dbName != "") _db_name = dbName; 
//  if(host != "") _host_name = host;
//  if(port) _port = port;
//  if(userName != "") p_user_name = userName;
//  if(pass != "") p_password = pass;
}

QSqlError SvSQLITE::execSQL(QString queryText, bool doLog, bool commit)
{
  QSqlError err;
  if(queryText == "")
  {  
    err.setType(QSqlError::UnknownError);
    err.setDatabaseText("Query is empty");
    return err;
  }
  
  qDebug() << queryText;
//  if(doLog) log_ns::log(m_Data, queryText);
  
  QSqlQuery query = db.exec(queryText);
  err = query.lastError();
  query.finish();
  
  qDebug() << err.databaseText();
//  if(doLog) log_ns::log_SQL_error(err);
  
  return err;  

}

QSqlError SvSQLITE::execSQL(QString queryText, QByteArray *data1, QByteArray *data2, QByteArray *data3, QSqlQuery* query, bool doLog)
{
  QSqlError err;
  if((queryText == "") || (data1 == 0))
  {  
    err.setType(QSqlError::UnknownError);
    err.setDatabaseText("Query is empty");
    return err;
  }
  
//  if(doLog) log_ns::log(m_Data, queryText);
  
  QSqlQuery *q;
  if(!query) q = new QSqlQuery(this->db);
  else q = query;
  
  q->prepare(queryText);

  q->addBindValue(QVariant(*data1), QSql::In | QSql::Binary);
  if(data2) q->addBindValue(QVariant(*data2), QSql::In | QSql::Binary); 
  if(data3) q->addBindValue(QVariant(*data3), QSql::In | QSql::Binary);

  q->exec();
  
  err = q->lastError();
  
  if(!query)
  {
    q->finish();
    delete q;
  }
  qDebug() << err.databaseText();
//  if(doLog) log_ns::log_SQL_error(err);
  
  return err;
  
}

QSqlError SvSQLITE::execSQL(QString queryText, QSqlQuery* query, bool doLog)
{
  QSqlError err;
  if(queryText == "")
  {  
    err.setType(QSqlError::UnknownError);
    err.setDatabaseText("Query is empty");
    return err;
  }
  qDebug() << queryText;
//  if(doLog) log_ns::log(m_Data, queryText);

  *query = db.exec(queryText);
  
//  if(doLog) log_ns::log_SQL_error();
  qDebug() << query->lastError().databaseText();
  
  return query->lastError();
  
}

QSqlError SvSQLITE::execSQL(QString queryText, QSqlQueryModel *model, bool doLog)
{
  if(queryText == "")
  {  
    QSqlError err;
    err.setType(QSqlError::UnknownError);
    err.setDatabaseText("Query is empty");
    return err;
  }
  qDebug() << queryText;
//  if(doLog) log_ns::log(m_Data, queryText);
  
  model->setQuery(queryText, db);
  model->query().execBatch();
  
//  if(doLog) log_ns::log_SQL_error(model->query().lastError());
  qDebug() << model->query().lastError().databaseText();
  return model->query().lastError();
  
}

QSqlError SvSQLITE::disconnectFromDb()
{
  db.close();
  return db.lastError();
}

