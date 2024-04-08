/*
 * DIO_interface.h
 *
 *  Created on: Sep 9, 2023
 *      Author: Mohannad
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_u8PORTA 0
#define DIO_u8PORTB 1
#define DIO_u8PORTC 2
#define DIO_u8PORTD 3

#define DIO_u8INPUT 0
#define DIO_u8OUTPUT 1

#define DIO_u8LOW 0
#define DIO_u8HIGH 1

#define A0 0
#define A1 1
#define A2 2
#define A3 3
#define A4 4
#define A5 5
#define A6 6
#define A7 7

#define B0 0
#define B1 1
#define B2 2
#define B3 3
#define B4 4
#define B5 5
#define B6 6
#define B7 7

#define C0 0
#define C1 1
#define C2 2
#define C3 3
#define C4 4
#define C5 5
#define C6 6
#define C7 7

#define D0 0
#define D1 1
#define D2 2
#define D3 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7

void DIO_voidSetPinDir(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Dir);
void DIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value);
void DIO_voidSetPortDir(u8 Copy_u8Port,u8 Copy_u8Dir);
void DIO_voidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value);
u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin);


#endif /* DIO_INTERFACE_H_ */
