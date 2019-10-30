/*
 * gpio.c
 *
 *  Created on: Sep 28, 2019
 *      Author: jessi
 */


#include <gpio_hal.h>

void initGPIO(){
    GPIO_init();

    GPIO_setConfig(OUTA_1, GPIO_CFG_IN_PU  | GPIO_CFG_IN_INT_BOTH_EDGES);
    GPIO_setConfig(OUTB_1, GPIO_CFG_INPUT  | GPIO_CFG_IN_INT_NONE);
    GPIO_setConfig(OUTA_2, GPIO_CFG_IN_PU  | GPIO_CFG_IN_INT_BOTH_EDGES);
    GPIO_setConfig(OUTB_2, GPIO_CFG_INPUT  | GPIO_CFG_IN_INT_NONE);
    GPIO_setConfig(BIN1, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    GPIO_setConfig(AIN2, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);

    // TEMP: going forward in slow decay mode
    //GPIO_write(BIN1, 0);

    GPIO_setCallback(OUTA_1, encoder1_isr);
    GPIO_setCallback(OUTA_2, encoder2_isr);

    GPIO_enableInt(OUTA_1);
    GPIO_enableInt(OUTA_2);

}

void setGPIO(int stateVal){
    if(stateVal==0){
    // stop
        GPIO_write(AIN2, 0);
        GPIO_write(BIN1, 0);
    }
    else if(stateVal==1){
    // forward
        GPIO_write(AIN2, 0);
        GPIO_write(BIN1, 0);
    }
    else if(stateVal==2){
    // turn right
        GPIO_write(AIN2, 0);
        GPIO_write(BIN1, 1);
    }
    else if(stateVal==3){
    // turn left
        GPIO_write(AIN2, 1);
        GPIO_write(BIN1, 0);
    }
    else if(stateVal==4){
    // backward
        GPIO_write(AIN2, 1);
        GPIO_write(BIN1, 1);
    }
}

void encoder1_isr(uint_least8_t index){
    //GPIO_toggle(Board_GPIO_LED0);

    uint8_t Enc1_A= GPIO_read(OUTA_1);
    uint8_t Enc1_B= GPIO_read(OUTB_1);

    int counter_msg1;
    if(Enc1_A!=Enc1_B)
        counter_msg1=1;
    else
        counter_msg1=-1;

    if(sendCounterMsgToRQ1(counter_msg1) == QUEUE_FAILURE)
    {
           //setErrorFlagTrue();
    }
}

void encoder2_isr(uint_least8_t index){
    //GPIO_toggle(Board_GPIO_LED0);
    uint8_t Enc2_A=GPIO_read(OUTA_2);
    uint8_t Enc2_B=GPIO_read(OUTB_2);

    int counter_msg2;
    if(Enc2_A!=Enc2_B)
        counter_msg2=-1;
    else
        counter_msg2=1;

    if(sendCounterMsgToRQ2(counter_msg2) == QUEUE_FAILURE)
    {
           //setErrorFlagTrue();
    }

}
