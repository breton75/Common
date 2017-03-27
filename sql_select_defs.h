#ifndef SQL_SELECT_DEFS
#define SQL_SELECT_DEFS

#include <QString>
#include "sql_fields_defs.h"

//using namespace sql_fields_defs;
//sql_fields_defs
//#define DEVICE_NAME "device_name"
//#define DEVICE_IP "ip"

namespace sql_select_defs
{
  
  #define SELECT_DEVICE_LIST  "SELECT " CRR\
                              TBL_DEVICES "." F_DEVICE_ID " as " F_DEVICE_ID ", " CRR\
                              TBL_DEVICES "." F_DEVICE_NAME " as " F_DEVICE_NAME ", " CRR\
                              TBL_DEVICES "." F_DEVICE_IP " as " F_DEVICE_IP ", " CRR\
                              TBL_DEVICES "." F_DEVICE_PORT " as " F_DEVICE_PORT ", " CRR\
                              TBL_CLASSES "." F_CLASS_NAME " as " F_CLASS_NAME ", " CRR\
                              TBL_BRANDS  "." F_BRAND_NAME " as " F_BRAND_NAME ", " CRR\
                              TBL_MODELS  "." F_MODEL_NAME " as " F_MODEL_NAME ", " CRR\
                              TBL_DEVICES "." F_DEVICE_POSX " as " F_DEVICE_POSX ", " CRR\
                              TBL_DEVICES "." F_DEVICE_POSY " as " F_DEVICE_POSY ", " CRR\
                              TBL_DEVICES "." F_DEVICE_POSZ " as " F_DEVICE_POSZ ", " CRR\
                              TBL_DEVICES "." F_DEVICE_STATE " as " F_DEVICE_STATE ", " CRR\
                              TBL_DEVICES "." F_DEVICE_DESCRIPT " as " F_DEVICE_DESCRIPT ", " CRR\
                              TBL_DEVICES "." F_DEVICE_CONFIG " as " F_DEVICE_CONFIG ", " CRR\
                              TBL_DEVICES "." F_DEVICE_SETTINGS " as " F_DEVICE_SETTINGS ", " CRR\
                              TBL_DEVICES "." F_DEVICE_ARCH_CONFIG " as " F_DEVICE_ARCH_CONFIG CR\
                            "FROM " \
                              TBL_DEVICES CRR\
                              "left join " TBL_MODELS  " on " TBL_DEVICES "." F_DEVICE_MODEL_ID "=" TBL_MODELS "." F_MODEL_ID CRR\
                              "left join " TBL_CLASSES " on " TBL_MODELS  "." F_MODEL_CLASS "=" TBL_CLASSES "." F_CLASS_ID CRR\
                              "left join " TBL_BRANDS  " on " TBL_MODELS  "." F_MODEL_BRAND "=" TBL_BRANDS "." F_BRAND_ID CR\
                            "ORDER BY " TBL_DEVICES "." F_DEVICE_ID
  
  #define DEVICES_COLUMN_LIST "/ID/true;/Device name/true;/Ip/true;/Port/true;/Class/true;"\
                              "/Brand/true;/Model/true;/Longitude/true;/Latitude/true;"\
                              "/Altitude/true;/Sate/true;/Description/true;"\
                              "/Configuration/false;/Settings/false;/Arch settings/false"
  
#define SELECT_FROM_DEVICES_WHERE_IN "SELECT " CRR\
                                        TBL_DEVICES "." F_DEVICE_ID " as " F_DEVICE_ID ", " CRR\
                                        TBL_DEVICES "." F_DEVICE_NAME " as " F_DEVICE_NAME ", " CRR\
                                        TBL_DEVICES "." F_DEVICE_IP " as " F_DEVICE_IP ", " CRR\
                                        TBL_DEVICES "." F_DEVICE_PORT " as " F_DEVICE_PORT ", " CRR\
                                        TBL_CLASSES "." F_CLASS_NAME " as " F_CLASS_NAME ", " CRR\
                                        TBL_BRANDS  "." F_BRAND_NAME " as " F_BRAND_NAME "," CRR\     
                                        TBL_MODELS  "." F_MODEL_NAME " as " F_MODEL_NAME ", " CRR\
                                        TBL_DEVICES "." F_DEVICE_POSX " as " F_DEVICE_POSX ", " CRR\
                                        TBL_DEVICES "." F_DEVICE_POSY " as " F_DEVICE_POSY ", " CRR\
                                        TBL_DEVICES "." F_DEVICE_POSZ " as " F_DEVICE_POSZ ", " CRR\
                                        TBL_DEVICES "." F_DEVICE_STATE " as " F_DEVICE_STATE ", " CRR\
                                        TBL_DEVICES "." F_DEVICE_DESCRIPT " as " F_DEVICE_DESCRIPT ", " CRR\
                                        TBL_DEVICES "." F_DEVICE_CONFIG " as " F_DEVICE_CONFIG ", " CRR\
                                        TBL_DEVICES "." F_DEVICE_SETTINGS " as " F_DEVICE_SETTINGS ", " CRR\
                                        TBL_DEVICES "." F_DEVICE_ARCH_CONFIG " as " F_DEVICE_ARCH_CONFIG CR\
                                      "FROM "\
                                        TBL_DEVICES CRR\
                                        "left join " TBL_MODELS  " on " TBL_DEVICES "." F_DEVICE_MODEL_ID "=" TBL_MODELS "." F_MODEL_ID CRR\
                                        "left join " TBL_CLASSES " on " TBL_MODELS "." F_MODEL_CLASS "=" TBL_CLASSES "." F_CLASS_ID CRR\
                                        "left join " TBL_BRANDS  " on " TBL_MODELS "." F_MODEL_BRAND "=" TBL_BRANDS "." F_BRAND_ID CR\
                                      "WHERE " TBL_DEVICES "." F_DEVICE_ID "in (%1)"

