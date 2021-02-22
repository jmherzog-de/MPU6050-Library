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
 *  \file mpu6050_interruptEnable.c
 *  \brief Interrupt Enable
 *  
 *  This register enables interrupt generation by interrupt sources.
 *  
 *  For information regarding the interrupt status for each interrupt
 *  generation source, please refer to register 58. Further information
 *  regarding I2C Master interrupt generation can be found in register 54.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include "mpu6050_interruptEnable.h"

/**
 *  \brief Read Interrupt Enable register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.15 for more details.
 */
void mpu6050_intEnableReadReg(tMPU6050_INT_ENABLE *obj)
{
    uint8_t reg = i2c_receive(MPU6050_I2C_ADDR, MPU6050_INT_ENABLE);
    obj->FIFO_OFLOW_EN = (reg >> 4) & 0x01;
    obj->I2C_MST_INT_EN = (reg >> 3) & 0x01;
    obj->DATA_RDY_EN = reg & 0x01;
}

/**
 *  \brief Write to Interrupt Enable register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.15 for more details.
 */
void mpu6050_intEnableWriteReg(tMPU6050_INT_ENABLE *obj)
{
    uint8_t reg = obj->FIFO_OFLOW_EN << 4;
    reg |= obj->I2C_MST_INT_EN << 3;
    reg |= obj->DATA_RDY_EN;
    i2c_write(MPU6050_I2C_ADDR, MPU6050_INT_ENABLE, reg);
}