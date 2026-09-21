################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include release/Mcal/DIO/subdir.mk
-include release/Hal/SevSeg/subdir.mk
-include release/Hal/Led/subdir.mk
-include release/Hal/LCD/subdir.mk
-include release/Hal/KPD/subdir.mk
-include release/Hal/DcMotor/subdir.mk
-include release/App/App1/subdir.mk
-include release/subdir.mk
-include Mcal/GIE/subdir.mk
-include Mcal/EXTI/subdir.mk
-include Mcal/DIO/subdir.mk
-include Hal/SevSeg/subdir.mk
-include Hal/Led/subdir.mk
-include Hal/LCD/subdir.mk
-include Hal/KPD/subdir.mk
-include Hal/DcMotor/subdir.mk
-include App/App1/subdir.mk
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Atmega32Driver
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Atmega32Driver.lss \

FLASH_IMAGE += \
Atmega32Driver.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: Atmega32Driver.elf secondary-outputs

# Tool invocations
Atmega32Driver.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Atmega32Driver.map -mmcu=atmega16 -o "Atmega32Driver.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Atmega32Driver.lss: Atmega32Driver.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Atmega32Driver.elf  >"Atmega32Driver.lss"
	@echo 'Finished building: $@'
	@echo ' '

Atmega32Driver.hex: Atmega32Driver.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Atmega32Driver.elf  "Atmega32Driver.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Atmega32Driver.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Atmega32Driver.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Atmega32Driver.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
