/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Command: kcg662.exe -config C:/Users/missael/Documents/CINVESTAV/embedded critical software/Project/CC-003/System__SystemSimul_KCG66/config.txt
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "CruiseSpeedMgt_CruiseControl.h"

/* CruiseControl::CruiseSpeedMgt/ */
void CruiseSpeedMgt_CruiseControl(
  /* IfBlock1:, Set/ */
  kcg_bool Set,
  /* QuickAccel/ */
  kcg_bool QuickAccel,
  /* QuickDecel/ */
  kcg_bool QuickDecel,
  /* Speed/ */
  tSpeed_CarType Speed,
  outC_CruiseSpeedMgt_CruiseControl *outC)
{
  /* CruiseSpeed/ */
  tSpeed_Defs last_CruiseSpeed;
  /* @1/LUS_Input/, @1/_L3/, LocalCruiseSpeed/, _L43/ */
  tSpeed_Defs LocalCruiseSpeed;

  /* CruiseSpeed/ */
  if (outC->init) {
    outC->init = kcg_false;
    last_CruiseSpeed = Speed;
  }
  else {
    last_CruiseSpeed = outC->CruiseSpeed;
  }
  /* IfBlock1: */
  if (Set) {
    LocalCruiseSpeed = Speed;
  }
  else /* IfBlock1:else: */
  if (QuickAccel) {
    LocalCruiseSpeed = last_CruiseSpeed + SpeedInc_Defs;
  }
  else /* IfBlock1:else:else: */
  if (QuickDecel) {
    LocalCruiseSpeed = last_CruiseSpeed - SpeedInc_Defs;
  }
  else {
    LocalCruiseSpeed = last_CruiseSpeed;
  }
  /* @1/_L9= */
  if (LocalCruiseSpeed >= SpeedMax_Defs) {
    outC->CruiseSpeed = SpeedMax_Defs;
  }
  else /* @1/_L11= */
  if (LocalCruiseSpeed <= SpeedMin_Defs) {
    outC->CruiseSpeed = SpeedMin_Defs;
  }
  else {
    outC->CruiseSpeed = LocalCruiseSpeed;
  }
}

#ifndef KCG_USER_DEFINED_INIT
void CruiseSpeedMgt_init_CruiseControl(outC_CruiseSpeedMgt_CruiseControl *outC)
{
  outC->init = kcg_true;
  outC->CruiseSpeed = kcg_lit_float64(0.0);
}
#endif /* KCG_USER_DEFINED_INIT */


void CruiseSpeedMgt_reset_CruiseControl(outC_CruiseSpeedMgt_CruiseControl *outC)
{
  outC->init = kcg_true;
}

/*
  Expanded instances for: CruiseControl::CruiseSpeedMgt/
  @1: (pwlinear::LimiterUnSymmetrical#1)
*/

/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** CruiseSpeedMgt_CruiseControl.c
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

