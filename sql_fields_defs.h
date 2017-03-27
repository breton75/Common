#ifndef SQL_FIELDS_DEFS
#define SQL_FIELDS_DEFS

#define CR "\r\n"
#define CRR "\r\n    "

/* data for archiving */
#define A_DATA_USERS "Users actions"
#define A_DATA_EMPLOY "Emoloyees"
#define A_DATA_ZONES "Security zones"
#define A_DATA_VARIABLES "Variables"
#define A_DATA_EMPLOY_MOVEMENT "Employees movement"
//#define A_DATA_ ""


/* tables */
#define TBL_DEVICES "public.devices"
#define TBL_MODELS "public.dev_models"
#define TBL_CLASSES "public.dev_classes"
#define TBL_BRANDS "public.dev_brands"
#define TBL_ARCH "public.arch"


/****** devices *******/
#define F_DEVICE_ID "id"
#define F_DEVICE_NAME "device_name"
#define F_DEVICE_IP "ip"
#define F_DEVICE_PORT "port"
#define F_DEVICE_MODEL_ID "model_id"
#define F_DEVICE_POSX "location_x"
#define F_DEVICE_POSY "location_y"
#define F_DEVICE_POSZ "location_z"
#define F_DEVICE_STATE "device_state"
#define F_DEVICE_DESCRIPT "description"
#define F_DEVICE_CONFIG "device_config"
#define F_DEVICE_SETTINGS "device_settings"
#define F_DEVICE_ARCH_CONFIG "device_arch_config"


/***** classes ******/
#define F_CLASS_ID "id"
#define F_CLASS_NAME "class_name"
#define F_CLASS_LIB "class_lib_path"
#define F_CLASS_DESCRIPT "description"

/****** brands ******/
#define F_BRAND_ID "id"
#define F_BRAND_NAME "brand_name"
#define F_BRAND_DESCRIPT "description"

/****** models *********/
#define F_MODEL_ID    "id"
#define F_MODEL_NAME  "model_name"
#define F_MODEL_CLASS "model_class"
#define F_MODEL_BRAND "model_brand"
#define F_MODEL_LIB   "model_lib_path"
#define F_MODEL_DESCRIPTION "description"

/******** arch *********/
#define F_ARCH_ID "id"
#define F_ARCH_ARCHIVER_ID "archiver_id"
#define F_ARCH_DATA_TYPE "data_type"
#define F_ARCH_DATA_ID "data_id"
#define F_ARCH_CONFIG "config"
#define F_ARCH_DESCRIPT "description"

#define ARCH_TYPE_DEVICE 0
#define ARCH_TYPE_DATA  1
//#define 
//#define


#endif // SQL_FIELDS_DEFS

