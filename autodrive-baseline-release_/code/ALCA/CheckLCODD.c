/*
 * File: CheckLCODD.c
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

#include "CheckLCODD.h"

/* Include model header file for global data */
#include "ALCA_subsystem_integrated.h"
#include "ALCA_subsystem_integrated_private.h"
#include "interp2_q9UVjiL3.h"

/* Forward declaration for local functions */
static boolean_T ALCA_subsyste_check_target_lane(EnumALCA_state pre_state,
  real32_T veh_state_veh_speed, real32_T target_lane_width, real32_T
  target_lane_length, int8_T target_lane_type, int8_T lane_marker_type);
static boolean_T ALCA_sub_check_obstacle_polygon(const Vector3f points[8],
  real32_T lane_marker_c0_position, real32_T lane_marker_c1_heading, real32_T
  lane_marker_c2_curvature, real32_T lane_marker_c3_curvature_deriva, real32_T
  lane_shift);
static void ALCA_sub_check_target_lane_hgrj(int8_T
  mpfu_info_left_lane_marker_inde, int8_T mpfu_info_target_lane_from_dcsn,
  real32_T veh_state_veh_speed, const MPFU_Lane MPFU_data_lanes[8], const
  MPFU_LaneMarker MPFU_data_lane_markers[16], const OBFU_Obstacle
  OBFU_data_obstacles[128], uint16_T OBFU_data_num_obstacles, const real32_T
  RelativeSpeed_X[15], const real32_T VehSpeed_Y[8], const real32_T
  RangeFront_V[120], const real32_T RangeRear_V[120], real32_T
  lateral_dist_to_go, boolean_T *has_obstacle, uint16_T *obstacle_index);
static void ALCA_su_check_target_lane_hgrjc(int8_T
  mpfu_info_left_lane_marker_inde, int8_T mpfu_info_right_lane_marker_ind,
  int8_T mpfu_info_target_lane_from_dcsn, real32_T veh_state_veh_speed, const
  MPFU_Lane MPFU_data_lanes[8], const MPFU_LaneMarker MPFU_data_lane_markers[16],
  const OBFU_Obstacle OBFU_data_obstacles[128], uint16_T OBFU_data_num_obstacles,
  const real32_T RelativeSpeed_X[15], const real32_T VehSpeed_Y[8], const
  real32_T RangeFront_V[120], const real32_T RangeRear_V[120], real32_T
  lateral_dist_to_go, boolean_T check_left, boolean_T *has_obstacle, uint16_T
  *obstacle_index);

/* Function for MATLAB Function: '<S8>/CheckLCODD' */
static boolean_T ALCA_subsyste_check_target_lane(EnumALCA_state pre_state,
  real32_T veh_state_veh_speed, real32_T target_lane_width, real32_T
  target_lane_length, int8_T target_lane_type, int8_T lane_marker_type)
{
  boolean_T lc_enable;
  boolean_T lane_marker_can_cross;
  lc_enable = false;
  lane_marker_can_cross = false;
  VfALCA_TargetSideLaneMarkerType = lane_marker_type;
  if (ALCA_subsystem_integrated_DW.KbALCA_EnblCheckMPFULaneMarkerT)
  {
    if ((lane_marker_type != 5) && (lane_marker_type != 6))
    {
      lane_marker_can_cross = true;
    }
  }
  else
  {
    lane_marker_can_cross = true;
  }

  VfALCA_TargetLaneType = target_lane_type;
  VfALCA_TargetLaneWidth = target_lane_width;
  if (ALCA_subsystem_integrated_DW.KbALCA_EnblOvrdLaneWidth_czwz)
  {
    VfALCA_TargetLaneWidth = 3.75F;
  }

  if ((lane_marker_can_cross && (target_lane_type == 1)) &&
      (VfALCA_TargetLaneWidth >
       (ALCA_subsystem_integrated_DW.KfALCA_d_EgoVehWidth_d0rj *
        ALCA_subsystem_integrated_DW.KfALCA_r_EgoWidth2LaneWidthRati)))
  {
    lc_enable = true;
  }

  if (lc_enable && (!ALCA_subsystem_integrated_DW.KbALCA_EnblOvrdLaneLength_mu5k))
  {
    VfALCA_TargetLaneLength = target_lane_length;
    lc_enable = (target_lane_length > (veh_state_veh_speed *
      ALCA_subsystem_integrated_DW.KfALCA_t_LaneChangeTimeMin_jj0b));
    if (((uint32_T)pre_state) == ALCA_state_Activated)
    {
      lc_enable = true;
    }
  }

  return lc_enable;
}

