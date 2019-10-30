/*
 * rover_control_queue.c
 *
 *  Created on: Sep 30, 2019
 *      Author: jessi
 */


#include <rover_control_queue.h>


QueueHandle_t createQueueRQ()
{
    xQueue1 = xQueueCreate(QUEUE_LENGTH, QUEUE_WIDTH);
    return xQueue1;
}

int sendTimeMsgToRQ(uint8_t timeVal)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    AMessage pxmsg = {TIME_MSG_ID, timeVal};

    xQueueSendFromISR(xQueue1, (void *)&pxmsg, &xHigherPriorityTaskWoken);

    return QUEUE_SUCCESS;
}

int sendCounterMsgToRQ1(int16_t counterVal1)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    AMessage pxmsg = {COUNTER1_MSG_ID, (uint32_t) counterVal1};

    xQueueSendFromISR(xQueue1, (void *)&pxmsg, &xHigherPriorityTaskWoken);

    if (xHigherPriorityTaskWoken)
    {
        //yield to higher prio task if woken
        //taskYIELD_FROM_ISR();
    }
    return QUEUE_SUCCESS;
}

int sendCounterMsgToRQ2(int16_t counterVal2)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    AMessage pxmsg = {COUNTER2_MSG_ID, (uint32_t) counterVal2};

    xQueueSendFromISR(xQueue1, (void *)&pxmsg, &xHigherPriorityTaskWoken);

    if (xHigherPriorityTaskWoken)
    {
        //yield to higher prio task if woken
        //taskYIELD_FROM_ISR();
    }
    return QUEUE_SUCCESS;
}

int sendStateMsgToRQ(uint8_t stateVal)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    AMessage pxmsg = {ROVER_STATE_MSG_ID, (uint32_t)stateVal};

    xQueueSend(xQueue1, (void *)&pxmsg, portMAX_DELAY);

    return QUEUE_SUCCESS;
}

int receiveMsgFromRQ(uint8_t *timeVal, int16_t *counterVal1, int16_t *counterVal2, uint8_t *stateVal)
{
    AMessage pxrecmsg;

    xQueueReceive(xQueue1, &pxrecmsg, portMAX_DELAY);

    char msgID = pxrecmsg.msgID;
    switch (msgID)
    {
    case TIME_MSG_ID:
        *timeVal = pxrecmsg.message;
        break;
    case COUNTER1_MSG_ID:
        *counterVal1 += (int) pxrecmsg.message;
        break;
    case COUNTER2_MSG_ID:
        *counterVal2 += (int) pxrecmsg.message;
        break;
    case ROVER_STATE_MSG_ID:
        *stateVal = pxrecmsg.message;
        break;
    default:
        return QUEUE_FAILURE;
    }
    return QUEUE_SUCCESS;
}


