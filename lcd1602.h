/*
// This file is part of LCD1602 Driver project
// Last-Modified:2019-1-29 12:07:23 @ V0.0.3
// Copyright (C)2019 SENCOM <sencom1997@outlook.com>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either
// version 3 of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/
#ifndef LCD1602_H
#define LCD1602_H

#include "wiringPi.h"
#include "time.h"

#define SETMODE 0x38	//16*2显示,5*8点阵,8位数据接口
#define DISOPEN 0x0C	//显示开,显示光标,光标不闪烁
#define DISMODE 0x06	//读写字符后地址加1,屏显不移动
#define SETADDR 0x80	//设置数据地址指针初始值
#define CLEAR	0x01	//清屏,数据指针清零
#define RET	0x02	//回车,数据指针清零
#define LSHIFT	0x18	//屏幕左移
#define	RSHIFT	0x1C	//屏幕右移

#define COM_SLEEP	200		//指令延时
#define DATA_SLEEP	100		//数据延时

typedef signed char        int8_t;
typedef short              int16_t;
typedef int                int32_t;
typedef long long          int64_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;


class LCD1602
{
	private:
		int _rs_pin;							// LOW: 命令.  HIGH: 数据.
		int _rw_pin;							// LOW: 写.  HIGH: 读.
		int _en_pin;							// 高电平有效.
		int _data_pins[8];						// 数据/指令针脚
		
		void Write_Com(uint8_t com);			//写命令
		void Write_Data(uint8_t data);			//写数据
	public:
		void Init(int rs, int rw, int en,int d0, int d1, int d2, int d3,int d4, int d5, int d6, int d7);
			//初始化,参数为对应的GPIO针脚
		void Write_String(uint8_t x,uint8_t y,const char *s);
			//写字符串 x:行数 y:列数 (默认屏幕左上角为 第一行第一列) *s为字符串地址
		void Shift(uint8_t dire, uint32_t ms, uint8_t len);	
			//字符位移 dire:移动方向 ms:移动速度(以毫秒为单位) len:移动长度
		void Set_User_Char(uint8_t index, const uint8_t *c);
			//设置自定义字符 index 为自定义符号编号 从 0 --- 7 八个自定义字符编号，*c为字模数组地址
		void Write_User_Char(uint8_t x,uint8_t y,uint8_t index);
			//写字符串 x:列数 y:行数 (默认屏幕左上角为 第一行第一列) index为用户自定义字符串编号
		void Clear(void);
			//清屏
}; 

#endif
