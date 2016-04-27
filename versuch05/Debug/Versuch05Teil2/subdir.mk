################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Versuch05Teil2/List.cpp \
../Versuch05Teil2/ListElem.cpp \
../Versuch05Teil2/main.cpp 

OBJS += \
./Versuch05Teil2/List.o \
./Versuch05Teil2/ListElem.o \
./Versuch05Teil2/main.o 

CPP_DEPS += \
./Versuch05Teil2/List.d \
./Versuch05Teil2/ListElem.d \
./Versuch05Teil2/main.d 


# Each subdirectory must supply rules for building sources it contributes
Versuch05Teil2/%.o: ../Versuch05Teil2/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


