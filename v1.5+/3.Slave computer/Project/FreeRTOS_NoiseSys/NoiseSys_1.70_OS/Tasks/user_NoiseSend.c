#include "main.h"
#include "user_NoiseSend.h" // Noise send header
#include "OLED.h"
#include "noisen.h"
#include "24l01.h"

void NoiseSend(void *argument)
{
    uint32_t now_tick = 0;
    while (1)
    {
        now_tick = osKernelGetTickCount();
        Get_noise(); // 更新一次噪声信号
        // NRF24L01_TX_Mode();
        // NRF24L01_TxPacket(txdata); // 通过2.4G模块发送一次
        OLED_ShowNum(3, 1, (txdata[2] << 8) + txdata[3], 4);
        osDelayUntil(now_tick + 2000);
    }
}
