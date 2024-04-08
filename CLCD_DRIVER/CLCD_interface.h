/*
 * CLCD_interface.h
 *
 *  Created on: Sep 9, 2023
 *      Author: user
 */

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

#define LINE_ONE 0
#define LINE_TWO 1

void CLCD_voidInit(void);
void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidSendCommand(u8 Copy_u8Command);
void CLCD_voidSendString(u8 *Copy_u8String);
void CLCD_voidSendCustomData(u8 *Copy_u8CData,u8 Copy_u8PatterNumber,u8 Copy_u8XPosition,u8 Copy_u8YPosition);
void CLCD_voidSendCompleteNum(u16 Copy_u16Num);
void CLCD_voidSetXYPosition(u8 Copy_u8XPosition,u8 Copy_u8YPosition);

#endif /* CLCD_INTERFACE_H_ */
