/*
 * main.c
 *
 *  Created on: Sep 9, 2023
 *      Author: Mohannad
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/delay.h>
#include "DIO_interface.h"


int main(void){
	/*use the driver here*/
	DIO_voidSetPinDir(DIO_u8PORTA,A0,DIO_u8OUTPUT);
	while(1){
		DIO_voidSetPinValue(DIO_u8PORTA,A0,DIO_u8HIGH);
		_delay_ms(1000);
		DIO_voidSetPinValue(DIO_u8PORTA,A0,DIO_u8LOW);
		_delay_ms(1000);
	}
}
