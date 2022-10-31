/**
  ******************************************************************************
  * @file    Timer.c
  * @author  mohamed mohamed taha
  * @Target  TivaC TM4C123GH6PM
  * @version V1
  * @date    22-Aug-2022
  * @brief   This source file contains the implementation of timer functions .
  ******************************************************************************/

#include "Stdlib.h"
#include "Macros.h"
#include "Timer_Private.h"
#include "Timer.h"
#include "Timer_Config.h"


static void(*Timer_Set_Call_Back_Timer1A)(void) = NULL;  //pointer to function to hold the function that comes from application layer

//Array Of Pointers To Structure To Access Timer Registers By Base Address Of the timers
static Timer_Registers *TIMERx[No_Timers] = {TIMER0,TIMER1,TIMER2,TIMER3,TIMER4,TIMER5,WIDE_TIMER0,WIDE_TIMER1,WIDE_TIMER2,WIDE_TIMER3,WIDE_TIMER4,WIDE_TIMER5};


//Definition Of Function That Configuration The Timer
Execution_state __TIMER_Initialize__(const TIMER_Configuration *Data) {

    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state

    if(Data != NULL)  //Check If The Content Of Structure Is Not Empty And It Hold The Address
    {

        if(Data->Mode == Normal_Mode) {

            if(Data->AB_Selection == TimerA) {

                TIMERx[Data->Channel]->GPTMCTL |= Disable;        //disable timer A

                Timer_Set_Call_Back_Timer1A = Data->Function;
                TIMERx[Data->Channel]->GPTMCFG = Data->Register_Size;    //select size of bits configuration option
                TIMERx[Data->Channel]->GPTMTAMR = Data->Period;          //select periodic counter mode of timer

                #if Timer_Tick == GPTM_1s
                    /*for over flow every one second*/
                    TIMERx[Data->Channel]->GPTMTAPR = 249;                   // update prescaler value
                    TIMERx[Data->Channel]->GPTMTAILR = 63999;                //update the value of the timer counter

                #elif Timer_Tick == GPTM_1us
                    /*for over flow every 1us*/
                    TIMERx[Data->Channel]->GPTMTAPR = 16;                   // update prescaler value
//                    TIMERx[Data->Channel]->GPTMTAILR = 64000;                //update the value of the timer counter

                #elif Timer_Tick == GPTM_10us
                    /*for over flow every 10us*/
                    TIMERx[Data->Channel]->GPTMTAPR = 160;                   // update prescaler value
//                    TIMERx[Data->Channel]->GPTMTAILR = 64000;                //update the value of the timer counter

                #elif Timer_Tick == GPTM_100us
                    /*for over flow every 100us*/
                    TIMERx[Data->Channel]->GPTMTAPR = 1600;                   // update prescaler value
//                    TIMERx[Data->Channel]->GPTMTAILR = 64000;                //update the value of the timer counter


                #endif

                TIMERx[Data->Channel]->GPTMICR = 1 << (Data->Interrupt);  //clear the selected interrupt flag
                TIMERx[Data->Channel]->GPTMIMR |= 1 << (Data->Interrupt);  //enable the selected interrupt mask

                TIMERx[Data->Channel]->GPTMCTL |= Enable;        //enable timer A


            } //the end of the if statement

            else if(Data->AB_Selection == TimerB) {

                TIMERx[Data->Channel]->GPTMCTL |= (Enable << 8);        //disable timer B

//              Timer_Set_Call_Back_Timer1A = Data->Function;

                TIMERx[Data->Channel]->GPTMCFG = Data->Register_Size;  //select size of bits configuration option
                TIMERx[Data->Channel]->GPTMTBMR = ((Data->Period) | (Data->Direction));       //select periodic counter mode of timer
                /*for over flow every one second*/
                TIMERx[Data->Channel]->GPTMTBPR = 249;               // update prescaler value
                TIMERx[Data->Channel]->GPTMTBILR = 63999;            //update the value of the timer counter

                TIMERx[Data->Channel]->GPTMICR |= (1 << (Data->Interrupt));   //clear the selected interrupt flag
                TIMERx[Data->Channel]->GPTMIMR |= (1 << (Data->Interrupt));   //enable the selected interrupt mask

                TIMERx[Data->Channel]->GPTMCTL |= (Enable << 8);   //enable timer B

            } //the end of the else if scope


            else {
                Error_State = Execution_Error;    //Update the error state to the variable
            }


        }

        else if(Data->Mode == Compare_Match_Mode) {

            if(Data->AB_Selection == TimerA) {

                    TIMERx[Data->Channel]->GPTMCFG = Data->Register_Size;    //select size of bits configuration option
                    TIMERx[Data->Channel]->GPTMTAMR = Data->Period | (1 << 5);          //select periodic counter mode of timer
                    /*for over flow every one second*/
                    TIMERx[Data->Channel]->GPTMTAPR = 249;                   // update prescaler value
                    TIMERx[Data->Channel]->GPTMTAILR = 63999;                //update the value of the timer counter

                    TIMERx[Data->Channel]->GPTMICR = 1 << (Data->Interrupt);  //clear the selected interrupt flag
                    TIMERx[Data->Channel]->GPTMIMR |= 1 << (Data->Interrupt);  //enable the selected interrupt mask

                    TIMERx[Data->Channel]->GPTMCTL |= Enable;        //enable timer A


                } //the end of the if statement

                else if(Data->AB_Selection == TimerB) {

                    TIMERx[Data->Channel]->GPTMCFG = Data->Register_Size;  //select size of bits configuration option
                    TIMERx[Data->Channel]->GPTMTBMR = Data->Period | (1 << 5);          //select periodic counter mode of timer
                    /*for over flow every one second*/
                    TIMERx[Data->Channel]->GPTMTBPR = 249;               // update prescaler value
                    TIMERx[Data->Channel]->GPTMTBILR = 63999;            //update the value of the timer counter

                    TIMERx[Data->Channel]->GPTMICR |= (1 << (Data->Interrupt));   //clear the selected interrupt flag
                    TIMERx[Data->Channel]->GPTMIMR |= (1 << (Data->Interrupt));   //enable the selected interrupt mask

                    TIMERx[Data->Channel]->GPTMCTL |= (Enable << 8);   //enable timer B

                } //the end of the else if scope


        } //the end of the else if scope


    } //the end of if statement


    else    //else the structure is empty address
        Error_State = Execution_Error;    //Update the error state to the variable


    return Error_State;    //Return the error state

} //the end of the function


