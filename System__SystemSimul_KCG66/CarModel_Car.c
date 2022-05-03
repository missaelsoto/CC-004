/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Command: kcg662.exe -config C:/Users/missael/Documents/CINVESTAV/embedded critical software/Project/CC-003/System__SystemSimul_KCG66/config.txt
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "CarModel_Car.h"

/* Car::CarModel/ */
void CarModel_Car(
  /* Throttle/, _L54/ */
  tPercent_CarType Throttle,
  /* Brake/, _L2/ */
  tPercent_CarType Brake,
  outC_CarModel_Car *outC)
{
  /* _L55=(Car::Body#0)/ */
  Body_Car(
    /* _L53=(Car::PowerTrainStatic#1)/ */ PowerTrainStatic_Car(Throttle),
    Brake,
    &outC->Context_Body_0);
  outC->VehicleSpeed = outC->Context_Body_0.VehicleSpeed;
}

#ifndef KCG_USER_DEFINED_INIT
void CarModel_init_Car(outC_CarModel_Car *outC)
{
  outC->VehicleSpeed = kcg_lit_float64(0.0);
  /* _L55=(Car::Body#0)/ */ Body_init_Car(&outC->Context_Body_0);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void CarModel_reset_Car(outC_CarModel_Car *outC)
{
  /* _L55=(Car::Body#0)/ */ Body_reset_Car(&outC->Context_Body_0);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** CarModel_Car.c
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

