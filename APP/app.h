/*
 * app.h
 *
 *  Created on: Oct 3, 2022
 *      Author: Mohammed
 */

#ifndef APP_APP_H_
#define APP_APP_H_

#include "../MCAL/DIO/DIO_interface.h"
enum Traffic_Mode{
	Cars_Mode,
	Pedestrians_Mode
};
void Pedestrians(void);
enum PORTS{
	Cars_Port = DIO_PORTA,
	Pedestrians_Port = DIO_PORTB
};
enum LEDS{
	GREEN_LED = DIO_PIN0,
	YELLOW_LED = DIO_PIN1,
	RED_LED = DIO_PIN2
};

/*************************************/
/***********INPUT: void***************/
/***********OUTPUT: void**************/
/******Description: Initializing******/
/*************************************/

void APP_Init(void);


/*************************************/
/***********INPUT: void***************/
/***********OUTPUT: void**************/
/********Description: Starting********/
/*************************************/
void APP_Start(void);




/*************************************/
/***********INPUT: void***************/
/***********OUTPUT: void**************/
/********Description: Interrupt*******/
/*************************************/
void Pedestrians(void);

#endif /* APP_APP_H_ */
