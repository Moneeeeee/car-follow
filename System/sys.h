#ifndef __SYS_H
#define __SYS_H	 



//#define uint8_t uint8_t
//#define u16 uint16_t
//#define uint32_t uint32_t

#include "stm32f4xx.h"
#include "Delay.h"
#include "Encoder.h"
#include "USART.h"
//#include "USART2.h"
#include "direction.h"
#include "camera.h"
#include "state.h"
#include "LED.h"
#include "LCD.h"
#include "OLED.h"
#include "Key.h"
#include "EXTI.h"
#include "PWM.h"
//#include "USB_PlugIn.h"
#include "Timer.h"
//#include "adc.h"
#include "function.h"
#include "Buzzer.h"
#include "Speed.h"
#include "Control.h"
#include "Motor.h"
#include "Encoder.h"
#include "MPU6050.h"
//#include "stmflash.h"
//#include "SR04.h"
#include "PS2.h"
//#include "VOFA.h"
//#include "SHOW.h"
#include "DCMI.h"
#include "SCCB.h"
#include "OV2640.h"
#include "mpuiic.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "inv_mpu.h"
#include "VisionAnalys.h"
#include "Menu.h"
#include "Bluetooth.h"
#include "PS2.h"

////////////////////////////////////////////////////////////////////////////
#include <string.h> 
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



//�����Լ��ĵ��ѡ��ֻ����һ���������define��Ч
//#define GA12N20
//#define GM25370
#define TT130
//#define GB37520

#ifdef GB37520
#define BLC_KP 240
#define BLC_KD 0.75
#define SPD_KP 62
#define SPD_KI 0.31
#define TURN_KP -40
#define TURN_KD -0.6
#endif

#ifdef TT130
#define BLC_KP 360
#define BLC_KD 1.125
#define SPD_KP -72
#define SPD_KI -0.36
#define TURN_KP -40
#define TURN_KD -0.4
#endif

#ifdef GA12N20
#define BLC_KP -400
#define BLC_KD -0.75
#define SPD_KP -80
#define SPD_KI -0.4
#define TURN_KP -40
#define TURN_KD 0.6
#endif

#ifdef GM25370
#define BLC_KP 240
#define BLC_KD 0.75
#define SPD_KP -60
#define SPD_KI -0.3
#define TURN_KP -40
#define TURN_KD -0.6
#endif

//λ������,ʵ��51���Ƶ�GPIO���ƹ���
//����ʵ��˼��,�ο�<<CM3Ȩ��ָ��>>������(87ҳ~92ҳ).M4ͬM3����,ֻ�ǼĴ�����ַ����.
//IO�ڲ����궨��
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 
//IO�ڵ�ַӳ��
#define GPIOA_ODR_Addr    (GPIOA_BASE+20) //0x40020014
#define GPIOB_ODR_Addr    (GPIOB_BASE+20) //0x40020414 
#define GPIOC_ODR_Addr    (GPIOC_BASE+20) //0x40020814 
#define GPIOD_ODR_Addr    (GPIOD_BASE+20) //0x40020C14 
#define GPIOE_ODR_Addr    (GPIOE_BASE+20) //0x40021014 
#define GPIOF_ODR_Addr    (GPIOF_BASE+20) //0x40021414    
#define GPIOG_ODR_Addr    (GPIOG_BASE+20) //0x40021814   
#define GPIOH_ODR_Addr    (GPIOH_BASE+20) //0x40021C14    
#define GPIOI_ODR_Addr    (GPIOI_BASE+20) //0x40022014     

#define GPIOA_IDR_Addr    (GPIOA_BASE+16) //0x40020010 
#define GPIOB_IDR_Addr    (GPIOB_BASE+16) //0x40020410 
#define GPIOC_IDR_Addr    (GPIOC_BASE+16) //0x40020810 
#define GPIOD_IDR_Addr    (GPIOD_BASE+16) //0x40020C10 
#define GPIOE_IDR_Addr    (GPIOE_BASE+16) //0x40021010 
#define GPIOF_IDR_Addr    (GPIOF_BASE+16) //0x40021410 
#define GPIOG_IDR_Addr    (GPIOG_BASE+16) //0x40021810 
#define GPIOH_IDR_Addr    (GPIOH_BASE+16) //0x40021C10 
#define GPIOI_IDR_Addr    (GPIOI_BASE+16) //0x40022010 
 
//IO�ڲ���,ֻ�Ե�һ��IO��!
//ȷ��n��ֵС��16!
#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)  //��� 
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)  //���� 

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  //��� 
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  //���� 

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  //��� 
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  //���� 

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  //��� 
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)  //���� 

#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)  //��� 
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)  //����

