/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Command: kcg662.exe -config C:/Users/missael/Documents/CINVESTAV/embedded critical software/Project/CC-003/System__SystemSimul_KCG66/config.txt
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */
#ifndef _CruiseRegulation_CruiseControl_H_
#define _CruiseRegulation_CruiseControl_H_

#include "kcg_types.h"
#include "SaturateThrottle_CruiseControl.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  tPercent_Defs /* Throttle/, _L13/ */ Throttle;
  /* -----------------------  no local probes  ----------------------- */
  /* ----------------------- local memories  ------------------------- */
  kcg_float64 /* @1/G_Input/, @1/_L1/, _L10/ */ _L10;
  kcg_bool /* _L14/ */ _L14;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_CruiseRegulation_CruiseControl;

/* ===========  node initialization and cycle functions  =========== */
/* CruiseControl::CruiseRegulation/ */
extern void CruiseRegulation_CruiseControl(
  /* CruiseSpeed/, _L1/ */
  tSpeed_Defs CruiseSpeed,
  /* VehiculeSpeed/, _L2/ */
  tSpeed_Defs VehiculeSpeed,
  outC_CruiseRegulation_CruiseControl *outC);

extern void CruiseRegulation_reset_CruiseControl(
  outC_CruiseRegulation_CruiseControl *outC);

#ifndef KCG_USER_DEFINED_INIT
extern void CruiseRegulation_init_CruiseControl(
  outC_CruiseRegulation_CruiseControl *outC);
#endif /* KCG_USER_DEFINED_INIT */

/*
  Expanded instances for: CruiseControl::CruiseRegulation/
  @1: (linear::Gain#2)
*/

#endif /* _CruiseRegulation_CruiseControl_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** CruiseRegulation_CruiseControl.h
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

