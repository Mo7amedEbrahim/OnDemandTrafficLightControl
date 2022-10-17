/*************************LAYER: MCAL**********************************/
/*************************Version: 1.0*********************************/
/*************************AUTHOR: Mohammed Gaafar**********************/
/*************************Name : DIO_register**************************/

#ifndef _DIO_REGISTER_H
#define _DIO_REGISTER_H


/*****************Port A Registers*****************/
#define PORTA_REG	*((volatile u8 *) 0x3B)				//Output mode
#define DDRA_REG	*((volatile u8 *) 0x3A)				//Output or input
#define PINA_REG	*((volatile u8 *) 0x39)				//Input mode

/*****************Port B Registers*****************/
#define PORTB_REG	*((volatile u8 *) 0x38)				//Output mode
#define DDRB_REG	*((volatile u8 *) 0x37)				//Output or input
#define PINB_REG	*((volatile u8 *) 0x36)				//Input mode

/*****************Port C Registers*****************/
#define PORTC_REG	*((volatile u8 *) 0x35)				//Output mode
#define DDRC_REG	*((volatile u8 *) 0x34)				//Output or input
#define PINC_REG	*((volatile u8 *) 0x33)				//Input mode

/*****************Port C Registers*****************/
#define PORTD_REG	*((volatile u8 *) 0x32)				//Output mode
#define DDRD_REG	*((volatile u8 *) 0x31)				//Output or input
#define PIND_REG	*((volatile u8 *) 0x30)				//Input mode











#endif