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

#include "SmuTypes.h"

#ifndef NO_SMU_LIB
#   include "SmuLib.h" /* SimString* */
#endif

#define UNUSED(x) (void)(x)
#define ssm_isspace(c) ((c) == ' ' || (c) == '\t')
#define ssm_skipspace(s) while(ssm_isspace(*s)) ++s

const SimTolerance defaultSimToleranceFloat = {SSM_FLT_MIN, 0};
const SimTolerance defaultSimToleranceDouble = {SSM_DBL_MIN, 0};

/* Helpers */

static void CharToHex(char cHex, char *strHex)
{   /* assuming sizeof(char) == 1 */
    static char const*const hex_ = "0123456789ABCDEF";
    strHex[0] = hex_[(cHex & 0xF0) >> 4];
    strHex[1] = hex_[(cHex & 0x0F) >> 0];
    strHex[2] = '\0';
}

static int HexToChar(const char *strHex, char* cHex)
{   /* assuming sizeof(char) == 1 */
    *cHex = 0;
    switch (strHex[0]) {
        case '0': *cHex |= 0x0; break;
        case '1': *cHex |= 0x1; break;
        case '2': *cHex |= 0x2; break;
        case '3': *cHex |= 0x3; break;
        case '4': *cHex |= 0x4; break;
        case '5': *cHex |= 0x5; break;
        case '6': *cHex |= 0x6; break;
        case '7': *cHex |= 0x7; break;
        case '8': *cHex |= 0x8; break;
        case '9': *cHex |= 0x9; break;
        case 'a': case 'A': *cHex |= 0xA; break;
        case 'b': case 'B': *cHex |= 0xB; break;
        case 'c': case 'C': *cHex |= 0xC; break;
        case 'd': case 'D': *cHex |= 0xD; break;
        case 'e': case 'E': *cHex |= 0xE; break;
        case 'f': case 'F': *cHex |= 0xF; break;
        default: return 1;
    }
    *cHex <<= 4;
    switch (strHex[1]) {
        case '0': *cHex |= 0x0; break;
        case '1': *cHex |= 0x1; break;
        case '2': *cHex |= 0x2; break;
        case '3': *cHex |= 0x3; break;
        case '4': *cHex |= 0x4; break;
        case '5': *cHex |= 0x5; break;
        case '6': *cHex |= 0x6; break;
        case '7': *cHex |= 0x7; break;
        case '8': *cHex |= 0x8; break;
        case '9': *cHex |= 0x9; break;
        case 'a': case 'A': *cHex |= 0xA; break;
        case 'b': case 'B': *cHex |= 0xB; break;
        case 'c': case 'C': *cHex |= 0xC; break;
        case 'd': case 'D': *cHex |= 0xD; break;
        case 'e': case 'E': *cHex |= 0xE; break;
        case 'f': case 'F': *cHex |= 0xF; break;
        default: return 1;
    }
    return 0;
}

static const char* NextToken(const char *buf)
{
    unsigned char bBackslashed = 0;
    unsigned char bFirstChar = 0;
    enum {IN_STRING, IN_CHAR, OTHER} state = OTHER;
    unsigned int n = 0;
    register const char* pos = buf;
    register char c;

    while (pos) {
        c = *pos;
        if (c == 0)
            return pos;
        else if (bBackslashed)
            bBackslashed = 0;
        else {
            switch (state) {
            case IN_STRING:
                switch (c) {
                case '"':
                    state = OTHER;
                    break;
                case '\\':
                    bBackslashed = 1;
                    break;
                }
                break;
            case IN_CHAR:
                if (bFirstChar) {
                    bFirstChar=0;
                } else if (c == '\'') {
                    state = OTHER;
                }
                break;
            case OTHER:
                switch (c) {
                case '"':
                    state = IN_STRING;
                    break;
                case '\'':
                    state = IN_CHAR;
                    bFirstChar=1;
                    break;
                case '(':
                case '{':
                    n++;
                    break;
                case ')':
                case '}':
                    if (n == 0) return pos;
                    n--;
                    break;
                case ',':
                    if (n == 0) return pos;
                    break;
                }
                break;
            }
        }
        pos++;
    }
    return NULL;
}

