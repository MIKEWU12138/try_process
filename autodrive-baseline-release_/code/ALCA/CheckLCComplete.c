/*
 * File: CheckLCComplete.c
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

#include "CheckLCComplete.h"

/* Include model header file for global data */
#include "ALCA_subsystem_integrated.h"
#include "ALCA_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S8>/CheckLCComplete' */
void ALCA_subsystem__CheckLCComplete(boolean_T rtu_enable,
  EnumDCSN_driving_direction rtu_lc_side, const ALCA_MPFU_Info *rtu_mpfu_info,
  real32_T rtu_pre_distance_to_host, boolean_T *rty_touched_new_lane, real32_T
  *rty_dist_to_ego_lane_center, real32_T *rty_distance_to_host)
{
  real32_T distance_to_host;
  real32_T tmp;
  *rty_touched_new_lane = false;
  distance_to_host = rtu_pre_distance_to_host;
  if ((((uint32_T)rtu_lc_side) == LEFT) && (rtu_mpfu_info->has_left_lane_marker))
  {
    /* Inport: '<Root>/MPFU_DataBus' */
    distance_to_host = VsMPFU_DataBus.lane_markers
      [rtu_mpfu_info->left_lane_marker_index - 1].distance_to_host;
  }
  else
  {
    if ((((uint32_T)rtu_lc_side) == RIGHT) &&
        (rtu_mpfu_info->has_right_lane_marker))
    {
      /* Inport: '<Root>/MPFU_DataBus' */
      distance_to_host = (real32_T)fabs((real_T)
        VsMPFU_DataBus.lane_markers[rtu_mpfu_info->right_lane_marker_index - 1].
        distance_to_host);
    }
  }

  if (ALCA_subsystem_integrated_DW.KbALCA_EnblOvrdLaneWidth_czwz)
  {
    tmp = 3.75F;
  }
  else
  {
    /* Inport: '<Root>/MPFU_DataBus' */
    tmp = VsMPFU_DataBus.lanes[rtu_mpfu_info->ego_lane_index - 1].width;
  }

  *rty_dist_to_ego_lane_center = (real32_T)fabs((real_T)((real32_T)
    (distance_to_host - (0.5F * tmp))));
  if ((rtu_enable && (((real32_T)fabs((real_T)rtu_pre_distance_to_host)) > 0.0F))
      && (((real32_T)fabs((real_T)((real32_T)(rtu_pre_distance_to_host -
           distance_to_host)))) >
          ALCA_subsystem_integrated_DW.KfALCA_d_TouchedNewLaneDis_lbrk))
  {
    *rty_touched_new_lane = true;
  }

  *rty_distance_to_host = distance_to_host;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
