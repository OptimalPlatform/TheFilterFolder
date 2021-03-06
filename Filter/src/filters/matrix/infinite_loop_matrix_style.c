/*
 * infinite_loop_matrix_style.c
 *
 *  Created on: 19 dec. 2018
 *      Author: User
 */




#include "arm_math.h"

#include "stdint.h" // To get uint16_t (Could also use inttypes.h)
//#include "kalman_filter_vector_edition.h" //kalman_filter(y, x_pred, MSE_pred, A, B, H, C_w, C_u);

//#include "data_instances.h"
#include "matrix_filter.h"


/*
 * 	function for checking that the matrix library works.
 */
void infinite_loop_matrix_style(	volatile uint8_t* ADC1HalfBuffer, volatile uint8_t* ADC1FullBuffer,
									volatile uint8_t* ADC2HalfBuffer, volatile uint8_t* ADC2FullBuffer,
									volatile uint8_t* ADC3HalfBuffer, volatile uint8_t* ADC3FullBuffer,
									uint16_t* ADC1InBuff, uint16_t* ADC2InBuff,
									uint16_t* ADC3InBuff, uint16_t* DAC1OutBuff,
									uint16_t* DAC2OutBuff, uint16_t* appBuff,
									uint32_t BUFFER_SIZE) // Should BUFFER_SIZE really be 32 long. The for loops below are 16 long.
{

	struct Matrix_Data_exp Matrix_Data;

	struct DataMat Data;

	/* ------------------------------------	*/
	/* 			Start of debug area 		*/
	/* ____________________________________	*/



	Data.yo_f32[0] = 2;
	Data.yo_f32[1] = 1;
	Data.yo_f32[2] = 0.5;
	Data.yo_f32[3] = 0;

	Data.hello_f32[0] = 1;
	Data.hello_f32[1] = 0.5;




	/* ------------------------------------	*/
	/* 			End of debug area 			*/
	/* ____________________________________	*/


	/* -------------------------------------------- */
	/* 			Start: Matrix initialization 		*/
	/* _____________________________________________*/

	uint32_t srcRows, srcColumns;  /* Temporary variables */
	//arm_status status;

	/* Initialize x_est Matrix Instance with numRows, numCols and data array(x_est_f32) */
	srcRows = 2;
	srcColumns = 2;
	arm_mat_init_f32(&(Matrix_Data.yo), srcRows, srcColumns, (float32_t *)(Data.yo_f32));

	srcRows = 2;
	srcColumns = 2;
	arm_mat_init_f32(&(Matrix_Data.yoScale), srcRows, srcColumns, (float32_t *)(Data.yoScale_f32));


	srcRows = 2;
	srcColumns = 1;
	arm_mat_init_f32(&(Matrix_Data.hello), srcRows, srcColumns, (float32_t *)(Data.hello_f32));

	srcRows = 1;
	srcColumns = 2;
	arm_mat_init_f32(&(Matrix_Data.helloT), srcRows, srcColumns, (float32_t *)(Data.helloT_f32));

	srcRows = 2;
	srcColumns = 1;
	arm_mat_init_f32(&(Matrix_Data.yoHello), srcRows, srcColumns, (float32_t *)(Data.yoHello_f32));

	srcRows = 2;
	srcColumns = 1;
	arm_mat_init_f32(&(Matrix_Data.buffer_2r1c), srcRows, srcColumns, (float32_t *)(Data.buffer_2r1c_f32));

	srcRows = 1;
	srcColumns = 2;
	arm_mat_init_f32(&(Matrix_Data.buffer_1r2c), srcRows, srcColumns, (float32_t *)(Data.buffer_1r2c_f32));

	srcRows = 2;
	srcColumns = 2;
	arm_mat_init_f32(&(Matrix_Data.buffer_2r2c), srcRows, srcColumns, (float32_t *)(Data.buffer_2r2c_f32));

	srcRows = 1;
	srcColumns = 1;
	arm_mat_init_f32(&(Matrix_Data.y_mat), srcRows, srcColumns, (float32_t *)(Data.y_f32));





	/* -------------------------------------------- */
	/* 			End: Matrix initialization 			*/
	/* _____________________________________________*/



	for(;;)
		{
			while(!*ADC1HalfBuffer); // Question: Do I need extra parentheses around *ADC1HalfBuffer?
			for(uint16_t i=0; i<BUFFER_SIZE/2; i++)
			{
				matrix_filter(&Matrix_Data,(float32_t)ADC1InBuff[i]);
				DAC1OutBuff[i] = Matrix_Data.buffer_1r2c.pData[0];
			}
			*ADC1HalfBuffer = 0;

			while(!*ADC1FullBuffer);
			for(uint16_t i=0; i<BUFFER_SIZE/2; i++)
			{
				matrix_filter(&Matrix_Data,(float32_t)ADC1InBuff[i+BUFFER_SIZE/2]);
				DAC1OutBuff[i+BUFFER_SIZE/2] = Matrix_Data.buffer_1r2c.pData[0];
			}
			*ADC1FullBuffer = 0;
		}
}
