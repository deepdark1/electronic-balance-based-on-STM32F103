#ifndef __LCD1602_H
#define __LCD1602_H	 
#include "sys.h"

//1602液晶指令/数据选择引脚
#define	LCD_RS_Set()	GPIO_SetBits(GPIOC, GPIO_Pin_15)
#define	LCD_RS_Clr()	GPIO_ResetBits(GPIOC, GPIO_Pin_15)

//1602液晶读写引脚
#define	LCD_RW_Set()	GPIO_SetBits(GPIOC, GPIO_Pin_14)
#define	LCD_RW_Clr()	GPIO_ResetBits(GPIOC, GPIO_Pin_14)

//1602液晶使能引脚
#define	LCD_EN_Set()	GPIO_SetBits(GPIOC, GPIO_Pin_13)
#define	LCD_EN_Clr()	GPIO_ResetBits(GPIOC, GPIO_Pin_13)

//1602液晶数据端口	PD0~7
#define	DATAOUT(x)	GPIO_Write(GPIOB, x<<8)

//1602两行显示的写入地址
#define line_1 0x80
#define line_2 0x80+0x40

void GPIO_Configuration(void);
void LCD1602_Wait_Ready(void);
void LCD1602_Write_Cmd(u8 cmd);
void LCD1602_Write_Dat(u8 dat);
void LCD1602_ClearScreen(void);
void LCD1602_Set_Cursor(u8 x, u8 y);
void LCD1602_Show_Str(u8 x, u8 y, u8 *str);
void LCD1602_Init(void);

#endif
