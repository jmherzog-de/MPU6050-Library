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
 *  \file i2c.h
 *  \brief Tiva I2C headerfile
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_i2c.h"
#include "inc/hw_memmap.h"
#include "driverlib/i2c.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"

void i2c_initialization();
uint32_t i2c_receive(uint8_t ui8SlaveAddr, uint8_t ui8Reg);
void i2c_write(uint8_t ui8SlaveAddr, uint8_t ui8Reg, uint8_t ui8Data);

#endif