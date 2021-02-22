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
 *  \file mpu6050_i2cSlave1Control.h
 *  \brief I2C Slave 1 Control headerfile
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef MPU6050_I2CSLAVE1CONTROL_H_
#define MPU6050_I2CSLAVE1CONTROL_H_

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"

/** Datatype for I2C Slave 1 ADDR register */
typedef struct
{
    /** When set to 1, this bit configures the data transfer as a read operation.
     * When cleared to 0, this bit configures the data transfer as a write operation. */
    bool I2C_SLV1_RW;

    /** I2C address of slave 1 */
    unsigned char I2C_SLV1_ADDR: 7;
}
tMPU6050_I2C_SLV1_ADDR;

/** Slave 1 address to/from which data transfer starts. */
typedef unsigned char tMPU6050_I2C_SLV1_REG;

/** Datatype for I2C Slave 1 CTRL register */
typedef struct
{
    /** When set to 1, this bit enables Slave 1 for data transfer operations.
     * When cleared to 0, this bit disables Slave 0 from data transfer operations. */
    bool I2C_SLV1_EN;

    /** When set to 1, this bit enables byte swapping. When byte swapping is enabled, the
     * high and low bytes of a word pair are swapped. */
    bool I2C_SLV1_BYTE_SW;

    /** When set to 1, the transaction will read or write data only.
     * When cleared to 0, the transaction will write a register address prior to
     * reading or writing data. */
    bool I2C_SLV1_REG_DIS;

    /** Specifying the grouping order of word pairs received from registers. When cleared to 0,
     * bytes from register addresses 0 and 1, 2 and 3, etc (even, then odd register addresses)
     * are paired to form a word. When set to 1, bytes from register addresses are
     * paired 1 and 2, 3 and 4, etc. (odd, then even register addresses) are paired
     * to form a word.  */
    bool I2C_SLV1_GRP;

    /** Specifies the number of bytes transferred to and from Slave 1. */
    unsigned char I2C_SLV1_LEN: 4;
}
tMPU6050_I2C_SLV1_CTRL;

/** complete type for I2C Slave 1 Control. */
typedef struct
{
    tMPU6050_I2C_SLV1_ADDR ADDR;
    tMPU6050_I2C_SLV1_REG REG;
    tMPU6050_I2C_SLV1_CTRL CTRL;
}
tMPU6050_I2C_SLV1;

extern void mpu6050_i2cSlv1AddrReadReg(tMPU6050_I2C_SLV1_ADDR*);
extern void mpu6050_i2cSlv1AddrWriteReg(tMPU6050_I2C_SLV1_ADDR*);

extern void mpu6050_i2cSlv1RegReadReg(tMPU6050_I2C_SLV1_REG*);
extern void mpu6050_i2cSlv1RegWriteReg(tMPU6050_I2C_SLV1_REG*);

extern void mpu6050_i2cSlv1CtrlReadReg(tMPU6050_I2C_SLV1_CTRL*);
extern void mpu6050_i2cSlv1CtrlWriteReg(tMPU6050_I2C_SLV1_CTRL*);

extern void mpu6050_i2cSlv1ReadReg(tMPU6050_I2C_SLV1*);
extern void mpu6050_i2cSlv1WriteReg(tMPU6050_I2C_SLV1*);

#endif