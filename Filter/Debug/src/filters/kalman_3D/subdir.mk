################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/filters/kalman_3D/data3D_debug.c \
../src/filters/kalman_3D/infinite_loop_kalman_style_3D.c \
../src/filters/kalman_3D/matrix_initialize_3D.c 

OBJS += \
./src/filters/kalman_3D/data3D_debug.o \
./src/filters/kalman_3D/infinite_loop_kalman_style_3D.o \
./src/filters/kalman_3D/matrix_initialize_3D.o 

C_DEPS += \
./src/filters/kalman_3D/data3D_debug.d \
./src/filters/kalman_3D/infinite_loop_kalman_style_3D.d \
./src/filters/kalman_3D/matrix_initialize_3D.d 


# Each subdirectory must supply rules for building sources it contributes
src/filters/kalman_3D/%.o: ../src/filters/kalman_3D/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F429ZITx -DSTM32F429I_DISC1 -DDEBUG -DSTM32F429xx -DUSE_HAL_DRIVER -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<" @"src/filters/kalman_3D/includes.args"
	@echo 'Finished building: $<'
	@echo ' '


