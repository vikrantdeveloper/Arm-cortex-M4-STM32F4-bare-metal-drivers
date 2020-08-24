################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/src/LL_gpio.c \
../drivers/src/LL_rcc.c 

OBJS += \
./drivers/src/LL_gpio.o \
./drivers/src/LL_rcc.o 

C_DEPS += \
./drivers/src/LL_gpio.d \
./drivers/src/LL_rcc.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/src/LL_gpio.o: ../drivers/src/LL_gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DDEBUG -DNUCLEO_F446RE -c -I"/home/vikrant/STM32-drivers/Inc" -I"/home/vikrant/STM32-drivers/drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/src/LL_gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
drivers/src/LL_rcc.o: ../drivers/src/LL_rcc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DDEBUG -DNUCLEO_F446RE -c -I"/home/vikrant/STM32-drivers/Inc" -I"/home/vikrant/STM32-drivers/drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/src/LL_rcc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

