#include "stdio.h" // standard library
#include "string.h"
#include <stdlib.h>

#include "stm32f10x.h" // Device header
#include "delay.h"
#include "usart.h"
#include "LED.h"
#include "OLED.h"
#include "noisen.h"
#include "Air724ug.h"
#include "onenet_MQTT.h"

static char *ini_str = "NoiseSys"; // original words
static char *air_OK = "air finished";
static char *PDP_OK = "PDP finished";
static char *MQTT_OK = "MQTT finished";
float noisen_data = 0.0f;
char noise_local[20] = {0};
char noise_json[80] = 0;

int main(void)
{
    delay_init();                   // Initial delay
    Usart1_Init(9600);              // Initial usart1
    LED_Init();                     // Initialize the LED
    nosen_init();                   // Initialize the nosen
    OLED_Init();                    // Initialize the OLED
    OLED_ShowString(1, 4, ini_str); // Show the initialized string
    // Air724_Reset();                 // Reset the Air724
    delay_ms(1000);
    Air724_Init();                  // Initialize the Air724
    OLED_ShowString(2, 3, air_OK);  // air724 initialization finished
    Air724_PDPact();                // activate PDP
    OLED_ShowString(3, 3, PDP_OK);  // air724 initialization finished
    onenet_MQTTConnect();           // Connect to onenet
    OLED_ShowString(4, 2, MQTT_OK); // air724 initialization finished
    delay_ms(1000);
    OLED_Clear();
    while (1)
    {
        if (!Connect_Check())
        {
            onenet_MQTTConnect(); // Connect to onenet
            OLED_Clear();
        }

        // get_noise();
        noisen_data = (float)(rand() % 100 + 1);
        sprintf(noise_json, "{\\22id\\22: 1,\\22dp\\22: {\\22Noise\\22: [{\\22v\\22:%.2f}]}}", noisen_data);
        onenet_MQTT_MPUB(noise_json);
        memset(noise_json, 0, sizeof(noise_json));

        sprintf(noise_local, "Noise:%.2f", noisen_data);
        OLED_ShowString(2, 1, noise_local);
        memset(noise_local, 0, sizeof(noise_local));
        delay_ms(1000);
    }
}
