/*
 * ****************************** DIO_private.h ************************************
 *
 * Created: 8/4/2022 1:49:09 AM
 *  Author: maria
 *  Layer:  MCAL
 */


#ifndef DIO_REGS_H_
#define DIO_REGS_H_

//registers and addresses

/***************** GROUP A *****************/
#define PORTA *((volatile u8 *) 0x3B)
#define DDRA  *((volatile u8 *) 0x3A)
#define PINA  *((volatile u8 *) 0x39)

/***************** GROUP B *****************/
#define PORTB *((volatile u8 *) 0x38)
#define DDRB  *((volatile u8 *) 0x37)
#define PINB  *((volatile u8 *) 0x36)

/***************** GROUP C *****************/
#define PORTC *((volatile u8 *) 0x35)
#define DDRC  *((volatile u8 *) 0x34)
#define PINC  *((volatile u8 *) 0x33)

/***************** GROUP D *****************/
#define PORTD *((volatile u8 *) 0x32)
#define DDRD  *((volatile u8 *) 0x31)
#define PIND  *((volatile u8 *) 0x30)




#endif /* DIO_REGS_H_ */
