/*
 * File: AEB_FCWVIPTargetSelection.c
 *
 * Code generated for Simulink model 'AEBS_subsystem_integrated'.
 *
 * Model version                  : 1.3091
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 16:35:01 2020
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

#include "AEB_FCWVIPTargetSelection.h"

/* Include model header file for global data */
#include "AEBS_subsystem_integrated.h"
#include "AEBS_subsystem_integrated_private.h"
#include "look1_iflf_binlc.h"
#include "ttc_calculation_aebs_an7L2XSm.h"

/* Named constants for Chart: '<S166>/Chart' */
#define AEBS_su_IN_NO_ACTIVE_CHILD_ofei ((uint8_T)0U)
#define AEBS_subsystem_in_IN_Right_Turn ((uint8_T)2U)
#define AEBS_subsystem_int_IN_Left_Turn ((uint8_T)1U)
#define AEBS_subsystem_inte_IN_Straight ((uint8_T)3U)

/* Forward declaration for local functions */
static void AEBS_subsyste_init_obs_vip_info(AEBS_Obs_VIP_info_Bus *obs_vip_info);
static void AEBS_sub_vip_selection_straight(real32_T veh_speed, real32_T
  veh_acceleration, const real32_T obs_lateral_buffer[120], const real32_T
  obs_long_buffer[120], const OBFU_Obstacle OBFU_Data_obstacles[128], uint16_T
  OBFU_Data_num_obstacles, const boolean_T *KbAEBS_FilterVehicleinSide_pjy4,
  const boolean_T *KbAEBS_Use_OBFU_Accelerati_jkde, const boolean_T
  *KbAEBS_use_OBFU_speed_ne4p, real32_T *KfAEBS_GainTHW_lutf, real32_T
  *KfAEBS_GainTTC_b2qu, real32_T *KfAEBS_Veh_Dis2OC_useCenterPoin,
  AEBS_Obs_VIP_info_Bus *obs_vip_info, uint8_T obs_position_state[32], real32_T
  obs_delta_dis[32], real32_T obs_delta_speed[32], real32_T obs_ttc[32],
  real32_T obs_dis2adc_long[32], real32_T obs_dis2adc_lateral[32], real32_T
  obs_v_long[32], real32_T obs_v_lateral[32], uint8_T obs_filtered_type[32]);
static void AEBS_subsyst_vip_selection_turn(boolean_T right_turn, real32_T
  veh_speed, real32_T adc_v_x, real32_T adc_v_y, real32_T veh_acceleration,
  real32_T veh_curvature, real32_T veh_width_update, const real32_T
  obs_long_buffer[120], const OBFU_Obstacle OBFU_Data_obstacles[128], uint16_T
  OBFU_Data_num_obstacles, const boolean_T *KbAEBS_FilterVehicleinSide_pjy4,
  const boolean_T *KbAEBS_Use_OBFU_Accelerati_jkde, const real32_T
  *KfAEBS_Pedstr_width_Thrsh_golk, real32_T *KfAEBS_GainTHW_lutf, real32_T
  *KfAEBS_GainTTC_b2qu, real32_T *KfAEBS_Veh_DisRear2OC_kfng,
  AEBS_Obs_VIP_info_Bus *obs_vip_info, uint8_T obs_position_state[32], real32_T
  obs_delta_dis[32], real32_T obs_delta_speed[32], real32_T obs_ttc[32],
  real32_T obs_dis2adc_long[32], real32_T obs_dis2adc_lateral[32], real32_T
  obs_v_long[32], real32_T obs_v_lateral[32], uint8_T obs_filtered_type[32]);

/* Function for MATLAB Function: '<S9>/AEB_Target_Selection' */
static void AEBS_subsyste_init_obs_vip_info(AEBS_Obs_VIP_info_Bus *obs_vip_info)
{
  obs_vip_info->has_obs_VIP = false;
  obs_vip_info->obs_index_VIP = 0U;
  obs_vip_info->obs_rp_VIP = 0.0F;
  obs_vip_info->obs_position_state_VIP = 0U;
  obs_vip_info->obs_ttc_VIP = 0.0F;
  obs_vip_info->obs_delta_dis_VIP = 0.0F;
  obs_vip_info->obs_delta_speed_VIP = 0.0F;
  obs_vip_info->obs_id_VIP = 0;
  obs_vip_info->obs_type_VIP = 0;
  obs_vip_info->obs_v_lateral_VIP = 0.0F;
  obs_vip_info->obs_v_long_VIP = 0.0F;
  obs_vip_info->obs_acc_lateral_VIP = 0.0F;
  obs_vip_info->obs_acc_long_VIP = 0.0F;
  obs_vip_info->obs_NP_x_VIP = 0.0F;
  obs_vip_info->obs_NP_y_VIP = 0.0F;
  obs_vip_info->obs_heading_VIP = 0.0F;
  obs_vip_info->obs_length_VIP = 0.0F;
  obs_vip_info->obs_width_VIP = 0.0F;
  obs_vip_info->obs_dis_long_VIP = 0.0F;
  obs_vip_info->obs_dis_lateral_VIP = 0.0F;
  obs_vip_info->obs_position_zone_VIP = 0;
  obs_vip_info->obs_motion_status_VIP = 0;
  obs_vip_info->obs_confidence_VIP = 0U;
}

