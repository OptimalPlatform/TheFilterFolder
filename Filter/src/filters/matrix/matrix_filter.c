/*
 * matrix_filter.c
 *
 *  Created on: 19 dec. 2018
 *      Author: User
 */



#include "matrix_filter.h"

/************************** Matrix Filter **************************/
/*
 * Note to self:
 * 			Because we have an offset the y*0.5 will give  some scaleability wierdness.
 * 			This will happen if you look with DC mode on the osciloscope.
 *
 */
void matrix_filter( struct Matrix_Data_exp* Matrix_Data , float32_t y )

{
	//Matrix_Data->yo.pData[0] = 2;
	//Matrix_Data->yo.pData[1] = 1;
	//Matrix_Data->yo.pData[2] = 0.5;
	//Matrix_Data->yo.pData[3] = 0;

	//Matrix_Data->status = arm_mat_scale_f32(&(Matrix_Data->yo), y, &(Matrix_Data->yoScale));


	Matrix_Data->status = arm_mat_trans_f32(&(Matrix_Data->hello),&(Matrix_Data->helloT));

	// To do:
	// 		Check if the lines below works.
	Matrix_Data->y_mat.pData[0] = y;
	//Matrix_Data->status = arm_mat_mult_f32(&(Matrix_Data->hello),&(Matrix_Data->y_mat), &(Matrix_Data->buffer_2r1c));
	//Matrix_Data->status = arm_mat_mult_f32(&(Matrix_Data->helloT), &(Matrix_Data->y_mat), &(Matrix_Data->buffer_1r2c));
	// I wonder if this matrix multiplication above really works.
	// It seems as if I can get out the first element but not the second.

	//Matrix_Data->status = arm_mat_mult_f32(&(Matrix_Data->helloT),&(Matrix_Data->y_mat), &(Matrix_Data->buffer_1r2c));

	Matrix_Data->status = arm_mat_scale_f32(&(Matrix_Data->helloT), y, &(Matrix_Data->buffer_1r2c));


	// To do:
	// 		Invert the signal y using arm_mat_inverse_f32()
	// 		That is: invert a 1by1 matrix and see what happens
	// 		But this does not seem like a good idea to use int the function. Seems easier with just dividing.

}
