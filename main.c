#include "prof_concept.h"
//#include <xc.h>



int init_led()
{
    TRISBbits.TRISB8 = 0;
    TRISBbits.TRISB9 = 0;
    TRISBbits.TRISB10 = 0;
    
    // init oled reset
    TRISFbits.TRISF1 = 0;
    LATFbits.LATF1 = 1;
    
//    LED0 = 1;
//    LED1 = 1;
//    LED2 = 1;
}

int main()
{
    init_led();

    init_oled();
    

    
//    DBINIT();
  //  DBPRINTF("test\n");
    while (1)
    {
        //LED1 = ~GET_LED1;
    }
    
    return (0);
}

/*
     // init
    I2C5MSK = 0;         // pas de bit d'adressage ignorer
    I2C5BRG = 0x09;     // 400 khz
    I2C5CONbits.ON = 1;
    // end init
    
    int i;
    
    I2C5CONbits.SEN = 1;
    while (I2C5CONbits.SEN)
        LED1 = 1;
    I2C5TRN = OLED_CMD_W << 1 + 0;
    while (I2C5STATbits.TRSTAT)
       ;//LED2 = 1;
    if (!I2C5STATbits.ACKSTAT)
        ;//LED3 = 1;
    I2C5TRN = 0xAF;
    while (I2C5STATbits.TRSTAT)
       LED2 = 1;
    if (!I2C5STATbits.ACKSTAT)
        LED3 = 1;
    I2C5CONbits.PEN = 1;
    while (I2C5CONbits.PEN);

    i = 0;
    while (++i < 10000);
    
    
    
    I2C5CONbits.SEN = 1;
    while (I2C5CONbits.SEN)
        LED1 = 1;
    I2C5TRN = OLED_CMD_W << 1 + 0;
    while (I2C5STATbits.TRSTAT)
       ;//LED2 = 1;
    if (!I2C5STATbits.ACKSTAT)
        ;//LED3 = 1;
    I2C5TRN = 0xA5;
    while (I2C5STATbits.TRSTAT)
       LED2 = 1;
    if (!I2C5STATbits.ACKSTAT)
        LED3 = 1;
    I2C5CONbits.PEN = 1;
    while (I2C5CONbits.PEN);
    i = 0;
    while (++i < 1000);
    
    
 */