/**
  ******************************************************************************
  * @file    LED.c
  * @author  mohamed mohamed taha
  * @Target  TivaC TM4C123GH6PM
  * @version V1
  * @date    22-Aug-2022
  * @brief   This source file contains the implementation of LED functions .
  ******************************************************************************/


#include "Stdlib.h"
#include "System_Control.h"
#include "Timer.h"
#include "GPIO.h"
#include "NVIC.h"
#include "LED.h"


static volatile u8 T_ON;    //declare a variable to hold the T_ON value
static volatile u8 T_OFF;   //declare a variable to hold the T_OFF value
static volatile u8 LED_Flag = Null;   //declare a variable to hold the Flag status


TIMER_Configuration TM = {Timer1,TimerA,Normal_Mode,Timer_16bit_32bit,Timer_Count_Down,Periodic_Timer_Mode,TIMERA_Time_Out_Interrupt_Mask,&__LED_PWM_ISR__};
GPIO_Pin_Configuration LED = {PORTF,Pin_Two,Output,R2R};  //define a led

//function to initialize the LED
void __LED_Initialize__(void) {

    __SYSCTL_Enable_TIMERx__(RCGTIMER1);   //enable timer clock
    __SYSCTL_Enable_GPIOx__(RCGPORTF);     //enable gpio clock

    __GPIO_Set_Pin_Direction__(&LED);      //set pin direction

    __TIMER_Initialize__(&TM);       //initialize timer
    __NVIC_Enable_Interrupt_Peripheral__(INT_TIMER1A); //enable the interrupt timer1A


}   //the end of the function


//function to take the T_ON period and T_OFF period
void __LED_PWM_Period__(u8 T_On,u8 T_Off) {


        T_ON = T_On;     //update T_ON period
        T_OFF = T_Off;   //update T_OFF period
        LED_Flag = True; //enable flag

}   //the end of the function


//function to set the time on and time off
void __LED_PWM_ISR__()
{

    static u8 count = Null;   //define a variable to count the number of over flow

    if(LED_Flag == True) {   //check if the flag is enabled
        count = Null;    //clear count
        LED_Flag = Null;  //clear flag
    } //end of the if statement

    if(count == T_ON) {   //check if the count equal the T_ON

        if(__TIMER_Masked_Interrupt_Status__(&TM))   //check if the timeout is happened
        {
            __GPIO_Clear_Pin__(&LED);  //set the led
        } //end of the if statement
    } //end of the if statement

    else if(count == (T_ON + T_OFF)) {   //check if the count equal the period

        if(__TIMER_Masked_Interrupt_Status__(&TM))    //check if the timeout is happened
        {
            __GPIO_Set_Pin__(&LED);  //clear the led
        }  //the end of the if statement

        count = Null;  //clear the count
    } //end of the else if statement

    count++;   //increase the count

    __TIMER_Clear_Flag__(&TM);   //clear the interrupt flag

}  //the end of the function


