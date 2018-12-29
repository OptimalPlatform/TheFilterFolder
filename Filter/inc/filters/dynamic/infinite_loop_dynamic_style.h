/*
 * infinite_loop_dynamic_style.h
 *
 *  Created on: 27 dec. 2018
 *      Author: User
 */

#ifndef FILTERS_DYNAMIC_INFINITE_LOOP_DYNAMIC_STYLE_H_
#define FILTERS_DYNAMIC_INFINITE_LOOP_DYNAMIC_STYLE_H_

#include <stdint.h>

void infinite_loop_dynamic_style(	volatile uint8_t* ADC1HalfBuffer, volatile uint8_t* ADC1FullBuffer,
									volatile uint8_t* ADC2HalfBuffer, volatile uint8_t* ADC2FullBuffer,
									volatile uint8_t* ADC3HalfBuffer, volatile uint8_t* ADC3FullBuffer,
									uint16_t* ADC1InBuff, uint16_t* ADC2InBuff,
									uint16_t* ADC3InBuff, uint16_t* DAC1OutBuff,
									uint16_t* DAC2OutBuff, uint16_t* appBuff,
									uint32_t BUFFER_SIZE);

#endif /* FILTERS_DYNAMIC_INFINITE_LOOP_DYNAMIC_STYLE_H_ */
