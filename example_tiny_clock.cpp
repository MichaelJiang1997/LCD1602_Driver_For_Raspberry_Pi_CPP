/*
// This file is part of LCD1602 Driver project
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

#include "lcd1602.h"					//引用 lcd1602

int main()
{
	time_t t;
    char buf[128];
    char stime[64];						//存放时间截取
	char sdate[64];						//存放日期截取
	int i,j;
	
	LCD1602 lcd;
	lcd.Init(1,4,5,0,2,3,21,22,23,24,25);
	while(1)
	{
		time(&t);
		ctime_r(&t,buf); 
		for(i=0; i<11;i++)
			sdate[i] = buf[i];
		sdate[i] = '\0';
		for(i=11,j=0; i<20;i++,j++)
			stime[j] = buf[i];
		stime[j] = '\0';
		lcd.Write_String(1,1,sdate);
		lcd.Write_String(1,2,stime);
	}
	return 0;
}
