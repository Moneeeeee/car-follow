#ifndef __MENU_H
#define __MENU_H	 
#include "sys.h"                  


typedef struct
{
    u8 current;//当前状态索引号
    u8 last;
    u8 next; //向下一个
    u8 enter; //确定
    u8 back;
    void (*current_operation)(void); //当前状态应该执行的操作
} Menu_table;

void Menu_key_set(void);
void show0(void);
void show1(void);
void show2(void);
void show3(void);
void show4(void);
void show5(void);
void show6(void);
void show7(void);
void show8(void);
void show9(void);
void show10(void);
void show11(void);
void show12(void);
void show13(void);
void show14(void);
void show15(void);
void show16(void);
void show17(void);
void show18(void);
void show19(void);
void show20(void);
void show21(void);
void show22(void);
void show23(void);
void show24(void);
void show25(void);
void show26(void);
void show27(void);
void show28(void);
void show29(void);
void show30(void);
void show31(void);
void show32(void);
#endif	
