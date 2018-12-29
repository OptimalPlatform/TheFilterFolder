/* infinite_loop_kalman_style_int.c
 *
 *  Created on: 26 nov. 2018
 *      Author: User
 */

//#include "stdint.h" // To get uint16_t (Could also use inttypes.h)
#include "kalman_filter_int.h" //kalman_filter(y, x_pred, MSE_pred, A, B, H, C_w, C_u);

/*
 * Notation:
 * 			For notation on the variables used here, see kalman_filter.c.
 * Note:
 * 		If I fix the signals as:
 * 		// Dynamic variables
 *		Data.x_est = 1;
 *		Data.x_pred = 0;
 *		Data.MSE_pred = 1;
 *
 *		// Fixed variables
 *		Data.A = 1;
 *		Data.B = 1;
 * 		Data.H = 1;
 *		Data.C_w = 4;
 * 		Data.C_u = 1;
 *
 * 		I get an output that seems nice.
 */
void infinite_loop_kalman_style_int(	volatile uint8_t* ADC1HalfBuffer, volatile uint8_t* ADC1FullBuffer,
										volatile uint8_t* ADC2HalfBuffer, volatile uint8_t* ADC2FullBuffer,
										volatile uint8_t* ADC3HalfBuffer, volatile uint8_t* ADC3FullBuffer,
										uint16_t* ADC1InBuff, uint16_t* ADC2InBuff,
										uint16_t* ADC3InBuff, uint16_t* DAC1OutBuff,
										uint16_t* DAC2OutBuff, uint16_t* appBuff,
										uint32_t BUFFER_SIZE) // Should BUFFER_SIZE really be 32 long. The for loops below are 16 long.
{

	struct Data1D_int Data;

	// choose the above variables
	//interface(&choose_variables, Data);

	// Start of debug part ====================================

	// Dynamic variables
	Data.x_est = 1;
	Data.x_pred = 0;
	Data.MSE_pred = 1;

	// Fixed variables
	Data.A = 1; // Should A not be a sinusoid here?
	Data.B = 1;
	Data.H = 1;
	Data.C_w = 4;
	Data.C_u = 1;

	// Offset from OP-amp
	int32_t offset = 0; // Should correspond to 1.5 V. Find out what that value is!

	// End of debug part ========================================


	/*
	 * Here we can have a function that checks what offset is added
	 * It should read the value and store it as <code>offset<code>.
	 * - In this function we need to read the other ADC_port.
	 * - How should this be done? With a finite for-loop?
	 * - Maybe this should be called from main.c instead?
	 *   It might look cleaner to call it from here thou!
	 *
	 * To do:
	 * 		Create a file/function called find_offset()
	 */

	for(;;)
		{
			while(!*ADC1HalfBuffer); // Question: Do I need extra parentheses around *ADC1HalfBuffer?
			for(uint16_t i=0; i<BUFFER_SIZE/2; i++)
			{
				kalman_filter_int(&Data,(int32_t)(ADC1InBuff[i])-offset); // Here, for the int32_t you should be able to send in an offsetted integer!
				DAC1OutBuff[i] = Data.x_est + offset;
				//DAC1OutBuff[i] = ADC1InBuff[i];

			}
			*ADC1HalfBuffer = 0;

			while(!*ADC1FullBuffer);
			for(uint16_t i=0; i<BUFFER_SIZE/2; i++)
			{
				kalman_filter_int(&Data,(int32_t)(ADC1InBuff[i+BUFFER_SIZE/2]) - offset);
				DAC1OutBuff[i+BUFFER_SIZE/2] = Data.x_est + offset;
				//DAC1OutBuff[i+BUFFER_SIZE/2] = ADC1InBuff[i+BUFFER_SIZE/2];
			}
			*ADC1FullBuffer = 0;
		}
}
