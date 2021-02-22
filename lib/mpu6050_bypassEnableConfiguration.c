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
 *  \file mpu6050_bypassEnableConfiguration.c
 *  \brief INT Pin / Bypass Enable Configuration
 *  
 *  This register configures the behavior of the interrupt signals at the INT pins.
 *  This regsiter is also used to enable the FSYNC Pin to be used as an interrupt
 *  to the host application processor, as well as to enable Bypass Mode on the I2C
 *  Master. This bit also enables the clock output.
 *  
 *  FSYNC_INT_EN enables the FSYNC pin to be used as an interrupt to the host application
 *  processor. A transition to the active level specified in FSYNC_INT_LEVEL will trigger
 *  an interrupt. The status of this interrupt is read from PASS_THROUGH bit in I2C Master
 *  Status Register (Register 54).
 *  
 *  When I2C_BYPASS_EN is equal to 1 and I2C_MST_EN (Register 106 bit[5]) is equal to 0, the
 *  host application processor will be able to directly access the auxiliary I2C bus of the
 *  MPU6050. When this bit is equal to 0, the host application processor will not be able
 *  to directly access the auxiliary I2C bus of the MPU6050 regardless of the state of
 *  I2C_MST_EN.
 *  
 *  For further information regarding Bypass Mode, please refer to Section 7.11 and 7.13
 *  of the MPU6050 Product Specification document.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"
#include "mpu6050_bypassEnableConfiguration.h"

/**
 *  \brief Read Interrupt Pin Configuration Register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.14 for more details
 */
void mpu6050_intPinCfgReadReg(tMPU6050_INT_PIN_CFG *obj)
{
    uint8_t reg = i2c_receive(MPU6050_I2C_ADDR, MPU6050_INT_PIN_CFG);
    obj->INT_LEVEL = reg >> 7;
    obj->INT_OPEN = (reg >> 6) & 0x01;
    obj->LATCH_INT_EN = (reg >> 5) & 0x01;
    obj->INT_RD_CLEAR = (reg >> 4) & 0x01;
    obj->FSYNC_INT_LEVEL = (reg >> 3) & 0x01;
    obj->FSYNC_INT_EN = (reg >> 2) & 0x01;
    obj->I2C_BYPASS_EN = (reg >> 1) & 0x01;
}

/**
 *  \brief Write Interrupt Pin Configuration Register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.14 for more details
 */
void mpu6050_intPinCfgWriteReg(tMPU6050_INT_PIN_CFG *obj)
{
    uint8_t reg = (uint8_t)(obj->INT_LEVEL) << 7;
    reg |= (uint8_t)(obj->INT_OPEN) << 6;
    reg |= (uint8_t)(obj->LATCH_INT_EN) << 5;
    reg |= (uint8_t)(obj->INT_RD_CLEAR) << 4;
    reg |= (uint8_t)(obj->FSYNC_INT_LEVEL) << 3;
    reg |= (uint8_t)(obj->FSYNC_INT_EN) << 2;
    reg |= (uint8_t)(obj->I2C_BYPASS_EN) << 1;
    i2c_write(MPU6050_I2C_ADDR, MPU6050_INT_PIN_CFG, reg);
}