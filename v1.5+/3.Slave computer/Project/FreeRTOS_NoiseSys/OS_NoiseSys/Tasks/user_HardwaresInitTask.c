/* Private includes -----------------------------------------------------------*/
// includes
#include "stdio.h"
#include "stm32f1xx_hal.h"
#include "FreeRTOS.h"
#include "task.h"
#include "user_TasksInit.h"
#include "OLED.h"

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
        OLED_Init();
        HAL_Delay(1000);
        xTaskResumeAll();
        vTaskDelete(NULL);
        osDelay(1000);

    }
}
