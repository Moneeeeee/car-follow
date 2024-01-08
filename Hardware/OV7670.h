#ifndef _OV7670_H
#define _OV7670_H
#include "sys.h"
#include "sccb.h"

#define OV7670_PWDN  	PGout(9)			//POWER DOWN控制信号 
#define OV7670_RST  	PGout(8)			//复位控制信号 
////////////////////////////////////////////////////////////////////////////////// 
#define OV7670_MID				0X7FA2    
#define OV7670_PID				0X7673
													  					 
#define OV7670_DATA   GPIO_ReadInputData(GPIOC,0x00FF) 					//数据输入端口
//GPIOC->IDR&0x00FF 
/////////////////////////////////////////
	    				 
uint8_t   OV7670_Init(void);		  	   		 
void OV7670_Light_Mode(uint8_t mode);
void OV7670_Color_Saturation(uint8_t sat);
void OV7670_Brightness(uint8_t bright);
void OV7670_Contrast(uint8_t contrast);
void OV7670_Special_Effects(uint8_t eft);
void OV7670_Window_Set(uint16_t sx,uint16_t sy,uint16_t width,uint16_t height);
void set_cif(void);

#endif





















