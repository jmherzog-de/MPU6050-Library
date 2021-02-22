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
 *  \file mpu6050_powerManagement1.h
 *  \brief Power Management 1 headerfile
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef MPU6050_POWERMANAGEMENT1_H_
#define MPU6050_POWERMANAGEMENT1_H_

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"

#define MPU6050_PWR_MGMT_1_INTERNAL_8MHz                            0x00
#define MPU6050_PWR_MGMT_1_PLL_WITH_X_AXIS_GYRO_REFERENCE           0x01
#define MPU6050_PWR_MGMT_1_PLL_WITH_Y_AXIS_GYRO_REFERENCE           0x03
#define MPU6050_PWR_MGMT_1_PLL_WITH_Z_AXIS_GYRO_REFERENCE           0x03
#define MPU6050_PWR_MGMT_1_PLL_WITH_EXTERNAL_32_768_kHz_REFERENCE   0x04
#define MPU6050_PWR_MGMT_1_PLL_WITH_EXTERNAL_19_2_MHz_REFERENCE     0x05
#define MPU6050_PWR_MGMT_1_Reserved                                 0x06
#define MPU6050_PWR_MGMT_1_STOP_CLOCK                               0x07

/**
 *  \brief Datatype for Power Management 1 register data
 */
typedef struct
{
    /** When set to 1, this bit resets all internal registers to their default values.
     * The bit automatically clears to 0 once the reset is done. */
    bool DEVICE_RESET;

    /** When set to 1, this bit puts the MPU6050 into sleep mode. */
    bool SLEEP;

    /** When this bit is set to 1 and SLEEP is disabled, the MPU6050 will cycle
     * between sleep mode and waking up to take a single sample of data from
     * active sensors at a rate determined by LP_WAKE_CTRL (Register 108). */
    bool CYCLE;

    /** When set to 1, this bit disables the temperature sensor. */
    bool TEMP_DIS;

    /** 3-bit unsigned value. Specifies the clock source of the device. */
    uint8_t CLKSEL: 3;
}
tMPU6050_PWR_MGMT_1;

extern void mpu6050_pwrMgmt1ReadReg(tMPU6050_PWR_MGMT_1*);
extern void mpu6050_pwrMgmt1WriteReg(tMPU6050_PWR_MGMT_1*);

#endif