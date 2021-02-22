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
 *  \file mpu6050_gyroscopeMeasurements.c
 *  \brief Gyroscope Measurements
 *  
 *  These registers store the most recent gyroscope measurements.
 *  
 *  Gyroscope measurements are written to these registers at the Sample Rate as
 *  defined in register 25.
 *  
 *  These gyroscope measurement registers, along with the accelerometer measurement 
 *  registers, temperature measurement registers, and external sensor data registers, 
 *  are composed of two sets of registers: an internal register set and a user-facing 
 *  read register set.
 *  
 *  The data within the gyroscope sensors’ internal register set is always updated at 
 *  the Sample Rate. Meanwhile, the user-facing read register set duplicates the internal 
 *  register set’s data values whenever the serial interface is idle. This guarantees 
 *  that a burst read of sensor registers will read measurements from the same sampling 
 *  instant. Note that if burst reads are not used, the user is responsible for ensuring 
 *  a set of single byte reads correspond to a single sampling instant by 
 *  checking the Data Ready interrupt.
 *  
 *  Each 16-bit gyroscope measurement has a full scale defined in FS_SEL (register 27). For
 *  each full scale setting, the gyroscope's sensitivity per LSB in GYRO_xOUT is shown in
 *  the table below:
 *  
 *  | FS_SEL | Full Scale Range | LSB Sensitivity |
 *	|:------:|:----------------:|:---------------:|
 *	|   0    | +/- 250 °/s      |   131 LSB °/s   |
 *	|   1    | +/- 500 °/s      |   65.5 LSB °/s  |
 *	|   2    | +/- 1000 °/s     |   32.8 LSB °/s  |
 *	|   3    | +/- 2000 °/s     |   16.4 LSB °/s  |
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include "mpu6050_gyroscopeMeasurements.h"

/**
 *  \brief Read Gyroscope X axis measurement
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.19 for more details.
 */
void mpu6050_gyroXoutReadReg(tMPU6050_GYRO_XOUT *obj)
{
    uint16_t high = (uint8_t)I2C_receive(MPU6050_I2C_ADDR, MPU6050_GYRO_XOUT_H);
    uint16_t low = (uint8_t)I2C_receive(MPU6050_I2C_ADDR, MPU6050_GYRO_XOUT_L);
    *obj = (high << 8) | low;
}

/**
 *  \brief Read Gyroscope Y axis measurement
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.19 for more details.
 */
void mpu6050_gyroYoutReadReg(tMPU6050_GYRO_YOUT *obj)
{
    uint16_t high = (uint8_t)I2C_receive(MPU6050_I2C_ADDR, MPU6050_GYRO_YOUT_H);
    uint16_t low = (uint8_t)I2C_receive(MPU6050_I2C_ADDR, MPU6050_GYRO_YOUT_L);
    *obj = (high << 8) | low;
}

/**
 *  \brief Read Gyroscope Z axis measurement
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.19 for more details.
 */
void mpu6050_gyroZoutReadReg(tMPU6050_GYRO_ZOUT *obj)
{
    uint16_t high = (uint8_t)I2C_receive(MPU6050_I2C_ADDR, MPU6050_GYRO_ZOUT_H);
    uint16_t low = (uint8_t)I2C_receive(MPU6050_I2C_ADDR, MPU6050_GYRO_ZOUT_L);
    *obj = (high << 8) | low;
}

/**
 *  \brief Read Gyroscope all axis measurement
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details Read all axis of the Gyroscope at once.
 */
void mpu6050_gyroReadReg(tMPU6050_GYRO *obj)
{
    mpu6050_gyroXoutReadReg(&(obj->X));
    mpu6050_gyroYoutReadReg(&(obj->Y));
    mpu6050_gyroZoutReadReg(&(obj->Z));
}