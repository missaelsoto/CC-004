/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Command: kcg662.exe -config C:/Users/missael/Documents/CINVESTAV/embedded critical software/Project/CC-003/System__SystemSimul_KCG66/config.txt
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */
#ifndef _KCG_TYPES_H_
#define _KCG_TYPES_H_

#include "stddef.h"

#define KCG_MAPW_CPY

#ifndef kcg_char
#define kcg_char kcg_char
typedef char kcg_char;
#endif /* kcg_char */

#ifndef kcg_bool
#define kcg_bool kcg_bool
typedef unsigned char kcg_bool;
#endif /* kcg_bool */

#ifndef kcg_float32
#define kcg_float32 kcg_float32
typedef float kcg_float32;
#endif /* kcg_float32 */

#ifndef kcg_float64
#define kcg_float64 kcg_float64
typedef double kcg_float64;
#endif /* kcg_float64 */

#ifndef kcg_size
#define kcg_size kcg_size
typedef ptrdiff_t kcg_size;
#endif /* kcg_size */

#ifndef kcg_uint64
#define kcg_uint64 kcg_uint64
typedef unsigned long long kcg_uint64;
#endif /* kcg_uint64 */

#ifndef kcg_uint32
#define kcg_uint32 kcg_uint32
typedef unsigned long kcg_uint32;
#endif /* kcg_uint32 */

#ifndef kcg_uint16
#define kcg_uint16 kcg_uint16
typedef unsigned short kcg_uint16;
#endif /* kcg_uint16 */

#ifndef kcg_uint8
#define kcg_uint8 kcg_uint8
typedef unsigned char kcg_uint8;
#endif /* kcg_uint8 */

#ifndef kcg_int64
#define kcg_int64 kcg_int64
typedef signed long long kcg_int64;
#endif /* kcg_int64 */

#ifndef kcg_int32
#define kcg_int32 kcg_int32
typedef signed long kcg_int32;
#endif /* kcg_int32 */

#ifndef kcg_int16
#define kcg_int16 kcg_int16
typedef signed short kcg_int16;
#endif /* kcg_int16 */

#ifndef kcg_int8
#define kcg_int8 kcg_int8
typedef signed char kcg_int8;
#endif /* kcg_int8 */

#ifndef kcg_lit_float32
#define kcg_lit_float32(kcg_C1) ((kcg_float32) (kcg_C1))
#endif /* kcg_lit_float32 */

#ifndef kcg_lit_float64
#define kcg_lit_float64(kcg_C1) ((kcg_float64) (kcg_C1))
#endif /* kcg_lit_float64 */

#ifndef kcg_lit_size
#define kcg_lit_size(kcg_C1) ((kcg_size) (kcg_C1))
#endif /* kcg_lit_size */

#ifndef kcg_lit_uint64
#define kcg_lit_uint64(kcg_C1) ((kcg_uint64) (kcg_C1))
#endif /* kcg_lit_uint64 */

#ifndef kcg_lit_uint32
#define kcg_lit_uint32(kcg_C1) ((kcg_uint32) (kcg_C1))
#endif /* kcg_lit_uint32 */

#ifndef kcg_lit_uint16
#define kcg_lit_uint16(kcg_C1) ((kcg_uint16) (kcg_C1))
#endif /* kcg_lit_uint16 */

#ifndef kcg_lit_uint8
#define kcg_lit_uint8(kcg_C1) ((kcg_uint8) (kcg_C1))
#endif /* kcg_lit_uint8 */

#ifndef kcg_lit_int64
#define kcg_lit_int64(kcg_C1) ((kcg_int64) (kcg_C1))
#endif /* kcg_lit_int64 */

#ifndef kcg_lit_int32
#define kcg_lit_int32(kcg_C1) ((kcg_int32) (kcg_C1))
#endif /* kcg_lit_int32 */

#ifndef kcg_lit_int16
#define kcg_lit_int16(kcg_C1) ((kcg_int16) (kcg_C1))
#endif /* kcg_lit_int16 */

#ifndef kcg_lit_int8
#define kcg_lit_int8(kcg_C1) ((kcg_int8) (kcg_C1))
#endif /* kcg_lit_int8 */

