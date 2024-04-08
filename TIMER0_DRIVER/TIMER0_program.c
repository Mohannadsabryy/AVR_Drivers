/*
 * TIMER0_program.c
 *
 *  Created on: Sep 8, 2023
 *      Author: user
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER0_register.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"
#include "TIMER0_interface.h"

void (*TIMER0_CallBack)(void);


void TIMER0_voidInit(void){
	/*WGM Wave Generation Mode*/
	#if(MODE==NORMAL)
		ClR_BIT(TCCR0,3);
		ClR_BIT(TCCR0,6);
	#elif(MODE==PWM_PHASECORRECT)
		SET_BIT(TCCR0,6);
		ClR_BIT(TCCR0,3);
	#elif(MODE==CTC)
		SET_BIT(TCCR0,3);
		ClR_BIT(TCCR0,6);
	#elif(MODE==FAST_PWM)
		SET_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
	#endif

	/*Compare Match Output Mode*/

	#if(MODE==CTC || MODE==NORMAL)
		#if(Compare_Match_Output_Mode==DISCONNECTED)
				ClR_BIT(TCCR0,4);
				ClR_BIT(TCCR0,5);
		#elif(Compare_Match_Output_Mode==TOGGLE)
			    SET_BIT(TCCR0,4);
			    ClR_BIT(TCCR0,5);
		#elif(Compare_Match_Output_Mode==CLEAR)
			    SET_BIT(TCCR0,5);
			    ClR_BIT(TCCR0,4);
		#elif(Compare_Match_Output_Mode==SET)
			    SET_BIT(TCCR0,5);
			    SET_BIT(TCCR0,4);
		#endif
	#elif(MODE==FAST_PWM || MODE==PWM_PHASECORRECT)
		#if(Compare_Match_Output_Mode==DISCONNECTED)
			    ClR_BIT(TCCR0,4);
			    ClR_BIT(TCCR0,5);
		#elif(Compare_Match_Output_Mode==CLEAR_ON_COMPARE)
			    SET_BIT(TCCR0,5);
			    ClR_BIT(TCCR0,4);
		#elif(Compare_Match_Output_Mode==SET_ON_COMPARE)
			    SET_BIT(TCCR0,5);
			    SET_BIT(TCCR0,4);
		#endif
	#endif

	/*Prescaler*/
	#if(CLK==NO_CLK)
		ClR_BIT(TCCR0,2);
		ClR_BIT(TCCR0,1);
		ClR_BIT(TCCR0,0);
	#elif(CLK==CLK_N0PRES)
		SET_BIT(TCCR0,0);
		ClR_BIT(TCCR0,1);
		ClR_BIT(TCCR0,2);
	#elif(CLK==CLK_8)
		ClR_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		ClR_BIT(TCCR0,2);
	#elif(CLK==CLK_64)
		SET_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		ClR_BIT(TCCR0,2);
	#elif(CLK==CLK_256)
		ClR_BIT(TCCR0,0);
		ClR_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
	#elif(CLK==CLK_1024)
		SET_BIT(TCCR0,0);
		ClR_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
	#elif(CLK==ECLK_FALLING)
		ClR_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
	#elif(CLK==ECLK_RISING)
		SET_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
	#endif

	/*Interrupt enable*/
	#if(MODE==CTC)
		SET_BIT(TIMSK,1);
	#elif(MODE==NORMAL)
		SET_BIT(TIMSK,0);
	#endif
}
void TIMER0_voidSetCallBack(void (*Copy_pvCallBack)(void)){
	TIMER0_CallBack=Copy_pvCallBack;
}
#if(MODE==CTC)
	void __vector_10(void) __attribute__((signal));
	void __vector_10(void){
		TIMER0_CallBack();
	}
#elif(MODE==NORMAL)
	void __vector_11(void) __attribute__((signal));
	void __vector_11(void){
		TIMER0_CallBack();
	}
#endif
void TIMER0_SETOCR(u8 Copy_u8Val){
	OCR0=Copy_u8Val;
}
void TIMER0_SETTCNT(u8 Copy_u8Val){
	TCNT0=Copy_u8Val;
}
