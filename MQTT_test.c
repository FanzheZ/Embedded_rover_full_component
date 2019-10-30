
#include <MQTT_test.h>

void *MQTT_test_Thread(void *arg0)
{
    xQueueMTQ = createQueueMTQ();
    uint16_t testVal = 0, tableVal = 0, i;
    uint32_t tableSum;
    dbgOutputLoc(DLOC_TEST_TASK_BEFORE_WHILE);
    while (1) {
        dbgOutputLoc(DLOC_TEST_TASK_RECIEVE_FROM_QUEUE);
        receiveMsgFromMTQ_BL(&testVal,&tableVal);
        dbgOutputLoc(DLOC_TEST_TASK_RECIEVE_SUCCESS);
        if (!tableVal)
        {
            dbgOutputLoc(DLOC_BEFORE_SENDTO_MQTT_WRITE);
            sendTestMsgToMWQ_BL(testVal+1);
            dbgOutputLoc(DLOC_AFTER_SENDTO_MQTT_WRITE);
        }
        else
        {
            //table stuff here
            tableSum=0;
            for (i=0;i<LUT_SIZE;i++)
            {
                tableSum += LUT_array[i];
            }
            sendTableAckMsgToMWQ_BL(tableSum);
        }
    }
}