/* Function for MATLAB Function: '<S8>/CheckLCODD' */
static boolean_T ALCA_sub_check_obstacle_polygon(const Vector3f points[8],
  real32_T lane_marker_c0_position, real32_T lane_marker_c1_heading, real32_T
  lane_marker_c2_curvature, real32_T lane_marker_c3_curvature_deriva, real32_T
  lane_shift)
{
  boolean_T in_lane;
  real32_T c0_1;
  real32_T delta_y1;
  real32_T delta_y2;
  int32_T i;
  real32_T delta_y1_tmp;
  real32_T delta_y1_tmp_0;
  boolean_T exitg1;
  in_lane = false;
  c0_1 = lane_marker_c0_position + lane_shift;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 8))
  {
    if (ALCA_subsystem_integrated_DW.KbALCA_UseNewAPI_Of_MPFU_jrss)
    {
      delta_y2 = (lane_marker_c2_curvature * points[i].x) * points[i].x;
      delta_y1_tmp = ((lane_marker_c3_curvature_deriva * points[i].x) * points[i]
                      .x) * points[i].x;
      delta_y1 = (((lane_marker_c0_position + (lane_marker_c1_heading * points[i]
        .x)) + delta_y2) + delta_y1_tmp) - points[i].y;
      delta_y2 = (((c0_1 + (lane_marker_c1_heading * points[i].x)) + delta_y2) +
                  delta_y1_tmp) - points[i].y;
    }
    else
    {
      delta_y2 = lane_marker_c1_heading * points[i].x;
      delta_y1_tmp = ((0.5F * lane_marker_c2_curvature) * points[i].x) *
        points[i].x;
      delta_y1_tmp_0 = (((0.167F * lane_marker_c3_curvature_deriva) * points[i].
                         x) * points[i].x) * points[i].x;
      delta_y1 = (((lane_marker_c0_position + delta_y2) + delta_y1_tmp) +
                  delta_y1_tmp_0) - points[i].y;
      delta_y2 = (((c0_1 + delta_y2) + delta_y1_tmp) + delta_y1_tmp_0) -
        points[i].y;
    }

    if ((delta_y1 * delta_y2) < 0.0F)
    {
      in_lane = true;
      exitg1 = true;
    }
    else
    {
      i++;
    }
  }

  return in_lane;
}

