
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "LED.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "util/delay.h"
#include "../../MCAL/TIMER/timer.h"



void LED_voidInit(u8 Port, u8 Pin){
	DIO_voidSetPinDirection(Port,Pin,DIO_OUTPUT);
}
void LED_voidON(u8 Port, u8 Pin){
	DIO_voidSetPinValue(Port,Pin,DIO_HIGH);
}


void LED_voidOFF(u8 Port, u8 Pin){
	DIO_voidSetPinValue(Port,Pin,DIO_LOW);
}

void LED_voidTOG(u8 Port, u8 Pin){
	DIO_voidTogPinValue(Port,Pin);
}
/*void LED_voidBLINK(u8 Port, u8 Pin){
	u8 Counter=0;
	while(Counter <= 10){
	DIO_voidSetPinValue(Port,Pin,DIO_HIGH);
	TIMER_delay(1500);
	DIO_voidSetPinValue(Port,Pin,DIO_LOW);
	TIMER_delay(1500);
	Counter++;
	}
}*/




