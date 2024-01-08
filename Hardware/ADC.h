#ifndef __ADC_H
#define __ADC_H	
#include "sys.h"
/**************************************************************************
**************************************************************************/
#define Battery_Ch 8		//Í¨µÀ8
void Adc_Init(void);
uint16_t Get_Adc(uint8_t ch);
float Get_battery_volt(void);  
#endif 
