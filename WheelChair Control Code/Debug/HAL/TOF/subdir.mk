################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/TOF/VL53L1X_api.c \
../HAL/TOF/VL53L1X_calibration.c \
../HAL/TOF/tof_pp.c \
../HAL/TOF/vl53l1_platform.c 

OBJS += \
./HAL/TOF/VL53L1X_api.o \
./HAL/TOF/VL53L1X_calibration.o \
./HAL/TOF/tof_pp.o \
./HAL/TOF/vl53l1_platform.o 

C_DEPS += \
./HAL/TOF/VL53L1X_api.d \
./HAL/TOF/VL53L1X_calibration.d \
./HAL/TOF/tof_pp.d \
./HAL/TOF/vl53l1_platform.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/TOF/%.o HAL/TOF/%.su HAL/TOF/%.cyclo: ../HAL/TOF/%.c HAL/TOF/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-HAL-2f-TOF

clean-HAL-2f-TOF:
	-$(RM) ./HAL/TOF/VL53L1X_api.cyclo ./HAL/TOF/VL53L1X_api.d ./HAL/TOF/VL53L1X_api.o ./HAL/TOF/VL53L1X_api.su ./HAL/TOF/VL53L1X_calibration.cyclo ./HAL/TOF/VL53L1X_calibration.d ./HAL/TOF/VL53L1X_calibration.o ./HAL/TOF/VL53L1X_calibration.su ./HAL/TOF/tof_pp.cyclo ./HAL/TOF/tof_pp.d ./HAL/TOF/tof_pp.o ./HAL/TOF/tof_pp.su ./HAL/TOF/vl53l1_platform.cyclo ./HAL/TOF/vl53l1_platform.d ./HAL/TOF/vl53l1_platform.o ./HAL/TOF/vl53l1_platform.su

.PHONY: clean-HAL-2f-TOF

