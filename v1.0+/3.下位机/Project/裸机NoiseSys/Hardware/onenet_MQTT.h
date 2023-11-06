#ifndef __ONENET_MQTT_H
#define __ONENET_MQTT_H

#include "stm32f10x.h"                  // Device header

void onenet_MQTTConnect(void);
void onenet_TCPDisConnect(void);
void onenet_MQTT_MPUB(char *strsend);
uint8_t Connect_Check(void);

extern const char *mqtturl;
extern const char *mqttport;

#endif