  const QString SELECT_FROM_DEVICES_WHERE =  "SELECT "
                                      "  devices.id as id, "
                                      "  devices.device_name as device_name, "
                                      "  devices.ip as ip, "
                                      "  devices.port as port, "
                                      "  dev_classes.class_name as class_name, "
                                      "  dev_brands.brand_name as brand_name,"     
                                      "  dev_models.model_name as model_name, "
//                                      "  devices.model_id as model_id, "
//                                      "  dev_models.model_class as class_id,"
//                                      "  dev_models.model_brand as brand_id, "
                                      "  devices.location_x as location_x, "
                                      "  devices.location_y as location_y, "
                                      "  devices.location_z as location_z, "
                                      "  devices.device_state as device_state, "
                                      "  devices.description as description, "
                                      "  devices.device_config as device_config, "
                                      "  devices.device_settings as device_settings,"
                                      "  devices.device_arch_config as device_arch_config "
                                      "FROM "
                                      "  public.devices "
                                      "  left join dev_models on devices.model_id = dev_models.id "
                                      "  left join dev_classes on dev_models.model_class = dev_classes.id "
                                      "  left join dev_brands on dev_models.model_brand = dev_brands.id "
                                      " WHERE devices.id = %1";
  
  
  /******** device models ********/
  const QString SELECT_FROM_DEV_MODELS = "SELECT " 
                                       "      devices.id as id, "
                                       "      devices.device_name as dev_name, "
                                       "      devices.ip  as dev_ip, "
                                       "      devices.port as dev_port, "
                                       "      devices.dev_class as dev_class, "
                                       "      dev_models.model_name as model_name, "
                                       "      dev_models.model_media_link as model_media_link, "      
                                       "      dev_list.location_x as location_x, "
                                       "      dev_list.location_y as location_y, "
                                       "      dev_list.location_z as location_z, "
                                       "      dev_list.dev_state as dev_state, "
                                       "      dev_list.description as description "
                                       "    FROM "
                                       "      "
                                       "      public.dev_list, "
                                       "      public.dev_models"
                                       "    WHERE "
                                       "      dev_models.id = devices.dev_model;";
  
  const QString SELECT_DEV_MODELS_LIST = " SELECT "
                                         "   dev_models.id, "
                                         "   dev_models.model_name, "
//                                         "   dev_models.model_class, "
//                                         "   dev_models.model_brand, "      
                                         "   dev_classes.class_name, "
                                         "   dev_brands.brand_name,"
                                         "   dev_models.model_lib_path, "
                                         "   dev_models.default_port, "
                                         "   dev_models.description "
//                                         "   dev_models.model_media_link "
                                         " FROM "
                                         "   public.dev_models"
                                         "   left join dev_classes on dev_models.model_class = dev_classes.id"
                                         "   left join dev_brands on dev_models.model_brand = dev_brands.id";
  
