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
 *  \file mpu6050_i2cSlave0DataOut.h
 *  \brief I2C Slave 0 Data Out headerfile 
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef MPU6050_I2CSLAVEDATAOUT_H_
#define MPU6050_I2CSLAVEDATAOUT_H_

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"

typedef uint8_t tMPU6050_I2C_SLV0_DO;	/**< Datatype for I2C Slave 0 Data Out register */

extern void mpu6050_i2cSlv0DoReadReg(tMPU6050_I2C_SLV0_DO*);
extern void mpu6050_i2cSlv0DoWriteReg(tMPU6050_I2C_SLV0_DO*);

#endif