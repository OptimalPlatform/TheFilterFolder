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
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

//functions
void BSP_Pointer_Update(void);

#endif /* MAIN_H_ */
