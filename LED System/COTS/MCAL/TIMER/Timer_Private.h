/**
  ******************************************************************************
  * @file    Timer_Private.h
  * @author  mohamed mohamed taha
  * @Target  TivaC TM4C123GH6PM
  * @version V1
  * @date    22-Aug-2022
  * @brief   This header file contains the registers of Timer.
  ******************************************************************************/


/*Header file guard*/
#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_


//declare a structure to declare Timer registers
typedef struct {

    volatile u32 GPTMCFG;     //declare the GPTM Configuration registers
    volatile u32 GPTMTAMR;    //declare the GPTM Timer A Mode registers
    volatile u32 GPTMTBMR;    //declare the GPTM Timer B Mode registers
    volatile u32 GPTMCTL;     //declare the GPTM Control registers
    volatile u32 GPTMSYNC;    //declare the GPTM Synchronize registers
    volatile u32 Reserved;    //reserved
    volatile u32 GPTMIMR;     //declare the GPTM Interrupt Mask registers
    volatile u32 GPTMRIS;     //declare the GPTM Raw Interrupt Status registers
    volatile u32 GPTMMIS;     //declare the GPTM Masked Interrupt Status registers
    volatile u32 GPTMICR;     //declare the GPTM Interrupt Clear registers
    volatile u32 GPTMTAILR;   //declare the GPTM Timer A Interval Load registers
    volatile u32 GPTMTBILR;   //declare the GPTM Timer B Interval Load registers
    volatile u32 GPTMTAMATCHR;//declare the GPTM Timer A Match registers
    volatile u32 GPTMTBMATCHR;//declare the GPTM Timer B Match registers
    volatile u32 GPTMTAPR;    //declare the GPTM Timer A Prescale registers
    volatile u32 GPTMTBPR;    //declare the GPTM Timer B Prescale registers
    volatile u32 GPTMTAPMR;   //declare the GPTM TimerA Prescale Match registers
    volatile u32 GPTMTBPMR;   //declare the GPTM TimerB Prescale Match registers
    volatile u32 GPTMTAR;     //declare the GPTM Timer A registers
    volatile u32 GPTMTBR;     //declare the GPTM Timer B registers
    volatile u32 GPTMTAV;     //declare the GPTM Timer A Value registers
    volatile u32 GPTMTBV;     //declare the GPTM Timer B Value registers
    volatile u32 GPTMRTCPD;   //declare the GPTM RTC Predivide registers
    volatile u32 GPTMTAPS;    //declare the GPTM Timer A Prescale Snapshot registers
    volatile u32 GPTMTBPS;    //declare the GPTM Timer B Prescale Snapshot registers
    volatile u32 GPTMTAPV;    //declare the GPTM Timer A Prescale Value registers
    volatile u32 GPTMTBPV;    //declare the GPTM Timer B Prescale Value registers
    volatile u32 GPTMPP;      //declare the GPTM Peripheral Properties registers

}Timer_Registers;   //the end of the structure


#define TIMER0 ((Timer_Registers*)0x40030000)        //Define the TIMER0 16/32 base address
#define TIMER1 ((Timer_Registers*)0x40031000)        //Define the TIMER1 16/32 base address
#define TIMER2 ((Timer_Registers*)0x40032000)        //Define the TIMER2 16/32 base address
#define TIMER3 ((Timer_Registers*)0x40033000)        //Define the TIMER3 16/32 base address
#define TIMER4 ((Timer_Registers*)0x40034000)        //Define the TIMER4 16/32 base address
#define TIMER5 ((Timer_Registers*)0x40035000)        //Define the TIMER5 16/32 base address
#define WIDE_TIMER0 ((Timer_Registers*)0x40036000)   //Define the WIDE_TIMER0 32/64 base address
#define WIDE_TIMER1 ((Timer_Registers*)0x40037000)   //Define the WIDE_TIMER1 32/64 base address
#define WIDE_TIMER2 ((Timer_Registers*)0x4004C000)  //Define the WIDE_TIMER2 32/64 base address
#define WIDE_TIMER3 ((Timer_Registers*)0x4004D000)  //Define the WIDE_TIMER3 32/64 base address
#define WIDE_TIMER4 ((Timer_Registers*)0x4004E000)  //Define the WIDE_TIMER4 32/64 base address
#define WIDE_TIMER5 ((Timer_Registers*)0x4004F000)  //Define the WIDE_TIMER5 32/64 base address




#endif /* TIMER_PRIVATE_H_ */
