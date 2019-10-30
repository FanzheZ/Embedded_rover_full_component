/*
 * debug.c
 *
 *  Created on: Sep 8, 2019
 *      Author: Luke
 */

#include "debug.h"
#include "Board.h"

void dbgUARTConfig() {
/*
    UART_Params uartParams;

    UART_init();

    //Configure Uart
    UART_Params_init(&uartParams);
    uartParams.writeMode = UART_MODE_BLOCKING;
    uartParams.readMode = UART_MODE_BLOCKING;
    uartParams.writeDataMode = UART_DATA_BINARY;
    uartParams.readDataMode = UART_DATA_BINARY;
    uartParams.readReturnMode = UART_RETURN_FULL;
    uartParams.baudRate = 115200;
    uartParams.readEcho = UART_ECHO_OFF;
    uart0 = UART_open(Board_UART0, &uartParams);

    if (uart0 == NULL) {
        setErrorFlagTrue();
    }*/
}
/*
 * Writes a value to the UART
 */
void dbgUARTVal(unsigned char outVal) {
    UART_write(uart0, &outVal, 1);
}

/*
 * Outputs a value less than or equal to 127 to GPIO
 * Tracks location in the code
 * If the value is greater than 127 - throws an error
 */

void dbgOutputLoc(unsigned int outLoc) {

    if (outLoc < MAX_DEBUG_LOC) {
        /*
        GPIO_toggle(Board_GPIO_LED0);
        GPIO_toggle(Board_GPIO0);
        GPIO_toggle(Board_GPIO1);
        GPIO_toggle(Board_GPIO3);
        GPIO_toggle(Board_GPIO4);
        GPIO_toggle(Board_GPIO8);
        GPIO_toggle(Board_GPIO9);
        GPIO_toggle(Board_GPIO10);
        */
//        GPIO_write(Board_GPIO9, BIT6_MASK & outLoc);
//        GPIO_write(Board_GPIO8, BIT5_MASK & outLoc);
//        GPIO_write(Board_GPIO4, BIT4_MASK & outLoc);
//        GPIO_write(Board_GPIO3, BIT3_MASK & outLoc);
//        GPIO_write(Board_GPIO1, BIT2_MASK & outLoc);
//        GPIO_write(Board_GPIO0, BIT1_MASK & outLoc);
//        GPIO_write(Board_GPIO_LED0, BIT0_MASK & outLoc);
//        GPIO_toggle(Board_GPIO10);

    }
    else {
        setErrorFlagTrue();
    }
#if DEMO_SHUTDOWN
    locCount++;
    if (locCount == DEMO_SHUTDOWN_TRIG)
    {
        setErrorFlagTrue();
    }
#endif
}

/**
 * Occurs if an error is thrown
 * Activates the Error LED
 * Disables Interrupts
 */
void setErrorFlagTrue() {
    int retc = 0;

   dbgOutputLoc(DLOC_ERROR);

   HwiP_disable();
   vTaskSuspendAll();
   pthread_exit((void *)retc);
}
