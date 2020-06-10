/*
 * File: CheckLCODD.h
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

#ifndef RTW_HEADER_CheckLCODD_h_
#define RTW_HEADER_CheckLCODD_h_
#include <math.h>
#ifndef ALCA_subsystem_integrated_COMMON_INCLUDES_
# define ALCA_subsystem_integrated_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* ALCA_subsystem_integrated_COMMON_INCLUDES_ */

#include "ALCA_subsystem_integrated_types.h"

extern void ALCA_subsystem_integ_CheckLCODD(const ALCA_MPFU_Info *rtu_mpfu_info,
  const ALCA_DcsnInfo *rtu_dcsn_info, const ALCA_VehState *rtu_veh_state,
  boolean_T rtu_inform_suggest, uint8_T rtu_fault, boolean_T
  rtu_touched_new_lane, EnumALCA_state rtu_pre_state, const real32_T
  rtu_RelativeSpeed_X[15], const real32_T rtu_VehSpeed_Y[8], const real32_T
  rtu_RangeFront_V[120], const real32_T rtu_RangeRear_V[120], boolean_T
  *rty_lc_acceptable, EnumALCA_not_fulfill_reason *rty_not_fulfill_reason,
  boolean_T *rty_inform_req, EnumDCSN_driving_direction *rty_inform_side,
  EnumDCSN_driving_direction *rty_req_side, real32_T *rty_lc_time, OBFU_Obstacle
  *rty_dangerous_obstacle, real32_T *rty_dist_host_2_target_lane_cen, real32_T
  *rty_v_lon);

#endif                                 /* RTW_HEADER_CheckLCODD_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
