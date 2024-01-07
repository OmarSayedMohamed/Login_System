#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"

u8 Reading = 0;     //variable to store the pressed button for Keypad
u8 flag = 0;
u8 checker;

void DCM (void);  // Function For DC Motor

void Step (void); // Function For Stepper Motor

void main (void)

{
	DIO_voidSetPortDir(PORTA_REG,PORT_DIR_OUT);
	DIO_voidSetPortDir(PORTC_REG,PORT_DIR_OUT);
	DIO_voidSetPortDir(PORTD_REG,PORT_DIR_OUT);

	DIO_voidSetPortDir(PORTB_REG,0b00001111);
	DIO_voidSetPortVal(PORTB_REG,PORT_VAL_HIGH);

	CLCD_voidInit(); 	/* Initialize LCD  */
	CLCD_voidSendString("Welcome");
	CLCD_voidSetPosition(1,0);
	CLCD_voidSendString("To Our System");
	_delay_ms (2000);
	CLCD_voidSendCommand(Clear);
	while (1)
	{
		CLCD_voidSendString(" Press 1 for DC");
		CLCD_voidSetPosition(1,0);
		CLCD_voidSendString("Press 2 For Step");
		Reading= KPD_u8GetPressedKey();
		switch (Reading)
		{
		case 1:
			flag = 1;
			DCM ();
			break;
		case 2:
			flag=1 ;
			Step ();
			break;

		}


	}

}

/******************************************************************************************/
void DCM (void)
{
	while (flag == 1)
	{
		DIO_voidSetPinVal(PORTD_REG,PIN0,PIN_VAL_LOW);
		DIO_voidSetPinVal(PORTD_REG,PIN1,PIN_VAL_LOW);
		Reading = 0;
		CLCD_voidSendCommand(Clear);
		CLCD_voidSendString(" Welcome to DC");
		_delay_ms (2000);
		CLCD_voidSendCommand(Clear);
		CLCD_voidSendString(" Press 1 For CW");
		CLCD_voidSetPosition(1,0);
		CLCD_voidSendString(" Press 2 For CCW");
		_delay_ms (1000);
		CLCD_voidSendCommand(Clear);
		CLCD_voidSendString(" Press 3 to back");
		_delay_ms (1000);
		CLCD_voidSendCommand(Clear);
		do {
			Reading=KPD_u8GetPressedKey();

			switch (Reading)

			{
			case 1:
				CLCD_voidSendString(" Rotate CW");
				CLCD_voidSetPosition(1,0);
				CLCD_voidSendString("Press C for back");
				while(Reading != '&')
				{
					Reading=KPD_u8GetPressedKey();
					if(Reading == '&') break;
					DIO_voidSetPinVal(PORTD_REG,PIN0,PIN_VAL_HIGH);
					DIO_voidSetPinVal(PORTD_REG,PIN1,PIN_VAL_LOW);
				}
				flag =1;
				break;

			case 2:
				CLCD_voidSendString(" Rotate CCW");
				CLCD_voidSetPosition(1,0);
				CLCD_voidSendString("Press C for back");
				while(Reading != '&')
				{
					Reading=KPD_u8GetPressedKey();
					if(Reading == '&') break;
					DIO_voidSetPinVal(PORTD_REG,PIN0,PIN_VAL_LOW);
					DIO_voidSetPinVal(PORTD_REG,PIN1,PIN_VAL_HIGH);
				}
				flag =1;
				break;

			case 3:
				CLCD_voidSendCommand(Clear);
				flag = 0;
				break;

			}

		} while (Reading == '\0');

	}

}

/********************************************************************************************/

