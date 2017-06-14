#include "button.h"
#include <xc.h>
#include <sys/attribs.h>

uint16_t    rb_prev;

void	init_timer_2(int periode, char diviseur, char sub_priorite)
{

     ////  initilaisation pour l'animaiton sur le pwm /////
    T2CONbits.ON = 0b0;		// desactivaiton du timer pour le configurer
    TMR2 = 0x0;
    PR2 = periode;      //  la periode du truc il faudra qu'il y ai 100 transche en 5 seconde donc 2 par seconde donc voila
    T2CONbits.TCKPS = diviseur;	// diviseur de clock
    // PRIORITE
    IPC2bits.T2IP = 1;// parceque ipl1 il est chiant a changer  //0b111 & priorite;	// ac
    IPC2bits.T2IS = 0b11 & sub_priorite;

    IEC0bits.T2IE = 0b1;	// activation de l'interupion
    IFS0bits.T2IF = 0b0;	// reset du flag d'interruption
    T2CONbits.ON = 0b1;         // remise en marche du timer

}

void    init_but_int()
{
    init_timer_2(100, 10, 0);
    TRISBbits.TRISB11 = 1;
    TRISBbits.TRISB12 = 1;
    TRISBbits.TRISB13 = 1;
    rb_prev = 0b111 & (PORTB >> 10);
}

void    but1()
{
    LED1 = 1;
    offset_screen++;
    if (offset_screen >= offset_screen_max)
        offset_screen = offset_screen -1;
    print_screen();
}

void    but2()
{
    LED2 = 1;
    offset_screen = 0;
    print_screen();
}

void    but3()
{
    LED3 = 1;
    offset_screen--;
    if (offset_screen <= 0)
        offset_screen = 0;
    print_screen();
}

void __ISR(_TIMER_2_VECTOR, IPL1) interrupt_timer_4(void)
{
    uint16_t    rb;
    uint16_t    diff;
    
    rb = (PORTB >> 10) & 0b111;
    if (rb != rb_prev)
    {
        my_putstr("ouiii\n");
        diff = rb ^ rb_prev;
        if ((diff & 1))
            but1();
        else if ((diff & 1 << 1))
            but2();
        else if ((diff & 1 << 2))
            but3();
        rb_prev = rb;
    }
    if (PORTBbits.RB12)
    IFS0bits.T2IF = 0b0;	// reset du flag d'interruption
}
/*
__ISR() youpi()
{
    
}

*/


/*
void    test()
{
    uint8_t i;
    
    TRISBbits.TRISB12 = 1;
    TRISBbits.TRISB13 = 1;
    TRISBbits.TRISB14 = 1;
    
    TRISBbits.TRISB8 = 0;
    TRISBbits.TRISB9 = 0;
    TRISBbits.TRISB10 = 0;
    
    tick_begin(3);
   
//    aff_port();
//    return ;
    
    
    //
    LED3 = 1;
 //   LED3 = 0;
    for (i = 0; i >= 0; i++)
    {
        print_16_bin(PORTB);
        print_16_bin(LATB);
        print_16_bin(TRISB);
    }
}


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

*/