#ifndef _state_h
#define _state_h

#include "sys.h"

//舵机引脚
#define STEER_PIN GPIO_Pin_6

//蜂鸣器引脚
#define BUZZER_PIN GPIO_Pin_3

////按键引脚-0~5：P21_4 P21_5 P21_6 P21_7 P20_0
//#define KEY1_PIN P22_0//中
//#define KEY2_PIN P22_1//上
//#define KEY3_PIN P22_2//下
//#define KEY4_PIN P22_3//左
//#define KEY5_PIN P21_6//右

//#define KEY1_PIN P20_0//中
//#define KEY2_PIN P21_7//上
//#define KEY3_PIN P21_5//下
//#define KEY4_PIN P21_4//左
//#define KEY5_PIN P21_6//右
//拨码开关引脚-从上到下
//#define SWITCH_KEY1_PIN P33_12//前三
//#define SWITCH_KEY2_PIN P33_13
//#define SWITCH_KEY3_PIN P21_3
//#define SWITCH_KEY4_PIN P20_6//后三
//#define SWITCH_KEY5_PIN P20_7
//#define SWITCH_KEY6_PIN P20_8

//#define SWITCH_KEY1_PIN P22_3//前三
//#define SWITCH_KEY2_PIN P21_2
//#define SWITCH_KEY3_PIN P21_3
//#define SWITCH_KEY4_PIN P20_6//后三
//#define SWITCH_KEY5_PIN P20_7
//#define SWITCH_KEY6_PIN P20_8


//void Peripheral_init(void);
void Parameter_init(void);
void Speed_strategy_choose(void);
void State_Adjust(void);

#endif
