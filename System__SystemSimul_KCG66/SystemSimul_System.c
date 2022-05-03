/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Command: kcg662.exe -config C:/Users/missael/Documents/CINVESTAV/embedded critical software/Project/CC-003/System__SystemSimul_KCG66/config.txt
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "SystemSimul_System.h"

/* System::SystemSimul/ */
void SystemSimul_System(
  inC_SystemSimul_System *inC,
  outC_SystemSimul_System *outC)
{
  /* _L26=(CruiseControl::CruiseControl#1)/ */
  CruiseControl_CruiseControl(
    inC->On,
    inC->Off,
    inC->Resume,
    inC->Set,
    inC->QuickAccel,
    inC->QuickDecel,
    inC->Accel,
    inC->Brake,
    outC->_L19,
    &outC->Context_CruiseControl_1);
  outC->CruiseSpeed = outC->Context_CruiseControl_1.CruiseSpeed;
  outC->CruiseState = outC->Context_CruiseControl_1.CruiseState;
  /* _L33=(AutonomousEmergencyBrake::AutonomousEmergencyBrake#1)/ */
  AutonomousEmergencyBrake_AutonomousEmergencyBrake(
    inC->OnEmergencyBrake,
    inC->OffEmergencyBrake,
    inC->SterringWheel,
    inC->Time,
    inC->Brake,
    &outC->Context_AutonomousEmergencyBrake_1);
  /* _L12=(Car::CarModel#1)/ */
  CarModel_Car(
    outC->Context_CruiseControl_1.ThrottleCmd,
    outC->Context_AutonomousEmergencyBrake_1.BrakePercent + inC->Brake,
    &outC->Context_CarModel_1);
  outC->CarSpeed = outC->Context_CarModel_1.VehicleSpeed;
  outC->_L19 = outC->Context_CarModel_1.VehicleSpeed;
}

#ifndef KCG_USER_DEFINED_INIT
void SystemSimul_init_System(outC_SystemSimul_System *outC)
{
  outC->CarSpeed = kcg_lit_float64(0.0);
  outC->CruiseState = OFF_Defs;
  outC->CruiseSpeed = kcg_lit_float64(0.0);
  /* _L12=(Car::CarModel#1)/ */ CarModel_init_Car(&outC->Context_CarModel_1);
  /* _L33=(AutonomousEmergencyBrake::AutonomousEmergencyBrake#1)/ */
  AutonomousEmergencyBrake_init_AutonomousEmergencyBrake(
    &outC->Context_AutonomousEmergencyBrake_1);
  /* _L26=(CruiseControl::CruiseControl#1)/ */
  CruiseControl_init_CruiseControl(&outC->Context_CruiseControl_1);
  outC->_L19 = ZeroSpeed_Defs;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void SystemSimul_reset_System(outC_SystemSimul_System *outC)
{
  /* _L12=(Car::CarModel#1)/ */ CarModel_reset_Car(&outC->Context_CarModel_1);
  /* _L33=(AutonomousEmergencyBrake::AutonomousEmergencyBrake#1)/ */
  AutonomousEmergencyBrake_reset_AutonomousEmergencyBrake(
    &outC->Context_AutonomousEmergencyBrake_1);
  /* _L26=(CruiseControl::CruiseControl#1)/ */
  CruiseControl_reset_CruiseControl(&outC->Context_CruiseControl_1);
  outC->_L19 = ZeroSpeed_Defs;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** SystemSimul_System.c
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

