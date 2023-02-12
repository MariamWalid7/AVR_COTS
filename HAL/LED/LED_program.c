/*
 ******************************** LED_program.c **************************************
 *
 * Created: 2/12/2023 1:56:15 PM
 *  Author: maria
 *  Layer: HAL
 */ 
#include <util/delay.h>
#define F_CPU 8000000UL
 
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
 
#include "LED_config.h"
#include "LED_interface.h"
#include "LED_private.h"


/*
 * description : function initializes pin connected to led as output
 * parameters : port name, pin number
 * returns : void
 */
void LED_voidInit   (u8 copy_u8PortName, u8 copy_u8PinNumber){
	DIO_enumSetPinDirection(copy_u8PortName,copy_u8PinNumber, DIO_u8_PIN_OUTPUT);
}

/*
 * description : function turns led on
 * parameters : port name, pin number, active state
 * returns : void
 */
void LED_voidOn     (u8 copy_u8PortName, u8 copy_u8PinNumber,u8 copy_u8ActiveState){
	
	if (copy_u8ActiveState == ACTIVE_HIGH){
	 DIO_enumSetPinValue(copy_u8PortName,copy_u8PinNumber, DIO_u8_PIN_HIGH);	
	}
	else if (copy_u8ActiveState == ACTIVE_LOW){
		DIO_enumSetPinValue(copy_u8PortName,copy_u8PinNumber, DIO_u8_PIN_LOW);
	}
}

/*
 * description : function turns led off
 * parameters : port name, pin number, active state
 * returns : void
 */
void LED_voidOff     (u8 copy_u8PortName, u8 copy_u8PinNumber,u8 copy_u8ActiveState){
	if (copy_u8ActiveState == ACTIVE_HIGH){
		DIO_enumSetPinValue(copy_u8PortName,copy_u8PinNumber, DIO_u8_PIN_LOW);
	}
	else if (copy_u8ActiveState == ACTIVE_LOW){
		DIO_enumSetPinValue(copy_u8PortName,copy_u8PinNumber, DIO_u8_PIN_HIGH);
	}
	
}

/*
 * description : function toggles led
 * parameters : struct contains port name, pin number, active state
 * returns : void
 */
void LED_voidToggle  (u8 copy_u8PortName, u8 copy_u8PinNumber){
	DIO_enumTogglePin(copy_u8PortName,copy_u8PinNumber);
}


void LED_voidFlashing (u8 copy_u8PortName, u8 copy_u8ActiveState){
	
	DIO_enumSetPortDirection(copy_u8PortName, DIO_u8_PIN_OUTPUT);
	
	if(copy_u8ActiveState == ACTIVE_HIGH){
		DIO_enumSetPortValue(copy_u8PortName, DIO_u8_PORT_HIGH);
	}
	
	else if (copy_u8ActiveState == ACTIVE_LOW){
		DIO_enumSetPortValue(copy_u8PortName, DIO_u8_PORT_LOW);
	}
	_delay_ms(1000);
	
	if(copy_u8ActiveState == ACTIVE_HIGH){
		DIO_enumSetPortValue(copy_u8PortName, DIO_u8_PORT_LOW);
	}
	
	else if (copy_u8ActiveState == ACTIVE_LOW){
		DIO_enumSetPortValue(copy_u8PortName, DIO_u8_PORT_HIGH);
	}
	_delay_ms(1000);
}

void LED_voidShiftLeft (u8 copy_u8PortName, u8 copy_u8ActiveState){
	int Arr[8] = {DIO_u8_PIN0, DIO_u8_PIN1, DIO_u8_PIN2, DIO_u8_PIN3, DIO_u8_PIN4, DIO_u8_PIN5, DIO_u8_PIN6, DIO_u8_PIN7};
	
	DIO_enumSetPortDirection(copy_u8PortName, DIO_u8_PIN_OUTPUT);
	
	for(int i=0; i<=7; i++){
		
		if(copy_u8ActiveState == ACTIVE_HIGH){
		DIO_enumSetPinValue(copy_u8PortName, Arr[i], DIO_u8_PIN_HIGH);
		}
		
		else if(copy_u8ActiveState == ACTIVE_LOW){
			DIO_enumSetPinValue(copy_u8PortName, Arr[i], DIO_u8_PIN_LOW);
		}
		_delay_ms(500);
		
		if(copy_u8ActiveState == ACTIVE_HIGH){
			DIO_enumSetPinValue(copy_u8PortName, Arr[i], DIO_u8_PIN_LOW);
		}
		
		else if(copy_u8ActiveState == ACTIVE_LOW){
			DIO_enumSetPinValue(copy_u8PortName, Arr[i], DIO_u8_PIN_HIGH);
		}
		_delay_ms(500);
		
				
	}
}