void Step (void)
{
	while (flag ==1)
	{
		DIO_voidSetPinVal(PORTD_REG,PIN2,PIN_VAL_LOW);
		DIO_voidSetPinVal(PORTD_REG,PIN3,PIN_VAL_LOW);
		DIO_voidSetPinVal(PORTD_REG,PIN4,PIN_VAL_LOW);
		DIO_voidSetPinVal(PORTD_REG,PIN5,PIN_VAL_LOW);
		Reading = 0;
		CLCD_voidSendCommand(Clear);
		CLCD_voidSendString(" Welcome to Step");
		_delay_ms (2000);
		CLCD_voidSendCommand(Clear);
		CLCD_voidSendString(" Press 1 For CW");
		CLCD_voidSetPosition(1,0);
		CLCD_voidSendString(" Press 2 For CCW");
		_delay_ms (1000);
		CLCD_voidSendCommand(Clear);
		CLCD_voidSendString(" Press 3 to back");
		_delay_ms (1000);
		CLCD_voidSendCommand(Clear);

		do {
			Reading=KPD_u8GetPressedKey();

			switch (Reading)

			{
			case 1:
				CLCD_voidSendString(" Rotate CW");
				CLCD_voidSetPosition(1,0);
				CLCD_voidSendString("Press C for back");
				while(Reading != '&')
				{
					Reading=KPD_u8GetPressedKey();
					if(Reading == '&') break;
					DIO_voidSetPinVal(PORTD_REG,PIN2,PIN_VAL_LOW);
					DIO_voidSetPinVal(PORTD_REG,PIN3,PIN_VAL_HIGH);
					DIO_voidSetPinVal(PORTD_REG,PIN4,PIN_VAL_HIGH);
					DIO_voidSetPinVal(PORTD_REG,PIN5,PIN_VAL_LOW);
					_delay_ms(10);
					DIO_voidSetPinVal(PORTD_REG,PIN2,PIN_VAL_HIGH);
					DIO_voidSetPinVal(PORTD_REG,PIN3,PIN_VAL_HIGH);
					DIO_voidSetPinVal(PORTD_REG,PIN4,PIN_VAL_LOW);
					DIO_voidSetPinVal(PORTD_REG,PIN5,PIN_VAL_LOW);
					_delay_ms(10);
					DIO_voidSetPinVal(PORTD_REG,PIN2,PIN_VAL_HIGH);
					DIO_voidSetPinVal(PORTD_REG,PIN3,PIN_VAL_LOW);
					DIO_voidSetPinVal(PORTD_REG,PIN4,PIN_VAL_LOW);
					DIO_voidSetPinVal(PORTD_REG,PIN5,PIN_VAL_HIGH);
					_delay_ms(10);
					DIO_voidSetPinVal(PORTD_REG,PIN2,PIN_VAL_LOW);
					DIO_voidSetPinVal(PORTD_REG,PIN3,PIN_VAL_LOW);
					DIO_voidSetPinVal(PORTD_REG,PIN4,PIN_VAL_HIGH);
					DIO_voidSetPinVal(PORTD_REG,PIN5,PIN_VAL_HIGH);
					_delay_ms(10);
				}
				flag =1;
				break;

			case 2:
				CLCD_voidSendString(" Rotate CCW");
				CLCD_voidSetPosition(1,0);
				CLCD_voidSendString("Press C for back");
				while(Reading != '&')
				{
					Reading=KPD_u8GetPressedKey();
					if(Reading == '&') break;
					DIO_voidSetPinVal(PORTD_REG,PIN2,PIN_VAL_LOW);
					DIO_voidSetPinVal(PORTD_REG,PIN3,PIN_VAL_HIGH);
					DIO_voidSetPinVal(PORTD_REG,PIN4,PIN_VAL_HIGH);
					DIO_voidSetPinVal(PORTD_REG,PIN5,PIN_VAL_LOW);
					_delay_ms(10);
					DIO_voidSetPinVal(PORTD_REG,PIN2,PIN_VAL_LOW);
					DIO_voidSetPinVal(PORTD_REG,PIN3,PIN_VAL_LOW);
					DIO_voidSetPinVal(PORTD_REG,PIN4,PIN_VAL_HIGH);
					DIO_voidSetPinVal(PORTD_REG,PIN5,PIN_VAL_HIGH);
					_delay_ms(10);
					DIO_voidSetPinVal(PORTD_REG,PIN2,PIN_VAL_HIGH);
					DIO_voidSetPinVal(PORTD_REG,PIN3,PIN_VAL_LOW);
					DIO_voidSetPinVal(PORTD_REG,PIN4,PIN_VAL_LOW);
					DIO_voidSetPinVal(PORTD_REG,PIN5,PIN_VAL_HIGH);
					_delay_ms(10);
					DIO_voidSetPinVal(PORTD_REG,PIN2,PIN_VAL_HIGH);
					DIO_voidSetPinVal(PORTD_REG,PIN3,PIN_VAL_HIGH);
					DIO_voidSetPinVal(PORTD_REG,PIN4,PIN_VAL_LOW);
					DIO_voidSetPinVal(PORTD_REG,PIN5,PIN_VAL_LOW);
					_delay_ms(10);
				}
				flag =1;
				break;

			case 3:
				CLCD_voidSendCommand(Clear);
				flag = 0;
				break;

			}

		} while (Reading == '\0');

	}
}

/********************************************************************************************/

