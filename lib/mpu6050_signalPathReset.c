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
 *  \file mpu6050_signalPathReset.c
 *  \brief Signal Path Reset
 *  
 *  This register is used to reset the analog and digital signal paths
 *  of the gyroscope, accelerometer and temperature sensors.
 *  
 *  The reset will revert the signal path analog to digital converters
 *  and filters to their power up configurations.
 *  
 *  \note This register does not clear the sensor registers. The reset
 *  initializes the serial interface as well.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include "mpu6050_signalPathReset.h"

/**
 *  \brief Read signal path reset register
 *  \param [in] obj Datatype pointer to store read values
 *  
 *  \details See register datasheet chapter 4.26 for more details.
 */
void mpu6050_signalPathResetReadReg(tMPU6050_SIGNAL_PATH_RESET *obj)
{
    uint8_t reg = i2c_receive(MPU6050_I2C_ADDR, MPU6050_SIGNAL_PATH_RESET);
    obj->GYRO_RESET = (reg >> 2) & 0x01;
    obj->ACCEL_RESET = (reg >> 1) & 0x01;
    obj->TEMP_RESET = reg & 0x01;
}

/**
 *  \brief Write signal path reset register
 *  \param [in] obj Datatype pointer to store read values
 *  
 *  \details See register datasheet chapter 4.26 for more details.
 */
void mpu6050_signalPathResetWriteReg(tMPU6050_SIGNAL_PATH_RESET *obj)
{
    uint8_t reg = obj->GYRO_RESET << 2;
    reg |= obj->ACCEL_RESET << 1;
    reg |= obj->TEMP_RESET;
    i2c_write(MPU6050_I2C_ADDR, MPU6050_SIGNAL_PATH_RESET, reg);
}