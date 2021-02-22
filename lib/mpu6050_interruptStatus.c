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
 *  \file mpu6050_interruptStatus.c
 *  \brief Brief description
 *  
 *  This register shows the interrupt status of each interrupt generation source.
 *  Each bit will clear after the register is read.
 *  
 *  For information regarding the corresponding interrupt enable bits, pleaser
 *  refer to register 56. For a list of I2C Master interrupts, please refer to
 *  register 54.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include "mpu6050_interruptStatus.h"

/**
 *  \brief Read Interrupt Status register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.16 for more details.
 */
void mpu6050_intStatusReadReg(tMPU6050_INT_STATUS *obj)
{
    uint8_t reg = i2c_receive(MPU6050_I2C_ADDR, MPU6050_INT_STATUS);
    obj->FIFO_OFLOW_INT = reg >> 4;
    obj->I2C_MST_INT = (reg >> 3) & 0x01;
    obj->DATA_RDY_INT = reg & 0x01;
}

/**
 *  \brief Write to Interrupt Status register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.16 for more details.
 */
void mpu6050_intStatusWriteReg(tMPU6050_INT_STATUS *obj)
{
    uint8_t reg = (uint8_t)(obj->FIFO_OFLOW_INT << 4);
    reg |= (uint8_t)(obj->I2C_MST_INT << 3);
    reg |= (uint8_t)(obj->DATA_RDY_INT);
    i2c_write(MPU6050_I2C_ADDR, MPU6050_INT_STATUS, reg);
}