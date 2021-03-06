/*
 * kalman_filter_MD_static.c
 *
 *  Created on: 28 dec. 2018
 *      Author: User
 */



#include "kalman_filter_MD_static.h"



#include "kalman_MatrixMD_utilities.h"


/************************** Kalman Filter **************************/
/*
 * Note: 	Vector notation is used here and the actual function DEALS with vectors
 * 			In order to work with this I need:
 * 			- A way to multiply vectors with matrices etc.
 * 			- Find the Inverse of a matrix.
 *
 * System:
 * 			x[n+1]  = A[n]*x[n] + B[n]*u[n]											(eq. 1)
 * 			y[n] 	= H[n]*x[n] + w[n]												(eq. 2)
 *
 * Measurement update:
 * 			K[n] 	 = MSE_pred[n]*H[n]^T*(H[n]*MSE_pred[n]*H[n]^T + C_w[n])^-1		(eq. 3)
 * 			x_est[n] = x_pred[n] + K[n]*(y[n] - H[n]*x_pred[n])						(eq. 4)
 * 			MSE_est[n] 	 = (I - K[n]*H[n])*MSE_pred[n]								(eq. 5)
 *
 * Time update:
 * 			x_pred[n] 	= A[n]*x_est[n]												(eq. 8)
 * 			MSE_pred[n] = A[n]*MSE_est[n]*A[n]^T + B[n]*C_u[n]*B[n]^T				(eq. 7)
 *
 * Notation:
 * 			A[n]			This matrix regards to how the state of x[n] updates.
 * 			x[n]			The actual signal value at time n if it could be measured.
 * 			x_est[n]		The estimated signal value at time n.
 * 			x_pred[n]		The predicted signal value at time n using the signal value at time n-1.
 * 							After time update this corresponds to value at time n+1 using signal value at time n
 * 			MSE_est[n]		E[(x[n] - x_est[n])*(x[n] - x_est[n])^T]
 * 			MSE_pred[n]		E[(x[n] - x_pred[n])*(x[n] - x_pred[n])^T]
 * 			u[n]			Noise (Assumed zero-mean) (Can we really assume this with our offset? Think so!)
 * 			B[n]			This matrix regards to how the noise u[n] updates.
 * 			y[n]			The measurement signal (E.i. the signal we measure).
 * 			H[n]			This matrix relates the measured signal y[n] with the actual signal x[n]
 * 			w[n]			Noise (Assumed zero-mean) (Can we really assume this with our offset? Think so!)
 * 			I				Unit-matrix
 * 			K[n]			The Kalman-gain
 * 			C_w[n]			The covariance matrix of w[n]
 * 			C_u[n]			The covariance matrix of u[n]
 * 			^T				The transform of a matrix
 *
 * 	Input:
 *			A Struct called Data containing the relevant data
 *
 * 	Output:
 * 			None
 */
void kalman_filter_MD_static( struct Matrix_DataMD* Matrix_Data , float32_t y )

{

	/* Measurement update */
	kalman_gain_MatrixMD(Matrix_Data);
	x_est_MatrixMD(Matrix_Data, y);
	//Matrix_Data->x_est.pData[0] = 0.5 *y;
	//Matrix_Data->x_est.pData[1] = 0.5 *y;
	MSE_est_MatrixMD(Matrix_Data);

	/* Time update: */
	x_pred_MatrixMD(Matrix_Data);
	MSE_pred_MatrixMD(Matrix_Data);

}







