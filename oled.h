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


#define OLED_ADDR  0b0111100

#define OLED_DISPLAY    0xA4
#define OLED_ALL_ON     0xA5
#define OLED_OFF        0xAE
#define OLED_ON         0xAF

#define WIDTH           128
#define HEIGHT          64
#define OLED_SIZE       ((WIDTH * HEIGHT) / 8)
#define OLED_ADDRESS    0x3C



    extern uint8_t oledBuffer[OLED_SIZE];

    void    init_i2c_5(void);
    void    wait(uint32_t);

    void oledInitialize(void);
    void oledClear(void);
    void oledUpdate(void);
    
    void oledDrawPixel(uint8_t x, uint8_t y);
    void oledDrawVLine(uint8_t x);
    void oledDrawHLine(uint8_t y);

    uint8_t    buff_is_empty();
    void send_oled_data(uint8_t *data, uint16_t size);


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* OLED_H */

