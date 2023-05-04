/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "stdio.h"
#include "stdbool.h"
#include <stdlib.h>
#include <stdint.h>
//#include "ws2812/ws2812.h"
//#include  "Button/Button.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */



//#define COL_COUNT	8

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/*
#define M_COL_A	(GPIOF->BSRR|=GPIO_BSRR_BR_11, GPIOB->BSRR|=GPIO_BSRR_BS_7|GPIO_BSRR_BS_6|GPIO_BSRR_BS_5|GPIO_BSRR_BS_4|GPIO_BSRR_BS_3, GPIOA->BSRR|=GPIO_BSRR_BS_15|GPIO_BSRR_BS_11)
#define M_COL_B	(GPIOF->BSRR|=GPIO_BSRR_BS_11, GPIOB->BSRR|=GPIO_BSRR_BR_7|GPIO_BSRR_BS_6|GPIO_BSRR_BS_5|GPIO_BSRR_BS_4|GPIO_BSRR_BS_3, GPIOA->BSRR|=GPIO_BSRR_BS_15|GPIO_BSRR_BS_11)
#define M_COL_C	(GPIOF->BSRR|=GPIO_BSRR_BS_11, GPIOB->BSRR|=GPIO_BSRR_BS_7|GPIO_BSRR_BR_6|GPIO_BSRR_BS_5|GPIO_BSRR_BS_4|GPIO_BSRR_BS_3, GPIOA->BSRR|=GPIO_BSRR_BS_15|GPIO_BSRR_BS_11)
#define M_COL_D	(GPIOF->BSRR|=GPIO_BSRR_BS_11, GPIOB->BSRR|=GPIO_BSRR_BS_7|GPIO_BSRR_BS_6|GPIO_BSRR_BR_5|GPIO_BSRR_BS_4|GPIO_BSRR_BS_3, GPIOA->BSRR|=GPIO_BSRR_BS_15|GPIO_BSRR_BS_11)
#define M_COL_E	(GPIOF->BSRR|=GPIO_BSRR_BS_11, GPIOB->BSRR|=GPIO_BSRR_BS_7|GPIO_BSRR_BS_6|GPIO_BSRR_BS_5|GPIO_BSRR_BR_4|GPIO_BSRR_BS_3, GPIOA->BSRR|=GPIO_BSRR_BS_15|GPIO_BSRR_BS_11)
#define M_COL_F	(GPIOF->BSRR|=GPIO_BSRR_BS_11, GPIOB->BSRR|=GPIO_BSRR_BS_7|GPIO_BSRR_BS_6|GPIO_BSRR_BS_5|GPIO_BSRR_BS_4|GPIO_BSRR_BR_3, GPIOA->BSRR|=GPIO_BSRR_BS_15|GPIO_BSRR_BS_11)
#define M_COL_G	(GPIOF->BSRR|=GPIO_BSRR_BS_11, GPIOB->BSRR|=GPIO_BSRR_BS_7|GPIO_BSRR_BS_6|GPIO_BSRR_BS_5|GPIO_BSRR_BS_4|GPIO_BSRR_BS_3, GPIOA->BSRR|=GPIO_BSRR_BR_15|GPIO_BSRR_BS_11)
#define M_COL_DP	(GPIOF->BSRR|=GPIO_BSRR_BS_11, GPIOB->BSRR|=GPIO_BSRR_BS_7|GPIO_BSRR_BS_6|GPIO_BSRR_BS_5|GPIO_BSRR_BS_4|GPIO_BSRR_BS_3, GPIOA->BSRR|=GPIO_BSRR_BS_15|GPIO_BSRR_BR_11)
*/
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/*
uint8_t col_numb = 0;
uint8_t row_numb = 0;
uint8_t st_kbd = 0;
uint8_t cnt_tick = 10;
uint8_t row_data = 0xFF;
uint8_t but_status;
bool b_butpres;
bool b_enprint;
uint8_t cnt_scan = 0;
uint8_t n_col = 0;
uint8_t n_row = 0;
char test1[64];
uint8_t key[5][8] = {{1,2,3,4,5,6,7,8},
				  {9,10,11,12,13,14,15,16},
				  {17,18,19,20,21,22,23,24},
				  {25,26,27,28,29,30,31,32},
				  {33,34,35,36,37,38,39,40}};

extern uint32_t BUF_DMA [ARRAY_LEN];
uint16_t position_ws=0;
bool led_stat;
*/
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/*
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
		if(htim -> Instance == TIM3){

			keyboard.COL_SCAN();
			keyboard.ROW_SCAN();
		}

		if(htim->Instance == TIM7){


		}
	}
*/
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM3_Init();
  MX_USART1_UART_Init();
  MX_TIM2_Init();
  MX_TIM7_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim3);
  HAL_TIM_Base_Start_IT(&htim7);
//  BUF_DMA[0] = 19;
 // HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
 // HAL_TIM_PWM_Start_DMA(&htim2,TIM_CHANNEL_4,(uint32_t*)&BUF_DMA,1);
//  ws2812_init();
 // ws2812_pixel_rgb_to_buf_dma(0, 128, 128, 2);

 // HAL_TIM_PWM_Start_DMA(&htim2,TIM_CHANNEL_4,(uint32_t*)&BUF_DMA,2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  CppMain();
	  //для индикации только во время нажатия
	/*  if(b_butpres == true){
		  	position_ws = ws_num_led(n_row, n_col);
		    ws2812_init();
		  ws2812_pixel_rgb_to_buf_dma(0, 128, 128, position_ws);
		  HAL_TIM_PWM_Start_DMA(&htim2,TIM_CHANNEL_4,(uint32_t*)&BUF_DMA,ARRAY_LEN);
		  	  b_butpres = false;
	  } if(but_status == 0){
		  ws2812_init();
		  HAL_TIM_PWM_Start_DMA(&htim2,TIM_CHANNEL_4,(uint32_t*)&BUF_DMA,ARRAY_LEN);
	  }
*/
/*
	  if(but_status == 0){
		  ws2812_init();
		  HAL_TIM_PWM_Start_DMA(&htim2,TIM_CHANNEL_4,(uint32_t*)&BUF_DMA,ARRAY_LEN);
	  }
*/
/*
	  if(b_enprint == true){
		  sprintf(test1, "%d\r\n",key[n_row][n_col]);
		  	position_ws = ws_num_led(n_row, n_col);		//для индикации нажатия
		    ws2812_init();
		  ws2812_pixel_rgb_to_buf_dma(0, 128, 128, position_ws);
		  HAL_TIM_PWM_Start_DMA(&htim2,TIM_CHANNEL_4,(uint32_t*)&BUF_DMA,ARRAY_LEN);
		  HAL_UART_Transmit(&huart1, (uint8_t*)&test1, strlen(test1), 100);
		  b_enprint = false;
	  }
*/
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
