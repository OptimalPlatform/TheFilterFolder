################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/filters/kalman_MD_static/dataMD_static_debug.c \
../src/filters/kalman_MD_static/infinite_loop_kalman_style_MD_static.c \
../src/filters/kalman_MD_static/kalman_filter_MD_static.c \
../src/filters/kalman_MD_static/matrix_initialize_MD_static.c 

OBJS += \
./src/filters/kalman_MD_static/dataMD_static_debug.o \
./src/filters/kalman_MD_static/infinite_loop_kalman_style_MD_static.o \
./src/filters/kalman_MD_static/kalman_filter_MD_static.o \
./src/filters/kalman_MD_static/matrix_initialize_MD_static.o 

C_DEPS += \
./src/filters/kalman_MD_static/dataMD_static_debug.d \
./src/filters/kalman_MD_static/infinite_loop_kalman_style_MD_static.d \
./src/filters/kalman_MD_static/kalman_filter_MD_static.d \
./src/filters/kalman_MD_static/matrix_initialize_MD_static.d 


# Each subdirectory must supply rules for building sources it contributes
src/filters/kalman_MD_static/%.o: ../src/filters/kalman_MD_static/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F429ZITx -DSTM32F429I_DISC1 -DDEBUG -DSTM32F429xx -DUSE_HAL_DRIVER -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<" @"src/filters/kalman_MD_static/includes.args"
	@echo 'Finished building: $<'
	@echo ' '


