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
#include "DC_MOTOR_interface.h"


int main(void){
	/*Test of Dc Motor Driver*/
	DIO_voidSetPortDir(DIO_u8PORTA,0b00000011);
	while(1){
		DC_MOTOR_RotateCW();
		_delay_ms(1000);
		DC_MOTOR_Stop();
		_delay_ms(1000);
		DC_MOTOR_RotateCCW();
		_delay_ms(1000);
		DC_MOTOR_Stop();
		_delay_ms(1000);
	}
}
