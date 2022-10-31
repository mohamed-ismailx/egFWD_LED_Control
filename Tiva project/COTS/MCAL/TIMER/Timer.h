/**
  ******************************************************************************
  * @file    Timer.h
  * @author  mohamed mohamed taha
  * @Target  TivaC TM4C123GH6PM
  * @version V1
  * @date    22-Aug-2022
  * @brief   This header file contains the prototypes of Timer functions and others.
  ******************************************************************************/

#ifndef TIMER_H_
#define TIMER_H_


#define GPTM_1s      0     //define the overflow time is 1s
#define GPTM_1us     1     //define the time of one tick is 1us
#define GPTM_10us    2     //define the time of one tick is 10us
#define GPTM_100us   3     //define the time of one tick is 100us



#define No_Timers  12

/* Declare an enum to configure the Timer's channels */
typedef enum {

    Timer0,       //configuration of  the Timer0 16/32
    Timer1,       //configuration of  the Timer0 16/32
    Timer2,       //configuration of  the Timer0 16/32
    Timer3,       //configuration of  the Timer0 16/32
    Timer4,       //configuration of  the Timer0 16/32
    Timer5,       //configuration of  the Timer5 16/32
    Wide_Timer0,  //configuration of  the Wide Timer0 32/64
    Wide_Timer1,  //configuration of  the Wide Timer0 32/64
    Wide_Timer2,  //configuration of  the Wide Timer0 32/64
    Wide_Timer3,  //configuration of  the Wide Timer0 32/64
    Wide_Timer4,  //configuration of  the Wide Timer0 32/64
    Wide_Timer5   //configuration of  the Wide Timer5 32/64

}TIMER_Channels;  //the end of the enum


/* Declare an enum to configure the Timer's A and B */
typedef enum {

    TimerA,         //configure Timer A
    TimerB,         //configure Timer B
    Both            //configure Timer AB

}TIMER_AB;   //the end of the enum


/* Declare an enum to configure the Timer's Modes */
typedef enum {

    Normal_Mode = 0x1,    //configuration of the Normal Mode
    Compare_Match_Mode          //configuration of the Compare Match Mode

}TIMER_Modes ;  //the end of the enum



/* Declare an enum to configure the Timer's bits size */
typedef enum {

    Timer_32bit_64bit = 0x0,        //For a 16/32-bit timer, this value selects the 32-bit timer configuration.
                                   // and, For a 32/64-bit wide timer, this value selects the 64-bit timer configuration

    Timer_32bit_64bit_RTC = 0x1,    //For a 16/32-bit timer, this value selects the 32-bit real-time clock (RTC) counter configuration.
                                   //For a 32/64-bit wide timer, this value selects the 64-bit real-time clock (RTC) counter configuration.

    Timer_16bit_32bit = 0x4              //For a 16/32-bit timer, this value selects the 16-bit timer configuration.
                                        //For a 32/64-bit wide timer, this value selects the 32-bit timer configuration.

}TIMER_Register_Size;  //the end of the enum


/* Declare an enum to configure the Timer's directions */
typedef enum {

    Timer_Count_Down,    //configuration of the count down
    Timer_Count_Up = 0b100   //configuration of the count up

}TIMER_Direction ;  //the end of the enum



/* Declare an enum to configure the Timer's Modes */
typedef enum {

    One_Shot_Timer_Mode = 0x1,    //configuration of the One Shot Timer Mode
    Periodic_Timer_Mode,          //configuration of the Periodic Timer Mode
    Capture_Mode,                 //configuration of the Capture Mode

}TIMER_Periods ;  //the end of the enum


