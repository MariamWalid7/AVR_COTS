/*
 * UART_interface.h
 *
 * Created: 10/1/2022 2:28:31 PM
 *  Author: maria
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "STD_TYPES.h"


/*
 * function name : UART_voidInitialize
 * description : initialize UART
 * arguments : void
 * return : void
 */
void UART_voidInitialize (void);


/*
 * function name : UART_voidSendChar
 * description : send 1 byte over UART
 * arguments : u8 sent byte
 * return : void
 */
void UART_voidSendChar (u8 copy_u8Data);



/*
 * function name : UART_u8RecieveChar
 * description : Recieve 1 byte over UART in a desired timeout
 * arguments : void
 * return : u8 recieved byte
 */
u8 UART_u8RecieveChar (void);


/*
 * function name : UART_voidSendString
 * description : Send string over UART 
 * arguments : u8 *string
 * return : void
 */
void UART_voidSendString (u8 *copy_u8String);






#endif /* UART_INTERFACE_H_ */