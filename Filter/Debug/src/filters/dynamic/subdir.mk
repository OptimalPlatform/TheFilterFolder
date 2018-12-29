################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/filters/dynamic/allocate_memory_test.c \
../src/filters/dynamic/infinite_loop_dynamic_style.c 

OBJS += \
./src/filters/dynamic/allocate_memory_test.o \
./src/filters/dynamic/infinite_loop_dynamic_style.o 

C_DEPS += \
./src/filters/dynamic/allocate_memory_test.d \
./src/filters/dynamic/infinite_loop_dynamic_style.d 


# Each subdirectory must supply rules for building sources it contributes
src/filters/dynamic/%.o: ../src/filters/dynamic/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F429ZITx -DSTM32F429I_DISC1 -DDEBUG -DSTM32F429xx -DUSE_HAL_DRIVER -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<" @"src/filters/dynamic/includes.args"
	@echo 'Finished building: $<'
	@echo ' '


