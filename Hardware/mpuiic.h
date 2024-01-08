#ifndef __MPUIIC_H
#define __MPUIIC_H
#include "sys.h"

////F1
//#define AMG_SDA_IN()  {GPIOB->CRL&=0x0FFFFFFF;GPIOB->CRL|=(u32)8<<28;}//PB7����ģʽ
//#define AMG_SDA_OUT() {GPIOB->CRL&=0x0FFFFFFF;GPIOB->CRL|=(u32)3<<28;}//PB7����ģʽ
////F4
//#define AMG_SDA_IN()  {GPIOB->MODER&=~(3<<(7*2));GPIOB->MODER|=0<<7*2;}	//PB7����ģʽ
//#define AMG_SDA_OUT() {GPIOB->MODER&=~(3<<(7*2));GPIOB->MODER|=1<<7*2;}//PB7����ģʽ
//IO��������
#define MPU_SDA_IN()   {GPIOF->MODER&=~(3<<(4*2));GPIOF->MODER|=0<<4*2;}
#define MPU_SDA_OUT()  {GPIOF->MODER&=~(3<<(4*2));GPIOF->MODER|=1<<4*2;}//#define MPU_SDA_IN()   {GPIOF->MODER&=~(3<<(4*2));GPIOF->MODER|=0<<4*2;}
                                                                        //#define MPU_SDA_OUT()  {GPIOF->MODER&=~(3<<(4*2));GPIOF->MODER|=1<<4*2;}

//IO��������	 
#define MPU_IIC_SCL     PFout(2) //SCL
#define MPU_IIC_SDA     PFout(4) //SDA	
#define MPU_READ_SDA   	PFin(4) //SDA	

//IIC���в�������
void MPU_IIC_Delay(void);				//MPU IIC��ʱ����
void MPU_IIC_Init(void);                //��ʼ��IIC��IO��				 
void MPU_IIC_Start(void);				//����IIC��ʼ�ź�
void MPU_IIC_Stop(void);	  			//����IICֹͣ�ź�
void MPU_IIC_Send_Byte(uint8_t txd);			//IIC����һ���ֽ�
uint8_t MPU_IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
uint8_t MPU_IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void MPU_IIC_Ack(void);					//IIC����ACK�ź�
void MPU_IIC_NAck(void);				//IIC������ACK�ź�

void IMPU_IC_Write_One_Byte(uint8_t daddr,uint8_t addr,uint8_t data);
uint8_t MPU_IIC_Read_One_Byte(uint8_t daddr,uint8_t addr);	  
#endif

