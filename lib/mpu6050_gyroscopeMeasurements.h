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
 *  \file mpu6050_gyroscopeMeasurements.h
 *  \brief Gyroscope Measurements headerfile
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef MPU6050_GYROSCOPEMEASUREMENTS_H_
#define MPU6050_GYROSCOPEMEASUREMENTS_H_

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"

#define MPU6050_GYRO_SCALE_RANGE_250    0x00
#define MPU6050_GYRO_SCALE_RANGE_500    0x01
#define MPU6050_GYRO_SCALE_RANGE_1000   0x02
#define MPU6050_GYRO_SCALE_RANGE_2000   0x03

typedef uint16_t tMPU6050_GYRO_XOUT;	/**< Stores the most recent X axis gyroscope measurement. */
typedef uint16_t tMPU6050_GYRO_YOUT;	/**< Stores the most recent Y axis gyroscope measurement. */
typedef uint16_t tMPU6050_GYRO_ZOUT;	/**< Stores the most recent Z axis gyroscope measurement. */

/**
 *  \brief Datatype for gyroscope values
 */
typedef struct
{
    tMPU6050_GYRO_XOUT X;
    tMPU6050_GYRO_YOUT Y;
    tMPU6050_GYRO_ZOUT Z;
}
tMPU6050_GYRO;

extern void mpu6050_gyroXoutReadReg(tMPU6050_GYRO_XOUT*);
extern void mpu6050_gyroYoutReadReg(tMPU6050_GYRO_YOUT*);
extern void mpu6050_gyroZoutReadReg(tMPU6050_GYRO_ZOUT*);
extern void mpu6050_gyroReadReg(tMPU6050_GYRO*);

#endif