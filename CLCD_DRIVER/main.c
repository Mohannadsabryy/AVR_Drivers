/*
 * main.c
 *
 *  Created on: Sep 9, 2023
 *      Author: user
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/delay.h>
#include "DIO_interface.h"
#include "CLCD_interface.h"


int main(void){
	/*Use the driver here*/
	DIO_voidSetPortDir(DIO_u8PORTA,0b11111111);
	DIO_voidSetPortDir(DIO_u8PORTC,0b00000111);
	CLCD_voidInit();
	//CLCD_voidSendData('1');
	/*clr command*/
	//CLCD_voidSendCommand(0b00000001);
	//CLCD_voidSendCompleteNum(4000);
	//CLCD_voidSetXYPosition(0,LINE_TWO);
	//CLCD_voidSendString("Mohannad sabry");
	//char Pattern[] = {0x00,0x00, 0x0A, 0x00, 0x11, 0x0E, 0x00, 0x00};
	//CLCD_voidSendCustomData(Pattern,0,0,LINE_TWO);
	while(1){
	}
}
