/*
 * debug.h
 *
 *  Created on: Sep 8, 2019
 *      Author: Luke
 */


#ifndef DEBUG_H_
#define DEBUG_H_


#define DLOC_MQTT_SUBSCRIBE_ISR_BEGIN           0x01
#define DLOC_MQTT_SUBSCRIBE_ISR_NEW_DATA        0x02
#define DLOC_MQTT_SUBSCRIBE_ISR_PAYLOAD_LARGE   0x03
#define DLOC_MQTT_SUBSCRIBE_ISR_MSG_RECEIVED    0x04
#define DLOC_MQTT_SUBSCRIBE_ISR_MSG_CORRECT     0x05
#define DLOC_MQTT_SUBSCRIBE_ISR_MSG_MISSED      0x06
#define DLOC_MQTT_SUBSCRIBE_ISR_END             0x07

#define DLOC_TEST_TASK_BEFORE_WHILE             0x10
#define DLOC_TEST_TASK_RECIEVE_FROM_QUEUE       0x11
#define DLOC_TEST_TASK_RECIEVE_SUCCESS          0x12

#define DLOC_TIMER_ISR_ENTER                    0x20
#define DLOC_TIMER_ISR_EXIT                     0x21

#define DLOC_BEFORE_SENDTO_MQTT_WRITE           0x30
#define DLOC_AFTER_SENDTO_MQTT_WRITE            0x31

#define DLOC_MQTT_WRITE_BEFORE_WHILE            0x40
#define DLOC_MQTT_WRITE_BEFORE_RECEIVE          0x41
#define DLOC_MQTT_WRITE_AFTER_RECEIVE           0x42
#define DLOC_MQTT_WRITE_CREATE_STRING           0x43
#define DLOC_MQTT_WRITE_BEFORE_PUBLISH          0x44
#define DLOC_MQTT_WRITE_AFTER_PUBLISH           0x45

#define DLOC_ERROR                              0x7F

//Address references all pins of port
//#define GPIO_DATA_PORT_A1           0x400053FC
//#define SET_MSB_OF_BYTE             0x80
#define MAX_DEBUG_LOC               256
#define BIT0_MASK                   1
#define BIT1_MASK                   2
#define BIT2_MASK                   4
#define BIT3_MASK                   8
#define BIT4_MASK                   16
#define BIT5_MASK                   32
#define BIT6_MASK                   64
#define BIT7_MASK                   128

#include <stdbool.h>
#include <ti/drivers/GPIO.h>
#include "Board.h"
#include <ti/drivers/UART.h>
#include <ti/drivers/Power.h>
#include <ti/drivers/Timer.h>
#include <ti/devices/cc32xx/inc/hw_gpio.h>
#include <ti/drivers/dpl/HwiP.h>
#include <pthread.h>
#include <time.h>
#include <FreeRTOS.h>
#include <task.h>


//#include <ti/sysbios/hal/Hwi.h>
#if DEMO_SHUTDOWN
static int locCount = 0;
#endif


UART_Handle uart0;
Timer_Handle timer0;
Timer_Handle timer1;

void dbgUARTConfig();

void dbgUARTVal(unsigned char outVal);

void dbgOutputLoc(unsigned int outLoc);

void setErrorFlagTrue();

//void setErrorFlagFalse();

#endif /* DEBUG_H_ */
