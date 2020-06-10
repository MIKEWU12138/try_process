/*
 * File: ALCA_CheckLCConditions.h
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

#ifndef RTW_HEADER_ALCA_CheckLCConditions_h_
#define RTW_HEADER_ALCA_CheckLCConditions_h_
#ifndef ALCA_subsystem_integrated_COMMON_INCLUDES_
# define ALCA_subsystem_integrated_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* ALCA_subsystem_integrated_COMMON_INCLUDES_ */

#include "ALCA_subsystem_integrated_types.h"

/* Child system includes */
#include "CheckLCComplete.h"
#include "CheckLCODD.h"
#include "rt_sys_ALCA_subsystem_integrated_10.h"

extern void ALC_ALCA_CheckLCConditions_Init(void);
extern void AL_ALCA_CheckLCConditions_Reset(void);
extern void AL_ALCA_CheckLCConditions_Start(void);
extern void ALCA_sub_ALCA_CheckLCConditions(const ALCA_DcsnInfo *rtu_dcsn_info,
  const ALCA_VehState *rtu_veh_state, EnumALCA_state rtu_pre_state, uint8_T
  rtu_fault, const ALCA_MPFU_Info *rtu_mpfu_info, boolean_T *rty_lc_accept,
  boolean_T *rty_inform_req, EnumALCA_not_fulfill_reason
  *rty_odd_not_fulfill_reason, EnumDCSN_driving_direction *rty_inform_side,
  EnumDCSN_driving_direction *rty_req_side, real32_T
  *rty_dist_host_2_target_lane_cen, real32_T *rty_v_lon2lane_marker);

#endif                                 /* RTW_HEADER_ALCA_CheckLCConditions_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
