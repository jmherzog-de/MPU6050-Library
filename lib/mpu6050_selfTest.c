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
 *  \file mpu6050_selfTest.c
 *  \brief Self Test
 *  
 *  These registers are used for gyroscope and accelerometer self-tests that
 *  permit the user to test the mechanical and electrical portions of the 
 *  gyroscope and the accelerometer. The following sections descripe the
 *  self-test process.
 *  
 *  1. Gyroscope Hardware Self-Test: Relative Method
 *  
 *  When self-test is activated, the on-board electronics will actuate
 *  the appropriate sensor. This actuation will move the sensor's proof
 *  masses over a distance equivalent to a pre-defined Coriolis force.
 *  This proof mass displacement results in a change in the sensor
 *  output, which is reflected in the output signal. The output signal is
 *  used to observe the self-test response.
 *  
 *  The self-test response (STR) is defined as follows:
 *  
 *  SelfTestResponse = Gyro. output with SelfT. Enabled - Gyro. output with SelfT. disabled
 *  
 *  This self test-response is used to determine wheter the part has passed or failed self-test
 *  by finding the change from factory trim of the self-test response as follows:
 *  
 *  Change from Factory Trim of the Self-Test Response(%)=(STR-FT)/FT
 *  
 *  FT: Factory trim value of self test response, available via MotionApps software
 *  
 *  This change from factory trim of the self-test response must be within the limits provided
 *  in the MPU6050 Product Specification document for the part to pass self-test. Otherwise, the
 *  part is deemed to have failed self-test.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"
#include "mpu6050_selfTest.h"

/**
 *  \brief Read Self Test register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.1 for more details.
 */
void mpu6050_selftestRegRead(tMPU6050_SELF_TEST *obj)
{
    uint8_t x_reg = i2c_receive(MPU6050_I2C_ADDR, MPU6050_SELF_TEST_X);
    uint8_t y_reg = i2c_receive(MPU6050_I2C_ADDR, MPU6050_SELF_TEST_Y);
    uint8_t z_reg = i2c_receive(MPU6050_I2C_ADDR, MPU6050_SELF_TEST_Z);
    uint8_t a_reg = i2c_receive(MPU6050_I2C_ADDR, MPU6050_SELF_TEST_A);

    obj->XG_TEST = x_reg & 0x1F;
    obj->YG_TEST = y_reg & 0x1F;
    obj->ZG_TEST = z_reg & 0x1F;

    obj->XA_TEST = (x_reg & 0xE0) >> 3;
    obj->XA_TEST = obj->XA_TEST | (( a_reg >> 4) & 0x03);

    obj->YA_TEST = (y_reg & 0xE0) >> 3;
    obj->YA_TEST = obj->YA_TEST | (( a_reg >> 2) & 0x03);

    obj->ZA_TEST = (z_reg & 0xE0) >> 3;
    obj->ZA_TEST = obj->ZA_TEST | (a_reg & 0x03);
}

/**
 *  \brief Write Self Test register
 *  
 *  \param [in] obj Datatype pointer to register values
 *  
 *  \details See register datasheet chapter 4.1 for more details.
 */
void mpu6050_selftestRegWrite(tMPU6050_SELF_TEST *obj)
{
    uint8_t reg;

    reg = (((uint8_t)obj->XA_TEST >> 2) << 5) | ((uint8_t)obj->XG_TEST);
    i2c_write(MPU6050_I2C_ADDR, MPU6050_SELF_TEST_X, reg);

    reg = (((uint8_t)obj->YA_TEST >> 2) << 5) | ((uint8_t)obj->YG_TEST);
    i2c_write(MPU6050_I2C_ADDR, MPU6050_SELF_TEST_Y, reg);

    reg = (((uint8_t)obj->ZA_TEST >> 2) << 5) | ((uint8_t)obj->ZG_TEST);
    i2c_write(MPU6050_I2C_ADDR, MPU6050_SELF_TEST_Z, reg);

    reg = (((uint8_t)obj->XA_TEST & 0x03) << 4) | (((uint8_t)obj->YA_TEST & 0x03) << 2) | ((uint8_t)obj->ZA_TEST & 0x03);
    i2c_write(MPU6050_I2C_ADDR, MPU6050_SELF_TEST_A, reg);
}