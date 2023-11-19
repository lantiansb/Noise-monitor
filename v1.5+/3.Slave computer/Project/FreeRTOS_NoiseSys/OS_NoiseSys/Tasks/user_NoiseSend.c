#include "stm32f1xx_hal.h"
#include "stdio.h"
#include "user_NoiseSend.h" // Noise send header
#include "cmsis_os.h"
#include "OLED.h"
#include "Air724ug.h"
#include "onenet_MQTT.h"
#include "noisen.h"

void NoiseSend(void)
{
    uint32_t now_noise = 0;
    uint8_t OLED_show_buf[12];
    OLED_Clear();
    while (1)
    {
        if(Connect_Check() == 1)
        {
            now_noise = get_noise();
            // now_noise = (int)(now_noise * 100) / 100.0;
            sprintf(OLED_show_buf, "Noise:%.1f", (float)now_noise / 10.0);
            OLED_ShowString(2, 1, OLED_show_buf);
            onenet_MQTT_MPUB_JSON((float)now_noise / 10.0);
            osDelay(1000);
        }
        else
        {
            OLED_Clear();
            OLED_ShowString(2, 1, "error");
            osDelay(1000);
        }
    }
}
