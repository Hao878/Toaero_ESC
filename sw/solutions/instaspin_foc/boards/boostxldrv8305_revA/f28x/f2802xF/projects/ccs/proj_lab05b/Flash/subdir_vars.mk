################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
D:/ti/motorware/motorware_1_01_00_18/sw/ide/ccs/cmd/f2802x/F28027F.cmd 

LIB_SRCS += \
D:/ti/motorware/motorware_1_01_00_18/sw/modules/fast/lib/32b/f28x/f2802x/2802xRevB_Fast_IQ_ROMSymbols.lib \
D:/ti/motorware/motorware_1_01_00_18/sw/modules/fast/lib/32b/f28x/f2802x/2802xRevB_Fast_ONLY_ROMSymbols.lib \
D:/ti/motorware/motorware_1_01_00_18/sw/modules/fast/lib/32b/f28x/f2802x/2802xRevB_Fast_RTS_ROMSymbols.lib \
D:/ti/motorware/motorware_1_01_00_18/sw/modules/iqmath/lib/f28x/32b/IQmath.lib \
D:/ti/motorware/motorware_1_01_00_18/sw/modules/fast/lib/32b/f28x/f2802x/fast_public.lib 

ASM_SRCS += \
D:/ti/motorware/motorware_1_01_00_18/sw/drivers/cpu/src/32b/f28x/f2802x/CodeStartBranch.asm \
D:/ti/motorware/motorware_1_01_00_18/sw/modules/usDelay/src/32b/f28x/usDelay.asm 

C_SRCS += \
D:/ti/motorware/motorware_1_01_00_18/sw/drivers/adc/src/32b/f28x/f2802x/adc.c \
D:/ti/motorware/motorware_1_01_00_18/sw/modules/clarke/src/32b/clarke.c \
D:/ti/motorware/motorware_1_01_00_18/sw/drivers/clk/src/32b/f28x/f2802x/clk.c \
D:/ti/motorware/motorware_1_01_00_18/sw/drivers/cpu/src/32b/f28x/f2802x/cpu.c \
D:/ti/motorware/motorware_1_01_00_18/sw/modules/ctrl/src/32b/ctrl.c \
D:/ti/motorware/motorware_1_01_00_18/sw/drivers/drvic/drv8305/src/32b/f28x/f2802x/drv8305.c \
D:/ti/motorware/motorware_1_01_00_18/sw/modules/filter/src/32b/filter_fo.c \
D:/ti/motorware/motorware_1_01_00_18/sw/drivers/flash/src/32b/f28x/f2802x/flash.c \
D:/ti/motorware/motorware_1_01_00_18/sw/drivers/gpio/src/32b/f28x/f2802x/gpio.c \
D:/ti/motorware/motorware_1_01_00_18/sw/modules/hal/boards/boostxldrv8305_revA/f28x/f2802x/src/hal.c \
D:/ti/motorware/motorware_1_01_00_18/sw/modules/ipark/src/32b/ipark.c \
D:/ti/motorware/motorware_1_01_00_18/sw/modules/memCopy/src/memCopy.c \
D:/ti/motorware/motorware_1_01_00_18/sw/modules/offset/src/32b/offset.c \
D:/ti/motorware/motorware_1_01_00_18/sw/drivers/osc/src/32b/f28x/f2802x/osc.c \
D:/ti/motorware/motorware_1_01_00_18/sw/modules/park/src/32b/park.c \
D:/ti/motorware/motorware_1_01_00_18/sw/modules/pid/src/32b/pid.c \
D:/ti/motorware/motorware_1_01_00_18/sw/drivers/pie/src/32b/f28x/f2802x/pie.c \
D:/ti/motorware/motorware_1_01_00_18/sw/drivers/pll/src/32b/f28x/f2802x/pll.c \
D:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/src/proj_lab05b.c \
D:/ti/motorware/motorware_1_01_00_18/sw/drivers/pwm/src/32b/f28x/f2802x/pwm.c \
D:/ti/motorware/motorware_1_01_00_18/sw/drivers/pwr/src/32b/f28x/f2802x/pwr.c \
D:/ti/motorware/motorware_1_01_00_18/sw/drivers/spi/src/32b/f28x/f2802x/spi.c \
D:/ti/motorware/motorware_1_01_00_18/sw/modules/svgen/src/32b/svgen.c \
D:/ti/motorware/motorware_1_01_00_18/sw/drivers/timer/src/32b/f28x/f2802x/timer.c \
D:/ti/motorware/motorware_1_01_00_18/sw/modules/traj/src/32b/traj.c \
D:/ti/motorware/motorware_1_01_00_18/sw/modules/user/src/32b/user.c \
D:/ti/motorware/motorware_1_01_00_18/sw/drivers/wdog/src/32b/f28x/f2802x/wdog.c 

