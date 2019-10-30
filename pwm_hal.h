/*
 * pwm.h
 *
 *  Created on: Sep 28, 2019
 *      Author: jessi
 */

#ifndef PWM_HAL_H_
#define PWM_HAL_H_
#include "Board.h"
#include <ti/drivers/PWM.h>
#include <stddef.h>

void initPWM();
void resetPWM(uint16_t duty1, uint16_t duty2, int stateVal);

#endif /* PWM_HAL_H_ */
