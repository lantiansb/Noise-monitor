#include "drv_button.h"
#include "ddl.h"

/**
  * @brief :按键初始化
  * @param :无
  * @note  :无
  * @retval:无
  */ 
void drv_button_init( void )
{
	//配置为输入
	Gpio_InitIO(BUTOTN_GPIO_PORT, BUTTON_GPIO_PIN, GpioDirIn);
	Gpio_SetIO(BUTOTN_GPIO_PORT,BUTTON_GPIO_PIN,1);
}

/**
  * @brief :按键查询
  * @param :无
  * @note  :无
  * @retval:
  *			0:按键没有按下
  *			1:检测到按键动作
  */
uint8_t drv_button_check( void )
{
	//查询引脚输入状态
	if( FALSE ==  Gpio_GetIO( BUTOTN_GPIO_PORT,BUTTON_GPIO_PIN ) )	
	{
		delay1ms( 20 );			//
		if( FALSE ==  Gpio_GetIO( BUTOTN_GPIO_PORT,BUTTON_GPIO_PIN ))
		{
			return 1;				//按键按下
		}
	}
	
	return 0;
}
