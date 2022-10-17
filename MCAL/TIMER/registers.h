/*
 * registers.h
 *
 *  Created on: Sep 30, 2022
 *      Author: Mohammed
 */

#ifndef MCAL_TIMER_REGISTERS_H_
#define MCAL_TIMER_REGISTERS_H_

#define TCCR0 	(*(volatile u8*)(0x53))
#define TCNT0 	(*(volatile u8*)(0x52))
#define TIFR 	(*(volatile u8*)(0x58))
#define TIMSK 	(*(volatile u8*)(0x59))
#define TCCR1B	*((volatile u8*)(0x4E))

#endif /* MCAL_TIMER_REGISTERS_H_ */
