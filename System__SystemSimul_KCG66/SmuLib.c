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

#include "SmuLib.h"
#include "SmuTypes.h"

/* Helpers */

static void *SimAlloc(size_t nobj, size_t size)
{
    return ssm_malloc(nobj * size);
}
#define SimFree ssm_free

void* SimRealloc(void* pOld, unsigned nOldSize, unsigned nNewSize, SIM_PFN_ALLOCMEM pfnAllocMem, SIM_PFN_FREEMEM pfnFreeMem)
{
    void* pNew = pfnAllocMem(nNewSize, 1);
    ssm_memcpy(pNew, pOld, nOldSize < nNewSize ? nOldSize : nNewSize);
    pfnFreeMem(pOld);
    return pNew;
}

/* String management */

void SimStringAlloc(SimString* pString)
{
    SimStringAllocEx(pString, SimAlloc, SimFree);
}

void SimStringAllocEx(SimString* pString, SIM_PFN_ALLOCMEM pfnAllocMem, SIM_PFN_FREEMEM pfnFreeMem)
{
    pString->m_pfnAllocMem = pfnAllocMem;
    pString->m_pfnFreeMem = pfnFreeMem;
    pString->m_nSize = SIMSTRING_INIT_SIZE;
    pString->m_pszBase = (char*)pString->m_pfnAllocMem(pString->m_nSize, sizeof(char));
    SimStringReset(pString);
}

void SimStringReset(SimString* pString)
{
    *pString->m_pszBase = '\0';
    pString->m_nLength = 0;
}

int SimStringAppend(const char* str, void* pStr)
{
    SimString *pString = (SimString*)pStr;
    cpy: while (*str && pString->m_nLength < pString->m_nSize) {
        pString->m_pszBase[pString->m_nLength++] = *str++;
    }
    if (pString->m_nLength == pString->m_nSize) {
        pString->m_pszBase = (char*)SimRealloc(pString->m_pszBase, pString->m_nSize, pString->m_nSize * 2, pString->m_pfnAllocMem, pString->m_pfnFreeMem);
        pString->m_nSize *= 2;
        goto cpy;
    }
    pString->m_pszBase[pString->m_nLength] = *str;
    return 1;
}

const char* SimStringGet(SimString* pString)
{
    return pString && pString->m_pszBase ? pString->m_pszBase : "";
}

void SimStringFree(SimString* pString)
{
    if (pString->m_pszBase != NULL)
        pString->m_pfnFreeMem(pString->m_pszBase);
}

/* String list management */

void SimStringListAlloc(SimStringList* pStringList)
{
    SimStringListAllocEx(pStringList, SimAlloc, SimFree);
}

void SimStringListAllocEx(SimStringList* pStringList, SIM_PFN_ALLOCMEM pfnAllocMem, SIM_PFN_FREEMEM pfnFreeMem)
{
    pStringList->m_pfnAllocMem = pfnAllocMem;
    pStringList->m_pfnFreeMem = pfnFreeMem;
    pStringList->m_nSize = SIMSTRINGLIST_INIT_SIZE ;
    pStringList->m_nCount = 0;
    pStringList->m_pData = (char**) pStringList->m_pfnAllocMem(pStringList->m_nSize, sizeof(char*));
    SimStringListReset(pStringList);
}

void SimStringListReset(SimStringList* pStringList)
{
    unsigned i;
    if (pStringList->m_pData) {
        for (i = 0; i < pStringList->m_nCount; i++)
            pStringList->m_pfnFreeMem(pStringList->m_pData[i]);
    }
    pStringList->m_nCount = 0;
}

int SimStringListAppend(const char* str, void* pList)
{
    SimString elm;
    SimStringList *pStringList = (SimStringList*)pList;
    if (*str) {
        if (pStringList->m_nCount + 1 > pStringList->m_nSize) {
            pStringList->m_nSize *= 2;
            pStringList->m_pData = (char**)SimRealloc(pStringList->m_pData, pStringList->m_nCount * sizeof(char*), pStringList->m_nSize * sizeof(char*), pStringList->m_pfnAllocMem, pStringList->m_pfnFreeMem);
        }
        SimStringAllocEx(&elm, pStringList->m_pfnAllocMem, pStringList->m_pfnFreeMem);
        SimStringAppend(str, &elm);
        pStringList->m_pData[pStringList->m_nCount++] = elm.m_pszBase;
    }
    return 1;
}

const char** SimStringListGetData(SimStringList* pStringList)
{
    return (const char**)pStringList->m_pData;
}

unsigned SimStringListGetCount(SimStringList* pStringList)
{
    return pStringList->m_nCount;
}

void SimStringListFree(SimStringList* pStringList)
{
    SimStringListReset(pStringList);
    if (pStringList->m_pData) {
        pStringList->m_pfnFreeMem(pStringList->m_pData);
    }
}
