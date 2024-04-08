/*
 * GIE_program.c
 *
 *  Created on: Sep 9, 2023
 *      Author: user
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_register.h"
#include "GIE_private.h"
#include "GIE_config.h"
#include "GIE_interface.h"


void GIE_voidEnable(void){
	SET_BIT(SREG,Global_Interrupt_Enable_bit);
}
void GIE_voidDisable(void){
	CLR_BIT(SREG,Global_Interrupt_Enable_bit);
}
