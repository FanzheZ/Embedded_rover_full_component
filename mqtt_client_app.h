/*
 * MQTT_defs.h
 *
 *  Created on: Oct 12, 2019
 *      Author: mmcgr
 */

#ifndef MQTT_CLIENT_APP_H_
#define MQTT_CLIENT_APP_H_

//#include "json_parse.h"

#include <stdlib.h>
#include <pthread.h>
#include <mqueue.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

/* TI-Driver includes                                                        */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/SPI.h>

/* Simplelink includes                                                       */
#include <ti/drivers/net/wifi/simplelink.h>

/* SlNetSock includes                                                        */
#include <ti/drivers/net/wifi/slnetifwifi.h>

/* MQTT Library includes                                                     */
#include <ti/net/mqtt/mqttclient.h>

/* Common interface includes                                                 */
#include "network_if.h"
#include "uart_term.h"

/* Application includes                                                      */
#include "Board.h"
#include "client_cbs.h"

#include "MQTT_write_queue.h"
#include "timer_MQTT_stats.h"
#include "stat_queue.h"

#include "json_parse.h"

#include "debug.h"

extern void MqttClientCallback(int32_t event,
                               void * metaData,
                               uint32_t metaDateLen,
                               void *data,
                               uint32_t dataLen);

//*****************************************************************************
//                          LOCAL DEFINES
//*****************************************************************************
#define SUBSCRIPTION_TOPIC_COUNT 4

/* Defining Subscription Topic Values                                        */
#define SUBSCRIPTION_TOPIC0         "/Broker/To/cc32xx"

#define SUBSCRIPTION_TOPIC1         "/topicD"

#define SUBSCRIPTION_TOPIC2         "/topicT1"
#define SUBSCRIPTION_TOPIC3         "/testsub3"

#define PUBLISH_TOPIC_COUNT         3
/* Defining Publish Topic Values                                             */


#define PUBLISH_TOPIC0              "/stat1"
#define PUBLISH_TOPIC1              "/topicA"
#define PUBLISH_TOPIC2              "/topicTACK1"

#define PUBLISH_TOPIC_BUFFER_SIZE           40

#define UART_VERBOSE                        0

#define CLIENTID_SIZE                       13
/* enables secured client                                                    */
//#define SECURE_CLIENT

/* enables client authentication by the server                               */
//#define CLNT_USR_PWD

#define CLIENT_INIT_STATE           (0x01)
#define MQTT_INIT_STATE          (0x04)

#define APPLICATION_VERSION      "1.1.1"
#define APPLICATION_NAME         "MQTT client"

#define SLNET_IF_WIFI_PRIO       (5)

/* Operate Lib in MQTT 3.1 mode.                                             */
#define MQTT_3_1_1               false
#define MQTT_3_1                 true

#define WILL_TOPIC               "Client"
#define WILL_MSG                 "Client Stopped"
#define WILL_QOS                 MQTT_QOS_2
#define WILL_RETAIN              false

/* Defining Broker IP address and port Number                                */
//#define SERVER_ADDRESS           "messagesight.demos.ibm.com"
#define SERVER_ADDRESS           "192.168.4.1"
#define SERVER_IP_ADDRESS        "192.168.4.1"
#define PORT_NUMBER              1883
#define SECURED_PORT_NUMBER      8883
#define LOOPBACK_PORT            1882

/* Clean session flag                                                        */
#define CLEAN_SESSION            true

/* Retain Flag. Used in publish message.                                     */
#define RETAIN_ENABLE            1

/* Spawn task priority and Task and Thread Stack Size                        */
#define TASKSTACKSIZE            2048
#define RXTASKSIZE               8192
#define MQTTTHREADSIZE           2048
#define SPAWN_TASK_PRIORITY      9

/* secured client requires time configuration, in order to verify server     */
/* certificate validity (date).                                              */

/* Day of month (DD format) range 1-31                                       */
#define DAY                      1
/* Month (MM format) in the range of 1-12                                    */
#define MONTH                    5
/* Year (YYYY format)                                                        */
#define YEAR                     2017
/* Hours in the range of 0-23                                                */
#define HOUR                     12
/* Minutes in the range of 0-59                                              */
#define MINUTES                  33
/* Seconds in the range of 0-59                                              */
#define SEC                      21

/* Number of files used for secure connection                                */
#define CLIENT_NUM_SECURE_FILES  1

/* Expiration value for the timer that is being used to toggle the Led.      */
#define TIMER_EXPIRATION_VALUE   100 * 1000000

extern const char *publish_topic;
extern const char *publish_data;

#endif /* MQTT_CLIENT_APP_H_ */
