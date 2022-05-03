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

#ifndef _TEE_PROXY_H_
#define _TEE_PROXY_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  SimErrCode_t{
    SmecNoError,        /* No error                     */
    SmecErrBadFormat,   /* Bad format                   */
    SmecErrBadMagic,    /* Bad magic number             */
    SmecErrFileRead,    /* Cannot open file for reading */
    SmecErrFileWrite,   /* Cannot open file for writing */
    SmecErrFileClose,   /* Cannot close  file           */
    SmecErrWrite,       /* Failed write operation       */
    SmecErrRead,        /* Failed read operation        */
    SmecErrUnknown      /* Unknown error                */
} SimErrCode;

/* To be provided by wrapping code (x_interface.c): */
extern int SimInit();
extern int SimReset();
extern int SimStep();
extern int SimStop();


#ifdef __cplusplus
} /* "C" */
#endif

#endif /* _TEE_PROXY_H_ */
