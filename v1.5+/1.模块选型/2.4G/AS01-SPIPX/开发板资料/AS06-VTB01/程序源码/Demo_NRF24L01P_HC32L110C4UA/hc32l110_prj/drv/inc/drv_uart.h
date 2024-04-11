#ifndef __DRV_UART_H
#define __DRV_UART_H

#include "uart.h"
#include "gpio.h"
#include "bt.h"


//UART硬件接口IO定义
#define UART_TX_GPIO_PORT			0
#define UART_TX_GPIO_PIN			1

#define UART_RX_GPIO_PORT			0
#define UART_RX_GPIO_PIN			2

#define UART1_TX_PIN_FUNC()				Gpio_SetFunc_UART1_TXD_P01()
#define UART1_RX_PIN_FUNC()				Gpio_SetFunc_UART1_RXD_P02()

void drv_uart_init( uint32_t UartBaudRate );
void drv_uart_tx_bytes( uint8_t* TxBuffer, uint8_t Length );
uint8_t drv_uart_rx_bytes( uint8_t* RxBuffer );

#endif
