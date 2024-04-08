/*
 * GIE_program.c
 *
 *  Created on: Aug 28, 2023
 *      Author: user
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_interface.h"
#include "GIE_register.h"

void GIE_voidEnable(void){
	SET_BIT(SREG,7);
}

void GIE_voidDisable(void){
	ClR_BIT(SREG,7);
}
