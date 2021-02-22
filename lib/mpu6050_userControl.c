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
 *  \file mpu6050_userControl.c
 *  \brief User Control
 *  
 *  This register allows the user to enable and disable the FIFO buffer, I2C Master
 *  Mode and primary I2C Interface. The FIFO buffer, I2C Master, sensor signal paths
 *  and sensor registers can also be reset using this register.
 *  
 *  When I2C_MST_EN is set to 1, I2C Master Mode is enabled. In this mode, the MPU6050
 *  acts as the I2C Master to external sensor slave devices on the auxiliary I2C bus.
 *  When this bit is cleared to 0, the auxiliary I2C bus lines (AUX_DA and AUX_CL) are
 *  logically driven by the primary I2C bus (SDA and SCL). This is a precondition to
 *  enabling Bypass Mode. For further information regarding Bypass Mode, please refer
 *  to register 55.
 *  
 *  \note Always write 0 to I2C_IF_DIS.
 *  \note When the reset bits (FIFO_RESET, I2C_MST_RESET and SIG_COND_RESET) are set to 1
 *  these reset bits will trigger a reset and then clear to 0.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include "mpu6050_userControl.h"

/**
 *  \brief Read User Control register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.27 for more details.
 */
void mpu6050_userCtrlReadReg(tMPU6050_USER_CTRL *obj)
{
    uint8_t reg = i2c_receive(MPU6050_I2C_ADDR, MPU6050_USER_CTRL);
    obj->FIFO_EN = (reg >> 6) & 0x01;
    obj->I2C_MST_EN = (reg >> 5) & 0x01;
    obj->I2C_IF_DIS = (reg >> 4) & 0x01;
    obj->FIFO_RESET = (reg >> 2) & 0x01;
    obj->I2C_MST_RESET = (reg >> 1) & 0x01;
    obj->SIG_COND_RESET = reg & 0x01;
}

/**
 *  \brief Write User Control register
 *  
 *  \param [in] obj Datatype pointer to register values
 *  
 *  \details See register datasheet chapter 4.27 for more details.
 */
void mpu6050_userCtrlWriteReg(tMPU6050_USER_CTRL *obj)
{
    uint8_t reg = obj->FIFO_EN << 6;
    reg |= obj->I2C_MST_EN << 5;
    reg |= obj->I2C_IF_DIS << 4;
    reg |= obj->FIFO_RESET << 2;
    reg |= obj->I2C_MST_RESET << 1;
    reg |= obj->SIG_COND_RESET;
    i2c_write(MPU6050_I2C_ADDR, MPU6050_USER_CTRL, reg);
}