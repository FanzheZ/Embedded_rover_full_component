################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./MQTT_test.obj" \
"./MQTT_test_queue.obj" \
"./MQTT_write_queue.obj" \
"./client_cbs.obj" \
"./syscfg/ti_drivers_net_wifi_config.obj" \
"./syscfg/Board.obj" \
"./debug.obj" \
"./gpio_hal.obj" \
"./jsmn.obj" \
"./json_parse.obj" \
"./main_freertos.obj" \
"./mqtt_client_app.obj" \
"./network_if.obj" \
"./pwm_hal.obj" \
"./rover_control_queue.obj" \
"./rover_control_thread.obj" \
"./stat_queue.obj" \
"./stat_task.obj" \
"./timer_MQTT_stats.obj" \
"./timerone.obj" \
"./uart_term.obj" \
"../CC3220SF_LAUNCHXL_FREERTOS.cmd" \
$(GEN_CMDS__FLAG) \
-l"ccs/m4/mqtt_release.a" \
-l"ccs/m4/slnetsock_release.a" \
-l"ccs/Release/slnetifwifi.a" \
-l"ti/display/lib/display.aem4" \
-l"ti/grlib/lib/ccs/m4/grlib.a" \
-l"third_party/spiffs/lib/ccs/m4/spiffs.a" \
-l"ti/drivers/lib/drivers_cc32xx.aem4" \
-l"third_party/fatfs/lib/ccs/m4/fatfs.a" \
-l"ccs/rtos/simplelink.a" \
-lfreertos_builds_CC3220SF_LAUNCHXL_release_ccs.lib \
-l"ti/devices/cc32xx/driverlib/ccs/Release/driverlib.a" \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
mqtt_client_CC3220SF_LAUNCHXL_freertos_ccs_syscfg.out \

EXE_OUTPUTS__QUOTED += \
"mqtt_client_CC3220SF_LAUNCHXL_freertos_ccs_syscfg.out" \

BIN_OUTPUTS += \
mqtt_client_CC3220SF_LAUNCHXL_freertos_ccs_syscfg.bin \

BIN_OUTPUTS__QUOTED += \
"mqtt_client_CC3220SF_LAUNCHXL_freertos_ccs_syscfg.bin" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "mqtt_client_CC3220SF_LAUNCHXL_freertos_ccs_syscfg.out"

dependents:
	-cd C:/Users/jessi/workspace_v9/freertos_builds_CC3220SF_LAUNCHXL_release_ccs/Debug && $(MAKE) clean all

# Tool invocations
mqtt_client_CC3220SF_LAUNCHXL_freertos_ccs_syscfg.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS) C:/Users/jessi/workspace_v9/freertos_builds_CC3220SF_LAUNCHXL_release_ccs/Debug/freertos_builds_CC3220SF_LAUNCHXL_release_ccs.lib
	@echo 'Building target: "$@"'
	@echo 'Invoking: ARM Linker'
	"C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on -z -m"mqtt_client_CC3220SF_LAUNCHXL_freertos_ccs_syscfg.map" -i"C:/ti/simplelink_cc32xx_sdk_3_20_01_01/source/ti/net/mqtt/lib" -i"C:/ti/simplelink_cc32xx_sdk_3_20_01_01/source/ti/net/lib" -i"C:/ti/simplelink_cc32xx_sdk_3_20_01_01/source/ti/drivers/net/wifi/slnetif" -i"C:/ti/simplelink_cc32xx_sdk_3_20_01_01/source" -i"C:/ti/simplelink_cc32xx_sdk_3_20_01_01/source/ti/drivers/net/wifi" -i"C:/Users/jessi/workspace_v9/freertos_builds_CC3220SF_LAUNCHXL_release_ccs/Debug" -i"C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/lib" --diag_suppress=10063 --diag_wrap=off --display_error_number --warn_sections --xml_link_info="mqtt_client_CC3220SF_LAUNCHXL_freertos_ccs_syscfg_linkInfo.xml" --rom_model -o "mqtt_client_CC3220SF_LAUNCHXL_freertos_ccs_syscfg.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

mqtt_client_CC3220SF_LAUNCHXL_freertos_ccs_syscfg.bin: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: ARM Hex Utility'
	"C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/bin/armhex"  -o "mqtt_client_CC3220SF_LAUNCHXL_freertos_ccs_syscfg.bin" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(BIN_OUTPUTS__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "MQTT_test.obj" "MQTT_test_queue.obj" "MQTT_write_queue.obj" "client_cbs.obj" "syscfg\ti_drivers_net_wifi_config.obj" "syscfg\Board.obj" "debug.obj" "gpio_hal.obj" "jsmn.obj" "json_parse.obj" "main_freertos.obj" "mqtt_client_app.obj" "network_if.obj" "pwm_hal.obj" "rover_control_queue.obj" "rover_control_thread.obj" "stat_queue.obj" "stat_task.obj" "timer_MQTT_stats.obj" "timerone.obj" "uart_term.obj" 
	-$(RM) "MQTT_test.d" "MQTT_test_queue.d" "MQTT_write_queue.d" "client_cbs.d" "syscfg\ti_drivers_net_wifi_config.d" "syscfg\Board.d" "debug.d" "gpio_hal.d" "jsmn.d" "json_parse.d" "main_freertos.d" "mqtt_client_app.d" "network_if.d" "pwm_hal.d" "rover_control_queue.d" "rover_control_thread.d" "stat_queue.d" "stat_task.d" "timer_MQTT_stats.d" "timerone.d" "uart_term.d" 
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-C:/ti/ccs910/ccs/utils/tiobj2bin/tiobj2bin mqtt_client_CC3220SF_LAUNCHXL_freertos_ccs_syscfg.out mqtt_client_CC3220SF_LAUNCHXL_freertos_ccs_syscfg.bin C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/bin/armofd C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/bin/armhex C:/ti/ccs910/ccs/utils/tiobj2bin/mkhex4bin
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:
C:/Users/jessi/workspace_v9/freertos_builds_CC3220SF_LAUNCHXL_release_ccs/Debug/freertos_builds_CC3220SF_LAUNCHXL_release_ccs.lib:

-include ../makefile.targets

