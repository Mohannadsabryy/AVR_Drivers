/*
 * EXTI0_program.c
 *
 *  Created on: Sep 10, 2023
 *      Author: user
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI0_register.h"
#include "EXTI0_private.h"
#include "EXTI0_config.h"
#include "EXTI0_interface.h"
void (*EXTI0_CallBack)(void);

void EXTI0_voidInit(void){
	/*select sense control*/
	#if(SENSE_CONTROL==LOW_LEVEL)
		CLR_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
	#elif(SENSE_CONTROL==ANY_CHANGE)
		SET_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
	#elif(SENSE_CONTROL==FALLING_EDGE)
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
	#elif(SENSE_CONTROL==RISING_EDGE)
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
	#endif

	/*External Interrupt Request 0 Enable*/
	SET_BIT(GICR,6);
}
void EXTI0_voidSenseControl(u8 Copy_u8SenseVal){
		switch(Copy_u8SenseVal){
			case LOW_LEVEL: CLR_BIT(MCUCR,0);
							CLR_BIT(MCUCR,1);break;
			case ANY_CHANGE:SET_BIT(MCUCR,0);
							CLR_BIT(MCUCR,1);break;
			case FALLING_EDGE:CLR_BIT(MCUCR,0);
							  SET_BIT(MCUCR,1);break;
			case RISING_EDGE:SET_BIT(MCUCR,0);
							 SET_BIT(MCUCR,1);break;
		}
}

void EXTI0_voidSetCallBack(void (*Copy_pvCallBack)(void)){
	EXTI0_CallBack=Copy_pvCallBack;
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void){
	EXTI0_CallBack();
}
