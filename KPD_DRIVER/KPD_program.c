/*
 * KPD_program.c
 *
 *  Created on: Sep 10, 2023
 *      Author: user
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/delay.h>
#include "DIO_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"
#include "KPD_interface.h"



u8 KPD_u8GetKeyPressed(void){
	u8 keys[4][4]={{BTN_ONE,BTN_TWO,BTN_THREE,BTN_FOUR},{BTN_FIVE,BTN_SIX,BTN_SEVEN,BTN_EIGHT},{BTN_NINE,BTN_TEN,BTN_ELEVEN,BTN_TWELVE},{BTN_THIRTEEN,BTN_FOURTEEN,BTN_FIFTEEN,BTN_SIXTEEN}};
	u8 key_pressed=0xff;
	u8 is_found=0;
	for(u8 col=0;col<4;col++){
		DIO_voidSetPinValue(KPD_PORT,col,DIO_u8LOW);
		for(u8 row=0;row<4;row++){
			if(DIO_u8GetPinValue(KPD_PORT,row+4)==0){
				key_pressed=keys[row][col];
				is_found=1;
				_delay_ms(2);
				while(DIO_u8GetPinValue(KPD_PORT,row+4)==0){
				}
			}
		}
		DIO_voidSetPinValue(KPD_PORT,col,DIO_u8HIGH);
		if(is_found==1){
			return key_pressed;
		}
	}
	return key_pressed;

}
