/*************************LAYER: MCAL**********************************/
/*************************Version: 1.0*********************************/
/*************************AUTHOR: Mohammed Gaafar**********************/
/*************************Name : EXTI_program***************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "EXTI_register.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"

static void (*INT0_Fptr) (void) = NULLPTR;
static void (*INT1_Fptr) (void) = NULLPTR;
static void (*INT2_Fptr) (void) = NULLPTR;


void EXTI_voidINT0Init(u8 Local_u8Sense){
				/*		Set the sense control		*/
	switch (Local_u8Sense){
		case LOW_LEVEL:
		CLR_BIT(MCUCR,MCUCR_IS00);
		CLR_BIT(MCUCR,MCUCR_IS01);
		break;
		
		case ON_CHANGE:
		SET_BIT(MCUCR,MCUCR_IS00);
		CLR_BIT(MCUCR,MCUCR_IS01);
		break;
		
		case FALLING_EDGE:
		CLR_BIT(MCUCR,MCUCR_IS00);
		SET_BIT(MCUCR,MCUCR_IS01);
		break;
		
		case RISING_EDGE:
		SET_BIT(MCUCR,MCUCR_IS00);
		SET_BIT(MCUCR,MCUCR_IS01);
		break;
	}
	
	/*Peripheral Interrupt Enable*/
	SET_BIT(GICR,GICR_INT0);
}

void EXTI_voidINT1Init(u8 Local_u8Sense){
	/*		Set the sense control		*/
	switch (Local_u8Sense){
		case LOW_LEVEL:
		CLR_BIT(MCUCR,MCUCR_IS10);
		CLR_BIT(MCUCR,MCUCR_IS11);
		break;
		
		case ON_CHANGE:
		SET_BIT(MCUCR,MCUCR_IS10);
		CLR_BIT(MCUCR,MCUCR_IS11);
		break;
		
		case FALLING_EDGE:
		CLR_BIT(MCUCR,MCUCR_IS10);
		SET_BIT(MCUCR,MCUCR_IS11);
		break;
		
		case RISING_EDGE:
		SET_BIT(MCUCR,MCUCR_IS10);
		SET_BIT(MCUCR,MCUCR_IS11);
		break;
	}
	
	/*Peripheral Interrupt Enable*/
	SET_BIT(GICR,GICR_INT1);
}

void EXTI_voidINT2Init(u8 Local_u8Sense){
	/*		Set the sense control		*/
	switch (Local_u8Sense){
		case FALLING_EDGE:
		CLR_BIT(MCUCSR,MCUCSR_ISC2);
		break;
		
		case RISING_EDGE:
		SET_BIT(MCUCSR,MCUCSR_ISC2);
		break;
	}
	/*Peripheral Interrupt Enable*/
	SET_BIT(GICR,GICR_INT2);
}

void EXTI_voidSetCallBackINT0( void(*LocalPtr)(void) ){
	INT0_Fptr = LocalPtr;
}

void EXTI_voidSetCallBackINT1( void(*LocalPtr)(void) ){
	INT1_Fptr = LocalPtr;
}

void EXTI_voidSetCallBackINT2( void(*LocalPtr)(void) ){
	INT2_Fptr = LocalPtr;
}


ISR(__vector_1)
{
	INT0_Fptr();
}
ISR(__vector_2)
{
	INT1_Fptr();
}
ISR(__vector_3)
{
	INT2_Fptr();
}