/* Function for MATLAB Function: '<S8>/CheckLCODD' */
static void ALCA_sub_check_target_lane_hgrj(int8_T
  mpfu_info_left_lane_marker_inde, int8_T mpfu_info_target_lane_from_dcsn,
  real32_T veh_state_veh_speed, const MPFU_Lane MPFU_data_lanes[8], const
  MPFU_LaneMarker MPFU_data_lane_markers[16], const OBFU_Obstacle
  OBFU_data_obstacles[128], uint16_T OBFU_data_num_obstacles, const real32_T
  RelativeSpeed_X[15], const real32_T VehSpeed_Y[8], const real32_T
  RangeFront_V[120], const real32_T RangeRear_V[120], real32_T
  lateral_dist_to_go, boolean_T *has_obstacle, uint16_T *obstacle_index)
{
  real32_T target_lane_width;
  real32_T lane_shift;
  real32_T check_distance_forward;
  real32_T check_distance_backward;
  boolean_T in_pt_graph;
  boolean_T in_target_lane;
  uint16_T i;
  boolean_T exitg1;
  target_lane_width = MPFU_data_lanes[mpfu_info_target_lane_from_dcsn - 1].width;
  if (ALCA_subsystem_integrated_DW.KbALCA_EnblOvrdLaneWidth_czwz)
  {
    target_lane_width = 3.75F;
  }

  if (target_lane_width <
      ALCA_subsystem_integrated_DW.KfALCA_d_LaneWidthMax_a3am)
  {
    lane_shift = target_lane_width;
  }
  else
  {
    lane_shift = ALCA_subsystem_integrated_DW.KfALCA_d_LaneWidthMax_a3am;
  }

  *has_obstacle = false;
  *obstacle_index = 0U;
  if (target_lane_width <
      ALCA_subsystem_integrated_DW.KfALCA_d_LaneWidthMax_a3am)
  {
  }
  else
  {
    target_lane_width = ALCA_subsystem_integrated_DW.KfALCA_d_LaneWidthMax_a3am;
  }

  target_lane_width = lateral_dist_to_go / target_lane_width;
  i = 1U;
  exitg1 = false;
  while ((!exitg1) && (i <= OBFU_data_num_obstacles))
  {
    check_distance_forward = interp2_q9UVjiL3(RelativeSpeed_X, VehSpeed_Y,
      RangeFront_V, OBFU_data_obstacles[((int32_T)i) - 1].velocity_rel.x,
      veh_state_veh_speed) * target_lane_width;
    if (check_distance_forward <
        ALCA_subsystem_integrated_DW.KfAlCA_d_CheckObstacleDist_aqcl)
    {
    }
    else
    {
      check_distance_forward =
        ALCA_subsystem_integrated_DW.KfAlCA_d_CheckObstacleDist_aqcl;
    }

    check_distance_backward = interp2_q9UVjiL3(RelativeSpeed_X, VehSpeed_Y,
      RangeRear_V, OBFU_data_obstacles[((int32_T)i) - 1].velocity_rel.x,
      veh_state_veh_speed) * target_lane_width;
    if (check_distance_backward <
        ALCA_subsystem_integrated_DW.KfAlCA_d_CheckObstacleDist_aqcl)
    {
    }
    else
    {
      check_distance_backward =
        ALCA_subsystem_integrated_DW.KfAlCA_d_CheckObstacleDist_aqcl;
    }

    in_pt_graph = false;
    if ((OBFU_data_obstacles[((int32_T)i) - 1].nearest_point_rel.x < 0.0F) &&
        (((OBFU_data_obstacles[((int32_T)i) - 1].nearest_point_rel.x *
           OBFU_data_obstacles[((int32_T)i) - 1].nearest_point_rel.x) +
          (OBFU_data_obstacles[((int32_T)i) - 1].nearest_point_rel.y *
           OBFU_data_obstacles[((int32_T)i) - 1].nearest_point_rel.y)) <
         (check_distance_backward * check_distance_backward)))
    {
      in_pt_graph = true;
    }
    else
    {
      if ((OBFU_data_obstacles[((int32_T)i) - 1].nearest_point_rel.x > 0.0F) &&
          (((OBFU_data_obstacles[((int32_T)i) - 1].nearest_point_rel.x *
             OBFU_data_obstacles[((int32_T)i) - 1].nearest_point_rel.x) +
            (OBFU_data_obstacles[((int32_T)i) - 1].nearest_point_rel.y *
             OBFU_data_obstacles[((int32_T)i) - 1].nearest_point_rel.y)) <
           (check_distance_forward * check_distance_forward)))
      {
        in_pt_graph = true;
      }
    }

    in_target_lane = false;
    if (in_pt_graph)
    {
      in_target_lane = ALCA_sub_check_obstacle_polygon(OBFU_data_obstacles
        [((int32_T)i) - 1].polygon_points,
        MPFU_data_lane_markers[mpfu_info_left_lane_marker_inde - 1].c0_position,
        MPFU_data_lane_markers[mpfu_info_left_lane_marker_inde - 1].c1_heading,
        MPFU_data_lane_markers[mpfu_info_left_lane_marker_inde - 1].c2_curvature,
        MPFU_data_lane_markers[mpfu_info_left_lane_marker_inde - 1].
        c3_curvature_derivative, lane_shift);
    }

    if (in_target_lane)
    {
      *has_obstacle = true;
      *obstacle_index = i;
      exitg1 = true;
    }
    else
    {
      i = (uint16_T)(((uint32_T)i) + 1U);
    }
  }
}

