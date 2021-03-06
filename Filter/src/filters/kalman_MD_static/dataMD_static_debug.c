/*
 * dataMD_static_debug.c
 *
 *  Created on: 28 dec. 2018
 *      Author: User
 */


#include "kalman_filter_MD_static.h"

/*
 * Debug function for declaring variables.
 */
void dataMD_static_debug_observable(struct DataMD_static* Data, uint32_t dim, uint32_t maxDim) {


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

	//float32_t a[] = {-1.05, -0.45, 0.07, 0.43}; //, 0, 0, 0, 0}; //, 0, 0, 0, 0, 0, 0, 0, 0};
	//float32_t b[] = {1.98, 1.47, 0.64, 0.28}; //, 0, 0, 0, 0}; //, 0, 0, 0, 0 ,0 ,0 ,0 ,0};

	float32_t a[] = {-0.8, -0.2, 0.07, 0.03}; //, 0, 0, 0, 0}; //, 0, 0, 0, 0, 0, 0, 0, 0};
	float32_t b[] = {0.2, 0.02, 0.01, 0.01}; //, 0, 0, 0, 0}; //, 0, 0, 0, 0 ,0 ,0 ,0 ,0};


	// x_pred 		Dynamic variable
	uint16_t i;
	for (i=0;i<maxDim;i++){
		Data->x_pred_f32[i] = 0;
	}


	// A 			Static variable
	uint16_t j = 0;
	uint16_t n = 1;
	for (i=0;i<(maxDim*maxDim);i++){
		Data->A_f32[i] = 0;
	}
	// Think about (maxDim-2). Is this correct?! Not (maxDim-1) ?!
	for (i=0;i<(maxDim*(dim-1)+1);i++){
		if ( (i%maxDim)==0) {
			Data->A_f32[i] = -a[j]; // Notice negative sign
			j++;
		}
		if (i==n) {
			Data->A_f32[i] = 1;
			n = n + maxDim+1;
		}
	}


	// B			Static variable
	for (i=0;i<maxDim;i++){
		Data->B_f32[i] = b[i];
	}

	// H 			Static variable
	Data->H_f32[0] = 1;
	for (i=1;i<maxDim;i++){
		Data->H_f32[i] = 0;
	}


	// MSE_pred		Dynamic variable
	n = 0;
	for (i=0;i<(maxDim*maxDim);i++){
		Data->MSE_pred_f32[i] = 0;
	}
	for (i=0;i<(maxDim*(dim-1)+1);i++){
		if (i==n) {
			Data->MSE_pred_f32[i] = 100;
			n = n + maxDim+1;
		}
	}



	// C_w;			Static variable
	Data->C_w_f32[0] = 4; // 4

	// C_u;			Static variable
	Data->C_u_f32[0] = 1;

	// I			// Here I found an error. Had created the unit matrix incorrectly.
	n = 0;
	for (i=0;i<(maxDim*maxDim);i++){
		Data->I_f32[i] = 0;
	}
	for (i=0;i<(maxDim*(dim-1)+1);i++){
		if (i==n) {
			Data->I_f32[i] = 1;
			n = n + maxDim+1;
		}
	}


	// x_est 		Should I delete this?
	for (i=0;i<maxDim;i++){
		Data->x_est_f32[i] = 1;
	}
}

