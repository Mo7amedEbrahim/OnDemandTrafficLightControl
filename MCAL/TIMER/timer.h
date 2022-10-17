/*
 * timer.h
 *
 *  Created on: Sep 30, 2022
 *      Author: Mohammed
 */

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_
#include "registers.h"
#include "../../LIB/STD_TYPES.h"

/*************************************/
/*************INPUT:void**************/
/***********OUTPUT: void**************/
/******Description:Initiat Timer******/
/*************************************/
void TIMER_init();//initialize Timer0

/*************************************/
/*************INPUT:void**************/
/***********OUTPUT: void**************/
/******Description:Timer Delay******/
/*************************************/
void TIMER_delay(u16 millisec); //delay of specific amount default uses 256 prescalar



#endif /* MCAL_TIMER_TIMER_H_ */
