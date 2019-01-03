/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "main.h" 	// Read that I never ever should include definitions (allocating of memory)
// in a header file so maybe I have to re-do this!
//Interface
#include "WM.h"
#include "GUI.h"

// ===========================================

#include "stm32f4xx.h"
#include "stm32f429i_discovery.h"
#include "periph_configs.h"

//#include "kalman_filter.h"
//#include "simple_filter.h"

static void SystemClock_Config(void);

static void BSP_Config(void);
void BSP_Background(void);

uint8_t GUI_Initialized = 0;
TIM_HandleTypeDef TimHandle;
uint32_t uwPrescalerValue = 0;

// ===========================================

int main(void) {

	HAL_Init();

	/* Initialize LCD and LEDs */
	BSP_Config();

	SystemClock_Config();
	//initADC_DAC(ADC1InBuff, ADC2InBuff, ADC3InBuff, DAC1OutBuff, DAC2OutBuff,BUFFER_SIZE);

	/* Compute the prescaler value to have TIM3 counter clock equal to 10 KHz */
	uwPrescalerValue = (uint32_t) ((SystemCoreClock / 2) / 10000) - 1;

	/* Set TIMx instance */
	TimHandle.Instance = TIM3;

	/* Initialize TIM3 peripheral as follows:
	 + Period = 500 - 1
	 + Prescaler = ((SystemCoreClock/2)/10000) - 1
	 + ClockDivision = 0
	 + Counter direction = Up
	 */
	TimHandle.Init.Period = 500 - 1;
	TimHandle.Init.Prescaler = uwPrescalerValue;
	TimHandle.Init.ClockDivision = 0;
	TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;
	if (HAL_TIM_Base_Init(&TimHandle) != HAL_OK) {
		while (1) {
		}
	}

	/*##-2- Start the TIM Base generation in interrupt mode ####################*/
	/* Start Channel1 */
	if (HAL_TIM_Base_Start_IT(&TimHandle) != HAL_OK) {
		while (1) {

		}
	}

	/***********************************************************/

	/* Init the STemWin GUI Library */
	GUI_Init();
	GUI_SetFont(&GUI_Font24_ASCII);
	GUI_Initialized = 1;

	GUI_Clear();
	GUI_DispString("Snyggt");

	/* Activate the use of memory device feature */
	WM_SetCreateFlags(WM_CF_MEMDEV);

	MainTask();

	while (1)
		;
}

/**
 * @brief  Period elapsed callback in non blocking mode
 * @param  htim: TIM handle
 * @retval None
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	BSP_Background();
}

// Synchronization for ADC1 buffer
void DMA2_Stream0_IRQHandler(void) {
	// Half transfer complete interrupt?
	if (DMA2->LISR & (1 << 4)) {
		// Clear interrupt flag
		DMA2->LIFCR |= 1 << 4;
		ADC1HalfBuffer = 1;
	}
	// Transfer complete interrupt?
	else if (DMA2->LISR & (1 << 5)) {
		// Clear interrupt flag
		DMA2->LIFCR |= 1 << 5;
		ADC1FullBuffer = 1;
	}
}

/**
 * @brief TIM MSP Initialization
 *        This function configures the hardware resources used in This application:
 *           - Peripheral's clock enable
 *           - Peripheral's GPIO Configuration
 * @param htim: TIM handle pointer
 * @retval None
 */
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim) {
	/*##-1- Enable peripherals and GPIO Clocks #################################*/
	/* TIMx Peripheral clock enable */
	__HAL_RCC_TIM3_CLK_ENABLE()
	;

	/*##-2- Configure the NVIC for TIMx ########################################*/
	/* Set the TIMx priority */
	HAL_NVIC_SetPriority(TIM3_IRQn, 0, 1);

	/* Enable the TIMx global Interrupt */
	HAL_NVIC_EnableIRQ(TIM3_IRQn);
}

// Synchronization for ADC2 buffer
void DMA2_Stream2_IRQHandler(void) {
	if (DMA2->LISR & (1 << 20)) {
		// Clear interrupt flag
		DMA2->LIFCR |= 1 << 20;
		ADC2HalfBuffer = 1;
	}
	// Transfer complete interrupt?
	else if (DMA2->LISR & (1 << 21)) {
		// Clear interrupt flag
		DMA2->LIFCR |= 1 << 21;
		ADC2FullBuffer = 1;
	}
}

