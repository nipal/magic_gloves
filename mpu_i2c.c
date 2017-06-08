#include "mpu_i2c.h"



static unsigned char	i2c1_send_byte(unsigned char byte)
{
	I2C1TRN = byte;			// Byte a transmettre
	while (I2C1STATbits.TRSTAT);
	if (I2C1STATbits.ACKSTAT)	// Si sans reponse du MPU
	{
		I2C1CONbits.PEN = 1;	// STOP
		while (I2C1CONbits.PEN);
		return (0);		// ECHEC
	}
	return (1);
}

static unsigned char	i2c3_send_byte(unsigned char byte)
{
	I2C3TRN = byte;			// Byte a transmettre
	while (I2C3STATbits.TRSTAT);
	if (I2C3STATbits.ACKSTAT)	// Si sans reponse du MPU
	{
		I2C3CONbits.PEN = 1;	// STOP
		while (I2C3CONbits.PEN);
		return (0);		// ECHEC
	}
	return (1);
}

static unsigned char	i2c4_send_byte(unsigned char byte)
{
	I2C4TRN = byte;			// Byte a transmettre
	while (I2C4STATbits.TRSTAT);
	if (I2C4STATbits.ACKSTAT)	// Si sans reponse du MPU
	{
		I2C4CONbits.PEN = 1;	// STOP
		while (I2C4CONbits.PEN);
		return (0);		// ECHEC
	}
	return (1);
}

static unsigned short	send(unsigned short mpu, unsigned short reg,
	unsigned short data)
{
	unsigned short address;

	address = 0b1101000 + mpu % 2;	// 2 mpus par i2c
	if (mpu < 2)
	{
		I2C1CONbits.SEN = 1;		// Envoi du Start bit
		while (I2C1CONbits.SEN);	// Attente que le start bit soit bien envoye
		if (!i2c1_send_byte((address << 1) + 0))	// Adresse + Write
			return (0);
		if (!i2c1_send_byte(reg))	// Registre
			return (0);
		if (!i2c1_send_byte(data))	// Data
			return (0);
		I2C1CONbits.PEN = 1;		// Envoi du stop bit
		while (I2C1CONbits.PEN);
	}
	else if (mpu < 4)
	{
		I2C3CONbits.SEN = 1;		// Envoi du Start bit
		while (I2C3CONbits.SEN);	// Attente que le start bit soit bien envoye
		if (!i2c3_send_byte((address << 1) + 0))	// Adresse + Write
			return (0);
		if (!i2c3_send_byte(reg))	// Registre
			return (0);
		if (!i2c3_send_byte(data))	// Data
			return (0);
		I2C3CONbits.PEN = 1;		// Envoi du stop bit
		while (I2C3CONbits.PEN);
	}
	else
	{
		I2C4CONbits.SEN = 1;		// Envoi du Start bit
		while (I2C4CONbits.SEN);	// Attente que le start bit soit bien envoye
		if (!i2c4_send_byte((address << 1) + 0))	// Adresse + Write
			return (0);
		if (!i2c4_send_byte(reg))	// Registre
			return (0);
		if (!i2c4_send_byte(data))	// Data
			return (0);
		I2C4CONbits.PEN = 1;		// Envoi du stop bit
		while (I2C4CONbits.PEN);
	}
	return 1;
}

