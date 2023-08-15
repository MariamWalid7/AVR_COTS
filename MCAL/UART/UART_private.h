/*
 * UART_private.h
 *
 * Created: 10/1/2022 2:29:09 PM
 *  Author: maria
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

/********************** UART REGISTERS **************************/
#define UDR      (*(volatile u8 *)(0x2C))
#define UCSRA    (*(volatile u8 *)(0x2B))
#define UCSRB    (*(volatile u8 *)(0x2A))
#define UCSRC    (*(volatile u8 *)(0x40))
#define UBRRH    (*(volatile u8 *)(0x40))
#define UBRRL    (*(volatile u8 *)(0x29))

/********************** UCSRA PINS **************************/
#define UART_RXC    7   
#define UART_TXC    6 
#define UART_UDRE   5
#define UART_FE     4 
#define UART_DOR    3 
#define UART_PE     2 
#define UART_U2X    1 
#define UART_MPCM   0
 
/********************** UCSRB PINS **************************/
#define UART_RXCIE      7
#define UART_TXCIE      6
#define UART_UDRIE      5
#define UART_RXEN       4
#define UART_TXEN       3
#define UART_UCSZ2      2
#define UART_RXB8       1
#define UART_TXB8       0

/********************** UCSRC PINS **************************/
#define UART_URSEL       7
#define UART_UMSEL       6
#define UART_UPM1        5
#define UART_UPM0        4
#define UART_USBS        3
#define UART_UCSZ1       2
#define UART_UCSZ0       1


/********************** CONFIGURATIONS **************************/

#define UART_BAUDRATE_38400 38400
#define UART_BAUDRATE_19200 19200
#define UART_BAUDRATE_9600  9600
#define UART_BAUDRATE_4800  4800
#define UART_BAUDRATE_2400  2400
#define UART_BAUDRATE_1200  1200


#define UART_DISABLED       0
#define UART_ENABLED        1

#define UART_5BITS          0
#define UART_6BITS          1
#define UART_7BITS          2
#define UART_8BITS          3
#define UART_9BITS          4

#define UART_STOPBITS_1     0
#define UART_STOPBITS_2     1

#define UART_EVEN_PARITY    2
#define UART_ODD_PARITY     3
#define UART_NO_PARITY      0

#endif /* UART_PRIVATE_H_ */