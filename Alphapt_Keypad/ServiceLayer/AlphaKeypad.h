/*
 * AlphaKepad.h
 *
 *  Created on: Jan 9, 2019
 *      Author: root
 */

#ifndef SERVICELAYER_ALPHAKEYPAD_H_
#define SERVICELAYER_ALPHAKEYPAD_H_



#include "../MCAL/F94_DIO.h"
#include "../MCAL/EF_UART.h"
#include "../ServiceLayer/Services.h"
#include "../Utilities/EF_SpechialTIMER.h"
#include "../HAL/EF_LCD.h"
#include "../HAL/EF_Keypad.h"


char EF_Keypad_AlphpRead();
char Alphaptic_Map(char keyPressed,char pressedCount);
char lowerCharTO_UperCase(char lower );

#endif /* SERVICELAYER_ALPHAKEYPAD_H_ */
