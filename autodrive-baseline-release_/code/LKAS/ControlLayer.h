/*
 * File: ControlLayer.h
 *
 * Code generated for Simulink model 'LKAS_subsystem_integrated'.
 *
 * Model version                  : 1.102
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 11:05:35 2020
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

#ifndef RTW_HEADER_ControlLayer_h_
#define RTW_HEADER_ControlLayer_h_
#ifndef LKAS_subsystem_integrated_COMMON_INCLUDES_
# define LKAS_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* LKAS_subsystem_integrated_COMMON_INCLUDES_ */

#include "LKAS_subsystem_integrated_types.h"

/* Child system includes */
#include "CreateCtrlValue.h"
#include "EnablingManager_LKA.h"
#include "InterventionAbort.h"
#include "InterventionCompletion.h"
#include "InterventionManager.h"
#include "OutputManager_LKA.h"
#include "SuppressionManager_LKA.h"
#include "TriggeringSLKA.h"

extern void LKAS_subsyste_ControlLayer_Init(void);
extern void LKAS_subsystem_int_ControlLayer(void);

#endif                                 /* RTW_HEADER_ControlLayer_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
