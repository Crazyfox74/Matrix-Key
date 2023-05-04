################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/ws2812/ws2812.c 

C_DEPS += \
./Core/Src/ws2812/ws2812.d 

OBJS += \
./Core/Src/ws2812/ws2812.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/ws2812/%.o Core/Src/ws2812/%.su: ../Core/Src/ws2812/%.c Core/Src/ws2812/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F091xC -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-ws2812

clean-Core-2f-Src-2f-ws2812:
	-$(RM) ./Core/Src/ws2812/ws2812.d ./Core/Src/ws2812/ws2812.o ./Core/Src/ws2812/ws2812.su

.PHONY: clean-Core-2f-Src-2f-ws2812