/* Declare an enum to configure the Timer's Interrupts */
typedef enum {

    TIMERA_Time_Out_Interrupt_Mask,                     //configuration of the Time Out Interrupt Mask A
    TIMERA_Capture_Mode_Match_Interrupt_Mask,           //configuration of the Capture Mode Match  Interrupt Mask A
    TIMERA_Timer_Capture_Mode_Event_Interrupt_Mask,     //configuration of the Timer Capture Mode Event Interrupt Mask A
    TIMERA_RTC_Interrupt_Mask,                          //configuration of the RTC Interrupt Mask A
    TIMERA_Match_Interrupt_Mask,                         //configuration of the Match Interrupt Mask A

    TIMERB_Time_Out_Interrupt_Mask = 0b1000,            //configuration of the Time Out Interrupt Mask B
    TIMERB_Capture_Mode_Match_Interrupt_Mask,           //configuration of the Capture Mode Match  Interrupt Mask B
    TIMERB_Timer_Capture_Mode_Event_Interrupt_Mask,     //configuration of the Timer Capture Mode Event Interrupt Mask B
    TIMERB_Match_Interrupt_Mask                         //configuration of the Match Interrupt Mask B


}TIMER_Interrupts ;  //the end of the enum


/* Declare a structure for timer configuration parameters  */
typedef struct
{
    TIMER_Channels       Channel;        //Declare a variable from type TIMER_Channels
    TIMER_AB             AB_Selection;   //Declare a variable from type TIMER_AB
    TIMER_Modes          Mode;           //Declare a variable from type TIMER_Modes
    TIMER_Register_Size  Register_Size;  //Declare a variable from type TIMER_Register_Size
    TIMER_Direction      Direction;      //Declare a variable from type TIMER_Direction
    TIMER_Periods        Period;         //Declare a variable from type TIMER_Modes
    TIMER_Interrupts     Interrupt;      //Declare a variable from type TIMER_Interrupts
    void(*Function)(void);               //Declare a pointer to function to hold the function that will used

}TIMER_Configuration; //the end of the structure


Execution_state __TIMER_Initialize__(const TIMER_Configuration *Data);                     //prototype of the function that initializes the timer
Execution_state __TIMER_Start__(const TIMER_Configuration *Data);                                     //prototype of the function that starts the timer
Execution_state __TIMER_Stop__(const TIMER_Configuration *Data);                                      //prototype of the function that stops the timer
Execution_state __TIMER_Write_Counter_Register__(const TIMER_Configuration *Data,u8 value);           //prototype of the function that writes on the counter register
u8 __TIMER_Read_Counter_Register__(const TIMER_Configuration *Data);       //prototype of the function that reads the counter register
Execution_state __TIMER_Write_Compare_Match_Register__(const TIMER_Configuration *Data,u32 value);    //prototype of the function that writes on the compare match register
Execution_state __TIMER_Clear_Flag__(const TIMER_Configuration *Data);                                //prototype of the function that clears the selected interrupt flag
Execution_state __TIMER_Masked_Interrupt_Status__(const TIMER_Configuration *Data);                     //prototype of the function that read the mask interrupt status
u8 __TIMER_Get_Prescale__(const TIMER_Configuration *Data);                     //prototype of the function that read the timer prescale
u8 __TIMER_Read_Row_Interrupt_Status__(const TIMER_Configuration *Data);       //prototype of the function that reads the row interrupt
u8 __TIMER_Get_Prescale_Match__(const TIMER_Configuration *Data);                     //prototype of the function that read the timer prescale match
u8 __TIMER_Read_Current_Timer_Value__(const TIMER_Configuration *Data);       //prototype of the function that reads the current timer value
Execution_state __TIMER_Write_Timer_Value__(const TIMER_Configuration *Data,u8 value);           //prototype of the function that writes on the Timer value
u8 __TIMER_Read_Current_RTC_Value__(const TIMER_Configuration *Data);       //prototype of the function that reads the current RTC value
u8 __TIMER_Read_Prescale_Snapshot_Value__(const TIMER_Configuration *Data);       //prototype of the function that reads the Prescale Snapshot
u8 __TIMER_Read_Prescale_Value__(const TIMER_Configuration *Data);       //prototype of the function that reads the Prescale Value



#endif /* TIMER_H_ */
