/*

  main.c

  Graphics Test for ATMEGA Controller

  Universal 8bit Graphics Library

  Copyright (c) 2012, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification,
  are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice, this list
    of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice, this
    list of conditions and the following disclaimer in the documentation and/or other
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 */

#include <avr/io.h>
#include <string.h>
#include <stdlib.h>
#include <util/delay.h>
#include "MCAL/EF_UART.h"
#include "HAL/EF_Keypad.h"
#include "HAL/EF_LCD.h"



static UART_cfg_str uart_cfg1 = {9600, 8, ONE_STOP_BIT, NO_PARITY, TRUE, FALSE, TRUE, TRUE};


char movecursur = 1;

int main(void)
{
	int key = -1;
	signed char alphKey = -1;

	sei();

	 EF_void_TimerInit();
	EF_void_LCD_init();
	EF_KEYPAD_Init();
	EF_void_UART_Init(&uart_cfg1);


	EF_void_TimerCreate(WAIT_KEYCHAR_SCAN_ID, WAIT_KEYCHAR_SCAN_TIMEOUT);





	while(1)
	{
//		EF_void_LCD_goto(1,1);
//		EF_void_LCD_print("key pressed");


		alphKey = EF_Keypad_AlphpRead();




		if(alphKey != -1 )
		{

			movecursur++;

//			EF_void_UART_PutChar(alphKey);
//			EF_void_UART_SendString("\n");

//			EF_void_LCD_goto(2,1);
//			EF_void_LCD_send_data((alphKey));

		}





	}/*end Super loop*/

}
