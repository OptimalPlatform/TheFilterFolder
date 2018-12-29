/*
 * infinite_loop_kalman_style_vector_edition.h
 *
 *  Created on: 3 dec. 2018
 *      Author: User
 */

#ifndef INFINITE_LOOP_KALMAN_STYLE_2D_H_
#define INFINITE_LOOP_KALMAN_STYLE_2D_H_

#include "parameters.h"

// Should aI not have include stdint here?!!

void infinite_loop_kalman_style_2D(	volatile uint8_t* ADC1HalfBuffer, volatile uint8_t* ADC1FullBuffer,
												volatile uint8_t* ADC2HalfBuffer, volatile uint8_t* ADC2FullBuffer,
												volatile uint8_t* ADC3HalfBuffer, volatile uint8_t* ADC3FullBuffer,
												uint16_t* ADC1InBuff, uint16_t* ADC2InBuff,
												uint16_t* ADC3InBuff, uint16_t* DAC1OutBuff,
												uint16_t* DAC2OutBuff, uint16_t* appBuff,
												uint32_t BUFFER_SIZE, struct Params* Parameters);

#endif /* INFINITE_LOOP_KALMAN_STYLE_2D_H_ */
