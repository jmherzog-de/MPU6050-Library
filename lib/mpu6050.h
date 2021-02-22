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
 *  @mainpage Library Overview
 *  
 *  @section library_description Library description
 *  Some words about the library.
 *  
 *  @section implemented_hardware_driver Implemented hardware driver
 *  Some words about the already implemented hardware driver.
 *  
 *  @section ready_to_use_functions Ready to use functions
 *  Some words about the implemented ready to use functions. Work out of the box.
 */

/**
 *  \file mpu6050.h
 *  \brief MPU6050 Main include headerfile
 *  
 *	Comment out the parts of the library which are not used
 *	in your project.
 *
 *  \copyright Copyright 2021 Jean-Marcel Herzog. All rights reserved. This project is released under the GNU Public License.
 */
 
#ifndef MPU6050_H_
#define MPU6050_H_

//--------------------------------------//
// 4.1 Self Test Registers              //
//--------------------------------------//
#include "mpu6050_selfTest.h"

//--------------------------------------//
// 4.2 Sample Rate Divider              //
//--------------------------------------//
#include "mpu6050_sampleRateDivider.h"

//--------------------------------------//
// 4.3 Configuration                    //
//--------------------------------------//
#include "mpu6050_configuration.h"

//--------------------------------------//
// 4.4 Gyroscope Configuration          //
//--------------------------------------//
#include "mpu6050_gyroscopeConfiguration.h"

//--------------------------------------//
// 4.5 Accelerometer Configuration      //
//--------------------------------------//
#include "mpu6050_accelerometerConfiguration.h"

//--------------------------------------//
// 4.6 FIFO Enable                      //
//--------------------------------------//
#include "mpu6050_fifoEnable.h"

//--------------------------------------//
// 4.7 I2C Master Control               //
//--------------------------------------//
#include "mpu6050_i2cMasterControl.h"

//--------------------------------------//
// 4.8 I2C Slave 0 Control              //
//--------------------------------------//
#include "mpu6050_i2cSlave0Control.h"

//--------------------------------------//
// 4.9 I2C Slave 1 Control              //
//--------------------------------------//
#include "mpu6050_i2cSlave1Control.h"

//--------------------------------------//
// 4.10 I2C Slave 2 Control             //
//--------------------------------------//
#include "mpu6050_i2cSlave2Control.h"

//--------------------------------------//
// 4.11 I2C Slave 3 Control             //
//--------------------------------------//
#include "mpu6050_i2cSlave3Control.h"

//--------------------------------------//
// 4.12 I2C Slave 4 Control             //
//--------------------------------------//
#include "mpu6050_i2cSlave4Control.h"

//--------------------------------------//
// 4.13 I2C Master Status               //
//--------------------------------------//
#include "mpu6050_i2cMasterStatus.h"

//--------------------------------------//
// 4.14 Bypass Enable Configuration     //
//--------------------------------------//
#include "mpu6050_bypassEnableConfiguration.h"

//--------------------------------------//
// 4.15 Interrupt Enable                //
//--------------------------------------//
#include "mpu6050_interruptEnable.h"

//--------------------------------------//
// 4.16 Interrupt Status                //
//--------------------------------------//
#include "mpu6050_interruptStatus.h"

//--------------------------------------//
// 4.17 Accelerometer Measurements      //
//--------------------------------------//
#include "mpu6050_accelerometerMeasurements.h"

//--------------------------------------//
// 4.18 Temperature Measurements        //
//--------------------------------------//
#include "mpu6050_temperatureMeasurements.h"

//--------------------------------------//
// 4.19 Gyroscope Measurements          //
//--------------------------------------//
#include "mpu6050_gyroscopeMeasurements.h"

//--------------------------------------//
// 4.20 External Sensor Data            //
//--------------------------------------//
#include "mpu6050_externalSensorData.h"

//--------------------------------------//
// 4.21 I2C Slave 0 Data Out            //
//--------------------------------------//
#include "mpu6050_i2cSlave0DataOut.h"

//--------------------------------------//
// 4.22 I2C Slave 1 Data Out            //
//--------------------------------------//
#include "mpu6050_i2cSlave1DataOut.h"

//--------------------------------------//
// 4.23 I2C Slave 2 Data Out            //
//--------------------------------------//
#include "mpu6050_i2cSlave2DataOut.h"

//--------------------------------------//
// 4.24 I2C Slave 3 Data Out            //
//--------------------------------------//
#include "mpu6050_i2cSlave3DataOut.h"

//--------------------------------------//
// 4.25 I2C Master Delay Control        //
//--------------------------------------//
#include "mpu6050_i2cMasterDelayControl.h"

//--------------------------------------//
// 4.26 Signal Path Reset               //
//--------------------------------------//
#include "mpu6050_signalPathReset.h"

//--------------------------------------//
// 4.27 User Control                    //
//--------------------------------------//
#include "mpu6050_userControl.h"

//--------------------------------------//
// 4.28 Power Management 1              //
//--------------------------------------//
#include "mpu6050_powerManagement1.h"

//--------------------------------------//
// 4.29 Power Management 2              //
//--------------------------------------//
#include "mpu6050_powerManagement2.h"

//--------------------------------------//
// 4.30 FIFO Count Registers            //
//--------------------------------------//
#include "mpu6050_fifoCountRegisters.h"

//--------------------------------------//
// 4.31 FIFO Read Write                 //
//--------------------------------------//
#include "mpu6050_fifoReadWrite.h"

//--------------------------------------//
// 4.32 Who Am I                        //
//--------------------------------------//
#include "mpu6050_whoAmI.h"

#endif /* MPU6050_H_ */