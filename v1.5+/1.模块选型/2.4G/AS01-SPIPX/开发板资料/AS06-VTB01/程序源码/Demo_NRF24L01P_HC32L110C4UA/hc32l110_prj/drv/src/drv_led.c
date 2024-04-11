#include "drv_led.h"

uint8_t led1_sta = 0;
uint8_t led2_sta = 0;

void drv_led_init( void )
{
	Gpio_InitIOExt(LED1_PORT, LED1_PIN, GpioDirOut, TRUE, FALSE, FALSE, FALSE);
	Gpio_InitIOExt(LED2_PORT, LED2_PIN, GpioDirOut, TRUE, FALSE, FALSE, FALSE);
	Gpio_SetIO(LED1_PORT, LED1_PIN, 0);
	Gpio_SetIO(LED2_PORT, LED2_PIN, 0);
	led1_sta = 0;
	led2_sta = 0;
}


void drv_led_on( LedPortType LedPort )
{
	if( LED_RED == LedPort )	//LED_RED
	{
		led1_sta = 1;
		Gpio_SetIO( LED1_PORT, LED1_PIN,1 );
	}
	else				
	{
		led2_sta = 1;
		Gpio_SetIO( LED2_PORT, LED2_PIN,1 );
	}
}

void drv_led_off( LedPortType LedPort )
{
	if( LED_RED == LedPort )	//LED_RED
	{
		led1_sta = 0;
		Gpio_SetIO( LED1_PORT, LED1_PIN,0 );	
	}
	else					
	{
		led1_sta = 0;
		Gpio_SetIO( LED2_PORT, LED2_PIN,0 );
	}
}

void drv_led_flashing( LedPortType LedPort )
{
	if( LED_RED == LedPort )
	{
		if(led1_sta == 0 )
		{
			led1_sta = 1;
			Gpio_SetIO( LED1_PORT, LED1_PIN,1);
		}
		else
		{
			led1_sta = 0;
			Gpio_SetIO( LED1_PORT, LED1_PIN,0);
		}
	}
	else
	{
		if(led2_sta == 0 )
		{
			led2_sta = 1;
			Gpio_SetIO( LED2_PORT, LED2_PIN,1);
		}
		else
		{
			led2_sta = 0;
			Gpio_SetIO( LED2_PORT, LED2_PIN,0);
		}
	}
}

