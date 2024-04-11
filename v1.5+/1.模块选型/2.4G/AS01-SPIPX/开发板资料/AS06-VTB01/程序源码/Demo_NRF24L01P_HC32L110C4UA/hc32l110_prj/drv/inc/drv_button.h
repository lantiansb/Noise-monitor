#ifndef __DRV_BUTTON_H
#define __DRV_BUTTON_H

#include "gpio.h"


//按键硬件接口定义
#define BUTOTN_GPIO_PORT			3									
#define BUTTON_GPIO_PIN				3



enum
{
	BUTOTN_UP = 0,		//按键没有按下
	BUTOTN_PRESS_DOWN	//按键按下
};



void drv_button_init( void );
uint8_t drv_button_check( void );


#endif
