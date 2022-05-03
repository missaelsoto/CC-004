/*
 * Copyright(C) 2020 ANSYS, Inc. ALL RIGHTS RESERVED.
 * Copyright(C) 2015 ESTEREL TECHNOLOGIES SAS. ALL RIGHTS RESERVED.
 * This source file may be used and distributed without restriction provided
 * that this copyright statement is not removed from the file and that any
 * derivative work contains this copyright notice.
 *
 * Warranty
 * ANSYS, Inc  makes no warranty of any kind with regard to the
 * use of this Software, either expressed or implied, including, but not
 * limited to the fitness for a particular purpose.
 */

#include "SmuPredefConv.h"
#include "SmuConfig.h"

/****************************************************************************************
***
*** Utils
***
****************************************************************************************/
#define skip_whitespace(str) while(*str == ' ' || *str == '\t') str++

void updateCompareResult(int unitResult, int *pGlobalResult)
{
    if (unitResult<0) {
        *pGlobalResult |= SIM_CMP_RES_LT;
        *pGlobalResult |= SIM_CMP_RES_NEQ;
    } else if (unitResult>0) {
        *pGlobalResult |= SIM_CMP_RES_GT;
        *pGlobalResult |= SIM_CMP_RES_NEQ;
    } else {
        *pGlobalResult |= SIM_CMP_RES_EQ;
    }
}

/****************************************************************************************
***
*** Local Utils
***
****************************************************************************************/

#define IS_SIGNED(T) ((T)-1 < (T)0)

#define IMPLEMENT_CMP_INT()\
{\
    if (value1 == value2) {\
        *pResult |= SIM_CMP_RES_EQ;\
        return 0;\
    } else if (value1 < value2) {\
        *pResult |= SIM_CMP_RES_NEQ | SIM_CMP_RES_LT;\
        return -1;\
    }\
    *pResult |= SIM_CMP_RES_NEQ | SIM_CMP_RES_GT;\
    return 1;\
}

#define IMPLEMENT_CMP_FLOAT(float_type, eps_value)\
{\
    int nRet = 0;\
    int nSign;\
    float_type delta;\
    float_type threshold;\
    \
    if (pConverter->m_bAdvancedTeCheck && (ssm_is_nan_pzero(value2) || ssm_is_nzero(value2)) && value1 == (float_type)0) {\
        *pResult |= (ssm_sign_bit(value1) != ssm_sign_bit(value2) ? SIM_CMP_RES_NEQ : SIM_CMP_RES_EQ);\
        return 0;\
    }\
    if (pConverter->m_bAdvancedTeCheck && ssm_is_nan_xnan(value2) && ssm_is_nan(value1)) {\
        *pResult |= SIM_CMP_RES_EQ;\
        return 0;\
    }\
    if (ssm_is_nan(value1) || ssm_is_nan(value2)) {\
        *pResult |= (   (ssm_is_snan(value1) && ssm_is_snan(value2))\
                     || (ssm_is_qnan(value1) && ssm_is_qnan(value2))) ? SIM_CMP_RES_EQ:SIM_CMP_RES_NEQ;\
        return 0; \
    }\
    if (ssm_is_inf(value1) || ssm_is_inf(value2)) {\
        if (ssm_is_inf(value1) && ssm_is_inf(value2)) {\
            *pResult |= ssm_sign_bit(value1) ?\
                ssm_sign_bit(value2) ? SIM_CMP_RES_EQ : (SIM_CMP_RES_NEQ | SIM_CMP_RES_LT) :\
                ssm_sign_bit(value2) ? (SIM_CMP_RES_NEQ | SIM_CMP_RES_GT) : SIM_CMP_RES_EQ  \
            ;\
        }\
        else if (ssm_is_inf(value1)) {\
            *pResult |= SIM_CMP_RES_NEQ | (ssm_sign_bit(value1) ? SIM_CMP_RES_LT : SIM_CMP_RES_GT);\
        }\
        else if (ssm_is_inf(value2)) {\
            *pResult |= SIM_CMP_RES_NEQ | (ssm_sign_bit(value2) ? SIM_CMP_RES_GT : SIM_CMP_RES_LT);\
        }\
        return 0;\
    }\
    \
    /* delta = |value2-value1| */\
    nSign = value1<value2;\
    delta = nSign ? value2-value1 : value1-value2;\
    \
    /* threshold = |tolerance| or |tolerance*value2| */\
    threshold = 0.0;\
    if (pTol) {\
        threshold = (float_type)pTol->m_dTolerance;\
        if (pTol->m_bRelative) threshold = threshold*value2;\
        if (threshold<0.0) threshold = -threshold;\
    }\
    \
    /* criterion : delta <= threshold */\
    if (delta <= threshold) {\
        *pResult |= SIM_CMP_RES_EQ;\
    } else {\
        nRet = nSign ? -1 : 1;\
        *pResult |= SIM_CMP_RES_NEQ | (nSign ? SIM_CMP_RES_LT : SIM_CMP_RES_GT);\
    }\
    \
    /* delta = |delta-threshold| */\
    nSign = threshold<delta;\
    delta = nSign ? delta-threshold : threshold-delta;\
    \
    /* threshold = |epsilon*value2| */\
    threshold = (float_type)(eps_value*value2);\
    if (threshold < 0.0) threshold = -threshold;\
    \
    /* NBW criterion : delta < threshold */\
    if (delta < threshold) {\
        *pResult |= SIM_CMP_RES_BOUNDARY;\
    }\
    \
    return nRet;\
}

