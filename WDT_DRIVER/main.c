/* * main.c
 *
 *  Created on: Sep 8, 2023
 *      Author: user
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/delay.h>
#include "DIO_interface.h"
#include "WDT_interface.h"


int main(void){
	DIO_voidSetPinDir(DIO_u8PORTA,0,DIO_u8OUTPUT);
	DIO_voidSetPinValue(DIO_u8PORTA,0,DIO_u8HIGH);
	_delay_ms(1000);
	DIO_voidSetPinValue(DIO_u8PORTA,0,DIO_u8LOW);
	WDT_voidEnable();
	WDT_voidSetTime(WDT_TIME6);

	while(1){

	}
}
