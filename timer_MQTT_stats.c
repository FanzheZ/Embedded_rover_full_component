/*
 * timer_periodic_arm.c
 *
 *  Created on: Sep 24, 2019
 *      Author: mmcgr
 */

#include <timer_MQTT_stats.h>
#include "Board.h"

void timer_MQTT_stats_Init()
{
    xTimer = xTimerCreate("Timer", SOFTWARE_TIMER_PERIOD, pdTRUE, ( void * ) 0, vTimerCallback);
             if( xTimer == NULL )
             {
                 /* The timer was not created. */
                 setErrorFlagTrue();
             }
             else
             {
                 if( xTimerStart(xTimer, 0) != pdPASS )
                 {
                     setErrorFlagTrue();
                 }
             }
}

void vTimerCallback( TimerHandle_t xTimer )
{
    dbgOutputLoc(DLOC_TIMER_ISR_ENTER);
    sendTimeMsgToMSQ_NB(1);
    dbgOutputLoc(DLOC_TIMER_ISR_EXIT);
}

