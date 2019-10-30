/*
 * json_parse.h
 *
 *  Created on: Oct 12, 2019
 *      Author: mmcgr
 */

#ifndef JSON_PARSE_H_
#define JSON_PARSE_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "MQTT_test_queue.h"
#define JSMN_HEADER
#include "jsmn.h"

/* Defining Number of subscription topics                                    */
#define SUBSCRIPTION_TOPIC_COUNT 4

#define PUBLISH_PAYLOAD_BUFFER_SIZE         512
#define LUT_SIZE                            256
#define INT_BUFFER_SIZE 8

#define JSON_INITIAL_KEY        "{"
#define JSON_SEPERATOR_KEY      ", "
#define JSON_MSGID_KEY          "\"msgID\": "
#define JSON_COUNT_KEY          "\"count\": "
#define JSON_SUM_KEY          "\"sum\": "
#define JSON_FINAL_KEY          "}"
#define JSON_NUMP_KEY          "\"published\": "
#define JSON_NUMR_KEY          "\"received\": "
#define JSON_NUMM_KEY          "\"missed\": "


// parse
#define JSON_parse_msgID        "msgID"
#define JSON_parse_count        "count"
#define JSON_parse_LUT          "LUT"

extern int8_t LUT_array[LUT_SIZE];

typedef void (*topic_func_type)(const char * payload_p);

topic_func_type topic_functions[SUBSCRIPTION_TOPIC_COUNT];

void json_parse_topic_functions_init(topic_func_type *tfuncs);

void json_parse_big(const char *payload_p, uint16_t *msgID_p);

void json_parse_topic1(const char *payload_p, uint16_t *msgID_p);

void json_parse_topic2(const char *payload_p);

void json_parse_topic3(const char *payload_p);

void json_parse_recvd(const char *payload_p);

void json_stringify_topic0(char *payload_p, uint16_t msgID, uint16_t published_num, uint16_t received_num, uint16_t missed_num);


void json_stringify_topic1(char *payload_p, uint16_t msgID, uint16_t testVal);

void json_stringify_topic2(char *payload_p, uint16_t msgID, uint16_t testVal);

#endif /* JSON_PARSE_H_ */
