################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libr/arm_mat_add_f32.c \
../Libr/arm_mat_add_q15.c \
../Libr/arm_mat_add_q31.c \
../Libr/arm_mat_cmplx_mult_f32.c \
../Libr/arm_mat_cmplx_mult_q15.c \
../Libr/arm_mat_cmplx_mult_q31.c \
../Libr/arm_mat_init_f32.c \
../Libr/arm_mat_init_q15.c \
../Libr/arm_mat_init_q31.c \
../Libr/arm_mat_inverse_f32.c \
../Libr/arm_mat_inverse_f64.c \
../Libr/arm_mat_mult_f32.c \
../Libr/arm_mat_mult_fast_q15.c \
../Libr/arm_mat_mult_fast_q31.c \
../Libr/arm_mat_mult_q15.c \
../Libr/arm_mat_mult_q31.c \
../Libr/arm_mat_scale_f32.c \
../Libr/arm_mat_scale_q15.c \
../Libr/arm_mat_scale_q31.c \
../Libr/arm_mat_sub_f32.c \
../Libr/arm_mat_sub_q15.c \
../Libr/arm_mat_sub_q31.c \
../Libr/arm_mat_trans_f32.c \
../Libr/arm_mat_trans_q15.c \
../Libr/arm_mat_trans_q31.c 

OBJS += \
./Libr/arm_mat_add_f32.o \
./Libr/arm_mat_add_q15.o \
./Libr/arm_mat_add_q31.o \
./Libr/arm_mat_cmplx_mult_f32.o \
./Libr/arm_mat_cmplx_mult_q15.o \
./Libr/arm_mat_cmplx_mult_q31.o \
./Libr/arm_mat_init_f32.o \
./Libr/arm_mat_init_q15.o \
./Libr/arm_mat_init_q31.o \
./Libr/arm_mat_inverse_f32.o \
./Libr/arm_mat_inverse_f64.o \
./Libr/arm_mat_mult_f32.o \
./Libr/arm_mat_mult_fast_q15.o \
./Libr/arm_mat_mult_fast_q31.o \
./Libr/arm_mat_mult_q15.o \
./Libr/arm_mat_mult_q31.o \
./Libr/arm_mat_scale_f32.o \
./Libr/arm_mat_scale_q15.o \
./Libr/arm_mat_scale_q31.o \
./Libr/arm_mat_sub_f32.o \
./Libr/arm_mat_sub_q15.o \
./Libr/arm_mat_sub_q31.o \
./Libr/arm_mat_trans_f32.o \
./Libr/arm_mat_trans_q15.o \
./Libr/arm_mat_trans_q31.o 

C_DEPS += \
./Libr/arm_mat_add_f32.d \
./Libr/arm_mat_add_q15.d \
./Libr/arm_mat_add_q31.d \
./Libr/arm_mat_cmplx_mult_f32.d \
./Libr/arm_mat_cmplx_mult_q15.d \
./Libr/arm_mat_cmplx_mult_q31.d \
./Libr/arm_mat_init_f32.d \
./Libr/arm_mat_init_q15.d \
./Libr/arm_mat_init_q31.d \
./Libr/arm_mat_inverse_f32.d \
./Libr/arm_mat_inverse_f64.d \
./Libr/arm_mat_mult_f32.d \
./Libr/arm_mat_mult_fast_q15.d \
./Libr/arm_mat_mult_fast_q31.d \
./Libr/arm_mat_mult_q15.d \
./Libr/arm_mat_mult_q31.d \
./Libr/arm_mat_scale_f32.d \
./Libr/arm_mat_scale_q15.d \
./Libr/arm_mat_scale_q31.d \
./Libr/arm_mat_sub_f32.d \
./Libr/arm_mat_sub_q15.d \
./Libr/arm_mat_sub_q31.d \
./Libr/arm_mat_trans_f32.d \
./Libr/arm_mat_trans_q15.d \
./Libr/arm_mat_trans_q31.d 


# Each subdirectory must supply rules for building sources it contributes
Libr/%.o: ../Libr/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F429ZITx -DSTM32F429I_DISC1 -DDEBUG -DSTM32F429xx -DUSE_HAL_DRIVER -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<" @"Libr/includes.args"
	@echo 'Finished building: $<'
	@echo ' '


