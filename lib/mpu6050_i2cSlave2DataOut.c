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
 *  \file mpu6050_i2cSlave2DataOut.c
 *  \brief I2C Slave 2 Data Out
 *  
 *  This register holds the output data written into Slave 2 when Slave 2 is set
 *  to write mode.
 *  
 *  \note For further information regarding Slave 2 control, please refer to
 *  register 43 to 45.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include "mpu6050_i2cSlave2DataOut.h"

/**
 *  \brief Read I2C Slave 2 Data Out register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.23 for more details.
 */
void mpu6050_i2cSlv2DoReadReg(tMPU6050_I2C_SLV2_DO *obj)
{
    *obj = i2c_receive(MPU6050_I2C_ADDR, MPU6050_I2C_SLV2_DO);
}

/**
 *  \brief Write to I2C Slave 2 Data Out register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.23 for more details.
 */
void mpu6050_i2cSlv2DoWriteReg(tMPU6050_I2C_SLV2_DO *obj)
{
    i2c_write(MPU6050_I2C_ADDR, MPU6050_I2C_SLV2_DO, *obj);
}