/*
 * UART_config.h
 *
 * Created: 10/1/2022 2:28:03 PM
 *  Author: maria
 */ 


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

//Baud rate config
#define UART_BAUDRATE    UART_BAUDRATE_9600         

//Recieve enable config
#define UART_RECIEVE_ENABLE       UART_ENABLED

//send enable config
#define UART_SEND_ENABLE          UART_ENABLED

//selecting char size
#define UART_CHAR_SIZE            UART_8BITS

//recieve interrupt enable config
#define UART_RXC_INTERRUPT_ENABLE UART_DISABLED 

//send interrupt enable config
#define UART_TXC_INTERRUPT_ENABLE UART_DISABLED

//UDR empty interrupt enable config
#define UART_UDRE_INTERRUPT_ENABLE UART_DISABLED

//select stop bits no.
#define UART_STOPBITS_NO          UART_STOPBITS_1

//select parity bits mode
#define UART_PARITY_MODE          UART_EVEN_PARITY

#endif /* UART_CONFIG_H_ */