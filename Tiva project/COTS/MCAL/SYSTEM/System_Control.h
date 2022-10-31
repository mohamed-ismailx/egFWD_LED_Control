/**
  ******************************************************************************
  * @file    System_Control.h
  * @author  mohamed mohamed taha
  * @Target  TivaC TM4C123GH6PM
  * @version V1
  * @date    21-Aug-2022
  * @brief   This header file contains the prototypes of System Control functions and others.
  ******************************************************************************/

/*Header file guard*/
#ifndef SYSTEM_CONTROL_H_
#define SYSTEM_CONTROL_H_



/* Declare an enum to configure the Timer Peripherals */
typedef enum
{
    RCGTIMER0,       //configuration of RCGTIMER0
    RCGTIMER1,       //configuration of RCGTIMER1
    RCGTIMER2,       //configuration of RCGTIMER2
    RCGTIMER3,       //configuration of RCGTIMER3
    RCGTIMER4,       //configuration of RCGTIMER4
    RCGTIMER5        //configuration of RCGTIMER5

}RCGTIMERx; //the end of the enum


/* Declare an enum to configure the RCGPORTs */
typedef enum
{
    RCGPORTA,       //configuration of RCGPORTA
    RCGPORTB,       //configuration of RCGPORTB
    RCGPORTC,       //configuration of RCGPORTC
    RCGPORTD,       //configuration of RCGPORTD
    RCGPORTE,       //configuration of RCGPORTE
    RCGPORTF        //configuration of RCGPORTF

}RCGPORTx; //the end of the enum



Execution_state __SYSCTL_Enable_GPIOx__(u8 GPIOx);    //The Prototype Of Function That Enables the GPIOx Clock
Execution_state __SYSCTL_Disable_GPIOx__(u8 GPIOx);   //The Prototype Of Function That Disables the GPIOx Clock
Execution_state __SYSCTL_Enable_TIMERx__(u8 TIMERx);  //The Prototype Of Function That Enables the TIMERx Clock
Execution_state __SYSCTL_Disable_TIMERx__(u8 TIMERx); //The Prototype Of Function That Disables the TIMERx Clock





#endif /* SYSTEM_CONTROL_H_ */
