/*
 * timer.h
 *
 *  Created on: Sep 30, 2019
 *      Author: jessi
 */

#ifndef TIMERONE_H_
#define TIMERONE_H_
#include <ti/drivers/Timer.h>
#include "Board.h"
#include "gpio_hal.h"
#include "rover_control_queue.h"
#include "debug.h"

#define HARDWARE_TIMER_PERIOD            100000
#define HARDWARE_TIMER              1

#if HARDWARE_TIMER
Timer_Handle timer0;
void timerCallbackFxn(Timer_Handle myHandle);

#else
#define SOFTWARE_TIMER_PERIOD       100
#include <timers.h>
TimerHandle_t xTimer;
void vTimerCallback(TimerHandle_t xTimer);
#endif

void initTimer();

#endif /* TIMERONE_H_ */
