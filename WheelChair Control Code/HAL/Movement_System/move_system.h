/*
 * move_system.h
 *
 *  Created on: Mar 18, 2025
 *      Author: ACC
 */

#ifndef MOVEMENT_SYSTEM_MOVE_SYSTEM_H_
#define MOVEMENT_SYSTEM_MOVE_SYSTEM_H_

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"


typedef struct
{
	GPIO_TypeDef * Motor1_port;
	uint16_t Motor1_pin1;
	uint16_t Motor1_pin2;
	GPIO_TypeDef * Motor2_port;
	uint16_t Motor2_pin1;
	uint16_t Motor2_pin2;
}Movement_system_t;

void Chair_Move_Forward(const Movement_system_t* move_sys);
void Chair_Move_Backward(const Movement_system_t* move_sys);
void Chair_Move_Right(const Movement_system_t* move_sys);
void Chair_Move_Left(const Movement_system_t* move_sys);
void Chair_Stop(const Movement_system_t* move_sys);


#endif /* MOVEMENT_SYSTEM_MOVE_SYSTEM_H_ */
