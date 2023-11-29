/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
extern uint32_t FreeRTOSRunTimeTicks; // FreeRTOS Run Time ticks counter
extern uint32_t TimeStamp; // 世界时间对应的时间戳
extern uint8_t NRF24L01_rxdata[32];

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
/**
 * @brief 北京时间结构体
 * 
 */
typedef struct
{
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
} TimeStruct;

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
#ifndef RETURN_ERROR
    #define RETURN_ERROR 0xFFFFFFFF
#endif // !RETURN_ERROR
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_T_Pin GPIO_PIN_13
#define LED_T_GPIO_Port GPIOC
#define NSS1_Pin GPIO_PIN_4
#define NSS1_GPIO_Port GPIOA
#define nRF24_IRQ_Pin GPIO_PIN_0
#define nRF24_IRQ_GPIO_Port GPIOB
#define NSS2_Pin GPIO_PIN_12
#define NSS2_GPIO_Port GPIOB
#define CE_Pin GPIO_PIN_8
#define CE_GPIO_Port GPIOA
#define KEY1_Pin GPIO_PIN_11
#define KEY1_GPIO_Port GPIOA
#define KEY2_Pin GPIO_PIN_12
#define KEY2_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
