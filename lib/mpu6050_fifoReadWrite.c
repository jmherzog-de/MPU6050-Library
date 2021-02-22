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
 *  \file mpu6050_fifoReadWrite.c
 *  \brief FIFO Read/Write
 *  
 *  This register is used to read and write data from the FIFO buffer.
 *  
 *  Data is written to the FIFO in order of register number (from lowest to highest).
 *  If all the FIFO enable flags (see below) are enabled and all External Sensor Data
 *  registers (register 73 to 96) are associated with a Slave device, the contents of
 *  registers 59 through 96 will be written in order at the Sample Rate.
 *  
 *  The contents of the sensor data registers (registers 59 to 96) are written into the
 *  FIFO buffer when their corresponding FIFO enable flags are set to 1 in FIFO_EN (register 35).
 *  An additional flag for the sensor data registers associated with I2C Slave 3 can be found
 *  in I2C_MST_CTRL (register 36).
 *  
 *  If the FIFO buffer has overflowed, the status bit FIFO_OFLOW_INT is automatically set to 1.
 *  This bit is located in INT_STATUS (register 58). When the FIFO buffer has overflowed, the oldest
 *  data will be lost and new data will be written to the FIFO.
 *  
 *  If the FIFO buffer is empty, reading this register will return the last byte that was
 *  previously read from the FIFO until new data is available. The user should check FIFO_COUNT
 *  to ensure that the FIFO buffer is not read when empty.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"
#include "mpu6050_fifoReadWrite.h"

/**
 *  \brief Read FIFO Read Write register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.31 for more details.
 */
void mpu6050_fifoRwReadReg(tMPU6050_FIFO_R_W *obj)
{
    *obj = i2c_receive(MPU6050_I2C_ADDR, MPU6050_FIFO_R_W);
}

/**
 *  \brief Write to FIFO Read Write register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.31 for more details.
 */
void mpu6050_fifoRwWriteReg(tMPU6050_FIFO_R_W *obj)
{
    i2c_write(MPU6050_I2C_ADDR, MPU6050_FIFO_R_W, *obj);
}