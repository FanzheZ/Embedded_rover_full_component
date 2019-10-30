/*
 * gpio.h
 *
 *  Created on: Sep 28, 2019
 *      Author: jessi
 */

#ifndef GPIO_HAL_H_
#define GPIO_HAL_H_
#include <ti/drivers/GPIO.h>
#include "Board.h"
#include "rover_control_queue.h"

void encoder1_isr(uint_least8_t index);
void encoder2_isr(uint_least8_t index);

void initGPIO();
void setGPIO(int stateVal);


#endif /* GPIO_HAL_H_ */