// Synchronization for ADC3 buffer
void DMA2_Stream1_IRQHandler(void) {
	// Half transfer complete interrupt?
	if (DMA2->LISR & (1 << 10)) {
		// Clear interrupt flag
		DMA2->LIFCR |= 1 << 10;
		ADC3HalfBuffer = 1;
	}
	// Transfer complete interrupt?
	else if (DMA2->LISR & (1 << 11)) {
		// Clear interrupt flag
		DMA2->LIFCR |= 1 << 11;
		ADC3FullBuffer = 1;
	}
}

/**
 * @brief  BSP_Background.
 * @param  None
 * @retval None
 */
void BSP_Background(void) {
	BSP_LED_Toggle(LED3);
	BSP_LED_Toggle(LED4);

	/* Capture input event and update cursor */
	if (GUI_Initialized == 1) {
		BSP_Pointer_Update();
	}
}

/**
 * @brief  Initializes the STM32F429I-DISCO's LCD and LEDs resources.
 * @param  None
 * @retval None
 */
static void BSP_Config(void) {
	/* Initialize STM32F429I-DISCO's LEDs */
	BSP_LED_Init(LED3);
	BSP_LED_Init(LED4);

	/* Initializes the SDRAM device */
	BSP_SDRAM_Init();

	/* Initialize the Touch screen */
	if (BSP_TS_Init(240, 320) != TS_OK) {
		while (1)
			;
	}

	/* Enable the CRC Module */
	__HAL_RCC_CRC_CLK_ENABLE()
	;
}

/**
 * @brief  Provide the GUI with current state of the touch screen
 * @param  None
 * @retval None
 */

void BSP_Pointer_Update(void) {
	GUI_PID_STATE TS_State;
	static TS_StateTypeDef prev_state;
	TS_StateTypeDef ts;
	uint16_t xDiff, yDiff;

	BSP_TS_GetState(&ts);

	TS_State.Pressed = 0;
	if (ts.TouchDetected == 1) {
		TS_State.Pressed = 1;
	}

	xDiff = (prev_state.X > ts.X) ?
			(prev_state.X - ts.X) : (ts.X - prev_state.X);
	yDiff = (prev_state.Y > ts.Y) ?
			(prev_state.Y - ts.Y) : (ts.Y - prev_state.Y);

	if (ts.TouchDetected) {
		if ((prev_state.TouchDetected != ts.TouchDetected) || (xDiff > 3)
				|| (yDiff > 3)) {
			prev_state = ts;

			TS_State.Layer = 0;
			TS_State.x = ts.X;
			TS_State.y = ts.Y;
			GUI_TOUCH_StoreStateEx(&TS_State);
		}
	} else {
		TS_State.Layer = 0;
		TS_State.x = -1;
		TS_State.y = -1;
		GUI_TOUCH_StoreStateEx(&TS_State);
	}
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
static void SystemClock_Config(void) {

	RCC_OscInitTypeDef RCC_OscInitStruct;
	RCC_ClkInitTypeDef RCC_ClkInitStruct;

	//Configure the main internal regulator output voltage

	__HAL_RCC_PWR_CLK_ENABLE()
	;

	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	//Initializes the CPU, AHB and APB busses clocks

	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = 16;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 16; // 1MHz clock input to PLL
	RCC_OscInitStruct.PLL.PLLN = 360; // PLL multiplier, output of PLL = 1*360 = 360MHz
	RCC_OscInitStruct.PLL.PLLP = 2; // System clock = output of PLL / 2 = 180MHz
	RCC_OscInitStruct.PLL.PLLQ = 7;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		//_Error_Handler(__FILE__, __LINE__);
	}

	//Initializes the CPU, AHB and APB busses clocks

	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK) {
		//_Error_Handler(__FILE__, __LINE__);
	}

	//Configure the Systick interrupt time

	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq() / 1000);

	//*Configure the Systick

	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
	SystemCoreClockUpdate();
	// SysTick_IRQn interrupt configuration
	HAL_NVIC_SetPriority(SysTick_IRQn, 15, 0);
}

