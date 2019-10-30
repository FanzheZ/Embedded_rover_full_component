/*
 * rover_control_queue.h
 *
 *  Created on: Sep 30, 2019
 *      Author: jessi
 */

#ifndef ROVER_CONTROL_QUEUE_H_
#define ROVER_CONTROL_QUEUE_H_

#include <FreeRTOS.h>
#include <queue.h>
typedef struct {
    char msgID;
    uint32_t message;
} AMessage;

#define QUEUE_SUCCESS       0
#define QUEUE_FAILURE       1


#define QUEUE_LENGTH        20
#define QUEUE_WIDTH         sizeof(AMessage)

#define TIME_MSG_ID         1
#define COUNTER1_MSG_ID       2
#define COUNTER2_MSG_ID       3
#define ROVER_STATE_MSG_ID    4

/*
 * Queue handles defined as global vars, per Code Requirements Documentation
 */
QueueHandle_t xQueue1;

/*
 * Initializes Q1 with length = QUEUE_LENGTH and width = QUEUE_WIDTH
 */
QueueHandle_t createQueueRQ();
/*
 * Sends time message to queue using nonblocking *fromISR send
 */
int sendTimeMsgToRQ(uint8_t timeVal);
/*
 * Sends encoder counter message to queue using nonblocking *fromISR send
 */
int sendCounterMsgToRQ1(int16_t counterVal1);
int sendCounterMsgToRQ2(int16_t counterVal2);
/*
 * Blocking receive from Q1. Determines data type (time/sensor) and assigns received value to
 *  appropriate argument. Sets other arg = 0.
 *
 *
 */
int receiveMsgFromRQ(uint8_t *timeVal, int16_t *counterVal1, int16_t *counterVal2, uint8_t *stateVal);

int receiveMsgFromMQTT(uint8_t *stateVal);

#endif /* ROVER_CONTROL_QUEUE_H_ */
