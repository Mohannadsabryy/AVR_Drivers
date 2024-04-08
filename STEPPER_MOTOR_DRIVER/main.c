/*
 * main.c
 *
 *  Created on: Sep 10, 2023
 *      Author: user
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <avr/delay.h>

#include "DIO_interface.h"

#include "STEPPER_MOTOR_interface.h"


int main(void){
	/*Test for Stepper-Motor*/
	DIO_voidSetPortDir(DIO_u8PORTA,0b00001111);

	while(1){
		STEPPER_MOTOR_voidRotateCW(360);
		_delay_ms(1000);
		STEPPER_MOTOR_voidStop();
		_delay_ms(1000);
		STEPPER_MOTOR_voidRotateCCW(360);
		_delay_ms(1000);
		STEPPER_MOTOR_voidStop();
		_delay_ms(1000);
	}
}
