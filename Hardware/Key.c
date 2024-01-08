#include "stm32f4xx.h" // Device header
#include "Key.h"
#include "Delay.h"


//����A - PF12
//����C - PF2
//����D - PB15

#define MenuKey_Left    GPIO_Pin_12  //F
#define MenuKey_Right   GPIO_Pin_15 //B
#define MenuKey_0   GPIO_Pin_8      //F


uint8_t Key1= 0;
uint8_t Key2= 0;
uint8_t Key3= 0;
uint8_t Key4= 0;
//uint8_t flag= 0;
void KEY_Init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
    
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��������Ĭ�ϸߵ�ƽ�������½ӵ�����
	GPIO_InitStructure.GPIO_Pin = MenuKey_Left | MenuKey_0 ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOF, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = MenuKey_Right|GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

uint8_t KEY1_Get(void)//����ѡ��
{
	if (GPIO_ReadInputDataBit(GPIOB, MenuKey_Right) == 0)
	{
		Delay_ms(10);
		while (GPIO_ReadInputDataBit(GPIOB, MenuKey_Right) == 0)
			;
		Delay_ms(10);
		Key1=1;
	}
	else
		Key1=0;

	return Key1;
}

uint8_t KEY2_Get(void)//����ǰ��
{
	if (GPIO_ReadInputDataBit(GPIOF, MenuKey_0) == 0)
	{
		Delay_ms(10);
		while (GPIO_ReadInputDataBit(GPIOF, MenuKey_0) == 0)
			;
		Delay_ms(10);
		Key2= 1;
	}
	else
		Key2=0;

	return Key2;
}


uint8_t KEY3_Get(void)//����ѡ��
{
	if (GPIO_ReadInputDataBit(GPIOF, MenuKey_Left) == 0)
	{
		Delay_ms(10);
		while (GPIO_ReadInputDataBit(GPIOF, MenuKey_Left) == 0)
			;
		Delay_ms(10);
		Key3 = 1;
	}
    else
		Key3=0;

	return Key3;

}

uint8_t KEY4_Get(void)//�������
{

	return Key4;

}


 
/**************************************************************************
�������ܣ�����ɨ��
��ڲ�����˫���ȴ�ʱ��
����  ֵ������״̬ 0���޶��� 1������ 2��˫�� 3������
**************************************************************************/
uint8_t click_N_Double (uint16_t double_time,uint16_t longpress_time)
{
		static	uint8_t flag_key,count_key,double_key,long_press;	
		static	uint16_t count_single,count;

		if(KEY==0)  count++;   //������־λδ��1
     else        count=0;
		if(count>longpress_time)long_press=1;
			
		if(0==KEY&&0==flag_key)		flag_key=1;	
	  if(0==count_key)
		{
				if(flag_key==1) 
				{
					double_key++;
					count_key=1;	
				}
				if(double_key==2) 
				{
					double_key=0;
					count_single=0;
					return 2;//˫��ִ�е�ָ��
				}
		}
		if(1==KEY)
		{
			flag_key=0,count_key=0;
			if(long_press==1)
			{
				double_key=0;
				count_single=0;
				long_press=0;
				return 3;
			}
		}
		
		if(1==double_key)
		{
			count_single++;
			if(count_single>double_time&&count<double_time)
			{
			double_key=0;
			count_single=0;	
			return 1;//����ִ�е�ָ��
			}
			if(count>double_time)
			{
			double_key=0;
			count_single=0;	
			}
		}	
		return 0;

}


