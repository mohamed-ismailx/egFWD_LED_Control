/**
  ******************************************************************************
  * @file    Macros.h
  * @author  mohamed mohamed taha
  * @Target  TivaC TM4C123GH6PM
  * @version V1
  * @date    20-Aug-2022
  * @brief   Macros to access register bits.
  ******************************************************************************/

#ifndef MACROS_H_
#define MACROS_H_


#define Clear(Register,Bit) Register&=~(1<<Bit)            //define a macro to clear bit
#define Set(Register,Bit) Register|=(1<<Bit)               //define a macro to set bit
#define Tog(Register,Bit) Register^=(1<<Bit)               //define a macro to toggle bit
#define Get_Bit(Register,Bit) !!(Register & (1<<Bit))      //define a macro to read bit
#define Write_Bit (Variable,Value) Variable=Value          //define a macro to write bit
#define Read(Register) Register                            //define a macro to read register


#define IS_PIN_SET(Register,Pin)  (Register & (1<<Pin)))           //define a macro to check if the bit is set
#define IS_PIN_CLR(Register,Pin)  (!(Register & (1<<Pin)))         //define a macro to check if the bit is clear


#endif /* MACROS_H_ */
