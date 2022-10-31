/**
  ******************************************************************************
  * @file    NVIC.c
  * @author  mohamed mohamed taha
  * @Target  TivaC TM4C123GH6PM
  * @version V1
  * @date    20-Aug-2022
  * @brief   This source file contains the implementation of NVIC functions .
  ******************************************************************************/


#include "Macros.h"
#include "Stdlib.h"
#include "NVIC.h"
#include "NVIC_private.h"
#include "NVIC_config.h"



NVIC_IPR_Configuration 	Register_Configuration;   //create a object form union to configure the groups and subs


//function to initialize NVIC priority field
void __NVIC_Initialize_Priority_Field__(void) {

#if NVIC_Priority_Field_Configuration == NVIC_8_Group_1_Sub    //check if the selected priority field is 8 Group and 1 subs
	SCB_AIRCR = 0x05FA0400;     //if that, assign this value to AIRCR register

#elif NVIC_Priority_Field_Configuration == NVIC_4_Group_2_Sub   //check if the selected priority field is 4 Group and 2 subs
	SCB_AIRCR = 0x05FA0500;     //if that, assign this value to AIRCR register

#elif NVIC_Priority_Field_Configuration == NVIC_2_Group_4_Sub   //check if the selected priority field is 2 Group and 4 subs
	SCB_AIRCR = 0x05FA0600;     //if that, assign this value to AIRCR register

#elif NVIC_Priority_Field_Configuration == NVIC_1_Group_8_Sub  //check if the selected priority field is 1 Group and 8 subs
	SCB_AIRCR = 0x05FA0700;     //if that, assign this value to AIRCR register

#endif

}  //the end of the function


//function to enable the interrupts
Execution_state __NVIC_Enable_Interrupt_Peripheral__(u8 Interrupt) {

	Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state
	u8 Index,Bit_Location;                             //declare Index to hold the index of the interrupt register,
	                                                   //declare Bit_Location to hold the interrupt location in the register

	if(Interrupt <= NVIC_No_Interrupts) {         //check if the interrupt in the range

	    Index = Interrupt / NVIC_Register_Bits;            //calculate the index of the interrupt
	    Bit_Location = Interrupt % NVIC_Register_Bits;     //calculate the interrupt location
		NVIC->EN[Index] = (1 << Bit_Location);   //enable the selected interrupt

	}  //the end of the if statement

	else {      //else

		Error_State = Execution_Error;   //update the error state

	}  //the end of the else scope

	return Error_State;    //return the error state

}  //the end of the function



//function to disable the interrupts
Execution_state __NVIC_Disable_Interrupt_Peripheral__(u8 Interrupt) {

    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state
    u8 Index,Bit_Location;                             //declare Index to hold the index of the interrupt register,
                                                       //declare Bit_Location to hold the interrupt location in the register

    if(Interrupt <= NVIC_No_Interrupts) {         //check if the interrupt in the range

        Index = Interrupt / NVIC_Register_Bits;            //calculate the index of the interrupt
        Bit_Location = Interrupt % NVIC_Register_Bits;     //calculate the interrupt location
        NVIC->DIS[Index] = (1 << Bit_Location);   //disable the selected interrupt

    }  //the end of the if statement

    else {      //else

        Error_State = Execution_Error;   //update the error state

    }  //the end of the else scope

    return Error_State;    //return the error state

}  //the end of the function


//function to enable the interrupt's pending flag
Execution_state __NVIC_Enable_Pending_Flag_Interrupt_Peripheral__(u8 Interrupt) {

    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state
    u8 Index,Bit_Location;                             //declare Index to hold the index of the interrupt register,
                                                       //declare Bit_Location to hold the interrupt location in the register

    if(Interrupt <= NVIC_No_Interrupts) {         //check if the interrupt in the range

        Index = Interrupt / NVIC_Register_Bits;            //calculate the index of the interrupt
        Bit_Location = Interrupt % NVIC_Register_Bits;     //calculate the interrupt location
        NVIC->PEND[Index] = (1 << Bit_Location);   //enable the selected interrupt's pending flag

    }  //the end of the if statement

    else {      //else

        Error_State = Execution_Error;   //update the error state

    }  //the end of the else scope

    return Error_State;    //return the error state

}  //the end of the function




//function to disable the interrupt's pending flag
Execution_state __NVIC_Disable_Pending_Flag_Interrupt_Peripheral__(u8 Interrupt) {

    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state
    u8 Index,Bit_Location;                             //declare Index to hold the index of the interrupt register,
                                                       //declare Bit_Location to hold the interrupt location in the register

    if(Interrupt <= NVIC_No_Interrupts) {         //check if the interrupt in the range

        Index = Interrupt / NVIC_Register_Bits;            //calculate the index of the interrupt
        Bit_Location = Interrupt % NVIC_Register_Bits;     //calculate the interrupt location
        NVIC->UNPEND[Index] = (1 << Bit_Location);   //disable the selected interrupt's pending flag

    }  //the end of the if statement

    else {      //else

        Error_State = Execution_Error;   //update the error state

    }  //the end of the else scope

    return Error_State;    //return the error state

} //the end of the function



