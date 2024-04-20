#include "main.h"
#include "user_OELDShow.h"
#include "OLED.h"

// uint8_t getLocationTimeFlag = 0; // 0-系统未获得位置时间；1-系统已经获得位置时间

SysStatus getSysStatus(void)
{
    SysStatus sys_status;
    sys_status = reatimeGetNoise;
    return sys_status;
}

void OLEDShow(void)
{
    uint32_t now_tick = 0;
    static SysStatus show_status = 0;
    while (1)
    {
        now_tick = osKernelGetTickCount();
        show_status = getSysStatus(); // 获取当前系统状态，执行对应的显示功能

        switch (show_status)
        {
        case reatimeGetNoise:
            // 显示当前经纬度与时间戳
            if (sysTimeStamp != 0)
            {
                OLED_ShowString(1, 1, latitude);
                OLED_ShowString(2, 1, longitude);
                OLED_ShowNum(4, 1, sysTimeStamp, 10);
                // OLED_ShowHexNum(4, 1, txdata[5], 2);
                // OLED_ShowHexNum(4, 3, txdata[6], 2);
                // OLED_ShowHexNum(4, 5, txdata[7], 2);
                // OLED_ShowHexNum(4, 7, txdata[8], 2);
            }
            else
                OLED_ShowString(1, 1, "location...");
            break;
        case uploadHistoryNoise:
            //
            break;

        default:
            break;
        }

        osDelayUntil(now_tick + 1000); // 每50ticks刷一次，能够保证实时性
    }
}
