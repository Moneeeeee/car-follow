#ifndef __CONTROL_H
#define __CONTROL_H
#include "sys.h"



/*------------------------------------------------------*/
/* 					  �ⲿ�������� 						*/
/*======================================================*/
#define PI 3.14159265


////	�ⲿ�ṹ������
//typedef struct{
//	void (*INC)(pidpara *, const short);
//	void (*POS)(pidpara *, const short);
//}pidfunc;


////	�ṹ������
//typedef struct pidpara{
////	ִ�к���
//	void (*action)(void);	// ����ִ��
//	void (*getAct)(void);	// ʵ��ֵ��ȡ
////	PID����
//	float alpha;			// һ�׵�ͨ�˲�ϵ��
//	float Kp;
//	float Ki;
//	float Kd;
////	�������
//	float I;				// �������ݴ�
//	int e1, e2, e3;			// ���
//	int rs;               	// ������
//	int thrsod;				// ��ֵ
//	int act;				// ʵ��ֵ
//}pidpara;


/*------------------------------------------------------*/ 
/* 						�������� 						*/
/*======================================================*/

//void EXTI9_5_IRQHandler(void);
////int balance_UP(float Angle,float Mechanical_balance,float Gyro);
//int Position(int encoder_left,int encoder_right,int target);
//int Turn_UP(int gyro_Z, int RC);
//void Tracking(void);
//void Get_RC(void);
//void Key(void);
//void Mode_Init(uint8_t CMD_MODE);

///*----------------------*/
///*	 	  PIDģ��		*/
///*======================*/
//void inc_pid(struct pidpara *para, const short tar);
//void pos_pid(struct pidpara *para, const short tar);
//int getCalculateResult(const struct pidpara *para); // ��ȡ��������ע�ⷵ��ֵ����Ҫ��ṹ���Աrs��Ӧ


#endif
