################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32_F103C6_Drivers/stm32_F103C6_EXTI_driver.c \
../stm32_F103C6_Drivers/stm32_F103C6_gpio_driver.c 

OBJS += \
./stm32_F103C6_Drivers/stm32_F103C6_EXTI_driver.o \
./stm32_F103C6_Drivers/stm32_F103C6_gpio_driver.o 

C_DEPS += \
./stm32_F103C6_Drivers/stm32_F103C6_EXTI_driver.d \
./stm32_F103C6_Drivers/stm32_F103C6_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
stm32_F103C6_Drivers/%.o stm32_F103C6_Drivers/%.su: ../stm32_F103C6_Drivers/%.c stm32_F103C6_Drivers/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I"D:/Embedded Course/Unit7_MCU_Essential_Peripherals/GPIO3/Drivers/HAL/includes" -I../Inc -I"D:/Embedded Course/Unit7_MCU_Essential_Peripherals/GPIO3/Drivers/stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-stm32_F103C6_Drivers

clean-stm32_F103C6_Drivers:
	-$(RM) ./stm32_F103C6_Drivers/stm32_F103C6_EXTI_driver.d ./stm32_F103C6_Drivers/stm32_F103C6_EXTI_driver.o ./stm32_F103C6_Drivers/stm32_F103C6_EXTI_driver.su ./stm32_F103C6_Drivers/stm32_F103C6_gpio_driver.d ./stm32_F103C6_Drivers/stm32_F103C6_gpio_driver.o ./stm32_F103C6_Drivers/stm32_F103C6_gpio_driver.su

.PHONY: clean-stm32_F103C6_Drivers

