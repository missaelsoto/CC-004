/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Command: kcg662.exe -config C:/Users/missael/Documents/CINVESTAV/embedded critical software/Project/CC-003/System__SystemSimul_KCG66/config.txt
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */
#ifndef _Body_Car_H_
#define _Body_Car_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  tSpeed_CarType /* VehicleSpeed/, _L18/ */ VehicleSpeed;
  /* -----------------------  no local probes  ----------------------- */
  /* ----------------------- local memories  ------------------------- */
  kcg_bool init;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_Body_Car;

/* ===========  node initialization and cycle functions  =========== */
/* Car::Body/ */
extern void Body_Car(
  /* Torq/, _L26/ */
  tTorq_CarType Torq,
  /* Brake/, _L2/ */
  tSpeed_CarType Brake,
  outC_Body_Car *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void Body_reset_Car(outC_Body_Car *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void Body_init_Car(outC_Body_Car *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _Body_Car_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Body_Car.h
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

