#ifndef __DRV_SPI_H
#define __DRV_SPI_H

#include "spi.h"
#include "gpio.h"

//SPI硬件接口IO定义
//#define SPI_CLK_GPIO_PORT			GPIOB
//#define SPI_CLK_GPIO_PIN			GPIO_Pin_5

//#define SPI_MISO_GPIO_PORT			GPIOB
//#define SPI_MISO_GPIO_PIN			GPIO_Pin_7

//#define SPI_MOSI_GPIO_PORT			GPIOB
//#define SPI_MOSI_GPIO_PIN			GPIO_Pin_6

#define SPI_NSS_GPIO_PORT			1
#define SPI_NSS_GPIO_PIN			4


#define SPIx_NSS_HIGH( )		{ Gpio_SetIO( SPI_NSS_GPIO_PORT, SPI_NSS_GPIO_PIN,1 ); 	M0P_SPI->SSN = TRUE; }	
#define SPIx_NSS_LOW( )			{ Gpio_SetIO( SPI_NSS_GPIO_PORT, SPI_NSS_GPIO_PIN,0 ); 	M0P_SPI->SSN = FALSE; }	


void drv_spi_init( void );
uint8_t drv_spi_read_write_byte( uint8_t TxByte );

#endif
