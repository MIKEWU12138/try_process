/*
 * File: lccs_control_output.c
 *
 * Code generated for Simulink model 'LCCS_subsystem_integrated'.
 *
 * Model version                  : 1.2176
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Jun 10 09:42:58 2020
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

#include "lccs_control_output.h"

/* Include model header file for global data */
#include "LCCS_subsystem_integrated.h"
#include "LCCS_subsystem_integrated_private.h"
#include "look1_iflf_binlca.h"

/* Named constants for Chart: '<S156>/lateral_movement_enable' */
#define IN_lateral_movement_enable_dela ((uint8_T)2U)
#define LCCS_su_IN_NO_ACTIVE_CHILD_l1ko ((uint8_T)0U)
#define LCC_IN_lateral_movement_disable ((uint8_T)1U)
#define LCC_IN_lateral_movement_enabled ((uint8_T)3U)

/* Named constants for Chart: '<S156>/steering_control_states' */
#define LCCS__IN_steer_control_engaging ((uint8_T)2U)
#define LCCS__IN_steer_control_inactive ((uint8_T)3U)
#define LCCS_s_IN_steer_control_engaged ((uint8_T)1U)

/* System initialize for atomic system: '<S2>/DtrmnLCCS_steering_control_output' */
void DtrmnLCCS_steering_control_Init(void)
{
  /* SystemInitialize for Chart: '<S156>/steering_control_states' */
  LCCS_subsystem_integrated_DW.is_active_c43_LCCS_subsystem_in = 0U;
  LCCS_subsystem_integrated_DW.is_c43_LCCS_subsystem_integrate =
    LCCS_su_IN_NO_ACTIVE_CHILD_l1ko;
  VbLCCS_steering_control_engaged = false;

  /* SystemInitialize for Chart: '<S156>/lateral_movement_enable' */
  LCCS_subsystem_integrated_DW.temporalCounter_i1_l3pc = 0U;
  LCCS_subsystem_integrated_DW.is_active_c8_LCCS_subsystem_int = 0U;
  LCCS_subsystem_integrated_DW.is_c8_LCCS_subsystem_integrated =
    LCCS_su_IN_NO_ACTIVE_CHILD_l1ko;
  VbLCCS_lateral_movement_enabled = false;
}

