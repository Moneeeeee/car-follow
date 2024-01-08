#ifndef __VISIONANALYS_H__
#define __VISIONANALYS_H__
#include "sys.h"

#define MT9V03X_W               200             	//Í¼Ïñ¿í¶È 	·¶Î§1-188
#define MT9V03X_H               120             	//Í¼Ïñ¸ß¶È	·¶Î§1-120
void zhi(void);
void you(void);
void zuo(void);
void ting(void);
void er_zhi(void);
void OV2640_DCMI_Init(void);
void convertUint16toUint8(uint16_t inputImage[MT9V03X_H][MT9V03X_W], uint8_t outputImage[MT9V03X_H][MT9V03X_W]) ;

#endif





