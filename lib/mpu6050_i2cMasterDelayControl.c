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
 *  \file mpu6050_i2cMasterDelayControl.c
 *  \brief I2C Master Delay Control
 *  
 *  This register is used to specify the timing of external sensor data
 *  shadowing. The register is also used to decrease the access rate of
 *  slave devices realtive to the Sample Rate.
 *  
 *  When DELAY_ES_SHADOW is set to 1, shadowing of external sensor data
 *  is delayed until all data has been received.
 *  
 *  When I2C_SLV4_DLY_EN, I2C_SLV3_DLY_EN, I2C_SLV2_DLY_EN, I2C_SLV1_DLY_EN and
 *  I2C_SLV0_DLY_EN are enabled, the rate of access for the corresponding slave
 *  devices is reduced.
 *  
 *  When a slave's access rate is decreased relative to the Sample Rate, the slave
 *  is accessed every 1/(1+I2C_MST_DLY) samples.
 *  
 *  This base Sample Rate in turn is determined by SMPLRT_DIV (register 25) and
 *  DLPF_CFG (register 26).
 *  
 *  \note For further information regarding I2C_MST_DLY, please reger to register 52.
 *  \note For further information regarding Sample Rate, please refer to register 25.
 *  
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#include "mpu6050_i2cMasterDelayControl.h"

/**
 *  \brief Read I2C Master Delay Control register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.1 for more details.
 */
void mpu6050_i2cMstDelayCtrlReadReg(tMPU6050_I2C_MST_DELAY_CTRL *obj)
{
    uint8_t reg = I2C_receive(MPU6050_I2C_ADDR, MPU6050_I2C_MST_DELAY_CT_RL);
    obj->DELAY_ES_SHADOW  = reg >> 7;
    obj->I2C_SLV4_DLY_EN = (reg >> 4) & 0x01;
    obj->I2C_SLV3_DLY_EN = (reg >> 3) & 0x01;
    obj->I2C_SLV2_DLY_EN = (reg >> 2) & 0x01;
    obj->I2C_SLV1_DLY_EN = (reg >> 1) & 0x01;
    obj->I2C_SLV0_DLY_EN = reg  & 0x01;
}

/**
 *  \brief Write to I2C Master Delay Control register
 *  
 *  \param [in] obj Datatype pointer to return register values
 *  
 *  \details See register datasheet chapter 4.1 for more details.
 */
void mpu6050_i2cMstDelayCtrlWriteReg(tMPU6050_I2C_MST_DELAY_CTRL *obj)
{
    uint8_t reg = obj->DELAY_ES_SHADOW << 7;
    reg |= obj->I2C_SLV4_DLY_EN << 4;
    reg |= obj->I2C_SLV3_DLY_EN << 3;
    reg |= obj->I2C_SLV2_DLY_EN << 2;
    reg |= obj->I2C_SLV1_DLY_EN << 1;
    reg |= obj->I2C_SLV0_DLY_EN;
    i2c_write(MPU6050_I2C_ADDR, MPU6050_I2C_MST_DELAY_CT_RL, reg);
}