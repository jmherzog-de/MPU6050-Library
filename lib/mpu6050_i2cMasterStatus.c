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
 *  \file mpu6050_i2cMasterStatus.c
 *  \brief I2C Master Status
 *  
 *  This register shows the status of the interrupt generating signals in
 *  the I2C Master within the MPU6050. This register also communicates the
 *  status of the FSYNC interrupt to the host processor.
 *  
 *  \note Reading this register will clear all the status bits in the register.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */
 
#include "mpu6050_i2cMasterStatus.h"

/**
 *  \brief Read I2c Master Status register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.13 for more details.
 */
void mpu6050_i2cMstStatusReadReg(tMPU6050_I2C_MST_STATUS *obj)
{
    uint8_t reg = i2c_receive(MPU6050_I2C_ADDR, MPU6050_I2C_MST_STATUS);
    obj->PASS_THROUGH = reg >> 7;
    obj->I2C_SLV4_DONE = (reg >> 6) & 0x01;
    obj->I2C_LOST_ARB = (reg >> 5) & 0x01;
    obj->I2C_SLV4_NACK = (reg >> 4) & 0x01;
    obj->I2C_SLV3_NACK = (reg >> 3) & 0x01;
    obj->I2C_SLV2_NACK = (reg >> 2) & 0x01;
    obj->I2C_SLV1_NACK = (reg >> 1) & 0x01;
    obj->I2C_SLV0_NACK = reg & 0x01;
}

/**
 *  \brief Write to I2c Master Status register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.13 for more details.
 */
void mpu6050_i2cMstStatusWriteReg(tMPU6050_I2C_MST_STATUS *obj)
{
    uint8_t reg = (uint8_t)(obj->PASS_THROUGH) << 7;
    reg |= (uint8_t)(obj->I2C_SLV4_DONE) << 6;
    reg |= (uint8_t)(obj->I2C_LOST_ARB) << 5;
    reg |= (uint8_t)(obj->I2C_SLV4_NACK) << 4;
    reg |= (uint8_t)(obj->I2C_SLV3_NACK) << 3;
    reg |= (uint8_t)(obj->I2C_SLV2_NACK) << 2;
    reg |= (uint8_t)(obj->I2C_SLV1_NACK) << 1;
    reg |= (uint8_t)(obj->I2C_SLV0_NACK);

    i2c_write(MPU6050_I2C_ADDR, MPU6050_I2C_MST_STATUS, reg);
}