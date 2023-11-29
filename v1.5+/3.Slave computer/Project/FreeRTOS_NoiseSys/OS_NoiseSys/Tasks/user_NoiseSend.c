#include "stm32f1xx_hal.h"
#include "stdio.h"
#include "user_NoiseSend.h" // Noise send header
#include "cmsis_os.h"
#include "OLED.h"
#include "noisen.h"

void NoiseSend(void *argument)
{
    while (1)
    {
        osDelay(1);
    }
}
