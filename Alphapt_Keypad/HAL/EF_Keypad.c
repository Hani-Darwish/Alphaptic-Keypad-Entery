
#include "EF_Keypad.h"


extern char movecursur ;


static char alphaptic_number[10][4] = {
									 {' ',' ',' ',' '},
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


void EF_KEYPAD_Init()
{
	EF_void_DIO_init_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN1 , OUTPUT);
	EF_void_DIO_init_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN2 , OUTPUT);
	EF_void_DIO_init_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN3 , OUTPUT);
	EF_void_DIO_init_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN4 , OUTPUT);


	EF_void_DIO_init_pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN1 , INPUT);
	EF_void_DIO_init_pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN2 , INPUT);
	EF_void_DIO_init_pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN3 , INPUT);
	EF_void_DIO_init_pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN4 , INPUT);

	EF_void_DIO_Write_pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN1 , HIGH);
	EF_void_DIO_Write_pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN2 , HIGH);
	EF_void_DIO_Write_pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN3 , HIGH);
	EF_void_DIO_Write_pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN4 , HIGH);

}

static int KEYPAD_COLUMN_1_Read()
{
	EF_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN1 , LOW);
	EF_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN2 , HIGH);
	EF_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN3 , HIGH);
	EF_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN4 , HIGH);



	if(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN1) == LOW)
	{
		while(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN1) == LOW);

		return NUMBER_1;
	}
	if(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN2) == LOW)
	{
		while(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN2) == LOW);

		return NUMBER_4;
	}
	if(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN3) == LOW)
	{
		while(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN3) == LOW);

		return NUMBER_7;
	}
	if(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN4) == LOW)
	{
		while(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN4) == LOW);

		return BUTTON_STAR;
	}



	return ERROR;
}

static int KEYPAD_COLUMN_2_Read()
{
	EF_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN1 , HIGH);
	EF_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN2 , LOW);
	EF_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN3 , HIGH);
	EF_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN4 , HIGH);


	if(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN1) == LOW)
	{

		while(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN1) == LOW);
		return NUMBER_2;
	}
	if(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN2) == LOW)
	{
		while(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN2) == LOW);

		return NUMBER_5;
	}
	if(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN3) == LOW)
	{
		while(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN3) == LOW);

		return NUMBER_8;
	}
	if(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN4) == LOW)
	{
		while(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN4) == LOW);

		return NUMBER_0;
	}


	return ERROR;
}

static int KEYPAD_COLUMN_3_Read()
{
	EF_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN1 , HIGH);
	EF_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN2 , HIGH);
	EF_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN3 , LOW);
	EF_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN4 , HIGH);



	if(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN1) == LOW)
	{
		while(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN1) == LOW);

		return NUMBER_3;
	}
	if(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN2) == LOW)
	{
		while(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN2) == LOW);

		return NUMBER_6;
	}
	if(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN3) == LOW)
	{
		while(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN3) == LOW);

		return NUMBER_9;
	}
	if(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN4) == LOW)
	{
		while(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN4) == LOW);

		return BUTTON_ENTR;
	}


	return ERROR;
}


static int KEYPAD_COLUMN_4_Read()
{


	EF_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN1 , HIGH);
	EF_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN2 , HIGH);
	EF_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN3 , HIGH);
	EF_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN4 , LOW);



	if(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN1) == LOW)
	{
		while(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN1) == LOW);

		return BUTTON_F1;
	}
	else if(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN2) == LOW)
	{
		while(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN2) == LOW);

		return BUTTON_F2;
	}
	else if(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN3) == LOW)
	{
		while(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN3) == LOW);

		return BUTTON_F3;
	}
	else if(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN4) == LOW)
	{
		while(EF_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN4) == LOW);

		return BUTTON_F4;
	}


	return ERROR;
}

int EF_KeypadRead()
{

	EF_KEYPAD_Init();

	return KEYPAD_COLUMN_1_Read() ^ KEYPAD_COLUMN_2_Read()
			 ^KEYPAD_COLUMN_4_Read() ^ KEYPAD_COLUMN_3_Read()  ^ -1 ;


}


char EF_Keypad_AlphpRead()
{
	volatile int  keyPresd  = -1;
	unsigned char presCount =  0;
	signed char alphmap   	= -1;
	 signed char last_Keypresed   = -1;


	keyPresd = EF_KeypadRead();
	if(!(keyPresd == -1))
	{

		EF_void_TimerStart(WAIT_KEYCHAR_SCAN_ID);

		do{

//			EF_void_UART_SendString("last key update ");
//			EF_void_UART_Send_Integer(last_Keypresed);
//			EF_void_UART_SendString("\n");


			if(!(keyPresd == -1))
			{



				if((keyPresd !=  last_Keypresed) || (presCount == 4)   )
				{
//					presCount++;
					presCount = 0;
					EF_void_UART_SendString("reset.........\n");

				}

				EF_void_UART_SendString("keyPresd ");
				EF_void_UART_Send_Integer(keyPresd);
				EF_void_UART_SendString("     ");

				EF_void_UART_SendString("presCount ");
				EF_void_UART_Send_Integer(presCount);
				EF_void_UART_SendString("\n");

				alphmap = Alphaptic_Map(keyPresd,presCount);

//				EF_void_UART_SendString("return char ");
//				EF_void_UART_PutChar(alphmap);
//				EF_void_UART_SendString("\n");

				EF_void_LCD_goto(1,movecursur);
				EF_void_LCD_send_data((alphmap));

				presCount++;

				EF_void_TimerReset(WAIT_KEYCHAR_SCAN_ID);

				last_Keypresed = (char)keyPresd;


			}

//			EF_void_LCD_Clear_Screen();


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

	return alphaptic_number[keyPressed][pressedCount];
}







