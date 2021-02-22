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
 *  \file mpu6050_signalPathReset.h
 *  \brief Signal Path Reset headerfile
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef MPU6050_SIGNALPATHRESET_H_
#define MPU6050_SIGNALPATHRESET_H_

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"

/**
 *  \brief Datatype for Signal Path Reset register
 */
typedef struct
{
    
    bool GYRO_RESET;	/**< When set to 1, this bit resets the gyroscope analog and digital signal paths. */
    bool ACCEL_RESET;	/**< When set to 1, this bit resets the accelerometer analog and digital signal paths. */
    bool TEMP_RESET;	/**< When set to 1, this bit resets the temperature sensor analog and digital signal paths. */
}
tMPU6050_SIGNAL_PATH_RESET;

extern void mpu6050_signalPathResetReadReg(tMPU6050_SIGNAL_PATH_RESET*);
extern void mpu6050_signalPathResetWriteReg(tMPU6050_SIGNAL_PATH_RESET*);

#endif