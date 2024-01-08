#include "sys.h"

float Voltage; //????????????????
float pitch,roll,yaw; 		//?????//???????????????
short gyrox,gyroy,gyroz;//?????
short aacx,aacy,aacz;//?????
int   Encoder_Left,Encoder_Right;         		 //??????????????????
int 	Moto1=0,Moto2=0;												 //?????????????????????PWM
int PS2_LX,PS2_LY,PS2_RX,PS2_RY,PS2_KEY;     //



uint8_t i=0;

int main(void)
{
    //delay_init(168); 
//	Usart2_Init(9600);
		
    // ???? NVIC ?з╪??????????
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
//    // ???????????? 115200 ?????
//    uart_init(115200);

    // ????? LED??LCD ?????
    LED_Init();
    KEY_Init();
    Encoder_Init_TIM2();
    Encoder_Init_TIM3();
//    MPU_Init();
//    mpu_dmp_init();
////    
    OLED_Init();//?????u8??
//    LCD_Init();
//    OV2640_DCMI_Init ();
////    
    Moto_PWM_Init(5000-1,84-1);
    Servo_PWM_Init(12800-1,84-1);
    Motor_Init();
//    Speed_strategy_choose();
    
//    flag.init_ok = 1;//????????

//    Handle_Barn_Out(1);//?????
//			OLED_ShowNumber (1,1,323,5,8);
    	 	PS2_Init();
	PS2_SetInit();
    while (1)
    {
		PS2_Receive();
		OLED_ShowNumber (1,1,PS2_RX,5,16);
			Get_RC();
//			PS2_RedLightPS2_DataKey
//		Set_Servo_Position(30);
//			Delay_ms(1000);
				OLED_Clear();
//        PWM_SetCompare1(2000);
//        PWM_SetCompare2(1000);
//        Delay_ms(500);
//        Delay_ms(500);
//			int p;
//			
//			for(p=80;p<=170;p+=10)
//			{
////			 //???PWM????
//        Set_Servo_Position(p);
//				TIM_SetCompare1(TIM10,3000);
//			        mpu_dmp_get_data(&pitch,&roll,&yaw);										 //?????????????????????
//        MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	
     
//			  OLED_ShowNumber (1,2,p,5,16);
//				   Delay_ms(1000);
//	  OLED_ShowNumber (2,2,roll,5,16);
//	  OLED_ShowNumber (3,2,yaw,5,16);				
			}
         //???PWM????


        

//        Show_Picture(0,0,120,200,image_01[0]);
//        if(flag.init_ok)
//        {
//            if(flag.start)
//            {
////                Datasend();
////                State_Adjust();
            }
//        }
        //key = 1;
       // Menu_key_set();
//        er_zhi();
//        zhi(); 
//        you();
//        zuo();
////        ting();
//        
//        MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	
//        mpu_dmp_get_data(&pitch,&roll,&yaw);										 //?????????????????????
////        OLED_ShowSignedNum(1,1,yaw,5);
////        OLED_ShowSignedNum(2,1,pitch,5);
////        OLED_ShowSignedNum(3,1,roll,5);
//        OLED_ShowString(1,1,"Car",16);

        
       // Set_Pwm(-1000,1000);
        //???PWM????
//        PWM_SetCompare1(2000);
//        PWM_SetCompare2(1000);
//        Delay_ms(500);
//        Delay_ms(500);
//        Set_Servo_Position(90);
//        Delay_ms(500);
//        Set_Servo_Position(180);
//        Delay_ms(500);
//        Set_Servo_Position(90);
//        Delay_ms(500);
//        Set_Servo_Position(60);
//        Delay_ms(500);
        
          //???PWM????
//        for(int i = 300;i<=3000;i++)
//        {
//            Set_Pwm(-i,i);
//            Delay_ms(10);
//        }


//    }
//    
//    
//}



//    uart_init(9600);              //=====????????
//    PS2_Init();		    //=====ps2???????????
//    PS2_SetInit();	  //=====ps2???ио????,???ив??????????????????????????

//        PS2_LX=PS2_AnologData(PSS_LX);    
//        PS2_LY=PS2_AnologData(PSS_LY);
//        PS2_RX=PS2_AnologData(PSS_RX);
//        PS2_RY=PS2_AnologData(PSS_RY);
//        PS2_KEY=PS2_DataKey();	
//        printf("%d     PS2_LX:",PS2_LX);
//        printf("%d     PS2_LY:",PS2_LY);
//		  printf("%d     PS2_RX:",PS2_RX);
//	printf("%d     PS2_RY:",PS2_RY);
//	printf("%d \r\nPS2_KEY:",PS2_KEY);
//	Delay_ms(100);



 
