/*************************LAYER: MCAL**********************************/
/*************************Version: 1.0*********************************/
/*************************AUTHOR: Mohammed Gaafar**********************/
/*************************Name : EXTI_private***************************/
#ifndef _EXTI_PRIVATE_H
#define	_EXTI_PRIVATE_H



#define NULLPTR ((void*) 0)


#define ISR(__vector_num)                                                      \
    void __vector_num(void) __attribute__((signal, used, externally_visible)); \
    void __vector_num(void)









#endif
