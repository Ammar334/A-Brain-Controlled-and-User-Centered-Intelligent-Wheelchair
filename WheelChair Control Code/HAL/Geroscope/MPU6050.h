/*
 * MPU6050.h
 *
 *  Created on: Jun 13, 2025
 *      Author: ACC
 */

#ifndef GEROSCOPE_MPU6050_H_
#define GEROSCOPE_MPU6050_H_
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include <math.h>

#define MPU6050_ADDR 0x68 << 1  // Shifted for HAL (7-bit address + R/W bit)
#define WHO_AM_I_REG 0x75
#define PWR_MGMT_1   0x6B
#define ACCEL_XOUT_H 0x3B
extern I2C_HandleTypeDef hi2c2;
typedef struct {
	// I2C information
	I2C_HandleTypeDef* hi2c;
	uint8_t address;
} MPU6050_t;


void MPU6050_Init(MPU6050_t* const sensor);
void MPU6050_Read_Accel(MPU6050_t* const sensor,int16_t* ax, int16_t* ay, int16_t* az);
float Get_Roll(int16_t ay, int16_t az);
float Get_Pitch(int16_t ax, int16_t ay, int16_t az);


#endif /* GEROSCOPE_MPU6050_H_ */
