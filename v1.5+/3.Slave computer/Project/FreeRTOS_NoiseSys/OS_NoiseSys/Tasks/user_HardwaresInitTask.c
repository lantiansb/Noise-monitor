/* Private includes -----------------------------------------------------------*/
// includes
#include "math.h"
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
TimeStruct RealTime = {0xFF};   // real time structure
uint8_t TimeStampTemp[4] = {0}; // temporary variable to store the time stamp
uint8_t SysBootTimes = 0xFF;    // system boot times
uint8_t RefreshFlag = 0;        // refresh flag from Upper computer, 1 means refresh, 0 means no refresh
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
        TimeSync(); // 等待与上位机握手，进行初始化同步
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

/**
 * @brief 每次上电初始化时访问外部FLASH最后一页，读取历史开机记录并记录本次开机，以确定本次启动数据存储起点
 *
 */
void TimeSync(void)
{
    OLED_Clear();
    OLED_ShowString(1, 1, "Refresh?");
    OLED_ShowString(2, 1, "1.yes   2.no");
    RefreshFlag = NRF24L01_rxdata[1];                      // 第一位为是否选择刷新
    while (NRF24L01_WatingTimeGet() == NRF24L01_REC_ERROR) // 检查上位机是否需要清空外部FLASH
        ;
    if (NRF24L01_rxdata[1])
    {
        OLED_Clear();
        OLED_ShowString(1, 1, "Erase chip...");
        OLED_ShowString(2, 1, "wait for mins...");
        W25QXX_Erase_Sector(NumBlockOfChip * NumSectorOfBlock - 1);
        // W25QXX_Erase_Chip(); // 擦除整片外部FLASH，等待时间比较久！
    }
    OLED_Clear();
    W25QXX_Read((uint8_t *)(&SysBootTimes), FLASH_SIZE - NumByteOfPage * 2 - 1, sizeof(SysBootTimes));          // 倒数第二页第一个字节存放开机次数
    SysBootTimes = SysBootTimes << 1;                                                                           // 由于外部FLASH不可写1，所以用左移代替计数，11111111 << 1 -> 11111110，表示已启动1次
    W25QXX_Write_NoCheck((uint8_t *)(&SysBootTimes), FLASH_SIZE - NumByteOfPage * 2 - 1, sizeof(SysBootTimes)); // 开机次数存入FLASH
    SysBootTimes = (uint8_t)log2((double)(~SysBootTimes)) + 1; // 取反后再取对数，表明有几位已用，例：~11111110 = 00000001,此时为2的0次方，表示历史启动0次
    OLED_Clear();
    W25QXX_Write_NoCheck((uint8_t *)(&TimeStamp), FLASH_SIZE - NumByteOfPage * 1 + SysBootTimes * 12, sizeof(TimeStamp)); // 写入首地址进外部flash
    uint8_t i = ~SysBootTimes;
    for (; i > 0; i = i >> 1)
    {
        W25QXX_Read((uint8_t *)TimeStampTemp, FLASH_SIZE - NumByteOfPage * 1 + i * 12, sizeof(TimeStampTemp));
        OLED_ShowNum(1, 1, TimeStampTemp[0], 2);
        HAL_Delay(1000);
    }
    RealTime = TimeStamp2TimeShow(TimeStamp);
    OLED_TimeShow(RealTime, 2);
}
