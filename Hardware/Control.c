
//#include "control.h"  
//float Position_KP,Position_KI, velocity_KP,velocity_KI;
////#define T 0.245f
////#define L 0.29f
////#define K 14.00f
//#define T 0.156f
//#define L 0.1445f
//#define K 622.8f
//u8 Flag_Target,Flag_Change;  //相关标志位
//float Voltage_Temp,Voltage_Count,Voltage_All;  //电压采样相关变量
//int j,sum;

///**************************************************************************
//函数功能：小车运动数学模型
//入口参数：速度和转角
//返回  值：无
//**************************************************************************/
//void Kinematic_Analysis(float velocity,float angle)
//{
//    Target_A=velocity*(1+T*tan(angle)/2/L); 
//    Target_B=velocity*(1-T*tan(angle)/2/L);      //后轮差速
//    Servo=SERVO_INIT+angle*K;                    //舵机转向   
//}
///**************************************************************************
//函数功能：所有的控制代码都在这里面
//         定时中断触发
//         严格保证采样和数据处理的时间同步         
//**************************************************************************/
//void Control(void)
//{
//  //oled_show();               //显示屏打开
//  Encoder_Left=Read_Encoder(2);                                      
//  Encoder_Right=-Read_Encoder(3);      //读取左右编码器   
//  Delay_ms(50);                  //=====延时等待稳定  
//  if(Turn_Off(Voltage)==0&&Flag_Way==0)
//   {   
//      jiexi();
//      Kinematic_Analysis(Velocity,Angle);                                   //小车运动学分析
//      Motor_A=Target_A*20;                                                     //===计算电机A最终PWM
//      Motor_B=Target_B*20;                                                    //===计算电机B最终PWM 
//      Xianfu_Pwm();                                                      //===PWM限幅
//      Set_Pwm(Motor_A,Motor_B,Servo);                                    //===赋值给PWM寄存器  
//    
//   }       
//  else if(Turn_Off(Voltage)==0&&Flag_Way==1)                                  //===如果不存在异常
//    {
//      Get_RC();
//      Kinematic_Analysis(Velocity,Angle);                                   //小车运动学分析 
//      Motor_A=Incremental_PI_Left(Encoder_Left,Target_A);                   //===速度闭环控制计算电机A最终PWM
//      Motor_B=Incremental_PI_Right(Encoder_Right,Target_B);                  //===速度闭环控制计算电机B最终PWM 
//      Xianfu_Pwm();                                                      //===PWM限幅
//      Set_Pwm(Motor_A,Motor_B,Servo);                                    //===赋值给PWM寄存器  
//    }
//  else Set_Pwm(0,0,SERVO_INIT);  //===赋值给PWM寄存器    
//  Voltage_Temp=Get_battery_volt();                                     //=====读取电池电压    
//  Voltage_Count++;                                                     //=====平均值计数器
//  Voltage_All+=Voltage_Temp;                                           //=====多次采样累积
//  if(Voltage_Count==10) Voltage=Voltage_All/10,Voltage_All=0,Voltage_Count=0;//=====求平均值                                       
//  if(Flag_Show==0)        Led_Flash(100);
//  else if(Flag_Show==1)  Led_Flash(0);  //led闪烁
//  Key();    //===扫描按键状态 单击双击可以改变小车运行状态

//}

