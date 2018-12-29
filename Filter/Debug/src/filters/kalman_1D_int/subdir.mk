################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/filters/kalman_1D_int/infinite_loop_kalman_style_int.c \
../src/filters/kalman_1D_int/kalman_filter_int.c 

OBJS += \
./src/filters/kalman_1D_int/infinite_loop_kalman_style_int.o \
./src/filters/kalman_1D_int/kalman_filter_int.o 

C_DEPS += \
./src/filters/kalman_1D_int/infinite_loop_kalman_style_int.d \
./src/filters/kalman_1D_int/kalman_filter_int.d 


# Each subdirectory must supply rules for building sources it contributes
src/filters/kalman_1D_int/%.o: ../src/filters/kalman_1D_int/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F429ZITx -DSTM32F429I_DISC1 -DDEBUG -DSTM32F429xx -DUSE_HAL_DRIVER -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<" @"src/filters/kalman_1D_int/includes.args"
	@echo 'Finished building: $<'
	@echo ' '


