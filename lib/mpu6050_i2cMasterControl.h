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
 *  \file mpu6050_i2cMasterControl.h
 *  \brief I2C Master Control headerfile
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef MPU6050_I2CMASTERCONTROL_H_
#define MPU6050_I2CMASTERCONTROL_H_

#define MPU6050_I2C_MST_CLK_348kHz  0x00
#define MPU6050_I2C_MST_CLK_333kHz  0x01
#define MPU6050_I2C_MST_CLK_320kHz  0x02
#define MPU6050_I2C_MST_CLK_308kHz  0x03
#define MPU6050_I2C_MST_CLK_296kHz  0x04
#define MPU6050_I2C_MST_CLK_286kHz  0x05
#define MPU6050_I2C_MST_CLK_276kHz  0x06
#define MPU6050_I2C_MST_CLK_267kHz  0x07
#define MPU6050_I2C_MST_CLK_258kHz  0x08
#define MPU6050_I2C_MST_CLK_500kHz  0x09
#define MPU6050_I2C_MST_CLK_471kHz  0x0A
#define MPU6050_I2C_MST_CLK_444kHz  0x0B
#define MPU6050_I2C_MST_CLK_421kHz  0x0C
#define MPU6050_I2C_MST_CLK_400kHz  0x0D
#define MPU6050_I2C_MST_CLK_381kHz  0x0E
#define MPU6050_I2C_MST_CLK_364kHz  0x0F

/**
 *  \brief Datatype for I2C Master Control register
 */
typedef struct
{
    bool MULTI_MST_EN;              /**< When set to 1, this bit enables multi-master capability. */

    /** When set to 1, this bit delays the Data Ready
     * interrupt until External Sensor data from the
     * Slave device have been loaded into the EXT_SENS_DATA
     * registers. */
    bool WAIT_FOR_ES;

    /** When set to 1, this bit enables EXT_SENS_DATA registers associated with Slave 3 to be written into the FIFO.
     * The corresponding bits for Slaves 0-2 can be found in Register 35.*/
    bool SLV_3_FIFO_EN;

    /** Controls the I2C Master transition from one slave read to the next slave read.
     * When this bit equals 0, there is a restart between reads.
     * When this bit equals 1, there is a stop and start marking the beginning of the next read.
     * Note: When a write follows a read, a stop and start is always enforced. */
    bool I2C_MST_P_NSR;

    unsigned char I2C_MST_CLK : 4;	/**< Configures the I2C master clock speed divider. */
}
tMPU6050_I2C_MST_CTRL;

extern void mpu6050_i2cMstCtrlReadReg(tMPU6050_I2C_MST_CTRL*);

#endif