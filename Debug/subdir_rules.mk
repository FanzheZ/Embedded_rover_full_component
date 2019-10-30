################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/jessi/workspace_v9/mqtt_client_CC3220SF_LAUNCHXL_freertos_ccs_syscfg" --include_path="C:/Users/jessi/workspace_v9/mqtt_client_CC3220SF_LAUNCHXL_freertos_ccs_syscfg/Debug" --include_path="C:/ti/simplelink_cc32xx_sdk_3_20_01_01/source" --include_path="C:/ti/simplelink_cc32xx_sdk_3_20_01_01/source/ti/posix/ccs" --include_path="C:/FreeRTOSv10.2.1/FreeRTOS/Source/include" --include_path="C:/FreeRTOSv10.2.1/FreeRTOS/Source/portable/CCS/ARM_CM3" --include_path="C:/Users/jessi/workspace_v9/freertos_builds_CC3220SF_LAUNCHXL_release_ccs" --include_path="C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/include" -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/jessi/workspace_v9/mqtt_client_CC3220SF_LAUNCHXL_freertos_ccs_syscfg/Debug/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-401114479:
	@$(MAKE) --no-print-directory -Onone -f subdir_rules.mk build-401114479-inproc

build-401114479-inproc: ../common.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs910/ccs/utils/sysconfig/sysconfig_cli.bat" -s "C:/ti/simplelink_cc32xx_sdk_3_20_01_01/.metadata/product.json" -o "syscfg" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/ti_drivers_net_wifi_config.c: build-401114479 ../common.syscfg
syscfg/Board.c: build-401114479
syscfg/Board.h: build-401114479
syscfg/: build-401114479

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/jessi/workspace_v9/mqtt_client_CC3220SF_LAUNCHXL_freertos_ccs_syscfg" --include_path="C:/Users/jessi/workspace_v9/mqtt_client_CC3220SF_LAUNCHXL_freertos_ccs_syscfg/Debug" --include_path="C:/ti/simplelink_cc32xx_sdk_3_20_01_01/source" --include_path="C:/ti/simplelink_cc32xx_sdk_3_20_01_01/source/ti/posix/ccs" --include_path="C:/FreeRTOSv10.2.1/FreeRTOS/Source/include" --include_path="C:/FreeRTOSv10.2.1/FreeRTOS/Source/portable/CCS/ARM_CM3" --include_path="C:/Users/jessi/workspace_v9/freertos_builds_CC3220SF_LAUNCHXL_release_ccs" --include_path="C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/include" -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/jessi/workspace_v9/mqtt_client_CC3220SF_LAUNCHXL_freertos_ccs_syscfg/Debug/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


