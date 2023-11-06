#ifndef _ADIO16_
#define _ADIO16_

#ifdef ADIO16_EXPORTS
#define ADIO16_API __declspec(dllexport)
#else
#define ADIO16_API __declspec(dllimport)
#endif

#include <dbt.h>

#ifdef __cplusplus
extern "C" {
#endif
/*******************************************************************/
/*USB HID ADIO2.0 Dll 全局定义                                     */
/*******************************************************************/
/*******************************************************************/
/*USB HID 设备基本读写函数如下                                     */
/*******************************************************************/

ADIO16_API BOOL OpenDeviceHID(HANDLE *HidDevHandle, unsigned int uVid, unsigned int uPid ,unsigned int ID );

ADIO16_API BOOL ReadDeviceHID(unsigned int ID,unsigned char ucDataBuffer[], unsigned char ucDataLength);

ADIO16_API BOOL WriteDeviceHID(unsigned int ID,unsigned char ucTxBuffer[], unsigned char ucTxLength);

/*******************************************************************/
/*USB HID 设备扩展读写函数如下   /* unsigned char IDN,             */                                   
/*******************************************************************/
ADIO16_API BOOL WriteDeviceHIDEX(unsigned int ID, unsigned char CMD, unsigned char Data0, unsigned char Data1, unsigned char Data2, unsigned char Data3);

//ADIO16_API unsigned int FindDevice(unsigned int uVid, unsigned int uPid);
ADIO16_API unsigned int FindDevice();

ADIO16_API BOOL OpenDevice (unsigned int ID);

ADIO16_API unsigned int m_ReadDeviceHID2BUF(unsigned int ID,unsigned int *ADDataBuffer, unsigned int len, unsigned int *DADataBuffer, unsigned int *CNTDataBuffer, unsigned int *DIODataBuffer);

ADIO16_API BOOL CloseDevice( unsigned int ID );

#ifdef __cplusplus
}
#endif

#endif; // _ADIO16_