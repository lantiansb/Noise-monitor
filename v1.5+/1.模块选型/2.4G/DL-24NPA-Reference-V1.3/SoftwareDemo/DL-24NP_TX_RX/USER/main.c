#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	 
#include "24l01.h" 	 
 
 
/*
硬件SPI2 软件CS

/SCL(PB13)
/MISO(PB14)
/MOSI(PB15)

/CS(PB8)
/CE(PB11))
/IRQ(PB12)

*/

/*选择模式: rx = 0  tx = !rx*/
u8 Mode = 1;

void rf_rx_mode()
{


}

int main(void)
{
	u8 t = 100;
	u8 tmp_buf[33];		    
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化为115200

 	NRF24L01_Init();    		//初始化NRF24L01 
	
	while(NRF24L01_Check())
	{
		printf("NRF24L01_Check: erro\n");
	} 
	printf("NRF24L01 OK\n");
 	while(1)
	{	
		if(Mode==0)//RX模式
		{
			NRF24L01_RX_Mode();		  
			while(1)
			{
				if(NRF24L01_RxPacket(tmp_buf)==0)//一旦接收到信息,则显示出来.
				{
					tmp_buf[32]=0;//加入字符串结束符
					printf("NRF24L01_Rx:OK,Rec data = %s",tmp_buf);
				}
				delay_ms(10);
				if(t == 0)
				{
					t = 100;
					printf("Try to Rx\n");
				}else t--;
				
			};
		}else//TX模式
		{
			NRF24L01_TX_Mode();
//			NRF24L01_ContinuousTX();//测试专用, 会卡住
			while(1)
			{
				sprintf((char *)tmp_buf,"NRF24L01P TX-RX Test!\n");
				if(NRF24L01_TxPacket(tmp_buf) == TX_OK)
				{
					printf("NRF24L01 Tx OK!\n");
				}else
				{
					/**/
					printf("NRF24L01 Tx FAIL!\n");
				};
				delay_ms(500);				    
			};
		} 
	}

}
