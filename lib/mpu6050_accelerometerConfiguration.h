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
 *  \file mpu6050_accelerometerConfiguration.h
 *  \brief Accelerometer Configuration definition file
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef MPU6050_ACCELEROMETERCONFIGURATION_H_
#define MPU6050_ACCELEROMETERCONFIGURATION_H_

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"

#define MPU6050_ACCEL_RANGE_2G     0x00
#define MPU6050_ACCEL_RANGE_4G     0x01
#define MPU6050_ACCEL_RANGE_8G     0x02
#define MPU6050_ACCEL_RANGE_16G    0x03

/**
 *  \brief Acceleration Configuration type
 */
typedef struct
{
    bool XA_ST;                 /**< Setting this bit causes the X axis accelerometer to perform self test. */
    bool YA_ST;                 /**< Setting this bit causes the Y axis accelerometer to perform self test. */
    bool ZA_ST;                 /**< Setting this bit causes the Z axis accelerometer to perform self test. */
    unsigned char AFS_SEL : 2;  /**< Selects the full scale range of accelerometers. */
}
tMPU6050_ACCEL_CONFIG;

extern void mpu6050_accelConfigReadReg(tMPU6050_ACCEL_CONFIG*);
extern void mpu6050_accelConfigWriteReg(tMPU6050_ACCEL_CONFIG*);

#endif /* MPU6050_ACCELEROMETERCONFIGURATION_H_ */