#ifndef __SYSCONF_H
#define __SYSCONF_H

/// @brief 系统状态，reatimeGetNoise为实时上传状态，uploadHistoryNoise为上传历史数据状态
typedef enum
{
    reatimeGetNoise = 1,
    uploadHistoryNoise = 2
} SysStatus;

#define bool	_Bool
#define TRUE 1
#define FALSE 0

#define DEVICE_ID 0x02

#endif /* __SYSCONF_H */