C_DEPS += \
./adc.d \
./clarke.d \
./clk.d \
./cpu.d \
./ctrl.d \
./drv8305.d \
./filter_fo.d \
./flash.d \
./gpio.d \
./hal.d \
./ipark.d \
./memCopy.d \
./offset.d \
./osc.d \
./park.d \
./pid.d \
./pie.d \
./pll.d \
./proj_lab05b.d \
./pwm.d \
./pwr.d \
./spi.d \
./svgen.d \
./timer.d \
./traj.d \
./user.d \
./wdog.d 

OBJS += \
./CodeStartBranch.obj \
./adc.obj \
./clarke.obj \
./clk.obj \
./cpu.obj \
./ctrl.obj \
./drv8305.obj \
./filter_fo.obj \
./flash.obj \
./gpio.obj \
./hal.obj \
./ipark.obj \
./memCopy.obj \
./offset.obj \
./osc.obj \
./park.obj \
./pid.obj \
./pie.obj \
./pll.obj \
./proj_lab05b.obj \
./pwm.obj \
./pwr.obj \
./spi.obj \
./svgen.obj \
./timer.obj \
./traj.obj \
./usDelay.obj \
./user.obj \
./wdog.obj 

ASM_DEPS += \
./CodeStartBranch.d \
./usDelay.d 

OBJS__QUOTED += \
"CodeStartBranch.obj" \
"adc.obj" \
"clarke.obj" \
"clk.obj" \
"cpu.obj" \
"ctrl.obj" \
"drv8305.obj" \
"filter_fo.obj" \
"flash.obj" \
"gpio.obj" \
"hal.obj" \
"ipark.obj" \
"memCopy.obj" \
"offset.obj" \
"osc.obj" \
"park.obj" \
"pid.obj" \
"pie.obj" \
"pll.obj" \
"proj_lab05b.obj" \
"pwm.obj" \
"pwr.obj" \
"spi.obj" \
"svgen.obj" \
"timer.obj" \
"traj.obj" \
"usDelay.obj" \
"user.obj" \
"wdog.obj" 

C_DEPS__QUOTED += \
"adc.d" \
"clarke.d" \
"clk.d" \
"cpu.d" \
"ctrl.d" \
"drv8305.d" \
"filter_fo.d" \
"flash.d" \
"gpio.d" \
"hal.d" \
"ipark.d" \
"memCopy.d" \
"offset.d" \
"osc.d" \
"park.d" \
"pid.d" \
"pie.d" \
"pll.d" \
"proj_lab05b.d" \
"pwm.d" \
"pwr.d" \
"spi.d" \
"svgen.d" \
"timer.d" \
"traj.d" \
"user.d" \
"wdog.d" 

ASM_DEPS__QUOTED += \
"CodeStartBranch.d" \
"usDelay.d" 

ASM_SRCS__QUOTED += \
"D:/ti/motorware/motorware_1_01_00_18/sw/drivers/cpu/src/32b/f28x/f2802x/CodeStartBranch.asm" \
"D:/ti/motorware/motorware_1_01_00_18/sw/modules/usDelay/src/32b/f28x/usDelay.asm" 

C_SRCS__QUOTED += \
"D:/ti/motorware/motorware_1_01_00_18/sw/drivers/adc/src/32b/f28x/f2802x/adc.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/modules/clarke/src/32b/clarke.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/drivers/clk/src/32b/f28x/f2802x/clk.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/drivers/cpu/src/32b/f28x/f2802x/cpu.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/modules/ctrl/src/32b/ctrl.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/drivers/drvic/drv8305/src/32b/f28x/f2802x/drv8305.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/modules/filter/src/32b/filter_fo.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/drivers/flash/src/32b/f28x/f2802x/flash.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/drivers/gpio/src/32b/f28x/f2802x/gpio.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/modules/hal/boards/boostxldrv8305_revA/f28x/f2802x/src/hal.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/modules/ipark/src/32b/ipark.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/modules/memCopy/src/memCopy.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/modules/offset/src/32b/offset.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/drivers/osc/src/32b/f28x/f2802x/osc.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/modules/park/src/32b/park.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/modules/pid/src/32b/pid.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/drivers/pie/src/32b/f28x/f2802x/pie.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/drivers/pll/src/32b/f28x/f2802x/pll.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/src/proj_lab05b.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/drivers/pwm/src/32b/f28x/f2802x/pwm.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/drivers/pwr/src/32b/f28x/f2802x/pwr.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/drivers/spi/src/32b/f28x/f2802x/spi.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/modules/svgen/src/32b/svgen.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/drivers/timer/src/32b/f28x/f2802x/timer.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/modules/traj/src/32b/traj.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/modules/user/src/32b/user.c" \
"D:/ti/motorware/motorware_1_01_00_18/sw/drivers/wdog/src/32b/f28x/f2802x/wdog.c" 