/* Output and update for atomic system: '<S2>/DtrmnLCCS_steering_control_output' */
void DtrmnLCCS_steering_control_outp(void)
{
  real_T rtb_Abs1_efq1;
  boolean_T rtb_Compare_bwuf;
  real32_T tmp;

  /* Abs: '<S12>/Abs' incorporates:
   *  Sum: '<S12>/Add2'
   */
  VfLCCS_steering_angle_diff_abs = (real32_T)fabs((real_T)((real32_T)
    (LCCS_subsystem_integrated_B.Add1 - VfLCCS_EPS_ActualSteeringAngle)));

  /* Logic: '<S156>/Logical Operator19' */
  VbLCCS_steering_control_active = (VbLCCS_steer_control_enable && (((int32_T)
    VcLCCS_EPS_SteeringControlResponse_LCC) != 0));

  /* Abs: '<S12>/Abs1' incorporates:
   *  Sum: '<S12>/Add'
   */
  rtb_Abs1_efq1 = fabs(VfLCCS_timestamp_EGMO - VfLCCS_timestamp_MPFU);

  /* Logic: '<S12>/Logical Operator' incorporates:
   *  Constant: '<S12>/Constant10'
   *  Logic: '<S12>/Logical Operator2'
   *  Lookup_n-D: '<S12>/KtLCCS_Ang_steering_angle_reentry_zone'
   *  RelationalOperator: '<S12>/Relational Operator'
   *  RelationalOperator: '<S12>/Relational Operator2'
   */
  VbLCCS_LCC_ReadyToEngage = ((((VbLCCS_steering_control_active ||
    (VfLCCS_steering_angle_diff_abs < look1_iflf_binlca(VfLCCS_linear_velocity,
    KtLCCS_AXIS_vehicle_speed, KtLCCS_Ang_steering_angle_reentry_zone, 20U))) &&
    VbLCCS_both_lanemark_available) && VbLCCS_lcc_feature_enable) &&
    (rtb_Abs1_efq1 < ((real_T)KfLCCS_t_TimestampAliveThresh)));

  /* Logic: '<S12>/Logical Operator1' incorporates:
   *  Constant: '<S12>/Constant1'
   *  Constant: '<S155>/Constant'
   *  RelationalOperator: '<S12>/Relational Operator1'
   *  RelationalOperator: '<S12>/Relational Operator3'
   */
  VbLCCS_LCC_ForceToDisengage = ((rtb_Abs1_efq1 >= ((real_T)
    KfLCCS_t_TimestampAliveThresh)) || (VeLCCS_valid_lane_marker == LCCS_NoLane));

  /* Logic: '<S156>/Logical Operator18' incorporates:
   *  Constant: '<S157>/Constant'
   *  RelationalOperator: '<S157>/Compare'
   */
  VbLCCS_steering_control_stable = (VbLCCS_steering_control_active &&
    (VfLCCS_steering_angle_diff_abs < 12.0F));

  /* Chart: '<S156>/steering_control_states' */
  if (((uint32_T)LCCS_subsystem_integrated_DW.is_active_c43_LCCS_subsystem_in) ==
      0U)
  {
    LCCS_subsystem_integrated_DW.is_active_c43_LCCS_subsystem_in = 1U;
    LCCS_subsystem_integrated_DW.is_c43_LCCS_subsystem_integrate =
      LCCS__IN_steer_control_inactive;
    VbLCCS_steering_control_engaged = false;
  }
  else
  {
    switch (LCCS_subsystem_integrated_DW.is_c43_LCCS_subsystem_integrate)
    {
     case LCCS_s_IN_steer_control_engaged:
      if (!VbLCCS_steering_control_active)
      {
        LCCS_subsystem_integrated_DW.is_c43_LCCS_subsystem_integrate =
          LCCS__IN_steer_control_inactive;
        VbLCCS_steering_control_engaged = false;
      }
      break;

     case LCCS__IN_steer_control_engaging:
      if (VbLCCS_steering_control_stable)
      {
        LCCS_subsystem_integrated_DW.is_c43_LCCS_subsystem_integrate =
          LCCS_s_IN_steer_control_engaged;
        VbLCCS_steering_control_engaged = true;
      }
      break;

     default:
      if (VbLCCS_steering_control_active)
      {
        LCCS_subsystem_integrated_DW.is_c43_LCCS_subsystem_integrate =
          LCCS__IN_steer_control_engaging;
        VbLCCS_steering_control_engaged = false;
      }
      break;
    }
  }

  /* End of Chart: '<S156>/steering_control_states' */

  /* BusCreator: '<S12>/Bus Creator' */
  VsLCCS_DataBus.LCC_ReadyToEngage = VbLCCS_LCC_ReadyToEngage;
  VsLCCS_DataBus.LCC_ForceToDisengage = VbLCCS_LCC_ForceToDisengage;
  VsLCCS_DataBus.steering_control_engaged = VbLCCS_steering_control_engaged;
  VsLCCS_DataBus.valid_lane_marker = VeLCCS_valid_lane_marker;
  VsLCCS_DataBus.veh_strwhl_angle_des = VfLCCS_veh_strwhl_angle_des;
  VsLCCS_DataBus.lateral_dist_to_go = VfLCCS_lateral_dist_to_go;

  /* RelationalOperator: '<S158>/Compare' incorporates:
   *  Constant: '<S158>/Constant'
   */
  rtb_Compare_bwuf = (VfLCCS_linear_velocity > 1.0F);

  /* Chart: '<S156>/lateral_movement_enable' incorporates:
   *  Constant: '<S156>/KfLCCS_lateral_movement_delay'
   *  Product: '<S156>/Divide2'
   */
  if (((uint32_T)LCCS_subsystem_integrated_DW.temporalCounter_i1_l3pc) < 65535U)
  {
    LCCS_subsystem_integrated_DW.temporalCounter_i1_l3pc = (uint16_T)((int32_T)
      (((int32_T)LCCS_subsystem_integrated_DW.temporalCounter_i1_l3pc) + 1));
  }

  if (((uint32_T)LCCS_subsystem_integrated_DW.is_active_c8_LCCS_subsystem_int) ==
      0U)
  {
    LCCS_subsystem_integrated_DW.is_active_c8_LCCS_subsystem_int = 1U;
    LCCS_subsystem_integrated_DW.is_c8_LCCS_subsystem_integrated =
      LCC_IN_lateral_movement_disable;
    VbLCCS_lateral_movement_enabled = false;
  }
  else
  {
    switch (LCCS_subsystem_integrated_DW.is_c8_LCCS_subsystem_integrated)
    {
     case LCC_IN_lateral_movement_disable:
      if (rtb_Compare_bwuf && VbLCCS_steering_control_engaged)
      {
        LCCS_subsystem_integrated_DW.is_c8_LCCS_subsystem_integrated =
          IN_lateral_movement_enable_dela;
        LCCS_subsystem_integrated_DW.temporalCounter_i1_l3pc = 0U;
        VbLCCS_lateral_movement_enabled = false;
      }
      break;

     case IN_lateral_movement_enable_dela:
      /* MinMax: '<S156>/MinMax4' incorporates:
       *  Constant: '<S156>/Constant10'
       *  Constant: '<S156>/Constant11'
       */
      if ((KfLCCS_t_SampleTime > 0.01F) || (rtIsNaNF(0.01F)))
      {
        tmp = KfLCCS_t_SampleTime;
      }
      else
      {
        tmp = 0.01F;
      }

      /* End of MinMax: '<S156>/MinMax4' */
      if (LCCS_subsystem_integrated_DW.temporalCounter_i1_l3pc >= ((uint16_T)
           ((real32_T)(KfLCCS_t_lateral_movement_delay / tmp))))
      {
        LCCS_subsystem_integrated_DW.is_c8_LCCS_subsystem_integrated =
          LCC_IN_lateral_movement_enabled;
        VbLCCS_lateral_movement_enabled = true;
      }
      else
      {
        if ((!rtb_Compare_bwuf) || (!VbLCCS_steering_control_engaged))
        {
          LCCS_subsystem_integrated_DW.is_c8_LCCS_subsystem_integrated =
            LCC_IN_lateral_movement_disable;
          VbLCCS_lateral_movement_enabled = false;
        }
      }
      break;

     default:
      if ((!rtb_Compare_bwuf) || (!VbLCCS_steering_control_engaged))
      {
        LCCS_subsystem_integrated_DW.is_c8_LCCS_subsystem_integrated =
          LCC_IN_lateral_movement_disable;
        VbLCCS_lateral_movement_enabled = false;
      }
      break;
    }
  }

  /* End of Chart: '<S156>/lateral_movement_enable' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
