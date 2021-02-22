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
 *  \file i2c.c
 *  \brief Brief description
 *  
 *  I2C implementation for Tiva TM4C microcontrollers. It contain a function
 *  for I2C hardware initialization, sending and receive data.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include "i2c.h"

#define I2C_SYSCTL_PERIPH       SYSCTL_PERIPH_I2C0
#define I2C_BASE                I2C0_BASE
#define I2C_PERIPH_PORT         SYSCTL_PERIPH_GPIOB
#define I2C_PORT_BASE           GPIO_PORTB_BASE
#define I2C_PIN_SCL             GPIO_PIN_2
#define I2C_PIN_SDA             GPIO_PIN_3


/**
 *  \brief Tiva I2C hardware initialization
 *  
 *  This functions initializes the I2C0 on PORTB at PIN2 and PIN3.
 *  Edit the define variables to change it.
 */
void i2c_initialization()
{
    // GPIO configuration
    SysCtlPeripheralEnable(I2C_PERIPH_PORT);

    // enable I2C peripheral for GPIO
    SysCtlPeripheralEnable(I2C_SYSCTL_PERIPH);

    GPIOPinConfigure(GPIO_PB2_I2C0SCL);
    GPIOPinConfigure(GPIO_PB3_I2C0SDA);

    // select the I2C function for these pins
    GPIOPinTypeI2CSCL(I2C_PORT_BASE, I2C_PIN_SCL);
    GPIOPinTypeI2C(I2C_PORT_BASE, I2C_PIN_SDA);

    // reset module
    SysCtlPeripheralReset(I2C_SYSCTL_PERIPH);

    // wait for the I2C bus to be ready
    while(!SysCtlPeripheralReady(I2C_SYSCTL_PERIPH)){}

    // initialize master and slave
    I2CMasterInitExpClk(I2C_BASE, SysCtlClockGet(), true);

    // Clear I2C FIFOs
    I2CRxFIFOFlush(I2C_BASE);
}

/**
 *  \brief Tiva I2C receive register data
 *  
 *  \param [in] ui8SlaveAddr I2C slave address of the MPU6050 sensor
 *  \param [in] ui8Reg Register address to read from
 *  \return Received data from sensor
 *  
 *  Transmit a burst command with the register address and read
 *  the incomming data.
 */
 uint32_t i2c_receive(uint8_t ui8SlaveAddr, uint8_t ui8Reg)
{
    // specify that we are writing (a register address) to the
    // slave device
    I2CMasterSlaveAddrSet(I2C0_BASE, ui8SlaveAddr, false);

    // specify register to be read
    I2CMasterDataPut(I2C0_BASE, ui8Reg);

    // send control byte and register address byte to slave device
    I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_START);

    // wait for MCU to finish transaction
    while(I2CMasterBusy(I2C0_BASE));

    // specify that we are going to read from slave device
    I2CMasterSlaveAddrSet(I2C0_BASE, ui8SlaveAddr, true);

    // send control byte and read from the register we specified
    I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_SINGLE_RECEIVE);

    // wait for MCU to finish transaction
    while(I2CMasterBusy(I2C0_BASE));

    // return data pulled from the specified register
    return I2CMasterDataGet(I2C0_BASE);
}

/**
 *  \brief Tiva I2C write register data
 *  
 *  \param [in] ui8SlaveAddr I2C slave address of the MPU6050 sensor
 *  \param [in] ui8Reg Register address to write
 *  \param [in] ui8Data Data to transmit into register
 *  
 *  Transmit two bytes. First databyte contain the register address where
 *  to store the new data. Second byte contains the data.
 */
void i2c_write(uint8_t ui8SlaveAddr, uint8_t ui8Reg, uint8_t ui8Data)
{
    // Tell the master module what address it will be place on the bus when
    // communicating with the slave
    I2CMasterSlaveAddrSet(I2C0_BASE, ui8SlaveAddr, false);

    // put data to be sent into FIFO
    I2CMasterDataPut(I2C0_BASE, ui8Reg);

    // initiate send of data from the MCU
    I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_START);

    // wait until MCU is done transferring.
    while(I2CMasterBusy(I2C0_BASE));

    // put next piece of data into I2C FIFO
    I2CMasterDataPut(I2C0_BASE, ui8Data);

    // send next data that was just placed into FIFO
    I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);

    // wait until MCU is done transferring.
    while(I2CMasterBusy(I2C0_BASE));
}