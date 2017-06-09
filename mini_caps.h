/* 
 * File:   mini_caps.h
 * Author: lapin
 *
 * Created on June 9, 2017, 4:58 AM
 */

#ifndef MINI_CAPS_H
#define	MINI_CAPS_H
#include "oled.h"
#include <xc.h>


#define CHAR_BY_LINE 16
#define CHAR_BY_COLUMN 32
#define TAB_SIZE 4

#define SIZE_HISTORY (16 * 16 * 8)

extern uint32_t    offset_screen;
extern uint32_t    offset_screen_max;


extern  const uint8_t basicFont[96][8];


void    my_putchar(int8_t c);
void    my_putstr(int8_t *str);
void    my_putnbr(int32_t nbr);
void    putnbr_endl(int32_t nbr);
void    init_mini_caps();
void    print_screen();

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* MINI_CAPS_H */

