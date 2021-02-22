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
 *  \file mpu6050_whoAmI.c
 *  \brief Who Am I register reading
 *  
 *  This register is used to verify the identity of the device.
 *  The contents of WHO_AM_I are the upper 6 bits of the MPU6050
 *  I2C address. The least significant bit of the MPU6050's I2C
 *  address is determined by the value of the AD0 pin. The value
 *  of the AD0 pin is not reflected in this register.
 *  
 *  The default value of the register is 0x68.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include "mpu6050_whoAmI.h"

/**
 *  \brief Read Who Am I register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.32 for more details.
 */
void mpu6050_whoAmIReadReg(tMPU6050_WHO_AM_I *obj)
{
    *obj = i2c_receive(MPU6050_I2C_ADDR, MPU6050_WHO_AM_I);
}