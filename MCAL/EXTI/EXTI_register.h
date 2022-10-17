/*************************LAYER: MCAL**********************************/
/*************************Version: 1.0*********************************/
/*************************AUTHOR: Mohammed Gaafar**********************/
/*************************Name : EXTI_register***************************/
#ifndef _EXTI_REGISTER_H
#define	_EXTI_REGISTER_H

/******************MCU Control Register******************/
#define MCUCR					*((volatile u8 *) 0x55)
#define MCUCR_IS00				0
#define MCUCR_IS01				1
#define MCUCR_IS10				2
#define MCUCR_IS11				3



/******************MCU Control and Status Register******************/
#define	MCUCSR					*((volatile u8 *) 0x54)
#define	MCUCSR_ISC2				6



/******************General Interrupt Control Register******************/
#define GICR					*((volatile u8 *) 0x5B)
#define GICR_INT2				5
#define GICR_INT0				6
#define GICR_INT1				7



/******************General Interrupt Flag Register******************/
#define GIFR					*((volatile u8 *) 0x5A)
#define GIFR_INTF2				5
#define GIFR_INTF0				6
#define GIFR_INTF1				7






#endif