//function to read the active flag of the selected interrupt
Execution_state __NVIC_Read_Active_Flag_Interrupt_Peripheral__(u8 Interrupt,u8 *Active_State) {

    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state
    u8 Index,Bit_Location;                             //declare Index to hold the index of the interrupt register,
                                                       //declare Bit_Location to hold the interrupt location in the register

    if(Interrupt <= NVIC_No_Interrupts) {         //check if the interrupt in the range

        Index = Interrupt / NVIC_Register_Bits;            //calculate the index of the interrupt
        Bit_Location = Interrupt % NVIC_Register_Bits;     //calculate the interrupt location
        *Active_State = Get_Bit(NVIC->ACTIVE[Index],Bit_Location);  //read the value of interrup's active flag

    }  //the end of the if statement

    else {      //else

        Error_State = Execution_Error;   //update the error state

    }  //the end of the else scope

    return Error_State;    //return the error state

} //the end of the function



//check the selected priority field
#if NVIC_Priority_Field_Configuration == NVIC_8_Group_1_Sub      //check if the selected priority field is 8 Group and 1 subs

	Execution_state __NVIC_Set_Priority__(u8 IRQ,u8 Group)   //if that, then the user will use this function that sets the priority field of interrupts
	{
		Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state

		if((Group <= NVIC_Max_Groups) && (IRQ <= NVIC_No_Interrupts)) //check if the group and IRQ in range
		{
			Register.NVIC_8_Group_1_Sub_Access.Group = Group;     //assign the group value
			NVIC.PRI[IRQ] = Register_Configuration.IPR_Register;   //update the group value to IPR
		}   //the end of the if statement

		else {      //else

			Error_State = Execution_Error;   //update the error state

		} //end of the else scope

		return Error_State;    //return the error state

	}  //the end of the function

#elif NVIC_Priority_Field_Configuration == NVIC_1_Group_8_Sub    //check if the selected priority field is 1 Group and 8 subs

	Execution_state __NVIC_Set_Priority__(u8 IRQ,u8 Sub)                    //if that, then the user will use this function that sets the priority field of interrupts
	{
		Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state

		if((Sub <= NVIC_Max_Subs) && (IRQ <= NVIC_No_Interrupts))   //check if the group and IRQ in range
		{
			Register.NVIC_1_Group_8_Sub_Access.Sub = Sub;          //assign the sub value
			NVIC.PRI[IRQ] = Register_Configuration.IPR_Register;     //update the sub value to IPR
		}   //the end of the if statement

		else {      //else

			Error_State = Execution_Error;   //update the error state

		}  //the end of the else scope

		return Error_State;    //return the error state

	}  //the end of the function

#else   //else

	Execution_state __NVIC_Set_Priority__(u8 IRQ,u8 Group,u8 Sub)             //if that, then the user will use this function that sets the priority field of interrupts
	{
		Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state


	#if NVIC_Priority_Field_Configuration == NVIC_4_Group_2_Sub    //check if the selected priority field is 4 Group and 2 subs

		if((Sub <= NVIC_Sub_One) && (Group <= NVIC_Group_Three) && (IRQ <= NVIC_No_Interrupts))   //check if the all of parameters is in range
		{
			Register_Configuration.NVIC_4_Group_2_Sub_Access.Group = Group;    //assign the group value
			Register_Configuration.NVIC_4_Group_2_Sub_Access.Sub = Sub;        //assign the sub value
			NVIC->PRI[IRQ] = Register_Configuration.IPR_Register;              //update the sub and group value to IPR
		}  //the end of the if statement


	#elif NVIC_Priority_Field_Configuration == NVIC_2_Group_4_Sub     //check if the selected priority field is 2 Group and 4 subs

		if((Sub <= NVIC_Sub_Three) && (Group <= NVIC_Group_One) && (IRQ <= NVIC_No_Interrupts))   //check if the all of parameters is in range
		{
			Register_Configuration.NVIC_2_Group_4_Sub_Access.Group = Group;  //assign the group value
			Register_Configuration.NVIC_2_Group_4_Sub_Access.Sub = Sub;      //assign the sub value
			NVIC->PRI[IRQ] = Register_Configuration.IPR_Register;            //update the sub and group value to IPR
		}  //the end of the if statement

	#endif

		else {      //else

			Error_State = Execution_Error;   //update the error state

		}   //the end of the else scope

		return Error_State;    //return the error state

	}  //the end of the function

#endif
















