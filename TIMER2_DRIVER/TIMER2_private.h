/*
 * TIMER2_private.h
 *
 *  Created on: Sep 11, 2023
 *      Author: user
 */

#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_

#define NORMAL_MODE 0
#define PHASE_CORRECT_PWM_MODE 1
#define CTC_MODE 2
#define FAST_PWM_MODE 3

#define DISCONNECTED 0
#define TOGGLE 1
#define CLEAR 2
#define SET 3

#define CLEAR_ON_COMPARE 2
#define SET_ON_COMPARE 3

#define NO_CLK    0
#define NO_PRES   1
#define PRES_8    2
#define PRES_32   3
#define PRES_64   4
#define PRES_128  5
#define PRES_256  6
#define PRES_1024 7


#endif /* TIMER2_PRIVATE_H_ */
