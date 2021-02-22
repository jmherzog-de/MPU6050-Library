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
 *  \file mpu6050_fifoCountRegisters.c
 *  \brief FIFO Count Registers
 *  
 *  These registers keep track of the number of samples currently in the FIFO buffer.
 *  
 *  These registers shadow the FIFO Count value. Both registers are loaded with the
 *  current sample count when FIFO_COUNT_H (register 72) is read.
 *  
 *  \note Reading only FIFO_COUNT_L will not update the registers to the current sample
 *  count. FIFO_COUNT_H must be accessed first to update the contents of both these registers.
 *  
 *  \note FIFO_COUNT should always be read in high-low order in order to guarantee that the
 *  most current FIFO Count value is read.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"
#include "mpu6050_fifoCountRegisters.h"

/**
 *  \brief Read from FIFO Count register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.30 for more details.
 */
void mpu6050_fifoCountReadReg(tMPU6050_FIFO_COUNT *obj)
{
    uint16_t high = i2c_receive(MPU6050_I2C_ADDR, MPU6050_FIFO_COUNTH);
    uint16_t low = i2c_receive(MPU6050_I2C_ADDR, MPU6050_FIFO_COUNTL);
    *obj = (high << 8) | low;
}

/**
 *  \brief Write to FIFO Count register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.30 for more details.
 */
void mpu6050_fifoCountWriteReg(tMPU6050_FIFO_COUNT *obj)
{
    uint16_t high = *obj >> 8;
    uint16_t low = *obj & 0xFF;
    i2c_write(MPU6050_I2C_ADDR, MPU6050_FIFO_COUNTH, high);
    i2c_write(MPU6050_I2C_ADDR, MPU6050_FIFO_COUNTL, low);
}