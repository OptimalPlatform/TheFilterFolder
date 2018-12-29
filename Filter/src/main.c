/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


// Hej Olof!

#include "main.h" 	// Read that I never ever should include definitions (allocating of memory)
					// in a header file so maybe I have to re-do this!
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


// ===========================================

#include "stm32f4xx.h"
#include "stm32f429i_discovery.h"
#include "periph_configs.h"
//#include "kalman_filter.h"
//#include "simple_filter.h"

#define BUFFER_SIZE 200

void SystemClock_Config(void);

// ADC buffer flags
volatile uint8_t ADC1HalfBuffer = 0;
volatile uint8_t ADC1FullBuffer = 0;
volatile uint8_t ADC2HalfBuffer = 0;
volatile uint8_t ADC2FullBuffer = 0;
volatile uint8_t ADC3HalfBuffer = 0;
volatile uint8_t ADC3FullBuffer = 0;

// Buffers for ADC's and DAC'
uint16_t ADC1InBuff[BUFFER_SIZE];
uint16_t ADC2InBuff[BUFFER_SIZE];
uint16_t ADC3InBuff[BUFFER_SIZE];
uint16_t DAC1OutBuff[BUFFER_SIZE];
uint16_t DAC2OutBuff[BUFFER_SIZE];

// Buffers for Application
uint16_t appBuff[BUFFER_SIZE];


// ===========================================

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	initADC_DAC(ADC1InBuff, ADC2InBuff, ADC3InBuff,
			    DAC1OutBuff, DAC2OutBuff, BUFFER_SIZE);

	char which_filter = 'J';  // E I J
	//interface(&which filter);

	// To do:
	// 		Create a circuit that subtracts the offset.
	//		This requires a negatve voltage equal to the added offset.
	// 		Idea: Get this negative voltage using an inverting amplifier
	//		(with amplification A = -1).
	// 		(Needs to be done, mostly, at school.)

	// To do:
	// 		Structure the Source and Include files better using sub folders.
	// 		(Can be started with at home. But needs checking at school.)

	// To do:
	//		Start writing Theory on the report.
	// 		Can do from home.

	// To do:
	// 		Start thinking about how to implement a kalman filter with larger ARMA model order.
	// 		Can do from home (partly).

	switch(which_filter) {

		// Case 'S' works. //
	   	case 'A'  :
	   		infinite_loop_simple_style(	&ADC1HalfBuffer, &ADC1FullBuffer, &ADC2HalfBuffer, &ADC2FullBuffer,
										&ADC3HalfBuffer, &ADC3FullBuffer,
										ADC1InBuff, ADC2InBuff,
										ADC3InBuff, DAC1OutBuff,
										DAC2OutBuff, appBuff,
										BUFFER_SIZE);
	      	break;


	    // Case 'X' works. //
	   	case 'B'  :
	   		infinite_loop_struct_style(	&ADC1HalfBuffer, &ADC1FullBuffer, &ADC2HalfBuffer, &ADC2FullBuffer,
	   									&ADC3HalfBuffer, &ADC3FullBuffer,
	   		   							ADC1InBuff, ADC2InBuff,
	   		   							ADC3InBuff, DAC1OutBuff,
	   		   							DAC2OutBuff, appBuff,
	   		   							BUFFER_SIZE);
	   		break;



	   	// Case 'K' does work (but with constant transition and measurement matrix).	//
	   	case 'C'  :
	   		infinite_loop_kalman_style(	&ADC1HalfBuffer, &ADC1FullBuffer, &ADC2HalfBuffer, &ADC2FullBuffer,
	   			   						&ADC3HalfBuffer, &ADC3FullBuffer,
	   			   						ADC1InBuff, ADC2InBuff,
	   			   						ADC3InBuff, DAC1OutBuff,
	   			   						DAC2OutBuff, appBuff,
	   			   						BUFFER_SIZE);
	   		break;



	   	// Case 'I' not tested yet	(Subtracts the offset and deals with negative values)	//
	   						// Remember to change the offset value! //
	   	case 'D' :
	   		infinite_loop_kalman_style_int(	&ADC1HalfBuffer, &ADC1FullBuffer, &ADC2HalfBuffer, &ADC2FullBuffer,
	   		   			   					&ADC3HalfBuffer, &ADC3FullBuffer,
	   										ADC1InBuff, ADC2InBuff,
	   										ADC3InBuff, DAC1OutBuff,
	   										DAC2OutBuff, appBuff,
	   										BUFFER_SIZE);
	   		break;



	   	// Case 'A' not yet implemented . (Extension of case 'I') //
	   	case 'E' :
	   		infinite_loop_kalman_style_2D(	&ADC1HalfBuffer, &ADC1FullBuffer, &ADC2HalfBuffer, &ADC2FullBuffer,
	   			   							&ADC3HalfBuffer, &ADC3FullBuffer,
											ADC1InBuff, ADC2InBuff,
											ADC3InBuff, DAC1OutBuff,
											DAC2OutBuff, appBuff,
											BUFFER_SIZE);
	   		break;



	   	// Case 'M' not yet implemented.  //
	   	case 'F' :
	   		infinite_loop_matrix_style(	&ADC1HalfBuffer, &ADC1FullBuffer, &ADC2HalfBuffer, &ADC2FullBuffer,
	   		   			   				&ADC3HalfBuffer, &ADC3FullBuffer,
	   									ADC1InBuff, ADC2InBuff,
	   									ADC3InBuff, DAC1OutBuff,
	   									DAC2OutBuff, appBuff,
	   									BUFFER_SIZE);
	   		break;

	   	case 'G' :
	   		infinite_loop_dynamic_style( &ADC1HalfBuffer, &ADC1FullBuffer, &ADC2HalfBuffer, &ADC2FullBuffer,
	   		   		   			   		 &ADC3HalfBuffer, &ADC3FullBuffer,
	   		   							 ADC1InBuff, ADC2InBuff,
	   		   							 ADC3InBuff, DAC1OutBuff,
	   		   							 DAC2OutBuff, appBuff,
	   		   							 BUFFER_SIZE);
	   		break;

	   	case 'H' :
	   		infinite_loop_kalman_style_MD_static(	&ADC1HalfBuffer, &ADC1FullBuffer, &ADC2HalfBuffer, &ADC2FullBuffer,
	   		   		   			   		 	 	 	&ADC3HalfBuffer, &ADC3FullBuffer,
													ADC1InBuff, ADC2InBuff,
													ADC3InBuff, DAC1OutBuff,
													DAC2OutBuff, appBuff,
													BUFFER_SIZE);
	   		break;

	   	case 'I' :
	   		infinite_loop_kalman_style_3D(	&ADC1HalfBuffer, &ADC1FullBuffer, &ADC2HalfBuffer, &ADC2FullBuffer,
	   		   		   		   	   		 	&ADC3HalfBuffer, &ADC3FullBuffer,
	   										ADC1InBuff, ADC2InBuff,
	   										ADC3InBuff, DAC1OutBuff,
	   										DAC2OutBuff, appBuff,
	   										BUFFER_SIZE);
	   		break;

	   	case 'J' :
	   		infinite_loop_kalman_style_4D(	&ADC1HalfBuffer, &ADC1FullBuffer, &ADC2HalfBuffer, &ADC2FullBuffer,
	   		   		   		   			   	&ADC3HalfBuffer, &ADC3FullBuffer,
	   										ADC1InBuff, ADC2InBuff,
	   										ADC3InBuff, DAC1OutBuff,
	   										DAC2OutBuff, appBuff,
	   										BUFFER_SIZE);
	   		break;

	  	default :
	  		//print_error_on_screen();
	  		;
	}
}




