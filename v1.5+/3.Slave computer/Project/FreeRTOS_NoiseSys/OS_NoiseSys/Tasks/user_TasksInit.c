/* Private includes -----------------------------------------------------------*/
// includes
// sys
#include "main.h"
#include "sys.h"
#include "stdio.h"
#include "noisen.h"
// tasks
#include "user_TasksInit.h"
#include "user_HardwaresInitTask.h"
#include "user_NoiseSend.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Timers --------------------------------------------------------------------*/
osTimerId_t IdleTimerHandle;

/* Tasks ---------------------------------------------------------------------*/
// HardwaresInitTask
osThreadId_t HardwaresInitTaskHandle;
const osThreadAttr_t HardwaresInitTask_attributes = {
    .name = "HardwaresInitTask",
    .stack_size = 128 * 10,
    .priority = (osPriority_t)osPriorityHigh1,
};

// LED task
osThreadId_t LEDTaskHandle;
const osThreadAttr_t LEDTask_attributes = {
    .name = "LEDTask",
    .stack_size = 128 * 1,
    .priority = (osPriority_t)osPriorityLow,
};

// // get noise task
// osThreadId_t NoiseGetTaskHandle;
// const osThreadAttr_t NoiseGetTask_attributes = {
//     .name = "NoiseGetTask",
//     .stack_size = 128 * 2,
//     .priority = (osPriority_t)osPriorityLow,
// };

// MeasureSend task
osThreadId_t MeasureSendTaskHandle;
const osThreadAttr_t MeasureSendTask_attributes = {
    .name = "MeasureSendTask",
    .stack_size = 128 * 10,
    .priority = (osPriority_t)osPriorityLow2,
};

/* Message queues ------------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
void LEDTask(void *argument);

/**
 * @brief  FreeRTOS initialization
 * @param  None
 * @retval None
 */
void User_Tasks_Init(void)
{
    /* add mutexes, ... */

    /* add semaphores, ... */

    /* start timers, add new ones, ... */

    /* add queues, ... */

    /* add threads, ... */
    HardwaresInitTaskHandle = osThreadNew(HardwaresInitTask, NULL, &HardwaresInitTask_attributes); // hardwares initialization
    LEDTaskHandle = osThreadNew(LEDTask, NULL, &LEDTask_attributes);                               // toggles LED
    // NoiseGetTaskHandle = osThreadNew(get_noise, NULL, &NoiseGetTask_attributes);                   // get noise
    MeasureSendTaskHandle = osThreadNew(NoiseSend, NULL, &MeasureSendTask_attributes);             // send noise to onenet

    /* add events, ... */

    /* add  others ... */
}

/**
 * @brief  FreeRTOS Tick Hook
 * @param  None
 * @retval None
 */
void vApplicationTickHook()
{
}

/**
 * @brief  LED Task, to show the sys is not choken
 * @param  None
 * @retval None
 */
void LEDTask(void *argument)
{
    while (1)
    {
        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
        osDelay(500);
    }
}
