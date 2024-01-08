#include "stm32f4xx.h"                  // Device header
#include "Motor.h"
#include "Encoder.h"
#include "LED.h"
#include "timer.h"
#include "usart.h"
extern u8 ov_frame;
extern volatile u16 jpeg_data_len;


//通用定时器3中断初始化
//arr：自动重装值。
//psc：时钟预分频数
//定时器溢出时间计算方法:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=定时器工作频率,单位:Mhz
//这里使用的是定时器3!
//void TIM3_Int_Init(u16 arr,u16 psc)
//{
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;
//	
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  ///使能TIM3时钟
//	
//	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  //定时器分频
//	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
//	TIM_TimeBaseInitStructure.TIM_Period=arr;   //自动重装载值
//	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
//	
//	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);
//	
//	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); //允许定时器3更新中断
//	TIM_Cmd(TIM3,ENABLE); //使能定时器3
//	
//	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn; //定时器3中断
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //抢占优先级1
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; //子优先级3
//	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
//	
//}

////定时器3中断服务函数
//void TIM3_IRQHandler(void)
//{
//	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //溢出中断
//	{
//		//printf("frame:%d\r\n",ov_frame);//打印帧率
//		//printf("jpeg_data_len:%d\r\n",jpeg_data_len);//打印帧率
//		ov_frame=0;
//	}
//	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //清除中断标志位
//}

//LED闪烁

//int Target_Position=0,Encoder_cnt = 0;
//uint8_t LEDTurn_Flag=0;
//uint8_t LED_Count=0;//u8 0-255
//void Time1_Init(void)//72MHz/3600/20=1kHz 1ms
//{
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);  //打开TIM1的中断时钟
//    
//    TIM_InternalClockConfig(TIM1);
//	
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
//	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
//	TIM_TimeBaseInitStructure.TIM_Period = 3599;
//	TIM_TimeBaseInitStructure.TIM_Prescaler = 19;
//	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
//	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);             //初始化
//	
//    TIM_ClearFlag(TIM1, TIM_FLAG_Update);
//    TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE);                    //打开定时器中断
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

//void TIM1_UP_IRQHandler(void)//1ms触发一次
//{
//    LED_Count++;
//    if(LEDTurn_Flag==1&&LED_Count>=200)
//    {
//        LED_Count=0;
//        LED_Turn();
//    }

//    TIM_ClearITPendingBit(TIM1,TIM_IT_Update);
//}


