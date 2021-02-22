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

#ifndef MPU6050_POWERMANAGEMENT2_H_
#define MPU6050_POWERMANAGEMENT2_H_

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"

#define MPU6050_PWR_MGMT_2_WAKE_UP_FREQ_1_25Hz      0x00
#define MPU6050_PWR_MGMT_2_WAKE_UP_FREQ_5Hz         0x01
#define MPU6050_PWR_MGMT_2_WAKE_UP_FREQ_20Hz        0x02
#define MPU6050_PWR_MHMT_2_WAKE_UP_FREQ_40Hz        0x03

/**
 *  \brief Datatype for Power Management 2 register data
 */
typedef struct
{
    /** Specifies the frequency of wake-ups during Accelerometer Only Low Power Mode. */
    uint8_t LP_WAKE_CTRL: 2;

    /** When set to 1, this bit puts the X axis accelerometer in standby mode. */
    bool STBY_XA;

    /** When set to 1, this bit puts the Y axis accelerometer into standby mode. */
    bool STBY_YA;

    /** When set to 1, this bit puts the Z axis accelerometer into standby mode. */
    bool STBY_ZA;

    /** When set to 1, this bit puts the X axis gyroscope into standby mode. */
    bool STBY_XG;

    /** When set to 1, this bit puts the Y axis gyroscope into standby mode. */
    bool STBY_YG;

    /** When set to 1, this bit puts the Z axis gyroscope into standby mode. */
    bool STBY_ZG;
}
tMPU6050_PWR_MGMT_2;

extern void mpu6050_pwrMgmt2ReadReg(tMPU6050_PWR_MGMT_2*);
extern void mpu6050_pwrMgmt2WriteReg(tMPU6050_PWR_MGMT_2*);

#endif