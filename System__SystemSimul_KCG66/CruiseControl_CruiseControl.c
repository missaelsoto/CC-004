/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Command: kcg662.exe -config C:/Users/missael/Documents/CINVESTAV/embedded critical software/Project/CC-003/System__SystemSimul_KCG66/config.txt
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "CruiseControl_CruiseControl.h"

/* CruiseControl::CruiseControl/ */
void CruiseControl_CruiseControl(
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
  outC_CruiseControl_CruiseControl *outC)
{
  /* SM1:Enabled:SM2: */
  kcg_bool SM2_reset_act_Enabled_SM1;
  /* SM1:Enabled:SM2: */
  _2_SSM_ST_SM2_Enabled_SM1 SM2_state_sel_Enabled_SM1;
  /* SM1:Enabled:SM2: */
  _2_SSM_ST_SM2_Enabled_SM1 SM2_clock_Enabled_SM1;
  /* SM1:Enabled:SM2:Active:SM3: */
  SSM_ST_SM3_Active_SM2_Enabled_SM1 SM3_state_sel_Active_SM2_Enabled_SM1;
  /* SM1:Enabled:SM2:Active:SM3: */
  SSM_ST_SM3_Active_SM2_Enabled_SM1 SM3_state_act_Active_SM2_Enabled_SM1;
  /* SM1:Enabled:SM2:Active:SM3: */
  kcg_bool SM3_reset_act_Active_SM2_Enabled_SM1;
  /* SM1:Enabled:SM2:Active:StdbyCondition/, SM1:Enabled:SM2:Active:_L2/ */
  kcg_bool StdbyCondition_Active_SM2_Enabled_SM1;
  /* SM1: */
  _4_SSM_ST_SM1 SM1_state_act;
  /* SM1: */
  kcg_bool SM1_reset_act;

  /* SM1: */
  switch (outC->SM1_state_nxt) {
    case SSM_st_Enabled_SM1 :
      if (Off) {
        SM1_state_act = SSM_st_Off_SM1;
      }
      else {
        SM1_state_act = SSM_st_Enabled_SM1;
      }
      SM1_reset_act = Off;
      break;
    case SSM_st_Off_SM1 :
      if (On) {
        SM1_state_act = SSM_st_Enabled_SM1;
      }
      else {
        SM1_state_act = SSM_st_Off_SM1;
      }
      SM1_reset_act = On;
      break;
    default :
      /* this default branch is unreachable */
      break;
  }
  /* SM1: */
  switch (SM1_state_act) {
    case SSM_st_Enabled_SM1 :
      if (SM1_reset_act) {
        outC->init = kcg_true;
      }
      /* SM1:Enabled:SM2: */
      if (outC->init) {
        outC->init = kcg_false;
        SM2_state_sel_Enabled_SM1 = SSM_st_Active_SM2_Enabled_SM1;
      }
      else {
        SM2_state_sel_Enabled_SM1 = outC->SM2_state_nxt_Enabled_SM1;
      }
      /* SM1:Enabled:SM2: */
      switch (SM2_state_sel_Enabled_SM1) {
        case SSM_st_Interrupt_SM2_Enabled_SM1 :
          if (Resume) {
            SM2_clock_Enabled_SM1 = SSM_st_Active_SM2_Enabled_SM1;
          }
          else {
            SM2_clock_Enabled_SM1 = SSM_st_Interrupt_SM2_Enabled_SM1;
          }
          SM2_reset_act_Enabled_SM1 = Resume;
          break;
        case SSM_st_Active_SM2_Enabled_SM1 :
          SM2_reset_act_Enabled_SM1 = Brake > PedalsMin_Defs;
          if (SM2_reset_act_Enabled_SM1) {
            SM2_clock_Enabled_SM1 = SSM_st_Interrupt_SM2_Enabled_SM1;
          }
          else {
            SM2_clock_Enabled_SM1 = SSM_st_Active_SM2_Enabled_SM1;
          }
          break;
        default :
          /* this default branch is unreachable */
          break;
      }
      switch (SM2_clock_Enabled_SM1) {
        case SSM_st_Active_SM2_Enabled_SM1 :
          if (SM2_reset_act_Enabled_SM1) {
            outC->init1 = kcg_true;
          }
          break;
        default :
          /* this branch is empty */
          break;
      }
      if (SM1_reset_act) {
        outC->init1 = kcg_true;
        /* SM1:Enabled:_L8=(CruiseControl::CruiseSpeedMgt#1)/ */
        CruiseSpeedMgt_reset_CruiseControl(&outC->Context_CruiseSpeedMgt_1);
      }
      /* SM1:Enabled:_L8=(CruiseControl::CruiseSpeedMgt#1)/ */
      CruiseSpeedMgt_CruiseControl(
        Set,
        QuickAccel,
        QuickDecel,
        Speed,
        &outC->Context_CruiseSpeedMgt_1);
      outC->CruiseSpeed = outC->Context_CruiseSpeedMgt_1.CruiseSpeed;
      /* SM1:Enabled:SM2: */
      switch (SM2_clock_Enabled_SM1) {
        case SSM_st_Interrupt_SM2_Enabled_SM1 :
          outC->SM2_state_nxt_Enabled_SM1 = SSM_st_Interrupt_SM2_Enabled_SM1;
          break;
        case SSM_st_Active_SM2_Enabled_SM1 :
          StdbyCondition_Active_SM2_Enabled_SM1 = (Accel > PedalsMin_Defs) |
            (Speed < SpeedMin_Defs) | (Speed > SpeedMax_Defs);
          /* SM1:Enabled:SM2:Active:SM3: */
          if (outC->init1) {
            SM3_state_sel_Active_SM2_Enabled_SM1 = SSM_st_On_SM3_Active_SM2_Enabled_SM1;
          }
          else {
            SM3_state_sel_Active_SM2_Enabled_SM1 =
              outC->SM3_state_nxt_Active_SM2_Enabled_SM1;
          }
          /* SM1:Enabled:SM2:Active:SM3: */
          switch (SM3_state_sel_Active_SM2_Enabled_SM1) {
            case SSM_st_StandBy_SM3_Active_SM2_Enabled_SM1 :
              SM3_reset_act_Active_SM2_Enabled_SM1 = !StdbyCondition_Active_SM2_Enabled_SM1;
              if (SM3_reset_act_Active_SM2_Enabled_SM1) {
                SM3_state_act_Active_SM2_Enabled_SM1 = SSM_st_On_SM3_Active_SM2_Enabled_SM1;
              }
              else {
                SM3_state_act_Active_SM2_Enabled_SM1 =
                  SSM_st_StandBy_SM3_Active_SM2_Enabled_SM1;
              }
              break;
            case SSM_st_On_SM3_Active_SM2_Enabled_SM1 :
              if (StdbyCondition_Active_SM2_Enabled_SM1) {
                SM3_state_act_Active_SM2_Enabled_SM1 =
                  SSM_st_StandBy_SM3_Active_SM2_Enabled_SM1;
              }
              else {
                SM3_state_act_Active_SM2_Enabled_SM1 = SSM_st_On_SM3_Active_SM2_Enabled_SM1;
              }
              SM3_reset_act_Active_SM2_Enabled_SM1 = StdbyCondition_Active_SM2_Enabled_SM1;
              break;
            default :
              /* this default branch is unreachable */
              break;
          }
          outC->SM2_state_nxt_Enabled_SM1 = SSM_st_Active_SM2_Enabled_SM1;
          /* SM1:Enabled:SM2:Active:SM3: */
          switch (SM3_state_act_Active_SM2_Enabled_SM1) {
            case SSM_st_StandBy_SM3_Active_SM2_Enabled_SM1 :
              outC->SM3_state_nxt_Active_SM2_Enabled_SM1 =
                SSM_st_StandBy_SM3_Active_SM2_Enabled_SM1;
              break;
            case SSM_st_On_SM3_Active_SM2_Enabled_SM1 :
              outC->SM3_state_nxt_Active_SM2_Enabled_SM1 =
                SSM_st_On_SM3_Active_SM2_Enabled_SM1;
              if (SM3_reset_act_Active_SM2_Enabled_SM1) {
                /* SM1:Enabled:SM2:Active:SM3:On:_L13=(CruiseControl::CruiseRegulation#3)/ */
                CruiseRegulation_reset_CruiseControl(
                  &outC->Context_CruiseRegulation_3);
              }
              break;
            default :
              /* this default branch is unreachable */
              break;
          }
          if (SM2_reset_act_Enabled_SM1) {
            /* SM1:Enabled:SM2:Active:SM3:On:_L13=(CruiseControl::CruiseRegulation#3)/ */
            CruiseRegulation_reset_CruiseControl(
              &outC->Context_CruiseRegulation_3);
          }
          break;
        default :
          /* this default branch is unreachable */
          break;
      }
      if (SM1_reset_act) {
        /* SM1:Enabled:SM2:Active:SM3:On:_L13=(CruiseControl::CruiseRegulation#3)/ */
        CruiseRegulation_reset_CruiseControl(&outC->Context_CruiseRegulation_3);
      }
      outC->SM1_state_nxt = SSM_st_Enabled_SM1;
      /* SM1:Enabled:SM2: */
      switch (SM2_clock_Enabled_SM1) {
        case SSM_st_Interrupt_SM2_Enabled_SM1 :
          outC->ThrottleCmd = Accel;
          outC->CruiseState = INT_Defs;
          break;
        case SSM_st_Active_SM2_Enabled_SM1 :
          /* SM1:Enabled:SM2:Active:SM3: */
          switch (SM3_state_act_Active_SM2_Enabled_SM1) {
            case SSM_st_StandBy_SM3_Active_SM2_Enabled_SM1 :
              outC->ThrottleCmd = Accel;
              outC->CruiseState = STDBY_Defs;
              break;
            case SSM_st_On_SM3_Active_SM2_Enabled_SM1 :
              /* SM1:Enabled:SM2:Active:SM3:On:_L13=(CruiseControl::CruiseRegulation#3)/ */
              CruiseRegulation_CruiseControl(
                outC->Context_CruiseSpeedMgt_1.CruiseSpeed,
                Speed,
                &outC->Context_CruiseRegulation_3);
              outC->ThrottleCmd = outC->Context_CruiseRegulation_3.Throttle;
              outC->CruiseState = ON_Defs;
              break;
            default :
              /* this default branch is unreachable */
              break;
          }
          outC->init1 = kcg_false;
          break;
        default :
          /* this default branch is unreachable */
          break;
      }
      break;
    case SSM_st_Off_SM1 :
      outC->CruiseSpeed = ZeroSpeed_Defs;
      outC->ThrottleCmd = Accel;
      outC->CruiseState = OFF_Defs;
      outC->SM1_state_nxt = SSM_st_Off_SM1;
      break;
    default :
      /* this default branch is unreachable */
      break;
  }
}

