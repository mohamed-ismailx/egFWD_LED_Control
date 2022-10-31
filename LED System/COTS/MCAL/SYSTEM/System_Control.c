/**
  ******************************************************************************
  * @file    System_Control.c
  * @author  mohamed mohamed taha
  * @Target  TivaC TM4C123GH6PM
  * @version V1
  * @date    21-Aug-2022
  * @brief   This source file contains the implementation of System_Control functions .
  ******************************************************************************/

#include "Stdlib.h"
#include "System_Control_Private.h"
#include "System_Control.h"


//Function to Enable the GPIOx Clock
Execution_state __SYSCTL_Enable_GPIOx__(u8 GPIOx) {

    Execution_state Error_State = Execution_Correct;   //Define a variable to check error in the function


    switch(GPIOx) {   //Switching The Value Of GPIOx

        case RCGPORTA:   //case of RCGPORTA
            SYSCTL->RCGCGPIO.Bit_Access.R0 = Enable;   //enable the RCGPORTA
            break;  //end of the case

        case RCGPORTB:   //case of RCGPORTB
            SYSCTL->RCGCGPIO.Bit_Access.R1 = Enable;   //enable the RCGPORTB
            break;  //end of the case

        case RCGPORTC:   //case of RCGPORTC
            SYSCTL->RCGCGPIO.Bit_Access.R2 = Enable;   //enable the RCGPORTC
            break;  //end of the case

        case RCGPORTD:   //case of RCGPORTD
            SYSCTL->RCGCGPIO.Bit_Access.R3 = Enable;   //enable the RCGPORTD
            break;  //end of the case

        case RCGPORTE:   //case of RCGPORTE
            SYSCTL->RCGCGPIO.Bit_Access.R4 = Enable;   //enable the RCGPORTE
            break;  //end of the case

        case RCGPORTF:   //case of RCGPORTF
            SYSCTL->RCGCGPIO.Bit_Access.R5 = Enable;   //enable the RCGPORTF
            break;  //end of the case

        default:  //Default the pin value is error
            Error_State = Execution_Error;   //Update The Error State To The Variable
            break;  //end of the default

    } //the end of the switch



     return Error_State;    //Return the error state

} //the end of the function

//Function That Disables the GPIOx Clock
Execution_state __SYSCTL_Disable_GPIOx__(u8 GPIOx) {


    Execution_state Error_State = Execution_Correct;   //Define a variable to check error in the function


    switch(GPIOx) {   //Switching The Value Of GPIOx

        case RCGPORTA:   //case of RCGPORTA
            SYSCTL->RCGCGPIO.Bit_Access.R0 = Disable;   //Disable the RCGPORTA
            break;  //end of the case

        case RCGPORTB:   //case of RCGPORTB
            SYSCTL->RCGCGPIO.Bit_Access.R1 = Disable;   //Disable the RCGPORTB
            break;  //end of the case

        case RCGPORTC:   //case of RCGPORTC
            SYSCTL->RCGCGPIO.Bit_Access.R2 = Disable;   //Disable the RCGPORTC
            break;  //end of the case

        case RCGPORTD:   //case of RCGPORTD
            SYSCTL->RCGCGPIO.Bit_Access.R3 = Disable;   //Disable the RCGPORTD
            break;  //end of the case

        case RCGPORTE:   //case of RCGPORTE
            SYSCTL->RCGCGPIO.Bit_Access.R4 = Disable;   //Disable the RCGPORTE
            break;  //end of the case

        case RCGPORTF:   //case of RCGPORTF
            SYSCTL->RCGCGPIO.Bit_Access.R5 = Disable;   //Disable the RCGPORTF
            break;  //end of the case

        default:  //Default the pin value is error
            Error_State = Execution_Error;   //Update The Error State To The Variable
            break;  //end of the default

    } //the end of the switch


     return Error_State;    //Return the error state

} //the end of the function

//Function to Enable the TIMERx Clock
Execution_state __SYSCTL_Enable_TIMERx__(u8 TIMERx)
{
    Execution_state Error_State = Execution_Correct;   //Define a variable to check error in the function

    switch(TIMERx) {   //Switching The Value Of TIMERx

        case RCGTIMER0:   //case of RCGTIMER0
            SYSCTL->RCGCTIMER.Bit_Access.R0 = Enable;   //enable the RCGTIMER0
            break;  //end of the case

        case RCGTIMER1:   //case of RCGTIMER1
            SYSCTL->RCGCTIMER.Bit_Access.R1 = Enable;   //enable the RCGTIMER1
            break;  //end of the case

        case RCGTIMER2:   //case of RCGTIMER2
            SYSCTL->RCGCTIMER.Bit_Access.R2 = Enable;   //enable the RCGTIMER2
            break;  //end of the case

        case RCGTIMER3:   //case of RCGTIMER3
            SYSCTL->RCGCTIMER.Bit_Access.R3 = Enable;   //enable the RCGTIMER3
            break;  //end of the case

        case RCGTIMER4:   //case of RCGTIMER4
            SYSCTL->RCGCTIMER.Bit_Access.R4 = Enable;   //enable the RCGTIMER4
            break;  //end of the case

        case RCGTIMER5:   //case of RCGTIMER5
            SYSCTL->RCGCTIMER.Bit_Access.R5 = Enable;   //enable the RCGTIMER5
            break;  //end of the case

        default:  //Default the pin value is error
            Error_State = Execution_Error;   //Update The Error State To The Variable
            break;  //end of the default

    } //the end of the switch


     return Error_State;    //Return the error state

} //the end of the function


//Function to Disable the TIMERx Clock
Execution_state __SYSCTL_Disable_TIMERx__(u8 TIMERx)
{
    Execution_state Error_State = Execution_Correct;   //Define a variable to check error in the function

    switch(TIMERx) {   //Switching The Value Of TIMERx

        case RCGTIMER0:   //case of RCGTIMER0
            SYSCTL->RCGCTIMER.Bit_Access.R0 = Disable;   //Disable the RCGTIMER0
            break;  //end of the case

        case RCGTIMER1:   //case of RCGTIMER1
            SYSCTL->RCGCTIMER.Bit_Access.R1 = Disable;   //Disable the RCGTIMER1
            break;  //end of the case

        case RCGTIMER2:   //case of RCGTIMER2
            SYSCTL->RCGCTIMER.Bit_Access.R2 = Disable;   //Disable the RCGTIMER2
            break;  //end of the case

        case RCGTIMER3:   //case of RCGTIMER3
            SYSCTL->RCGCTIMER.Bit_Access.R3 = Disable;   //Disable the RCGTIMER3
            break;  //end of the case

        case RCGTIMER4:   //case of RCGTIMER4
            SYSCTL->RCGCTIMER.Bit_Access.R4 = Disable;   //Disable the RCGTIMER4
            break;  //end of the case

        case RCGTIMER5:   //case of RCGTIMER5
            SYSCTL->RCGCTIMER.Bit_Access.R5 = Disable;   //Disable the RCGTIMER5
            break;  //end of the case

        default:  //Default the pin value is error
            Error_State = Execution_Error;   //Update The Error State To The Variable
            break;  //end of the default

    } //the end of the switch


     return Error_State;    //Return the error state

} //the end of the function




