#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/cs600-redo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/cs600-redo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=--mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=F:/2017/cs66/cs600-redo.X/src/api/ui.c F:/2017/cs66/cs600-redo.X/src/api/data.c F:/2017/cs66/cs600-redo.X/src/app/event.c F:/2017/cs66/cs600-redo.X/src/app/main.c F:/2017/cs66/cs600-redo.X/src/depend/m_string.c F:/2017/cs66/cs600-redo.X/src/driver/ad421.c F:/2017/cs66/cs600-redo.X/src/driver/ads1115.c F:/2017/cs66/cs600-redo.X/src/driver/ex_eeprom.c F:/2017/cs66/cs600-redo.X/src/driver/ex_pwr.c F:/2017/cs66/cs600-redo.X/src/driver/i2c.c F:/2017/cs66/cs600-redo.X/src/driver/iic_gpio.c F:/2017/cs66/cs600-redo.X/src/driver/in_adc.c F:/2017/cs66/cs600-redo.X/src/driver/key.c F:/2017/cs66/cs600-redo.X/src/driver/lcd.c F:/2017/cs66/cs600-redo.X/src/driver/m_flash.c F:/2017/cs66/cs600-redo.X/src/driver/m_gpio.c F:/2017/cs66/cs600-redo.X/src/driver/uart.c F:/2017/cs66/cs600-redo.X/src/soc/clock.c F:/2017/cs66/cs600-redo.X/src/soc/int.c F:/2017/cs66/cs600-redo.X/src/soc/rtc.c F:/2017/cs66/cs600-redo.X/src/soc/soc.c F:/2017/cs66/cs600-redo.X/src/soc/ticker.c F:/2017/cs66/cs600-redo.X/src/depend/crc16.c F:/2017/cs66/cs600-redo.X/src/api/key_menu.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1135332820/ui.p1 ${OBJECTDIR}/_ext/1135332820/data.p1 ${OBJECTDIR}/_ext/1135332813/event.p1 ${OBJECTDIR}/_ext/1135332813/main.p1 ${OBJECTDIR}/_ext/243453210/m_string.p1 ${OBJECTDIR}/_ext/255266518/ad421.p1 ${OBJECTDIR}/_ext/255266518/ads1115.p1 ${OBJECTDIR}/_ext/255266518/ex_eeprom.p1 ${OBJECTDIR}/_ext/255266518/ex_pwr.p1 ${OBJECTDIR}/_ext/255266518/i2c.p1 ${OBJECTDIR}/_ext/255266518/iic_gpio.p1 ${OBJECTDIR}/_ext/255266518/in_adc.p1 ${OBJECTDIR}/_ext/255266518/key.p1 ${OBJECTDIR}/_ext/255266518/lcd.p1 ${OBJECTDIR}/_ext/255266518/m_flash.p1 ${OBJECTDIR}/_ext/255266518/m_gpio.p1 ${OBJECTDIR}/_ext/255266518/uart.p1 ${OBJECTDIR}/_ext/1135315559/clock.p1 ${OBJECTDIR}/_ext/1135315559/int.p1 ${OBJECTDIR}/_ext/1135315559/rtc.p1 ${OBJECTDIR}/_ext/1135315559/soc.p1 ${OBJECTDIR}/_ext/1135315559/ticker.p1 ${OBJECTDIR}/_ext/243453210/crc16.p1 ${OBJECTDIR}/_ext/1135332820/key_menu.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1135332820/ui.p1.d ${OBJECTDIR}/_ext/1135332820/data.p1.d ${OBJECTDIR}/_ext/1135332813/event.p1.d ${OBJECTDIR}/_ext/1135332813/main.p1.d ${OBJECTDIR}/_ext/243453210/m_string.p1.d ${OBJECTDIR}/_ext/255266518/ad421.p1.d ${OBJECTDIR}/_ext/255266518/ads1115.p1.d ${OBJECTDIR}/_ext/255266518/ex_eeprom.p1.d ${OBJECTDIR}/_ext/255266518/ex_pwr.p1.d ${OBJECTDIR}/_ext/255266518/i2c.p1.d ${OBJECTDIR}/_ext/255266518/iic_gpio.p1.d ${OBJECTDIR}/_ext/255266518/in_adc.p1.d ${OBJECTDIR}/_ext/255266518/key.p1.d ${OBJECTDIR}/_ext/255266518/lcd.p1.d ${OBJECTDIR}/_ext/255266518/m_flash.p1.d ${OBJECTDIR}/_ext/255266518/m_gpio.p1.d ${OBJECTDIR}/_ext/255266518/uart.p1.d ${OBJECTDIR}/_ext/1135315559/clock.p1.d ${OBJECTDIR}/_ext/1135315559/int.p1.d ${OBJECTDIR}/_ext/1135315559/rtc.p1.d ${OBJECTDIR}/_ext/1135315559/soc.p1.d ${OBJECTDIR}/_ext/1135315559/ticker.p1.d ${OBJECTDIR}/_ext/243453210/crc16.p1.d ${OBJECTDIR}/_ext/1135332820/key_menu.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1135332820/ui.p1 ${OBJECTDIR}/_ext/1135332820/data.p1 ${OBJECTDIR}/_ext/1135332813/event.p1 ${OBJECTDIR}/_ext/1135332813/main.p1 ${OBJECTDIR}/_ext/243453210/m_string.p1 ${OBJECTDIR}/_ext/255266518/ad421.p1 ${OBJECTDIR}/_ext/255266518/ads1115.p1 ${OBJECTDIR}/_ext/255266518/ex_eeprom.p1 ${OBJECTDIR}/_ext/255266518/ex_pwr.p1 ${OBJECTDIR}/_ext/255266518/i2c.p1 ${OBJECTDIR}/_ext/255266518/iic_gpio.p1 ${OBJECTDIR}/_ext/255266518/in_adc.p1 ${OBJECTDIR}/_ext/255266518/key.p1 ${OBJECTDIR}/_ext/255266518/lcd.p1 ${OBJECTDIR}/_ext/255266518/m_flash.p1 ${OBJECTDIR}/_ext/255266518/m_gpio.p1 ${OBJECTDIR}/_ext/255266518/uart.p1 ${OBJECTDIR}/_ext/1135315559/clock.p1 ${OBJECTDIR}/_ext/1135315559/int.p1 ${OBJECTDIR}/_ext/1135315559/rtc.p1 ${OBJECTDIR}/_ext/1135315559/soc.p1 ${OBJECTDIR}/_ext/1135315559/ticker.p1 ${OBJECTDIR}/_ext/243453210/crc16.p1 ${OBJECTDIR}/_ext/1135332820/key_menu.p1

