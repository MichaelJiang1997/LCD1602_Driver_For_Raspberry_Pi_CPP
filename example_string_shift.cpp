/*
// This file is part of LCD1602 Driver project
// Last-Modified:2019-1-28 13:23:21 @ V0.0.2
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
#include "string.h"

int main()
{
	char buf[128] = "People's Republic of China";
	
	wiringPiSetup();
	
	LCD1602 lcd;
	lcd.Init(1, 4, 5, 0, 2, 3, 21, 22, 23, 24, 25);
	lcd.Write_String(1, 1, buf);
	while(1)
		lcd.Shift(1, 1, strlen(buf));	//左移，整体一秒移一下，移动总长度为字符串 buf 长度
	return 0;
}