static unsigned char	i2c1_receive(unsigned short address, unsigned short reg,
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

static unsigned char	i2c3_receive(unsigned short address, unsigned short reg,
	void *data, unsigned short size)
{
	I2C3CONbits.SEN = 1;		// Envoi du Start bit
	while (I2C3CONbits.SEN);	// Attente que le start bit soit bien envoye
	if (!i2c3_send_byte((address << 1) + 0))	// Adresse + Write
		return (0);
	if (!i2c3_send_byte(reg))	// Registre
		return (0);
	I2C3CONbits.RSEN = 1;		// Envoi du Repeated Start bit
	while (I2C3CONbits.RSEN);
	if (!i2c3_send_byte((address << 0) + 1))	// Adresse + Read
		return (0);
	while (size--) 			// Read tant qu'on a pas atteint size octets
	{
		I2C3CONbits.RCEN = 1;		// Pret a recevoir
		while (!I2C3STATbits.RBF);	// Tant que Receive Buffer non Full
		*((unsigned char *)data++) = (unsigned char)I2C3RCV; // On stock le byte
		I2C3CONbits.ACKDT = !size;	// On envoit ACK si il en reste a lire
		I2C3CONbits.ACKEN = 1;		// Envoi du ACK / NACK
		while (I2C3CONbits.ACKEN);
	}
	I2C3CONbits.PEN = 1;		// Envoi du stop bit
	while (I2C3CONbits.PEN);
	return 1;
}

static unsigned char	i2c4_receive(unsigned short address, unsigned short reg,
	void *data, unsigned short size)
{
	I2C4CONbits.SEN = 1;		// Envoi du Start bit
	while (I2C4CONbits.SEN);	// Attente que le start bit soit bien envoye
	if (!i2c4_send_byte((address << 1) + 0))	// Adresse + Write
		return (0);
	if (!i2c4_send_byte(reg))	// Registre
		return (0);
	I2C4CONbits.RSEN = 1;		// Envoi du Repeated Start bit
	while (I2C4CONbits.RSEN);
	if (!i2c4_send_byte((address << 0) + 1))	// Adresse + Read
		return (0);
	while (size--) 			// Read tant qu'on a pas atteint size octets
	{
		I2C4CONbits.RCEN = 1;		// Pret a recevoir
		while (!I2C4STATbits.RBF);	// Tant que Receive Buffer non Full
		*((unsigned char *)data++) = (unsigned char)I2C4RCV; // On stock le byte
		I2C4CONbits.ACKDT = !size;	// On envoit ACK si il en reste a lire
		I2C4CONbits.ACKEN = 1;		// Envoi du ACK / NACK
		while (I2C4CONbits.ACKEN);
	}
	I2C4CONbits.PEN = 1;		// Envoi du stop bit
	while (I2C4CONbits.PEN);
	return 1;
}

static unsigned short	receive(unsigned short mpu, unsigned short reg,
	void *data, unsigned short size)
{
	unsigned short address;

	address = 0b1101000 + mpu % 2;	// 2 mpu par I2C
	if (mpu < 2)
		return i2c1_receive(address, reg, data, size);
	else if (mpu < 4)
		return i2c3_receive(address, reg, data, size);
	else
		return i2c4_receive(address, reg, data, size);
}

static unsigned short	init_i2c()
{
	I2C1BRG = 0x037;	// 400Khz pour une PBCLK de 50Mhz
	I2C1CONbits.ON = 1;	// Activation du module I2C
	I2C4BRG = 0x037;
	I2C4CONbits.ON = 1;
	I2C3BRG = 0x037;
	I2C3CONbits.ON = 1;
}

unsigned short	init_mpus()
{
	unsigned short	mpu;

    init_i2c();
	mpu = 0;
    while (++mpu < 10000); // just au cas ou...
	mpu = (unsigned short)-1;
	while (++mpu < 6)
	{
		send(mpu, SMPRT_DIV, SAMPLE_RATE_DIVIDER);
		send(mpu, MPU_CONFIG, 0b00000000);	// Pas de sync externe ni de DLPF
		send(mpu, GYRO_CONFIG, GYRO_FS_250);	// Gyroscope en mode full scale +/-250deg
		send(mpu, ACCEL_CONFIG, ACCEL_FS_2);	// Accelerometre en mode full scale +/-2g
		send(mpu, USER_CTRL, 0b01000101);	// FIFO enable, FIFO reset, Sensor reset
		send(mpu, FIFO_EN, 0b11111000);		// FIFO composition : accel, gyro, temperature
	}
	mpu = (unsigned short)-1;
	while (++mpu < 6)
		send(mpu, PWR_MGMT_1, 0b00000000); // On vire le sleep mode
	return 0;
}

unsigned char	read_mpu_samples(t_mpu_sample *mpu_sample)
{
	unsigned short	size;
	unsigned short	mpu;

	mpu = (unsigned short)-1;
	while (++mpu < 6)
		if (!receive(mpu, FIFO_COUNT, &size, 2) || MPU_DATA_SIZE != size)
			return (0);
	mpu = (unsigned short)-1;
	while (++mpu < 6)
		if (!receive(mpu, FIFO_R_W, &mpu_sample[mpu], MPU_DATA_SIZE))
			return 0;
	return (1);
}