################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
sevn_segment.lss \

FLASH_IMAGE += \
sevn_segment.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: sevn_segment.elf secondary-outputs

# Tool invocations
sevn_segment.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,sevn_segment.map -mmcu=atmega32 -o "sevn_segment.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

sevn_segment.lss: sevn_segment.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S sevn_segment.elf  >"sevn_segment.lss"
	@echo 'Finished building: $@'
	@echo ' '

sevn_segment.hex: sevn_segment.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex sevn_segment.elf  "sevn_segment.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: sevn_segment.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 sevn_segment.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) sevn_segment.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
