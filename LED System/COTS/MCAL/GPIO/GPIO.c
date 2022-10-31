/**
  ******************************************************************************
  * @file    GPIO.c
  * @author  mohamed mohamed taha
  * @Target  TivaC TM4C123GH6PM
  * @version V1
  * @date    21-Aug-2022
  * @brief   This source file contains the implementation of GPIO functions .
  ******************************************************************************/

#include "Stdlib.h"
#include "GPIO_Private.h"
#include "GPIO.h"


//Array Of Pointers To Structure To Access GPIO Registers By Base Address Of GPIOA,GPIOB,GPIOC,GPIOD,GPIOE And GPIOF
static GPIO_Registers *GPIOx[No_Ports] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF};

Execution_state __GPIO_Set_Pin_Direction__(const GPIO_Pin_Configuration *Data)   //Definition Of Function That Configuration The Pin Direction
{

    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state

    if(Data != NULL)  //Check If The Content Of Structure Is Not Empty And It Hold The Address
    {

        switch (Data->Pin)   //Switching The Value Of Pin That In Structure
        {
            case Pin_Zero:   //case pin is zero

                if((Data->Direction == Input_Pull_Down) || (Data->Direction == Input_Pull_Up)) {   //check if the direction is input pull up or pull down

                    GPIOx[Data->Port]->GPIOLOCK = Lock;                 //unlock commit register
                    GPIOx[Data->Port]->GPIOCR.Register_Access = Enable; //enable GPIOPUR, GPIOPDR and GPIODEN

                    if((Data->Direction == Input_Pull_Up)){       //check if the direction is input pull up

                        GPIOx[Data->Port]->GPIOPUR.Bit_Access.Bit_Zero = Enable;  //set pin zero to be pull up
                    }  //end of the if statement

                    else {  //else

                        GPIOx[Data->Port]->GPIOPDR.Bit_Access.Bit_Zero = Enable;  //set pin zero to be pull down
                    }  //end of the else scope

                }  //end of the if statement

                else if(Data->Direction == Open_Drain) {
                    GPIOx[Data->Port]->GPIOODR.Bit_Access.Bit_Zero = Enable; //set pin to work as open drain

                } //the end of the else if scope


                GPIOx[Data->Port]->GPIODRxR[Data->Current].Bit_Access.Bit_Zero = Enable;  //set current of the pin
                GPIOx[Data->Port]->GPIODIR.Bit_Access.Bit_Zero = Data->Direction;  //set pin zero direction
                GPIOx[Data->Port]->GPIODEN.Bit_Access.Bit_Zero = Enable;  //set pin zero to be a digital pin


                break;  //the end of the case

            case Pin_One:    //case pin is one

                 if((Data->Direction == Input_Pull_Down) || (Data->Direction == Input_Pull_Up)) {  //check if the direction is input pull up or pull down

                     GPIOx[Data->Port]->GPIOLOCK = Lock;                      //unlock commit register
                     GPIOx[Data->Port]->GPIOCR.Register_Access = Enable;      //enable GPIOPUR, GPIOPDR and GPIODEN

                     if((Data->Direction == Input_Pull_Up)){      //check if the direction is input pull up

                         GPIOx[Data->Port]->GPIOPUR.Bit_Access.Bit_One = Enable;  //set pin one to be pull up
                     } //end of the if statement

                     else {  //else
                         GPIOx[Data->Port]->GPIOPDR.Bit_Access.Bit_One = Enable;  //set pin one to be pull down

                     } //end of the else scope

                 }  //end of the if statement

                 else if(Data->Direction == Open_Drain) {
                     GPIOx[Data->Port]->GPIOODR.Bit_Access.Bit_One = Enable; //set pin to work as open drain

                 } //the end of the else if scope


                 GPIOx[Data->Port]->GPIODRxR[Data->Current].Bit_Access.Bit_One = Enable;  //set current of the pin
                 GPIOx[Data->Port]->GPIODIR.Bit_Access.Bit_One = Data->Direction;  //set pin one direction
                 GPIOx[Data->Port]->GPIODEN.Bit_Access.Bit_One = Enable;  //set pin one to be digital pin


                break; //the end of the case

            case Pin_Two:    //case pin is two

                 if((Data->Direction == Input_Pull_Down) || (Data->Direction == Input_Pull_Up)) {     //check if the direction is input pull up or pull down

                     GPIOx[Data->Port]->GPIOLOCK = Lock;                   //unlock commit register
                     GPIOx[Data->Port]->GPIOCR.Register_Access = Enable;   //enable GPIOPUR, GPIOPDR and GPIODEN

                     if((Data->Direction == Input_Pull_Up)){          //check if the direction is input pull up

                         GPIOx[Data->Port]->GPIOPUR.Bit_Access.Bit_Two = Enable; //set pin two to be pull up
                     }  //end of the if statement

                     else {  //else
                         GPIOx[Data->Port]->GPIOPDR.Bit_Access.Bit_Two = Enable;   //set pin two to be pull down

                     }  //end of the else scope

                 }  //end of the if statement

                 else if(Data->Direction == Open_Drain) {
                     GPIOx[Data->Port]->GPIOODR.Bit_Access.Bit_Two = Enable; //set pin to work as open drain

                 } //the end of the else if scope


                 GPIOx[Data->Port]->GPIODRxR[Data->Current].Bit_Access.Bit_Two = Enable;  //set current of the pin
                 GPIOx[Data->Port]->GPIODIR.Bit_Access.Bit_Two = Data->Direction;  //set pin two direction
                 GPIOx[Data->Port]->GPIODEN.Bit_Access.Bit_Two = Enable;  //set pin two to be digital pin

                 break; //the end of the case

            case Pin_Three:    //case pin is three

                 if((Data->Direction == Input_Pull_Down) || (Data->Direction == Input_Pull_Up)) {   //check if the direction is input pull up or pull down

                     GPIOx[Data->Port]->GPIOLOCK = Lock;                  //unlock commit register
                     GPIOx[Data->Port]->GPIOCR.Register_Access = Enable;  //enable GPIOPUR, GPIOPDR and GPIODEN

                     if((Data->Direction == Input_Pull_Up)){          //check if the direction is input pull up

                         GPIOx[Data->Port]->GPIOPUR.Bit_Access.Bit_Three = Enable;   //set pin three to be pull up
                     }  //end of the if statement

                     else { //else
                         GPIOx[Data->Port]->GPIOPDR.Bit_Access.Bit_Three = Enable; //set pin three to be pull down

                     }  //end of the else scope

                 }  //end of the if statement

                 else if(Data->Direction == Open_Drain) {
                     GPIOx[Data->Port]->GPIOODR.Bit_Access.Bit_Three = Enable; //set pin to work as open drain

                 } //the end of the else if scope


                 GPIOx[Data->Port]->GPIODRxR[Data->Current].Bit_Access.Bit_Three = Enable;  //set current of the pin
                 GPIOx[Data->Port]->GPIODIR.Bit_Access.Bit_Three = Data->Direction;  //set pin three direction
                 GPIOx[Data->Port]->GPIODEN.Bit_Access.Bit_Three = Enable;  //set pin three to be digital pin

                 break; //the end of the case

            case Pin_Four:    //case pin is four

                 if((Data->Direction == Input_Pull_Down) || (Data->Direction == Input_Pull_Up)) {  //check if the direction is input pull up or pull down

                     GPIOx[Data->Port]->GPIOLOCK = Lock;                 //unlock commit register
                     GPIOx[Data->Port]->GPIOCR.Register_Access = Enable; //enable GPIOPUR, GPIOPDR and GPIODEN

                     if((Data->Direction == Input_Pull_Up)){           //check if the direction is input pull up

                         GPIOx[Data->Port]->GPIOPUR.Bit_Access.Bit_Four = Enable;  //set pin four to be pull up
                     }  //end of the if statement

                     else { //else
                         GPIOx[Data->Port]->GPIOPDR.Bit_Access.Bit_Four = Enable;  //set pin four to be pull down

                     }  //end of the else scope

                 }  //end of the if statement

                 else if(Data->Direction == Open_Drain) {
                     GPIOx[Data->Port]->GPIOODR.Bit_Access.Bit_Four = Enable; //set pin to work as open drain

                 } //the end of the else if scope


                 GPIOx[Data->Port]->GPIODRxR[Data->Current].Bit_Access.Bit_Four = Enable;  //set current of the pin
                 GPIOx[Data->Port]->GPIODIR.Bit_Access.Bit_Four = Data->Direction;  //set pin four direction
                 GPIOx[Data->Port]->GPIODEN.Bit_Access.Bit_Four = Enable;  //set pin four to be digital pin

                 break; //the end of the case

            case Pin_Five:   //case pin is Five

                 if((Data->Direction == Input_Pull_Down) || (Data->Direction == Input_Pull_Up)) {  //check if the direction is input pull up or pull down

                     GPIOx[Data->Port]->GPIOLOCK = Lock;                 //unlock commit register
                     GPIOx[Data->Port]->GPIOCR.Register_Access = Enable; //enable GPIOPUR, GPIOPDR and GPIODEN

                     if((Data->Direction == Input_Pull_Up)){            //check if the direction is input pull up

                         GPIOx[Data->Port]->GPIOPUR.Bit_Access.Bit_Five = Enable;   //set pin five to be pull up
                     }  //end of the if statement

                     else {  //else
                         GPIOx[Data->Port]->GPIOPDR.Bit_Access.Bit_Five = Enable;  //set pin five to be pull down

                     }  //end of the else scope

                 }  //end of the if statement

                 else if(Data->Direction == Open_Drain) {
                     GPIOx[Data->Port]->GPIOODR.Bit_Access.Bit_Five = Enable; //set pin to work as open drain

                 } //the end of the else if scope


                 GPIOx[Data->Port]->GPIODRxR[Data->Current].Bit_Access.Bit_Five = Enable;  //set current of the pin
                 GPIOx[Data->Port]->GPIODIR.Bit_Access.Bit_Five = Data->Direction;  //set pin five direction
                 GPIOx[Data->Port]->GPIODEN.Bit_Access.Bit_Five = Enable;  //set pin five to be digital pin

                 break; //the end of the case

            case Pin_Six:   //case pin is Six

                 if((Data->Direction == Input_Pull_Down) || (Data->Direction == Input_Pull_Up)) {  //check if the direction is input pull up or pull down

                     GPIOx[Data->Port]->GPIOLOCK = Lock;                  //unlock commit register
                     GPIOx[Data->Port]->GPIOCR.Register_Access = Enable;  //enable GPIOPUR, GPIOPDR and GPIODEN

                     if((Data->Direction == Input_Pull_Up)){               //check if the direction is input pull up

                         GPIOx[Data->Port]->GPIOPUR.Bit_Access.Bit_Six = Enable;   //set pin six to be pull up
                     }  //end of the if statement

                     else {   //else
                         GPIOx[Data->Port]->GPIOPDR.Bit_Access.Bit_Six = Enable;   //set pin six to be pull down

                     }  //end of the else scope

                 }  //end of the if statement

                 else if(Data->Direction == Open_Drain) {
                     GPIOx[Data->Port]->GPIOODR.Bit_Access.Bit_Six = Enable; //set pin to work as open drain

                 } //the end of the else if scope


                 GPIOx[Data->Port]->GPIODRxR[Data->Current].Bit_Access.Bit_Six = Enable;  //set current of the pin
                 GPIOx[Data->Port]->GPIODIR.Bit_Access.Bit_Six = Data->Direction;  //set pin six direction
                 GPIOx[Data->Port]->GPIODEN.Bit_Access.Bit_Six = Enable;  //set pin six to be digital pin

                 break; //the end of the case

            case Pin_Seven:   //case pin is Seven

                 if((Data->Direction == Input_Pull_Down) || (Data->Direction == Input_Pull_Up)) {  //check if the direction is input pull up or pull down

                     GPIOx[Data->Port]->GPIOLOCK = Lock;                  //unlock commit register
                     GPIOx[Data->Port]->GPIOCR.Register_Access = Enable;  //enable GPIOPUR, GPIOPDR and GPIODEN

                     if((Data->Direction == Input_Pull_Up)){             //check if the direction is input pull up

                         GPIOx[Data->Port]->GPIOPUR.Bit_Access.Bit_Seven = Enable;   //set pin seven to be pull up
                     }  //end of the if statement

                     else {   //else
                         GPIOx[Data->Port]->GPIOPDR.Bit_Access.Bit_Seven = Enable;  //set pin seven to be pull down

                     }  //end of the else scope

                 } //end of the if statement

                 else if(Data->Direction == Open_Drain) {
                     GPIOx[Data->Port]->GPIOODR.Bit_Access.Bit_Seven = Enable; //set pin to work as open drain

                 } //the end of the else if scope


                 GPIOx[Data->Port]->GPIODRxR[Data->Current].Bit_Access.Bit_Seven = Enable;  //set current of the pin
                 GPIOx[Data->Port]->GPIODIR.Bit_Access.Bit_Seven = Data->Direction;  //set pin seven direction
                 GPIOx[Data->Port]->GPIODEN.Bit_Access.Bit_Seven = Enable;  //set pin seven to be digital pin

                 break; //the end of the case

            default:  //Default the pin value is error
                Error_State = Execution_Error;   //Update The Error State To The Variable
                break;  //the end of the default case
        } //the end of the switch

    } //the end of the if statement

    else    //else the structure is empty address
        Error_State = Execution_Error;    //Update the error state to the variable


    return Error_State;    //Return the error state
}   //the end of the function


