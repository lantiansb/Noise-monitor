/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
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
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "cmsis_os.h"
#include "SysConf.h"
    /* USER CODE END Includes */

    /* Exported types ------------------------------------------------------------*/
    /* USER CODE BEGIN ET */
    extern UART_HandleTypeDef huart1;
    extern UART_HandleTypeDef huart2;
    extern UART_HandleTypeDef huart3;
    extern uint8_t txdata[32];     // 用于发送的缓冲区
    extern uint8_t txdata_loc[32]; // 用于发送GPS位置的缓冲区
    extern uint8_t rxdata[32];     // 用于接收的缓冲区
    extern uint8_t Air780_rec_buf[100];
    extern char latitude[20], longitude[20];
    extern char dateStr[11], timeStr[9]; // 根据预期的数据格式分配足够的空间
    extern uint32_t sysTimeStamp;
    extern uint8_t getLocationTimeFlag;
    extern uint32_t ulFLASHFrameIndex;
    extern uint8_t ucFLASHFrame[];

    /* USER CODE END ET */

    /* Exported constants --------------------------------------------------------*/
    /* USER CODE BEGIN EC */

    /* USER CODE END EC */

    /* Exported macro ------------------------------------------------------------*/
    /* USER CODE BEGIN EM */

    /* USER CODE END EM */

    /* Exported functions prototypes ---------------------------------------------*/
    void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_T_Pin GPIO_PIN_13
#define LED_T_GPIO_Port GPIOC
#define NOISE_TX_Pin GPIO_PIN_2
#define NOISE_TX_GPIO_Port GPIOA
#define NOISE_RX_Pin GPIO_PIN_3
#define NOISE_RX_GPIO_Port GPIOA
#define NRF24_CS_Pin GPIO_PIN_4
#define NRF24_CS_GPIO_Port GPIOA
#define NRF24_CLK_Pin GPIO_PIN_5
#define NRF24_CLK_GPIO_Port GPIOA
#define NRF24_READ_Pin GPIO_PIN_6
#define NRF24_READ_GPIO_Port GPIOA
#define NRF24_WRITE_Pin GPIO_PIN_7
#define NRF24_WRITE_GPIO_Port GPIOA
#define NRF24_IRQ_Pin GPIO_PIN_0
#define NRF24_IRQ_GPIO_Port GPIOB
#define GPS_TX_Pin GPIO_PIN_10
#define GPS_TX_GPIO_Port GPIOB
#define GPS_RX_Pin GPIO_PIN_11
#define GPS_RX_GPIO_Port GPIOB
#define FLASH_CS_Pin GPIO_PIN_12
#define FLASH_CS_GPIO_Port GPIOB
#define FLASH_CLK_Pin GPIO_PIN_13
#define FLASH_CLK_GPIO_Port GPIOB
#define FLASH_READ_Pin GPIO_PIN_14
#define FLASH_READ_GPIO_Port GPIOB
#define FLASH_WRITE_Pin GPIO_PIN_15
#define FLASH_WRITE_GPIO_Port GPIOB
#define DEBUG_TX_Pin GPIO_PIN_9
#define DEBUG_TX_GPIO_Port GPIOA
#define DEBUG_RX_Pin GPIO_PIN_10
#define DEBUG_RX_GPIO_Port GPIOA
#define OLED_CLK_Pin GPIO_PIN_6
#define OLED_CLK_GPIO_Port GPIOB
#define OLED_DAT_Pin GPIO_PIN_7
#define OLED_DAT_GPIO_Port GPIOB
#define NRF24_CE_Pin GPIO_PIN_8
#define NRF24_CE_GPIO_Port GPIOB

    /* USER CODE BEGIN Private defines */

    /* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
