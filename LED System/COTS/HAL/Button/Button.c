/*
 * Button.c
 *
 *  Created on: Oct 9, 2022
 *      Author: oliver
 */

#include "Stdlib.h"
#include "GPIO.h"

GPIO_Pin_Configuration BT1 = {PORTF,Pin_Four,Input_Pull_Up,R4R};
GPIO_Pin_Configuration BT2 = {PORTF,Pin_Zero,Input_Pull_Up,R4R};


void __Button_Initialize__(void) {

    __GPIO_Set_Pin_Direction__(&BT1);
    __GPIO_Set_Pin_Direction__(&BT2);

}




u8 __Button_One_Read__(void) {

    return __GPIO_Read_Pin__(&BT1);

}


u8 __Button_Two_Read__(void) {

    return __GPIO_Read_Pin__(&BT2);

}
