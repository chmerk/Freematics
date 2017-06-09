#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

/**************************************
* Configuration Definitions
**************************************/
#define NET_NONE 0
#define NET_SERIAL 1
#define NET_BLE 2
#define NET_WIFI 3
#define NET_SIM800 4
#define NET_SIM5360 5

#define STORAGE_NONE 0
#define STORAGE_RAM 1
#define STORAGE_FLASH 2
#define STORAGE_SD 3

#define MEMS_NONE 0
#define MEMS_MPU6050 1
#define MEMS_MPU9250 2

/**************************************
* Networking configurations
**************************************/
#ifndef NET_DEVICE
#define NET_DEVICE NET_WIFI
// WIFI settings
#define WIFI_SSID "HOMEWIFI"
#define WIFI_PASSWORD "862150909018"
// APN settings for cellular network
#define CELLULAR_APN "connect"
// Freematics Hub server settings
#define SERVER_URL "hub.freematics.com"
#define SERVER_PORT 8081
#define SERVER_KEY "TEST_SERVER_KEY"
#endif

// xBee module serial baudrate
#define XBEE_BAUDRATE 115200
// maximum consecutive communication errors before entering standby
#define MAX_CONN_ERRORS 10
// maximum consecutive communication errors before reconnecting
#define MAX_CONN_ERRORS_RECONNECT 3
// maximum allowed connecting time
#define MAX_CONN_TIME 10000 /* ms */

/**************************************
* Data storage configurations
**************************************/
#ifndef STORAGE_TYPE
#define STORAGE_TYPE STORAGE_RAM
#endif
#ifndef STORAGE_SIZE
#if NET_BLE == NET_BLE
#define STORAGE_SIZE 160 /* bytes */
#else
#define STORAGE_SIZE 1020 /* bytes */
#endif
#endif
#ifndef DATA_SENDING_INTERVAL
#define DATA_SENDING_INTERVAL 1000 /* ms */
#endif

/**************************************
* OBD-II configurations
**************************************/
// maximum consecutive OBD-II access errors before entering standby
#define MAX_OBD_ERRORS 10

/**************************************
* MEMS sensors
**************************************/
#ifndef MEMS_TYPE
#define MEMS_TYPE MEMS_NONE
#endif
#define ACC_DATA_RATIO 172
#define GYRO_DATA_RATIO 256
#define COMPASS_DATA_RATIO 8

/**************************************
* GPS
**************************************/
#ifndef USE_GPS
#define USE_GPS 1
#define GPS_SERIAL_BAUDRATE 115200L
#endif

/**************************************
* Motion detection
**************************************/
#define WAKEUP_MOTION_THRESHOLD 50 /* for wakeup on movement */
#define CALIBRATION_TIME 1000 /* ms */

/**************************************
* Other options
**************************************/
#define COOLING_DOWN_TEMP 65 /* celsius degrees */

#endif // CONFIG_H_INCLUDED