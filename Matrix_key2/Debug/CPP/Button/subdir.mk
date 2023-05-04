################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CPP/Button/Button.cpp 

OBJS += \
./CPP/Button/Button.o 

CPP_DEPS += \
./CPP/Button/Button.d 


# Each subdirectory must supply rules for building sources it contributes
CPP/Button/%.o CPP/Button/%.su: ../CPP/Button/%.cpp CPP/Button/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m0 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F091xC -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/Freertos tests/Matrix_key2/CPP/Inc" -I"D:/Freertos tests/Matrix_key2/CPP" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-CPP-2f-Button

clean-CPP-2f-Button:
	-$(RM) ./CPP/Button/Button.d ./CPP/Button/Button.o ./CPP/Button/Button.su

.PHONY: clean-CPP-2f-Button

