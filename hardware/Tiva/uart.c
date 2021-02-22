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
 *  \file uart.c
 *  \brief Brief description
 *  
 *  UART implementation for Tiva TM4C microcontrollers. It contain a function
 *  for UART hardware initialization, sending and receive data.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include "uart.h"

#define UART_PERIPH         SYSCTL_PERIPH_UART0
#define UART_PERIPH_GPIO    SYSCTL_PERIPH_GPIOA
#define UART_GPIO_PINS      (GPIO_PIN_0 | GPIO_PIN_1)
#define UART_PORT_BASE      GPIO_PORTA_BASE
#define UART_BASE           UART0_BASE
#define UART_GPIO_RX        GPIO_PA0_U0RX
#define UART_GPIO_TX        GPIO_PA1_U0TX
#define UART_BAUDRATE       115200
#define UART_CONFIG         (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE)

/**
 *  \brief Tiva UART hardware initialization
 *  
 *  This function initializes the UART0 on PORTA with PIN0 and PIN1.
 *  Edit the define variables to change it.
 */
void uart_initialization()
{
    SysCtlPeripheralEnable(UART_PERIPH);
    SysCtlPeripheralEnable(UART_PERIPH_GPIO);
    GPIOPinConfigure(UART_GPIO_RX);
    GPIOPinConfigure(UART_GPIO_TX);
    GPIOPinTypeUART(UART_PORT_BASE, UART_CLOCK_SYSTEM);
    UARTConfigSetExpClk(UART_BASE, SysCtlClockGet(), UART_BAUDRATE, UART_CONFIG);
}

/**
 *  \brief Tiva UART send string
 *  
 *  \param [in] pucBuffer character string to transmit
 *  
 *  Transmit a character string with a line break at the
 *  end of the string.
 */
void uart_puts(const unsigned char* pucBuffer)
{
    while(*pucBuffer != '\0')
        UARTCharPut(UART_BASE, *pucBuffer);

    UARTCharPut(UART_BASE, '\n');
}

/**
 *  \brief Tiva UART send single character
 *  
 *  \param [in] character Character to transmit
 *  
 *  Transmit a single character over UART.
 */
void uart_putc(unsigned char character)
{
    UARTCharPut(UART_BASE, character);
}