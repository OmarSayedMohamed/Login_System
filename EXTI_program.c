/*******************************************************************************/
// Layer : MCAL
// Author : OMAR Sayed 
// Version : 01
// Date : 30/8/2023
//                              *Component EXTI*
/*******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "GIE_interface.h"

static void (*GlobalPtrToFuncint0)(void)=NULL;
static void (*GlobalPtrToFuncint1)(void)=NULL;
static void (*GlobalPtrToFuncint2)(void)=NULL;

void EXTI_voidSetSenseCtrl(sense_ctrl Copy_sense_ctr,interrupt_idx Copy_interrupt_idx)
{

	switch (Copy_interrupt_idx)
	{
	case int0:
		switch (Copy_sense_ctr)
		{
		case low_level:
			CLR_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
			break;
		case on_change:
			SET_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
			break;
		case falling_edge:
			CLR_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
			break;
		case rising_edge:
			SET_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
			break;
		}
		break;
		case int1:
			switch (Copy_sense_ctr)
			{
			case low_level:
				CLR_BIT(MCUCR,MCUCR_ISC10);
				CLR_BIT(MCUCR,MCUCR_ISC11);
				break;
			case on_change:
				SET_BIT(MCUCR,MCUCR_ISC10);
				CLR_BIT(MCUCR,MCUCR_ISC11);
				break;
			case falling_edge:
				CLR_BIT(MCUCR,MCUCR_ISC10);
				SET_BIT(MCUCR,MCUCR_ISC11);
				break;
			case rising_edge:
				SET_BIT(MCUCR,MCUCR_ISC10);
				SET_BIT(MCUCR,MCUCR_ISC11);
				break;
			}
			break;
		case int2:
			switch (Copy_sense_ctr)
			{
			case falling_edge:
				CLR_BIT(MCUCSR,MCUCSR_ISC2);
				break;
			case rising_edge:
				SET_BIT(MCUCSR,MCUCSR_ISC2);
				break;
			}
			break;

	}

}


void EXTI_voidEnableInterrupt(interrupt_idx Copy_interrupt_idx)
{
switch (Copy_interrupt_idx)
{
case int0:
	SET_BIT(GICR,GICR_INT0);
	break;
case int1:
	SET_BIT(GICR,GICR_INT1);
	break;
case int2:
	SET_BIT(GICR,GICR_INT2);
	break;
}
}

void EXTI_voidDisableInterrupt(interrupt_idx Copy_interrupt_idx)
{
switch (Copy_interrupt_idx)
{
case int0:
	CLR_BIT(GICR,GICR_INT0);
	break;
case int1:
	CLR_BIT(GICR,GICR_INT1);
	break;
case int2:
	CLR_BIT(GICR,GICR_INT2);
	break;
}
}

void EXTI_voidSetCallBack(interrupt_idx Copy_interrupt_idx, void  (*ptrtofunc)(void))
{
if (*ptrtofunc != NULL)
{
switch (Copy_interrupt_idx)
{
case int0: GlobalPtrToFuncint0=ptrtofunc;
	break;
case int1: GlobalPtrToFuncint1=ptrtofunc;
	break;
case int2: GlobalPtrToFuncint2=ptrtofunc;
	break;
}
}
else
{
/* Do Nothing */
 asm ("NOP");
}
}

// Call Function to ISR

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
if (GlobalPtrToFuncint0 !=NULL)
{
 GlobalPtrToFuncint0 ();
}
else
{
/* Do Nothing */
 asm ("NOP");
}
}

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
if (GlobalPtrToFuncint1 !=NULL)
{
 GlobalPtrToFuncint1 ();
}
else
{
/* Do Nothing */
 asm ("NOP");
}
}

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
if (GlobalPtrToFuncint2 !=NULL)
{
 GlobalPtrToFuncint2 ();
}
else
{
/* Do Nothing */
 asm ("NOP");
}
}
