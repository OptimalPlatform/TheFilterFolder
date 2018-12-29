/*
 * kalman_filter_int.h
 *
 *  Created on: 4 dec. 2018
 *      Author: User
 */

#ifndef KALMAN_FILTER_INT_H_
#define KALMAN_FILTER_INT_H_

#include "stdint.h" // To get uint32_t. How come I dont need this in Experimentation2?


struct Data1D_int {
	// Dynamic variables
	int32_t x_est;
	int32_t x_pred;
	int32_t MSE_pred;
	// Fixed variables (For now)
	int32_t A;
	int32_t B;
	int32_t H;
	int32_t C_w;
	int32_t C_u;
};

void kalman_filter_int( struct Data1D_int* Data, int32_t y);

#endif /* KALMAN_FILTER_INT_H_ */
