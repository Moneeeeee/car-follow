#ifndef _state_h
#define _state_h

#include "sys.h"

//�������
#define STEER_PIN GPIO_Pin_6

//����������
#define BUZZER_PIN GPIO_Pin_3

////��������-0~5��P21_4 P21_5 P21_6 P21_7 P20_0
//#define KEY1_PIN P22_0//��
//#define KEY2_PIN P22_1//��
//#define KEY3_PIN P22_2//��
//#define KEY4_PIN P22_3//��
//#define KEY5_PIN P21_6//��

//#define KEY1_PIN P20_0//��
//#define KEY2_PIN P21_7//��
//#define KEY3_PIN P21_5//��
//#define KEY4_PIN P21_4//��
//#define KEY5_PIN P21_6//��
//���뿪������-���ϵ���
//#define SWITCH_KEY1_PIN P33_12//ǰ��
//#define SWITCH_KEY2_PIN P33_13
//#define SWITCH_KEY3_PIN P21_3
//#define SWITCH_KEY4_PIN P20_6//����
//#define SWITCH_KEY5_PIN P20_7
//#define SWITCH_KEY6_PIN P20_8

//#define SWITCH_KEY1_PIN P22_3//ǰ��
//#define SWITCH_KEY2_PIN P21_2
//#define SWITCH_KEY3_PIN P21_3
//#define SWITCH_KEY4_PIN P20_6//����
//#define SWITCH_KEY5_PIN P20_7
//#define SWITCH_KEY6_PIN P20_8


//void Peripheral_init(void);
void Parameter_init(void);
void Speed_strategy_choose(void);
void State_Adjust(void);

#endif