#ifndef KCG_USER_DEFINED_INIT
void CruiseControl_init_CruiseControl(outC_CruiseControl_CruiseControl *outC)
{
  outC->init = kcg_true;
  outC->init1 = kcg_true;
  outC->SM3_state_nxt_Active_SM2_Enabled_SM1 =
    SSM_st_On_SM3_Active_SM2_Enabled_SM1;
  outC->SM2_state_nxt_Enabled_SM1 = SSM_st_Active_SM2_Enabled_SM1;
  outC->CruiseState = OFF_Defs;
  outC->ThrottleCmd = kcg_lit_float64(0.0);
  outC->CruiseSpeed = kcg_lit_float64(0.0);
  /* SM1:Enabled:SM2:Active:SM3:On:_L13=(CruiseControl::CruiseRegulation#3)/ */
  CruiseRegulation_init_CruiseControl(&outC->Context_CruiseRegulation_3);
  /* SM1:Enabled:_L8=(CruiseControl::CruiseSpeedMgt#1)/ */
  CruiseSpeedMgt_init_CruiseControl(&outC->Context_CruiseSpeedMgt_1);
  outC->SM1_state_nxt = SSM_st_Off_SM1;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void CruiseControl_reset_CruiseControl(outC_CruiseControl_CruiseControl *outC)
{
  outC->init = kcg_true;
  outC->init1 = kcg_true;
  /* SM1:Enabled:SM2:Active:SM3:On:_L13=(CruiseControl::CruiseRegulation#3)/ */
  CruiseRegulation_reset_CruiseControl(&outC->Context_CruiseRegulation_3);
  /* SM1:Enabled:_L8=(CruiseControl::CruiseSpeedMgt#1)/ */
  CruiseSpeedMgt_reset_CruiseControl(&outC->Context_CruiseSpeedMgt_1);
  outC->SM1_state_nxt = SSM_st_Off_SM1;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** CruiseControl_CruiseControl.c
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

