/*
 * ADC_private.h
 *
 *  Created on: Sep 10, 2023
 *      Author: user
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define AREF 0
#define AVCC 1
#define INTERNAL_VOLTAGE 3


/*both of them can take any number it is only for choosing one of them only.*/
#define ADC_START_CONVERSION_METHOD 1  /*1 stands for method 1*/
#define ADC_AUTO_TRIGGER_METHOD 2 /*2 stands for method 2*/

#define PRES_2 	 0
#define PRES_2I  1
#define PRES_4 	 2
#define PRES_8 	 3
#define PRES_16  4
#define PRES_32  5
#define PRES_64  6
#define PRES_128 7

#define POLLING 0
#define INTERUTPT 1

#endif /* ADC_PRIVATE_H_ */
