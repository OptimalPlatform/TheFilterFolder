/*
 * struct_filter.h
 *
 *  Created on: 26 nov. 2018
 *      Author: User
 */

#ifndef STRUCT_FILTER_H_
#define STRUCT_FILTER_H_

#include "stdint.h" // To get uint16_t (Could also use inttypes.h)

struct DataTest {
	uint16_t test;
};

void struct_filter( struct DataTest* Data, uint16_t y);

#endif /* STRUCT_FILTER_H_ */
