/*
 * kalman_data_2D.h
 *
 *  Created on: 29 dec. 2018
 *      Author: User
 */

#ifndef FILTERS_KALMAN_2D_KALMAN_DATA_2D_H_
#define FILTERS_KALMAN_2D_KALMAN_DATA_2D_H_

//#include "stdint.h" // To get uint16_t. How come I dont need this in Experimentation2?
//#include "arm_math.h"
#include "data_instances.h"


/*
 * List of matrix instances to be initialized and their dimensions.
 * 	Index:		Variabel								Dimensions: (These should be correct!)
 * 	(1)			x_est 									2r1c
 * 	(2)			x_pred 									2r1c
 * 	(3)			A 										2r2c
 * 	(4)			B 										2r1c
 * 	(5)			H 										1r2c
 * 	(6)			HT										2r1c
 * 	(7)			C_w										1r1c
 * 	(8)			C_u										1r1c
 * 	(9)			MSEpred									2r2c
 * 	(10)		MSEpredHT								2r1c
 * 	(11)		MSEest									2r2c
 * 	(12)		HMSEpredHT								1r1c
 * 	(13)		HMSEpredHTplusCw						1r1c
 * 	(14)		invOfHMSEpredHTplusCw					1r1c
 * 	(15)		K (MSEpredHTinvOfHMSEpredHTplusCw)		2r1c
 * 	(16)		Hxpred									1r1c
 * 	(17)		yminusHxpred							1r1c
 * 	(18)		correction (KyminusHxpred)				2r1c
 * 	(19)		KH										2r2c
 * 	(20)		I										2r2c
 * 	(21)		IminusKH								2r2c
 * 	(22)		BT										1r2c
 * 	(23)		CuBT									1r2c
 * 	(24)		BCuBT									2r2c
 * 	(25)		AT										2r2c
 * 	(26)		MSEestAT								2r2c
 * 	(27)		AMSEestAT								2r2c
 *
 *
 */
struct Data2D {

	// 	(1)			x_est 									2r1c
	float32_t x_est_f32[2]; // Dynamic variable

	// 	(2)			x_pred 									2r1c
	float32_t x_pred_f32[2]; // Dynamic variable

	// 	(3)			A 										2r2c
	float32_t A_f32[4]; // Static variable

	// 	(4)			B 										2r1c
	float32_t B_f32[2]; // Static variable

	// 	(5)			H 										1r2c
	float32_t H_f32[2];  // Static variable

	// 	(6)			HT										2r1c
	float32_t HT_f32[2];  // Static variable

	// 	(7)			C_w										1r1c
	float32_t C_w_f32[1]; // Static variable
	// Does this size of array work? Think so.

	// 	(8)			C_u										1r1c
	float32_t C_u_f32[1]; // Static variable

	// 	(9)			MSEpred									2r2c
	float32_t MSE_pred_f32[4]; // Dynamic variable


	// 	(10)		MSEpredHT								2r1c
	float32_t MSEpredHT_f32[2];

	// 	(11)		MSEest									2r2c
	float32_t MSE_est_f32[4];

	// 	(12)		HMSEpredHT								1r1c
	float32_t HMSEpredHT_f32[1];

	// 	(13)		HMSEpredHTplusCw						1r1c
	float32_t HMSEpredHTplusCw_f32[1];

	// 	(14)		invOfHMSEpredHTplusCw					1r1c
	float32_t invOfHMSEpredHTplusCw_f32[1];

	// 	(15)		K (MSEpredHTinvOfHMSEpredHTplusCw)		2r1c
	float32_t K_f32[2];

	// 	(16)		Hxpred									1r1c
	float32_t Hxpred_f32[1];

	// 	(17)		yminusHxpred							1r1c
	float32_t yminusHxpred_f32[1];

	// 	(18)		correction (KyminusHxpred)				2r1c
	float32_t correction_f32[2];

	// 	(19)		KH										2r2c
	float32_t KH_f32[4];

	// 	(20)		I										2r2c
	float32_t I_f32[4]; // Static variable

	// 	(21)		IminusKH								2r2c
	float32_t IminusKH_f32[4];

	// 	(22)		BT										1r2c
	float32_t BT_f32[2]; // Static variable

	// 	(23)		CuBT									1r2c
	float32_t CuBT_f32[2];

	// 	(24)		BCuBT									2r2c
	float32_t BCuBT_f32[4];

	// 	(25)		AT										2r2c
	float32_t AT_f32[4]; // Static variable

	// 	(26)		MSEestAT								2r2c
	float32_t MSEestAT_f32[4];

	// 	(27)		AMSEestAT								2r2c
	float32_t AMSEestAT_f32[4];

};



/*
 * Unused!
 */
struct Matrix_Data2D_buffers {
	arm_matrix_instance_f32 buffer_2r1c;
	arm_matrix_instance_f32 buffer_1r2c;
	arm_matrix_instance_f32 buffer_2r2c;
	arm_matrix_instance_f32 y_mat;
};

/*
 * Unused!
 */
struct Data2D_buffers {
	float32_t buffer_2r1c_f32;
	float32_t buffer_1r2c_f32;
	float32_t buffer_2r2c_f32;
};


#endif /* FILTERS_KALMAN_2D_KALMAN_DATA_2D_H_ */
