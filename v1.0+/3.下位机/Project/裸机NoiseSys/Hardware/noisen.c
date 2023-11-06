#include "stm32f10x.h" // Device header
#include "noisen.h"    // Noise sensor header
#include "usart.h"     // USART header

uint8_t ask_noise[8] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A}; // Request noise from device
uint8_t result[7] = {0};
uint8_t rec_cnt = 0;
extern float noisen_data;

void nosen_init(void)
{
    Usart2_Init(9600);
}

void get_noise(void)
{
    Usart_SendString(USART2, ask_noise, sizeof(ask_noise));
}

void USART2_IRQHandler(void)
{

	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET) //接收中断
	{
		USART_ClearFlag(USART2, USART_FLAG_RXNE);
        if(rec_cnt >= 7)
        {
            rec_cnt = 0;
        }
        result[rec_cnt++] = USART2->DR;
        if(rec_cnt >= 5)
        {
            noisen_data = (float)(result[3] << 8 + result[4]) / 10;
        }
        // rec_cnt++;
        // if(rec_cnt == 3)
        //     result = USART2->DR << 8;
        // if(rec_cnt == 4)
        // {
        //     result += USART2->DR;
        //     noisen_data = (float)result / 10;
        //     rec_cnt = 0;
        // }
	}
}
