/*
 * File: DtrmnDCSN_Integrated.h
 *
 * Code generated for Simulink model 'DCSN_subsystem_integrated'.
 *
 * Model version                  : 1.602
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 17:40:58 2020
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

#ifndef RTW_HEADER_DtrmnDCSN_Integrated_h_
#define RTW_HEADER_DtrmnDCSN_Integrated_h_
#ifndef DCSN_subsystem_integrated_COMMON_INCLUDES_
# define DCSN_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* DCSN_subsystem_integrated_COMMON_INCLUDES_ */

#include "DCSN_subsystem_integrated_types.h"

/* Child system includes */
#include "DtrmnDCSN_ADM.h"
#include "DtrmnDCSN_EnablingManager.h"
#include "DtrmnDCSN_TrafficDecider.h"

extern void DCSN__DtrmnDCSN_Integrated_Init(void);
extern void DCSN_subsy_DtrmnDCSN_Integrated(void);

#endif                                 /* RTW_HEADER_DtrmnDCSN_Integrated_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
