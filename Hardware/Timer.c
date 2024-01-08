#include "stm32f4xx.h"                  // Device header
#include "Motor.h"
#include "Encoder.h"
#include "LED.h"
#include "timer.h"
#include "usart.h"
extern u8 ov_frame;
extern volatile u16 jpeg_data_len;


//ͨ�ö�ʱ��3�жϳ�ʼ��
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//��ʱ�����ʱ����㷽��:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=��ʱ������Ƶ��,��λ:Mhz
//����ʹ�õ��Ƕ�ʱ��3!
//void TIM3_Int_Init(u16 arr,u16 psc)
//{
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;
//	
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  ///ʹ��TIM3ʱ��
//	
//	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  //��ʱ����Ƶ
//	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
//	TIM_TimeBaseInitStructure.TIM_Period=arr;   //�Զ���װ��ֵ
//	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
//	
//	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);
//	
//	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); //����ʱ��3�����ж�
//	TIM_Cmd(TIM3,ENABLE); //ʹ�ܶ�ʱ��3
//	
//	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn; //��ʱ��3�ж�
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //��ռ���ȼ�1
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; //�����ȼ�3
//	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
//	
//}

////��ʱ��3�жϷ�����
//void TIM3_IRQHandler(void)
//{
//	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //����ж�
//	{
//		//printf("frame:%d\r\n",ov_frame);//��ӡ֡��
//		//printf("jpeg_data_len:%d\r\n",jpeg_data_len);//��ӡ֡��
//		ov_frame=0;
//	}
//	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //����жϱ�־λ
//}

//LED��˸

//int Target_Position=0,Encoder_cnt = 0;
//uint8_t LEDTurn_Flag=0;
//uint8_t LED_Count=0;//u8 0-255
//void Time1_Init(void)//72MHz/3600/20=1kHz 1ms
//{
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);  //��TIM1���ж�ʱ��
//    
//    TIM_InternalClockConfig(TIM1);
//	
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
//	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
//	TIM_TimeBaseInitStructure.TIM_Period = 3599;
//	TIM_TimeBaseInitStructure.TIM_Prescaler = 19;
//	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
//	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);             //��ʼ��
//	
//    TIM_ClearFlag(TIM1, TIM_FLAG_Update);
//    TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE);                    //�򿪶�ʱ���ж�
//	
//    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
//	
//	NVIC_InitTypeDef NVIC_InitStructure;
//	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_TIM10_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//	NVIC_Init(&NVIC_InitStructure);
//	
//	TIM_Cmd(TIM1, ENABLE);
//    
//}

//void TIM1_UP_IRQHandler(void)//1ms����һ��
//{
//    LED_Count++;
//    if(LEDTurn_Flag==1&&LED_Count>=200)
//    {
//        LED_Count=0;
//        LED_Turn();
//    }

//    TIM_ClearITPendingBit(TIM1,TIM_IT_Update);
//}


