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
 *  \file mpu6050_externalSensorData.h
 *  \brief External Sensor Data definition file
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef MPU6050_EXTERNALSENSORDATA_H_
#define MPU6050_EXTERNALSENSORDATA_H_

/**
 *  \brief Datatype for External Sensor Data
 */
typedef uint8_t tMPU6050_EXT_SENS_DATA;

/**
 * \brief Datatype contain all External Sensor Data Registers 
 */
typedef struct
{
    tMPU6050_EXT_SENS_DATA DATA[24];
}
tMPU6050_EXT_SENS_DATA_ALL;

extern void mpu6050_extSensDataReadReg(tMPU6050_EXT_SENS_DATA*, uint8_t number);
extern void mpu6050_extSensDataWriteReg(tMPU6050_EXT_SENS_DATA*, uint8_t number);

extern void mpu6050_extSensDataAllReadReg(tMPU6050_EXT_SENS_DATA_ALL*);
extern void mpu6050_extSensDataAllWriteReg(tMPU6050_EXT_SENS_DATA_ALL*);

#endif
