/*******************************************************************************/
// Layer : MCAL
// Author : OMAR Sayed 
// Version : 01
// Date : 30/8/2023
//                              *Component EXTI*
/*******************************************************************************/
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

// For Controlling Sense Control for INT0 & INT01
#define MCUCR     *((volatile u8*)0x55)
// For Controlling Sense Control for INT0
#define MCUCR_ISC00  0
#define MCUCR_ISC01  1
// For Controlling Sense Control for INT1
#define MCUCR_ISC10  2
#define MCUCR_ISC11  3

// For Controlling Sense Control for INT2
#define MCUCSR    *((volatile u8*)0x54)
#define MCUCSR_ISC2  6

// To Control SIE of INT0 & INT1 & INT2
#define GICR      *((volatile u8*)0x5B)
#define GICR_INT0    6
#define GICR_INT1    7
#define GICR_INT2    5






#endif