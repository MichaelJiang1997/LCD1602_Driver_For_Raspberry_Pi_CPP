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

void LCD1602::Init( int rs, int rw, int en, int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7)
{
	_rs_pin = rs;
	_rw_pin = rw;
	_en_pin = en;

	_data_pins[0] = d0;
	_data_pins[1] = d1;
	_data_pins[2] = d2;
	_data_pins[3] = d3;
	_data_pins[4] = d4;
	_data_pins[5] = d5;
	_data_pins[6] = d6;
	_data_pins[7] = d7;
	for(int i=0; i<8; i++)
		pinMode(_data_pins[i],OUTPUT);

	pinMode(_en_pin,OUTPUT);
	pinMode(_rw_pin,OUTPUT);
	pinMode(_rs_pin,OUTPUT);

	Write_Com(SETMODE);     //模式设置
	Write_Com(DISOPEN);     //显示设置
	Write_Com(DISMODE);     //显示模式
	Write_Com(CLEAR);       //清屏

}

void LCD1602::Write_Com(uint8_t com)
{
	digitalWrite(_en_pin,LOW);
	digitalWrite(_rs_pin,LOW);
	digitalWrite(_rw_pin,LOW);
	for(uint8_t i=0; i<8; i++)
		digitalWrite(_data_pins[i],(com >> i) & 0x01);
	delayMicroseconds(COM_SLEEP);
	digitalWrite(_en_pin,HIGH);
	delayMicroseconds(COM_SLEEP);
	digitalWrite(_en_pin,LOW);
	delayMicroseconds(COM_SLEEP);
}

void LCD1602::Write_Data(uint8_t data)
{
	digitalWrite(_en_pin,LOW);
	digitalWrite(_rs_pin,HIGH);
	digitalWrite(_rw_pin,LOW);
	for(uint8_t i=0; i<8; i++)
		digitalWrite(_data_pins[i],(data >> i) & 0x01);
	delayMicroseconds(DATA_SLEEP);
	digitalWrite(_en_pin,HIGH);
	delayMicroseconds(DATA_SLEEP);
	digitalWrite(_en_pin,LOW);
	delayMicroseconds(DATA_SLEEP);
}
void LCD1602::Write_String(uint8_t x,uint8_t y,const char *s)
{
	Write_Com(0x80);				//消除第一次不能指定位置写入问题
	if(y == 1)
		Write_Com(0x80 + x - 1);		//在第一行 x 列写
	else
		Write_Com(0xC0 + x - 1);		//在第二行 x 列写
	while(*s)
	{
		Write_Data(*s);
		s++;
	}
}

void LCD1602::Clear()
{
	Write_Com(CLEAR);
}

void LCD1602::Shift(uint8_t dire, uint32_t ms, uint8_t len)
{
	if( dire )
	{
		for(int i = 0; i < len; i++)
		{
			Write_Com(LSHIFT);
			delay(ms);
		}
	}
	else
	{
		for(int i = 0; i < len; i++)
		{
			Write_Com(RSHIFT);
			delay(ms);
		}
	}
}
void LCD1602::Set_User_Char(uint8_t index, const uint8_t *c)
{
	Write_Com(0x80);				//消除第一次不能指定位置写入问题
	Write_Com(index | 0x40);
	for(int i = 0; i < 8; i++)
	{
		Write_Data(c[i]);
	}
}
void LCD1602::Write_User_Char(uint8_t x,uint8_t y,uint8_t index)
{
	Write_Com(0x80);				//消除第一次不能指定位置写入问题
	if(y == 1)
		Write_Com(0x80 + x - 1);		//在第一行 x 列写
	else
		Write_Com(0xC0 + x - 1);		//在第二行 x 列写
	Write_Data(index);
}


