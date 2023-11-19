#include "stm32f1xx_hal.h"
#include "noisen.h" // Noise sensor header
#include "cmsis_os.h"
#include "delay.h"
#include "OLED.h"

extern UART_HandleTypeDef huart2;
extern uint8_t usart2_rec_buf[10];
extern uint8_t usart2_rec_flag;

uint8_t ask_noise[8] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A}; // Request noise from device

uint32_t get_noise(void)
{
    uint32_t noise;
    HAL_UART_Transmit_DMA(&huart2, (uint8_t *)ask_noise, sizeof(ask_noise));
    delay_ms(100);
    if(usart2_rec_flag == 1)
    {
        usart2_rec_flag = 0;
        noise = (usart2_rec_buf[3] * 16 * 16 + usart2_rec_buf[4]);
        return noise; // return noise
    }
}
