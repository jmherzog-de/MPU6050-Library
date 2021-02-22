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
 *  \file mpu6050_i2cSlave0Control.c
 *  \brief I2C Slave 0 Control
 *  
 *  These registers configure the data transfer sequence for Slave 0. Slave 1,2, and 3
 *  also behave in a similar manner to Slave 0. However, Slave 4's characteristics differ
 *  greatly from those of Slaves 0-3. For further information regarding Slave 4, please
 *  refer to register 49 to 53.
 *  
 *  I2C slave data transactions between the MPU6050 and Slave 0 are set as either read or
 *  write operations by the I2C_SLV0_RW bit. When this bit is 1, the transfer is a read
 *  operation. When the bit is 0, the transfer is a write operation.
 *  
 *  I2C_SLV0_ADDR is used to specify the I2C slave address of Slave 0.
 *  
 *  Data transfer starts at an internal register within Slave 0. This address of this
 *  register is specified by I2C_SLV0_REG.
 *  
 *  The number of bytes transferred is specified by I2C_SLV0_LEN. When more than 1 byte is
 *  transferred (I2C_SLV0_LEN > 1), data is read from (written to) sequential adresses starting
 *  from I2C_SLV0_REG.
 *  
 *  In read mode, the result of the read is placed in the lowest available EXT_SENS_DATA register.
 *  For further information regarding the allocation of read results, please refer to the
 *  EXT_SENS_DATA register description (register 73-96).
 *  
 *  In write mode, the contents of I2C_SLV0_DO (register 99) will be written to the slave device.
 *  
 *  I2C_SLV0_EN enables Slave 0 for I2C data transaction. A data transaction is performed only if
 *  more than zero bytes are to be transferred (I2C_SLV0_LEN >0) between an enabled slave device
 *  (I2C_SLV0_EN = 1).
 *  
 *  I2C_SLV0_BYTE_SW configures byte swapping of word pairs. When byte swapping is enabled, the
 *  high and low bytes of a word pair are swapped. Please refer I2C_SLV0_GPR for the pairing
 *  convention of the word pairs. When this bit is cleared to 0, bytes transferred to and from
 *  Slave 0 will be written to EXT_SENS_DATA registers in the order they were transferred.
 *  
 *  When I2C_SLV0_REG_DIS is set to 1, the transaction will read or write data only. When cleared
 *  to 0, the transaction will write a register address prior to reading or writing data. This bit
 *  should equal to 0 when specifying the register address within the Slave device to/from which the
 *  ensuing data transaction will take place.
 *  
 *  I2C_SLV0_GPR specifies the grouping order of word pairs received from registers. When cleared to
 *  0, bytes from register addresses 0 and 1,2,3, etc. (even, then odd register addresses) are paired
 *  to form a word. When set to 1, bytes from register addresses are paired 1 and 2, 3 and 4 etc. (odd
 *  then even register addresses) are paired to form a word.
 *  
 *  I2C data transactions are performed at the Sample Rate, as defined in register 25. The user is responsible
 *  for ensuring that I2C data transactions to and from each enabled Slave can be completed within a single
 *  period of the Sample Rate.
 *  
 *  The I2C slave access rate can be reduced relative to the Sample Rate. This reduced access rate is
 *  determined by I2C_MST_DLY (register 52). Whether a slave's access rate is reduced relative to the
 *  Sample Rate is determined by I2C_MST_DELAY_CTRL (register 103).
 *  
 *  The processing order for the slaves is fixed. The sequence followed for processing the slaves is
 *  Slave 0, Slave 2, Slave 3 and Slave 4. If a particular Slave is disabled it will be skipped.
 *  
 *  Each slave can either be accessed at the sample rate or at a reduced sample rate. In a case where some 
 *  slaves are accessed at the Sample Rate and some slaves are accessed at the reduced rate, the sequence of 
 *  accessing the slaves (Slave 0 to Slave 4) is still followed. However, the reduced rate slaves will be skipped 
 *  if their access rate dictates that they should not be accessed during that particular cycle. 
 *  
 *  \note For further information regarding the reduced access rate, please refer to register 52. Whether a slave is 
 *  accessed at the Sample Rate or at the reduced rate is determined by the Delay Enable bits in register 103.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */
 
