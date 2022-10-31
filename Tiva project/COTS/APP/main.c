/**
  ******************************************************************************
  * @file    main.c
  * @author  mohamed mohamed taha
  * @Target  TivaC TM4C123GH6PM
  * @version V1
  * @date    22-Aug-2022
  * @brief   This source file contains the implementation of application .
  ******************************************************************************/


#include "Stdlib.h"
#include "LED.h"
#include "Button.h"

u8 cases = Null;
u8 T_ON_Set = Null;
u8 T_OFF_Set = Null;



//starting point
int main(void) {

    __LED_Initialize__();  //initialize the LED

    __Button_Initialize__();

    __LED_PWM_Period__(1,1);  //set the PWM


    for(;;) {  //super loop


        switch(cases) {

        case 0:
               if(!__Button_One_Read__()) {
            //   __LED_Stop__();
                   while(!__Button_One_Read__());
               cases++;
               }

            break;

        case 1:

            if(!__Button_One_Read__()) {
                while(!__Button_One_Read__());
                cases++;
            }
            if(!__Button_Two_Read__()) {

                while(!__Button_Two_Read__());
                T_ON_Set++;

            }

            break;

        case 2:

            if(!__Button_One_Read__()) {
                while(!__Button_One_Read__());
                cases++;
            }
            if(!__Button_Two_Read__()) {
                while(!__Button_Two_Read__());
                T_OFF_Set++;
                __LED_On__();

            }

            break;

        case 3:
    //        __LED_Start__();
            __LED_PWM_Period__(T_ON_Set,T_OFF_Set);  //set the PWM

            cases++;
            break;

        case 4:

            if(!__Button_One_Read__()) {
                while(!__Button_One_Read__());
                T_OFF_Set = Null;
                T_ON_Set = Null;
                cases = 1;
            }

            break;
        default :
            break;

        }


    } //end of the super loop

} //end of the main function
