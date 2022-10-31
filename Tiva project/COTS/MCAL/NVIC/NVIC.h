/**
  ******************************************************************************
  * @file    NVIC.h
  * @author  mohamed mohamed taha
  * @Target  TivaC TM4C123GH6PM
  * @version V1
  * @date    20-Aug-2022
  * @brief   This header file contains the prototypes of NVIC functions and others.
  ******************************************************************************/

/*Header file guard*/
#ifndef NVIC_H_
#define NVIC_H_


#define NVIC_8_Group_1_Sub  	0x4       //define 8 numbers of group and 1 numbers of sub
#define NVIC_4_Group_2_Sub      0x5       //define 4 numbers of group and 2 numbers of sub
#define NVIC_2_Group_4_Sub  	0x6       //define 2 numbers of group and 4 numbers of sub
#define NVIC_1_Group_8_Sub  	0x7       //define 1 numbers of group and 8 numbers of sub

#define NVIC_No_Interrupts       138         //define the number of the interrupts

#define NVIC_Register_Bits   32     //define the number of the NVIC register's bits

#define NVIC_Max_Groups 7       //define the max number of groups
#define NVIC_Max_Subs   7       //define the max number of subs



//declare an enum to define the priority groups
typedef enum
{
	NVIC_Group_Zero,      //define group zero (higher priority)
	NVIC_Group_One,       //define group one priority
	NVIC_Group_Two,       //define group two priority
	NVIC_Group_Three,     //define group three priority
	NVIC_Group_Four,      //define group four priority
	NVIC_Group_Five,      //define group five priority
	NVIC_Group_Six,       //define group six priority
	NVIC_Group_Seven,     //define group seven priority

}NVIC_Group_Numbers;



//declare an enum to define the priority subs
typedef enum
{
	NVIC_Sub_Zero,     //define sub zero (higher priority)
	NVIC_Sub_One,      //define sub one priority
	NVIC_Sub_Two,      //define sub two priority
	NVIC_Sub_Three,    //define sub three priority
	NVIC_Sub_Four,     //define sub four priority
	NVIC_Sub_Five,     //define sub five priority
	NVIC_Sub_Six,      //define sub six priority
	NVIC_Sub_Seven,    //define sub seven priority

}NVIC_Sub_Numbers;


//declare an enum to define the positions of peripherals
typedef enum
{
	/* NVIC Peripherals Position */
    INT_GPIOA      ,     // GPIO Port A
    INT_GPIOB      ,     // GPIO Port B
    INT_GPIOC      ,     // GPIO Port C
    INT_GPIOD      ,     // GPIO Port D
    INT_GPIOE      ,     // GPIO Port E
    INT_UART0      ,     // UART0
    INT_UART1      ,     // UART1
    INT_SSI0       ,     // SSI0
    INT_I2C0       ,     // I2C0
    INT_PWM0_FAULT ,     // PWM0 Fault
    INT_PWM0_0     ,     // PWM0 Generator 0
    INT_PWM0_1     ,     // PWM0 Generator 1
    INT_PWM0_2     ,     // PWM0 Generator 2
    INT_QEI0       ,     // QEI0
    INT_ADC0SS0    ,     // ADC0 Sequence 0
    INT_ADC0SS1    ,     // ADC0 Sequence 1
    INT_ADC0SS2    ,     // ADC0 Sequence 2
    INT_ADC0SS3    ,     // ADC0 Sequence 3
    INT_WATCHDOG   ,     // Watchdog Timers 0 and 1
    INT_TIMER0A    ,     // 16/32-Bit Timer 0A
    INT_TIMER0B    ,     // 16/32-Bit Timer 0B
    INT_TIMER1A    ,     // 16/32-Bit Timer 1A
    INT_TIMER1B    ,     // 16/32-Bit Timer 1B
    INT_TIMER2A    ,     // 16/32-Bit Timer 2A
    INT_TIMER2B    ,     // 16/32-Bit Timer 2B
    INT_COMP0      ,     // Analog Comparator 0
    INT_COMP1      ,     // Analog Comparator 1
    INT_SYSCTL = 28,     // System Control
    INT_FLASH      ,     // Flash Memory Control and EEPROM
    INT_GPIOF      ,     // GPIO Port F
    INT_UART2 = 33 ,     // UART2
    INT_SSI1       ,     // SSI1
    INT_TIMER3A    ,     // 16/32-Bit Timer 3A
    INT_TIMER3B    ,     // Timer 3B
    INT_I2C1       ,     // I2C1
    INT_QEI1       ,     // QEI1
    INT_CAN0       ,     // CAN0
    INT_CAN1       ,     // CAN1
    INT_HIBERNATE = 43,     // Hibernation Module
    INT_USB0       ,     // USB
    INT_PWM0_3     ,     // PWM Generator 3
    INT_UDMA       ,     // uDMA Software
    INT_UDMAERR    ,     // uDMA Error
    INT_ADC1SS0    ,     // ADC1 Sequence 0
    INT_ADC1SS1    ,     // ADC1 Sequence 1
    INT_ADC1SS2    ,     // ADC1 Sequence 2
    INT_ADC1SS3    ,     // ADC1 Sequence 3
    INT_SSI2  = 57 ,     // SSI2
    INT_SSI3       ,     // SSI3
    INT_UART3      ,     // UART3
    INT_UART4      ,     // UART4
    INT_UART5      ,     // UART5
    INT_UART6      ,     // UART6
    INT_UART7      ,     // UART7
    INT_I2C2  = 68 ,     // I2C2
    INT_I2C3       ,     // I2C3
    INT_TIMER4A    ,     // 16/32-Bit Timer 4A
    INT_TIMER4B    ,     // 16/32-Bit Timer 4B
    INT_TIMER5A = 92 ,     // 16/32-Bit Timer 5A
    INT_TIMER5B    ,     // 16/32-Bit Timer 5B
    INT_WTIMER0A   ,     // 32/64-Bit Timer 0A
    INT_WTIMER0B   ,     // 32/64-Bit Timer 0B
    INT_WTIMER1A   ,     // 32/64-Bit Timer 1A
    INT_WTIMER1B   ,     // 32/64-Bit Timer 1B
    INT_WTIMER2A   ,     // 32/64-Bit Timer 2A
    INT_WTIMER2B   ,     // 32/64-Bit Timer 2B
    INT_WTIMER3A   ,     // 32/64-Bit Timer 3A
    INT_WTIMER3B   ,     // 32/64-Bit Timer 3B
    INT_WTIMER4A   ,     // 32/64-Bit Timer 4A
    INT_WTIMER4B   ,     // 32/64-Bit Timer 4B
    INT_WTIMER5A   ,     // 32/64-Bit Timer 5A
    INT_WTIMER5B   ,     // 32/64-Bit Timer 5B
    INT_SYSEXC     ,     // System Exception (imprecise)
    INT_PWM1_0 = 134,     // PWM1 Generator 0
    INT_PWM1_1     ,     // PWM1 Generator 1
    INT_PWM1_2     ,     // PWM1 Generator 2
    INT_PWM1_3     ,     // PWM1 Generator 3
    INT_PWM1_FAULT       // PWM1 Fault

}NVIC_Peripherals_Position;