#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"
#include "mpu6050_i2cSlave0Control.h"

/**
 *  \brief Read I2C Slave 0 ADDR register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.8 for more details.
 */
void mpu6050_i2cSlv0AddrReadReg(tMPU6050_I2C_SLV0_ADDR *obj)
{
    uint8_t reg = i2c_receive(MPU6050_I2C_ADDR, MPU6050_I2C_SLV0_ADDR);
    obj->I2C_SLV0_RW = reg >> 7;
    obj->I2C_SLV0_ADDR = reg & 0x7F;
}

/**
 *  \brief Write to I2C Slave 0 ADDR register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.8 for more details.
 */
void mpu6050_i2cSlv0AddrWriteReg(tMPU6050_I2C_SLV0_ADDR *obj)
{
    uint8_t reg = (uint8_t)obj->I2C_SLV0_RW << 7 | (uint8_t)obj->I2C_SLV0_ADDR;
    i2c_write(MPU6050_I2C_ADDR, MPU6050_I2C_SLV0_ADDR, reg);
}

/**
 *  \brief Read I2C Slave 0 REG register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.8 for more details.
 */
void mpu6050_i2c_slv0_reg_readReg(tMPU6050_I2C_SLV0_REG *obj, void (*callback)())
{
    *obj = I2C_receive(MPU6050_I2C_ADDR, MPU6050_I2C_SLV0_REG);

    callback();
}

/**
 *  \brief Write to I2C Slave 0 REG register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.8 for more details.
 */
void mpu6050_i2cSlv0RegWriteReg(tMPU6050_I2C_SLV0_REG *obj)
{
    i2c_write(MPU6050_I2C_ADDR, MPU6050_I2C_SLV0_REG, *obj);
}

/**
 *  \brief Read I2C Slave 0 CTRL register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.8 for more details.
 */
void mpu6050_i2cSlv0CtrlReadReg(tMPU6050_I2C_SLV0_CTRL *obj)
{
    uint8_t reg = i2c_receive(MPU6050_I2C_ADDR, MPU6050_I2C_SLV0_CTRL);
    obj->I2C_SLV0_EN = reg >> 7;
    obj->I2C_SLV0_BYTE_SW = (reg >> 6) & 0x01;
    obj->I2C_SLV0_REG_DIS = (reg >> 5) & 0x01;
    obj->I2C_SLV0_GRP = (reg >> 4) & 0x01;
    obj->I2C_SLV0_LEN = reg & 0x0F;
}

/**
 *  \brief Write to I2C Slave 0 CTRL register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.8 for more details.
 */
void mpu6050_i2cSlv0CtrlWriteReg(tMPU6050_I2C_SLV0_CTRL *obj)
{
    uint8_t reg = (uint8_t)(obj->I2C_SLV0_EN) << 7;
    reg |= (uint8_t)(obj->I2C_SLV0_BYTE_SW) << 6;
    reg |= (uint8_t)(obj->I2C_SLV0_REG_DIS) << 5;
    reg |= (uint8_t)(obj->I2C_SLV0_GRP) << 4;
    reg |= (uint8_t)(obj->I2C_SLV0_LEN);
    i2c_write(MPU6050_I2C_ADDR, MPU6050_I2C_SLV0_CTRL, reg);
}

/**
 *  \brief Read I2C Slave 0 registers
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details Read all I2C Slave 0 registers with one function
 */
void mpu6050_i2cSlv0ReadReg(tMPU6050_I2C_SLV0 *obj)
{
    mpu6050_i2cSlv0AddrReadReg(&(obj->ADDR));
    mpu6050_i2cSlv0RegReadReg(&(obj->REG));
    mpu6050_i2cSlv0CtrlReadReg(&(obj->CTRL));
}

/**
 *  \brief Write to I2C Slave 0 registers
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details Write all I2C Slave 0 registers with one function
 */
void mpu6050_i2cSlv0WriteReg(tMPU6050_I2C_SLV0 *obj)
{
    mpu6050_i2cSlv0AddrWriteReg(&(obj->ADDR));
    mpu6050_i2cSlv0RegWriteReg(&(obj->REG));
    mpu6050_i2cSlv0CtrlWriteReg(&(obj->CTRL));
}