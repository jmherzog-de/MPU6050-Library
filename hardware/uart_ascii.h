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
 *  \file uart_ascii.h
 *  \brief UART ASCII headerfile
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef UART_ASCII_H_
#define UART_ASCII_H_

#include <stdint.h>
#include <stdbool.h>
#include "uart.h"

void UART_puthex8AsASCII(uint8_t ui8Val);
void UART_puthex16AsASCII(uint16_t ui16Val);
void UART_puthex32AsASCII(uint32_t ui32Val);
void UART_putU8AsASCII(uint8_t ui8Val);
void UART_putS8AsASCII(int8_t i8Val);
void UART_putU16AsASCII(uint16_t ui16Val);
void UART_putS16AsASCII(int16_t i16Val);

#endif