static int StringToType(const char *str, void *pValue, SimTypeUtils *pTypeUtils, const char **endptr)
{
    const char *pszNextTok = NULL;
    size_t nTokLen = 0;
    char cEnd;

    ssm_skipspace(str);

    /* token end detection before parsing element
        - str given to m_pfnStringToType DON'T contain trailing characters. Ex: str="(1.1,2.2,3.3)"
        - token end detection done here: */
    pszNextTok = NextToken(str);
    if (pszNextTok == NULL) { /* end token not found */
        return 0;
    }
    nTokLen = pszNextTok - str;

    if (pszNextTok != str && ssm_strncmp(str, "n/a", nTokLen) != 0) {
        *endptr = str;
        cEnd = str[nTokLen]; /* keep trailer */
        ((char*)str)[nTokLen] = '\0'; /* terminate as endptr is useless, str is expected to be non-static */
        if (!pTypeUtils->m_pfnStringToType(str, pValue, (char**)endptr)) { /* conversion failed => return an error */
            ((char*)str)[nTokLen] = cEnd; /* restore trailer */
            return 0;
        }
        ((char*)str)[nTokLen] = cEnd; /* restore trailer */
        /* Conversion OK => update endptr with the last char parsed +1 
            ex:  str        points to: "1!, true)"        (1! is supposed to be an integer)
            then pszNextTok points to: ", true)"
                 endptr     points to: "!, true)" */
        if (*endptr == str) {
            *endptr += nTokLen;
        }
    }
    else {
        *endptr = pszNextTok;
    }

    return 1;
}

/* Array */

static int ArrayToString(const void *pValue,
            int (*pfnTypeToString)(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pData),
            int nSize, int nCellSize, PFN_STR_APPEND pfnStrAppend, void *pData)
{
    int i;
    pfnStrAppend("(", pData);

    for (i=0; i < nSize; i++) {
        if (i > 0)
            pfnStrAppend(", ", pData);
        pfnTypeToString(((char*)pValue + nCellSize*i), pfnStrAppend, pData);
    }

    pfnStrAppend(")", pData);
    return 1;
}

static int StringToArray(const char *str, void *pValue, SimTypeUtils *pTypeUtils, int nSize, int nCellSize, char **endptr)
{
    char cBegin;
    int bAll;
    char* p;
    int i;
    int idx;
    void *pSubValue;

    ssm_skipspace(str);

    if (*str == '(')
        bAll=1;
    else if (*str == '{')
        bAll=0;
    else    
        /* Parse error */
        return 0;

    cBegin = *str;
    str++;

    /* Unserialize array cells */
    if (bAll) { /* ( v1, v2, v3, ... , vN ) */
        for (i=0; i < nSize; i++) {
            if (i != 0) {
                if (*str != ',') {
                    /* Parse error */
                    return 0;
                }
                str++;
            }

            /* Unserialize cell */
            if (pValue != NULL)
                pSubValue = ((char*)pValue + nCellSize*i);
            else
                pSubValue = NULL;
            
            if (!StringToType(str, pSubValue, pTypeUtils, &str))
                return 0;

            ssm_skipspace(str);
        }
    } else { /* [ 1:v1, 3:v3, ... p:vP ] */
        for ( ; ; ) {
            ssm_skipspace(str);

            /*idx = strtol(str, &p, 10);*/
            ssm_string_to_int(str, &idx, sizeof(int), 1, &p);

            str = p;
            if (idx < 0 || idx >= nSize) {
                /* Parse error */
                return 0;
            }

            if (*str != ':') {
                /* Parse error */
                return 0;
            }
            str++;

            /* Unserialize cell */
            if (pValue != NULL)
                pSubValue = ((char*)pValue + nCellSize*idx);
            else
                pSubValue = NULL;

            if (!StringToType(str, pSubValue, pTypeUtils, &str))
                return 0;

            ssm_skipspace(str);

            if (*str != ',')
                break;

            str++;
        }
    }

    ssm_skipspace(str);

    if (cBegin == '(' && *str != ')') {
        /* Parse error */
        return 0;
    } else if (cBegin == '{' && *str != '}') {
        /* Parse error */
        return 0;
    }

    str++;

    *endptr = (char*)str;
    return 1;
}

