
//#include "control.h"  
//float Position_KP,Position_KI, velocity_KP,velocity_KI;
////#define T 0.245f
////#define L 0.29f
////#define K 14.00f
//#define T 0.156f
//#define L 0.1445f
//#define K 622.8f
//u8 Flag_Target,Flag_Change;  //��ر�־λ
//float Voltage_Temp,Voltage_Count,Voltage_All;  //��ѹ������ر���
//int j,sum;

///**************************************************************************
//�������ܣ�С���˶���ѧģ��
//��ڲ������ٶȺ�ת��
//����  ֵ����
//**************************************************************************/
//void Kinematic_Analysis(float velocity,float angle)
//{
//    Target_A=velocity*(1+T*tan(angle)/2/L); 
//    Target_B=velocity*(1-T*tan(angle)/2/L);      //���ֲ���
//    Servo=SERVO_INIT+angle*K;                    //���ת��   
//}
///**************************************************************************
//�������ܣ����еĿ��ƴ��붼��������
//         ��ʱ�жϴ���
//         �ϸ�֤���������ݴ����ʱ��ͬ��         
//**************************************************************************/
//void Control(void)
//{
//  //oled_show();               //��ʾ����
//  Encoder_Left=Read_Encoder(2);                                      
//  Encoder_Right=-Read_Encoder(3);      //��ȡ���ұ�����   
//  Delay_ms(50);                  //=====��ʱ�ȴ��ȶ�  
//  if(Turn_Off(Voltage)==0&&Flag_Way==0)
//   {   
//      jiexi();
//      Kinematic_Analysis(Velocity,Angle);                                   //С���˶�ѧ����
//      Motor_A=Target_A*20;                                                     //===������A����PWM
//      Motor_B=Target_B*20;                                                    //===������B����PWM 
//      Xianfu_Pwm();                                                      //===PWM�޷�
//      Set_Pwm(Motor_A,Motor_B,Servo);                                    //===��ֵ��PWM�Ĵ���  
//    
//   }       
//  else if(Turn_Off(Voltage)==0&&Flag_Way==1)                                  //===����������쳣
//    {
//      Get_RC();
//      Kinematic_Analysis(Velocity,Angle);                                   //С���˶�ѧ���� 
//      Motor_A=Incremental_PI_Left(Encoder_Left,Target_A);                   //===�ٶȱջ����Ƽ�����A����PWM
//      Motor_B=Incremental_PI_Right(Encoder_Right,Target_B);                  //===�ٶȱջ����Ƽ�����B����PWM 
//      Xianfu_Pwm();                                                      //===PWM�޷�
//      Set_Pwm(Motor_A,Motor_B,Servo);                                    //===��ֵ��PWM�Ĵ���  
//    }
//  else Set_Pwm(0,0,SERVO_INIT);  //===��ֵ��PWM�Ĵ���    
//  Voltage_Temp=Get_battery_volt();                                     //=====��ȡ��ص�ѹ    
//  Voltage_Count++;                                                     //=====ƽ��ֵ������
//  Voltage_All+=Voltage_Temp;                                           //=====��β����ۻ�
//  if(Voltage_Count==10) Voltage=Voltage_All/10,Voltage_All=0,Voltage_Count=0;//=====��ƽ��ֵ                                       
//  if(Flag_Show==0)        Led_Flash(100);
//  else if(Flag_Show==1)  Led_Flash(0);  //led��˸
//  Key();    //===ɨ�谴��״̬ ����˫�����Ըı�С������״̬

//}

