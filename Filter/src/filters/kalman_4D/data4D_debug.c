/*
 * data4D_debug.c
 *
 *  Created on: 28 dec. 2018
 *      Author: User
 */




//#include "kalman_filter_4D.h"
#include "kalman_data_4D.h"
#include "data4D_debug.h"

/*
 * Debug function for declaring variables.
 */
void data4D_debug(struct Data4D* Data, struct Params* P) {


	/*
	 * List of matrix instances to be initialized and their dimensions.
	 * 	Index:		Variabel								Dimensions: (These should be correct!)
	 * 	(1)			x_est 									4r1c
	 * 	(2)			x_pred 									4r1c ------	Need to be initialized
	 * 	(3)			A 										4r4c ------	Need to be initialized
	 * 	(4)			B 										4r1c ------	Need to be initialized
	 * 	(5)			H 										1r4c ------	Need to be initialized!
	 * 	(6)			HT										4r1c ------	Could be initialized.
	 * 	(7)			C_w										1r1c ------	Need to be initialized!
	 * 	(8)			C_u										1r1c ------	Need to be initialized!
	 * 	(9)			MSE_pred								4r4c ------	Need to be initialized!
	 * 	(10)		MSEpredHT								4r1c
	 * 	(11)		MSE_est									4r4c
	 * 	(12)		HMSEpredHT								1r1c
	 * 	(13)		HMSEpredHTplusCw						1r1c
	 * 	(14)		invOfHMSEpredHTplusCw					1r1c
	 * 	(15)		K (MSEpredHTinvOfHMSEpredHTplusCw)		4r1c
	 * 	(16)		Hxpred									1r1c
	 * 	(17)		yminusHxpred							1r1c
	 * 	(18)		correction (KyminusHxpred)				4r1c
	 * 	(19)		KH										4r4c
	 * 	(20)		I										4r4c ------	Need to be initialized!
	 * 	(21)		IminusKH								4r4c
	 * 	(22)		BT										1r4c ------	Could be initialized.
	 * 	(23)		CuBT									1r4c
	 * 	(24)		BCuBT									4r4c
	 * 	(25)		AT										4r4c ------	Could be initialized.
	 * 	(26)		MSEestAT								4r4c
	 * 	(27)		AMSEestAT								4r4c
	 *
	 *
	 */

	uint16_t i;

	// x_pred 		Dynamic variable
	float32_t x_pred[] = {P->x_pred[0],P->x_pred[1],P->x_pred[2],P->x_pred[3]};
	for(i=0;i<4;i++) {
		Data->x_pred_f32[i] = x_pred[i];
	}


	// A 			Static variable
	float32_t A[] = {	-(P->a[1]), 1, 0, 0,
						-(P->a[2]), 0, 1, 0,
						-(P->a[3]), 0, 0, 1,
						-(P->a[4]), 0, 0, 0	};
	for(i=0;i<16;i++) {
		Data->A_f32[i] = A[i];
	}


	// B			Static variable
	float32_t B[] = {P->b[0], P->b[1], P->b[2], P->b[3]};
	for(i=0;i<4;i++) {
		Data->B_f32[i] = B[i];
	}

	// H 			Static variable
	float32_t H[] = {1, 0, 0, 0};
	for(i=0;i<4;i++) {
		Data->H_f32[i] = H[i];
	}

	// MSE_pred		Dynamic variable
	float32_t MSE_pred[] = {	P->MSE_pred, 0, 0, 0,
								0, P->MSE_pred, 0, 0,
								0, 0, P->MSE_pred, 0,
								0, 0, 0, P->MSE_pred	};
	for(i=0;i<16;i++) {
		Data->MSE_pred_f32[i] = MSE_pred[i];
	}

	// C_w;			Static variable
	Data->C_w_f32[0] = P->C_w;

	// C_u;			Static variable
	Data->C_u_f32[0] = P->C_u;

	// I			// Here I found an error. Had created the unit matrix incorrectly.
	float32_t I[] = {	1, 0, 0, 0,
						0, 1, 0, 0,
						0, 0, 1, 0,
						0, 0, 0, 1	};
	for(i=0;i<16;i++) {
		Data->I_f32[i] = I[i];
	}

	// x_est 		Should I delete this?
	float32_t x_est[] = {1,1,1,1};
	for(i=0;i<4;i++) {
		Data->x_est_f32[i] = x_est[i];
	}

}


