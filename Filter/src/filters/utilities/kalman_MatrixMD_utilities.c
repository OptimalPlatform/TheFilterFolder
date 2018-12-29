/*
 * kalman_MatrixMD_utilities.c
 *
 *  Created on: 19 dec. 2018
 *      Author: User
 */


#include "kalman_MatrixMD_utilities.h" // Do I really need this.
//#include "arm_math.h"

/*
 * Calculates the Kalman Gain
 * K[n] = MSE_pred[n]*H[n]^T*(H[n]*MSE_pred[n]*H[n]^T + C_w[n])^-1
 *
 * 	Thought:
 * 		Does 1x1 matrix manioulation work?
 *
 * 	Comment:
 * 		Another solution for addition of 1by1 matrices is:
 * 		Matrix_Data->HMSEpredHTplusCw.pData[0] = Matrix_Data->HMSEpredHT.pData[0] + Matrix_Data->C_w.pData[0];
 *
 * 	Thought:
 * 		Regarding "const arm_matrix_instance_f32 * pSrcA" in the matrix functions, do I have to care about the const word?
 * 		Surely I should be able to manipulate the matrix elements?
 *
 * 	 To do:
 *  	Check in with the matrix_filter.c if 2x1 times 1x1 matrix multiplication works.
 *
 */
void kalman_gain_MatrixMD(struct Matrix_DataMD* Matrix_Data) {

	// H[n]^T
	Matrix_Data->status = arm_mat_trans_f32(&(Matrix_Data->H),&(Matrix_Data->HT));

	// MSE_pred[n]*H[n]^T
	Matrix_Data->status = arm_mat_mult_f32(&(Matrix_Data->MSE_pred), &(Matrix_Data->HT), &(Matrix_Data->MSEpredHT));

	// H[n]*MSE_pred[n]*H[n]^T  This will make it a scalar in this special case.
	Matrix_Data->status = arm_mat_mult_f32( &(Matrix_Data->H), &(Matrix_Data->MSEpredHT), &(Matrix_Data->HMSEpredHT));

	// H[n]*MSE_pred[n]*H[n]^T + C_w[n]
	Matrix_Data->status = arm_mat_add_f32(&(Matrix_Data->HMSEpredHT), &(Matrix_Data->C_w), &(Matrix_Data->HMSEpredHTplusCw));

	// (H[n]*MSE_pred[n]*H[n]^T + C_w[n])^-1
	// (Maybe this should be done without using the inv function!)
	Matrix_Data->status = arm_mat_inverse_f32(&(Matrix_Data->HMSEpredHTplusCw),&(Matrix_Data->invOfHMSEpredHTplusCw));

	// MSE_pred[n]*H[n]^T
	// Already calculated;

	// MSE_pred[n]*H[n]^T*(H[n]*MSE_pred[n]*H[n]^T + C_w[n])^-1
	Matrix_Data->status = arm_mat_scale_f32(&(Matrix_Data->MSEpredHT), Matrix_Data->invOfHMSEpredHTplusCw.pData[0], &(Matrix_Data->K));
	// Need to change this line if argument 2 is not scalar! Think arm_mult can work for this scalar case also.
	// This is because of the dimensions of MSEpredHT

	//Matrix_Data->K.pData[0] = 0.8; // Debug
	//Matrix_Data->K.pData[1] = 0.8; // Debug

}


/*
 * x_est[n] = x_pred[n] + K[n]*(y[n] - H[n]*x_pred[n])
 */
void x_est_MatrixMD(struct Matrix_DataMD* Matrix_Data, float32_t y) {

	// H[n]*x_pred[n]
	Matrix_Data->status = arm_mat_mult_f32(&(Matrix_Data->H) ,&(Matrix_Data->x_pred), &(Matrix_Data->Hxpred));

	// y[n] - H[n]*x_pred[n]
	Matrix_Data->yminusHxpred.pData[0] = y - Matrix_Data->Hxpred.pData[0];
	// Need to change this line if y is not scalar!

	// K[n]*(y[n] - H[n]*x_pred[n])
	Matrix_Data->status = arm_mat_scale_f32(&(Matrix_Data->K), Matrix_Data->yminusHxpred.pData[0], &(Matrix_Data->correction));
	// Also this line if y is not scalar!

	// x_pred[n] + K[n]*(y[n] - H[n]*x_pred[n])
	Matrix_Data->status = arm_mat_add_f32(&(Matrix_Data->x_pred), &(Matrix_Data->correction), &(Matrix_Data->x_est));

	//Matrix_Data->x_est.pData[0] = 0.5*y; // Debug
	//Matrix_Data->x_est.pData[1] = 0.5*y; // Debug

}


/*
 * MSE_est[n] = (I - K[n]*H[n])*MSE_pred[n]
 */
void MSE_est_MatrixMD(struct Matrix_DataMD* Matrix_Data) {

	// K[n]*H[n]
	Matrix_Data->status = arm_mat_mult_f32(&(Matrix_Data->K) ,&(Matrix_Data->H), &(Matrix_Data->KH));

	// I - K[n]*H[n]
	Matrix_Data->status = arm_mat_sub_f32( &(Matrix_Data->I), &(Matrix_Data->KH),&(Matrix_Data->IminusKH));

	// (I - K[n]*H[n])*MSE_pred[n]
	Matrix_Data->status = arm_mat_mult_f32(&(Matrix_Data->IminusKH),&(Matrix_Data->MSE_pred), &(Matrix_Data->MSE_est));

}

/*
 * x_pred[n] = A[n]*x_est[n]
 */
void x_pred_MatrixMD(struct Matrix_DataMD* Matrix_Data) {
	// A[n]*x_est[n]
	Matrix_Data->status = arm_mat_mult_f32(&(Matrix_Data->A),&(Matrix_Data->x_est), &(Matrix_Data->x_pred));

}

/*
 * MSE_pred[n] = A[n]*MSE_est[n]*A[n]^T + B[n]*C_u[n]*B[n]^T
 */
void MSE_pred_MatrixMD(struct Matrix_DataMD* Matrix_Data) {

	// B[n]^T
	Matrix_Data->status = arm_mat_trans_f32(&(Matrix_Data->B),&(Matrix_Data->BT));


	// C_u[n]*B[n]^T
	Matrix_Data->status = arm_mat_mult_f32(&(Matrix_Data->C_u) ,&(Matrix_Data->BT), &(Matrix_Data->CuBT));


	// B[n]*C_u[n]*B[n]^T
	Matrix_Data->status = arm_mat_mult_f32(&(Matrix_Data->B) ,&(Matrix_Data->CuBT), &(Matrix_Data->BCuBT));

	// A[n]^T
	Matrix_Data->status = arm_mat_trans_f32(&(Matrix_Data->A),&(Matrix_Data->AT));

	// MSE_est[n]*A[n]^T
	Matrix_Data->status = arm_mat_mult_f32(&(Matrix_Data->MSE_est) ,&(Matrix_Data->AT), &(Matrix_Data->MSEestAT));

	// A[n]*MSE_est[n]*A[n]^T
	Matrix_Data->status = arm_mat_mult_f32(&(Matrix_Data->A) ,&(Matrix_Data->MSEestAT), &(Matrix_Data->AMSEestAT));


	// A[n]*MSE_est[n]*A[n]^T + B[n]*C_u[n]*B[n]^T
	Matrix_Data->status = arm_mat_add_f32(&(Matrix_Data->AMSEestAT), &(Matrix_Data->BCuBT), &(Matrix_Data->MSE_pred));

}






