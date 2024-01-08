    
/****
   // ������ɫ����ɫ����ɫ�����ı���
//    u8 red, green, blue;

//    // ����ѭ������ i �� j
//    int i, j;

//    // ���ö�ֵ������ֵ
//    threshold = 128;
        //        // ���� LCD ���λ��
//        LCD_SetCursor(0, 0);

//        // ׼�� LCD ����д��
//        LCD_WriteRAM_Prepare();

//        // �� LCD ����ʾͼ��
//        Show_Picture(0, 0, 240, 400, (u16 *)rgb_buf);

//        // ѭ������ RGB �������е�ÿ������
//        for (i = 0; i < A; i++)
//        {
//            for (j = 0; j < B; j++)
//            {
//                // �� RGB ֵ����ȡ��ɫ����ɫ����ɫ����
//                red = ((rgb_buf[i][j] & 0xF800) >> 8);
//                green = ((rgb_buf[i][j] & 0x07E0) >> 3);
//                blue = ((rgb_buf[i][j] & 0x001F) << 3);

//                // ʹ�ü�Ȩ�ͽ���ת��Ϊ 8 λ�Ҷ�ֵ
//                gray8[i][j] = (red * 38 + green * 75 + blue * 15) >> 7;

//                // ������ֵ�����ؽ��ж�ֵ��
//                if (threshold < gray8[i][j])
//                {
//                    // �������ֵ������ֵ��������Ϊ��ɫ
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
//                    // �������ֵ���ڻ������ֵ��������Ϊ��ɫ
//                    LCD_SetCursor(2 * j, 480 + 2 * i);
//                    LCD_WriteRAM_Prepare();
//                    LCD->LCD_RAM = BLACK;
//                    LCD->LCD_RAM = BLACK;

//                    LCD_SetCursor(2 * j, 480 + 2 * i + 1);
//                    LCD_WriteRAM_Prepare();
//                    LCD->LCD_RAM = BLACK;
//                    LCD->LCD_RAM = BLACK;
//                }


//                // Ϊ���ؽ��ж���� LCD ����
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

//                // �� 8 λ�Ҷ�ֵת��Ϊ 16 λ��ɫֵ
//                gray16 = gray8[i][j] >> 3;
//                color = ((0x001f & gray16) << 11) | (((0x003f) & (gray16 * 2)) << 5) | (0x001f & gray16);

//                // ���� LCD ��겢д����ɫֵ
//                LCD_SetCursor(2 * j, 240 + 2 * i);
//                LCD_WriteRAM_Prepare();
//                LCD->LCD_RAM = color;
//                LCD->LCD_RAM = color;

//                LCD_SetCursor(2 * j, 240 + 2 * i + 1);
//                LCD_WriteRAM_Prepare();
//                LCD->LCD_RAM = color;
//                LCD->LCD_RAM = color;

// ���峣�� A �� B���ֱ�Ϊ 120 �� 200// ���� OV2640 ����ߴ�
#define A 120
#define B 200
// ����һ�����ڴ洢 RGB ���ݵĶ�ά���飬ÿ��Ԫ��Ϊ 16 λ�޷�������
u16 rgb_buf[A][B];
// ����һ�����ڴ洢�Ҷ����ݵĶ�ά���飬ÿ��Ԫ��Ϊ 8 λ�޷�������
u8 gray8[A][B];
// ���� 16 λ���������ڴ洢�ҶȺ���ɫֵ
u16 gray16;
u16 color;
// ���� 8 λ���������ڶ�ֵ������ֵ
u8 threshold;

int main(void)
{
	u8 red,green,blue;// ������ɫ����ɫ����ɫ�����ı���
	int i,j;
	threshold=128;  // ���ö�ֵ������ֵ
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	//delay_init(168);  //��ʼ����ʱ����
	uart_init(115200);		//��ʼ�����ڲ�����Ϊ115200
	LED_Init();					//��ʼ��LED 
 	LCD_Init();					//LCD��ʼ��  
 	KEY_Init();					//������ʼ�� 
	while(OV2640_Init())//��ʼ��OV2640
	{
		LCD_ShowString(30,130,240,16,16,"OV2640 ERR");
		Delay_ms(200);
	    LCD_Fill(30,130,239,170,WHITE);
		Delay_ms(200);
	}
    
	OV2640_OutSize_Set(B,A);// ���� OV2640 ����ߴ�
	OV2640_RGB565_Mode();// �� OV2640 ����Ϊ RGB565 ģʽ
  My_DCMI_Init();// ��ʼ�� DCMI �ӿ�
//	DCMI_DMA_Init((u32)&LCD->LCD_RAM,1,DMA_MemoryDataSize_HalfWord,DMA_MemoryInc_Disable);
  DCMI_DMA_Init((u32)rgb_buf,sizeof(rgb_buf)/4,DMA_MemoryDataSize_HalfWord,DMA_MemoryInc_Enable);// ��ʼ�� DCMI �� DMA
  DCMI_Start(); // ���� DCMI
//	OV2640_Special_Effects(2);
	
	while(1)
	{
		LCD_SetCursor(0,0);// ���� LCD ���λ��
		LCD_WriteRAM_Prepare();// ׼�� LCD ����д��
		
	  Show_Picture(0,0,240,400,(u16*)rgb_buf);		// �� LCD ����ʾͼ��
		for(i=0;i<A;i++)// ѭ������ RGB �������е�ÿ������
		{
				for(j=0;j<B;j++)
				{   // �� RGB ֵ����ȡ��ɫ����ɫ����ɫ����
					red=((rgb_buf[i][j] & 0xF800)>>8);
					green=((rgb_buf[i][j] & 0x07E0)>>3);
					blue=((rgb_buf[i][j] & 0x001F)<<3);
					gray8[i][j]=(red*38+green*75+blue*15)>>7; // ʹ�ü�Ȩ�ͽ���ת��Ϊ 8 λ�Ҷ�ֵ
                     // ������ֵ�����ؽ��ж�ֵ��
					if(threshold<gray8[i][j])
					{   // �������ֵ������ֵ��������Ϊ��ɫ
						LCD_SetCursor(2*j,480+2*i);LCD_WriteRAM_Prepare();LCD->LCD_RAM=WHITE;LCD->LCD_RAM=WHITE;
						LCD_SetCursor(2*j,480+2*i+1);LCD_WriteRAM_Prepare();LCD->LCD_RAM=WHITE;LCD->LCD_RAM=WHITE;
					}
					else
					{    // �������ֵ���ڻ������ֵ��������Ϊ��ɫ
						LCD_SetCursor(2*j,480+2*i);LCD_WriteRAM_Prepare();LCD->LCD_RAM=BLACK;LCD->LCD_RAM=BLACK;
						LCD_SetCursor(2*j,480+2*i+1);LCD_WriteRAM_Prepare();LCD->LCD_RAM=BLACK;LCD->LCD_RAM=BLACK;
					}
                    // Ϊ���ؽ��ж���� LCD ����
					LCD_SetCursor(2*j,480+2*i);LCD_WriteRAM_Prepare();if(threshold<gray8[i][j]){LCD->LCD_RAM=WHITE;LCD->LCD_RAM=WHITE;}else {LCD->LCD_RAM=BLACK;LCD->LCD_RAM=BLACK;}
					LCD_SetCursor(2*j,480+2*i+1);LCD_WriteRAM_Prepare();if(threshold<gray8[i][j]){LCD->LCD_RAM=WHITE;LCD->LCD_RAM=WHITE;}else {LCD->LCD_RAM=BLACK;LCD->LCD_RAM=BLACK;}
					LCD_SetCursor(2*j+1,480+2*i);LCD_WriteRAM_Prepare();if(threshold<gray8[i][j])LCD->LCD_RAM=WHITE;else LCD->LCD_RAM=BLACK;
					LCD_SetCursor(2*j+1,480+2*i+1);LCD_WriteRAM_Prepare();if(threshold<gray8[i][j])LCD->LCD_RAM=WHITE;else LCD->LCD_RAM=BLACK;
					// �� 8 λ�Ҷ�ֵת��Ϊ 16 λ��ɫֵ
					gray16=gray8[i][j]>>3;
					color=((0x001f&gray16)<<11)|(((0x003f)&(gray16*2))<<5)|(0x001f&gray16);
                    // ���� LCD ��겢д����ɫֵ
					LCD_SetCursor(2*j,240+2*i);LCD_WriteRAM_Prepare();LCD->LCD_RAM=color;LCD->LCD_RAM=color;
					LCD_SetCursor(2*j,240+2*i+1);LCD_WriteRAM_Prepare();LCD->LCD_RAM=color;LCD->LCD_RAM=color;

			}
		}

	}
}


u8 hsync_int = 0;						//֡�жϱ�־
u8 ov2640_mode=0;						//����ģʽ:0,RGB565ģʽ;1,JPEGģʽ

#define jpeg_buf_size 31*1024  			//����JPEG���ݻ���jpeg_buf�Ĵ�С(*4�ֽ�)
__align(4) u32 jpeg_buf[jpeg_buf_size];	//JPEG���ݻ���buf
volatile u32 jpeg_data_len=0; 			//buf�е�JPEG��Ч���ݳ��� 
volatile u8 jpeg_data_ok=0;				//JPEG���ݲɼ���ɱ�־ 
										//0,����û�вɼ���;
										//1,���ݲɼ�����,���ǻ�û����;
										//2,�����Ѿ����������,���Կ�ʼ��һ֡����
//JPEG�ߴ�֧���б�
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
const u8*EFFECTS_TBL[7]={"Normal","Negative","B&W","Redish","Greenish","Bluish","Antique"};	//7����Ч 
const u8*JPEG_SIZE_TBL[9]={"QCIF","QQVGA","CIF","QVGA","VGA","SVGA","XGA","SXGA","UXGA"};	//JPEGͼƬ 9�ֳߴ� 


//����JPEG����
//���ɼ���һ֡JPEG���ݺ�,���ô˺���,�л�JPEG BUF.��ʼ��һ֡�ɼ�.
void jpeg_data_process(void)
{
	if(ov2640_mode)//ֻ����JPEG��ʽ��,����Ҫ������.
	{
		if(jpeg_data_ok==0)	//jpeg���ݻ�δ�ɼ���?
		{	
			DMA_Cmd(DMA2_Stream1, DISABLE);//ֹͣ��ǰ���� 
			while (DMA_GetCmdStatus(DMA2_Stream1) != DISABLE){}//�ȴ�DMA2_Stream1������  
			jpeg_data_len=jpeg_buf_size-DMA_GetCurrDataCounter(DMA2_Stream1);//�õ��˴����ݴ���ĳ���
				
			jpeg_data_ok=1; 				//���JPEG���ݲɼ��갴��,�ȴ�������������
		}
		if(jpeg_data_ok==2)	//��һ�ε�jpeg�����Ѿ���������
		{
			DMA2_Stream1->NDTR=jpeg_buf_size;	
			DMA_SetCurrDataCounter(DMA2_Stream1,jpeg_buf_size);//���䳤��Ϊjpeg_buf_size*4�ֽ�
			DMA_Cmd(DMA2_Stream1, ENABLE);			//���´���
			jpeg_data_ok=0;						//�������δ�ɼ�
		}
	}
    else
    {
        LCD_SetCursor(0, 0);
        LCD_WriteRAM_Prepare();     //��ʼд��GRAM
        hsync_int = 1;
    }
} 
//JPEG����
//JPEG����,ͨ������2���͸�����.
void jpeg_test(void)
{
	u32 i; 
	u8 *p;
	u8 key;
	u8 effect=0,saturation=2,contrast=2;
	u8 size=3;		//Ĭ����QVGA 320*240�ߴ�
	u8 msgbuf[15];	//��Ϣ������ 
	LCD_Clear(WHITE);
  POINT_COLOR=RED; 
	LCD_ShowString(30,50,200,16,16,"ALIENTEK STM32F4");
	LCD_ShowString(30,70,200,16,16,"OV2640 JPEG Mode");
	LCD_ShowString(30,100,200,16,16,"KEY0:Contrast");			//�Աȶ�
	LCD_ShowString(30,120,200,16,16,"KEY1:Saturation"); 		//ɫ�ʱ��Ͷ�
	LCD_ShowString(30,140,200,16,16,"KEY2:Effects"); 			//��Ч 
	LCD_ShowString(30,160,200,16,16,"KEY_UP:Size");				//�ֱ������� 
	sprintf((char*)msgbuf,"JPEG Size:%s",JPEG_SIZE_TBL[size]);
	LCD_ShowString(30,180,200,16,16,msgbuf);					//��ʾ��ǰJPEG�ֱ���
	
 	OV2640_JPEG_Mode();		//JPEGģʽ
	My_DCMI_Init();			//DCMI����
	DCMI_DMA_Init((u32)&jpeg_buf,jpeg_buf_size,DMA_MemoryDataSize_Word,DMA_MemoryInc_Enable);//DCMI DMA����   
	OV2640_OutSize_Set(jpeg_img_size_tbl[size][0],jpeg_img_size_tbl[size][1]);//��������ߴ� 
	DCMI_Start(); 		//��������
	while(1)
	{
		if(jpeg_data_ok==1)	//�Ѿ��ɼ���һ֡ͼ����
		{  
			p=(u8*)jpeg_buf;
			LCD_ShowString(30,210,210,16,16,"Sending JPEG data..."); //��ʾ���ڴ�������
			for(i=0;i<jpeg_data_len*4;i++)		//dma����1�ε���4�ֽ�,���Գ���4.
			{
        while(USART_GetFlagStatus(USART2,USART_FLAG_TC)==RESET);	//ѭ������,ֱ���������  		
				USART_SendData(USART2,p[i]); 
				key=KEY_Scan(0); 
				if(key)break;
			} 
			if(key)	//�а�������,��Ҫ����
			{  
				LCD_ShowString(30,210,210,16,16,"Quit Sending data   ");//��ʾ�˳����ݴ���
				switch(key)
				{				    
					case KEY0_PRES:	//�Աȶ�����
						contrast++;
						if(contrast>4)contrast=0;
						OV2640_Contrast(contrast);
						sprintf((char*)msgbuf,"Contrast:%d",(signed char)contrast-2);
						break;
					case KEY1_PRES:	//���Ͷ�Saturation
						saturation++;
						if(saturation>4)saturation=0;
						OV2640_Color_Saturation(saturation);
						sprintf((char*)msgbuf,"Saturation:%d",(signed char)saturation-2);
						break;
					case KEY2_PRES:	//��Ч����				 
						effect++;
						if(effect>6)effect=0;
						OV2640_Special_Effects(effect);//������Ч
						sprintf((char*)msgbuf,"%s",EFFECTS_TBL[effect]);
						break;
					case WKUP_PRES:	//JPEG����ߴ�����   
						size++;  
						if(size>8)size=0;   
						OV2640_OutSize_Set(jpeg_img_size_tbl[size][0],jpeg_img_size_tbl[size][1]);//��������ߴ�  
						sprintf((char*)msgbuf,"JPEG Size:%s",JPEG_SIZE_TBL[size]);
						break;
				}
				LCD_Fill(30,180,239,190+16,WHITE);
				LCD_ShowString(30,180,210,16,16,msgbuf);//��ʾ��ʾ����
				Delay_ms(800); 				  
			}else LCD_ShowString(30,210,210,16,16,"Send data complete!!");//��ʾ����������� 
			jpeg_data_ok=2;	//���jpeg���ݴ�������,������DMAȥ�ɼ���һ֡��.
		}		
	}    
} 
//RGB565����
//RGB����ֱ����ʾ��LCD����
void rgb565_test(void)
{ 
	u8 key;
	u8 effect=0,saturation=2,contrast=2;
	u8 scale=1;		//Ĭ����ȫ�ߴ�����
	u8 msgbuf[15];	//��Ϣ������ 
	LCD_Clear(WHITE);
    POINT_COLOR=RED; 
	LCD_ShowString(30,50,200,16,16,"ALIENTEK STM32F4");
	LCD_ShowString(30,70,200,16,16,"OV2640 RGB565 Mode");
	
	LCD_ShowString(30,100,200,16,16,"KEY0:Contrast");			//�Աȶ�
	LCD_ShowString(30,130,200,16,16,"KEY1:Saturation"); 		//ɫ�ʱ��Ͷ�
	LCD_ShowString(30,150,200,16,16,"KEY2:Effects"); 			//��Ч 
	LCD_ShowString(30,170,200,16,16,"KEY_UP:FullSize/Scale");	//1:1�ߴ�(��ʾ��ʵ�ߴ�)/ȫ�ߴ�����
	
	OV2640_RGB565_Mode();	//RGB565ģʽ
	My_DCMI_Init();			//DCMI����
	DCMI_DMA_Init((u32)&LCD->LCD_RAM,1,DMA_MemoryDataSize_HalfWord,DMA_MemoryInc_Disable);//DCMI DMA����  
 	OV2640_OutSize_Set(lcddev.width,lcddev.height); 
	DCMI_Start(); 		//��������
	while(1)
	{ 
		key=KEY_Scan(0); 
		if(key)
		{ 
			DCMI_Stop(); //ֹͣ��ʾ
			switch(key)
			{				    
				case KEY0_PRES:	//�Աȶ�����
					contrast++;
					if(contrast>4)contrast=0;
					OV2640_Contrast(contrast);
					sprintf((char*)msgbuf,"Contrast:%d",(signed char)contrast-2);
					break;
				case KEY1_PRES:	//���Ͷ�Saturation
					saturation++;
					if(saturation>4)saturation=0;
					OV2640_Color_Saturation(saturation);
					sprintf((char*)msgbuf,"Saturation:%d",(signed char)saturation-2);
					break;
				case KEY2_PRES:	//��Ч����				 
					effect++;
					if(effect>6)effect=0;
					OV2640_Special_Effects(effect);//������Ч
					sprintf((char*)msgbuf,"%s",EFFECTS_TBL[effect]);
					break;
				case WKUP_PRES:	//1:1�ߴ�(��ʾ��ʵ�ߴ�)/����	    
					scale=!scale;  
					if(scale==0)
					{
                        if(lcddev.id == 0X5510)
                        {
                            SCCB_WR_Reg(0xd3,0x02);
                        }
						OV2640_ImageWin_Set((1600-lcddev.width)/2,(1200-lcddev.height)/2,lcddev.width,lcddev.height);//1:1��ʵ�ߴ�
						OV2640_OutSize_Set(lcddev.width,lcddev.height); 
						sprintf((char*)msgbuf,"Full Size 1:1");
					}else 
					{
						OV2640_ImageWin_Set(0,0,1600,1200);				//ȫ�ߴ�����
						OV2640_OutSize_Set(lcddev.width,lcddev.height); 
						sprintf((char*)msgbuf,"Scale");
					}
					break;
			}
			LCD_ShowString(30,50,210,16,16,msgbuf);//��ʾ��ʾ����
			Delay_ms(800); 
			DCMI_Start();//���¿�ʼ����
		} 
        if (hsync_int)  //�ող���֡�ж�,������ʱ
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
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	//delay_init(168);  //��ʼ����ʱ����
	uart_init(115200);		//��ʼ�����ڲ�����Ϊ115200
	//usart2_init(42,115200);		//��ʼ������2������Ϊ115200
	LED_Init();					//��ʼ��LED 
 	LCD_Init();					//LCD��ʼ��  
 	KEY_Init();					//������ʼ�� 
	TIM3_Int_Init(10000-1,8400-1);//10Khz����,1�����ж�һ��
	
 	//usmart_dev.init(84);		//��ʼ��USMART
 	POINT_COLOR=RED;//��������Ϊ��ɫ 
	LCD_ShowString(30,50,200,16,16,"Explorer STM32F4");	
	LCD_ShowString(30,70,200,16,16,"OV2640 TEST");	
	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,110,200,16,16,"2014/5/14");  	 
	while(OV2640_Init())//��ʼ��OV2640
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
		if(key==KEY1_PRES)			//JPEGģʽ
		{
			ov2640_mode=0;   
			break;
		}else if(key==KEY0_PRES)	//RGB565ģʽ
		{
			ov2640_mode=1;
			break;
		}
		t++; 									  
		if(t==100)LCD_ShowString(30,150,230,16,16,"KEY0:RGB565  KEY1:JPEG"); //��˸��ʾ��ʾ��Ϣ
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


 POINT_COLOR=RED;      //������ɫ����ɫ
    u8 x=0;
    uart_init(115200);		//��ʼ�����ڲ�����Ϊ115200
	u8 lcd_id[12];				//���LCD ID�ַ���
    LCD_Init();           //��ʼ��LCD FSMC�ӿ�
    sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//��LCD ID��ӡ��lcd_id����
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
 		LCD_ShowString(30,110,200,16,16,lcd_id);		//��ʾLCD ID	      					 
		LCD_ShowString(30,130,200,12,12,"2014/5/4");	      					 
	  x++;
		if(x==12)x=0;
		LED_Turn();	 
		Delay_ms(1000);	**/

