/*
 * kalman_filter_int.c
 *
 *  Created on: 4 dec. 2018
 *      Author: User
 */

//#include "stdint.h" // To get uint16_t (Could also use inttypes.h)
#include "kalman_filter_int.h"



/*
 * It seems to work if you fix the H, MSE_pred and C_w values. Look into how MSE_pred changes!
 */
float kalman_gain_int(int32_t MSE_pred, uint32_t H, uint32_t C_w){
	//H = 1;
	//MSE_pred = 1;
	//C_w = 4;
	float K = (((float)H)*((float)MSE_pred)/( (float)(H*MSE_pred*H + C_w) ) );
	return K;
}


/************************** Kalman Filter **************************/
/*
 * Note: This version of the kalman filter deals with negative values, hence int32_t is used.
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
void kalman_filter_int( struct Data1D_int* Data , int32_t y )

{
	// Declarations
	float K; // I suppose I need 32 here since the unsigned uses 16?
	int32_t MSE_est;

	// Measurement update:
	K = kalman_gain_int(Data->MSE_pred, Data->H, Data->C_w);
	Data->x_est = (Data->x_pred) + (K*(y - ((Data->H) * (Data->x_pred)))); // Try changing K to 0.2 and it sort of works
	MSE_est = (int32_t)((1.0f - (K*((Data->H)))) * (Data->MSE_pred));

	// Time update:
	Data->x_pred 	= (Data->A) * (Data->x_est);
	Data->MSE_pred = (Data->A) * MSE_est * (Data->A) + (Data->B) * (Data->C_u) * (Data->B);


	// Start of debug section //
	//Data->x_est = y;

	// Debug:
	// Data->x_est = y;

	// End of debug section //

	// Comment:
	// Can I declare some variable as uint8_t instead of uint16_t?
	// Or will that mess up my math?

	// Question:
	// How large in uint16_t is really the signals we are dealing with?

}
