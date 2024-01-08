#include "menu.h"
#include "key.h"
#include "oled.h"
#include "stm32f4xx.h"                  // Device header
#include "LED.h"
#include "Timer.h"
#include "Motor.h"
float Add_Num=1.0f;
void (*current_operation_index)(); //��������ָ��
uint8_t func_index = 0;
uint8_t key1;
uint8_t key2;
uint8_t key3;
uint8_t key4;
float Position_KP=0;
/*�������������飬��������Ҫ��������򰴼�ֵ����ѡ��*/
// ���� last next enter back
 Menu_table  table[32]=
{
    //һ��
    {0, 0, 0, 1,  0,(*show0)},//һ������	
    {1, 4, 2, 5,  0,(*show1)},//һ������ѡ���һ��LED
    {2, 1, 3, 9,  0,(*show2)},//һ������ѡ��ڶ���PID
    {3, 2, 4, 13, 0,(*show3)},//һ������ѡ�������
    {4, 3, 1, 17, 0,(*show4)},//һ������ѡ�������
	//����
    {5, 8, 6, 1, 1, (*show5)},//back  
    {6, 5, 7, 21, 1, (*show6)},//LED����������ѡ���һ��
    {7, 6, 8, 22, 1, (*show7)},//����������ѡ��ڶ���
    {8, 7, 5, 23, 1, (*show8)},//����������ѡ�������

    {9 , 12, 10, 2, 2, (*show9)}, //back  
    {10, 9,  11, 24, 2,  (*show10)},//PID ����������ѡ���һ��
    {11, 10, 12, 25, 2, (*show11)},//����������ѡ��ڶ��� 
    {12, 11, 9 , 26, 2, (*show12)},//����������ѡ�������  

    {13, 16, 14, 3,  3, (*show13)}, //back 
    {14, 13, 15, 13, 3, (*show14)},//����������ѡ���һ�� 
    {15, 14, 16, 13, 3, (*show15)},//����������ѡ��ڶ��� 
    {16, 15, 13, 13, 3, (*show16)},//����������ѡ�������

    {17, 20, 18, 4,  4, (*show17)},  //back
    {18, 17, 19, 17, 4, (*show18)}, //����������ѡ���һ��
    {19, 18, 20, 17, 4, (*show19)}, //����������ѡ��ڶ���
    {20, 20, 17, 17, 4, (*show20)}, //����������ѡ�������  
// ���� last next enter back  
    //����LED����ҳ
    {21, 21, 21, 21, 6, (*show21)}, //LED_ON
    {22, 22, 22, 22, 7, (*show22)}, //LED_OFF
    {23, 23, 23, 23, 8, (*show23)}, //LED_Turn 

    {24, 27, 25, 10, 10, (*show24)}, //BACK 
    {25, 24, 26, 25, 25, (*show25)}, //KP������ʾ
    {26, 25, 27, 28, 29, (*show26)}, //ADD_NUM
    {27, 26, 24, 30, 31, (*show27)}, //UPDATE
    
    {28, 28, 28, 28, 28, (*show28)}, //ADD_NUM++
    {29, 29, 29, 29, 29, (*show29)}, //ADD_NUM--
    
    {30, 30, 30, 30, 30, (*show30)}, //update+
    {31, 31, 31, 31, 31, (*show31)}, //update-
};


void  Menu_key_set(void)
{
  key1 = KEY1_Get();
  key2 = KEY2_Get();
  key3 = KEY3_Get();
  key4 = KEY4_Get();
  if(key1 == 1)
  {   
    func_index=table[func_index].next;//��ȡnext������
    OLED_Clear();
  }
  else if(key2 == 1)//��ȡenter������
  {
    func_index=table[func_index].enter;
    OLED_Clear();
  }
  else if(key3 == 1)//��ȡlast������
  {
    func_index=table[func_index].last;
    OLED_Clear();
  }
  else if(key4 == 1)//��ȡback������
  {
    func_index=table[func_index].back;
    OLED_Clear();
  }

  current_operation_index=table[func_index].current_operation;//ִ�е�ǰ����������Ӧ�Ĺ��ܺ�����
  (*current_operation_index)();//ִ�е�ǰ��������
}

