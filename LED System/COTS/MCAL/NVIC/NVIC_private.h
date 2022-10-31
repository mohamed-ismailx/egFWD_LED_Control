/**
  ******************************************************************************
  * @file    NVIC_Private.h
  * @author  mohamed mohamed taha
  * @Target  TivaC TM4C123GH6PM
  * @version V1
  * @date    20-Aug-2022
  * @brief   This header file contains the registers of NVIC.
  ******************************************************************************/


/*Header file guard*/
#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_



//declare a structure to declare NVIC registers
typedef struct {

	volatile u32 EN[5];         //declare the interrupt set enable registers
	volatile u32 ReservedA[27];   //reserved locations
	volatile u32 DIS[5];         //declare the interrupt clear enable registers
	volatile u32 ReservedB[27];   //reserved locations
	volatile u32 PEND[5];         //declare the interrupt set pending registers
	volatile u32 ReservedC[27];   //reserved locations
	volatile u32 UNPEND[5];         //declare the interrupt clear pending registers
	volatile u32 ReservedD[27];   //reserved locations
	volatile u32 ACTIVE[5];         //declare the interrupt active bit registers
	volatile u32 ReservedE[59];   //reserved locations
	volatile u8  PRI[136];        //declare the interrupt priority registers

}NVIC_Registers;   //the end of the structure


#define NVIC_Base_Address  0xE000E100            //define the base address of NVIC
#define NVIC               ((NVIC_Registers*)NVIC_Base_Address)

#define SCB_AIRCR           *((volatile u32*)(0xE000ED0C))  //define the address of (SCB_AIRCR) register




#endif /* NVIC_PRIVATE_H_ */
