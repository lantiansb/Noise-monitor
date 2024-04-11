#ifndef __DRV_SI4432_H
#define __DRV_SI4432_H


#include "drv_spi.h"
#include "gpio.h"


#define SI4432_DATA_LEN_MAX			64			//自定义数据最大长度，最大为64


/** SI4432硬件接口IO定义 */
#define SI4432_SDN_PORT				1								
#define SI4432_SDN_PIN				5

#define SI4432_IRQ_PORT				2									
#define SI4432_IRQ_PIN				6

//#define SI4432_GPIO0_PORT			GPIOA								
//#define SI4432_GPIO0_PIN			GPIO_Pin_2

//#define SI4432_GPIO1_PORT			GPIOA								
//#define SI4432_GPIO1_PIN			GPIO_Pin_3

#define SI4432_GPIO2_PORT			3								
#define SI4432_GPIO2_PIN			6



//IO操作函数定义
#define SI_SET_SDN_HIGH( )			Gpio_SetIO(SI4432_SDN_PORT,SI4432_SDN_PIN,1);
#define SI_SET_SDN_LOW( )			Gpio_SetIO(SI4432_SDN_PORT,SI4432_SDN_PIN,0);

#define SI_SET_CSN_HIGH( )			SPIx_NSS_HIGH( )
#define SI_SET_CSN_LOW( )			SPIx_NSS_LOW( )

#define SI_GET_IRQ_STATUS( )		Gpio_GetIO( SI4432_IRQ_PORT,SI4432_IRQ_PIN )
//#define SI_GET_GPIO0_STATUS( )		(( SI4432_GPIO0_PORT->IDR & SI4432_GPIO0_PIN ) != SI4432_GPIO0_PIN ) ? 0 : 1
//#define SI_GET_GPIO1_STATUS( )		(( SI4432_GPIO1_PORT->IDR & SI4432_GPIO1_PIN ) != SI4432_GPIO1_PIN ) ? 0 : 1
#define SI_GET_GPIO2_STATUS( )		Gpio_GetIO( SI4432_GPIO2_PORT,SI4432_GPIO2_PIN )


#define SI4432_Tx_Byte( TxByte )	drv_spi_read_write_byte( TxByte )
#define SI4432_Rx_Byte( )			drv_spi_read_write_byte( 0x55 )	



uint8_t SI4432_Read_Reg( uint8_t ReadAddr );
void SI4432_Write_Reg( uint8_t WriteAddr, uint8_t WriteValue );
uint8_t SI4432_Get_It_Status1( void );
uint8_t SI4432_Get_It_Status2( void );
void SI4432_SW_Reset( void );
void SI4432_Set_Sync( uint16_t SyncValue );
void SI4432_Clear_Rx_FIFO( void );
void SI4432_Start_Tx( void );
void SI4432_Start_Rx( void );
void SI4432_Tx_Packet( uint8_t *pTxBuff, uint8_t TxLength );
uint8_t SI4432_Rx_Packet( uint8_t *pRxBuff );
void SI4432_Gpio_Init( void );
void SI4432_Init( void );


#endif

