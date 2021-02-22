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
 *  \file mpu6050_powerManagement1.c
 *  \brief Power Management 1
 *  
 *  This register allows the user to configure the power mode and clock source.
 *  It also provides a bit for resetting the entire device and a bit for
 *  disabling the temperature sensor.
 *  
 *  By setting SLEEP to 1, the MPU6050 can be put into Cycle Mode. In Cycle Mode,
 *  the device cycles between sleep mode and waking up to take a single sample of
 *  data from accelerometer at a rate determined by LP_WAKE_CTRL (register 108). To
 *  configure the wake frequency, use LP_WAKE_CTRL within the Power Management 2
 *  register (Register 108).
 *  
 *  An internal 8 MHz oscillator, gyroscope based clock or external sources can be
 *  selected as the MPU6050 clock source. When the internal 8 MHz oscillator or an
 *  external source is chosen as the clock source, the MPU6050 can operate in low
 *  power modes with the gyroscope disabled.
 *  
 *  Upon power up, the MPU6050 clock source defaults to the internal oscillator.
 *  However, it is highly recommended that the device be configured to use one of the
 *  gyroscopes (or an external clock source) as the clock reference for improved
 *  stability. The clock source can be selected according to the following table.
 *  
 *  |CLKSEL|                    Clock Source                         |
 *  |:----:|:-------------------------------------------------------:|
 *  |  0   | Internal 8 Mhz oscillator                               |
 *  |  1   | PLL with X axis gyroscope reference                     |
 *  |  2   | PLL with Y axis gyroscope reference                     |
 *  |  3   | PLL with Z axis gyroscope reference                     |
 *  |  4   | PLL with external 32.768 kHz reference                  |
 *  |  5   | PLL with external 19.2 MHz reference                    |
 *  |  6   | Reserved                                                |
 *  |  7   | Stops the clock and keeps the timing generator in reset |
 *  
 *  \note For further information regarding the MPU6050 clock source, please refer
 *  to the MPU6050 Product Specification document.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include "mpu6050_powerManagement1.h"

/**
 *  \brief Read Power Management 1 register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.28 for more details.
 */
void mpu6050_pwrMgmt1ReadReg(tMPU6050_PWR_MGMT_1 *obj)
{
    uint8_t reg = i2c_receive(MPU6050_I2C_ADDR, MPU6050_PWR_MGMT_1);
    obj->DEVICE_RESET = (reg >> 7) & 0x01;
    obj->SLEEP = (reg >> 6) & 0x01;
    obj->CYCLE = (reg >> 5) & 0x01;
    obj->TEMP_DIS = (reg >> 3) & 0x01;
    obj->CLKSEL = reg & 0x07;
}

/**
 *  \brief Write to Power Management 1 register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.28 for more details.
 */
void mpu6050_pwrMgmt1WriteReg(tMPU6050_PWR_MGMT_1 *obj)
{
    uint8_t reg = (uint8_t)(obj->DEVICE_RESET) << 7;
    reg |= (uint8_t)(obj->SLEEP) << 6;
    reg |= (uint8_t)(obj->CYCLE) << 5;
    reg |= (uint8_t)(obj->TEMP_DIS) << 3;
    reg |= (uint8_t)(obj->CLKSEL);
    i2c_write(MPU6050_I2C_ADDR, MPU6050_PWR_MGMT_1, reg);
}