/****************************************************************************************
***
*** Predefined <type> comparison functions
***
****************************************************************************************/

static int predef_compare(int cond, int *pResult)
{
    if (cond) {
        *pResult |= SIM_CMP_RES_EQ;
        return 0;
    }
    *pResult |= SIM_CMP_RES_NEQ;
    return -1;
}

int predef_compare_kcg_bool(int *pResult, kcg_bool value1, kcg_bool value2)
{
    return predef_compare(value1==value2, pResult);
}

int predef_compare_kcg_char(int *pResult, kcg_char value1, kcg_char value2)
{
    return predef_compare(value1==value2, pResult);
}

int predef_compare_enum(int *pResult, int value1, int value2)
{
    return predef_compare(value1==value2, pResult);
}

#ifdef kcg_size
int predef_compare_kcg_size(int *pResult, kcg_size value1, kcg_size value2)
{
    return predef_compare(value1 == value2, pResult);
}
#endif

#ifdef kcg_int8
int predef_compare_kcg_int8(int *pResult, kcg_int8 value1, kcg_int8 value2)
{
    IMPLEMENT_CMP_INT()
}
#endif
#ifdef kcg_int16
int predef_compare_kcg_int16(int *pResult, kcg_int16 value1, kcg_int16 value2)
{
    IMPLEMENT_CMP_INT()
}
#endif
#ifdef kcg_int32
int predef_compare_kcg_int32(int *pResult, kcg_int32 value1, kcg_int32 value2)
{
    IMPLEMENT_CMP_INT()
}
#endif
#ifdef kcg_int64
int predef_compare_kcg_int64(int *pResult, kcg_int64 value1, kcg_int64 value2)
{
    IMPLEMENT_CMP_INT()
}
#endif
#ifdef kcg_uint8
int predef_compare_kcg_uint8(int *pResult, kcg_uint8 value1, kcg_uint8 value2)
{
    IMPLEMENT_CMP_INT()
}
#endif
#ifdef kcg_uint16
int predef_compare_kcg_uint16(int *pResult, kcg_uint16 value1, kcg_uint16 value2)
{
    IMPLEMENT_CMP_INT()
}
#endif
#ifdef kcg_uint32
int predef_compare_kcg_uint32(int *pResult, kcg_uint32 value1, kcg_uint32 value2)
{
    IMPLEMENT_CMP_INT()
}
#endif
#ifdef kcg_uint64
int predef_compare_kcg_uint64(int *pResult, kcg_uint64 value1, kcg_uint64 value2)
{
    IMPLEMENT_CMP_INT()
}
#endif
#ifdef kcg_float32
int predef_compare_kcg_float32(int *pResult, kcg_float32 value1, kcg_float32 value2, SimTolerance *pTol)
{
    IMPLEMENT_CMP_FLOAT(kcg_float32, 2.0 * SSM_FLT_EPSILON)
}
#endif
#ifdef kcg_float64
int predef_compare_kcg_float64(int *pResult, kcg_float64 value1, kcg_float64 value2, SimTolerance *pTol)
{
    IMPLEMENT_CMP_FLOAT(kcg_float64, 2.0 * SSM_DBL_EPSILON)
}
#endif

