/*
 * File: ACCS_MainLogic.h
 *
 * Code generated for Simulink model 'ACCS_subsystem_integrated'.
 *
 * Model version                  : 1.1217
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 17:55:27 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. Safety precaution
 *    3. Execution efficiency
 *    4. RAM efficiency
 *    5. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ACCS_MainLogic_h_
#define RTW_HEADER_ACCS_MainLogic_h_
#include <math.h>
#include <string.h>
#ifndef ACCS_subsystem_integrated_COMMON_INCLUDES_
# define ACCS_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ACCS_subsystem_integrated_COMMON_INCLUDES_ */

#include "ACCS_subsystem_integrated_types.h"

extern void CalcACCS_EgoVehicleTargetSpeed(void);
extern void CalcACCS_OpenAccel(void);
extern void DtrmnACCS_AccelAndSpdLimit(void);
extern void DtrmnACCS_DsrdLonControlParm(void);
extern void DtrmnACCS_EgoStatusFrmCan(void);
extern void DtrmnACCS_ObstacleExtraction(void);
extern void DtrmnACCS_TargetObject(void);
extern void DtrmnACCS_TargetsSecletion(void);
extern void DtrmnACCS_InputSignalConvert(void);
extern void CalcACCS_RampAcceleration(void);
extern void CalcACCS_RampStep(void);
extern void DtrmnACCS_Acceleration_Ramp(void);
extern void ClacACCS_DsrdLonAccel(void);
extern void CalcACCS_FinalAccelReq(void);
extern void DtrmnACCS_TorqCtrlProp(void);
extern void CalcACCS_FinalTorqReq(void);
extern void DtrmnACCS_ActuaorControl(void);
extern void DtrmnACCS_RangeCtrlProp(void);
extern void DtrmnACCS_RangeCtrlPID(void);
extern void DtrmnACCS_SpeedCtrlProp(void);
extern void DtrmnACCS_SpeedCtrlPID(void);
extern void DtrmnACCS_Lon_AccelOrTorq(void);
extern void DtrmnACCS_FaultState_Init(void);
extern void DtrmnACCS_FaultState(void);
extern void DtrmnACCS_ModeStateTransfer_Init(void);
extern void DtrmnACCS_ModeStateTransfer(void);
extern void DtrmnACCS_ModeTransferConds(void);
extern void DtrmnACCS_ModeState_Init(void);
extern void DtrmnACCS_ModeState(void);
extern void DtrmnACCS_RunStatusTransfer_Init(void);
extern void DtrmnACCS_RunStatusTransfer(void);
extern void DtrmnACCS_StatusTransferConds_Init(void);
extern void DtrmnACCS_StatusTransferConds(void);
extern void DtrmnACCS_RunStatus_Init(void);
extern void DtrmnACCS_RunStatus(void);
extern void DtrmnACCS_ModeManger_Init(void);
extern void DtrmnACCS_ModeManger(void);
extern void DtrmnACCS_MainLogic_Init(void);
extern void DtrmnACCS_MainLogic(void);

#endif                                 /* RTW_HEADER_ACCS_MainLogic_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
