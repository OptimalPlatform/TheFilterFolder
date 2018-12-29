/*
 * struct_filter.c
 *
 *  Created on: 26 nov. 2018
 *      Author: User
 */

//#include "stdint.h" // To get uint16_t (Could also use inttypes.h)
#include "struct_filter.h"

/*
 * A filter of the simplest form
 *
 * input:
 * 		The measured signal y and a Struct
 * Output:
 * 		A modification of the measured signal using a variable in a struct
 */
void struct_filter( struct DataTest* Data, uint16_t y)
{
	Data->test = y*0.5;
}
