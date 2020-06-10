/*
 * File: ACCS_Input.h
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

#ifndef RTW_HEADER_ACCS_Input_h_
#define RTW_HEADER_ACCS_Input_h_
#include <math.h>
#ifndef ACCS_subsystem_integrated_COMMON_INCLUDES_
# define ACCS_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ACCS_subsystem_integrated_COMMON_INCLUDES_ */

#include "ACCS_subsystem_integrated_types.h"

extern void CheckACCS_FaultState(void);
extern void DtrmnACCS_CAN_Information(void);
extern void DtrmnACCS_DCSNInformation(void);
extern void DtrmnACCS_EGMOInformation(void);
extern void DtrmnACCS_MPFUInformation(void);
extern void DtrmnACCS_Input(void);

#endif                                 /* RTW_HEADER_ACCS_Input_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
