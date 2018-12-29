/*
 * matrix_initialize_2D.h
 *
 *  Created on: 20 dec. 2018
 *      Author: User
 */

#ifndef MATRIX_INITIALIZE_2D_H_
#define MATRIX_INITIALIZE_2D_H_


#include "data_instances.h"
//#include "kalman_filter_2D.h"
#include "kalman_data_2D.h"
#include "stdint.h"

void matrix_initialize_2D(struct Matrix_DataMD* Matrix_Data, struct Data2D* Data, uint32_t dim);


#endif /* MATRIX_INITIALIZE_2D_H_ */
