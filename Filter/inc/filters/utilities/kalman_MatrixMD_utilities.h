/*
 * kalman_MatrixMD_utilities.h
 *
 *  Created on: 21 dec. 2018
 *      Author: User
 */

#ifndef KALMAN_MATRIXMD_UTILITIES_H_
#define KALMAN_MATRIXMD_UTILITIES_H_


//#include "kalman_filter_2D.h"
#include "data_instances.h"

void kalman_gain_MatrixMD(struct Matrix_DataMD* Matrix_Data);
void x_est_MatrixMD(struct Matrix_DataMD* Matrix_Data, float32_t y);
void MSE_est_MatrixMD(struct Matrix_DataMD* Matrix_Data);
void x_pred_MatrixMD(struct Matrix_DataMD* Matrix_Data);
void MSE_pred_MatrixMD(struct Matrix_DataMD* Matrix_Data);








#endif /* KALMAN_MATRIXMD_UTILITIES_H_ */
