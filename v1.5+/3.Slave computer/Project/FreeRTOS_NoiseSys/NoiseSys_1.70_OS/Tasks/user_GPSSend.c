#include <stdio.h>
#include "main.h"
#include "user_GPSSend.h"
#include "24l01.h"
#include "Air780eg.h"

/**
 * @brief 发送GPS定位信息
 *
 */
void GPSLocSend(void)
{
    // char *latitude1 = "23.0452825"; // 测试用
    // char *longitude1 = "113.379973";
    // sysTimeStamp = 0x12345678; // 测试时间戳
    // 使用snprintf将经纬度插入到txdata_loc中，从索引3开始
    // 确保不超过数组的剩余空间，数组大小为32，已使用3个字节
    snprintf((char *)txdata_loc + 3, sizeof(txdata_loc) - 3, "%s,%s", latitude, longitude);

    NRF24L01_TX_Mode();
    NRF24L01_TxPacket(txdata_loc); // 通过2.4G模块发送一次GPS
}
