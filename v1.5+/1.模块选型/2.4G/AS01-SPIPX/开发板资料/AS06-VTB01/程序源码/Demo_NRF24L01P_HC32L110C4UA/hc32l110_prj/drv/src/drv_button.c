#include "drv_button.h"
#include "ddl.h"

/**
  * @brief :������ʼ��
  * @param :��
  * @note  :��
  * @retval:��
  */ 
void drv_button_init( void )
{
	//����Ϊ����
	Gpio_InitIO(BUTOTN_GPIO_PORT, BUTTON_GPIO_PIN, GpioDirIn);
	Gpio_SetIO(BUTOTN_GPIO_PORT,BUTTON_GPIO_PIN,1);
}

/**
  * @brief :������ѯ
  * @param :��
  * @note  :��
  * @retval:
  *			0:����û�а���
  *			1:��⵽��������
  */
uint8_t drv_button_check( void )
{
	//��ѯ��������״̬
	if( FALSE ==  Gpio_GetIO( BUTOTN_GPIO_PORT,BUTTON_GPIO_PIN ) )	
	{
		delay1ms( 20 );			//
		if( FALSE ==  Gpio_GetIO( BUTOTN_GPIO_PORT,BUTTON_GPIO_PIN ))
		{
			return 1;				//��������
		}
	}
	
	return 0;
}