/****************************************************************************************
***
*** Predefined string to <type> convetion functions
***
****************************************************************************************/

int predef_string_to_kcg_bool(const char* str, kcg_bool *pValue, char **endptr) {
    int value;
    if (ssm_string_to_bool(str, &value, endptr))
        return 0;

    *pValue = value == 0 ? kcg_false : kcg_true;
    return 1;
}

int predef_string_to_kcg_char(const char* str, kcg_char *pValue, char **endptr) {
    return ssm_string_to_char(str, (char*)pValue, endptr) == 0 ? 1 : 0;
}

#ifdef kcg_size
    int predef_string_to_kcg_size(const char* str, kcg_size *pValue, char **endptr) {
        static const int sign = IS_SIGNED(kcg_size);
        return ssm_string_to_int(str, pValue, sizeof(kcg_size), sign, endptr) == 0 ? 1 : 0;
    }
#endif

#ifdef kcg_int8
    int predef_string_to_kcg_int8(const char* str, kcg_int8 *pValue, char **endptr) {
        return ssm_string_to_int(str, pValue, sizeof(kcg_int8), 1, endptr) == 0 ? 1 : 0;
    }
#endif

#ifdef kcg_int16
    int predef_string_to_kcg_int16(const char* str, kcg_int16 *pValue, char **endptr) {
        return ssm_string_to_int(str, pValue, sizeof(kcg_int16), 1, endptr) == 0 ? 1 : 0;
    }
#endif

#ifdef kcg_int32
    int predef_string_to_kcg_int32(const char* str, kcg_int32 *pValue, char **endptr) {
        return ssm_string_to_int(str, pValue, sizeof(kcg_int32), 1, endptr) == 0 ? 1 : 0;
    }
#endif

#ifdef kcg_int64
    int predef_string_to_kcg_int64(const char* str, kcg_int64 *pValue, char **endptr) {
        return ssm_string_to_int(str, pValue, sizeof(kcg_int64), 1, endptr) == 0 ? 1 : 0;
    }
#endif

#ifdef kcg_uint8
    int predef_string_to_kcg_uint8(const char* str, kcg_uint8 *pValue, char **endptr) {
        return ssm_string_to_int(str, pValue, sizeof(kcg_uint8), 0, endptr) == 0 ? 1 : 0;
    }
#endif

#ifdef kcg_uint16
    int predef_string_to_kcg_uint16(const char* str, kcg_uint16 *pValue, char **endptr) {
        return ssm_string_to_int(str, pValue, sizeof(kcg_uint16), 0, endptr) == 0 ? 1 : 0;
    }
#endif

#ifdef kcg_uint32
    int predef_string_to_kcg_uint32(const char* str, kcg_uint32 *pValue, char **endptr) {
        return ssm_string_to_int(str, pValue, sizeof(kcg_uint32), 0, endptr) == 0 ? 1 : 0;
    }
#endif

#ifdef kcg_uint64
    int predef_string_to_kcg_uint64(const char* str, kcg_uint64 *pValue, char **endptr) {
        return ssm_string_to_int(str, pValue, sizeof(kcg_uint64), 0, endptr) == 0 ? 1 : 0;
    }
#endif

#ifdef kcg_float32
    int predef_string_to_kcg_float32(const char* str, kcg_float32 *pValue, char **endptr) {
        return ssm_string_to_real(str, pValue, sizeof(kcg_float32), endptr, pConverter->m_bAdvancedTeCheck) == 0 ? 1 : 0;
    }
#endif

#ifdef kcg_float64
    int predef_string_to_kcg_float64(const char* str, kcg_float64 *pValue, char **endptr) {
        return ssm_string_to_real(str, pValue, sizeof(kcg_float64), endptr, pConverter->m_bAdvancedTeCheck) == 0 ? 1 : 0;
    }
#endif

/****************************************************************************************
***
*** Predefined <type> to string conversion functions
***
****************************************************************************************/

int predef_int_to_string(void *value, int size, int sign, char *str) {
    switch (pConverter->m_IntDisplayBase) {
        case IDB_BINARY:
            return ssm_int_to_base_string(value, size, sign, 2, str);
        case IDB_OCTAL:
            return ssm_int_to_base_string(value, size, sign, 8, str);
        case IDB_HEXADECIMAL:
            return ssm_int_to_base_string(value, size, sign, 16, str);
    }
    return ssm_int_to_string(value, size, sign, str);
}

