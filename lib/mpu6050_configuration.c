/*
 * This file is part of the MPU6050-Library distribution (https://github.com/jmherzog-de/MPU6050-Library).
 * Copyright (c) 2021 Jean-Marcel Herzog.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/**
 *  \file mpu6050_configuration.c
 *  \brief Configuration
 *  
 *  This register configures the external Frame Synchronization (FSYNC) pin sampling
 *  and the Digital Low Pass Filter (DLPF) setting for gyroscopes and accelerometers.
 *  
 *  An external signal connected to the FSYNC pin can be sampled by configuring
 *  EXT_SYNC_SET.
 *  
 *  Signal changes to the FSYNC pin are latched so that short strobes my be captured.
 *  The latched FSYNC signal will be sampled at the Sampling Rate, as defined in
 *  register 25. After sampling, the latch will reset to the current FSYNC signal state.
 *  
 *  The sampled value will be reported in place of the least significant bit in a sensor
 *  data register determined by the value of EXT_SYNC_SET according to the following table:
 *  
 *  | EXT_SYNC_SET  | FSYNC Bit Location	|
 *	|:-------------:|:---------------------:|
 *	|		0		|	Input disabled		|
 *	| 		1		|	TEMP_OUT_L[0]		|
 *	| 		2  		|   GYRO_XOUT_L[0]		|
 *	| 		3  		|   GYRO_YOUT_L[0]		|
 *	| 		4  		|   GYRO_ZOUT_L[0]		|
 *	| 		5  		|   ACCEL_XOUT_L[0]		|
 *	| 		6  		|   ACCEL_YOUT_L[0]		|
 *	| 		7  		|   ACCEL_ZOUT_L[0]		|
 *
 * The DLPF is configured by DLPF_CFG. The accelerometer and gyroscope are filtered according
 * to the value of DLPF_CFG as shown in the table below. The accelerometer Fs= 1kHz.
 *
 *	|	DLPF_CFG	|	Acc. Bandwidth (Hz)	|	Acc. Delay (ms)	|	Gyro. Bandwidth (Hz)	|	Gyro. Delay (ms)	|	Gyro. Fs (kHz)	|
 *	|:-------------:|:---------------------:|:----------------:|:--------------------------:|:---------------------:|:-----------------:|		
 *	|		0  		|			260			|		0			|			260				|		0.98			|			8		|
 *	|		1  		|			184			|		0			|			260				|		0.98			|			1		|
 *	|		2  		|			94			|		0			|			260				|		0.98			|			1		|
 *	|		3  		|			44			|		0			|			260				|		0.98			|			1		|
 *	|		4  		|			21			|		0			|			260				|		0.98			|			1		|
 *	|		5  		|			10			|		0			|			260				|		0.98			|			1		|
 *	|		6  		|			5			|		0			|			260				|		0.98			|			1		|
 *	|		7  		|		RESERVED		|	RESERVED		|		RESERVED			|		RESERVED		|			8		|
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"
#include "mpu6050_configuration.h"

/**
 *  \brief Read Configuration register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *   
 *  \details See register datasheet chapter 4.3 for more details.
 */
void mpu6050_configRegRead(tMPU6050_CONFIG *obj)
{
    uint8_t reg = i2c_receive(MPU6050_I2C_ADDR, MPU6050_CONFIG);
    obj->DLPF_CFG = reg & 0x07;
    obj->EXT_SYNC_SET = reg >> 3;
}

/**
 *  \brief Write Configuration register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  \return Return description
 *  
 *  \details See register datasheet chapter 4.3 for more details.
 */
void mpu6050_configRegWrite(tMPU6050_CONFIG *obj)
{
    uint8_t reg = (uint8_t)(obj->EXT_SYNC_SET) << 3 | (uint8_t)(obj->DLPF_CFG);
    i2c_write(MPU6050_I2C_ADDR, MPU6050_CONFIG, reg);
}