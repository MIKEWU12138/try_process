/*
 * File: ALCA_Dtrmn_interrupt_action.c
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

#include "ALCA_Dtrmn_interrupt_action.h"

/* Include model header file for global data */
#include "ALCA_subsystem_integrated.h"
#include "ALCA_subsystem_integrated_private.h"
#include "interp2_q9UVjiL3.h"

/* Output and update for atomic system: '<S10>/ALCA_Dtrmn_interrupt_action' */
void ALC_ALCA_Dtrmn_interrupt_action(boolean_T rtu_touched_new_lane, boolean_T
  rtu_interrupt, const ALCA_MPFU_Info *rtu_mpfu_info, const ALCA_VehState
  *rtu_veh_state, EnumALCA_interrupt_type rtu_interrupt_type, const real32_T
  rtu_RelativeSpeed_X[15], const real32_T rtu_VehSpeed_Y[8], const real32_T
  rtu_RangeFront_V[120], const real32_T rtu_RangeRear_V[120], uint8_T
  *rty_interrupt_action)
{
  uint8_T interrupt_action;
  boolean_T has_obstacle;
  real32_T check_distance_forward;
  real32_T check_distance_backward;
  boolean_T in_pt_graph;
  boolean_T in_target_lane;
  uint16_T i;
  int32_T b_i;
  boolean_T exitg1;
  boolean_T exitg2;
  interrupt_action = 0U;
  if (rtu_interrupt && (ALCA_subsystem_integrated_DW.KbALCA_EnblInterrupt_hmoa))
  {
    if (rtu_touched_new_lane)
    {
      interrupt_action = 1U;
    }
    else
    {
      switch (rtu_interrupt_type)
      {
       case ALCA_interrupt_type_driver_cancel:
        has_obstacle = false;
        i = 1U;
        exitg1 = false;
        while ((!exitg1) && (i <= VsOBFU_DataBus.num_obstacles))
        {
          check_distance_forward = interp2_q9UVjiL3(rtu_RelativeSpeed_X,
            rtu_VehSpeed_Y, rtu_RangeFront_V, VsOBFU_DataBus.obstacles[((int32_T)
            i) - 1].velocity_rel.x, rtu_veh_state->veh_speed) * 0.5F;
          check_distance_backward = interp2_q9UVjiL3(rtu_RelativeSpeed_X,
            rtu_VehSpeed_Y, rtu_RangeRear_V, VsOBFU_DataBus.obstacles[((int32_T)
            i) - 1].velocity_rel.x, rtu_veh_state->veh_speed) * 0.5F;
          in_pt_graph = false;
          if ((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].nearest_point_rel.x <
               0.0F) && (((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
                           nearest_point_rel.x * VsOBFU_DataBus.obstacles
                           [((int32_T)i) - 1].nearest_point_rel.x) +
                          (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
                           nearest_point_rel.y * VsOBFU_DataBus.obstacles
                           [((int32_T)i) - 1].nearest_point_rel.y)) <
                         (check_distance_backward * check_distance_backward)))
          {
            in_pt_graph = true;
          }
          else
          {
            if ((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].nearest_point_rel.x >
                 0.0F) && (((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
                             nearest_point_rel.x * VsOBFU_DataBus.obstacles
                             [((int32_T)i) - 1].nearest_point_rel.x) +
                            (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
                             nearest_point_rel.y * VsOBFU_DataBus.obstacles
                             [((int32_T)i) - 1].nearest_point_rel.y)) <
                           (check_distance_forward * check_distance_forward)))
            {
              in_pt_graph = true;
            }
          }

          in_target_lane = false;
          if (in_pt_graph)
          {
            b_i = 0;
            exitg2 = false;
            while ((!exitg2) && (b_i < 8))
            {
              if (ALCA_subsystem_integrated_DW.KbALCA_UseNewAPI_Of_MPFU_jrss)
              {
                check_distance_forward =
                  (((VsMPFU_DataBus.lane_markers
                     [rtu_mpfu_info->left_lane_marker_index - 1].c0_position +
                     (VsMPFU_DataBus.lane_markers
                      [rtu_mpfu_info->left_lane_marker_index - 1].c1_heading *
                      VsOBFU_DataBus.obstacles[((int32_T)i) - 1]
                      .polygon_points[b_i].x)) +
                    ((VsMPFU_DataBus.lane_markers
                      [rtu_mpfu_info->left_lane_marker_index - 1].c2_curvature *
                      VsOBFU_DataBus.obstacles[((int32_T)i) - 1]
                      .polygon_points[b_i].x) * VsOBFU_DataBus.obstacles
                     [((int32_T)i) - 1].polygon_points[b_i].x)) +
                   (((VsMPFU_DataBus.lane_markers
                      [rtu_mpfu_info->left_lane_marker_index - 1].
                      c3_curvature_derivative * VsOBFU_DataBus.obstacles
                      [((int32_T)i) - 1].polygon_points[b_i].x) *
                     VsOBFU_DataBus.obstacles[((int32_T)i) - 1]
                     .polygon_points[b_i].x) * VsOBFU_DataBus.obstacles
                    [((int32_T)i) - 1].polygon_points[b_i].x)) -
                  VsOBFU_DataBus.obstacles[((int32_T)i) - 1].polygon_points[b_i]
                  .y;
                check_distance_backward =
                  (((VsMPFU_DataBus.lane_markers
                     [rtu_mpfu_info->right_lane_marker_index - 1].c0_position +
                     (VsMPFU_DataBus.lane_markers
                      [rtu_mpfu_info->right_lane_marker_index - 1].c1_heading *
                      VsOBFU_DataBus.obstacles[((int32_T)i) - 1]
                      .polygon_points[b_i].x)) +
                    ((VsMPFU_DataBus.lane_markers
                      [rtu_mpfu_info->right_lane_marker_index - 1].c2_curvature *
                      VsOBFU_DataBus.obstacles[((int32_T)i) - 1]
                      .polygon_points[b_i].x) * VsOBFU_DataBus.obstacles
                     [((int32_T)i) - 1].polygon_points[b_i].x)) +
                   (((VsMPFU_DataBus.lane_markers
                      [rtu_mpfu_info->right_lane_marker_index - 1].
                      c3_curvature_derivative * VsOBFU_DataBus.obstacles
                      [((int32_T)i) - 1].polygon_points[b_i].x) *
                     VsOBFU_DataBus.obstacles[((int32_T)i) - 1]
                     .polygon_points[b_i].x) * VsOBFU_DataBus.obstacles
                    [((int32_T)i) - 1].polygon_points[b_i].x)) -
                  VsOBFU_DataBus.obstacles[((int32_T)i) - 1].polygon_points[b_i]
                  .y;
              }
              else
              {
                check_distance_forward =
                  (((VsMPFU_DataBus.lane_markers
                     [rtu_mpfu_info->left_lane_marker_index - 1].c0_position +
                     (VsMPFU_DataBus.lane_markers
                      [rtu_mpfu_info->left_lane_marker_index - 1].c1_heading *
                      VsOBFU_DataBus.obstacles[((int32_T)i) - 1]
                      .polygon_points[b_i].x)) + (((0.5F *
                       VsMPFU_DataBus.lane_markers
                       [rtu_mpfu_info->left_lane_marker_index - 1].c2_curvature)
                      * VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
                      polygon_points[b_i].x) * VsOBFU_DataBus.obstacles
                     [((int32_T)i) - 1].polygon_points[b_i].x)) + ((((0.167F *
                       VsMPFU_DataBus.lane_markers
                       [rtu_mpfu_info->left_lane_marker_index - 1].
                       c3_curvature_derivative) * VsOBFU_DataBus.obstacles
                      [((int32_T)i) - 1].polygon_points[b_i].x) *
                     VsOBFU_DataBus.obstacles[((int32_T)i) - 1]
                     .polygon_points[b_i].x) * VsOBFU_DataBus.obstacles
                    [((int32_T)i) - 1].polygon_points[b_i].x)) -
                  VsOBFU_DataBus.obstacles[((int32_T)i) - 1].polygon_points[b_i]
                  .y;
                check_distance_backward =
                  (((VsMPFU_DataBus.lane_markers
                     [rtu_mpfu_info->right_lane_marker_index - 1].c0_position +
                     (VsMPFU_DataBus.lane_markers
                      [rtu_mpfu_info->right_lane_marker_index - 1].c1_heading *
                      VsOBFU_DataBus.obstacles[((int32_T)i) - 1]
                      .polygon_points[b_i].x)) + (((0.5F *
                       VsMPFU_DataBus.lane_markers
                       [rtu_mpfu_info->right_lane_marker_index - 1].c2_curvature)
                      * VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
                      polygon_points[b_i].x) * VsOBFU_DataBus.obstacles
                     [((int32_T)i) - 1].polygon_points[b_i].x)) + ((((0.167F *
                       VsMPFU_DataBus.lane_markers
                       [rtu_mpfu_info->right_lane_marker_index - 1].
                       c3_curvature_derivative) * VsOBFU_DataBus.obstacles
                      [((int32_T)i) - 1].polygon_points[b_i].x) *
                     VsOBFU_DataBus.obstacles[((int32_T)i) - 1]
                     .polygon_points[b_i].x) * VsOBFU_DataBus.obstacles
                    [((int32_T)i) - 1].polygon_points[b_i].x)) -
                  VsOBFU_DataBus.obstacles[((int32_T)i) - 1].polygon_points[b_i]
                  .y;
              }

              if ((check_distance_forward * check_distance_backward) < 0.0F)
              {
                in_target_lane = true;
                exitg2 = true;
              }
              else
              {
                b_i++;
              }
            }
          }

          if (in_target_lane)
          {
            has_obstacle = true;
            exitg1 = true;
          }
          else
          {
            i = (uint16_T)(((uint32_T)i) + 1U);
          }
        }

        if (has_obstacle)
        {
          interrupt_action = 3U;
        }
        else
        {
          interrupt_action = 2U;
        }
        break;

       case ALCA_interrupt_type_has_obstacle:
        interrupt_action = 3U;
        break;

       default:
        /* no actions */
        break;
      }
    }

    if (ALCA_subsystem_integrated_DW.KbALCA_EnblOvrdInterruptAc_fnlg)
    {
      interrupt_action = 3U;
    }
  }

  *rty_interrupt_action = interrupt_action;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
