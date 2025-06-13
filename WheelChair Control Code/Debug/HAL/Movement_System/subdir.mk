################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Movement_System/move_system.c \
../HAL/Movement_System/move_system_cfg.c 

OBJS += \
./HAL/Movement_System/move_system.o \
./HAL/Movement_System/move_system_cfg.o 

C_DEPS += \
./HAL/Movement_System/move_system.d \
./HAL/Movement_System/move_system_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Movement_System/%.o HAL/Movement_System/%.su HAL/Movement_System/%.cyclo: ../HAL/Movement_System/%.c HAL/Movement_System/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-HAL-2f-Movement_System

clean-HAL-2f-Movement_System:
	-$(RM) ./HAL/Movement_System/move_system.cyclo ./HAL/Movement_System/move_system.d ./HAL/Movement_System/move_system.o ./HAL/Movement_System/move_system.su ./HAL/Movement_System/move_system_cfg.cyclo ./HAL/Movement_System/move_system_cfg.d ./HAL/Movement_System/move_system_cfg.o ./HAL/Movement_System/move_system_cfg.su

.PHONY: clean-HAL-2f-Movement_System

