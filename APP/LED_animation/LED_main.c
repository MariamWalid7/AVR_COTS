/*
 * LED.c
 *
 * Created: 2/12/2023 1:55:35 PM
 *  Author: maria
 */ 

#include <util/delay.h>
#define F_CPU 8000000UL

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "LED_interface.h"



int main(void)
{
	
	
	
	
    while(1)
    {
	  LED_voidFlashing (DIO_u8_PORTC, ACTIVE_HIGH);
	  _delay_ms(500);
	  
	  LED_voidShiftLeft (DIO_u8_PORTC, ACTIVE_HIGH);
	  _delay_ms(500);
	  
	  LED_voidShiftRight (DIO_u8_PORTC, ACTIVE_HIGH);
	  _delay_ms(500);
	  
	  LED_voidConverging (DIO_u8_PORTC, ACTIVE_HIGH);
	  _delay_ms(500);
	  
	  LED_voidDiverging (DIO_u8_PORTC, ACTIVE_HIGH);
	  _delay_ms(500);
	  	
      LED_voidIncrement (DIO_u8_PORTC, ACTIVE_HIGH);
	  _delay_ms(500);
    }
}