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
 *  \file mpu6050_sampleRateDivider.h
 *  \brief Sample Rate Divider headerfile
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef MPU6050_SAMPLERATEDIVIDER_H_
#define MPU6050_SAMPLERATEDIVIDER_H_

typedef unsigned char tMPU6050_SMPLRT_DIV;	/**< Datatype for Sample Rate Register. The Sample Rate is determined by dividing the gyro output rate by this value. */

extern void mpu6050_sampleRateDividerRegRead(tMPU6050_SMPLRT_DIV*);
extern void mpu6050_sampleRateDividerRegWrite(tMPU6050_SMPLRT_DIV*);

#endif