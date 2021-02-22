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
 *  \file mpu6050_i2cMasterDelayControl.h
 *  \brief I2C Master Delay Control headerfile
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */
 
#ifndef MPU6050_I2CMASTERDELAYCONTROL_H_
#define MPU6050_I2CMASTERDELAYCONTROL_H_

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"

/**
 *  \brief Datatype for I2C Master Delay Control register
 */
typedef struct
{
    /** When set, delays shadowing of external sensor data until
     * all data has been received. */
    bool DELAY_ES_SHADOW;

    /** When enabled, slave 4 will only be accessed at a decreased rate. */
    bool I2C_SLV4_DLY_EN;

    /** When enabled, slave 3 will only be accessed at a decreased rate. */
    bool I2C_SLV3_DLY_EN;

    /** When enabled, slave 2 will only be accessed at a decreased rate. */
    bool I2C_SLV2_DLY_EN;

    /** When enabled, slave 1 will only be accessed at a decreased rate. */
    bool I2C_SLV1_DLY_EN;

    /** When enabled, slave 0 will only be accessed at a decreased rate. */
    bool I2C_SLV0_DLY_EN;
}
tMPU6050_I2C_MST_DELAY_CTRL;

extern void mpu6050_i2cMstDelayCtrlReadReg(tMPU6050_I2C_MST_DELAY_CTRL*);
extern void mpu6050_i2cMstDelayCtrlWriteReg(tMPU6050_I2C_MST_DELAY_CTRL*);

#endif