/*
 * matrix_initialize_4D.c
 *
 *  Created on: 28 dec. 2018
 *      Author: User
 */



#include "matrix_initialize_4D.h"



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
void matrix_initialize_4D(struct Matrix_DataMD* Matrix_Data, struct Data4D* Data, uint32_t dim) {

	uint32_t srcRows, srcColumns;  /* Temporary variables */
	//arm_status status;


	// (1) 			x_est 									2r1c
	srcRows = dim;
	srcColumns = 1;
	arm_mat_init_f32(&(Matrix_Data->x_est), srcRows, srcColumns, (float32_t *)(Data->x_est_f32));

	// (2) 			x_pred 									2r1c
	srcRows = dim;
	srcColumns = 1;
	arm_mat_init_f32(&(Matrix_Data->x_pred), srcRows, srcColumns, (float32_t *)(Data->x_pred_f32));

	// (3) 			A 										2r2c
	srcRows = dim;
	srcColumns = dim;
	arm_mat_init_f32(&(Matrix_Data->A), srcRows, srcColumns, (float32_t *)(Data->A_f32));

	// (4) 			B 										2r1c
	srcRows = dim;
	srcColumns = 1;
	arm_mat_init_f32(&(Matrix_Data->B), srcRows, srcColumns, (float32_t *)(Data->B_f32));

	// (5) 			H 										1r2c
	srcRows = 1;
	srcColumns = dim;
	arm_mat_init_f32(&(Matrix_Data->H), srcRows, srcColumns, (float32_t *)(Data->H_f32));

	// (6) 			HT										2r1c
	srcRows = dim;
	srcColumns = 1;
	arm_mat_init_f32(&(Matrix_Data->HT), srcRows, srcColumns, (float32_t *)(Data->HT_f32));

	// (7) 			C_w										1r1c
	srcRows = 1;
	srcColumns = 1;
	arm_mat_init_f32(&(Matrix_Data->C_w), srcRows, srcColumns, (float32_t *)(Data->C_w_f32));

	// (8) 			C_u										1r1c
	srcRows = 1;
	srcColumns = 1;
	arm_mat_init_f32(&(Matrix_Data->C_u), srcRows, srcColumns, (float32_t *)(Data->C_u_f32));

	// (9) 			MSEpred									2r2c
	srcRows = dim;
	srcColumns = dim;
	arm_mat_init_f32(&(Matrix_Data->MSE_pred), srcRows, srcColumns, (float32_t *)(Data->MSE_pred_f32));

	// (10) 		MSEpredHT								2r1c
	srcRows = dim;
	srcColumns = 1;
	arm_mat_init_f32(&(Matrix_Data->MSEpredHT), srcRows, srcColumns, (float32_t *)(Data->MSEpredHT_f32));

	// (11) 		MSEest									2r2c
	srcRows = dim;
	srcColumns = dim;
	arm_mat_init_f32(&(Matrix_Data->MSE_est), srcRows, srcColumns, (float32_t *)(Data->MSE_est_f32));

	// (12) 		HMSEpredHT								1r1c
	srcRows = 1;
	srcColumns = 1;
	arm_mat_init_f32(&(Matrix_Data->HMSEpredHT), srcRows, srcColumns, (float32_t *)(Data->HMSEpredHT_f32));

	// (13) 		HMSEpredHTplusCw						1r1c
	srcRows = 1;
	srcColumns = 1;
	arm_mat_init_f32(&(Matrix_Data->HMSEpredHTplusCw), srcRows, srcColumns, (float32_t *)(Data->HMSEpredHTplusCw_f32));

	// (14) 		invOfHMSEpredHTplusCw					1r1c
	srcRows = 1;
	srcColumns = 1;
	arm_mat_init_f32(&(Matrix_Data->invOfHMSEpredHTplusCw), srcRows, srcColumns, (float32_t *)(Data->invOfHMSEpredHTplusCw_f32));

	// (15) 		K (MSEpredHTinvOfHMSEpredHTplusCw)		2r1c
	srcRows = dim;
	srcColumns = 1;
	arm_mat_init_f32(&(Matrix_Data->K), srcRows, srcColumns, (float32_t *)(Data->K_f32));

	// (16) 		Hxpred									1r1c
	srcRows = 1;
	srcColumns = 1;
	arm_mat_init_f32(&(Matrix_Data->Hxpred), srcRows, srcColumns, (float32_t *)(Data->Hxpred_f32));

	// (17) 		yminusHxpred							1r1c
	srcRows = 1;
	srcColumns = 1;
	arm_mat_init_f32(&(Matrix_Data->yminusHxpred), srcRows, srcColumns, (float32_t *)(Data->yminusHxpred_f32));

	// (18) 		correction (KyminusHxpred)				2r1c
	srcRows = dim;
	srcColumns = 1;
	arm_mat_init_f32(&(Matrix_Data->correction), srcRows, srcColumns, (float32_t *)(Data->correction_f32));

	// (19) 		KH										2r2c
	srcRows = dim;
	srcColumns = dim;
	arm_mat_init_f32(&(Matrix_Data->KH), srcRows, srcColumns, (float32_t *)(Data->KH_f32));

	// (20) 		I										2r2c
	srcRows = dim;
	srcColumns = dim;
	arm_mat_init_f32(&(Matrix_Data->I), srcRows, srcColumns, (float32_t *)(Data->I_f32));

	// (21) 		IminusKH								2r2c
	srcRows = dim;
	srcColumns = dim;
	arm_mat_init_f32(&(Matrix_Data->IminusKH), srcRows, srcColumns, (float32_t *)(Data->IminusKH_f32));

	// (22) 		BT										1r2c
	srcRows = 1;
	srcColumns = dim;
	arm_mat_init_f32(&(Matrix_Data->BT), srcRows, srcColumns, (float32_t *)(Data->BT_f32));

	// (23) 		CuBT									1r2c
	srcRows = 1;
	srcColumns = dim;
	arm_mat_init_f32(&(Matrix_Data->CuBT), srcRows, srcColumns, (float32_t *)(Data->CuBT_f32));

	// (24) 		BCuBT									2r2c
	srcRows = dim;
	srcColumns = dim;
	arm_mat_init_f32(&(Matrix_Data->BCuBT), srcRows, srcColumns, (float32_t *)(Data->BCuBT_f32));

	// (25) 		AT										2r2c
	srcRows = dim;
	srcColumns = dim;
	arm_mat_init_f32(&(Matrix_Data->AT), srcRows, srcColumns, (float32_t *)(Data->AT_f32));

	// (26) 		MSEestAT								2r2c
	srcRows = dim;
	srcColumns = dim;
	arm_mat_init_f32(&(Matrix_Data->MSEestAT), srcRows, srcColumns, (float32_t *)(Data->MSEestAT_f32));

	// (27) 		AMSEestAT								2r2c
	srcRows = dim;
	srcColumns = dim;
	arm_mat_init_f32(&(Matrix_Data->AMSEestAT), srcRows, srcColumns, (float32_t *)(Data->AMSEestAT_f32));


	// Comment:
	// 		Should I put C_w and C_u to scalars instead?






	srcRows = dim;
	srcColumns = 1;
	//arm_mat_init_f32(&(Matrix_Data->MSEpredHT), srcRows, srcColumns, (float32_t *)(Data->MSEpredHT_f32));

	srcRows = dim;
	srcColumns = 1;
	//arm_mat_init_f32(&(Matrix_Data->MSEpredHT), srcRows, srcColumns, (float32_t *)(Data->MSEpredHT_f32));

}



// Example:
/* Initialize x_est Matrix Instance with numRows, numCols and data array(x_est_f32) */