Execution_state __GPIO_Set_Pin__(const GPIO_Pin_Configuration *Data)  //Definition Of Function That Configuration The Pin Output (HIGH)
{

    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state

    if(Data != NULL)        //Check If The Content Of Structure Is Not Empty And It Hold The Address
    {

        switch (Data->Pin)    //Switching The Value Of Pin That In Structure
        {
            case Pin_Zero:   //case pin is zero
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Zero = High;   //set pin zero
                break;  //the end of the case

            case Pin_One:   //case pin is one
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_One = High;   //set pin one
                break; //the end of the case

            case Pin_Two:   //case pin is two
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Two = High;   //set pin two
                break;   //the end of the case

            case Pin_Three:   //case pin is three
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Three = High;   //set pin three
                break;   //the end of the case

            case Pin_Four:    //case pin is four
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Four = High;   //set pin four
                break;    //the end of the case

            case Pin_Five:    //case pin is five
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Five = High;   //set pin five
                break;   //the end of the case

            case Pin_Six:  //case pin is six
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Six = High;   //set pin six
                break;     //the end of the case

            case Pin_Seven:   //case pin is seven
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Seven = High;   //set pin seven
                break;  //the end of the case

            default:     //default case
                Error_State = Execution_Error;   //Update The Error State To The Variable
                break;   //the end of the default case
        }   //the end of the switch

    }   //the end of the if statement

    else  //Else The Structure Is Empty Address
        Error_State = Execution_Error;   //Update The Error State To The Variable


    return Error_State;    //return error state
} //the end of the function