/* Function for MATLAB Function: '<S9>/AEB_Target_Selection' */
static void AEBS_sub_vip_selection_straight(real32_T veh_speed, real32_T
  veh_acceleration, const real32_T obs_lateral_buffer[120], const real32_T
  obs_long_buffer[120], const OBFU_Obstacle OBFU_Data_obstacles[128], uint16_T
  OBFU_Data_num_obstacles, const boolean_T *KbAEBS_FilterVehicleinSide_pjy4,
  const boolean_T *KbAEBS_Use_OBFU_Accelerati_jkde, const boolean_T
  *KbAEBS_use_OBFU_speed_ne4p, real32_T *KfAEBS_GainTHW_lutf, real32_T
  *KfAEBS_GainTTC_b2qu, real32_T *KfAEBS_Veh_Dis2OC_useCenterPoin,
  AEBS_Obs_VIP_info_Bus *obs_vip_info, uint8_T obs_position_state[32], real32_T
  obs_delta_dis[32], real32_T obs_delta_speed[32], real32_T obs_ttc[32],
  real32_T obs_dis2adc_long[32], real32_T obs_dis2adc_lateral[32], real32_T
  obs_v_long[32], real32_T obs_v_lateral[32], uint8_T obs_filtered_type[32])
{
  real32_T rp_max;
  uint16_T rp_max_index;
  real32_T vip_delta_dis;
  real32_T vip_delta_speed;
  real32_T vip_dis_long;
  real32_T vip_dis_lateral;
  uint8_T vip_position_state;
  real32_T vip_obs_ttc;
  real32_T obs_velocity_long;
  real32_T dis2adc_long;
  real32_T dis2adc_lateral;
  boolean_T is_infront;
  boolean_T is_inRight;
  boolean_T is_inLeft;
  real32_T obs_proj;
  boolean_T use_center;
  boolean_T use_nearest_point;
  real32_T obs_acceleration_long;
  real32_T delta_speed_long;
  uint16_T i;
  int32_T i_0;
  real32_T TTSP;
  real32_T tmp;
  real32_T TTSP_tmp;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  AEBS_subsyste_init_obs_vip_info(obs_vip_info);
  rp_max = 0.0F;
  rp_max_index = 0U;
  memset(&obs_delta_dis[0], 0, (sizeof(real32_T)) << 5U);
  memset(&obs_delta_speed[0], 0, (sizeof(real32_T)) << 5U);
  memset(&obs_ttc[0], 0, (sizeof(real32_T)) << 5U);
  memset(&obs_dis2adc_long[0], 0, (sizeof(real32_T)) << 5U);
  memset(&obs_dis2adc_lateral[0], 0, (sizeof(real32_T)) << 5U);
  memset(&obs_v_long[0], 0, (sizeof(real32_T)) << 5U);
  memset(&obs_v_lateral[0], 0, (sizeof(real32_T)) << 5U);
  for (i_0 = 0; i_0 < 32; i_0++)
  {
    obs_position_state[i_0] = 0U;
    obs_filtered_type[i_0] = 0U;
  }

  vip_delta_dis = 0.0F;
  vip_delta_speed = 0.0F;
  vip_dis_long = 0.0F;
  vip_dis_lateral = 0.0F;
  vip_position_state = 0U;
  vip_obs_ttc = 0.0F;
  for (i = 1U; i <= OBFU_Data_num_obstacles; i = (uint16_T)(((uint32_T)i) + 1U))
  {
    i_0 = ((int32_T)i) - 1;
    if (OBFU_Data_obstacles[i_0].id < 1)
    {
      if (((int32_T)i) < 33)
      {
        obs_filtered_type[i_0] = 1U;
      }
    }
    else
    {
      obs_velocity_long = veh_speed + OBFU_Data_obstacles[((int32_T)i) - 1].
        velocity_rel.x;
      dis2adc_long = 0.0F;
      dis2adc_lateral = 0.0F;
      is_infront = false;
      is_inRight = false;
      is_inLeft = false;
      obs_proj = 0.0F;
      use_center = false;
      use_nearest_point = false;
      if (((OBFU_Data_obstacles[((int32_T)i) - 1].position_zone == 6) ||
           (OBFU_Data_obstacles[((int32_T)i) - 1].position_zone == 7)) ||
          (OBFU_Data_obstacles[((int32_T)i) - 1].position_zone == 8))
      {
        if (((int32_T)i) < 33)
        {
          obs_filtered_type[i_0] = 2U;
        }
      }
      else if (OBFU_Data_obstacles[((int32_T)i) - 1].nearest_point_rel.x <
               AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisIngnore2OC_p2fq)
      {
        if (((int32_T)i) < 33)
        {
          obs_filtered_type[i_0] = 4U;
        }
      }
      else
      {
        if (*KbAEBS_Use_OBFU_Accelerati_jkde)
        {
          switch (OBFU_Data_obstacles[((int32_T)i) - 1].type)
          {
           case 3:
            obs_acceleration_long = veh_acceleration + OBFU_Data_obstacles
              [((int32_T)i) - 1].acceleration_rel.x;
            break;

           case 4:
            obs_acceleration_long = veh_acceleration + OBFU_Data_obstacles
              [((int32_T)i) - 1].acceleration_rel.x;
            break;

           case 5:
            obs_acceleration_long = veh_acceleration + OBFU_Data_obstacles
              [((int32_T)i) - 1].acceleration_rel.x;
            break;

           case 6:
            obs_acceleration_long = veh_acceleration + OBFU_Data_obstacles
              [((int32_T)i) - 1].acceleration_rel.x;
            break;

           default:
            obs_acceleration_long = 0.0F;
            break;
          }
        }
        else
        {
          obs_acceleration_long = 0.0F;
        }

        delta_speed_long = veh_speed - obs_velocity_long;
        if ((((real_T)delta_speed_long) < 0.01) && (delta_speed_long >=
             (-AEBS_subsystem_integrated_DW.KfAEBS_v_Speed_DeltaWExit_gqet)))
        {
          delta_speed_long = 0.01F;
        }

        if (delta_speed_long <
            (-AEBS_subsystem_integrated_DW.KfAEBS_v_Speed_DeltaWExit_gqet))
        {
          if (((int32_T)i) < 33)
          {
            obs_filtered_type[i_0] = 3U;
          }
        }
        else
        {
          if (OBFU_Data_obstacles[((int32_T)i) - 1].position_zone == 2)
          {
            use_center = true;
          }
          else if (OBFU_Data_obstacles[((int32_T)i) - 1].nearest_point_rel.x > (*
                    KfAEBS_Veh_Dis2OC_useCenterPoin))
          {
            use_center = true;
          }
          else
          {
            use_nearest_point = true;
          }

          if (use_center)
          {
            if (((real32_T)fabs((real_T)OBFU_Data_obstacles[((int32_T)i) - 1].
                                nearest_point_rel.y)) <= (0.5F *
                 AEBS_subsystem_integrated_DW.KfAEBS_Veh_Width_b12o))
            {
              is_infront = true;
            }

            if (OBFU_Data_obstacles[((int32_T)i) - 1].nearest_point_rel.y <
                (-0.5F * AEBS_subsystem_integrated_DW.KfAEBS_Veh_Width_b12o))
            {
              if ((((((real_T)OBFU_Data_obstacles[((int32_T)i) - 1].heading_rel)
                     > -0.78539816339744828) && (((real_T)OBFU_Data_obstacles
                      [((int32_T)i) - 1].heading_rel) < 0.78539816339744828)) ||
                   ((((real_T)OBFU_Data_obstacles[((int32_T)i) - 1].heading_rel)
                     > 2.3561944901923448) && (((real_T)OBFU_Data_obstacles
                      [((int32_T)i) - 1].heading_rel) <= 3.1415926535897931))) ||
                  ((((real_T)OBFU_Data_obstacles[((int32_T)i) - 1].heading_rel) >=
                    -3.1415926535897931) && (((real_T)OBFU_Data_obstacles
                     [((int32_T)i) - 1].heading_rel) <= -2.3561944901923448)))
              {
                dis2adc_lateral = (OBFU_Data_obstacles[((int32_T)i) - 1].
                                   nearest_point_rel.y + (0.5F *
                  OBFU_Data_obstacles[((int32_T)i) - 1].width)) +
                  obs_lateral_buffer[((int32_T)i) - 1];
                if (dis2adc_lateral > (-0.5F *
                                       AEBS_subsystem_integrated_DW.KfAEBS_Veh_Width_b12o))
                {
                  is_infront = true;
                  dis2adc_lateral = 0.0F;
                }
                else
                {
                  is_inRight = true;
                  obs_proj = OBFU_Data_obstacles[((int32_T)i) - 1].width +
                    obs_lateral_buffer[((int32_T)i) - 1];
                  dis2adc_lateral = ((real32_T)fabs((real_T)dis2adc_lateral)) -
                    (0.5F * AEBS_subsystem_integrated_DW.KfAEBS_Veh_Width_b12o);
                }

                dis2adc_long = (OBFU_Data_obstacles[((int32_T)i) - 1].
                                nearest_point_rel.x - obs_long_buffer[((int32_T)
                  i) - 1]) -
                  AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms;
              }
              else
              {
                dis2adc_lateral = (OBFU_Data_obstacles[((int32_T)i) - 1].
                                   nearest_point_rel.y + (0.5F *
                  OBFU_Data_obstacles[((int32_T)i) - 1].length)) +
                  obs_lateral_buffer[((int32_T)i) - 1];
                if (dis2adc_lateral > (-0.5F *
                                       AEBS_subsystem_integrated_DW.KfAEBS_Veh_Width_b12o))
                {
                  is_infront = true;
                  dis2adc_lateral = 0.0F;
                }
                else
                {
                  is_inRight = true;
                  obs_proj = OBFU_Data_obstacles[((int32_T)i) - 1].length +
                    obs_lateral_buffer[((int32_T)i) - 1];
                  dis2adc_lateral = ((real32_T)fabs((real_T)dis2adc_lateral)) -
                    (0.5F * AEBS_subsystem_integrated_DW.KfAEBS_Veh_Width_b12o);
                }

                dis2adc_long = (OBFU_Data_obstacles[((int32_T)i) - 1].
                                nearest_point_rel.x - obs_long_buffer[((int32_T)
                  i) - 1]) -
                  AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms;
              }
            }
            else if ((((((real_T)OBFU_Data_obstacles[((int32_T)i) - 1].
                         heading_rel) > -0.78539816339744828) && (((real_T)
                         OBFU_Data_obstacles[((int32_T)i) - 1].heading_rel) <
                        0.78539816339744828)) || ((((real_T)OBFU_Data_obstacles
                         [((int32_T)i) - 1].heading_rel) > 2.3561944901923448) &&
                       (((real_T)OBFU_Data_obstacles[((int32_T)i) - 1].
                         heading_rel) <= 3.1415926535897931))) || ((((real_T)
                        OBFU_Data_obstacles[((int32_T)i) - 1].heading_rel) >=
                       -3.1415926535897931) && (((real_T)OBFU_Data_obstacles
                        [((int32_T)i) - 1].heading_rel) <= -2.3561944901923448)))
            {
              dis2adc_lateral = (OBFU_Data_obstacles[((int32_T)i) - 1].
                                 nearest_point_rel.y - (0.5F *
                OBFU_Data_obstacles[((int32_T)i) - 1].width)) -
                obs_lateral_buffer[((int32_T)i) - 1];
              if (dis2adc_lateral < (0.5F *
                                     AEBS_subsystem_integrated_DW.KfAEBS_Veh_Width_b12o))
              {
                is_infront = true;
                dis2adc_lateral = 0.0F;
              }
              else
              {
                is_inLeft = true;
                obs_proj = OBFU_Data_obstacles[((int32_T)i) - 1].width +
                  obs_lateral_buffer[((int32_T)i) - 1];
                dis2adc_lateral = ((real32_T)fabs((real_T)dis2adc_lateral)) -
                  (0.5F * AEBS_subsystem_integrated_DW.KfAEBS_Veh_Width_b12o);
              }

              dis2adc_long = (OBFU_Data_obstacles[((int32_T)i) - 1].
                              nearest_point_rel.x - obs_long_buffer[((int32_T)i)
                              - 1]) -
                AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms;
            }
            else
            {
              dis2adc_lateral = (OBFU_Data_obstacles[((int32_T)i) - 1].
                                 nearest_point_rel.y - (0.5F *
                OBFU_Data_obstacles[((int32_T)i) - 1].length)) -
                obs_lateral_buffer[i_0];
              if (dis2adc_lateral < (0.5F *
                                     AEBS_subsystem_integrated_DW.KfAEBS_Veh_Width_b12o))
              {
                is_infront = true;
                dis2adc_lateral = 0.0F;
              }
              else
              {
                is_inLeft = true;
                obs_proj = OBFU_Data_obstacles[((int32_T)i) - 1].length +
                  obs_lateral_buffer[((int32_T)i) - 1];
                dis2adc_lateral = ((real32_T)fabs((real_T)dis2adc_lateral)) -
                  (0.5F * AEBS_subsystem_integrated_DW.KfAEBS_Veh_Width_b12o);
              }

              dis2adc_long = (OBFU_Data_obstacles[((int32_T)i) - 1].
                              nearest_point_rel.x - obs_long_buffer[i_0]) -
                AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms;
            }
          }

          if (use_nearest_point)
          {
            if (((real32_T)fabs((real_T)OBFU_Data_obstacles[((int32_T)i) - 1].
                                nearest_point_rel.y)) <= (0.5F *
                 AEBS_subsystem_integrated_DW.KfAEBS_Veh_Width_b12o))
            {
              is_infront = true;
            }

            if (OBFU_Data_obstacles[((int32_T)i) - 1].nearest_point_rel.y <
                (-0.5F * AEBS_subsystem_integrated_DW.KfAEBS_Veh_Width_b12o))
            {
              if (OBFU_Data_obstacles[((int32_T)i) - 1].nearest_point_rel.y >
                  (-0.5F * AEBS_subsystem_integrated_DW.KfAEBS_Veh_Width_b12o))
              {
                is_infront = true;
                dis2adc_lateral = 0.0F;
              }
              else
              {
                is_inRight = true;
                obs_proj = OBFU_Data_obstacles[((int32_T)i) - 1].width +
                  obs_lateral_buffer[((int32_T)i) - 1];
                dis2adc_lateral = ((real32_T)fabs((real_T)((real32_T)
                  (OBFU_Data_obstacles[((int32_T)i) - 1].nearest_point_rel.y +
                   obs_lateral_buffer[((int32_T)i) - 1])))) - (0.5F *
                  AEBS_subsystem_integrated_DW.KfAEBS_Veh_Width_b12o);
              }

              dis2adc_long = (OBFU_Data_obstacles[((int32_T)i) - 1].
                              nearest_point_rel.x - obs_long_buffer[((int32_T)i)
                              - 1]) -
                AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms;
            }
            else
            {
              if (OBFU_Data_obstacles[((int32_T)i) - 1].nearest_point_rel.y <
                  (0.5F * AEBS_subsystem_integrated_DW.KfAEBS_Veh_Width_b12o))
              {
                is_infront = true;
                dis2adc_lateral = 0.0F;
              }
              else
              {
                is_inLeft = true;
                obs_proj = OBFU_Data_obstacles[((int32_T)i) - 1].width +
                  obs_lateral_buffer[((int32_T)i) - 1];
                dis2adc_lateral = ((real32_T)fabs((real_T)((real32_T)
                  (OBFU_Data_obstacles[((int32_T)i) - 1].nearest_point_rel.y -
                   obs_lateral_buffer[((int32_T)i) - 1])))) - (0.5F *
                  AEBS_subsystem_integrated_DW.KfAEBS_Veh_Width_b12o);
              }

              dis2adc_long = (OBFU_Data_obstacles[((int32_T)i) - 1].
                              nearest_point_rel.x - obs_long_buffer[((int32_T)i)
                              - 1]) -
                AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms;
            }
          }

          if (((int32_T)i) < 33)
          {
            obs_dis2adc_long[i_0] = dis2adc_long;
            obs_dis2adc_lateral[i_0] = dis2adc_lateral;
          }

          guard1 = false;
          guard2 = false;
          if (is_inLeft)
          {
            if (OBFU_Data_obstacles[((int32_T)i) - 1].velocity_rel.y >
                (-AEBS_subsystem_integrated_DW.KfAEBS_v_Speed_ObjStillThrshLat))
            {
              if (((int32_T)i) < 33)
              {
                obs_filtered_type[i_0] = 9U;
              }
            }
            else if ((*KbAEBS_FilterVehicleinSide_pjy4) &&
                     (((OBFU_Data_obstacles[((int32_T)i) - 1].type == 4) ||
                       (OBFU_Data_obstacles[((int32_T)i) - 1].type == 5)) ||
                      (OBFU_Data_obstacles[((int32_T)i) - 1].type == 6)))
            {
              if (((int32_T)i) < 33)
              {
                obs_filtered_type[i_0] = 10U;
              }
            }
            else
            {
              guard2 = true;
            }
          }
          else
          {
            guard2 = true;
          }

          if (guard2)
          {
            if (is_inRight)
            {
              if (OBFU_Data_obstacles[((int32_T)i) - 1].velocity_rel.y <
                  AEBS_subsystem_integrated_DW.KfAEBS_v_Speed_ObjStillThrshLat)
              {
                if (((int32_T)i) < 33)
                {
                  obs_filtered_type[i_0] = 12U;
                }
              }
              else if ((*KbAEBS_FilterVehicleinSide_pjy4) &&
                       (((OBFU_Data_obstacles[((int32_T)i) - 1].type == 4) ||
                         (OBFU_Data_obstacles[((int32_T)i) - 1].type == 5)) ||
                        (OBFU_Data_obstacles[((int32_T)i) - 1].type == 6)))
              {
                if (((int32_T)i) < 33)
                {
                  obs_filtered_type[i_0] = 13U;
                }
              }
              else
              {
                guard1 = true;
              }
            }
            else
            {
              guard1 = true;
            }
          }

          if (guard1)
          {
            if (((int32_T)i) < 33)
            {
              obs_delta_dis[i_0] = dis2adc_long;
              obs_delta_speed[i_0] = delta_speed_long;
              obs_v_long[i_0] = obs_velocity_long;
              obs_v_lateral[i_0] = OBFU_Data_obstacles[((int32_T)i) - 1].
                velocity_rel.y;
              if (is_infront)
              {
                obs_position_state[i_0] = 1U;
              }
              else
              {
                obs_position_state[i_0] = 2U;
              }
            }

            if (((real_T)dis2adc_long) < 0.1)
            {
              dis2adc_long = 0.1F;
            }

            if (((real_T)dis2adc_long) > 0.01)
            {
              obs_velocity_long = dis2adc_long;
            }
            else
            {
              obs_velocity_long = 0.01F;
            }

            obs_velocity_long = (((*KfAEBS_GainTTC_b2qu) * delta_speed_long) +
                                 ((*KfAEBS_GainTHW_lutf) * veh_speed)) /
              obs_velocity_long;
            obs_acceleration_long = ttc_calculation_aebs_an7L2XSm(dis2adc_long,
              delta_speed_long, veh_acceleration - obs_acceleration_long);
            if (!(*KbAEBS_use_OBFU_speed_ne4p))
            {
              delta_speed_long = veh_speed +
                AEBS_subsystem_integrated_DW.KfAEBS_v_obsSpdBuffer_dhnh;
            }

            if (((int32_T)i) < 33)
            {
              obs_ttc[i_0] = obs_acceleration_long;
            }

            if (is_infront)
            {
              if (((int32_T)rp_max_index) == 0)
              {
                rp_max = obs_velocity_long;
                rp_max_index = i;
                vip_delta_dis = dis2adc_long;
                vip_delta_speed = delta_speed_long;
                vip_dis_long = dis2adc_long;
                vip_dis_lateral = dis2adc_lateral;
                vip_obs_ttc = obs_acceleration_long;
                vip_position_state = 1U;
              }
              else
              {
                if (obs_velocity_long > rp_max)
                {
                  rp_max = obs_velocity_long;
                  rp_max_index = i;
                  vip_delta_dis = dis2adc_long;
                  vip_delta_speed = delta_speed_long;
                  vip_dis_long = dis2adc_long;
                  vip_dis_lateral = dis2adc_lateral;
                  vip_obs_ttc = obs_acceleration_long;
                  vip_position_state = 1U;
                }
              }
            }
            else
            {
              tmp = (real32_T)fabs((real_T)dis2adc_lateral);
              if (tmp >
                  AEBS_subsystem_integrated_DW.KfAEBS_d_Dis_LateralIgnore_jbqn)
              {
                if (((int32_T)i) < 33)
                {
                  obs_filtered_type[i_0] = 14U;
                }
              }
              else
              {
                TTSP_tmp = (real32_T)fabs((real_T)OBFU_Data_obstacles[((int32_T)
                  i) - 1].velocity_rel.y);
                if (((real_T)TTSP_tmp) > 0.01)
                {
                  TTSP = TTSP_tmp;
                }
                else
                {
                  TTSP = 0.01F;
                }

                TTSP = tmp / TTSP;
                if (TTSP >= obs_acceleration_long)
                {
                  if (((real_T)veh_speed) > 0.01)
                  {
                    obs_proj = veh_speed;
                  }
                  else
                  {
                    obs_proj = 0.01F;
                  }

                  is_infront = ((TTSP - obs_acceleration_long) <
                                ((AEBS_subsystem_integrated_DW.KfAEBS_d_Dis_BufferTTSP_le_ahgr
                                  + AEBS_subsystem_integrated_DW.KfAEBS_d_Dis_BufferTTSP_fvf0)
                                 / obs_proj));
                }
                else
                {
                  if (((real_T)TTSP_tmp) > 0.01)
                  {
                  }
                  else
                  {
                    TTSP_tmp = 0.01F;
                  }

                  is_infront = ((obs_acceleration_long - TTSP) <
                                (((AEBS_subsystem_integrated_DW.KfAEBS_Veh_Width_b12o
                                   + AEBS_subsystem_integrated_DW.KfAEBS_d_Dis_BufferTTSP_fvf0)
                                  + obs_proj) / TTSP_tmp));
                }

                if (!is_infront)
                {
                  if (((int32_T)i) < 33)
                  {
                    obs_filtered_type[i_0] = 15U;
                  }
                }
                else if (((int32_T)rp_max_index) == 0)
                {
                  rp_max = obs_velocity_long;
                  rp_max_index = i;
                  vip_delta_dis = dis2adc_long;
                  vip_delta_speed = delta_speed_long;
                  vip_dis_long = dis2adc_long;
                  vip_dis_lateral = dis2adc_lateral;
                  vip_obs_ttc = obs_acceleration_long;
                  vip_position_state = 2U;
                }
                else
                {
                  if (obs_velocity_long > rp_max)
                  {
                    rp_max = obs_velocity_long;
                    rp_max_index = i;
                    vip_delta_dis = dis2adc_long;
                    vip_delta_speed = delta_speed_long;
                    vip_dis_long = dis2adc_long;
                    vip_dis_lateral = dis2adc_lateral;
                    vip_obs_ttc = obs_acceleration_long;
                    vip_position_state = 2U;
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  if (((int32_T)rp_max_index) != 0)
  {
    obs_vip_info->has_obs_VIP = true;
    i = rp_max_index;
    if (((int32_T)rp_max_index) > 255)
    {
      i = 255U;
    }

    obs_vip_info->obs_index_VIP = (uint8_T)i;
    obs_vip_info->obs_rp_VIP = rp_max;
    obs_vip_info->obs_position_state_VIP = vip_position_state;
    obs_vip_info->obs_ttc_VIP = vip_obs_ttc;
    obs_vip_info->obs_delta_dis_VIP = vip_delta_dis;
    obs_vip_info->obs_delta_speed_VIP = vip_delta_speed;
    obs_vip_info->obs_id_VIP = OBFU_Data_obstacles[((int32_T)rp_max_index) - 1].
      id;
    obs_vip_info->obs_type_VIP = OBFU_Data_obstacles[((int32_T)rp_max_index) - 1]
      .type;
    obs_vip_info->obs_v_lateral_VIP = OBFU_Data_obstacles[((int32_T)rp_max_index)
      - 1].velocity_rel.y;
    obs_vip_info->obs_v_long_VIP = OBFU_Data_obstacles[((int32_T)rp_max_index) -
      1].velocity_rel.x;
    obs_vip_info->obs_acc_lateral_VIP = OBFU_Data_obstacles[((int32_T)
      rp_max_index) - 1].acceleration_rel.y;
    obs_vip_info->obs_acc_long_VIP = OBFU_Data_obstacles[((int32_T)rp_max_index)
      - 1].acceleration_rel.x;
    obs_vip_info->obs_NP_x_VIP = OBFU_Data_obstacles[((int32_T)rp_max_index) - 1]
      .nearest_point_rel.x;
    obs_vip_info->obs_NP_y_VIP = OBFU_Data_obstacles[((int32_T)rp_max_index) - 1]
      .nearest_point_rel.y;
    obs_vip_info->obs_heading_VIP = OBFU_Data_obstacles[((int32_T)rp_max_index)
      - 1].heading_rel;
    obs_vip_info->obs_length_VIP = OBFU_Data_obstacles[((int32_T)rp_max_index) -
      1].length;
    obs_vip_info->obs_width_VIP = OBFU_Data_obstacles[((int32_T)rp_max_index) -
      1].width;
    obs_vip_info->obs_dis_long_VIP = vip_dis_long;
    obs_vip_info->obs_dis_lateral_VIP = vip_dis_lateral;
    obs_vip_info->obs_position_zone_VIP = OBFU_Data_obstacles[((int32_T)
      rp_max_index) - 1].position_zone;
    obs_vip_info->obs_motion_status_VIP = OBFU_Data_obstacles[((int32_T)
      rp_max_index) - 1].motion_status;
    obs_vip_info->obs_confidence_VIP = OBFU_Data_obstacles[((int32_T)
      rp_max_index) - 1].confidence;
  }
}

/* Function for MATLAB Function: '<S9>/AEB_Target_Selection' */
static void AEBS_subsyst_vip_selection_turn(boolean_T right_turn, real32_T
  veh_speed, real32_T adc_v_x, real32_T adc_v_y, real32_T veh_acceleration,
  real32_T veh_curvature, real32_T veh_width_update, const real32_T
  obs_long_buffer[120], const OBFU_Obstacle OBFU_Data_obstacles[128], uint16_T
  OBFU_Data_num_obstacles, const boolean_T *KbAEBS_FilterVehicleinSide_pjy4,
  const boolean_T *KbAEBS_Use_OBFU_Accelerati_jkde, const real32_T
  *KfAEBS_Pedstr_width_Thrsh_golk, real32_T *KfAEBS_GainTHW_lutf, real32_T
  *KfAEBS_GainTTC_b2qu, real32_T *KfAEBS_Veh_DisRear2OC_kfng,
  AEBS_Obs_VIP_info_Bus *obs_vip_info, uint8_T obs_position_state[32], real32_T
  obs_delta_dis[32], real32_T obs_delta_speed[32], real32_T obs_ttc[32],
  real32_T obs_dis2adc_long[32], real32_T obs_dis2adc_lateral[32], real32_T
  obs_v_long[32], real32_T obs_v_lateral[32], uint8_T obs_filtered_type[32])
{
  real32_T rp_max;
  uint8_T rp_max_index;
  real32_T vip_delta_dis;
  real32_T vip_delta_speed;
  real32_T vip_dis_long;
  real32_T vip_dis_lateral;
  real32_T veh_radius;
  uint8_T vip_position_state;
  real32_T vip_obs_ttc;
  real32_T obs_velocity_long;
  real32_T obs_velocity_lateral;
  real32_T this_obs_velocity_arc;
  real32_T this_obs_velocity_radius;
  real32_T this_obs_acc_arc;
  real32_T dis2adc_long;
  real32_T dis2adc_lateral;
  boolean_T is_inPath;
  boolean_T is_inInnerCircle;
  boolean_T is_inOuterCircle;
  real32_T obs_proj;
  boolean_T is_front_pz_zero;
  real32_T obs_acceleration_long;
  real32_T obs_acceleration_lateral;
  real32_T radius_inner_vehHead;
  real32_T radius_outer_vehHead;
  uint16_T i;
  int32_T i_0;
  uint16_T tmp;
  real32_T u0;
  real32_T radius_inner_vehHead_tmp;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  AEBS_subsyste_init_obs_vip_info(obs_vip_info);
  rp_max = 0.0F;
  rp_max_index = 0U;
  memset(&obs_delta_dis[0], 0, (sizeof(real32_T)) << 5U);
  memset(&obs_delta_speed[0], 0, (sizeof(real32_T)) << 5U);
  memset(&obs_ttc[0], 0, (sizeof(real32_T)) << 5U);
  memset(&obs_dis2adc_long[0], 0, (sizeof(real32_T)) << 5U);
  memset(&obs_dis2adc_lateral[0], 0, (sizeof(real32_T)) << 5U);
  memset(&obs_v_long[0], 0, (sizeof(real32_T)) << 5U);
  memset(&obs_v_lateral[0], 0, (sizeof(real32_T)) << 5U);
  for (i_0 = 0; i_0 < 32; i_0++)
  {
    obs_position_state[i_0] = 0U;
    obs_filtered_type[i_0] = 0U;
  }

  vip_delta_dis = 0.0F;
  vip_delta_speed = 0.0F;
  vip_dis_long = 0.0F;
  vip_dis_lateral = 0.0F;
  veh_radius = (real32_T)fabs((real_T)veh_curvature);
  if (((real_T)veh_radius) > 0.001)
  {
  }
  else
  {
    veh_radius = 0.001F;
  }

  veh_radius = 1.0F / veh_radius;
  vip_position_state = 0U;
  vip_obs_ttc = 0.0F;
  for (i = 1U; i <= OBFU_Data_num_obstacles; i = (uint16_T)(((uint32_T)i) + 1U))
  {
    i_0 = ((int32_T)i) - 1;
    if (OBFU_Data_obstacles[i_0].id < 1)
    {
    }
    else
    {
      obs_velocity_long = adc_v_x + OBFU_Data_obstacles[((int32_T)i) - 1].
        velocity_rel.x;
      obs_velocity_lateral = adc_v_y + OBFU_Data_obstacles[((int32_T)i) - 1].
        velocity_rel.y;
      this_obs_velocity_arc = 0.0F;
      this_obs_velocity_radius = 0.0F;
      this_obs_acc_arc = 0.0F;
      dis2adc_long = 0.0F;
      dis2adc_lateral = 0.0F;
      is_inPath = false;
      is_inInnerCircle = false;
      is_inOuterCircle = false;
      obs_proj = 0.0F;
      is_front_pz_zero = false;
      if (((OBFU_Data_obstacles[((int32_T)i) - 1].position_zone == 6) ||
           (OBFU_Data_obstacles[((int32_T)i) - 1].position_zone == 7)) ||
          (OBFU_Data_obstacles[((int32_T)i) - 1].position_zone == 8))
      {
        if (((int32_T)i) < 33)
        {
          obs_filtered_type[i_0] = 2U;
        }
      }
      else if (OBFU_Data_obstacles[((int32_T)i) - 1].nearest_point_rel.x <
               AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms)
      {
        if (((int32_T)i) < 33)
        {
          obs_filtered_type[i_0] = 4U;
        }
      }
      else
      {
        if (*KbAEBS_Use_OBFU_Accelerati_jkde)
        {
          if ((((OBFU_Data_obstacles[((int32_T)i) - 1].type == 3) ||
                (OBFU_Data_obstacles[((int32_T)i) - 1].type == 4)) ||
               (OBFU_Data_obstacles[((int32_T)i) - 1].type == 5)) ||
              (OBFU_Data_obstacles[((int32_T)i) - 1].type == 6))
          {
            obs_acceleration_long = veh_acceleration + OBFU_Data_obstacles
              [((int32_T)i) - 1].acceleration_rel.x;
            obs_acceleration_lateral = OBFU_Data_obstacles[((int32_T)i) - 1].
              acceleration_rel.y;
          }
          else
          {
            obs_acceleration_long = 0.0F;
            obs_acceleration_lateral = 0.0F;
          }
        }
        else
        {
          obs_acceleration_long = 0.0F;
          obs_acceleration_lateral = 0.0F;
        }

        radius_inner_vehHead_tmp = (*KfAEBS_Veh_DisRear2OC_kfng) +
          AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms;
        radius_outer_vehHead = veh_radius - (0.5F * veh_width_update);
        radius_inner_vehHead = (real32_T)sqrt((real_T)((real32_T)
          ((radius_inner_vehHead_tmp * radius_inner_vehHead_tmp) +
           (radius_outer_vehHead * radius_outer_vehHead))));
        radius_outer_vehHead = veh_radius + (0.5F * veh_width_update);
        radius_outer_vehHead = (real32_T)sqrt((real_T)((real32_T)
          ((radius_inner_vehHead_tmp * radius_inner_vehHead_tmp) +
           (radius_outer_vehHead * radius_outer_vehHead))));
        guard1 = false;
        guard2 = false;
        guard3 = false;
        guard4 = false;
        guard5 = false;
        guard6 = false;
        if (OBFU_Data_obstacles[((int32_T)i) - 1].position_zone == 0)
        {
          if (OBFU_Data_obstacles[((int32_T)i) - 1].nearest_point_rel.x <
              AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms)
          {
            if (((int32_T)i) < 33)
            {
              obs_filtered_type[i_0] = 4U;
            }
          }
          else
          {
            is_front_pz_zero = true;
            guard6 = true;
          }
        }
        else
        {
          guard6 = true;
        }

        if (guard6)
        {
          if ((((OBFU_Data_obstacles[((int32_T)i) - 1].position_zone == 1) ||
                (OBFU_Data_obstacles[((int32_T)i) - 1].position_zone == 2)) ||
               (OBFU_Data_obstacles[((int32_T)i) - 1].position_zone == 3)) ||
              is_front_pz_zero)
          {
            if (right_turn)
            {
              if (((real32_T)fabs((real_T)OBFU_Data_obstacles[((int32_T)i) - 1].
                                  nearest_point_rel.y)) <= veh_radius)
              {
                this_obs_acc_arc = (real32_T)atan2((real_T)((real32_T)
                  (OBFU_Data_obstacles[((int32_T)i) - 1].nearest_point_rel.x + (*
                  KfAEBS_Veh_DisRear2OC_kfng))), (real_T)((real32_T)(veh_radius
                  + OBFU_Data_obstacles[((int32_T)i) - 1].nearest_point_rel.y)));
              }
              else
              {
                this_obs_acc_arc = 3.14159274F + ((real32_T)atan2((real_T)
                  ((real32_T)(OBFU_Data_obstacles[((int32_T)i) - 1].
                              nearest_point_rel.x + (*KfAEBS_Veh_DisRear2OC_kfng))),
                  (real_T)((real32_T)(veh_radius + OBFU_Data_obstacles[((int32_T)
                  i) - 1].nearest_point_rel.y))));
              }
            }
            else if (((real32_T)fabs((real_T)OBFU_Data_obstacles[((int32_T)i) -
                       1].nearest_point_rel.y)) <= veh_radius)
            {
              this_obs_acc_arc = (real32_T)atan2((real_T)((real32_T)
                (OBFU_Data_obstacles[((int32_T)i) - 1].nearest_point_rel.x +
                 (*KfAEBS_Veh_DisRear2OC_kfng))), (real_T)((real32_T)(veh_radius
                - OBFU_Data_obstacles[((int32_T)i) - 1].nearest_point_rel.y)));
            }
            else
            {
              this_obs_acc_arc = 3.14159274F + ((real32_T)atan2((real_T)
                ((real32_T)(OBFU_Data_obstacles[((int32_T)i) - 1].
                            nearest_point_rel.x + (*KfAEBS_Veh_DisRear2OC_kfng))),
                (real_T)((real32_T)(veh_radius - OBFU_Data_obstacles[((int32_T)i)
                                    - 1].nearest_point_rel.y))));
            }

            radius_inner_vehHead_tmp = (real32_T)sin((real_T)this_obs_acc_arc);
            this_obs_velocity_radius = (OBFU_Data_obstacles[((int32_T)i) - 1].
              nearest_point_rel.x + (*KfAEBS_Veh_DisRear2OC_kfng)) /
              radius_inner_vehHead_tmp;
            if ((this_obs_velocity_radius >= radius_inner_vehHead) &&
                (this_obs_velocity_radius <= radius_outer_vehHead))
            {
              is_inPath = true;
              dis2adc_long = ((veh_radius * this_obs_acc_arc) -
                              AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms)
                - (*KfAEBS_Veh_DisRear2OC_kfng);
            }

            u0 = OBFU_Data_obstacles[((int32_T)i) - 1].width;
            this_obs_velocity_arc = OBFU_Data_obstacles[((int32_T)i) - 1].length;
            if (u0 < this_obs_velocity_arc)
            {
              this_obs_velocity_arc = u0;
            }

            if (this_obs_velocity_radius < radius_inner_vehHead)
            {
              dis2adc_long = (this_obs_velocity_radius + (0.5F *
                this_obs_velocity_arc)) + (*KfAEBS_Pedstr_width_Thrsh_golk);
              if (dis2adc_long > radius_inner_vehHead)
              {
                is_inPath = true;
                dis2adc_long = ((veh_radius * this_obs_acc_arc) -
                                AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms)
                  - (*KfAEBS_Veh_DisRear2OC_kfng);
              }
              else
              {
                is_inInnerCircle = true;
                dis2adc_lateral = radius_inner_vehHead - dis2adc_long;
                dis2adc_long = ((veh_radius * this_obs_acc_arc) -
                                AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms)
                  - (*KfAEBS_Veh_DisRear2OC_kfng);
                obs_proj = this_obs_velocity_arc +
                  (*KfAEBS_Pedstr_width_Thrsh_golk);
              }
            }

            if (this_obs_velocity_radius > radius_outer_vehHead)
            {
              dis2adc_long = (this_obs_velocity_radius - (0.5F *
                this_obs_velocity_arc)) - (*KfAEBS_Pedstr_width_Thrsh_golk);
              if (dis2adc_long < radius_outer_vehHead)
              {
                is_inPath = true;
                dis2adc_lateral = 0.0F;
                dis2adc_long = ((veh_radius * this_obs_acc_arc) -
                                AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms)
                  - (*KfAEBS_Veh_DisRear2OC_kfng);
              }
              else
              {
                is_inOuterCircle = true;
                dis2adc_lateral = dis2adc_long - radius_outer_vehHead;
                dis2adc_long = ((veh_radius * this_obs_acc_arc) -
                                AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms)
                  - (*KfAEBS_Veh_DisRear2OC_kfng);
                obs_proj = this_obs_velocity_arc +
                  (*KfAEBS_Pedstr_width_Thrsh_golk);
              }
            }

            if (right_turn)
            {
              this_obs_velocity_radius = ((-obs_velocity_lateral) * ((real32_T)
                cos((real_T)this_obs_acc_arc))) - (obs_velocity_long
                * ((real32_T)sin((real_T)this_obs_acc_arc)));
              this_obs_velocity_arc = ((-obs_velocity_lateral) *
                radius_inner_vehHead_tmp) + (obs_velocity_long * ((real32_T)cos
                ((real_T)this_obs_acc_arc)));
              this_obs_acc_arc = ((-obs_acceleration_lateral) *
                                  radius_inner_vehHead_tmp) +
                (obs_acceleration_long * ((real32_T)cos((real_T)this_obs_acc_arc)));
            }
            else
            {
              this_obs_acc_arc = (real32_T)cos((real_T)this_obs_acc_arc);
              this_obs_velocity_radius = (obs_velocity_lateral *
                this_obs_acc_arc) - (obs_velocity_long
                * radius_inner_vehHead_tmp);
              this_obs_velocity_arc = (obs_velocity_lateral *
                radius_inner_vehHead_tmp) + (obs_velocity_long
                * this_obs_acc_arc);
              this_obs_acc_arc = (obs_acceleration_lateral *
                                  radius_inner_vehHead_tmp) +
                (obs_acceleration_long * this_obs_acc_arc);
            }
          }

          if (OBFU_Data_obstacles[((int32_T)i) - 1].position_zone == 4)
          {
            if (OBFU_Data_obstacles[((int32_T)i) - 1].nearest_point_rel.x <
                AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms)
            {
              if (((int32_T)i) < 33)
              {
                obs_filtered_type[i_0] = 4U;
              }
            }
            else
            {
              if (right_turn)
              {
                is_inInnerCircle = true;
                if (((real32_T)fabs((real_T)OBFU_Data_obstacles[((int32_T)i) - 1]
                                    .nearest_point_rel.y)) <= veh_radius)
                {
                  this_obs_acc_arc = (real32_T)atan2((real_T)((real32_T)
                    (OBFU_Data_obstacles[((int32_T)i) - 1].nearest_point_rel.x +
                     (*KfAEBS_Veh_DisRear2OC_kfng))), (real_T)((real32_T)
                    (veh_radius + OBFU_Data_obstacles[((int32_T)i) - 1].
                     nearest_point_rel.y)));
                }
                else
                {
                  this_obs_acc_arc = 3.14159274F + ((real32_T)atan2((real_T)
                    ((real32_T)(OBFU_Data_obstacles[((int32_T)i) - 1].
                                nearest_point_rel.x +
                                (*KfAEBS_Veh_DisRear2OC_kfng))), (real_T)
                    ((real32_T)(veh_radius + OBFU_Data_obstacles[((int32_T)i) -
                                1].nearest_point_rel.y))));
                }
              }
              else
              {
                is_inOuterCircle = true;
                if (((real32_T)fabs((real_T)OBFU_Data_obstacles[((int32_T)i) - 1]
                                    .nearest_point_rel.y)) <= veh_radius)
                {
                  this_obs_acc_arc = (real32_T)atan2((real_T)((real32_T)
                    (OBFU_Data_obstacles[((int32_T)i) - 1].nearest_point_rel.x +
                     (*KfAEBS_Veh_DisRear2OC_kfng))), (real_T)((real32_T)
                    (veh_radius - OBFU_Data_obstacles[((int32_T)i) - 1].
                     nearest_point_rel.y)));
                }
                else
                {
                  this_obs_acc_arc = 3.14159274F + ((real32_T)atan2((real_T)
                    ((real32_T)(OBFU_Data_obstacles[((int32_T)i) - 1].
                                nearest_point_rel.x +
                                (*KfAEBS_Veh_DisRear2OC_kfng))), (real_T)
                    ((real32_T)(veh_radius - OBFU_Data_obstacles[((int32_T)i) -
                                1].nearest_point_rel.y))));
                }
              }

              radius_inner_vehHead_tmp = (real32_T)sin((real_T)this_obs_acc_arc);
              this_obs_velocity_radius = (OBFU_Data_obstacles[((int32_T)i) - 1].
                nearest_point_rel.x + (*KfAEBS_Veh_DisRear2OC_kfng)) /
                radius_inner_vehHead_tmp;
              if (right_turn)
              {
                if ((((((real_T)OBFU_Data_obstacles[((int32_T)i) - 1].
                        heading_rel) > -0.78539816339744828) && (((real_T)
                        OBFU_Data_obstacles[((int32_T)i) - 1].heading_rel) <
                       0.78539816339744828)) || ((((real_T)OBFU_Data_obstacles
                        [((int32_T)i) - 1].heading_rel) > 2.3561944901923448) &&
                      (((real_T)OBFU_Data_obstacles[((int32_T)i) - 1].
                        heading_rel) <= 3.1415926535897931))) || ((((real_T)
                       OBFU_Data_obstacles[((int32_T)i) - 1].heading_rel) >=
                      -3.1415926535897931) && (((real_T)OBFU_Data_obstacles
                       [((int32_T)i) - 1].heading_rel) <= -2.3561944901923448)))
                {
                  obs_proj = OBFU_Data_obstacles[((int32_T)i) - 1].width +
                    (*KfAEBS_Pedstr_width_Thrsh_golk);
                  dis2adc_lateral = (radius_inner_vehHead -
                                     this_obs_velocity_radius) -
                    (*KfAEBS_Pedstr_width_Thrsh_golk);
                  dis2adc_long = (((veh_radius * this_obs_acc_arc) -
                                   OBFU_Data_obstacles[((int32_T)i) - 1].length)
                                  - obs_long_buffer[((int32_T)i) - 1]) -
                    AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms;
                }
                else
                {
                  obs_proj = OBFU_Data_obstacles[((int32_T)i) - 1].length +
                    (*KfAEBS_Pedstr_width_Thrsh_golk);
                  dis2adc_lateral = (radius_inner_vehHead -
                                     (*KfAEBS_Pedstr_width_Thrsh_golk)) -
                    this_obs_velocity_radius;
                  dis2adc_long = (((veh_radius * this_obs_acc_arc) -
                                   OBFU_Data_obstacles[((int32_T)i) - 1].width)
                                  - obs_long_buffer[((int32_T)i) - 1]) -
                    AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms;
                }
              }
              else if ((((((real_T)OBFU_Data_obstacles[((int32_T)i) - 1].
                           heading_rel) > -0.78539816339744828) && (((real_T)
                           OBFU_Data_obstacles[((int32_T)i) - 1].heading_rel) <
                          0.78539816339744828)) || ((((real_T)
                           OBFU_Data_obstacles[((int32_T)i) - 1].heading_rel) >
                          2.3561944901923448) && (((real_T)OBFU_Data_obstacles
                           [((int32_T)i) - 1].heading_rel) <= 3.1415926535897931)))
                       || ((((real_T)OBFU_Data_obstacles[((int32_T)i) - 1].
                             heading_rel) >= -3.1415926535897931) && (((real_T)
                          OBFU_Data_obstacles[((int32_T)i) - 1].heading_rel) <=
                         -2.3561944901923448)))
              {
                obs_proj = OBFU_Data_obstacles[((int32_T)i) - 1].width +
                  (*KfAEBS_Pedstr_width_Thrsh_golk);
                dis2adc_lateral = (this_obs_velocity_radius -
                                   radius_outer_vehHead) -
                  (*KfAEBS_Pedstr_width_Thrsh_golk);
                dis2adc_long = (((veh_radius * this_obs_acc_arc) -
                                 OBFU_Data_obstacles[((int32_T)i) - 1].length) -
                                obs_long_buffer[((int32_T)i) - 1]) -
                  AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms;
              }
              else
              {
                obs_proj = OBFU_Data_obstacles[((int32_T)i) - 1].length +
                  (*KfAEBS_Pedstr_width_Thrsh_golk);
                dis2adc_lateral = (this_obs_velocity_radius -
                                   radius_outer_vehHead) -
                  (*KfAEBS_Pedstr_width_Thrsh_golk);
                dis2adc_long = (((veh_radius * this_obs_acc_arc) -
                                 OBFU_Data_obstacles[((int32_T)i) - 1].width) -
                                obs_long_buffer[i_0]) -
                  AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms;
              }

              if (dis2adc_long <
                  AEBS_subsystem_integrated_DW.KfAEBS_d_Dis2HeadIgnoreSid_clhs)
              {
                if (((int32_T)i) < 33)
                {
                  obs_filtered_type[i_0] = 5U;
                }
              }
              else
              {
                if (right_turn)
                {
                  this_obs_velocity_radius = ((-obs_velocity_lateral) *
                    ((real32_T)cos((real_T)this_obs_acc_arc))) -
                    (obs_velocity_long * ((real32_T)sin((real_T)this_obs_acc_arc)));
                  this_obs_velocity_arc = ((-obs_velocity_lateral) *
                    radius_inner_vehHead_tmp) + (obs_velocity_long * ((real32_T)
                    cos((real_T)this_obs_acc_arc)));
                  this_obs_acc_arc = ((-obs_acceleration_lateral) *
                                      radius_inner_vehHead_tmp) +
                    (obs_acceleration_long * ((real32_T)cos((real_T)
                       this_obs_acc_arc)));
                }
                else
                {
                  this_obs_acc_arc = (real32_T)cos((real_T)this_obs_acc_arc);
                  this_obs_velocity_radius = (obs_velocity_lateral *
                    this_obs_acc_arc) - (obs_velocity_long
                    * radius_inner_vehHead_tmp);
                  this_obs_velocity_arc = (obs_velocity_lateral *
                    radius_inner_vehHead_tmp) + (obs_velocity_long
                    * this_obs_acc_arc);
                  this_obs_acc_arc = (obs_acceleration_lateral *
                                      radius_inner_vehHead_tmp) +
                    (obs_acceleration_long * this_obs_acc_arc);
                }

                guard5 = true;
              }
            }
          }
          else
          {
            guard5 = true;
          }
        }

        if (guard5)
        {
          if (OBFU_Data_obstacles[((int32_T)i) - 1].position_zone == 5)
          {
            if (OBFU_Data_obstacles[((int32_T)i) - 1].nearest_point_rel.x <
                AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms)
            {
              if (((int32_T)i) < 33)
              {
                obs_filtered_type[i_0] = 4U;
              }
            }
            else
            {
              if (right_turn)
              {
                is_inOuterCircle = true;
                if (((real32_T)fabs((real_T)OBFU_Data_obstacles[((int32_T)i) - 1]
                                    .nearest_point_rel.y)) <= veh_radius)
                {
                  this_obs_acc_arc = (real32_T)atan2((real_T)((real32_T)
                    (OBFU_Data_obstacles[((int32_T)i) - 1].nearest_point_rel.x +
                     (*KfAEBS_Veh_DisRear2OC_kfng))), (real_T)((real32_T)
                    (veh_radius + OBFU_Data_obstacles[((int32_T)i) - 1].
                     nearest_point_rel.y)));
                }
                else
                {
                  this_obs_acc_arc = 3.14159274F + ((real32_T)atan2((real_T)
                    ((real32_T)(OBFU_Data_obstacles[((int32_T)i) - 1].
                                nearest_point_rel.x +
                                (*KfAEBS_Veh_DisRear2OC_kfng))), (real_T)
                    ((real32_T)(veh_radius + OBFU_Data_obstacles[((int32_T)i) -
                                1].nearest_point_rel.y))));
                }
              }
              else
              {
                is_inInnerCircle = true;
                if (((real32_T)fabs((real_T)OBFU_Data_obstacles[((int32_T)i) - 1]
                                    .nearest_point_rel.y)) <= veh_radius)
                {
                  this_obs_acc_arc = (real32_T)atan2((real_T)((real32_T)
                    (OBFU_Data_obstacles[((int32_T)i) - 1].nearest_point_rel.x +
                     (*KfAEBS_Veh_DisRear2OC_kfng))), (real_T)((real32_T)
                    (veh_radius - OBFU_Data_obstacles[((int32_T)i) - 1].
                     nearest_point_rel.y)));
                }
                else
                {
                  this_obs_acc_arc = 3.14159274F + ((real32_T)atan2((real_T)
                    ((real32_T)(OBFU_Data_obstacles[((int32_T)i) - 1].
                                nearest_point_rel.x +
                                (*KfAEBS_Veh_DisRear2OC_kfng))), (real_T)
                    ((real32_T)(veh_radius - OBFU_Data_obstacles[((int32_T)i) -
                                1].nearest_point_rel.y))));
                }
              }

              radius_inner_vehHead_tmp = (real32_T)sin((real_T)this_obs_acc_arc);
              this_obs_velocity_radius = (OBFU_Data_obstacles[((int32_T)i) - 1].
                nearest_point_rel.x + (*KfAEBS_Veh_DisRear2OC_kfng)) /
                radius_inner_vehHead_tmp;
              if (right_turn)
              {
                if ((((((real_T)OBFU_Data_obstacles[((int32_T)i) - 1].
                        heading_rel) > -0.78539816339744828) && (((real_T)
                        OBFU_Data_obstacles[((int32_T)i) - 1].heading_rel) <
                       0.78539816339744828)) || ((((real_T)OBFU_Data_obstacles
                        [((int32_T)i) - 1].heading_rel) > 2.3561944901923448) &&
                      (((real_T)OBFU_Data_obstacles[((int32_T)i) - 1].
                        heading_rel) <= 3.1415926535897931))) || ((((real_T)
                       OBFU_Data_obstacles[((int32_T)i) - 1].heading_rel) >=
                      -3.1415926535897931) && (((real_T)OBFU_Data_obstacles
                       [((int32_T)i) - 1].heading_rel) <= -2.3561944901923448)))
                {
                  obs_proj = OBFU_Data_obstacles[((int32_T)i) - 1].width +
                    (*KfAEBS_Pedstr_width_Thrsh_golk);
                  dis2adc_lateral = (this_obs_velocity_radius -
                                     radius_outer_vehHead) -
                    (*KfAEBS_Pedstr_width_Thrsh_golk);
                  dis2adc_long = (((veh_radius * this_obs_acc_arc) -
                                   OBFU_Data_obstacles[((int32_T)i) - 1].length)
                                  - obs_long_buffer[((int32_T)i) - 1]) -
                    AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms;
                }
                else
                {
                  obs_proj = OBFU_Data_obstacles[((int32_T)i) - 1].length +
                    (*KfAEBS_Pedstr_width_Thrsh_golk);
                  dis2adc_lateral = (this_obs_velocity_radius -
                                     radius_outer_vehHead) -
                    (*KfAEBS_Pedstr_width_Thrsh_golk);
                  dis2adc_long = (((veh_radius * this_obs_acc_arc) -
                                   OBFU_Data_obstacles[((int32_T)i) - 1].width)
                                  - obs_long_buffer[((int32_T)i) - 1]) -
                    AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms;
                }
              }
              else if ((((((real_T)OBFU_Data_obstacles[((int32_T)i) - 1].
                           heading_rel) > -0.78539816339744828) && (((real_T)
                           OBFU_Data_obstacles[((int32_T)i) - 1].heading_rel) <
                          0.78539816339744828)) || ((((real_T)
                           OBFU_Data_obstacles[((int32_T)i) - 1].heading_rel) >
                          2.3561944901923448) && (((real_T)OBFU_Data_obstacles
                           [((int32_T)i) - 1].heading_rel) <= 3.1415926535897931)))
                       || ((((real_T)OBFU_Data_obstacles[((int32_T)i) - 1].
                             heading_rel) >= -3.1415926535897931) && (((real_T)
                          OBFU_Data_obstacles[((int32_T)i) - 1].heading_rel) <=
                         -2.3561944901923448)))
              {
                obs_proj = OBFU_Data_obstacles[((int32_T)i) - 1].width +
                  (*KfAEBS_Pedstr_width_Thrsh_golk);
                dis2adc_lateral = (radius_inner_vehHead -
                                   this_obs_velocity_radius) -
                  (*KfAEBS_Pedstr_width_Thrsh_golk);
                dis2adc_long = (((veh_radius * this_obs_acc_arc) -
                                 OBFU_Data_obstacles[((int32_T)i) - 1].length) -
                                obs_long_buffer[((int32_T)i) - 1]) -
                  AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms;
              }
              else
              {
                obs_proj = OBFU_Data_obstacles[((int32_T)i) - 1].length +
                  (*KfAEBS_Pedstr_width_Thrsh_golk);
                dis2adc_lateral = (radius_inner_vehHead -
                                   (*KfAEBS_Pedstr_width_Thrsh_golk)) -
                  this_obs_velocity_radius;
                dis2adc_long = (((veh_radius * this_obs_acc_arc) -
                                 OBFU_Data_obstacles[((int32_T)i) - 1].width) -
                                obs_long_buffer[((int32_T)i) - 1]) -
                  AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms;
              }

              if (dis2adc_long <
                  AEBS_subsystem_integrated_DW.KfAEBS_d_Dis2HeadIgnoreSid_clhs)
              {
                if (((int32_T)i) < 33)
                {
                  obs_filtered_type[i_0] = 5U;
                }
              }
              else
              {
                if (right_turn)
                {
                  this_obs_velocity_radius = ((-obs_velocity_lateral) *
                    ((real32_T)cos((real_T)this_obs_acc_arc))) -
                    (obs_velocity_long * ((real32_T)sin((real_T)this_obs_acc_arc)));
                  this_obs_velocity_arc = ((-obs_velocity_lateral) *
                    radius_inner_vehHead_tmp) + (obs_velocity_long * ((real32_T)
                    cos((real_T)this_obs_acc_arc)));
                  this_obs_acc_arc = ((-obs_acceleration_lateral) *
                                      radius_inner_vehHead_tmp) +
                    (obs_acceleration_long * ((real32_T)cos((real_T)
                       this_obs_acc_arc)));
                }
                else
                {
                  this_obs_acc_arc = (real32_T)cos((real_T)this_obs_acc_arc);
                  this_obs_velocity_radius = (obs_velocity_lateral *
                    this_obs_acc_arc) - (obs_velocity_long
                    * radius_inner_vehHead_tmp);
                  this_obs_velocity_arc = (obs_velocity_lateral *
                    radius_inner_vehHead_tmp) + (obs_velocity_long
                    * this_obs_acc_arc);
                  this_obs_acc_arc = (obs_acceleration_lateral *
                                      radius_inner_vehHead_tmp) +
                    (obs_acceleration_long * this_obs_acc_arc);
                }

                guard4 = true;
              }
            }
          }
          else
          {
            guard4 = true;
          }
        }

        if (guard4)
        {
          if (((int32_T)i) < 33)
          {
            obs_dis2adc_long[i_0] = dis2adc_long;
            obs_dis2adc_lateral[i_0] = dis2adc_lateral;
            obs_v_long[i_0] = this_obs_velocity_arc;
            obs_v_lateral[i_0] = this_obs_velocity_radius;
          }

          if (this_obs_velocity_arc >
              AEBS_subsystem_integrated_DW.KfAEBS_v_obsSpeedArcMin_bsty)
          {
          }
          else
          {
            this_obs_velocity_arc =
              AEBS_subsystem_integrated_DW.KfAEBS_v_obsSpeedArcMin_bsty;
          }

          if (is_inInnerCircle)
          {
            if (OBFU_Data_obstacles[((int32_T)i) - 1].motion_status == 2)
            {
              if (((int32_T)i) < 33)
              {
                obs_filtered_type[i_0] = 16U;
              }
            }
            else if (this_obs_velocity_radius > 0.0F)
            {
              if (((int32_T)i) < 33)
              {
                obs_filtered_type[i_0] = 17U;
              }
            }
            else if (this_obs_velocity_arc > veh_speed)
            {
              if (((int32_T)i) < 33)
              {
                obs_filtered_type[i_0] = 18U;
              }
            }
            else if ((*KbAEBS_FilterVehicleinSide_pjy4) &&
                     (((OBFU_Data_obstacles[((int32_T)i) - 1].type == 4) ||
                       (OBFU_Data_obstacles[((int32_T)i) - 1].type == 5)) ||
                      (OBFU_Data_obstacles[((int32_T)i) - 1].type == 6)))
            {
              if (((int32_T)i) < 33)
              {
                obs_filtered_type[i_0] = 19U;
              }
            }
            else
            {
              guard3 = true;
            }
          }
          else
          {
            guard3 = true;
          }
        }

        if (guard3)
        {
          if (is_inOuterCircle)
          {
            if (OBFU_Data_obstacles[((int32_T)i) - 1].motion_status == 2)
            {
              if (((int32_T)i) < 33)
              {
                obs_filtered_type[i_0] = 20U;
              }
            }
            else if (this_obs_velocity_radius < 0.0F)
            {
              if (((int32_T)i) < 33)
              {
                obs_filtered_type[i_0] = 21U;
              }
            }
            else if (this_obs_velocity_arc > veh_speed)
            {
              if (((int32_T)i) < 33)
              {
                obs_filtered_type[i_0] = 22U;
              }
            }
            else if ((*KbAEBS_FilterVehicleinSide_pjy4) &&
                     (((OBFU_Data_obstacles[((int32_T)i) - 1].type == 4) ||
                       (OBFU_Data_obstacles[((int32_T)i) - 1].type == 5)) ||
                      (OBFU_Data_obstacles[((int32_T)i) - 1].type == 6)))
            {
              if (((int32_T)i) < 33)
              {
                obs_filtered_type[i_0] = 23U;
              }
            }
            else
            {
              guard2 = true;
            }
          }
          else
          {
            guard2 = true;
          }
        }

        if (guard2)
        {
          obs_velocity_long = veh_speed - this_obs_velocity_arc;
          if ((((real_T)obs_velocity_long) < 0.01) && (obs_velocity_long >=
               (-AEBS_subsystem_integrated_DW.KfAEBS_v_Speed_DeltaWExit_gqet)))
          {
            obs_velocity_long = 0.01F;
          }

          if (obs_velocity_long <
              (-AEBS_subsystem_integrated_DW.KfAEBS_v_Speed_DeltaWExit_gqet))
          {
            if (((int32_T)i) < 33)
            {
              obs_filtered_type[i_0] = 24U;
            }
          }
          else
          {
            if (((real_T)dis2adc_long) > 0.01)
            {
              obs_acceleration_long = dis2adc_long;
            }
            else
            {
              obs_acceleration_long = 0.01F;
            }

            obs_acceleration_long = (((*KfAEBS_GainTTC_b2qu) * obs_velocity_long)
              + ((*KfAEBS_GainTHW_lutf) * veh_speed)) / obs_acceleration_long;
            obs_acceleration_lateral = ttc_calculation_aebs_an7L2XSm
              (dis2adc_long, obs_velocity_long, veh_acceleration -
               this_obs_acc_arc);
            if (is_inPath)
            {
              u0 = veh_speed *
                AEBS_subsystem_integrated_DW.KfAEBS_t_timeGap_ignore_tu_nfky;
              if (u0 > AEBS_subsystem_integrated_DW.KfAEBS_d_min_dis_swap_ivsz)
              {
              }
              else
              {
                u0 = AEBS_subsystem_integrated_DW.KfAEBS_d_min_dis_swap_ivsz;
              }

              if (dis2adc_long > u0)
              {
                if (((int32_T)i) < 33)
                {
                  obs_filtered_type[i_0] = 25U;
                }
              }
              else
              {
                if (((int32_T)rp_max_index) == 0)
                {
                  rp_max = obs_acceleration_long;
                  tmp = i;
                  if (((int32_T)i) > 255)
                  {
                    tmp = 255U;
                  }

                  rp_max_index = (uint8_T)tmp;
                  vip_delta_dis = dis2adc_long;
                  vip_delta_speed = obs_velocity_long;
                  vip_dis_long = dis2adc_long;
                  vip_dis_lateral = dis2adc_lateral;
                  vip_obs_ttc = obs_acceleration_lateral;
                  if (right_turn)
                  {
                    vip_position_state = 3U;
                  }
                  else
                  {
                    vip_position_state = 7U;
                  }
                }

                if (((int32_T)i) < 33)
                {
                  if (right_turn)
                  {
                    obs_position_state[i_0] = 3U;
                  }
                  else
                  {
                    obs_position_state[i_0] = 7U;
                  }

                  obs_delta_dis[i_0] = dis2adc_long;
                  obs_delta_speed[i_0] = obs_velocity_long;
                  obs_ttc[i_0] = obs_acceleration_lateral;
                }

                guard1 = true;
              }
            }
            else
            {
              this_obs_velocity_radius = (real32_T)fabs((real_T)
                this_obs_velocity_radius);
              if (((real_T)this_obs_velocity_radius) > 0.01)
              {
              }
              else
              {
                this_obs_velocity_radius = 0.01F;
              }

              this_obs_velocity_radius = ((real32_T)fabs((real_T)dis2adc_lateral))
                / this_obs_velocity_radius;
              if (this_obs_velocity_radius >= obs_acceleration_lateral)
              {
                if (((real_T)veh_speed) > 0.01)
                {
                  obs_velocity_lateral = veh_speed;
                }
                else
                {
                  obs_velocity_lateral = 0.01F;
                }

                is_inPath = ((this_obs_velocity_radius -
                              obs_acceleration_lateral) <
                             ((AEBS_subsystem_integrated_DW.KfAEBS_d_Dis_BufferTTSP_le_ahgr
                               + AEBS_subsystem_integrated_DW.KfAEBS_d_Dis_BufferTTSP_fvf0)
                              / obs_velocity_lateral));
              }
              else
              {
                obs_velocity_lateral = (real32_T)fabs((real_T)
                  obs_velocity_lateral);
                if (((real_T)obs_velocity_lateral) > 0.01)
                {
                }
                else
                {
                  obs_velocity_lateral = 0.01F;
                }

                is_inPath = ((obs_acceleration_lateral -
                              this_obs_velocity_radius) <
                             (((AEBS_subsystem_integrated_DW.KfAEBS_Veh_Width_b12o
                                + AEBS_subsystem_integrated_DW.KfAEBS_d_Dis_BufferTTSP_fvf0)
                               + obs_proj) / obs_velocity_lateral));
              }

              if (!is_inPath)
              {
                if (((int32_T)i) < 33)
                {
                  obs_filtered_type[i_0] = 26U;
                }
              }
              else
              {
                if (((int32_T)rp_max_index) == 0)
                {
                  rp_max = obs_acceleration_long;
                  tmp = i;
                  if (((int32_T)i) > 255)
                  {
                    tmp = 255U;
                  }

                  rp_max_index = (uint8_T)tmp;
                  vip_delta_dis = dis2adc_long;
                  vip_delta_speed = obs_velocity_long;
                  vip_dis_long = dis2adc_long;
                  vip_dis_lateral = dis2adc_lateral;
                  vip_obs_ttc = obs_acceleration_lateral;
                  vip_position_state = 6U;
                }
                else
                {
                  if (obs_acceleration_long > rp_max)
                  {
                    rp_max = obs_acceleration_long;
                    tmp = i;
                    if (((int32_T)i) > 255)
                    {
                      tmp = 255U;
                    }

                    rp_max_index = (uint8_T)tmp;
                    vip_delta_dis = dis2adc_long;
                    vip_delta_speed = obs_velocity_long;
                    vip_dis_long = dis2adc_long;
                    vip_dis_lateral = dis2adc_lateral;
                    vip_obs_ttc = obs_acceleration_lateral;
                    vip_position_state = 6U;
                  }
                }

                guard1 = true;
              }
            }
          }
        }

        if (guard1)
        {
          if (((int32_T)rp_max_index) > 0)
          {
            obs_vip_info->has_obs_VIP = true;
            obs_vip_info->obs_index_VIP = rp_max_index;
            obs_vip_info->obs_rp_VIP = rp_max;
            obs_vip_info->obs_position_state_VIP = vip_position_state;
            obs_vip_info->obs_ttc_VIP = vip_obs_ttc;
            obs_vip_info->obs_dis_long_VIP = vip_dis_long;
            obs_vip_info->obs_dis_lateral_VIP = vip_dis_lateral;
            obs_vip_info->obs_delta_dis_VIP = vip_delta_dis;
            obs_vip_info->obs_delta_speed_VIP = vip_delta_speed;
            obs_vip_info->obs_id_VIP = OBFU_Data_obstacles[((int32_T)
              rp_max_index) - 1].id;
            obs_vip_info->obs_type_VIP = OBFU_Data_obstacles[((int32_T)
              rp_max_index) - 1].type;
            obs_vip_info->obs_v_long_VIP = OBFU_Data_obstacles[((int32_T)
              rp_max_index) - 1].velocity_rel.x;
            obs_vip_info->obs_v_lateral_VIP = OBFU_Data_obstacles[((int32_T)
              rp_max_index) - 1].velocity_rel.y;
            obs_vip_info->obs_acc_long_VIP = OBFU_Data_obstacles[((int32_T)
              rp_max_index) - 1].acceleration_rel.x;
            obs_vip_info->obs_acc_lateral_VIP = OBFU_Data_obstacles[((int32_T)
              rp_max_index) - 1].acceleration_rel.y;
            obs_vip_info->obs_NP_x_VIP = OBFU_Data_obstacles[((int32_T)
              rp_max_index) - 1].nearest_point_rel.x;
            obs_vip_info->obs_NP_y_VIP = OBFU_Data_obstacles[((int32_T)
              rp_max_index) - 1].nearest_point_rel.y;
            obs_vip_info->obs_heading_VIP = OBFU_Data_obstacles[((int32_T)
              rp_max_index) - 1].heading_rel;
            obs_vip_info->obs_length_VIP = OBFU_Data_obstacles[((int32_T)
              rp_max_index) - 1].length;
            obs_vip_info->obs_width_VIP = OBFU_Data_obstacles[((int32_T)
              rp_max_index) - 1].width;
            obs_vip_info->obs_position_zone_VIP = OBFU_Data_obstacles[((int32_T)
              rp_max_index) - 1].position_zone;
            obs_vip_info->obs_motion_status_VIP = OBFU_Data_obstacles[((int32_T)
              rp_max_index) - 1].motion_status;
            obs_vip_info->obs_confidence_VIP = OBFU_Data_obstacles[((int32_T)
              rp_max_index) - 1].confidence;
          }
        }
      }
    }
  }
}

/* System initialize for atomic system: '<S3>/AEB_FCWVIPTargetSelection' */
void AEB_FCWVIPTargetSelection_Init(void)
{
  /* SystemInitialize for Chart: '<S166>/Chart' */
  AEBS_subsystem_integrated_DW.is_active_c20_AEBS_subsystem_in = 0U;
  AEBS_subsystem_integrated_DW.is_c20_AEBS_subsystem_integrate =
    AEBS_su_IN_NO_ACTIVE_CHILD_ofei;
}

/* Start for atomic system: '<S3>/AEB_FCWVIPTargetSelection' */
void AEB_FCWVIPTargetSelection_Start(void)
{
  /* Start for DataStoreMemory: '<S9>/KfAEBS_Veh_DisHead2OC' */
  AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms =
    KfAEBS_Veh_DisHead2OC;

  /* Start for DataStoreMemory: '<S9>/KfAEBS_Veh_DisIngnore2OC' */
  AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisIngnore2OC_p2fq =
    KfAEBS_Veh_DisIngnore2OC;

  /* Start for DataStoreMemory: '<S9>/KfAEBS_Veh_Width' */
  AEBS_subsystem_integrated_DW.KfAEBS_Veh_Width_b12o = KfAEBS_Veh_Width;

  /* Start for DataStoreMemory: '<S9>/KfAEBS_d_Dis2HeadIgnoreSide' */
  AEBS_subsystem_integrated_DW.KfAEBS_d_Dis2HeadIgnoreSid_clhs =
    KfAEBS_d_Dis2HeadIgnoreSide;

  /* Start for DataStoreMemory: '<S9>/KfAEBS_d_Dis_BufferTTSP' */
  AEBS_subsystem_integrated_DW.KfAEBS_d_Dis_BufferTTSP_fvf0 =
    KfAEBS_d_Dis_BufferTTSP;

  /* Start for DataStoreMemory: '<S9>/KfAEBS_d_Dis_BufferTTSP_length' */
  AEBS_subsystem_integrated_DW.KfAEBS_d_Dis_BufferTTSP_le_ahgr =
    KfAEBS_d_Dis_BufferTTSP_length;

  /* Start for DataStoreMemory: '<S9>/KfAEBS_d_Dis_LateralIgnore' */
  AEBS_subsystem_integrated_DW.KfAEBS_d_Dis_LateralIgnore_jbqn =
    KfAEBS_d_Dis_LateralIgnore;

  /* Start for DataStoreMemory: '<S9>/KfAEBS_d_min_dis_swap' */
  AEBS_subsystem_integrated_DW.KfAEBS_d_min_dis_swap_ivsz =
    KfAEBS_d_min_dis_swap;

  /* Start for DataStoreMemory: '<S9>/KfAEBS_t_timeGap_ignore_turn' */
  AEBS_subsystem_integrated_DW.KfAEBS_t_timeGap_ignore_tu_nfky =
    KfAEBS_t_timeGap_ignore_turn;

  /* Start for DataStoreMemory: '<S9>/KfAEBS_v_Speed_DeltaWExit' */
  AEBS_subsystem_integrated_DW.KfAEBS_v_Speed_DeltaWExit_gqet =
    KfAEBS_v_Speed_DeltaWExit;

  /* Start for DataStoreMemory: '<S9>/KfAEBS_v_Speed_ObjStillThrshLateral' */
  AEBS_subsystem_integrated_DW.KfAEBS_v_Speed_ObjStillThrshLat =
    KfAEBS_v_Speed_ObjStillThrshLateral;

  /* Start for DataStoreMemory: '<S9>/KfAEBS_v_obsSpdBuffer' */
  AEBS_subsystem_integrated_DW.KfAEBS_v_obsSpdBuffer_dhnh =
    KfAEBS_v_obsSpdBuffer;

  /* Start for DataStoreMemory: '<S9>/KfAEBS_v_obsSpeedArcMin' */
  AEBS_subsystem_integrated_DW.KfAEBS_v_obsSpeedArcMin_bsty =
    KfAEBS_v_obsSpeedArcMin;
}

/* Output and update for atomic system: '<S3>/AEB_FCWVIPTargetSelection' */
void AEBS__AEB_FCWVIPTargetSelection(void)
{
  int32_T s167_iter;
  AEBS_Obs_VIP_info_Bus rtb_BusAssignment;
  EnumAEBS_TurnType rtb_turn_state;
  boolean_T KbAEBS_use_OBFU_speed_ne4p;
  uint8_T obs_position_state[32];
  uint8_T obs_filtered_type[32];
  real32_T obs_delta_dis[32];
  real32_T obs_delta_speed[32];
  real32_T obs_ttc[32];
  real32_T obs_dis2adc_long[32];
  real32_T obs_dis2adc_lateral[32];
  real32_T obs_v_long[32];
  real32_T obs_v_lateral[32];
  AEBS_Obs_VIP_info_Bus obs_vip_info;
  real32_T KfAEBS_GainTHW_lutf;
  real32_T KfAEBS_GainTTC_b2qu;
  real32_T KfAEBS_Veh_Dis2OC_useCenterPoin;
  real32_T KfAEBS_Veh_DisRear2OC_kfng;

  /* Outputs for Iterator SubSystem: '<S163>/Calc_Lateral_long_buffer' incorporates:
   *  ForIterator: '<S167>/For Iterator'
   */
  /* Assignment: '<S167>/Assignment1' incorporates:
   *  Assignment: '<S167>/Assignment'
   *  Selector: '<S167>/Selector'
   */
  for (s167_iter = 0; (s167_iter + 1) <= 120; s167_iter++)
  {
    /* SwitchCase: '<S168>/Switch Case' incorporates:
     *  Inport: '<Root>/OBFU_DataBus'
     */
    switch (VsOBFU_DataBus.obstacles[s167_iter].type)
    {
     case 1:
      /* Outputs for IfAction SubSystem: '<S168>/Pedestrain' incorporates:
       *  ActionPort: '<S174>/Action Port'
       */
      /* Lookup_n-D: '<S174>/lateral_buffer_pedestrain_table' */
      KfAEBS_Veh_Dis2OC_useCenterPoin = look1_iflf_binlc
        (VsOBFU_DataBus.obstacles[s167_iter].nearest_point_rel.x,
         KaAEBS_AXIS_NearestPointX_vec, KtAEBS_LateralBuffer_Pedstrn, 10U);

      /* End of Outputs for SubSystem: '<S168>/Pedestrain' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S168>/Bicycle' incorporates:
       *  ActionPort: '<S171>/Action Port'
       */
      /* Lookup_n-D: '<S171>/lateral_buffer_bicycle_table' */
      KfAEBS_Veh_Dis2OC_useCenterPoin = look1_iflf_binlc
        (VsOBFU_DataBus.obstacles[s167_iter].nearest_point_rel.x,
         KaAEBS_AXIS_NearestPointX_vec, KtAEBS_LateralBuffer_Bicycle, 10U);

      /* End of Outputs for SubSystem: '<S168>/Bicycle' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S168>/Motorcycle' incorporates:
       *  ActionPort: '<S172>/Action Port'
       */
      /* Lookup_n-D: '<S172>/lateral_buffer_motorcycle_table' */
      KfAEBS_Veh_Dis2OC_useCenterPoin = look1_iflf_binlc
        (VsOBFU_DataBus.obstacles[s167_iter].nearest_point_rel.x,
         KaAEBS_AXIS_NearestPointX_vec, KtAEBS_LateralBuffer_Motor, 10U);

      /* End of Outputs for SubSystem: '<S168>/Motorcycle' */
      break;

     case 4:
     case 5:
     case 6:
      /* Outputs for IfAction SubSystem: '<S168>/VehicleBusTruck' incorporates:
       *  ActionPort: '<S175>/Action Port'
       */
      /* Lookup_n-D: '<S175>/lateral_buffer_vehicle_table' */
      KfAEBS_Veh_Dis2OC_useCenterPoin = look1_iflf_binlc
        (VsOBFU_DataBus.obstacles[s167_iter].nearest_point_rel.x,
         KaAEBS_AXIS_NearestPointX_vec, KtAEBS_LateralBuffer_Vehicle, 10U);

      /* End of Outputs for SubSystem: '<S168>/VehicleBusTruck' */
      break;

     default:
      /* Outputs for IfAction SubSystem: '<S168>/Other' incorporates:
       *  ActionPort: '<S173>/Action Port'
       */
      /* Lookup_n-D: '<S173>/lateral_buffer_other_table' */
      KfAEBS_Veh_Dis2OC_useCenterPoin = look1_iflf_binlc
        (VsOBFU_DataBus.obstacles[s167_iter].nearest_point_rel.x,
         KaAEBS_AXIS_NearestPointX_vec, KtAEBS_LateralBuffer_Other, 10U);

      /* End of Outputs for SubSystem: '<S168>/Other' */
      break;
    }

    /* End of SwitchCase: '<S168>/Switch Case' */

    /* MultiPortSwitch: '<S170>/SwitchVRUObs' incorporates:
     *  Constant: '<S170>/Constant'
     *  Constant: '<S170>/Constant1'
     *  Constant: '<S170>/Constant2'
     *  Inport: '<Root>/OBFU_DataBus'
     */
    switch (VsOBFU_DataBus.obstacles[s167_iter].position_zone)
    {
     case 0:
      KbAEBS_use_OBFU_speed_ne4p = false;
      break;

     case 1:
      KbAEBS_use_OBFU_speed_ne4p = false;
      break;

     case 2:
      KbAEBS_use_OBFU_speed_ne4p = false;
      break;

     case 3:
      KbAEBS_use_OBFU_speed_ne4p = false;
      break;

     case 4:
      KbAEBS_use_OBFU_speed_ne4p = false;
      break;

     case 5:
      KbAEBS_use_OBFU_speed_ne4p = false;
      break;

     case 6:
      KbAEBS_use_OBFU_speed_ne4p = true;
      break;

     case 7:
      KbAEBS_use_OBFU_speed_ne4p = true;
      break;

     case 8:
      KbAEBS_use_OBFU_speed_ne4p = true;
      break;

     default:
      KbAEBS_use_OBFU_speed_ne4p = false;
      break;
    }

    /* End of MultiPortSwitch: '<S170>/SwitchVRUObs' */

    /* Logic: '<S170>/Logical Operator' incorporates:
     *  Constant: '<S170>/Constant19'
     *  Inport: '<Root>/OBFU_DataBus'
     *  RelationalOperator: '<S170>/Relational Operator'
     */
    KbAEBS_use_OBFU_speed_ne4p = (KbAEBS_use_OBFU_speed_ne4p ||
      (VsOBFU_DataBus.obstacles[s167_iter].nearest_point_rel.x <=
       KfAEBS_Veh_DisHead2OC));

    /* Switch: '<S167>/Switch' incorporates:
     *  Constant: '<S167>/Constant2'
     */
    if (KbAEBS_use_OBFU_speed_ne4p)
    {
      KfAEBS_Veh_Dis2OC_useCenterPoin = 0.0F;
    }

    /* End of Switch: '<S167>/Switch' */
    AEBS_subsystem_integrated_B.Assignment[s167_iter] =
      KfAEBS_Veh_Dis2OC_useCenterPoin;

    /* SwitchCase: '<S169>/Switch Case' incorporates:
     *  Inport: '<Root>/OBFU_DataBus'
     */
    switch (VsOBFU_DataBus.obstacles[s167_iter].type)
    {
     case 1:
      /* Outputs for IfAction SubSystem: '<S169>/Pedestrain' incorporates:
       *  ActionPort: '<S179>/Action Port'
       */
      /* Lookup_n-D: '<S179>/long_buffer_pedestrain_table' incorporates:
       *  Abs: '<S179>/Abs'
       */
      KfAEBS_Veh_Dis2OC_useCenterPoin = look1_iflf_binlc((real32_T)fabs((real_T)
        VsOBFU_DataBus.obstacles[s167_iter].nearest_point_rel.y),
        KaAEBS_AXIS_NearestPointY_vec, KtAEBS_LongBuffer_Pedstrn, 10U);

      /* End of Outputs for SubSystem: '<S169>/Pedestrain' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S169>/Bicycle' incorporates:
       *  ActionPort: '<S176>/Action Port'
       */
      /* Lookup_n-D: '<S176>/long_buffer_bicycle_table' incorporates:
       *  Abs: '<S176>/Abs'
       */
      KfAEBS_Veh_Dis2OC_useCenterPoin = look1_iflf_binlc((real32_T)fabs((real_T)
        VsOBFU_DataBus.obstacles[s167_iter].nearest_point_rel.y),
        KaAEBS_AXIS_NearestPointY_vec, KtAEBS_LongBuffer_Bicycle, 10U);

      /* End of Outputs for SubSystem: '<S169>/Bicycle' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S169>/Motorcycle' incorporates:
       *  ActionPort: '<S177>/Action Port'
       */
      /* Lookup_n-D: '<S177>/long_buffer_motorcycle_table' incorporates:
       *  Abs: '<S177>/Abs'
       */
      KfAEBS_Veh_Dis2OC_useCenterPoin = look1_iflf_binlc((real32_T)fabs((real_T)
        VsOBFU_DataBus.obstacles[s167_iter].nearest_point_rel.y),
        KaAEBS_AXIS_NearestPointY_vec, KtAEBS_LongBuffer_Motor, 10U);

      /* End of Outputs for SubSystem: '<S169>/Motorcycle' */
      break;

     case 4:
     case 5:
     case 6:
      /* Outputs for IfAction SubSystem: '<S169>/VehicleBusTruck' incorporates:
       *  ActionPort: '<S180>/Action Port'
       */
      /* Lookup_n-D: '<S180>/long_buffer_vehicle_table' */
      KfAEBS_Veh_Dis2OC_useCenterPoin = look1_iflf_binlc
        (VsOBFU_DataBus.obstacles[s167_iter].nearest_point_rel.y,
         KaAEBS_AXIS_NearestPointY_vec, KtAEBS_LongBuffer_Vehicle, 10U);

      /* End of Outputs for SubSystem: '<S169>/VehicleBusTruck' */
      break;

     default:
      /* Outputs for IfAction SubSystem: '<S169>/Other' incorporates:
       *  ActionPort: '<S178>/Action Port'
       */
      /* Lookup_n-D: '<S178>/long_buffer_other_table' incorporates:
       *  Abs: '<S178>/Abs'
       */
      KfAEBS_Veh_Dis2OC_useCenterPoin = look1_iflf_binlc((real32_T)fabs((real_T)
        VsOBFU_DataBus.obstacles[s167_iter].nearest_point_rel.y),
        KaAEBS_AXIS_NearestPointY_vec, KtAEBS_LongBuffer_Other, 10U);

      /* End of Outputs for SubSystem: '<S169>/Other' */
      break;
    }

    /* End of SwitchCase: '<S169>/Switch Case' */

    /* Switch: '<S167>/Switch1' incorporates:
     *  Constant: '<S167>/Constant3'
     */
    if (KbAEBS_use_OBFU_speed_ne4p)
    {
      KfAEBS_Veh_Dis2OC_useCenterPoin = 0.0F;
    }

    /* End of Switch: '<S167>/Switch1' */
    AEBS_subsystem_integrated_B.Assignment1[s167_iter] =
      KfAEBS_Veh_Dis2OC_useCenterPoin;
  }

  /* End of Assignment: '<S167>/Assignment1' */
  /* End of Outputs for SubSystem: '<S163>/Calc_Lateral_long_buffer' */

  /* DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn7' incorporates:
   *  Constant: '<S9>/Constant10'
   */
  KfAEBS_Veh_Dis2OC_useCenterPoin = KfAEBS_Veh_Dis2OC_useCenterPoint;

  /* DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn8' incorporates:
   *  Constant: '<S9>/Constant11'
   */
  AEBS_subsystem_integrated_DW.KfAEBS_v_obsSpeedArcMin_bsty =
    KfAEBS_v_obsSpeedArcMin;

  /* DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn10' incorporates:
   *  Constant: '<S9>/Constant13'
   */
  AEBS_subsystem_integrated_DW.KfAEBS_v_obsSpdBuffer_dhnh =
    KfAEBS_v_obsSpdBuffer;

  /* DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn15' incorporates:
   *  Constant: '<S9>/Constant19'
   */
  AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisHead2OC_ddms =
    KfAEBS_Veh_DisHead2OC;

  /* DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn17' incorporates:
   *  Constant: '<S9>/Constant21'
   */
  KfAEBS_Veh_DisRear2OC_kfng = KfAEBS_Veh_DisRear2OC;

  /* DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn21' incorporates:
   *  Constant: '<S9>/Constant25'
   */
  AEBS_subsystem_integrated_DW.KfAEBS_v_Speed_ObjStillThrshLat =
    KfAEBS_v_Speed_ObjStillThrshLateral;

  /* DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn22' incorporates:
   *  Constant: '<S9>/Constant26'
   */
  AEBS_subsystem_integrated_DW.KfAEBS_v_Speed_DeltaWExit_gqet =
    KfAEBS_v_Speed_DeltaWExit;

  /* DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn3' incorporates:
   *  Constant: '<S9>/Constant27'
   */
  AEBS_subsystem_integrated_DW.KfAEBS_d_Dis_LateralIgnore_jbqn =
    KfAEBS_d_Dis_LateralIgnore;

  /* DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn4' incorporates:
   *  Constant: '<S9>/Constant28'
   */
  KfAEBS_GainTHW_lutf = KfAEBS_GainTHW;

  /* DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn5' incorporates:
   *  Constant: '<S9>/Constant29'
   */
  KfAEBS_GainTTC_b2qu = KfAEBS_GainTTC;

  /* DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn31' incorporates:
   *  Constant: '<S9>/Constant37'
   */
  AEBS_subsystem_integrated_DW.KfAEBS_d_min_dis_swap_ivsz =
    KfAEBS_d_min_dis_swap;

  /* DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn38' incorporates:
   *  Constant: '<S9>/Constant44'
   */
  AEBS_subsystem_integrated_DW.KfAEBS_d_Dis2HeadIgnoreSid_clhs =
    KfAEBS_d_Dis2HeadIgnoreSide;

  /* DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn6' incorporates:
   *  Constant: '<S9>/Constant5'
   */
  AEBS_subsystem_integrated_DW.KfAEBS_Veh_DisIngnore2OC_p2fq =
    KfAEBS_Veh_DisIngnore2OC;

  /* DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn23' incorporates:
   *  Constant: '<S9>/Constant6'
   */
  AEBS_subsystem_integrated_DW.KfAEBS_t_timeGap_ignore_tu_nfky =
    KfAEBS_t_timeGap_ignore_turn;

  /* DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn' incorporates:
   *  Constant: '<S9>/Constant7'
   */
  AEBS_subsystem_integrated_DW.KfAEBS_Veh_Width_b12o = KfAEBS_Veh_Width;

  /* DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn1' incorporates:
   *  Constant: '<S9>/Constant8'
   */
  AEBS_subsystem_integrated_DW.KfAEBS_d_Dis_BufferTTSP_fvf0 =
    KfAEBS_d_Dis_BufferTTSP;

  /* DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn2' incorporates:
   *  Constant: '<S9>/Constant9'
   */
  AEBS_subsystem_integrated_DW.KfAEBS_d_Dis_BufferTTSP_le_ahgr =
    KfAEBS_d_Dis_BufferTTSP_length;

  /* SignalConversion: '<S9>/Signal Conversion' */
  VfAEBS_veh_speed_used = AEBS_subsystem_integrated_B.veh_speed;

  /* SignalConversion: '<S9>/Signal Conversion11' */
  VfAEBS_speed_x_used = AEBS_subsystem_integrated_B.veh_speed_rel_x;

  /* SignalConversion: '<S9>/Signal Conversion12' */
  VfAEBS_speed_y_used = AEBS_subsystem_integrated_B.veh_speed_rel_y;

  /* SignalConversion: '<S9>/Signal Conversion13' */
  VfAEBS_veh_acc_used = AEBS_subsystem_integrated_B.veh_acceleration;

  /* SignalConversion: '<S9>/Signal Conversion10' */
  VfAEBS_veh_cur_used = AEBS_subsystem_integrated_B.veh_curvature;

  /* Chart: '<S166>/Chart' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Constant: '<S9>/Constant2'
   *  Constant: '<S9>/Constant3'
   *  Constant: '<S9>/Constant4'
   *  DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn24'
   *  DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn25'
   *  DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn26'
   *  DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn27'
   */
  if (((uint32_T)AEBS_subsystem_integrated_DW.is_active_c20_AEBS_subsystem_in) ==
      0U)
  {
    AEBS_subsystem_integrated_DW.is_active_c20_AEBS_subsystem_in = 1U;
    if (VfAEBS_veh_cur_used < KfAEBS_Cur_RightTurnThrshLo)
    {
      AEBS_subsystem_integrated_DW.is_c20_AEBS_subsystem_integrate =
        AEBS_subsystem_in_IN_Right_Turn;
      rtb_turn_state = AEBS_RightTurn;
    }
    else if (VfAEBS_veh_cur_used > KfAEBS_Cur_LeftTurnThrshHi)
    {
      AEBS_subsystem_integrated_DW.is_c20_AEBS_subsystem_integrate =
        AEBS_subsystem_int_IN_Left_Turn;
      rtb_turn_state = AEBS_LeftTurn;
    }
    else
    {
      AEBS_subsystem_integrated_DW.is_c20_AEBS_subsystem_integrate =
        AEBS_subsystem_inte_IN_Straight;
      rtb_turn_state = AEBS_Straight;
    }
  }
  else
  {
    switch (AEBS_subsystem_integrated_DW.is_c20_AEBS_subsystem_integrate)
    {
     case AEBS_subsystem_int_IN_Left_Turn:
      if (VfAEBS_veh_cur_used < KfAEBS_Cur_LeftTurnThrshLo)
      {
        AEBS_subsystem_integrated_DW.is_c20_AEBS_subsystem_integrate =
          AEBS_subsystem_inte_IN_Straight;
        rtb_turn_state = AEBS_Straight;
      }
      else
      {
        rtb_turn_state = AEBS_LeftTurn;
      }
      break;

     case AEBS_subsystem_in_IN_Right_Turn:
      if (VfAEBS_veh_cur_used > KfAEBS_Cur_RightTurnThrshHi)
      {
        AEBS_subsystem_integrated_DW.is_c20_AEBS_subsystem_integrate =
          AEBS_subsystem_inte_IN_Straight;
        rtb_turn_state = AEBS_Straight;
      }
      else
      {
        rtb_turn_state = AEBS_RightTurn;
      }
      break;

     default:
      if (VfAEBS_veh_cur_used < KfAEBS_Cur_RightTurnThrshLo)
      {
        AEBS_subsystem_integrated_DW.is_c20_AEBS_subsystem_integrate =
          AEBS_subsystem_in_IN_Right_Turn;
        rtb_turn_state = AEBS_RightTurn;
      }
      else if (VfAEBS_veh_cur_used > KfAEBS_Cur_LeftTurnThrshHi)
      {
        AEBS_subsystem_integrated_DW.is_c20_AEBS_subsystem_integrate =
          AEBS_subsystem_int_IN_Left_Turn;
        rtb_turn_state = AEBS_LeftTurn;
      }
      else
      {
        rtb_turn_state = AEBS_Straight;
      }
      break;
    }
  }

  /* End of Chart: '<S166>/Chart' */

  /* If: '<S166>/If2' incorporates:
   *  Constant: '<S166>/Constant2'
   *  Constant: '<S166>/Constant3'
   *  Constant: '<S166>/Constant4'
   *  Constant: '<S183>/Constant'
   *  Constant: '<S184>/Constant'
   *  Constant: '<S185>/Constant'
   *  Logic: '<S166>/Logical Operator'
   *  Logic: '<S166>/Logical Operator1'
   *  Logic: '<S166>/Logical Operator2'
   *  RelationalOperator: '<S166>/Relational Operator'
   *  RelationalOperator: '<S166>/Relational Operator1'
   *  RelationalOperator: '<S166>/Relational Operator2'
   */
  if ((rtb_turn_state == AEBS_Straight) && KbAEBS_Active_Straight)
  {
    /* Outputs for IfAction SubSystem: '<S166>/Straight' incorporates:
     *  ActionPort: '<S188>/Action Port'
     */
    /* SignalConversion: '<S188>/OutportBufferForturn_type' incorporates:
     *  Constant: '<S192>/Constant'
     */
    VeAEBS_TurnType = AEBS_Straight;

    /* End of Outputs for SubSystem: '<S166>/Straight' */
  }
  else if ((rtb_turn_state == AEBS_RightTurn) && KbAEBS_Active_RightTurn)
  {
    /* Outputs for IfAction SubSystem: '<S166>/RightTurn' incorporates:
     *  ActionPort: '<S187>/Action Port'
     */
    /* SignalConversion: '<S187>/OutportBufferForturn_type' incorporates:
     *  Constant: '<S191>/Constant'
     */
    VeAEBS_TurnType = AEBS_RightTurn;

    /* End of Outputs for SubSystem: '<S166>/RightTurn' */
  }
  else if ((rtb_turn_state == AEBS_LeftTurn) && KbAEBS_Active_LeftTurn)
  {
    /* Outputs for IfAction SubSystem: '<S166>/LeftTurn' incorporates:
     *  ActionPort: '<S186>/Action Port'
     */
    /* SignalConversion: '<S186>/OutportBufferForturn_type' incorporates:
     *  Constant: '<S190>/Constant'
     */
    VeAEBS_TurnType = AEBS_LeftTurn;

    /* End of Outputs for SubSystem: '<S166>/LeftTurn' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S166>/Default' incorporates:
     *  ActionPort: '<S182>/Action Port'
     */
    /* SignalConversion: '<S182>/OutportBufferForturn_type' incorporates:
     *  Constant: '<S189>/Constant'
     */
    VeAEBS_TurnType = AEBS_TurnInvalid;

    /* End of Outputs for SubSystem: '<S166>/Default' */
  }

  /* End of If: '<S166>/If2' */

  /* MATLAB Function: '<S9>/AEB_Target_Selection' incorporates:
   *  Constant: '<S9>/Constant12'
   *  Constant: '<S9>/Constant30'
   *  Constant: '<S9>/Constant39'
   *  Constant: '<S9>/Constant41'
   *  Constant: '<S9>/Constant45'
   *  DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn33'
   *  DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn35'
   *  DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn39'
   *  DataStoreWrite: '<S9>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn9'
   *  Inport: '<Root>/OBFU_DataBus'
   *  Lookup_n-D: '<S9>/veh_widthGain_table'
   *  Product: '<S9>/Product'
   */
  AEBS_subsyste_init_obs_vip_info(&obs_vip_info);
  memset(&obs_delta_dis[0], 0, (sizeof(real32_T)) << 5U);
  memset(&obs_delta_speed[0], 0, (sizeof(real32_T)) << 5U);
  memset(&obs_ttc[0], 0, (sizeof(real32_T)) << 5U);
  memset(&obs_dis2adc_long[0], 0, (sizeof(real32_T)) << 5U);
  memset(&obs_dis2adc_lateral[0], 0, (sizeof(real32_T)) << 5U);
  memset(&obs_v_long[0], 0, (sizeof(real32_T)) << 5U);
  memset(&obs_v_lateral[0], 0, (sizeof(real32_T)) << 5U);
  for (s167_iter = 0; s167_iter < 32; s167_iter++)
  {
    obs_position_state[s167_iter] = 0U;
    obs_filtered_type[s167_iter] = 0U;
  }

  switch (VeAEBS_TurnType)
  {
   case AEBS_Straight:
    AEBS_sub_vip_selection_straight(VfAEBS_veh_speed_used, VfAEBS_veh_acc_used,
      AEBS_subsystem_integrated_B.Assignment,
      AEBS_subsystem_integrated_B.Assignment1, VsOBFU_DataBus.obstacles,
      VsOBFU_DataBus.num_obstacles, &KbAEBS_FilterVehicleinSide,
      &KbAEBS_Use_OBFU_Acceleration, &KbAEBS_use_OBFU_speed,
      &KfAEBS_GainTHW_lutf, &KfAEBS_GainTTC_b2qu,
      &KfAEBS_Veh_Dis2OC_useCenterPoin, &obs_vip_info, obs_position_state,
      obs_delta_dis, obs_delta_speed, obs_ttc, obs_dis2adc_long,
      obs_dis2adc_lateral, obs_v_long, obs_v_lateral, obs_filtered_type);
    break;

   case AEBS_RightTurn:
    AEBS_subsyst_vip_selection_turn(true, VfAEBS_veh_speed_used,
      VfAEBS_speed_x_used, VfAEBS_speed_y_used, VfAEBS_veh_acc_used,
      VfAEBS_veh_cur_used, look1_iflf_binlc(VfAEBS_veh_speed_used,
      KaAEBS_AXIS_Veh_Speed_vec, KtAEBS_veh_widthGain, 8U) * KfAEBS_Veh_Width,
      AEBS_subsystem_integrated_B.Assignment1, VsOBFU_DataBus.obstacles,
      VsOBFU_DataBus.num_obstacles, &KbAEBS_FilterVehicleinSide,
      &KbAEBS_Use_OBFU_Acceleration, &KfAEBS_Pedstr_width_Thrsh,
      &KfAEBS_GainTHW_lutf, &KfAEBS_GainTTC_b2qu, &KfAEBS_Veh_DisRear2OC_kfng,
      &obs_vip_info, obs_position_state, obs_delta_dis, obs_delta_speed, obs_ttc,
      obs_dis2adc_long, obs_dis2adc_lateral, obs_v_long, obs_v_lateral,
      obs_filtered_type);
    break;

   case AEBS_LeftTurn:
    AEBS_subsyst_vip_selection_turn(false, VfAEBS_veh_speed_used,
      VfAEBS_speed_x_used, VfAEBS_speed_y_used, VfAEBS_veh_acc_used,
      VfAEBS_veh_cur_used, look1_iflf_binlc(VfAEBS_veh_speed_used,
      KaAEBS_AXIS_Veh_Speed_vec, KtAEBS_veh_widthGain, 8U) * KfAEBS_Veh_Width,
      AEBS_subsystem_integrated_B.Assignment1, VsOBFU_DataBus.obstacles,
      VsOBFU_DataBus.num_obstacles, &KbAEBS_FilterVehicleinSide,
      &KbAEBS_Use_OBFU_Acceleration, &KfAEBS_Pedstr_width_Thrsh,
      &KfAEBS_GainTHW_lutf, &KfAEBS_GainTTC_b2qu, &KfAEBS_Veh_DisRear2OC_kfng,
      &obs_vip_info, obs_position_state, obs_delta_dis, obs_delta_speed, obs_ttc,
      obs_dis2adc_long, obs_dis2adc_lateral, obs_v_long, obs_v_lateral,
      obs_filtered_type);
    break;

   default:
    /* no actions */
    break;
  }

  /* End of MATLAB Function: '<S9>/AEB_Target_Selection' */

  /* SignalConversion: '<S9>/Signal Conversion8' */
  for (s167_iter = 0; s167_iter < 32; s167_iter++)
  {
    VfAEBS_obs_position_state[s167_iter] = obs_position_state[s167_iter];
  }

  /* End of SignalConversion: '<S9>/Signal Conversion8' */

  /* SignalConversion: '<S9>/Signal Conversion9' */
  for (s167_iter = 0; s167_iter < 32; s167_iter++)
  {
    VfAEBS_obs_filtered_type[s167_iter] = obs_filtered_type[s167_iter];
  }

  /* End of SignalConversion: '<S9>/Signal Conversion9' */

  /* SignalConversion: '<S9>/Signal Conversion1' */
  memcpy(&VfAEBS_obs_delta_dis[0], &obs_delta_dis[0], (sizeof(real32_T)) << 5U);

  /* SignalConversion: '<S9>/Signal Conversion2' */
  memcpy(&VfAEBS_obs_delta_speed[0], &obs_delta_speed[0], (sizeof(real32_T)) <<
         5U);

  /* SignalConversion: '<S9>/Signal Conversion3' */
  memcpy(&VfAEBS_obs_ttc[0], &obs_ttc[0], (sizeof(real32_T)) << 5U);

  /* SignalConversion: '<S9>/Signal Conversion4' */
  memcpy(&VfAEBS_obs_dis2adc_long[0], &obs_dis2adc_long[0], (sizeof(real32_T)) <<
         5U);

  /* SignalConversion: '<S9>/Signal Conversion5' */
  memcpy(&VfAEBS_obs_dis2adc_lateral[0], &obs_dis2adc_lateral[0], (sizeof
          (real32_T)) << 5U);

  /* SignalConversion: '<S9>/Signal Conversion6' */
  memcpy(&VfAEBS_obs_v_long[0], &obs_v_long[0], (sizeof(real32_T)) << 5U);

  /* SignalConversion: '<S9>/Signal Conversion7' */
  memcpy(&VfAEBS_obs_v_lateral[0], &obs_v_lateral[0], (sizeof(real32_T)) << 5U);

  /* BusAssignment: '<S164>/Bus Assignment' incorporates:
   *  Constant: '<S164>/Constant1'
   */
  rtb_BusAssignment = obs_vip_info;
  rtb_BusAssignment.obs_type_VIP = KfAEBS_VIPObsType;

  /* Switch: '<S164>/Switch' incorporates:
   *  Constant: '<S164>/Constant5'
   */
  if (KbAEBS_RedifineVIPObsType)
  {
    AEBS_subsystem_integrated_B.Switch = rtb_BusAssignment;
  }
  else
  {
    AEBS_subsystem_integrated_B.Switch = obs_vip_info;
  }

  /* End of Switch: '<S164>/Switch' */

  /* DataTypeConversion: '<S165>/Data Type Conversion' */
  VbAEBS_has_obs_vip = AEBS_subsystem_integrated_B.Switch.has_obs_VIP;

  /* DataTypeConversion: '<S165>/Data Type Conversion1' */
  VfAEBS_obs_index_vip = AEBS_subsystem_integrated_B.Switch.obs_index_VIP;

  /* DataTypeConversion: '<S165>/Data Type Conversion10' */
  VfAEBS_obs_v_long_vip = AEBS_subsystem_integrated_B.Switch.obs_v_long_VIP;

  /* DataTypeConversion: '<S165>/Data Type Conversion11' */
  VfAEBS_obs_acc_lateral_vip =
    AEBS_subsystem_integrated_B.Switch.obs_acc_lateral_VIP;

  /* DataTypeConversion: '<S165>/Data Type Conversion12' */
  VfAEBS_obs_acc_long_vip = AEBS_subsystem_integrated_B.Switch.obs_acc_long_VIP;

  /* DataTypeConversion: '<S165>/Data Type Conversion13' */
  VfAEBS_obs_NP_x_vip = AEBS_subsystem_integrated_B.Switch.obs_NP_x_VIP;

  /* DataTypeConversion: '<S165>/Data Type Conversion14' */
  VfAEBS_obs_NP_y_vip = AEBS_subsystem_integrated_B.Switch.obs_NP_y_VIP;

  /* DataTypeConversion: '<S165>/Data Type Conversion15' */
  VfAEBS_obs_heading_VIP = AEBS_subsystem_integrated_B.Switch.obs_heading_VIP;

  /* DataTypeConversion: '<S165>/Data Type Conversion16' */
  VfAEBS_obs_length_VIP = AEBS_subsystem_integrated_B.Switch.obs_length_VIP;

  /* DataTypeConversion: '<S165>/Data Type Conversion17' */
  VfAEBS_obs_width_VIP = AEBS_subsystem_integrated_B.Switch.obs_width_VIP;

  /* DataTypeConversion: '<S165>/Data Type Conversion18' */
  VfAEBS_obs_dis_long_VIP = AEBS_subsystem_integrated_B.Switch.obs_dis_long_VIP;

  /* DataTypeConversion: '<S165>/Data Type Conversion19' */
  VfAEBS_obs_dis_lateral_VIP =
    AEBS_subsystem_integrated_B.Switch.obs_dis_lateral_VIP;

  /* DataTypeConversion: '<S165>/Data Type Conversion2' */
  VfAEBS_obs_rp_vip = AEBS_subsystem_integrated_B.Switch.obs_rp_VIP;

  /* DataTypeConversion: '<S165>/Data Type Conversion20' */
  VfAEBS_obs_position_zone_VIP =
    AEBS_subsystem_integrated_B.Switch.obs_position_zone_VIP;

  /* DataTypeConversion: '<S165>/Data Type Conversion21' */
  VfAEBS_obs_motion_status_VIP =
    AEBS_subsystem_integrated_B.Switch.obs_motion_status_VIP;

  /* DataTypeConversion: '<S165>/Data Type Conversion22' */
  VfAEBS_obs_confidence_VIP =
    AEBS_subsystem_integrated_B.Switch.obs_confidence_VIP;

  /* DataTypeConversion: '<S165>/Data Type Conversion3' */
  VfAEBS_obs_position_state_vip =
    AEBS_subsystem_integrated_B.Switch.obs_position_state_VIP;

  /* DataTypeConversion: '<S165>/Data Type Conversion4' */
  VfAEBS_obs_ttc_vip = AEBS_subsystem_integrated_B.Switch.obs_ttc_VIP;

  /* DataTypeConversion: '<S165>/Data Type Conversion5' */
  VfAEBS_obs_delta_dis_vip =
    AEBS_subsystem_integrated_B.Switch.obs_delta_dis_VIP;

  /* DataTypeConversion: '<S165>/Data Type Conversion6' */
  VfAEBS_obs_delta_speed_vip =
    AEBS_subsystem_integrated_B.Switch.obs_delta_speed_VIP;

  /* DataTypeConversion: '<S165>/Data Type Conversion7' */
  VfAEBS_obs_id_vip = AEBS_subsystem_integrated_B.Switch.obs_id_VIP;

  /* DataTypeConversion: '<S165>/Data Type Conversion8' */
  VfAEBS_obs_type_vip = AEBS_subsystem_integrated_B.Switch.obs_type_VIP;

  /* DataTypeConversion: '<S165>/Data Type Conversion9' */
  VfAEBS_obs_v_lateral_vip =
    AEBS_subsystem_integrated_B.Switch.obs_v_lateral_VIP;

  /* Switch: '<S9>/Switch2' incorporates:
   *  Constant: '<S9>/Constant32'
   *  Constant: '<S9>/Constant33'
   */
  if (KbAEBS_Test_Mode)
  {
    AEBS_subsystem_integrated_B.Switch2 = ((uint8_T)0U);
  }
  else
  {
    AEBS_subsystem_integrated_B.Switch2 = AEBS_subsystem_integrated_B.Switch1;
  }

  /* End of Switch: '<S9>/Switch2' */

  /* Switch: '<S9>/Switch1' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant31'
   */
  if (KbAEBS_Test_Mode)
  {
    AEBS_subsystem_integrated_B.Switch1 = ((uint8_T)0U);
  }

  /* End of Switch: '<S9>/Switch1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
