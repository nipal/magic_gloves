/* 
 * File:   oled_driver.h
 * Author: lapin
 *
 * Created on June 8, 2017, 4:36 PM
 */

#ifndef OLED_DRIVER_H
#define	OLED_DRIVER_H

/*
  SeeedOLED.h - SSD130x OLED Driver Library
  2011 Copyright (c) Seeed Technology Inc.  All right reserved.
 
  Author: Visweswara R
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef OLED_DRIVER_H
#define OLED_DRIVER_H

#include <xc.h>
#include <stdint.h>

#define SeeedOLED_Max_X 				127	//128 Pixels
#define SeeedOLED_Max_Y 				63	//64  Pixels

#define PAGE_MODE						01
#define HORIZONTAL_MODE					02


#define SeeedOLED_Address				0x3c
#define SeeedOLED_Command_Mode			0x80
#define SeeedOLED_Data_Mode				0x40
#define SeeedOLED_Display_Off_Cmd		0xAE
#define SeeedOLED_Display_On_Cmd		0xAF
#define SeeedOLED_Normal_Display_Cmd	0xA6
#define SeeedOLED_Inverse_Display_Cmd	0xA7
#define SeeedOLED_Activate_Scroll_Cmd	0x2F
#define SeeedOLED_Dectivate_Scroll_Cmd	0x2E
#define SeeedOLED_Set_Brightness_Cmd	0x81

#define Scroll_Left						0x00
#define Scroll_Right					0x01

#define Scroll_2Frames					0x7
#define Scroll_3Frames					0x4
#define Scroll_4Frames					0x5
#define Scroll_5Frames					0x0
#define Scroll_25Frames					0x6
#define Scroll_64Frames					0x1
#define Scroll_128Frames				0x2
#define Scroll_256Frames				0x3


extern char addressingMode;
extern const uint8_t BasicFont[][8] PROGMEM=


void init(void);

void setNormalDisplay();
void setInverseDisplay();

void sendCommand(uint8_t command);
void sendData(uint8_t Data);

void setPageMode();
void setHorizontalMode();

void setTextXY(uint8_t Row, uint8_t Column);
void clearDisplay();
void setBrightness(uint8_t Brightness);
void putChar(uint8_t c);
void putString(const char *String);
uint8_t putNumber(long n);
uint8_t putFloat(float floatNumber, uint8_t decimal);
uint8_t putFloat(float floatNumber);
void drawBitmap(uint8_t *bitmaparray, int bytes);

void setHorizontalScrollProperties(bool direction, uint8_t startPage, uint8_t endPage, uint8_t scrollSpeed);
void activateScroll();
void deactivateScroll();


#endif



#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* OLED_DRIVER_H */

