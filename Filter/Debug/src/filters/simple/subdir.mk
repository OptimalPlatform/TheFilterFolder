################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/filters/simple/infinite_loop_simple_style.c \
../src/filters/simple/simple_filter.c 

OBJS += \
./src/filters/simple/infinite_loop_simple_style.o \
./src/filters/simple/simple_filter.o 

C_DEPS += \
./src/filters/simple/infinite_loop_simple_style.d \
./src/filters/simple/simple_filter.d 


# Each subdirectory must supply rules for building sources it contributes
src/filters/simple/%.o: ../src/filters/simple/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F429ZITx -DSTM32F429I_DISC1 -DDEBUG -DSTM32F429xx -DUSE_HAL_DRIVER -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<" @"src/filters/simple/includes.args"
	@echo 'Finished building: $<'
	@echo ' '


