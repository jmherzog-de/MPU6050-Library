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
 *  \file mpu6050_accelerometerMeasurements.c
 *  \brief Accelerometer Measurements
 *  
 *  These registers store the most recent accelerometer measurements.
 *  
 *  Accelerometer measurements are written to these registers at the
 *  Sample Rate as defined in Register 25.
 *  
 *  The accelerometer measurement registers, along with the temperature
 *  measurement registers, gyroscope measurement registers and external
 *  sensor data registers, are composed of two sets of registers: an
 *  internal register set and a user-facing read register set.
 *  
 *  The data within the accelerometer sensors internal register set is
 *  always updated at the Sample Rate. Meanwhile, the user-facing read
 *  register set duplicates the internal register set's data values
 *  whenever the serial interface is idle. This guarantees that a burst
 *  read of sensor registers will read measurements from the same sampling
 *  instant. Note that if burst reads are not used, the user is responsible
 *  for ensuring a set of single byte reads correspond to a single sampling
 *  instant by checking the Data Ready interrupt.
 *  
 *  Each 16-bit accelerometer measurement has a full scale defined in ACCEL_FS
 *  (Register 28). For each full scale setting, the accelerometer sensitivity
 *  per LSB in ACCEL_xOUT can be found in the register documentation page 29.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include "mpu6050_accelerometerMeasurements.h"

/**
 *  \brief Read X axis accelerometer measurement
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.17 for more details
 */
void mpu6050_accelXoutReadReg(tMPU6050_ACCEL_XOUT *obj)
{
    uint16_t high = (uint8_t)i2c_receive(MPU6050_I2C_ADDR, MPU6050_ACCEL_XOUT_H);
    uint16_t low = (uint8_t)i2c_receive(MPU6050_I2C_ADDR, MPU6050_ACCEL_XOUT_L);
    *obj = (high << 8) | low;
}

/**
 *  \brief Write Y axis accelerometer measurement
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.17 for more details
 */
void mpu6050_accelYoutReadReg(tMPU6050_ACCEL_YOUT *obj)
{
    uint16_t high = (uint8_t)i2c_receive(MPU6050_I2C_ADDR, MPU6050_ACCEL_YOUT_H);
    uint16_t low = (uint8_t)i2c_receive(MPU6050_I2C_ADDR, MPU6050_ACCEL_YOUT_L);
    *obj = (high << 8) | low;
}

/**
 *  \brief Read Z axis accelerometer measurement
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.17 for more details
 */
void mpu6050_accelZoutReadReg(tMPU6050_ACCEL_ZOUT *obj)
{
    uint16_t high = (uint8_t)i2c_receive(MPU6050_I2C_ADDR, MPU6050_ACCEL_ZOUT_H);
    uint16_t low = (uint8_t)i2c_receive(MPU6050_I2C_ADDR, MPU6050_ACCEL_ZOUT_L);
    *obj = (high << 8) | low;
}

/**
 *  \brief Read all axis accelerometer measurement
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details Read x,y and z axis acceleration with one function call.
 */
void mpu6050_accelReadReg(tMPU6050_ACCEL *obj)
{
    mpu6050_accel_xout_readReg(&(obj->X), callback);
    mpu6050_accel_yout_readReg(&(obj->Y), callback);
    mpu6050_accel_zout_readReg(&(obj->Z), callback);
}