int predef_kcg_bool_to_string(kcg_bool bValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj) {
    return pfnStrAppend(bValue == kcg_true ? "true" : "false", pStrObj);
}

int predef_kcg_char_to_string(kcg_char cValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj) {
    char szValue[8];
    ssm_char_to_string(cValue, szValue);
    return pfnStrAppend(szValue, pStrObj);
}

#ifdef kcg_size
    int predef_kcg_size_to_string(kcg_size nValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj) {
        static const int sign = IS_SIGNED(kcg_size);
        char szValue[68];
        predef_int_to_string(&nValue, sizeof(kcg_size), sign, szValue);
        return pfnStrAppend(szValue, pStrObj);
    }
#endif

#ifdef kcg_int8
    int predef_kcg_int8_to_string(kcg_int8 nValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj) {
        char szValue[10];
        predef_int_to_string(&nValue, sizeof(kcg_int8), 1, szValue);
        return pfnStrAppend(szValue, pStrObj);
    }
#endif

#ifdef kcg_int16
    int predef_kcg_int16_to_string(kcg_int16 nValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj) {
        char szValue[18];
        predef_int_to_string(&nValue, sizeof(kcg_int16), 1, szValue);
        return pfnStrAppend(szValue, pStrObj);
    }
#endif

#ifdef kcg_int32
    int predef_kcg_int32_to_string(kcg_int32 nValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj) {
        char szValue[34];
        predef_int_to_string(&nValue, sizeof(kcg_int32), 1, szValue);
        return pfnStrAppend(szValue, pStrObj);
    }
#endif

#ifdef kcg_int64
    int predef_kcg_int64_to_string(kcg_int64 nValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj) {
        char szValue[66];
        predef_int_to_string(&nValue, sizeof(kcg_int64), 1, szValue);
        return pfnStrAppend(szValue, pStrObj);
    }
#endif

#ifdef kcg_uint8
    int predef_kcg_uint8_to_string(kcg_uint8 nValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj) {
        char szValue[10];
        predef_int_to_string(&nValue, sizeof(kcg_uint8), 0, szValue);
        return pfnStrAppend(szValue, pStrObj);
    }
#endif

#ifdef kcg_uint16
    int predef_kcg_uint16_to_string(kcg_uint16 nValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj) {
        char szValue[18];
        predef_int_to_string(&nValue, sizeof(kcg_uint16), 0, szValue);
        return pfnStrAppend(szValue, pStrObj);
    }
#endif

#ifdef kcg_uint32
    int predef_kcg_uint32_to_string(kcg_uint32 nValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj) {
        char szValue[34];
        predef_int_to_string(&nValue, sizeof(kcg_uint32), 0, szValue);
        return pfnStrAppend(szValue, pStrObj);
    }
#endif

#ifdef kcg_uint64
    int predef_kcg_uint64_to_string(kcg_uint64 nValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj) {
        char szValue[66];
        predef_int_to_string(&nValue, sizeof(kcg_uint64), 0, szValue);
        return pfnStrAppend(szValue, pStrObj);
    }
#endif

#ifdef kcg_float32
    int predef_kcg_float32_to_string(kcg_float32 fValue, const char *realFormat, PFN_STR_APPEND pfnStrAppend, void *pStrObj) {
        char szValue[64];
        const char *szRealFormat = "%.10g";
        if (realFormat && *realFormat) {
            szRealFormat = realFormat;
        }
        ssm_real_to_string(&fValue, sizeof(fValue), szRealFormat, szValue, pConverter->m_bAdvancedTeCheck);
        return pfnStrAppend(szValue, pStrObj);
    }
#endif

#ifdef kcg_float64
    int predef_kcg_float64_to_string(kcg_float64 fValue, const char *realFormat, PFN_STR_APPEND pfnStrAppend, void *pStrObj) {
        char szValue[64];
        const char *szRealFormat = "%.17g";
        if (realFormat && *realFormat) {
            szRealFormat = realFormat;
        }
        ssm_real_to_string(&fValue, sizeof(fValue), szRealFormat, szValue, pConverter->m_bAdvancedTeCheck);
        return pfnStrAppend(szValue, pStrObj);
    }
#endif
