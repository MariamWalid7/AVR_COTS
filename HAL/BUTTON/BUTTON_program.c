/*
 ********************************************* BUTTON_program.c **********************************************************
 *
 * Created: 2/13/2023 6:22:18 PM
 *  Author: maria
 *  Layer: HAL
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "BUTTON_config.h"
#include "BUTTON_interface.h"
#include "BUTTON_private.h"



/*
 * description : function initializes button pin as input 
 * parameters : struct contains port name, pin number and connection
 * returns :void
 */

void Button_voidInitialize (BUTTON_Type BUTTON_Config){
	
	DIO_enumSetPinDirection(BUTTON_Config.Port, BUTTON_Config.Pin, DIO_u8_PIN_INPUT);
	
	if (BUTTON_Config.PullState == BUTTON_INT_PULLUP){
		
		DIO_voidConnectPullup(BUTTON_Config.Port, BUTTON_Config.Pin, 1);
	}
	
}


/*
 * description : function reads the state of button pin  
 * parameters : struct contains port name, pin number and connection
 * returns : state of button
 */
u8 Button_u8Read (BUTTON_Type BUTTON_Config){
	
	 u8 LOC_u8PinValue = 0;
	 u8 LOC_u8State = 0;
	 
	 if ((BUTTON_Config.PullState == BUTTON_INT_PULLUP) || (BUTTON_Config.PullState == BUTTON_EXT_PULLUP)){
		  
	 DIO_enumGetPinvalue(BUTTON_Config.Port, BUTTON_Config.Pin, &LOC_u8PinValue);
	 
	 if(LOC_u8PinValue == 1){
		 
		 LOC_u8State == BUTTON_NOTPRESSED;
	 }
	 
	 else if(LOC_u8PinValue == 0){
		 
		 LOC_u8State == BUTTON_PRESSED;
	 }
	 
	 }
	 
	 
	 else if (BUTTON_Config.PullState == BUTTON_EXT_PULLDOWN)	{
		 
		 DIO_enumGetPinvalue(BUTTON_Config.Port, BUTTON_Config.Pin, &LOC_u8PinValue);
		 
		 if(LOC_u8PinValue == 1){
			 
			 LOC_u8State == BUTTON_PRESSED;
		 }
		 
		 else if(LOC_u8PinValue == 0){
			 
			 LOC_u8State == BUTTON_NOTPRESSED;
		 }
	 } 

return LOC_u8State;	 
}
