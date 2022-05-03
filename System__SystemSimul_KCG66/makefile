include compiler.mk

te_ada_inc = \
	$(CCINC)"." \
	$(CCINC)".." \

te_inc = \
	$(CCINC)"." \
	$(CCINC)".." \
	$(CCINC)"C:\Program Files\ANSYS Inc\v221\SCADE\SCADE\libraries\SC65\libmathext" \

te_obj = \
	.obj/SystemSimul_System.o \
	.obj/AutonomousEmergencyBrake_AutonomousEmergencyBrake.o \
	.obj/IfCases_AutonomousEmergencyBrake.o \
	.obj/ArduinoCalculation_AutonomousEmergencyBrake.o \
	.obj/CruiseControl_CruiseControl.o \
	.obj/CruiseSpeedMgt_CruiseControl.o \
	.obj/CruiseRegulation_CruiseControl.o \
	.obj/SaturateThrottle_CruiseControl.o \
	.obj/CarModel_Car.o \
	.obj/Body_Car.o \
	.obj/PowerTrainStatic_Car.o \
	.obj/kcg_types.o \
	.obj/kcg_consts.o \
	.obj/CC-003_interface.o \
	.obj/CC-003_dll.o \
	.obj/CC-003_type.o \
	.obj/CC-003_mapping.o \
	.obj/SmuConfig.o \
	.obj/SmuTypes.o \
	.obj/SmuLib.o \
	.obj/SmuVTable.o \
	.obj/TEEProxy.o \
	.obj/te_image_lib.o \
	.obj/SmuPredefConv.o \

ur_obj = \

te_def = TEEExport.def 
te_lddef = $(LDDEF) TEEExport.def 

all: TE.dll
	@rm -f .obj/clean

TE.dll: $(te_obj) $(ur_obj) $(te_def)
	$(LD) $(USER_LDFLAGS) $(LDFLAGS) @.obj.in $(te_lddef) $(USER_LDLIBS) $(LDLIBS) $(LDOUT) TE.dll

.obj/SystemSimul_System.o: ../SystemSimul_System.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "..\SystemSimul_System.c" $(CCOUT) ".obj\SystemSimul_System.o"

.obj/AutonomousEmergencyBrake_AutonomousEmergencyBrake.o: ../AutonomousEmergencyBrake_AutonomousEmergencyBrake.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "..\AutonomousEmergencyBrake_AutonomousEmergencyBrake.c" $(CCOUT) ".obj\AutonomousEmergencyBrake_AutonomousEmergencyBrake.o"

.obj/IfCases_AutonomousEmergencyBrake.o: ../IfCases_AutonomousEmergencyBrake.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "..\IfCases_AutonomousEmergencyBrake.c" $(CCOUT) ".obj\IfCases_AutonomousEmergencyBrake.o"

.obj/ArduinoCalculation_AutonomousEmergencyBrake.o: ../ArduinoCalculation_AutonomousEmergencyBrake.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "..\ArduinoCalculation_AutonomousEmergencyBrake.c" $(CCOUT) ".obj\ArduinoCalculation_AutonomousEmergencyBrake.o"

.obj/CruiseControl_CruiseControl.o: ../CruiseControl_CruiseControl.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "..\CruiseControl_CruiseControl.c" $(CCOUT) ".obj\CruiseControl_CruiseControl.o"

.obj/CruiseSpeedMgt_CruiseControl.o: ../CruiseSpeedMgt_CruiseControl.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "..\CruiseSpeedMgt_CruiseControl.c" $(CCOUT) ".obj\CruiseSpeedMgt_CruiseControl.o"

.obj/CruiseRegulation_CruiseControl.o: ../CruiseRegulation_CruiseControl.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "..\CruiseRegulation_CruiseControl.c" $(CCOUT) ".obj\CruiseRegulation_CruiseControl.o"

.obj/SaturateThrottle_CruiseControl.o: ../SaturateThrottle_CruiseControl.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "..\SaturateThrottle_CruiseControl.c" $(CCOUT) ".obj\SaturateThrottle_CruiseControl.o"

.obj/CarModel_Car.o: ../CarModel_Car.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "..\CarModel_Car.c" $(CCOUT) ".obj\CarModel_Car.o"

.obj/Body_Car.o: ../Body_Car.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "..\Body_Car.c" $(CCOUT) ".obj\Body_Car.o"

.obj/PowerTrainStatic_Car.o: ../PowerTrainStatic_Car.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "..\PowerTrainStatic_Car.c" $(CCOUT) ".obj\PowerTrainStatic_Car.o"

.obj/kcg_types.o: ../kcg_types.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "..\kcg_types.c" $(CCOUT) ".obj\kcg_types.o"

.obj/kcg_consts.o: ../kcg_consts.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "..\kcg_consts.c" $(CCOUT) ".obj\kcg_consts.o"

.obj/CC-003_interface.o: CC-003_interface.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "CC-003_interface.c" $(CCOUT) ".obj\CC-003_interface.o"

.obj/CC-003_dll.o: CC-003_dll.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "CC-003_dll.c" $(CCOUT) ".obj\CC-003_dll.o"

.obj/CC-003_type.o: CC-003_type.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "CC-003_type.c" $(CCOUT) ".obj\CC-003_type.o"

.obj/CC-003_mapping.o: CC-003_mapping.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "CC-003_mapping.c" $(CCOUT) ".obj\CC-003_mapping.o"

.obj/SmuConfig.o: SmuConfig.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "SmuConfig.c" $(CCOUT) ".obj\SmuConfig.o"

.obj/SmuTypes.o: SmuTypes.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "SmuTypes.c" $(CCOUT) ".obj\SmuTypes.o"

.obj/SmuLib.o: SmuLib.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "SmuLib.c" $(CCOUT) ".obj\SmuLib.o"

.obj/SmuVTable.o: SmuVTable.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "SmuVTable.c" $(CCOUT) ".obj\SmuVTable.o"

.obj/TEEProxy.o: TEEProxy.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "TEEProxy.c" $(CCOUT) ".obj\TEEProxy.o"

.obj/te_image_lib.o: te_image_lib.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "te_image_lib.c" $(CCOUT) ".obj\te_image_lib.o"

.obj/SmuPredefConv.o: SmuPredefConv.c .obj/clean
	$(CC) $(te_inc) $(USER_CPPDEF) $(CPPDEF) $(USER_CFLAGS) $(CFLAGS) "SmuPredefConv.c" $(CCOUT) ".obj\SmuPredefConv.o"

.obj/clean: .obj
	@rm -f ../kcg_imported_types.h
	@rm -f ../user_macros.h
	@touch .obj/clean

.obj:
	@mkdir .obj

.PHONY: all