//function to start the timer
Execution_state __TIMER_Start__(const TIMER_Configuration *Data) {

    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state

    if(Data != NULL)  //Check If The Content Of Structure Is Not Empty And It Hold The Address
    {

        if(Data->AB_Selection == TimerA) {

            TIMERx[Data->Channel]->GPTMCTL |= Enable;        //enable timer A

        }  //the end of the if statement

        else if(Data->AB_Selection == TimerB) {

            TIMERx[Data->Channel]->GPTMCTL |= (Enable);   //enable timer B
        }  //end of the else if scope

    } //the end of the if statement

    else    //else the structure is empty address
        Error_State = Execution_Error;    //Update the error state to the variable

    return Error_State;    //Return the error state

} //the end of the function



//function to stop the timer
Execution_state __TIMER_Stop__(const TIMER_Configuration *Data) {

    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state

    if(Data != NULL)  //Check If The Content Of Structure Is Not Empty And It Hold The Address
    {

        if(Data->AB_Selection == TimerA) {

            TIMERx[Data->Channel]->GPTMCTL &= ~Enable ;   //disable timer A

        }  //the end of the if statement

        else if(Data->AB_Selection == TimerB) {

            TIMERx[Data->Channel]->GPTMCTL &= ~(Enable);   //disable timer B

        }  //end of the else if scope

    } //the end of the if statement

    else    //else the structure is empty address
        Error_State = Execution_Error;    //Update the error state to the variable


    return Error_State;    //Return the error state



}//the end of the function



