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
 *  \file mpu6050_gyroscopeConfiguration.h
 *  \brief Gyroscope Configuration headerfile
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef MPU6050_GYROSCOPECONFIGURATION_H_
#define MPU6050_GYROSCOPECONFIGURATION_H_

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"

#define MPU6050_GYRO_RANGE_250_DEG_PER_S  0x00
#define MPU6050_GYRO_RANGE_500_DEG_PER_S  0x01
#define MPU6050_GYRO_RANGE_1000_DEG_PER_S 0x02
#define MPU6050_GYRO_RANGE_2000_DEG_PER_S 0x03

/**
 *  \brief Datatype for Gyroscope Configuration data
 */
typedef struct
{
    bool XG_ST;                 /**< Setting this bit causes the X axis gyroscope to perform self test. */
    bool YG_ST;                 /**< Setting this bit causes the Y axis gyroscope to perform self test. */
    bool ZG_ST;                 /**< Setting this bit causes the Z axis gyroscope to perform self test. */
    unsigned char FS_SEL : 2;   /**< Selects the full scale range of the gyroscope outputs. */
}
tMPU6050_GYRO_CONFIG;

extern void mpu6050_gyroConfigReadReg(tMPU6050_GYRO_CONFIG*);
extern void mpu6050_gyroConfigWriteReg(tMPU6050_GYRO_CONFIG*);

#endif