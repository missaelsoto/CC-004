/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Command: kcg662.exe -config C:/Users/missael/Documents/CINVESTAV/embedded critical software/Project/CC-003/System__SystemSimul_KCG66/config.txt
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "CruiseRegulation_CruiseControl.h"

/* CruiseControl::CruiseRegulation/ */
void CruiseRegulation_CruiseControl(
  /* CruiseSpeed/, _L1/ */
  tSpeed_Defs CruiseSpeed,
  /* VehiculeSpeed/, _L2/ */
  tSpeed_Defs VehiculeSpeed,
  outC_CruiseRegulation_CruiseControl *outC)
{
  /* @2/G_Input/, @2/_L1/, _L3/ */
  kcg_float64 _L3;

  _L3 = CruiseSpeed - VehiculeSpeed;
  /* _L16= */
  if (outC->_L14) {
    outC->_L10 = ZeroSpeed_Defs + outC->_L10;
  }
  else {
    outC->_L10 = _L3 + outC->_L10;
  }
  /* _L13=(CruiseControl::SaturateThrottle#1)/ */
  SaturateThrottle_CruiseControl(
    _L3 * Kp_Defs + outC->_L10 * Ki_Defs,
    &outC->Throttle,
    &outC->_L14);
}

#ifndef KCG_USER_DEFINED_INIT
void CruiseRegulation_init_CruiseControl(
  outC_CruiseRegulation_CruiseControl *outC)
{
  outC->_L14 = kcg_true;
  outC->Throttle = kcg_lit_float64(0.0);
  outC->_L10 = ZeroSpeed_Defs;
}
#endif /* KCG_USER_DEFINED_INIT */


void CruiseRegulation_reset_CruiseControl(
  outC_CruiseRegulation_CruiseControl *outC)
{
  outC->_L14 = kcg_true;
  outC->_L10 = ZeroSpeed_Defs;
}

/*
  Expanded instances for: CruiseControl::CruiseRegulation/
  @2: (linear::Gain#1)
*/

/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** CruiseRegulation_CruiseControl.c
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