  const QString DEV_MODELS_COLUMN_LIST = "ID;Model name;Class;Brand;Driver library;Default port;Description";
  
  
  /******** device brands *********/ 
  const QString SELECT_DEV_BRANDS_LIST = "SELECT " 
                                         "      dev_brands.id as id, "
                                         "      dev_brands.brand_name as brand_name, "
                                         "      dev_brands.description as description "
                                         "    FROM "
                                         "      dev_brands;";
  
  const QString DEV_BRANDS_COLUMN_LIST = "ID;Brand name;Description";
  
  
  /********* device classes ********/
  const QString SELECT_DEV_CLASSES_LIST = "SELECT " 
                                          "      dev_classes.id as id, "
                                          "      dev_classes.class_name as class_name, "
                                          "      dev_classes.description as description "
                                          "    FROM "
                                          "      dev_classes ";
  
  const QString DEV_CLASSES_COLUMN_LIST = "ID;Class name;Description";
  
#define SELECT_FROM_ARCH_WHERE "SELECT " CRR\
                                 TBL_ARCH "." F_ARCH_ID " as " F_ARCH_ID ", " CRR\
                                 TBL_ARCH "." F_ARCH_ARCHIVER_ID " as " F_ARCH_ARCHIVER_ID ", "CRR\
                                 TBL_ARCH "." F_ARCH_DATA_TYPE " as " F_ARCH_DATA_TYPE ", "CRR\    
                                 TBL_ARCH "." F_ARCH_DATA_ID " as " F_ARCH_DATA_ID ", "CRR\ 
                                 TBL_ARCH "." F_ARCH_CONFIG " as " F_ARCH_CONFIG ", "CRR\  
                                 TBL_DEVICES "." F_DEVICE_NAME " as " F_DEVICE_NAME ", "CRR\
                                 TBL_DEVICES "." F_DEVICE_IP " as " F_DEVICE_IP ", "CRR\
                                 TBL_MODELS "." F_MODEL_NAME " as " F_MODEL_NAME ", "CRR\
                                 TBL_CLASSES "." F_CLASS_NAME " as " F_CLASS_NAME ", "CRR\
                                 TBL_CLASSES "." F_CLASS_LIB " as " F_CLASS_LIB ", "CRR\
                                 TBL_BRANDS "." F_BRAND_NAME " as " F_BRAND_NAME CR\
                               "FROM " TBL_ARCH CRR\
                                 "left join " TBL_DEVICES " on " TBL_ARCH "." F_ARCH_DATA_ID "=" TBL_DEVICES "." F_DEVICE_ID CRR\
                                 "left join " TBL_MODELS  " on " TBL_MODELS "." F_MODEL_ID "=" TBL_DEVICES "." F_DEVICE_MODEL_ID CRR\
                                 "left join " TBL_CLASSES " on " TBL_CLASSES "." F_CLASS_ID "=" TBL_MODELS "." F_MODEL_CLASS CRR\
                                 "left join " TBL_BRANDS  " on " TBL_BRANDS "." F_BRAND_ID "=" TBL_MODELS "." F_MODEL_BRAND CR\
                               "WHERE "CRR\
                                 TBL_ARCH "." F_ARCH_DATA_TYPE " = %1 and " TBL_ARCH "." F_ARCH_ARCHIVER_ID " = %2"
  
#define ARCH_DEVICES_COLUMN_LIST "/ID/true;/Arch device/false;/Data type/false;"\
                                 "/Data id/false;/Config/false;"\
                                 "/Device name/true;/IP/true;/Model/true;"\
                                 "/Class/true;/Class lib/false;/Brand/true"
}

namespace sql_insert_defs {
  
  /* *********** DEVICES *********** */
//  const QString INSERT_INTO_DEVICES_1 = ;
  
#define INSERT_INTO_DEVICES_1 "insert into " TBL_DEVICES CRR\
                                 "("\
                                 F_DEVICE_NAME "," CRR\
                                 F_DEVICE_IP "," CRR\
                                 F_DEVICE_PORT "," CRR\
                                 F_DEVICE_MODEL_ID "," CRR\
                                 F_DEVICE_POSX "," F_DEVICE_POSY "," F_DEVICE_POSZ "," CRR\
                                 F_DEVICE_STATE "," CRR\
                                 F_DEVICE_DESCRIPT "," CRR\
                                 F_DEVICE_CONFIG "," F_DEVICE_SETTINGS ")" CR\
                               "values" CRR\
                                 "('%1', '%2', %3, "\
                                 "%4, "\
                                 "%5, %6, %7, "\
                                 "%8, "\
                                 "'%9', "\
                                 "?, ?)"
  
  
//  const QString  
  
