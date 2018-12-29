/*
 * simple_filter.c
 *
 *  Created on: 22 nov. 2018
 *      Author: User
 */


#include "stdint.h" // To get uint16_t (Could also use inttypes.h)

/*
 * A filter of the simplest form
 *
 * input:
 * 		The measured signal y.
 * Output:
 * 		A modification of the measured signal.
 */
uint16_t simple_filter(	uint16_t y )
{
	//return y;
	return y-(y/2);
}
