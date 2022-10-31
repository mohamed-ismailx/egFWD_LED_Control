/**
  ******************************************************************************
  * @file    System_Control_Private.h
  * @author  mohamed mohamed taha
  * @Target  TivaC TM4C123GH6PM
  * @version V1
  * @date    21-Aug-2022
  * @brief   This header file contains the registers of System Control.
  ******************************************************************************/


/*Header file guard*/
#ifndef SYSTEM_CONTROL_PRIVATE_H_
#define SYSTEM_CONTROL_PRIVATE_H_




/* Declare a structure to declare the register's bits */
typedef struct
{
    u32 R0     : 1;              //Declare a variable with 1bit size
    u32 R1     : 1;              //Declare a variable with 1bit size
    u32 R2     : 1;              //Declare a variable with 1bit size
    u32 R3     : 1;              //Declare a variable with 1bit size
    u32 R4     : 1;              //Declare a variable with 1bit size
    u32 R5     : 1;              //Declare a variable with 1bit size
    u32        : 26;             //Reserved

}SYSCTL_Bits;  //end of the structure


/* Declare a union to access the register or its bits */
typedef union
{
    u32 Register_Access;         //Declare a variable with the size of the register
    SYSCTL_Bits Bit_Access;       //Declare a variable from type SYSCTL_Bits

}SYSCTL_Access;  //the end of the union




/* Declare a structure to access SYSCTL registers */
typedef struct {

    volatile SYSCTL_Access RCGCTIMER;    /* Declare the RCGCTIMER register */
    volatile SYSCTL_Access RCGCGPIO;     /* Declare the RCGCGPIO register */

}SYSCTL_Registers;   //the end of the structure


#define SYSCTL ((SYSCTL_Registers*)0x400FE604)




#endif /* SYSTEM_CONTROL_PRIVATE_H_ */
