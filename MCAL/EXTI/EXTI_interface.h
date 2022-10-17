/*************************LAYER: MCAL**********************************/
/*************************Version: 1.0*********************************/
/*************************AUTHOR: Mohammed Gaafar**********************/
/*************************Name : EXTI_interface***************************/
#ifndef _EXTI_INTERFACE_H
#define	_EXTI_INTERFACE_H


enum Sense_Control {
	LOW_LEVEL = 0,
	ON_CHANGE = 1,
	FALLING_EDGE = 2,
	RISING_EDGE = 3
};
/*************************************/
/************INPUT:Sense**************/
/***********OUTPUT: void**************/
/*******Description:Init INT0*********/
/*************************************/
void EXTI_voidINT0Init(u8 Local_u8Sense);

/*************************************/
/************INPUT:Sense**************/
/***********OUTPUT: void**************/
/*******Description:Init INT1*********/
/*************************************/
void EXTI_voidINT1Init(u8 Local_u8Sense);

/*************************************/
/************INPUT:Sense**************/
/***********OUTPUT: void**************/
/*******Description:Init INT2*********/
/*************************************/
void EXTI_voidINT2Init(u8 Local_u8Sense);

/*************************************/
/***********INPUT:Function************/
/***********OUTPUT: void**************/
/*****Description:Call Back INT0******/
/*************************************/
void EXTI_voidSetCallBackINT0( void(*LocalPtr)(void) );

/*************************************/
/***********INPUT:Function************/
/***********OUTPUT: void**************/
/*****Description:Call Back INT1******/
/*************************************/
void EXTI_voidSetCallBackINT1( void(*LocalPtr)(void) );

/*************************************/
/***********INPUT:Function************/
/***********OUTPUT: void**************/
/*****Description:Call Back INT2******/
/*************************************/
void EXTI_voidSetCallBackINT2( void(*LocalPtr)(void) );




#endif
