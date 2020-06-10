/*
 * File: ALCA_Dtrm_mpfu_info.c
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

#include "ALCA_Dtrm_mpfu_info.h"

/* Include model header file for global data */
#include "ALCA_subsystem_integrated.h"
#include "ALCA_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S12>/ALCA_Dtrm_mpfu_info' */
void ALCA_subsys_ALCA_Dtrm_mpfu_info(EnumDCSN_driving_direction
  rtu_dcsn_info_req_side, boolean_T rtu_touched_new_lane, int8_T
  *rty_ego_lane_index, boolean_T *rty_has_ego_lane, int8_T
  *rty_left_lane_marker_index, int8_T *rty_right_lane_marker_index, boolean_T
  *rty_has_left_lane_marker, boolean_T *rty_has_right_lane_marker, int8_T
  *rty_target_lane_from_dcsn_index, boolean_T *rty_has_left_lane, boolean_T
  *rty_has_right_lane, MPFU_LaneMarker *rty_left_lane_marker, MPFU_LaneMarker
  *rty_right_lane_marker)
{
  int8_T ego_lane_index;
  int8_T left_lane_marker_index;
  int8_T right_lane_marker_index;
  boolean_T has_left_lane;
  boolean_T has_right_lane;
  int8_T left_lane_index;
  int8_T right_lane_index;
  uint8_T i;
  uint8_T tmp;
  *rty_has_ego_lane = false;
  *rty_has_left_lane_marker = false;
  *rty_has_right_lane_marker = false;
  has_left_lane = false;
  has_right_lane = false;
  ego_lane_index = 1;
  *rty_target_lane_from_dcsn_index = 1;
  left_lane_marker_index = 1;
  right_lane_marker_index = 1;
  left_lane_index = 1;
  right_lane_index = 1;

  /* Inport: '<Root>/MPFU_DataBus' */
  for (i = 1U; i <= VsMPFU_DataBus.num_lanes; i = (uint8_T)(((uint32_T)i) + 1U))
  {
    if (((VsMPFU_DataBus.lanes[((int32_T)i) - 1].fusion_status == 0) ||
         (VsMPFU_DataBus.lanes[((int32_T)i) - 1].fusion_status == 2)) &&
        (ALCA_subsystem_integrated_DW.KbALCA_EnblCheckMPFUFusionStatu != 0.0F))
    {
    }
    else
    {
      switch (VsMPFU_DataBus.lanes[((int32_T)i) - 1].id)
      {
       case 0:
        *rty_has_ego_lane = true;
        tmp = i;
        if (((int32_T)i) > 127)
        {
          tmp = 127U;
        }

        ego_lane_index = (int8_T)tmp;
        break;

       case 1:
        tmp = i;
        if (((int32_T)i) > 127)
        {
          tmp = 127U;
        }

        left_lane_index = (int8_T)tmp;
        has_left_lane = true;
        break;

       case 2:
        tmp = i;
        if (((int32_T)i) > 127)
        {
          tmp = 127U;
        }

        right_lane_index = (int8_T)tmp;
        has_right_lane = true;
        break;

       default:
        /* no actions */
        break;
      }
    }
  }

  switch (rtu_dcsn_info_req_side)
  {
   case LEFT:
    *rty_target_lane_from_dcsn_index = left_lane_index;
    break;

   case RIGHT:
    *rty_target_lane_from_dcsn_index = right_lane_index;
    break;

   default:
    /* no actions */
    break;
  }

  if (rtu_touched_new_lane)
  {
    *rty_target_lane_from_dcsn_index = ego_lane_index;
  }

  /* Inport: '<Root>/MPFU_DataBus' */
  VfALCA_d_EGOLaneLength = VsMPFU_DataBus.lanes[ego_lane_index - 1].length;
  VfALCA_d_EGOLaneWidth = VsMPFU_DataBus.lanes[ego_lane_index - 1].width;
  VfALCA_HasRightLane = has_right_lane;
  VfALCA_HasLeftLane = has_left_lane;

  /* Inport: '<Root>/MPFU_DataBus' */
  for (i = 1U; i <= VsMPFU_DataBus.num_lane_markers; i = (uint8_T)(((uint32_T)i)
        + 1U))
  {
    if (((VsMPFU_DataBus.lane_markers[((int32_T)i) - 1].fusion_status == 0) ||
         (VsMPFU_DataBus.lane_markers[((int32_T)i) - 1].fusion_status == 2)) &&
        (ALCA_subsystem_integrated_DW.KbALCA_EnblCheckMPFUFusionStatu != 0.0F))
    {
    }
    else
    {
      switch (VsMPFU_DataBus.lane_markers[((int32_T)i) - 1].id)
      {
       case 1:
        tmp = i;
        if (((int32_T)i) > 127)
        {
          tmp = 127U;
        }

        left_lane_marker_index = (int8_T)tmp;
        *rty_has_left_lane_marker = true;
        break;

       case 2:
        tmp = i;
        if (((int32_T)i) > 127)
        {
          tmp = 127U;
        }

        right_lane_marker_index = (int8_T)tmp;
        *rty_has_right_lane_marker = true;
        break;

       default:
        /* no actions */
        break;
      }
    }
  }

  *rty_left_lane_marker = VsMPFU_DataBus.lane_markers[left_lane_marker_index - 1];
  *rty_right_lane_marker = VsMPFU_DataBus.lane_markers[right_lane_marker_index -
    1];
  *rty_ego_lane_index = ego_lane_index;
  *rty_left_lane_marker_index = left_lane_marker_index;
  *rty_right_lane_marker_index = right_lane_marker_index;
  *rty_has_left_lane = has_left_lane;
  *rty_has_right_lane = has_right_lane;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
