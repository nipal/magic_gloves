#include <xc.h>
#include <stdint.h>


//c'est le spi de la carte sd
void    init_spi2()
{
    uint32_t rData;
    
     // on desactive les interuption du spi2
    IEC4bits.SPI2EIE = 0;
    IEC4bits.SPI2RXIE = 0;
    IEC4bits.SPI2TXIE = 0;
    
    SPI2CON = 0; // Stops and resets the SPI2.
    rData=SPI2BUF; // clears the receive buffer
    
    // on reset les fla d'interuption
    IFS4bits.SPI2EIF = 0; 
    IFS4bits.SPI2RXIF = 0;
    IFS4bits.SPI2TXIF = 0;

    SPI2BRG=0x1; // use FPB/4 clock frequency
    SPI2STATCLR = (1 << 6); // lefla d'overflow des buffer qui declanche les interuption d'ereur
    SPI2CON=0x8220; // SPI ON, 8 bits transfer, SMP=1, Master mode
    // from now on, the device is ready to transmit and receive data
//    SPI2BUF='A'; // transmit an A character
  
}

uint32_t    read_spi()
{
    
}

// il faudra probablement revoir quelque etape je ne suis pas sur de tout
uint8_t    transmit_spi2(uint8_t data)
{
    uint8_t recive;

    while (SPI2STATbits.SPIBUSY);
    SPI2BUF = data;// on transmet
    while (SPI2STATbits.SPITBF);// tan que on a pas fini de transmetre de spi2buff aux reistre d'echange
    recive = SPI2BUF;// on est aublier de lire pour ps avoir d'overflow 
    return (recive);
}

void    init_sd_card()
{
    uint8_t i;
    
    SPI2CONbits.SSEN = 1; // on active le slave select
    // pour passer en mode sd il faut avoir au moins 76 coup de clock avec SS=1 et MOSI=1
    for (i = 0; i < 10; ++i) 
        transmit_spi2(0xFF);// on ne transmet que des 1
   // on passe en mode sd (il y a plusieur rotocole possible)
   // on fait un reset si besoin
   // on fait des baille
}

uint8_t    send_sd_cmd(uint8_t cmd, uint32_t arg, uint8_t crc)
{
    
}


/*
void __ISR(, ipl3)__SPI1Interrupt(void)
{
    int Data; // Read SPI data buffer
    Data = SPI1BUF;
    // ... perform application specific operations in response to the
    // interrupt
    IFS0CLR = 0x03800000; // Be sure to clear the SPI1 interrupt flags
    // before exiting the service routine.
}
*/
//*/