#ifndef  __KEY_H__
#define __KEY_H__

#include "sys.h"                  // Device header

#define KEY PBin(10)
void KEY_Init(void);
uint8_t KEY1_Get(void);//���ؼ�ֵΪ1��2��Ĭ��Ϊ0
uint8_t KEY2_Get(void);//���ؼ�ֵΪ1��2��Ĭ��Ϊ0
uint8_t KEY3_Get(void);
uint8_t KEY4_Get(void);


uint8_t click_N_Double (uint16_t double_time,uint16_t longpress_time);  //��������ɨ���˫������ɨ��

#endif      
