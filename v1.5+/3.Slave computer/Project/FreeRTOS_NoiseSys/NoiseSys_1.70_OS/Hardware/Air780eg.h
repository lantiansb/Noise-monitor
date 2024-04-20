#ifndef __AIR780EG_H
#define __AIR780EG_H

#define REV_OK 0   // received buffer finished
#define REV_WAIT 1 // received buffer unfinished

void Air780FlagSet(void);
void Air780eg_Init(void);
uint8_t GPS_GetLocationTime(void);
void GPS_CalcTimeStamp(void);
void Timestamp_To_DateTime(uint32_t timestamp);

#endif
