/*
 * F94_KEYPAD.h
 *
 *  Created on: Oct 5, 2018
 *      Author: root
 */




#ifndef F94_KEYPAD_H_
#define F94_KEYPAD_H_

#include "../MCAL/F94_DIO.h"
#include "../MCAL/EF_UART.h"
#include "../ServiceLayer/Services.h"
#include "../Utilities/EF_SpechialTIMER.h"
#include "../HAL/EF_LCD.h"

enum
{
	KEYPAD_COLUMN_PIN1 	=	4,
	KEYPAD_COLUMN_PIN2 	=   5,
	KEYPAD_COLUMN_PIN3 	=   6,
	KEYPAD_COLUMN_PIN4  =   7,
	KEYPAD_COLUMN_PORT 	= 	'A',
	KEYPAD_ROW_PIN1 	=	0,
	KEYPAD_ROW_PIN2 	=   1,
	KEYPAD_ROW_PIN3 	=   2,
	KEYPAD_ROW_PIN4     =   3,
	KEYPAD_ROW_PORT 	= 	'A'
};

enum
{
	NUMBER_0,
	NUMBER_1,
	NUMBER_2,
	NUMBER_3,
	NUMBER_4,
	NUMBER_5,
	NUMBER_6,
	NUMBER_7,
	NUMBER_8,
	NUMBER_9,
	BUTTON_STAR,
	BUTTON_ENTR,
	BUTTON_F1,
	BUTTON_F2,
	BUTTON_F3,
	BUTTON_F4
};
void EF_KEYPAD_Init();

int EF_KeypadRead();


char EF_Keypad_AlphpRead();
char Alphaptic_Map(char keyPressed,char pressedCount);

#endif /* F94_KEYPAD_H_ */