void show0(void)//��һҳ
{
    OLED_ShowString(25,0,"Main Menu ",16);
	OLED_ShowString(5,2,"LED   ",16);
	OLED_ShowString(5,4,"PID_Parm",16);
	OLED_ShowString(5,6,"Test 3",16);
}


void show1(void)//�ڶ�ҳ
{
	OLED_ShowString(25,0,"Main Menu",16);
	OLED_ShowString(5,2,"LED      <",16);
	OLED_ShowString(5,4,"PID_Parm",16);
	OLED_ShowString(5,6,"Test 3",16);
}


void show2(void)
{
	OLED_ShowString(25,0,"Main Menu",16);
	OLED_ShowString(5,2,"LED   ",16);
	OLED_ShowString(5,4,"PID_Parm <",16);
	OLED_ShowString(5,6,"Test 3",16);   
}

void show3(void)
{
	OLED_ShowString(25,0,"Main Menu",16);
	OLED_ShowString(5,2,"LED   ",16);
	OLED_ShowString(5,4,"PID_Parm",16);
	OLED_ShowString(5,6,"Test 3   <",16);
}

void show4(void)
{
	OLED_ShowString(25,0,"Main Menu",16);
	OLED_ShowString(5,2,"PID_Parm",16);
	OLED_ShowString(5,4,"Test 3",16);
	OLED_ShowString(5,6,"Test 4   <",16);  
}

void show5(void)//�ڶ�ҳ��һ���Ӧ�ĵ���ҳ
{
	OLED_ShowString(5,0,"Back     < ",16); 
	OLED_ShowString(5,2,"LED_ON",16);
	OLED_ShowString(5,4,"LED_OFF",16);
	OLED_ShowString(5,6,"LED_Turn",16); 
}

void show6(void)
{
	OLED_ShowString(5,0,"Back    ",16); 
	OLED_ShowString(5,2,"LED_ON < ",16);
	OLED_ShowString(5,4,"LED_OFF",16);
	OLED_ShowString(5,6,"LED_Turn",16); 
}

void show7(void)
{
	OLED_ShowString(5,0,"Back    ",16); 
	OLED_ShowString(5,2,"LED_ON",16);
	OLED_ShowString(5,4,"LED_OFF < ",16);
	OLED_ShowString(5,6,"LED_Turn",16);
}

void show8(void)
{
	OLED_ShowString(5,0,"Back    ",16); 
	OLED_ShowString(5,2,"LED_ON",16);
	OLED_ShowString(5,4,"LED_OFF",16);
	OLED_ShowString(5,6,"LED_Turn < ",16);
}

void show9(void)//�ڶ�ҳ�ڶ����Ӧ�ĵ���ҳ
{
	OLED_ShowString(5,0,"Back     < ",16); 
	OLED_ShowString(5,2,"KP",16);
	OLED_ShowString(5,4,"KI",16);
	OLED_ShowString(5,6,"KD",16);
}

void show10(void)
{
	OLED_ShowString(5,0,"Back   ",16);
	OLED_ShowString(5,2,"KP       < ",16);
	OLED_ShowString(5,4,"KI",16);
	OLED_ShowString(5,6,"KD",16); 
}

void show11(void)
{
	OLED_ShowString(5,0,"Back   ",16);
	OLED_ShowString(5,2,"KP",16);
	OLED_ShowString(5,4,"KI       < ",16);
	OLED_ShowString(5,6,"KD",16); 
}

void show12(void)
{
	OLED_ShowString(5,0,"Back   ",16);
	OLED_ShowString(5,2,"KP",16);
	OLED_ShowString(5,4,"KI",16);
	OLED_ShowString(5,6,"KD < ",16); 
}

void show13(void)//�ڶ�ҳ�������Ӧ�ĵ���ҳ
{
	OLED_ShowString(5,0,"Back     < ",16); 
	OLED_ShowString(5,2,"Test 3.1",16);
	OLED_ShowString(5,4,"Test 3.2",16);
	OLED_ShowString(5,6,"Test 3.3",16);
}

void show14(void)
{
	OLED_ShowString(5,0,"Back    ",16); 
	OLED_ShowString(5,2,"Test 3.1 < ",16);
	OLED_ShowString(5,4,"Test 3.2",16);
	OLED_ShowString(5,6,"Test 3.3",16);
}

