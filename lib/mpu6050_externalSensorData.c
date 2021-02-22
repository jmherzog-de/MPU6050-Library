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
 *  \file mpu6050_externalSensorData.c
 *  \brief External Sensor Data
 *  
 *  These registers store data read from external sensors by the Slave 0,1,2 and 3
 *  on the auxillary I2C interface. Data read by Slave 4 is stored in I2C_SLV4_DI (Register 53).
 *  
 *  External sensor data written to these registers at the Sample Rate as defined in Register 25.
 *  This access rate can be reduced by using the Slave Delay Enable registers (Register 103).
 *  
 *  External sensor data registers, along with gyroscope measurement registers, accelerometer
 *  measurement registers and temperature measurement registers, are composed of two sets of
 *  registers: an internal set and a user-facing read register set.
 *  
 *  The data within the external sensors internal register set is always updated at the 
 *  Sample Rate (or the reduced access rate) whenever the serial interface is idle. The
 *  gurantees that a burst read of sensor registers will read measurements from the same
 *  sampling instant. Note that if burst reads are not used, the user is responsible for
 *  ensuring a set of single byte reads correspond to  a single sampling instant by checking the
 *  Data Ready interrupt.
 *  
 *  Data is placed in these external sensor data registers according to I2C_SLV0_CTRL, I2C_SLV1_CTRL,
 *  I2C_SLV3_CTRL (registers 39, 42, 45 and 48). When more than zero bytes are read (I2C_SLVx_LEN > 0)
 *  from an enabled slave (I2C_SLVx_EN = 1), the slave is read at the Sample Rate (as defined in register 25)
 *  or delayed rate (if specified in register 52 and 103). During each Sample cycle, slave reads are performed
 *  in order of Slave number. If all slaves are enabled with more than zero bytes to be read, the order will
 *  be Slave 0, followed by Slave 1, Slave 2 and Slave 3.
 *  
 *  Each enabled slave will have EXT_SENS_DATA registers associated with it by number ob bytes read
 *  (I2C_SLVx_LEN) in order of slave number, starting from EXT_SENS_DATA_00. Note that this means
 *  enabling or disabling a slave may change the higher numbered slaves associated registers.
 *  Furthermore, if fewer total bytes are being read from external sensors as a result of such a
 *  change, then the data remaining in the registers which no longer have an associated slave device
 *  (i.e. high numbered registers) will remain in these previously allocated registers unless reset.
 *  
 *  If the sum of the read lengths of all SLVx transactions exceed the number of available EXT_SENS_DATA
 *  registers, the excess bytes will be dropped. There are 24 EXT_SENS_DATA registers and hence the total
 *  read lengths between all the slaves cannot be greater than 24 or some bytes will be lost.
 *  
 *  Note: Slave 4's behavior is distinct from that of Slaves 0-3. For furhter information regarding the
 *  characteristics of Slave 4, please refer to register 49 to 53.
 *  
 *  \note Example can be found at the register datasheet on page 33.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"
#include "mpu6050_externalSensorData.h"

/**
 *  \brief Read from a specific External Sensor Data Register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  \param [in] number External sensor data number (0-23)
 *  
 *  \details See register datasheet chapter 4.20 for more details 
 */
void mpu6050_extSensDataReadReg(tMPU6050_EXT_SENS_DATA *obj, uint8_t number)
{
    if(number > 23)
    {
        callback();
        return;
    }

    *obj = i2c_receive(MPU6050_I2C_ADDR, (MPU6050_EXT_SENS_DATA_00 + number) );
}

/**
 *  \brief Write to a specific External Sensor Data Register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  \param [in] number Description for number
 *  
 *  \details See register datasheet chapter 4.20 for more details 
 */
void mpu6050_extSensDataWriteReg(tMPU6050_EXT_SENS_DATA *obj, uint8_t number)
{
    if(number > 23)
    {
        return;
    }

    i2c_write(MPU6050_I2C_ADDR, (MPU6050_EXT_SENS_DATA_00 + number), *obj);
}

/**
 *  \brief Read from all External Sensor Data Registers
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.20 for more details 
 */
void mpu6050_extSensDataAllReadReg(tMPU6050_EXT_SENS_DATA_ALL *obj)
{
    uint8_t n = 0;
    uint8_t addr;
    for(addr = MPU6050_EXT_SENS_DATA_00; addr <= MPU6050_EXT_SENS_DATA_23; addr++)
    {
        obj->DATA[n] = i2c_receive(MPU6050_I2C_ADDR, addr);
        n++;
    }
}

/**
 *  \brief Write to all External Sensor Data Registers
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.20 for more details 
 */
void mpu6050_extSensDataAllWriteReg(tMPU6050_EXT_SENS_DATA_ALL *obj)
{
    uint8_t n = 0;
    uint8_t addr;
    for(addr = MPU6050_EXT_SENS_DATA_00; addr <= MPU6050_EXT_SENS_DATA_23; addr++)
    {
        i2c_write(MPU6050_I2C_ADDR, addr, obj->DATA[n]);
        n++;
    }
}