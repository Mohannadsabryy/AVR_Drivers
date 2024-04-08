/*
 * DC_MOTOR_program.c
 *
 *  Created on: Sep 10, 2023
 *      Author: user
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "DC_MOTOR_private.h"
#include "DC_MOTOR_config.h"
#include "DC_MOTOR_interface.h"


void DC_MOTOR_RotateCCW(void){
	DIO_voidSetPinValue(DC_MOTOR_PORT,DC_PIN1,DIO_u8LOW);
	DIO_voidSetPinValue(DC_MOTOR_PORT,DC_PIN0,DIO_u8HIGH);
}
void DC_MOTOR_RotateCW(void){
	DIO_voidSetPinValue(DC_MOTOR_PORT,DC_PIN0,DIO_u8LOW);
	DIO_voidSetPinValue(DC_MOTOR_PORT,DC_PIN1,DIO_u8HIGH);
}
void DC_MOTOR_Stop(void){
	DIO_voidSetPinValue(DC_MOTOR_PORT,DC_PIN0,DIO_u8LOW);
	DIO_voidSetPinValue(DC_MOTOR_PORT,DC_PIN1,DIO_u8LOW);
}
