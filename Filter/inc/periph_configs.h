/*
 * periph_configs.h
 *
 *  Created on: 27 apr. 2018
 *      Author: Myren
 */

#ifndef PERIPH_CONFIGS_H_
#define PERIPH_CONFIGS_H_

#include "stm32f4xx.h"
#include "stm32f429xx.h"
#include "stm32f4xx_hal.h"
#include <stdint.h>
#include <stdlib.h>





void initADC_DAC(uint16_t *bufferIn1, uint16_t *bufferIn2, uint16_t *bufferIn3,
					uint16_t *bufferOut1, uint16_t *bufferOut2, uint16_t bufferSize);

//void initUART(uint32_t BAUD);
//void UART_puts(uint8_t* data, uint16_t size);



#endif /* PERIPH_CONFIGS_H_ */
