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
 *  \file mpu6050_configuration.h
 *  \brief Configuration
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef MPU6050_CONFIGURATION_H_
#define MPU6050_CONFIGURATION_H_

#define MPU6050_CONFIG_EXT_SYNC_SET_Input_disabled  0x00
#define MPU6050_CONFIG_EXT_SYNC_SET_TEMP_OUT_L      0x01
#define MPU6050_CONFIG_EXT_SYNC_SET_GYRO_XOUT_L     0x02
#define MPU6050_CONFIG_EXT_SYNC_SET_GYRO_YOUT_L     0x03
#define MPU6050_CONFIG_EXT_SYNC_SET_GYRO_ZOUT_L     0x04
#define MPU6050_CONFIG_EXT_SYNC_SET_ACCEL_X_OUT_L   0x05
#define MPU6050_CONFIG_EXT_SYNC_SET_ACCEL_Y_OUT_L   0x06
#define MPU6050_CONFIG_EXT_SYNC_SET_ACCEL_Z_OUT_L   0x07

#define MPU6050_CONFIG_DLPF_CFG_ACCELBAND_260_GYROBAND_256  0x00
#define MPU6050_CONFIG_DLPF_CFG_ACCELBAND_184_GYROBAND_188  0x01
#define MPU6050_CONFIG_DLPF_CFG_ACCELBAND_94_GYROBAND_98    0x02
#define MPU6050_CONFIG_DLPF_CFG_ACCELBAND_44_GYROBAND_42    0x03
#define MPU6050_CONFIG_DLPF_CFG_ACCELBAND_21_GYROBAND_20    0x04
#define MPU6050_CONFIG_DLPF_CFG_ACCELBAND_10_GYROBAND_10    0x05
#define MPU6050_CONFIG_DLPF_CFG_ACCELBAND_5_GYROBAND_5      0x06

/**
 *  \brief Configuration datatype
 */
typedef struct
{
    unsigned char DLPF_CFG : 3;		/**< Configures the DLPF setting. */
    unsigned char EXT_SYNC_SET : 3;	/**< Configures the FSYNC pin sampling. */
}
tMPU6050_CONFIG;

extern void mpu6050_configRegRead(tMPU6050_CONFIG*);
extern void mpu6050_configRegWrite(tMPU6050_CONFIG*);

#endif