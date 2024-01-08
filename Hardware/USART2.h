#ifndef __USRAT2_H
#define __USRAT2_H 
#include "sys.h"
/**************************************************************************

**************************************************************************/
void uart2_init(uint32_t bound);
void USART2_IRQHandler(void);
void Uart2SendByte(char byte);   //串口发送一个字节
void Uart2SendBuf(char *buf, uint16_t len);
void Uart2SendStr(char *str);
void BluetoothCMD(int Uart_Receive);

#endif