  #define INSERT_INTO_DEVICES_2  "insert into " TBL_DEVICES "(" F_DEVICE_NAME ", "\
                                                            F_DEVICE_IP ", "\
                                                            F_DEVICE_PORT ", "\
                                                            F_DEVICE_MODEL_ID ", "\
                                                            F_DEVICE_POSX ", "\
                                                            F_DEVICE_POSY ", "\
                                                            F_DEVICE_POSZ ", "\
                                                            F_DEVICE_STATE ", "\
                                                            F_DEVICE_DESCRIPT\
                                                        " ) values("\
                                                            " '%1', '%2', %3, "\
                                                            " (select id from dev_models where model_name='%4' limit 1), "\
                                                            " %5, %6, %7,"\
                                                            " %8,"\
                                                            " '%9')"
//                                                            F_DEVICE_CONFIG ", "\
//                                                            F_DEVICE_SETTINGS\" ?, ?)"

#define UPDATE_DEVICES  "update " TBL_DEVICES " set " F_DEVICE_NAME "=%1, "\
                                                          F_DEVICE_IP "=%2, "\
                                                          F_DEVICE_PORT "=%3, "\
                                                          F_DEVICE_MODEL_ID "=(select " F_MODEL_ID " from " TBL_MODELS "where " F_MODEL_NAME "='%4' limit 1), "\
                                                          F_DEVICE_POSX "=%5, "\
                                                          F_DEVICE_POSY "=%6, "\
                                                          F_DEVICE_POSZ "=%7, "\
                                                          F_DEVICE_STATE "=%8, "\
                                                          F_DEVICE_DESCRIPT "=%9"
  
#define INSERT_INTO_ARCH_DEVICE "insert into " TBL_ARCH " (" F_ARCH_ARCHIVER_ID ", "\
                                    F_ARCH_DATA_TYPE ", "\
                                    F_ARCH_DATA_ID ")" CR\
                                    " values (%1, %2, %3)"
  
#define DELETE_FROM_ARCH_WHERE_IN "delete from " TBL_ARCH " where " F_ARCH_DATA_TYPE "=%1 and " F_ARCH_DATA_ID " in (%2)" 
  
//  const QString UPDATE_DEVICES      = "update devices set device_name='%1', model_id=%2, position_x=%3, " \
//                                       "position_y=%4, position_z=%5, description='%6' state=%7 where id=%8";
  
  const QString DELETE_FROM_DEVICES= "delete from devices where id=%1";
  
  
  
  /* ********* DEV MODELS ************ */
  const QString INSERT_INTO_DEV_MODELS = "insert into dev_models (model_name, model_class, model_brand, model_lib_path, default_port, description) " \
                                         "values('%1', %2, %3, '%4', %5, '%6')";
  
  const QString INSERT_NEW_DEV_MODEL = "insert into dev_models (model_name, model_class, model_brand, model_lib_path, default_port, description) " \
                                       "values('%1'," \
                                       "(select id from dev_classes where class_name='%2' limit 1), " \
                                       "(select id from dev_brands where brand_name='%3' limit 1), " \
                                       "'%4', %5, '%6')";  
  
  const QString UPDATE_DEV_MODELS      = "update dev_models set model_name='%1', dev_type=%2, lib_path='%3', brand=%4, " \
                                         "description='%5' where id=%6";
  
  const QString DELETE_FROM_DEV_MODELS = "delete from dev_models where id=%1";
  
  
  
  
  /* *********** DEV BRANDS ************** */
  const QString INSERT_INTO_DEV_BRANDS = "insert into dev_brands (brand_name, description) " \
                                         "values('%1', '%2')";
  
  const QString UPDATE_DEV_BRANDS      = "update dev_brands set brand_name='%1', description='%5' where id=%6" ;
  
  const QString DELETE_FROM_DEV_BRANDS = "delete from dev_brands where id=%1";
  
  
  
  /* *********** DEV CLASSES ************** */
  const QString INSERT_INTO_DEV_CLASSES = "insert into dev_classes (class_name, description) " \
                                         "values('%1', '%2')";
  
  const QString UPDATE_DEV_CLASSES      = "update dev_classes set class_name='%1'," \
                                          "description='%2' where id=%3" ;
  
  const QString DELETE_FROM_DEV_CLASSES = "delete from dev_classes where id=%1";
  
  
  
  
}

#endif // SQL_DEFS

