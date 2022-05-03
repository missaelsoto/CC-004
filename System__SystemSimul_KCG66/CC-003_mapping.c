/* CC-003_mapping.c */

#include "CC-003_type.h"
#include "CC-003_interface.h"
#include "CC-003_mapping.h"

#include "SmuTypes.h"
#include "SmuMapping.h"

#include "kcg_sensors.h"

/* mapping declaration */

#define DECL_ITER(name) extern const MappingIterator iter_##name


#define DECL_SCOPE(name, count) extern const MappingEntry name##_entries[count]; extern const MappingScope name

DECL_SCOPE(scope_11, 1);
DECL_SCOPE(scope_10, 1);
DECL_SCOPE(scope_9, 1);
DECL_SCOPE(scope_8, 1);
DECL_SCOPE(scope_7, 3);
DECL_SCOPE(scope_6, 1);
DECL_SCOPE(scope_5, 2);
DECL_SCOPE(scope_4, 1);
DECL_SCOPE(scope_3, 1);
DECL_SCOPE(scope_2, 3);
DECL_SCOPE(scope_1, 7);
DECL_SCOPE(scope_0, 1);

/* clock definition */


/* mapping definition */


const MappingEntry scope_11_entries[1] = {
    /* 0 */ { MAP_STRONG_TRANSITION, ">:", NULL, 0, 0, NULL, NULL, NULL, NULL, 1, 0 }
};
const MappingScope scope_11 = {
    "AutonomousEmergencyBrake::AutonomousEmergencyBrake/ AutonomousEmergencyBrake_AutonomousEmergencyBrakeSM1:Enabled:SM2:Standby:<1",
    scope_11_entries, 1
};

const MappingEntry scope_10_entries[1] = {
    /* 0 */ { MAP_FORK, "<1", NULL, 0, 0, NULL, NULL, NULL, &scope_11, 1, 0 }
};
const MappingScope scope_10 = {
    "AutonomousEmergencyBrake::AutonomousEmergencyBrake/ AutonomousEmergencyBrake_AutonomousEmergencyBrakeSM1:Enabled:SM2:Standby:",
    scope_10_entries, 1
};

const MappingEntry scope_9_entries[1] = {
    /* 0 */ { MAP_STRONG_TRANSITION, ">:", NULL, 0, 0, NULL, NULL, NULL, NULL, 1, 0 }
};
const MappingScope scope_9 = {
    "AutonomousEmergencyBrake::AutonomousEmergencyBrake/ AutonomousEmergencyBrake_AutonomousEmergencyBrakeSM1:Enabled:SM2:Active:<1",
    scope_9_entries, 1
};

const MappingEntry scope_8_entries[1] = {
    /* 0 */ { MAP_FORK, "<1", NULL, 0, 0, NULL, NULL, NULL, &scope_9, 1, 0 }
};
const MappingScope scope_8 = {
    "AutonomousEmergencyBrake::AutonomousEmergencyBrake/ AutonomousEmergencyBrake_AutonomousEmergencyBrakeSM1:Enabled:SM2:Active:",
    scope_8_entries, 1
};

const MappingEntry scope_7_entries[3] = {
    /* 0 */ { MAP_LOCAL, "@next_state", NULL, sizeof(SSM_ST_SM2_Enabled_SM1), (size_t)&outputs_ctx.SM2_state_nxt_Enabled_SM1, &_Type_SSM_ST_SM2_Enabled_SM1_Utils, NULL, NULL, NULL, 0, 0 },
    /* 1 */ { MAP_STATE, "Active:", NULL, 0, 0, NULL, NULL, NULL, &scope_8, 1, 1 },
    /* 2 */ { MAP_STATE, "Standby:", NULL, 0, 0, NULL, NULL, NULL, &scope_10, 1, 2 }
};
const MappingScope scope_7 = {
    "AutonomousEmergencyBrake::AutonomousEmergencyBrake/ AutonomousEmergencyBrake_AutonomousEmergencyBrakeSM1:Enabled:SM2:",
    scope_7_entries, 3
};

const MappingEntry scope_6_entries[1] = {
    /* 0 */ { MAP_STRONG_TRANSITION, ">:", NULL, 0, 0, NULL, NULL, NULL, NULL, 1, 0 }
};
const MappingScope scope_6 = {
    "AutonomousEmergencyBrake::AutonomousEmergencyBrake/ AutonomousEmergencyBrake_AutonomousEmergencyBrakeSM1:Enabled:<1",
    scope_6_entries, 1
};

