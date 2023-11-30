#include "spi.h"
#include "W25Q128.h"

/* IIC接口选择 */
#define SPIx hspi2

uint16_t W25QXX_TYPE; // 默认是W25Q256

uint8_t SPI1_RX_BUF[4096];

// 初始化SPI FLASH的IO口
uint8_t W25QXX_Init(void)
{
    W25Q128_CS_1;                  // SPI FLASH不选中
    W25QXX_TYPE = W25QXX_ReadID(); // 读取FLASH ID.
    if (W25QXX_TYPE == W25Q128)    // SPI FLASH为W25Q256
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// 读取W25QXX的状态寄存器，W25QXX一共有3个状态寄存器
// 状态寄存器1：
// BIT7  6   5   4   3   2   1   0
// SPR   RV  TB BP2 BP1 BP0 WEL BUSY
// SPR:默认0,状态寄存器保护位,配合WP使用
// TB,BP2,BP1,BP0:FLASH区域写保护设置
// WEL:写使能锁定
// BUSY:忙标记位(1,忙;0,空闲)
// 默认:0x00
// 状态寄存器2：
// BIT7  6   5   4   3   2   1   0
// SUS   CMP LB3 LB2 LB1 (R) QE  SRP1
// 状态寄存器3：
// BIT7      6    5    4   3   2   1   0
// HOLD/RST  DRV1 DRV0 (R) (R) WPS ADP ADS
// regno:状态寄存器号，范:1~3
// 返回值:状态寄存器值
uint8_t W25QXX_ReadSR(uint8_t regno)
{
    uint8_t cmd[2];
    uint8_t temp[2];
    switch (regno)
    {
    case 1:
        cmd[0] = W25X_ReadStatusReg1; // 读状态寄存器1指令
        break;
    case 2:
        cmd[0] = W25X_ReadStatusReg2; // 读状态寄存器2指令
        break;
    case 3:
        cmd[0] = W25X_ReadStatusReg3; // 读状态寄存器3指令
        break;
    default:
        cmd[0] = W25X_ReadStatusReg1;
        break;
    }
    W25Q128_CS_0;
    // Poll mode
    // 发送指令和接收简单数据推荐使用查询模式
    HAL_SPI_TransmitReceive(&SPIx, cmd, temp, 2, 10); // 发送读状态寄存器命令
    W25Q128_CS_1;                                     // 取消片选
    return temp[1];
}

// 写W25QXX状态寄存器
void W25QXX_Write_SR(uint8_t regno, uint8_t sr)
{
    uint8_t cmd[2];
    switch (regno)
    {
    case 1:
        cmd[0] = W25X_WriteStatusReg1; // 写状态寄存器1指令
        break;
    case 2:
        cmd[0] = W25X_WriteStatusReg2; // 写状态寄存器2指令
        break;
    case 3:
        cmd[0] = W25X_WriteStatusReg3; // 写状态寄存器3指令
        break;
    default:
        cmd[0] = W25X_WriteStatusReg1;
        break;
    }
    cmd[1] = sr;
    W25Q128_CS_0; // 使能器件
    // Poll mode
    // 发送指令和接收简单数据推荐使用查询模式
    HAL_SPI_Transmit(&SPIx, cmd, 2, 10); // 发送读状态寄存器命令
    W25Q128_CS_1;                        // 取消片选
}

// W25QXX写使能
// 将WEL置位
void W25QXX_Write_Enable(void)
{
    uint8_t cmd = W25X_WriteEnable;
    W25Q128_CS_0;                         // 使能器件
    HAL_SPI_Transmit(&SPIx, &cmd, 1, 10); // 发送写使能
    W25Q128_CS_1;                         // 取消片选
}
// W25QXX写禁止
// 将WEL清零
void W25QXX_Write_Disable(void)
{
    uint8_t cmd = W25X_WriteDisable;
    W25Q128_CS_0;                         // 使能器件
    HAL_SPI_Transmit(&SPIx, &cmd, 1, 10); // 发送写禁止指令
    W25Q128_CS_1;                         // 取消片选
}

// 等待空闲
void W25QXX_Wait_Busy(void)
{
    while ((W25QXX_ReadSR(1) & 0x01) == 0x01)
        ; // 等待BUSY位清空
}
// 进入掉电模式
void W25QXX_PowerDown(void)
{
    uint8_t cmd = W25X_PowerDown;
    W25Q128_CS_0;                         // 使能器件
    HAL_SPI_Transmit(&SPIx, &cmd, 1, 10); // 发送掉电命令
    W25Q128_CS_1;                         // 取消片选
    HAL_Delay(1);                         // 等待TPD
}
// 唤醒
void W25QXX_WAKEUP(void)
{
    uint8_t cmd = W25X_ReleasePowerDown;
    W25Q128_CS_0;                         // 使能器件
    HAL_SPI_Transmit(&SPIx, &cmd, 1, 10); //  send W25X_PowerDown command 0xAB
    W25Q128_CS_1;                         // 取消片选
    HAL_Delay(1);                         // 等待TRES1
}

// 读取芯片ID
// 返回值如下:
// 0XEF13,表示芯片型号为W25Q80
// 0XEF14,表示芯片型号为W25Q16
// 0XEF15,表示芯片型号为W25Q32
// 0XEF16,表示芯片型号为W25Q64
// 0XEF17,表示芯片型号为W25Q128
// 0XEF18,表示芯片型号为W25Q256
uint16_t W25QXX_ReadID(void)
{
    uint16_t Temp = 0;
    uint8_t cmd[6], rst[6];
    cmd[0] = W25X_ManufactDeviceID;

    W25Q128_CS_0;
    // Poll mode
    // 发送指令和接收简单数据推荐使用查询模式
    HAL_SPI_TransmitReceive(&SPIx, cmd, rst, 6, 10); // 发送读取ID命令
    // DMA mode
    //	HAL_SPI_TransmitReceive_DMA(&SPIx, SPI1_DMA_CMD, SPI1_DMA_BUF,6);
    Temp = rst[4] << 8 | rst[5];
    W25Q128_CS_1;
    return Temp;
}

// 读取SPI FLASH
// 在指定地址开始读取指定长度的数据
// pBuffer:数据存储区
// ReadAddr:开始读取的地址(24bit)
// NumByteToRead:要读取的字节数(最大65535)
void W25QXX_Read(uint8_t *pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead)
{
    uint8_t cmd[5];
    uint8_t *ptr = pBuffer - 4;
    cmd[0] = W25X_ReadData;
    cmd[1] = (uint8_t)((ReadAddr) >> 24);
    cmd[2] = (uint8_t)((ReadAddr) >> 16);
    cmd[3] = (uint8_t)((ReadAddr) >> 8);
    cmd[4] = (uint8_t)(ReadAddr);

    W25Q128_CS_0;                        // 使能器件
    HAL_SPI_Transmit(&SPIx, cmd, 1, 10); // 发送读取命令
    if (W25QXX_TYPE == W25Q256)          // 如果是W25Q128/256的话地址为4字节的，要发送最高8位
    {
        HAL_SPI_TransmitReceive(&SPIx, &cmd[1], ptr, 4 + NumByteToRead, 10 * NumByteToRead); // 发送32bit地址
    }
    else
    {
        HAL_SPI_TransmitReceive(&SPIx, &cmd[2], ptr + 1, 3 + NumByteToRead, 10 * NumByteToRead); // 发送24bit地址
    }
    W25Q128_CS_1;
}

// 读取SPI FLASH  DMA
// 在指定地址开始读取指定长度的数据
// pBuffer:数据存储区
// ReadAddr:开始读取的地址(24bit)
// NumByteToRead:要读取的字节数(最大65535)
void W25QXX_Read_DMA(uint8_t *pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead)
{
    uint8_t cmd[5];
    uint8_t *ptr = pBuffer - 4;
    cmd[0] = W25X_ReadData;
    cmd[1] = (uint8_t)((ReadAddr) >> 24);
    cmd[2] = (uint8_t)((ReadAddr) >> 16);
    cmd[3] = (uint8_t)((ReadAddr) >> 8);
    cmd[4] = (uint8_t)(ReadAddr);

    W25Q128_CS_0;                        // 使能器件
    HAL_SPI_Transmit(&SPIx, cmd, 1, 10); // 发送读取命令
    if (W25QXX_TYPE == W25Q256)          // 如果是W25Q128/256的话地址为4字节的，要发送最高8位
    {
        HAL_SPI_TransmitReceive_DMA(&SPIx, &cmd[1], ptr, 4 + NumByteToRead); // 发送32bit地址
    }
    else
    {
        HAL_SPI_TransmitReceive_DMA(&SPIx, &cmd[2], ptr + 1, 3 + NumByteToRead); // 发送24bit地址
    }
    //	W25Q128_CS_1;
}

// SPI在一页(0~65535)内写入少于256个字节的数据
// 在指定地址开始写入最大256字节的数据
// pBuffer:数据存储区
// WriteAddr:开始写入的地址(24bit)
// NumByteToWrite:要写入的字节数(最大256),该数不应该超过该页的剩余字节数!!!
void W25QXX_Write_Page(uint8_t *pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite)
{
    uint8_t cmd[5];
    cmd[0] = W25X_PageProgram;
    cmd[1] = (uint8_t)((WriteAddr) >> 24);
    cmd[2] = (uint8_t)((WriteAddr) >> 16);
    cmd[3] = (uint8_t)((WriteAddr) >> 8);
    cmd[4] = (uint8_t)(WriteAddr);

    W25QXX_Write_Enable(); // SET WEL
    W25QXX_Wait_Busy();
    W25Q128_CS_0;                        // 使能器件
    HAL_SPI_Transmit(&SPIx, cmd, 1, 10); // 发送写页命令
    if (W25QXX_TYPE == W25Q256)          // 如果是W25Q256的话地址为4字节的，要发送最高8位
    {
        HAL_SPI_Transmit(&SPIx, &cmd[1], 4, 1000); // 发送32bit地址
    }
    else
    {
        HAL_SPI_Transmit(&SPIx, &cmd[2], 3, 1000); // 发送24bit地址
    }
    HAL_SPI_Transmit(&SPIx, pBuffer, NumByteToWrite, 4000); // 发送24bit地址

    W25Q128_CS_1;       // 取消片选
    W25QXX_Wait_Busy(); // 等待写入结束
}

// 无检验写SPI FLASH
// 必须确保所写的地址范围内的数据全部为0XFF,否则在非0XFF处写入的数据将失败!
// 具有自动换页功能
// 在指定地址开始写入指定长度的数据,但是要确保地址不越界!
// pBuffer:数据存储区
// WriteAddr:开始写入的地址(24bit)
// NumByteToWrite:要写入的字节数(最大65535)
// CHECK OK
void W25QXX_Write_NoCheck(uint8_t *pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite)
{
    uint16_t pageremain;
    uint16_t NumByteToWriteNow;
    pageremain = NumByteOfPage - WriteAddr % NumByteOfPage; // 单页剩余的字节数
    NumByteToWriteNow = NumByteToWrite;
    if (NumByteToWrite <= pageremain)
        pageremain = NumByteToWriteNow; // 不大于256个字节
    while (1)
    {
        W25QXX_Write_Page(pBuffer, WriteAddr, pageremain);
        if (NumByteToWriteNow == pageremain)
            break; // 写入结束了
        else       // NumByteToWrite>pageremain
        {
            pBuffer += pageremain;
            WriteAddr += pageremain;

            NumByteToWriteNow -= pageremain; // 减去已经写入了的字节数
            if (NumByteToWriteNow > NumByteOfPage)
                pageremain = NumByteOfPage; // 一次可以写入256个字节
            else
                pageremain = NumByteToWriteNow; // 不够256个字节了
        }
    };
}

// 写SPI FLASH
// 在指定地址开始写入指定长度的数据
// 该函数带擦除操作!
// pBuffer:数据存储区
// WriteAddr:开始写入的地址(24bit)
// NumByteToWrite:要写入的字节数(最大65535)
uint8_t W25QXX_BUFFER[NumByteOfSector];
void W25QXX_Write(uint8_t *pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite)
{
    uint16_t secpos;
    uint16_t secoff;
    uint16_t secremain;
    uint16_t i;
    uint8_t *W25QXX_BUF;
    W25QXX_BUF = W25QXX_BUFFER;
    secpos = WriteAddr / NumByteOfSector; // 扇区地址
    secoff = WriteAddr % NumByteOfSector; // 在扇区内的偏移
    secremain = NumByteOfSector - secoff; // 扇区剩余空间大小
    // printf("ad:%X,nb:%X\r\n",WriteAddr,NumByteToWrite);//测试用
    if (NumByteToWrite <= secremain)
        secremain = NumByteToWrite; // 不大于4096个字节
    while (1)
    {
        W25QXX_Read(W25QXX_BUF, secpos * NumByteOfSector, NumByteOfSector); // 读出整个扇区的内容
        for (i = 0; i < secremain; i++)                                     // 校验数据
        {
            if (W25QXX_BUF[secoff + i] != 0XFF)
                break; // 需要擦除
        }
        if (i < secremain) // 需要擦除
        {
            W25QXX_Erase_Sector(secpos);    // 擦除这个扇区
            for (i = 0; i < secremain; i++) // 复制
            {
                W25QXX_BUF[i + secoff] = pBuffer[i];
            }
            W25QXX_Write_NoCheck(W25QXX_BUF, secpos * NumByteOfSector, NumByteOfSector); // 写入整个扇区
        }
        else
            W25QXX_Write_NoCheck(pBuffer, WriteAddr, secremain); // 写已经擦除了的,直接写入扇区剩余区间.
        if (NumByteToWrite == secremain)
            break; // 写入结束了
        else       // 写入未结束
        {
            secpos++;                    // 扇区地址增1
            secoff = 0;                  // 偏移位置为0
            pBuffer += secremain;        // 指针偏移
            WriteAddr += secremain;      // 写地址偏移
            NumByteToWrite -= secremain; // 字节数递减
            if (NumByteToWrite > NumByteOfSector)
                secremain = NumByteOfSector; // 下一个扇区还是写不完
            else
                secremain = NumByteToWrite; // 下一个扇区可以写完了
        }
    };
}

// 擦除整个芯片
// 等待时间超长...
void W25QXX_Erase_Chip(void)
{
    uint8_t cmd = W25X_ChipErase;
    W25QXX_Write_Enable(); // SET WEL
    W25QXX_Wait_Busy();
    W25Q128_CS_0;                           // 使能器件
    HAL_SPI_Transmit(&SPIx, &cmd, 1, 1000); // 发送片擦除命令
    W25Q128_CS_1;                           // 取消片选
    W25QXX_Wait_Busy();   				   //等待芯片擦除结束
}

// 擦除一个扇区
// Dst_Addr:扇区地址 根据实际容量设置
// 擦除一个扇区的最少时间:45ms - 400ms
void W25QXX_Erase_Sector(uint32_t Dst_Addr)
{
    uint8_t cmd[5];
    // 监视falsh擦除情况,测试用
    // printf("fe:%x\r\n",Dst_Addr);
    cmd[0] = W25X_SectorErase;
    cmd[1] = (uint8_t)((Dst_Addr * NumByteOfSector) >> 24);
    cmd[2] = (uint8_t)((Dst_Addr * NumByteOfSector) >> 16);
    cmd[3] = (uint8_t)((Dst_Addr * NumByteOfSector) >> 8);
    cmd[4] = (uint8_t)(Dst_Addr * NumByteOfSector);

    W25QXX_Write_Enable(); // SET WEL
    W25QXX_Wait_Busy();
    W25Q128_CS_0;                        // 使能器件
    HAL_SPI_Transmit(&SPIx, cmd, 1, 10); // 发送扇区擦除指令
    if (W25QXX_TYPE == W25Q256)          // 如果是W25Q256的话地址为4字节的，要发送最高8位
    {
        HAL_SPI_Transmit(&SPIx, &cmd[1], 4, 4000); // 发送32bit地址
    }
    else
    {
        HAL_SPI_Transmit(&SPIx, &cmd[2], 3, 4000); // 发送24bit地址
    }

    W25Q128_CS_1;       // 取消片选
    W25QXX_Wait_Busy(); // 等待擦除完成
}

// 擦除一个块
// Dst_Addr:块地址 根据实际容量设置
// 擦除一个块的最少时间:150ms - 2000ms
void W25QXX_Erase_Block(uint32_t Dst_Addr)
{
    uint8_t cmd[5];
    // 监视falsh擦除情况,测试用
    // printf("fe:%x\r\n",Dst_Addr);
    cmd[0] = W25X_BlockErase;
    cmd[1] = (uint8_t)((Dst_Addr * NumByteOfBlock) >> 24);
    cmd[2] = (uint8_t)((Dst_Addr * NumByteOfBlock) >> 16);
    cmd[3] = (uint8_t)((Dst_Addr * NumByteOfBlock) >> 8);
    cmd[4] = (uint8_t)(Dst_Addr * NumByteOfBlock);

    W25QXX_Write_Enable(); // SET WEL
    W25QXX_Wait_Busy();
    W25Q128_CS_0;                        // 使能器件
    HAL_SPI_Transmit(&SPIx, cmd, 1, 10); // 发送扇区擦除指令
    if (W25QXX_TYPE == W25Q256)          // 如果是W25Q256的话地址为4字节的，要发送最高8位
    {
        HAL_SPI_Transmit(&SPIx, &cmd[1], 4, 2000); // 发送32bit地址
    }
    else
    {
        HAL_SPI_Transmit(&SPIx, &cmd[2], 3, 2000); // 发送24bit地址
    }

    W25Q128_CS_1;       // 取消片选
    W25QXX_Wait_Busy(); // 等待擦除完成
}
