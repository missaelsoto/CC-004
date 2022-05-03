#include "CC-003_type.h"

#include "SmuTypes.h"
#include "SmuPredefConv.h"
#include "SmuVTable.h"

#include "kcg_types.h"

#include "SmuConfig.h"

char strDefaultRealFormat[] = "%.5g"; /* (from .etp) */
#define UNUSED(x) (void)(x)
#define skip_whitespace(str) while(*str == ' ' || *str == '\t') str++

/****************************************************************
 ** Constants 
 ****************************************************************/

#include "kcg_consts.h"

static tSpeed_Defs const TU_ZeroSpeed_Defs = ZeroSpeed_Defs;
static tPercent_Defs const TU_ZeroPercent_Defs = ZeroPercent_Defs;
static tSpeed_Defs const TU_SpeedMin_Defs = SpeedMin_Defs;
static tSpeed_Defs const TU_SpeedMax_Defs = SpeedMax_Defs;
static tSpeed_Defs const TU_SpeedInc_Defs = SpeedInc_Defs;
static tPercent_Defs const TU_RegulThrottleMax_Defs = RegulThrottleMax_Defs;
static tPercent_Defs const TU_PedalsMin_Defs = PedalsMin_Defs;
static kcg_float64 const TU_Kp_Defs = Kp_Defs;
static kcg_float64 const TU_Ki_Defs = Ki_Defs;
static kcg_float64 const TU_SensorConst_Defs = SensorConst_Defs;
static tPercent_CarType const TU_BrakeConst_Defs = BrakeConst_Defs;
static tPercent_CarType const TU_SecondBrakeConst_Defs = SecondBrakeConst_Defs;
static kcg_float64 const TU_Iengine_Car = Iengine_Car;
static kcg_float64 const TU_KBRAKE_Car = KBRAKE_Car;
#define TU_KTRANSM_Car KTRANSM_Car
static kcg_float64 const TU_MASS_Car = MASS_Car;
static kcg_float64 const TU_TCYCLE_Car = TCYCLE_Car;
static kcg_float64 const TU_Tengine_Car = Tengine_Car;
static kcg_float64 const TU_TorqMax_Car = TorqMax_Car;
static kcg_float64 const TU_VehicleDynamic_Car = VehicleDynamic_Car;

/****************************************************************
 ** _2_SSM_ST_SM2_Enabled_SM1 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSim_2_SSM_ST_SM2_Enabled_SM1VTable_defined
    extern struct SimTypeVTable *pSim_2_SSM_ST_SM2_Enabled_SM1VTable;
  #else 
    struct SimTypeVTable *pSim_2_SSM_ST_SM2_Enabled_SM1VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSim_2_SSM_ST_SM2_Enabled_SM1VTable;
#endif

static SimEnumValUtils _2_SSM_ST_SM2_Enabled_SM1_values[] = {
    { "Active", SSM_st_Active_SM2_Enabled_SM1},
    { "Interrupt", SSM_st_Interrupt_SM2_Enabled_SM1},
};
const int _2_SSM_ST_SM2_Enabled_SM1_nb_values = 2;

int _2_SSM_ST_SM2_Enabled_SM1_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSim_2_SSM_ST_SM2_Enabled_SM1VTable != NULL
        && pSim_2_SSM_ST_SM2_Enabled_SM1VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSim_2_SSM_ST_SM2_Enabled_SM1VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return pConverter->m_pfnEnumToString(*(_2_SSM_ST_SM2_Enabled_SM1*)pValue, _2_SSM_ST_SM2_Enabled_SM1_values, _2_SSM_ST_SM2_Enabled_SM1_nb_values, pfnStrAppend, pStrObj); 
}

int check__2_SSM_ST_SM2_Enabled_SM1_string(const char *str, char **endptr)
{
    static _2_SSM_ST_SM2_Enabled_SM1 rTemp;
    return string_to__2_SSM_ST_SM2_Enabled_SM1(str, (void*)&rTemp, endptr);
}

int string_to__2_SSM_ST_SM2_Enabled_SM1(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSim_2_SSM_ST_SM2_Enabled_SM1VTable != NULL) {
        nRet = string_to_VTable(str, pSim_2_SSM_ST_SM2_Enabled_SM1VTable, pValue, endptr);
    }
    if (nRet == 0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, _2_SSM_ST_SM2_Enabled_SM1_values, _2_SSM_ST_SM2_Enabled_SM1_nb_values, endptr);
        if (pValue != NULL && nRet != 0)
            *(_2_SSM_ST_SM2_Enabled_SM1*)pValue = (_2_SSM_ST_SM2_Enabled_SM1)nTemp;
    }
    return nRet;
}

int is__2_SSM_ST_SM2_Enabled_SM1_double_conversion_allowed()
{
    if (pSim_2_SSM_ST_SM2_Enabled_SM1VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSim_2_SSM_ST_SM2_Enabled_SM1VTable);
    }
    return 1;
}

int _2_SSM_ST_SM2_Enabled_SM1_to_double(const void *pValue, double *nValue)
{
    if (pSim_2_SSM_ST_SM2_Enabled_SM1VTable != NULL) {
        return VTable_to_double(pValue, pSim_2_SSM_ST_SM2_Enabled_SM1VTable, nValue);
    }
    *nValue = (double)*((_2_SSM_ST_SM2_Enabled_SM1*)pValue);
    return 1;
}

int is__2_SSM_ST_SM2_Enabled_SM1_long_conversion_allowed()
{
    if (pSim_2_SSM_ST_SM2_Enabled_SM1VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSim_2_SSM_ST_SM2_Enabled_SM1VTable);
    }
    return 1;
}

int _2_SSM_ST_SM2_Enabled_SM1_to_long(const void *pValue, long *nValue)
{
    if (pSim_2_SSM_ST_SM2_Enabled_SM1VTable != NULL) {
        return VTable_to_long(pValue, pSim_2_SSM_ST_SM2_Enabled_SM1VTable, nValue);
    }
    *nValue = (long)*((_2_SSM_ST_SM2_Enabled_SM1*)pValue);
    return 1;
}

void compare__2_SSM_ST_SM2_Enabled_SM1(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSim_2_SSM_ST_SM2_Enabled_SM1VTable != NULL
        && pSim_2_SSM_ST_SM2_Enabled_SM1VTable->m_version >= Scv612
        && pSim_2_SSM_ST_SM2_Enabled_SM1VTable->m_pfnCompare != NULL) {
        if (pSim_2_SSM_ST_SM2_Enabled_SM1VTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSim_2_SSM_ST_SM2_Enabled_SM1VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSim_2_SSM_ST_SM2_Enabled_SM1VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(_2_SSM_ST_SM2_Enabled_SM1*)pValue1), (int)(*(_2_SSM_ST_SM2_Enabled_SM1*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get__2_SSM_ST_SM2_Enabled_SM1_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pConverter->m_pfnGetEnumSignature(_2_SSM_ST_SM2_Enabled_SM1_values, _2_SSM_ST_SM2_Enabled_SM1_nb_values, pfnStrAppend, pStrObj);
}

int init__2_SSM_ST_SM2_Enabled_SM1(void *pValue)
{
    *(_2_SSM_ST_SM2_Enabled_SM1*)pValue = SSM_st_Active_SM2_Enabled_SM1;
    return 1;
}

int release__2_SSM_ST_SM2_Enabled_SM1(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy__2_SSM_ST_SM2_Enabled_SM1(void *pToValue, const void *pFromValue)
{
    *((_2_SSM_ST_SM2_Enabled_SM1*)pToValue) = *((_2_SSM_ST_SM2_Enabled_SM1*)pFromValue);
    return 1;
}

SimTypeUtils _Type__2_SSM_ST_SM2_Enabled_SM1_Utils = {
    _2_SSM_ST_SM2_Enabled_SM1_to_string,
    check__2_SSM_ST_SM2_Enabled_SM1_string,
    string_to__2_SSM_ST_SM2_Enabled_SM1,
    is__2_SSM_ST_SM2_Enabled_SM1_double_conversion_allowed,
    _2_SSM_ST_SM2_Enabled_SM1_to_double,
    is__2_SSM_ST_SM2_Enabled_SM1_long_conversion_allowed,
    _2_SSM_ST_SM2_Enabled_SM1_to_long,
    compare__2_SSM_ST_SM2_Enabled_SM1,
    get__2_SSM_ST_SM2_Enabled_SM1_signature,
    init__2_SSM_ST_SM2_Enabled_SM1,
    release__2_SSM_ST_SM2_Enabled_SM1,
    copy__2_SSM_ST_SM2_Enabled_SM1,
    sizeof(_2_SSM_ST_SM2_Enabled_SM1)
};

/****************************************************************
 ** _3_SSM_TR_SM2_Enabled_SM1 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSim_3_SSM_TR_SM2_Enabled_SM1VTable_defined
    extern struct SimTypeVTable *pSim_3_SSM_TR_SM2_Enabled_SM1VTable;
  #else 
    struct SimTypeVTable *pSim_3_SSM_TR_SM2_Enabled_SM1VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSim_3_SSM_TR_SM2_Enabled_SM1VTable;
#endif

static SimEnumValUtils _3_SSM_TR_SM2_Enabled_SM1_values[] = {
    { "_9_SSM_TR_no_trans_SM2_Enabled_SM1", _9_SSM_TR_no_trans_SM2_Enabled_SM1},
    { "SSM_TR_Active_Interrupt_1_Active_SM2_Enabled_SM1", SSM_TR_Active_Interrupt_1_Active_SM2_Enabled_SM1},
    { "SSM_TR_Interrupt_Active_1_Interrupt_SM2_Enabled_SM1", SSM_TR_Interrupt_Active_1_Interrupt_SM2_Enabled_SM1},
};
const int _3_SSM_TR_SM2_Enabled_SM1_nb_values = 3;

int _3_SSM_TR_SM2_Enabled_SM1_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSim_3_SSM_TR_SM2_Enabled_SM1VTable != NULL
        && pSim_3_SSM_TR_SM2_Enabled_SM1VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSim_3_SSM_TR_SM2_Enabled_SM1VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return pConverter->m_pfnEnumToString(*(_3_SSM_TR_SM2_Enabled_SM1*)pValue, _3_SSM_TR_SM2_Enabled_SM1_values, _3_SSM_TR_SM2_Enabled_SM1_nb_values, pfnStrAppend, pStrObj); 
}

int check__3_SSM_TR_SM2_Enabled_SM1_string(const char *str, char **endptr)
{
    static _3_SSM_TR_SM2_Enabled_SM1 rTemp;
    return string_to__3_SSM_TR_SM2_Enabled_SM1(str, (void*)&rTemp, endptr);
}

int string_to__3_SSM_TR_SM2_Enabled_SM1(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSim_3_SSM_TR_SM2_Enabled_SM1VTable != NULL) {
        nRet = string_to_VTable(str, pSim_3_SSM_TR_SM2_Enabled_SM1VTable, pValue, endptr);
    }
    if (nRet == 0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, _3_SSM_TR_SM2_Enabled_SM1_values, _3_SSM_TR_SM2_Enabled_SM1_nb_values, endptr);
        if (pValue != NULL && nRet != 0)
            *(_3_SSM_TR_SM2_Enabled_SM1*)pValue = (_3_SSM_TR_SM2_Enabled_SM1)nTemp;
    }
    return nRet;
}

int is__3_SSM_TR_SM2_Enabled_SM1_double_conversion_allowed()
{
    if (pSim_3_SSM_TR_SM2_Enabled_SM1VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSim_3_SSM_TR_SM2_Enabled_SM1VTable);
    }
    return 1;
}

int _3_SSM_TR_SM2_Enabled_SM1_to_double(const void *pValue, double *nValue)
{
    if (pSim_3_SSM_TR_SM2_Enabled_SM1VTable != NULL) {
        return VTable_to_double(pValue, pSim_3_SSM_TR_SM2_Enabled_SM1VTable, nValue);
    }
    *nValue = (double)*((_3_SSM_TR_SM2_Enabled_SM1*)pValue);
    return 1;
}

int is__3_SSM_TR_SM2_Enabled_SM1_long_conversion_allowed()
{
    if (pSim_3_SSM_TR_SM2_Enabled_SM1VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSim_3_SSM_TR_SM2_Enabled_SM1VTable);
    }
    return 1;
}

int _3_SSM_TR_SM2_Enabled_SM1_to_long(const void *pValue, long *nValue)
{
    if (pSim_3_SSM_TR_SM2_Enabled_SM1VTable != NULL) {
        return VTable_to_long(pValue, pSim_3_SSM_TR_SM2_Enabled_SM1VTable, nValue);
    }
    *nValue = (long)*((_3_SSM_TR_SM2_Enabled_SM1*)pValue);
    return 1;
}

void compare__3_SSM_TR_SM2_Enabled_SM1(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSim_3_SSM_TR_SM2_Enabled_SM1VTable != NULL
        && pSim_3_SSM_TR_SM2_Enabled_SM1VTable->m_version >= Scv612
        && pSim_3_SSM_TR_SM2_Enabled_SM1VTable->m_pfnCompare != NULL) {
        if (pSim_3_SSM_TR_SM2_Enabled_SM1VTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSim_3_SSM_TR_SM2_Enabled_SM1VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSim_3_SSM_TR_SM2_Enabled_SM1VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(_3_SSM_TR_SM2_Enabled_SM1*)pValue1), (int)(*(_3_SSM_TR_SM2_Enabled_SM1*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get__3_SSM_TR_SM2_Enabled_SM1_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pConverter->m_pfnGetEnumSignature(_3_SSM_TR_SM2_Enabled_SM1_values, _3_SSM_TR_SM2_Enabled_SM1_nb_values, pfnStrAppend, pStrObj);
}

int init__3_SSM_TR_SM2_Enabled_SM1(void *pValue)
{
    *(_3_SSM_TR_SM2_Enabled_SM1*)pValue = _9_SSM_TR_no_trans_SM2_Enabled_SM1;
    return 1;
}

int release__3_SSM_TR_SM2_Enabled_SM1(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy__3_SSM_TR_SM2_Enabled_SM1(void *pToValue, const void *pFromValue)
{
    *((_3_SSM_TR_SM2_Enabled_SM1*)pToValue) = *((_3_SSM_TR_SM2_Enabled_SM1*)pFromValue);
    return 1;
}

SimTypeUtils _Type__3_SSM_TR_SM2_Enabled_SM1_Utils = {
    _3_SSM_TR_SM2_Enabled_SM1_to_string,
    check__3_SSM_TR_SM2_Enabled_SM1_string,
    string_to__3_SSM_TR_SM2_Enabled_SM1,
    is__3_SSM_TR_SM2_Enabled_SM1_double_conversion_allowed,
    _3_SSM_TR_SM2_Enabled_SM1_to_double,
    is__3_SSM_TR_SM2_Enabled_SM1_long_conversion_allowed,
    _3_SSM_TR_SM2_Enabled_SM1_to_long,
    compare__3_SSM_TR_SM2_Enabled_SM1,
    get__3_SSM_TR_SM2_Enabled_SM1_signature,
    init__3_SSM_TR_SM2_Enabled_SM1,
    release__3_SSM_TR_SM2_Enabled_SM1,
    copy__3_SSM_TR_SM2_Enabled_SM1,
    sizeof(_3_SSM_TR_SM2_Enabled_SM1)
};

/****************************************************************
 ** _4_SSM_ST_SM1 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSim_4_SSM_ST_SM1VTable_defined
    extern struct SimTypeVTable *pSim_4_SSM_ST_SM1VTable;
  #else 
    struct SimTypeVTable *pSim_4_SSM_ST_SM1VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSim_4_SSM_ST_SM1VTable;
#endif

static SimEnumValUtils _4_SSM_ST_SM1_values[] = {
    { "Off", SSM_st_Off_SM1},
    { "Enabled", SSM_st_Enabled_SM1},
};
const int _4_SSM_ST_SM1_nb_values = 2;

int _4_SSM_ST_SM1_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSim_4_SSM_ST_SM1VTable != NULL
        && pSim_4_SSM_ST_SM1VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSim_4_SSM_ST_SM1VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return pConverter->m_pfnEnumToString(*(_4_SSM_ST_SM1*)pValue, _4_SSM_ST_SM1_values, _4_SSM_ST_SM1_nb_values, pfnStrAppend, pStrObj); 
}

int check__4_SSM_ST_SM1_string(const char *str, char **endptr)
{
    static _4_SSM_ST_SM1 rTemp;
    return string_to__4_SSM_ST_SM1(str, (void*)&rTemp, endptr);
}

int string_to__4_SSM_ST_SM1(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSim_4_SSM_ST_SM1VTable != NULL) {
        nRet = string_to_VTable(str, pSim_4_SSM_ST_SM1VTable, pValue, endptr);
    }
    if (nRet == 0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, _4_SSM_ST_SM1_values, _4_SSM_ST_SM1_nb_values, endptr);
        if (pValue != NULL && nRet != 0)
            *(_4_SSM_ST_SM1*)pValue = (_4_SSM_ST_SM1)nTemp;
    }
    return nRet;
}

int is__4_SSM_ST_SM1_double_conversion_allowed()
{
    if (pSim_4_SSM_ST_SM1VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSim_4_SSM_ST_SM1VTable);
    }
    return 1;
}

int _4_SSM_ST_SM1_to_double(const void *pValue, double *nValue)
{
    if (pSim_4_SSM_ST_SM1VTable != NULL) {
        return VTable_to_double(pValue, pSim_4_SSM_ST_SM1VTable, nValue);
    }
    *nValue = (double)*((_4_SSM_ST_SM1*)pValue);
    return 1;
}

int is__4_SSM_ST_SM1_long_conversion_allowed()
{
    if (pSim_4_SSM_ST_SM1VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSim_4_SSM_ST_SM1VTable);
    }
    return 1;
}

int _4_SSM_ST_SM1_to_long(const void *pValue, long *nValue)
{
    if (pSim_4_SSM_ST_SM1VTable != NULL) {
        return VTable_to_long(pValue, pSim_4_SSM_ST_SM1VTable, nValue);
    }
    *nValue = (long)*((_4_SSM_ST_SM1*)pValue);
    return 1;
}

void compare__4_SSM_ST_SM1(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSim_4_SSM_ST_SM1VTable != NULL
        && pSim_4_SSM_ST_SM1VTable->m_version >= Scv612
        && pSim_4_SSM_ST_SM1VTable->m_pfnCompare != NULL) {
        if (pSim_4_SSM_ST_SM1VTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSim_4_SSM_ST_SM1VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSim_4_SSM_ST_SM1VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(_4_SSM_ST_SM1*)pValue1), (int)(*(_4_SSM_ST_SM1*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get__4_SSM_ST_SM1_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pConverter->m_pfnGetEnumSignature(_4_SSM_ST_SM1_values, _4_SSM_ST_SM1_nb_values, pfnStrAppend, pStrObj);
}

int init__4_SSM_ST_SM1(void *pValue)
{
    *(_4_SSM_ST_SM1*)pValue = SSM_st_Off_SM1;
    return 1;
}

int release__4_SSM_ST_SM1(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy__4_SSM_ST_SM1(void *pToValue, const void *pFromValue)
{
    *((_4_SSM_ST_SM1*)pToValue) = *((_4_SSM_ST_SM1*)pFromValue);
    return 1;
}

SimTypeUtils _Type__4_SSM_ST_SM1_Utils = {
    _4_SSM_ST_SM1_to_string,
    check__4_SSM_ST_SM1_string,
    string_to__4_SSM_ST_SM1,
    is__4_SSM_ST_SM1_double_conversion_allowed,
    _4_SSM_ST_SM1_to_double,
    is__4_SSM_ST_SM1_long_conversion_allowed,
    _4_SSM_ST_SM1_to_long,
    compare__4_SSM_ST_SM1,
    get__4_SSM_ST_SM1_signature,
    init__4_SSM_ST_SM1,
    release__4_SSM_ST_SM1,
    copy__4_SSM_ST_SM1,
    sizeof(_4_SSM_ST_SM1)
};

/****************************************************************
 ** _5_SSM_TR_SM1 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSim_5_SSM_TR_SM1VTable_defined
    extern struct SimTypeVTable *pSim_5_SSM_TR_SM1VTable;
  #else 
    struct SimTypeVTable *pSim_5_SSM_TR_SM1VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSim_5_SSM_TR_SM1VTable;
#endif

static SimEnumValUtils _5_SSM_TR_SM1_values[] = {
    { "_10_SSM_TR_no_trans_SM1", _10_SSM_TR_no_trans_SM1},
    { "_11_SSM_TR_Off_Enabled_1_Off_SM1", _11_SSM_TR_Off_Enabled_1_Off_SM1},
    { "_12_SSM_TR_Enabled_Off_1_Enabled_SM1", _12_SSM_TR_Enabled_Off_1_Enabled_SM1},
};
const int _5_SSM_TR_SM1_nb_values = 3;

int _5_SSM_TR_SM1_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSim_5_SSM_TR_SM1VTable != NULL
        && pSim_5_SSM_TR_SM1VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSim_5_SSM_TR_SM1VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return pConverter->m_pfnEnumToString(*(_5_SSM_TR_SM1*)pValue, _5_SSM_TR_SM1_values, _5_SSM_TR_SM1_nb_values, pfnStrAppend, pStrObj); 
}

int check__5_SSM_TR_SM1_string(const char *str, char **endptr)
{
    static _5_SSM_TR_SM1 rTemp;
    return string_to__5_SSM_TR_SM1(str, (void*)&rTemp, endptr);
}

int string_to__5_SSM_TR_SM1(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSim_5_SSM_TR_SM1VTable != NULL) {
        nRet = string_to_VTable(str, pSim_5_SSM_TR_SM1VTable, pValue, endptr);
    }
    if (nRet == 0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, _5_SSM_TR_SM1_values, _5_SSM_TR_SM1_nb_values, endptr);
        if (pValue != NULL && nRet != 0)
            *(_5_SSM_TR_SM1*)pValue = (_5_SSM_TR_SM1)nTemp;
    }
    return nRet;
}

int is__5_SSM_TR_SM1_double_conversion_allowed()
{
    if (pSim_5_SSM_TR_SM1VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSim_5_SSM_TR_SM1VTable);
    }
    return 1;
}

int _5_SSM_TR_SM1_to_double(const void *pValue, double *nValue)
{
    if (pSim_5_SSM_TR_SM1VTable != NULL) {
        return VTable_to_double(pValue, pSim_5_SSM_TR_SM1VTable, nValue);
    }
    *nValue = (double)*((_5_SSM_TR_SM1*)pValue);
    return 1;
}

int is__5_SSM_TR_SM1_long_conversion_allowed()
{
    if (pSim_5_SSM_TR_SM1VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSim_5_SSM_TR_SM1VTable);
    }
    return 1;
}

int _5_SSM_TR_SM1_to_long(const void *pValue, long *nValue)
{
    if (pSim_5_SSM_TR_SM1VTable != NULL) {
        return VTable_to_long(pValue, pSim_5_SSM_TR_SM1VTable, nValue);
    }
    *nValue = (long)*((_5_SSM_TR_SM1*)pValue);
    return 1;
}

void compare__5_SSM_TR_SM1(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSim_5_SSM_TR_SM1VTable != NULL
        && pSim_5_SSM_TR_SM1VTable->m_version >= Scv612
        && pSim_5_SSM_TR_SM1VTable->m_pfnCompare != NULL) {
        if (pSim_5_SSM_TR_SM1VTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSim_5_SSM_TR_SM1VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSim_5_SSM_TR_SM1VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(_5_SSM_TR_SM1*)pValue1), (int)(*(_5_SSM_TR_SM1*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get__5_SSM_TR_SM1_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pConverter->m_pfnGetEnumSignature(_5_SSM_TR_SM1_values, _5_SSM_TR_SM1_nb_values, pfnStrAppend, pStrObj);
}

int init__5_SSM_TR_SM1(void *pValue)
{
    *(_5_SSM_TR_SM1*)pValue = _10_SSM_TR_no_trans_SM1;
    return 1;
}

int release__5_SSM_TR_SM1(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy__5_SSM_TR_SM1(void *pToValue, const void *pFromValue)
{
    *((_5_SSM_TR_SM1*)pToValue) = *((_5_SSM_TR_SM1*)pFromValue);
    return 1;
}

SimTypeUtils _Type__5_SSM_TR_SM1_Utils = {
    _5_SSM_TR_SM1_to_string,
    check__5_SSM_TR_SM1_string,
    string_to__5_SSM_TR_SM1,
    is__5_SSM_TR_SM1_double_conversion_allowed,
    _5_SSM_TR_SM1_to_double,
    is__5_SSM_TR_SM1_long_conversion_allowed,
    _5_SSM_TR_SM1_to_long,
    compare__5_SSM_TR_SM1,
    get__5_SSM_TR_SM1_signature,
    init__5_SSM_TR_SM1,
    release__5_SSM_TR_SM1,
    copy__5_SSM_TR_SM1,
    sizeof(_5_SSM_TR_SM1)
};

/****************************************************************
 ** array_float64_5 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimarray_float64_5VTable_defined
    extern struct SimTypeVTable *pSimarray_float64_5VTable;
  #else 
    struct SimTypeVTable *pSimarray_float64_5VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimarray_float64_5VTable;
#endif

static SimConstValUtils const array_float64_5_constants[] = {
    { "Car::KTRANSM", &TU_KTRANSM_Car },
    { "KTRANSM", &TU_KTRANSM_Car },
};

int array_float64_5_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimarray_float64_5VTable != NULL
        && pSimarray_float64_5VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray_float64_5VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return pConverter->m_pfnArrayToString(pValue, kcg_float64_to_string, 5, sizeof(kcg_float64), pfnStrAppend, pStrObj);
}

int check_array_float64_5_string(const char *str, char **endptr)
{
    static array_float64_5 rTemp;
    return string_to_array_float64_5(str, (void*)&rTemp, endptr);
}

int string_to_array_float64_5(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimarray_float64_5VTable != NULL) {
        nRet = string_to_VTable(str, pSimarray_float64_5VTable, pValue, endptr);
    }
    if (nRet == 0 && pConverter->m_pfnStringToConstant) {
        nRet = pConverter->m_pfnStringToConstant(str, pValue, array_float64_5_constants, sizeof(array_float64_5_constants) / sizeof(array_float64_5_constants[0]), sizeof(array_float64_5), endptr);
        if (nRet != 0) {
            return 2;
        }
    }
    if (nRet == 0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_kcg_float64_Utils, 5, sizeof(kcg_float64), endptr);
    }
    return nRet;
}

int is_array_float64_5_double_conversion_allowed()
{
    if (pSimarray_float64_5VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimarray_float64_5VTable);
    }
    return 0;
}

int array_float64_5_to_double(const void *pValue, double *nValue)
{
    if (pSimarray_float64_5VTable != NULL) {
        return VTable_to_double(pValue, pSimarray_float64_5VTable, nValue);
    }
    return 0;
}

int is_array_float64_5_long_conversion_allowed()
{
    if (pSimarray_float64_5VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimarray_float64_5VTable);
    }
    return 0;
}

int array_float64_5_to_long(const void *pValue, long *nValue)
{
    if (pSimarray_float64_5VTable != NULL) {
        return VTable_to_long(pValue, pSimarray_float64_5VTable, nValue);
    }
    return 0;
}

void compare_array_float64_5(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimarray_float64_5VTable != NULL
        && pSimarray_float64_5VTable->m_version >= Scv612
        && pSimarray_float64_5VTable->m_pfnCompare != NULL) {
        if (pSimarray_float64_5VTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSimarray_float64_5VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSimarray_float64_5VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_kcg_float64, 5, sizeof(kcg_float64), pTol, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_array_float64_5_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pConverter->m_pfnGetArraySignature(get_kcg_float64_signature, 5, pfnStrAppend, pStrObj); 
}

int init_array_float64_5(void *pValue)
{
    size_t i;
    for (i = 0; i < 5; i++)
        init_kcg_float64(&((kcg_float64*)pValue)[i]);
    return 1;
}

int release_array_float64_5(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_array_float64_5(void *pToValue, const void *pFromValue)
{
    kcg_copy_array_float64_5((array_float64_5*)pToValue, (array_float64_5*)pFromValue);
    return 1;
}

SimTypeUtils _Type_array_float64_5_Utils = {
    array_float64_5_to_string,
    check_array_float64_5_string,
    string_to_array_float64_5,
    is_array_float64_5_double_conversion_allowed,
    array_float64_5_to_double,
    is_array_float64_5_long_conversion_allowed,
    array_float64_5_to_long,
    compare_array_float64_5,
    get_array_float64_5_signature,
    init_array_float64_5,
    release_array_float64_5,
    copy_array_float64_5,
    sizeof(array_float64_5)
};

/****************************************************************
 ** kcg_bool 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimBoolVTable_defined
    extern struct SimTypeVTable *pSimBoolVTable;
  #else 
    struct SimTypeVTable *pSimBoolVTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimBoolVTable;
#endif

int kcg_bool_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimBoolVTable != NULL
        && pSimBoolVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        if (pSimBoolVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> variable to VTable function: */
            return pfnStrAppend(*(char**)pSimBoolVTable->m_pfnToType(SptString, pValue), pStrObj);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            SimBool value = (*((const kcg_bool*)pValue) == kcg_true)? SbTrue : SbFalse;
            return pfnStrAppend(*(char**)pSimBoolVTable->m_pfnToType(SptString, &value), pStrObj);
        }
    }
    return predef_kcg_bool_to_string(*((kcg_bool*)pValue), pfnStrAppend, pStrObj);
}

