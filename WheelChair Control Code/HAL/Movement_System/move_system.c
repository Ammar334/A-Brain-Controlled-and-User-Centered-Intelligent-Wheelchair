/*
 * move_system.c
 *
 *  Created on: Mar 18, 2025
 *      Author: ACC
 */

#include "move_system.h"


void Chair_Move_Forward(const Movement_system_t* move_sys)
{
	HAL_GPIO_WritePin(move_sys->Motor1_port, move_sys-> Motor1_pin1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(move_sys->Motor1_port, move_sys-> Motor1_pin2, GPIO_PIN_SET);
	HAL_GPIO_WritePin(move_sys->Motor2_port, move_sys-> Motor2_pin1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(move_sys->Motor2_port, move_sys-> Motor2_pin2, GPIO_PIN_RESET);
}
void Chair_Move_Backward(const Movement_system_t* move_sys){
	HAL_GPIO_WritePin(move_sys->Motor1_port, move_sys-> Motor1_pin1, GPIO_PIN_SET);
		HAL_GPIO_WritePin(move_sys->Motor1_port, move_sys-> Motor1_pin2, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(move_sys->Motor2_port, move_sys-> Motor2_pin1, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(move_sys->Motor2_port, move_sys-> Motor2_pin2, GPIO_PIN_SET);
}
void Chair_Move_Right(const Movement_system_t* move_sys)
{
	HAL_GPIO_WritePin(move_sys->Motor1_port, move_sys-> Motor1_pin1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(move_sys->Motor1_port, move_sys-> Motor1_pin2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(move_sys->Motor2_port, move_sys-> Motor2_pin1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(move_sys->Motor2_port, move_sys-> Motor2_pin2, GPIO_PIN_RESET);
}
void Chair_Move_Left(const Movement_system_t* move_sys){
	HAL_GPIO_WritePin(move_sys->Motor1_port, move_sys-> Motor1_pin1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(move_sys->Motor1_port, move_sys-> Motor1_pin2, GPIO_PIN_SET);
	HAL_GPIO_WritePin(move_sys->Motor2_port, move_sys-> Motor2_pin1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(move_sys->Motor2_port, move_sys-> Motor2_pin2, GPIO_PIN_SET);
}
void Chair_Stop(const Movement_system_t* move_sys){
	HAL_GPIO_WritePin(move_sys->Motor1_port, move_sys-> Motor1_pin1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(move_sys->Motor1_port, move_sys-> Motor1_pin2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(move_sys->Motor2_port, move_sys-> Motor2_pin1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(move_sys->Motor2_port, move_sys-> Motor2_pin2, GPIO_PIN_RESET);
}



