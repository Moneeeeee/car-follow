#ifndef __PWM_H
#define __PWM_H
#include "sys.h"


void Servo_PWM_Init(uint16_t arr,uint16_t psc) ;
    
void Moto_PWM_Init(uint16_t arr,uint16_t psc);

void PWM_SetCompare1(uint16_t Compare);

void PWM_SetCompare2(uint16_t Compare);

void Set_Servo_Position(float Angle);
#endif
