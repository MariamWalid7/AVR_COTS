/*
 ******************************** LED_interface.h **************************************
 *
 * Created: 2/12/2023 1:56:15 PM
 *  Author: maria
 *  Layer: HAL
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/* port defines */
#define  LED_PORTA  0
#define  LED_PORTB  1
#define  LED_PORTC  2
#define  LED_PORTD  3


/* Pin defines */
#define LED_PIN0   0
#define LED_PIN1   1
#define LED_PIN2   2
#define LED_PIN3   3
#define LED_PIN4   4
#define LED_PIN5   5
#define LED_PIN6   6
#define LED_PIN7   7

/* Active states */
#define ACTIVE_HIGH  1
#define ACTIVE_LOW   0
	
/* function prototypes */

void LED_voidInit     (u8 copy_u8PortName, u8 copy_u8PinNumber);
void LED_voidOn       (u8 copy_u8PortName, u8 copy_u8PinNumber, u8 copy_u8ActiveState);
void LED_voidOff      (u8 copy_u8PortName, u8 copy_u8PinNumber, u8 copy_u8ActiveState);
void LED_voidToggle   (u8 copy_u8PortName, u8 copy_u8PinNumber);
void LED_voidFlashing (u8 copy_u8PortName, u8 copy_u8ActiveState);
void LED_voidShiftRight (u8 copy_u8PortName, u8 copy_u8ActiveState); 
void LED_voidShiftLeft (u8 copy_u8PortName, u8 copy_u8ActiveState);
void LED_voidConverging (u8 copy_u8PortName, u8 copy_u8ActiveState);
void LED_voidDiverging (u8 copy_u8PortName, u8 copy_u8ActiveState);	
void LED_voidPingPong (u8 copy_u8PortName, u8 copy_u8ActiveState);
void LED_voidIncrement (u8 copy_u8PortName, u8 copy_u8ActiveState);

#endif /* LED_INTERFACE_H_ */