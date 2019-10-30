/*
 * stat_task.c
 *
 *  Created on: Oct 21, 2019
 *      Author: jessi
 */

#include <stat_task.h>

void *stat_Thread(void *arg0)
{

    xQueueMSQ = createQueueMSQ();
    uint16_t publish = 0, receive = 0, missed = 0, count =0, msgType = 0;
    //dbgOutputLoc(DLOC_TEST_TASK_BEFORE_WHILE);
    while (1) {
        //dbgOutputLoc(DLOC_TEST_TASK_RECIEVE_FROM_QUEUE);
        receiveMsgFromMSQ_BL(&msgType,&count);
        //dbgOutputLoc(DLOC_TEST_TASK_RECIEVE_SUCCESS);
        switch(msgType)
        {
        case 1://PUBLISH
            publish += count;
            break;
        case 2://RECEIVE
            receive += count;
            break;
        case 3://MISSED
            missed += count;
            break;
        case 4://TIME
            //dbgOutputLoc(DLOC_BEFORE_SENDTO_MQTT_WRITE);
            sendStatMsgToMWQ_BL(publish,receive,missed);
            //dbgOutputLoc(DLOC_AFTER_SENDTO_MQTT_WRITE);
            break;

        }
    }
}