/* Function for MATLAB Function: '<S8>/CheckLCODD' */
static void ALCA_su_check_target_lane_hgrjc(int8_T
  mpfu_info_left_lane_marker_inde, int8_T mpfu_info_right_lane_marker_ind,
  int8_T mpfu_info_target_lane_from_dcsn, real32_T veh_state_veh_speed, const
  MPFU_Lane MPFU_data_lanes[8], const MPFU_LaneMarker MPFU_data_lane_markers[16],
  const OBFU_Obstacle OBFU_data_obstacles[128], uint16_T OBFU_data_num_obstacles,
  const real32_T RelativeSpeed_X[15], const real32_T VehSpeed_Y[8], const
  real32_T RangeFront_V[120], const real32_T RangeRear_V[120], real32_T
  lateral_dist_to_go, boolean_T check_left, boolean_T *has_obstacle, uint16_T
  *obstacle_index)
{
  real32_T target_lane_width;
  real32_T lane_marker_c0_position;
  real32_T lane_marker_c1_heading;
  real32_T lane_marker_c2_curvature;
  real32_T lane_marker_c3_curvature_deriva;
  real32_T lane_shift;
  real32_T check_distance_forward;
  real32_T check_distance_backward;
  boolean_T in_pt_graph;
  boolean_T in_target_lane;
  uint16_T i;
  boolean_T exitg1;
  target_lane_width = MPFU_data_lanes[mpfu_info_target_lane_from_dcsn - 1].width;
  if (ALCA_subsystem_integrated_DW.KbALCA_EnblOvrdLaneWidth_czwz)
  {
    target_lane_width = 3.75F;
  }

  if (check_left)
  {
    lane_marker_c0_position =
      MPFU_data_lane_markers[mpfu_info_left_lane_marker_inde - 1].c0_position;
    lane_marker_c1_heading =
      MPFU_data_lane_markers[mpfu_info_left_lane_marker_inde - 1].c1_heading;
    lane_marker_c2_curvature =
      MPFU_data_lane_markers[mpfu_info_left_lane_marker_inde - 1].c2_curvature;
    lane_marker_c3_curvature_deriva =
      MPFU_data_lane_markers[mpfu_info_left_lane_marker_inde - 1].
      c3_curvature_derivative;
    if (target_lane_width <
        ALCA_subsystem_integrated_DW.KfALCA_d_LaneWidthMax_a3am)
    {
      lane_shift = target_lane_width;
    }
    else
    {
      lane_shift = ALCA_subsystem_integrated_DW.KfALCA_d_LaneWidthMax_a3am;
    }
  }
  else
  {
    lane_marker_c0_position =
      MPFU_data_lane_markers[mpfu_info_right_lane_marker_ind - 1].c0_position;
    lane_marker_c1_heading =
      MPFU_data_lane_markers[mpfu_info_right_lane_marker_ind - 1].c1_heading;
    lane_marker_c2_curvature =
      MPFU_data_lane_markers[mpfu_info_right_lane_marker_ind - 1].c2_curvature;
    lane_marker_c3_curvature_deriva =
      MPFU_data_lane_markers[mpfu_info_right_lane_marker_ind - 1].
      c3_curvature_derivative;
    if (target_lane_width <
        ALCA_subsystem_integrated_DW.KfALCA_d_LaneWidthMax_a3am)
    {
      lane_shift = -target_lane_width;
    }
    else
    {
      lane_shift = -ALCA_subsystem_integrated_DW.KfALCA_d_LaneWidthMax_a3am;
    }
  }

  *has_obstacle = false;
  *obstacle_index = 0U;
  if (target_lane_width <
      ALCA_subsystem_integrated_DW.KfALCA_d_LaneWidthMax_a3am)
  {
  }
  else
  {
    target_lane_width = ALCA_subsystem_integrated_DW.KfALCA_d_LaneWidthMax_a3am;
  }

  target_lane_width = lateral_dist_to_go / target_lane_width;
  i = 1U;
  exitg1 = false;
  while ((!exitg1) && (i <= OBFU_data_num_obstacles))
  {
    check_distance_forward = interp2_q9UVjiL3(RelativeSpeed_X, VehSpeed_Y,
      RangeFront_V, OBFU_data_obstacles[((int32_T)i) - 1].velocity_rel.x,
      veh_state_veh_speed) * target_lane_width;
    if (check_distance_forward <
        ALCA_subsystem_integrated_DW.KfAlCA_d_CheckObstacleDist_aqcl)
    {
    }
    else
    {
      check_distance_forward =
        ALCA_subsystem_integrated_DW.KfAlCA_d_CheckObstacleDist_aqcl;
    }

    check_distance_backward = interp2_q9UVjiL3(RelativeSpeed_X, VehSpeed_Y,
      RangeRear_V, OBFU_data_obstacles[((int32_T)i) - 1].velocity_rel.x,
      veh_state_veh_speed) * target_lane_width;
    if (check_distance_backward <
        ALCA_subsystem_integrated_DW.KfAlCA_d_CheckObstacleDist_aqcl)
    {
    }
    else
    {
      check_distance_backward =
        ALCA_subsystem_integrated_DW.KfAlCA_d_CheckObstacleDist_aqcl;
    }

    in_pt_graph = false;
    if ((OBFU_data_obstacles[((int32_T)i) - 1].nearest_point_rel.x < 0.0F) &&
        (((OBFU_data_obstacles[((int32_T)i) - 1].nearest_point_rel.x *
           OBFU_data_obstacles[((int32_T)i) - 1].nearest_point_rel.x) +
          (OBFU_data_obstacles[((int32_T)i) - 1].nearest_point_rel.y *
           OBFU_data_obstacles[((int32_T)i) - 1].nearest_point_rel.y)) <
         (check_distance_backward * check_distance_backward)))
    {
      in_pt_graph = true;
    }
    else
    {
      if ((OBFU_data_obstacles[((int32_T)i) - 1].nearest_point_rel.x > 0.0F) &&
          (((OBFU_data_obstacles[((int32_T)i) - 1].nearest_point_rel.x *
             OBFU_data_obstacles[((int32_T)i) - 1].nearest_point_rel.x) +
            (OBFU_data_obstacles[((int32_T)i) - 1].nearest_point_rel.y *
             OBFU_data_obstacles[((int32_T)i) - 1].nearest_point_rel.y)) <
           (check_distance_forward * check_distance_forward)))
      {
        in_pt_graph = true;
      }
    }

    in_target_lane = false;
    if (in_pt_graph)
    {
      in_target_lane = ALCA_sub_check_obstacle_polygon(OBFU_data_obstacles
        [((int32_T)i) - 1].polygon_points, lane_marker_c0_position,
        lane_marker_c1_heading, lane_marker_c2_curvature,
        lane_marker_c3_curvature_deriva, lane_shift);
    }

    if (in_target_lane)
    {
      *has_obstacle = true;
      *obstacle_index = i;
      exitg1 = true;
    }
    else
    {
      i = (uint16_T)(((uint32_T)i) + 1U);
    }
  }
}

