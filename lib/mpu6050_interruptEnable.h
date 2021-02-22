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
 *  \file mpu6050_interruptEnable.h
 *  \brief Interrupt Enable headerfile
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef MPU6050_INTERRUPTENABLE_H_
#define MPU6050_INTERRUPTENABLE_H_

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"

/**
 *  \brief Datatype for Interrupt Enable register
 */
typedef struct
{
    /** When set to 1, this bit enables a FIFO buffer overflow to generate an interrupt. */
    bool FIFO_OFLOW_EN;

    /** When set to 1, this bit enables any of the I2C Master interrupt sources to
     * generate an interrupt. */
    bool I2C_MST_INT_EN;

    /** When set to 1, this bit enables the Data Ready interrupt, which occurs each time
     * a write operation to all of the sensor registers has been completed. */
    bool DATA_RDY_EN;
}
tMPU6050_INT_ENABLE;

extern void mpu6050_intEnableReadReg(tMPU6050_INT_ENABLE*);
extern void mpu6050_intEnableWriteReg(tMPU6050_INT_ENABLE*);

#endif