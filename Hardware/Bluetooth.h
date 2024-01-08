#ifndef __Bluetooth_H
#define __Bluetooth_H

void Bluetooth_Iint(void);
#include "sys.h"
#include "stm32f4xx_tim.h" 
void USART_Send(uint16_t Data);
void USART2_IRQHandler(void);

#endif



//#ifndef __Bluetooth_H
//#define __Bluetooth_H

//void Bluetooth_Iint(void);
//#include "sys.h"
//#include "stm32f4xx_tim.h" 
//void USART_Send(uint16_t Data);
//void USART2_IRQHandler(void);

//#endif
