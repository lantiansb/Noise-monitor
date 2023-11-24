#include "Air724ug.h"
#include "stdio.h"
#include "string.h"
#include "cmsis_os.h"
#include "delay.h"
#include "usart.h"
#include "onenet_MQTT.h"

/**
 ******************************************************************************
 * @file         Air724ug.c
 * @brief        这个文件用于合宙的Air724ug模块，使用串口发送AT指令.
 *
 * @author	      Landin
 ******************************************************************************
 * @attention
 *
 * 由于本文件中串口发送指令全部用了 printf, 在编译的时候要打开 use microlib .
 * printf 重定向在 usart.c 里面定义了.
 *
 ******************************************************************************
 */

uint8_t Air724_buf[500];
uint8_t Air724_flag = 0;

/**
 * @brief clear the buffer
 *
 */
void Air724_Clear(void)
{
    memset(Air724_buf, 0, sizeof(Air724_buf));
}

/**
 * @brief waiting for receive buffer
 *
 * @return _Bool 0 mean the receive buffer is finished
 */
_Bool Air724_WaitRecive(void)
{

    if (Air724_flag == 0) // 如果接收计数为0 则说明没有处于接收数据中，所以直接跳出，结束函数
    {
        return REV_WAIT;
    }
    else
    {
        Air724_flag = 0; // 清0接收计数
        return REV_OK; // 返回接收完成标志
    }
}

/**
 * @brief send command to air724
 *
 * @param cmd command
 * @param res response from air724
 * @return _Bool 0-success, 1-failure
 */
_Bool Air724_SendCmd(char *cmd, char *res)
{
    unsigned char timeOut = 200;

    printf((const unsigned char *)cmd);
    // HAL_UART_Transmit(&huart1, cmd, sizeof(cmd), 0xffffffff);

    while (timeOut--)
    {
        if (Air724_WaitRecive() == REV_OK) // if receive the response
        {
            if (strstr((const char *)Air724_buf, res) != NULL) // if check Correct response
            {
                Air724_Clear(); // clear the buffer
                return 0;
            }
        }
        delay_ms(10);
    }
    return 1;
}

void Air724_Reset(void)
{
    printf("AT+RESET\r\n");
}

/**
 * @brief  初始化Air724,包括：
 * 		1.匹配波特率
 * 		2.检测SIM卡是否插好
 * 		3.信号质量(17-31信号才良好)
 * 		4.网络注册状态(正常第二位返回1)
 * 		5.查询网络状态GPRS附着状态(正常返回1,停机返回0)
 * 		6.设置APN(获取IP失败)
 * 		7.激活网络(初始只能激活一次)
 * 		8.查询IP地址是否有了
 */
void Air724_Init(void)
{
    while (Air724_SendCmd("AT\r\n", "OK")) // matching baud rate
        delay_ms(500);

    while (Air724_SendCmd("AT+CPIN?\r\n", "+CPIN: READY\r\n\r\nOK\r\n")) // check whether the SIM card is properly inserted
        delay_ms(500);

    while (Air724_SendCmd("AT+CREG?\r\n", "+CREG: 0,1\r\n\r\nOK\r\n")) // network registration status
        delay_ms(500);

    while (Air724_SendCmd("AT+CGATT?\r\n", "+CGATT: 1\r\n\r\nOK\r\n")) // GPRS attachment status
        delay_ms(500);

    // activate PDP
    while (Air724_SendCmd("AT+CSTT\r\n", "OK")) // set APN
    {
        if(!Air724_SendCmd("AT+CSTT\r\n", "+CME ERROR: 3"))
            break;
        delay_ms(500);
    }
    
    while (Air724_SendCmd("AT+CIICR\r\n", "OK")) // activate network
    {
        if(!Air724_SendCmd("AT+CIICR\r\n", "+CME ERROR: 3"))
            break;
        delay_ms(500);
    }
    while (Air724_SendCmd("AT+CIFSR\r\n", ".")) // check IP
        delay_ms(500);
}

/**
 * @brief  激活PDP,包括：
 * 		1.打开承载,激活PDP
 * 		2.设置GPRS承载场景ID
 * 		3.同步网络时间
 */
void Air724_PDPact(void)
{
    while (Air724_SendCmd("AT+CNTPCID=1\r\n", "OK")) // set GPRS bearer scenarios
        delay_ms(500);

    while (Air724_SendCmd("AT+SAPBR=1,1\r\n", "OK")) // synchronous network clock
    {
        if(!Air724_SendCmd("AT+SAPBR=1,1\r\n", "+CME ERROR: 3"))
            break;
        delay_ms(500);
    }

    while (Air724_SendCmd("AT+CCLK?\r\n", "+CCLK:")) // acquisition time
        delay_ms(500);
}
