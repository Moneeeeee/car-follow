#include "sys.h" 

//����NVIC 
//NVIC_PreemptionPriority:��ռ���ȼ�
//NVIC_SubPriority       :��Ӧ���ȼ�
//NVIC_Channel           :�жϱ��
//NVIC_Group             :�жϷ��� 0~4
//ע�����ȼ����ܳ����趨����ķ�Χ!����������벻���Ĵ���
//�黮��:
//��0:0λ��ռ���ȼ�,4λ��Ӧ���ȼ�
//��1:1λ��ռ���ȼ�,3λ��Ӧ���ȼ�
//��2:2λ��ռ���ȼ�,2λ��Ӧ���ȼ�
//��3:3λ��ռ���ȼ�,1λ��Ӧ���ȼ�
//��4:4λ��ռ���ȼ�,0λ��Ӧ���ȼ�
//NVIC_SubPriority��NVIC_PreemptionPriority��ԭ����,��ֵԽС,Խ����	   
void NVIC_Configuration(void)
{
    
        NVIC_InitTypeDef  NVIC_InitStructure;
        NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�ļ���ռ�ļ���Ӧ����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�

        //////////////////�ⲿ�ж�5���ȼ�����Ҳ����MPU6050 INT���ŵ�����///////////��Ϊ�ǿ����жϣ��ʴ����ȼ�Ӧ����ߡ�
        NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;				//ʹ���ⲿ�ж�ͨ��
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;	//��ռ���ȼ�0�� 
        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//�����ȼ�1
        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
        NVIC_Init(&NVIC_InitStructure); 
        
        //////////////////�ⲿ�ж�2���ȼ�����Ҳ���ǳ��������ŵ�����//////////////////
        NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;							//ʹ���ⲿ�ж�ͨ��
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;	//��ռ���ȼ�2 
        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					//�����ȼ�2 
        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
        NVIC_Init(&NVIC_InitStructure);  	  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���
        
        //////////////////Usart1 NVIC �ж����ȼ�����////////////////////////////////////
        NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x02 ;//��ռ���ȼ�2
        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;			//��ռ���ȼ�2
        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;						//IRQͨ��ʹ��
        NVIC_Init(&NVIC_InitStructure);														//����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���USART1
        
        //////////////////Usart2 NVIC �ж����ȼ�����Ҳ����������������//////////////////
        NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x02 ;//��ռ���ȼ�2
        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;		//�����ȼ�2
        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
        NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
        
}