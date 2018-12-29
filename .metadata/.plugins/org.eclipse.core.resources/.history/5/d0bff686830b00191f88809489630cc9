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

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
struct FilterState
{
	uint8_t doneFlag;
	char filterType;
	char filterState;
	int filterOrder;
	float initMSE;
	float initValue;

	float R_1;
	float R_2;

	float a_1;
	float a_2;
	float a_3;
	float a_4;

	float b_1;
	float b_2;
	float b_3;
	float b_4;
};


//functions
void FilterChoice(struct FilterState* fState);
void KalmanMenu(struct FilterState* fState);
void WienerMenu(struct FilterState* fState);
int keypad(void);
void BSP_Pointer_Update(void);
void aVecMenu(struct FilterState* fState);
void bVecMenu(struct FilterState* fState);
#endif /* MAIN_H_ */
