/*
 * WDT_interface.h
 *
 *  Created on: Sep 8, 2023
 *      Author: user
 */

#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

#define WDT_TIME0 0 /*16.3 ms*/
#define WDT_TIME1 1 /*32.5ms*/
#define WDT_TIME2 2 /*65ms*/
#define WDT_TIME3 3 /*0.13sec*/
#define WDT_TIME4 4 /*0.26sec*/
#define WDT_TIME5 5 /*0.52sec*/
#define WDT_TIME6 6 /*1sec*/
#define WDT_TIME7 7 /*2.1sec*/

void WDT_voidEnable(void);
void WDT_voidDisable(void);
void WDT_voidRefresh(u8 Copy_u8Val);
void WDT_voidSetTime(u8 Copy_u8Val);

#endif /* WDT_INTERFACE_H_ */
