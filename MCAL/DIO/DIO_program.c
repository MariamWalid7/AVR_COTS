/* ****************************** DIO_program.c *************************************
 * Author: maria
 * Layer:  MCAL
 *
 *
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_private.h"
#include "DIO_interface.h"

//implementation of functions

void DIO_voidSetPinDirection(u8 copy_u8PortName, u8 copy_u8PinNumber, u8 copy_u8Direction){
switch(copy_u8Direction){
default : break;

case DIO_u8_PIN_OUTPUT :
switch(copy_u8PortName){
case DIO_u8_PORTA : SET_BIT(DDRA, copy_u8PinNumber); break;
case DIO_u8_PORTB : SET_BIT(DDRB, copy_u8PinNumber); break;
case DIO_u8_PORTC : SET_BIT(DDRC, copy_u8PinNumber); break;
case DIO_u8_PORTD : SET_BIT(DDRD, copy_u8PinNumber); break;
default : break;
}break;

case DIO_u8_PIN_INPUT :
switch (copy_u8PortName){
case DIO_u8_PORTA : CLR_BIT(DDRA, copy_u8PinNumber); break;
case DIO_u8_PORTB : CLR_BIT(DDRB, copy_u8PinNumber); break;
case DIO_u8_PORTC : CLR_BIT(DDRC, copy_u8PinNumber); break;
case DIO_u8_PORTD : CLR_BIT(DDRD, copy_u8PinNumber); break;
default : break;
}break;
}
}


void DIO_voidSetPinValue (u8 copy_u8PortName, u8 copy_u8PinNumber, u8 copy_u8Value){
switch(copy_u8Value){
default:break;

case DIO_u8_PIN_HIGH:
switch(copy_u8PortName){
case DIO_u8_PORTA : SET_BIT(PORTA, copy_u8PinNumber); break;
case DIO_u8_PORTB : SET_BIT(PORTB, copy_u8PinNumber); break;
case DIO_u8_PORTC : SET_BIT(PORTC, copy_u8PinNumber); break;
case DIO_u8_PORTD : SET_BIT(PORTD, copy_u8PinNumber); break;
default : break;
}break;

case DIO_u8_PIN_LOW:
switch(copy_u8PortName){
	case DIO_u8_PORTA : CLR_BIT(PORTA, copy_u8PinNumber); break;
	case DIO_u8_PORTB : CLR_BIT(PORTB, copy_u8PinNumber); break;
	case DIO_u8_PORTC : CLR_BIT(PORTC, copy_u8PinNumber); break;
	case DIO_u8_PORTD : CLR_BIT(PORTD, copy_u8PinNumber); break;
	default : break;
}break;
}
}

u8 DIO_u8GetPinvalue(u8 copy_u8PortName, u8 copy_u8PinNumber){
u8 LOC_u8Value = 0;
switch (copy_u8PortName){
case DIO_u8_PORTA : LOC_u8Value= GET_BIT(PINA,copy_u8PinNumber); break;
case DIO_u8_PORTB : LOC_u8Value= GET_BIT(PINB,copy_u8PinNumber); break;
case DIO_u8_PORTC : LOC_u8Value= GET_BIT(PINC,copy_u8PinNumber); break;
case DIO_u8_PORTD : LOC_u8Value= GET_BIT(PIND,copy_u8PinNumber); break;
default: break;
}
return LOC_u8Value;
}

void DIO_voidTogglePin(u8 copy_u8PortName, u8 copy_u8PinNumber){
switch (copy_u8PortName){
case DIO_u8_PORTA : TOG_BIT(PORTA, copy_u8PinNumber); break;
case DIO_u8_PORTB : TOG_BIT(PORTB, copy_u8PinNumber); break;
case DIO_u8_PORTC : TOG_BIT(PORTC, copy_u8PinNumber); break;
case DIO_u8_PORTD : TOG_BIT(PORTD, copy_u8PinNumber); break;
default : break;
}
}

void DIO_voidSetPortDirection(u8 copy_u8PortName,u8 copy_u8Direction){
switch(copy_u8Direction){
	default:break;
case DIO_u8_PORT_OUTPUT:
switch(copy_u8PortName)	{
	default : break;
case DIO_u8_PORTA : DDRA = 0xff; break;
case DIO_u8_PORTB : DDRB = 0xff; break;
case DIO_u8_PORTC : DDRC = 0xff; break;
case DIO_u8_PORTD : DDRD = 0xff; break;
} break;

case DIO_u8_PORT_INPUT:
switch(copy_u8PortName)	{
	default : break;
	case DIO_u8_PORTA : DDRA = 0x00; break;
	case DIO_u8_PORTB : DDRB = 0x00; break;
	case DIO_u8_PORTC : DDRC = 0x00; break;
	case DIO_u8_PORTD : DDRD = 0x00; break;
} break;
}
}

void DIO_voidSetPortValue (u8 copy_u8PortName,u8 copy_u8Value){
switch(copy_u8Value){
default : break;

case DIO_u8_PORT_HIGH:
switch(copy_u8PortName)	{
default : break;
case DIO_u8_PORTA : PORTA = 0xff;
case DIO_u8_PORTB : PORTB = 0xff;
case DIO_u8_PORTC : PORTC = 0xff;
case DIO_u8_PORTD : PORTD = 0xff;
}break;

case DIO_u8_PORT_LOW :
switch(copy_u8PortName)	{
	default : break;
	case DIO_u8_PORTA : PORTA = 0x00;
	case DIO_u8_PORTB : PORTB = 0x00;
	case DIO_u8_PORTC : PORTC = 0x00;
	case DIO_u8_PORTD : PORTD = 0x00;
}break;
}
}

u8 DIO_u8GetPortvalue(u8 Copy_u8PortName){
 u8 Port_value = 0;
switch (Copy_u8PortName){
default : break;
    case DIO_u8_PORTA : return PINA ; break;
	case DIO_u8_PORTB : return PINB ; break;
	case DIO_u8_PORTC : return PINC ; break;
	case DIO_u8_PORTD : return PIND ; break;
}
}
