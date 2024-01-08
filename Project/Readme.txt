    
/****
   // 声明红色、绿色和蓝色分量的变量
//    u8 red, green, blue;

//    // 声明循环变量 i 和 j
//    int i, j;

//    // 设置二值化的阈值
//    threshold = 128;
        //        // 设置 LCD 光标位置
//        LCD_SetCursor(0, 0);

//        // 准备 LCD 进行写入
//        LCD_WriteRAM_Prepare();

//        // 在 LCD 上显示图像
//        Show_Picture(0, 0, 240, 400, (u16 *)rgb_buf);

//        // 循环遍历 RGB 缓冲区中的每个像素
//        for (i = 0; i < A; i++)
//        {
//            for (j = 0; j < B; j++)
//            {
//                // 从 RGB 值中提取红色、绿色和蓝色分量
//                red = ((rgb_buf[i][j] & 0xF800) >> 8);
//                green = ((rgb_buf[i][j] & 0x07E0) >> 3);
//                blue = ((rgb_buf[i][j] & 0x001F) << 3);

//                // 使用加权和将其转换为 8 位灰度值
//                gray8[i][j] = (red * 38 + green * 75 + blue * 15) >> 7;

//                // 根据阈值对像素进行二值化
//                if (threshold < gray8[i][j])
//                {
//                    // 如果像素值高于阈值，则设置为白色
//                    LCD_SetCursor(2 * j, 480 + 2 * i);
//                    LCD_WriteRAM_Prepare();
//                    LCD->LCD_RAM = WHITE;
//                    LCD->LCD_RAM = WHITE;

//                    LCD_SetCursor(2 * j, 480 + 2 * i + 1);
//                    LCD_WriteRAM_Prepare();
//                    LCD->LCD_RAM = WHITE;
//                    LCD->LCD_RAM = WHITE;
//                }
//                else
//                {
//                    // 如果像素值低于或等于阈值，则设置为黑色
//                    LCD_SetCursor(2 * j, 480 + 2 * i);
//                    LCD_WriteRAM_Prepare();
//                    LCD->LCD_RAM = BLACK;
//                    LCD->LCD_RAM = BLACK;

//                    LCD_SetCursor(2 * j, 480 + 2 * i + 1);
//                    LCD_WriteRAM_Prepare();
//                    LCD->LCD_RAM = BLACK;
//                    LCD->LCD_RAM = BLACK;
//                }


//                // 为像素进行额外的 LCD 设置
//                LCD_SetCursor(2 * j, 480 + 2 * i);
//                LCD_WriteRAM_Prepare();
//                if (threshold < gray8[i][j])
//                {
//                    LCD->LCD_RAM = WHITE;
//                    LCD->LCD_RAM = WHITE;
//                }
//                else
//                {
//                    LCD->LCD_RAM = BLACK;
//                    LCD->LCD_RAM = BLACK;
//                }

//                LCD_SetCursor(2 * j, 480 + 2 * i + 1);
//                LCD_WriteRAM_Prepare();
//                if (threshold < gray8[i][j])
//                {
//                    LCD->LCD_RAM = WHITE;
//                    LCD->LCD_RAM = WHITE;
//                }
//                else
//                {
//                    LCD->LCD_RAM = BLACK;
//                    LCD->LCD_RAM = BLACK;
//                }

//                LCD_SetCursor(2 * j + 1, 480 + 2 * i);
//                LCD_WriteRAM_Prepare();
//                if (threshold < gray8[i][j])
//                    LCD->LCD_RAM = WHITE;
//                else
//                    LCD->LCD_RAM = BLACK;

//                LCD_SetCursor(2 * j + 1, 480 + 2 * i + 1);
//                LCD_WriteRAM_Prepare();
//                if (threshold < gray8[i][j])
//                    LCD->LCD_RAM = WHITE;
//                else
//                    LCD->LCD_RAM = BLACK;

//                // 将 8 位灰度值转换为 16 位颜色值
//                gray16 = gray8[i][j] >> 3;
//                color = ((0x001f & gray16) << 11) | (((0x003f) & (gray16 * 2)) << 5) | (0x001f & gray16);

//                // 设置 LCD 光标并写入颜色值
//                LCD_SetCursor(2 * j, 240 + 2 * i);
//                LCD_WriteRAM_Prepare();
//                LCD->LCD_RAM = color;
//                LCD->LCD_RAM = color;

//                LCD_SetCursor(2 * j, 240 + 2 * i + 1);
//                LCD_WriteRAM_Prepare();
//                LCD->LCD_RAM = color;
//                LCD->LCD_RAM = color;

// 定义常量 A 和 B，分别为 120 和 200// 设置 OV2640 输出尺寸
#define A 120
#define B 200
// 定义一个用于存储 RGB 数据的二维数组，每个元素为 16 位无符号整数
u16 rgb_buf[A][B];
// 定义一个用于存储灰度数据的二维数组，每个元素为 8 位无符号整数
u8 gray8[A][B];
// 定义 16 位变量，用于存储灰度和颜色值
u16 gray16;
u16 color;
// 定义 8 位变量，用于二值化的阈值
u8 threshold;

int main(void)
{
	u8 red,green,blue;// 声明红色、绿色和蓝色分量的变量
	int i,j;
	threshold=128;  // 设置二值化的阈值
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	//delay_init(168);  //初始化延时函数
	uart_init(115200);		//初始化串口波特率为115200
	LED_Init();					//初始化LED 
 	LCD_Init();					//LCD初始化  
 	KEY_Init();					//按键初始化 
	while(OV2640_Init())//初始化OV2640
	{
		LCD_ShowString(30,130,240,16,16,"OV2640 ERR");
		Delay_ms(200);
	    LCD_Fill(30,130,239,170,WHITE);
		Delay_ms(200);
	}
    
	OV2640_OutSize_Set(B,A);// 设置 OV2640 输出尺寸
	OV2640_RGB565_Mode();// 将 OV2640 设置为 RGB565 模式
  My_DCMI_Init();// 初始化 DCMI 接口
//	DCMI_DMA_Init((u32)&LCD->LCD_RAM,1,DMA_MemoryDataSize_HalfWord,DMA_MemoryInc_Disable);
  DCMI_DMA_Init((u32)rgb_buf,sizeof(rgb_buf)/4,DMA_MemoryDataSize_HalfWord,DMA_MemoryInc_Enable);// 初始化 DCMI 的 DMA
  DCMI_Start(); // 启动 DCMI
//	OV2640_Special_Effects(2);
	
	while(1)
	{
		LCD_SetCursor(0,0);// 设置 LCD 光标位置
		LCD_WriteRAM_Prepare();// 准备 LCD 进行写入
		
	  Show_Picture(0,0,240,400,(u16*)rgb_buf);		// 在 LCD 上显示图像
		for(i=0;i<A;i++)// 循环遍历 RGB 缓冲区中的每个像素
		{
				for(j=0;j<B;j++)
				{   // 从 RGB 值中提取红色、绿色和蓝色分量
					red=((rgb_buf[i][j] & 0xF800)>>8);
					green=((rgb_buf[i][j] & 0x07E0)>>3);
					blue=((rgb_buf[i][j] & 0x001F)<<3);
					gray8[i][j]=(red*38+green*75+blue*15)>>7; // 使用加权和将其转换为 8 位灰度值
                     // 根据阈值对像素进行二值化
					if(threshold<gray8[i][j])
					{   // 如果像素值高于阈值，则设置为白色
						LCD_SetCursor(2*j,480+2*i);LCD_WriteRAM_Prepare();LCD->LCD_RAM=WHITE;LCD->LCD_RAM=WHITE;
						LCD_SetCursor(2*j,480+2*i+1);LCD_WriteRAM_Prepare();LCD->LCD_RAM=WHITE;LCD->LCD_RAM=WHITE;
					}
					else
					{    // 如果像素值低于或等于阈值，则设置为黑色
						LCD_SetCursor(2*j,480+2*i);LCD_WriteRAM_Prepare();LCD->LCD_RAM=BLACK;LCD->LCD_RAM=BLACK;
						LCD_SetCursor(2*j,480+2*i+1);LCD_WriteRAM_Prepare();LCD->LCD_RAM=BLACK;LCD->LCD_RAM=BLACK;
					}
                    // 为像素进行额外的 LCD 设置
					LCD_SetCursor(2*j,480+2*i);LCD_WriteRAM_Prepare();if(threshold<gray8[i][j]){LCD->LCD_RAM=WHITE;LCD->LCD_RAM=WHITE;}else {LCD->LCD_RAM=BLACK;LCD->LCD_RAM=BLACK;}
					LCD_SetCursor(2*j,480+2*i+1);LCD_WriteRAM_Prepare();if(threshold<gray8[i][j]){LCD->LCD_RAM=WHITE;LCD->LCD_RAM=WHITE;}else {LCD->LCD_RAM=BLACK;LCD->LCD_RAM=BLACK;}
					LCD_SetCursor(2*j+1,480+2*i);LCD_WriteRAM_Prepare();if(threshold<gray8[i][j])LCD->LCD_RAM=WHITE;else LCD->LCD_RAM=BLACK;
					LCD_SetCursor(2*j+1,480+2*i+1);LCD_WriteRAM_Prepare();if(threshold<gray8[i][j])LCD->LCD_RAM=WHITE;else LCD->LCD_RAM=BLACK;
					// 将 8 位灰度值转换为 16 位颜色值
					gray16=gray8[i][j]>>3;
					color=((0x001f&gray16)<<11)|(((0x003f)&(gray16*2))<<5)|(0x001f&gray16);
                    // 设置 LCD 光标并写入颜色值
					LCD_SetCursor(2*j,240+2*i);LCD_WriteRAM_Prepare();LCD->LCD_RAM=color;LCD->LCD_RAM=color;
					LCD_SetCursor(2*j,240+2*i+1);LCD_WriteRAM_Prepare();LCD->LCD_RAM=color;LCD->LCD_RAM=color;

			}
		}

	}
}


u8 hsync_int = 0;						//帧中断标志
u8 ov2640_mode=0;						//工作模式:0,RGB565模式;1,JPEG模式

#define jpeg_buf_size 31*1024  			//定义JPEG数据缓存jpeg_buf的大小(*4字节)
__align(4) u32 jpeg_buf[jpeg_buf_size];	//JPEG数据缓存buf
volatile u32 jpeg_data_len=0; 			//buf中的JPEG有效数据长度 
volatile u8 jpeg_data_ok=0;				//JPEG数据采集完成标志 
										//0,数据没有采集完;
										//1,数据采集完了,但是还没处理;
										//2,数据已经处理完成了,可以开始下一帧接收
//JPEG尺寸支持列表
const u16 jpeg_img_size_tbl[][2]=
{
	176,144,	//QCIF
	160,120,	//QQVGA
	352,288,	//CIF
	320,240,	//QVGA
	640,480,	//VGA
	800,600,	//SVGA
	1024,768,	//XGA
	1280,1024,	//SXGA
	1600,1200,	//UXGA
}; 
const u8*EFFECTS_TBL[7]={"Normal","Negative","B&W","Redish","Greenish","Bluish","Antique"};	//7种特效 
const u8*JPEG_SIZE_TBL[9]={"QCIF","QQVGA","CIF","QVGA","VGA","SVGA","XGA","SXGA","UXGA"};	//JPEG图片 9种尺寸 


//处理JPEG数据
//当采集完一帧JPEG数据后,调用此函数,切换JPEG BUF.开始下一帧采集.
void jpeg_data_process(void)
{
	if(ov2640_mode)//只有在JPEG格式下,才需要做处理.
	{
		if(jpeg_data_ok==0)	//jpeg数据还未采集完?
		{	
			DMA_Cmd(DMA2_Stream1, DISABLE);//停止当前传输 
			while (DMA_GetCmdStatus(DMA2_Stream1) != DISABLE){}//等待DMA2_Stream1可配置  
			jpeg_data_len=jpeg_buf_size-DMA_GetCurrDataCounter(DMA2_Stream1);//得到此次数据传输的长度
				
			jpeg_data_ok=1; 				//标记JPEG数据采集完按成,等待其他函数处理
		}
		if(jpeg_data_ok==2)	//上一次的jpeg数据已经被处理了
		{
			DMA2_Stream1->NDTR=jpeg_buf_size;	
			DMA_SetCurrDataCounter(DMA2_Stream1,jpeg_buf_size);//传输长度为jpeg_buf_size*4字节
			DMA_Cmd(DMA2_Stream1, ENABLE);			//重新传输
			jpeg_data_ok=0;						//标记数据未采集
		}
	}
    else
    {
        LCD_SetCursor(0, 0);
        LCD_WriteRAM_Prepare();     //开始写入GRAM
        hsync_int = 1;
    }
} 
//JPEG测试
//JPEG数据,通过串口2发送给电脑.
void jpeg_test(void)
{
	u32 i; 
	u8 *p;
	u8 key;
	u8 effect=0,saturation=2,contrast=2;
	u8 size=3;		//默认是QVGA 320*240尺寸
	u8 msgbuf[15];	//消息缓存区 
	LCD_Clear(WHITE);
  POINT_COLOR=RED; 
	LCD_ShowString(30,50,200,16,16,"ALIENTEK STM32F4");
	LCD_ShowString(30,70,200,16,16,"OV2640 JPEG Mode");
	LCD_ShowString(30,100,200,16,16,"KEY0:Contrast");			//对比度
	LCD_ShowString(30,120,200,16,16,"KEY1:Saturation"); 		//色彩饱和度
	LCD_ShowString(30,140,200,16,16,"KEY2:Effects"); 			//特效 
	LCD_ShowString(30,160,200,16,16,"KEY_UP:Size");				//分辨率设置 
	sprintf((char*)msgbuf,"JPEG Size:%s",JPEG_SIZE_TBL[size]);
	LCD_ShowString(30,180,200,16,16,msgbuf);					//显示当前JPEG分辨率
	
 	OV2640_JPEG_Mode();		//JPEG模式
	My_DCMI_Init();			//DCMI配置
	DCMI_DMA_Init((u32)&jpeg_buf,jpeg_buf_size,DMA_MemoryDataSize_Word,DMA_MemoryInc_Enable);//DCMI DMA配置   
	OV2640_OutSize_Set(jpeg_img_size_tbl[size][0],jpeg_img_size_tbl[size][1]);//设置输出尺寸 
	DCMI_Start(); 		//启动传输
	while(1)
	{
		if(jpeg_data_ok==1)	//已经采集完一帧图像了
		{  
			p=(u8*)jpeg_buf;
			LCD_ShowString(30,210,210,16,16,"Sending JPEG data..."); //提示正在传输数据
			for(i=0;i<jpeg_data_len*4;i++)		//dma传输1次等于4字节,所以乘以4.
			{
        while(USART_GetFlagStatus(USART2,USART_FLAG_TC)==RESET);	//循环发送,直到发送完毕  		
				USART_SendData(USART2,p[i]); 
				key=KEY_Scan(0); 
				if(key)break;
			} 
			if(key)	//有按键按下,需要处理
			{  
				LCD_ShowString(30,210,210,16,16,"Quit Sending data   ");//提示退出数据传输
				switch(key)
				{				    
					case KEY0_PRES:	//对比度设置
						contrast++;
						if(contrast>4)contrast=0;
						OV2640_Contrast(contrast);
						sprintf((char*)msgbuf,"Contrast:%d",(signed char)contrast-2);
						break;
					case KEY1_PRES:	//饱和度Saturation
						saturation++;
						if(saturation>4)saturation=0;
						OV2640_Color_Saturation(saturation);
						sprintf((char*)msgbuf,"Saturation:%d",(signed char)saturation-2);
						break;
					case KEY2_PRES:	//特效设置				 
						effect++;
						if(effect>6)effect=0;
						OV2640_Special_Effects(effect);//设置特效
						sprintf((char*)msgbuf,"%s",EFFECTS_TBL[effect]);
						break;
					case WKUP_PRES:	//JPEG输出尺寸设置   
						size++;  
						if(size>8)size=0;   
						OV2640_OutSize_Set(jpeg_img_size_tbl[size][0],jpeg_img_size_tbl[size][1]);//设置输出尺寸  
						sprintf((char*)msgbuf,"JPEG Size:%s",JPEG_SIZE_TBL[size]);
						break;
				}
				LCD_Fill(30,180,239,190+16,WHITE);
				LCD_ShowString(30,180,210,16,16,msgbuf);//显示提示内容
				Delay_ms(800); 				  
			}else LCD_ShowString(30,210,210,16,16,"Send data complete!!");//提示传输结束设置 
			jpeg_data_ok=2;	//标记jpeg数据处理完了,可以让DMA去采集下一帧了.
		}		
	}    
} 
//RGB565测试
//RGB数据直接显示在LCD上面
void rgb565_test(void)
{ 
	u8 key;
	u8 effect=0,saturation=2,contrast=2;
	u8 scale=1;		//默认是全尺寸缩放
	u8 msgbuf[15];	//消息缓存区 
	LCD_Clear(WHITE);
    POINT_COLOR=RED; 
	LCD_ShowString(30,50,200,16,16,"ALIENTEK STM32F4");
	LCD_ShowString(30,70,200,16,16,"OV2640 RGB565 Mode");
	
	LCD_ShowString(30,100,200,16,16,"KEY0:Contrast");			//对比度
	LCD_ShowString(30,130,200,16,16,"KEY1:Saturation"); 		//色彩饱和度
	LCD_ShowString(30,150,200,16,16,"KEY2:Effects"); 			//特效 
	LCD_ShowString(30,170,200,16,16,"KEY_UP:FullSize/Scale");	//1:1尺寸(显示真实尺寸)/全尺寸缩放
	
	OV2640_RGB565_Mode();	//RGB565模式
	My_DCMI_Init();			//DCMI配置
	DCMI_DMA_Init((u32)&LCD->LCD_RAM,1,DMA_MemoryDataSize_HalfWord,DMA_MemoryInc_Disable);//DCMI DMA配置  
 	OV2640_OutSize_Set(lcddev.width,lcddev.height); 
	DCMI_Start(); 		//启动传输
	while(1)
	{ 
		key=KEY_Scan(0); 
		if(key)
		{ 
			DCMI_Stop(); //停止显示
			switch(key)
			{				    
				case KEY0_PRES:	//对比度设置
					contrast++;
					if(contrast>4)contrast=0;
					OV2640_Contrast(contrast);
					sprintf((char*)msgbuf,"Contrast:%d",(signed char)contrast-2);
					break;
				case KEY1_PRES:	//饱和度Saturation
					saturation++;
					if(saturation>4)saturation=0;
					OV2640_Color_Saturation(saturation);
					sprintf((char*)msgbuf,"Saturation:%d",(signed char)saturation-2);
					break;
				case KEY2_PRES:	//特效设置				 
					effect++;
					if(effect>6)effect=0;
					OV2640_Special_Effects(effect);//设置特效
					sprintf((char*)msgbuf,"%s",EFFECTS_TBL[effect]);
					break;
				case WKUP_PRES:	//1:1尺寸(显示真实尺寸)/缩放	    
					scale=!scale;  
					if(scale==0)
					{
                        if(lcddev.id == 0X5510)
                        {
                            SCCB_WR_Reg(0xd3,0x02);
                        }
						OV2640_ImageWin_Set((1600-lcddev.width)/2,(1200-lcddev.height)/2,lcddev.width,lcddev.height);//1:1真实尺寸
						OV2640_OutSize_Set(lcddev.width,lcddev.height); 
						sprintf((char*)msgbuf,"Full Size 1:1");
					}else 
					{
						OV2640_ImageWin_Set(0,0,1600,1200);				//全尺寸缩放
						OV2640_OutSize_Set(lcddev.width,lcddev.height); 
						sprintf((char*)msgbuf,"Scale");
					}
					break;
			}
			LCD_ShowString(30,50,210,16,16,msgbuf);//显示提示内容
			Delay_ms(800); 
			DCMI_Start();//重新开始传输
		} 
        if (hsync_int)  //刚刚产生帧中断,可以延时
        {
            Delay_ms(10);
            hsync_int = 0;
        }
	}    
} 
int main(void)
{ 
	u8 key;
	u8 t;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	//delay_init(168);  //初始化延时函数
	uart_init(115200);		//初始化串口波特率为115200
	//usart2_init(42,115200);		//初始化串口2波特率为115200
	LED_Init();					//初始化LED 
 	LCD_Init();					//LCD初始化  
 	KEY_Init();					//按键初始化 
	TIM3_Int_Init(10000-1,8400-1);//10Khz计数,1秒钟中断一次
	
 	//usmart_dev.init(84);		//初始化USMART
 	POINT_COLOR=RED;//设置字体为红色 
	LCD_ShowString(30,50,200,16,16,"Explorer STM32F4");	
	LCD_ShowString(30,70,200,16,16,"OV2640 TEST");	
	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,110,200,16,16,"2014/5/14");  	 
	while(OV2640_Init())//初始化OV2640
	{
		LCD_ShowString(30,130,240,16,16,"OV2640 ERR");
		Delay_ms(200);
	    LCD_Fill(30,130,239,170,WHITE);
		Delay_ms(200);
	}
	LCD_ShowString(30,130,200,16,16,"OV2640 OK");  	  
 	while(1)
	{	
		key=KEY_Scan(0);
		if(key==KEY1_PRES)			//JPEG模式
		{
			ov2640_mode=0;   
			break;
		}else if(key==KEY0_PRES)	//RGB565模式
		{
			ov2640_mode=1;
			break;
		}
		t++; 									  
		if(t==100)LCD_ShowString(30,150,230,16,16,"KEY0:RGB565  KEY1:JPEG"); //闪烁显示提示信息
 		if(t==200)
		{	
			LCD_Fill(30,150,210,150+16,WHITE);
			t=0; 
		}
		Delay_ms(5);	  
	}
	if(ov2640_mode)jpeg_test();
	else rgb565_test(); 
    
}

//////////////////////////////////////////////////////////////////////


 POINT_COLOR=RED;      //画笔颜色：红色
    u8 x=0;
    uart_init(115200);		//初始化串口波特率为115200
	u8 lcd_id[12];				//存放LCD ID字符串
    LCD_Init();           //初始化LCD FSMC接口
    sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//将LCD ID打印到lcd_id数组
    while(1)
    {
        switch(x)
		{
			case 0:LCD_Clear(WHITE);break;
			case 1:LCD_Clear(BLACK);break;
			case 2:LCD_Clear(BLUE);break;
			case 3:LCD_Clear(RED);break;
			case 4:LCD_Clear(MAGENTA);break;
			case 5:LCD_Clear(GREEN);break;
			case 6:LCD_Clear(CYAN);break; 
			case 7:LCD_Clear(YELLOW);break;
			case 8:LCD_Clear(BRRED);break;
			case 9:LCD_Clear(GRAY);break;
			case 10:LCD_Clear(LGRAY);break;
			case 11:LCD_Clear(BROWN);break;
		}
		POINT_COLOR=RED;	  
		LCD_ShowString(30,40,210,24,24,"Explorer STM32F4");	
		LCD_ShowString(30,70,200,16,16,"TFTLCD TEST");
		LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
 		LCD_ShowString(30,110,200,16,16,lcd_id);		//显示LCD ID	      					 
		LCD_ShowString(30,130,200,12,12,"2014/5/4");	      					 
	  x++;
		if(x==12)x=0;
		LED_Turn();	 
		Delay_ms(1000);	**/

