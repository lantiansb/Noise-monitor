#include "main.h"

/* W25Q128片选引脚定义 */
#define W25Q128_CS_GPIO_PORT FLASH_CS_GPIO_Port
#define W25Q128_CS_GPIO_PIN FLASH_CS_Pin

// 业务相关define
#define FLASH_WRITER_START 0x000000 // w25q128的写入初始地址，地址范围为0x000000 ~ 0xFFFFFF
#define NOISEFrame_SIZE 6           // 两字节噪声值，四字节时间戳
#define INDEX_ADDRESS (0xfffff - 4) // 定义存储ulFLASHFrameIndex的地址

/* W25Q128片选信号 */
#define W25Q128_CS(x)                                                                                                                                                  \
    do                                                                                                                                                                 \
    {                                                                                                                                                                  \
        x ? HAL_GPIO_WritePin(W25Q128_CS_GPIO_PORT, W25Q128_CS_GPIO_PIN, GPIO_PIN_SET) : HAL_GPIO_WritePin(W25Q128_CS_GPIO_PORT, W25Q128_CS_GPIO_PIN, GPIO_PIN_RESET); \
    } while (0)

/* FLASH芯片列表 */
#define W25Q128 0XEF17 /* W25Q128  芯片ID */

/* 指令表 */
#define FLASH_WriteEnable 0x06
#define FLASH_ReadStatusReg1 0x05
#define FLASH_ReadData 0x03
#define FLASH_PageProgram 0x02
#define FLASH_SectorErase 0x20
#define FLASH_ChipErase 0xC7
#define FLASH_ManufactDeviceID 0x90

/* 内部函数 */
static void w25q128_wait_busy(void);                                               // 等待W25Q128空闲
static void w25q128_send_address(uint32_t address);                                // 发送24位地址
static void w25q128_write_page(uint8_t *pbuf, uint32_t addr, uint16_t datalen);    // 单页写，在指定地址写入小于256字节的指定长度的数据，在非0xFF处写入的数据会失败
static void w25q128_write_nocheck(uint8_t *pbuf, uint32_t addr, uint16_t datalen); // 多页写，在指定地址写入指定长度的数据，在非0xFF处写入的数据会失败

/* 普通函数 */
bool w25q128_init(void);         // 初始化W25Q128
uint16_t w25q128_read_id(void);  // 读取w25q128芯片ID
void w25q128_write_enable(void); // W25Q128写使能,即置位WEL为1
uint8_t w25q128_rd_sr1(void);    // 读取状态寄存器的值

void w25q128_erase_chip(void);                                      // 擦除整个芯片
void w25q128_erase_sector(uint32_t saddr);                          // 擦除一个扇区
void w25q128_read(uint8_t *pbuf, uint32_t addr, uint16_t datalen);  // 读取W25Q128的FLASH，在指定地址开始读取指定长度的数据
void w25q128_write(uint8_t *pbuf, uint32_t addr, uint16_t datalen); // 写入W25Q128的FLASH，在指定地址开写入取指定长度的数据

/* 业务函数 */
void vSaveNowIndex(void);
void vGetNowIndex(void);
void vSaveNowMesureValue(void);
void vSaveAddrIndexUpdate(void);
uint8_t *ucReadNoiseDataFrames(void);
