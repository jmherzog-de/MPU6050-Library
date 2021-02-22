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
 *  \file mpu6050_i2cSlave2Control.c
 *  \brief I2C Slave 2 Control
 *  
 *  These register describe the data transfer sequence for Slave 2. Their
 *  functions correspond to those described for the Slave 0 registers
 *  (register 37 to 39).
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include "mpu6050_i2cSlave2Control.h"

/**
 *  \brief Read I2C Slave 2 ADDR register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.10 for more details.
 */
void mpu6050_i2cSlv2AddrReadReg(tMPU6050_I2C_SLV2_ADDR *obj)
{
    uint8_t reg = i2c_receive(MPU6050_I2C_ADDR, MPU6050_I2C_SLV2_ADDR);
    obj->I2C_SLV2_RW = reg >> 7;
    obj->I2C_SLV2_ADDR = reg & 0x7F;
}

/**
 *  \brief Write to I2C Slave 2 ADDR register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.10 for more details.
 */
void mpu6050_i2cSlv2AddrWriteReg(tMPU6050_I2C_SLV2_ADDR *obj)
{
    uint8_t reg = (uint8_t)obj->I2C_SLV2_RW << 7 | (uint8_t)obj->I2C_SLV2_ADDR;
    i2c_write(MPU6050_I2C_ADDR, MPU6050_I2C_SLV2_ADDR, reg);
}

/**
 *  \brief Read I2C Slave 2 Register register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.10 for more details.
 */
void mpu6050_i2cSlv2RegReadReg(tMPU6050_I2C_SLV2_REG *obj)
{
    *obj = i2c_receive(MPU6050_I2C_ADDR, MPU6050_I2C_SLV2_REG);
}

/**
 *  \brief Write to I2C Slave 2 Register register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.10 for more details.
 */
void mpu6050_i2cSlv2RegWriteReg(tMPU6050_I2C_SLV2_REG *obj)
{
    i2c_write(MPU6050_I2C_ADDR, MPU6050_I2C_SLV2_REG, *obj);
}

/**
 *  \brief Read I2C Slave 2 CTRL register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.10 for more details.
 */
void mpu6050_i2cSlv2CtrlReadReg(tMPU6050_I2C_SLV2_CTRL *obj)
{
    uint8_t reg = I2C_receive(MPU6050_I2C_ADDR, MPU6050_I2C_SLV2_CTRL);
    obj->I2C_SLV2_EN = reg >> 7;
    obj->I2C_SLV2_BYTE_SW = (reg >> 6) & 0x01;
    obj->I2C_SLV2_REG_DIS = (reg >> 5) & 0x01;
    obj->I2C_SLV2_GRP = (reg >> 4) & 0x01;
    obj->I2C_SLV2_LEN = reg & 0x0F;
}

/**
 *  \brief Write to I2C Slave 2 CTRL register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.10 for more details.
 */
void mpu6050_i2cSlv2CtrlWriteReg(tMPU6050_I2C_SLV2_CTRL *obj)
{
    uint8_t reg = (uint8_t)(obj->I2C_SLV2_EN) << 7;
    reg |= (uint8_t)(obj->I2C_SLV2_BYTE_SW) << 6;
    reg |= (uint8_t)(obj->I2C_SLV2_REG_DIS) << 5;
    reg |= (uint8_t)(obj->I2C_SLV2_GRP) << 4;
    reg |= (uint8_t)(obj->I2C_SLV2_LEN);
    i2c_write(MPU6050_I2C_ADDR, MPU6050_I2C_SLV2_CTRL, reg);
}

/**
 *  \brief Read I2C Slave 2 Control registers
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details Read all I2C Slave 2 Control registers with one function.
 */
void mpu6050_i2cSlv2ReadReg(tMPU6050_I2C_SLV2 *obj)
{
    mpu6050_i2cSlv2AddrReadReg(&(obj->ADDR));
    mpu6050_i2cSlv2RegReadReg(&(obj->REG));
    mpu6050_i2cSlv2CtrlReadReg(&(obj->CTRL));
}

/**
 *  \brief Write to I2C Slave 2 Control registers
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details Write all I2C Slave 2 Control registers with one function.
 */
void mpu6050_i2cSlv2WriteReg(tMPU6050_I2C_SLV2 *obj)
{
    mpu6050_i2cSlv2AddrWriteReg(&(obj->ADDR));
    mpu6050_i2cSlv2RegWriteReg(&(obj->REG));
    mpu6050_i2cSlv2CtrlWriteReg(&(obj->CTRL));
}