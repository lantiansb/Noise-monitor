#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.h"
#include "Air780eg.h"

// 接受Air780eg返回buffer
uint8_t Air780_rec_buf[100] = {0};
static uint8_t Air780_rec_finish_flag = 0; // 接收完成标志，0-接收等待，1-接收完成

// 发送Air780eg指令
const uint8_t AT_Init[] = "AT\r\n";
const uint8_t AT_SAPBR_active[] = "AT+SAPBR=1,1\r\n";
const uint8_t AT_CIPGSMLOC[] = "AT+CIPGSMLOC=1,1\r\n";

// 经纬度时间相关
char latitude[20] = {0}, longitude[20] = {0};
char dateStr[11] = {0}, timeStr[9] = {0}; // 根据预期的数据格式分配足够的空间
uint32_t sysTimeStamp = 0;

/**
 * @brief 让接收中断服务函数置位Air780_rec_finish_flag
 *
 */
void Air780FlagSet(void)
{
    Air780_rec_finish_flag = 1;
}

/**
 * @brief 清空Air780接收buffer
 *
 */
void Air780_Clear(void)
{
    memset(Air780_rec_buf, 0, sizeof(Air780_rec_buf));
}

/**
 * @brief 等待接收buffer接收完成
 *
 * @return _Bool 0表示接收完成
 */
_Bool Air780_WaitRecive(void)
{

    if (Air780_rec_finish_flag == 0) // 如果接收计数为0 则说明没有处于接收数据中，所以直接跳出，结束函数
    {
        return REV_WAIT;
    }
    else
    {
        Air780_rec_finish_flag = 0; // 清0接收计数
        return REV_OK;              // 返回接收完成标志
    }
}

/**
 * @brief send command to air724
 *
 * @param cmd command
 * @param res response from air724
 * @return _Bool 0-success, 1-failure
 */
_Bool Air780_SendCmd(const uint8_t *cmd, char *res)
{
    unsigned char timeOut = 200;

    HAL_UART_Transmit(&huart3, cmd, strlen(cmd), 0xffffffff);

    while (timeOut--)
    {
        if (Air780_WaitRecive() == REV_OK) // if receive the response
        {
            if (strstr((const char *)Air780_rec_buf, res) != NULL) // if check Correct response
            {
                return 0;
            }
        }
        HAL_Delay(10);
    }
    return 1;
}

/**
 * @brief 初始化Air780eg，校准波特率
 *
 */
void Air780eg_Init(void)
{
    while (Air780_SendCmd(AT_Init, "OK"))
        ; // 发送基本的AT命令来检测模块是否响应
    Air780_Clear();
    while (Air780_SendCmd(AT_SAPBR_active, "AT+"))
        ; // 激活GPRS承载上下文
    Air780_Clear();
}

/**
 * @brief 通过GPS获取当前位置与时间
 *
 * @return uint8_t 0-成功解析，1-解析失败，2-未返回数据
 */
uint8_t GPS_GetLocationTime(void)
{
    if (!Air780_SendCmd(AT_CIPGSMLOC, "OK"))
    {
        // 发送获取GPS位置的命令，并等待响应
        // 解析经纬度
        if (4 == sscanf(Air780_rec_buf, "\r\n+CIPGSMLOC: 0,%19[^,],%19[^,],%10[^,],%8s", latitude, longitude, dateStr, timeStr))
        {
            GPS_CalcTimeStamp();
            Air780_Clear();
            return 0;
        }
        else
        {
            Air780_Clear();
            return 1;
        }
    }
    else
        return 2;
}

/**
 * @brief 通过GPS得到的时间转换为时间戳
 *
 */
void GPS_CalcTimeStamp(void)
{
    // 示例日期和时间
    int year, month, day, hour, minute, second;

    // 使用sscanf从日期和时间字符串中解析出年、月、日、时、分、秒
    sscanf(dateStr, "%d/%d/%d", &year, &month, &day);
    sscanf(timeStr, "%d:%d:%d", &hour, &minute, &second);

    // 填充tm结构
    struct tm tm = {0};
    tm.tm_year = year - 1900; // tm_year是从1900年起的年数
    tm.tm_mon = month - 1;    // tm_mon是从0开始的月数（0代表1月）
    tm.tm_mday = day;
    tm.tm_hour = hour;
    tm.tm_min = minute;
    tm.tm_sec = second;

    // 将tm结构转换为时间戳
    time_t timestamp = mktime(&tm);
    sysTimeStamp = (uint32_t)timestamp;
    if (timestamp == -1)
    {
        return;
    }
}

/**
 * @brief 通过时间戳得到日期和时间
 *
 * @param timestamp 时间戳
 * @param dateStr 日期字符串
 * @param timeStr 时间字符串
 */
void Timestamp_To_DateTime(uint32_t timestamp)
{
    // 将时间戳转换为tm结构
    struct tm *tm = localtime((time_t *)&timestamp);

    // 格式化日期和时间字符串
    strftime(dateStr, 20, "%Y/%m/%d", tm);
    strftime(timeStr, 20, "%H:%M:%S", tm);
}
