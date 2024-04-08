/*
 * TIMER0_interface.h
 *
 *  Created on: Sep 8, 2023
 *      Author: user
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

void TIMER0_voidInit(void);
void TIMER0_voidSetCallBack(void (*Copy_pvCallBack)(void));
void TIMER0_SETOCR(u8 Copy_u8Val);
void TIMER0_SETTCNT(u8 Copy_u8Val);

#endif /* TIMER0_INTERFACE_H_ */
