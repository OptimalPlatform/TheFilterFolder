/*
 * debug_parameters.c
 *
 *  Created on: 29 dec. 2018
 *      Author: User
 */

#include "debug_parameters.h"

void debug_parameters(struct Params* Parameters) {

	// x_pred 		Dynamic variable
	Parameters->x_pred[0] = 0;
	Parameters->x_pred[1] = 0;
	Parameters->x_pred[2] = 0;
	Parameters->x_pred[3] = 0;

	// A 			Static variable
	Parameters->a[0] = 1;
	Parameters->a[1] = -0.8;
	Parameters->a[2] = -0.2;
	Parameters->a[3] = -0.01;
	Parameters->a[4] = 0.05;

	// B			Static variable
	Parameters->b[0] = 0.100;
	Parameters->b[1] = 0.025;
	Parameters->b[2] = 0.010;
	Parameters->b[3] = 0.005;

	// MSE_pred		Dynamic variable
	Parameters->MSE_pred = 100;

	// C_w;			Static variable
	Parameters->C_w = 4;

	// C_u;			Static variable
	Parameters->C_u = 1;
}
