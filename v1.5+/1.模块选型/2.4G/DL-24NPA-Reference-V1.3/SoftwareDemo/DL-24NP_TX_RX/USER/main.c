#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	 
#include "24l01.h" 	 
 
 
/*
Ӳ��SPI2 ���CS

/SCL(PB13)
/MISO(PB14)
/MOSI(PB15)

/CS(PB8)
/CE(PB11))
/IRQ(PB12)

*/

/*ѡ��ģʽ: rx = 0  tx = !rx*/
u8 Mode = 1;

void rf_rx_mode()
{


}

int main(void)
{
	u8 t = 100;
	u8 tmp_buf[33];		    
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200

 	NRF24L01_Init();    		//��ʼ��NRF24L01 
	
	while(NRF24L01_Check())
	{
		printf("NRF24L01_Check: erro\n");
	} 
	printf("NRF24L01 OK\n");
 	while(1)
	{	
		if(Mode==0)//RXģʽ
		{
			NRF24L01_RX_Mode();		  
			while(1)
			{
				if(NRF24L01_RxPacket(tmp_buf)==0)//һ�����յ���Ϣ,����ʾ����.
				{
					tmp_buf[32]=0;//�����ַ���������
					printf("NRF24L01_Rx:OK,Rec data = %s",tmp_buf);
				}
				delay_ms(10);
				if(t == 0)
				{
					t = 100;
					printf("Try to Rx\n");
				}else t--;
				
			};
		}else//TXģʽ
		{
			NRF24L01_TX_Mode();
//			NRF24L01_ContinuousTX();//����ר��, �Ῠס
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
