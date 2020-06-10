/*
 * File: AEBS.h
 *
 * Code generated for Simulink model 'AEBS_subsystem_integrated'.
 *
 * Model version                  : 1.3091
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 16:35:01 2020
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

#ifndef RTW_HEADER_AEBS_h_
#define RTW_HEADER_AEBS_h_
#ifndef AEBS_subsystem_integrated_COMMON_INCLUDES_
# define AEBS_subsystem_integrated_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* AEBS_subsystem_integrated_COMMON_INCLUDES_ */

#include "AEBS_subsystem_integrated_types.h"

/* Child system includes */
#include "AEBS_Input.h"
#include "AEBS_Output.h"
#include "AEB_Determination.h"
#include "AEB_FCWVIPTargetSelection.h"
#include "FCW_Determination.h"

extern void AEBS_subsystem_integr_AEBS_Init(void);
extern void AEBS_subsystem_integ_AEBS_Start(void);
extern void AEBS_subsystem_integ_AEBS_Const(void);
extern void AEBS_subsystem_integrated_AEBS(void);

#endif                                 /* RTW_HEADER_AEBS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
