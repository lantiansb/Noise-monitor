#ifndef __CMT_SPI3_H
#define __CMT_SPI3_H

#include "base_types.h"
#include "ddl.h"


#define CMT2300A_GPIO3_PORT						3
#define CMT2300A_GPIO3_PIN						3

#define CMT2300A_GPIO2_PORT						1
#define CMT2300A_GPIO2_PIN						5

#define CMT2300A_GPIO1_PORT						2
#define CMT2300A_GPIO1_PIN						6

#define CMT2300A_SPI_SCLK_PORT					2
#define CMT2300A_SPI_SCLK_PIN					5

#define CMT2300A_SPI_MOSI_PORT					2
#define CMT2300A_SPI_MOSI_PIN					4

#define CMT2300A_SPI_MISO_PORT					2
#define CMT2300A_SPI_MISO_PIN					3

#define CMT2300A_SPI_CSB_PORT					1
#define CMT2300A_SPI_CSB_PIN					4

#define CMT2300A_SPI_FCSB_PORT					3
#define CMT2300A_SPI_FCSB_PIN					4


__inline void cmt_spi3_delay(void);
__inline void cmt_spi3_delay_us(void);

void cmt_spi3_init(void);

void cmt_spi3_send(u8 data8);
u8 cmt_spi3_recv(void);

void cmt_spi3_write(u8 addr, u8 dat);
void cmt_spi3_read(u8 addr, u8* p_dat);

void cmt_spi3_write_fifo(const u8* p_buf, u16 len);
void cmt_spi3_read_fifo(u8* p_buf, u16 len);

#endif
