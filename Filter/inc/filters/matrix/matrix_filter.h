/*
 * matrix_filter.h
 *
 *  Created on: 19 dec. 2018
 *      Author: User
 */

#ifndef MATRIX_FILTER_H_
#define MATRIX_FILTER_H_

//#include "stdint.h" // To get uint16_t. How come I dont need this in Experimentation2?
#include "arm_math.h"
#include "data_instances.h"

struct DataMat {

	float32_t yo_f32[4];
	float32_t yoScale_f32[4];
	float32_t hello_f32[2];
	float32_t yoHello_f32[2];
	float32_t helloT_f32[2];
	float32_t buffer_2r1c_f32[2];
	float32_t buffer_1r2c_f32[2];
	float32_t buffer_2r2c_f32[4];
	float32_t y_f32[1];
};

void matrix_filter( struct Matrix_Data_exp* Matrix_Data, float32_t y);

#endif /* MATRIX_FILTER_H_ */
