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
#include "SmuMapping.h"
#include "TEEProxy.h"

#define UNUSED(x) (void)(x)

#ifdef __cplusplus
extern "C" {
#endif

void SsmInitValues(void* pConv)
{
    UNUSED(pConv);
}

int SsmInit()
{
    return SimInit();
}

int SsmReset()
{
    return SimReset();
}

int SsmStop()
{
    return SimStop();
}

int SsmStep()
{
    /* MSC version uses _control87 in calling program */
    return SimStep();
}

const MappingScope* SsmGetMapping()
{
    return pTop;
}

SimConverter* SsmGetConverter()
{
    return pConverter;
}

#ifdef __cplusplus
} /* "C" */
#endif
