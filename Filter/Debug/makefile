################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/interface/subdir.mk
-include src/filters/utilities/subdir.mk
-include src/filters/struct/subdir.mk
-include src/filters/simple/subdir.mk
-include src/filters/matrix/subdir.mk
-include src/filters/kalman_MD_static/subdir.mk
-include src/filters/kalman_4D/subdir.mk
-include src/filters/kalman_3D/subdir.mk
-include src/filters/kalman_2D/subdir.mk
-include src/filters/kalman_1D_int/subdir.mk
-include src/filters/kalman_1D/subdir.mk
-include src/filters/dynamic/subdir.mk
-include src/subdir.mk
-include Utilities/STM32F429I-Discovery/subdir.mk
-include Utilities/Log/subdir.mk
-include Utilities/Components/wm8994/subdir.mk
-include Utilities/Components/ts3510/subdir.mk
-include Utilities/Components/stmpe811/subdir.mk
-include Utilities/Components/stmpe1600/subdir.mk
-include Utilities/Components/st7789h2/subdir.mk
-include Utilities/Components/st7735/subdir.mk
-include Utilities/Components/s5k5cag/subdir.mk
-include Utilities/Components/ov2640/subdir.mk
-include Utilities/Components/otm8009a/subdir.mk
-include Utilities/Components/mfxstm32l152/subdir.mk
-include Utilities/Components/lsm303dlhc/subdir.mk
-include Utilities/Components/ls016b8uy/subdir.mk
-include Utilities/Components/lis3dsh/subdir.mk
-include Utilities/Components/lis302dl/subdir.mk
-include Utilities/Components/l3gd20/subdir.mk
-include Utilities/Components/ili9341/subdir.mk
-include Utilities/Components/ili9325/subdir.mk
-include Utilities/Components/ft6x06/subdir.mk
-include Utilities/Components/exc7200/subdir.mk
-include Utilities/Components/cs43l22/subdir.mk
-include Middlewares/ST/STemWin/Config/subdir.mk
-include Libr/subdir.mk
-include HAL_Driver/Src/Legacy/subdir.mk
-include HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Filter.elf

# Tool invocations
Filter.elf: $(OBJS) $(USER_OBJS) E:\Users\Olof\prog\Proj_inbygda\git\TheFilterFolder\Filter/LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -L"E:\Users\Olof\prog\Proj_inbygda\git\TheFilterFolder\Filter\Middlewares\ST\STemWin\Lib" -T"E:/Users/Olof/prog/Proj_inbygda/git/TheFilterFolder/Filter/LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "Filter.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "Filter.elf" "Filter.bin"
	arm-none-eabi-size "Filter.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
