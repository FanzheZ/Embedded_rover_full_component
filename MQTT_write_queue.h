/*
 * sensor_queue.h
 *
 *  Created on: Sep 6, 2019
 *      Author: mmcgruther
 */

#ifndef MQTT_WRITE_QUEUE_H_
#define MQTT_WRITE_QUEUE_H_

#include <FreeRTOS.h>
#include <queue.h>
#include "debug.h"

typedef struct {
    char msgID;
    uint32_t message1;
    uint32_t message2;
} MWQMessage;

#define MWQ_QUEUE_LENGTH        10
#define MWQ_QUEUE_WIDTH         sizeof(MWQMessage)

#define MWQ_STAT_MSG_ID         0
#define MWQ_TEST_MSG_ID         1
#define MWQ_TABLE_MSG_ID        2

/*
 * Queue handles defined as global vars, per Code Requirements Documentation
 */
QueueHandle_t xQueueMWQ;

/*
 * Initializes Q1 with length = QUEUE_LENGTH and width = QUEUE_WIDTH
 */
QueueHandle_t createQueueMWQ();
/*
 * Sends test message to queue using non blocking send
 */
void sendTestMsgToMWQ_NB(uint16_t testVal);
/*
 * Sends test message to queue using non blocking send
 */
void sendStatMsgToMWQ_BL(uint16_t publish, uint16_t receive, uint16_t miss);
/*
 * Sends test message to queue using blocking send
 */
void sendTestMsgToMWQ_BL(uint16_t testVal);
/*
 * Sends table ack message to queue using blocking send
 */
void sendTableAckMsgToMWQ_BL(uint32_t tableVal);
/*
 * Blocking receive from Q1. Determines data type and assigns received value to
 *  appropriate argument. Sets other arg = 0.
 */
void receiveMsgFromMWQ_BL(uint16_t *topic_index_p, uint16_t *testVal_p, uint16_t *publishVal_p, uint16_t *receiveVal_p, uint16_t *missVal_p);

#endif /* ARM_SENSOR_QUEUE_H_ */
