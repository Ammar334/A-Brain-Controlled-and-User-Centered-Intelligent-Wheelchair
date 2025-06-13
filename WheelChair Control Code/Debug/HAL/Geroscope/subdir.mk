################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Geroscope/MPU6050.c \
../HAL/Geroscope/MPU6050_cfg.c 

OBJS += \
./HAL/Geroscope/MPU6050.o \
./HAL/Geroscope/MPU6050_cfg.o 

C_DEPS += \
./HAL/Geroscope/MPU6050.d \
./HAL/Geroscope/MPU6050_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Geroscope/%.o HAL/Geroscope/%.su HAL/Geroscope/%.cyclo: ../HAL/Geroscope/%.c HAL/Geroscope/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-HAL-2f-Geroscope

clean-HAL-2f-Geroscope:
	-$(RM) ./HAL/Geroscope/MPU6050.cyclo ./HAL/Geroscope/MPU6050.d ./HAL/Geroscope/MPU6050.o ./HAL/Geroscope/MPU6050.su ./HAL/Geroscope/MPU6050_cfg.cyclo ./HAL/Geroscope/MPU6050_cfg.d ./HAL/Geroscope/MPU6050_cfg.o ./HAL/Geroscope/MPU6050_cfg.su

.PHONY: clean-HAL-2f-Geroscope

