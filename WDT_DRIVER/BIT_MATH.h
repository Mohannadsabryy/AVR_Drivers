/*
 * BIT_MATH.h
 *
 *  Created on: Aug 14, 2023
 *      Author: user
 */
//dah general file
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(var,bit_num) var|=1<<bit_num
#define ClR_BIT(var,bit_num) var&=(~(1<<bit_num))
#define TOGGLE_BIT(var,bit_num) var^=(1<<bit_num)
//hena mesh ha7otha goa variable 3ashen mesh 3ayz a8yar el kema bet3tha ana 3yz ageeb el value bas
#define GET_BIT(var,bit_num) ((var>>bit_num)&1)
#endif /* BIT_MATH_H_ */
