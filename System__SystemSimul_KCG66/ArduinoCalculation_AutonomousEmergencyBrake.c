/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Command: kcg662.exe -config C:/Users/missael/Documents/CINVESTAV/embedded critical software/Project/CC-003/System__SystemSimul_KCG66/config.txt
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ArduinoCalculation_AutonomousEmergencyBrake.h"

/* AutonomousEmergencyBrake::ArduinoCalculation/ */
kcg_float64 ArduinoCalculation_AutonomousEmergencyBrake(
  /* Time/, _L1/ */
  kcg_float64 Time)
{
  /* Long/, _L2/ */
  kcg_float64 Long;

  Long = Time / SensorConst_Defs;
  return Long;
}



/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** ArduinoCalculation_AutonomousEmergencyBrake.c
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

