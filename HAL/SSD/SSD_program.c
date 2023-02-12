/*
 * **************************** SSD_program.c ***************************************
 *
 * Created: 2/12/2023 9:32:10 PM
 *  Author: maria
 *  Layer: HAL
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"

#include "SSD_config.h"
#include "SSD_interface.h"
#include "SSD_private.h" 

static u8 LOC_u8NumArray [10] = SSD_numberArray;

/*
 * description : function initializes port connected to SSD as output 
 * parameters : port name 
 * returns : void
 */
void SSD_voidInit    (SSD_Type SSD_configure){
	
	DIO_enumSetPortDirection(SSD_configure.Port, DIO_u8_PORT_OUTPUT);
	
}

/*
 * description : function writes numbers 0:9 on 7SEG 
 * parameters : struct contains port name, SSD type and enable 
 * returns : void
 */
void SSD_voidWrite   (SSD_Type SSD_configure, u8 copy_u8Number){
	
	if (SSD_configure.Type == COMMON_CATHODE){
		DIO_enumSetPortValue(SSD_configure.Port, LOC_u8NumArray[copy_u8Number]);
	}
	
	else if (SSD_configure.Type == COMMON_ANODE){
		DIO_enumSetPortValue(SSD_configure.Port, ~(LOC_u8NumArray[copy_u8Number]));
	}	
	
}

/*
 * description : function enables common pin
 * parameters : struct contains port name, SSD type and enable 
 * returns : void
 */
void SSD_voidEnable  (SSD_Type SSD_configure){
	if (SSD_configure.Type == COMMON_CATHODE){
		
		DIO_enumSetPinDirection (SSD_configure.EnablePort, SSD_configure.EnablePin, DIO_u8_PIN_OUTPUT);
		DIO_enumSetPinValue     (SSD_configure.EnablePort, SSD_configure.EnablePin, DIO_u8_PIN_LOW);
	}
	
	else if (SSD_configure.Type == COMMON_ANODE){
		
		DIO_enumSetPinDirection (SSD_configure.EnablePort, SSD_configure.EnablePin, DIO_u8_PIN_OUTPUT);
		DIO_enumSetPinValue     (SSD_configure.EnablePort, SSD_configure.EnablePin, DIO_u8_PIN_HIGH);
	}
		
}

/*
 * description : function disables common pin
 * parameters : struct contains port name, SSD type and enable 
 * returns : void
 */
void SSD_voidDisable (SSD_Type SSD_configure){
	if (SSD_configure.Type == COMMON_CATHODE){
		
		DIO_enumSetPinDirection (SSD_configure.EnablePort, SSD_configure.EnablePin, DIO_u8_PIN_OUTPUT);
		DIO_enumSetPinValue     (SSD_configure.EnablePort, SSD_configure.EnablePin, DIO_u8_PIN_HIGH);
	}
	
	else if (SSD_configure.Type == COMMON_ANODE){
		
		DIO_enumSetPinDirection (SSD_configure.EnablePort, SSD_configure.EnablePin, DIO_u8_PIN_OUTPUT);
		DIO_enumSetPinValue     (SSD_configure.EnablePort, SSD_configure.EnablePin, DIO_u8_PIN_LOW);
	}	
	
}