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
 *  \file uart_ascii.c
 *  \brief Sending hex values as ASCII characters over UART
 *  
 *  This file defines functions to send hex values as ASCII characters
 *  over UART.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include "uart_ascii.h"

/**
 *  \brief Send 8 bit hex value over UART
 *  
 *  \param [in] ui8Val Value to convert and transmit
 */
void uart_puthex8AsASCII(uint8_t ui8Val)
{
    // extract upper and lower nibble from input value
    uint8_t upperNibble = (ui8Val & 0xF0) >> 4;
    uint8_t lowerNibble = (ui8Val & 0x0F);

    // convert nibble to ASCII hex value
    upperNibble += upperNibble > 9 ? 'A' - 10 : '0';
    lowerNibble += lowerNibble > 9 ? 'A' - 10 : '0';

    // send two ASCII values
    uart_putc(upperNibble);
    uart_putc(lowerNibble);
}

/**
 *  \brief Send 16 bit hex value over UART
 *  
 *  \param [in] ui16Val Value to convert and transmit
 */
void uart_puthex16AsASCII(uint16_t ui16Val)
{
    // transmit high byte
    uart_puthex8AsASCII((uint8_t)(ui16Val >> 8));

    // transmit low byte
    uart_puthex8AsASCII((uint8_t)(ui16Val & 0xFF));
}

/**
 *  \brief Send 32 bit hex value over UART
 *  
 *  \param [in] ui32Val Value to convert and trasnmit
 */
void uart_puthex32AsASCII(uint32_t ui32Val)
{
    // transmit upper 16 bit
    uart_puthex16AsASCII((uint16_t)(ui32Val >> 16));

    // transmit lower 16 bit
    uart_puthex16AsASCII((uint16_t)(ui32Val & 0xFFFF));
}

/**
 *  \brief Send 8 bit unsigned decimal over UART
 *  
 *  \param [in] ui8Val Value to convert and transmit
 */
void uart_putU8AsASCII(uint8_t ui8Val)
{
    uint8_t digit1 = '0', digit2 = '0';

    while(ui8Val >= 100)
    {
        ui8Val -= 100;
        digit1++;
    }
    while(ui8Val >= 10)
    {
        ui8Val -= 10;
        digit2++;
    }

    // send first character (or ignore leading 0)
    if(digit1 != '0') uart_putc(digit1);

    // send second character (or ignore leading 0)
    if(digit1 != '0' || (digit2 != '0')) uart_putc(digit2);

    // send last character
    uart_putc(ui8Val + '0');
}

/**
 *  \brief Send 8 bit signed decimal over UART
 *  
 *  \param [in] i8Val Value to convert and transmit
 */
void uart_putS8AsASCII(int8_t i8Val)
{
    // negative number ? bit 7 -> 1
    if(i8Val & 0x80)
    {
        // send sign
        uart_putc('-');

        // convert to positive number
        i8Val = -(i8Val);
    }
    // send number
    uart_putU8AsASCII(i8Val);
}

/**
 *  \brief Send 16 bit unsigned decimal over UART
 *  
 *  \param [in] ui16Val Value to convert and transmit
 */
void uart_putU16AsASCII(uint16_t ui16Val)
{
    uint8_t digit1 = '0', digit2 = '0', digit3= '0', digit4 = '0';

    // extract 10000
    while( ui16Val >= 10000)
    {
        ui16Val -= 10000;
        digit1++;
    }
    // extract 1000
    while(ui16Val >= 1000)
    {
        ui16Val -= 1000;
        digit2++;
    }
    // extract 100
    while(ui16Val >= 100)
    {
        ui16Val -= 100;
        digit3++;
    }
    // extract 10
    while(ui16Val >= 10)
    {
        ui16Val -= 10;
        digit4++;
    }

    bool prevprint = 0; // previous place > 0 flag

    // send 10000 (or ignore leading 0)
    if(digit1 != '0')
    {
        uart_putc(digit1);
        prevprint = 1;
    }
    // send 1000 (or ignore leading 0)
    if(prevprint || digit2 != '0')
    {
        uart_putc(digit2);
        prevprint = 1;
    }
    // send 100 (or ignore leading 0)
    if(prevprint || digit3 != '0')
    {
        uart_putc(digit3);
        prevprint = 1;
    }
    // send 10 (or ignore leading 0)
    if(prevprint || digit4 != '0')
    {
        uart_putc(digit4);
    }
    // send last character
    uart_putc(ui16Val + '0');
}

/**
 *  \brief Send 16 bit signed decimal over UART
 *  
 *  \param [in] i16Val Value to convert and transmit
 */
void uart_putS16AsASCII(int16_t i16Val)
{
    if(i16Val & 0x8000)
    {
        UART_putc('-');
        i16Val = ~(i16Val-1);
    }
    uart_putU16AsASCII((uint16_t)i16Val);
}