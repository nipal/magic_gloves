/* 
 * File:   mpu_i2c.h
 * Author: lapin
 *
 * Created on June 6, 2017, 3:25 PM
 */

#ifndef MPU_I2C_H
#define	MPU_I2C_H

////////////////
#include "oled.h"
#include <stdint.h>
////////////////

#include <xc.h>

#define SMPRT_DIV	0x19
#define MPU_CONFIG	0x1A
#define GYRO_CONFIG	0x1B
#define ACCEL_CONFIG	0x1C
#define USER_CTRL	0x6A
#define FIFO_EN		0x23
#define PWR_MGMT_1	0x6B
#define FIFO_COUNT	0x72
#define FIFO_R_W	0x74

#define GYRO_FS_250	0b00000000
#define GYRO_FS_500	0b00001000
#define GYRO_FS_1000	0b00010000
#define GYRO_FS_2000	0b00011000

#define ACCEL_FS_2	0b00000000
#define ACCEL_FS_4	0b00001000
#define ACCEL_FS_8	0b00010000
#define ACCEL_FS_16	0000011000

#define SAMPLE_RATE_DIVIDER	79

typedef struct			s_mpu_sample
{
	signed short		accel_x;
	signed short		accel_y;
	signed short		accel_z;
	signed short		temp;
	signed short		gyro_x;
	signed short		gyro_y;
	signed short		gyro_z;
}				t_mpu_sample;

#define MPU_DATA_SIZE (sizeof(t_mpu_sample))

unsigned short	init_mpus();
unsigned char	read_mpu_samples(t_mpu_sample *mpu_sample);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* MPU_I2C_H */

