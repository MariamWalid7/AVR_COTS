/*
 * **************************** SSD_interface.h ***************************************
 *
 * Created: 2/12/2023 9:32:10 PM
 *  Author: maria
 *  Layer: HAL
 */  


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

/* port defines */
#define SSD_PORTA  0
#define SSD_PORTB  1
#define SSD_PORTC  2
#define SSD_PORTD  3

/* pin defines */
#define SSD_PIN0   0
#define SSD_PIN1   1
#define SSD_PIN2   2
#define SSD_PIN3   3
#define SSD_PIN4   4
#define SSD_PIN5   5

/* SSD type defines */
#define COMMON_CATHODE 0
#define COMMON_ANODE   1

typedef struct{
	
	u8 Type;  //common cathode or anode
	u8 Port;
	u8 EnablePort;
	u8 EnablePin;
	
	}SSD_Type ;
	
	
/* functions prototypes */
void SSD_voidInit    (SSD_Type SSD_configure);
void SSD_voidWrite   (SSD_Type SSD_configure, u8 copy_u8Number);
void SSD_voidEnable  (SSD_Type SSD_configure);
void SSD_voidDisable (SSD_Type SSD_configure);

#endif /* SSD_INTERFACE_H_ */