/*
 * rover_control_thread.c
 *
 *  Created on: Oct 1, 2019
 *      Author: jessi
 */

#include <rover_control_thread.h>
/*
 *  ======== mainThread ========
 *  Task periodically increments the PWM duty for the on board LED.
 */
void *RoverControlThread(void *arg0)
{
    // pinConfig();
    initTimer();

    uint8_t timeVal = 0;
    int8_t counterVal1=0;
    int8_t counterVal2=0;
    int16_t speed1=0;
    int16_t speed2=0;
    uint8_t pStateVal=0;
    uint8_t stateVal=0;
    resetPWM(500, 500, 0);
    setGPIO(0);

    while (1) {

        if (receiveMsgFromRQ(&timeVal,&counterVal1, &counterVal2, &stateVal) == QUEUE_SUCCESS)
        {
            if (timeVal == 1) {
               speed1=counterVal1*10;
               speed2=counterVal2*10;

               //pid

               //sendSpeedMsgToDUWQ_BL1(speed1);
               printToUART(speed1, speed2, stateVal);

               //reset the timeval and counterval
               timeVal = 0;
               counterVal1=0;
               counterVal2=0;
            }
            else if(stateVal!=pStateVal){
                resetPWM(500, 500, stateVal);
                setGPIO(stateVal);
                pStateVal=stateVal;
            }
        }
        else{
            // receive from RQ fail
        }

    }

    //return (NULL);
}


void printToUART(int speed1, int speed2, uint32_t stateVal){
    unsigned char speed_one[]= "Speed1: ";
    unsigned char speed_two[]= "Speed2: ";
    unsigned char rover_state[]= "Rover state:  ";
    unsigned char  newline[] = "\r\n";

    int speed1_digit[10];
    int speed2_digit[10];

    //speed1
    int i;
    for(i=0; i<sizeof(speed_one); i++){
        dbgUARTVal(speed_one[i]);
    }

    if(speed1<0){
        dbgUARTVal(45);
        speed1=-speed1;
    }
    int digit_ct_1=digitCount(speed1);
    int count1=digit_ct_1;
    int temp1=0;

    while(count1 > 0){
        temp1=speed1 % 10;
        speed1=speed1/10;
        temp1=temp1+48;
        speed1_digit[count1-1]=temp1;
        count1--;
    }

    for(i=0;i<digit_ct_1;i++){
        dbgUARTVal(speed1_digit[i]);
    }

    for(i=0; i<sizeof(newline); i++){
        dbgUARTVal(newline[i]);
    }

    // speed2
    for(i=0; i<sizeof(speed_two); i++){
        dbgUARTVal(speed_two[i]);
    }

    if(speed2<0){
        dbgUARTVal(45);
        speed2=-speed2;
    }
    int digit_ct_2=digitCount(speed2);
    int count2=digit_ct_2;
    int temp2=0;

    while(count2 > 0){
        temp2=speed2 % 10;
        speed2=speed2/10;
        temp2=temp2+48;
        speed2_digit[count2-1]=temp2;
        count2--;
    }

    for(i=0;i<digit_ct_2;i++){
        dbgUARTVal(speed2_digit[i]);
    }
    for(i=0; i<sizeof(newline); i++){
        dbgUARTVal(newline[i]);
    }


    // rover state
    for(i=0; i<sizeof(rover_state); i++){
        dbgUARTVal(rover_state[i]);
    }
    dbgUARTVal(stateVal+48);
    for(i=0; i<sizeof(newline); i++){
        dbgUARTVal(newline[i]);
    }
    for(i=0; i<sizeof(newline); i++){
        dbgUARTVal(newline[i]);
    }


}

int digitCount(int input){
    int digit_count=0;
    while(input != 0){
        digit_count++;
        input /= 10;
    }

    return digit_count;
}
