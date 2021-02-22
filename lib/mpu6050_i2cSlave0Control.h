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
 *  \file mpu6050_i2cSlave0Control.h
 *  \brief I2C Slave 0 Control headerfile
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef MPU6050_I2CSLAVE0CONTROL_H_
#define MPU6050_I2CSLVAE0CONTROL_H_

/**
 *  \brief Datatype for I2C Slave 0 ADDR register
 */
typedef struct
{
    /** When set to 1, this bit configures the data transfer as a read operation.
     * When cleared to 0, this bit configures the data transfer as a write operation. */
    bool I2C_SLV0_RW;

    /** I2C address of slave 0 */
    unsigned char I2C_SLV0_ADDR: 7;
}
tMPU6050_I2C_SLV0_ADDR;

/** Slave 0 address to/from which data transfer starts. */
typedef unsigned char tMPU6050_I2C_SLV0_REG;

/**
 *  \brief Datatype for I2C Slave 0 CTRL register
 */
typedef struct
{
    /** When set to 1, this bit enables Slave 0 for data transfer operations.
     * When cleared to 0, this bit disables Slave 0 from data transfer operations. */
    bool I2C_SLV0_EN;

    /** When set to 1, this bit enables byte swapping. When byte swapping is enabled, the
     * high and low bytes of a word pair are swapped. */
    bool I2C_SLV0_BYTE_SW;

    /** When set to 1, the transaction will read or write data only.
     * When cleared to 0, the transaction will write a register address prior to
     * reading or writing data. */
    bool I2C_SLV0_REG_DIS;

    /** Specifying the grouping order of word pairs received from registers. When cleared to 0,
     * bytes from register addresses 0 and 1, 2 and 3, etc (even, then odd register addresses)
     * are paired to form a word. When set to 1, bytes from register addresses are
     * paired 1 and 2, 3 and 4, etc. (odd, then even register addresses) are paired
     * to form a word.  */
    bool I2C_SLV0_GRP;

    /** Specifies the number of bytes transferred to and from Slave 0. */
    unsigned char I2C_SLV0_LEN: 4;
}
tMPU6050_I2C_SLV0_CTRL;

/** complete type for I2C Slave 0 Control. */
typedef struct
{
    tMPU6050_I2C_SLV0_ADDR ADDR;
    tMPU6050_I2C_SLV0_REG REG;
    tMPU6050_I2C_SLV0_CTRL CTRL;
}
tMPU6050_I2C_SLV0;

extern void mpu6050_i2cSlv0AddrReadReg(tMPU6050_I2C_SLV0_ADDR*);
extern void mpu6050_i2cSlv0AddrWriteReg(tMPU6050_I2C_SLV0_ADDR*);

extern void mpu6050_i2cSlv0RegReadReg(tMPU6050_I2C_SLV0_REG*);
extern void mpu6050_i2cSlv0RegWriteReg(tMPU6050_I2C_SLV0_REG*);

extern void mpu6050_i2cSlv0CtrlReadReg(tMPU6050_I2C_SLV0_CTRL*);
extern void mpu6050_i2cSlv0CtrlWriteReg(tMPU6050_I2C_SLV0_CTRL*);

extern void mpu6050_i2cSlv0ReadReg(tMPU6050_I2C_SLV0*);
extern void mpu6050_i2cSlv0WriteReg(tMPU6050_I2C_SLV0*);

#endif