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
 *  \file mpu6050_fifoEnable.h
 *  \brief FIFO Enable headerfile
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef MPU6050_FIFOENABLE_H_
#define MPU6050_FIFOENABLE_H_

typedef struct
{
    bool TEMP_FIFO_EN;	/**< Setting this bit enables TEMP_OUT_H and TEMP_OUT_L (Registers 65 and 66) to be written into the FIFO buffer. */
    bool XG_FIFO_EN; 	/**< Setting this bit enables GYRO_XOUT_H and GYRO_XOUT_L (Registers 67 and 68) to be written into the FIFO buffer. */
    bool YG_FIFO_EN;	/**< Setting this bit enables GYRO_YOUT_H and GYRO_YOUT_L (Registers 69 and 70) to be written into the FIFO buffer. */
    bool ZG_FIFO_EN; 	/**< Setting this bit enables GYRO_ZOUT_H and GYRO_ZOUT_L (Registers 71 and 72) to be written into the FIFO buffer. */
    bool ACCEL_FIFO_EN;	/**< Setting this bit enables ACCEL_XOUT_H, ACCEL_XOUT_L, ACCEL_YOUT_H, ACCEL_YOUT_L, ACCEL_ZOUT_H and ACCEL_ZOUT_L (Registers 59 to 64) to be written into the FIFO buffer. */
    bool SLV2_FIFO_EN;	/**< Setting this bit enables EXT_SENS_DATA registers (Register 73 to 96) associated with Slave 2 to be written into the FIFO buffer.*/
    bool SLV1_FIFO_EN;	/**< Setting this bit enables EXT_SENS_DATA registers (Register 73 to 96) associated with Slave 1 to be written into the FIFO buffer. */
    bool SLV0_FIFO_EN;	/**< Setting this bit enables EXT_SENS_DATA registers (Register 73 to 96) associated with Slave 0 to be written into the FIFO buffer. */
}
tMPU6050_FIFO_EN;

extern void mpu6050_fifoEnReadReg(tMPU6050_FIFO_EN*);
extern void mpu6050_fifoEnWriteReg(tMPU6050_FIFO_EN*);

#endif