//declare a union to assign the value of priority (group, sub)
typedef union
{

	//declare a structure to assign the value of group priority
	struct
	{
		u8 Reserved : 5 ;        //the first 5bits that in IPR register is not used
		u8 Group    : 3 ;        //declare 3bits for group priority

	}NVIC_8_Group_1_Sub_Access;

	//declare a structure to assign the value of group and sub priorities
	struct
	{
		u8 Reserved : 5 ;        //the first 5bits that in IPR register is not used
		u8 Sub      : 1 ;        //declare 1bit for sub priority
		u8 Group    : 2 ;        //declare 2bits for group priority

	}NVIC_4_Group_2_Sub_Access;


	//declare a structure to assign the value of group and sub priorities
	struct
	{
		u8 Reserved : 5 ;        //the first 5bits that in IPR register is not used
		u8 Sub      : 2 ;        //declare 2bits for sub priority
		u8 Group    : 1 ;        //declare 1bit for group priority

	}NVIC_2_Group_4_Sub_Access;


	//declare a structure to assign the value of group and sub priorities
	struct
	{
		u8 Reserved : 5 ;      //the first 5bits that in IPR register is not used
		u8 Sub      : 3 ;      //declare 3bits for sub priority

	}NVIC_1_Group_8_Sub_Access;


	u8 IPR_Register;           //declare a variable to hold the value of the IPR register

}NVIC_IPR_Configuration;


void __NVIC_Initialize_Priority_Field__(void);   //prototype of the function that initializes the NVIC

Execution_state __NVIC_Enable_Interrupt_Peripheral__(u8 Interrupt);     //prototype of the function that enables the interrupts
Execution_state __NVIC_Disable_Interrupt_Peripheral__(u8 Interrupt);    //prototype of the function that disables the interrupts

Execution_state __NVIC_Enable_Pending_Flag_Interrupt_Peripheral__(u8 Interrupt);  //prototype of the function that enables pending flag of interrupts
Execution_state __NVIC_Disable_Pending_Flag_Interrupt_Peripheral__(u8 Interrupt); //prototype of the function that disables pending flag of interrupts

Execution_state __NVIC_Read_Active_Flag_Interrupt_Peripheral__(u8 Interrupt,u8 *Active_State);  //prototype of the function that reads active flag of interrupts



//check the selected priority field
#if NVIC_Priority_Field_Configuration == NVIC_8_Group_1_Sub      //check if the selected priority field is 16 Group and none subs
	Execution_state __NVIC_Set_Priority__(u8 IRQ,u8 Group);                    //if that, then the user will use this function that sets the priority field of interrupts

#elif NVIC_Priority_Field_Configuration == NVIC_1_Group_8_Sub    //check if the selected priority field is 0 Group and 16 subs
	Execution_state __NVIC_Set_Priority__(u8 IRQ,u8 Sub);                      //if that, then the user will use this function that sets the priority field of interrupts

#else   //else
	Execution_state __NVIC_Set_Priority__(u8 IRQ,u8 Group,u8 Sub);             //if that, then the user will use this function that sets the priority field of interrupts

#endif





#endif /* NVIC_H_ */
