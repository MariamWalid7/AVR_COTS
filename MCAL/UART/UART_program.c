/*
 * UART_program.c
 *
 * Created: 10/1/2022 2:35:06 PM
 *  Author: maria
 */ 
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "UART_config.h"
#include "UART_interface.h"
#include "UART_private.h"

#define F_CPU 8000000UL
#include <util/delay.h>

u8  UCSRC_u8_VALUE = 0;
u16 UBRR_u16_VALUE = 0;

void UART_voidInitialize (void){
	
//recieve enable configuration
SET_BIT_VALUE (UCSRB,UART_RXEN,UART_RECIEVE_ENABLE);

//send enable configuration
SET_BIT_VALUE (UCSRB,UART_TXEN,UART_SEND_ENABLE);

//selecting baud rate
UBRR_u16_VALUE = (F_CPU/(16*UART_BAUDRATE))-1;
UBRRH = (u8)(UBRR_u16_VALUE>>8);
UBRRL = (u8)UBRR_u16_VALUE;

//mode configuration
CLR_BIT (UCSRC_u8_VALUE,UART_UMSEL);


//parity mode selection
UCSRC_u8_VALUE |= (UART_PARITY_MODE<<4);

//stop bits number
SET_BIT_VALUE (UCSRC_u8_VALUE,UART_USBS,UART_STOPBITS_NO);

//configure data size
if (UART_CHAR_SIZE != UART_9BITS){
 CLR_BIT (UCSRB,UART_UCSZ2);
 if(UART_CHAR_SIZE == UART_5BITS){
 CLR_BIT (UCSRC_u8_VALUE,UART_UCSZ1);
 CLR_BIT (UCSRC_u8_VALUE,UART_UCSZ0);	 
 }
 else if(UART_CHAR_SIZE == UART_6BITS){
 CLR_BIT (UCSRC_u8_VALUE,UART_UCSZ1);
 SET_BIT (UCSRC_u8_VALUE,UART_UCSZ0);
 }	
 else if (UART_CHAR_SIZE == UART_7BITS){
 SET_BIT (UCSRC_u8_VALUE,UART_UCSZ1);
 CLR_BIT (UCSRC_u8_VALUE,UART_UCSZ0);	 
 }
 else if (UART_CHAR_SIZE == UART_8BITS){
 SET_BIT (UCSRC_u8_VALUE,UART_UCSZ1);
 SET_BIT (UCSRC_u8_VALUE,UART_UCSZ0);
  }
}

else{
SET_BIT (UCSRB,UART_UCSZ2);

 if(UART_CHAR_SIZE == UART_5BITS){
	 CLR_BIT (UCSRC_u8_VALUE,UART_UCSZ1);
	 CLR_BIT (UCSRC_u8_VALUE,UART_UCSZ0);
 }
 else if(UART_CHAR_SIZE == UART_6BITS){
	 CLR_BIT (UCSRC_u8_VALUE,UART_UCSZ1);
	 SET_BIT (UCSRC_u8_VALUE,UART_UCSZ0);
 }
 else if (UART_CHAR_SIZE == UART_7BITS){
	 SET_BIT (UCSRC_u8_VALUE,UART_UCSZ1);
	 CLR_BIT (UCSRC_u8_VALUE,UART_UCSZ0);
 }
 else if (UART_CHAR_SIZE == UART_8BITS){
	 SET_BIT (UCSRC_u8_VALUE,UART_UCSZ1);
	 SET_BIT (UCSRC_u8_VALUE,UART_UCSZ0);
 }	
} 

//accessing UCSRC register
SET_BIT (UCSRC_u8_VALUE,7);    //setting UMSEL  
UCSRC = UCSRC_u8_VALUE;
} //end of initialization function


void UART_voidSendChar (u8 copy_u8Data){
	
//wait until UDR TX buffer is empty
while (GET_BIT(UCSRA,UART_UDRE)==0);

//put data to be transmitted in UDR TX buffer
UDR = copy_u8Data;
	
} //end of send char function


u8 UART_u8RecieveChar (void){

//wait until receiving is complete
while (GET_BIT(UCSRA,UART_RXC)==1); 	

//get recieved data from UDR RX buffer
return UDR;	
	
} //end of recieve char 

void UART_voidSendString (u8 *copy_u8String){

while (*copy_u8String != '/0'){

UART_voidSendChar (*copy_u8String);

copy_u8String++;

_delay_ms(100);
} //end of while loop
} // end of send string function

