/*
 * main.c
 *
 *  Created on: Sep 10, 2023
 *      Author: user
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "EXTI0_interface.h"
void Led(void);

int main(void){
	/*Test EXTI0 DRIVER*/
	/*connection the switch with pin 2 in port D and connecting led to pin0 in portA and
	 when the switch is opened the interrupt occured and the led turned on.*/
	DIO_voidSetPinDir(DIO_u8PORTD,2,DIO_u8INPUT);
	DIO_voidSetPinValue(DIO_u8PORTD,2,DIO_u8HIGH);
	DIO_voidSetPinDir(DIO_u8PORTA,0,DIO_u8OUTPUT);
	GIE_voidEnable();
	EXTI0_voidInit();
	EXTI0_voidSetCallBack(Led);
	while(1){

	}
}
void Led(void){
	DIO_voidSetPinValue(DIO_u8PORTA,0,DIO_u8HIGH);
}
