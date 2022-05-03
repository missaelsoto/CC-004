/*
 * Copyright (C) 2020  ANSYS, Inc. ALL RIGHTS RESERVED.
 * This source file may be used and distributed without restriction provided
 * that this copyright statement is not removed from the file and that any
 * derivative work contains this copyright notice.
 *
 * Warranty
 * ANSYS, Inc  makes no warranty of any kind with regard to the
 * use of this Software, either expressed or implied, including, but not
 * limited to the fitness for a particular purpose.
 */

#ifndef PLATFORM_TYPE_H
#define PLATFORM_TYPE_H

#define CPU_TYPE_8 8
#define CPU_TYPE_16 16
#define CPU_TYPE_32 32
#define MSB_FIRST 0
#define LSB_FIRST 1
#define HIGH_BYTE_FIRST 0
#define LOW_BYTE_FIRST 1

#define CPU_TYPE CPU_TYPE_32
#define CPU_BIT_ORDER LSB_FIRST
#define CPU_BYTE_ORDER HIGH_BYTE_FIRST

typedef unsigned char boolean;
typedef signed char sint8;
typedef unsigned char uint8;
typedef signed short sint16;
typedef unsigned short uint16;
typedef signed long sint32;
typedef signed long long sint64;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef signed char sint8_least;
typedef unsigned char uint8_least;
typedef signed short sint16_least;
typedef unsigned short uint16_least;
typedef signed long sint32_least;
typedef unsigned long uint32_least;

typedef float float32;
typedef double float64;

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#endif /* PLATFORM_TYPES_H */
        