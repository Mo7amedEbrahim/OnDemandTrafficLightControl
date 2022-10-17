/*
 * timer.c
 *
 *  Created on: Sep 30, 2022
 *      Author: Mohammed
 */

#include "timer.h"
#include "registers.h"
#include <math.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

void TIMER_init(){
	TCCR0 = 0x00; //normal mode
}
void TIMER_delay(u16 millisec){
	u16 Noverflows,TimerInitial;
	double Tmaxdelay,Ttick;
	u32 overFlowcnt=0;
	//max delay 256 micro second
	//at 1MHz no prescaler
	// 256 prescaler
	Ttick = 256.0/8000.0; //ms    Ttick = Presc/FCPU
	Tmaxdelay= 65.536; //ms		Tmaxdelay = Ttick * 2^8
	if(millisec<Tmaxdelay){
		TimerInitial = (Tmaxdelay-millisec)/Ttick;
		Noverflows = 1;

	}else if(millisec == (int)Tmaxdelay){
		TimerInitial=0;
		Noverflows=1;
	}else{
		Noverflows = ceil((double)millisec/Tmaxdelay);
		TimerInitial = (1<<8) - ((double)millisec/Ttick)/Noverflows;

	}
	TCNT0 = TimerInitial;
	TCCR0 |= (1<<2); //set 256 prescaler
	while(overFlowcnt<Noverflows){
		//busy wait
		while(GET_BIT(TIFR,0)==0);
		//clear overflow flag
		SET_BIT(TIFR,0);
		//increment counter
		overFlowcnt++;
	}
	//Timer stop
	TCCR0 = 0x00;
}
