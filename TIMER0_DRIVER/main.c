/*
 * main.c
 *
 *  Created on: Sep 8, 2023
 *      Author: user
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "TIMER0_interface.h"
void Toggle_Led(void);

int main(void){
	/*Test-code for fast-pwm & phase_correct pwm
		DIO_voidSetPinDir(DIO_u8PORTB,3,DIO_u8OUTPUT);
		TIMER0_voidInit();
		TIMER0_SETOCR(220); //by increasing ocr, Ton increased
	*/

	//Test code for CTC Mode,and also for Normal but without calling TIMER0_SETOCR(250)
		DIO_voidSetPinDir(DIO_u8PORTA,0,DIO_u8OUTPUT);
		GIE_voidEnable();
		TIMER0_voidInit();
		TIMER0_voidSetCallBack(Toggle_Led);
		TIMER0_SETOCR(250);

	while(1){
	}
}
void Toggle_Led(void){
	static u16 counter=0;
	static u8 result=0;
	counter++;
	while(counter==4000){
		TOGGLE_BIT(result,0);
		DIO_voidSetPinValue(DIO_u8PORTA,0,result);
		counter=0;
	}
}
