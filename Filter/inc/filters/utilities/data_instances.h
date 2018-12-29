/*
 * data_instances.h
 *
 *  Created on: 15 dec. 2018
 *      Author: User
 */

#ifndef DATA_INSTANCES_H_
#define DATA_INSTANCES_H_

#include "arm_math.h"

/*
 * This struct contains matrix instances of the parameters necessary for kalman
 * filter calculation as well as extra matrix instances for the calculations
 */
struct Matrix_DataMD {
	/* Necessary parameters*/
	// Dynamic variables
	arm_matrix_instance_f32 x_est;
	arm_matrix_instance_f32 x_pred;
	arm_matrix_instance_f32 MSE_pred;
	arm_matrix_instance_f32 MSE_est;
	// Fixed variables (For now)
	arm_matrix_instance_f32 A;
	arm_matrix_instance_f32 B;
	arm_matrix_instance_f32 H;
	arm_matrix_instance_f32 C_w;
	arm_matrix_instance_f32 C_u;
	arm_status status;

	/* Extra parameters: */

	/* For Utilities calculation: */
	arm_matrix_instance_f32 HT;
	arm_matrix_instance_f32 MSEpredHT;
	arm_matrix_instance_f32 HMSEpredHT;
	arm_matrix_instance_f32 HMSEpredHTplusCw;
	arm_matrix_instance_f32 invOfHMSEpredHTplusCw;
	arm_matrix_instance_f32 K; //MSEpredHTinvOfHMSEpredHTplusCw;
	arm_matrix_instance_f32 correction;
	arm_matrix_instance_f32 Hxpred;
	arm_matrix_instance_f32 yminusHxpred;
	arm_matrix_instance_f32 KH;
	arm_matrix_instance_f32 I;
	arm_matrix_instance_f32 IminusKH;

	arm_matrix_instance_f32 BT;
	arm_matrix_instance_f32 CuBT;
	arm_matrix_instance_f32 BCuBT;
	arm_matrix_instance_f32 AT;
	arm_matrix_instance_f32 MSEestAT;
	arm_matrix_instance_f32 AMSEestAT;

	// Doublets below!
	//arm_matrix_instance_f32 MSEpred;
	//arm_matrix_instance_f32 MSEest;




	/* for signal estimate calculation: */

	/* for MSE estimate calculation: */

	/* for signal prediction calculation: */

	/* for MSE prediction calculation: */

};


/*
 * This struct contains extra matrix instances required for matrix operations.
 */ /*
struct Matrix_DataMD_Utilities {
	// For Kalman gain calculation:
	arm_matrix_instance_f32 HT;
	arm_matrix_instance_f32 MSEpredHT;
	arm_matrix_instance_f32 HMSEpredHT;
	arm_matrix_instance_f32 HMSEpredHTplusCw;
	arm_matrix_instance_f32 invOfHMSEpredHTplusCw;
	arm_matrix_instance_f32 MSEpredHTinvOfHMSEpredHTplusCw;

	// for signal estimate calculation:

	// for MSE estimate calculation:

	// for signal prediction calculation:

	// for MSE prediction calculation:
};
*/


/*
 * This struct contains matrix instances for experimenting with matrix operations.
 * (Might be deleted or moved in the future.)
 */
struct Matrix_Data_exp {
	arm_matrix_instance_f32 yo;
	arm_matrix_instance_f32 yoScale;
	arm_matrix_instance_f32 hello;
	arm_matrix_instance_f32 yoHello;
	arm_matrix_instance_f32 helloT;
	arm_matrix_instance_f32 buffer_2r1c;
	arm_matrix_instance_f32 buffer_1r2c;
	arm_matrix_instance_f32 buffer_2r2c;
	arm_matrix_instance_f32 y_mat;
	arm_status status;
};


#endif /* DATA_INSTANCES_H_ */
