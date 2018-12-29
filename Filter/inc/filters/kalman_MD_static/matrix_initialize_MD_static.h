/*
 * matrix_initialize_MD_static.h
 *
 *  Created on: 28 dec. 2018
 *      Author: User
 */

#ifndef FILTERS_KALMAN_MD_STATIC_MATRIX_INITIALIZE_MD_STATIC_H_
#define FILTERS_KALMAN_MD_STATIC_MATRIX_INITIALIZE_MD_STATIC_H_

#include "data_instances.h"
#include "kalman_filter_MD_static.h"
#include "stdint.h"

void matrix_initialize_MD_static(struct Matrix_DataMD* Matrix_Data, struct DataMD_static* Data, uint32_t dim);


#endif /* FILTERS_KALMAN_MD_STATIC_MATRIX_INITIALIZE_MD_STATIC_H_ */
