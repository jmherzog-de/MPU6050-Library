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
 *  \file mpu6050_userControl.h
 *  \brief User Control headerfile
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef MPU6050_USERCONTROL_H_
#define MPU6050_USERCONTROL_H_

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"

/**
 *  \brief Datatype User Control
 */
typedef struct
{
    /** When set to 1, this bit enables FIFO operations.
     *  When this bit is cleared to 0, the FIFO buffer is disabled.
     *  The FIFO buffer cannot be written to or read from while disabled.
     *  The FIFO buffer’s state does not change unless the MPU-60X0 is power cycled. 
     */
    bool FIFO_EN;
	
    bool I2C_MST_EN;	/**< When set to 1, this bit enables I2C Master Mode. */
	
    bool I2C_IF_DIS;	/**< Always write this bit as zero. */

    /** This bit resets the FIFO buffer when set to 1 while FIFO_EN equals 0.
     * This bit automatically clears to 0 after the reset has been triggered. */
    bool FIFO_RESET;

    /** This bit resets the I2C Master when set to 1 while I2C_MST_EN equals 0.
     * This bit automatically clears to 0 after the reset has been triggered. */
    bool I2C_MST_RESET;

    /** When set to 1, this bit resets the signal paths for all sensors (gyroscopes,
     * accelerometers and temperature sensor). This operation will also be clear the
     * sensor registers. This bit automatically clears to 0 after the reset has been triggered.
     * When resetting only the signal path ( and not the sensor registers), please use
     * Register 104 (SIGNAL_PATH_RESET) */
    bool SIG_COND_RESET;
}
tMPU6050_USER_CTRL;

extern void mpu6050_userCtrlReadReg(tMPU6050_USER_CTRL*);
extern void mpu6050_userCtrlWriteReg(tMPU6050_USER_CTRL*);

#endif