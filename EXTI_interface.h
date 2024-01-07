/*******************************************************************************/
// Layer : MCAL
// Author : OMAR Sayed 
// Version : 01
// Date : 30/8/2023
//                              *Component EXTI*
/*******************************************************************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum
{
low_level =0,
on_change,
falling_edge,
rising_edge
}sense_ctrl;

typedef enum
{
	int0 =0,
	int1,
	int2
}interrupt_idx;

// Function to set the sense control for the interrupt
void EXTI_voidSetSenseCtrl(sense_ctrl Copy_sense_ctr,interrupt_idx Copy_interrupt_idx);
// Function to Enable the Interrupt
void EXTI_voidEnableInterrupt(interrupt_idx Copy_interrupt_idx);
// Function to Disable the Interrupt
void EXTI_voidDisableInterrupt(interrupt_idx Copy_interrupt_idx);
// Function to Call ISR into main
void EXTI_voidSetCallBack(interrupt_idx Copy_interrupt_idx,void  (*ptrtofunc)(void));












#endif
