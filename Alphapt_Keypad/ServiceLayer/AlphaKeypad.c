/*
 * AlphaKeypad.c
 *
 *  Created on: Jan 9, 2019
 *      Author: root
 */

#include "AlphaKeypad.h"


extern char movecursur ;


/*  " !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~"  */

static char alphaptic_number[10][4] = {

									  {' ','0','0','0'},
									  {'a','b','c','1'},
									  {'d','e','f','2'},
									  {'j','h','i','3'},
									  {'g','k','l','4'},
									  {'m','n','0','5'},
									  {'p','q','r','6'},
									  {'s','t','u','7'},
									  {'v','w','x','8'},
									  {'y','z','.','9'},

								     };

char EF_Keypad_AlphpRead()
{
	volatile int  keyPresd       = -1;
	unsigned char presCount      =  0;
	signed 	 char alphmap   	 = -1;
	signed   char last_Keypresed = -1;
	static   char CaptlFlag      =  0;


	keyPresd = EF_KeypadRead();
	if(!(keyPresd == -1))
	{
		EF_void_TimerStart(WAIT_KEYCHAR_SCAN_ID);

		do{

			if(!(keyPresd == -1))
			{



				if((keyPresd !=  last_Keypresed) || (presCount == 4)   )
				{
					presCount = 0;
					EF_void_UART_SendString("reset.........\n");

				}

				EF_void_UART_SendString("keyPresd ");
				EF_void_UART_Send_Integer(keyPresd);
				EF_void_UART_SendString("     ");

				EF_void_UART_SendString("presCount ");
				EF_void_UART_Send_Integer(presCount);
				EF_void_UART_SendString("\n");


				/*capital letters  */
				if((int)keyPresd == BUTTON_F4 )
				{
					CaptlFlag ^= 1;
					EF_void_UART_SendString("Capitacl Flag\n");
					break;
				}

				/* clear lcd */
				if((int)keyPresd == BUTTON_F3)
				{

					movecursur = 1;
					EF_void_LCD_Clear_Screen();

					EF_void_UART_SendString("Clear Screen \n");

					break;
				}


				alphmap = Alphaptic_Map(keyPresd,presCount);
				/* check capitalization   */
				if(CaptlFlag == 1)
				{
					alphmap = lowerCharTO_UperCase(alphmap);
				}

				EF_void_LCD_goto(1,movecursur);
				EF_void_LCD_send_data((alphmap));

				EF_void_TimerReset(WAIT_KEYCHAR_SCAN_ID);
				last_Keypresed = (char)keyPresd;
				presCount++;

			}
			keyPresd = EF_KeypadRead();


		}while(!(EF_BOOLEAN_TimerCheck(WAIT_KEYCHAR_SCAN_ID) == TRUE));

		EF_void_TimerStop(WAIT_KEYCHAR_SCAN_ID);
		EF_void_TimerReset(WAIT_KEYCHAR_SCAN_ID);


		EF_void_UART_SendString("Exit do while \n");


	}


//	EF_void_UART_SendString("Exit while\n");
//	EF_void_UART_PutChar(alphmap);
//	EF_void_UART_SendString("\n");


	return alphmap;

}



char Alphaptic_Map( char keyPressed,char pressedCount)
{
    if(  (keyPressed >=0) && (keyPressed <= 9) )
    {
    	return alphaptic_number[keyPressed][pressedCount];

    }
    else{
    	return '0';
    }
}



char lowerCharTO_UperCase(char lower )
{
	char  upper;

	if(lower >= 'a' && lower <= 'z'){
		upper = ('A' + lower - 'a');
	}
	else
	{
		upper = lower;
	}


	EF_void_UART_SendString("The uppercase equivalent is ");
	EF_void_UART_PutChar(upper);
	EF_void_UART_SendString("\n");


	return upper;
}




