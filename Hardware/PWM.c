#include "PWM.h"


//PWM输出初始化，这是左右两个电机的PWM
//arr：自动重装值
//psc：时钟预分频数
//TIM4_PWM_Init(7199,0);//PWM频率=72000/(7199+1)=10Khz


#define TIM_SERVO       TIM10
#define GPIO_PORT_SERVO GPIOF
#define GPIO_PIN_SERVO  GPIO_Pin_6





//通过调整TIM_OC1Init中的TIM_OCInitStructure.TIM_Pulse
//来设置舵机的具体位置。TIM_Pulse的值可以在一定范围内调整，
//对应舵机在不同位置的角度

// 舵机PWM初始化
void Servo_PWM_Init(uint16_t arr,uint16_t psc) 
    {
    // 使能 TIM 时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10, ENABLE);

    // 使能 GPIO 时钟
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

    // 配置 TIM 控制舵机的引脚
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = GPIO_PIN_SERVO;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIO_PORT_SERVO, &GPIO_InitStruct);

    // 配置 GPIO 引脚为 TIM 复用功能
    GPIO_PinAFConfig(GPIO_PORT_SERVO, GPIO_PinSource6, GPIO_AF_TIM10);

    // 配置 TIM 基本参数
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_Period = arr; // 周期为 20ms,arr//频率50Hz//12800-1
    
    TIM_TimeBaseStructure.TIM_Prescaler = psc; // 时钟预分频，时钟频率为 84MHz/psc//84-1
    
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM_SERVO, &TIM_TimeBaseStructure);

    // 配置 TIM 为 PWM 模式
    TIM_OCInitTypeDef TIM_OCInitStructure;
    TIM_SelectOCxM(TIM_SERVO,TIM_Channel_1, TIM_OCMode_PWM1);
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 0;                            //设置待装入捕获比较寄存器的脉冲值
    TIM_OC1Init(TIM_SERVO, &TIM_OCInitStructure);
    TIM_CtrlPWMOutputs(TIM_SERVO,ENABLE);	//MOE 主输出使能	

	TIM_OC1PreloadConfig(TIM_SERVO, TIM_OCPreload_Enable);  //CH3预装载使能	 
    
                         
	TIM_ARRPreloadConfig(TIM_SERVO, ENABLE); //使能TIMx在ARR上的预装载寄存器
    // 启动 TIM
    TIM_Cmd(TIM_SERVO, ENABLE);
}


void Moto_PWM_Init(uint16_t arr,uint16_t psc)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);// 
 	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD , ENABLE);  //使能GPIO外设时钟使能
   //设置该引脚为复用输出功能,输出TIM4 CH3 CH4的PWM脉冲波形
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13; //TIM4_CH3 //TIM4_CH4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;  //复用推挽输出
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
    
    // 配置 GPIO 引脚为 TIM 复用功能
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);

    //Timer clock = sysclock /(TIM_Prescaler+1) = 168M
	//Period = (TIM counter clock / TIM output clock) - 1 = 20K
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值  不分频
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
    TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 0;                            //设置待装入捕获比较寄存器的脉冲值
    TIM_OCInitStructure.TIM_Pulse = arr >> 1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;     //输出极性:TIM输出比较极性高
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx

    TIM_CtrlPWMOutputs(TIM4,ENABLE);	//MOE 主输出使能	

	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);  //CH3预装载使能	 
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);  //CH4预装载使能	 
	
	TIM_ARRPreloadConfig(TIM4, ENABLE); //使能TIMx在ARR上的预装载寄存器
	
	TIM_Cmd(TIM4, ENABLE);  //使能TIM4
}


/**
  * @brief ：装载，赋值（PID运算完后）
  * @param
  * @retval
  */
void PWM_SetCompare1(uint16_t Compare)
{
	TIM_SetCompare1(TIM4, Compare);//0-5000
}

void PWM_SetCompare2(uint16_t Compare)//0-5000
{
	TIM_SetCompare2(TIM4, Compare);
}





//舵机的PWM好了，下面就是舵机的控制//怎么控制？当摄像头检测到曲线的时候
//就进入PWM中断，设置舵机的转向角度；时刻变化

void Set_Servo_Position(float Angle) {

//    0  12800
//     
//    90 12160
//    
//    180 11520
//    
    TIM_SetCompare1(TIM_SERVO,12800 - Angle/180*1280);
    
    
}



//舵机转向 + 摄像头传参




