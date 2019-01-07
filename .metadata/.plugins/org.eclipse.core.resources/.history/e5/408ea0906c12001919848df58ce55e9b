/*
 * main.h
 *
 *  Created on: 23 nov. 2018
 *      Author: User
 */

#ifndef MAIN_H_
#define MAIN_H_

// Do nothing yet!

/* Includes ------------------------------------------------------------------*/
#include "stm32f429xx.h"
#include "stm32f4xx_hal.h"
#include "GUI.h"
#include "WM.h"
#include "stm32f429i_discovery.h"
#include "stm32f429i_discovery_ts.h"
#include "stm32f429i_discovery_sdram.h"
#include "../Components/ili9341/ili9341.h"
#include "parameters.h"
#include "interfaceMain.h"

#include "infinite_loop_simple_style.h"
#include "infinite_loop_kalman_style.h"
#include "infinite_loop_struct_style.h"
#include "infinite_loop_kalman_style_int.h"
#include "infinite_loop_kalman_style_2D.h"
#include "infinite_loop_kalman_style_3D.h"
#include "infinite_loop_kalman_style_4D.h"

#include "infinite_loop_matrix_style.h"
#include "infinite_loop_dynamic_style.h"
#include "infinite_loop_kalman_style_MD_static.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

#define BUFFER_SIZE 200


// ADC buffer flags
volatile uint8_t ADC1HalfBuffer;
volatile uint8_t ADC1FullBuffer;
volatile uint8_t ADC2HalfBuffer;
volatile uint8_t ADC2FullBuffer;
volatile uint8_t ADC3HalfBuffer;
volatile uint8_t ADC3FullBuffer;

// Buffers for ADC's and DAC'
uint16_t ADC1InBuff[BUFFER_SIZE];
uint16_t ADC2InBuff[BUFFER_SIZE];
uint16_t ADC3InBuff[BUFFER_SIZE];
uint16_t DAC1OutBuff[BUFFER_SIZE];
uint16_t DAC2OutBuff[BUFFER_SIZE];

// Buffers for Application
uint16_t appBuff[BUFFER_SIZE];
//functions
void BSP_Pointer_Update(void);
void MainTask(void);

#endif /* MAIN_H_ */
