#include "PWM.h"


//PWM�����ʼ���������������������PWM
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
//TIM4_PWM_Init(7199,0);//PWMƵ��=72000/(7199+1)=10Khz


#define TIM_SERVO       TIM10
#define GPIO_PORT_SERVO GPIOF
#define GPIO_PIN_SERVO  GPIO_Pin_6





//ͨ������TIM_OC1Init�е�TIM_OCInitStructure.TIM_Pulse
//�����ö���ľ���λ�á�TIM_Pulse��ֵ������һ����Χ�ڵ�����
//��Ӧ����ڲ�ͬλ�õĽǶ�

// ���PWM��ʼ��
void Servo_PWM_Init(uint16_t arr,uint16_t psc) 
    {
    // ʹ�� TIM ʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10, ENABLE);

    // ʹ�� GPIO ʱ��
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

    // ���� TIM ���ƶ��������
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = GPIO_PIN_SERVO;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIO_PORT_SERVO, &GPIO_InitStruct);

    // ���� GPIO ����Ϊ TIM ���ù���
    GPIO_PinAFConfig(GPIO_PORT_SERVO, GPIO_PinSource6, GPIO_AF_TIM10);

    // ���� TIM ��������
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_Period = arr; // ����Ϊ 20ms,arr//Ƶ��50Hz//12800-1
    
    TIM_TimeBaseStructure.TIM_Prescaler = psc; // ʱ��Ԥ��Ƶ��ʱ��Ƶ��Ϊ 84MHz/psc//84-1
    
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM_SERVO, &TIM_TimeBaseStructure);

    // ���� TIM Ϊ PWM ģʽ
    TIM_OCInitTypeDef TIM_OCInitStructure;
    TIM_SelectOCxM(TIM_SERVO,TIM_Channel_1, TIM_OCMode_PWM1);
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 0;                            //���ô�װ�벶��ȽϼĴ���������ֵ
    TIM_OC1Init(TIM_SERVO, &TIM_OCInitStructure);
    TIM_CtrlPWMOutputs(TIM_SERVO,ENABLE);	//MOE �����ʹ��	

	TIM_OC1PreloadConfig(TIM_SERVO, TIM_OCPreload_Enable);  //CH3Ԥװ��ʹ��	 
    
                         
	TIM_ARRPreloadConfig(TIM_SERVO, ENABLE); //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
    // ���� TIM
    TIM_Cmd(TIM_SERVO, ENABLE);
}


void Moto_PWM_Init(uint16_t arr,uint16_t psc)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);// 
 	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD , ENABLE);  //ʹ��GPIO����ʱ��ʹ��
   //���ø�����Ϊ�����������,���TIM4 CH3 CH4��PWM���岨��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13; //TIM4_CH3 //TIM4_CH4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;  //�����������
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
    
    // ���� GPIO ����Ϊ TIM ���ù���
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);

    //Timer clock = sysclock /(TIM_Prescaler+1) = 168M
	//Period = (TIM counter clock / TIM output clock) - 1 = 20K
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  ����Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
    TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0;                            //���ô�װ�벶��ȽϼĴ���������ֵ
    TIM_OCInitStructure.TIM_Pulse = arr >> 1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;     //�������:TIM����Ƚϼ��Ը�
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx

    TIM_CtrlPWMOutputs(TIM4,ENABLE);	//MOE �����ʹ��	

	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);  //CH3Ԥװ��ʹ��	 
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);  //CH4Ԥװ��ʹ��	 
	
	TIM_ARRPreloadConfig(TIM4, ENABLE); //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
	
	TIM_Cmd(TIM4, ENABLE);  //ʹ��TIM4
}


/**
  * @brief ��װ�أ���ֵ��PID�������
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





//�����PWM���ˣ�������Ƕ���Ŀ���//��ô���ƣ�������ͷ��⵽���ߵ�ʱ��
//�ͽ���PWM�жϣ����ö����ת��Ƕȣ�ʱ�̱仯

void Set_Servo_Position(float Angle) {

//    0  12800
//     
//    90 12160
//    
//    180 11520
//    
    TIM_SetCompare1(TIM_SERVO,12800 - Angle/180*1280);
    
    
}



//���ת�� + ����ͷ����




