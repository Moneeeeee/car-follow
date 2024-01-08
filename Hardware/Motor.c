#include "Motor.h"


//这是电机正反转；
void Motor_Init(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE); //使能PB端口时钟
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;	//端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;      //推挽输出
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;     //50MHZ
    GPIO_Init(GPIOC, &GPIO_InitStructure);      //根据设定参数初始化GPIOB
    GPIO_ResetBits(GPIOC,GPIO_Pin_4);
    
}

/**************************************************************************
函数功能：赋值给PWM寄存器
入口参数：左轮PWM、右轮PWM
返回  值：无
**************************************************************************/
void Set_Pwm(int Moto1,int Moto2)
{
	if(Moto1<0){
        
        GPIO_SetBits(GPIOC,GPIO_Pin_2);
        GPIO_ResetBits(GPIOC,GPIO_Pin_3);
    }
	else
    {
        GPIO_ResetBits(GPIOC,GPIO_Pin_2);
        GPIO_SetBits(GPIOC,GPIO_Pin_3);
    }

	PWM_SetCompare1(myabs(Moto1));
    
    
	if(Moto2<0)	{
        GPIO_ResetBits(GPIOC,GPIO_Pin_4);
        GPIO_SetBits(GPIOC,GPIO_Pin_5);
    }
	else 
    {
        GPIO_SetBits(GPIOC,GPIO_Pin_4);
        GPIO_ResetBits(GPIOC,GPIO_Pin_5);
    }
	PWM_SetCompare2(myabs(Moto2));
    
}


/**************************************************************************
函数功能：绝对值函数
入口参数：int
返回  值：unsigned int
目    的：经过直立环和速度环以及转向环计算出来的PWM有可能为负值
					而只能赋给定时器PWM寄存器只能是正值。故需要对PWM进行绝对值处理
**************************************************************************/
int myabs(int a)
{ 
    
    int temp;
    if(a<0)  temp=-a;  
    else temp=a;
    
    return temp;
}
/**************************************************************************
函数功能：限制PWM赋值 
入口参数：无
返回  值：无
**************************************************************************/
void Xianfu_Pwm(void)
{
	 //===PWM满幅是7200 限制在4800
    if(Moto1<-4800 ) Moto1=-4800 ;
		if(Moto1>4800 )  Moto1=4800 ;
	  if(Moto2<-4800 ) Moto2=-4800 ;
		if(Moto2>4800 )  Moto2=4800 ;
}
/**************************************************************************
函数功能：异常关闭电机：防止电机功率过大
入口参数：倾角和电压
返回  值：无
**************************************************************************/
void Turn_Off(float angle, float voltage)
{
        if(angle<-40||angle>40||voltage<7.4f)	 //电池电压低于7.4V关闭电机
        {                                      //===倾角大于40度关闭电机																			 
                Moto1=0;
                Moto2=0;
        }
}

