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
 *  \file mpu6050_powerManagement2.c
 *  \brief Brief description
 *  
 *  This register allows the user to configure the frequency of wake-ups in
 *  accelerometer only low power mode. This register also allows the user to
 *  put individual axes of the accelerometer and gyroscope into standby mode.
 *  
 *  The MPU6050 can be put into Accelerometer Only Low Power Mode using the
 *  following steps:
 *  
 *  (i) Set Cycle bit to 1
 *  (ii) Set SLEEP bit to 0
 *  (iii) Set TEMP_DIS bit to 1
 *  (iv) Set STBY_XG, STBY_YG, STBY_ZG bits to 1
 *  
 *  All of the above bits can be found in Power Management 1 register (register 107).
 *  
 *  In this mode, the device will power off all devices except for the primary I2C
 *  interface, waking only the accelerometer at fixed intervals to take a single
 *  measurement. The frequency of wake-ups can be configured with LP_WAKE_CTRL as
 *  shown below.
 *  
 *  |LP_WAKE_CTRL|Wake-up Freq.|
 *  |:----------:|:-----------:|
 *  |     0      |   1.25 Hz   |
 *  |     1      |    5 Hz     |
 *  |     2      |    20 Hz    |
 *  |     3      |    40 Hz    |
 *  
 *  \note For further information regarding MPU6050's power modes, please refer to register 107.
 *  
 *  \note The user can put individual accelerometer and gyroscope axes into standby mode by using this
 *  register. If the device is using a gyroscope axis as the clock source and this axis is put into
 *  standby mode, the clock source will automatically be changed to the internal 8 MHz oscillator.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include "mpu6050_powerManagement2.h"

/**
 *  \brief Read Power Management 2 register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.29 for more details.
 */
void mpu6050_pwr_mgmt_2_readReg(tMPU6050_PWR_MGMT_2 *obj)
{
    uint8_t reg = i2c_receive(MPU6050_I2C_ADDR, MPU6050_PWR_MGMT_2);
    obj->LP_WAKE_CTRL = (reg >> 6) & 0x02;
    obj->STBY_XA = (reg >> 5) & 0x01;
    obj->STBY_YA = (reg >> 4) & 0x01;
    obj->STBY_ZA = (reg >> 3) & 0x01;
    obj->STBY_XG = (reg >> 2) & 0x01;
    obj->STBY_YG = (reg >> 1) & 0x01;
    obj->STBY_ZG = reg & 0x01;
}

/**
 *  \brief Write Power Management 2 register
 *  
 *  \param [in] obj Datatype pointer to register values
 *  
 *  \details See register datasheet chapter 4.29 for more details.
 */
void mpu6050_pwr_mgmt_2_writeReg(tMPU6050_PWR_MGMT_2 *obj)
{
    uint8_t reg = (uint8_t)(obj->LP_WAKE_CTRL) << 6;
    reg |= (uint8_t)(obj->STBY_XA) << 5;
    reg |= (uint8_t)(obj->STBY_YA) << 4;
    reg |= (uint8_t)(obj->STBY_ZA) << 3;
    reg |= (uint8_t)(obj->STBY_XG) << 2;
    reg |= (uint8_t)(obj->STBY_YG) << 1;
    reg |= (uint8_t)(obj->STBY_ZG);
    i2c_write(MPU6050_I2C_ADDR, MPU6050_PWR_MGMT_2, reg);
}