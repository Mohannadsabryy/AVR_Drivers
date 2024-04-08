/*
 * ADC_program.c
 *
 *  Created on: Sep 10, 2023
 *      Author: user
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_register.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_interface.h"




void ADC_voidInit(void){
	/*Select VREF Mode*/
	#if(VREF==AREF)
		CLR_BIT(ADMUX,7);
		CLR_BIT(ADMUX,6);
	#elif(VREF==AVCC)
		SET_BIT(ADMUX,6);
		CLR_BIT(ADMUX,7);
	#elif(VREF==INTERNAL_VOLTAGE)
		SET_BIT(ADMUX,6);
		SET_BIT(ADMUX,7);
	#endif

	/*Prescaler-Bits*/
	#if(ADC_PRESCALER==PRES_2)
		CLR_BIT(ADCSRA,2);
		CLR_BIT(ADCSRA,1);
		CLR_BIT(ADCSRA,0);
	#elif(ADC_PRESCALER==PRES_2I)
		CLR_BIT(ADCSRA,2);
		CLR_BIT(ADCSRA,1);
		SET_BIT(ADCSRA,0);
	#elif(ADC_PRESCALER==PRES_4)
		CLR_BIT(ADCSRA,2);
		SET_BIT(ADCSRA,1);
		CLR_BIT(ADCSRA,0);
	#elif(ADC_PRESCALER==PRES_8)
		CLR_BIT(ADCSRA,2);
		SET_BIT(ADCSRA,1);
		SET_BIT(ADCSRA,0);
	#elif(ADC_PRESCALER==PRES_16)
		SET_BIT(ADCSRA,2);
		CLR_BIT(ADCSRA,1);
		CLR_BIT(ADCSRA,0);
	#elif(ADC_PRESCALER==PRES_32)
		SET_BIT(ADCSRA,2);
		CLR_BIT(ADCSRA,1);
		SET_BIT(ADCSRA,0);
	#elif(ADC_PRESCALER==PRES_64)
		SET_BIT(ADCSRA,2);
		SET_BIT(ADCSRA,1);
		CLR_BIT(ADCSRA,0);
	#elif(ADC_PRESCALER==PRES_128)
		SET_BIT(ADCSRA,2);
		SET_BIT(ADCSRA,1);
		SET_BIT(ADCSRA,0);
	#endif

	/*ADC ENABLE BIT*/
	SET_BIT(ADCSRA,7);

	/*Interupt enable*/
	#if(METHOD==INTERUTPT)
		SET_BIT(ADCSRA,3);
	#elif(METHOD==POLLING)
		CLR_BIT(ADCSRA,3);
	#endif
}
u16 ADC_voidStartConversion(u8 Copy_u8Channel){
	ADMUX&=0b11110000;
	ADMUX|=Copy_u8Channel;
	/*start-conversion method*/
	#if(CONVERSION_METHOD==ADC_START_CONVERSION_METHOD)
		SET_BIT(ADCSRA,6);
	#elif(CONVERSION_METHOD==ADC_AUTO_TRIGGER_METHOD)
		SET_BIT(ADCSRA,5);
	#endif

	while(GET_BIT(ADCSRA,4)==0){
		asm("NOP");
	}
	SET_BIT(ADCSRA,4);
	return ADC;
}
