/*
 * timer.c
 *
 *  Created on: Sep 30, 2019
 *      Author: jessi
 */


#include <timerone.h>
void initTimer()
{
    Timer_init();
#if HARDWARE_TIMER
    Timer_Params params;
    Timer_Params_init(&params);
    params.period = HARDWARE_TIMER_PERIOD;
    params.periodUnits = Timer_PERIOD_US;
    params.timerMode = Timer_CONTINUOUS_CALLBACK;
    params.timerCallback = timerCallbackFxn;

    timer0=Timer_open(Board_TIMER0, &params);

    if (timer0 == NULL) {
        /* Failed to initialized timer */
        setErrorFlagTrue();
    }
    if (Timer_start(timer0) == Timer_STATUS_ERROR) {
        /* Failed to start timer */
        setErrorFlagTrue();
    }
#else
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
#endif
}
#if HARDWARE_TIMER
void timerCallbackFxn(Timer_Handle myHandle)
{
    uint32_t timeVal=1;
    if(sendTimeMsgToRQ(timeVal) == QUEUE_FAILURE)
    {
        setErrorFlagTrue();
    }
}
#else
void vTimerCallback( TimerHandle_t xTimer )
{
//    dbgOutputLoc(DLOC_ARM_TIMER_ENTER_ISR);
//    dbgOutputLoc(DLOC_ARM_TIMER_BEFORE_QUEUE_ISR);
      uint32_t timeVal=1;
      if(sendTimeMsgToRQ(timeVal) == QUEUE_FAILURE)
      {
         setErrorFlagTrue();
      }
//    dbgOutputLoc(DLOC_ARM_TIMER_AFTER_QUEUE_ISR);
//    dbgOutputLoc(DLOC_ARM_TIMER_EXIT_ISR);
}
#endif