#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)  //��� 
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)  //����

#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)  //��� 
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)  //����

#define PHout(n)   BIT_ADDR(GPIOH_ODR_Addr,n)  //��� 
#define PHin(n)    BIT_ADDR(GPIOH_IDR_Addr,n)  //����

#define PIout(n)   BIT_ADDR(GPIOI_ODR_Addr,n)  //��� 
#define PIin(n)    BIT_ADDR(GPIOI_IDR_Addr,n)  //����
////////////////////////////////////////////////////////////////////////////////// 
//Ex_NVIC_Configר�ö���
#define GPIO_A 				0
#define GPIO_B 				1
#define GPIO_C				2
#define GPIO_D 				3
#define GPIO_E 				4
#define GPIO_F 				5
#define GPIO_G 				6 
#define GPIO_H 				7 
#define GPIO_I 				8 

#define FTIR   				1  		//�½��ش���
#define RTIR   				2  		//�����ش���

//GPIO����ר�ú궨��
#define GPIO_MODE_IN    	0		//��ͨ����ģʽ
#define GPIO_MODE_OUT		1		//��ͨ���ģʽ
#define GPIO_MODE_AF		2		//AF����ģʽ
#define GPIO_MODE_AIN		3		//ģ������ģʽ

#define GPIO_SPEED_2M		0		//GPIO�ٶ�2Mhz
#define GPIO_SPEED_25M		1		//GPIO�ٶ�25Mhz
#define GPIO_SPEED_50M		2		//GPIO�ٶ�50Mhz
#define GPIO_SPEED_100M		3		//GPIO�ٶ�100Mhz

#define GPIO_PUPD_NONE		0		//����������
#define GPIO_PUPD_PU		1		//����
#define GPIO_PUPD_PD		2		//����
#define GPIO_PUPD_RES		3		//���� 

#define GPIO_OTYPE_PP		0		//�������
#define GPIO_OTYPE_OD		1		//��©��� 

//GPIO���ű�Ŷ���
#define PIN0				1<<0
#define PIN1				1<<1
#define PIN2				1<<2
#define PIN3				1<<3
#define PIN4				1<<4
#define PIN5				1<<5
#define PIN6				1<<6
#define PIN7				1<<7
#define PIN8				1<<8
#define PIN9				1<<9
#define PIN10				1<<10
#define PIN11				1<<11
#define PIN12				1<<12
#define PIN13				1<<13
#define PIN14				1<<14
#define PIN15				1<<15 

#define MT9V03X_W               200             	//ͼ���� 	��Χ1-188
#define MT9V03X_H               120             	//ͼ��߶�	��Χ1-120
    
typedef uint16_t uint16;
typedef uint8_t uint8;
typedef uint32_t uint32;
    
extern float Voltage;  //��ص�ѹ������صı���
extern uint8_t oled_index;
extern unsigned char DAT[7];
extern uint16_t PID_Parameter[10],Flash_Parameter[10];
extern  float pitch,roll,yaw;//�����Ǻ����ƫ����
extern  short gyrox,gyroy,gyroz;//���ٶ�
extern  short aacx,aacy,aacz;//���ٶ�
extern uint8_t CTRL_MODE,Mode_Change;      			//ģʽ
extern uint8_t delay_50,delay_flag,show_flag; //��ʱ��ر���
extern int Uart_Receive;
extern int   Encoder_Left,Encoder_Right;        //���ұ��������������
extern int   Moto1,Moto2;    //������������ո��������PWM
extern uint8_t Fore,Back,Left,Right;
extern uint8_t TkSensor;
extern float SR04_Distance;
extern int PS2_LX,PS2_LY,PS2_RX,PS2_RY,PS2_KEY; //PS2��ر��� 
extern uint8_t PS2_Plugin;
extern float Target_Speed,Turn_Speed;	//�����ٶȣ�����/ƫ����
//extern u8 ov_frame;
//extern float balance_KP,balance_KD; 	 // С��ֱ����PD����
extern float Position_KP,Position_KI, velocity_KP,velocity_KI;     // С���ٶȻ�PI����
extern float Turn_Kd,Turn_KP;
//extern    uint8_t g_ov_mode                                      /* bit0: 0, RGB565ģʽ;  1, JPEGģʽ */
//extern    uint16_t X,Y;
extern uint16_t rgb_buf[MT9V03X_H][MT9V03X_W];                                 /* ��������ͷ����*/
//extern   float rpwmval; 
//extern    uint8_t threshold;
//extern    uint8_t X_min,X_max,X_he;
//extern    uint16_t Xs_max,Xs_min=500,Xx_max=0,Xx_min=500;

#endif

