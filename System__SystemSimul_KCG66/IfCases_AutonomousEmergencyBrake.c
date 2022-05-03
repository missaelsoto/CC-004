/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Command: kcg662.exe -config C:/Users/missael/Documents/CINVESTAV/embedded critical software/Project/CC-003/System__SystemSimul_KCG66/config.txt
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "IfCases_AutonomousEmergencyBrake.h"

/* AutonomousEmergencyBrake::IfCases/ */
tPercent_CarType IfCases_AutonomousEmergencyBrake(
  /* Long/ */
  kcg_float64 Long,
  /* SteeringWheel/ */
  kcg_bool SteeringWheel,
  /* Brake/ */
  tPercent_CarType Brake)
{
  /* IfBlock1:else: */
  kcg_bool else_clock_IfBlock1;
  /* IfBlock1:else:else:else: */
  kcg_bool else_clock_else_else_IfBlock1;
  /* IfBlock1:else:else: */
  kcg_bool else_clock_else_IfBlock1;
  /* IfBlock1: */
  kcg_bool IfBlock1_clock;
  /* BrakePercent/ */
  tPercent_CarType BrakePercent;

  IfBlock1_clock = (Long < kcg_lit_float64(50.)) & SteeringWheel;
  /* IfBlock1: */
  if (IfBlock1_clock) {
    BrakePercent = Brake;
  }
  else {
    else_clock_IfBlock1 = (Long < kcg_lit_float64(100.)) & SteeringWheel;
    /* IfBlock1:else: */
    if (else_clock_IfBlock1) {
      BrakePercent = Brake;
    }
    else {
      else_clock_else_IfBlock1 = Long < kcg_lit_float64(50.);
      /* IfBlock1:else:else: */
      if (else_clock_else_IfBlock1) {
        BrakePercent = BrakeConst_Defs;
      }
      else {
        else_clock_else_else_IfBlock1 = Long < kcg_lit_float64(100.);
        /* IfBlock1:else:else:else: */
        if (else_clock_else_else_IfBlock1) {
          BrakePercent = SecondBrakeConst_Defs;
        }
        else {
          BrakePercent = Brake;
        }
      }
    }
  }
  return BrakePercent;
}



/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** IfCases_AutonomousEmergencyBrake.c
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