void LED_voidShiftRight (u8 copy_u8PortName, u8 copy_u8ActiveState){
int Arr[8] = {DIO_u8_PIN0, DIO_u8_PIN1, DIO_u8_PIN2, DIO_u8_PIN3, DIO_u8_PIN4, DIO_u8_PIN5, DIO_u8_PIN6, DIO_u8_PIN7};

DIO_enumSetPortDirection(copy_u8PortName, DIO_u8_PIN_OUTPUT);

for(int i=7; i>=0; i--){
	
	if(copy_u8ActiveState == ACTIVE_HIGH){
		DIO_enumSetPinValue(copy_u8PortName, Arr[i], DIO_u8_PIN_HIGH);
	}
	
	else if(copy_u8ActiveState == ACTIVE_LOW){
		DIO_enumSetPinValue(copy_u8PortName, Arr[i], DIO_u8_PIN_LOW);
	}
	_delay_ms(500);
	
	if(copy_u8ActiveState == ACTIVE_HIGH){
		DIO_enumSetPinValue(copy_u8PortName, Arr[i], DIO_u8_PIN_LOW);
	}
	
	else if(copy_u8ActiveState == ACTIVE_LOW){
		DIO_enumSetPinValue(copy_u8PortName, Arr[i], DIO_u8_PIN_HIGH);
	}
	_delay_ms(500);
	
	
 }
}

void LED_voidPingPong (u8 copy_u8PortName, u8 copy_u8ActiveState){
	
	LED_voidShiftRight (copy_u8PortName, copy_u8ActiveState);
	LED_voidShiftLeft (copy_u8PortName, copy_u8ActiveState);
}

void LED_voidConverging (u8 copy_u8PortName, u8 copy_u8ActiveState){
	int Arr[6] = {DIO_u8_PIN1, DIO_u8_PIN2, DIO_u8_PIN3, DIO_u8_PIN4, DIO_u8_PIN5, DIO_u8_PIN6};
		
	DIO_enumSetPortDirection(copy_u8PortName, DIO_u8_PIN_OUTPUT);
	
	if(copy_u8ActiveState == ACTIVE_HIGH){
		DIO_enumSetPinValue(copy_u8PortName, DIO_u8_PIN0, DIO_u8_PIN_HIGH);
	}
	
	else if(copy_u8ActiveState == ACTIVE_LOW){
		DIO_enumSetPinValue(copy_u8PortName, DIO_u8_PIN0, DIO_u8_PIN_LOW);
	}
	if(copy_u8ActiveState == ACTIVE_HIGH){
		DIO_enumSetPinValue(copy_u8PortName, DIO_u8_PIN7, DIO_u8_PIN_HIGH);
	}
	
	else if(copy_u8ActiveState == ACTIVE_LOW){
		DIO_enumSetPinValue(copy_u8PortName, DIO_u8_PIN7, DIO_u8_PIN_LOW);
	}
	_delay_ms(1000);
	
		if(copy_u8ActiveState == ACTIVE_HIGH){
			DIO_enumSetPinValue(copy_u8PortName, DIO_u8_PIN0, DIO_u8_PIN_LOW);
		}
		
		else if(copy_u8ActiveState == ACTIVE_LOW){
			DIO_enumSetPinValue(copy_u8PortName, DIO_u8_PIN0, DIO_u8_PIN_HIGH);
		}
		if(copy_u8ActiveState == ACTIVE_HIGH){
			DIO_enumSetPinValue(copy_u8PortName, DIO_u8_PIN7, DIO_u8_PIN_LOW);
		}
		
		else if(copy_u8ActiveState == ACTIVE_LOW){
			DIO_enumSetPinValue(copy_u8PortName, DIO_u8_PIN7, DIO_u8_PIN_HIGH);
		}
		_delay_ms(1000);
	
	for(int i=0; i<=6; i++){
		
		if(copy_u8ActiveState == ACTIVE_HIGH){
			DIO_enumSetPinValue(copy_u8PortName, Arr[i], DIO_u8_PIN_HIGH);
		}
		
		else if(copy_u8ActiveState == ACTIVE_LOW){
			DIO_enumSetPinValue(copy_u8PortName, Arr[i], DIO_u8_PIN_LOW);
		}
		_delay_ms(1000);
		
		if(copy_u8ActiveState == ACTIVE_HIGH){
			DIO_enumSetPinValue(copy_u8PortName, Arr[i], DIO_u8_PIN_LOW);
		}
		
		else if(copy_u8ActiveState == ACTIVE_LOW){
			DIO_enumSetPinValue(copy_u8PortName, Arr[i], DIO_u8_PIN_HIGH);
		}
		_delay_ms(1000);
		
			for(int i=6; i>=0; i--){
				
				if(copy_u8ActiveState == ACTIVE_HIGH){
					DIO_enumSetPinValue(copy_u8PortName, Arr[i], DIO_u8_PIN_HIGH);
				}
				
				else if(copy_u8ActiveState == ACTIVE_LOW){
					DIO_enumSetPinValue(copy_u8PortName, Arr[i], DIO_u8_PIN_LOW);
				}
				_delay_ms(1000);
				
				if(copy_u8ActiveState == ACTIVE_HIGH){
					DIO_enumSetPinValue(copy_u8PortName, Arr[i], DIO_u8_PIN_LOW);
				}
				
				else if(copy_u8ActiveState == ACTIVE_LOW){
					DIO_enumSetPinValue(copy_u8PortName, Arr[i], DIO_u8_PIN_HIGH);
				}
				_delay_ms(1000);
			}
	}
	
	}
	