int check_kcg_bool_string(const char *str, char **endptr)
{
    static kcg_bool rTemp;
    return string_to_kcg_bool(str, (void*)&rTemp, endptr);
}

int string_to_kcg_bool(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    static SimBool rTemp;
    skip_whitespace(str);
    if (pSimBoolVTable != NULL) {
        if (pSimBoolVTable->m_version >= Scv65) {
            /* R15 and higher: VTable function must return a kcg_<type> *variable: */
            nRet = string_to_VTable(str, pSimBoolVTable, pValue, endptr);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            nRet = string_to_VTable(str, pSimBoolVTable, &rTemp, endptr);
            if (nRet != 0) {
                *(kcg_bool*)pValue = (rTemp == SbTrue)? kcg_true : kcg_false;
            }
        }
    }
    if (nRet == 0) {
        nRet = predef_string_to_kcg_bool(str, (kcg_bool*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_bool_double_conversion_allowed()
{
    if (pSimBoolVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimBoolVTable);
    }
    return 1;
}

int kcg_bool_to_double(const void *pValue, double *nValue)
{
    if (pSimBoolVTable != NULL) {
        if (pSimBoolVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            return VTable_to_double(pValue, pSimBoolVTable, nValue);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            SimBool value = (*((const kcg_bool*)pValue) == kcg_true)? SbTrue : SbFalse;
            return VTable_to_double(&value, pSimBoolVTable, nValue);
        }
    }
    *nValue = *((kcg_bool*)pValue) == kcg_true ? 1.0 : 0.0;
    return 1;
}

int is_kcg_bool_long_conversion_allowed()
{
    if (pSimBoolVTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimBoolVTable);
    }
    return 1;
}

int kcg_bool_to_long(const void *pValue, long *nValue)
{
    if (pSimBoolVTable != NULL) {
        if (pSimBoolVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            return VTable_to_long(pValue, pSimBoolVTable, nValue);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            SimBool value = (*((const kcg_bool*)pValue) == kcg_true)? SbTrue : SbFalse;
            return VTable_to_long(&value, pSimBoolVTable, nValue);
        }
    }
    *nValue = *((kcg_bool*)pValue) == kcg_true ? 1 : 0;
    return 1;
}

void compare_kcg_bool(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimBoolVTable != NULL
        && pSimBoolVTable->m_version >= Scv612
        && pSimBoolVTable->m_pfnCompare != NULL) {
        if (pSimBoolVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            unitResult = pSimBoolVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            SimBool value1 = (*((const kcg_bool*)pValue1) == kcg_true)? SbTrue : SbFalse;
            SimBool value2 = (*((const kcg_bool*)pValue2) == kcg_true)? SbTrue : SbFalse;
            pSimBoolVTable->m_pfnCompare(&unitResult, &value1, &value2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_kcg_bool(pResult, *((kcg_bool*)pValue1), *((kcg_bool*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_kcg_bool_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pfnStrAppend("B", pStrObj);
}

int init_kcg_bool(void *pValue)
{
    *(kcg_bool*)pValue = kcg_false;
    return 1;
}

int release_kcg_bool(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_kcg_bool(void *pToValue, const void *pFromValue)
{
    *((kcg_bool*)pToValue) = *((kcg_bool*)pFromValue);
    return 1;
}

SimTypeUtils _Type_kcg_bool_Utils = {
    kcg_bool_to_string,
    check_kcg_bool_string,
    string_to_kcg_bool,
    is_kcg_bool_double_conversion_allowed,
    kcg_bool_to_double,
    is_kcg_bool_long_conversion_allowed,
    kcg_bool_to_long,
    compare_kcg_bool,
    get_kcg_bool_signature,
    init_kcg_bool,
    release_kcg_bool,
    copy_kcg_bool,
    sizeof(kcg_bool)
};

/****************************************************************
 ** kcg_char 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimCharVTable_defined
    extern struct SimTypeVTable *pSimCharVTable;
  #else 
    struct SimTypeVTable *pSimCharVTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimCharVTable;
#endif

int kcg_char_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimCharVTable != NULL
        && pSimCharVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        if (pSimCharVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> variable to VTable function: */
            return pfnStrAppend(*(char**)pSimCharVTable->m_pfnToType(SptString, pValue), pStrObj);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            char value = (char)(*(const kcg_char*)pValue);
            return pfnStrAppend(*(char**)pSimCharVTable->m_pfnToType(SptString, &value), pStrObj);
        }
    }
    return predef_kcg_char_to_string(*((kcg_char*)pValue), pfnStrAppend, pStrObj);
}

int check_kcg_char_string(const char *str, char **endptr)
{
    static kcg_char rTemp;
    return string_to_kcg_char(str, (void*)&rTemp, endptr);
}

int string_to_kcg_char(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    static char rTemp;
    skip_whitespace(str);
    if (pSimCharVTable != NULL) {
        if (pSimCharVTable->m_version >= Scv65) {
            /* R15 and higher: VTable function must return a kcg_<type> *variable: */
            nRet = string_to_VTable(str, pSimCharVTable, pValue, endptr);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            nRet = string_to_VTable(str, pSimCharVTable, &rTemp, endptr);
            if (nRet != 0) {
                *(kcg_char*)pValue = (kcg_char)rTemp;
            }
        }
    }
    if (nRet == 0) {
        nRet = predef_string_to_kcg_char(str, (kcg_char*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_char_double_conversion_allowed()
{
    if (pSimCharVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimCharVTable);
    }
    return 1;
}

int kcg_char_to_double(const void *pValue, double *nValue)
{
    if (pSimCharVTable != NULL) {
        if (pSimCharVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            return VTable_to_double(pValue, pSimCharVTable, nValue);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            char value = (char)(*(const kcg_char*)pValue);
            return VTable_to_double(&value, pSimCharVTable, nValue);
        }
    }
    *nValue = (double)*((kcg_char*)pValue);
    return 1;
}

int is_kcg_char_long_conversion_allowed()
{
    if (pSimCharVTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimCharVTable);
    }
    return 1;
}

int kcg_char_to_long(const void *pValue, long *nValue)
{
    if (pSimCharVTable != NULL) {
        if (pSimCharVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            return VTable_to_long(pValue, pSimCharVTable, nValue);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            char value = (char)(*(const kcg_char*)pValue);
            return VTable_to_long(&value, pSimCharVTable, nValue);
        }
    }
    *nValue = (long)*((kcg_char*)pValue);
    return 1;
}

void compare_kcg_char(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimCharVTable != NULL
        && pSimCharVTable->m_version >= Scv612
        && pSimCharVTable->m_pfnCompare != NULL) {
        if (pSimCharVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            unitResult = pSimCharVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            char value1 = (char)(*(const kcg_char*)pValue1);
            char value2 = (char)(*(const kcg_char*)pValue2);
            pSimCharVTable->m_pfnCompare(&unitResult, &value1, &value2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_kcg_char(pResult, *((kcg_char*)pValue1), *((kcg_char*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_kcg_char_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pfnStrAppend("C", pStrObj);
}

int init_kcg_char(void *pValue)
{
    *(kcg_char*)pValue = 0;
    return 1;
}

int release_kcg_char(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_kcg_char(void *pToValue, const void *pFromValue)
{
    *((kcg_char*)pToValue) = *((kcg_char*)pFromValue);
    return 1;
}

SimTypeUtils _Type_kcg_char_Utils = {
    kcg_char_to_string,
    check_kcg_char_string,
    string_to_kcg_char,
    is_kcg_char_double_conversion_allowed,
    kcg_char_to_double,
    is_kcg_char_long_conversion_allowed,
    kcg_char_to_long,
    compare_kcg_char,
    get_kcg_char_signature,
    init_kcg_char,
    release_kcg_char,
    copy_kcg_char,
    sizeof(kcg_char)
};

/****************************************************************
 ** kcg_float32 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimFloat32VTable_defined
    extern struct SimTypeVTable *pSimFloat32VTable;
  #else 
    struct SimTypeVTable *pSimFloat32VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimFloat32VTable;
#endif

int kcg_float32_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimFloat32VTable != NULL
        && pSimFloat32VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimFloat32VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return predef_kcg_float32_to_string(*((kcg_float32*)pValue), pConverter->m_RealFormat, pfnStrAppend, pStrObj);
}

int check_kcg_float32_string(const char *str, char **endptr)
{
    static kcg_float32 rTemp;
    return string_to_kcg_float32(str, (void*)&rTemp, endptr);
}

int string_to_kcg_float32(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimFloat32VTable != NULL) {
        nRet = string_to_VTable(str, pSimFloat32VTable, pValue, endptr);
    }
    if (nRet == 0) {
        nRet = predef_string_to_kcg_float32(str, (kcg_float32*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_float32_double_conversion_allowed()
{
    if (pSimFloat32VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimFloat32VTable);
    }
    return 1;
}

int kcg_float32_to_double(const void *pValue, double *nValue)
{
    if (pSimFloat32VTable != NULL) {
        return VTable_to_double(pValue, pSimFloat32VTable, nValue);
    }
    *nValue = (double)*((kcg_float32*)pValue);
    return 1;
}

int is_kcg_float32_long_conversion_allowed()
{
    if (pSimFloat32VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimFloat32VTable);
    }
    return 1;
}

int kcg_float32_to_long(const void *pValue, long *nValue)
{
    if (pSimFloat32VTable != NULL) {
        return VTable_to_long(pValue, pSimFloat32VTable, nValue);
    }
    *nValue = (long)*((kcg_float32*)pValue);
    return 1;
}

void compare_kcg_float32(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    if (!pTol)
        pTol = (SimTolerance*)&defaultSimToleranceFloat;
    if (pSimFloat32VTable != NULL
        && pSimFloat32VTable->m_pfnCompareWithTol != NULL ) {
        /* Customized comparison with tolerance (R15 and higher): */
        unitResult = pSimFloat32VTable->m_pfnCompareWithTol(pResult, pValue1, pValue2, pTol);
    } else if (pSimFloat32VTable != NULL && pTol == (SimTolerance*)&defaultSimToleranceFloat
               && pSimFloat32VTable->m_version >= Scv612
               && pSimFloat32VTable->m_pfnCompare != NULL) {
        /* Customized comparison without tolerance: */
        unitResult = pSimFloat32VTable->m_pfnCompare(pResult, pValue1, pValue2);
    } else {
        /* Predefined comparison (with/without tolerance): */
        unitResult = predef_compare_kcg_float32(pResult, *((kcg_float32*)pValue1), *((kcg_float32*)pValue2), pTol);
    }
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_kcg_float32_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pfnStrAppend("F32", pStrObj);
}

int init_kcg_float32(void *pValue)
{
    *(kcg_float32*)pValue = 0.0;
    return 1;
}

int release_kcg_float32(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_kcg_float32(void *pToValue, const void *pFromValue)
{
    *((kcg_float32*)pToValue) = *((kcg_float32*)pFromValue);
    return 1;
}

SimTypeUtils _Type_kcg_float32_Utils = {
    kcg_float32_to_string,
    check_kcg_float32_string,
    string_to_kcg_float32,
    is_kcg_float32_double_conversion_allowed,
    kcg_float32_to_double,
    is_kcg_float32_long_conversion_allowed,
    kcg_float32_to_long,
    compare_kcg_float32,
    get_kcg_float32_signature,
    init_kcg_float32,
    release_kcg_float32,
    copy_kcg_float32,
    sizeof(kcg_float32)
};

/****************************************************************
 ** kcg_float64 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimFloat64VTable_defined
    extern struct SimTypeVTable *pSimFloat64VTable;
  #else 
    struct SimTypeVTable *pSimFloat64VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimFloat64VTable;
#endif

static SimConstValUtils const kcg_float64_constants[] = {
    { "Defs::ZeroSpeed", &TU_ZeroSpeed_Defs },
    { "ZeroSpeed", &TU_ZeroSpeed_Defs },
    { "Defs::ZeroPercent", &TU_ZeroPercent_Defs },
    { "ZeroPercent", &TU_ZeroPercent_Defs },
    { "Defs::SpeedMin", &TU_SpeedMin_Defs },
    { "SpeedMin", &TU_SpeedMin_Defs },
    { "Defs::SpeedMax", &TU_SpeedMax_Defs },
    { "SpeedMax", &TU_SpeedMax_Defs },
    { "Defs::SpeedInc", &TU_SpeedInc_Defs },
    { "SpeedInc", &TU_SpeedInc_Defs },
    { "Defs::RegulThrottleMax", &TU_RegulThrottleMax_Defs },
    { "RegulThrottleMax", &TU_RegulThrottleMax_Defs },
    { "Defs::PedalsMin", &TU_PedalsMin_Defs },
    { "PedalsMin", &TU_PedalsMin_Defs },
    { "Defs::Kp", &TU_Kp_Defs },
    { "Kp", &TU_Kp_Defs },
    { "Defs::Ki", &TU_Ki_Defs },
    { "Ki", &TU_Ki_Defs },
    { "Defs::SensorConst", &TU_SensorConst_Defs },
    { "SensorConst", &TU_SensorConst_Defs },
    { "Defs::BrakeConst", &TU_BrakeConst_Defs },
    { "BrakeConst", &TU_BrakeConst_Defs },
    { "Defs::SecondBrakeConst", &TU_SecondBrakeConst_Defs },
    { "SecondBrakeConst", &TU_SecondBrakeConst_Defs },
    { "Car::Iengine", &TU_Iengine_Car },
    { "Iengine", &TU_Iengine_Car },
    { "Car::KBRAKE", &TU_KBRAKE_Car },
    { "KBRAKE", &TU_KBRAKE_Car },
    { "Car::MASS", &TU_MASS_Car },
    { "MASS", &TU_MASS_Car },
    { "Car::TCYCLE", &TU_TCYCLE_Car },
    { "TCYCLE", &TU_TCYCLE_Car },
    { "Car::Tengine", &TU_Tengine_Car },
    { "Tengine", &TU_Tengine_Car },
    { "Car::TorqMax", &TU_TorqMax_Car },
    { "TorqMax", &TU_TorqMax_Car },
    { "Car::VehicleDynamic", &TU_VehicleDynamic_Car },
    { "VehicleDynamic", &TU_VehicleDynamic_Car },
};

int kcg_float64_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimFloat64VTable != NULL
        && pSimFloat64VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimFloat64VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return predef_kcg_float64_to_string(*((kcg_float64*)pValue), pConverter->m_RealFormat, pfnStrAppend, pStrObj);
}

int check_kcg_float64_string(const char *str, char **endptr)
{
    static kcg_float64 rTemp;
    return string_to_kcg_float64(str, (void*)&rTemp, endptr);
}

int string_to_kcg_float64(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimFloat64VTable != NULL) {
        nRet = string_to_VTable(str, pSimFloat64VTable, pValue, endptr);
    }
    if (nRet == 0 && pConverter->m_pfnStringToConstant) {
        nRet = pConverter->m_pfnStringToConstant(str, pValue, kcg_float64_constants, sizeof(kcg_float64_constants) / sizeof(kcg_float64_constants[0]), sizeof(kcg_float64), endptr);
        if (nRet != 0) {
            return 2;
        }
    }
    if (nRet == 0) {
        nRet = predef_string_to_kcg_float64(str, (kcg_float64*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_float64_double_conversion_allowed()
{
    if (pSimFloat64VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimFloat64VTable);
    }
    return 1;
}

int kcg_float64_to_double(const void *pValue, double *nValue)
{
    if (pSimFloat64VTable != NULL) {
        return VTable_to_double(pValue, pSimFloat64VTable, nValue);
    }
    *nValue = (double)*((kcg_float64*)pValue);
    return 1;
}

int is_kcg_float64_long_conversion_allowed()
{
    if (pSimFloat64VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimFloat64VTable);
    }
    return 1;
}

int kcg_float64_to_long(const void *pValue, long *nValue)
{
    if (pSimFloat64VTable != NULL) {
        return VTable_to_long(pValue, pSimFloat64VTable, nValue);
    }
    *nValue = (long)*((kcg_float64*)pValue);
    return 1;
}

void compare_kcg_float64(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    if (!pTol)
        pTol = (SimTolerance*)&defaultSimToleranceDouble;
    if (pSimFloat64VTable != NULL
        && pSimFloat64VTable->m_pfnCompareWithTol != NULL ) {
        /* Customized comparison with tolerance (R15 and higher): */
        unitResult = pSimFloat64VTable->m_pfnCompareWithTol(pResult, pValue1, pValue2, pTol);
    } else if (pSimFloat64VTable != NULL && pTol == (SimTolerance*)&defaultSimToleranceDouble
               && pSimFloat64VTable->m_version >= Scv612
               && pSimFloat64VTable->m_pfnCompare != NULL) {
        /* Customized comparison without tolerance: */
        unitResult = pSimFloat64VTable->m_pfnCompare(pResult, pValue1, pValue2);
    } else {
        /* Predefined comparison (with/without tolerance): */
        unitResult = predef_compare_kcg_float64(pResult, *((kcg_float64*)pValue1), *((kcg_float64*)pValue2), pTol);
    }
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_kcg_float64_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pfnStrAppend("F64", pStrObj);
}

int init_kcg_float64(void *pValue)
{
    *(kcg_float64*)pValue = 0.0;
    return 1;
}

int release_kcg_float64(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_kcg_float64(void *pToValue, const void *pFromValue)
{
    *((kcg_float64*)pToValue) = *((kcg_float64*)pFromValue);
    return 1;
}

SimTypeUtils _Type_kcg_float64_Utils = {
    kcg_float64_to_string,
    check_kcg_float64_string,
    string_to_kcg_float64,
    is_kcg_float64_double_conversion_allowed,
    kcg_float64_to_double,
    is_kcg_float64_long_conversion_allowed,
    kcg_float64_to_long,
    compare_kcg_float64,
    get_kcg_float64_signature,
    init_kcg_float64,
    release_kcg_float64,
    copy_kcg_float64,
    sizeof(kcg_float64)
};

/****************************************************************
 ** kcg_int16 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimInt16VTable_defined
    extern struct SimTypeVTable *pSimInt16VTable;
  #else 
    struct SimTypeVTable *pSimInt16VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimInt16VTable;
#endif

int kcg_int16_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimInt16VTable != NULL
        && pSimInt16VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimInt16VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return predef_kcg_int16_to_string(*((kcg_int16*)pValue), pfnStrAppend, pStrObj);
}

int check_kcg_int16_string(const char *str, char **endptr)
{
    static kcg_int16 rTemp;
    return string_to_kcg_int16(str, (void*)&rTemp, endptr);
}

int string_to_kcg_int16(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimInt16VTable != NULL) {
        nRet = string_to_VTable(str, pSimInt16VTable, pValue, endptr);
    }
    if (nRet == 0) {
        nRet = predef_string_to_kcg_int16(str, (kcg_int16*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_int16_double_conversion_allowed()
{
    if (pSimInt16VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimInt16VTable);
    }
    return 1;
}

int kcg_int16_to_double(const void *pValue, double *nValue)
{
    if (pSimInt16VTable != NULL) {
        return VTable_to_double(pValue, pSimInt16VTable, nValue);
    }
    *nValue = (double)*((kcg_int16*)pValue);
    return 1;
}

int is_kcg_int16_long_conversion_allowed()
{
    if (pSimInt16VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimInt16VTable);
    }
    return 1;
}

int kcg_int16_to_long(const void *pValue, long *nValue)
{
    if (pSimInt16VTable != NULL) {
        return VTable_to_long(pValue, pSimInt16VTable, nValue);
    }
    *nValue = (long)*((kcg_int16*)pValue);
    return 1;
}

void compare_kcg_int16(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimInt16VTable != NULL
        && pSimInt16VTable->m_version >= Scv612
        && pSimInt16VTable->m_pfnCompare != NULL) {
        unitResult = pSimInt16VTable->m_pfnCompare(pResult, pValue1, pValue2);
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_kcg_int16(pResult, *((kcg_int16*)pValue1), *((kcg_int16*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_kcg_int16_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pfnStrAppend("I16", pStrObj);
}

int init_kcg_int16(void *pValue)
{
    *(kcg_int16*)pValue = 0;
    return 1;
}

int release_kcg_int16(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_kcg_int16(void *pToValue, const void *pFromValue)
{
    *((kcg_int16*)pToValue) = *((kcg_int16*)pFromValue);
    return 1;
}

SimTypeUtils _Type_kcg_int16_Utils = {
    kcg_int16_to_string,
    check_kcg_int16_string,
    string_to_kcg_int16,
    is_kcg_int16_double_conversion_allowed,
    kcg_int16_to_double,
    is_kcg_int16_long_conversion_allowed,
    kcg_int16_to_long,
    compare_kcg_int16,
    get_kcg_int16_signature,
    init_kcg_int16,
    release_kcg_int16,
    copy_kcg_int16,
    sizeof(kcg_int16)
};

/****************************************************************
 ** kcg_int32 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimInt32VTable_defined
    extern struct SimTypeVTable *pSimInt32VTable;
  #else 
    struct SimTypeVTable *pSimInt32VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimInt32VTable;
#endif

int kcg_int32_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimInt32VTable != NULL
        && pSimInt32VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimInt32VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return predef_kcg_int32_to_string(*((kcg_int32*)pValue), pfnStrAppend, pStrObj);
}

int check_kcg_int32_string(const char *str, char **endptr)
{
    static kcg_int32 rTemp;
    return string_to_kcg_int32(str, (void*)&rTemp, endptr);
}

int string_to_kcg_int32(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimInt32VTable != NULL) {
        nRet = string_to_VTable(str, pSimInt32VTable, pValue, endptr);
    }
    if (nRet == 0) {
        nRet = predef_string_to_kcg_int32(str, (kcg_int32*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_int32_double_conversion_allowed()
{
    if (pSimInt32VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimInt32VTable);
    }
    return 1;
}

int kcg_int32_to_double(const void *pValue, double *nValue)
{
    if (pSimInt32VTable != NULL) {
        return VTable_to_double(pValue, pSimInt32VTable, nValue);
    }
    *nValue = (double)*((kcg_int32*)pValue);
    return 1;
}

int is_kcg_int32_long_conversion_allowed()
{
    if (pSimInt32VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimInt32VTable);
    }
    return 1;
}

int kcg_int32_to_long(const void *pValue, long *nValue)
{
    if (pSimInt32VTable != NULL) {
        return VTable_to_long(pValue, pSimInt32VTable, nValue);
    }
    *nValue = (long)*((kcg_int32*)pValue);
    return 1;
}

void compare_kcg_int32(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimInt32VTable != NULL
        && pSimInt32VTable->m_version >= Scv612
        && pSimInt32VTable->m_pfnCompare != NULL) {
        unitResult = pSimInt32VTable->m_pfnCompare(pResult, pValue1, pValue2);
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_kcg_int32(pResult, *((kcg_int32*)pValue1), *((kcg_int32*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_kcg_int32_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pfnStrAppend("I32", pStrObj);
}

int init_kcg_int32(void *pValue)
{
    *(kcg_int32*)pValue = 0;
    return 1;
}

int release_kcg_int32(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_kcg_int32(void *pToValue, const void *pFromValue)
{
    *((kcg_int32*)pToValue) = *((kcg_int32*)pFromValue);
    return 1;
}

SimTypeUtils _Type_kcg_int32_Utils = {
    kcg_int32_to_string,
    check_kcg_int32_string,
    string_to_kcg_int32,
    is_kcg_int32_double_conversion_allowed,
    kcg_int32_to_double,
    is_kcg_int32_long_conversion_allowed,
    kcg_int32_to_long,
    compare_kcg_int32,
    get_kcg_int32_signature,
    init_kcg_int32,
    release_kcg_int32,
    copy_kcg_int32,
    sizeof(kcg_int32)
};

/****************************************************************
 ** kcg_int64 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimInt64VTable_defined
    extern struct SimTypeVTable *pSimInt64VTable;
  #else 
    struct SimTypeVTable *pSimInt64VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimInt64VTable;
#endif

int kcg_int64_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimInt64VTable != NULL
        && pSimInt64VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimInt64VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return predef_kcg_int64_to_string(*((kcg_int64*)pValue), pfnStrAppend, pStrObj);
}

int check_kcg_int64_string(const char *str, char **endptr)
{
    static kcg_int64 rTemp;
    return string_to_kcg_int64(str, (void*)&rTemp, endptr);
}

int string_to_kcg_int64(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimInt64VTable != NULL) {
        nRet = string_to_VTable(str, pSimInt64VTable, pValue, endptr);
    }
    if (nRet == 0) {
        nRet = predef_string_to_kcg_int64(str, (kcg_int64*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_int64_double_conversion_allowed()
{
    if (pSimInt64VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimInt64VTable);
    }
    return 1;
}

int kcg_int64_to_double(const void *pValue, double *nValue)
{
    if (pSimInt64VTable != NULL) {
        return VTable_to_double(pValue, pSimInt64VTable, nValue);
    }
    *nValue = (double)*((kcg_int64*)pValue);
    return 1;
}

int is_kcg_int64_long_conversion_allowed()
{
    if (pSimInt64VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimInt64VTable);
    }
    return 1;
}

int kcg_int64_to_long(const void *pValue, long *nValue)
{
    if (pSimInt64VTable != NULL) {
        return VTable_to_long(pValue, pSimInt64VTable, nValue);
    }
    *nValue = (long)*((kcg_int64*)pValue);
    return 1;
}

void compare_kcg_int64(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimInt64VTable != NULL
        && pSimInt64VTable->m_version >= Scv612
        && pSimInt64VTable->m_pfnCompare != NULL) {
        unitResult = pSimInt64VTable->m_pfnCompare(pResult, pValue1, pValue2);
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_kcg_int64(pResult, *((kcg_int64*)pValue1), *((kcg_int64*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_kcg_int64_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pfnStrAppend("I64", pStrObj);
}

int init_kcg_int64(void *pValue)
{
    *(kcg_int64*)pValue = 0;
    return 1;
}

int release_kcg_int64(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_kcg_int64(void *pToValue, const void *pFromValue)
{
    *((kcg_int64*)pToValue) = *((kcg_int64*)pFromValue);
    return 1;
}

SimTypeUtils _Type_kcg_int64_Utils = {
    kcg_int64_to_string,
    check_kcg_int64_string,
    string_to_kcg_int64,
    is_kcg_int64_double_conversion_allowed,
    kcg_int64_to_double,
    is_kcg_int64_long_conversion_allowed,
    kcg_int64_to_long,
    compare_kcg_int64,
    get_kcg_int64_signature,
    init_kcg_int64,
    release_kcg_int64,
    copy_kcg_int64,
    sizeof(kcg_int64)
};

/****************************************************************
 ** kcg_int8 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimInt8VTable_defined
    extern struct SimTypeVTable *pSimInt8VTable;
  #else 
    struct SimTypeVTable *pSimInt8VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimInt8VTable;
#endif

int kcg_int8_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimInt8VTable != NULL
        && pSimInt8VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimInt8VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return predef_kcg_int8_to_string(*((kcg_int8*)pValue), pfnStrAppend, pStrObj);
}

int check_kcg_int8_string(const char *str, char **endptr)
{
    static kcg_int8 rTemp;
    return string_to_kcg_int8(str, (void*)&rTemp, endptr);
}

int string_to_kcg_int8(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimInt8VTable != NULL) {
        nRet = string_to_VTable(str, pSimInt8VTable, pValue, endptr);
    }
    if (nRet == 0) {
        nRet = predef_string_to_kcg_int8(str, (kcg_int8*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_int8_double_conversion_allowed()
{
    if (pSimInt8VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimInt8VTable);
    }
    return 1;
}

int kcg_int8_to_double(const void *pValue, double *nValue)
{
    if (pSimInt8VTable != NULL) {
        return VTable_to_double(pValue, pSimInt8VTable, nValue);
    }
    *nValue = (double)*((kcg_int8*)pValue);
    return 1;
}

int is_kcg_int8_long_conversion_allowed()
{
    if (pSimInt8VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimInt8VTable);
    }
    return 1;
}

int kcg_int8_to_long(const void *pValue, long *nValue)
{
    if (pSimInt8VTable != NULL) {
        return VTable_to_long(pValue, pSimInt8VTable, nValue);
    }
    *nValue = (long)*((kcg_int8*)pValue);
    return 1;
}

void compare_kcg_int8(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimInt8VTable != NULL
        && pSimInt8VTable->m_version >= Scv612
        && pSimInt8VTable->m_pfnCompare != NULL) {
        unitResult = pSimInt8VTable->m_pfnCompare(pResult, pValue1, pValue2);
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_kcg_int8(pResult, *((kcg_int8*)pValue1), *((kcg_int8*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_kcg_int8_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pfnStrAppend("I8", pStrObj);
}

int init_kcg_int8(void *pValue)
{
    *(kcg_int8*)pValue = 0;
    return 1;
}

int release_kcg_int8(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_kcg_int8(void *pToValue, const void *pFromValue)
{
    *((kcg_int8*)pToValue) = *((kcg_int8*)pFromValue);
    return 1;
}

SimTypeUtils _Type_kcg_int8_Utils = {
    kcg_int8_to_string,
    check_kcg_int8_string,
    string_to_kcg_int8,
    is_kcg_int8_double_conversion_allowed,
    kcg_int8_to_double,
    is_kcg_int8_long_conversion_allowed,
    kcg_int8_to_long,
    compare_kcg_int8,
    get_kcg_int8_signature,
    init_kcg_int8,
    release_kcg_int8,
    copy_kcg_int8,
    sizeof(kcg_int8)
};

/****************************************************************
 ** kcg_size 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimSizeVTable_defined
    extern struct SimTypeVTable *pSimSizeVTable;
  #else 
    struct SimTypeVTable *pSimSizeVTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimSizeVTable;
#endif

int kcg_size_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimSizeVTable != NULL
        && pSimSizeVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        if (pSimSizeVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> variable to VTable function: */
            return pfnStrAppend(*(char**)pSimSizeVTable->m_pfnToType(SptString, pValue), pStrObj);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            size_t value = (size_t)(*(const kcg_size*)pValue);
            return pfnStrAppend(*(char**)pSimSizeVTable->m_pfnToType(SptString, &value), pStrObj);
        }
    }
    return predef_kcg_size_to_string(*((kcg_size*)pValue), pfnStrAppend, pStrObj);
}

int check_kcg_size_string(const char *str, char **endptr)
{
    static kcg_size rTemp;
    return string_to_kcg_size(str, (void*)&rTemp, endptr);
}

int string_to_kcg_size(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    static size_t rTemp;
    skip_whitespace(str);
    if (pSimSizeVTable != NULL) {
        if (pSimSizeVTable->m_version >= Scv65) {
            /* R15 and higher: VTable function must return a kcg_<type> *variable: */
            nRet = string_to_VTable(str, pSimSizeVTable, pValue, endptr);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            nRet = string_to_VTable(str, pSimSizeVTable, &rTemp, endptr);
            if (nRet != 0) {
                *(kcg_size*)pValue = (kcg_size)rTemp;
            }
        }
    }
    if (nRet == 0) {
        nRet = predef_string_to_kcg_size(str, (kcg_size*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_size_double_conversion_allowed()
{
    if (pSimSizeVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimSizeVTable);
    }
    return 1;
}

int kcg_size_to_double(const void *pValue, double *nValue)
{
    if (pSimSizeVTable != NULL) {
        if (pSimSizeVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            return VTable_to_double(pValue, pSimSizeVTable, nValue);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            size_t value = (size_t)(*(const kcg_size*)pValue);
            return VTable_to_double(&value, pSimSizeVTable, nValue);
        }
    }
    *nValue = (double)*((kcg_size*)pValue);
    return 1;
}

int is_kcg_size_long_conversion_allowed()
{
    if (pSimSizeVTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimSizeVTable);
    }
    return 1;
}

int kcg_size_to_long(const void *pValue, long *nValue)
{
    if (pSimSizeVTable != NULL) {
        if (pSimSizeVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            return VTable_to_long(pValue, pSimSizeVTable, nValue);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            size_t value = (size_t)(*(const kcg_size*)pValue);
            return VTable_to_long(&value, pSimSizeVTable, nValue);
        }
    }
    *nValue = (long)*((kcg_size*)pValue);
    return 1;
}

void compare_kcg_size(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimSizeVTable != NULL
        && pSimSizeVTable->m_version >= Scv612
        && pSimSizeVTable->m_pfnCompare != NULL) {
        if (pSimSizeVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            unitResult = pSimSizeVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            size_t value1 = (size_t)(*(const kcg_size*)pValue1);
            size_t value2 = (size_t)(*(const kcg_size*)pValue2);
            pSimSizeVTable->m_pfnCompare(&unitResult, &value1, &value2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_kcg_size(pResult, *((kcg_size*)pValue1), *((kcg_size*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_kcg_size_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pfnStrAppend("S", pStrObj);
}

int init_kcg_size(void *pValue)
{
    *(kcg_size*)pValue = 0;
    return 1;
}

int release_kcg_size(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_kcg_size(void *pToValue, const void *pFromValue)
{
    *((kcg_size*)pToValue) = *((kcg_size*)pFromValue);
    return 1;
}

SimTypeUtils _Type_kcg_size_Utils = {
    kcg_size_to_string,
    check_kcg_size_string,
    string_to_kcg_size,
    is_kcg_size_double_conversion_allowed,
    kcg_size_to_double,
    is_kcg_size_long_conversion_allowed,
    kcg_size_to_long,
    compare_kcg_size,
    get_kcg_size_signature,
    init_kcg_size,
    release_kcg_size,
    copy_kcg_size,
    sizeof(kcg_size)
};

/****************************************************************
 ** kcg_uint16 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimUint16VTable_defined
    extern struct SimTypeVTable *pSimUint16VTable;
  #else 
    struct SimTypeVTable *pSimUint16VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimUint16VTable;
#endif

int kcg_uint16_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimUint16VTable != NULL
        && pSimUint16VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimUint16VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return predef_kcg_uint16_to_string(*((kcg_uint16*)pValue), pfnStrAppend, pStrObj);
}

int check_kcg_uint16_string(const char *str, char **endptr)
{
    static kcg_uint16 rTemp;
    return string_to_kcg_uint16(str, (void*)&rTemp, endptr);
}

int string_to_kcg_uint16(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimUint16VTable != NULL) {
        nRet = string_to_VTable(str, pSimUint16VTable, pValue, endptr);
    }
    if (nRet == 0) {
        nRet = predef_string_to_kcg_uint16(str, (kcg_uint16*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_uint16_double_conversion_allowed()
{
    if (pSimUint16VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimUint16VTable);
    }
    return 1;
}

int kcg_uint16_to_double(const void *pValue, double *nValue)
{
    if (pSimUint16VTable != NULL) {
        return VTable_to_double(pValue, pSimUint16VTable, nValue);
    }
    *nValue = (double)*((kcg_uint16*)pValue);
    return 1;
}

int is_kcg_uint16_long_conversion_allowed()
{
    if (pSimUint16VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimUint16VTable);
    }
    return 1;
}

int kcg_uint16_to_long(const void *pValue, long *nValue)
{
    if (pSimUint16VTable != NULL) {
        return VTable_to_long(pValue, pSimUint16VTable, nValue);
    }
    *nValue = (long)*((kcg_uint16*)pValue);
    return 1;
}

void compare_kcg_uint16(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimUint16VTable != NULL
        && pSimUint16VTable->m_version >= Scv612
        && pSimUint16VTable->m_pfnCompare != NULL) {
        unitResult = pSimUint16VTable->m_pfnCompare(pResult, pValue1, pValue2);
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_kcg_uint16(pResult, *((kcg_uint16*)pValue1), *((kcg_uint16*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_kcg_uint16_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pfnStrAppend("UI16", pStrObj);
}

int init_kcg_uint16(void *pValue)
{
    *(kcg_uint16*)pValue = 0;
    return 1;
}

int release_kcg_uint16(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_kcg_uint16(void *pToValue, const void *pFromValue)
{
    *((kcg_uint16*)pToValue) = *((kcg_uint16*)pFromValue);
    return 1;
}

SimTypeUtils _Type_kcg_uint16_Utils = {
    kcg_uint16_to_string,
    check_kcg_uint16_string,
    string_to_kcg_uint16,
    is_kcg_uint16_double_conversion_allowed,
    kcg_uint16_to_double,
    is_kcg_uint16_long_conversion_allowed,
    kcg_uint16_to_long,
    compare_kcg_uint16,
    get_kcg_uint16_signature,
    init_kcg_uint16,
    release_kcg_uint16,
    copy_kcg_uint16,
    sizeof(kcg_uint16)
};

/****************************************************************
 ** kcg_uint32 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimUint32VTable_defined
    extern struct SimTypeVTable *pSimUint32VTable;
  #else 
    struct SimTypeVTable *pSimUint32VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimUint32VTable;
#endif

int kcg_uint32_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimUint32VTable != NULL
        && pSimUint32VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimUint32VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return predef_kcg_uint32_to_string(*((kcg_uint32*)pValue), pfnStrAppend, pStrObj);
}

int check_kcg_uint32_string(const char *str, char **endptr)
{
    static kcg_uint32 rTemp;
    return string_to_kcg_uint32(str, (void*)&rTemp, endptr);
}

int string_to_kcg_uint32(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimUint32VTable != NULL) {
        nRet = string_to_VTable(str, pSimUint32VTable, pValue, endptr);
    }
    if (nRet == 0) {
        nRet = predef_string_to_kcg_uint32(str, (kcg_uint32*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_uint32_double_conversion_allowed()
{
    if (pSimUint32VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimUint32VTable);
    }
    return 1;
}

int kcg_uint32_to_double(const void *pValue, double *nValue)
{
    if (pSimUint32VTable != NULL) {
        return VTable_to_double(pValue, pSimUint32VTable, nValue);
    }
    *nValue = (double)*((kcg_uint32*)pValue);
    return 1;
}

int is_kcg_uint32_long_conversion_allowed()
{
    if (pSimUint32VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimUint32VTable);
    }
    return 1;
}

int kcg_uint32_to_long(const void *pValue, long *nValue)
{
    if (pSimUint32VTable != NULL) {
        return VTable_to_long(pValue, pSimUint32VTable, nValue);
    }
    *nValue = (long)*((kcg_uint32*)pValue);
    return 1;
}

void compare_kcg_uint32(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimUint32VTable != NULL
        && pSimUint32VTable->m_version >= Scv612
        && pSimUint32VTable->m_pfnCompare != NULL) {
        unitResult = pSimUint32VTable->m_pfnCompare(pResult, pValue1, pValue2);
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_kcg_uint32(pResult, *((kcg_uint32*)pValue1), *((kcg_uint32*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_kcg_uint32_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pfnStrAppend("UI32", pStrObj);
}

int init_kcg_uint32(void *pValue)
{
    *(kcg_uint32*)pValue = 0;
    return 1;
}

int release_kcg_uint32(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_kcg_uint32(void *pToValue, const void *pFromValue)
{
    *((kcg_uint32*)pToValue) = *((kcg_uint32*)pFromValue);
    return 1;
}

SimTypeUtils _Type_kcg_uint32_Utils = {
    kcg_uint32_to_string,
    check_kcg_uint32_string,
    string_to_kcg_uint32,
    is_kcg_uint32_double_conversion_allowed,
    kcg_uint32_to_double,
    is_kcg_uint32_long_conversion_allowed,
    kcg_uint32_to_long,
    compare_kcg_uint32,
    get_kcg_uint32_signature,
    init_kcg_uint32,
    release_kcg_uint32,
    copy_kcg_uint32,
    sizeof(kcg_uint32)
};

/****************************************************************
 ** kcg_uint64 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimUint64VTable_defined
    extern struct SimTypeVTable *pSimUint64VTable;
  #else 
    struct SimTypeVTable *pSimUint64VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimUint64VTable;
#endif

int kcg_uint64_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimUint64VTable != NULL
        && pSimUint64VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimUint64VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return predef_kcg_uint64_to_string(*((kcg_uint64*)pValue), pfnStrAppend, pStrObj);
}

int check_kcg_uint64_string(const char *str, char **endptr)
{
    static kcg_uint64 rTemp;
    return string_to_kcg_uint64(str, (void*)&rTemp, endptr);
}

int string_to_kcg_uint64(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimUint64VTable != NULL) {
        nRet = string_to_VTable(str, pSimUint64VTable, pValue, endptr);
    }
    if (nRet == 0) {
        nRet = predef_string_to_kcg_uint64(str, (kcg_uint64*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_uint64_double_conversion_allowed()
{
    if (pSimUint64VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimUint64VTable);
    }
    return 1;
}

int kcg_uint64_to_double(const void *pValue, double *nValue)
{
    if (pSimUint64VTable != NULL) {
        return VTable_to_double(pValue, pSimUint64VTable, nValue);
    }
    *nValue = (double)*((kcg_uint64*)pValue);
    return 1;
}

int is_kcg_uint64_long_conversion_allowed()
{
    if (pSimUint64VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimUint64VTable);
    }
    return 1;
}

int kcg_uint64_to_long(const void *pValue, long *nValue)
{
    if (pSimUint64VTable != NULL) {
        return VTable_to_long(pValue, pSimUint64VTable, nValue);
    }
    *nValue = (long)*((kcg_uint64*)pValue);
    return 1;
}

void compare_kcg_uint64(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimUint64VTable != NULL
        && pSimUint64VTable->m_version >= Scv612
        && pSimUint64VTable->m_pfnCompare != NULL) {
        unitResult = pSimUint64VTable->m_pfnCompare(pResult, pValue1, pValue2);
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_kcg_uint64(pResult, *((kcg_uint64*)pValue1), *((kcg_uint64*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_kcg_uint64_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pfnStrAppend("UI64", pStrObj);
}

int init_kcg_uint64(void *pValue)
{
    *(kcg_uint64*)pValue = 0;
    return 1;
}

int release_kcg_uint64(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_kcg_uint64(void *pToValue, const void *pFromValue)
{
    *((kcg_uint64*)pToValue) = *((kcg_uint64*)pFromValue);
    return 1;
}

SimTypeUtils _Type_kcg_uint64_Utils = {
    kcg_uint64_to_string,
    check_kcg_uint64_string,
    string_to_kcg_uint64,
    is_kcg_uint64_double_conversion_allowed,
    kcg_uint64_to_double,
    is_kcg_uint64_long_conversion_allowed,
    kcg_uint64_to_long,
    compare_kcg_uint64,
    get_kcg_uint64_signature,
    init_kcg_uint64,
    release_kcg_uint64,
    copy_kcg_uint64,
    sizeof(kcg_uint64)
};

/****************************************************************
 ** kcg_uint8 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimUint8VTable_defined
    extern struct SimTypeVTable *pSimUint8VTable;
  #else 
    struct SimTypeVTable *pSimUint8VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimUint8VTable;
#endif

int kcg_uint8_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimUint8VTable != NULL
        && pSimUint8VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimUint8VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return predef_kcg_uint8_to_string(*((kcg_uint8*)pValue), pfnStrAppend, pStrObj);
}

int check_kcg_uint8_string(const char *str, char **endptr)
{
    static kcg_uint8 rTemp;
    return string_to_kcg_uint8(str, (void*)&rTemp, endptr);
}

int string_to_kcg_uint8(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimUint8VTable != NULL) {
        nRet = string_to_VTable(str, pSimUint8VTable, pValue, endptr);
    }
    if (nRet == 0) {
        nRet = predef_string_to_kcg_uint8(str, (kcg_uint8*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_uint8_double_conversion_allowed()
{
    if (pSimUint8VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimUint8VTable);
    }
    return 1;
}

int kcg_uint8_to_double(const void *pValue, double *nValue)
{
    if (pSimUint8VTable != NULL) {
        return VTable_to_double(pValue, pSimUint8VTable, nValue);
    }
    *nValue = (double)*((kcg_uint8*)pValue);
    return 1;
}

int is_kcg_uint8_long_conversion_allowed()
{
    if (pSimUint8VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimUint8VTable);
    }
    return 1;
}

int kcg_uint8_to_long(const void *pValue, long *nValue)
{
    if (pSimUint8VTable != NULL) {
        return VTable_to_long(pValue, pSimUint8VTable, nValue);
    }
    *nValue = (long)*((kcg_uint8*)pValue);
    return 1;
}

void compare_kcg_uint8(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimUint8VTable != NULL
        && pSimUint8VTable->m_version >= Scv612
        && pSimUint8VTable->m_pfnCompare != NULL) {
        unitResult = pSimUint8VTable->m_pfnCompare(pResult, pValue1, pValue2);
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_kcg_uint8(pResult, *((kcg_uint8*)pValue1), *((kcg_uint8*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_kcg_uint8_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pfnStrAppend("UI8", pStrObj);
}

int init_kcg_uint8(void *pValue)
{
    *(kcg_uint8*)pValue = 0;
    return 1;
}

int release_kcg_uint8(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_kcg_uint8(void *pToValue, const void *pFromValue)
{
    *((kcg_uint8*)pToValue) = *((kcg_uint8*)pFromValue);
    return 1;
}

SimTypeUtils _Type_kcg_uint8_Utils = {
    kcg_uint8_to_string,
    check_kcg_uint8_string,
    string_to_kcg_uint8,
    is_kcg_uint8_double_conversion_allowed,
    kcg_uint8_to_double,
    is_kcg_uint8_long_conversion_allowed,
    kcg_uint8_to_long,
    compare_kcg_uint8,
    get_kcg_uint8_signature,
    init_kcg_uint8,
    release_kcg_uint8,
    copy_kcg_uint8,
    sizeof(kcg_uint8)
};

/****************************************************************
 ** SSM_ST_SM1 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimSSM_ST_SM1VTable_defined
    extern struct SimTypeVTable *pSimSSM_ST_SM1VTable;
  #else 
    struct SimTypeVTable *pSimSSM_ST_SM1VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimSSM_ST_SM1VTable;
#endif

static SimEnumValUtils SSM_ST_SM1_values[] = {
    { "Off", _6_SSM_st_Off_SM1},
    { "Enabled", _7_SSM_st_Enabled_SM1},
};
const int SSM_ST_SM1_nb_values = 2;

int SSM_ST_SM1_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimSSM_ST_SM1VTable != NULL
        && pSimSSM_ST_SM1VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimSSM_ST_SM1VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return pConverter->m_pfnEnumToString(*(SSM_ST_SM1*)pValue, SSM_ST_SM1_values, SSM_ST_SM1_nb_values, pfnStrAppend, pStrObj); 
}

int check_SSM_ST_SM1_string(const char *str, char **endptr)
{
    static SSM_ST_SM1 rTemp;
    return string_to_SSM_ST_SM1(str, (void*)&rTemp, endptr);
}

int string_to_SSM_ST_SM1(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimSSM_ST_SM1VTable != NULL) {
        nRet = string_to_VTable(str, pSimSSM_ST_SM1VTable, pValue, endptr);
    }
    if (nRet == 0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, SSM_ST_SM1_values, SSM_ST_SM1_nb_values, endptr);
        if (pValue != NULL && nRet != 0)
            *(SSM_ST_SM1*)pValue = (SSM_ST_SM1)nTemp;
    }
    return nRet;
}

int is_SSM_ST_SM1_double_conversion_allowed()
{
    if (pSimSSM_ST_SM1VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimSSM_ST_SM1VTable);
    }
    return 1;
}

int SSM_ST_SM1_to_double(const void *pValue, double *nValue)
{
    if (pSimSSM_ST_SM1VTable != NULL) {
        return VTable_to_double(pValue, pSimSSM_ST_SM1VTable, nValue);
    }
    *nValue = (double)*((SSM_ST_SM1*)pValue);
    return 1;
}

int is_SSM_ST_SM1_long_conversion_allowed()
{
    if (pSimSSM_ST_SM1VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimSSM_ST_SM1VTable);
    }
    return 1;
}

int SSM_ST_SM1_to_long(const void *pValue, long *nValue)
{
    if (pSimSSM_ST_SM1VTable != NULL) {
        return VTable_to_long(pValue, pSimSSM_ST_SM1VTable, nValue);
    }
    *nValue = (long)*((SSM_ST_SM1*)pValue);
    return 1;
}

void compare_SSM_ST_SM1(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimSSM_ST_SM1VTable != NULL
        && pSimSSM_ST_SM1VTable->m_version >= Scv612
        && pSimSSM_ST_SM1VTable->m_pfnCompare != NULL) {
        if (pSimSSM_ST_SM1VTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSimSSM_ST_SM1VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSimSSM_ST_SM1VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(SSM_ST_SM1*)pValue1), (int)(*(SSM_ST_SM1*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_SSM_ST_SM1_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pConverter->m_pfnGetEnumSignature(SSM_ST_SM1_values, SSM_ST_SM1_nb_values, pfnStrAppend, pStrObj);
}

int init_SSM_ST_SM1(void *pValue)
{
    *(SSM_ST_SM1*)pValue = _6_SSM_st_Off_SM1;
    return 1;
}

int release_SSM_ST_SM1(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_SSM_ST_SM1(void *pToValue, const void *pFromValue)
{
    *((SSM_ST_SM1*)pToValue) = *((SSM_ST_SM1*)pFromValue);
    return 1;
}

SimTypeUtils _Type_SSM_ST_SM1_Utils = {
    SSM_ST_SM1_to_string,
    check_SSM_ST_SM1_string,
    string_to_SSM_ST_SM1,
    is_SSM_ST_SM1_double_conversion_allowed,
    SSM_ST_SM1_to_double,
    is_SSM_ST_SM1_long_conversion_allowed,
    SSM_ST_SM1_to_long,
    compare_SSM_ST_SM1,
    get_SSM_ST_SM1_signature,
    init_SSM_ST_SM1,
    release_SSM_ST_SM1,
    copy_SSM_ST_SM1,
    sizeof(SSM_ST_SM1)
};

/****************************************************************
 ** SSM_ST_SM2_Enabled_SM1 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimSSM_ST_SM2_Enabled_SM1VTable_defined
    extern struct SimTypeVTable *pSimSSM_ST_SM2_Enabled_SM1VTable;
  #else 
    struct SimTypeVTable *pSimSSM_ST_SM2_Enabled_SM1VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimSSM_ST_SM2_Enabled_SM1VTable;
#endif

static SimEnumValUtils SSM_ST_SM2_Enabled_SM1_values[] = {
    { "Active", _8_SSM_st_Active_SM2_Enabled_SM1},
    { "Standby", SSM_st_Standby_SM2_Enabled_SM1},
};
const int SSM_ST_SM2_Enabled_SM1_nb_values = 2;

int SSM_ST_SM2_Enabled_SM1_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimSSM_ST_SM2_Enabled_SM1VTable != NULL
        && pSimSSM_ST_SM2_Enabled_SM1VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimSSM_ST_SM2_Enabled_SM1VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return pConverter->m_pfnEnumToString(*(SSM_ST_SM2_Enabled_SM1*)pValue, SSM_ST_SM2_Enabled_SM1_values, SSM_ST_SM2_Enabled_SM1_nb_values, pfnStrAppend, pStrObj); 
}

int check_SSM_ST_SM2_Enabled_SM1_string(const char *str, char **endptr)
{
    static SSM_ST_SM2_Enabled_SM1 rTemp;
    return string_to_SSM_ST_SM2_Enabled_SM1(str, (void*)&rTemp, endptr);
}

int string_to_SSM_ST_SM2_Enabled_SM1(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimSSM_ST_SM2_Enabled_SM1VTable != NULL) {
        nRet = string_to_VTable(str, pSimSSM_ST_SM2_Enabled_SM1VTable, pValue, endptr);
    }
    if (nRet == 0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, SSM_ST_SM2_Enabled_SM1_values, SSM_ST_SM2_Enabled_SM1_nb_values, endptr);
        if (pValue != NULL && nRet != 0)
            *(SSM_ST_SM2_Enabled_SM1*)pValue = (SSM_ST_SM2_Enabled_SM1)nTemp;
    }
    return nRet;
}

int is_SSM_ST_SM2_Enabled_SM1_double_conversion_allowed()
{
    if (pSimSSM_ST_SM2_Enabled_SM1VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimSSM_ST_SM2_Enabled_SM1VTable);
    }
    return 1;
}

int SSM_ST_SM2_Enabled_SM1_to_double(const void *pValue, double *nValue)
{
    if (pSimSSM_ST_SM2_Enabled_SM1VTable != NULL) {
        return VTable_to_double(pValue, pSimSSM_ST_SM2_Enabled_SM1VTable, nValue);
    }
    *nValue = (double)*((SSM_ST_SM2_Enabled_SM1*)pValue);
    return 1;
}

int is_SSM_ST_SM2_Enabled_SM1_long_conversion_allowed()
{
    if (pSimSSM_ST_SM2_Enabled_SM1VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimSSM_ST_SM2_Enabled_SM1VTable);
    }
    return 1;
}

int SSM_ST_SM2_Enabled_SM1_to_long(const void *pValue, long *nValue)
{
    if (pSimSSM_ST_SM2_Enabled_SM1VTable != NULL) {
        return VTable_to_long(pValue, pSimSSM_ST_SM2_Enabled_SM1VTable, nValue);
    }
    *nValue = (long)*((SSM_ST_SM2_Enabled_SM1*)pValue);
    return 1;
}

void compare_SSM_ST_SM2_Enabled_SM1(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimSSM_ST_SM2_Enabled_SM1VTable != NULL
        && pSimSSM_ST_SM2_Enabled_SM1VTable->m_version >= Scv612
        && pSimSSM_ST_SM2_Enabled_SM1VTable->m_pfnCompare != NULL) {
        if (pSimSSM_ST_SM2_Enabled_SM1VTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSimSSM_ST_SM2_Enabled_SM1VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSimSSM_ST_SM2_Enabled_SM1VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(SSM_ST_SM2_Enabled_SM1*)pValue1), (int)(*(SSM_ST_SM2_Enabled_SM1*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_SSM_ST_SM2_Enabled_SM1_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pConverter->m_pfnGetEnumSignature(SSM_ST_SM2_Enabled_SM1_values, SSM_ST_SM2_Enabled_SM1_nb_values, pfnStrAppend, pStrObj);
}

int init_SSM_ST_SM2_Enabled_SM1(void *pValue)
{
    *(SSM_ST_SM2_Enabled_SM1*)pValue = _8_SSM_st_Active_SM2_Enabled_SM1;
    return 1;
}

int release_SSM_ST_SM2_Enabled_SM1(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_SSM_ST_SM2_Enabled_SM1(void *pToValue, const void *pFromValue)
{
    *((SSM_ST_SM2_Enabled_SM1*)pToValue) = *((SSM_ST_SM2_Enabled_SM1*)pFromValue);
    return 1;
}

SimTypeUtils _Type_SSM_ST_SM2_Enabled_SM1_Utils = {
    SSM_ST_SM2_Enabled_SM1_to_string,
    check_SSM_ST_SM2_Enabled_SM1_string,
    string_to_SSM_ST_SM2_Enabled_SM1,
    is_SSM_ST_SM2_Enabled_SM1_double_conversion_allowed,
    SSM_ST_SM2_Enabled_SM1_to_double,
    is_SSM_ST_SM2_Enabled_SM1_long_conversion_allowed,
    SSM_ST_SM2_Enabled_SM1_to_long,
    compare_SSM_ST_SM2_Enabled_SM1,
    get_SSM_ST_SM2_Enabled_SM1_signature,
    init_SSM_ST_SM2_Enabled_SM1,
    release_SSM_ST_SM2_Enabled_SM1,
    copy_SSM_ST_SM2_Enabled_SM1,
    sizeof(SSM_ST_SM2_Enabled_SM1)
};

/****************************************************************
 ** SSM_ST_SM3_Active_SM2_Enabled_SM1 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable_defined
    extern struct SimTypeVTable *pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable;
  #else 
    struct SimTypeVTable *pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable;
#endif

static SimEnumValUtils SSM_ST_SM3_Active_SM2_Enabled_SM1_values[] = {
    { "On", SSM_st_On_SM3_Active_SM2_Enabled_SM1},
    { "StandBy", SSM_st_StandBy_SM3_Active_SM2_Enabled_SM1},
};
const int SSM_ST_SM3_Active_SM2_Enabled_SM1_nb_values = 2;

int SSM_ST_SM3_Active_SM2_Enabled_SM1_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable != NULL
        && pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return pConverter->m_pfnEnumToString(*(SSM_ST_SM3_Active_SM2_Enabled_SM1*)pValue, SSM_ST_SM3_Active_SM2_Enabled_SM1_values, SSM_ST_SM3_Active_SM2_Enabled_SM1_nb_values, pfnStrAppend, pStrObj); 
}

int check_SSM_ST_SM3_Active_SM2_Enabled_SM1_string(const char *str, char **endptr)
{
    static SSM_ST_SM3_Active_SM2_Enabled_SM1 rTemp;
    return string_to_SSM_ST_SM3_Active_SM2_Enabled_SM1(str, (void*)&rTemp, endptr);
}

int string_to_SSM_ST_SM3_Active_SM2_Enabled_SM1(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable != NULL) {
        nRet = string_to_VTable(str, pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable, pValue, endptr);
    }
    if (nRet == 0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, SSM_ST_SM3_Active_SM2_Enabled_SM1_values, SSM_ST_SM3_Active_SM2_Enabled_SM1_nb_values, endptr);
        if (pValue != NULL && nRet != 0)
            *(SSM_ST_SM3_Active_SM2_Enabled_SM1*)pValue = (SSM_ST_SM3_Active_SM2_Enabled_SM1)nTemp;
    }
    return nRet;
}

int is_SSM_ST_SM3_Active_SM2_Enabled_SM1_double_conversion_allowed()
{
    if (pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable);
    }
    return 1;
}

int SSM_ST_SM3_Active_SM2_Enabled_SM1_to_double(const void *pValue, double *nValue)
{
    if (pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable != NULL) {
        return VTable_to_double(pValue, pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable, nValue);
    }
    *nValue = (double)*((SSM_ST_SM3_Active_SM2_Enabled_SM1*)pValue);
    return 1;
}

int is_SSM_ST_SM3_Active_SM2_Enabled_SM1_long_conversion_allowed()
{
    if (pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable);
    }
    return 1;
}

int SSM_ST_SM3_Active_SM2_Enabled_SM1_to_long(const void *pValue, long *nValue)
{
    if (pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable != NULL) {
        return VTable_to_long(pValue, pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable, nValue);
    }
    *nValue = (long)*((SSM_ST_SM3_Active_SM2_Enabled_SM1*)pValue);
    return 1;
}

void compare_SSM_ST_SM3_Active_SM2_Enabled_SM1(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable != NULL
        && pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable->m_version >= Scv612
        && pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable->m_pfnCompare != NULL) {
        if (pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSimSSM_ST_SM3_Active_SM2_Enabled_SM1VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(SSM_ST_SM3_Active_SM2_Enabled_SM1*)pValue1), (int)(*(SSM_ST_SM3_Active_SM2_Enabled_SM1*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_SSM_ST_SM3_Active_SM2_Enabled_SM1_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pConverter->m_pfnGetEnumSignature(SSM_ST_SM3_Active_SM2_Enabled_SM1_values, SSM_ST_SM3_Active_SM2_Enabled_SM1_nb_values, pfnStrAppend, pStrObj);
}

int init_SSM_ST_SM3_Active_SM2_Enabled_SM1(void *pValue)
{
    *(SSM_ST_SM3_Active_SM2_Enabled_SM1*)pValue = SSM_st_On_SM3_Active_SM2_Enabled_SM1;
    return 1;
}

int release_SSM_ST_SM3_Active_SM2_Enabled_SM1(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_SSM_ST_SM3_Active_SM2_Enabled_SM1(void *pToValue, const void *pFromValue)
{
    *((SSM_ST_SM3_Active_SM2_Enabled_SM1*)pToValue) = *((SSM_ST_SM3_Active_SM2_Enabled_SM1*)pFromValue);
    return 1;
}

SimTypeUtils _Type_SSM_ST_SM3_Active_SM2_Enabled_SM1_Utils = {
    SSM_ST_SM3_Active_SM2_Enabled_SM1_to_string,
    check_SSM_ST_SM3_Active_SM2_Enabled_SM1_string,
    string_to_SSM_ST_SM3_Active_SM2_Enabled_SM1,
    is_SSM_ST_SM3_Active_SM2_Enabled_SM1_double_conversion_allowed,
    SSM_ST_SM3_Active_SM2_Enabled_SM1_to_double,
    is_SSM_ST_SM3_Active_SM2_Enabled_SM1_long_conversion_allowed,
    SSM_ST_SM3_Active_SM2_Enabled_SM1_to_long,
    compare_SSM_ST_SM3_Active_SM2_Enabled_SM1,
    get_SSM_ST_SM3_Active_SM2_Enabled_SM1_signature,
    init_SSM_ST_SM3_Active_SM2_Enabled_SM1,
    release_SSM_ST_SM3_Active_SM2_Enabled_SM1,
    copy_SSM_ST_SM3_Active_SM2_Enabled_SM1,
    sizeof(SSM_ST_SM3_Active_SM2_Enabled_SM1)
};

/****************************************************************
 ** SSM_TR_SM1 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimSSM_TR_SM1VTable_defined
    extern struct SimTypeVTable *pSimSSM_TR_SM1VTable;
  #else 
    struct SimTypeVTable *pSimSSM_TR_SM1VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimSSM_TR_SM1VTable;
#endif

static SimEnumValUtils SSM_TR_SM1_values[] = {
    { "SSM_TR_no_trans_SM1", SSM_TR_no_trans_SM1},
    { "SSM_TR_Off_Enabled_1_Off_SM1", SSM_TR_Off_Enabled_1_Off_SM1},
    { "SSM_TR_Enabled_Off_1_Enabled_SM1", SSM_TR_Enabled_Off_1_Enabled_SM1},
};
const int SSM_TR_SM1_nb_values = 3;

int SSM_TR_SM1_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimSSM_TR_SM1VTable != NULL
        && pSimSSM_TR_SM1VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimSSM_TR_SM1VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return pConverter->m_pfnEnumToString(*(SSM_TR_SM1*)pValue, SSM_TR_SM1_values, SSM_TR_SM1_nb_values, pfnStrAppend, pStrObj); 
}

int check_SSM_TR_SM1_string(const char *str, char **endptr)
{
    static SSM_TR_SM1 rTemp;
    return string_to_SSM_TR_SM1(str, (void*)&rTemp, endptr);
}

int string_to_SSM_TR_SM1(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimSSM_TR_SM1VTable != NULL) {
        nRet = string_to_VTable(str, pSimSSM_TR_SM1VTable, pValue, endptr);
    }
    if (nRet == 0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, SSM_TR_SM1_values, SSM_TR_SM1_nb_values, endptr);
        if (pValue != NULL && nRet != 0)
            *(SSM_TR_SM1*)pValue = (SSM_TR_SM1)nTemp;
    }
    return nRet;
}

int is_SSM_TR_SM1_double_conversion_allowed()
{
    if (pSimSSM_TR_SM1VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimSSM_TR_SM1VTable);
    }
    return 1;
}

int SSM_TR_SM1_to_double(const void *pValue, double *nValue)
{
    if (pSimSSM_TR_SM1VTable != NULL) {
        return VTable_to_double(pValue, pSimSSM_TR_SM1VTable, nValue);
    }
    *nValue = (double)*((SSM_TR_SM1*)pValue);
    return 1;
}

int is_SSM_TR_SM1_long_conversion_allowed()
{
    if (pSimSSM_TR_SM1VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimSSM_TR_SM1VTable);
    }
    return 1;
}

int SSM_TR_SM1_to_long(const void *pValue, long *nValue)
{
    if (pSimSSM_TR_SM1VTable != NULL) {
        return VTable_to_long(pValue, pSimSSM_TR_SM1VTable, nValue);
    }
    *nValue = (long)*((SSM_TR_SM1*)pValue);
    return 1;
}

void compare_SSM_TR_SM1(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimSSM_TR_SM1VTable != NULL
        && pSimSSM_TR_SM1VTable->m_version >= Scv612
        && pSimSSM_TR_SM1VTable->m_pfnCompare != NULL) {
        if (pSimSSM_TR_SM1VTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSimSSM_TR_SM1VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSimSSM_TR_SM1VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(SSM_TR_SM1*)pValue1), (int)(*(SSM_TR_SM1*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_SSM_TR_SM1_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pConverter->m_pfnGetEnumSignature(SSM_TR_SM1_values, SSM_TR_SM1_nb_values, pfnStrAppend, pStrObj);
}

int init_SSM_TR_SM1(void *pValue)
{
    *(SSM_TR_SM1*)pValue = SSM_TR_no_trans_SM1;
    return 1;
}

int release_SSM_TR_SM1(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_SSM_TR_SM1(void *pToValue, const void *pFromValue)
{
    *((SSM_TR_SM1*)pToValue) = *((SSM_TR_SM1*)pFromValue);
    return 1;
}

SimTypeUtils _Type_SSM_TR_SM1_Utils = {
    SSM_TR_SM1_to_string,
    check_SSM_TR_SM1_string,
    string_to_SSM_TR_SM1,
    is_SSM_TR_SM1_double_conversion_allowed,
    SSM_TR_SM1_to_double,
    is_SSM_TR_SM1_long_conversion_allowed,
    SSM_TR_SM1_to_long,
    compare_SSM_TR_SM1,
    get_SSM_TR_SM1_signature,
    init_SSM_TR_SM1,
    release_SSM_TR_SM1,
    copy_SSM_TR_SM1,
    sizeof(SSM_TR_SM1)
};

/****************************************************************
 ** SSM_TR_SM2_Enabled_SM1 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimSSM_TR_SM2_Enabled_SM1VTable_defined
    extern struct SimTypeVTable *pSimSSM_TR_SM2_Enabled_SM1VTable;
  #else 
    struct SimTypeVTable *pSimSSM_TR_SM2_Enabled_SM1VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimSSM_TR_SM2_Enabled_SM1VTable;
#endif

static SimEnumValUtils SSM_TR_SM2_Enabled_SM1_values[] = {
    { "SSM_TR_no_trans_SM2_Enabled_SM1", SSM_TR_no_trans_SM2_Enabled_SM1},
    { "SSM_TR_Active_Standby_1_Active_SM2_Enabled_SM1", SSM_TR_Active_Standby_1_Active_SM2_Enabled_SM1},
    { "SSM_TR_Standby_Active_1_Standby_SM2_Enabled_SM1", SSM_TR_Standby_Active_1_Standby_SM2_Enabled_SM1},
};
const int SSM_TR_SM2_Enabled_SM1_nb_values = 3;

int SSM_TR_SM2_Enabled_SM1_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimSSM_TR_SM2_Enabled_SM1VTable != NULL
        && pSimSSM_TR_SM2_Enabled_SM1VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimSSM_TR_SM2_Enabled_SM1VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return pConverter->m_pfnEnumToString(*(SSM_TR_SM2_Enabled_SM1*)pValue, SSM_TR_SM2_Enabled_SM1_values, SSM_TR_SM2_Enabled_SM1_nb_values, pfnStrAppend, pStrObj); 
}

int check_SSM_TR_SM2_Enabled_SM1_string(const char *str, char **endptr)
{
    static SSM_TR_SM2_Enabled_SM1 rTemp;
    return string_to_SSM_TR_SM2_Enabled_SM1(str, (void*)&rTemp, endptr);
}

int string_to_SSM_TR_SM2_Enabled_SM1(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimSSM_TR_SM2_Enabled_SM1VTable != NULL) {
        nRet = string_to_VTable(str, pSimSSM_TR_SM2_Enabled_SM1VTable, pValue, endptr);
    }
    if (nRet == 0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, SSM_TR_SM2_Enabled_SM1_values, SSM_TR_SM2_Enabled_SM1_nb_values, endptr);
        if (pValue != NULL && nRet != 0)
            *(SSM_TR_SM2_Enabled_SM1*)pValue = (SSM_TR_SM2_Enabled_SM1)nTemp;
    }
    return nRet;
}

int is_SSM_TR_SM2_Enabled_SM1_double_conversion_allowed()
{
    if (pSimSSM_TR_SM2_Enabled_SM1VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimSSM_TR_SM2_Enabled_SM1VTable);
    }
    return 1;
}

int SSM_TR_SM2_Enabled_SM1_to_double(const void *pValue, double *nValue)
{
    if (pSimSSM_TR_SM2_Enabled_SM1VTable != NULL) {
        return VTable_to_double(pValue, pSimSSM_TR_SM2_Enabled_SM1VTable, nValue);
    }
    *nValue = (double)*((SSM_TR_SM2_Enabled_SM1*)pValue);
    return 1;
}

int is_SSM_TR_SM2_Enabled_SM1_long_conversion_allowed()
{
    if (pSimSSM_TR_SM2_Enabled_SM1VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimSSM_TR_SM2_Enabled_SM1VTable);
    }
    return 1;
}

int SSM_TR_SM2_Enabled_SM1_to_long(const void *pValue, long *nValue)
{
    if (pSimSSM_TR_SM2_Enabled_SM1VTable != NULL) {
        return VTable_to_long(pValue, pSimSSM_TR_SM2_Enabled_SM1VTable, nValue);
    }
    *nValue = (long)*((SSM_TR_SM2_Enabled_SM1*)pValue);
    return 1;
}

void compare_SSM_TR_SM2_Enabled_SM1(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimSSM_TR_SM2_Enabled_SM1VTable != NULL
        && pSimSSM_TR_SM2_Enabled_SM1VTable->m_version >= Scv612
        && pSimSSM_TR_SM2_Enabled_SM1VTable->m_pfnCompare != NULL) {
        if (pSimSSM_TR_SM2_Enabled_SM1VTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSimSSM_TR_SM2_Enabled_SM1VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSimSSM_TR_SM2_Enabled_SM1VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(SSM_TR_SM2_Enabled_SM1*)pValue1), (int)(*(SSM_TR_SM2_Enabled_SM1*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_SSM_TR_SM2_Enabled_SM1_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pConverter->m_pfnGetEnumSignature(SSM_TR_SM2_Enabled_SM1_values, SSM_TR_SM2_Enabled_SM1_nb_values, pfnStrAppend, pStrObj);
}

int init_SSM_TR_SM2_Enabled_SM1(void *pValue)
{
    *(SSM_TR_SM2_Enabled_SM1*)pValue = SSM_TR_no_trans_SM2_Enabled_SM1;
    return 1;
}

int release_SSM_TR_SM2_Enabled_SM1(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_SSM_TR_SM2_Enabled_SM1(void *pToValue, const void *pFromValue)
{
    *((SSM_TR_SM2_Enabled_SM1*)pToValue) = *((SSM_TR_SM2_Enabled_SM1*)pFromValue);
    return 1;
}

SimTypeUtils _Type_SSM_TR_SM2_Enabled_SM1_Utils = {
    SSM_TR_SM2_Enabled_SM1_to_string,
    check_SSM_TR_SM2_Enabled_SM1_string,
    string_to_SSM_TR_SM2_Enabled_SM1,
    is_SSM_TR_SM2_Enabled_SM1_double_conversion_allowed,
    SSM_TR_SM2_Enabled_SM1_to_double,
    is_SSM_TR_SM2_Enabled_SM1_long_conversion_allowed,
    SSM_TR_SM2_Enabled_SM1_to_long,
    compare_SSM_TR_SM2_Enabled_SM1,
    get_SSM_TR_SM2_Enabled_SM1_signature,
    init_SSM_TR_SM2_Enabled_SM1,
    release_SSM_TR_SM2_Enabled_SM1,
    copy_SSM_TR_SM2_Enabled_SM1,
    sizeof(SSM_TR_SM2_Enabled_SM1)
};

/****************************************************************
 ** SSM_TR_SM3_Active_SM2_Enabled_SM1 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable_defined
    extern struct SimTypeVTable *pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable;
  #else 
    struct SimTypeVTable *pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable;
#endif

static SimEnumValUtils SSM_TR_SM3_Active_SM2_Enabled_SM1_values[] = {
    { "SSM_TR_no_trans_SM3_Active_SM2_Enabled_SM1", SSM_TR_no_trans_SM3_Active_SM2_Enabled_SM1},
    { "SSM_TR_On_StandBy_1_On_SM3_Active_SM2_Enabled_SM1", SSM_TR_On_StandBy_1_On_SM3_Active_SM2_Enabled_SM1},
    { "SSM_TR_StandBy_On_1_StandBy_SM3_Active_SM2_Enabled_SM1", SSM_TR_StandBy_On_1_StandBy_SM3_Active_SM2_Enabled_SM1},
};
const int SSM_TR_SM3_Active_SM2_Enabled_SM1_nb_values = 3;

int SSM_TR_SM3_Active_SM2_Enabled_SM1_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable != NULL
        && pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return pConverter->m_pfnEnumToString(*(SSM_TR_SM3_Active_SM2_Enabled_SM1*)pValue, SSM_TR_SM3_Active_SM2_Enabled_SM1_values, SSM_TR_SM3_Active_SM2_Enabled_SM1_nb_values, pfnStrAppend, pStrObj); 
}

int check_SSM_TR_SM3_Active_SM2_Enabled_SM1_string(const char *str, char **endptr)
{
    static SSM_TR_SM3_Active_SM2_Enabled_SM1 rTemp;
    return string_to_SSM_TR_SM3_Active_SM2_Enabled_SM1(str, (void*)&rTemp, endptr);
}

int string_to_SSM_TR_SM3_Active_SM2_Enabled_SM1(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable != NULL) {
        nRet = string_to_VTable(str, pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable, pValue, endptr);
    }
    if (nRet == 0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, SSM_TR_SM3_Active_SM2_Enabled_SM1_values, SSM_TR_SM3_Active_SM2_Enabled_SM1_nb_values, endptr);
        if (pValue != NULL && nRet != 0)
            *(SSM_TR_SM3_Active_SM2_Enabled_SM1*)pValue = (SSM_TR_SM3_Active_SM2_Enabled_SM1)nTemp;
    }
    return nRet;
}

int is_SSM_TR_SM3_Active_SM2_Enabled_SM1_double_conversion_allowed()
{
    if (pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable);
    }
    return 1;
}

int SSM_TR_SM3_Active_SM2_Enabled_SM1_to_double(const void *pValue, double *nValue)
{
    if (pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable != NULL) {
        return VTable_to_double(pValue, pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable, nValue);
    }
    *nValue = (double)*((SSM_TR_SM3_Active_SM2_Enabled_SM1*)pValue);
    return 1;
}

int is_SSM_TR_SM3_Active_SM2_Enabled_SM1_long_conversion_allowed()
{
    if (pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable);
    }
    return 1;
}

int SSM_TR_SM3_Active_SM2_Enabled_SM1_to_long(const void *pValue, long *nValue)
{
    if (pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable != NULL) {
        return VTable_to_long(pValue, pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable, nValue);
    }
    *nValue = (long)*((SSM_TR_SM3_Active_SM2_Enabled_SM1*)pValue);
    return 1;
}

void compare_SSM_TR_SM3_Active_SM2_Enabled_SM1(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable != NULL
        && pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable->m_version >= Scv612
        && pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable->m_pfnCompare != NULL) {
        if (pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSimSSM_TR_SM3_Active_SM2_Enabled_SM1VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(SSM_TR_SM3_Active_SM2_Enabled_SM1*)pValue1), (int)(*(SSM_TR_SM3_Active_SM2_Enabled_SM1*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_SSM_TR_SM3_Active_SM2_Enabled_SM1_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pConverter->m_pfnGetEnumSignature(SSM_TR_SM3_Active_SM2_Enabled_SM1_values, SSM_TR_SM3_Active_SM2_Enabled_SM1_nb_values, pfnStrAppend, pStrObj);
}

int init_SSM_TR_SM3_Active_SM2_Enabled_SM1(void *pValue)
{
    *(SSM_TR_SM3_Active_SM2_Enabled_SM1*)pValue = SSM_TR_no_trans_SM3_Active_SM2_Enabled_SM1;
    return 1;
}

int release_SSM_TR_SM3_Active_SM2_Enabled_SM1(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_SSM_TR_SM3_Active_SM2_Enabled_SM1(void *pToValue, const void *pFromValue)
{
    *((SSM_TR_SM3_Active_SM2_Enabled_SM1*)pToValue) = *((SSM_TR_SM3_Active_SM2_Enabled_SM1*)pFromValue);
    return 1;
}

SimTypeUtils _Type_SSM_TR_SM3_Active_SM2_Enabled_SM1_Utils = {
    SSM_TR_SM3_Active_SM2_Enabled_SM1_to_string,
    check_SSM_TR_SM3_Active_SM2_Enabled_SM1_string,
    string_to_SSM_TR_SM3_Active_SM2_Enabled_SM1,
    is_SSM_TR_SM3_Active_SM2_Enabled_SM1_double_conversion_allowed,
    SSM_TR_SM3_Active_SM2_Enabled_SM1_to_double,
    is_SSM_TR_SM3_Active_SM2_Enabled_SM1_long_conversion_allowed,
    SSM_TR_SM3_Active_SM2_Enabled_SM1_to_long,
    compare_SSM_TR_SM3_Active_SM2_Enabled_SM1,
    get_SSM_TR_SM3_Active_SM2_Enabled_SM1_signature,
    init_SSM_TR_SM3_Active_SM2_Enabled_SM1,
    release_SSM_TR_SM3_Active_SM2_Enabled_SM1,
    copy_SSM_TR_SM3_Active_SM2_Enabled_SM1,
    sizeof(SSM_TR_SM3_Active_SM2_Enabled_SM1)
};

/****************************************************************
 ** tCruiseState_Defs 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimtCruiseState_DefsVTable_defined
    extern struct SimTypeVTable *pSimtCruiseState_DefsVTable;
  #else 
    struct SimTypeVTable *pSimtCruiseState_DefsVTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimtCruiseState_DefsVTable;
#endif

static SimEnumValUtils tCruiseState_Defs_values[] = {
    { "Defs::OFF", OFF_Defs},
    { "Defs::INT", INT_Defs},
    { "Defs::STDBY", STDBY_Defs},
    { "Defs::ON", ON_Defs},
};
const int tCruiseState_Defs_nb_values = 4;

int tCruiseState_Defs_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimtCruiseState_DefsVTable != NULL
        && pSimtCruiseState_DefsVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimtCruiseState_DefsVTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return pConverter->m_pfnEnumToString(*(tCruiseState_Defs*)pValue, tCruiseState_Defs_values, tCruiseState_Defs_nb_values, pfnStrAppend, pStrObj); 
}

int check_tCruiseState_Defs_string(const char *str, char **endptr)
{
    static tCruiseState_Defs rTemp;
    return string_to_tCruiseState_Defs(str, (void*)&rTemp, endptr);
}

int string_to_tCruiseState_Defs(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimtCruiseState_DefsVTable != NULL) {
        nRet = string_to_VTable(str, pSimtCruiseState_DefsVTable, pValue, endptr);
    }
    if (nRet == 0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, tCruiseState_Defs_values, tCruiseState_Defs_nb_values, endptr);
        if (pValue != NULL && nRet != 0)
            *(tCruiseState_Defs*)pValue = (tCruiseState_Defs)nTemp;
    }
    return nRet;
}

int is_tCruiseState_Defs_double_conversion_allowed()
{
    if (pSimtCruiseState_DefsVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimtCruiseState_DefsVTable);
    }
    return 1;
}

int tCruiseState_Defs_to_double(const void *pValue, double *nValue)
{
    if (pSimtCruiseState_DefsVTable != NULL) {
        return VTable_to_double(pValue, pSimtCruiseState_DefsVTable, nValue);
    }
    *nValue = (double)*((tCruiseState_Defs*)pValue);
    return 1;
}

int is_tCruiseState_Defs_long_conversion_allowed()
{
    if (pSimtCruiseState_DefsVTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimtCruiseState_DefsVTable);
    }
    return 1;
}

int tCruiseState_Defs_to_long(const void *pValue, long *nValue)
{
    if (pSimtCruiseState_DefsVTable != NULL) {
        return VTable_to_long(pValue, pSimtCruiseState_DefsVTable, nValue);
    }
    *nValue = (long)*((tCruiseState_Defs*)pValue);
    return 1;
}

void compare_tCruiseState_Defs(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimtCruiseState_DefsVTable != NULL
        && pSimtCruiseState_DefsVTable->m_version >= Scv612
        && pSimtCruiseState_DefsVTable->m_pfnCompare != NULL) {
        if (pSimtCruiseState_DefsVTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSimtCruiseState_DefsVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSimtCruiseState_DefsVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(tCruiseState_Defs*)pValue1), (int)(*(tCruiseState_Defs*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_tCruiseState_Defs_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pConverter->m_pfnGetEnumSignature(tCruiseState_Defs_values, tCruiseState_Defs_nb_values, pfnStrAppend, pStrObj);
}

int init_tCruiseState_Defs(void *pValue)
{
    *(tCruiseState_Defs*)pValue = OFF_Defs;
    return 1;
}

int release_tCruiseState_Defs(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_tCruiseState_Defs(void *pToValue, const void *pFromValue)
{
    *((tCruiseState_Defs*)pToValue) = *((tCruiseState_Defs*)pFromValue);
    return 1;
}

SimTypeUtils _Type_tCruiseState_Defs_Utils = {
    tCruiseState_Defs_to_string,
    check_tCruiseState_Defs_string,
    string_to_tCruiseState_Defs,
    is_tCruiseState_Defs_double_conversion_allowed,
    tCruiseState_Defs_to_double,
    is_tCruiseState_Defs_long_conversion_allowed,
    tCruiseState_Defs_to_long,
    compare_tCruiseState_Defs,
    get_tCruiseState_Defs_signature,
    init_tCruiseState_Defs,
    release_tCruiseState_Defs,
    copy_tCruiseState_Defs,
    sizeof(tCruiseState_Defs)
};

/****************************************************************
 ** tPercent_CarType 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimtPercent_CarTypeVTable_defined
    extern struct SimTypeVTable *pSimtPercent_CarTypeVTable;
  #else 
    struct SimTypeVTable *pSimtPercent_CarTypeVTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimtPercent_CarTypeVTable;
#endif

static SimConstValUtils const tPercent_CarType_constants[] = {
    { "Defs::BrakeConst", &TU_BrakeConst_Defs },
    { "BrakeConst", &TU_BrakeConst_Defs },
    { "Defs::SecondBrakeConst", &TU_SecondBrakeConst_Defs },
    { "SecondBrakeConst", &TU_SecondBrakeConst_Defs },
};

int tPercent_CarType_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimtPercent_CarTypeVTable != NULL
        && pSimtPercent_CarTypeVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimtPercent_CarTypeVTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return kcg_float64_to_string(pValue, pfnStrAppend, pStrObj);
}

int check_tPercent_CarType_string(const char *str, char **endptr)
{
    static tPercent_CarType rTemp;
    return string_to_tPercent_CarType(str, (void*)&rTemp, endptr);
}

int string_to_tPercent_CarType(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimtPercent_CarTypeVTable != NULL) {
        nRet = string_to_VTable(str, pSimtPercent_CarTypeVTable, pValue, endptr);
    }
    if (nRet == 0 && pConverter->m_pfnStringToConstant) {
        nRet = pConverter->m_pfnStringToConstant(str, pValue, tPercent_CarType_constants, sizeof(tPercent_CarType_constants) / sizeof(tPercent_CarType_constants[0]), sizeof(tPercent_CarType), endptr);
        if (nRet != 0) {
            return 2;
        }
    }
    if (nRet == 0) {
        nRet = string_to_kcg_float64(str, pValue, endptr);
    }
    return nRet;
}

int is_tPercent_CarType_double_conversion_allowed()
{
    if (pSimtPercent_CarTypeVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimtPercent_CarTypeVTable);
    }
    return is_kcg_float64_double_conversion_allowed();
}

int tPercent_CarType_to_double(const void *pValue, double *nValue)
{
    if (pSimtPercent_CarTypeVTable != NULL) {
        return VTable_to_double(pValue, pSimtPercent_CarTypeVTable, nValue);
    }
    return kcg_float64_to_double(pValue, nValue);
}

int is_tPercent_CarType_long_conversion_allowed()
{
    if (pSimtPercent_CarTypeVTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimtPercent_CarTypeVTable);
    }
    return is_kcg_float64_long_conversion_allowed();
}

int tPercent_CarType_to_long(const void *pValue, long *nValue)
{
    if (pSimtPercent_CarTypeVTable != NULL) {
        return VTable_to_long(pValue, pSimtPercent_CarTypeVTable, nValue);
    }
    return kcg_float64_to_long(pValue, nValue);
}

void compare_tPercent_CarType(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimtPercent_CarTypeVTable != NULL
        && pSimtPercent_CarTypeVTable->m_version >= Scv612
        && pSimtPercent_CarTypeVTable->m_pfnCompare != NULL) {
        if (pSimtPercent_CarTypeVTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSimtPercent_CarTypeVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSimtPercent_CarTypeVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_kcg_float64(pResult, pValue1, pValue2, pTol, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_tPercent_CarType_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return get_kcg_float64_signature(pfnStrAppend, pStrObj);
}

int init_tPercent_CarType(void *pValue)
{
    init_kcg_float64(pValue);
    return 1;
}

int release_tPercent_CarType(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_tPercent_CarType(void *pToValue, const void *pFromValue)
{
    *((tPercent_CarType*)pToValue) = *((tPercent_CarType*)pFromValue);
    return 1;
}

SimTypeUtils _Type_tPercent_CarType_Utils = {
    tPercent_CarType_to_string,
    check_tPercent_CarType_string,
    string_to_tPercent_CarType,
    is_tPercent_CarType_double_conversion_allowed,
    tPercent_CarType_to_double,
    is_tPercent_CarType_long_conversion_allowed,
    tPercent_CarType_to_long,
    compare_tPercent_CarType,
    get_tPercent_CarType_signature,
    init_tPercent_CarType,
    release_tPercent_CarType,
    copy_tPercent_CarType,
    sizeof(tPercent_CarType)
};

/****************************************************************
 ** tPercent_Defs 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimtPercent_DefsVTable_defined
    extern struct SimTypeVTable *pSimtPercent_DefsVTable;
  #else 
    struct SimTypeVTable *pSimtPercent_DefsVTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimtPercent_DefsVTable;
#endif

static SimConstValUtils const tPercent_Defs_constants[] = {
    { "Defs::ZeroPercent", &TU_ZeroPercent_Defs },
    { "ZeroPercent", &TU_ZeroPercent_Defs },
    { "Defs::RegulThrottleMax", &TU_RegulThrottleMax_Defs },
    { "RegulThrottleMax", &TU_RegulThrottleMax_Defs },
    { "Defs::PedalsMin", &TU_PedalsMin_Defs },
    { "PedalsMin", &TU_PedalsMin_Defs },
};

int tPercent_Defs_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimtPercent_DefsVTable != NULL
        && pSimtPercent_DefsVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimtPercent_DefsVTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return kcg_float64_to_string(pValue, pfnStrAppend, pStrObj);
}

int check_tPercent_Defs_string(const char *str, char **endptr)
{
    static tPercent_Defs rTemp;
    return string_to_tPercent_Defs(str, (void*)&rTemp, endptr);
}

int string_to_tPercent_Defs(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimtPercent_DefsVTable != NULL) {
        nRet = string_to_VTable(str, pSimtPercent_DefsVTable, pValue, endptr);
    }
    if (nRet == 0 && pConverter->m_pfnStringToConstant) {
        nRet = pConverter->m_pfnStringToConstant(str, pValue, tPercent_Defs_constants, sizeof(tPercent_Defs_constants) / sizeof(tPercent_Defs_constants[0]), sizeof(tPercent_Defs), endptr);
        if (nRet != 0) {
            return 2;
        }
    }
    if (nRet == 0) {
        nRet = string_to_kcg_float64(str, pValue, endptr);
    }
    return nRet;
}

int is_tPercent_Defs_double_conversion_allowed()
{
    if (pSimtPercent_DefsVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimtPercent_DefsVTable);
    }
    return is_kcg_float64_double_conversion_allowed();
}

int tPercent_Defs_to_double(const void *pValue, double *nValue)
{
    if (pSimtPercent_DefsVTable != NULL) {
        return VTable_to_double(pValue, pSimtPercent_DefsVTable, nValue);
    }
    return kcg_float64_to_double(pValue, nValue);
}

int is_tPercent_Defs_long_conversion_allowed()
{
    if (pSimtPercent_DefsVTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimtPercent_DefsVTable);
    }
    return is_kcg_float64_long_conversion_allowed();
}

int tPercent_Defs_to_long(const void *pValue, long *nValue)
{
    if (pSimtPercent_DefsVTable != NULL) {
        return VTable_to_long(pValue, pSimtPercent_DefsVTable, nValue);
    }
    return kcg_float64_to_long(pValue, nValue);
}

void compare_tPercent_Defs(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimtPercent_DefsVTable != NULL
        && pSimtPercent_DefsVTable->m_version >= Scv612
        && pSimtPercent_DefsVTable->m_pfnCompare != NULL) {
        if (pSimtPercent_DefsVTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSimtPercent_DefsVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSimtPercent_DefsVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_kcg_float64(pResult, pValue1, pValue2, pTol, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_tPercent_Defs_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return get_kcg_float64_signature(pfnStrAppend, pStrObj);
}

int init_tPercent_Defs(void *pValue)
{
    init_kcg_float64(pValue);
    return 1;
}

int release_tPercent_Defs(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_tPercent_Defs(void *pToValue, const void *pFromValue)
{
    *((tPercent_Defs*)pToValue) = *((tPercent_Defs*)pFromValue);
    return 1;
}

SimTypeUtils _Type_tPercent_Defs_Utils = {
    tPercent_Defs_to_string,
    check_tPercent_Defs_string,
    string_to_tPercent_Defs,
    is_tPercent_Defs_double_conversion_allowed,
    tPercent_Defs_to_double,
    is_tPercent_Defs_long_conversion_allowed,
    tPercent_Defs_to_long,
    compare_tPercent_Defs,
    get_tPercent_Defs_signature,
    init_tPercent_Defs,
    release_tPercent_Defs,
    copy_tPercent_Defs,
    sizeof(tPercent_Defs)
};

/****************************************************************
 ** tRpm_CarType 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimtRpm_CarTypeVTable_defined
    extern struct SimTypeVTable *pSimtRpm_CarTypeVTable;
  #else 
    struct SimTypeVTable *pSimtRpm_CarTypeVTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimtRpm_CarTypeVTable;
#endif

int tRpm_CarType_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimtRpm_CarTypeVTable != NULL
        && pSimtRpm_CarTypeVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimtRpm_CarTypeVTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return kcg_float64_to_string(pValue, pfnStrAppend, pStrObj);
}

int check_tRpm_CarType_string(const char *str, char **endptr)
{
    static tRpm_CarType rTemp;
    return string_to_tRpm_CarType(str, (void*)&rTemp, endptr);
}

int string_to_tRpm_CarType(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimtRpm_CarTypeVTable != NULL) {
        nRet = string_to_VTable(str, pSimtRpm_CarTypeVTable, pValue, endptr);
    }
    if (nRet == 0) {
        nRet = string_to_kcg_float64(str, pValue, endptr);
    }
    return nRet;
}

int is_tRpm_CarType_double_conversion_allowed()
{
    if (pSimtRpm_CarTypeVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimtRpm_CarTypeVTable);
    }
    return is_kcg_float64_double_conversion_allowed();
}

int tRpm_CarType_to_double(const void *pValue, double *nValue)
{
    if (pSimtRpm_CarTypeVTable != NULL) {
        return VTable_to_double(pValue, pSimtRpm_CarTypeVTable, nValue);
    }
    return kcg_float64_to_double(pValue, nValue);
}

int is_tRpm_CarType_long_conversion_allowed()
{
    if (pSimtRpm_CarTypeVTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimtRpm_CarTypeVTable);
    }
    return is_kcg_float64_long_conversion_allowed();
}

int tRpm_CarType_to_long(const void *pValue, long *nValue)
{
    if (pSimtRpm_CarTypeVTable != NULL) {
        return VTable_to_long(pValue, pSimtRpm_CarTypeVTable, nValue);
    }
    return kcg_float64_to_long(pValue, nValue);
}

void compare_tRpm_CarType(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimtRpm_CarTypeVTable != NULL
        && pSimtRpm_CarTypeVTable->m_version >= Scv612
        && pSimtRpm_CarTypeVTable->m_pfnCompare != NULL) {
        if (pSimtRpm_CarTypeVTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSimtRpm_CarTypeVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSimtRpm_CarTypeVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_kcg_float64(pResult, pValue1, pValue2, pTol, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_tRpm_CarType_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return get_kcg_float64_signature(pfnStrAppend, pStrObj);
}

int init_tRpm_CarType(void *pValue)
{
    init_kcg_float64(pValue);
    return 1;
}

int release_tRpm_CarType(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_tRpm_CarType(void *pToValue, const void *pFromValue)
{
    *((tRpm_CarType*)pToValue) = *((tRpm_CarType*)pFromValue);
    return 1;
}

SimTypeUtils _Type_tRpm_CarType_Utils = {
    tRpm_CarType_to_string,
    check_tRpm_CarType_string,
    string_to_tRpm_CarType,
    is_tRpm_CarType_double_conversion_allowed,
    tRpm_CarType_to_double,
    is_tRpm_CarType_long_conversion_allowed,
    tRpm_CarType_to_long,
    compare_tRpm_CarType,
    get_tRpm_CarType_signature,
    init_tRpm_CarType,
    release_tRpm_CarType,
    copy_tRpm_CarType,
    sizeof(tRpm_CarType)
};

/****************************************************************
 ** tRpm_Defs 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimtRpm_DefsVTable_defined
    extern struct SimTypeVTable *pSimtRpm_DefsVTable;
  #else 
    struct SimTypeVTable *pSimtRpm_DefsVTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimtRpm_DefsVTable;
#endif

int tRpm_Defs_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimtRpm_DefsVTable != NULL
        && pSimtRpm_DefsVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimtRpm_DefsVTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return kcg_float64_to_string(pValue, pfnStrAppend, pStrObj);
}

int check_tRpm_Defs_string(const char *str, char **endptr)
{
    static tRpm_Defs rTemp;
    return string_to_tRpm_Defs(str, (void*)&rTemp, endptr);
}

int string_to_tRpm_Defs(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimtRpm_DefsVTable != NULL) {
        nRet = string_to_VTable(str, pSimtRpm_DefsVTable, pValue, endptr);
    }
    if (nRet == 0) {
        nRet = string_to_kcg_float64(str, pValue, endptr);
    }
    return nRet;
}

int is_tRpm_Defs_double_conversion_allowed()
{
    if (pSimtRpm_DefsVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimtRpm_DefsVTable);
    }
    return is_kcg_float64_double_conversion_allowed();
}

int tRpm_Defs_to_double(const void *pValue, double *nValue)
{
    if (pSimtRpm_DefsVTable != NULL) {
        return VTable_to_double(pValue, pSimtRpm_DefsVTable, nValue);
    }
    return kcg_float64_to_double(pValue, nValue);
}

int is_tRpm_Defs_long_conversion_allowed()
{
    if (pSimtRpm_DefsVTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimtRpm_DefsVTable);
    }
    return is_kcg_float64_long_conversion_allowed();
}

int tRpm_Defs_to_long(const void *pValue, long *nValue)
{
    if (pSimtRpm_DefsVTable != NULL) {
        return VTable_to_long(pValue, pSimtRpm_DefsVTable, nValue);
    }
    return kcg_float64_to_long(pValue, nValue);
}

void compare_tRpm_Defs(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimtRpm_DefsVTable != NULL
        && pSimtRpm_DefsVTable->m_version >= Scv612
        && pSimtRpm_DefsVTable->m_pfnCompare != NULL) {
        if (pSimtRpm_DefsVTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSimtRpm_DefsVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSimtRpm_DefsVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_kcg_float64(pResult, pValue1, pValue2, pTol, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_tRpm_Defs_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return get_kcg_float64_signature(pfnStrAppend, pStrObj);
}

int init_tRpm_Defs(void *pValue)
{
    init_kcg_float64(pValue);
    return 1;
}

int release_tRpm_Defs(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_tRpm_Defs(void *pToValue, const void *pFromValue)
{
    *((tRpm_Defs*)pToValue) = *((tRpm_Defs*)pFromValue);
    return 1;
}

SimTypeUtils _Type_tRpm_Defs_Utils = {
    tRpm_Defs_to_string,
    check_tRpm_Defs_string,
    string_to_tRpm_Defs,
    is_tRpm_Defs_double_conversion_allowed,
    tRpm_Defs_to_double,
    is_tRpm_Defs_long_conversion_allowed,
    tRpm_Defs_to_long,
    compare_tRpm_Defs,
    get_tRpm_Defs_signature,
    init_tRpm_Defs,
    release_tRpm_Defs,
    copy_tRpm_Defs,
    sizeof(tRpm_Defs)
};

/****************************************************************
 ** TruthTableValues_truthtables 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimTruthTableValues_truthtablesVTable_defined
    extern struct SimTypeVTable *pSimTruthTableValues_truthtablesVTable;
  #else 
    struct SimTypeVTable *pSimTruthTableValues_truthtablesVTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimTruthTableValues_truthtablesVTable;
#endif

static SimEnumValUtils TruthTableValues_truthtables_values[] = {
    { "truthtables::T", T_truthtables},
    { "truthtables::F", F_truthtables},
    { "truthtables::X", X_truthtables},
};
const int TruthTableValues_truthtables_nb_values = 3;

int TruthTableValues_truthtables_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimTruthTableValues_truthtablesVTable != NULL
        && pSimTruthTableValues_truthtablesVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimTruthTableValues_truthtablesVTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return pConverter->m_pfnEnumToString(*(TruthTableValues_truthtables*)pValue, TruthTableValues_truthtables_values, TruthTableValues_truthtables_nb_values, pfnStrAppend, pStrObj); 
}

int check_TruthTableValues_truthtables_string(const char *str, char **endptr)
{
    static TruthTableValues_truthtables rTemp;
    return string_to_TruthTableValues_truthtables(str, (void*)&rTemp, endptr);
}

int string_to_TruthTableValues_truthtables(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimTruthTableValues_truthtablesVTable != NULL) {
        nRet = string_to_VTable(str, pSimTruthTableValues_truthtablesVTable, pValue, endptr);
    }
    if (nRet == 0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, TruthTableValues_truthtables_values, TruthTableValues_truthtables_nb_values, endptr);
        if (pValue != NULL && nRet != 0)
            *(TruthTableValues_truthtables*)pValue = (TruthTableValues_truthtables)nTemp;
    }
    return nRet;
}

int is_TruthTableValues_truthtables_double_conversion_allowed()
{
    if (pSimTruthTableValues_truthtablesVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimTruthTableValues_truthtablesVTable);
    }
    return 1;
}

int TruthTableValues_truthtables_to_double(const void *pValue, double *nValue)
{
    if (pSimTruthTableValues_truthtablesVTable != NULL) {
        return VTable_to_double(pValue, pSimTruthTableValues_truthtablesVTable, nValue);
    }
    *nValue = (double)*((TruthTableValues_truthtables*)pValue);
    return 1;
}

int is_TruthTableValues_truthtables_long_conversion_allowed()
{
    if (pSimTruthTableValues_truthtablesVTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimTruthTableValues_truthtablesVTable);
    }
    return 1;
}

int TruthTableValues_truthtables_to_long(const void *pValue, long *nValue)
{
    if (pSimTruthTableValues_truthtablesVTable != NULL) {
        return VTable_to_long(pValue, pSimTruthTableValues_truthtablesVTable, nValue);
    }
    *nValue = (long)*((TruthTableValues_truthtables*)pValue);
    return 1;
}

void compare_TruthTableValues_truthtables(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimTruthTableValues_truthtablesVTable != NULL
        && pSimTruthTableValues_truthtablesVTable->m_version >= Scv612
        && pSimTruthTableValues_truthtablesVTable->m_pfnCompare != NULL) {
        if (pSimTruthTableValues_truthtablesVTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSimTruthTableValues_truthtablesVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSimTruthTableValues_truthtablesVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(TruthTableValues_truthtables*)pValue1), (int)(*(TruthTableValues_truthtables*)pValue2));
    }
    UNUSED(pTol);
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_TruthTableValues_truthtables_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pConverter->m_pfnGetEnumSignature(TruthTableValues_truthtables_values, TruthTableValues_truthtables_nb_values, pfnStrAppend, pStrObj);
}

int init_TruthTableValues_truthtables(void *pValue)
{
    *(TruthTableValues_truthtables*)pValue = T_truthtables;
    return 1;
}

int release_TruthTableValues_truthtables(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_TruthTableValues_truthtables(void *pToValue, const void *pFromValue)
{
    *((TruthTableValues_truthtables*)pToValue) = *((TruthTableValues_truthtables*)pFromValue);
    return 1;
}

SimTypeUtils _Type_TruthTableValues_truthtables_Utils = {
    TruthTableValues_truthtables_to_string,
    check_TruthTableValues_truthtables_string,
    string_to_TruthTableValues_truthtables,
    is_TruthTableValues_truthtables_double_conversion_allowed,
    TruthTableValues_truthtables_to_double,
    is_TruthTableValues_truthtables_long_conversion_allowed,
    TruthTableValues_truthtables_to_long,
    compare_TruthTableValues_truthtables,
    get_TruthTableValues_truthtables_signature,
    init_TruthTableValues_truthtables,
    release_TruthTableValues_truthtables,
    copy_TruthTableValues_truthtables,
    sizeof(TruthTableValues_truthtables)
};

/****************************************************************
 ** tSpeed_CarType 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimtSpeed_CarTypeVTable_defined
    extern struct SimTypeVTable *pSimtSpeed_CarTypeVTable;
  #else 
    struct SimTypeVTable *pSimtSpeed_CarTypeVTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimtSpeed_CarTypeVTable;
#endif

int tSpeed_CarType_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimtSpeed_CarTypeVTable != NULL
        && pSimtSpeed_CarTypeVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimtSpeed_CarTypeVTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return kcg_float64_to_string(pValue, pfnStrAppend, pStrObj);
}

int check_tSpeed_CarType_string(const char *str, char **endptr)
{
    static tSpeed_CarType rTemp;
    return string_to_tSpeed_CarType(str, (void*)&rTemp, endptr);
}

int string_to_tSpeed_CarType(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimtSpeed_CarTypeVTable != NULL) {
        nRet = string_to_VTable(str, pSimtSpeed_CarTypeVTable, pValue, endptr);
    }
    if (nRet == 0) {
        nRet = string_to_kcg_float64(str, pValue, endptr);
    }
    return nRet;
}

int is_tSpeed_CarType_double_conversion_allowed()
{
    if (pSimtSpeed_CarTypeVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimtSpeed_CarTypeVTable);
    }
    return is_kcg_float64_double_conversion_allowed();
}

int tSpeed_CarType_to_double(const void *pValue, double *nValue)
{
    if (pSimtSpeed_CarTypeVTable != NULL) {
        return VTable_to_double(pValue, pSimtSpeed_CarTypeVTable, nValue);
    }
    return kcg_float64_to_double(pValue, nValue);
}

int is_tSpeed_CarType_long_conversion_allowed()
{
    if (pSimtSpeed_CarTypeVTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimtSpeed_CarTypeVTable);
    }
    return is_kcg_float64_long_conversion_allowed();
}

int tSpeed_CarType_to_long(const void *pValue, long *nValue)
{
    if (pSimtSpeed_CarTypeVTable != NULL) {
        return VTable_to_long(pValue, pSimtSpeed_CarTypeVTable, nValue);
    }
    return kcg_float64_to_long(pValue, nValue);
}

void compare_tSpeed_CarType(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimtSpeed_CarTypeVTable != NULL
        && pSimtSpeed_CarTypeVTable->m_version >= Scv612
        && pSimtSpeed_CarTypeVTable->m_pfnCompare != NULL) {
        if (pSimtSpeed_CarTypeVTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSimtSpeed_CarTypeVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSimtSpeed_CarTypeVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_kcg_float64(pResult, pValue1, pValue2, pTol, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_tSpeed_CarType_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return get_kcg_float64_signature(pfnStrAppend, pStrObj);
}

int init_tSpeed_CarType(void *pValue)
{
    init_kcg_float64(pValue);
    return 1;
}

int release_tSpeed_CarType(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_tSpeed_CarType(void *pToValue, const void *pFromValue)
{
    *((tSpeed_CarType*)pToValue) = *((tSpeed_CarType*)pFromValue);
    return 1;
}

SimTypeUtils _Type_tSpeed_CarType_Utils = {
    tSpeed_CarType_to_string,
    check_tSpeed_CarType_string,
    string_to_tSpeed_CarType,
    is_tSpeed_CarType_double_conversion_allowed,
    tSpeed_CarType_to_double,
    is_tSpeed_CarType_long_conversion_allowed,
    tSpeed_CarType_to_long,
    compare_tSpeed_CarType,
    get_tSpeed_CarType_signature,
    init_tSpeed_CarType,
    release_tSpeed_CarType,
    copy_tSpeed_CarType,
    sizeof(tSpeed_CarType)
};

/****************************************************************
 ** tSpeed_Defs 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimtSpeed_DefsVTable_defined
    extern struct SimTypeVTable *pSimtSpeed_DefsVTable;
  #else 
    struct SimTypeVTable *pSimtSpeed_DefsVTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimtSpeed_DefsVTable;
#endif

static SimConstValUtils const tSpeed_Defs_constants[] = {
    { "Defs::ZeroSpeed", &TU_ZeroSpeed_Defs },
    { "ZeroSpeed", &TU_ZeroSpeed_Defs },
    { "Defs::SpeedMin", &TU_SpeedMin_Defs },
    { "SpeedMin", &TU_SpeedMin_Defs },
    { "Defs::SpeedMax", &TU_SpeedMax_Defs },
    { "SpeedMax", &TU_SpeedMax_Defs },
    { "Defs::SpeedInc", &TU_SpeedInc_Defs },
    { "SpeedInc", &TU_SpeedInc_Defs },
};

int tSpeed_Defs_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimtSpeed_DefsVTable != NULL
        && pSimtSpeed_DefsVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimtSpeed_DefsVTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return kcg_float64_to_string(pValue, pfnStrAppend, pStrObj);
}

int check_tSpeed_Defs_string(const char *str, char **endptr)
{
    static tSpeed_Defs rTemp;
    return string_to_tSpeed_Defs(str, (void*)&rTemp, endptr);
}

int string_to_tSpeed_Defs(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimtSpeed_DefsVTable != NULL) {
        nRet = string_to_VTable(str, pSimtSpeed_DefsVTable, pValue, endptr);
    }
    if (nRet == 0 && pConverter->m_pfnStringToConstant) {
        nRet = pConverter->m_pfnStringToConstant(str, pValue, tSpeed_Defs_constants, sizeof(tSpeed_Defs_constants) / sizeof(tSpeed_Defs_constants[0]), sizeof(tSpeed_Defs), endptr);
        if (nRet != 0) {
            return 2;
        }
    }
    if (nRet == 0) {
        nRet = string_to_kcg_float64(str, pValue, endptr);
    }
    return nRet;
}

int is_tSpeed_Defs_double_conversion_allowed()
{
    if (pSimtSpeed_DefsVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimtSpeed_DefsVTable);
    }
    return is_kcg_float64_double_conversion_allowed();
}

int tSpeed_Defs_to_double(const void *pValue, double *nValue)
{
    if (pSimtSpeed_DefsVTable != NULL) {
        return VTable_to_double(pValue, pSimtSpeed_DefsVTable, nValue);
    }
    return kcg_float64_to_double(pValue, nValue);
}

int is_tSpeed_Defs_long_conversion_allowed()
{
    if (pSimtSpeed_DefsVTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimtSpeed_DefsVTable);
    }
    return is_kcg_float64_long_conversion_allowed();
}

int tSpeed_Defs_to_long(const void *pValue, long *nValue)
{
    if (pSimtSpeed_DefsVTable != NULL) {
        return VTable_to_long(pValue, pSimtSpeed_DefsVTable, nValue);
    }
    return kcg_float64_to_long(pValue, nValue);
}

void compare_tSpeed_Defs(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimtSpeed_DefsVTable != NULL
        && pSimtSpeed_DefsVTable->m_version >= Scv612
        && pSimtSpeed_DefsVTable->m_pfnCompare != NULL) {
        if (pSimtSpeed_DefsVTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSimtSpeed_DefsVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSimtSpeed_DefsVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_kcg_float64(pResult, pValue1, pValue2, pTol, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_tSpeed_Defs_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return get_kcg_float64_signature(pfnStrAppend, pStrObj);
}

int init_tSpeed_Defs(void *pValue)
{
    init_kcg_float64(pValue);
    return 1;
}

int release_tSpeed_Defs(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_tSpeed_Defs(void *pToValue, const void *pFromValue)
{
    *((tSpeed_Defs*)pToValue) = *((tSpeed_Defs*)pFromValue);
    return 1;
}

SimTypeUtils _Type_tSpeed_Defs_Utils = {
    tSpeed_Defs_to_string,
    check_tSpeed_Defs_string,
    string_to_tSpeed_Defs,
    is_tSpeed_Defs_double_conversion_allowed,
    tSpeed_Defs_to_double,
    is_tSpeed_Defs_long_conversion_allowed,
    tSpeed_Defs_to_long,
    compare_tSpeed_Defs,
    get_tSpeed_Defs_signature,
    init_tSpeed_Defs,
    release_tSpeed_Defs,
    copy_tSpeed_Defs,
    sizeof(tSpeed_Defs)
};

/****************************************************************
 ** tTorq_CarType 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimtTorq_CarTypeVTable_defined
    extern struct SimTypeVTable *pSimtTorq_CarTypeVTable;
  #else 
    struct SimTypeVTable *pSimtTorq_CarTypeVTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimtTorq_CarTypeVTable;
#endif

int tTorq_CarType_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimtTorq_CarTypeVTable != NULL
        && pSimtTorq_CarTypeVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimtTorq_CarTypeVTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    return kcg_float64_to_string(pValue, pfnStrAppend, pStrObj);
}

int check_tTorq_CarType_string(const char *str, char **endptr)
{
    static tTorq_CarType rTemp;
    return string_to_tTorq_CarType(str, (void*)&rTemp, endptr);
}

int string_to_tTorq_CarType(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimtTorq_CarTypeVTable != NULL) {
        nRet = string_to_VTable(str, pSimtTorq_CarTypeVTable, pValue, endptr);
    }
    if (nRet == 0) {
        nRet = string_to_kcg_float64(str, pValue, endptr);
    }
    return nRet;
}

int is_tTorq_CarType_double_conversion_allowed()
{
    if (pSimtTorq_CarTypeVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimtTorq_CarTypeVTable);
    }
    return is_kcg_float64_double_conversion_allowed();
}

int tTorq_CarType_to_double(const void *pValue, double *nValue)
{
    if (pSimtTorq_CarTypeVTable != NULL) {
        return VTable_to_double(pValue, pSimtTorq_CarTypeVTable, nValue);
    }
    return kcg_float64_to_double(pValue, nValue);
}

int is_tTorq_CarType_long_conversion_allowed()
{
    if (pSimtTorq_CarTypeVTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimtTorq_CarTypeVTable);
    }
    return is_kcg_float64_long_conversion_allowed();
}

int tTorq_CarType_to_long(const void *pValue, long *nValue)
{
    if (pSimtTorq_CarTypeVTable != NULL) {
        return VTable_to_long(pValue, pSimtTorq_CarTypeVTable, nValue);
    }
    return kcg_float64_to_long(pValue, nValue);
}

void compare_tTorq_CarType(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimtTorq_CarTypeVTable != NULL
        && pSimtTorq_CarTypeVTable->m_version >= Scv612
        && pSimtTorq_CarTypeVTable->m_pfnCompare != NULL) {
        if (pSimtTorq_CarTypeVTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSimtTorq_CarTypeVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSimtTorq_CarTypeVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_kcg_float64(pResult, pValue1, pValue2, pTol, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_tTorq_CarType_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return get_kcg_float64_signature(pfnStrAppend, pStrObj);
}

int init_tTorq_CarType(void *pValue)
{
    init_kcg_float64(pValue);
    return 1;
}

int release_tTorq_CarType(void *pValue)
{
    UNUSED(pValue);
    return 1;
}

int copy_tTorq_CarType(void *pToValue, const void *pFromValue)
{
    *((tTorq_CarType*)pToValue) = *((tTorq_CarType*)pFromValue);
    return 1;
}

SimTypeUtils _Type_tTorq_CarType_Utils = {
    tTorq_CarType_to_string,
    check_tTorq_CarType_string,
    string_to_tTorq_CarType,
    is_tTorq_CarType_double_conversion_allowed,
    tTorq_CarType_to_double,
    is_tTorq_CarType_long_conversion_allowed,
    tTorq_CarType_to_long,
    compare_tTorq_CarType,
    get_tTorq_CarType_signature,
    init_tTorq_CarType,
    release_tTorq_CarType,
    copy_tTorq_CarType,
    sizeof(tTorq_CarType)
};

