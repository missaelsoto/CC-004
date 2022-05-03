#include "CC-003_interface.h"
#include "CC-003_type.h"
#include "CC-003_mapping.h"
#include "TEEProxy.h"
#include "te_image_lib.h"

#define UNUSED(x) (void)(x)
/* context */

kcg_bool On;
kcg_bool Off;
kcg_bool SteeringWheel;
kcg_float64 Time;
tPercent_CarType Brake;
outC_AutonomousEmergencyBrake_AutonomousEmergencyBrake outputs_ctx;

static void _SCSIM_RestoreInterface(void) {
    init_kcg_bool(&On);
    init_kcg_bool(&Off);
    init_kcg_bool(&SteeringWheel);
    init_kcg_float64(&Time);
    init_tPercent_CarType(&Brake);
}

static void _SCSIM_ExecuteInterface(void) {
}

#ifdef __cplusplus
extern "C" {
#endif

/* simulation */

int SimInit(void) {
    _SCSIM_RestoreInterface();
#ifndef KCG_USER_DEFINED_INIT
    AutonomousEmergencyBrake_init_AutonomousEmergencyBrake(&outputs_ctx);
    return 1;
#else
    return 0;
#endif
}

int SimReset(void) {
    _SCSIM_RestoreInterface();
#ifndef KCG_NO_EXTERN_CALL_TO_RESET
    AutonomousEmergencyBrake_reset_AutonomousEmergencyBrake(&outputs_ctx);
    return 1;
#else
    return 0;
#endif
}

int SimStep(void) {
    _SCSIM_ExecuteInterface();
    AutonomousEmergencyBrake_AutonomousEmergencyBrake(On, Off, SteeringWheel, Time, Brake, &outputs_ctx);
    return 1;
}

int SimStop(void) {
    return 1;
}

/* snapshot */

int SsmSaveSnapshot(const char * szFilePath, size_t nCycle) {
    /* Test Services API not available */
    UNUSED(szFilePath);
    UNUSED(nCycle);
    return 0;
}

int SsmLoadSnapshot(const char * szFilePath, size_t *nCycle) {
    /* Test Services API not available */
    UNUSED(szFilePath);
    UNUSED(nCycle);
    return 0;
}

/* check expressions */

void SsmEnableExprCheck(size_t idx, unsigned char on) {
    /* No test context (no scenario with expression check) */
    UNUSED(idx);
    UNUSED(on);
}

unsigned char SsmGetExprCheckResult(size_t idx) {
    /* No test context (no scenario with expression check) */
    UNUSED(idx);
    return 0;
}

unsigned char SsmGetExprCheckNBW(size_t idx) {
    /* No test context (no scenario with expression check) */
    UNUSED(idx);
    return 0;
}


/* check images */

void SsmSetHideDisplay(unsigned char on) {
    /* No hide_display flag (Display only) */
    UNUSED(on);
}

void SsmEnableImageCheck(unsigned char on) {
    /* No image check (Display only) */
    UNUSED(on);
}

TeImage* SsmGetImageBuffer() {
    /* No image buffer (Display only) */
    return 0;
}


/* coverage */

void SsmEnableCov(unsigned char on)
{
    UNUSED(on);
}

void SsmResetCovData()
{
}

SimErrCode SsmReadCovFile(const char* pszFilePath)
{
    UNUSED(pszFilePath);
}

SimErrCode SsmWriteCovFile(const char* pszFilePath, const char* pszTestInfo, size_t nTestInfoSize)
{
    UNUSED(pszFilePath);
    UNUSED(pszTestInfo);
    UNUSED(nTestInfoSize);
}

#ifdef __cplusplus
} /* "C" */
#endif

