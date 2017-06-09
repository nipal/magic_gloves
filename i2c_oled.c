#include "oled.h"




// 128 * 64 = (8*128) * 8

//uint8_t oled[OLED_SIZE];

/*
void    init_i2c_5(void)
{
    I2C5CON = 0;
    I2C5BRG = 0x09;     // 400 khz
    I2C5CONbits.ON = 1;
}
*/

/*
static inline uint8_t     i2c5_tr_one(const uint8_t data)
{
    I2C5TRN = data;
   while (I2C5STATbits.TRSTAT)
       LED1 = 1;
    if (I2C5STATbits.ACKSTAT)
        LED1 = 1;
    return (~I2C5STATbits.ACKSTAT);
}

uint8_t    oled_i2c_tr(const uint8_t *data, const uint16_t nb)
{
    // on ecrit
    //tant qu'il n'est pas libre
    //tant qu'il n'a pas ack
    uint16_t    i;
    
    I2C5CONbits.SEN = 1;
    while (I2C5CONbits.SEN);
    i = 0;
    while (i < nb && i2c5_tr_one(data[i]))
        i++;
    I2C5CONbits.PEN = 1;
    while (I2C5CONbits.PEN);
}

void    oled_test(void)
{
    uint8_t data[3];
    
    data[0] = OLED_CMD_W;
    data[1] = OLED_ON;
    oled_i2c_tr(data, 2);
    
    data[1] = OLED_ALL_ON;
    oled_i2c_tr(data, 2);
}

*/
/*
static inline	uint8_t	i2c5_send_byte(const uint8_t byte)
{
	I2C5TRN = byte;             // Byte a transmettre
	while (I2C5STATbits.TRSTAT)
        ;
	if (I2C5STATbits.ACKSTAT)	// Si sans reponse du MPU
	{
        LED3 = 1;               // on active la led d'erreur
		I2C5CONbits.PEN = 1;	// STOP
		while (I2C5CONbits.PEN);
		return (0);             // ECHEC
	}
	return (1);
}

uint8_t	oled_send_cmd(const uint8_t reg, const uint8_t * const data, const uint8_t size)
{
    uint8_t i;
    
    i = 0;
	I2C5CONbits.SEN = 1;		// Envoi du Start bit
	while (I2C5CONbits.SEN);	// Attente que le start bit soit bien envoye
	if (!i2c5_send_byte(OLED_RAM_R))	// Adresse + mode_cmd + Write
		return (0);
	if (!i2c5_send_byte(reg))	// Adresse + mode_cmd + Write
		return (0);
	for (i = 0; i < size && i2c5_send_byte(data[i]); i++);
	I2C5CONbits.PEN = 1;		// Envoi du stop bit
	while (I2C5CONbits.PEN);
}
*/

void	wait(uint32_t wait)
{
	uint32_t	i;

	for (i = 0; i < wait * 8000; i++);
}

void    init_oled()
{
//    uint16_t    i;
    uint8_t     tram[10];
    
    //  on allume l'i2c
  //  LED2 = PORTFbits.RF1;
    //TRISFbits.TRISF1 = 0;
    //LATFbits.LATF1 = 1;     // pour alumer le lcd
    
    init_i2c_5();
    wait(10);						/* on attend au cas ou*/
    
    /*
    tram[0] = 0xAE;                 // display off
    oled_send_cmd(tram, 1);			//	on envoie la tram
    wait(10);
    
    
    tram[0] = 0xAF;                 // display on
    oled_send_cmd(tram, 1);
    wait(10);
    
    tram[0] = 0xA7;                 // set inv diplay
    oled_send_cmd(tram, 1);
 //   wait(10);
    
    tram[0] = 0x0;                  // le contraste
    
    tram[0] = 0xA5;                 // diisplay the ram
    oled_send_cmd(tram, 1);
    */
 //   wait(10);
}


/*
static unsigned char	i2c1_receive(unsigned short address, unsigned short reg,ss
	void *data, unsigned short size)
{
	I2C1CONbits.SEN = 1;		// Envoi du Start bit
	while (I2C1CONbits.SEN);	// Attente que le start bit soit bien envoye
    wait(5);					    // on attend au cas ou
    tram[0] = 0xA5;
    oled_send_cmd(tram, 1);
}
/*
static unsigned char	i2c1_receive(unsigned short address, unsigned short reg,ss
	void *data, unsigned short size)
{
	I2C1CONbits.SEN = 1;		// Envoi du Start bit
	while (I2C1CONbits.SEN);	// Attente que le start bit soit bien envoye
	if (!i2c1_send_byte((address << 1) + 0))	// Adresse + Write
		return (0);
	if (!i2c1_send_byte(reg))	// Registre
		return (0);
	I2C1CONbits.RSEN = 1;		// Envoi du Repeated Start bit
	while (I2C1CONbits.RSEN);
	if (!i2c1_send_byte((address << 0) + 1))	// Adresse + Read
		return (0);
	while (size--) 			// Read tant qu'on a pas atteint size octets
	{
		I2C1CONbits.RCEN = 1;		// Pret a recevoir
		while (!I2C1STATbits.RBF);	// Tant que Receive Buffer non Full
		*((unsigned char *)data++) = (unsigned char)I2C1RCV; // On stock le byte
		I2C1CONbits.ACKDT = !size;	// On envoit ACK si il en reste a lire
		I2C1CONbits.ACKEN = 1;		// Envoi du ACK / NACK
		while (I2C1CONbits.ACKEN);
	}
	I2C1CONbits.PEN = 1;		// Envoi du stop bit
	while (I2C1CONbits.PEN);
	return 1;
}
*/
