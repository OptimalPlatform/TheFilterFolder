/*
 * matrix_initialize_3D.h
 *
 *  Created on: 28 dec. 2018
 *      Author: User
 */

#ifndef FILTERS_KALMAN_3D_MATRIX_INITIALIZE_3D_H_
#define FILTERS_KALMAN_3D_MATRIX_INITIALIZE_3D_H_

#include "data_instances.h"
//#include "kalman_filter_3D.h"
#include "kalman_data_3D.h"
#include "stdint.h"

void matrix_initialize_3D(struct Matrix_DataMD* Matrix_Data, struct Data3D* Data, uint32_t dim);



#endif /* FILTERS_KALMAN_3D_MATRIX_INITIALIZE_3D_H_ */
