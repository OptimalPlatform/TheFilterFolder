################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libr/arm_mat_add_f32.c \
../Libr/arm_mat_cmplx_mult_f32.c \
../Libr/arm_mat_init_f32.c \
../Libr/arm_mat_inverse_f32.c \
../Libr/arm_mat_inverse_f64.c \
../Libr/arm_mat_mult_f32.c \
../Libr/arm_mat_scale_f32.c \
../Libr/arm_mat_sub_f32.c \
../Libr/arm_mat_trans_f32.c 

OBJS += \
./Libr/arm_mat_add_f32.o \
./Libr/arm_mat_cmplx_mult_f32.o \
./Libr/arm_mat_init_f32.o \
./Libr/arm_mat_inverse_f32.o \
./Libr/arm_mat_inverse_f64.o \
./Libr/arm_mat_mult_f32.o \
./Libr/arm_mat_scale_f32.o \
./Libr/arm_mat_sub_f32.o \
./Libr/arm_mat_trans_f32.o 

C_DEPS += \
./Libr/arm_mat_add_f32.d \
./Libr/arm_mat_cmplx_mult_f32.d \
./Libr/arm_mat_init_f32.d \
./Libr/arm_mat_inverse_f32.d \
./Libr/arm_mat_inverse_f64.d \
./Libr/arm_mat_mult_f32.d \
./Libr/arm_mat_scale_f32.d \
./Libr/arm_mat_sub_f32.d \
./Libr/arm_mat_trans_f32.d 


# Each subdirectory must supply rules for building sources it contributes
Libr/%.o: ../Libr/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F429ZITx -DSTM32F429I_DISC1 -DDEBUG -DSTM32F429xx -DUSE_HAL_DRIVER -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/ili9325" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/s25fl512s" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/cs43l22" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/ili9341" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/ampire480272" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/n25q512a" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/s5k5cag" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/mfxstm32l152" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/CMSIS/device" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/n25q128a" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/ts3510" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/st7735" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/HAL_Driver/Inc/Legacy" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/lis302dl" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/otm8009a" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/stmpe1600" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/Common" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/ov2640" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/l3gd20" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/HAL_Driver/Inc" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/stmpe811" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/lis3dsh" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/wm8994" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Fonts" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/n25q256a" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/inc" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/ls016b8uy" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/ft6x06" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/exc7200" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/st7789h2" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Log" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/ampire640480" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/Components/lsm303dlhc" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/CMSIS/core" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Utilities/STM32F429I-Discovery" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/inc/filters/simple" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/inc/filters/struct" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/inc/filters/kalman_1D" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/inc/filters/kalman_1D_int" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/inc/filters/matrix" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/inc/filters/utilities" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/inc/filters/kalman_2D" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/inc/filters/dynamic" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/inc/filters/kalman_MD_dynamic" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/inc/filters/kalman_MD_static" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/inc/filters/kalman_3D" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/inc/filters/kalman_4D" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/inc/interface" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Middlewares/ST/STemWin/Config" -I"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/Middlewares/ST/STemWin/inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


