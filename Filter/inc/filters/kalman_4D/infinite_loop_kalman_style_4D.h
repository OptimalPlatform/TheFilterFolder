/*
 * infinite_loop_kalman_style_4D.h
 *
 *  Created on: 28 dec. 2018
 *      Author: User
 */
#include "parameters.h"

#ifndef FILTERS_KALMAN_4D_INFINITE_LOOP_KALMAN_STYLE_4D_H_
#define FILTERS_KALMAN_4D_INFINITE_LOOP_KALMAN_STYLE_4D_H_

void infinite_loop_kalman_style_4D(	volatile uint8_t* ADC1HalfBuffer, volatile uint8_t* ADC1FullBuffer,
												volatile uint8_t* ADC2HalfBuffer, volatile uint8_t* ADC2FullBuffer,
												volatile uint8_t* ADC3HalfBuffer, volatile uint8_t* ADC3FullBuffer,
												uint16_t* ADC1InBuff, uint16_t* ADC2InBuff,
												uint16_t* ADC3InBuff, uint16_t* DAC1OutBuff,
												uint16_t* DAC2OutBuff, uint16_t* appBuff,
												uint32_t BUFFER_SIZE, struct Params* Parameters);

#endif /* FILTERS_KALMAN_4D_INFINITE_LOOP_KALMAN_STYLE_4D_H_ */
