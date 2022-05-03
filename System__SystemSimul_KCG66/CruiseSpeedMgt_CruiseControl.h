/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Command: kcg662.exe -config C:/Users/missael/Documents/CINVESTAV/embedded critical software/Project/CC-003/System__SystemSimul_KCG66/config.txt
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */
#ifndef _CruiseSpeedMgt_CruiseControl_H_
#define _CruiseSpeedMgt_CruiseControl_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  tSpeed_Defs /* @1/LUS_Output/, @1/_L9/, CruiseSpeed/, _L42/ */ CruiseSpeed;
  /* -----------------------  no local probes  ----------------------- */
  /* ----------------------- local memories  ------------------------- */
  kcg_bool init;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_CruiseSpeedMgt_CruiseControl;

/* ===========  node initialization and cycle functions  =========== */
/* CruiseControl::CruiseSpeedMgt/ */
extern void CruiseSpeedMgt_CruiseControl(
  /* IfBlock1:, Set/ */
  kcg_bool Set,
  /* QuickAccel/ */
  kcg_bool QuickAccel,
  /* QuickDecel/ */
  kcg_bool QuickDecel,
  /* Speed/ */
  tSpeed_CarType Speed,
  outC_CruiseSpeedMgt_CruiseControl *outC);

extern void CruiseSpeedMgt_reset_CruiseControl(
  outC_CruiseSpeedMgt_CruiseControl *outC);

#ifndef KCG_USER_DEFINED_INIT
extern void CruiseSpeedMgt_init_CruiseControl(
  outC_CruiseSpeedMgt_CruiseControl *outC);
#endif /* KCG_USER_DEFINED_INIT */

/*
  Expanded instances for: CruiseControl::CruiseSpeedMgt/
  @1: (pwlinear::LimiterUnSymmetrical#1)
*/

#endif /* _CruiseSpeedMgt_CruiseControl_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** CruiseSpeedMgt_CruiseControl.h
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

