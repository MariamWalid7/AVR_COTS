/*
 * ***************************************** DIO_interface.h *****************************************
 *
 * Created: 8/4/2022 1:47:36 AM
 *  Author: maria
 *  Layer: MCAL
 */

//for user
//all defines
//prototypes of functions

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_u8_PORTA 0
#define DIO_u8_PORTB 1
#define DIO_u8_PORTC 2
#define DIO_u8_PORTD 3

#define DIO_u8_PIN0  0
#define DIO_u8_PIN1  1
#define DIO_u8_PIN2  2
#define DIO_u8_PIN3  3
#define DIO_u8_PIN4  4
#define DIO_u8_PIN5  5
#define DIO_u8_PIN6  6
#define DIO_u8_PIN7  7

#define DIO_u8_PIN_OUTPUT 1
#define DIO_u8_PIN_INPUT  0

#define DIO_u8_PIN_HIGH 1
#define DIO_u8_PIN_LOW  0

#define DIO_u8_PORT_OUTPUT  1
#define DIO_u8_PORT_INPUT   0

#define DIO_u8_PORT_HIGH  1
#define DIO_u8_PORT_LOW   0

void DIO_voidSetPinDirection(u8 copy_u8PortName, u8 copy_u8PinNumber, u8 copy_u8Direction);
void DIO_SetPinValue (u8 copy_u8PortName, u8 copy_u8PinNumber, u8 Copy_u8Value);
u8 DIO_u8GetPinvalue(u8 copy_u8PortName, u8 copy_u8PinNumber);
void DIO_voidTogglePin(u8 copy_u8PortName, u8 copy_u8PinNumber);

void DIO_voidSetPortDirection(u8 copy_u8PortName,u8 copy_u8Direction);
void DIO_voidSetPortValue (u8 copy_u8PortName,u8 copy_u8Value);
u8 DIO_u8GetPortvalue(u8 Copy_u8PortName);

void DIO_voidConnectPullup (u8 copy_u8PortName,u8 copy_u8PinNumber, u8 copy_u8Enable);

#endif /* DIO_INTERFACE_H_ */
