/*
 * MPU6050.c
 *
 *  Created on: Jun 13, 2025
 *      Author: ACC
 */
#include "MPU6050.h"

void MPU6050_Init(MPU6050_t* const sensor) {
    uint8_t check;
    uint8_t data;

    // Read WHO_AM_I register
    HAL_I2C_Mem_Read(sensor->hi2c, MPU6050_ADDR, WHO_AM_I_REG, 1, &check, 1, HAL_MAX_DELAY);
    if (check == 0x68) {
        // Wake up sensor by clearing the sleep bit (PWR_MGMT_1 = 0)
        data = 0;
        HAL_I2C_Mem_Write(sensor->hi2c, MPU6050_ADDR, PWR_MGMT_1, 1, &data, 1, HAL_MAX_DELAY);
    } else {
        ITM_printf("MPU6050 not found!\r\n");
    }
}

void MPU6050_Read_Accel(MPU6050_t* const sensor,int16_t* ax, int16_t* ay, int16_t* az) {
    uint8_t Rec_Data[6];

    // Read 6 bytes starting from ACCEL_XOUT_H
    HAL_I2C_Mem_Read(sensor->hi2c, sensor->address, ACCEL_XOUT_H, 1, Rec_Data, 6, 1000);

    *ax = (int16_t)(Rec_Data[0] << 8 | Rec_Data[1]);
    *ay = (int16_t)(Rec_Data[2] << 8 | Rec_Data[3]);
    *az = (int16_t)(Rec_Data[4] << 8 | Rec_Data[5]);
}
float Get_Roll(int16_t ay, int16_t az) {
    return atan2f(ay, az) * 180.0f / M_PI;
}
float Get_Pitch(int16_t ax, int16_t ay, int16_t az) {
    return atan2f(-ax, sqrtf(ay * ay + az * az)) * 180.0f / M_PI;
}