//function to write the counter register
Execution_state __TIMER_Write_Counter_Register__(const TIMER_Configuration *Data,u8 value) {

    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state

    if(Data != NULL)  //Check If The Content Of Structure Is Not Empty And It Hold The Address
    {

        if(Data->AB_Selection == TimerA) {

            TIMERx[Data->Channel]->GPTMTAILR = value;                //update the value of the timer counter

          }  //the end of the if statement

          else if(Data->AB_Selection == TimerB) {

              TIMERx[Data->Channel]->GPTMTBILR = value;            //update the value of the timer counter

          }  //end of the else if scope

    } //the end of the if statement

    else    //else the structure is empty address
        Error_State = Execution_Error;    //Update the error state to the variable


    return Error_State;    //Return the error state


}  //the end of the function


//function to read counter register
u8 __TIMER_Read_Counter_Register__(const TIMER_Configuration *Data) {

    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state
    u8 Read_Data; //declare a variable to hold the data

    if(Data != NULL)  //Check If The Content Of Structure Is Not Empty And It Hold The Address
    {

        if(Data->AB_Selection == TimerA) {

            Read_Data = TIMERx[Data->Channel]->GPTMTAILR;                //read the value of the timer counter

          }  //the end of the if statement

          else if(Data->AB_Selection == TimerB) {

              Read_Data = TIMERx[Data->Channel]->GPTMTBILR;            //read the value of the timer counter

          }  //end of the else if scope

    } //the end of the if statement

    else    //else the structure is empty address
        Error_State = Execution_Error;    //Update the error state to the variable


    return Error_State == Execution_Error ? Error_State : Read_Data;    //Return the error state


}  //the end of the function



//function to clear interrupt flag
Execution_state __TIMER_Clear_Flag__(const TIMER_Configuration *Data) {

    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state

    if(Data != NULL)  //Check If The Content Of Structure Is Not Empty And It Hold The Address
    {

        if(Data->AB_Selection == TimerA) {

            TIMERx[Data->Channel]->GPTMICR = 1 << (Data->Interrupt);  //clear the selected interrupt flag

          }  //the end of the if statement

          else if(Data->AB_Selection == TimerB) {

            TIMERx[Data->Channel]->GPTMICR |= (1 << ((Data->Interrupt)));   //clear the selected interrupt flag

          }  //end of the else if scope

    } //the end of the if statement

    else    //else the structure is empty address
        Error_State = Execution_Error;    //Update the error state to the variable


    return Error_State;    //Return the error state

} //the end of the function


//function to read the masked interrupt status
u8 __TIMER_Masked_Interrupt_Status__(const TIMER_Configuration *Data) {

    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state
    u8 Read_Data; //declare a variable to hold the data

    if(Data != NULL)  //Check If The Content Of Structure Is Not Empty And It Hold The Address
    {
        if(Data->AB_Selection == TimerA) {

            Read_Data = Get_Bit(TIMERx[Data->Channel]->GPTMMIS,Data->Interrupt);

          }  //the end of the if statement

          else if(Data->AB_Selection == TimerB) {

              Read_Data = Get_Bit(TIMERx[Data->Channel]->GPTMMIS,(Data->Interrupt));

          }  //end of the else if scope

    } //the end of the if statement

    else    //else the structure is empty address
        Error_State = Execution_Error;    //Update the error state to the variable


    return Error_State == Execution_Error ? Error_State : Read_Data;    //Return the error state

} //the end of the function



