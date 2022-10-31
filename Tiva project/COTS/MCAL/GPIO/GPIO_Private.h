/**
  ******************************************************************************
  * @file    GPIO_Private.h
  * @author  mohamed mohamed taha
  * @Target  TivaC TM4C123GH6PM
  * @version V1
  * @date    21-Aug-2022
  * @brief   This header file contains the registers of GPIO.
  ******************************************************************************/


/*Header file guard*/
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_



/************************************ GPIO *********************************/


/* Declare a structure to declare the register's bits */
typedef struct
{
    u32 Bit_Zero    : 1;              //Declare a variable with 1bit size
    u32 Bit_One     : 1;              //Declare a variable with 1bit size
    u32 Bit_Two     : 1;              //Declare a variable with 1bit size
    u32 Bit_Three   : 1;              //Declare a variable with 1bit size
    u32 Bit_Four    : 1;              //Declare a variable with 1bit size
    u32 Bit_Five    : 1;              //Declare a variable with 1bit size
    u32 Bit_Six     : 1;              //Declare a variable with 1bit size
    u32 Bit_Seven   : 1;              //Declare a variable with 1bit size
    u32             : 24;             //Reserved

}GPIO_Bits;  //end of the structure


/* Declare a union to access the register or its bits */
typedef union
{
    u32 Register_Access;         //Declare a variable with the size of the register
    GPIO_Bits Bit_Access;       //Declare a variable from type GPIO bits

}GPIO_Access;  //the end of the union


/* Declare a structure to access GPIO registers */
typedef struct
{
    volatile GPIO_Access GPIODATA;          /* Declare the GPIO DATA register */
    volatile GPIO_Access GPIODIR;           /* Declare the GPIO Direction register */
    volatile GPIO_Access GPIOIS;            /* Declare the GPIO Interrupt Sense register */

    volatile GPIO_Access GPIOIBE;           /* Declare the GPIO Interrupt Both Edges register */
    volatile GPIO_Access GPIOIEV;           /* Declare the GPIO Interrupt Event register */
    volatile GPIO_Access GPIOIM;            /* Declare the GPIO Interrupt Mask register */
    volatile GPIO_Access GPIORIS;           /* Declare the GPIO Raw Interrupt Status register */

    volatile GPIO_Access GPIOMIS;           /* Declare the GPIO Masked Interrupt Status register */
    volatile GPIO_Access GPIOICR;           /* Declare the GPIO Interrupt Clear register */
    volatile GPIO_Access GPIOAFSEL;         /* Declare the GPIO Alternate Function Select register */
    volatile u32         Reserved[55];      /* Reserved */
//    volatile GPIO_Access GPIODR2R;          /* Declare the GPIO 2-mA Drive Select register */
//    volatile GPIO_Access GPIODR4R;          /* Declare the GPIO 4-mA Drive Select register */
//    volatile GPIO_Access GPIODR8R;          /* Declare the GPIO 8-mA Drive Select register */
    volatile GPIO_Access GPIODRxR[3];          /* Declare the GPIO 2-4-8-mA Drive Select register */
    volatile GPIO_Access GPIOODR;           /* Declare the GPIO Open Drain Select register */
    volatile GPIO_Access GPIOPUR;           /* Declare the GPIO Pull-Up Select register */
    volatile GPIO_Access GPIOPDR;           /* Declare the GPIO Pull-Down Select register */
    volatile GPIO_Access GPIOSLR;           /* Declare the GPIO Slew Rate Control Select register */
    volatile GPIO_Access GPIODEN;           /* Declare the GPIO Digital Enable register */
    volatile u32 GPIOLOCK;                  /* Declare the GPIO Lock register */
    volatile GPIO_Access GPIOCR;            /* Declare the GPIO Commit register */
    volatile GPIO_Access GPIOAMSEL;         /* Declare the GPIO Analog Mode Select register */

    volatile u32 GPIOPCTL;                  /* Declare the GPIO Port Control register */
    volatile GPIO_Access GPIOADCCTL;        /* Declare the GPIO ADC Control register */
    volatile GPIO_Access GPIODMACTL;        /* Declare the GPIO DMA Control register */


    volatile GPIO_Access GPIOPeriphID4;     /* Declare the GPIO Peripheral Identification 4 register */
    volatile GPIO_Access GPIOPeriphID5;     /* Declare the GPIO Peripheral Identification 5 register */
    volatile GPIO_Access GPIOPeriphID6;     /* Declare the GPIO Peripheral Identification 6 register */
    volatile GPIO_Access GPIOPeriphID7;     /* Declare the GPIO Peripheral Identification 7 register */
    volatile GPIO_Access GPIOPeriphID0;     /* Declare the GPIO Peripheral Identification 0 register */
    volatile GPIO_Access GPIOPeriphID1;     /* Declare the GPIO Peripheral Identification 1 register */
    volatile GPIO_Access GPIOPeriphID2;     /* Declare the GPIO Peripheral Identification 2 register */
    volatile GPIO_Access GPIOPeriphID3;     /* Declare the GPIO Peripheral Identification 3 register */

    volatile GPIO_Access GPIOPCellID0;      /* Declare the GPIO PrimeCell Identification 0 register */
    volatile GPIO_Access GPIOPCellID1;      /* Declare the GPIO PrimeCell Identification 1 register */
    volatile GPIO_Access GPIOPCellID2;      /* Declare the GPIO PrimeCell Identification 2 register */
    volatile GPIO_Access GPIOPCellID3;      /* Declare the GPIO PrimeCell Identification 3 register */


}GPIO_Registers;  //the end of the structure



#define GPIOA ((GPIO_Registers*)0x400043FC)           //Define the PORTA base address
#define GPIOB ((GPIO_Registers*)0x400053FC)           //Define the PORTB base address
#define GPIOC ((GPIO_Registers*)0x400063FC)           //Define the PORTC base address
#define GPIOD ((GPIO_Registers*)0x400073FC)           //Define the PORTD base address
#define GPIOE ((GPIO_Registers*)0x400243FC)           //Define the PORTE base address
#define GPIOF ((GPIO_Registers*)0x400253FC)           //Define the PORTF base address



/***************************************************************************/


#endif /* GPIO_PRIVATE_H_ */
