/*
 * MPU6050_cfg.c
 *
 *  Created on: Jun 13, 2025
 *      Author: ACC
 */


#include "MPU6050_cfg.h"

MPU6050_t MPU_1 ={
		.address = MPU6050_ADDR,
		.hi2c = &hi2c2
};
