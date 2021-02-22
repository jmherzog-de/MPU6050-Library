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
 *  \file mpu6050_accelerometerMeasurements.h
 *  \brief Accelerometer Measurements headerfile
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef MPU6050_ACCELEROMETERMEASUREMENTS_H_
#define MPU6050_ACCELEROMETERMEASUREMENTS_H_

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"

#define MPU6050_ACCEL_2g_16384LSB_per_g 0x00
#define MPU6050_ACCEL_4g_8192LSB_per_g  0x01
#define MPU6050_ACCEL_8g_4096LSB_per_g  0x02
#define MPU6050_ACCEL_16g_2048LSB_per_g 0x03


/**
 *  \brief Type for X axis accelerometer measurement data
 */
typedef uint16_t tMPU6050_ACCEL_XOUT;

/**
 *  \brief Type for Y axis accelerometer measurement data
 */
typedef uint16_t tMPU6050_ACCEL_YOUT;

/**
 *  \brief Type for Z axis accelerometer measurement data
 */
typedef uint16_t tMPU6050_ACCEL_ZOUT;

/**
 *  \brief Type contain all axis accelerometer measurement.
 */
typedef struct
{
    tMPU6050_ACCEL_XOUT X;	/**< X axis accelerometer measurement data */
    tMPU6050_ACCEL_YOUT Y;	/**< Y axis accelerometer measurement data */
    tMPU6050_ACCEL_ZOUT Z;	/**< Z axis accelerometer measurement data */
}
tMPU6050_ACCEL;

extern void mpu6050_accelXoutReadReg(tMPU6050_ACCEL_XOUT*);
extern void mpu6050_accelYoutReadReg(tMPU6050_ACCEL_YOUT*);
extern void mpu6050_accelZoutReadReg(tMPU6050_ACCEL_ZOUT*);
extern void mpu6050_accelReadReg(tMPU6050_ACCEL*);

#endif