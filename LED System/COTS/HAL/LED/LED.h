/**
  ******************************************************************************
  * @file    LED.h
  * @author  mohamed mohamed taha
  * @Target  TivaC TM4C123GH6PM
  * @version V1
  * @date    22-Aug-2022
  * @brief   This header file contains the prototypes of LED functions and others.
  ******************************************************************************/

#ifndef LED_H_
#define LED_H_


void __LED_Initialize__(void);   //prototype of the function that initializes the LED
void __LED_PWM_Period__(u8 T_Off,u8 T_On) ;  //prototype of the function that takes T_on and T_off values from user
void __LED_PWM_ISR__(void);             // prototype of the ISR function of the TIMER

#endif /* LED_H_ */
