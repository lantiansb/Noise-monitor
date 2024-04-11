#include "main.h"
#include "noisen.h" // Noise sensor header
#include "cmsis_os.h"
#include "OLED.h"

// 接受噪声传感器返回buffer
static uint8_t usart2_rec_buf[7] = {0};

// 噪声获取指令
const uint8_t ask_noise[8] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A}; // Request noise from device

void Get_noise(void)
{
    HAL_UART_Transmit(&huart2, (uint8_t *)ask_noise, 8, 10);
    HAL_UART_Receive(&huart2, (uint8_t *)usart2_rec_buf, 7, 10);
    txdata[2] = usart2_rec_buf[3];
    txdata[3] = usart2_rec_buf[4];
}
