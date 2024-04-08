/*
 * CLCD_config.h
 *
 *  Created on: Sep 9, 2023
 *      Author: user
 */

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

#define CTRL_PORT DIO_u8PORTC
#define DATA_PORT DIO_u8PORTA
#define RS_PIN 0
#define RW_PIN 1
#define E_PIN 2

#define N_LINES TWO_LINE_DISPLAY
#define DOT_CH_FONT FIVE_SEVEN_MODE
#define DISPLAY DISPLAY_ON
#define CURSOR BLINK_OFF
#define BLINK BLINK_OFF

#endif /* CLCD_CONFIG_H_ */
