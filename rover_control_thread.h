/*
 * rover_control_thread.h
 *
 *  Created on: Oct 1, 2019
 *      Author: jessi
 */

#ifndef ROVER_CONTROL_THREAD_H_
#define ROVER_CONTROL_THREAD_H_

#include <unistd.h>
#include <stddef.h>

/* Driver Header files */
#include <ti/drivers/PWM.h>

/* Example/Board Header files */
#include "Board.h"
#include <ti/drivers/GPIO.h>
#include "gpio_hal.h"
#include "pwm_hal.h"
#include "timerone.h"
#include "rover_control_queue.h"
#include "debug.h"

void *RoverControlThread(void *arg0);
void printToUART(int speed1, int speed2, uint32_t stateVal);
int digitCount(int input);


#endif /* ROVER_CONTROL_THREAD_H_ */
