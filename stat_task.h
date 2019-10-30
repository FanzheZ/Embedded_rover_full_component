/*
 * stat_task.h
 *
 *  Created on: Oct 21, 2019
 *      Author: jessi
 */

#ifndef STAT_TASK_H_
#define STAT_TASK_H_

#include "Board.h"
#include "json_parse.h"
#include "debug.h"
#include "stat_queue.h"
#include "MQTT_write_queue.h"

void *stat_Thread(void *arg0);

#endif /* STAT_TASK_H_ */
