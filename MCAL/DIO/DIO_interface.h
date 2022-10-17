/*************************LAYER: MCAL**********************************/
/*************************Version: 1.0*********************************/
/*************************AUTHOR: Mohammed Gaafar**********************/
/*************************Name : DIO_interface*************************/

#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H

#include "../../LIB/STD_TYPES.h"

//enum to represent the PORT
enum PORT {
	DIO_PORTA = 0,
	DIO_PORTB = 1,
	DIO_PORTC = 2,
	DIO_PORTD = 3
};
//enum to represent the DIRECTION
enum DIRECTION {
	DIO_INPUT = 0,
	DIO_OUTPUT = 1
};
//enum to represent the PIN
enum PIN {
	DIO_PIN0 = 0 ,
	DIO_PIN1 = 1 ,
	DIO_PIN2 = 2 ,
	DIO_PIN3 = 3 ,
	DIO_PIN4 = 4 ,
	DIO_PIN5 = 5 ,
	DIO_PIN6 = 6 ,
	DIO_PIN7 = 7 ,
};
//enum to represent the VALUE
enum VALUE {
	DIO_LOW = 0,
	DIO_HIGH = 1
};

						//Function Prototype
						//Control Pins
/*************************************/
/******INPUT:Port&Pin&Value***********/
/***********OUTPUT: void**************/
/****Description:Set Pin Direction****/
/*************************************/
void DIO_voidSetPinDirection(u8 Port ,u8 Pin ,u8 Direction);

/*************************************/
/******INPUT:Port&Pin&Value***********/
/***********OUTPUT: void**************/
/******Description:Set Pin Value******/
/*************************************/
void DIO_voidSetPinValue(u8 Port ,u8 Pin ,u8 Value);

/*************************************/
/***********INPUT: Port&Pin***********/
/***********OUTPUT: void**************/
/******Description:Tog Pin Value******/
/*************************************/
void DIO_voidTogPinValue(u8 Port ,u8 Pin);

/*************************************/
/***********INPUT: Port&Pin***********/
/*************OUTPUT: u8**************/
/******Description:Get Pin Value******/
/*************************************/
u8 DIO_u8GetPinValue(u8 Port ,u8 Pin);

						//Control PORTs
/*************************************/
/**********INPUT: Port&Direction******/
/*************OUTPUT: void************/
/****Description:Set Port Direction***/
/*************************************/
void DIO_voidSetPortDirection(u8 Port ,u8 Direction);
/*************************************/
/************INPUT: Port&Value********/
/*************OUTPUT: void************/
/******Description:Set Port Value*****/
/*************************************/
void DIO_voidSetPortValue(u8 Port ,u8 Value);












#endif
