################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/arcade.c \
../src/informes.c \
../src/pp_scabrera_1H.c \
../src/salon.c \
../src/unionArcSal.c \
../src/utn.c 

OBJS += \
./src/arcade.o \
./src/informes.o \
./src/pp_scabrera_1H.o \
./src/salon.o \
./src/unionArcSal.o \
./src/utn.o 

C_DEPS += \
./src/arcade.d \
./src/informes.d \
./src/pp_scabrera_1H.d \
./src/salon.d \
./src/unionArcSal.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


