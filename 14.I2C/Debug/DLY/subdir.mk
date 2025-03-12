################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/H/Desktop/STM32/nucleoG4/Work_space/BareMetal/9.Systick/Src/main.c \
C:/Users/H/Desktop/STM32/nucleoG4/Work_space/BareMetal/9.Systick/Src/syscalls.c \
C:/Users/H/Desktop/STM32/nucleoG4/Work_space/BareMetal/9.Systick/Src/sysmem.c 

OBJS += \
./DLY/main.o \
./DLY/syscalls.o \
./DLY/sysmem.o 

C_DEPS += \
./DLY/main.d \
./DLY/syscalls.d \
./DLY/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
DLY/main.o: C:/Users/H/Desktop/STM32/nucleoG4/Work_space/BareMetal/9.Systick/Src/main.c DLY/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32G4 -DSTM32G431RBTx -c -I../Inc -I"C:/Users/H/Desktop/STM32/nucleoG4/CMSIS/Device/Include" -I"C:/Users/H/Desktop/STM32/nucleoG4/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
DLY/syscalls.o: C:/Users/H/Desktop/STM32/nucleoG4/Work_space/BareMetal/9.Systick/Src/syscalls.c DLY/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32G4 -DSTM32G431RBTx -c -I../Inc -I"C:/Users/H/Desktop/STM32/nucleoG4/CMSIS/Device/Include" -I"C:/Users/H/Desktop/STM32/nucleoG4/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
DLY/sysmem.o: C:/Users/H/Desktop/STM32/nucleoG4/Work_space/BareMetal/9.Systick/Src/sysmem.c DLY/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32G4 -DSTM32G431RBTx -c -I../Inc -I"C:/Users/H/Desktop/STM32/nucleoG4/CMSIS/Device/Include" -I"C:/Users/H/Desktop/STM32/nucleoG4/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-DLY

clean-DLY:
	-$(RM) ./DLY/main.cyclo ./DLY/main.d ./DLY/main.o ./DLY/main.su ./DLY/syscalls.cyclo ./DLY/syscalls.d ./DLY/syscalls.o ./DLY/syscalls.su ./DLY/sysmem.cyclo ./DLY/sysmem.d ./DLY/sysmem.o ./DLY/sysmem.su

.PHONY: clean-DLY