/* Output and update for atomic system: '<S8>/CheckLCODD' */
void ALCA_subsystem_integ_CheckLCODD(const ALCA_MPFU_Info *rtu_mpfu_info, const
  ALCA_DcsnInfo *rtu_dcsn_info, const ALCA_VehState *rtu_veh_state, boolean_T
  rtu_inform_suggest, uint8_T rtu_fault, boolean_T rtu_touched_new_lane,
  EnumALCA_state rtu_pre_state, const real32_T rtu_RelativeSpeed_X[15], const
  real32_T rtu_VehSpeed_Y[8], const real32_T rtu_RangeFront_V[120], const
  real32_T rtu_RangeRear_V[120], boolean_T *rty_lc_acceptable,
  EnumALCA_not_fulfill_reason *rty_not_fulfill_reason, boolean_T *rty_inform_req,
  EnumDCSN_driving_direction *rty_inform_side, EnumDCSN_driving_direction
  *rty_req_side, real32_T *rty_lc_time, OBFU_Obstacle *rty_dangerous_obstacle,
  real32_T *rty_dist_host_2_target_lane_cen, real32_T *rty_v_lon)
{
  real32_T lc_time;
  real32_T dist_host_2_target_lane_center;
  real32_T ego_lane_length;
  real32_T target_lane_width;
  real32_T angle;
  real32_T lateral_dist_to_go_abs;
  real32_T v_comfortable;
  boolean_T ego_lane_length_enough;
  boolean_T map_accept;
  boolean_T obfu_accept;
  uint8_T check_side;
  EnumALCA_not_fulfill_reason b_not_fulfill_reason;
  EnumDCSN_driving_direction b_inform_side;
  boolean_T dcsn_condiction;
  boolean_T target_lane_allow;
  uint16_T e_obstacle_index;
  real32_T angle_0;

  /* Inport: '<Root>/OBFU_DataBus' */
  VfALCA_ObstacleNum = VsOBFU_DataBus.num_obstacles;
  map_accept = false;
  obfu_accept = false;
  b_inform_side = FORWARD;

  /* Inport: '<Root>/OBFU_DataBus' */
  *rty_dangerous_obstacle = VsOBFU_DataBus.obstacles[0];
  b_not_fulfill_reason = ALCA_not_fulfill_reason_check_fulfilled;
  dcsn_condiction = (((rtu_dcsn_info->change_lane_req) &&
                      (rtu_dcsn_info->alca_enable)) && (((uint32_T)
    rtu_dcsn_info->change_lane_req_side) != FORWARD));
  ego_lane_length = ALCA_subsystem_integrated_DW.KfALCA_d_DefaultLaneLength_pz0k;
  angle = rtu_veh_state->veh_speed;
  dist_host_2_target_lane_center = 0.0F;
  target_lane_width = 3.75F;
  if (dcsn_condiction)
  {
    /* Inport: '<Root>/MPFU_DataBus' */
    target_lane_width = VsMPFU_DataBus.lanes
      [rtu_mpfu_info->target_lane_from_dcsn_index - 1].width;
    if (ALCA_subsystem_integrated_DW.KbALCA_EnblOvrdLaneWidth_czwz)
    {
      target_lane_width = 3.75F;
    }

    switch (rtu_dcsn_info->change_lane_req_side)
    {
     case LEFT:
      if (rtu_touched_new_lane)
      {
        /* Inport: '<Root>/MPFU_DataBus' */
        dist_host_2_target_lane_center =
          VsMPFU_DataBus.lane_markers[rtu_mpfu_info->left_lane_marker_index - 1]
          .distance_to_host - (target_lane_width * 0.5F);
      }
      else
      {
        /* Inport: '<Root>/MPFU_DataBus' */
        dist_host_2_target_lane_center =
          VsMPFU_DataBus.lane_markers[rtu_mpfu_info->left_lane_marker_index - 1]
          .distance_to_host + (target_lane_width * 0.5F);
      }

      /* Inport: '<Root>/MPFU_DataBus' */
      angle = (real32_T)atan((real_T)VsMPFU_DataBus.lane_markers
        [rtu_mpfu_info->left_lane_marker_index - 1].c1_heading);
      angle = (rtu_veh_state->veh_vx * ((real32_T)cos((real_T)angle))) +
        (rtu_veh_state->veh_vy * ((real32_T)sin((real_T)angle)));
      break;

     case RIGHT:
      if (rtu_touched_new_lane)
      {
        /* Inport: '<Root>/MPFU_DataBus' */
        dist_host_2_target_lane_center =
          VsMPFU_DataBus.lane_markers[rtu_mpfu_info->right_lane_marker_index - 1]
          .distance_to_host + (target_lane_width * 0.5F);
      }
      else
      {
        /* Inport: '<Root>/MPFU_DataBus' */
        dist_host_2_target_lane_center =
          VsMPFU_DataBus.lane_markers[rtu_mpfu_info->right_lane_marker_index - 1]
          .distance_to_host - (target_lane_width * 0.5F);
      }

      /* Inport: '<Root>/MPFU_DataBus' */
      angle = (real32_T)atan((real_T)VsMPFU_DataBus.lane_markers
        [rtu_mpfu_info->right_lane_marker_index - 1].c1_heading);
      angle = (rtu_veh_state->veh_vx * ((real32_T)cos((real_T)angle))) +
        (rtu_veh_state->veh_vy * ((real32_T)sin((real_T)angle)));
      break;

     default:
      /* no actions */
      break;
    }

    /* Inport: '<Root>/MPFU_DataBus' */
    ego_lane_length = VsMPFU_DataBus.lanes[rtu_mpfu_info->ego_lane_index - 1].
      length;
  }

  if (ALCA_subsystem_integrated_DW.KbALCA_EnblOvrdLaneLength_mu5k)
  {
    ego_lane_length =
      ALCA_subsystem_integrated_DW.KfALCA_d_DefaultLaneLength_pz0k;
  }

  VfALCA_v_VehLonSpeed2LaneMarker = angle;
  lateral_dist_to_go_abs = (real32_T)fabs((real_T)dist_host_2_target_lane_center);
  v_comfortable = angle *
    ALCA_subsystem_integrated_DW.KfALCA_r_ComfortableVRatio_ldnz;
  if (((real_T)v_comfortable) > 1.0E-6)
  {
  }
  else
  {
    v_comfortable = 1.0E-6F;
  }

  v_comfortable = lateral_dist_to_go_abs / v_comfortable;
  if (lateral_dist_to_go_abs > (target_lane_width * 0.5F))
  {
    target_lane_width = lateral_dist_to_go_abs - (target_lane_width * 0.5F);
    if (((real_T)angle) > 1.0E-6)
    {
      angle_0 = angle;
    }
    else
    {
      angle_0 = 1.0E-6F;
    }

    if (((real_T)target_lane_width) > 1.0E-6)
    {
      lc_time = target_lane_width;
    }
    else
    {
      lc_time = 1.0E-6F;
    }

    lc_time = (ego_lane_length / angle_0) * (lateral_dist_to_go_abs / lc_time);
    if (((real_T)lateral_dist_to_go_abs) > 1.0E-6)
    {
      angle_0 = lateral_dist_to_go_abs;
    }
    else
    {
      angle_0 = 1.0E-6F;
    }

    target_lane_width =
      ALCA_subsystem_integrated_DW.KfALCA_t_LaneChangeTimeMin_jj0b *
      (target_lane_width / angle_0);
  }
  else
  {
    target_lane_width = 0.0F;
    lc_time = v_comfortable;
  }

  if (lc_time > v_comfortable)
  {
    lc_time = v_comfortable;
  }

  if (lc_time < ALCA_subsystem_integrated_DW.KfALCA_t_LaneChangeTimeMax_lff2)
  {
  }
  else
  {
    lc_time = ALCA_subsystem_integrated_DW.KfALCA_t_LaneChangeTimeMax_lff2;
  }

  ego_lane_length_enough = (ego_lane_length > (target_lane_width * angle));
  if (((uint32_T)rtu_pre_state) == ALCA_state_Activated)
  {
    ego_lane_length_enough = true;
  }

  if (dcsn_condiction && (((int32_T)rtu_fault) != 0))
  {
    b_not_fulfill_reason = ALCA_not_fulfill_reason_system_error;
  }
  else if (dcsn_condiction && (rtu_veh_state->veh_speed <
            ALCA_subsystem_integrated_DW.KfALCA_v_SpeedLaneChangeEn_hgzb))
  {
    b_not_fulfill_reason = ALCA_not_fulfill_reason_low_speed;
  }
  else if (dcsn_condiction && (rtu_veh_state->veh_speed >
            ALCA_subsystem_integrated_DW.KfALCA_v_SpeedLaneChangeEn_g0ux))
  {
    b_not_fulfill_reason = ALCA_not_fulfill_reason_high_speed;
  }
  else if (dcsn_condiction && (((uint32_T)rtu_pre_state) == ALCA_state_Finish))
  {
    b_not_fulfill_reason = ALCA_not_fulfill_reason_too_often;
  }
  else if (rtu_touched_new_lane && dcsn_condiction)
  {
    map_accept = true;
    b_inform_side = rtu_dcsn_info->change_lane_req_side;
  }
  else
  {
    check_side = 0U;
    if (dcsn_condiction)
    {
      b_not_fulfill_reason = ALCA_not_fulfill_reason_check_fulfilled;
      if ((rtu_mpfu_info->has_ego_lane) && ((((((uint32_T)
               rtu_dcsn_info->change_lane_req_side) == LEFT) &&
             (rtu_mpfu_info->has_left_lane)) &&
            (rtu_mpfu_info->has_left_lane_marker)) || (((((uint32_T)
               rtu_dcsn_info->change_lane_req_side) == RIGHT) &&
             (rtu_mpfu_info->has_right_lane)) &&
            (rtu_mpfu_info->has_right_lane_marker))))
      {
        target_lane_allow = false;
        switch (rtu_dcsn_info->change_lane_req_side)
        {
         case LEFT:
          check_side = 1U;

          /* Inport: '<Root>/MPFU_DataBus' */
          target_lane_allow = ALCA_subsyste_check_target_lane(rtu_pre_state,
            rtu_veh_state->veh_speed, VsMPFU_DataBus.lanes
            [rtu_mpfu_info->target_lane_from_dcsn_index - 1].width,
            VsMPFU_DataBus.lanes[rtu_mpfu_info->target_lane_from_dcsn_index - 1]
            .length, VsMPFU_DataBus.lanes
            [rtu_mpfu_info->target_lane_from_dcsn_index - 1].type,
            VsMPFU_DataBus.lane_markers[rtu_mpfu_info->left_lane_marker_index -
            1].type);
          break;

         case RIGHT:
          check_side = 2U;

          /* Inport: '<Root>/MPFU_DataBus' */
          target_lane_allow = ALCA_subsyste_check_target_lane(rtu_pre_state,
            rtu_veh_state->veh_speed, VsMPFU_DataBus.lanes
            [rtu_mpfu_info->target_lane_from_dcsn_index - 1].width,
            VsMPFU_DataBus.lanes[rtu_mpfu_info->target_lane_from_dcsn_index - 1]
            .length, VsMPFU_DataBus.lanes
            [rtu_mpfu_info->target_lane_from_dcsn_index - 1].type,
            VsMPFU_DataBus.lane_markers[rtu_mpfu_info->right_lane_marker_index -
            1].type);
          break;

         default:
          /* no actions */
          break;
        }

        if (target_lane_allow)
        {
          map_accept = true;
        }
        else
        {
          b_not_fulfill_reason = ALCA_not_fulfill_reason_mpfu_reject;
          check_side = 0U;
        }
      }
      else if ((rtu_inform_suggest && (rtu_mpfu_info->has_ego_lane)) &&
               ((rtu_mpfu_info->has_left_lane) || (rtu_mpfu_info->has_right_lane)))
      {
      }
      else
      {
        b_not_fulfill_reason = ALCA_not_fulfill_reason_mpfu_reject;
      }
    }

    map_accept = (map_accept && ego_lane_length_enough);
    if (map_accept)
    {
      ego_lane_length_enough = true;
      b_inform_side = FORWARD;
      e_obstacle_index = 1U;
      switch (check_side)
      {
       case 1U:
        /* Inport: '<Root>/MPFU_DataBus' incorporates:
         *  Inport: '<Root>/OBFU_DataBus'
         */
        ALCA_sub_check_target_lane_hgrj(rtu_mpfu_info->left_lane_marker_index,
          rtu_mpfu_info->target_lane_from_dcsn_index, rtu_veh_state->veh_speed,
          VsMPFU_DataBus.lanes, VsMPFU_DataBus.lane_markers,
          VsOBFU_DataBus.obstacles, VsOBFU_DataBus.num_obstacles,
          rtu_RelativeSpeed_X, rtu_VehSpeed_Y, rtu_RangeFront_V, rtu_RangeRear_V,
          lateral_dist_to_go_abs, &ego_lane_length_enough, &e_obstacle_index);
        if (!ego_lane_length_enough)
        {
          b_inform_side = LEFT;
        }
        break;

       case 2U:
        /* Inport: '<Root>/MPFU_DataBus' incorporates:
         *  Inport: '<Root>/OBFU_DataBus'
         */
        ALCA_su_check_target_lane_hgrjc(rtu_mpfu_info->left_lane_marker_index,
          rtu_mpfu_info->right_lane_marker_index,
          rtu_mpfu_info->target_lane_from_dcsn_index, rtu_veh_state->veh_speed,
          VsMPFU_DataBus.lanes, VsMPFU_DataBus.lane_markers,
          VsOBFU_DataBus.obstacles, VsOBFU_DataBus.num_obstacles,
          rtu_RelativeSpeed_X, rtu_VehSpeed_Y, rtu_RangeFront_V, rtu_RangeRear_V,
          lateral_dist_to_go_abs, false, &ego_lane_length_enough,
          &e_obstacle_index);
        if (!ego_lane_length_enough)
        {
          b_inform_side = RIGHT;
        }
        break;

       case 3U:
        /* Inport: '<Root>/MPFU_DataBus' incorporates:
         *  Inport: '<Root>/OBFU_DataBus'
         */
        ALCA_sub_check_target_lane_hgrj(rtu_mpfu_info->left_lane_marker_index,
          rtu_mpfu_info->target_lane_from_dcsn_index, rtu_veh_state->veh_speed,
          VsMPFU_DataBus.lanes, VsMPFU_DataBus.lane_markers,
          VsOBFU_DataBus.obstacles, VsOBFU_DataBus.num_obstacles,
          rtu_RelativeSpeed_X, rtu_VehSpeed_Y, rtu_RangeFront_V, rtu_RangeRear_V,
          lateral_dist_to_go_abs, &ego_lane_length_enough, &e_obstacle_index);
        if (!ego_lane_length_enough)
        {
          b_inform_side = LEFT;
        }
        else
        {
          /* Inport: '<Root>/MPFU_DataBus' incorporates:
           *  Inport: '<Root>/OBFU_DataBus'
           */
          ALCA_su_check_target_lane_hgrjc(rtu_mpfu_info->left_lane_marker_index,
            rtu_mpfu_info->right_lane_marker_index,
            rtu_mpfu_info->target_lane_from_dcsn_index, rtu_veh_state->veh_speed,
            VsMPFU_DataBus.lanes, VsMPFU_DataBus.lane_markers,
            VsOBFU_DataBus.obstacles, VsOBFU_DataBus.num_obstacles,
            rtu_RelativeSpeed_X, rtu_VehSpeed_Y, rtu_RangeFront_V,
            rtu_RangeRear_V, lateral_dist_to_go_abs, false,
            &ego_lane_length_enough, &e_obstacle_index);
          if (!ego_lane_length_enough)
          {
            b_inform_side = RIGHT;
          }
        }
        break;

       default:
        /* no actions */
        break;
      }

      obfu_accept = !ego_lane_length_enough;
      if (!obfu_accept)
      {
        /* Inport: '<Root>/OBFU_DataBus' */
        *rty_dangerous_obstacle = VsOBFU_DataBus.obstacles[((int32_T)
          e_obstacle_index) - 1];
      }
    }

    if (((ALCA_subsystem_integrated_DW.KbALCA_EnblCheckObstacles_odv1) &&
         map_accept) && (!obfu_accept))
    {
      b_not_fulfill_reason = ALCA_not_fulfill_reason_has_obstacle;
    }

    if (ALCA_subsystem_integrated_DW.KbALCA_EnblCheckObstacles_odv1)
    {
      map_accept = (map_accept && obfu_accept);
    }
    else
    {
      b_inform_side = rtu_dcsn_info->change_lane_req_side;
    }

    obfu_accept = (rtu_inform_suggest && map_accept);
  }

  if (!dcsn_condiction)
  {
    b_not_fulfill_reason = ALCA_not_fulfill_reason_no_request;
  }

  *rty_lc_acceptable = map_accept;
  *rty_not_fulfill_reason = b_not_fulfill_reason;
  *rty_inform_req = obfu_accept;
  *rty_inform_side = b_inform_side;
  *rty_req_side = b_inform_side;
  *rty_lc_time = lc_time;
  *rty_dist_host_2_target_lane_cen = dist_host_2_target_lane_center;
  *rty_v_lon = angle;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
