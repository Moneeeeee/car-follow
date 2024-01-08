#ifndef __ENCODER_H
#define __ENCODER_H
#include "sys.h"


#define ENCODER_TIM_PERIOD (u16)(65535)   //103�Ķ�ʱ����16λ 2��16�η������65536
void Encoder_Init_TIM2(void);
void Encoder_Init_TIM3(void);
int Read_Encoder(int TIMx);
void TIM2_IRQHandler(void);
void TIM3_IRQHandler(void);

#endif
