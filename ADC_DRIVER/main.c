/*
 * main.c
 *
 *  Created on: Sep 10, 2023
 *      Author: user
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
int main(void){
	u16 reading;
	//Connected to potentiometer
	DIO_voidSetPinDir(DIO_u8PORTA,0,DIO_u8INPUT);
	//connected to led
	DIO_voidSetPortDir(DIO_u8PORTD,0b11111111);
	ADC_voidInit();
	while(1){
		reading=ADC_voidStartConversion(0);
		if(reading<200){
			DIO_voidSetPortValue(DIO_u8PORTD,0b00000000);
		}
		else if(reading<700){
			DIO_voidSetPortValue(DIO_u8PORTD,0b00001111);
		}
		else{
			DIO_voidSetPortValue(DIO_u8PORTD,0b11111111);
		}
	}
}
