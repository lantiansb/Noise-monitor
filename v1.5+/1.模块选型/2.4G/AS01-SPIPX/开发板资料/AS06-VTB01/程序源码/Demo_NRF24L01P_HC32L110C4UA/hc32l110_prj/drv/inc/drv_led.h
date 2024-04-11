#ifndef __DRV_LED_H
#define __DRV_LED_H

#include "gpio.h"

#define LED1_PORT			3
#define LED1_PIN			4

#define LED2_PORT			3
#define LED2_PIN			5

/** LED定义 */
typedef enum LedPort
{
	LED_RED = 0,		//红色LED
	LED_GREEN			//绿色LED
}LedPortType;


void drv_led_init( void );
void drv_led_on( LedPortType LedPort );
void drv_led_off( LedPortType LedPort );
void drv_led_flashing( LedPortType LedPort );

//红色LED操作函数
#define led_red_on( )				drv_led_on( LED_RED )
#define led_red_off( )				drv_led_off( LED_RED )
#define led_red_flashing( )			drv_led_flashing( LED_RED )
//绿色LED操作函数
#define led_green_on( )				drv_led_on( LED_GREEN )
#define led_green_off( )			drv_led_off( LED_GREEN )
#define led_green_flashing( )		drv_led_flashing( LED_GREEN )

#endif

