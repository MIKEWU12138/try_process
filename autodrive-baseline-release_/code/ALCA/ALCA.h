/*
 * File: ALCA.h
 *
 * Code generated for Simulink model 'ALCA_subsystem_integrated'.
 *
 * Model version                  : 1.6591
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 17:34:22 2020
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

#ifndef RTW_HEADER_ALCA_h_
#define RTW_HEADER_ALCA_h_
#ifndef ALCA_subsystem_integrated_COMMON_INCLUDES_
# define ALCA_subsystem_integrated_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* ALCA_subsystem_integrated_COMMON_INCLUDES_ */

#include "ALCA_subsystem_integrated_types.h"

/* Child system includes */
#include "ALCA_CalcLateralV.h"
#include "ALCA_CheckLCConditions.h"
#include "ALCA_DtrmnALCAState.h"
#include "ALCA_InputDataProcess.h"

extern void ALCA_subsystem_integr_ALCA_Init(void);
extern void ALCA_subsystem_integ_ALCA_Start(void);
extern void ALCA_subsystem_integrated_ALCA(void);

#endif                                 /* RTW_HEADER_ALCA_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
