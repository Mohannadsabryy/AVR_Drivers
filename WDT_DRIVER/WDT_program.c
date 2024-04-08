/*
 * WDT_program.c
 *
 *  Created on: Sep 8, 2023
 *      Author: user
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "WDT_register.h"
#include "WDT_private.h"
#include "WDT_config.h"
#include "WDT_interface.h"


void WDT_voidEnable(){
	SET_BIT(WDTCR,3);
}
void WDT_voidSetTime(u8 Copy_u8Val){
	WDTCR&=0b11111000;
	WDTCR|=Copy_u8Val;
}
void WDT_voidDisable(void){
	WDTCR = (1<<3) | (1<<4);
	/* Turn off WDT */
	WDTCR = 0x00;
}
void WDT_voidRefresh(u8 Copy_u8Val){
	WDT_voidDisable();
	WDT_voidEnable();
	WDT_voidSetTime(Copy_u8Val);
}
