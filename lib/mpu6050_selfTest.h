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
 *  \file mpu6050_selfTest.h
 *  \brief Self Test headerfile
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */

#ifndef MPU6050_SELFTEST_H_
#define MPU6050_SELFTEST_H_

typedef struct
{
    unsigned char XA_TEST: 5;
    unsigned char XG_TEST: 5;
    unsigned char YA_TEST: 5;
    unsigned char YG_TEST: 5;
    unsigned char ZA_TEST: 5;
    unsigned char ZG_TEST: 5;
}
tMPU6050_SELF_TEST;

extern void mpu6050_selftestRegRead(tMPU6050_SELF_TEST*);
extern void mpu6050_selftestRegWrite(tMPU6050_SELF_TEST*);

#endif