/*
 * matrix_initialize_4D.h
 *
 *  Created on: 28 dec. 2018
 *      Author: User
 */

#ifndef FILTERS_KALMAN_4D_MATRIX_INITIALIZE_4D_H_
#define FILTERS_KALMAN_4D_MATRIX_INITIALIZE_4D_H_

#include "data_instances.h"
//#include "kalman_filter_4D.h"
#include "kalman_data_4D.h"
#include "stdint.h"

void matrix_initialize_4D(struct Matrix_DataMD* Matrix_Data, struct Data4D* Data, uint32_t dim);



#endif /* FILTERS_KALMAN_4D_MATRIX_INITIALIZE_4D_H_ */
