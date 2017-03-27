#ifndef SQL_CREATE_DEFS
#define SQL_CREATE_DEFS

#include <QString>

#define FFH "dsdsd"

namespace sql_create_defs
{
  
  const QString CHECK_TABLE_EXISTS = "select table_name from information_schema.tables where table_name = %1";
  
  const QString CREATE_TABLE_TABLES_HISTORY = "create table tables_history "
                                                  "(id serial NOT NULL,"
                                                  "table_name character varying(255),"
                                                  "period_from timestamp without time zone, "
                                                  "period_until timestamp without time zone, "
                                                  "user_id integer";
  
  /* *********** DEVICES *********** */
  const QString CREATE_TABLE_DEVICES = "create table %1 (id serial NOT NULL,"
                                                        "device_name character varying(255),"
                                                        "ip character varying(15),"
                                                        "port integer,"
                                                        "model_id integer NOT NULL,"
                                                        "location_x integer,"
                                                        "location_y integer,"
                                                        "location_z integer,"
                                                        "device_state integer,"
                                                        "device_config bytea ,"
                                                        "device_settings bytea,"
                                                        "device_arch_config bytea,"
                                                        "description text)";

  
  
  
  
  
  
}


#endif // SQL_CREATE_DEFS

