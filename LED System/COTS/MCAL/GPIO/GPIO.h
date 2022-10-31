/**
  ******************************************************************************
  * @file    GPIO.h
  * @author  mohamed mohamed taha
  * @Target  TivaC TM4C123GH6PM
  * @version V1
  * @date    21-Aug-2022
  * @brief   This header file contains the prototypes of GPIO functions and others.
  ******************************************************************************/

/*Header file guard*/
#ifndef GPIO_H_
#define GPIO_H_



#define No_Ports 6      //define the number of ports

#define Lock    0x4C4F434B

/* Declare an enum to configure the modes of the GPIO */
typedef enum
{
    Input_Pull_Up = 0b0010,       //configuration of input pull up mode
    Input_Pull_Down = 0b0100,      //configuration of input pull Down mode
    Input_Floating = 0b1000,      //configuration of input floating mode
    Output = 0b0001,             //configuration of output mode
    Open_Drain = 01001

}GPIO_Directions;  //the end of the enum


/* Declare an enum to configure the current */
typedef enum {

    R2R,      //configuration of 2mA current
    R4R,      //configuration of 4mA current
    R8R       //configuration of 8mA current

}GPIO_Current;  //the end of the enum

/* Declare an enum to configure the Pins of the GPIO */
typedef enum
{
    Pin_Zero,      //configuration of pin zero
    Pin_One,       //configuration of pin one
    Pin_Two,       //configuration of pin two
    Pin_Three,     //configuration of pin three
    Pin_Four,      //configuration of pin four
    Pin_Five,      //configuration of pin five
    Pin_Six,       //configuration of pin six
    Pin_Seven      //configuration of pin seven

}GPIO_Pins; //the end of the enum



/* Declare an enum to configure the Ports of the GPIO */

typedef enum
{
    PORTA,      //configuration of port A
    PORTB,      //configuration of port B
    PORTC,      //configuration of port C
    PORTD,       //configuration of port D
    PORTE,       //configuration of port E
    PORTF       //configuration of port F

}GPIO_Ports;   //the end of the enum



/* Declare an enum to configure the levels of the pins */

typedef enum
{
    Low,    //configuration of low  is 0
    High    //configuration of high is 1

}GPIO_Level;  //the end of the enum


/* Declare a structure for pin configuration parameters  */
typedef struct
{
    GPIO_Ports Port;                   //Declare a variable from type GPIO_Ports
    GPIO_Pins Pin;                     //Declare a variable from type GPIO_Pins
    GPIO_Directions Direction;         //Declare a variable from type GPIO_Directions
    GPIO_Current Current;              //Declare a variable form type  GPIO_Current

}GPIO_Pin_Configuration; //the end of the structure


/* Declare a structure for port configuration parameters  */

typedef struct
{
    GPIO_Ports Port;                  //Declare a variable from type GPIO_Ports
    u8 Port_Value;                    //Declare a variable to hold the port value
    GPIO_Directions Direction;        //Declare a variable from type GPIO_Directions
    GPIO_Current Current;              //Declare a variable form type  GPIO_Current

}GPIO_Port_Configuration; //the end of the structure



Execution_state __GPIO_Set_Pin_Direction__(const GPIO_Pin_Configuration *Data);  //The Prototype Of Function That Configuration The Pin Direction
Execution_state __GPIO_Set_Pin__(const GPIO_Pin_Configuration *Data);           //The Prototype Of Function That Configuration The Pin Output (HIGH)
Execution_state __GPIO_Clear_Pin__(const GPIO_Pin_Configuration *Data);         //The Prototype Of Function That Configuration The Pin Output (LOW)
u8 __GPIO_Read_Pin__(const GPIO_Pin_Configuration *Data);                   //The Prototype Of Function That read The Pin value
Execution_state __GPIO_Toggle_Pin__(const GPIO_Pin_Configuration *Data);        //The Prototype Of Function That toggle The Pin value
Execution_state __GPIO_Set_Port_Direction__(GPIO_Port_Configuration *Data);     //The Prototype Of Function That Configuration The Port Direction
Execution_state __GPIO_Write_Port__(GPIO_Port_Configuration *Data);             //The Prototype Of Function That write The port value
u8 __GPIO_Read_Port__(GPIO_Port_Configuration *Data);                       //The Prototype Of Function That read The port value


#endif /* GPIO_H_ */
