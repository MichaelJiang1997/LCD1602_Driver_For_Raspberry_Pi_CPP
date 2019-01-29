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

#include "lcd1602.h"				
#include "wiringPi.h"

int main()
{
	uint8_t pi[8]={                       
		0x00, 0x1f, 0x0a, 0x0a, 0x0a, 0x13, 0x00, 0x00	//自定义 pai 字模
	};
	wiringPiSetup();
	LCD1602 lcd;
	lcd.Init(1, 4, 5, 0, 2, 3, 21, 22, 23, 24, 25);
	lcd.Set_User_Char(0, pi);//在 0 号自定义字符位置写入 pi
	lcd.Write_User_Char(1, 1, 0);//把 0 号单元的自定义字符 打印到(1,1)
	
};