################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/HAL/Src/SetPin.c \
../Core/HAL/Src/timer_hal.c 

OBJS += \
./Core/HAL/Src/SetPin.o \
./Core/HAL/Src/timer_hal.o 

C_DEPS += \
./Core/HAL/Src/SetPin.d \
./Core/HAL/Src/timer_hal.d 


# Each subdirectory must supply rules for building sources it contributes
Core/HAL/Src/%.o Core/HAL/Src/%.su Core/HAL/Src/%.cyclo: ../Core/HAL/Src/%.c Core/HAL/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"C:/Users/denni/Documents/STM32 Projects/DHT11/STM32F103_DHT11/Core/DHT11_HAL/Inc" -I"C:/Users/denni/Documents/STM32 Projects/DHT11/STM32F103_DHT11/Core/HAL/Inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-HAL-2f-Src

clean-Core-2f-HAL-2f-Src:
	-$(RM) ./Core/HAL/Src/SetPin.cyclo ./Core/HAL/Src/SetPin.d ./Core/HAL/Src/SetPin.o ./Core/HAL/Src/SetPin.su ./Core/HAL/Src/timer_hal.cyclo ./Core/HAL/Src/timer_hal.d ./Core/HAL/Src/timer_hal.o ./Core/HAL/Src/timer_hal.su

.PHONY: clean-Core-2f-HAL-2f-Src