/////**************************************************************************
////函数功能：赋值给PWM寄存器
////入口参数：PWM
////返回  值：无
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
////函数功能：限制PWM赋值 
////入口参数：幅值
////返回  值：无
////**************************************************************************/
////void Xianfu_Pwm(void)
////{  
////    int Amplitude=6900;    //===PWM满幅是7200 限制在6900
////    if(Motor_A<-Amplitude) Motor_A=-Amplitude;  
////    if(Motor_A>Amplitude)  Motor_A=Amplitude;  
////    if(Motor_B<-Amplitude) Motor_B=-Amplitude;  
////    if(Motor_B>Amplitude)  Motor_B=Amplitude;    
////    if(Servo<(SERVO_INIT-500))     Servo=SERVO_INIT-500;    //舵机限幅
////    if(Servo>(SERVO_INIT+500))     Servo=SERVO_INIT+500;      //舵机限幅
////}
/////************************************************************************
////函数功能：按键修改小车运行状态 
////入口参数：无
////返回  值：无
////**************************************************************************/
////void Key(void)
////{  
////  u8 tmp,tmp2;
////  tmp=click(); 
//////  tmp=click_N_Double(50); //双击，双击等待时间500ms
////  if(tmp==1)Flag_Stop=!Flag_Stop;//单击控制小车的启停
////  //if(tmp==2)Flag_Show=!Flag_Show;//双击控制小车的显示状态
////  tmp2=Long_Press();  //长按        
////  if(tmp2==1)Flag_Show=!Flag_Show;//控制小车的显示状态                 
////}
/////**************************************************************************
////函数功能：异常关闭电机
////入口参数：电压
////返回  值：1：异常  0：正常
////**************************************************************************/
////u8 Turn_Off( int voltage)
////{
////      u8 temp;
////      if(voltage<740||Flag_Stop==1)//电池电压低于11.1V关闭电机
////      {                                                  
////      temp=1;  
////      PWMA1=0; //电机控制位清零                                           
////      PWMB1=0; //电机控制位清零
////      PWMA2=0; //电机控制位清零
////      PWMB2=0; //电机控制位清零            
////      }
////      else
////      temp=0;
////      return temp;    
////}



/////**************************************************************************
////函数功能：绝对值函数
////入口参数：int
////返回  值：unsigned int
////**************************************************************************/
////int myabs(int a)
////{        
////    int temp;
////    if(a<0)  temp=-a;  
////    else temp=a;
////    return temp;
////}


/////**************************************************************************
////函数功能：增量PI控制器
////入口参数：编码器测量值，目标速度
////返回  值：电机PWM
////根据增量式离散PID公式 
////pwm+=Kp[e（k）-e(k-1)]+Ki*e(k)+Kd[e(k)-2e(k-1)+e(k-2)]
////e(k)代表本次偏差 
////e(k-1)代表上一次的偏差  以此类推 
////pwm代表增量输出
////在我们的速度控制闭环系统里面，只使用PI控制
////pwm+=Kp[e（k）-e(k-1)]+Ki*e(k)
////**************************************************************************/
////int Incremental_PI_Left (int Encoder,int Target)
////{   
////   static int Bias,Pwm,Last_bias;
////   Bias=Target-Encoder;                //计算偏差
////   Pwm+=Velocity_KP*(Bias-Last_bias)+Velocity_KI*Bias;   //增量式PI控制器
////   Last_bias=Bias;                     //保存上一次偏差 
////   return Pwm;                         //增量输出
////}
////int Incremental_PI_Right (int Encoder,int Target)
////{   
////   static int Bias,Pwm,Last_bias;
////   Bias=Target-Encoder;                //计算偏差
////   Pwm+=Velocity_KP*(Bias-Last_bias)+Velocity_KI*Bias;   //增量式PI控制器
////   Last_bias=Bias;                     //保存上一次偏差 
////   return Pwm;                         //增量输出
////}


///////**************************************************************************
//////函数功能：通过指令对小车进行遥控
//////入口参数：PS2指令
//////返回  值：无 
//////**************************************************************************/
//////void Get_RC(void)//PS2控制
//////{
//////  int Yuzhi=2;
//////  float LY,RX;
//////  LY=PS2_LY-128;     //计算偏差
//////  RX=PS2_RX-128;
//////  if(LY>-Yuzhi&&LY<Yuzhi)LY=0;   //小角度设为死区 防止抖动出现异常
//////  if(RX>-Yuzhi&&RX<Yuzhi)RX=0;
//////   Velocity=-LY/2;    //速度和摇杆的力度相关。
//////   Angle=RX/200; 
//////      
//////}








/////**************************************************************************
////函数功能：所有的控制代码都在这里面
////         5ms定时中断由MPU6050的INT引脚触发
////         严格保证采样和数据处理的时间同步	
////				 在MPU6050的采样频率设置中，设置成100HZ，即可保证6050的数据是10ms更新一次。
////				 可在imv_mpu.h文件第26行的宏定义进行修改(#define DEFAULT_MPU_HZ  (100))
////**************************************************************************/
////#define SPEED_Y 100 //俯仰(前后)最大设定速度
////#define SPEED_Z 80//偏航(左右)最大设定速度 


////int ServoAngle;
//////int Balance_Pwm,Velocity_Pwm,Turn_Pwm;
////int Position_Pwm,Turn_Pwm;

////float Mechanical_angle=0; 
////float Target_Speed=0;	//期望速度（俯仰）。用于控制小车前进后退及其速度。
////float Turn_Speed=0;		//期望速度（偏航）





