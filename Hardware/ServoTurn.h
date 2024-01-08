#ifndef __SERVOTURN_H__
#define __SERVOTURN_H__

#include "sys.h"


#define Servo_Right_90 	TIM_SetCompare2(TIM2,195)
#define Servo_Right_45 	TIM_SetCompare2(TIM2,190)//右转45

#define Servo_Front   		TIM_SetCompare2(TIM2,185)//方向摆正,(15/200)*20ms=1.5ms

#define Servo_Left_45 		TIM_SetCompare2(TIM2,180)
#define Servo_Left_90 		TIM_SetCompare2(TIM2,175)//左转45

void Servo_PWM_Init(void);
void Set_Servo_Position(float Angle);

#endif


