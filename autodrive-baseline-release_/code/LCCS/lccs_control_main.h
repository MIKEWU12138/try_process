/*
 * File: lccs_control_main.h
 *
 * Code generated for Simulink model 'LCCS_subsystem_integrated'.
 *
 * Model version                  : 1.2176
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Jun 10 09:42:58 2020
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

#ifndef RTW_HEADER_lccs_control_main_h_
#define RTW_HEADER_lccs_control_main_h_
#include <math.h>
#include <string.h>
#ifndef LCCS_subsystem_integrated_COMMON_INCLUDES_
# define LCCS_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* LCCS_subsystem_integrated_COMMON_INCLUDES_ */

#include "LCCS_subsystem_integrated_types.h"
#include "rt_nonfinite.h"

extern void CalcLCCS_lateral_control_m_Init(void);
extern void L_CalcLCCS_lateral_control_main(void);

#endif                                 /* RTW_HEADER_lccs_control_main_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
