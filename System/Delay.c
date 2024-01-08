#include "delay.h"


/**
  * @brief  微秒级延时
  * @param  xus 延时时长，范围：0~233015
  * @retval 无
  */
void Delay_us(uint32_t xus)
{
	SysTick->LOAD = 72 * xus;				//设置定时器重装值
	SysTick->VAL = 0x00;					//清空当前计数值
	SysTick->CTRL = 0x00000005;				//设置时钟源为HCLK，启动定时器
	while(!(SysTick->CTRL & 0x00010000));	//等待计数到0
	SysTick->CTRL = 0x00000004;				//关闭定时器
}

/**
  * @brief  毫秒级延时
  * @param  xms 延时时长，范围：0~4294967295
  * @retval 无
  */
void Delay_ms(uint32_t xms)
{
	while(xms--)
	{
		Delay_us(1000);
	}
}
 
/**
  * @brief  秒级延时
  * @param  xs 延时时长，范围：0~4294967295
  * @retval 无
  */
void Delay_s(uint32_t xs)
{
	while(xs--)
	{
		Delay_ms(1000);
	}
} 








//static u8  fac_us=0;//us延时倍乘数
//static u16 fac_ms=0;//ms延时倍乘数

///*
//********************************************************************************************************
//函数名称：Delay_Init(u8 SYSCLK)
//函数功能：初始化延迟函数
//硬件连接：SYSTICK的时钟固定为HCLK时钟的1/8，SYSCLK:系统时钟
//备    注：
//日    期:  2017-2-6
//*********************************************************************************************************
//*/
//void Delay_Init(u8 SYSCLK)
//{
////    SysTick->CTRL&=0xfffffffb;//bit2清空,选择外部时钟  HCLK/8
//    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);    //选择外部时钟  HCLK/8
//    fac_us=SYSCLK/8;            
//    fac_ms=(u16)fac_us*1000;
//}                                    

///*
//********************************************************************************************************
//函数名称：Delay_ms(u16 nms)
//函数功能：延时nms
//硬件连接：//SysTick->LOAD为24位寄存器,所以,最大延时为:
//                    //nms<=0xffffff*8*1000/SYSCLK
//                    //SYSCLK单位为Hz,nms单位为ms
//                    //对72M条件下,nms<=1864 
//备    注：
//日    期: 2017-2-6
//*********************************************************************************************************
//*/
//void Delay_ms(u16 nms)
//{                     
//    u32 temp;           
//    SysTick->LOAD=(u32)nms*fac_ms;//时间加载(SysTick->LOAD为24bit)
//    SysTick->VAL =0x00;           //清空计数器
//    SysTick->CTRL=0x01 ;          //开始倒数  
//    do
//    {
//        temp=SysTick->CTRL;
//    }
//    while(temp&0x01&&!(temp&(1<<16)));//等待时间到达   
//    SysTick->CTRL=0x00;       //关闭计数器
//    SysTick->VAL =0X00;       //清空计数器              
//}   

///*
//********************************************************************************************************
//函数名称：void Delay_us(u32 nus)
//函数功能：延时nus
//硬件连接：
//备    注:
//日    期: 2017-2-6
//*********************************************************************************************************
//*/                                      
//void Delay_us(u32 nus)
//{        
//    u32 temp;             
//    SysTick->LOAD=nus*fac_us; //时间加载               
//    SysTick->VAL=0x00;        //清空计数器
//    SysTick->CTRL=0x01 ;      //开始倒数      
//    do
//    {
//        temp=SysTick->CTRL;
//    }
//    while(temp&0x01&&!(temp&(1<<16)));//等待时间到达   
//    SysTick->CTRL=0x00;       //关闭计数器
//    SysTick->VAL =0X00;       //清空计数器     
//}
