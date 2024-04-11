#include "drv_uart.h"

//uint8_t rx_tmp[10];
//uint8_t rx_tmp_len;

void RxIntCallback(void)
{
//	while(1);
//	rx_tmp[rx_tmp_len++] = M0P_UART1->SBUF;
}

void ErrIntCallback(void)
{
	while(1);
}

/**
  * @brief :���ڳ�ʼ��
  * @param :��
  * @note  :��
  * @retval:��
  */
void drv_uart_init( uint32_t UartBaudRate )
{
	uint16_t timer=0;
	uint32_t pclk=0;
	
    stc_uart_config_t  stcConfig;
    stc_uart_irq_cb_t stcUartIrqCb;
    stc_uart_multimode_t stcMulti;
    stc_uart_baud_config_t stcBaud;
    stc_bt_config_t stcBtConfig;
	
	DDL_ZERO_STRUCT(stcUartIrqCb);
	DDL_ZERO_STRUCT(stcMulti);
	DDL_ZERO_STRUCT(stcBaud);
	DDL_ZERO_STRUCT(stcBtConfig);
	
    Gpio_InitIOExt(UART_TX_GPIO_PORT, UART_TX_GPIO_PIN, GpioDirOut, TRUE, FALSE, FALSE, 0);   
    Gpio_InitIOExt(UART_RX_GPIO_PORT, UART_RX_GPIO_PIN, GpioDirIn, TRUE, FALSE, FALSE, 0); 
	
    UART1_TX_PIN_FUNC();
    UART1_RX_PIN_FUNC();

    //����ʱ��ʹ��
    Clk_SetPeripheralGate(ClkPeripheralBt, TRUE);//ģʽ0/2���Բ�ʹ��
    Clk_SetPeripheralGate(ClkPeripheralUart1, TRUE);
	
    stcUartIrqCb.pfnRxIrqCb = RxIntCallback;
    stcUartIrqCb.pfnTxIrqCb = NULL;
    stcUartIrqCb.pfnRxErrIrqCb = NULL;
    stcConfig.pstcIrqCb = &stcUartIrqCb;
    stcConfig.bTouchNvic = FALSE;
	
	stcConfig.enRunMode = UartMode1;//��������Ĵ˴���ת��4��ģʽ����
	
    stcMulti.enMulti_mode = UartNormal;//��������Ĵ˴���ת��������ģʽ��mode2/3���ж�����ģʽ

    stcConfig.pstcMultiMode = &stcMulti;
	
	
    stcBaud.bDbaud = 0u;//˫�������ʹ���
    stcBaud.u32Baud = UartBaudRate;//���²�����λ��
    stcBaud.u8Mode = UartMode1; //���㲨������Ҫģʽ����
    pclk = Clk_GetPClkFreq();
    timer = Uart_SetBaudRate(UARTCH1,pclk,&stcBaud);
	
    stcBtConfig.enMD = BtMode2;
    stcBtConfig.enCT = BtTimer;
    Bt_Init(TIM1, &stcBtConfig);//����basetimer1���ú�������������
    Bt_ARRSet(TIM1,timer);
    Bt_Cnt16Set(TIM1,timer);
    Bt_Run(TIM1);
    Uart_Init(UARTCH1, &stcConfig);
	
	Uart_EnableIrq(UARTCH1,UartRxIrq);
	
	Uart_ClrStatus(UARTCH1,UartRxFull);
	
	Uart_EnableFunc(UARTCH1,UartRx);
}


/**
  * @brief :���ڷ�������
  * @param :
  *			@TxBuffer:���������׵�ַ
  *			@Length:���ݳ���
  * @note  :��
  * @retval:��
  */
void drv_uart_tx_bytes( uint8_t* TxBuffer, uint8_t Length )
{
	while( Length-- )
	{
		Uart_SendData( UARTCH1,* TxBuffer );
		TxBuffer++;
	}
}

/**
  * @brief :���ڽ�������
  * @param :
  *			@RxBuffer:���������׵�ַ
  * @note  :��
  * @retval:���յ����ֽڸ���
  */
uint8_t drv_uart_rx_bytes( uint8_t* RxBuffer )
{
	uint8_t l_RxLength = 0;
	uint16_t l_UartRxTimOut = 0xfff;
	
	while( l_UartRxTimOut-- )			//�ڳ�ʱ��Χ�ڲ�ѯ����
	{
		if( TRUE == Uart_GetStatus( UARTCH1,UartRxFull) )
		{
			*RxBuffer = Uart_ReceiveData(UARTCH1 );
			Uart_ClrStatus( UARTCH1,UartRxFull);
			RxBuffer++;
			l_RxLength++;
			l_UartRxTimOut = 0xfff;		//�ָ���ʱ�ȴ�ʱ��
		}
	}
	
	return l_RxLength;					//���ؽ��յ����ֽڸ���
}