Execution_state __GPIO_Clear_Pin__(const GPIO_Pin_Configuration *Data)  //Definition Of Function That Configuration The Pin Output (LOW)
{

    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state

    if(Data != NULL)   //Check If The Content Of Structure Is Not Empty And It Hold The Address
    {

        switch (Data->Pin)   //Switching The Value Of Pin That In Structure
        {
            case Pin_Zero:   //case pin is zero
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Zero = Low;   //set pin zero
                break;   //the end of the case

            case Pin_One:    //case pin is one
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_One = Low;   //set pin one
                break;   //the end of the case

            case Pin_Two:   //case pin is two
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Two = Low;   //set pin two
                break;   //the end of the case

            case Pin_Three:   //case pin is three
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Three = Low;   //set pin three
                break;   //the end of the case

            case Pin_Four:   //case pin is four
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Four = Low;   //set pin four
                break;   //the end of the case

            case Pin_Five:  //case pin is five
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Five = Low;   //set pin five
                break;  //the end of the case

            case Pin_Six:   //case pin is six
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Six = Low;   //set pin six
                break;   //the end of the case

            case Pin_Seven:   //case pin is seven
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Seven = Low;   //set pin seven
                break;  //the end of the case

            default:    //default case
                Error_State = Execution_Error;   //Update The Error State To The Variable
                break; //the end of the default case
        }  //the end of the switch

    } //the end of the if statement

    else   //Else The Structure Is Empty Address
        Error_State = Execution_Error;    //Update The Error State To The Variable


    return Error_State;    //return error state

}  //the end of the function


