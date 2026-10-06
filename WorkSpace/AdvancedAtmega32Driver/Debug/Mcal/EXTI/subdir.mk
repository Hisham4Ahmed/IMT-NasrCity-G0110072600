################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal/EXTI/EXTI_Progrma.c 

OBJS += \
./Mcal/EXTI/EXTI_Progrma.o 

C_DEPS += \
./Mcal/EXTI/EXTI_Progrma.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal/EXTI/%.o: ../Mcal/EXTI/%.c Mcal/EXTI/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


