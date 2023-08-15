/*
 * SPI_private.h
 *
 * Created: 4/24/2023 12:52:19 AM
 *  Author: maria
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPDR (*(volatile u8 *)(0x2F))  
#define SPSR (*(volatile u8 *)(0x2E))  
#define SPCR (*(volatile u8 *)(0x2D))

#define SPCR_SPIE   7
#define SPCR_SPE    6
#define SPCR_DORD   5
#define SPCR_MSTR   4
#define SPCR_CPOL   3
#define SPCR_CPHA   2
#define SPCR_SPR1   1
#define SPCR_SPR0   0



#endif /* SPI_PRIVATE_H_ */