// Synchronization for ADC1 buffer
void DMA2_Stream0_IRQHandler(void)
{
	// Half transfer complete interrupt?
	if(DMA2->LISR & (1 << 4))
	{
		// Clear interrupt flag
		DMA2->LIFCR |= 1 << 4;
		ADC1HalfBuffer = 1;
	}
	// Transfer complete interrupt?
	else if(DMA2->LISR & (1 << 5))
	{
		// Clear interrupt flag
		DMA2->LIFCR |= 1 << 5;
		ADC1FullBuffer = 1;
	}
}

// Synchronization for ADC2 buffer
void DMA2_Stream2_IRQHandler(void)
{
	if(DMA2->LISR & (1 << 20))
	{
		// Clear interrupt flag
		DMA2->LIFCR |= 1 << 20;
		ADC2HalfBuffer = 1;
	}
	// Transfer complete interrupt?
	else if(DMA2->LISR & (1 << 21))
	{
		// Clear interrupt flag
		DMA2->LIFCR |= 1 << 21;
		ADC2FullBuffer = 1;
	}
}

// Synchronization for ADC3 buffer
void DMA2_Stream1_IRQHandler(void)
{
	// Half transfer complete interrupt?
	if(DMA2->LISR & (1 << 10))
	{
		// Clear interrupt flag
		DMA2->LIFCR |= 1 << 10;
		ADC3HalfBuffer = 1;
	}
	// Transfer complete interrupt?
	else if(DMA2->LISR & (1 << 11))
	{
		// Clear interrupt flag
		DMA2->LIFCR |= 1 << 11;
		ADC3FullBuffer = 1;
	}
}


/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Configure the main internal regulator output voltage
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16; // 1MHz clock input to PLL
  RCC_OscInitStruct.PLL.PLLN = 360; // PLL multiplier, output of PLL = 1*360 = 360MHz
  RCC_OscInitStruct.PLL.PLLP = 2; // System clock = output of PLL / 2 = 180MHz
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    //_Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    //_Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
  SystemCoreClockUpdate();
  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 15, 0);
}



