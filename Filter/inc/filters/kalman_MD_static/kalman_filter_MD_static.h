/*
 * kalman_filter_MD_static.h
 *
 *  Created on: 28 dec. 2018
 *      Author: User
 */

#ifndef FILTERS_KALMAN_MD_STATIC_KALMAN_FILTER_MD_STATIC_H_
#define FILTERS_KALMAN_MD_STATIC_KALMAN_FILTER_MD_STATIC_H_

#include "data_instances.h"

/*
 * List of matrix instances to be initialized and their dimensions.
 * 	Index:		Variabel								Dimensions: (These should be correct!)
 * 	(1)			x_est 									16r1c
 * 	(2)			x_pred 									16r1c
 * 	(3)			A 										16r16c
 * 	(4)			B 										16r1c
 * 	(5)			H 										1r16c
 * 	(6)			HT										16r1c
 * 	(7)			C_w										1r1c
 * 	(8)			C_u										1r1c
 * 	(9)			MSEpred									16r16c
 * 	(10)		MSEpredHT								16r1c
 * 	(11)		MSEest									16r16c
 * 	(12)		HMSEpredHT								1r1c
 * 	(13)		HMSEpredHTplusCw						1r1c
 * 	(14)		invOfHMSEpredHTplusCw					1r1c
 * 	(15)		K (MSEpredHTinvOfHMSEpredHTplusCw)		16r1c
 * 	(16)		Hxpred									1r1c
 * 	(17)		yminusHxpred							1r1c
 * 	(18)		correction (KyminusHxpred)				16r1c
 * 	(19)		KH										16r16c
 * 	(20)		I										16r16c
 * 	(21)		IminusKH								16r16c
 * 	(22)		BT										1r16c
 * 	(23)		CuBT									1r16c
 * 	(24)		BCuBT									16r16c
 * 	(25)		AT										16r16c
 * 	(26)		MSEestAT								16r16c
 * 	(27)		AMSEestAT								16r16c
 *
 *
 */
struct DataMD_static {

	// 	(1)			x_est 									Dr1c
	float32_t x_est_f32[4]; // Dynamic variable

	// 	(2)			x_pred 									Dr1c
	float32_t x_pred_f32[4]; // Dynamic variable

	// 	(3)			A 										DrDc
	float32_t A_f32[16]; // Static variable

	// 	(4)			B 										Dr1c
	float32_t B_f32[4]; // Static variable

	// 	(5)			H 										1rDc
	float32_t H_f32[4];  // Static variable

	// 	(6)			HT										Dr1c
	float32_t HT_f32[4];  // Static variable

	// 	(7)			C_w										1r1c
	float32_t C_w_f32[1]; // Static variable
	// Does this size of array work? Think so.

	// 	(8)			C_u										1r1c
	float32_t C_u_f32[1]; // Static variable

	// 	(9)			MSEpred									DrDc
	float32_t MSE_pred_f32[16]; // Dynamic variable


	// 	(10)		MSEpredHT								Dr1c
	float32_t MSEpredHT_f32[4];

	// 	(11)		MSEest									DrDc
	float32_t MSE_est_f32[16];

	// 	(12)		HMSEpredHT								1r1c
	float32_t HMSEpredHT_f32[1];

	// 	(13)		HMSEpredHTplusCw						1r1c
	float32_t HMSEpredHTplusCw_f32[1];

	// 	(14)		invOfHMSEpredHTplusCw					1r1c
	float32_t invOfHMSEpredHTplusCw_f32[1];

	// 	(15)		K (MSEpredHTinvOfHMSEpredHTplusCw)		Dr1c
	float32_t K_f32[4];

	// 	(16)		Hxpred									1r1c
	float32_t Hxpred_f32[1];

	// 	(17)		yminusHxpred							1r1c
	float32_t yminusHxpred_f32[1];

	// 	(18)		correction (KyminusHxpred)				Dr1c
	float32_t correction_f32[4];

	// 	(19)		KH										DrDc
	float32_t KH_f32[16];

	// 	(20)		I										DrDc
	float32_t I_f32[16]; // Static variable

	// 	(21)		IminusKH								DrDc
	float32_t IminusKH_f32[16];

	// 	(22)		BT										1rDc
	float32_t BT_f32[5]; // Static variable

	// 	(23)		CuBT									1rDc
	float32_t CuBT_f32[4];

	// 	(24)		BCuBT									DrDc
	float32_t BCuBT_f32[16];

	// 	(25)		AT										DrDc
	float32_t AT_f32[16]; // Static variable

	// 	(26)		MSEestAT								DrDc
	float32_t MSEestAT_f32[16];

	// 	(27)		AMSEestAT								DrDc
	float32_t AMSEestAT_f32[16];

};

void kalman_filter_MD_static( struct Matrix_DataMD* Matrix_Data , float32_t y );

#endif /* FILTERS_KALMAN_MD_STATIC_KALMAN_FILTER_MD_STATIC_H_ */
