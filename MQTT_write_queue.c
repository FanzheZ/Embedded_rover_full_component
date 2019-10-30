/*
 * sensor_queue.c
 *
 *  Created on: Sep 6, 2019
 *      Author: mmcgruther
 */
#include <MQTT_write_queue.h>

QueueHandle_t createQueueMWQ()
{
    xQueueMWQ = xQueueCreate(MWQ_QUEUE_LENGTH, MWQ_QUEUE_WIDTH);
    return xQueueMWQ;
}
void sendTestMsgToMWQ_NB(uint16_t testVal)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    MWQMessage pxmsg = {MWQ_TEST_MSG_ID, 0, testVal};

    if(xQueueSendFromISR(xQueueMWQ, (void *)&pxmsg, &xHigherPriorityTaskWoken) != pdTRUE)
    {
        setErrorFlagTrue();
    }

    if (xHigherPriorityTaskWoken)
    {
        //yield to higher prio task if woken
        //taskYIELD_FROM_ISR();
    }
}
void sendTestMsgToMWQ_BL(uint16_t testVal)
{

    MWQMessage pxmsg = {MWQ_TEST_MSG_ID, 0, testVal};

    if(xQueueSend(xQueueMWQ, (void *)&pxmsg, portMAX_DELAY) != pdTRUE)
    {
        setErrorFlagTrue();
    }

}
void sendStatMsgToMWQ_BL(uint16_t publish, uint16_t receive, uint16_t miss)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    MWQMessage pxmsg = {MWQ_STAT_MSG_ID, (publish<<16)|receive,miss};

    if(xQueueSend(xQueueMWQ, (void *)&pxmsg, portMAX_DELAY) != pdTRUE)
    {
        setErrorFlagTrue();
    }
}

void sendTableAckMsgToMWQ_BL(uint32_t tableVal)
{
    MWQMessage pxmsg = {MWQ_TABLE_MSG_ID, 0, tableVal};

    if(xQueueSend(xQueueMWQ, (void *)&pxmsg, portMAX_DELAY) != pdTRUE)
    {
        setErrorFlagTrue();
    }
}



void receiveMsgFromMWQ_BL(uint16_t *topic_index_p, uint16_t *testVal_p, uint16_t *publishVal_p, uint16_t *receiveVal_p, uint16_t *missVal_p)
{
    MWQMessage pxrecmsg;

    xQueueReceive(xQueueMWQ, &pxrecmsg, portMAX_DELAY);

    char msgID = pxrecmsg.msgID;
    switch (msgID)
    {
    case MWQ_TEST_MSG_ID:
        *testVal_p = pxrecmsg.message2;
        *topic_index_p = msgID;
        break;
    case MWQ_STAT_MSG_ID:
        *publishVal_p = pxrecmsg.message1>>16;
        *receiveVal_p=pxrecmsg.message1;
        *missVal_p=pxrecmsg.message2;
        *topic_index_p = msgID;
        break;
    case MWQ_TABLE_MSG_ID:
        *testVal_p = pxrecmsg.message2;
        *topic_index_p = msgID;
        break;
    default:
        setErrorFlagTrue();;
    }
}