Execution_state __TIMER_Write_Compare_Match_Register__(const TIMER_Configuration *Data,u32 value) {


    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state

    if(Data != NULL)  //Check If The Content Of Structure Is Not Empty And It Hold The Address
    {

            if(Data->AB_Selection == TimerA) {

                TIMERx[Data->Channel]->GPTMTAMATCHR = value;   //up date value to compare match register
              }  //the end of the if statement

              else if(Data->AB_Selection == TimerB) {

                  TIMERx[Data->Channel]->GPTMTBMATCHR = value; //up date value to compare match register
              }  //end of the else if scope


    } //the end of the if statement

    else    //else the structure is empty address
        Error_State = Execution_Error;    //Update the error state to the variable


    return Error_State;    //Return the error state


    } //the end of the function


//function to read the row interrupt
u8 __TIMER_Read_Row_Interrupt_Status__(const TIMER_Configuration *Data){


    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state
    u8 Read_Data; //declare a variable to hold the data

    if(Data != NULL)  //Check If The Content Of Structure Is Not Empty And It Hold The Address
    {

            if(Data->AB_Selection == TimerA) {

                Read_Data = Get_Bit(TIMERx[Data->Channel]->GPTMRIS,Data->Interrupt);                //read the value of the row interrupt status

              }  //the end of the if statement

              else if(Data->AB_Selection == TimerB) {

                  Read_Data = Get_Bit(TIMERx[Data->Channel]->GPTMRIS,Data->Interrupt);                //read the value of the row interrupt status

              }  //end of the else if scope


    } //the end of the if statement

    else    //else the structure is empty address
        Error_State = Execution_Error;    //Update the error state to the variable


    return Error_State == Execution_Error ? Error_State : Read_Data;    //Return the error state


} //the end of the function


//function to read the timer prescale
u8 __TIMER_Get_Prescale__(const TIMER_Configuration *Data) {


    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state
    u8 Read_Data; //declare a variable to hold the data

    if(Data != NULL)  //Check If The Content Of Structure Is Not Empty And It Hold The Address
    {

        if(Data->AB_Selection == TimerA) {

            Read_Data = TIMERx[Data->Channel]->GPTMTAPR;                //read the value of the timer prescale

          }  //the end of the if statement

          else if(Data->AB_Selection == TimerB) {

              Read_Data = TIMERx[Data->Channel]->GPTMTBPR;                //read the value of the timer prescale

          }  //end of the else if scope

    } //the end of the if statement

    else    //else the structure is empty address
        Error_State = Execution_Error;    //Update the error state to the variable


    return Error_State == Execution_Error ? Error_State : Read_Data;    //Return the error state


} //the end of the function



//function to read the timer prescale match
u8 __TIMER_Get_Prescale_Match__(const TIMER_Configuration *Data) {

    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state
    u8 Read_Data; //declare a variable to hold the data

    if(Data != NULL)  //Check If The Content Of Structure Is Not Empty And It Hold The Address
    {

        if(Data->AB_Selection == TimerA) {

            Read_Data = TIMERx[Data->Channel]->GPTMTAPMR;                //read the value of the timer prescale

          }  //the end of the if statement

          else if(Data->AB_Selection == TimerB) {

              Read_Data = TIMERx[Data->Channel]->GPTMTBPMR;                //read the value of the timer prescale

          }  //end of the else if scope

    } //the end of the if statement

    else    //else the structure is empty address
        Error_State = Execution_Error;    //Update the error state to the variable


    return Error_State == Execution_Error ? Error_State : Read_Data;    //Return the error state


} //the end of the function


//function to read the current timer value
u8 __TIMER_Read_Current_Timer_Value__(const TIMER_Configuration *Data)
{

    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state
    u8 Read_Data; //declare a variable to hold the data

    if(Data != NULL)  //Check If The Content Of Structure Is Not Empty And It Hold The Address
    {

        if(Data->AB_Selection == TimerA) {

            Read_Data = TIMERx[Data->Channel]->GPTMTAR;                //read the value of the current timer value

          }  //the end of the if statement

          else if(Data->AB_Selection == TimerB) {

              Read_Data = TIMERx[Data->Channel]->GPTMTBR;                //read the value of the current timer value

          }  //end of the else if scope

    } //the end of the if statement

    else    //else the structure is empty address
        Error_State = Execution_Error;    //Update the error state to the variable


    return Error_State == Execution_Error ? Error_State : Read_Data;    //Return the error state



} //the end of the function



