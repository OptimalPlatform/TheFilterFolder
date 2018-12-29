################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/filters/utilities/debug_parameters.c \
../src/filters/utilities/kalman_MatrixMD_utilities.c \
../src/filters/utilities/kalman_filter_MD.c 

OBJS += \
./src/filters/utilities/debug_parameters.o \
./src/filters/utilities/kalman_MatrixMD_utilities.o \
./src/filters/utilities/kalman_filter_MD.o 

C_DEPS += \
./src/filters/utilities/debug_parameters.d \
./src/filters/utilities/kalman_MatrixMD_utilities.d \
./src/filters/utilities/kalman_filter_MD.d 


# Each subdirectory must supply rules for building sources it contributes
src/filters/utilities/%.o: ../src/filters/utilities/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F429ZITx -DSTM32F429I_DISC1 -DDEBUG -DSTM32F429xx -DUSE_HAL_DRIVER -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<" @"src/filters/utilities/includes.args"
	@echo 'Finished building: $<'
	@echo ' '


