/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Command: kcg662.exe -config C:/Users/missael/Documents/CINVESTAV/embedded critical software/Project/CC-003/System__SystemSimul_KCG66/config.txt
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */
#ifndef _SaturateThrottle_CruiseControl_H_
#define _SaturateThrottle_CruiseControl_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* CruiseControl::SaturateThrottle/ */
extern void SaturateThrottle_CruiseControl(
  /* ThrottleIn/, _L12/ */
  tPercent_Defs ThrottleIn,
  /* ThrottleOut/, _L8/ */
  tPercent_Defs *ThrottleOut,
  /* Saturate/, _L13/ */
  kcg_bool *Saturate);



#endif /* _SaturateThrottle_CruiseControl_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** SaturateThrottle_CruiseControl.h
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

