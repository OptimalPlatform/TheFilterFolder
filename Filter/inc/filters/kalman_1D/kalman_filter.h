/*
 * kalman_filter.h
 *
 *  Created on: 21 nov. 2018
 *      Author: User
 */

#ifndef KALMAN_FILTER_H_
#define KALMAN_FILTER_H_

//#include "stdint.h" // To get uint16_t. How come I dont need this in Experimentation2?
#include "arm_math.h"

struct Data1D {
	// Dynamic variables
	float32_t x_est;
	float32_t x_pred;
	float32_t MSE_pred;
	float32_t A;
	float32_t B;
	float32_t H;
	float32_t C_w;
	float32_t C_u;
};

void kalman_filter( struct Data1D* Data, float32_t y);

#endif /* KALMAN_FILTER_H_ */
