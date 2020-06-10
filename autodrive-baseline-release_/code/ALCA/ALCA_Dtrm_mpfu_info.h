/*
 * File: ALCA_Dtrm_mpfu_info.h
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

#ifndef RTW_HEADER_ALCA_Dtrm_mpfu_info_h_
#define RTW_HEADER_ALCA_Dtrm_mpfu_info_h_
#ifndef ALCA_subsystem_integrated_COMMON_INCLUDES_
# define ALCA_subsystem_integrated_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* ALCA_subsystem_integrated_COMMON_INCLUDES_ */

#include "ALCA_subsystem_integrated_types.h"

extern void ALCA_subsys_ALCA_Dtrm_mpfu_info(EnumDCSN_driving_direction
  rtu_dcsn_info_req_side, boolean_T rtu_touched_new_lane, int8_T
  *rty_ego_lane_index, boolean_T *rty_has_ego_lane, int8_T
  *rty_left_lane_marker_index, int8_T *rty_right_lane_marker_index, boolean_T
  *rty_has_left_lane_marker, boolean_T *rty_has_right_lane_marker, int8_T
  *rty_target_lane_from_dcsn_index, boolean_T *rty_has_left_lane, boolean_T
  *rty_has_right_lane, MPFU_LaneMarker *rty_left_lane_marker, MPFU_LaneMarker
  *rty_right_lane_marker);

#endif                                 /* RTW_HEADER_ALCA_Dtrm_mpfu_info_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
