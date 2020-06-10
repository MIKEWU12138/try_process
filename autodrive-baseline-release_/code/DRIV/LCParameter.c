/*
 * File: LCParameter.c
 *
 * Code generated for Simulink model 'DRIV_subsystem_integrated'.
 *
 * Model version                  : 1.1200
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Jun 10 08:50:22 2020
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

#include "LCParameter.h"

/* Include model header file for global data */
#include "DRIV_subsystem_integrated.h"
#include "DRIV_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S53>/DtrmnLCParameter' */
void DtrmnLCParameter(void)
{
  real32_T distance_to_host;
  int8_T left_lane_marker;
  boolean_T has_left_lane_marker;
  int8_T right_lane_marker;
  boolean_T has_right_lane_marker;
  uint8_T i;
  uint8_T tmp;
  VbDRIV_Touched_new_lane = false;
  distance_to_host = DRIV_subsystem_integrated_B.Gain_f5cc;
  DRIV_subsystem_integrated_B.dist_to_ego_lane_center =
    DRIV_subsystem_integrated_DW.KfDRIV_w_LaneWidthMax_cdo4 * 0.5F;
  left_lane_marker = 0;
  has_left_lane_marker = false;
  right_lane_marker = 0;
  has_right_lane_marker = false;
  VfDRIV_c1_heading = 0.0F;
  DRIV_subsystem_integrated_B.c0_position =
    DRIV_subsystem_integrated_DW.KfDRIV_w_LaneWidthMax_cdo4 * 0.5F;
  DRIV_subsystem_integrated_B.c2_curvature = 0.0F;

  /* Update for Inport: '<Root>/MPFU_DataBus' */
  for (i = 1U; i <= VsMPFU_DataBus.num_lane_markers; i = (uint8_T)(((uint32_T)i)
        + 1U))
  {
    switch (VsMPFU_DataBus.lane_markers[((int32_T)i) - 1].id)
    {
     case 1:
      tmp = i;
      if (((int32_T)i) > 127)
      {
        tmp = 127U;
      }

      left_lane_marker = (int8_T)tmp;
      has_left_lane_marker = true;
      break;

     case 2:
      tmp = i;
      if (((int32_T)i) > 127)
      {
        tmp = 127U;
      }

      right_lane_marker = (int8_T)tmp;
      has_right_lane_marker = true;
      break;

     default:
      /* no actions */
      break;
    }
  }

  if (VbDRIV_LeftSide_LC_Req && has_left_lane_marker)
  {
    /* Update for Inport: '<Root>/MPFU_DataBus' */
    distance_to_host = VsMPFU_DataBus.lane_markers[left_lane_marker - 1].
      distance_to_host;
    VfDRIV_c1_heading = VsMPFU_DataBus.lane_markers[left_lane_marker - 1].
      c1_heading;
    DRIV_subsystem_integrated_B.c0_position =
      VsMPFU_DataBus.lane_markers[left_lane_marker - 1].c0_position;
    DRIV_subsystem_integrated_B.c2_curvature =
      VsMPFU_DataBus.lane_markers[left_lane_marker - 1].c2_curvature;
  }
  else
  {
    if (VbDRIV_RightSide_LC_Req && has_right_lane_marker)
    {
      /* Update for Inport: '<Root>/MPFU_DataBus' */
      distance_to_host = VsMPFU_DataBus.lane_markers[right_lane_marker - 1].
        distance_to_host;
      VfDRIV_c1_heading = VsMPFU_DataBus.lane_markers[right_lane_marker - 1].
        c1_heading;
      DRIV_subsystem_integrated_B.c0_position =
        VsMPFU_DataBus.lane_markers[right_lane_marker - 1].c0_position;
      DRIV_subsystem_integrated_B.c2_curvature =
        VsMPFU_DataBus.lane_markers[right_lane_marker - 1].c2_curvature;
    }
  }

  /* Update for Inport: '<Root>/MPFU_DataBus' */
  for (i = 1U; i <= VsMPFU_DataBus.num_lanes; i = (uint8_T)(((uint32_T)i) + 1U))
  {
    if (VsMPFU_DataBus.lanes[((int32_T)i) - 1].id == 0)
    {
      DRIV_subsystem_integrated_B.dist_to_ego_lane_center = (real32_T)fabs
        ((real_T)((real32_T)(distance_to_host - (0.5F * VsMPFU_DataBus.lanes
            [((int32_T)i) - 1].width))));
    }
  }

  if ((((real32_T)fabs((real_T)DRIV_subsystem_integrated_B.Gain_f5cc)) > 0.0F) &&
      (((real32_T)fabs((real_T)((real32_T)(DRIV_subsystem_integrated_B.Gain_f5cc
           - distance_to_host)))) >
       DRIV_subsystem_integrated_DW.KfDRIV_d_TouchedNewLaneDis_mmyg))
  {
    VbDRIV_Touched_new_lane = true;
  }

  DRIV_subsystem_integrated_B.distance_to_host = distance_to_host;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
