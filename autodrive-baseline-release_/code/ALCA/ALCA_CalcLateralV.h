/*
 * File: ALCA_CalcLateralV.h
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

#ifndef RTW_HEADER_ALCA_CalcLateralV_h_
#define RTW_HEADER_ALCA_CalcLateralV_h_
#include <math.h>
#ifndef ALCA_subsystem_integrated_COMMON_INCLUDES_
# define ALCA_subsystem_integrated_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* ALCA_subsystem_integrated_COMMON_INCLUDES_ */

#include "ALCA_subsystem_integrated_types.h"

extern void ALCA_sub_ALCA_CalcLateralV_Init(void);
extern void ALCA_su_ALCA_CalcLateralV_Reset(void);
extern real32_T ALCA_subsyste_ALCA_CalcLateralV(boolean_T rtu_request, real32_T
  rtu_v_lon2lane_marker);

#endif                                 /* RTW_HEADER_ALCA_CalcLateralV_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
