/* Private includes -----------------------------------------------------------*/
// includes
#include <stdio.h>
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "user_TasksInit.h"
#include "OLED.h"
#include "Air780eg.h"
#include "W25Q128.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/**
 * @brief  measure the light and send to the cloud
 * @param  argument: Not used
 * @retval None
 */
void HardwaresInitTask(void *argument)
{
    while (1)
    {
        vTaskSuspendAll();
        // 初始化OLED
        OLED_Init();
        // 初始化W25Q128
        OLED_ShowString(1, 1, "FLASH Init...");
        w25q128_init();
        // w25q128_erase_chip(); // 开机发送完上次开机的历史数据后，擦除整个芯片，防止数据混乱
        HAL_Delay(1000);
        // 初始化2.4G模块
        OLED_ShowString(2, 1, "2.4G Init...");
        while (NRF24L01_Check())
            HAL_Delay(1);
        // 初始化噪声传感器
        OLED_ShowString(3, 1, "Noisen Init...");
        Get_noise();
        // 初始化GPS
        OLED_ShowString(3, 1, "GPS Init...");
        Air780eg_Init();

        OLED_Clear();

        xTaskResumeAll();
        vTaskDelete(NULL);
        osDelay(1000);
    }
}