# Source Files
SOURCEFILES=F:/2017/cs66/cs600-redo.X/src/api/ui.c F:/2017/cs66/cs600-redo.X/src/api/data.c F:/2017/cs66/cs600-redo.X/src/app/event.c F:/2017/cs66/cs600-redo.X/src/app/main.c F:/2017/cs66/cs600-redo.X/src/depend/m_string.c F:/2017/cs66/cs600-redo.X/src/driver/ad421.c F:/2017/cs66/cs600-redo.X/src/driver/ads1115.c F:/2017/cs66/cs600-redo.X/src/driver/ex_eeprom.c F:/2017/cs66/cs600-redo.X/src/driver/ex_pwr.c F:/2017/cs66/cs600-redo.X/src/driver/i2c.c F:/2017/cs66/cs600-redo.X/src/driver/iic_gpio.c F:/2017/cs66/cs600-redo.X/src/driver/in_adc.c F:/2017/cs66/cs600-redo.X/src/driver/key.c F:/2017/cs66/cs600-redo.X/src/driver/lcd.c F:/2017/cs66/cs600-redo.X/src/driver/m_flash.c F:/2017/cs66/cs600-redo.X/src/driver/m_gpio.c F:/2017/cs66/cs600-redo.X/src/driver/uart.c F:/2017/cs66/cs600-redo.X/src/soc/clock.c F:/2017/cs66/cs600-redo.X/src/soc/int.c F:/2017/cs66/cs600-redo.X/src/soc/rtc.c F:/2017/cs66/cs600-redo.X/src/soc/soc.c F:/2017/cs66/cs600-redo.X/src/soc/ticker.c F:/2017/cs66/cs600-redo.X/src/depend/crc16.c F:/2017/cs66/cs600-redo.X/src/api/key_menu.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/cs600-redo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F86J93
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1135332820/ui.p1: F:/2017/cs66/cs600-redo.X/src/api/ui.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1135332820" 
	@${RM} ${OBJECTDIR}/_ext/1135332820/ui.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1135332820/ui.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1135332820/ui.p1  F:/2017/cs66/cs600-redo.X/src/api/ui.c 
	@-${MV} ${OBJECTDIR}/_ext/1135332820/ui.d ${OBJECTDIR}/_ext/1135332820/ui.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1135332820/ui.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1135332820/data.p1: F:/2017/cs66/cs600-redo.X/src/api/data.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1135332820" 
	@${RM} ${OBJECTDIR}/_ext/1135332820/data.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1135332820/data.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1135332820/data.p1  F:/2017/cs66/cs600-redo.X/src/api/data.c 
	@-${MV} ${OBJECTDIR}/_ext/1135332820/data.d ${OBJECTDIR}/_ext/1135332820/data.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1135332820/data.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1135332813/event.p1: F:/2017/cs66/cs600-redo.X/src/app/event.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1135332813" 
	@${RM} ${OBJECTDIR}/_ext/1135332813/event.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1135332813/event.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1135332813/event.p1  F:/2017/cs66/cs600-redo.X/src/app/event.c 
	@-${MV} ${OBJECTDIR}/_ext/1135332813/event.d ${OBJECTDIR}/_ext/1135332813/event.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1135332813/event.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1135332813/main.p1: F:/2017/cs66/cs600-redo.X/src/app/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1135332813" 
	@${RM} ${OBJECTDIR}/_ext/1135332813/main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1135332813/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1135332813/main.p1  F:/2017/cs66/cs600-redo.X/src/app/main.c 
	@-${MV} ${OBJECTDIR}/_ext/1135332813/main.d ${OBJECTDIR}/_ext/1135332813/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1135332813/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/243453210/m_string.p1: F:/2017/cs66/cs600-redo.X/src/depend/m_string.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/243453210" 
	@${RM} ${OBJECTDIR}/_ext/243453210/m_string.p1.d 
	@${RM} ${OBJECTDIR}/_ext/243453210/m_string.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/243453210/m_string.p1  F:/2017/cs66/cs600-redo.X/src/depend/m_string.c 
	@-${MV} ${OBJECTDIR}/_ext/243453210/m_string.d ${OBJECTDIR}/_ext/243453210/m_string.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/243453210/m_string.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/ad421.p1: F:/2017/cs66/cs600-redo.X/src/driver/ad421.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/ad421.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/ad421.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/ad421.p1  F:/2017/cs66/cs600-redo.X/src/driver/ad421.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/ad421.d ${OBJECTDIR}/_ext/255266518/ad421.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/ad421.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/ads1115.p1: F:/2017/cs66/cs600-redo.X/src/driver/ads1115.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/ads1115.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/ads1115.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/ads1115.p1  F:/2017/cs66/cs600-redo.X/src/driver/ads1115.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/ads1115.d ${OBJECTDIR}/_ext/255266518/ads1115.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/ads1115.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/ex_eeprom.p1: F:/2017/cs66/cs600-redo.X/src/driver/ex_eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/ex_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/ex_eeprom.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/ex_eeprom.p1  F:/2017/cs66/cs600-redo.X/src/driver/ex_eeprom.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/ex_eeprom.d ${OBJECTDIR}/_ext/255266518/ex_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/ex_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/ex_pwr.p1: F:/2017/cs66/cs600-redo.X/src/driver/ex_pwr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/ex_pwr.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/ex_pwr.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/ex_pwr.p1  F:/2017/cs66/cs600-redo.X/src/driver/ex_pwr.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/ex_pwr.d ${OBJECTDIR}/_ext/255266518/ex_pwr.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/ex_pwr.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/i2c.p1: F:/2017/cs66/cs600-redo.X/src/driver/i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/i2c.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/i2c.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/i2c.p1  F:/2017/cs66/cs600-redo.X/src/driver/i2c.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/i2c.d ${OBJECTDIR}/_ext/255266518/i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/iic_gpio.p1: F:/2017/cs66/cs600-redo.X/src/driver/iic_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/iic_gpio.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/iic_gpio.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/iic_gpio.p1  F:/2017/cs66/cs600-redo.X/src/driver/iic_gpio.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/iic_gpio.d ${OBJECTDIR}/_ext/255266518/iic_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/iic_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/in_adc.p1: F:/2017/cs66/cs600-redo.X/src/driver/in_adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/in_adc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/in_adc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/in_adc.p1  F:/2017/cs66/cs600-redo.X/src/driver/in_adc.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/in_adc.d ${OBJECTDIR}/_ext/255266518/in_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/in_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/key.p1: F:/2017/cs66/cs600-redo.X/src/driver/key.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/key.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/key.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/key.p1  F:/2017/cs66/cs600-redo.X/src/driver/key.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/key.d ${OBJECTDIR}/_ext/255266518/key.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/key.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/lcd.p1: F:/2017/cs66/cs600-redo.X/src/driver/lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/lcd.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/lcd.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/lcd.p1  F:/2017/cs66/cs600-redo.X/src/driver/lcd.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/lcd.d ${OBJECTDIR}/_ext/255266518/lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/m_flash.p1: F:/2017/cs66/cs600-redo.X/src/driver/m_flash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/m_flash.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/m_flash.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/m_flash.p1  F:/2017/cs66/cs600-redo.X/src/driver/m_flash.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/m_flash.d ${OBJECTDIR}/_ext/255266518/m_flash.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/m_flash.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/m_gpio.p1: F:/2017/cs66/cs600-redo.X/src/driver/m_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/m_gpio.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/m_gpio.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/m_gpio.p1  F:/2017/cs66/cs600-redo.X/src/driver/m_gpio.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/m_gpio.d ${OBJECTDIR}/_ext/255266518/m_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/m_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/uart.p1: F:/2017/cs66/cs600-redo.X/src/driver/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/uart.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/uart.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/uart.p1  F:/2017/cs66/cs600-redo.X/src/driver/uart.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/uart.d ${OBJECTDIR}/_ext/255266518/uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/uart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1135315559/clock.p1: F:/2017/cs66/cs600-redo.X/src/soc/clock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1135315559" 
	@${RM} ${OBJECTDIR}/_ext/1135315559/clock.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1135315559/clock.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1135315559/clock.p1  F:/2017/cs66/cs600-redo.X/src/soc/clock.c 
	@-${MV} ${OBJECTDIR}/_ext/1135315559/clock.d ${OBJECTDIR}/_ext/1135315559/clock.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1135315559/clock.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1135315559/int.p1: F:/2017/cs66/cs600-redo.X/src/soc/int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1135315559" 
	@${RM} ${OBJECTDIR}/_ext/1135315559/int.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1135315559/int.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1135315559/int.p1  F:/2017/cs66/cs600-redo.X/src/soc/int.c 
	@-${MV} ${OBJECTDIR}/_ext/1135315559/int.d ${OBJECTDIR}/_ext/1135315559/int.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1135315559/int.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1135315559/rtc.p1: F:/2017/cs66/cs600-redo.X/src/soc/rtc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1135315559" 
	@${RM} ${OBJECTDIR}/_ext/1135315559/rtc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1135315559/rtc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1135315559/rtc.p1  F:/2017/cs66/cs600-redo.X/src/soc/rtc.c 
	@-${MV} ${OBJECTDIR}/_ext/1135315559/rtc.d ${OBJECTDIR}/_ext/1135315559/rtc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1135315559/rtc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1135315559/soc.p1: F:/2017/cs66/cs600-redo.X/src/soc/soc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1135315559" 
	@${RM} ${OBJECTDIR}/_ext/1135315559/soc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1135315559/soc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1135315559/soc.p1  F:/2017/cs66/cs600-redo.X/src/soc/soc.c 
	@-${MV} ${OBJECTDIR}/_ext/1135315559/soc.d ${OBJECTDIR}/_ext/1135315559/soc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1135315559/soc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1135315559/ticker.p1: F:/2017/cs66/cs600-redo.X/src/soc/ticker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1135315559" 
	@${RM} ${OBJECTDIR}/_ext/1135315559/ticker.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1135315559/ticker.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1135315559/ticker.p1  F:/2017/cs66/cs600-redo.X/src/soc/ticker.c 
	@-${MV} ${OBJECTDIR}/_ext/1135315559/ticker.d ${OBJECTDIR}/_ext/1135315559/ticker.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1135315559/ticker.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/243453210/crc16.p1: F:/2017/cs66/cs600-redo.X/src/depend/crc16.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/243453210" 
	@${RM} ${OBJECTDIR}/_ext/243453210/crc16.p1.d 
	@${RM} ${OBJECTDIR}/_ext/243453210/crc16.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/243453210/crc16.p1  F:/2017/cs66/cs600-redo.X/src/depend/crc16.c 
	@-${MV} ${OBJECTDIR}/_ext/243453210/crc16.d ${OBJECTDIR}/_ext/243453210/crc16.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/243453210/crc16.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1135332820/key_menu.p1: F:/2017/cs66/cs600-redo.X/src/api/key_menu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1135332820" 
	@${RM} ${OBJECTDIR}/_ext/1135332820/key_menu.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1135332820/key_menu.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1135332820/key_menu.p1  F:/2017/cs66/cs600-redo.X/src/api/key_menu.c 
	@-${MV} ${OBJECTDIR}/_ext/1135332820/key_menu.d ${OBJECTDIR}/_ext/1135332820/key_menu.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1135332820/key_menu.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/1135332820/ui.p1: F:/2017/cs66/cs600-redo.X/src/api/ui.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1135332820" 
	@${RM} ${OBJECTDIR}/_ext/1135332820/ui.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1135332820/ui.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1135332820/ui.p1  F:/2017/cs66/cs600-redo.X/src/api/ui.c 
	@-${MV} ${OBJECTDIR}/_ext/1135332820/ui.d ${OBJECTDIR}/_ext/1135332820/ui.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1135332820/ui.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1135332820/data.p1: F:/2017/cs66/cs600-redo.X/src/api/data.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1135332820" 
	@${RM} ${OBJECTDIR}/_ext/1135332820/data.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1135332820/data.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1135332820/data.p1  F:/2017/cs66/cs600-redo.X/src/api/data.c 
	@-${MV} ${OBJECTDIR}/_ext/1135332820/data.d ${OBJECTDIR}/_ext/1135332820/data.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1135332820/data.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1135332813/event.p1: F:/2017/cs66/cs600-redo.X/src/app/event.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1135332813" 
	@${RM} ${OBJECTDIR}/_ext/1135332813/event.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1135332813/event.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1135332813/event.p1  F:/2017/cs66/cs600-redo.X/src/app/event.c 
	@-${MV} ${OBJECTDIR}/_ext/1135332813/event.d ${OBJECTDIR}/_ext/1135332813/event.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1135332813/event.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1135332813/main.p1: F:/2017/cs66/cs600-redo.X/src/app/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1135332813" 
	@${RM} ${OBJECTDIR}/_ext/1135332813/main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1135332813/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1135332813/main.p1  F:/2017/cs66/cs600-redo.X/src/app/main.c 
	@-${MV} ${OBJECTDIR}/_ext/1135332813/main.d ${OBJECTDIR}/_ext/1135332813/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1135332813/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/243453210/m_string.p1: F:/2017/cs66/cs600-redo.X/src/depend/m_string.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/243453210" 
	@${RM} ${OBJECTDIR}/_ext/243453210/m_string.p1.d 
	@${RM} ${OBJECTDIR}/_ext/243453210/m_string.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/243453210/m_string.p1  F:/2017/cs66/cs600-redo.X/src/depend/m_string.c 
	@-${MV} ${OBJECTDIR}/_ext/243453210/m_string.d ${OBJECTDIR}/_ext/243453210/m_string.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/243453210/m_string.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/ad421.p1: F:/2017/cs66/cs600-redo.X/src/driver/ad421.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/ad421.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/ad421.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/ad421.p1  F:/2017/cs66/cs600-redo.X/src/driver/ad421.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/ad421.d ${OBJECTDIR}/_ext/255266518/ad421.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/ad421.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/ads1115.p1: F:/2017/cs66/cs600-redo.X/src/driver/ads1115.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/ads1115.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/ads1115.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/ads1115.p1  F:/2017/cs66/cs600-redo.X/src/driver/ads1115.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/ads1115.d ${OBJECTDIR}/_ext/255266518/ads1115.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/ads1115.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/ex_eeprom.p1: F:/2017/cs66/cs600-redo.X/src/driver/ex_eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/ex_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/ex_eeprom.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/ex_eeprom.p1  F:/2017/cs66/cs600-redo.X/src/driver/ex_eeprom.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/ex_eeprom.d ${OBJECTDIR}/_ext/255266518/ex_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/ex_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/ex_pwr.p1: F:/2017/cs66/cs600-redo.X/src/driver/ex_pwr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/ex_pwr.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/ex_pwr.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/ex_pwr.p1  F:/2017/cs66/cs600-redo.X/src/driver/ex_pwr.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/ex_pwr.d ${OBJECTDIR}/_ext/255266518/ex_pwr.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/ex_pwr.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/i2c.p1: F:/2017/cs66/cs600-redo.X/src/driver/i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/i2c.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/i2c.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/i2c.p1  F:/2017/cs66/cs600-redo.X/src/driver/i2c.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/i2c.d ${OBJECTDIR}/_ext/255266518/i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/iic_gpio.p1: F:/2017/cs66/cs600-redo.X/src/driver/iic_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/iic_gpio.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/iic_gpio.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/iic_gpio.p1  F:/2017/cs66/cs600-redo.X/src/driver/iic_gpio.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/iic_gpio.d ${OBJECTDIR}/_ext/255266518/iic_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/iic_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/in_adc.p1: F:/2017/cs66/cs600-redo.X/src/driver/in_adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/in_adc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/in_adc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/in_adc.p1  F:/2017/cs66/cs600-redo.X/src/driver/in_adc.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/in_adc.d ${OBJECTDIR}/_ext/255266518/in_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/in_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/key.p1: F:/2017/cs66/cs600-redo.X/src/driver/key.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/key.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/key.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/key.p1  F:/2017/cs66/cs600-redo.X/src/driver/key.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/key.d ${OBJECTDIR}/_ext/255266518/key.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/key.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/lcd.p1: F:/2017/cs66/cs600-redo.X/src/driver/lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/lcd.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/lcd.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/lcd.p1  F:/2017/cs66/cs600-redo.X/src/driver/lcd.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/lcd.d ${OBJECTDIR}/_ext/255266518/lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/m_flash.p1: F:/2017/cs66/cs600-redo.X/src/driver/m_flash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/m_flash.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/m_flash.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/m_flash.p1  F:/2017/cs66/cs600-redo.X/src/driver/m_flash.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/m_flash.d ${OBJECTDIR}/_ext/255266518/m_flash.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/m_flash.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/m_gpio.p1: F:/2017/cs66/cs600-redo.X/src/driver/m_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/m_gpio.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/m_gpio.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/m_gpio.p1  F:/2017/cs66/cs600-redo.X/src/driver/m_gpio.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/m_gpio.d ${OBJECTDIR}/_ext/255266518/m_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/m_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/255266518/uart.p1: F:/2017/cs66/cs600-redo.X/src/driver/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/255266518" 
	@${RM} ${OBJECTDIR}/_ext/255266518/uart.p1.d 
	@${RM} ${OBJECTDIR}/_ext/255266518/uart.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/255266518/uart.p1  F:/2017/cs66/cs600-redo.X/src/driver/uart.c 
	@-${MV} ${OBJECTDIR}/_ext/255266518/uart.d ${OBJECTDIR}/_ext/255266518/uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/255266518/uart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1135315559/clock.p1: F:/2017/cs66/cs600-redo.X/src/soc/clock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1135315559" 
	@${RM} ${OBJECTDIR}/_ext/1135315559/clock.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1135315559/clock.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1135315559/clock.p1  F:/2017/cs66/cs600-redo.X/src/soc/clock.c 
	@-${MV} ${OBJECTDIR}/_ext/1135315559/clock.d ${OBJECTDIR}/_ext/1135315559/clock.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1135315559/clock.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1135315559/int.p1: F:/2017/cs66/cs600-redo.X/src/soc/int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1135315559" 
	@${RM} ${OBJECTDIR}/_ext/1135315559/int.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1135315559/int.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1135315559/int.p1  F:/2017/cs66/cs600-redo.X/src/soc/int.c 
	@-${MV} ${OBJECTDIR}/_ext/1135315559/int.d ${OBJECTDIR}/_ext/1135315559/int.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1135315559/int.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1135315559/rtc.p1: F:/2017/cs66/cs600-redo.X/src/soc/rtc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1135315559" 
	@${RM} ${OBJECTDIR}/_ext/1135315559/rtc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1135315559/rtc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1135315559/rtc.p1  F:/2017/cs66/cs600-redo.X/src/soc/rtc.c 
	@-${MV} ${OBJECTDIR}/_ext/1135315559/rtc.d ${OBJECTDIR}/_ext/1135315559/rtc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1135315559/rtc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1135315559/soc.p1: F:/2017/cs66/cs600-redo.X/src/soc/soc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1135315559" 
	@${RM} ${OBJECTDIR}/_ext/1135315559/soc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1135315559/soc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1135315559/soc.p1  F:/2017/cs66/cs600-redo.X/src/soc/soc.c 
	@-${MV} ${OBJECTDIR}/_ext/1135315559/soc.d ${OBJECTDIR}/_ext/1135315559/soc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1135315559/soc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1135315559/ticker.p1: F:/2017/cs66/cs600-redo.X/src/soc/ticker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1135315559" 
	@${RM} ${OBJECTDIR}/_ext/1135315559/ticker.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1135315559/ticker.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1135315559/ticker.p1  F:/2017/cs66/cs600-redo.X/src/soc/ticker.c 
	@-${MV} ${OBJECTDIR}/_ext/1135315559/ticker.d ${OBJECTDIR}/_ext/1135315559/ticker.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1135315559/ticker.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/243453210/crc16.p1: F:/2017/cs66/cs600-redo.X/src/depend/crc16.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/243453210" 
	@${RM} ${OBJECTDIR}/_ext/243453210/crc16.p1.d 
	@${RM} ${OBJECTDIR}/_ext/243453210/crc16.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/243453210/crc16.p1  F:/2017/cs66/cs600-redo.X/src/depend/crc16.c 
	@-${MV} ${OBJECTDIR}/_ext/243453210/crc16.d ${OBJECTDIR}/_ext/243453210/crc16.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/243453210/crc16.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1135332820/key_menu.p1: F:/2017/cs66/cs600-redo.X/src/api/key_menu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1135332820" 
	@${RM} ${OBJECTDIR}/_ext/1135332820/key_menu.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1135332820/key_menu.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1135332820/key_menu.p1  F:/2017/cs66/cs600-redo.X/src/api/key_menu.c 
	@-${MV} ${OBJECTDIR}/_ext/1135332820/key_menu.d ${OBJECTDIR}/_ext/1135332820/key_menu.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1135332820/key_menu.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/cs600-redo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/cs600-redo.X.${IMAGE_TYPE}.map  -D__DEBUG=1 --debugger=pickit3  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"        $(COMPARISON_BUILD) --memorysummary dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -odist/${CND_CONF}/${IMAGE_TYPE}/cs600-redo.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/cs600-redo.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/cs600-redo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/cs600-redo.X.${IMAGE_TYPE}.map  --double=32 --float=32 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --fill=0xaa --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:160:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     $(COMPARISON_BUILD) --memorysummary dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -odist/${CND_CONF}/${IMAGE_TYPE}/cs600-redo.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
