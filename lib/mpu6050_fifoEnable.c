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
 *  \file mpu6050_fifoEnable.c
 *  \brief FIFO Enable
 *  
 *  This register determines which sensor measurements are loaded into the
 *  FIFO buffer.
 *  
 *  Data stored inside the sensor data register (register 59 to 96) will be
 *  loaded into the FIFO buffer if a sensor's respective FIFO_EN bit set to 1
 *  in this register.
 *  
 *  When a sensor's FIFO_EN bit is enabled in this register, data from the sensor
 *  data registers will be loaded into the FIFO buffer. The sensors are sampled
 *  at the Sample Rate as defined in register 25. For further information
 *  regarding sensor data registers, please refer to register 59 to 96.
 *  
 *  When an external Slave's corresponding FIFO_EN bit (SLVx_FIFO_EN) is set to
 *  1, the data stored in its corresponding data registers (EXT_SENS_DATA register
 *  association with I2C Slaves is determined by the I2C_SLVx_CTRL registers.
 *  For information regarding EXT_SENS_DATA registers, please refer to
 *  register 73 to 96.
 *  
 *  Note that the corresponding FIFO_EN bit (SLV3_FIFO_EN) is found in I2C_MSR_CTRL
 *  (register 36). Also note that Slave 4 behaves in a different manner compared to
 *  Slaves 0-3. Please refer to register 49 to 53 for further information regarding
 *  Slave 4 usage.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "mpu6050_reg.h"
#include "mpu6050_fifoEnable.h"

/**
 *  \brief Read FIFO Enable register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.6 for more details.
 */
void mpu6050_fifoEnReadReg(tMPU6050_FIFO_EN *obj)
{
    uint8_t reg = i2c_receive(MPU6050_I2C_ADDR, MPU6050_FIFO_EN);
    obj->TEMP_FIFO_EN = reg >> 7;
    obj->XG_FIFO_EN = (reg >> 6) & 0x01;
    obj->YG_FIFO_EN = (reg >> 5) & 0x01;
    obj->ZG_FIFO_EN = (reg >> 4) & 0x01;
    obj->ACCEL_FIFO_EN = (reg >> 3) & 0x01;
    obj->SLV2_FIFO_EN = (reg >> 2) & 0x01;
    obj->SLV1_FIFO_EN = (reg >> 1 ) & 0x01;
    obj->SLV0_FIFO_EN = reg & 0x01;
}

/**
 *  \brief Write to FIFO Enable register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.6 for more details.
 */
void mpu6050_fifoEnWriteReg(tMPU6050_FIFO_EN *obj)
{
    uint8_t reg = (uint8_t)(obj->TEMP_FIFO_EN) << 7;
    reg |= (uint8_t)(obj->XG_FIFO_EN) << 6;
    reg |= (uint8_t)(obj->YG_FIFO_EN) << 5;
    reg |= (uint8_t)(obj->ZG_FIFO_EN) << 4;
    reg |= (uint8_t)(obj->ACCEL_FIFO_EN) << 3;
    reg |= (uint8_t)(obj->SLV2_FIFO_EN) << 2;
    reg |= (uint8_t)(obj->SLV1_FIFO_EN) << 1;
    reg |= (uint8_t)(obj->SLV0_FIFO_EN);
    i2c_write(MPU6050_I2C_ADDR, MPU6050_FIFO_EN, reg);
}