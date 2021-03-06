/*
 * infinite_loop_dynamic_style.c
 *
 *  Created on: 27 dec. 2018
 *      Author: User
 */

#include "infinite_loop_dynamic_style.h"
#include "test_dynamic_data.h"
#include "allocate_memory_test.h"


void infinite_loop_dynamic_style(	volatile uint8_t* ADC1HalfBuffer, volatile uint8_t* ADC1FullBuffer,
									volatile uint8_t* ADC2HalfBuffer, volatile uint8_t* ADC2FullBuffer,
									volatile uint8_t* ADC3HalfBuffer, volatile uint8_t* ADC3FullBuffer,
									uint16_t* ADC1InBuff, uint16_t* ADC2InBuff,
									uint16_t* ADC3InBuff, uint16_t* DAC1OutBuff,
									uint16_t* DAC2OutBuff, uint16_t* appBuff,
									uint32_t BUFFER_SIZE){

struct Test_Data Data;
uint16_t dim = 2;
allocate_memory_test(&Data,dim);

// To do:
// Figuring out how to reach the freeing of memory.
// With interrupts?

// To do:
// Write matrix initialization that uses the dynamic arrays.

// To do:
// Also try accessing the dynamic arrays directly.

// To do:
// Think about what variables you really need from Olof

// To do.
// Think if we always can have 16 (and 32) large vectors. And just choose how many variables we want to include!


	for(;;)
			{
				while(!*ADC1HalfBuffer); // Question: Do I need extra parentheses around *ADC1HalfBuffer?
				for(uint16_t i=0; i<BUFFER_SIZE/2; i++)
				{
					DAC1OutBuff[i] = ADC1InBuff[i];
				}
				*ADC1HalfBuffer = 0;

				while(!*ADC1FullBuffer);
				for(uint16_t i=0; i<BUFFER_SIZE/2; i++)
				{
					DAC1OutBuff[i+BUFFER_SIZE/2] = ADC1InBuff[i+BUFFER_SIZE/2];
				}
				*ADC1FullBuffer = 0;
			}

	// Need to create some interrupt such that this freeing can be reached.
	free_memory_test(&Data);

}
