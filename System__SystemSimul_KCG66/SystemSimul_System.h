/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Command: kcg662.exe -config C:/Users/missael/Documents/CINVESTAV/embedded critical software/Project/CC-003/System__SystemSimul_KCG66/config.txt
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */
#ifndef _SystemSimul_System_H_
#define _SystemSimul_System_H_

#include "kcg_types.h"
#include "AutonomousEmergencyBrake_AutonomousEmergencyBrake.h"
#include "CruiseControl_CruiseControl.h"
#include "CarModel_Car.h"

/* ========================  input structure  ====================== */
typedef struct {
  kcg_bool /* On/, _L4/ */ On;
  kcg_bool /* Off/, _L25/ */ Off;
  kcg_bool /* Resume/, _L6/ */ Resume;
  kcg_bool /* Set/, _L7/ */ Set;
  kcg_bool /* QuickAccel/, _L8/ */ QuickAccel;
  kcg_bool /* QuickDecel/, _L9/ */ QuickDecel;
  tPercent_Defs /* Accel/, _L10/ */ Accel;
  tPercent_Defs /* Brake/, _L11/, _L38/, _L46/ */ Brake;
  kcg_bool /* OnEmergencyBrake/, _L34/ */ OnEmergencyBrake;
  kcg_bool /* OffEmergencyBrake/, _L35/ */ OffEmergencyBrake;
  kcg_bool /* SterringWheel/, _L36/ */ SterringWheel;
  kcg_float64 /* Time/, _L37/ */ Time;
} inC_SystemSimul_System;

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  tSpeed_Defs /* CruiseSpeed/, _L26/ */ CruiseSpeed;
  tCruiseState_Defs /* CruiseState/, _L28/ */ CruiseState;
  tSpeed_Defs /* CarSpeed/ */ CarSpeed;
  /* -----------------------  no local probes  ----------------------- */
  /* ----------------------- local memories  ------------------------- */
  tSpeed_Defs /* _L19/ */ _L19;
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_CarModel_Car /* _L12=(Car::CarModel#1)/ */ Context_CarModel_1;
  outC_AutonomousEmergencyBrake_AutonomousEmergencyBrake /* _L33=(AutonomousEmergencyBrake::AutonomousEmergencyBrake#1)/ */ Context_AutonomousEmergencyBrake_1;
  outC_CruiseControl_CruiseControl /* _L26=(CruiseControl::CruiseControl#1)/ */ Context_CruiseControl_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_SystemSimul_System;

/* ===========  node initialization and cycle functions  =========== */
/* System::SystemSimul/ */
extern void SystemSimul_System(
  inC_SystemSimul_System *inC,
  outC_SystemSimul_System *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void SystemSimul_reset_System(outC_SystemSimul_System *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void SystemSimul_init_System(outC_SystemSimul_System *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _SystemSimul_System_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** SystemSimul_System.h
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

