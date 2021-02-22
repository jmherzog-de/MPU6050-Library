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
 *  \file mpu6050_i2cMasterStatus.h
 *  \brief I2C Master Status headerfile
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef MPU6050_I2CMASTERSTATUS_H_
#define MPU6050_I2CMASTERSTATUS_H_

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"

/**
 *  \brief Datatype for I2C Master Status register
 */
typedef struct
{
    /** This bit reflects the status of the FSYNC interrupt from an external device
     * into the MPU6050. This is used as a way to pass an external interrupt through
     * the MPU6050 to the host application processor. When set to 1, this bit will
     * cause an interrupt if FSYNC_INT_EN is asserted in INT_PIN_CFG (Register 55). */
    bool PASS_THROUGH;

    /** Automatically sets to 1 when a Slave 4 transaction has completed. This triggers an
     * interrupt if the I2C_MST_INT_EN bit in the INT_ENABLE register (Register 56) is
     * asserted and if the SLV4_DONE_INT bit is asserted in the I2C_SLV4_CTRL register (52). */
    bool I2C_SLV4_DONE;

    /** This bit automatically sets to 1 when the I2C Master has lost arbitration of the
     * auxiliary I2C bus (an error condition). This triggers an interrupt if the
     * I2C_MST_INT_EN bit in the INT_ENABLE register (Register 56) is asserted. */
    bool I2C_LOST_ARB;

    /** This bit automatically sets to 1 when the I2C Master receives a NACK in a
     * transaction with Slave 4. This triggers an interrupt if the I2C_MST_INT_EN bit
     * in the INT_ENABLE register (Register 56) is asserted. */
    bool I2C_SLV4_NACK;

    /** This bit automatically sets to 1 when the I2C Master receives a NACK in a
     * transaction with Slave 3. This triggers an interrupt if the I2C_MST_INT_EN bit
     * in the INT_ENABLE register (Register 56) is asserted. */
    bool I2C_SLV3_NACK;

    /** This bit automatically sets to 1 when the I2C Master receives a NACK in a
     * transaction with Slave 2. This triggers an interrupt if the I2C_MST_INT_EN bit
     * in the INT_ENABLE register (Register 56) is asserted. */
    bool I2C_SLV2_NACK;

    /** This bit automatically sets to 1 when the I2C Master receives a NACK in a
     * transaction with Slave 1. This triggers an interrupt if the I2C_MST_INT_EN bit
     * in the INT_ENABLE register (Register 56) is asserted. */
    bool I2C_SLV1_NACK;

    /** This bit automatically sets to 1 when the I2C Master receives a NACK in a
     * transaction with Slave 0. This triggers an interrupt if the I2C_MST_INT_EN bit
     * in the INT_ENABLE register (Register 56) is asserted. */
    bool I2C_SLV0_NACK;
}
tMPU6050_I2C_MST_STATUS;

extern void mpu6050_i2cMstStatusReadReg(tMPU6050_I2C_MST_STATUS*);
extern void mpu6050_i2cMstStatusWriteReg(tMPU6050_I2C_MST_STATUS*);

#endif