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
 *  \file mpu6050_bypassEnableConfiguration.h
 *  \brief Bypass Enable Configuration headerfile
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef MPU6050_BYPASSENABLECONFIGURATION_H_
#define MPU6050_BYPASSENABLECONFIGURATION_H_

/**
 *  \brief Interrupt Pin Configuration datatype
 */
typedef struct
{
    /** 
     * When this bit is equal to 0, the logic level for the INT pin is active high.
     * When this bit is equal to 1, the logic level for the INT pin is active low. 
     */
    bool INT_LEVEL;

	/**
	 * When this bit is equal to 0, the INT pin is configured as push-pull.
	 * When this bit is equal to 1, the INT pin is configured as open drain.
	 */
    bool INT_OPEN;

	/**
	 * When this bit is equal to 0, the INT pin emits a 50us long pulse.
	 * When this bit is equal to 1, the INT pin is held high until the interrupt is cleared.
	 */
    bool LATCH_INT_EN;

	/**
	 * When this bit is equal to 0, interrupt status bits are cleared only by reading
	 * INT_STATUS (Register 58).
	 * When this bit is equal to 1, interrupt status bits are cleared on any read operation.
	 */
    bool INT_RD_CLEAR;

	/**
	 * When this bit is equal to 0, the logic level for the FSYNC pin (when used as
	 * an interrupt to the host processor) is active high.
	 * When this bit is equal to 1, the logic level for the FSYNC pin (when used as
	 * an interrupt to the host processor) is active low.
	 */
    bool FSYNC_INT_LEVEL;
	 
	/**
	 * When equal to 0, this bit disables the FSYNC pin from causing an interrupt to the host processor.
	 * When equal to 1, this bit enables the FSYNC pin to be used as an interrupt to the host processor.
	 */
    bool FSYNC_INT_EN;

    /**
     * When this bit is equal to 1 and I2C_MST_EN (Register 106) is equal to 0, the host application
     * processor will be able to directly access the auxiliary I2C bus of the MPU6050.
     * When this bit is equal to 0, the host application processor will not be able to directly
     * access the auxiliary I2C bus of the MPU6050 regardless of the state of I2C_MST_EN.
     * When this bit is equal to 0, the host application processor will not be able to directly
     * access the auxiliary I2C bus of the MPU6050 regardless of the state of I2C_MST_EN. 
	 */
    bool I2C_BYPASS_EN;
}
tMPU6050_INT_PIN_CFG;

extern void mpu6050_intPinCfgReadReg(tMPU6050_INT_PIN_CFG*);
extern void mpu6050_intPinCfgWriteReg(tMPU6050_INT_PIN_CFG*);

#endif
