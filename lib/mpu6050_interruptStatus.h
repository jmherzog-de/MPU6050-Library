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
 *  \file mpu6050_interruptStatus.h
 *  \brief Interrupt Status headerfile
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef MPU6050_INTERRUPTSTATUS_H_
#define MPU6050_INTERRUPTSTATUS_H_

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"

/**
 *  \brief Datatype for Interrupt Status Register
 */
typedef struct
{
    /** This bit automatically sets to 1 when a FIFO buffer overflow interrupt has
     * been generated.
     * The bit clears to 0 after the register has been read. */
    bool FIFO_OFLOW_INT;

    /** This bit automatically sets to 1 when an I2C Master interrupt has been
     * generated. The bit clears to 0 after the register has been read.
     * Note: Interrupt informations see Register 54. */
    bool I2C_MST_INT;

    /** This bit automatically sets to 1 when a Data Ready interrupt
     * is generated. This bit clears to 0 after the register has been read. */
    bool DATA_RDY_INT;
}
tMPU6050_INT_STATUS;

extern void mpu6050_intStatusReadReg(tMPU6050_INT_STATUS*);

#endif