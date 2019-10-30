/*
 * pwm.c
 *
 *  Created on: Sep 28, 2019
 *      Author: jessi
 */

#include <pwm_hal.h>

PWM_Handle pwm1 = NULL;
PWM_Handle pwm2 = NULL;
PWM_Params params1;
PWM_Params params2;
uint16_t   pwmPeriod = 1000;

void initPWM(){
    /* Period and duty in microseconds */
    uint16_t   duty1 = 500;
    uint16_t   duty2 = 500;

    /* Call driver init functions. */
    PWM_init();

    PWM_Params_init(&params1);
    params1.dutyUnits = PWM_DUTY_US;
    params1.dutyValue = duty1;
    params1.periodUnits = PWM_PERIOD_US;
    params1.periodValue = pwmPeriod;
    pwm1 = PWM_open(AIN1, &params1);
    if (pwm1 == NULL) {
        /* Board_PWM0 did not open */
        while (1);
    }

    PWM_start(pwm1);

    PWM_Params_init(&params2);
    params2.dutyUnits = PWM_DUTY_US;
    params2.dutyValue = duty2;
    params2.periodUnits = PWM_PERIOD_US;
    params2.periodValue = pwmPeriod;

    pwm2 = PWM_open(BIN2, &params2);
    if (pwm2 == NULL) {
        /* Board_PWM0 did not open */
        while (1);
    }

    PWM_start(pwm2);
}

void resetPWM(uint16_t duty1, uint16_t duty2, int stateVal){

    if(stateVal==0){
        PWM_setDuty(pwm1,0);
        PWM_setDuty(pwm2,0);
    }
    else{
        PWM_setDuty(pwm1,duty1);
        PWM_setDuty(pwm2,duty2);
    }


}