//////参数

////float Position_KP=SPD_KP;     // 小车速度环PI参数
////float Position_KI=SPD_KI;

////float Turn_Kd=TURN_KD;//转向环KP、KD
////float Turn_KP=TURN_KP;

////void EXTI9_5_IRQHandler(void) 
////{

////	if(PBin(5)==0)
////	{
////        EXTI->PR=1<<5;                                           //清除LINE5上的中断标志位
////        mpu_dmp_get_data(&pitch,&roll,&yaw);										 //得到欧拉角（姿态角）的数据
////        MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);								 //得到陀螺仪数据
////        Encoder_Left=Read_Encoder(2);                            //读取编码器的值，保证输出极性一致
////        Encoder_Right=-Read_Encoder(3);                          //读取编码器的值
////        Led_Flash(60);
////        Target_Speed=Target_Speed>SPEED_Y?SPEED_Y:(Target_Speed<-SPEED_Y?(-SPEED_Y):Target_Speed);//限幅
////        Turn_Speed=Turn_Speed>SPEED_Z?SPEED_Z:(Turn_Speed<-SPEED_Z?(-SPEED_Z):Turn_Speed);//限幅( (20*100) * 100)
////            
////				Velocity_Pwm=velocity(Encoder_Left,Encoder_Right,Target_Speed);       //===速度环PID控制	 
////				Turn_Pwm =Turn_UP(gyroz,Turn_Speed);        //===转向环PID控制
////				Moto1=Velocity_Pwm;  	                            	//===计算左轮电机最终PWM
////				Moto2=Velocity_Pwm;                  //===计算右轮电机最终PWM
////				Xianfu_Pwm();		 //===PWM限幅
////				Set_Pwm(Moto1,Moto2);                                     //===赋值给PWM寄存器		
////				Set_Servo_Position((Turn_Pwm + 100) * 5 + 1000);		//对Turn_PWM 数据处理 传入Servo；
////	} 
////}


/////**************************************************************************
////函数功能：速度PI控制
////入口参数：电机编码器的值
////返回  值：速度控制PWM
////**************************************************************************/
////int Position(int encoder_left,int encoder_right,int Target_Speed)
////{  
////    static float Position,Encoder_Least,Encoder;
////	  static float Encoder_Integral;
////   //=============速度PI控制器=======================//	
////		Encoder_Least =(Encoder_Left+Encoder_Right);//-target;                    //===获取最新速度偏差==测量速度（左右编码器之和）-目标速度 
////		Encoder *= 0.8f;		                                                //===一阶低通滤波器       
////		Encoder += Encoder_Least*0.2f;	                                    //===一阶低通滤波器    
////		Encoder_Integral +=Encoder;                                       //===积分出位移 积分时间：10ms
////		Encoder_Integral=Encoder_Integral - Target_Speed;                       //===接收遥控器数据，控制前进后退
////		if(Encoder_Integral>10000)  	Encoder_Integral=10000;             //===积分限幅
////		if(Encoder_Integral<-10000)		Encoder_Integral=-10000;            //===积分限幅	
////		Position=Encoder*Position_KP+Encoder_Integral*Position_KI;        //===速度控制	
////	  if(pitch<-40||pitch>40) 			Encoder_Integral=0;     						//===电机关闭后清除积分
////	  return Position;
////}
/////**************************************************************************
////函数功能：转向PD控制
////入口参数：电机编码器的值、Z轴角速度
////返回  值：转向控制PWM
////**************************************************************************/

////int Turn_UP(int gyro_Z, int RC)
////{
////	int PWM_out;
////		/*转向约束*/
////	if(RC==0)Turn_Kd=Turn_Kd;//若无左右转向指令，则开启转向约束
////	else Turn_Kd=0;//若左右转向指令接收到，则去掉转向约束
////	
////	PWM_out=Turn_Kd*gyro_Z + Turn_KP*RC;
////	return PWM_out;           //舵机PWM
////}


//////------------------------------------------

//////#define T 0.245f
//////#define L 0.29f
//////#define K 14.00f
////#define T 0.156f
////#define L 0.1445f
////#define K 622.8f
////#define SERVO_INIT 0
////u8 Flag_Target,Flag_Change;  //相关标志位
////float Voltage_Temp,Voltage_Count,Voltage_All;  //电压采样相关变量
////int j,sum;
////int Target_A,Target_B,Servo;

