/*************************LAYER: LIB***********************************/
/*************************Version: 1.0*********************************/
/*************************AUTHOR: Mohammed Gaafar**********************/
/*************************Name : BIT_MATH******************************/

#ifndef _BIT_MATH_H
#define _BIT_MATH_H

/*Bit Math MACROS*/
#define SET_BIT( REG , BIT )	REG |= ( 1 << BIT )
#define CLR_BIT( REG , BIT )	REG &= ~( 1 << BIT )
#define GET_BIT( REG , BIT )	((REG >> BIT) & 1)
#define TOG_BIT( REG , BIT )	REG ^= ( 1 << BIT )


#endif
