/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Command: kcg662.exe -config C:/Users/missael/Documents/CINVESTAV/embedded critical software/Project/CC-003/System__SystemSimul_KCG66/config.txt
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "PowerTrainStatic_Car.h"

/* Car::PowerTrainStatic/ */
tTorq_CarType PowerTrainStatic_Car(
  /* Throttle/, _L7/ */
  tSpeed_CarType Throttle)
{
  kcg_float64 tmp;
  /* _L12/ */
  kcg_float64 _L12;
  /* Torq/, _L14/ */
  tTorq_CarType Torq;

  /* _L30= */
  if (Throttle < kcg_lit_float64(0.0)) {
    tmp = kcg_lit_float64(0.0);
  }
  else /* _L29= */
  if (Throttle > kcg_lit_float64(100.0)) {
    tmp = kcg_lit_float64(100.0);
  }
  else {
    tmp = Throttle;
  }
  _L12 = kcg_lit_float64(1.0) - /* _L11=(mathext::ExpR#8)/ */
    ExpR64_mathext_mathextimpl(tmp * Tengine_Car);
  Torq = _L12 * _L12 * (TorqMax_Car / Iengine_Car);
  return Torq;
}



/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** PowerTrainStatic_Car.c
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

