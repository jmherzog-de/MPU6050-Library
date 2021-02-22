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
 *  \file mpu6050_gyroscopeConfiguration.c
 *  \brief Gyroscope Configuration
 *  
 *  This register is used to trigger gyroscope self-test and configure the gyroscopes’ full scale range.
 *  
 *  Gyroscope self-test permits users to test the mechanical and electrical portions of the gyroscope. 
 *  The self-test for each gyroscope axis can be activated by controlling the XG_ST, YG_ST, and ZG_ST 
 *  bits of this register. Self-test for each axis may be performed independently or all at the same time.
 *  
 *  When self-test is activated, the on-board electronics will actuate the appropriate sensor. 
 *  This actuation will move the sensor’s proof masses over a distance equivalent to a pre-defined Coriolis force. 
 *  This proof mass displacement results in a change in the sensor output, which is reflected in the output signal. 
 *  The output signal is used to observe the self-test response.
 *  
 *  The self-test response is defined as follows:
 *  
 *  Self-test response = Sensor output with self-test enabled - Sensor output without self-test enabled
 *  
 *  The self-test limits for each gyroscope axis is provided in the electrical characteristics tables of 
 *  the MPU6050 Product Specification document. When the value of the self-test response is within the 
 *  min/max limits of the product specification, the part has passed self test. When the self-test 
 *  response exceeds the min/max values specified in the document, the part is deemed to have failed 
 *  self-test.
 *  
 *  FS_SEL selects the full scale range of the gyroscope outputs according to the following table.
 *  
 *  | FS_SEL | Full Scale Range |
 *	|:------:|:----------------:|
 *	|   0    |    +/- 250 °/s   |
 *	|   1    |    +/- 500 °/s   |
 *	|   2    |    +/- 1000 °/s  |
 *	|   3    |    +/- 2000 °/s  |
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"
#include "mpu6050_gyroscopeConfiguration.h"

/**
 *  \brief Read Gyroscope Configuration register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.4 for more details.
 */
void mpu6050_gyroConfigReadReg(tMPU6050_GYRO_CONFIG *obj)
{
    uint8_t reg = i2c_receive(MPU6050_I2C_ADDR, MPU6050_GYRO_CONFIG);
    obj->XG_ST = reg >> 7;
    obj->YG_ST = (reg >> 6) & 0x01;
    obj->ZG_ST = (reg >> 5) & 0x01;
    obj->FS_SEL = (reg >> 3) & 0x03;
}

/**
 *  \brief Write to Gyroscope Configuration register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.4 for more details.
 */
void mpu6050_gyroConfigWriteReg(tMPU6050_GYRO_CONFIG *obj)
{
    uint8_t reg = (uint8_t)(obj->XG_ST) << 7 | (uint8_t)(obj->YG_ST) << 6 | (uint8_t)(obj->ZG_ST) << 5 | (uint8_t)(obj->FS_SEL) << 3;
    i2c_write(MPU6050_I2C_ADDR, MPU6050_GYRO_CONFIG, reg);
}