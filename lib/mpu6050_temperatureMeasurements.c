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
 *  \file mpu6050_temperatureMeasurements.c
 *  \brief Temperature Measurement
 *  
 *  These registers store the most recent temperature sensor measurement.
 *  
 *  Temperature measurements are written to these registers as the Sample Rate
 *  as defined in register 25.
 *  
 *  These temperature measurement registers, along with the accelerometer
 *  registers, gyroscope measurement registers and external sensor data
 *  registers, are composed of two sets of registers: an internal register
 *  set and a user-facing read register set.
 *  
 *  The data within the temperature sensor's internal register set is always
 *  updated at the Sample Rate. Meanwhile, the user-facing read register set
 *  duplicates the internal register set's data values whenenver the serial
 *  interface is idle. This guarantees that a burst read of sensor registers
 *  will read measurements from the same sampling instant. Note that if burst
 *  reads are not used, the user is responsible for ensuring a set of single
 *  byte reads correspond to a single sampling instant by checking the Data
 *  Ready interrupt.
 *  
 *  The scale factor and offset for the temperature sensor are found in the
 *  Electrical Specification table (Section 6.4 of the MPU6050 Product
 *  Specification document).
 *  
 *  The temperature in degrees C for a given register value may be computed as:
 *  
 *  Temperature in degrees C = (TEMP_OUT register value as signed quantity)/340 + 36.53
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include "mpu6050_temperatureMeasurements.h"

/**
 *  \brief Read temperature measurement register
 *  \param [in] obj Datatype pointer to store read values
 *  
 *  \details See register datasheet chapter 4.18 for more details.
 */
void mpu6050_tempOutReadReg(tMPU6050_TEMP *obj)
{
    uint16_t high = (uint8_t)i2c_receive(MPU6050_I2C_ADDR, MPU6050_TEMP_OUT_H);
    uint16_t low = (uint8_t)i2c_receive(MPU6050_I2C_ADDR, MPU6050_TEMP_OUT_L);
    *obj = (high << 8) | low;
}