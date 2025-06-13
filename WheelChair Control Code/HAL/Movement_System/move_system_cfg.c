/*
 * move_system_cfg.c
 *
 *  Created on: Mar 18, 2025
 *      Author: ACC
 */


#include "move_system_cfg.h"

Movement_system_t Chair ={
		.Motor1_port = GPIOA,
		.Motor1_pin1 = GPIO_PIN_10,
		.Motor1_pin2 = GPIO_PIN_8,
		.Motor2_port = GPIOB,
		.Motor2_pin1 = GPIO_PIN_5,
		.Motor2_pin2 = GPIO_PIN_4
};
