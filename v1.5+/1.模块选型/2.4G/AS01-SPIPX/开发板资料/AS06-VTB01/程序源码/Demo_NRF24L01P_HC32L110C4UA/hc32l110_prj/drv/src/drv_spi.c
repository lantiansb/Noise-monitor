#include "drv_spi.h"


//SPI�ȴ���ʱ
#define SPI_WAIT_TIMEOUT			((uint16_t)0xFFFF)


/**
  * @brief :SPI��ʼ����Ӳ����
  * @param :��
  * @note  :��
  * @retval:��
  */
void drv_spi_init( void )
{
    Clk_SetPeripheralGate(ClkPeripheralSpi,TRUE); //SPI����ʱ�Ӵ�
    	
	Gpio_InitIOExt(SPI_NSS_GPIO_PORT, SPI_NSS_GPIO_PIN, GpioDirOut, FALSE, TRUE, FALSE, 0);
    Gpio_SetFunc_SPIMISO_P23();
    Gpio_SetFunc_SPIMOSI_P24();
    Gpio_SetFunc_SPICLK_P25();                    //����SPI��������
    
    SPIx_NSS_HIGH();
	
    //����SPI	
    M0P_SPI->CR = 0x00;
    
    M0P_SPI->CR_f.MSTR = SpiMaster;
    M0P_SPI->CR_f.CPOL = Spicpollow;
    M0P_SPI->CR_f.CPHA = Spicphafirst;
	
	M0P_SPI->CR_f.SPR2 = 1;//����16��Ƶ������
	
	M0P_SPI->CR |= (SpiClkDiv32&0x03u);  
	M0P_SPI->STAT = 0x00;
	M0P_SPI->CR_f.SPEN = TRUE;

	EnableNvic(SPI_IRQn,DDL_IRQ_LEVEL_DEFAULT,FALSE);
}

/**
  * @brief :SPI�շ�һ���ֽ�
  * @param :
  *			@TxByte: ���͵������ֽ�
  * @note  :�Ƕ���ʽ��һ���ȴ���ʱ���������Զ��˳�
  * @retval:���յ����ֽ�
  */
uint8_t drv_spi_read_write_byte( uint8_t TxByte )
{
	uint32_t err_time = SPI_WAIT_TIMEOUT;
	
	M0P_SPI->DATA = TxByte;
	
	while(err_time-- ) 
	{
		if(M0P_SPI->STAT_f.SPIF == TRUE )
		{
			break;
		}
	}			  
	  						    
	return M0P_SPI->DATA;	
}


