/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Command: kcg662.exe -config C:/Users/missael/Documents/CINVESTAV/embedded critical software/Project/CC-003/System__SystemSimul_KCG66/config.txt
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */
#ifndef _CruiseControl_CruiseControl_H_
#define _CruiseControl_CruiseControl_H_

#include "kcg_types.h"
#include "CruiseSpeedMgt_CruiseControl.h"
#include "CruiseRegulation_CruiseControl.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  tSpeed_Defs /* CruiseSpeed/ */ CruiseSpeed;
  tPercent_CarType /* ThrottleCmd/ */ ThrottleCmd;
  tCruiseState_Defs /* CruiseState/ */ CruiseState;
  /* -----------------------  no local probes  ----------------------- */
  /* ----------------------- local memories  ------------------------- */
  kcg_bool init;
  kcg_bool init1;
  _2_SSM_ST_SM2_Enabled_SM1 /* SM1:Enabled:SM2: */ SM2_state_nxt_Enabled_SM1;
  SSM_ST_SM3_Active_SM2_Enabled_SM1 /* SM1:Enabled:SM2:Active:SM3: */ SM3_state_nxt_Active_SM2_Enabled_SM1;
  _4_SSM_ST_SM1 /* SM1: */ SM1_state_nxt;
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_CruiseRegulation_CruiseControl /* SM1:Enabled:SM2:Active:SM3:On:_L13=(CruiseControl::CruiseRegulation#3)/ */ Context_CruiseRegulation_3;
  outC_CruiseSpeedMgt_CruiseControl /* SM1:Enabled:_L8=(CruiseControl::CruiseSpeedMgt#1)/ */ Context_CruiseSpeedMgt_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_CruiseControl_CruiseControl;

/* ===========  node initialization and cycle functions  =========== */
/* CruiseControl::CruiseControl/ */
extern void CruiseControl_CruiseControl(
  /* On/ */
  kcg_bool On,
  /* Off/ */
  kcg_bool Off,
  /* Resume/ */
  kcg_bool Resume,
  /* Set/ */
  kcg_bool Set,
  /* QuickAccel/ */
  kcg_bool QuickAccel,
  /* QuickDecel/ */
  kcg_bool QuickDecel,
  /* Accel/ */
  tPercent_CarType Accel,
  /* Brake/ */
  tPercent_CarType Brake,
  /* Speed/ */
  tSpeed_CarType Speed,
  outC_CruiseControl_CruiseControl *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void CruiseControl_reset_CruiseControl(
  outC_CruiseControl_CruiseControl *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void CruiseControl_init_CruiseControl(
  outC_CruiseControl_CruiseControl *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _CruiseControl_CruiseControl_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** CruiseControl_CruiseControl.h
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