u8 __GPIO_Read_Pin__(const GPIO_Pin_Configuration *Data)  //Definition Of Function That read The Pin value
{

    u8 Error_State = Execution_Correct;    //Variable To Check Error In The Function
    u8 Read_Pin;                           //Variable To read the pin value

    if(Data != NULL)    //Check If The Content Of Structure Is Not Empty And It Hold The Address
    {

        switch (Data->Pin)    //Switching The Value Of Pin That In Structure
        {
            case Pin_Zero:  //case pin zero
                Read_Pin = GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Zero;    //read pin zero
                break;  //the end of the case

            case Pin_One: //case pin one
                Read_Pin = GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_One;    //read pin one
                break; //the end of the case

            case Pin_Two:  //case pin two
                Read_Pin = GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Two;    //read pin two
                break; //the end of the case

            case Pin_Three: //case pin three
                Read_Pin = GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Three;    //read pin three
                break;  //the end of the case

            case Pin_Four:  //case pin four
                Read_Pin = GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Four;    //read pin four
                break;  //the end of the case

            case Pin_Five:  //case pin five
                Read_Pin = GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Five;    //read pin five
                break;  //the end of the case

            case Pin_Six:   //case pin six
                Read_Pin = GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Six;    //read pin six
                break;   //the end of the case

            case Pin_Seven:  //case pin seven
                Read_Pin = GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Seven;    //read pin seven
                break;  //the end of the case

            default:   //default case
                Error_State = Execution_Error;
                break;  //the end of the default case
        }  //the end of the switch

    } //the end of the if statement

    else    //Else The Structure Is Empty Address
        Error_State = Execution_Error;  //Update The Error State To The Variable


    return Error_State == Execution_Error? Error_State: Read_Pin;   //return the value of pin if there is no error

}  //the end of the function


