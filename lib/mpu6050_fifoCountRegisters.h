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
 *  \file mpu6050_fifoCountRegisters.h
 *  \brief FIFO Count Registers headerfile
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef MPU6050_FIFOCOUNTREGISTERS_H_
#define MPU6050_FIFOCOUNTREGISTERS_H_

 /**
  *  \brief Datatype for FIFO Count Register values
  *  
  *  Indicates the number of bytes stored in the FIFO
  *  buffer. This number is in turn the number of bytes that can
  *  be read from the FIFO buffer and it is directly proportional to the number
  *  of samples available given the set of sensor data bound to be stored
  *  in the FIF (Register 35 and 36).
  */
typedef uint16_t tMPU6050_FIFO_COUNT;

extern void mpu6050_fifoCountReadReg(tMPU6050_FIFO_COUNT*);
extern void mpu6050_fifoCountWriteReg(tMPU6050_FIFO_COUNT*);

#endif