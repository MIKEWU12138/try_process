/*
 * File: CheckLCComplete.h
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

#ifndef RTW_HEADER_CheckLCComplete_h_
#define RTW_HEADER_CheckLCComplete_h_
#include <math.h>
#ifndef ALCA_subsystem_integrated_COMMON_INCLUDES_
# define ALCA_subsystem_integrated_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* ALCA_subsystem_integrated_COMMON_INCLUDES_ */

#include "ALCA_subsystem_integrated_types.h"

extern void ALCA_subsystem__CheckLCComplete(boolean_T rtu_enable,
  EnumDCSN_driving_direction rtu_lc_side, const ALCA_MPFU_Info *rtu_mpfu_info,
  real32_T rtu_pre_distance_to_host, boolean_T *rty_touched_new_lane, real32_T
  *rty_dist_to_ego_lane_center, real32_T *rty_distance_to_host);

#endif                                 /* RTW_HEADER_CheckLCComplete_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