Execution_state __GPIO_Toggle_Pin__(const GPIO_Pin_Configuration *Data) //Definition Of Function That toggle The Pin value
{

    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state

    if(Data != NULL)    //Check If The Content Of Structure Is Not Empty And It Hold The Address
    {

        switch (Data->Pin)     //Switching The Value Of Pin That In Structure
        {
            case Pin_Zero:   //case pin zero
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Zero ^= High;         //toggle pin zero
                break;  //the end of the case

            case Pin_One: //case pin one
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_One ^= High; //toggle pin one

                break;  //the end of the case

            case Pin_Two:  //case pin two
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Two ^= High;    //toggle pin two
                break;  //the end of the case

            case Pin_Three:  //case pin three
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Three ^= High; //toggle pin three
               break;  //the end of the case

            case Pin_Four:  //case pin four
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Four ^= High;   //toggle pin four
                break;   //the end of the case

            case Pin_Five: //case pin five
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Five ^= High; //toggle pin five
                break; //the end of the case

            case Pin_Six:  //case pin six
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Six ^= High;  //toggle pin six
                break; //the end of the case

            case Pin_Seven:  //case pin seven
                GPIOx[Data->Port]->GPIODATA.Bit_Access.Bit_Seven ^= High;   //toggle pin seven
                break;  //the end of the case

            default:   //default case
                Error_State = Execution_Error;   //Update The Error State To The Variable
                break;  //the end of the default case
        } //the end of the switch

    }  //the end of the if statement

    else    //Else The Structure Is Empty Address
        Error_State = Execution_Error;    //Update The Error State To The Variable


    return Error_State;   //return error state

}  //the end of the function





