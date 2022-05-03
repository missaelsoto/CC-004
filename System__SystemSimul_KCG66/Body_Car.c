/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Command: kcg662.exe -config C:/Users/missael/Documents/CINVESTAV/embedded critical software/Project/CC-003/System__SystemSimul_KCG66/config.txt
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Body_Car.h"

/* Car::Body/ */
void Body_Car(
  /* Torq/, _L26/ */
  tTorq_CarType Torq,
  /* Brake/, _L2/ */
  tSpeed_CarType Brake,
  outC_Body_Car *outC)
{
  kcg_float64 tmp;
  /* _L19/ */
  kcg_float64 _L19;
  /* _L11/ */
  kcg_float64 _L11;

  /* _L19= */
  if (outC->init) {
    outC->init = kcg_false;
    _L19 = kcg_lit_float64(0.0);
  }
  else {
    _L19 = outC->VehicleSpeed;
  }
  /* _L40= */
  if (Torq <= kcg_lit_float64(1.0)) {
    tmp = kcg_lit_float64(150.0);
  }
  else {
    tmp = kcg_lit_float64(0.0);
  }
  _L11 = tmp + Brake * KBRAKE_Car + _L19 * _L19 * kcg_lit_float64(0.3) + _L19 *
    kcg_lit_float64(2.5);
  /* _L34= */
  if (_L19 < kcg_lit_float64(-0.1)) {
    tmp = - _L11;
  }
  else /* _L30= */
  if (_L19 > kcg_lit_float64(0.1)) {
    tmp = _L11;
  }
  else {
    tmp = kcg_lit_float64(0.0);
  }
  outC->VehicleSpeed = (Torq - tmp) * TCYCLE_Car * VehicleDynamic_Car /
    MASS_Car + _L19;
}

#ifndef KCG_USER_DEFINED_INIT
void Body_init_Car(outC_Body_Car *outC)
{
  outC->init = kcg_true;
  outC->VehicleSpeed = kcg_lit_float64(0.0);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Body_reset_Car(outC_Body_Car *outC)
{
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Body_Car.c
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

