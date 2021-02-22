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
 *  \file mpu6050_i2cSlave4Control.h
 *  \brief I2C Slave 4 Control headerfile
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef MPU6050_I2CSLAVE4CONTROL_H_
#define MPU6050_I2CSLAVE4CONTROL_H_

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"

/**
 *  \brief Datatype for I2C Slave 4 ADDR register
 */
typedef struct
{
    /** When set to 1, this bit configures the data transfer as a read operation.
     * When cleared to 0, this bit configures the data transfer as a write operation. */
    bool I2C_SLV4_RW;

    /** I2C address of slave 3 */
    unsigned char I2C_SLV4_ADDR: 7;
}
tMPU6050_I2C_SLV4_ADDR;

/** Slave 4 address to/from which data transfer starts. */
typedef unsigned char tMPU6050_I2C_SLV4_REG;

/** This register stores the data to be written into the slave 4. */
typedef unsigned char tMPU6050_I2C_SLV4_DO;

/** This register stores the data read from Slave 4. This field is populated
 * after a read transaction. */
typedef unsigned char tMPU6050_I2C_SLV4_DI;

/**
 *  \brief Datatype for I2C Slave 4 CTRL register
 */
typedef struct
{
    /** When set to 1, this bit enables Slave 4 for data transfer operations. */
    bool I2C_SLV4_EN;

    /** When set to 1, this bit enables the generation of an interrupt signal upon
     * completion of a Slave 4 transaction. */
    bool I2C_SLV4_INT_EN;

    /** When set to 1, the transaction will read or write data.
     * When cleared to 0, the transaction will read or write a register address. */
    bool I2C_SLV4_REG_DIS;

    /** Configures the decreased access rate of slave devices relative to the
     * Sample Rate. */
    unsigned char I2C_MST_DLY: 5;
}
tMPU6050_I2C_SLV4_CTRL;

/** This register stores the data read from Slave 4.
 * This field is populated after a read transaction. */
typedef unsigned char tI2C_SLV4_DI;

/** complete type for I2C Slave 4 Control. */
typedef struct
{
    tMPU6050_I2C_SLV4_ADDR ADDR;
    tMPU6050_I2C_SLV4_REG REG;
    tMPU6050_I2C_SLV4_CTRL CTRL;
    tMPU6050_I2C_SLV4_DO DO;
    tMPU6050_I2C_SLV4_DI DI;
}
tMPU6050_I2C_SLV4;

extern void mpu6050_i2cSlv4AddrReadReg(tMPU6050_I2C_SLV4_ADDR*);
extern void mpu6050_i2cSlv4AddrWriteReg(tMPU6050_I2C_SLV4_ADDR*);

extern void mpu6050_i2cSlv4RegReadReg(tMPU6050_I2C_SLV4_REG*);
extern void mpu6050_i2cSlv4RegWriteReg(tMPU6050_I2C_SLV4_REG*);

extern void mpu6050_i2cSlv4CtrlReadReg(tMPU6050_I2C_SLV4_CTRL*);
extern void mpu6050_i2cSlv4CtrlWriteReg(tMPU6050_I2C_SLV4_CTRL*);

extern void mpu6050_i2cSlv4DoReadReg(tMPU6050_I2C_SLV4_DO*);
extern void mpu6050_i2cSlv4DoWriteReg(tMPU6050_I2C_SLV4_DO*);

extern void mpu6050_i2cSlv4ReadReg(tMPU6050_I2C_SLV4*);
extern void mpu6050_i2cSlv4WriteReg(tMPU6050_I2C_SLV4*);

#endif