/*
 * TIMER0_private.h
 *
 *  Created on: Sep 8, 2023
 *      Author: user
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define NORMAL 0
#define PWM_PHASECORRECT 1
#define CTC 2
#define FAST_PWM 3
#define DISCONNECTED 0
#define TOGGLE 1
#define CLEAR 2
#define SET 3
#define CLEAR_ON_COMPARE 2
#define SET_ON_COMPARE 3
#define NO_CLK 0
#define CLK_N0PRES 1 // no prescaler
#define CLK_8 2 //prescaler 8
#define CLK_64 3 //prescaler 64
#define CLK_256 4 //prescaler 256
#define CLK_1024 5 //prescaler 1024
#define ECLK_FALLING 6 //ECLK(External) clk on falling edge
#define ECLK_RISING 7 //External clk on rising edge

#endif /* TIMER0_PRIVATE_H_ */
