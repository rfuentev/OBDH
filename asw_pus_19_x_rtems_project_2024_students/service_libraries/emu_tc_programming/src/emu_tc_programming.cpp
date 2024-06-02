/*
 * emu_tc_programming.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: user
 */

#include <public/emu_hw_timecode_drv_v1.h>
#include <public/emu_sc_channel_drv_v1.h>
#include <public/emu_gss_v1.h>

//#define FT_SOLO_EPD_ICU_SERV_17_0010
//#define FT_SOLO_EPD_ICU_SERV_9_0020
//#define FT_SOLO_EPD_ICU_SERV_1_REJ_TC_0030

//TODO
//#define FT_SOLO_EPD_ICU_SERV_3_DISABLE_SID0_0040
//#define FT_SOLO_EPD_ICU_SERV_3_UPDATE_INTERVAL_TC_0050

//#define FT_SOLO_EPD_ICU_SERV_20_UPDATE_PARAM_VALUE_0060

//#define FT_SOLO_EPD_ICU_Monitoring_0070

#define FT_SOLO_EPD_DeviceControl_0080

//TODO
// NOMBRE DEL SERVICIO A USAR
#ifdef FT_SOLO_EPD_ICU_SERV19_0190
// Test para comprobar el servicio 19
// Me defino los tiempos para los que van a ir ejecutando los steps
#define FT_0190_TIME_step0(UNITIME_AFTER_POWER_ON + )

// sinceramente estos puntos no sé para que sirven
#define FT_SOLO_EPD_Event_Action_0090
#define FT_SOLO_EPD_Event_Action_0100
#define FT_SOLO_EPD_Event_Action_0110

// PASO 0
EmuGSS_TCProgram20_3 prog_FT_0190_step0(UNITIME_AFTER_POWER_ON + 5,"FT_SOLO_EPD_ICU_SERV_20_0190 STEP 0, Set Param 0 to value 7",0,7);
// Me tiene que devolver unas determinadas TMs que son la (1,1) y la TM(1,7)
// Como es emuTCprogramming no hay que programar las telemetrias que se reciben

// PASO 1
// Mandar un TC(12,5) para definir la monitorización del parámetro 0
EmuGSS_TCProgram12_5 prog_FT_0190_step1(UNITIME_AFTER_POWER_ON + 6, "FT_SOLO_EPD_ICU_SERV_12_0190 STEP 1, Define the monitoring of parameter 0",0,1,0x3001,5,0x3002,10);

// PASO 2
// Permitir la monitorización de un TC(12,1)
EmuGSS_TCProgram12_1 prog_FT_0190_step2(UNITIME_AFTER_POWER_ON + 7, "FT_SOLO_EPD_ICU_SERV_12_0190 STEP 2, Enable motoring sending",0);

// PASO 3
// Mandar un TC(19,1) para asociar la TC(128,2) al evento de 0x3002
EmuGSS_TCProgram19_1 prog_FT_0190_step3(UNITIME_AFTER_POWER_ON + 8,  "FT_SOLO_EPD_ICU_SERV_12_0190 STEP 3, Send TC(19,1) to associate TC(128,2) to a type of event", 0x3002, 128,2);

// PASO 4
// Send TC(19,4) para permitir la event association
EmuGSS_TCProgram19_4 prog_FT_0190_step4(UNITIME_AFTER_POWER_ON + 9, "FT_SOLO EPD_ICU_SERV_19_0190 STEP 4, Send TC(19,4) to enable event association", 0x3002);

// PASO 5
// Cambio el valor de un determinado parámetro para settearlo de 0 a 15, por eso uso servicio 20
EmuGSS_TCProgram20_3 prog_FT_0190_step5(UNITIME_AFTER_POWER_ON + 10,"FT_SOLO_EPD_ICU_SERV_20_0190 STEP 5, Set Param 0 to value 15",0,15);

// PASO 6
// Ahora lo que hacemos es coger el valor del TC(19,5) to disable event association
EmuGSS_TCProgram19_5 prog_FT_0190_step6(UNITIME_AFTER_POWER_ON + 11, "FT_SOLO _EPD_ICU_SERV_19_0190 STEP 6, Send TC(19,5) to disable event association", 0x3002);

// PASO 7
//Enviar un TC(20,3) para settear el parametro 0 a 15, cambio de valor
EmuGSS_TCProgram20_3 prog_FT_0190_step7(UNITIME_AFTER_POWER_ON + 12,"FT_SOLO_EPD_ICU_SERV_20_0190 STEP 7, Set Param 0 to value 15",0,15);

// PASO 8
//Enviar TC(19,4) para permitir otra vez la event association
// ni idea de porq hace esto????
EmuGSS_TCProgram19_4 prog_FT_0190_step8(UNITIME_AFTER_POWER_ON + 13, "FT_SOLO EPD_ICU_SERV_19_0190 STEP 8, Send TC(19,4) to enable event association", 0x3002);


// PASO 9
// Enviar un TC(19,2) para borrar la asociacion de TC(128,2) al evento que habiamos puesto
EmuGSS_TCProgram19_2 prog_FT_0190_step9(UNITIME_AFTER_POWER_ON + 14,  "FT_SOLO_EPD_ICU_SERV_12_0190 STEP 3, Send TC(19,2) to delete the association of TC (128,2) to event 0x3002", 0x3002);

// PASO 10
// Enviar un TC(20,3) para otra vez settear el parametro 0 a 15. Es posible que lo este cambiando??
EmuGSS_TCProgram20_3 prog_FT_0190_step7(UNITIME_AFTER_POWER_ON + 15, "FT_SOLO_EPD_ICU_SERV_20_0190 STEP 7, Set Param 0 to value 15",0,15)
#endif




