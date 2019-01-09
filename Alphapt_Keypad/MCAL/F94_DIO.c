#include "F94_DIO.h"
#include <avr/io.h>
#include "../ServiceLayer/Services.h"


void EF_void_DIO_init_pin(char Reg , char pin , char dir)
{

	switch(Reg)
	{
	case 'a':
	case 'A':
		if(dir)
		{
			F94_SETBIT(DDRA , pin);
		}
		else
		{
			F94_CLEARBIT(DDRA , pin);
		}
		break;
	case 'b':
	case 'B':
		if(dir)
		{
			F94_SETBIT(DDRB , pin);
		}
		else
		{
			F94_CLEARBIT(DDRB , pin);
		}		break;
	case 'C':
	case 'c':
		if(dir)
		{
			F94_SETBIT(DDRC , pin);
		}
		else
		{
			F94_CLEARBIT(DDRC , pin);
		}		break;
	case 'D':
	case 'd':
		if(dir)
		{
			F94_SETBIT(DDRD , pin);
		}
		else
		{
			F94_CLEARBIT(DDRD , pin);
		}		break;
	}



}

void EF_void_DIO_Write_pin(char Reg , char pin , char dir)
{

	switch(Reg)
	{
	case 'a':
	case 'A':
		if(dir)
		{
			F94_SETBIT(PORTA , pin);
		}
		else
		{
			F94_CLEARBIT(PORTA , pin);
		}
		break;
	case 'b':
	case 'B':
		if(dir)
		{
			F94_SETBIT(PORTB , pin);
		}
		else
		{
			F94_CLEARBIT(PORTB , pin);
		}		break;
	case 'C':
	case 'c':
		if(dir)
		{
			F94_SETBIT(PORTC , pin);
		}
		else
		{
			F94_CLEARBIT(PORTC , pin);
		}		break;
	case 'D':
	case 'd':
		if(dir)
		{
			F94_SETBIT(PORTD , pin);
		}
		else
		{
			F94_CLEARBIT(PORTD , pin);
		}		break;
	}



}


void F94_void_DIO_init_Port(char Reg , char value)
{

	switch(Reg)
	{
	case 'a':
	case 'A':
		DDRA = value;
		break;
	case 'b':
	case 'B':
		DDRB = value;
		break;
	case 'C':
	case 'c':
		DDRC = value;
		break;
	case 'D':
	case 'd':
		DDRD = value;
		break;
	}
}

void F94_void_DIO_Write_Port(char Reg , char value)
{

	switch(Reg)
	{
	case 'a':
	case 'A':
		PORTA = value;
		break;
	case 'b':
	case 'B':
		PORTB = value;
		break;
	case 'C':
	case 'c':
		PORTC = value;
		break;
	case 'D':
	case 'd':
		PORTD = value;
		break;
	}
}

char EF_char_Read_Pin(char Reg , char pin)
{
	switch(Reg)
	{
	case 'a':
	case 'A':
		if(F94_READBIT(PINA , pin))
			return HIGH;
		else
			return LOW;
		break;
	case 'b':
	case 'B':
		if(F94_READBIT(PINB , pin))
			return HIGH;
		else
			return LOW;
		break;
	case 'C':
	case 'c':
		if(F94_READBIT(PINC , pin))
			return HIGH;
		else
			return LOW;
		break;
	case 'D':
	case 'd':
		if(F94_READBIT(PIND , pin))
			return HIGH;
		else
			return LOW;
		break;
	}
	return ERROR;
}