//function to write the timer value register
Execution_state __TIMER_Write_Timer_Value__(const TIMER_Configuration *Data,u8 value) {


    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state

       if(Data != NULL)  //Check If The Content Of Structure Is Not Empty And It Hold The Address
       {

           if(Data->AB_Selection == TimerA) {

             TIMERx[Data->Channel]->GPTMTAV = value;                //write the value of the timer value register

           }  //the end of the if statement

           else if(Data->AB_Selection == TimerB) {

               TIMERx[Data->Channel]->GPTMTBV= value;                 //write the value of the timer value register

           }  //end of the else if scope

       } //the end of the if statement

       else    //else the structure is empty address
           Error_State = Execution_Error;    //Update the error state to the variable


       return Error_State;    //Return the error state


} //the end of the function



//function to read the current RTC value
u8 __TIMER_Read_Current_RTC_Value__(const TIMER_Configuration *Data) {

    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state
    u8 Read_Data; //declare a variable to hold the data

    if(Data != NULL)  //Check If The Content Of Structure Is Not Empty And It Hold The Address
    {

        Read_Data = TIMERx[Data->Channel]->GPTMRTCPD;      //read the value of the RTC value register

    } //the end of the if statement

    else    //else the structure is empty address
        Error_State = Execution_Error;    //Update the error state to the variable


    return Error_State == Execution_Error ? Error_State : Read_Data;    //Return the error state


} //the end of the function



//prototype of the function that reads the Prescale Snapshot
u8 __TIMER_Read_Prescale_Snapshot_Value__(const TIMER_Configuration *Data) {


    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state
    u8 Read_Data; //declare a variable to hold the data

    if(Data != NULL)  //Check If The Content Of Structure Is Not Empty And It Hold The Address
    {

           if(Data->AB_Selection == TimerA) {

               Read_Data = TIMERx[Data->Channel]->GPTMTAPS;                //read the value of the timer value register

           }  //the end of the if statement

           else if(Data->AB_Selection == TimerB) {

               Read_Data = TIMERx[Data->Channel]->GPTMTBPS;                //read the value of the timer value register

           }  //end of the else if scope



    } //the end of the if statement

    else    //else the structure is empty address
        Error_State = Execution_Error;    //Update the error state to the variable


    return Error_State == Execution_Error ? Error_State : Read_Data;    //Return the error state


} //the end of the function



//function to reads the Prescale Value
u8 __TIMER_Read_Prescale_Value__(const TIMER_Configuration *Data){

    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state
    u8 Read_Data; //declare a variable to hold the data

    if(Data != NULL)  //Check If The Content Of Structure Is Not Empty And It Hold The Address
    {

        if(Data->AB_Selection == TimerA) {

            Read_Data = TIMERx[Data->Channel]->GPTMTAPV;                //read the value of the timer value register

           }  //the end of the if statement

           else if(Data->AB_Selection == TimerB) {

               Read_Data = TIMERx[Data->Channel]->GPTMTAPV;                //read the value of the timer value register

           }  //end of the else if scope

    } //the end of the if statement

    else    //else the structure is empty address
        Error_State = Execution_Error;    //Update the error state to the variable


    return Error_State == Execution_Error ? Error_State : Read_Data;    //Return the error state



} //the end of the function






//ISR of TIMER1A
void TIMER1A_Handler(void)
{

    Timer_Set_Call_Back_Timer1A();   //call the set call back function from the HAL layer

}   //the end of the function





