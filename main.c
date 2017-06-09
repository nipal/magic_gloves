#include "prof_concept.h"
#include "oled.h"
#include "mini_caps.h"


#include <stdio.h>
#include <xc.h>

//#include <xc.h>



int init_led()
{
    TRISBbits.TRISB8 = 0;
    TRISBbits.TRISB9 = 0;
    TRISBbits.TRISB10 = 0;
    
    // init oled reset
    TRISFbits.TRISF1 = 0;
    LATFbits.LATF1 = 1;
    
    TRISBbits.TRISB12 = 1;
    TRISBbits.TRISB13 = 1;
    TRISBbits.TRISB14 = 1;
    
//    LED0 = 1;
//    LED1 = 1;
//    LED2 = 1;
}

void tick_tick()
{
    int i = 0;
    int j = 0;
    uint8_t     data[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    uint32_t    test;
    
    
    test = 0xFFFFFFFF;
//    oledClear();
//    oledUpdate();
    while (1)
    {
 //       wait(10);
        LED1 = ~GET_LED1;
        
        if (j >= 96)
            j = 0;
        //send_oled_data((uint8_t*)&(basicFont[j][0]), 8);
        //my_putstr(" # Je suis un LAPIN!!! #");
        my_putstr("## Lapin est le plus beau ##");
        //        LED2 = buff_is_empty();
  //      oledUpdate();
        i++;
        j++;
        //LED1 = ~GET_LED1;
    }

}

void test_putnbr()
{
    putnbr_endl(42);
    putnbr_endl(666);
    putnbr_endl(-12);
    putnbr_endl(0);
    putnbr_endl(-2147483647);
//    putnbr_endl(2147483648);
    putnbr_endl(-42);
}

void test_sprintf()
{
    int8_t  buff[50];
    char toto[10] = "Lapin";
    float   b = 8.987;
    int32_t   c = 988;
    uint16_t    ret;
    
    ret = sprintf(buff, "Bonjour %s je te trouve tres:\n  %f\n%d\n", toto, b, c);
    buff[ret] = 0;
    my_putstr(buff);
}

void    test_scroll_str()
{
    uint8_t time = 1;
    
        wait(time); my_putstr(".\n");
        wait(time); my_putstr("..\n");
        wait(time); my_putstr("...\n");
        wait(time); my_putstr("....\n");
        wait(time); my_putstr("...\n");
        wait(time); my_putstr("..\n");
        wait(time); my_putstr(".\n");
        wait(time); my_putstr("\n");


}

void    test_scrol_nbr()
{
    float       i;
    float       f;
    float       r;
    int8_t      buff[16];

    sprintf(buff, "42");
    my_putstr(buff);
}

void    rambow_led(void)
{
    uint8_t time = 10;
        
    wait(time); LED1 = 1;
    wait(time); LED1 = 0;
    wait(time); LED2 = 1;
    wait(time); LED2 = 0;
    wait(time); LED3 = 1;
    wait(time); LED3 = 0;
}

int main()
{
    init_led();
    init_i2c_5();
    
 //   init_oled();
  //  init_but_int();
    init_mini_caps();    
    oledInitialize();

    TRISBbits.TRISB12 = 1;
    TRISBbits.TRISB13 = 1;
    TRISBbits.TRISB14 = 1;

    while (42)
    {
        LED1 = PORTBbits.RB12;
        LED2 = PORTBbits.RB13;
        LED3 = PORTBbits.RB14;
        /*
        if (PORTBbits.RB13 == 1)
        {
           //rambow_led();
           //test_scroll_str();
        }
         * */
    }
//    DBINIT();
  //  DBPRINTF("test\n");
    //my_putstr("Aujourd'hui\nle  grand Karim\n ne  sait plus perdre\n a street fighter\n      !!!!   ");
   
    while (1)
    {
        //tick_tick();
    }
    
    return (0);
}
