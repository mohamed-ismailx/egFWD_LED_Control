/**
  ******************************************************************************
  * @file    Stdlib.h
  * @author  mohamed mohamed taha
  * @Target  TivaC TM4C123GH6PM
  * @version V1
  * @date    20-Aug-2022
  * @brief   This header file contains C created data types.
  ******************************************************************************/


/*Header file guard*/
#ifndef _MATH_H_
#define _MATH_H_

/*Integer 8bits data type*/
typedef unsigned char       u8;
typedef signed char         s8;

/*Integer 16bits data type*/
typedef unsigned short int u16;
typedef signed short int   s16;

/*Integer 32bits data type*/
typedef unsigned long int  u32;
typedef signed long int    s32;

/*Float 32bits data type*/
typedef float              f32;

/*Float 64bits data type*/
typedef double             f64;


//Error Execution


//declare an enum to define the error states
typedef enum {

    Execution_Error,           //define the execution error state
    Execution_Correct          //define the execution correct state

}Execution_state; //end of the enum


#define Enable   1     //define the enable status
#define Disable  0     //define the disable status

#define Null 0                  //define null value
#define NULL ((void*)0)         //define NULL pointer
#define True 1                  //define True value

#endif/*_LSTDTYPES_H_*/

