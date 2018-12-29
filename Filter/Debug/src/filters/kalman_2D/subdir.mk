################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/filters/kalman_2D/data2D_debug.c \
../src/filters/kalman_2D/infinite_loop_kalman_style_2D.c \
../src/filters/kalman_2D/matrix_initialize_2D.c 

OBJS += \
./src/filters/kalman_2D/data2D_debug.o \
./src/filters/kalman_2D/infinite_loop_kalman_style_2D.o \
./src/filters/kalman_2D/matrix_initialize_2D.o 

C_DEPS += \
./src/filters/kalman_2D/data2D_debug.d \
./src/filters/kalman_2D/infinite_loop_kalman_style_2D.d \
./src/filters/kalman_2D/matrix_initialize_2D.d 


# Each subdirectory must supply rules for building sources it contributes
src/filters/kalman_2D/%.o: ../src/filters/kalman_2D/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F429ZITx -DSTM32F429I_DISC1 -DDEBUG -DSTM32F429xx -DUSE_HAL_DRIVER -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<" @"src/filters/kalman_2D/includes.args"
	@echo 'Finished building: $<'
	@echo ' '


