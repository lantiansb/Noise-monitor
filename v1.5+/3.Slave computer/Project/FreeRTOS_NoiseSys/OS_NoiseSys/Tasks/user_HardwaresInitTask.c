/* Private includes -----------------------------------------------------------*/
// includes
#include "stdio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "user_TasksInit.h"
#include "delay.h"
#include "OLED.h"
#include "Air724ug.h"
#include "onenet_MQTT.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/**
 * @brief  measure the light and send to the cloud
 * @param  argument: Not used
 * @retval None
 */
void HardwaresInitTask(void *argument)
{
    while (1)
    {
        vTaskSuspendAll();
        // OLED
        OLED_Init();
        // Air724
        OLED_ShowString(1, 1, "Air724...");
        Air724_Init();
        delay_ms(1000);
        // PDP
        OLED_ShowString(2, 1, "PDP...");
        Air724_PDPact();
        delay_ms(1000);
        // MQTT
        OLED_ShowString(3, 1, "MQTT...");
        onenet_MQTTConnect();
        delay_ms(1000);
        OLED_Clear();
        // finished
        OLED_ShowString(1, 1, "ini finished!");
        delay_ms(1000);

        xTaskResumeAll();
        vTaskDelete(NULL);
        osDelay(1000);
    }
}
