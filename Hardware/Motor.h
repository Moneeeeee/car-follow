#ifndef __MOTOR_H
#define __MOTOR_H
#include "sys.h"


#define AIN2   PCout(2)
#define AIN1   PCout(3)
#define BIN1   PCout(4)
#define BIN2   PCout(5)


void Motor_Init(void);
void Set_Pwm(int moto1,int moto2);
int myabs(int a);
void Xianfu_Pwm(void);
void Turn_Off(float angle, float voltage);


#endif
