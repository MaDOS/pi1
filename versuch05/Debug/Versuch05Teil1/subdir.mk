################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Versuch05Teil1/ListElem.cpp \
../Versuch05Teil1/Stack.cpp \
../Versuch05Teil1/main.cpp 

OBJS += \
./Versuch05Teil1/ListElem.o \
./Versuch05Teil1/Stack.o \
./Versuch05Teil1/main.o 

CPP_DEPS += \
./Versuch05Teil1/ListElem.d \
./Versuch05Teil1/Stack.d \
./Versuch05Teil1/main.d 


# Each subdirectory must supply rules for building sources it contributes
Versuch05Teil1/%.o: ../Versuch05Teil1/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


