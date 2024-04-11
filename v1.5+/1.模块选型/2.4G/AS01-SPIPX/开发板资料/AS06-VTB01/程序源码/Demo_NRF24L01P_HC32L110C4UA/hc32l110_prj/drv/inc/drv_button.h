#ifndef __DRV_BUTTON_H
#define __DRV_BUTTON_H

#include "gpio.h"


//����Ӳ���ӿڶ���
#define BUTOTN_GPIO_PORT			3									
#define BUTTON_GPIO_PIN				3



enum
{
	BUTOTN_UP = 0,		//����û�а���
	BUTOTN_PRESS_DOWN	//��������
};



void drv_button_init( void );
uint8_t drv_button_check( void );


#endif