const MappingEntry scope_5_entries[2] = {
    /* 0 */ { MAP_FORK, "<1", NULL, 0, 0, NULL, NULL, NULL, &scope_6, 1, 0 },
    /* 1 */ { MAP_AUTOMATON, "SM2:", NULL, 0, 0, NULL, NULL, NULL, &scope_7, 1, 1 }
};
const MappingScope scope_5 = {
    "AutonomousEmergencyBrake::AutonomousEmergencyBrake/ AutonomousEmergencyBrake_AutonomousEmergencyBrakeSM1:Enabled:",
    scope_5_entries, 2
};

const MappingEntry scope_4_entries[1] = {
    /* 0 */ { MAP_STRONG_TRANSITION, ">:", NULL, 0, 0, NULL, NULL, NULL, NULL, 1, 0 }
};
const MappingScope scope_4 = {
    "AutonomousEmergencyBrake::AutonomousEmergencyBrake/ AutonomousEmergencyBrake_AutonomousEmergencyBrakeSM1:Off:<1",
    scope_4_entries, 1
};

const MappingEntry scope_3_entries[1] = {
    /* 0 */ { MAP_FORK, "<1", NULL, 0, 0, NULL, NULL, NULL, &scope_4, 1, 0 }
};
const MappingScope scope_3 = {
    "AutonomousEmergencyBrake::AutonomousEmergencyBrake/ AutonomousEmergencyBrake_AutonomousEmergencyBrakeSM1:Off:",
    scope_3_entries, 1
};

const MappingEntry scope_2_entries[3] = {
    /* 0 */ { MAP_LOCAL, "@next_state", NULL, sizeof(SSM_ST_SM1), (size_t)&outputs_ctx.SM1_state_nxt, &_Type_SSM_ST_SM1_Utils, NULL, NULL, NULL, 0, 0 },
    /* 1 */ { MAP_STATE, "Off:", NULL, 0, 0, NULL, NULL, NULL, &scope_3, 1, 1 },
    /* 2 */ { MAP_STATE, "Enabled:", NULL, 0, 0, NULL, NULL, NULL, &scope_5, 1, 2 }
};
const MappingScope scope_2 = {
    "AutonomousEmergencyBrake::AutonomousEmergencyBrake/ AutonomousEmergencyBrake_AutonomousEmergencyBrakeSM1:",
    scope_2_entries, 3
};

const MappingEntry scope_1_entries[7] = {
    /* 0 */ { MAP_OUTPUT, "BrakePercent", NULL, sizeof(tPercent_CarType), (size_t)&outputs_ctx.BrakePercent, &_Type_tPercent_CarType_Utils, NULL, NULL, NULL, 1, 0 },
    /* 1 */ { MAP_INPUT, "On", NULL, sizeof(kcg_bool), (size_t)&On, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 1 },
    /* 2 */ { MAP_INPUT, "Off", NULL, sizeof(kcg_bool), (size_t)&Off, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 2 },
    /* 3 */ { MAP_INPUT, "SteeringWheel", NULL, sizeof(kcg_bool), (size_t)&SteeringWheel, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 3 },
    /* 4 */ { MAP_INPUT, "Time", NULL, sizeof(kcg_float64), (size_t)&Time, &_Type_kcg_float64_Utils, NULL, NULL, NULL, 1, 4 },
    /* 5 */ { MAP_INPUT, "Brake", NULL, sizeof(tPercent_CarType), (size_t)&Brake, &_Type_tPercent_CarType_Utils, NULL, NULL, NULL, 1, 5 },
    /* 6 */ { MAP_AUTOMATON, "SM1:", NULL, 0, 0, NULL, NULL, NULL, &scope_2, 1, 6 }
};
const MappingScope scope_1 = {
    "AutonomousEmergencyBrake::AutonomousEmergencyBrake/ AutonomousEmergencyBrake_AutonomousEmergencyBrake",
    scope_1_entries, 7
};

const MappingEntry scope_0_entries[1] = {
    /* 0 */ { MAP_ROOT, "AutonomousEmergencyBrake::AutonomousEmergencyBrake", NULL, 0, 0, NULL, NULL, NULL, &scope_1, 1, 0 }
};
const MappingScope scope_0 = {
    "",
    scope_0_entries, 1
};

/* entry point */
const MappingScope* pTop = &scope_0;
