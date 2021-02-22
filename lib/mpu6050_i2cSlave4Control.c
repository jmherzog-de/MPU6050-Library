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
 *  \file mpu6050_i2cSlave4Control.c
 *  \brief I2C Slave 4 Control
 *  
 *  These registers describe the data transfer sequence to Slave 4.
 *  The characteristics of Slave 4 differ greatly from those of
 *  Slave 0-3. For further information regarding the characteristics
 *  of Slave 0-3, please refer to register 37 to 48.
 *  
 *  I2C slave data transactions between MPU6050 and Slave 4 are et as
 *  either read or write operations by the I2C_SLV4_RW bit. When this
 *  bit is 1, the transfer is a read operation. When the bit is 0, the
 *  transfer is a write operation.
 *  
 *  I2C_SLV4_ADDR is used to specify the I2C slave address of Slave 4.
 *  
 *  Data transfer starts at an internal register within Slave 4. The
 *  register address is specified by I2C_SLV4_REG.
 *  
 *  In read mode, the result of the read will be available in I2C_SLV4_DI.
 *  In write mode, the contents of I2C_SLV4_DO will be written into the
 *  slave device.
 *  
 *  A data transaction is performed only if the I2C_SLV4_EN bit is set to 1.
 *  The data transaction should be enabled once its parameters are configured
 *  in the _ADDR and _REG regiters. For write, the _DO register is also
 *  required. I2C_SLV4_EN will be cleared after the transaction is performed once.
 *  
 *  An interrupt is triggered at the completion of Slave 4 data transaction if the
 *  interrupt is enabled. The status of this interrupt ca be observed in register 54.
 *  
 *  When I2C_SLV4_REG_DIS is set to 1, the transaction will read or write data instead of
 *  writing a register address. This bit should equal to 0 when specifying the register
 *  address within the Slave device to/from which the ensuing data transaction will take
 *  place.
 *  
 *  I2C_MST_DLY configures the reduced access rate of I2C slaves relative to the Sample Rate.
 *  When a slaves's access rate is decreased relative to the Sample Rate, the slave is accessed
 *  every 1/(1+I2C_MST_DLY) samples.
 *  
 *  This base Sample Rate in turn is determined by SMPLRT_DIV (register 25) and DLPF_CFG (register 26).
 *  Wheter a slave's access rate is reduced relative to the Sample Rate is determined by I2C_MST_DELY_CTRL (register 103).
 *  
 *  \note For further information regarding the Sample Rate, please refer to register 25.
 *  
 *  \note Slave 4 transactions are performed after Slave 0-3 transactions have been completed.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include "mpu6050_i2cSlave4Control.h"

/**
 *  \brief Read I2C Slave 4 Address register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.12 for more details.
 */
void mpu6050_i2c_slv4AddrReadReg(tMPU6050_I2C_SLV4_ADDR *obj)
{
    uint8_t reg = i2c_receive(MPU6050_I2C_ADDR, MPU6050_I2C_SLV4_ADDR);
    obj->I2C_SLV4_RW = reg >> 7;
    obj->I2C_SLV4_ADDR = reg & 0x7F;
}

/**
 *  \brief Write to I2C Slave 4 Address register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.12 for more details.
 */
void mpu6050_i2cSlv4AddrWriteReg(tMPU6050_I2C_SLV4_ADDR *obj)
{
    uint8_t reg = (uint8_t)obj->I2C_SLV4_RW << 7 | (uint8_t)obj->I2C_SLV4_ADDR;
    i2c_write(MPU6050_I2C_ADDR, MPU6050_I2C_SLV4_ADDR, reg);
}

/**
 *  \brief Read I2C Slave 4 Register register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.12 for more details.
 */
void mpu6050_i2cSlv4RegReadReg(tMPU6050_I2C_SLV4_REG *obj)
{
    *obj = I2C_receive(MPU6050_I2C_ADDR, MPU6050_I2C_SLV4_REG);
}
/**
 *  \brief Read I2C Slave 4 Register register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.12 for more details.
 */
