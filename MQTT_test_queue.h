/*
 *
 *  Created on: Sep 6, 2019
 *      Author: mmcgruther
 */

#ifndef MQTT_TEST_QUEUE_H_
#define MQTT_TEST_QUEUE_H_

#include <FreeRTOS.h>
#include <queue.h>
#include "debug.h"

typedef struct {
    char msgID;
    uint32_t message1;
    uint32_t message2;
} MTQMessage;

#define MTQ_QUEUE_LENGTH        10
#define MTQ_QUEUE_WIDTH         sizeof(MTQMessage)

#define MTQ_TEST_MSG_ID       1
#define MTQ_TABLE_MSG_ID       2

/*
 * Queue handles defined as global vars, per Code Requirements Documentation
 */
QueueHandle_t xQueueMTQ;

/*
 * Initializes Q1 with length = QUEUE_LENGTH and width = QUEUE_WIDTH
 */
QueueHandle_t createQueueMTQ();

/*
 * Sends count message to queue using blocking send
 */
void sendTestMsgToMTQ_BL(uint16_t testVal);
/*
 * Sends count message to queue using blocking send
 */
void sendTableMsgToMTQ_BL(uint16_t testVal);

/*
 * Blocking receive from Q1. Determines data type (time/sensor) and assigns received value to
 *  appropriate argument. Sets other arg = 0.
 */
void receiveMsgFromMTQ_BL(uint16_t *testVal_p,uint16_t *tableVal_p);

#endif
