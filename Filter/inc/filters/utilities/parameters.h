/*
 * parameters.h
 *
 *  Created on: 29 dec. 2018
 *      Author: User
 */

#ifndef FILTERS_UTILITIES_PARAMETERS_H_
#define FILTERS_UTILITIES_PARAMETERS_H_

#include "arm_math.h"

struct Params {

		// x_pred 		Dynamic variable
		float32_t x_pred[4];

		// A 			Static variable
		float32_t a[5];

		// B			Static variable
		float32_t b[4];

		// MSE_pred		Dynamic variable
		float32_t MSE_pred;

		// C_w;			Static variable measurement noise
		float32_t C_w;

		// C_u;			Static variable  process noise
		float32_t C_u;

};

#endif /* FILTERS_UTILITIES_PARAMETERS_H_ */