#ifndef kcg_false
#define kcg_false ((kcg_bool) 0)
#endif /* kcg_false */

#ifndef kcg_true
#define kcg_true ((kcg_bool) 1)
#endif /* kcg_true */

#ifndef kcg_lsl_uint64
#define kcg_lsl_uint64(kcg_C1, kcg_C2)                                        \
  ((kcg_uint64) ((kcg_C1) << (kcg_C2)) & 0xffffffffffffffff)
#endif /* kcg_lsl_uint64 */

#ifndef kcg_lsl_uint32
#define kcg_lsl_uint32(kcg_C1, kcg_C2)                                        \
  ((kcg_uint32) ((kcg_C1) << (kcg_C2)) & 0xffffffff)
#endif /* kcg_lsl_uint32 */

#ifndef kcg_lsl_uint16
#define kcg_lsl_uint16(kcg_C1, kcg_C2)                                        \
  ((kcg_uint16) ((kcg_C1) << (kcg_C2)) & 0xffff)
#endif /* kcg_lsl_uint16 */

#ifndef kcg_lsl_uint8
#define kcg_lsl_uint8(kcg_C1, kcg_C2)                                         \
  ((kcg_uint8) ((kcg_C1) << (kcg_C2)) & 0xff)
#endif /* kcg_lsl_uint8 */

#ifndef kcg_lnot_uint64
#define kcg_lnot_uint64(kcg_C1) ((kcg_C1) ^ 0xffffffffffffffff)
#endif /* kcg_lnot_uint64 */

#ifndef kcg_lnot_uint32
#define kcg_lnot_uint32(kcg_C1) ((kcg_C1) ^ 0xffffffff)
#endif /* kcg_lnot_uint32 */

#ifndef kcg_lnot_uint16
#define kcg_lnot_uint16(kcg_C1) ((kcg_C1) ^ 0xffff)
#endif /* kcg_lnot_uint16 */

#ifndef kcg_lnot_uint8
#define kcg_lnot_uint8(kcg_C1) ((kcg_C1) ^ 0xff)
#endif /* kcg_lnot_uint8 */

#ifndef kcg_assign
#include "kcg_assign.h"
#endif /* kcg_assign */

#ifndef kcg_assign_struct
#define kcg_assign_struct kcg_assign
#endif /* kcg_assign_struct */

#ifndef kcg_assign_array
#define kcg_assign_array kcg_assign
#endif /* kcg_assign_array */

