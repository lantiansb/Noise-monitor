#include "main.h"
#include "w25q128.h"
#include "spi.h"
#include <string.h>
#include <stdlib.h>

#define FLASH_WRITER_START 0x000000 // w25q128的写入初始地址，地址范围为0x000000 ~ 0xFFFFFF
#define NOISEFrame_SIZE 6           // 两字节噪声值，四字节时间戳
#define INDEX_ADDRESS (0xfffff - 4) // 定义存储ulFLASHFrameIndex的地址

uint8_t ucFLASHFrame[NOISEFrame_SIZE + 1] = {0}; // 多一字节为结束符
uint32_t ulFLASHFrameIndex = FLASH_WRITER_START; // 保存地址索引

/*通过SPI2同时读写一个字节数据
主机只向从机进行写操作，调用此函数时忽略返回值
主机只向从机进行读操作，调用此函数时随便传入一个字符，尽量是0xFF
*/
uint8_t spi2_read_write_byte(uint8_t data)
{
    uint8_t rec_data = 0;

    HAL_SPI_TransmitReceive(&hspi2, &data, &rec_data, 1, 1000); // spi读写数据函数，参数2存放用来发送的数据，参数3存放用来接收的数据

    return rec_data;
}

bool w25q128_init(void)
{
    uint16_t flash_type;
    spi2_read_write_byte(0xFF);     /* 清除DR（数据寄存器）,写入一个0xFF */
    W25Q128_CS(1);                  // 拉高片选信号不进行SPI通信
    flash_type = w25q128_read_id(); /* 读取FLASH ID. */
    if (flash_type == W25Q128)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

// 等待W25Q128空闲
static void w25q128_wait_busy(void)
{
    while ((w25q128_rd_sr1() & 0x01) == 1)
        ; /* 等待状态寄存器的BUSY位清空 */
}

// 读取状态寄存器的值
uint8_t w25q128_rd_sr1(void)
{
    uint8_t rec_data = 0;

    W25Q128_CS(0);
    spi2_read_write_byte(FLASH_ReadStatusReg1); // 写入指令0x05：读状态寄存器1
    rec_data = spi2_read_write_byte(0xFF);      // 获取状态寄存器1的值
    W25Q128_CS(1);

    return rec_data;
}

// W25Q128写使能,即置位WEL为1
void w25q128_write_enable(void)
{
    W25Q128_CS(0);
    spi2_read_write_byte(FLASH_WriteEnable); /* 发送指令0x06：写使能 */
    W25Q128_CS(1);
}

// 发送24位地址
static void w25q128_send_address(uint32_t address) /*address：地址范围0~16777215字节，即寻址范围为0x00 ~ 0xFFFFFF */
{
    spi2_read_write_byte((uint8_t)((address) >> 16)); /* 发送 bit23 ~ bit16 地址 */
    spi2_read_write_byte((uint8_t)((address) >> 8));  /* 发送 bit15 ~ bit8  地址 */
    spi2_read_write_byte((uint8_t)address);           /* 发送 bit7  ~ bit0  地址 */
}

// 擦除整个芯片
void w25q128_erase_chip(void)
{
    w25q128_write_enable(); /* 写使能 */
    w25q128_wait_busy();    /* 等待空闲 */
    W25Q128_CS(0);
    spi2_read_write_byte(FLASH_ChipErase); /* 发送指令0xC7：擦除整个芯片 */
    W25Q128_CS(1);
    w25q128_wait_busy(); /* 等待芯片擦除结束 */
}

// 擦除一个扇区
void w25q128_erase_sector(uint32_t saddr) /* saddr：该参数是第几个扇区 */
{
    saddr *= 4096;          /* 一个扇区大小为4096字节 */
    w25q128_write_enable(); /* 写使能 */
    w25q128_wait_busy();    /* 等待空闲 */
    W25Q128_CS(0);
    spi2_read_write_byte(FLASH_SectorErase); /* 发送指令0x20：擦除指定扇区 */
    w25q128_send_address(saddr);             /* 发送擦除的扇区地址 */
    W25Q128_CS(1);
    w25q128_wait_busy(); /* 等待扇区擦除完成 */
}

// 读取w25q128芯片ID
uint16_t w25q128_read_id(void)
{
    uint16_t deviceid;

    W25Q128_CS(0);                                // 拉低片选信号进行SPI通信
    spi2_read_write_byte(FLASH_ManufactDeviceID); /* 发送读取 ID 命令 */
    /* 发送3个0 */
    /*
spi2_read_write_byte(0);
spi2_read_write_byte(0);
spi2_read_write_byte(0);
    */

    w25q128_send_address(0x000000);

    deviceid = spi2_read_write_byte(0xFF) << 8; /* 读取高8位字节 */
    deviceid |= spi2_read_write_byte(0xFF);     /* 读取低8位字节 */
    W25Q128_CS(1);

    return deviceid;
}

/*
读取W25Q128的FLASH，在指定地址开始读取指定长度的数据
pubf：需要读取的数据
addr：指定的地址
datalen：指定的数据大小
*/
void w25q128_read(uint8_t *pbuf, uint32_t addr, uint16_t datalen)
{
    uint16_t i;

    W25Q128_CS(0);
    spi2_read_write_byte(FLASH_ReadData); /* 发送指令0x03：读取数据 */
    w25q128_send_address(addr);           /* 发送需要读取的数据地址 */

    for (i = 0; i < datalen; i++)
    {
        pbuf[i] = spi2_read_write_byte(0XFF); /* 循环读取 */
    }

    W25Q128_CS(1);
}

/*
单页写，在指定地址写入小于256字节的指定长度的数据，在非0xFF处写入的数据会失败
pubf：需要写入的数据
addr：指定的地址
datalen：指定的数据大小
*/
static void w25q128_write_page(uint8_t *pbuf, uint32_t addr, uint16_t datalen)
{
    uint16_t i;

    w25q128_write_enable(); /* 写使能 */

    W25Q128_CS(0);
    spi2_read_write_byte(FLASH_PageProgram); /* 发送命令0x02：页写 */
    w25q128_send_address(addr);              /* 发送写入的页地址 */

    for (i = 0; i < datalen; i++)
    {
        spi2_read_write_byte(pbuf[i]); /* 循环写入 */
    }

    W25Q128_CS(1);
    w25q128_wait_busy(); /* 等待写入结束 */
}

/*
多页写，在指定地址写入指定长度的数据，在非0xFF处写入的数据会失败
pubf：需要写入的数据
addr：指定的地址
datalen：指定的数据大小
*/
static void w25q128_write_nocheck(uint8_t *pbuf, uint32_t addr, uint16_t datalen)
{
    uint16_t pageremain;
    pageremain = 256 - addr % 256; /* 获取指定地址那页的剩余字节数 */

    if (datalen <= pageremain) /* 指定地址那页的剩余字节数能装下指定数据大小 */
    {
        pageremain = datalen;
    }

    while (1)
    {
        /* 当指定地址那页的剩余字节数能装下指定数据大小时,一次性写完 */

        /* 当指定数据大小比指定地址那页的剩余字节数要大时, 先写完指定地址那页的剩余字节, 然后根据剩余数据大小进行不同处理 */
        w25q128_write_page(pbuf, addr, pageremain); // 页写

        if (datalen == pageremain) /* 写入结束了 */
        {
            break;
        }
        else /* datalen > pageremain */
        {
            pbuf += pageremain;    /* pbuf指针地址偏移,前面已经写了pageremain字节 */
            addr += pageremain;    /* 写地址偏移,前面已经写了pageremain字节 */
            datalen -= pageremain; /* 写入总长度减去已经写入了的字节数 */

            if (datalen > 256) /* 剩余数据大小还大于一页 */
            {
                pageremain = 256; /* 一次写入256个字节，即一次写一页 */
            }
            else /* 剩余数据大小小于一页  */
            {
                pageremain = datalen; /* 一次性写完 */
            }
        }
    }
}

/*
//写入W25Q128的FLASH，在指定地址开写入取指定长度的数据
pubf：需要写入的数据
addr：指定的地址
datalen：指定的数据大小
*/
uint8_t g_w25q128_buf[4096]; /* 扇区缓存 */

void w25q128_write(uint8_t *pbuf, uint32_t addr, uint16_t datalen)
{
    uint32_t secpos;
    uint16_t secoff;
    uint16_t secremain;
    uint16_t i;
    uint8_t *w25q128_buf;
    // c8T6内存太小啦，只能用malloc分配内存到堆区
    w25q128_buf = (uint8_t*)malloc(4096 * sizeof(uint8_t));
    secpos = addr / 4096;      /* 获取指定地址在哪片扇区 */
    secoff = addr % 4096;      /* 指定数据在在扇区内的偏移数据大小 */
    secremain = 4096 - secoff; /* 扇区剩余字节数 */

    if (datalen <= secremain) /* 指定地址那片扇区的剩余字节数能装下指定数据大小 */
    {
        secremain = datalen;
    }

    while (1)
    {
        w25q128_read(w25q128_buf, secpos * 4096, 4096); /* 读出指定地址那片扇区的全部内容 */

        for (i = 0; i < secremain; i++) /* 校验数据，防止数据出现非0xFF */
        {
            if (w25q128_buf[secoff + i] != 0xFF) // 扇区数据有一个数据不是0xFF
            {
                break; /* 需要擦除, 直接退出for循环 */
            }
        }

        if (i < secremain) /* 需要擦除 */
        {
            w25q128_erase_sector(secpos); /* 擦除这个扇区 */

            for (i = 0; i < secremain; i++) /* 复制 */
            {
                w25q128_buf[i + secoff] = pbuf[i];
            }

            w25q128_write_nocheck(w25q128_buf, secpos * 4096, 4096); /* 写入整个扇区 */
        }
        else /* 写已经擦除了的,直接写入扇区剩余区间. */
        {
            w25q128_write_nocheck(pbuf, addr, secremain); /* 直接写扇区 */
        }

        if (datalen == secremain)
        {
            break; /* 写入结束了 */
        }
        else /* 写入未结束 */
        {
            secpos++;   /* 扇区地址增1，新的一个扇区 */
            secoff = 0; /* 偏移位置为0 */

            pbuf += secremain;    /* 指针偏移 */
            addr += secremain;    /* 写地址偏移 */
            datalen -= secremain; /* 字节数递减 */

            if (datalen > 4096)
            {
                secremain = 4096; /* 一次写入一个扇区 */
            }
            else
            {
                secremain = datalen; /* 一次性写完 */
            }
        }
    }
    free(w25q128_buf); // 释放内存
}

/**
 * @brief 保存当前FLASHFrameIndex
 *
 */
void vSaveNowIndex(void)
{
    w25q128_write((char *)&ulFLASHFrameIndex, INDEX_ADDRESS, sizeof(ulFLASHFrameIndex));
}

/**
 * @brief 保存当前测试的噪声值和其对应的时间戳
 *
 */
void vSaveNowMesureValue(void)
{
    sprintf((char *)ucFLASHFrame, (char *)&txdata[3]);
    w25q128_write(ucFLASHFrame, ulFLASHFrameIndex, NOISEFrame_SIZE);
    memset(ucFLASHFrame, 0, NOISEFrame_SIZE + 1);
}

/**
 * @brief 保存地址索引更新
 *
 */
void vSaveAddrIndexUpdate(void)
{
    ulFLASHFrameIndex += NOISEFrame_SIZE;
}

/**
 * @brief 从头开始读取FLASH中的噪声数据帧
 *
 * @return 返回一个指向数据帧的指针
 */
uint8_t *ucReadNoiseDataFrames(void)
{
    uint32_t addr = 0;
    uint32_t ulFLASHFrameIndex;
    char *dataFrames;

    // 从FLASH中读取ulFLASHFrameIndex
    w25q128_read((char *)&ulFLASHFrameIndex, INDEX_ADDRESS, sizeof(ulFLASHFrameIndex));

    dataFrames = malloc(ulFLASHFrameIndex);

    if (dataFrames == NULL)
    {
        return NULL; // 如果内存分配失败，返回NULL
    }

    while (addr <= ulFLASHFrameIndex)
    {
        w25q128_read(dataFrames + addr, addr, NOISEFrame_SIZE);
        addr += NOISEFrame_SIZE;
    }

    return dataFrames;
}