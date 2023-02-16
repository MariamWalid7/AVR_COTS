/*
 ********************************************* BUTTON_interface.h **********************************************************
 *
 * Created: 2/13/2023 6:22:18 PM
 *  Author: maria
 *  Layer: HAL
 */ 


#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_

#include "STD_TYPES.h"

#define BUTTON_PRESSED    1
#define BUTTON_NOTPRESSED 0



#define BUTTON_INT_PULLUP   0
#define BUTTON_EXT_PULLUP   1
#define BUTTON_EXT_PULLDOWN 2


/* Port defines */
#define  BUTTON_PORTA 0
#define  BUTTON_PORTB 1
#define  BUTTON_PORTC 2
#define  BUTTON_PORTD 3


/* Pin defines */
#define  BUTTON_PIN0 0
#define  BUTTON_PIN1 1
#define  BUTTON_PIN2 2
#define  BUTTON_PIN3 3
#define  BUTTON_PIN4 4
#define  BUTTON_PIN5 5
#define  BUTTON_PIN6 6
#define  BUTTON_PIN7 7


typedef struct{
	
	u8 Pin;
	u8 Port;
	u8 PullState;
	
	}BUTTON_Type;



void Button_voidInitialize (BUTTON_Type BUTTON_Config);
u8 Button_u8Read           (BUTTON_Type BUTTON_Config);



#endif /* BUTTON_INTERFACE_H_ */