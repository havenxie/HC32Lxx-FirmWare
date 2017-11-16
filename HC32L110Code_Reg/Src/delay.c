#include "delay.h"

void McuDelay( uint32_t cnt )
{
	while( cnt )
	{
		cnt--;
	}
}

static int8_t  fac_us=0;//us
static int16_t fac_ms=0;//ms

void delay_init(void)	 
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);//ѡ���ⲿʱ��  HCLK/8
	fac_us= 24;	//Ϊϵͳʱ�� 
	fac_ms=(int16_t)fac_us*1000;//ÿ��ms��Ҫ��systickʱ����     
    //L005_SystemCtrl->SYSTICK_CR_f.NOREF = 1;
//    L005_SystemCtrl->SYSTICK_CR_f.CLK_SEL = 2;
    
}	
//��ʱNus
void delay_us(int32_t nus)
{		
	int32_t temp;	    	 
	SysTick->LOAD=nus*fac_us; //ʱ�����	  		 
	SysTick->VAL=0x00;        //��ռ�����
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;          //��ʼ����	 
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//�ȴ�ʱ�䵽��   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;       //�رռ�����
	SysTick->VAL =0X00;       //��ռ�����	 
}
//��ʱNms

void delay_ms(int16_t nms)
{	 		  	  
	int32_t temp;		   
	SysTick->LOAD=(int32_t)nms*fac_ms;//ʱ�����(SysTick->LOADΪ24bit)
	SysTick->VAL =0x00;           //��ռ�����
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;          //��ʼ����  
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//�ȴ�ʱ�䵽��   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;       //�رռ�����
	SysTick->VAL =0X00;       //��ռ�����	  	    
} 

