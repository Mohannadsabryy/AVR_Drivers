/*
 * main.c
 *
 *  Created on: Sep 10, 2023
 *      Author: user
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "KPD_interface.h"


int main(void){
	/*Test for the driver*/
	DIO_voidSetPortDir(DIO_u8PORTD,0b00001111);
	DIO_voidSetPortValue(DIO_u8PORTD,0b11111111);
	DIO_voidSetPortDir(DIO_u8PORTC,0b11111111);
	while(1){
		u8 key_pressed=KPD_u8GetKeyPressed();
		switch(key_pressed){
			case BTN_ONE:DIO_voidSetPortValue(DIO_u8PORTC,0b00000001);break;
			case BTN_TWO:DIO_voidSetPortValue(DIO_u8PORTC,0b00000010);break;
			case BTN_THREE:DIO_voidSetPortValue(DIO_u8PORTC,0b00000100);break;
			case BTN_FOUR:DIO_voidSetPortValue(DIO_u8PORTC,0b00001000);break;
			case BTN_FIVE:DIO_voidSetPortValue(DIO_u8PORTC,0b00010000);break;
			case BTN_SIX:DIO_voidSetPortValue(DIO_u8PORTC,0b00100000);break;
			case BTN_SEVEN:DIO_voidSetPortValue(DIO_u8PORTC,0b01000000);break;
			case BTN_EIGHT:DIO_voidSetPortValue(DIO_u8PORTC,0b10000000);break;
		}
	}
}
