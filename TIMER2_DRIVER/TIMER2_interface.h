/*
 * TIMER2_interface.h
 *
 *  Created on: Sep 11, 2023
 *      Author: user
 */

#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

void TIMER2_voidInit(void);
void TIMER2_voidSetOCR2Val(u8 copy_u8OCR);
void TIMER2_voidSetTCNT2Val(u8 copy_u8TCNT);
void TIMER2_voidSetCallBack(void (*Copy_pvCallBack)(void));

#endif /* TIMER2_INTERFACE_H_ */
