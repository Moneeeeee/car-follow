#include "LED.h"                  // Device header

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOF, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOF, GPIO_Pin_3);
}
 
void LED_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOF, GPIO_Pin_3) == 0)
	{
		GPIO_SetBits(GPIOF, GPIO_Pin_3);
	}
	else
	{
		GPIO_ResetBits(GPIOF, GPIO_Pin_3);
	}
}

void LED_ON(void)
{
    GPIO_ResetBits(GPIOF, GPIO_Pin_3);
}

void LED_OFF(void)
{
    GPIO_SetBits(GPIOF, GPIO_Pin_3);
}

void Led_Flash(uint16_t time)
{
	static int temp;
	if(0==time) LED=0;
	else		if(++temp==time)	LED=~LED,temp=0;
}

