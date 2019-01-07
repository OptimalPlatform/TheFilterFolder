/*
 * kalman_filter.h
 *
 *  Created on: 21 nov. 2018
 *      Author: User
 */

#ifndef KALMAN_FILTER_H_
#define KALMAN_FILTER_H_

#include "stdint.h" // To get uint16_t. How come I dont need this in Experimentation2?


struct Data1D {
	// Dynamic variables
	uint16_t x_est;
	uint16_t x_pred;
	uint16_t MSE_pred;
	// Fixed variables (For now)
	uint16_t A;
	uint16_t B;
	uint16_t H;
	uint16_t C_w;
	uint16_t C_u;
};

void kalman_filter( struct Data1D* Data, uint16_t y);

#endif /* KALMAN_FILTER_H_ */