#ifdef FT_SOLO_EPD_ICU_SERV_17_0010

EmuGSS_TCProgram17_1 prog_FT_0010_step_0(UNITIME_AFTER_POWER_ON + 6,
					"FT_SOLO_EPD_ICU_SERV_17_0010 step 0, Connection Test");


#endif

#ifdef FT_SOLO_EPD_ICU_SERV_9_0020

#define FT_SOLO_EPD_ICU_SERV_9_0020_TIME 200000

EmuGSS_TCProgram9_129 prog_FT_0020_step_0(UNITIME_AFTER_POWER_ON + 10 ,
		"FT_SOLO_EPD_ICU_SERV_9_0020 step 0, Update UniTime Test",
		FT_SOLO_EPD_ICU_SERV_9_0020_TIME);



#endif

#ifdef FT_SOLO_EPD_ICU_SERV_1_REJ_TC_0030


#define FT_SOLO_EPD_ICU_SERV_1_0030_TIME (UNITIME_AFTER_POWER_ON + 10)

EmuGSS_TCProgram17_3 prog_FT_0030_step_0(FT_SOLO_EPD_ICU_SERV_1_0030_TIME,
		"FT_SOLO_EPD_ICU_SERV_1_0030 step 0, Rejected TC",0xFF);

#endif

#ifdef FT_SOLO_EPD_ICU_SERV_3_DISABLE_SID0_0040

#define FT_SOLO_EPD_ICU_SERV_3_0040_TIME (UNITIME_AFTER_POWER_ON + 30)

EmuGSS_TCProgram3_6 prog_FT_0040_step_0(FT_SOLO_EPD_ICU_SERV_3_0040_TIME,
		"FT_SOLO_EPD_ICU_SERV_3_0040 step 0, Disable SID 0 ",0);

#endif

#ifdef FT_SOLO_EPD_ICU_SERV_3_UPDATE_INTERVAL_TC_0050


#define FT_SOLO_EPD_ICU_SERV_3_0050_TIME_step0 (UNITIME_AFTER_POWER_ON + 35)
#define FT_SOLO_EPD_ICU_SERV_3_0050_TIME_step1 (FT_SOLO_EPD_ICU_SERV_3_0050_TIME_step0 + 10)
#define FT_SOLO_EPD_ICU_SERV_3_0050_TIME_step2 (FT_SOLO_EPD_ICU_SERV_3_0050_TIME_step1 + 10)


EmuGSS_TCProgram3_31 prog_FT_0050_step_0(FT_SOLO_EPD_ICU_SERV_3_0050_TIME_step0,
		"FT_SOLO_EPD_ICU_SERV_3_0050 step 0, Update SID 10 Rate to 5",10,5);

EmuGSS_TCProgram3_6 prog_FT_0050_step_1(FT_SOLO_EPD_ICU_SERV_3_0050_TIME_step1,
		"FT_SOLO_EPD_ICU_SERV_3_0050 step 1, Disable SID 10 ",10);

EmuGSS_TCProgram3_5 prog_FT_0050_step_2(FT_SOLO_EPD_ICU_SERV_3_0050_TIME_step2,
		"FT_SOLO_EPD_ICU_SERV_3_0050 step 2, Enable SID 10 ",10);


#endif

#ifdef FT_SOLO_EPD_ICU_SERV_20_UPDATE_PARAM_VALUE_0060


#define FT_SOLO_EPD_ICU_SERV_20_0060_TIME_step0 (UNITIME_AFTER_POWER_ON + 5)
#define FT_SOLO_EPD_ICU_SERV_20_0060_TIME_step1 (UNITIME_AFTER_POWER_ON + 8)


EmuGSS_TCProgram20_3 prog_FT_0060_step_0(FT_SOLO_EPD_ICU_SERV_20_0060_TIME_step0,
		"FT_SOLO_EPD_ICU_SERV_20_0060 step 0, Update PID 1 to 99",1,99);

EmuGSS_TCProgram20_1 prog_FT_0060_step_1(FT_SOLO_EPD_ICU_SERV_20_0060_TIME_step1,
		"FT_SOLO_EPD_ICU_SERV_20_0060 step 1, Get PID 1 Value",1);


#endif

#ifdef FT_SOLO_EPD_ICU_Monitoring_0070


#endif

#ifdef FT_SOLO_EPD_DeviceControl_0080

EmuGSS_TCProgram2_1 prog_FT_0080_step_0(UNITIME_AFTER_POWER_ON + 6,
					"FT_SOLO_EPD_ICU_SERV_2_1_0080 step 0, Device 1 Off",
					1, DeviceCommandOff);

EmuGSS_TCProgram2_1 prog_FT_0080_step_1(UNITIME_AFTER_POWER_ON + 6,
					"FT_SOLO_EPD_ICU_SERV_2_1_0080 step 1, Device 2 On",
					2, DeviceCommandOn);

EmuGSS_TCProgram2_1 prog_FT_0080_step_2(UNITIME_AFTER_POWER_ON + 6,
					"FT_SOLO_EPD_ICU_SERV_2_1_0080 step 1, Device Not Valid On",
					6, DeviceCommandOn);

#endif


#ifdef FT_SOLO_EPD_Event_Action_0090



#endif

#ifdef FT_SOLO_EPD_Event_Action_0100



#endif

#ifdef FT_SOLO_EPD_Event_Action_0110



#endif
