/*
 * kalman_dynamic_data.h
 *
 *  Created on: 28 dec. 2018
 *      Author: User
 */

#ifndef FILTERS_KALMAN_MD_DYNAMIC_KALMAN_DYNAMIC_DATA_H_
#define FILTERS_KALMAN_MD_DYNAMIC_KALMAN_DYNAMIC_DATA_H_


#include "arm_math.h"

	/*
	 * List of matrix instances to be initialized and their dimensions.
	 * 	Index:		Variabel								Dimensions: (These should be correct!)
	 * 	(1)			x_est 									Dr1c
	 * 	(2)			x_pred 									Dr1c
	 * 	(3)			A 										DrDc
	 * 	(4)			B 										Dr1c
	 * 	(5)			H 										1rDc
	 * 	(6)			HT										Dr1c
	 * 	(7)			C_w										1r1c
	 * 	(8)			C_u										1r1c
	 * 	(9)			MSEpred									DrDc
	 * 	(10)		MSEpredHT								Dr1c
	 * 	(11)		MSEest									DrDc
	 * 	(12)		HMSEpredHT								1r1c
	 * 	(13)		HMSEpredHTplusCw						1r1c
	 * 	(14)		invOfHMSEpredHTplusCw					1r1c
	 * 	(15)		K (MSEpredHTinvOfHMSEpredHTplusCw)		Dr1c
	 * 	(16)		Hxpred									1r1c
	 * 	(17)		yminusHxpred							1r1c
	 * 	(18)		correction (KyminusHxpred)				Dr1c
	 * 	(19)		KH										DrDc
	 * 	(20)		I										DrDc
	 * 	(21)		IminusKH								DrDc
	 * 	(22)		BT										1rDc
	 * 	(23)		CuBT									1rDc
	 * 	(24)		BCuBT									DrDc
	 * 	(25)		AT										DrDc
	 * 	(26)		MSEestAT								DrDc
	 * 	(27)		AMSEestAT								DrDc
	 *
	 *
	 */
struct Dynamic_Data
{
		// 	(1)			x_est 									Dr1c
		float32_t *x_est_f32; // Dynamic variable

		// 	(2)			x_pred 									Dr1c
		float32_t *x_pred_f32; // Dynamic variable

		// 	(3)			A 										DrDc
		float32_t *A_f32; // Static variable

		// 	(4)			B 										Dr1c
		float32_t *B_f32; // Static variable

		// 	(5)			H 										1rDc
		float32_t *H_f32;  // Static variable

		// 	(6)			HT										Dr1c
		float32_t *HT_f32;  // Static variable

		// 	(7)			C_w										1r1c
		float32_t *C_w_f32; // Static variable
		// Does this size of array work? Think so.

		// 	(8)			C_u										1r1c
		float32_t *C_u_f32; // Static variable

		// 	(9)			MSEpred									DrDc
		float32_t *MSE_pred_f32; // Dynamic variable


		// 	(10)		MSEpredHT								Dr1c
		float32_t *MSEpredHT_f32;

		// 	(11)		MSEest									DrDc
		float32_t *MSE_est_f32;

		// 	(12)		HMSEpredHT								1r1c
		float32_t *HMSEpredHT_f32;

		// 	(13)		HMSEpredHTplusCw						1r1c
		float32_t *HMSEpredHTplusCw_f32;

		// 	(14)		invOfHMSEpredHTplusCw					1r1c
		float32_t *invOfHMSEpredHTplusCw_f32;

		// 	(15)		K (MSEpredHTinvOfHMSEpredHTplusCw)		Dr1c
		float32_t *K_f32[2];

		// 	(16)		Hxpred									1r1c
		float32_t *Hxpred_f32[1];

		// 	(17)		yminusHxpred							1r1c
		float32_t *yminusHxpred_f32;

		// 	(18)		correction (KyminusHxpred)				Dr1c
		float32_t *correction_f32;

		// 	(19)		KH										DrDc
		float32_t *KH_f32;

		// 	(20)		I										DrDc
		float32_t *I_f32; // Static variable

		// 	(21)		IminusKH								DrDc
		float32_t *IminusKH_f32;

		// 	(22)		BT										1rDc
		float32_t *BT_f32; // Static variable

		// 	(23)		CuBT									1rDc
		float32_t *CuBT_f32;

		// 	(24)		BCuBT									DrDc
		float32_t *BCuBT_f32;

		// 	(25)		AT										DrDc
		float32_t *AT_f32; // Static variable

		// 	(26)		MSEestAT								DrDc
		float32_t *MSEestAT_f32;

		// 	(27)		AMSEestAT								DrDc
		float32_t *AMSEestAT_f32;

};



#endif /* FILTERS_KALMAN_MD_DYNAMIC_KALMAN_DYNAMIC_DATA_H_ */