/////**************************************************************************
////�������ܣ���ֵ��PWM�Ĵ���
////��ڲ�����PWM
////����  ֵ����
////**************************************************************************/
////void Set_Pwm(int motor_a,int motor_b,int servo)
////{
////      if(motor_a<0)      PWMA2=7200,PWMA1=7200+motor_a;
////      else               PWMA1=7200,PWMA2=7200-motor_a;
////    
////      if(motor_b<0)      PWMB1=7200,PWMB2=7200+motor_b;
////      else               PWMB2=7200,PWMB1=7200-motor_b;
////     SERVO=servo;  
////}
/////**************************************************************************
////�������ܣ�����PWM��ֵ 
////��ڲ�������ֵ
////����  ֵ����
////**************************************************************************/
////void Xianfu_Pwm(void)
////{  
////    int Amplitude=6900;    //===PWM������7200 ������6900
////    if(Motor_A<-Amplitude) Motor_A=-Amplitude;  
////    if(Motor_A>Amplitude)  Motor_A=Amplitude;  
////    if(Motor_B<-Amplitude) Motor_B=-Amplitude;  
////    if(Motor_B>Amplitude)  Motor_B=Amplitude;    
////    if(Servo<(SERVO_INIT-500))     Servo=SERVO_INIT-500;    //����޷�
////    if(Servo>(SERVO_INIT+500))     Servo=SERVO_INIT+500;      //����޷�
////}
/////************************************************************************
////�������ܣ������޸�С������״̬ 
////��ڲ�������
////����  ֵ����
////**************************************************************************/
////void Key(void)
////{  
////  u8 tmp,tmp2;
////  tmp=click(); 
//////  tmp=click_N_Double(50); //˫����˫���ȴ�ʱ��500ms
////  if(tmp==1)Flag_Stop=!Flag_Stop;//��������С������ͣ
////  //if(tmp==2)Flag_Show=!Flag_Show;//˫������С������ʾ״̬
////  tmp2=Long_Press();  //����        
////  if(tmp2==1)Flag_Show=!Flag_Show;//����С������ʾ״̬                 
////}
/////**************************************************************************
////�������ܣ��쳣�رյ��
////��ڲ�������ѹ
////����  ֵ��1���쳣  0������
////**************************************************************************/
////u8 Turn_Off( int voltage)
////{
////      u8 temp;
////      if(voltage<740||Flag_Stop==1)//��ص�ѹ����11.1V�رյ��
////      {                                                  
////      temp=1;  
////      PWMA1=0; //�������λ����                                           
////      PWMB1=0; //�������λ����
////      PWMA2=0; //�������λ����
////      PWMB2=0; //�������λ����            
////      }
////      else
////      temp=0;
////      return temp;    
////}



/////**************************************************************************
////�������ܣ�����ֵ����
////��ڲ�����int
////����  ֵ��unsigned int
////**************************************************************************/
////int myabs(int a)
////{        
////    int temp;
////    if(a<0)  temp=-a;  
////    else temp=a;
////    return temp;
////}


/////**************************************************************************
////�������ܣ�����PI������
////��ڲ���������������ֵ��Ŀ���ٶ�
////����  ֵ�����PWM
////��������ʽ��ɢPID��ʽ 
////pwm+=Kp[e��k��-e(k-1)]+Ki*e(k)+Kd[e(k)-2e(k-1)+e(k-2)]
////e(k)������ƫ�� 
////e(k-1)������һ�ε�ƫ��  �Դ����� 
////pwm�����������
////�����ǵ��ٶȿ��Ʊջ�ϵͳ���棬ֻʹ��PI����
////pwm+=Kp[e��k��-e(k-1)]+Ki*e(k)
////**************************************************************************/
////int Incremental_PI_Left (int Encoder,int Target)
////{   
////   static int Bias,Pwm,Last_bias;
////   Bias=Target-Encoder;                //����ƫ��
////   Pwm+=Velocity_KP*(Bias-Last_bias)+Velocity_KI*Bias;   //����ʽPI������
////   Last_bias=Bias;                     //������һ��ƫ�� 
////   return Pwm;                         //�������
////}
////int Incremental_PI_Right (int Encoder,int Target)
////{   
////   static int Bias,Pwm,Last_bias;
////   Bias=Target-Encoder;                //����ƫ��
////   Pwm+=Velocity_KP*(Bias-Last_bias)+Velocity_KI*Bias;   //����ʽPI������
////   Last_bias=Bias;                     //������һ��ƫ�� 
////   return Pwm;                         //�������
////}


///////**************************************************************************
//////�������ܣ�ͨ��ָ���С������ң��
//////��ڲ�����PS2ָ��
//////����  ֵ���� 
//////**************************************************************************/
//////void Get_RC(void)//PS2����
//////{
//////  int Yuzhi=2;
//////  float LY,RX;
//////  LY=PS2_LY-128;     //����ƫ��
//////  RX=PS2_RX-128;
//////  if(LY>-Yuzhi&&LY<Yuzhi)LY=0;   //С�Ƕ���Ϊ���� ��ֹ���������쳣
//////  if(RX>-Yuzhi&&RX<Yuzhi)RX=0;
//////   Velocity=-LY/2;    //�ٶȺ�ҡ�˵�������ء�
//////   Angle=RX/200; 
//////      
//////}








/////**************************************************************************
////�������ܣ����еĿ��ƴ��붼��������
////         5ms��ʱ�ж���MPU6050��INT���Ŵ���
////         �ϸ�֤���������ݴ����ʱ��ͬ��	
////				 ��MPU6050�Ĳ���Ƶ�������У����ó�100HZ�����ɱ�֤6050��������10ms����һ�Ρ�
////				 ����imv_mpu.h�ļ���26�еĺ궨������޸�(#define DEFAULT_MPU_HZ  (100))
////**************************************************************************/
////#define SPEED_Y 100 //����(ǰ��)����趨�ٶ�
////#define SPEED_Z 80//ƫ��(����)����趨�ٶ� 


