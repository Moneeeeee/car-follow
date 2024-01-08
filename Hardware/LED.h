#ifndef __LED_H
#define __LED_H

#include "sys.h"
//LED ¶Ë¿Ú¶¨Òå
#define LED PFout(10) // PF10


void LED_Init(void);
void LED_Turn(void);
void LED_ON(void);
void LED_OFF(void);
void Led_Flash(uint16_t time);
#endif
