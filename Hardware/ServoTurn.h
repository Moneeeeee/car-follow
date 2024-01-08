#ifndef __SERVOTURN_H__
#define __SERVOTURN_H__

#include "sys.h"


#define Servo_Right_90 	TIM_SetCompare2(TIM2,195)
#define Servo_Right_45 	TIM_SetCompare2(TIM2,190)//��ת45

#define Servo_Front   		TIM_SetCompare2(TIM2,185)//�������,(15/200)*20ms=1.5ms

#define Servo_Left_45 		TIM_SetCompare2(TIM2,180)
#define Servo_Left_90 		TIM_SetCompare2(TIM2,175)//��ת45

void Servo_PWM_Init(void);
void Set_Servo_Position(float Angle);

#endif