Execution_state __GPIO_Set_Port_Direction__(GPIO_Port_Configuration *Data) //Definition Of Function That Configuration The Port Direction
{

    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state

    if(Data != NULL)   //Check If The Content Of Structure Is Not Empty And It Hold The Address
    {
        if((Data->Direction == Input_Pull_Down) || (Data->Direction == Input_Pull_Up)) {   //check if the direction is input pull up or pull down

            GPIOx[Data->Port]->GPIOLOCK = Lock;                  //unlock commit register
            GPIOx[Data->Port]->GPIOCR.Register_Access = Enable;  //enable GPIOPUR, GPIOPDR and GPIODEN

            if((Data->Direction == Input_Pull_Up)){            //check if the direction is input pull up

                GPIOx[Data->Port]->GPIOPUR.Register_Access = ~(Data->Port_Value);     //set the selected pins to be input pull up
            } //end of the if statement

            else {  //else

                GPIOx[Data->Port]->GPIOPDR.Register_Access = ~(Data->Port_Value);    //set the selected pins to be input pull down
            }  //end of the else statement
        } //end of the if statement


        else if(Data->Direction == Open_Drain) {
            GPIOx[Data->Port]->GPIOODR.Register_Access = 0xFF; //set pin to work as open drain

        } //the end of the else if scope


        GPIOx[Data->Port]->GPIODRxR[Data->Current].Register_Access = 0xFF;  //set current of the port
        GPIOx[Data->Port]->GPIODIR.Register_Access = Data->Port_Value;  //set port direction
        GPIOx[Data->Port]->GPIODEN.Register_Access = 0xFF;  //set all of port's pins to be digital pins


    }  //the end of the if statement

    else   //Else The Structure Is Empty Address
        Error_State = Execution_Error;   //Update The Error State To The Variable


    return Error_State;   //return error state
}  //the end of the function

Execution_state __GPIO_Write_Port__(GPIO_Port_Configuration *Data)  //Definition Of Function That write The port value
{

    Execution_state Error_State = Execution_Correct;   //define a variable to hold the error state
    u8 Value;    //Variable To Check Error In The Function

    if(Data != NULL)   //Check If The Content Of Structure Is Not Empty And It Hold The Address
    {
        Value = GPIOx[Data->Port]->GPIODIR.Register_Access | GPIOx[Data->Port]->GPIODATA.Register_Access;  //get the value of input and output pins
        GPIOx[Data->Port]->GPIODATA.Register_Access = Data->Port_Value & Value;   //assign the value to the port.

    //       0x00 | 0x0f    =  0x0f
    //  x = GPIODATA | GPIODIR
    //       0xff & 0x0f
    //  GPIODATA = port value & x

    }  //end if

    else   //Else The Structure Is Empty Address
        Error_State = Execution_Error;   //Update The Error State To The Variable


    return Error_State;   //return error state
}


u8 __GPIO_Read_Port__(GPIO_Port_Configuration *Data)   //Definition Of Function That read The port value
{

    u8 Error_State = Execution_Correct;    //Define a variable To Check Error In The Function
    u8 Read_Port;                          //Define a variable To read port

    if(Data != NULL)    //Check If The Content Of Structure Is Not Empty And It Hold The Address
        Read_Port = GPIOx[Data->Port]->GPIODATA.Register_Access;    //read the value of the port


    else     //Else The Structure Is Empty Address
        Error_State = Execution_Error;    //Update The Error State To The Variable


    return Error_State == Execution_Error? Error_State: Read_Port;   //return read port if there is no error
}  //the end of the function

