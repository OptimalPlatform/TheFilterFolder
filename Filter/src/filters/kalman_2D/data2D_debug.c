/*
 * data2D_debug.c
 *
 *  Created on: 21 dec. 2018
 *      Author: User
 */



//#include "kalman_filter_2D.h"
#include "kalman_data_2D.h"
#include "data2D_debug.h"

/*
 * Debug function for declaring variables.
 */
void data2D_debug(struct Data2D* Data, struct Params* P) {


	/*
	 * List of matrix instances to be initialized and their dimensions.
	 * 	Index:		Variabel								Dimensions: (These should be correct!)
	 * 	(1)			x_est 									2r1c
	 * 	(2)			x_pred 									2r1c ------	Need to be initialized
	 * 	(3)			A 										2r2c ------	Need to be initialized
	 * 	(4)			B 										2r1c ------	Need to be initialized
	 * 	(5)			H 										1r2c ------	Need to be initialized!
	 * 	(6)			HT										2r1c ------	Could be initialized.
	 * 	(7)			C_w										1r1c ------	Need to be initialized!
	 * 	(8)			C_u										1r1c ------	Need to be initialized!
	 * 	(9)			MSE_pred								2r2c ------	Need to be initialized!
	 * 	(10)		MSEpredHT								2r1c
	 * 	(11)		MSE_est									2r2c
	 * 	(12)		HMSEpredHT								1r1c
	 * 	(13)		HMSEpredHTplusCw						1r1c
	 * 	(14)		invOfHMSEpredHTplusCw					1r1c
	 * 	(15)		K (MSEpredHTinvOfHMSEpredHTplusCw)		2r1c
	 * 	(16)		Hxpred									1r1c
	 * 	(17)		yminusHxpred							1r1c
	 * 	(18)		correction (KyminusHxpred)				2r1c
	 * 	(19)		KH										2r2c
	 * 	(20)		I										2r2c ------	Need to be initialized!
	 * 	(21)		IminusKH								2r2c
	 * 	(22)		BT										1r2c ------	Could be initialized.
	 * 	(23)		CuBT									1r2c
	 * 	(24)		BCuBT									2r2c
	 * 	(25)		AT										2r2c ------	Could be initialized.
	 * 	(26)		MSEestAT								2r2c
	 * 	(27)		AMSEestAT								2r2c
	 *
	 *
	 */

	uint16_t i;

	// x_pred 		Dynamic variable
	float32_t x_pred[] = {P->x_pred[0],P->x_pred[1]};
	for(i=0;i<2;i++) {
		Data->x_pred_f32[i] = x_pred[i];
	}

	//float32_t a[3];
	//a[0] = 1;
	//a[1] = 0.8;
	//a[2] = 0.2;

	// A 			Static variable
	float32_t A[] = {	-(P->a[1]), 1,
						-(P->a[2]), 0	};
	for(i=0;i<4;i++) {
		Data->A_f32[i] = A[i];
	}


	// B			Static variable
	float32_t B[] = {P->b[0], P->b[1]};
	for(i=0;i<2;i++) {
		Data->B_f32[i] = B[i];
	}

	// H 			Static variable
	float32_t H[] = {1, 0};
	for(i=0;i<2;i++) {
		Data->H_f32[i] = H[i];
	}

	// MSE_pred		Dynamic variable
	float32_t MSE_pred[] = {	P->MSE_pred, 0,
								0, P->MSE_pred	};
	for(i=0;i<4;i++) {
		Data->MSE_pred_f32[i] = MSE_pred[i];
	}

	// C_w;			Static variable
	Data->C_w_f32[0] = P->C_w;

	// C_u;			Static variable
	Data->C_u_f32[0] =  P->C_u;

	// I			// Here I found an error. Had created the unit matrix incorrectly.
	float32_t I[] = {	1, 0,
						0, 1	};
	for(i=0;i<4;i++) {
		Data->I_f32[i] = I[i];
	}

	// x_est 		Should I delete this?
	float32_t x_est[] = {1,1};
	for(i=0;i<2;i++) {
		Data->x_est_f32[i] = x_est[i];
	}



	// Below is another way to write it.
	/*
	// x_pred 		Dynamic variable
	Data->x_pred_f32[0] = 0;
	Data->x_pred_f32[1] = 0;

	// A 			Static variable
	Data->A_f32[0] = 0.8;	// a0
	Data->A_f32[1] = 1;	// 1
	Data->A_f32[2] = 0.2;	// a1
	Data->A_f32[3] = 0;	// 0

	// B			Static variable
	Data->B_f32[0] = 0.1; 	// b0
	Data->B_f32[1] = 0.025; 	// b1

	// H 			Static variable
	Data->H_f32[0] = 1;
	Data->H_f32[1] = 0;

	// MSE_pred		Dynamic variable
	Data->MSE_pred_f32[0] = 100;
	Data->MSE_pred_f32[1] = 0;
	Data->MSE_pred_f32[2] = 0;
	Data->MSE_pred_f32[3] = 100;

	// C_w;			Static variable
	Data->C_w_f32[0] = 4;

	// C_u;			Static variable
	Data->C_u_f32[0] = 1;

	// I			// Here I found an error. Had created the unit matrix incorrectly.
	Data->I_f32[0] = 1;
	Data->I_f32[1] = 0;
	Data->I_f32[2] = 0;
	Data->I_f32[3] = 1;

	// x_est 		Should I delete this?
	Data->x_est_f32[0] = 1;
	Data->x_est_f32[1] = 1;
	*/
}

