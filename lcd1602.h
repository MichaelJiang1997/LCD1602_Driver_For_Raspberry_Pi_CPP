/*
// This file is part of LCD1602 Driver project
// Last-Modified:2019-1-26 16:54:33 @ V0.0.1
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

#define SETMODE 0x38	 //16*2显示,5*8点阵,8位数据接口
#define DISOPEN 0x0C	 //显示开,显示光标,光标不闪烁
#define DISMODE 0x06	 //读写字符后地址加1,屏显不移动
#define SETADDR 0x80	 //设置数据地址指针初始值
#define CLEAR	0x01	 //清屏,数据指针清零
#define RET		0x02	 //回车,数据指针清零
#define TEST	0xFF	 //回车,数据指针清零

#define SLEEP_L 100000	 //长延时
#define SLEEP_S  50000	 //短延时

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
		int _rs_pin; 							// LOW: 命令.  HIGH: 数据.
		int _rw_pin; 							// LOW: 写.  HIGH: 读.
		int _en_pin; 							// 高电平有效.
		int _data_pins[8];
		
		void Delay(uint32_t s);					//延时
		void Check_Busy(void);					//检查忙
		void Write_Com(uint8_t com);			//写命令
		void Write_Data(uint8_t data);			//写数据
	public:
		void Init(int rs, int rw, int en,int d0, int d1, int d2, int d3,int d4, int d5, int d6, int d7);
		void Write_String(uint8_t x,uint8_t y,const char *s);
		void Clear(void);						//清屏
}; 

#endif
