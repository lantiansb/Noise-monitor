#include "Air724ug.h"
#include "onenet_MQTT.h"
#include "stdio.h"
#include "string.h"
#include "delay.h"
#include "usart.h"

/**
 ******************************************************************************
 * @file         onenet_MQTT.c
 * @brief        这个文件用于合宙的Air724ug模块使用MQTT连接中国移动onenet.
 * @author	      Kingham Xu
 ******************************************************************************
 * @attention
 *
 * 由于本文件中串口发送指令全部用了 printf, 在编译的时候要打开 use microlib .
 * printf 重定向在 usart.c 里面定义了.
 *
 ******************************************************************************
 */

/**
 * @brief  onenet设备参数，每个设备都需要改下.
 * 		    sign是通过onenet的token算法计算得到的值,
 *         token工具: https://open.iot.10086.cn/doc/mqtt/book/manual/auth/tool.html
 *         1.发文res格式为products/()/devices/()
 *         括号里面填你的参数
 *         2.时间戳et大于当前时间就行
 *         3.秘钥key去设备详情复制
 */

#define Device_4

const char *ProductID = "qYAZf2aVV6";
const char *mqtturl = "mqtts.heclouds.com";
const char *mqttport = "1883"; // port = 1883

#ifdef Device_1
// 机1
const char *DeviceName = "NoiseSys";
const char *sign = "version=2018-10-31&res=products%%2FqYAZf2aVV6%%2Fdevices%%2FNoiseSys&et=1918097402&method=md5&sign=3%%2FGB121wUakWGwrEMDzrEw%%3D%%3D"; // md5算法生成的sign, printf需要%%输出一个字符%
const char *topicpost = "$sys/qYAZf2aVV6/NoiseSys/dp/post/json";
const char *topicreply = "$sys/qYAZf2aVV6/NoiseSys/dp/post/json/accepted";

#elif defined Device_2
// 机2
const char *DeviceName = "NoiseSys2";
const char *sign = "version=2018-10-31&res=products%%2FqYAZf2aVV6%%2Fdevices%%2FNoiseSys2&et=2018097402&method=md5&sign=E%%2B7DhwPgVNOMGTQuVkHzyg%%3D%%3D"; // md5算法生成的sign, printf需要%%输出一个字符%

const char *topicpost = "$sys/qYAZf2aVV6/NoiseSys2/dp/post/json";
const char *topicreply = "$sys/qYAZf2aVV6/NoiseSys2/dp/post/json/accepted";

#elif defined Device_3
// 机2
const char *DeviceName = "NoiseSys3";
const char *sign = "version=2018-10-31&res=products%%2FqYAZf2aVV6%%2Fdevices%%2FNoiseSys3&et=2018097402&method=md5&sign=vaQdzyT3haf7OFXdMs%%2Fb5g%%3D%%3D"; // md5算法生成的sign, printf需要%%输出一个字符%

const char *topicpost = "$sys/qYAZf2aVV6/NoiseSys3/dp/post/json";
const char *topicreply = "$sys/qYAZf2aVV6/NoiseSys3/dp/post/json/accepted";

#elif defined Device_4
// 机2
const char *DeviceName = "NoiseSys4";
const char *sign = "version=2018-10-31&res=products%%2FqYAZf2aVV6%%2Fdevices%%2FNoiseSys4&et=2018097402&method=md5&sign=kT741g1OnI7TpVH2UQjiLw%%3D%%3D"; // md5算法生成的sign, printf需要%%输出一个字符%

const char *topicpost = "$sys/qYAZf2aVV6/NoiseSys4/dp/post/json";
const char *topicreply = "$sys/qYAZf2aVV6/NoiseSys4/dp/post/json/accepted";

#endif // device choice

uint8_t com_str_temp[300];

// 发送数据格式
// char * sendteststr = "{\\22params\\22:{\\22MeasuredIlluminance\\22:211.1}}";

/**
 * @brief 	连接MQTT,接入onenet,包括：
 * 		1.设置MQTT相关参数
 * 		2.建立TCP连接
 * 		3.请求会话(失败断开TCP重试)
 * 		4.订阅多个主题
 */
void onenet_MQTTConnect(void)
{
    // 设置参数
    sprintf(com_str_temp ,"AT+MCONFIG=\"%s\",\"%s\",\"%s\"\r\n", DeviceName, ProductID, sign);
    while (Air724_SendCmd(com_str_temp, "OK"))
        delay_ms(500);
    memset(com_str_temp, 0, sizeof(com_str_temp));
    
    // // 断开连接
    // onenet_TCPDisConnect();
    // delay_ms(200);

    // 建立TCP连接
    sprintf(com_str_temp, "AT+MIPSTART=\"%s\",%s\r\n", mqtturl, mqttport);
    while (Air724_SendCmd(com_str_temp, "OK"))
        delay_ms(500);
    memset(com_str_temp, 0, sizeof(com_str_temp));
    delay_ms(1000);

    // 请求会话//是否erro
    while (1)
    {
        if(Air724_SendCmd("AT+MCONNECT=1,120\r\n", "CONNACK OK") == RESET)
        {
            break;
        }
        delay_ms(500);
        if(Air724_SendCmd("AT+MCONNECT=1,120\r\n", "767") == RESET)
        {
            onenet_TCPDisConnect();
            sprintf(com_str_temp, "AT+MIPSTART=\"%s\",%s\r\n", mqtturl, mqttport);
            while (Air724_SendCmd(com_str_temp, "OK"))
                delay_ms(500);
        }
        delay_ms(500);
    }

    // 订阅主题
    printf("AT+MSUB=\"%s\",0\r\n",topicpost);
    delay_ms(500);
    printf("AT+MSUB=\"%s\",0\r\n",topicreply);
    delay_ms(500);
}

/**
 * @brief  TCP断开连接
 */
void onenet_TCPDisConnect(void)
{
    // 断开TCP连接
    while (Air724_SendCmd("AT+MIPCLOSE\r\n", "OK")) // matching baud rate
        delay_ms(500);
}

/**
 * @brief 	向已订阅主题发布消息
 *         数据传输格式必须满足 Alink JSON 格式
 *         Air724发送消息时用\\22替换掉引号"
 */
void onenet_MQTT_MPUB(char *strsend)
{
    printf("AT+MPUB=\"%s\",0,0,\"%s\"\r\n", topicpost, strsend);
}

void onenet_MQTT_MPUB_JSON(float strsend)
{
    char noise_json[80] = {0};
    sprintf(noise_json, "{\\22id\\22: 1,\\22dp\\22: {\\22Noise\\22: [{\\22v\\22:%.1f}]}}", strsend);
    onenet_MQTT_MPUB(noise_json);
}

/**
 * @brief  查询MQTT连接状态
 *         1:OK
 *         0:没连上
 */
uint8_t Connect_Check(void)
{
    if (Air724_SendCmd("AT+MQTTSTATU\r\n", "+MQTTSTATU :1\r\n\r\nOK\r\n")) // check mqtt connection status
    {
        return 0;
    }
    return 1;
}
