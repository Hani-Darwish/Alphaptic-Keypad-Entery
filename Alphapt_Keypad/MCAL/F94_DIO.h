

#ifndef F94_DIO_H_
#define F94_DIO_H_


#define F94_SETBIT(Reg,Pin) (Reg |= (1 << Pin))
#define F94_CLEARBIT(Reg,Pin) (Reg &=~ (1 << Pin))
#define F94_READBIT(Reg,Pin) (Reg & (1 << Pin))
#define F94_WRITEPORT(Reg,value) (Reg |= value)


void EF_void_DIO_init_pin(char Reg , char pin , char dir);
void EF_void_DIO_Write_pin(char Reg , char pin , char dir);
void F94_void_DIO_init_Port(char Reg , char value);
void F94_void_DIO_Write_Port(char Reg , char value);
char EF_char_Read_Pin(char Reg , char pin);


#endif /* F94_DIO_H_ */
