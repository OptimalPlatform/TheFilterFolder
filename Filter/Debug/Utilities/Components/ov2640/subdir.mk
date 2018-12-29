################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/Components/ov2640/ov2640.c 

OBJS += \
./Utilities/Components/ov2640/ov2640.o 

C_DEPS += \
./Utilities/Components/ov2640/ov2640.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/Components/ov2640/%.o: ../Utilities/Components/ov2640/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F429ZITx -DSTM32F429I_DISC1 -DDEBUG -DSTM32F429xx -DUSE_HAL_DRIVER -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<" @"Utilities/Components/ov2640/includes.args"
	@echo 'Finished building: $<'
	@echo ' '


