#include "EXTI.h"

/**************************************************************************
�������ܣ��ⲿ�жϳ�ʼ��
��ڲ�������
����  ֵ���� 
��    �ã�����������MPU6050����INT�ģ�ÿ��MPU6050���������ʱ������INT����Ӧ�ĵ�ƽ�����
					�����������ⲿ�ж���Ϊ�������ڡ�����MPU6050���ݵ�ʵʱ�ԡ�
**************************************************************************/

void MPU6050_EXTI_Init(void)
{  
    GPIO_InitTypeDef GPIO_InitStructure;
    EXTI_InitTypeDef EXTI_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);//�ⲿ�жϣ���Ҫʹ��AFIOʱ��
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); //ʹ��PB�˿�ʱ��
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;            //�˿�����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;         //��������
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_Init(GPIOB, &GPIO_InitStructure);     //�����趨������ʼ��GPIOB 
    //GPIO_PinAFConfig(GPIOB,GPIO_PinSource5,GPIO_AF_USART1);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource5);
    
    EXTI_InitStructure.EXTI_Line=EXTI_Line6;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//�½��ش���
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);	 	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
    
    //////////////////�ⲿ�ж�5���ȼ�����Ҳ����MPU6050 INT���ŵ�����///////////��Ϊ�ǿ����жϣ��ʴ����ȼ�Ӧ����ߡ�
    NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;				//ʹ���ⲿ�ж�ͨ��
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//��ռ���ȼ�0�� 
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//�����ȼ�1
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
    NVIC_Init(&NVIC_InitStructure); 
}












