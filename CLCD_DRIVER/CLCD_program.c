/*
 * CLCD_program.c
 *
 *  Created on: Sep 9, 2023
 *      Author: user
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/delay.h>
#include "DIO_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"

void CLCD_voidInit(void){
	_delay_ms(35);
	/*Function Set*/
	#if(N_LINES==TWO_LINE_DISPLAY && DOT_CH_FONT==FIVE_SEVEN_MODE)
		CLCD_voidSendCommand(0b00111000);
	#elif(N_LINES==TWO_LINE_DISPLAY && DOT_CH_FONT==FIVE_TEN_MODE)
		CLCD_voidSendCommand(0b00111100);
	#elif(N_LINES==ONE_LINE_DISPLAY && DOT_CH_FONT==FIVE_SEVEN_MODE)
		CLCD_voidSendCommand(0b00110000);
	#elif(N_LINES==ONE_LINE_DISPLAY && DOT_CH_FONT==FIVE_TEN_MODE)
		CLCD_voidSendCommand(0b00110100);
	#endif

	/*Display On/Off Control*/
	#if(DISPLAY==DISPLAY_ON && CURSOR==CURSOR_OFF)
		CLCD_voidSendCommand(0b00001100);
	#elif(DISPLAY==DISPLAY_ON &&CURSOR==CURSOR_ON && BLINK==BLINK_OFF)
		CLCD_voidSendCommand(0b00001110);
	#elif(DISPLAY==DISPLAY_ON &&CURSOR==CURSOR_ON && BLINK==BLINK_ON)
		CLCD_voidSendCommand(0b00001111);
	#endif

	/*Display Clear*/
	CLCD_voidSendCommand(0b00000001);
}
void CLCD_voidSendData(u8 Copy_u8Data){
	DIO_voidSetPinValue(CTRL_PORT,RS_PIN,DIO_u8HIGH);
	DIO_voidSetPinValue(CTRL_PORT,RW_PIN,DIO_u8LOW);
	DIO_voidSetPortValue(DATA_PORT,Copy_u8Data);
	DIO_voidSetPinValue(CTRL_PORT,E_PIN,DIO_u8HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(CTRL_PORT,E_PIN,DIO_u8LOW);
}
void CLCD_voidSendCommand(u8 Copy_u8Command){
	DIO_voidSetPinValue(CTRL_PORT,RS_PIN,DIO_u8LOW);
	DIO_voidSetPinValue(CTRL_PORT,RW_PIN,DIO_u8LOW);
	DIO_voidSetPortValue(DATA_PORT,Copy_u8Command);
	DIO_voidSetPinValue(CTRL_PORT,E_PIN,DIO_u8HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(CTRL_PORT,E_PIN,DIO_u8LOW);
}
void CLCD_voidSendString(u8 *Copy_u8String){
	u8 counter=0;
	while(Copy_u8String[counter]!='\0'){
		CLCD_voidSendData(Copy_u8String[counter]);
		counter++;
	}
}
void CLCD_voidSetXYPosition(u8 Copy_u8XPosition,u8 Copy_u8YPosition){
	u8 local_address;
	if(Copy_u8YPosition==LINE_ONE){
		local_address=Copy_u8XPosition;
	}
	else if(Copy_u8YPosition==LINE_TWO){
		local_address=Copy_u8XPosition+0x40;
	}
	SET_BIT(local_address,7);
	CLCD_voidSendCommand(local_address);
}
void CLCD_voidSendCustomData(u8 *Copy_u8CData,u8 Copy_u8PatterNumber,u8 Copy_u8XPosition,u8 Copy_u8YPosition){
	u8 local_address;
	local_address=Copy_u8PatterNumber*8;
	SET_BIT(local_address,6);
	CLCD_voidSendCommand(local_address);
	for(u8 i=0;i<8;i++){
		CLCD_voidSendData(Copy_u8CData[i]);
	}
	CLCD_voidSetXYPosition(Copy_u8XPosition,Copy_u8YPosition);
	CLCD_voidSendData(Copy_u8PatterNumber);
}
void CLCD_voidSendCompleteNum(u16 Copy_u16Num){
	u16 num;
	u8 length=0,result;
	num=Copy_u16Num;
	while(num!=0){
		length++;
		num=num/10;
	}
	u8 ANum[length];
	for(u8 i=0;i<length;i++){
		result=Copy_u16Num%10;
		Copy_u16Num=Copy_u16Num/10;
		ANum[length -(i+1)]=result+'0';
	}
	ANum[length]='\0';
	u8 i=0;
	while(ANum[i]!='\0'){
		CLCD_voidSendData(ANum[i]);
		i++;
	}
}
