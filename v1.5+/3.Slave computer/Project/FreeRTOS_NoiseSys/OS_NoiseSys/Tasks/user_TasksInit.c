/* Private includes -----------------------------------------------------------*/
// includes
// sys
#include "main.h"
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
    MeasureSendTaskHandle = osThreadNew(NoiseSend, NULL, &MeasureSendTask_attributes);             // send noise per second when online mode
    
    /* add events, ... */

    /* add  others ... */
}

/**
 * @brief  LED Task, to show the sys is not choken
 * @param  None
 * @retval None
 */
void LEDTask(void *argument)
{
    uint32_t now_tick = 0;
    while (1)
    {
        now_tick = osKernelGetTickCount();
        HAL_GPIO_TogglePin(LED_T_GPIO_Port, LED_T_Pin);
        osDelayUntil(now_tick + 500);
    }
}
