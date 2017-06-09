#include <proc/p32mz2048efh064.h>

#include "button.h"

void    init_but_int()
{
    TRISBbits.TRISB11 = 1;
    TRISBbits.TRISB12 = 1;
    TRISBbits.TRISB13 = 1;
}


__ISR() youpi()
{
    
}

