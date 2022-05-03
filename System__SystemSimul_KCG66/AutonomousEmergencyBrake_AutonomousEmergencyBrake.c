/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Command: kcg662.exe -config C:/Users/missael/Documents/CINVESTAV/embedded critical software/Project/CC-003/System__SystemSimul_KCG66/config.txt
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "AutonomousEmergencyBrake_AutonomousEmergencyBrake.h"

/* AutonomousEmergencyBrake::AutonomousEmergencyBrake/ */
void AutonomousEmergencyBrake_AutonomousEmergencyBrake(
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
  outC_AutonomousEmergencyBrake_AutonomousEmergencyBrake *outC)
{
  /* SM1:Enabled:SM2: */
  SSM_ST_SM2_Enabled_SM1 SM2_state_act_Enabled_SM1;
  /* SM1:Enabled:SM2: */
  SSM_ST_SM2_Enabled_SM1 SM2_state_sel_Enabled_SM1;
  /* SM1:Enabled:SM2:, SM1:Enabled:SM2:Standby:<1> */
  kcg_bool SM2_reset_act_partial_Enabled_SM1;
  /* SM1: */
  SSM_ST_SM1 SM1_state_act;
  /* SM1: */
  kcg_bool SM1_reset_act;

  /* SM1: */
  switch (outC->SM1_state_nxt) {
    case _7_SSM_st_Enabled_SM1 :
      if (Off) {
        SM1_state_act = _6_SSM_st_Off_SM1;
      }
      else {
        SM1_state_act = _7_SSM_st_Enabled_SM1;
      }
      SM1_reset_act = Off;
      break;
    case _6_SSM_st_Off_SM1 :
      if (On) {
        SM1_state_act = _7_SSM_st_Enabled_SM1;
      }
      else {
        SM1_state_act = _6_SSM_st_Off_SM1;
      }
      SM1_reset_act = On;
      break;
    default :
      /* this default branch is unreachable */
      break;
  }
  /* SM1: */
  switch (SM1_state_act) {
    case _7_SSM_st_Enabled_SM1 :
      if (SM1_reset_act) {
        outC->init = kcg_true;
      }
      /* SM1:Enabled:SM2: */
      if (outC->init) {
        outC->init = kcg_false;
        SM2_state_sel_Enabled_SM1 = _8_SSM_st_Active_SM2_Enabled_SM1;
      }
      else {
        SM2_state_sel_Enabled_SM1 = outC->SM2_state_nxt_Enabled_SM1;
      }
      /* SM1:Enabled:SM2: */
      switch (SM2_state_sel_Enabled_SM1) {
        case SSM_st_Standby_SM2_Enabled_SM1 :
          SM2_reset_act_partial_Enabled_SM1 = !SteeringWheel;
          if (SM2_reset_act_partial_Enabled_SM1) {
            SM2_state_act_Enabled_SM1 = _8_SSM_st_Active_SM2_Enabled_SM1;
          }
          else {
            SM2_state_act_Enabled_SM1 = SSM_st_Standby_SM2_Enabled_SM1;
          }
          break;
        case _8_SSM_st_Active_SM2_Enabled_SM1 :
          if (SteeringWheel) {
            SM2_state_act_Enabled_SM1 = SSM_st_Standby_SM2_Enabled_SM1;
          }
          else {
            SM2_state_act_Enabled_SM1 = _8_SSM_st_Active_SM2_Enabled_SM1;
          }
          break;
        default :
          /* this default branch is unreachable */
          break;
      }
      /* SM1:Enabled:SM2: */
      switch (SM2_state_act_Enabled_SM1) {
        case SSM_st_Standby_SM2_Enabled_SM1 :
          outC->SM2_state_nxt_Enabled_SM1 = SSM_st_Standby_SM2_Enabled_SM1;
          outC->BrakePercent = Brake;
          break;
        case _8_SSM_st_Active_SM2_Enabled_SM1 :
          outC->SM2_state_nxt_Enabled_SM1 = _8_SSM_st_Active_SM2_Enabled_SM1;
          outC->BrakePercent =
            /* SM1:Enabled:SM2:Active:_L7=(AutonomousEmergencyBrake::IfCases#1)/ */
            IfCases_AutonomousEmergencyBrake(
              /* SM1:Enabled:SM2:Active:_L1=(AutonomousEmergencyBrake::ArduinoCalculation#1)/ */
              ArduinoCalculation_AutonomousEmergencyBrake(Time),
              SteeringWheel,
              Brake);
          break;
        default :
          /* this default branch is unreachable */
          break;
      }
      outC->SM1_state_nxt = _7_SSM_st_Enabled_SM1;
      break;
    case _6_SSM_st_Off_SM1 :
      outC->BrakePercent = Brake;
      outC->SM1_state_nxt = _6_SSM_st_Off_SM1;
      break;
    default :
      /* this default branch is unreachable */
      break;
  }
}

#ifndef KCG_USER_DEFINED_INIT
void AutonomousEmergencyBrake_init_AutonomousEmergencyBrake(
  outC_AutonomousEmergencyBrake_AutonomousEmergencyBrake *outC)
{
  outC->init = kcg_true;
  outC->SM2_state_nxt_Enabled_SM1 = _8_SSM_st_Active_SM2_Enabled_SM1;
  outC->BrakePercent = kcg_lit_float64(0.0);
  outC->SM1_state_nxt = _6_SSM_st_Off_SM1;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void AutonomousEmergencyBrake_reset_AutonomousEmergencyBrake(
  outC_AutonomousEmergencyBrake_AutonomousEmergencyBrake *outC)
{
  outC->init = kcg_true;
  outC->SM1_state_nxt = _6_SSM_st_Off_SM1;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** AutonomousEmergencyBrake_AutonomousEmergencyBrake.c
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

