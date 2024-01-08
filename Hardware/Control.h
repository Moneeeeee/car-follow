#ifndef __CONTROL_H
#define __CONTROL_H
#include "sys.h"



/*------------------------------------------------------*/
/* 					  外部变量声明 						*/
/*======================================================*/
#define PI 3.14159265


////	外部结构体声明
//typedef struct{
//	void (*INC)(pidpara *, const short);
//	void (*POS)(pidpara *, const short);
//}pidfunc;


////	结构体声明
//typedef struct pidpara{
////	执行函数
//	void (*action)(void);	// 动作执行
//	void (*getAct)(void);	// 实际值获取
////	PID参数
//	float alpha;			// 一阶低通滤波系数
//	float Kp;
//	float Ki;
//	float Kd;
////	计算相关
//	float I;				// 积分项暂存
//	int e1, e2, e3;			// 误差
//	int rs;               	// 计算结果
//	int thrsod;				// 阈值
//	int act;				// 实际值
//}pidpara;


/*------------------------------------------------------*/ 
/* 						函数声明 						*/
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
///*	 	  PID模块		*/
///*======================*/
//void inc_pid(struct pidpara *para, const short tar);
//void pos_pid(struct pidpara *para, const short tar);
//int getCalculateResult(const struct pidpara *para); // 获取计算结果，注意返回值类型要与结构体成员rs对应


#endif