////int ServoAngle;
//////int Balance_Pwm,Velocity_Pwm,Turn_Pwm;
////int Position_Pwm,Turn_Pwm;

////float Mechanical_angle=0; 
////float Target_Speed=0;	//�����ٶȣ������������ڿ���С��ǰ�����˼����ٶȡ�
////float Turn_Speed=0;		//�����ٶȣ�ƫ����





//////����

////float Position_KP=SPD_KP;     // С���ٶȻ�PI����
////float Position_KI=SPD_KI;

////float Turn_Kd=TURN_KD;//ת��KP��KD
////float Turn_KP=TURN_KP;

////void EXTI9_5_IRQHandler(void) 
////{

////	if(PBin(5)==0)
////	{
////        EXTI->PR=1<<5;                                           //���LINE5�ϵ��жϱ�־λ
////        mpu_dmp_get_data(&pitch,&roll,&yaw);										 //�õ�ŷ���ǣ���̬�ǣ�������
////        MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);								 //�õ�����������
////        Encoder_Left=Read_Encoder(2);                            //��ȡ��������ֵ����֤�������һ��
////        Encoder_Right=-Read_Encoder(3);                          //��ȡ��������ֵ
////        Led_Flash(60);
////        Target_Speed=Target_Speed>SPEED_Y?SPEED_Y:(Target_Speed<-SPEED_Y?(-SPEED_Y):Target_Speed);//�޷�
////        Turn_Speed=Turn_Speed>SPEED_Z?SPEED_Z:(Turn_Speed<-SPEED_Z?(-SPEED_Z):Turn_Speed);//�޷�( (20*100) * 100)
////            
////				Velocity_Pwm=velocity(Encoder_Left,Encoder_Right,Target_Speed);       //===�ٶȻ�PID����	 
////				Turn_Pwm =Turn_UP(gyroz,Turn_Speed);        //===ת��PID����
////				Moto1=Velocity_Pwm;  	                            	//===�������ֵ������PWM
////				Moto2=Velocity_Pwm;                  //===�������ֵ������PWM
////				Xianfu_Pwm();		 //===PWM�޷�
////				Set_Pwm(Moto1,Moto2);                                     //===��ֵ��PWM�Ĵ���		
////				Set_Servo_Position((Turn_Pwm + 100) * 5 + 1000);		//��Turn_PWM ���ݴ��� ����Servo��
////	} 
////}


/////**************************************************************************
////�������ܣ��ٶ�PI����
////��ڲ����������������ֵ
////����  ֵ���ٶȿ���PWM
////**************************************************************************/
////int Position(int encoder_left,int encoder_right,int Target_Speed)
////{  
////    static float Position,Encoder_Least,Encoder;
////	  static float Encoder_Integral;
////   //=============�ٶ�PI������=======================//	
////		Encoder_Least =(Encoder_Left+Encoder_Right);//-target;                    //===��ȡ�����ٶ�ƫ��==�����ٶȣ����ұ�����֮�ͣ�-Ŀ���ٶ� 
////		Encoder *= 0.8f;		                                                //===һ�׵�ͨ�˲���       
////		Encoder += Encoder_Least*0.2f;	                                    //===һ�׵�ͨ�˲���    
////		Encoder_Integral +=Encoder;                                       //===���ֳ�λ�� ����ʱ�䣺10ms
////		Encoder_Integral=Encoder_Integral - Target_Speed;                       //===����ң�������ݣ�����ǰ������
////		if(Encoder_Integral>10000)  	Encoder_Integral=10000;             //===�����޷�
////		if(Encoder_Integral<-10000)		Encoder_Integral=-10000;            //===�����޷�	
////		Position=Encoder*Position_KP+Encoder_Integral*Position_KI;        //===�ٶȿ���	
////	  if(pitch<-40||pitch>40) 			Encoder_Integral=0;     						//===����رպ��������
////	  return Position;
////}
/////**************************************************************************
////�������ܣ�ת��PD����
////��ڲ����������������ֵ��Z����ٶ�
////����  ֵ��ת�����PWM
////**************************************************************************/

////int Turn_UP(int gyro_Z, int RC)
////{
////	int PWM_out;
////		/*ת��Լ��*/
////	if(RC==0)Turn_Kd=Turn_Kd;//��������ת��ָ�����ת��Լ��
////	else Turn_Kd=0;//������ת��ָ����յ�����ȥ��ת��Լ��
////	
////	PWM_out=Turn_Kd*gyro_Z + Turn_KP*RC;
////	return PWM_out;           //���PWM
////}


//////------------------------------------------

//////#define T 0.245f
//////#define L 0.29f
//////#define K 14.00f
////#define T 0.156f
////#define L 0.1445f
////#define K 622.8f
////#define SERVO_INIT 0
////u8 Flag_Target,Flag_Change;  //��ر�־λ
////float Voltage_Temp,Voltage_Count,Voltage_All;  //��ѹ������ر���
////int j,sum;
////int Target_A,Target_B,Servo;

