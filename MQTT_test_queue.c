/*
 *
 *
 *  Created on: Sep 6, 2019
 *      Author: mmcgruther
 */
#include <MQTT_test_queue.h>

QueueHandle_t createQueueMTQ()
{
    xQueueMTQ = xQueueCreate(MTQ_QUEUE_LENGTH, MTQ_QUEUE_WIDTH);
    return xQueueMTQ;
}

void sendTestMsgToMTQ_BL(uint16_t testVal)
{

    MTQMessage pxmsg = {MTQ_TEST_MSG_ID, 0, testVal};

    if(xQueueSend(xQueueMTQ, (void *)&pxmsg, portMAX_DELAY) != pdTRUE)
    {
        setErrorFlagTrue();
    }

}
void sendTableMsgToMTQ_BL(uint16_t testVal)
{
    MTQMessage pxmsg = {MTQ_TABLE_MSG_ID, 0, testVal};

    if(xQueueSend(xQueueMTQ, (void *)&pxmsg, portMAX_DELAY) != pdTRUE)
    {
        setErrorFlagTrue();
    }
}
void receiveMsgFromMTQ_BL(uint16_t *testVal_p,uint16_t *tableVal_p)
{
    MTQMessage pxrecmsg;

    xQueueReceive(xQueueMTQ, &pxrecmsg, portMAX_DELAY);

    char msgID = pxrecmsg.msgID;

    switch (msgID)
    {
    case MTQ_TEST_MSG_ID:
        *testVal_p = pxrecmsg.message2;
        *tableVal_p = 0;
        break;
    case MTQ_TABLE_MSG_ID:
        *testVal_p = 0;
        *tableVal_p = pxrecmsg.message2;
        break;
    default:
        setErrorFlagTrue();
    }
}