LED_voidDiverging (u8 copy_u8PortName, u8 copy_u8ActiveState){
	int Arr[6] = {DIO_u8_PIN0, DIO_u8_PIN1, DIO_u8_PIN2, DIO_u8_PIN5, DIO_u8_PIN6, DIO_u8_PIN7};

DIO_enumSetPortDirection(copy_u8PortName, DIO_u8_PIN_OUTPUT);

if(copy_u8ActiveState == ACTIVE_HIGH){
	DIO_enumSetPinValue(copy_u8PortName, DIO_u8_PIN3, DIO_u8_PIN_HIGH);
}

else if(copy_u8ActiveState == ACTIVE_LOW){
	DIO_enumSetPinValue(copy_u8PortName, DIO_u8_PIN3, DIO_u8_PIN_LOW);
}
if(copy_u8ActiveState == ACTIVE_HIGH){
	DIO_enumSetPinValue(copy_u8PortName, DIO_u8_PIN4, DIO_u8_PIN_HIGH);
}

else if(copy_u8ActiveState == ACTIVE_LOW){
	DIO_enumSetPinValue(copy_u8PortName, DIO_u8_PIN4, DIO_u8_PIN_LOW);
}
_delay_ms(1000);

if(copy_u8ActiveState == ACTIVE_HIGH){
	DIO_enumSetPinValue(copy_u8PortName, DIO_u8_PIN3, DIO_u8_PIN_LOW);
}

else if(copy_u8ActiveState == ACTIVE_LOW){
	DIO_enumSetPinValue(copy_u8PortName, DIO_u8_PIN3, DIO_u8_PIN_HIGH);
}
if(copy_u8ActiveState == ACTIVE_HIGH){
	DIO_enumSetPinValue(copy_u8PortName, DIO_u8_PIN4, DIO_u8_PIN_LOW);
}

else if(copy_u8ActiveState == ACTIVE_LOW){
	DIO_enumSetPinValue(copy_u8PortName, DIO_u8_PIN4, DIO_u8_PIN_HIGH);
}
_delay_ms(1000);	
	
	
}

void LED_voidIncrement (u8 copy_u8PortName, u8 copy_u8ActiveState){
	
int Arr[8] = {DIO_u8_PIN0, DIO_u8_PIN1, DIO_u8_PIN2, DIO_u8_PIN3, DIO_u8_PIN4, DIO_u8_PIN5, DIO_u8_PIN6, DIO_u8_PIN7};

DIO_enumSetPortDirection(copy_u8PortName, DIO_u8_PIN_OUTPUT);

for(int i=0; i<=7; i++){
	
	if(copy_u8ActiveState == ACTIVE_HIGH){
		DIO_enumSetPinValue(copy_u8PortName, Arr[i], DIO_u8_PIN_HIGH);
	}
	
	else if(copy_u8ActiveState == ACTIVE_LOW){
		DIO_enumSetPinValue(copy_u8PortName, Arr[i], DIO_u8_PIN_LOW);
	}
	_delay_ms(500);
}
}