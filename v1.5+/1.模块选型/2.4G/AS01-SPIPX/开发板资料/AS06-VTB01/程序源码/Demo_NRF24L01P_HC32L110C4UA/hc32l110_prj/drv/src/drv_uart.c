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
  * @brief :串口初始化
  * @param :无
  * @note  :无
  * @retval:无
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

    //外设时钟使能
    Clk_SetPeripheralGate(ClkPeripheralBt, TRUE);//模式0/2可以不使能
    Clk_SetPeripheralGate(ClkPeripheralUart1, TRUE);
	
    stcUartIrqCb.pfnRxIrqCb = RxIntCallback;
    stcUartIrqCb.pfnTxIrqCb = NULL;
    stcUartIrqCb.pfnRxErrIrqCb = NULL;
    stcConfig.pstcIrqCb = &stcUartIrqCb;
    stcConfig.bTouchNvic = FALSE;
	
	stcConfig.enRunMode = UartMode1;//测试项，更改此处来转换4种模式测试
	
    stcMulti.enMulti_mode = UartNormal;//测试项，更改此处来转换多主机模式，mode2/3才有多主机模式

    stcConfig.pstcMultiMode = &stcMulti;
	
	
    stcBaud.bDbaud = 0u;//双倍波特率功能
    stcBaud.u32Baud = UartBaudRate;//更新波特率位置
    stcBaud.u8Mode = UartMode1; //计算波特率需要模式参数
    pclk = Clk_GetPClkFreq();
    timer = Uart_SetBaudRate(UARTCH1,pclk,&stcBaud);
	
    stcBtConfig.enMD = BtMode2;
    stcBtConfig.enCT = BtTimer;
    Bt_Init(TIM1, &stcBtConfig);//调用basetimer1设置函数产生波特率
    Bt_ARRSet(TIM1,timer);
    Bt_Cnt16Set(TIM1,timer);
    Bt_Run(TIM1);
    Uart_Init(UARTCH1, &stcConfig);
	
	Uart_EnableIrq(UARTCH1,UartRxIrq);
	
	Uart_ClrStatus(UARTCH1,UartRxFull);
	
	Uart_EnableFunc(UARTCH1,UartRx);
}


/**
  * @brief :串口发送数据
  * @param :
  *			@TxBuffer:发送数据首地址
  *			@Length:数据长度
  * @note  :无
  * @retval:无
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
  * @brief :串口接收数据
  * @param :
  *			@RxBuffer:发送数据首地址
  * @note  :无
  * @retval:接收到的字节个数
  */
uint8_t drv_uart_rx_bytes( uint8_t* RxBuffer )
{
	uint8_t l_RxLength = 0;
	uint16_t l_UartRxTimOut = 0xfff;
	
	while( l_UartRxTimOut-- )			//在超时范围内查询数据
	{
		if( TRUE == Uart_GetStatus( UARTCH1,UartRxFull) )
		{
			*RxBuffer = Uart_ReceiveData(UARTCH1 );
			Uart_ClrStatus( UARTCH1,UartRxFull);
			RxBuffer++;
			l_RxLength++;
			l_UartRxTimOut = 0xfff;		//恢复超时等待时间
		}
	}
	
	return l_RxLength;					//返回接收到的字节个数
}