/* truthtables::TruthTableValues/ */
typedef enum kcg_tag_TruthTableValues_truthtables {
  T_truthtables,
  F_truthtables,
  X_truthtables
} TruthTableValues_truthtables;
/* Defs::tCruiseState/ */
typedef enum kcg_tag_tCruiseState_Defs {
  OFF_Defs,
  INT_Defs,
  STDBY_Defs,
  ON_Defs
} tCruiseState_Defs;
/* CruiseControl::CruiseControl/SM1: */
typedef enum kcg_tag__5_SSM_TR_SM1 {
  _10_SSM_TR_no_trans_SM1,
  _11_SSM_TR_Off_Enabled_1_Off_SM1,
  _12_SSM_TR_Enabled_Off_1_Enabled_SM1
} _5_SSM_TR_SM1;
/* CruiseControl::CruiseControl/SM1: */
typedef enum kcg_tag__4_SSM_ST_SM1 {
  SSM_st_Off_SM1,
  SSM_st_Enabled_SM1
} _4_SSM_ST_SM1;
/* CruiseControl::CruiseControl/SM1:Enabled:SM2: */
typedef enum kcg_tag__3_SSM_TR_SM2_Enabled_SM1 {
  _9_SSM_TR_no_trans_SM2_Enabled_SM1,
  SSM_TR_Active_Interrupt_1_Active_SM2_Enabled_SM1,
  SSM_TR_Interrupt_Active_1_Interrupt_SM2_Enabled_SM1
} _3_SSM_TR_SM2_Enabled_SM1;
/* CruiseControl::CruiseControl/SM1:Enabled:SM2: */
typedef enum kcg_tag__2_SSM_ST_SM2_Enabled_SM1 {
  SSM_st_Active_SM2_Enabled_SM1,
  SSM_st_Interrupt_SM2_Enabled_SM1
} _2_SSM_ST_SM2_Enabled_SM1;
/* CruiseControl::CruiseControl/SM1:Enabled:SM2:Active:SM3: */
typedef enum kcg_tag_SSM_TR_SM3_Active_SM2_Enabled_SM1 {
  SSM_TR_no_trans_SM3_Active_SM2_Enabled_SM1,
  SSM_TR_On_StandBy_1_On_SM3_Active_SM2_Enabled_SM1,
  SSM_TR_StandBy_On_1_StandBy_SM3_Active_SM2_Enabled_SM1
} SSM_TR_SM3_Active_SM2_Enabled_SM1;
/* CruiseControl::CruiseControl/SM1:Enabled:SM2:Active:SM3: */
typedef enum kcg_tag_SSM_ST_SM3_Active_SM2_Enabled_SM1 {
  SSM_st_On_SM3_Active_SM2_Enabled_SM1,
  SSM_st_StandBy_SM3_Active_SM2_Enabled_SM1
} SSM_ST_SM3_Active_SM2_Enabled_SM1;
/* AutonomousEmergencyBrake::AutonomousEmergencyBrake/SM1: */
typedef enum kcg_tag_SSM_TR_SM1 {
  SSM_TR_no_trans_SM1,
  SSM_TR_Off_Enabled_1_Off_SM1,
  SSM_TR_Enabled_Off_1_Enabled_SM1
} SSM_TR_SM1;
/* AutonomousEmergencyBrake::AutonomousEmergencyBrake/SM1: */
typedef enum kcg_tag_SSM_ST_SM1 {
  _6_SSM_st_Off_SM1,
  _7_SSM_st_Enabled_SM1
} SSM_ST_SM1;
/* AutonomousEmergencyBrake::AutonomousEmergencyBrake/SM1:Enabled:SM2: */
typedef enum kcg_tag_SSM_TR_SM2_Enabled_SM1 {
  SSM_TR_no_trans_SM2_Enabled_SM1,
  SSM_TR_Active_Standby_1_Active_SM2_Enabled_SM1,
  SSM_TR_Standby_Active_1_Standby_SM2_Enabled_SM1
} SSM_TR_SM2_Enabled_SM1;
/* AutonomousEmergencyBrake::AutonomousEmergencyBrake/SM1:Enabled:SM2: */
typedef enum kcg_tag_SSM_ST_SM2_Enabled_SM1 {
  _8_SSM_st_Active_SM2_Enabled_SM1,
  SSM_st_Standby_SM2_Enabled_SM1
} SSM_ST_SM2_Enabled_SM1;
/* CarType::tRpm/ */
typedef kcg_float64 tRpm_CarType;

/* Defs::tRpm/ */
typedef kcg_float64 tRpm_Defs;

/* CarType::tTorq/ */
typedef kcg_float64 tTorq_CarType;

/* CarType::tPercent/ */
typedef kcg_float64 tPercent_CarType;

/* CarType::tSpeed/ */
typedef kcg_float64 tSpeed_CarType;

/* Defs::tPercent/ */
typedef kcg_float64 tPercent_Defs;

/* Defs::tSpeed/ */
typedef kcg_float64 tSpeed_Defs;

typedef kcg_float64 array_float64_5[5];

#ifndef kcg_copy_array_float64_5
#define kcg_copy_array_float64_5(kcg_C1, kcg_C2)                              \
  (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (array_float64_5)))
#endif /* kcg_copy_array_float64_5 */

#ifdef kcg_use_array_float64_5
#ifndef kcg_comp_array_float64_5
extern kcg_bool kcg_comp_array_float64_5(
  array_float64_5 *kcg_c1,
  array_float64_5 *kcg_c2);
#endif /* kcg_comp_array_float64_5 */
#endif /* kcg_use_array_float64_5 */

#endif /* _KCG_TYPES_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** kcg_types.h
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

