/*
 * infinite_loop_struct_style.c
 *
 *  Created on: 26 nov. 2018
 *      Author: User
 */

#include "struct_filter.h"

void infinite_loop_struct_style(	volatile uint8_t* ADC1HalfBuffer, volatile uint8_t* ADC1FullBuffer,
									volatile uint8_t* ADC2HalfBuffer, volatile uint8_t* ADC2FullBuffer,
									volatile uint8_t* ADC3HalfBuffer, volatile uint8_t* ADC3FullBuffer,
									uint16_t* ADC1InBuff, uint16_t* ADC2InBuff,
									uint16_t* ADC3InBuff, uint16_t* DAC1OutBuff,
									uint16_t* DAC2OutBuff, uint16_t* appBuff,
									uint32_t BUFFER_SIZE)
{

	//interface(&choose_variables);

	struct DataTest Data;

	for(;;)
		{
			while(!*ADC1HalfBuffer); // Question: Do I need extra parentheses around *ADC1HalfBuffer?
			for(uint16_t i=0; i<BUFFER_SIZE/2; i++)
			{
				struct_filter(&Data,ADC1InBuff[i]);
				DAC1OutBuff[i] = Data.test;
				//DAC1OutBuff[i] = ADC1InBuff[i];

			}
			*ADC1HalfBuffer = 0;

			while(!*ADC1FullBuffer);
			for(uint16_t i=0; i<BUFFER_SIZE/2; i++)
			{
				struct_filter(&Data,ADC1InBuff[i+BUFFER_SIZE/2]);
				DAC1OutBuff[i+BUFFER_SIZE/2] = Data.test;
				//DAC1OutBuff[i+BUFFER_SIZE/2] = ADC1InBuff[i+BUFFER_SIZE/2];
			}
			*ADC1FullBuffer = 0;
		}
}
