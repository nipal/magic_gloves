#include <xc.h>
#include <stdint.h>
#include "mini_caps.h"

void    print_16_bin(uint16_t val)
{
    int8_t  i;
    int8_t  str[17];
    
    for (i = 0; i < 16; ++i)
    {
        if (val & (1 << (15 - i)))
            str[i] = '#';
        else
            str[i] = '_';
    }
    str[16] = '\0';
    my_putstr(str);
}

void    test()
{
//    TRISBbits.TRISB12 = 1;
//    TRISBbits.TRISB13 = 1;
//    TRISBbits.TRISB14 = 1;
    
 //   ODCBbits.ODCB12 = 0;
 //   ODCBbits.ODCB13 = 0;
 //   ODCBbits.ODCB14 = 0;
 
    TRISBbits.TRISB12 = 1;
    TRISBbits.TRISB13 = 1;
    TRISBbits.TRISB14 = 1;
    
    ANSELBbits.ANSB12  = 0;
    ANSELBbits.ANSB13  = 0;
    ANSELBbits.ANSB14  = 0;
    


    
    TRISBbits.TRISB8 = 0;
    TRISBbits.TRISB9 = 0;
    TRISBbits.TRISB10 = 0;
    
    tick_begin(3);
    
    while (42)
    {
//        LATBbits.LATB12 = !PORTBbits.RB12;
//        LATBbits.LATB13 = !PORTBbits.RB13;
//        LATBbits.LATB14 = !PORTBbits.RB14;
//        print_16_bin(ANSELB);
//        print_16_bin(TRISB);
        LED1 = BUT1;
        LED2 = BUT2;
        LED3 = BUT3;
        wait(30);
    }
}