void mpu6050_i2cSlv4RegWriteReg(tMPU6050_I2C_SLV4_REG *obj)
{
    i2c_write(MPU6050_I2C_ADDR, MPU6050_I2C_SLV4_REG, *obj);
}

/**
 *  \brief Write to I2C Slave 4 DO register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.12 for more details.
 */
void mpu6050_i2cSlv4DoReadReg(tMPU6050_I2C_SLV4_DO *obj)
{
    *obj = i2c_receive(MPU6050_I2C_ADDR, MPU6050_I2C_SLV4_DO);
}

/**
 *  \brief Write to I2C Slave 4 DO register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.12 for more details.
 */
void mpu6050_i2cSlv4DoWriteReg(tMPU6050_I2C_SLV4_DO *obj)
{
    i2c_write(MPU6050_I2C_ADDR, MPU6050_I2C_SLV4_DO, *obj);
}

/**
 *  \brief Read I2C Slave 4 DI register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.12 for more details.
 */
void mpu6050_i2cSlv4DiReadReg(tMPU6050_I2C_SLV4_DI *obj)
{
    *obj = i2c_receive(MPU6050_I2C_ADDR, MPU6050_I2C_SLV4_DI);
}

/**
 *  \brief Write to I2C Slave 4 DI register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.12 for more details.
 */
void mpu6050_i2cSlv4DiWriteReg(tMPU6050_I2C_SLV4_DI *obj)
{
    i2c_write(MPU6050_I2C_ADDR, MPU6050_I2C_SLV4_DI, *obj);
}

/**
 *  \brief Read I2C Slave 4 CTRL register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.12 for more details.
 */
void mpu6050_i2cSlv4CtrlReadReg(tMPU6050_I2C_SLV4_CTRL *obj)
{
    uint8_t reg = i2c_receive(MPU6050_I2C_ADDR, MPU6050_I2C_SLV4_CTRL);
    obj->I2C_SLV4_EN = reg >> 7;
    obj->I2C_SLV4_INT_EN = (reg >> 6) & 0x01;
    obj->I2C_SLV4_REG_DIS = (reg >> 5) & 0x01;
    obj->I2C_MST_DLY = reg & 0x1F;
}

/**
 *  \brief Write to I2C Slave 4 CTRL register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.12 for more details.
 */
void mpu6050_i2cSlv4CtrlWriteReg(tMPU6050_I2C_SLV4_CTRL *obj)
{
    uint8_t reg = (uint8_t)(obj->I2C_SLV4_EN) << 7;
    reg |= (uint8_t)(obj->I2C_SLV4_INT_EN) << 6;
    reg |= (uint8_t)(obj->I2C_SLV4_REG_DIS) << 5;
    reg |= (uint8_t)(obj->I2C_MST_DLY);
    i2c_write(MPU6050_I2C_ADDR, MPU6050_I2C_SLV4_CTRL, reg);
}

/**
 *  \brief Read I2C Slave 4 registers
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details Read all registers with one function call
 */
void mpu6050_i2c_slv4_readReg(tMPU6050_I2C_SLV4 *obj)
{
    mpu6050_i2cSlv4AddrReadReg(&(obj->ADDR));
    mpu6050_i2cSlv4RegReadReg(&(obj->REG));
    mpu6050_i2cSlv4CtrlReadReg(&(obj->CTRL));
    mpu6050_i2cSlv4DoReadReg(&(obj->DO));
    mpu6050_i2cSlv4DiReadReg(&(obj->DI));
}

/**
 *  \brief Write to I2C Slave 4 register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details Write all registers with one function call
 */
void mpu6050_i2cSlv4WriteReg(tMPU6050_I2C_SLV4 *obj)
{
    mpu6050_i2cSlv4AddrWriteReg(&(obj->ADDR));
    mpu6050_i2cSlv4RegWriteReg(&(obj->REG));
    mpu6050_i2cSlv4CtrlWriteReg(&(obj->CTRL));
    mpu6050_i2cSlv4DoWriteReg(&(obj->DO));
    mpu6050_i2cSlv4DiWriteReg(&(obj->DI));
}