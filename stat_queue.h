/*
 * stat_queue.h
 *
 *  Created on: Oct 21, 2019
 *      Author: jessi
 */

#ifndef STAT_QUEUE_H_
#define STAT_QUEUE_H_

#include <FreeRTOS.h>
#include <queue.h>
#include "debug.h"

typedef struct {
    char msgID;
    uint32_t message1;
    uint32_t message2;
} MSQMessage;

#define MSQ_QUEUE_LENGTH        10
#define MSQ_QUEUE_WIDTH         sizeof(MSQMessage)

#define MSQ_PUBLISH_MSG_ID       1
#define MSQ_RECEIVE_MSG_ID       2
#define MSQ_MISSED_MSG_ID        3
#define MSQ_TIME_MSG_ID          4

/*
 * Queue handles defined as global vars, per Code Requirements Documentation
 */
QueueHandle_t xQueueMSQ;

/*
 * Initializes Q1 with length = QUEUE_LENGTH and width = QUEUE_WIDTH
 */
QueueHandle_t createQueueMSQ();

/*
 * Sends count message to queue using blocking send
 */
void sendPublishMsgToMSQ_BL(uint16_t pubcount);
/*
 * Sends count message to queue using blocking send
 */
void sendReceiveMsgToMSQ_BL(uint16_t recCount);
/*
 * Sends count message to queue using blocking send
 */
void sendMissedMsgToMSQ_BL(uint16_t missCount);
/*
 * Sends count message to queue using blocking send
 */
void sendTimeMsgToMSQ_NB(uint16_t timeVal);
/*
 * Blocking receive from Q1. Determines data type (time/sensor) and assigns received value to
 *  appropriate argument. Sets other arg = 0.
 */
void receiveMsgFromMSQ_BL(uint16_t *msgtype_p,uint16_t *count_p);




#endif /* STAT_QUEUE_H_ */
