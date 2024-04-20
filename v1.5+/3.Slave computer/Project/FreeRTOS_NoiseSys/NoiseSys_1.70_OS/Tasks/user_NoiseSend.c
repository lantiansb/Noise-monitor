#include "main.h"
#include "user_NoiseSend.h" // Noise send header
#include "OLED.h"
#include "noisen.h"
#include "24l01.h"

uint8_t getLocationTimeFlag = 0; // 0-系统未获得位置时间；1-系统已经获得位置时间

void NoiseSend(void *argument)
{
    uint32_t now_tick = 0;
    // 该函数每次开机只执行一次
    if (getLocationTimeFlag == 0)
    {
        while (GPS_GetLocationTime())
            ; // 通过Air780eg获取位置与时间
        getLocationTimeFlag++;
        GPSLocSend(); // 发送一次位置信息给上位机
    }

    while (1)
    {
        now_tick = osKernelGetTickCount();
        Get_noise(); // 更新一次噪声信号
        NRF24L01_TX_Mode();
        NRF24L01_TxPacket(txdata); // 通过2.4G模块发送一次
        osDelayUntil(now_tick + 2000);
    }
}

/**
 * @brief 自动遍历FLASH中的数据，发送历史数据
 *
 * @param argument
 */
void NoiseSendHistroy(void *argument)
{
    NRF24L01_TX_Mode();
    NRF24L01_TxPacket(txdata); // 通过2.4G模块发送一次
}
