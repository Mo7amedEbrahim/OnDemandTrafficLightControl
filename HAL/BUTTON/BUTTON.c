#include "../../LIB/STD_TYPES.h"

#include "BUTTON.h"
#include "../../MCAL/DIO/DIO_interface.h"

u8 BUTTON_u8GetValue(u8 Port, u8 Pin){
	u8 Value;
	DIO_voidSetPinDirection(Port,Pin,DIO_INPUT);
	DIO_voidSetPinValue(Port,Pin,DIO_HIGH);//PULLED UP
	Value=  DIO_u8GetPinValue(Port,Pin);
	return Value;
}
