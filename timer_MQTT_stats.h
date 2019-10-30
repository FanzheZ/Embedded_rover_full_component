/*
 *
 *
 *  Created on: Sep 24, 2019
 *      Author: mmcgr
 */

#ifndef TIMER_MQTT_STATS_H_
#define TIMER_MQTT_STATS_H_

#include "stat_queue.h"
#include "debug.h"
#include <timers.h>
#define NULL                        0

#define SOFTWARE_TIMER_PERIOD       1000

TimerHandle_t xTimer;
void vTimerCallback( TimerHandle_t xTimer );

void timer_MQTT_stats_Init();

#endif /* TIMER_MQTT_STATS_H_ */