/////**************************************************************************
////�������ܣ�С���˶���ѧģ��
////��ڲ������ٶȺ�ת��
////����  ֵ����
////**************************************************************************/
////void Kinematic_Analysis(float velocity,float angle)
////{
////    Target_A=velocity*(1+T*tan(angle)/2/L); 
////    Target_B=velocity*(1-T*tan(angle)/2/L);      //���ֲ���
////    Servo=SERVO_INIT+angle*K;                    //���ת��   
////    
////    
////}

/////**************************************************************************
////�������ܣ����еĿ��ƴ��붼��������
////         ��ʱ�жϴ���
////         �ϸ�֤���������ݴ����ʱ��ͬ��         
////**************************************************************************/
////void Control(void)
////{
////  //oled_show();               //��ʾ����
////  Encoder_Left=Read_Encoder(2);                                      
////  Encoder_Right=-Read_Encoder(4);      //��ȡ���ұ�����   
////  Delay_ms(50);                  //=====��ʱ�ȴ��ȶ�  
////  if(Turn_Off(Voltage)==0&&Flag_Way==0)//�������
////   {   
////      jiexi();
////      Kinematic_Analysis(Velocity,Angle);       //С���˶�ѧ����
////      Motor_A=Target_A*20;                         //===������A����PWM
////      Motor_B=Target_B*20;                        //===������B����PWM 
////      Xianfu_Pwm();                          //===PWM�޷�
////      Set_Pwm(Motor_A,Motor_B,Servo);        //===��ֵ��PWM�Ĵ���  
////    
////   }       
////  else if(Turn_Off(Voltage)==0&&Flag_Way==1)                         //===����������쳣
////    {
////      Get_RC();
////      Kinematic_Analysis(Velocity,Angle);                          //С���˶�ѧ���� 
////      Motor_A=Incremental_PI_Left(Encoder_Left,Target_A);          //===�ٶȱջ����Ƽ�����A����PWM
////      Motor_B=Incremental_PI_Right(Encoder_Right,Target_B);         //===�ٶȱջ����Ƽ�����B����PWM 
////      Xianfu_Pwm();                                             //===PWM�޷�
////      Set_Pwm(Motor_A,Motor_B,Servo);                           //===��ֵ��PWM�Ĵ���  
////    }
////  else Set_Pwm(0,0,SERVO_INIT);  //===��ֵ��PWM�Ĵ���    
////  Voltage_Temp=Get_battery_volt();//=====��ȡ��ص�ѹ    
////  Voltage_Count++;                //=====ƽ��ֵ������
////  Voltage_All+=Voltage_Temp;      //=====��β����ۻ�
////  if(Voltage_Count==10) Voltage=Voltage_All/10,Voltage_All=0,Voltage_Count=0;//=====��ƽ��ֵ                                       
////  if(Flag_Show==0)        Led_Flash(100);
////  else if(Flag_Show==1)  Led_Flash(0);  //led��˸
////  Key();    //===ɨ�谴��״̬ ����˫�����Ըı�С������״̬

////}


/////**************************************************************************
////�������ܣ�����PWM��ֵ 
////��ڲ�������ֵ
////����  ֵ����
////**************************************************************************/
////void Xianfu_Pwm(void)
////{  
////    int Amplitude=6900;    //===PWM������7200 ������6900
////    if(Motor_A<-Amplitude) Motor_A=-Amplitude;  
////    if(Motor_A>Amplitude)  Motor_A=Amplitude;  
////    if(Motor_B<-Amplitude) Motor_B=-Amplitude;  
////    if(Motor_B>Amplitude)  Motor_B=Amplitude;    
////    if(Servo<(SERVO_INIT-500))     Servo=SERVO_INIT-500;    //����޷�
////    if(Servo>(SERVO_INIT+500))     Servo=SERVO_INIT+500;      //����޷�
////}


/////************************************************************************
////�������ܣ������޸�С������״̬ 
////��ڲ�������
////����  ֵ����
////**************************************************************************/
//////void Key(void)
//////{  
//////  u8 tmp,tmp2;
//////  tmp=click(); 
////////  tmp=click_N_Double(50); //˫����˫���ȴ�ʱ��500ms
//////  if(tmp==1)Flag_Stop=!Flag_Stop;//��������С������ͣ
//////  //if(tmp==2)Flag_Show=!Flag_Show;//˫������С������ʾ״̬
//////  tmp2=Long_Press();  //����        
//////  if(tmp2==1)Flag_Show=!Flag_Show;//����С������ʾ״̬                 
//////}




///**************




//****************/
