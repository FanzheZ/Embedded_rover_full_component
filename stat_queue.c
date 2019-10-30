/*
 * stat_queue.c
 *
 *  Created on: Oct 21, 2019
 *      Author: jessi
 */

#include <stat_queue.h>

QueueHandle_t createQueueMSQ()
{
    xQueueMSQ = xQueueCreate(MSQ_QUEUE_LENGTH, MSQ_QUEUE_WIDTH);
    return xQueueMSQ;
}

void sendPublishMsgToMSQ_BL(uint16_t pubcount)
{

    MSQMessage pxmsg = {MSQ_PUBLISH_MSG_ID, 0, pubcount};

    if(xQueueSend(xQueueMSQ, (void *)&pxmsg, portMAX_DELAY) != pdTRUE)
    {
        setErrorFlagTrue();
    }

}
void sendReceiveMsgToMSQ_BL(uint16_t reccount)
{

    MSQMessage pxmsg = {MSQ_RECEIVE_MSG_ID, 0, reccount};

    if(xQueueSend(xQueueMSQ, (void *)&pxmsg, portMAX_DELAY) != pdTRUE)
    {
        setErrorFlagTrue();
    }

}
void sendMissedMsgToMSQ_BL(uint16_t misscount)
{

    MSQMessage pxmsg = {MSQ_MISSED_MSG_ID, 0, misscount};

    if(xQueueSend(xQueueMSQ, (void *)&pxmsg, portMAX_DELAY) != pdTRUE)
    {
        setErrorFlagTrue();
    }

}

void sendTimeMsgToMSQ_NB(uint16_t timeVal)
{

    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    MSQMessage pxmsg = {MSQ_TIME_MSG_ID, 0, timeVal};

    if(xQueueSendFromISR(xQueueMSQ, (void *)&pxmsg, &xHigherPriorityTaskWoken) != pdTRUE)
    {
        setErrorFlagTrue();
    }

    if (xHigherPriorityTaskWoken)
    {
        //yield to higher prio task if woken
        //taskYIELD_FROM_ISR();
    }

}
void receiveMsgFromMSQ_BL(uint16_t *msgtype_p,uint16_t *count_p)
{
    MSQMessage pxrecmsg;

    xQueueReceive(xQueueMSQ, &pxrecmsg, portMAX_DELAY);

    char msgID = pxrecmsg.msgID;

    switch (msgID)
    {
    case MSQ_PUBLISH_MSG_ID:
        *count_p = pxrecmsg.message2;
        *msgtype_p = msgID;
        break;
    case MSQ_RECEIVE_MSG_ID:
        *count_p = pxrecmsg.message2;
        *msgtype_p = msgID;
        break;
    case MSQ_MISSED_MSG_ID:
        *count_p = pxrecmsg.message2;
        *msgtype_p = msgID;
        break;
    case MSQ_TIME_MSG_ID:
        *count_p = pxrecmsg.message2;
        *msgtype_p = msgID;
        break;
    default:
        setErrorFlagTrue();
    }
}




