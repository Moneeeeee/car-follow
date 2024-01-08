//#include "DataScope.h"
//unsigned char DataScope_OutPut_Buffer[42] = {0};     //串口发送缓冲区
//int send_cnt = 0;
//static u8 Send_rasberry[60];
//int re_Encoder_Left,re_Encoder_Right;
//int Distance_A,Distance_B,Distance_C,Distance_D;
//u8 Urxbuf[8],Usart_Flag,x=0;
//short accelX,accelY,accelZ,gyroX,gyroY,gyroZ,magX,magY,magZ;



//void jiexi(void)
//{
//  float StrAngle,Speed;
//  TargetAngleDirection=Urxbuf[1];
//  TargetStrAngle=Urxbuf[2];//0~255
//  TargetSpeed=Urxbuf[3];//0~255
//  TargetModeSelect=Urxbuf[4];
//  TargetShiftPosition=Urxbuf[5];//控制参数
//  Sum=Urxbuf[7];
//  if(Sum==0x92)
//  {
//    if(TargetModeSelect==0x00)
//    {
//      StrAngle=TargetStrAngle*1-128;     //计算偏差
//      Speed=TargetSpeed*1-128;
//    }
//    else if(TargetModeSelect==0x01)
//    {
//      switch(TargetAngleDirection)
//      {
//        case 0x00: StrAngle=0,Speed=80;break;
//        case 0x10: StrAngle=60,Speed=90;break;
//        case 0x20: StrAngle=-60,Speed=90;break;
//        default: StrAngle=0,Speed=0;break;
//      }
//    }
//    Velocity=Speed/2;    //速度和角度。
//    Angle=StrAngle/200;
//    Sum=0x00;  
//    UartASendStr(Urxbuf,8);
//    memset(Urxbuf, 0, sizeof(u8)*8); //数组清零    
//  }
////  printf("respond:");
////  UartASendStr(Urxbuf,8);
//}
