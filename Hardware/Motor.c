#include "Motor.h"


//���ǵ������ת��
void Motor_Init(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE); //ʹ��PB�˿�ʱ��
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;	//�˿�����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;      //�������
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;     //50MHZ
    GPIO_Init(GPIOC, &GPIO_InitStructure);      //�����趨������ʼ��GPIOB
    GPIO_ResetBits(GPIOC,GPIO_Pin_4);
    
}

/**************************************************************************
�������ܣ���ֵ��PWM�Ĵ���
��ڲ���������PWM������PWM
����  ֵ����
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
�������ܣ�����ֵ����
��ڲ�����int
����  ֵ��unsigned int
Ŀ    �ģ�����ֱ�������ٶȻ��Լ�ת�򻷼��������PWM�п���Ϊ��ֵ
					��ֻ�ܸ�����ʱ��PWM�Ĵ���ֻ������ֵ������Ҫ��PWM���о���ֵ����
**************************************************************************/
int myabs(int a)
{ 
    
    int temp;
    if(a<0)  temp=-a;  
    else temp=a;
    
    return temp;
}
/**************************************************************************
�������ܣ�����PWM��ֵ 
��ڲ�������
����  ֵ����
**************************************************************************/
void Xianfu_Pwm(void)
{
	 //===PWM������7200 ������4800
    if(Moto1<-4800 ) Moto1=-4800 ;
		if(Moto1>4800 )  Moto1=4800 ;
	  if(Moto2<-4800 ) Moto2=-4800 ;
		if(Moto2>4800 )  Moto2=4800 ;
}
/**************************************************************************
�������ܣ��쳣�رյ������ֹ������ʹ���
��ڲ�������Ǻ͵�ѹ
����  ֵ����
**************************************************************************/
void Turn_Off(float angle, float voltage)
{
        if(angle<-40||angle>40||voltage<7.4f)	 //��ص�ѹ����7.4V�رյ��
        {                                      //===��Ǵ���40�ȹرյ��																			 
                Moto1=0;
                Moto2=0;
        }
}

