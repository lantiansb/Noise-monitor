#include "main.h"
#include "noisen.h" // Noise sensor header
#include "cmsis_os.h"
#include "OLED.h"
#include "w25q128.h"

// 接受噪声传感器返回buffer
static uint8_t usart2_rec_buf[7] = {0};

// 噪声获取指令
const uint8_t ask_noise[8] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A}; // Request noise from device

void Get_noise(void)
{
    vTaskSuspendAll();

    HAL_UART_Transmit(&huart2, (uint8_t *)ask_noise, 8, 1000);
    HAL_UART_Receive(&huart2, (uint8_t *)usart2_rec_buf, 7, 1000);
    txdata[3] = usart2_rec_buf[3];
    txdata[4] = usart2_rec_buf[4];
    // 将时间戳拆分到txdata数组中
    txdata[5] = (uint8_t)(sysTimeStamp & 0xFF);         // 最低位字节
    txdata[6] = (uint8_t)((sysTimeStamp >> 8) & 0xFF);  // 第二字节
    txdata[7] = (uint8_t)((sysTimeStamp >> 16) & 0xFF); // 第三字节
    txdata[8] = (uint8_t)((sysTimeStamp >> 24) & 0xFF); // 最高位字节
    // 存储当前噪声值到FLASH中
    vSaveNowMesureValue();  // 保存当前噪声值
    vSaveNowIndex();        // 保存当前索引
    vSaveAddrIndexUpdate(); // 更新索引地址到下一个地址

    xTaskResumeAll();
}
