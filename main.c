// PIC32MZ2048EFH064 Configuration Bit Settings

// 'C' source line config statements

// DEVCFG3
// USERID = No Setting
#pragma config FMIIEN = ON              // Ethernet RMII/MII Enable (MII Enabled)
#pragma config FETHIO = ON              // Ethernet I/O Pin Select (Default Ethernet I/O)
#pragma config PGL1WAY = ON             // Permission Group Lock One Way Configuration (Allow only one reconfiguration)
#pragma config PMDL1WAY = ON            // Peripheral Module Disable Configuration (Allow only one reconfiguration)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow only one reconfiguration)
#pragma config FUSBIDIO = ON            // USB USBID Selection (Controlled by the USB Module)

// DEVCFG2
#pragma config FPLLIDIV = DIV_8         // System PLL Input Divider (8x Divider)
#pragma config FPLLRNG = RANGE_5_10_MHZ // System PLL Input Range (5-10 MHz Input)
#pragma config FPLLICLK = PLL_FRC       // System PLL Input Clock Selection (FRC is input to the System PLL)
#pragma config FPLLMULT = MUL_128       // System PLL Multiplier (PLL Multiply by 128)
#pragma config FPLLODIV = DIV_32        // System PLL Output Clock Divider (32x Divider)
#pragma config UPLLFSEL = FREQ_12MHZ    // USB PLL Input Frequency Selection (USB PLL input is 12 MHz)

// DEVCFG1
#pragma config FNOSC = FRCDIV           // Oscillator Selection Bits (Fast RC Osc w/Div-by-N (FRCDIV))
#pragma config DMTINTV = WIN_127_128    // DMT Count Window Interval (Window/Interval value is 127/128 counter value)
#pragma config FSOSCEN = ON             // Secondary Oscillator Enable (Enable SOSC)
#pragma config IESO = ON                // Internal/External Switch Over (Enabled)
#pragma config POSCMOD = OFF            // Primary Oscillator Configuration (Primary osc disabled)
#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config FCKSM = CSECME           // Clock Switching and Monitor Selection (Clock Switch Enabled, FSCM Enabled)
#pragma config WDTPS = PS1048576        // Watchdog Timer Postscaler (1:1048576)
#pragma config WDTSPGM = STOP           // Watchdog Timer Stop During Flash Programming (WDT stops during Flash programming)
#pragma config WINDIS = NORMAL          // Watchdog Timer Window Mode (Watchdog Timer is in non-Window mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (WDT Disabled)
#pragma config FWDTWINSZ = WINSZ_25     // Watchdog Timer Window Size (Window size is 25%)
#pragma config DMTCNT = DMT31           // Deadman Timer Count Selection (2^31 (2147483648))
#pragma config FDMTEN = OFF             // Deadman Timer Enable (Deadman Timer is disabled)

// DEVCFG0
#pragma config DEBUG = OFF               // Background Debugger Enable (Debugger is enabled)
#pragma config JTAGEN = OFF             // JTAG Enable (JTAG Disabled)
#pragma config ICESEL = ICS_PGx2        // ICE/ICD Comm Channel Select (Communicate on PGEC2/PGED2)
#pragma config TRCEN = ON               // Trace Enable (Trace features in the CPU are enabled)
#pragma config BOOTISA = MIPS32         // Boot ISA Selection (Boot code and Exception code is MIPS32)
#pragma config FECCCON = OFF_UNLOCKED   // Dynamic Flash ECC Configuration (ECC and Dynamic ECC are disabled (ECCCON bits are writable))
#pragma config FSLEEP = OFF             // Flash Sleep Mode (Flash is powered down when the device is in Sleep mode)
#pragma config DBGPER = PG_ALL          // Debug Mode CPU Access Permission (Allow CPU access to all permission regions)
#pragma config SMCLR = MCLR_NORM        // Soft Master Clear Enable bit (MCLR pin generates a normal system Reset)
#pragma config SOSCGAIN = GAIN_2X       // Secondary Oscillator Gain Control bits (2x gain setting)
#pragma config SOSCBOOST = ON           // Secondary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config POSCGAIN = GAIN_1X       // Primary Oscillator Gain Control bits (1x gain setting)
#pragma config POSCBOOST = ON           // Primary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config EJTAGBEN = NORMAL        // EJTAG Boot (Normal EJTAG functionality)

// DEVCP0
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

//#include "prof_concept.h"
#include "oled.h"
#include "mini_caps.h"
#include "mpu_i2c.h"

#include <stdint.h>
#include <stdio.h>
#include <xc.h>

//#include <xc.h>


void    test();

int8_t  txt_karimu[13][32] = {
    {"################"},
    {"Who is it?\n"},
    {"OWW it's the:\n"},
    {" GRAND KARIMU\n\n"},
    {"I'm so proud to\n"},
    {"meet you.\n"},
    {"I heard about\n"},
    {"your wining on:\n"},
    {"################\n"},
    {"Street fighter 5\n"},
    {"################\n"},
    {"Well...\n"},
    {"\n\n\tBY\n\n"}};

void    super_karim()
{
    uint8_t i;
    
    for (i = 0; i < 13; i++)
    {
        my_putstr(txt_karimu[i]);
    }
}  

void    tick_begin(uint8_t nb)
{
    uint8_t i;
    
    LED1 = 0;
    for (i = 0; i < (nb << 1); i++)
    {
        LED1 = !GET_LED1;
        wait(5);
    }
}

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

void    test(void);
void    test_i2c_init();

int    test_i2c4(void)
{
    uint8_t byte = 0b10101010;

    I2C4CONbits.SEN = 1;		// Envoi du Start bit
    while (I2C4CONbits.SEN);
    LED1 = 1;
 //   while (1)// on envoie en boucle
 //   {
        I2C4TRN = byte;			// Byte a transmettre
        while (I2C4STATbits.TRSTAT);
        if (I2C4STATbits.ACKSTAT)	// Si sans reponse du MPU
        {
            LED3 = 1;
            I2C4CONbits.PEN = 1;	// STOP
            while (I2C4CONbits.PEN);
            return (0);		// ECHEC
        }
 //   }
    I2C4CONbits.PEN = 1;		// Envoi du stop bit
    while (I2C4CONbits.PEN);
    LED2 = 1;
}

int main(void)
{
    init_led();
    oledInitialize();
    super_karim();
    
    /*
 //   LED1 = 1;
 //   LED2 = 1;
//  LED3 = 1;
    TRISBbits.TRISB8 = 0;
    TRISBbits.TRISB9 = 0;
    TRISBbits.TRISB10 = 0;
    I2C4CON = 0;
    I2C4BRG = 0x09;     // 400 khz
    I2C4CONbits.ON = 1;
    wait(10);
    
    
   while (1);
    test_i2c4();
   */
   return (0);
}