void show15(void)
{
	OLED_ShowString(5,0,"Back    ",16); 
	OLED_ShowString(5,2,"Test 3.1",16);
	OLED_ShowString(5,4,"Test 3.2 < ",16);
	OLED_ShowString(5,6,"Test 3.3",16);
}

void show16(void)
{
	OLED_ShowString(5,0,"Back    ",16); 
	OLED_ShowString(5,2,"Test 3.1",16);
	OLED_ShowString(5,4,"Test 3.2",16);
	OLED_ShowString(5,6,"Test 3.3 < ",16);
    
}

void show17(void)
{
	OLED_ShowString(5,0,"Back     < ",16); 
	OLED_ShowString(5,2,"Test 4.1",16);
	OLED_ShowString(5,4,"Test 4.2",16);
	OLED_ShowString(5,6,"Test 4.3 ",16);
    
}

void show18(void)
{
	OLED_ShowString(5,0,"Back    ",16); 
	OLED_ShowString(5,2,"Test 4.1 <",16);
	OLED_ShowString(5,4,"Test 4.2",16);
	OLED_ShowString(5,6,"Test 4.3",16);
    
}

void show19(void)
{
	OLED_ShowString(5,0,"Back    ",16); 
	OLED_ShowString(5,2,"Test 4.1",16);
	OLED_ShowString(5,4,"Test 4.2 < ",16);
	OLED_ShowString(5,6,"Test 4.3",16);
    
}

void show20(void)
{
	OLED_ShowString(5,0,"Back    ",16); 
	OLED_ShowString(5,2,"Test 4.1",16);
	OLED_ShowString(5,4,"Test 4.2",16);
	OLED_ShowString(5,6,"Test 4.3 < ",16);
    
}

void show21(void)
{
    //LEDTurn_Flag=0;
    LED_ON();
//	OLED_ShowString(5,0,"LED_ON",16); 
    func_index=6;    
}

void show22(void)
{
    //LEDTurn_Flag=0;
    LED_OFF();
//	OLED_ShowString(5,0,"LED_OFF",16);   
    func_index=7;    
}

void show23(void)
{
    LED_Turn();
//	OLED_ShowString(5,0,"LED_Turn",16);
    func_index=8;    
}

void show24(void)
{
    OLED_ShowString(5,0,">Back",16); 
	OLED_ShowString(5,2,"KP:",16); OLED_Float(30,2,Position_KP,1);
	OLED_ShowString(5,4,"Add:",16);OLED_Float(38,4,Add_Num,1);
	OLED_ShowString(5,6,"Update ",16);
}

void show25(void)
{
    OLED_ShowString(5,0,"Back",16); 
	OLED_ShowString(5,2,">KP:",16); OLED_Float(38,2,Position_KP,1);
	OLED_ShowString(5,4,"Add:",16);OLED_Float(38,4,Add_Num,1);
	OLED_ShowString(5,6,"Update ",16);    
}

void show26(void)
{
    OLED_ShowString(5,0,"Back",16); 
	OLED_ShowString(5,2,"KP:",16); OLED_Float(30,2,Position_KP,1);
	OLED_ShowString(5,4,">Add:",16);OLED_Float(46,4,Add_Num,1);
	OLED_ShowString(5,6,"Update ",16);    
}

void show27(void)
{
    OLED_ShowString(5,0,"Back",16); 
	OLED_ShowString(5,2,"KP:",16); OLED_Float(30,2,Position_KP,1);
	OLED_ShowString(5,4,"Add:",16);OLED_Float(38,4,Add_Num,1);
	OLED_ShowString(5,6,">Update",16);    
}
//PID Add_Num����
void show28(void)
{
    Add_Num*=10; 
    if(Add_Num>10000)Add_Num=0.1f;
    func_index=26;
}

void show29(void)
{
    Add_Num/=10;
    //if(Add_Num<0.1)Add_Num=10000.00;
    func_index=26;
    
}

void show30(void)
{
    Position_KP+=Add_Num;
    func_index=27;
    
}

void show31(void)
{
    Position_KP-=Add_Num;
    func_index=27;
    
}
