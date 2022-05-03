/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Command: kcg662.exe -config C:/Users/missael/Documents/CINVESTAV/embedded critical software/Project/CC-003/System__SystemSimul_KCG66/config.txt
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */
#ifndef _AutonomousEmergencyBrake_AutonomousEmergencyBrake_H_
#define _AutonomousEmergencyBrake_AutonomousEmergencyBrake_H_

#include "kcg_types.h"
#include "IfCases_AutonomousEmergencyBrake.h"
#include "ArduinoCalculation_AutonomousEmergencyBrake.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  tPercent_CarType /* BrakePercent/ */ BrakePercent;
  /* -----------------------  no local probes  ----------------------- */
  /* ----------------------- local memories  ------------------------- */
  kcg_bool init;
  SSM_ST_SM2_Enabled_SM1 /* SM1:Enabled:SM2: */ SM2_state_nxt_Enabled_SM1;
  SSM_ST_SM1 /* SM1: */ SM1_state_nxt;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_AutonomousEmergencyBrake_AutonomousEmergencyBrake;

/* ===========  node initialization and cycle functions  =========== */
/* AutonomousEmergencyBrake::AutonomousEmergencyBrake/ */
extern void AutonomousEmergencyBrake_AutonomousEmergencyBrake(
  /* On/ */
  kcg_bool On,
  /* Off/ */
  kcg_bool Off,
  /* SteeringWheel/ */
  kcg_bool SteeringWheel,
  /* Time/ */
  kcg_float64 Time,
  /* Brake/ */
  tPercent_CarType Brake,
  outC_AutonomousEmergencyBrake_AutonomousEmergencyBrake *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void AutonomousEmergencyBrake_reset_AutonomousEmergencyBrake(
  outC_AutonomousEmergencyBrake_AutonomousEmergencyBrake *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void AutonomousEmergencyBrake_init_AutonomousEmergencyBrake(
  outC_AutonomousEmergencyBrake_AutonomousEmergencyBrake *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _AutonomousEmergencyBrake_AutonomousEmergencyBrake_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** AutonomousEmergencyBrake_AutonomousEmergencyBrake.h
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

