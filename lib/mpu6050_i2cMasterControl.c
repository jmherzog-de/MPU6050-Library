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
 *  \file mpu6050_i2cMasterControl.c
 *  \brief I2C Master Control
 *  
 *  This register shows the status of the interrupt generating signals
 *  in the I2C Master within the MPU6050. This register also communicates
 *  the status of the FSYNC interrupt to the host processor.
 *  
 *  \note Reading this register will clear all the status bits in the register.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */
 
#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"
#include "mpu6050_i2cMasterControl.h"

/**
 *  \brief Read I2C Master Control register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.7 for more details.
 */
void mpu6050_i2cMstCtrlReadReg(tMPU6050_I2C_MST_CTRL *obj)
{
    uint8_t reg = i2c_receive(MPU6050_I2C_ADDR, MPU6050_I2C_MST_CTRL);
    obj->MULTI_MST_EN = reg >> 7;
    obj->WAIT_FOR_ES = (reg >> 6) & 0x01;
    obj->SLV_3_FIFO_EN = (reg >> 5) & 0x01;
    obj->I2C_MST_P_NSR = (reg >> 4) & 0x01;
    obj->I2C_MST_CLK = reg & 0x0F;
}