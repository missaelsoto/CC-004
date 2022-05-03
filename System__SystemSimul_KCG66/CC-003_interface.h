#ifndef CC_003_INTERFACE_H_
#define CC_003_INTERFACE_H_

#include "kcg_sensors.h"
#include "AutonomousEmergencyBrake_AutonomousEmergencyBrake.h"

/* context */

extern kcg_bool On;
extern kcg_bool Off;
extern kcg_bool SteeringWheel;
extern kcg_float64 Time;
extern tPercent_CarType Brake;
extern outC_AutonomousEmergencyBrake_AutonomousEmergencyBrake outputs_ctx;

#ifdef __cplusplus
extern "C" {
#endif

/* simulation */

int SimInit(void);
int SimReset(void);
int SimStep(void);
int SimStop(void);

#ifdef __cplusplus
} /* "C" */
#endif

#endif /* CC_003_INTERFACE_H_ */
