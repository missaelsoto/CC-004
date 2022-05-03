/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Command: kcg662.exe -config C:/Users/missael/Documents/CINVESTAV/embedded critical software/Project/CC-003/System__SystemSimul_KCG66/config.txt
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */
#ifndef _CarModel_Car_H_
#define _CarModel_Car_H_

#include "kcg_types.h"
#include "PowerTrainStatic_Car.h"
#include "Body_Car.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  tSpeed_CarType /* VehicleSpeed/, _L55/ */ VehicleSpeed;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_Body_Car /* _L55=(Car::Body#0)/ */ Context_Body_0;
  /* ----------------- no clocks of observable data ------------------ */
} outC_CarModel_Car;

/* ===========  node initialization and cycle functions  =========== */
/* Car::CarModel/ */
extern void CarModel_Car(
  /* Throttle/, _L54/ */
  tPercent_CarType Throttle,
  /* Brake/, _L2/ */
  tPercent_CarType Brake,
  outC_CarModel_Car *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void CarModel_reset_Car(outC_CarModel_Car *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void CarModel_init_Car(outC_CarModel_Car *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _CarModel_Car_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** CarModel_Car.h
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

