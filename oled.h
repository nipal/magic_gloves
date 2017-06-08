/* 
 * File:   oled.h
 * Author: lapin
 *
 * Created on June 6, 2017, 4:13 PM
 */

#ifndef OLED_H
#define	OLED_H

#include <stdint.h>
#include <xc.h>

#define LED1 LATBbits.LATB8
#define LED2 LATBbits.LATB9
#define LED3 LATBbits.LATB10
#define GET_LED1 PORTBbits.RB8
#define GET_LED2 PORTBbits.RB9
#define GET_LED3 PORTBbits.RB10


#define OLED_CMD_W  0b01111000
#define OLED_CMD_R  0b01111001
#define OLED_RAM_W  0b01111010
#define OLED_RAM_R  0b01111011

#define OLED_DISPLAY    0xA4
#define OLED_ALL_ON     0xA5
#define OLED_OFF        0xAE
#define OLED_ON         0xAF

#define OLED_ADD_HRZ    0x20

#define WIDTH 128
#define HEIGH 64
#define OLED_SIZE 1024
extern uint8_t oled[OLED_SIZE];
void    init_i2c_5(void);
void    oled_test(void);



void        init_oled();
uint8_t     oled_send_cmd(const uint8_t * const data, const uint8_t size);
uint8_t     i2c5_send_byte(const uint8_t byte);


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* OLED_H */