#ifndef NO_SMU_LIB
    static void ArrayComparison(int *pResult, const void *pValue1, const void *pValue2, PFN_COMPARE_TYPE pfnCompareType,
                int nSize, int nCellSize, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
    {
        int i;
        unsigned j;
        int nResult=0;
        char szTmp[12];
        SimString strElemPath;
        SimStringList elemErrPaths;

        SimStringAlloc(&strElemPath);
        SimStringListAlloc(&elemErrPaths);

        for (i=0 ; i < nSize ; i++) {
        
            /* Format path "tab[index]" */
            SimStringReset(&strElemPath);
            if (pszPath)
                SimStringAppend(pszPath, &strElemPath);
            ssm_sprintf(szTmp, "[%d]", i);
            SimStringAppend(szTmp, &strElemPath);
        
            /* Do comparison of one element of the array  */
            pfnCompareType(&nResult, ((char*)pValue1 + nCellSize*i),
                                           ((char*)pValue2 + nCellSize*i),
                                           pTol, SimStringGet(&strElemPath), 
                                           SimStringListAppend, &elemErrPaths);
        }
    
        if (!(nResult & SIM_CMP_RES_EQ)) {
            /* All elements of the array are failed, return only path of the array: */
            if (pszPath &&  *pszPath!=0)
                pfnStrListAppend(pszPath, pListErrPaths);
        } else {
            /* Not all elements failed, return failed element paths : */
            for (j=0 ; j<SimStringListGetCount(&elemErrPaths) ; j++) {
                pfnStrListAppend(SimStringListGetData(&elemErrPaths)[j], pListErrPaths);
            }
        }
        *pResult|=nResult;

        SimStringFree(&strElemPath);
        SimStringListFree(&elemErrPaths);
    }
#endif /* NO_SMU_LIB */

static int GetArraySignature(PFN_GET_SIGNATURE pfnGetSignature, int nSize, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    int i;
    pfnStrAppend("(", pStrObj);
    for (i = 0; i < nSize; i++) {
        if (i > 0)
            pfnStrAppend(",", pStrObj);
        pfnGetSignature(pfnStrAppend, pStrObj);
    }
    pfnStrAppend(")", pStrObj);
    return 1;
}

/* Char Array (String) */

static int CharArrayToString(const void *pValue,
            int (* pfnTypeToString)(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pData),
            int nSize, int nCellSize, PFN_STR_APPEND pfnStrAppend, void *pData,
            int bStringsPadding, char cStringsPaddingChar)
{
    int i;
    char buffer[8];
    const char* pStr = (const char*)pValue;
    
    UNUSED(pfnTypeToString);
    
    if (bStringsPadding) {
        int i;
        for (i=nSize ; i > 0 ; i--) {
            char* pElem =((char*)pValue)+nCellSize*(i-1);
            if (*pElem != cStringsPaddingChar) {
                nSize = i;
                break;
            }
        }
        if (i == 0)
            nSize = 0;
    }

    pfnStrAppend("\"", pData);
    for (i = 0; i < nSize; i++) {
        switch (*pStr) {
            case '\0':
                buffer[0] = '\\', buffer[1] = '0', buffer[2] = '\0';
                break;
            case '\t':
                buffer[0] = '\\', buffer[1] = 't', buffer[2] = '\0';
                break;
            case '\n':
                buffer[0] = '\\', buffer[1] = 'n', buffer[2] = '\0';
                break;
            case '\r':
                buffer[0] = '\\', buffer[1] = 'r', buffer[2] = '\0';
                break;
            case '\\':
                buffer[0] = '\\', buffer[1] = '\\', buffer[2] = '\0';
                break;
            case '\"':
                buffer[0] = '\\', buffer[1] = '\"', buffer[2] = '\0';
                break;
            default:
                if (*pStr < 32 || *pStr > 126) {
                    buffer[0] = '\\', buffer[1] = 'x';
                    CharToHex(*pStr, &buffer[2]);
                    buffer[4] = '\0';
                }
                else {
                    buffer[0] = *pStr, buffer[1] = '\0';
                }
        }
        pfnStrAppend(buffer, pData);
        pStr += nCellSize;
    }
    pfnStrAppend("\"", pData);

    return 1;
}

static int StringToCharArray(const char *str, void *pValue, SimTypeUtils *pTypeUtils,
            int nSize, int nCellSize, char **endptr,
            int bStringsPadding, char cStringsPaddingChar)
{
    const char* pSrc = (char*)str;
    char* pDst = (char*)pValue;
    const char *const pDstEnd = pDst + nSize;

    UNUSED(pTypeUtils);
    UNUSED(nCellSize);

    ssm_skipspace(pSrc);
    if (!pSrc[0] || !pSrc[1] || pSrc[0] != '\"') return 0; /* not a quoted string */

    for (++pSrc; *pSrc && pDst != pDstEnd; ++pSrc, ++pDst) {
        if (*pSrc == '\\') {
            switch (*++pSrc) {
                case '0' : *pDst = '\0'; break;
                case 't' : *pDst = '\t'; break;
                case 'n' : *pDst = '\n'; break;
                case 'r' : *pDst = '\r'; break;
                case '\\': *pDst = '\\'; break;
                case '\"': *pDst = '\"'; break;
                case 'x': /* \xHH */
                    ++pSrc;
                    if (!pSrc[0] || !pSrc[1] || HexToChar(pSrc,  pDst) != 0) {
                        return 0; /* invalid hex escape */
                    }
                    ++pSrc;
                    break;
                default:
                    *pDst = '\\'; 
                    pSrc--;
            }
        }
        else if (*pSrc == '"') break;
        else *pDst = *pSrc;
    }

    if (*pSrc != '"') return 0; /* bigger or missing quote */

    if (pDst != pDstEnd) {
        if (!bStringsPadding) return 0; /* smaller */
        for ( ; pDst != pDstEnd; ++pDst) {
            *pDst = cStringsPaddingChar;
        }
    }

    *endptr = (char*)++pSrc;

    return 1;
}

/* Structure */

static int StructureToString(const void *pValue, const SimFieldUtils *pFields, int nSize,
            PFN_STR_APPEND pfnStrAppend, void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i=0 ; i < nSize ; i++) {
        if (i > 0 )
            pfnStrAppend(", ", pData);
        pFields[i].m_pTypeUtils->m_pfnTypeToString((char*)pValue + pFields[i].m_nOffset, pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

static int StringToStructure(const char *str, void *pValue, const SimFieldUtils *pFields, int nSize, char **endptr)
{
    char cBegin;
    int bAll;
    int i;
    const SimFieldUtils *pField;
    void *pSubValue;
    const char *pAux;
    size_t len;

    ssm_skipspace(str);

    if (*str == '(')
        bAll=1;
    else if (*str == '{' )
        bAll=0;
    else    /* Parse error */
        return 0;

    cBegin = *str;
    str++;

    /* Unserialize fields */
    if (bAll) { /* ( v1, v2, v3, ... , vN ) */
        pField = pFields;
        for (i=0 ; i < nSize ; pField++, i++) {
            if (i > 0) {
                if (*str != ',') {
                    /* Parse error */
                    return 0;
                }
                str++;
            }

            /* Unserialize cell */
            if (pValue != NULL)
                pSubValue = (char*)pValue + pField->m_nOffset;
            else
                pSubValue = NULL;
    
            if (!StringToType(str, pSubValue, pField->m_pTypeUtils, &str))
                return 0;

            ssm_skipspace(str);
        }
    } else { /* { field1:v1, field3:v3, ... fieldp:vP } */

        for (;;) {

            ssm_skipspace(str);

            /* Search for field */
            pAux = str;
            while (*pAux != 0 && *pAux != ' ' && *pAux != ':')
                pAux++;
            len = pAux - str;
            for (i = 0, pField = pFields; i < nSize ; i++, pField++) {
                if (ssm_strncmp(pField->m_szScadeName, str, len) == 0 && pField->m_szScadeName[len] == '\0')
                    break;
            }
            if (i == nSize) {
                /* Parse error: invalid field name */
                return 0;
            }

            str = str + len;
            if (*str != ':') {
                /* Parse error */
                return 0;
            }
            str++;

            /* Unserialize cell */
            if (pValue != NULL)
                pSubValue = (char*)pValue + pField->m_nOffset;
            else
                pSubValue = NULL;

           if (!StringToType(str, pSubValue, pField->m_pTypeUtils, &str))
                return 0;

            ssm_skipspace(str);

            if (*str != ',')
                break;

            str++;
        }
    }

    ssm_skipspace(str);

    if (cBegin == '(' && *str != ')') {
        /* Parse error */
        return 0;
    } else if (cBegin == '{' && *str != '}') {
        /* Parse error */
        return 0;
    }

    str++;

    *endptr = (char*)str;
    return 1;
}

#ifndef NO_SMU_LIB
    static void StructureComparison(int *pResult, const void *pValue1, const void *pValue2,
               const SimFieldUtils *pFields, int nSize, SimTolerance *pTol, const char *pszPath, PFN_STR_APPEND pfnStrListAppend, void *pListErrPaths)
    {
        int i;
        unsigned j;
        int nResult=0;
        SimString strElemPath;
        SimStringList elemErrPaths;

        SimStringAlloc(&strElemPath);
        SimStringListAlloc(&elemErrPaths);

        for (i=0 ; i < nSize ; i++) {

            /* Format path "var_struct.element" */
            SimStringReset(&strElemPath);
            if (pszPath)
                SimStringAppend(pszPath, &strElemPath);
            SimStringAppend(".", &strElemPath);
            SimStringAppend(pFields[i].m_szScadeName, &strElemPath);

            pFields[i].m_pTypeUtils->m_pfnCompareType(&nResult,
                            (char*)pValue1 + pFields[i].m_nOffset,
                            (char*)pValue2 + pFields[i].m_nOffset,
                            pTol,
                            SimStringGet(&strElemPath),
                            SimStringListAppend, &elemErrPaths);
        }

        if (!(nResult & SIM_CMP_RES_EQ)) {
            /* All elements of the structure are failed, return only path of the array: */
            if (pszPath &&  *pszPath!=0)
                pfnStrListAppend(pszPath, pListErrPaths);
        } else {
            /* Not all elements failed, return failed element paths : */
            for (j=0 ; j<SimStringListGetCount(&elemErrPaths) ; j++) {
                pfnStrListAppend(SimStringListGetData(&elemErrPaths)[j], pListErrPaths);
            }
        }
        *pResult|=nResult;
    
        SimStringFree(&strElemPath);
        SimStringListFree(&elemErrPaths);
    }
#endif /* NO_SMU_LIB */

static int GetStructureSignature(const SimFieldUtils *pFields, int nSize, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    int i;
    pfnStrAppend("(", pStrObj);
    for (i = 0; i<nSize; i++) {
        if (i > 0)
            pfnStrAppend(",", pStrObj);
        pFields[i].m_pTypeUtils->m_pfnGetSignature(pfnStrAppend, pStrObj);
    }
    pfnStrAppend(")", pStrObj);
    return 1;
}

/* Enum */

int StringToEnum(const char *strValue, int *pValue, const SimEnumValUtils *pEnumVals, int nSize, char **endptr)
{
    const char *p;
    size_t i;
    size_t len;
    if (nSize <= 0) {
        return 0;
    }
    ssm_skipspace(strValue);
    p = strValue;
    while (*p != '\0' && *p != ')' && *p != '}' && *p != ' ' && *p != '\t') {
        ++p;
    }
    len = p - strValue;
    for (i = 0 ; i < (size_t)nSize ; i++) {
        if (ssm_strncmp(pEnumVals[i].m_szScadeName, strValue, len) == 0 && pEnumVals[i].m_szScadeName[len] == '\0') {
            if (pValue) {
                *pValue = pEnumVals[i].m_nVal;
            }
            *endptr = (char*)p;
            return 1;
        }
    }
    /* Parse error */
    return 0;
}

int EnumToString(int nValue, const SimEnumValUtils *pEnumVals, int nSize, PFN_STR_APPEND pfnStrAppend, void *pData)
{
    int i;
    const SimEnumValUtils *pEnumVal;
    for (i=0 ; i<nSize ; i++) {
        pEnumVal = &pEnumVals[i];
        if (pEnumVal->m_nVal == nValue) {
            return pfnStrAppend(pEnumVal->m_szScadeName, pData);
        }
    }
    /* --> save_snapshot: Hack for missing IntputChanged _init function for KCG6.4
       unitialized context memory of enum type with pragma value = 1 (thus 0 is not a valid value...)
       Let's take the first enum value*/
    if (nSize > 0)
        return pfnStrAppend(pEnumVals[0].m_szScadeName, pData);
    /*<--end hack*/
    return pfnStrAppend("?", pData);
}

static int GetEnumSignature(const SimEnumValUtils *pEnumVals, int nSize, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    int i;
    pfnStrAppend("E", pStrObj);
    for (i = 0; i<nSize; i++) {
        pfnStrAppend("|", pStrObj);
        pfnStrAppend(pEnumVals[i].m_szScadeName, pStrObj);
    }
    return 1;
}

/* Imported */

int ImportedToString(const void *pValue, unsigned nSizeOf, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    unsigned char const* p;
    unsigned char const* e;
    char b[3] = {0};
    if (!pfnStrAppend || !pStrObj) {
        return 0;
    }
    for (p = (unsigned char*)pValue, e = p + nSizeOf; p != e; ++p) {
        CharToHex(*p, &b[0]);
        if (!pfnStrAppend(b, pStrObj)) {
            return 0;
        }
    }
    return 1;
}

int StringToImported(const char *str, void *pValue, unsigned nSizeOf, char **endptr)
{
    char* v;
    char const* e;
    char c;
    for (v = (char*)pValue, e = v + nSizeOf; v != e; *v = c, ++v, str += 2) {
        if (HexToChar(str, &c) != 0) {
            return 0;
        }
    }
    if (endptr) {
        *endptr = (char*)str;
    }
    return 1;
}

static unsigned Compare(const char *lhs, const char *rhs)
{
    unsigned i = 0U;
    for ( ; lhs[i]; ++i)
        if (lhs[i] != rhs[i])
            return 0U;
    return rhs[i] == '\0' ? i : 0U;
}

/* Constants */
int StringToConstant(const char *strValue, void *pValue, const SimConstValUtils *pConstVals, unsigned nTableSize, unsigned nTypeSize, char **endptr)
{
    unsigned i = 0, len;
    for ( ; i < nTableSize; ++i) {
        len = Compare(pConstVals[i].m_szScadeName, strValue);
        if (len) {
            ssm_memcpy(pValue, pConstVals[i].m_pVal, nTypeSize);
            *endptr = (char*)strValue + len;
            return 1;
        }
    }
    return 0;
}

static SimConverter converter = {

    ArrayToString,
    StringToArray,
#   ifndef NO_SMU_LIB
        ArrayComparison,
#   else
        NULL,
#   endif
    GetArraySignature,

    CharArrayToString,
    StringToCharArray,

    StructureToString,
    StringToStructure,
#   ifndef NO_SMU_LIB
        StructureComparison,
#   else
        NULL,
#   endif
    GetStructureSignature,

    EnumToString,
    StringToEnum,
    GetEnumSignature,

    ImportedToString,
    StringToImported,

    StringToConstant,

    0,              /* m_bDisplayStrings */
    0,              /* m_bStringsPadding */
    0,              /* m_bImportedAsHex */
    0,              /* m_bAdvancedTeCheck */
    IDB_DEFAULT,    /* m_IntDisplayBase */
    "%.17g",        /* m_RealFormat */
    '\0'            /* m_cStringsPaddingChar */
};

#ifdef __cplusplus
extern "C" {
#endif
    SimConverter* pConverter = &converter;
#ifdef __cplusplus
}
#endif