/****************************************************************************** 
* �������ܣ� ���� x, y, z �������� 
* ��������� �� 
* ��������� data���ǶȽṹ�� 
* ����ֵ �� �� 
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

u8  TIM4CH4_CAPTURE_STA=0;	//���벶��״̬
u16	TIM4CH4_CAPTURE_VAL;	//���벶��ֵ
u8 cap_flag=0;
float  length_res[5];  //������Ų����
u32 time_cnt;
double long_chang;


float sensor(void)
{
	
	PBout(8)=1; //�����źţ���Ϊ�����ź�
	delay_us(20); //�ߵ�ƽ�źų���10us
	PBout(8)=0;
		
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==RESET);
		TIM_Cmd(TIM4,ENABLE);//�����źŵ�����������ʱ������
		
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==SET);//�����ź���ʧ
		TIM_Cmd(TIM4,DISABLE);//�رն�ʱ��
		
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
	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
//	uart_init(115200);
	
	delay_init();    //��ʱ��ʼ��		
	TIM3_PWM_Init();	//���pwm   TIM3
	SG90_PWM_Init();	//�����ʼ��
	CH_SR04_Init(0xffff,8);		//��������ʱ����ʼ��
	
	TIM_Cmd(TIM4,ENABLE);//������������ඨʱ��
	
	while(1)
	{
		
		SG90_Front;
		Delay_ms(700);
		length_res[0]=sensor();
		Delay_ms(10);
		//printf("fornt:%f\r\n",length_res[0]);
		
		if(length_res[0]>40.0000)       //���ǰ���������40cm  ǰ��
			{
				Forward();
			}
			
			else if(length_res[0]<40.0000)     //���ǰ������С��40����  ͣ�������Ҿ���
			{
				STOP();  
				SG90_Left_45;      //�����ת45�Ȳ��
				Delay_ms(700);		
				length_res[1] =sensor();    //�Ѳ�������Ž�����
				Delay_ms(10);
				//printf("left:%fcm left45 \r\n",length_res[1]);
			
				SG90_Right_45;     //�����ת45�Ȳ��
				Delay_ms(700);	
        length_res[4] =sensor();     //�Ѳ�������Ž�����	
				Delay_ms(10);
				//printf("right:%fcm right 45\r\n",length_res[4]);				
				
				SG90_Front;           //�������
				//Delay_ms(700); 
				if(length_res[1]<40.00&&length_res[4]<40.00&&length_res[1]>length_res[4])
				{
					SG90_Front; //�������
					Delay_ms(700);
					length_res[0] =sensor();	//�ظ���ǰ���ľ���ͬʱ
					Delay_ms(10);						
					Backward();
					Delay_ms(700);
					Turn_left();
//					Delay_ms(500);
				}
				if(length_res[1]<40.00&&length_res[4]<40.00&&length_res[1]<length_res[4])
				{
					SG90_Front; //�������
					Delay_ms(700);
					length_res[0] =sensor();	//�ظ���ǰ���ľ���ͬʱ
					Delay_ms(10);						
					Backward();
					Delay_ms(700);
					Turn_right();
//					Delay_ms(500);
				}
				if(length_res[1]>length_res[4])    //�����ߵľ�������ұߵľ���
					{
						SG90_Front; //�������
						Delay_ms(700);
						length_res[0] =sensor();	//�ظ���ǰ���ľ���ͬʱ��ת
						Delay_ms(10);						
						Turn_left();
						if(length_res[0]>35.0000)
							Forward();

					}
				if(length_res[1]<length_res[4])    //����ұߵľ��������ߵľ���
				{
					SG90_Front;
					Delay_ms(700);
					length_res[0] =sensor();  //�ظ���ǰ���ľ���ͬʱ��ת
					Delay_ms(10);						
					Turn_right();
					if(length_res[0]>35.0000)
							Forward();
				}
				
			}
	
	
	}
	
}





void TIM4_IRQHandler(void)//�ж����
{


	if((TIM4CH4_CAPTURE_STA&0x80)==0)
		{
		if(TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
			{			//�ж϶�ʱ���Ƿ����
			if(TIM4CH4_CAPTURE_STA&0x40)//�ж�֮ǰ�Ƿ��Ѿ����յ�������
				{							
				if((TIM4CH4_CAPTURE_STA&0X3F)==0X3F)			//��������Ѿ����� ֱ��ֹͣ
					{
					//cap_flag=1;
					TIM4CH4_CAPTURE_STA|=0x80;
					TIM4CH4_CAPTURE_VAL=0XFFFF;
					}
				else TIM4CH4_CAPTURE_STA++;			//�������û������������
			
			
			}
		
		}
	}
		
	
	if(TIM_GetITStatus(TIM4, TIM_IT_CC4) != RESET)
		{				//��ʾ������������
		
		if(TIM4CH4_CAPTURE_STA&0x40)//����֮ǰ�Ѿ����յ���һ�����أ���һ�β�����ر�ʾ���������
			{	
							
			cap_flag=1;
			TIM4CH4_CAPTURE_STA|=0x80;
			TIM4CH4_CAPTURE_VAL=TIM_GetCapture4(TIM4);			//��ȡ�����ֵ
			TIM_OC4PolarityConfig(TIM4,TIM_ICPolarity_Rising);		//��������Ϊ�����ز���
		
			}
		else
			{		//��ʾ�״ν��벶�����
			
			cap_flag=0;
			TIM4CH4_CAPTURE_STA=0;
			TIM4CH4_CAPTURE_VAL=0;
			TIM4CH4_CAPTURE_STA|=0X40;					//���Ϊ������һ��������
			TIM_SetCounter(TIM4,0);
			TIM_OC4PolarityConfig(TIM4,TIM_ICPolarity_Falling);	
			
			}
	
	
	}
	TIM_ClearITPendingBit(TIM4, TIM_IT_CC4|TIM_IT_Update); //����жϱ�־λ
	
	
	
}





************/


