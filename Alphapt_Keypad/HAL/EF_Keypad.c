
#include "EF_Keypad.h"





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

