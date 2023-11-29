/* Private includes -----------------------------------------------------------*/
// includes
#include "main.h"
#include "stdio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "user_TasksInit.h"
#include "OLED.h"
#include "24l01.h"
#include "W25Q128.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
TimeStruct RealTime;
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
        OLED_Init();
        OLED_ShowString(1, 1, "Waiting HW...");

        OLED_ShowString(2, 1, "Ini exFlash...");
        W25QXX_Init(); // Initial the W25Qxx external flash memory
        OLED_ShowString(3, 1, "Check 2.4G...");
        while (NRF24L01_Check())
            ; // Check the NRF24L01 exist or not
        OLED_ShowString(4, 1, "Finish.");
        OLED_ShowString(4, 10, "3");
        HAL_Delay(1000);
        OLED_ShowString(4, 10, "2");
        HAL_Delay(1000);
        OLED_ShowString(4, 10, "1"); 
        HAL_Delay(1000);
        OLED_Clear();
        OLED_ShowString(2, 1, "time sync...");

        while (NRF24L01_WatingTimeGet() == -1) // 检查是否收到上位机传来的时间同步信息
            ; // Wait for realtime getting
        RealTime = TimeStamp2TimeShow(TimeStamp);
        OLED_TimeShow(RealTime, 1);
        xTaskResumeAll();
        vTaskDelete(NULL);
        osDelay(1000);
    }
}

/**
 * @brief 时间戳转换成时分秒
 * 
 * @param Timestamp 待转换时间戳
 * @return TimeStruct 返回实时北京时间结构体
 */
TimeStruct TimeStamp2TimeShow(uint32_t Timestamp)
{
    TimeStruct time = {0};
    time.hour = Timestamp / 3600;
    time.minute = Timestamp % 3600 / 60;
    time.second = Timestamp % 60;
    return time;
}