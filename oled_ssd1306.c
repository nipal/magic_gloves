
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include <stdint.h>
#include <stdbool.h>
#include <xc.h>
#include "oled.h"
//#include "driver/i2c/drv_i2c_static.h"
//#include "oled.h"




/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

//uint8_t oledBuffer[OLED_SIZE];


uint8_t oledBuffer[OLED_SIZE];

uint8_t    buff_is_empty()
{
    uint16_t    i;
    
    i = 0;
    while (i < OLED_SIZE)
    {
        if (oledBuffer[i] != 0)
            return (0);
        i++;
    }
    return (1);
}

void	wait(uint32_t wait)
{
	uint32_t	i;

	for (i = 0; i < wait * 8000; ++i)
        ;
}

void    init_i2c_5(void)
{
    I2C5CON = 0;
    I2C5BRG = 0x09;     // 400 khz
    I2C5CONbits.ON = 1;
    wait(10);
}
    
static inline	uint8_t	i2c5_write_byte(const uint8_t byte)
{
    
  //  while (I2C4STATbits.TBF);
    
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


static inline void _i2cWrite(uint8_t reg, uint8_t *data, uint32_t size)
{
    uint32_t i;
    
    i = 0;
	I2C5CONbits.SEN = 1;		// Envoi du Start bit
	while (I2C5CONbits.SEN);	// Attente que le start bit soit bien envoye
	if (!i2c5_write_byte((OLED_ADDRESS << 1)) + 0)	// Adresse + mode_cmd + Write
		;
	if (!i2c5_write_byte(reg))	// Adresse + mode_cmd + Write
		;
    for (i = 0; i < size && i2c5_write_byte(data[i]); i++);

    /* Send STOP */
	I2C5CONbits.PEN = 1;
	while (I2C5CONbits.PEN);
}

static  inline void _sendCommand(uint8_t *data, uint32_t size)
{
    _i2cWrite(0x00, data, size);
}

static  inline void _sendData(uint8_t *data, uint32_t size)
{
    _i2cWrite(0x40, data, size);
}

static  inline void _set_display_on_off(bool state) {
    uint8_t command[1] = { 0xae | (uint8_t)state };
    _sendCommand(command, sizeof(command));
}

static  inline void _set_multiplex_ratio(uint8_t ratio) {
    uint8_t command[2] = { 0xa8, ratio };
    _sendCommand(command, sizeof(command));
}

static  inline void _set_display_offset(uint8_t offset)
{
    uint8_t command[2] = { 0xd3, offset };
    _sendCommand(command, sizeof(command));
}

static  inline void _set_display_start_line(uint8_t line)
{
    uint8_t command[1] = { 0x40 | line };
    _sendCommand(command, sizeof(command));
}

static  inline void _set_segment_remap(uint8_t remap)
{
    uint8_t command[1] = { 0xa0 | remap };
    _sendCommand(command, sizeof(command));
}

static  inline void _set_com_scan_direction(uint8_t dir)
{
    uint8_t command[1] = { 0xc0 | dir << 3 };
    _sendCommand(command, sizeof(command));
}

static  inline void _set_com_pins_configuration(uint8_t conf, uint8_t remap)
{
    uint8_t command[2] = { 0xda, 0x02 | (conf << 4) | (remap << 5) };
    _sendCommand(command, sizeof(command));
}

static  inline void _set_contrast_control(uint8_t contrast)
{
    uint8_t command[2] = { 0x81, contrast };
    _sendCommand(command, sizeof(command));
}


static  inline void _entire_display_on(uint8_t status)
{
    uint8_t command[1] = { 0xa4 | status };
    _sendCommand(command, sizeof(command));
}

static  inline void _set_inverse_display(uint8_t inverse)
{
    uint8_t command[1] = { 0xa6 | inverse };
    _sendCommand(command, sizeof(command));
}

static  inline void _set_display_clock(uint8_t divider, uint8_t freq)
{
    uint8_t command[2] = { 0xd5, (freq << 4 | divider) };
    _sendCommand(command, sizeof(command));
}

static  inline void _charge_pump_settings(uint8_t on)
{
    uint8_t command[2] = { 0x8d, 0x10 | (on << 2) };
    _sendCommand(command, sizeof(command));
}

static  inline void _set_memory_addressing_mode(uint8_t mode) {
    uint8_t command[2] = { 0x20, mode };
    _sendCommand(command, sizeof(command));
}

static  inline void _set_column_address(uint8_t start, uint8_t end)
{
    uint8_t command[3] = { 0x21, start, end };
    _sendCommand(command, sizeof(command));
}

static  inline void _set_page_address(uint8_t start, uint8_t end)
{
    uint8_t command[3] = { 0x22, start, end };
    _sendCommand(command, sizeof(command));
}

static inline void _swap(uint8_t *a, uint8_t *b) {
    uint8_t x;
    x = *a;
    *a = *b;
    *b = x;
}

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

// *****************************************************************************

/** 
  @Function
    int ExampleInterfaceFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Remarks
    Refer to the example_file.h interface header for function usage details.
 */
void oledInitialize(void)
{    
   TRISFbits.TRISF1 = 0;//    BSP_LCDTurnOn();
   LATFbits.LATF1 = 1;
   
   wait(10); 
    /* Send initialization */
    _set_display_on_off(false);
    _set_multiplex_ratio(63);
    _set_display_offset(0);
    _set_display_start_line(0);
    
    _set_segment_remap(1);
        
    _set_com_pins_configuration(1, 0);
    _set_com_scan_direction(1);
    
    _set_contrast_control(0x7f);
    _entire_display_on(0);
    _set_inverse_display(0);
    _set_display_clock(0, 15);
    _charge_pump_settings(1);
    _set_display_on_off(true);
    
    _set_memory_addressing_mode(0);
    _set_column_address(0, 127);
    _set_page_address(0, 7);
    
    /* Clear display */
    oledClear();
    oledUpdate();
}

void oledUpdate(void)
{
    _sendData(oledBuffer, OLED_SIZE);
//    _entire_display_on(0);
}

void send_oled_data(uint8_t *data, uint16_t size)
{
    _sendData(data ,size);
}

void oledClear(void)
{
    uint32_t    i;
    
    for (i = 0; i < OLED_SIZE; i++)
        oledBuffer[i] = 0;
}

void oledDrawPixel(uint8_t x, uint8_t y)
{

    if(x < WIDTH && y < HEIGHT)
        oledBuffer[ y/8 * 128 + x] |= 1 << (y % 8 );
}


void oledDrawVLine(uint8_t x)
{
    uint8_t i;
    for(i = 0; i < HEIGHT; i++) {
        oledDrawPixel(x, i);
    }
}

void oledDrawHLine(uint8_t y)
{
    uint8_t i;
    for(i = 0; i < WIDTH; i++) {
        oledDrawPixel(i, y);
    }
}
/* *****************************************************************************
 End of File
 */
