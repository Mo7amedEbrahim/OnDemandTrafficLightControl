#ifndef	_LED_H
#define	_LED_H



#include "../../LIB/STD_TYPES.h"
/*************************************/
/***********INPUT: void***************/
/***********OUTPUT: void**************/
/********Description: Initializing*******/
/*************************************/
void LED_voidInit(u8 Port, u8 Pin);

/*************************************/
/***********INPUT: void***************/
/***********OUTPUT: void**************/
/********Description: Turn led ON*******/
/*************************************/
void LED_voidON(u8 Port, u8 Pin);

/*************************************/
/***********INPUT: void***************/
/***********OUTPUT: void**************/
/********Description: Turn led OFF*******/
/*************************************/
void LED_voidOFF(u8 Port, u8 Pin);


/*************************************/
/***********INPUT: void***************/
/***********OUTPUT: void**************/
/********Description: tog led*******/
/*************************************/
void LED_voidTOG(u8 Port, u8 Pin);
//void LED_voidBLINK(u8 Port, u8 Pin);




#endif