/****************************************************************************** 
* 函数介绍： 计算 x, y, z 三轴的倾角 
* 输入参数： 无 
* 输出参数： data：角度结构体 
* 返回值 ： 无 
******************************************************************************/

/************
#include "stm32f10x.h"
#include "moter.h"
#include "delay.h"
#include "SG90.H"
#include "cj.h"
#include "usart.h"
#include "sys.h"
#include "stdio.h"

#define CLK_TIME 1.0/8000000.0

u8  TIM4CH4_CAPTURE_STA=0;	//输入捕获状态
u16	TIM4CH4_CAPTURE_VAL;	//输入捕获值
u8 cap_flag=0;
float  length_res[5];  //用来存放测距结果
u32 time_cnt;
double long_chang;


float sensor(void)
{
	
	PBout(8)=1; //拉高信号，作为触发信号
	delay_us(20); //高电平信号超过10us
	PBout(8)=0;
		
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==RESET);
		TIM_Cmd(TIM4,ENABLE);//回响信号到来，开启定时器计数
		
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==SET);//回响信号消失
		TIM_Cmd(TIM4,DISABLE);//关闭定时器
		
		if(cap_flag)
		{
			time_cnt=(TIM4CH4_CAPTURE_STA&0x3f)*65536;
			time_cnt+=TIM4CH4_CAPTURE_VAL;
			//printf("%d\r\n",time_cnt);
			long_chang=time_cnt*CLK_TIME*340/2.0*100.0;
			//printf("%f cm\r\n",long_chang);
			cap_flag=0;
			
			TIM4CH4_CAPTURE_STA=0;
			TIM4CH4_CAPTURE_VAL=0;
			Delay_ms(10);
			
		}
	return long_chang;
	
}



int main(void)
{
	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
//	uart_init(115200);
	
	delay_init();    //延时初始化		
	TIM3_PWM_Init();	//电机pwm   TIM3
	SG90_PWM_Init();	//舵机初始化
	CH_SR04_Init(0xffff,8);		//超声波定时器初始化
	
	TIM_Cmd(TIM4,ENABLE);//开启超声波测距定时器
	
	while(1)
	{
		
		SG90_Front;
		Delay_ms(700);
		length_res[0]=sensor();
		Delay_ms(10);
		//printf("fornt:%f\r\n",length_res[0]);
		
		if(length_res[0]>40.0000)       //如果前方距离大于40cm  前进
			{
				Forward();
			}
			
			else if(length_res[0]<40.0000)     //如果前方距离小于40厘米  停车测左右距离
			{
				STOP();  
				SG90_Left_45;      //舵机左转45度测距
				Delay_ms(700);		
				length_res[1] =sensor();    //把测量结果放进数组
				Delay_ms(10);
				//printf("left:%fcm left45 \r\n",length_res[1]);
			
				SG90_Right_45;     //舵机右转45度测距
				Delay_ms(700);	
        length_res[4] =sensor();     //把测量结果放进数组	
				Delay_ms(10);
				//printf("right:%fcm right 45\r\n",length_res[4]);				
				
				SG90_Front;           //舵机摆正
				//Delay_ms(700); 
				if(length_res[1]<40.00&&length_res[4]<40.00&&length_res[1]>length_res[4])
				{
					SG90_Front; //舵机摆正
					Delay_ms(700);
					length_res[0] =sensor();	//重复测前方的距离同时
					Delay_ms(10);						
					Backward();
					Delay_ms(700);
					Turn_left();
//					Delay_ms(500);
				}
				if(length_res[1]<40.00&&length_res[4]<40.00&&length_res[1]<length_res[4])
				{
					SG90_Front; //舵机摆正
					Delay_ms(700);
					length_res[0] =sensor();	//重复测前方的距离同时
					Delay_ms(10);						
					Backward();
					Delay_ms(700);
					Turn_right();
//					Delay_ms(500);
				}
				if(length_res[1]>length_res[4])    //如果左边的距离大于右边的距离
					{
						SG90_Front; //舵机摆正
						Delay_ms(700);
						length_res[0] =sensor();	//重复测前方的距离同时左转
						Delay_ms(10);						
						Turn_left();
						if(length_res[0]>35.0000)
							Forward();

					}
				if(length_res[1]<length_res[4])    //如果右边的距离大于左边的距离
				{
					SG90_Front;
					Delay_ms(700);
					length_res[0] =sensor();  //重复测前方的距离同时右转
					Delay_ms(10);						
					Turn_right();
					if(length_res[0]>35.0000)
							Forward();
				}
				
			}
	
	
	}
	
}





void TIM4_IRQHandler(void)//中断溢出
{


	if((TIM4CH4_CAPTURE_STA&0x80)==0)
		{
		if(TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
			{			//判断定时器是否溢出
			if(TIM4CH4_CAPTURE_STA&0x40)//判断之前是否已经接收到上升沿
				{							
				if((TIM4CH4_CAPTURE_STA&0X3F)==0X3F)			//如果计数已经满了 直接停止
					{
					//cap_flag=1;
					TIM4CH4_CAPTURE_STA|=0x80;
					TIM4CH4_CAPTURE_VAL=0XFFFF;
					}
				else TIM4CH4_CAPTURE_STA++;			//如果计数没满，继续计数
			
			
			}
		
		}
	}
		
	
	if(TIM_GetITStatus(TIM4, TIM_IT_CC4) != RESET)
		{				//表示捕获到来上升沿
		
		if(TIM4CH4_CAPTURE_STA&0x40)//表明之前已经接收到了一个边沿（这一次捕获边沿表示捕获结束）
			{	
							
			cap_flag=1;
			TIM4CH4_CAPTURE_STA|=0x80;
			TIM4CH4_CAPTURE_VAL=TIM_GetCapture4(TIM4);			//读取捕获的值
			TIM_OC4PolarityConfig(TIM4,TIM_ICPolarity_Rising);		//重新设置为上升沿捕获
		
			}
		else
			{		//表示首次进入捕获边沿
			
			cap_flag=0;
			TIM4CH4_CAPTURE_STA=0;
			TIM4CH4_CAPTURE_VAL=0;
			TIM4CH4_CAPTURE_STA|=0X40;					//标记为捕获了一次上升沿
			TIM_SetCounter(TIM4,0);
			TIM_OC4PolarityConfig(TIM4,TIM_ICPolarity_Falling);	
			
			}
	
	
	}
	TIM_ClearITPendingBit(TIM4, TIM_IT_CC4|TIM_IT_Update); //清除中断标志位
	
	
	
}





************/


