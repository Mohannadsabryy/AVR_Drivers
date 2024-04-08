/*
 * EXTI0_interface.h
 *
 *  Created on: Sep 10, 2023
 *      Author: user
 */

#ifndef EXTI0_INTERFACE_H_
#define EXTI0_INTERFACE_H_

#define LOW_LEVEL 0
#define ANY_CHANGE 1
#define FALLING_EDGE 2
#define RISING_EDGE 3

void EXTI0_voidInit(void);
void EXTI0_voidSenseControl(u8 Copy_u8SenseVal);
void EXTI0_voidSetCallBack(void (*Copy_pvCallBack)(void));

#endif /* EXTI0_INTERFACE_H_ */