/////**************************************************************************
////函数功能：小车运动数学模型
////入口参数：速度和转角
////返回  值：无
////**************************************************************************/
////void Kinematic_Analysis(float velocity,float angle)
////{
////    Target_A=velocity*(1+T*tan(angle)/2/L); 
////    Target_B=velocity*(1-T*tan(angle)/2/L);      //后轮差速
////    Servo=SERVO_INIT+angle*K;                    //舵机转向   
////    
////    
////}

/////**************************************************************************
////函数功能：所有的控制代码都在这里面
////         定时中断触发
////         严格保证采样和数据处理的时间同步         
////**************************************************************************/
////void Control(void)
////{
////  //oled_show();               //显示屏打开
////  Encoder_Left=Read_Encoder(2);                                      
////  Encoder_Right=-Read_Encoder(4);      //读取左右编码器   
////  Delay_ms(50);                  //=====延时等待稳定  
////  if(Turn_Off(Voltage)==0&&Flag_Way==0)//电池正常
////   {   
////      jiexi();
////      Kinematic_Analysis(Velocity,Angle);       //小车运动学分析
////      Motor_A=Target_A*20;                         //===计算电机A最终PWM
////      Motor_B=Target_B*20;                        //===计算电机B最终PWM 
////      Xianfu_Pwm();                          //===PWM限幅
////      Set_Pwm(Motor_A,Motor_B,Servo);        //===赋值给PWM寄存器  
////    
////   }       
////  else if(Turn_Off(Voltage)==0&&Flag_Way==1)                         //===如果不存在异常
////    {
////      Get_RC();
////      Kinematic_Analysis(Velocity,Angle);                          //小车运动学分析 
////      Motor_A=Incremental_PI_Left(Encoder_Left,Target_A);          //===速度闭环控制计算电机A最终PWM
////      Motor_B=Incremental_PI_Right(Encoder_Right,Target_B);         //===速度闭环控制计算电机B最终PWM 
////      Xianfu_Pwm();                                             //===PWM限幅
////      Set_Pwm(Motor_A,Motor_B,Servo);                           //===赋值给PWM寄存器  
////    }
////  else Set_Pwm(0,0,SERVO_INIT);  //===赋值给PWM寄存器    
////  Voltage_Temp=Get_battery_volt();//=====读取电池电压    
////  Voltage_Count++;                //=====平均值计数器
////  Voltage_All+=Voltage_Temp;      //=====多次采样累积
////  if(Voltage_Count==10) Voltage=Voltage_All/10,Voltage_All=0,Voltage_Count=0;//=====求平均值                                       
////  if(Flag_Show==0)        Led_Flash(100);
////  else if(Flag_Show==1)  Led_Flash(0);  //led闪烁
////  Key();    //===扫描按键状态 单击双击可以改变小车运行状态

////}


/////**************************************************************************
////函数功能：限制PWM赋值 
////入口参数：幅值
////返回  值：无
////**************************************************************************/
////void Xianfu_Pwm(void)
////{  
////    int Amplitude=6900;    //===PWM满幅是7200 限制在6900
////    if(Motor_A<-Amplitude) Motor_A=-Amplitude;  
////    if(Motor_A>Amplitude)  Motor_A=Amplitude;  
////    if(Motor_B<-Amplitude) Motor_B=-Amplitude;  
////    if(Motor_B>Amplitude)  Motor_B=Amplitude;    
////    if(Servo<(SERVO_INIT-500))     Servo=SERVO_INIT-500;    //舵机限幅
////    if(Servo>(SERVO_INIT+500))     Servo=SERVO_INIT+500;      //舵机限幅
////}


/////************************************************************************
////函数功能：按键修改小车运行状态 
////入口参数：无
////返回  值：无
////**************************************************************************/
//////void Key(void)
//////{  
//////  u8 tmp,tmp2;
//////  tmp=click(); 
////////  tmp=click_N_Double(50); //双击，双击等待时间500ms
//////  if(tmp==1)Flag_Stop=!Flag_Stop;//单击控制小车的启停
//////  //if(tmp==2)Flag_Show=!Flag_Show;//双击控制小车的显示状态
//////  tmp2=Long_Press();  //长按        
//////  if(tmp2==1)Flag_Show=!Flag_Show;//控制小车的显示状态                 
//////}




///**************




//****************/
