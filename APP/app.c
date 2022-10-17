/*
 * app.c
 *
 *  Created on: Oct 3, 2022
 *      Author: Mohammed
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LED/LED.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "app.h"


u8 Traffic_Mode;
void APP_Init(void){
	/*			CAR LEDS			*/
			LED_voidInit(Cars_Port, GREEN_LED);
			LED_voidInit(Cars_Port, YELLOW_LED);
			LED_voidInit(Cars_Port, RED_LED);

			/*			Pedestrians LEDS			*/
			LED_voidInit(Pedestrians_Port, GREEN_LED);
			LED_voidInit(Pedestrians_Port, YELLOW_LED);
			LED_voidInit(Pedestrians_Port, RED_LED);

			/*			Interrupt Init			*/
			GIE_voidEnable();
			EXTI_voidINT0Init(RISING_EDGE);
			EXTI_voidSetCallBackINT0(&Pedestrians);
			//EXTI_voidSetCallBackINT0(&TrafficMode);

			/*			Timer Init			*/
			TIMER_init();

			Traffic_Mode = Cars_Mode;
}

void APP_Start(void){
	while(1){
				u8 RedFlag=0,YellowFlag=0,GreenFlag=0;
								/*			Cars Mode			*/
				while(1){
				if ( Traffic_Mode == Cars_Mode ){			//If no interrupt happens
					LED_voidON(Cars_Port,GREEN_LED);		//GREEN LED ON
					GreenFlag=1;							//Rise the green flag
					TIMER_delay(15000);						//Wait before OFF
					if(Traffic_Mode == Pedestrians_Mode){	//Check the Mode
						goto jump;								//if true go to Pedestrians_Mode
					}
					LED_voidOFF(Cars_Port,GREEN_LED);		//GREEN LED OFF
					GreenFlag=0;							//Lower The Green Flag
					YellowFlag=1;							//Rise Yellow flag
					u8 Counter=0;
					while(Counter<=10){						//Blink yellow LED
						if(Traffic_Mode == Pedestrians_Mode){	//Check the Mode
							 	 	goto jump;						//if true go to Pedestrians_Mode
						}
						LED_voidON(Cars_Port,YELLOW_LED);
						TIMER_delay(750);
						LED_voidOFF(Cars_Port,YELLOW_LED);
						TIMER_delay(750);
						Counter++;
					}

					YellowFlag=0;							//Lower The Yellow Flag
					RedFlag=1;								//Rise Red Flag
					LED_voidON(Cars_Port,RED_LED);			//RED LED ON
					TIMER_delay(15000);						//Wait before OFF
					if(Traffic_Mode == Pedestrians_Mode){	//Check the Mode
						goto jump;						//if true go to Pedestrians_Mode
					}
					LED_voidOFF(Cars_Port,RED_LED);			//RED LED OFF
					RedFlag=0;								//Lower Red Flag
					}
				}
				jump:
						/*			Pedestrians Mode			*/
				if( Traffic_Mode == Pedestrians_Mode ){
					GIE_voidDisable();
					//LED_voidOFF(Cars_Port,GREEN_LED);
					//LED_voidOFF(Cars_Port,YELLOW_LED);
					//LED_voidOFF(Cars_Port,RED_LED);
					if(RedFlag == 1){
						LED_voidOFF(Pedestrians_Port,RED_LED);
						LED_voidON(Pedestrians_Port,GREEN_LED);
						LED_voidON(Cars_Port,RED_LED);
						TIMER_delay(15000);
					}
					else if((GreenFlag==1) | (YellowFlag == 1)){
						LED_voidON(Pedestrians_Port,RED_LED);
						TIMER_delay(15000);
						LED_voidOFF(Pedestrians_Port,RED_LED);
						LED_voidOFF(Cars_Port,GREEN_LED);
						u8 Counter=0;
						while(Counter<=10){
							LED_voidON(Cars_Port,YELLOW_LED);
							LED_voidON(Pedestrians_Port,YELLOW_LED);
							TIMER_delay(750);
							LED_voidOFF(Cars_Port,YELLOW_LED);
							LED_voidOFF(Pedestrians_Port,YELLOW_LED);
							TIMER_delay(750);
							Counter++;
						}
						LED_voidON(Cars_Port,RED_LED);
						LED_voidON(Pedestrians_Port,GREEN_LED);
						TIMER_delay(15000);
					}
					LED_voidOFF(Cars_Port,RED_LED);
					LED_voidOFF(Pedestrians_Port,GREEN_LED);
					u8 Counter=0;
					while(Counter<=10){
					 	LED_voidON(Cars_Port,YELLOW_LED);
					 	LED_voidON(Pedestrians_Port,YELLOW_LED);
					 	TIMER_delay(750);
					 	LED_voidOFF(Cars_Port,YELLOW_LED);
					 	LED_voidOFF(Pedestrians_Port,YELLOW_LED);
					 	TIMER_delay(750);
					 	Counter++;
					}
					LED_voidOFF(Pedestrians_Port,GREEN_LED);
					LED_voidON(Pedestrians_Port,RED_LED);
					LED_voidON(Cars_Port,GREEN_LED);
					Traffic_Mode = Cars_Mode;
					GIE_voidEnable();
				}
	}
}

void Pedestrians(void){
	Traffic_Mode = Pedestrians_Mode;
}

