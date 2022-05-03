/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Command: kcg662.exe -config C:/Users/missael/Documents/CINVESTAV/embedded critical software/Project/CC-003/System__SystemSimul_KCG66/config.txt
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "SaturateThrottle_CruiseControl.h"

/* CruiseControl::SaturateThrottle/ */
void SaturateThrottle_CruiseControl(
  /* ThrottleIn/, _L12/ */
  tPercent_Defs ThrottleIn,
  /* ThrottleOut/, _L8/ */
  tPercent_Defs *ThrottleOut,
  /* Saturate/, _L13/ */
  kcg_bool *Saturate)
{
  /* _L9/ */
  kcg_bool _L9;
  /* _L7/ */
  kcg_bool _L7;

  _L9 = ThrottleIn < ZeroPercent_Defs;
  _L7 = ThrottleIn > RegulThrottleMax_Defs;
  *Saturate = _L7 | _L9;
  /* _L8= */
  if (_L7) {
    *ThrottleOut = RegulThrottleMax_Defs;
  }
  else /* _L6= */
  if (_L9) {
    *ThrottleOut = ZeroPercent_Defs;
  }
  else {
    *ThrottleOut = ThrottleIn;
  }
}



/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** SaturateThrottle_CruiseControl.c
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

