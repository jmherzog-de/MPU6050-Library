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
 *  \file mpu6050_accelerometerConfiguration.c
 *  \brief Accelerometer Configuration
 *  
 *  This register is used to trigger accelerometer self test and configure the
 *  accelerometer full scale range. This register also configures
 *  the Digital High Pass Filter (DHPF).
 *  
 *  Accelerometer self-test permits users to test the mechanical and electrical
 *  portions of the accelerometer. The self-test for each accelerometer axis can
 *  be activated by controlling the XA_ST, YA_ST and ZA_ST bits of the register.
 *  Self-test for each axis may be performed independently or all at the same time.
 *  
 *  When self-test is activated, the on-board electronics will actuate the appropriate sensor.
 *  This actuation simulates an external force. The actuated sensor, in turn, will produce
 *  a corresponding output signal. The output signal is used to observe the self-test response.
 *  
 *  The self-test response is defined as follows:
 *  Self-test response = Sensor output with self-test enabled - Sensor output without self-test enabled
 *  
 *  The self-test limits for each accelerometer axis is provided in the electrical characteristics tables
 *  of the MPU6050 Product Specification document. When the value of the self-test response is within
 *  the min/max limits of the product specification, the part has passed self test. When the self-test
 *  response exceeds the min/max values specified in the document, the part is deemed to have failed self-test.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include "mpu6050_accelerometerConfiguration.h"

/**
 *  \brief Read Acceleration Configuration
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.5 for more details
 */
void mpu6050_accelConfigReadReg(tMPU6050_ACCEL_CONFIG *obj)
{
    uint8_t reg = i2c_receive(MPU6050_I2C_ADDR, MPU6050_ACCEL_CONFIG);
    obj->XA_ST = (reg & 0x80) >> 7;
    obj->YA_ST = (reg & 0x40) >> 6;
    obj->ZA_ST = (reg & 0x10) >> 5;
    obj->AFS_SEL = (reg & 0x18 ) >> 3;
}

/**
 *  \brief Write Acceleration Configuration
 *  
 *  \param [in] obj Datatype pointer to write register values
 *  
 *  \details See register datasheet chapter 4.5 for more details
 */
void mpu6050_accelConfigWriteReg(tMPU6050_ACCEL_CONFIG *obj)
{
    uint8_t reg = (uint8_t)(obj->XA_ST) << 7 | (uint8_t)(obj->YA_ST) << 6 | (uint8_t)(obj->ZA_ST) << 5 | (uint8_t)(obj->AFS_SEL) << 3;
    i2c_write(MPU6050_I2C_ADDR, MPU6050_ACCEL_CONFIG, reg);
}