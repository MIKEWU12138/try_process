/*
 * File: lccs_lateral_shift.c
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

#include "lccs_lateral_shift.h"

/* Include model header file for global data */
#include "LCCS_subsystem_integrated.h"
#include "LCCS_subsystem_integrated_private.h"

/* Named constants for Chart: '<S8>/lateral_shift_control_states' */
#define LCCS_subsy_IN_shifting_inactive ((uint8_T)2U)
#define LCCS_subsys_IN_touched_new_lane ((uint8_T)3U)
#define LCCS_subsyst_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define LCCS_subsystem_i_IN_approaching ((uint8_T)1U)

/* System initialize for atomic system: '<S2>/CalcLCCS_lateral_shift_width' */
void CalcLCCS_lateral_shift_wid_Init(void)
{
  /* SystemInitialize for Chart: '<S8>/lateral_shift_control_states' */
  LCCS_subsystem_integrated_DW.is_active_c7_LCCS_subsystem_int = 0U;
  LCCS_subsystem_integrated_DW.is_c7_LCCS_subsystem_integrated =
    LCCS_subsyst_IN_NO_ACTIVE_CHILD;
  VbLCCS_shifting_in_progress = false;
  VeLCCS_shifting_direction_final = FORWARD;
}

/* Output and update for atomic system: '<S2>/CalcLCCS_lateral_shift_width' */
void LC_CalcLCCS_lateral_shift_width(void)
{
  real32_T rtb_c2;
  boolean_T rtb_LogicalOperator1_f1jw;
  real32_T rtb_Min;
  real32_T rtb_Switch6_cvok;
  real32_T u0;

  /* Gain: '<S8>/Gain1' */
  rtb_c2 = 1.5F * VfLCCS_smoothed_lane_width;

  /* Logic: '<S8>/Logical Operator1' incorporates:
   *  Logic: '<S8>/Logical Operator'
   */
  rtb_LogicalOperator1_f1jw = ((VbLCCS_lane_change_request ||
    VbLCCS_inlane_nudge_request) &&
    (LCCS_subsystem_integrated_B.VbLCCS_steering_control_st_jgz4));

  /* Chart: '<S8>/lateral_shift_control_states' */
  if (((uint32_T)LCCS_subsystem_integrated_DW.is_active_c7_LCCS_subsystem_int) ==
      0U)
  {
    LCCS_subsystem_integrated_DW.is_active_c7_LCCS_subsystem_int = 1U;
    LCCS_subsystem_integrated_DW.is_c7_LCCS_subsystem_integrated =
      LCCS_subsy_IN_shifting_inactive;
    VbLCCS_shifting_in_progress = false;
    VeLCCS_shifting_direction_final = FORWARD;
  }
  else
  {
    switch (LCCS_subsystem_integrated_DW.is_c7_LCCS_subsystem_integrated)
    {
     case LCCS_subsystem_i_IN_approaching:
      if (VbLCCS_touched_new_lane)
      {
        LCCS_subsystem_integrated_DW.is_c7_LCCS_subsystem_integrated =
          LCCS_subsys_IN_touched_new_lane;
        VbLCCS_shifting_in_progress = false;
        VeLCCS_shifting_direction_final = FORWARD;
      }
      else
      {
        if (!rtb_LogicalOperator1_f1jw)
        {
          LCCS_subsystem_integrated_DW.is_c7_LCCS_subsystem_integrated =
            LCCS_subsy_IN_shifting_inactive;
          VbLCCS_shifting_in_progress = false;
          VeLCCS_shifting_direction_final = FORWARD;
        }
      }
      break;

     case LCCS_subsy_IN_shifting_inactive:
      if (rtb_LogicalOperator1_f1jw)
      {
        LCCS_subsystem_integrated_DW.is_c7_LCCS_subsystem_integrated =
          LCCS_subsystem_i_IN_approaching;
        VbLCCS_shifting_in_progress = true;
        VeLCCS_shifting_direction_final = VeLCCS_shifting_direction_raw;
      }
      break;

     default:
      if (!rtb_LogicalOperator1_f1jw)
      {
        LCCS_subsystem_integrated_DW.is_c7_LCCS_subsystem_integrated =
          LCCS_subsy_IN_shifting_inactive;
        VbLCCS_shifting_in_progress = false;
        VeLCCS_shifting_direction_final = FORWARD;
      }
      break;
    }
  }

  /* End of Chart: '<S8>/lateral_shift_control_states' */

  /* Sum: '<S84>/Add1' incorporates:
   *  Abs: '<S84>/Abs1'
   *  Constant: '<S84>/Constant1'
   *  Constant: '<S84>/Constant5'
   *  Gain: '<S84>/Gain'
   *  Sum: '<S84>/Add'
   */
  rtb_Switch6_cvok = (0.5F * (VfLCCS_smoothed_lane_width - KfLCCS_d_VehicleWidth))
    - ((real32_T)fabs((real_T)KfLCCS_d_NudgeSafetyZone));

  /* MinMax: '<S84>/Max' incorporates:
   *  Constant: '<S84>/Constant'
   */
  if ((0.0F > rtb_Switch6_cvok) || (rtIsNaNF(rtb_Switch6_cvok)))
  {
    rtb_Switch6_cvok = 0.0F;
  }

  /* End of MinMax: '<S84>/Max' */

  /* Switch: '<S84>/Switch4' incorporates:
   *  Constant: '<S84>/Constant12'
   */
  if (VbLCCS_shifting_in_progress)
  {
    /* Switch: '<S84>/Switch7' incorporates:
     *  Switch: '<S84>/Switch8'
     */
    if (VbLCCS_lane_change_request)
    {
      /* Switch: '<S84>/Switch5' incorporates:
       *  Constant: '<S88>/Constant'
       *  Constant: '<S89>/Constant'
       *  RelationalOperator: '<S84>/Relational Operator2'
       *  RelationalOperator: '<S84>/Relational Operator3'
       *  Switch: '<S84>/Switch6'
       */
      if (LEFT == VeLCCS_shifting_direction_final)
      {
        rtb_Switch6_cvok = VfLCCS_smoothed_lane_width;
      }
      else if (RIGHT == VeLCCS_shifting_direction_final)
      {
        /* Switch: '<S84>/Switch6' incorporates:
         *  Gain: '<S84>/Gain2'
         */
        rtb_Switch6_cvok = (-1.0F) * VfLCCS_smoothed_lane_width;
      }
      else
      {
        /* Switch: '<S84>/Switch6' incorporates:
         *  Constant: '<S84>/Constant13'
         */
        rtb_Switch6_cvok = 0.0F;
      }

      /* End of Switch: '<S84>/Switch5' */
    }
    else if (VbLCCS_inlane_nudge_request)
    {
      /* Switch: '<S84>/Switch1' incorporates:
       *  Constant: '<S90>/Constant'
       *  Constant: '<S91>/Constant'
       *  RelationalOperator: '<S84>/Relational Operator'
       *  RelationalOperator: '<S84>/Relational Operator1'
       *  Switch: '<S84>/Switch3'
       *  Switch: '<S84>/Switch8'
       */
      if (LEFT == VeLCCS_shifting_direction_final)
      {
      }
      else if (RIGHT == VeLCCS_shifting_direction_final)
      {
        /* Switch: '<S84>/Switch3' incorporates:
         *  Gain: '<S84>/Gain1'
         */
        rtb_Switch6_cvok *= (-1.0F);
      }
      else
      {
        /* Switch: '<S84>/Switch3' incorporates:
         *  Constant: '<S84>/Constant3'
         */
        rtb_Switch6_cvok = 0.0F;
      }

      /* End of Switch: '<S84>/Switch1' */
    }
    else
    {
      /* Switch: '<S84>/Switch8' incorporates:
       *  Constant: '<S84>/Constant14'
       */
      rtb_Switch6_cvok = 0.0F;
    }

    /* End of Switch: '<S84>/Switch7' */
    VfLCCS_target_lateral_shift_width = rtb_Switch6_cvok;
  }
  else
  {
    VfLCCS_target_lateral_shift_width = 0.0F;
  }

  /* End of Switch: '<S84>/Switch4' */

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant11'
   *  Logic: '<S8>/Logical Operator6'
   *  Logic: '<S8>/Logical Operator7'
   *  MultiPortSwitch: '<S8>/Multiport Switch2'
   *  Product: '<S8>/Divide1'
   *  Sum: '<S8>/Add'
   *  UnitDelay: '<S8>/Unit Delay1'
   *  UnitDelay: '<S8>/Unit Delay4'
   */
  if ((VbLCCS_lane_change_request && VbLCCS_touched_new_lane) &&
      (!LCCS_subsystem_integrated_DW.UnitDelay1_DSTATE_avtz))
  {
    /* MinMax: '<S8>/Min4' incorporates:
     *  Constant: '<S8>/Constant13'
     */
    if ((VfLCCS_c0_scaling > 1.0F) || (rtIsNaNF(1.0F)))
    {
      rtb_Switch6_cvok = VfLCCS_c0_scaling;
    }
    else
    {
      rtb_Switch6_cvok = 1.0F;
    }

    /* End of MinMax: '<S8>/Min4' */
    rtb_Switch6_cvok = (VaLCCS_raw_lane_center_line[1 - 1] -
                        LCCS_subsystem_integrated_DW.UnitDelay4_DSTATE_m2on) /
      rtb_Switch6_cvok;
  }
  else
  {
    rtb_Switch6_cvok = VfLCCS_target_lateral_shift_width;
  }

  /* End of Switch: '<S8>/Switch' */

  /* Sum: '<S8>/Add1' incorporates:
   *  UnitDelay: '<S8>/Unit Delay'
   */
  rtb_Switch6_cvok -= VfLCCS_lateral_shift_width;

  /* Abs: '<S8>/Abs1' incorporates:
   *  Constant: '<S8>/Constant14'
   *  Product: '<S8>/Product3'
   */
  u0 = (real32_T)fabs((real_T)((real32_T)(VfLCCS_linear_velocity *
    KfLCCS_r_MaxLateralSpeedPortion)));

  /* Abs: '<S8>/Abs2' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Product: '<S8>/Product2'
   */
  rtb_Min = (real32_T)fabs((real_T)((real32_T)(rtb_Switch6_cvok *
    KfLCCS_r_shift_speed_gain)));

  /* MinMax: '<S8>/Min' */
  if ((u0 < rtb_Min) || (rtIsNaNF(rtb_Min)))
  {
    rtb_Min = u0;
  }

  /* End of MinMax: '<S8>/Min' */

  /* Switch: '<S8>/Switch7' incorporates:
   *  Constant: '<S8>/Constant15'
   *  Constant: '<S8>/Constant2'
   *  Constant: '<S8>/Constant3'
   *  Logic: '<S8>/Logical Operator9'
   *  RelationalOperator: '<S85>/LowerRelop1'
   *  RelationalOperator: '<S85>/UpperRelop'
   *  Switch: '<S85>/Switch'
   *  Switch: '<S85>/Switch2'
   */
  if (KbLCCS_lane_change_source_ALCA && VbLCCS_lane_change_request)
  {
    rtb_Min = VfLCCS_lateral_v_from_ALCA;
  }
  else if (rtb_Min > KfLCCS_v_shift_speed_high_limit)
  {
    /* Switch: '<S85>/Switch2' incorporates:
     *  Constant: '<S8>/Constant3'
     */
    rtb_Min = KfLCCS_v_shift_speed_high_limit;
  }
  else
  {
    if (rtb_Min < KfLCCS_v_shift_speed_low_limit)
    {
      /* Switch: '<S85>/Switch' incorporates:
       *  Constant: '<S8>/Constant2'
       */
      rtb_Min = KfLCCS_v_shift_speed_low_limit;
    }
  }

  /* End of Switch: '<S8>/Switch7' */

  /* Product: '<S8>/Product' incorporates:
   *  Constant: '<S8>/Constant6'
   */
  VfLCCS_lateral_shift_step = rtb_Min * KfLCCS_t_SampleTime;

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<S8>/Constant5'
   *  Logic: '<S8>/Logical Operator2'
   *  Logic: '<S8>/Logical Operator3'
   *  Logic: '<S8>/Logical Operator4'
   *  Logic: '<S8>/Logical Operator5'
   *  Logic: '<S8>/Logical Operator8'
   *  MultiPortSwitch: '<S8>/Multiport Switch1'
   *  Product: '<S8>/Divide'
   *  Switch: '<S8>/Switch2'
   *  UnitDelay: '<S8>/Unit Delay2'
   */
  if ((((!VbLCCS_lane_change_request) && VbLCCS_touched_new_lane) &&
       (!LCCS_subsystem_integrated_DW.UnitDelay2_DSTATE_ojf4)) ||
      (!LCCS_subsystem_integrated_B.VbLCCS_steering_control_st_jgz4))
  {
    /* MinMax: '<S8>/Min3' incorporates:
     *  Constant: '<S8>/Constant12'
     */
    if ((VfLCCS_c0_scaling > 1.0F) || (rtIsNaNF(1.0F)))
    {
      rtb_Switch6_cvok = VfLCCS_c0_scaling;
    }
    else
    {
      rtb_Switch6_cvok = 1.0F;
    }

    /* End of MinMax: '<S8>/Min3' */
    VfLCCS_lateral_dist_to_go = VaLCCS_raw_lane_center_line[1 - 1] /
      rtb_Switch6_cvok;
  }
  else if (rtb_Switch6_cvok > 0.0F)
  {
    /* Sum: '<S8>/Add3' incorporates:
     *  Switch: '<S8>/Switch2'
     */
    rtb_Switch6_cvok -= VfLCCS_lateral_shift_step;

    /* MinMax: '<S8>/Min1' incorporates:
     *  Constant: '<S8>/Constant'
     *  Switch: '<S8>/Switch2'
     */
    if ((0.0F > rtb_Switch6_cvok) || (rtIsNaNF(rtb_Switch6_cvok)))
    {
      VfLCCS_lateral_dist_to_go = 0.0F;
    }
    else
    {
      VfLCCS_lateral_dist_to_go = rtb_Switch6_cvok;
    }

    /* End of MinMax: '<S8>/Min1' */
  }
  else
  {
    /* Sum: '<S8>/Add6' incorporates:
     *  Switch: '<S8>/Switch2'
     */
    rtb_Switch6_cvok += VfLCCS_lateral_shift_step;

    /* MinMax: '<S8>/Min2' incorporates:
     *  Constant: '<S8>/Constant4'
     *  Switch: '<S8>/Switch2'
     */
    if ((0.0F < rtb_Switch6_cvok) || (rtIsNaNF(rtb_Switch6_cvok)))
    {
      VfLCCS_lateral_dist_to_go = 0.0F;
    }
    else
    {
      VfLCCS_lateral_dist_to_go = rtb_Switch6_cvok;
    }

    /* End of MinMax: '<S8>/Min2' */
  }

  /* End of Switch: '<S8>/Switch1' */

  /* Sum: '<S8>/Add5' */
  rtb_Switch6_cvok = VfLCCS_target_lateral_shift_width -
    VfLCCS_lateral_dist_to_go;

  /* Gain: '<S8>/Gain' */
  rtb_Min = (-1.5F) * VfLCCS_smoothed_lane_width;

  /* Switch: '<S86>/Switch2' incorporates:
   *  RelationalOperator: '<S86>/LowerRelop1'
   *  RelationalOperator: '<S86>/UpperRelop'
   *  Switch: '<S86>/Switch'
   */
  if (rtb_Switch6_cvok > rtb_c2)
  {
    VfLCCS_lateral_shift_width = rtb_c2;
  }
  else if (rtb_Switch6_cvok < rtb_Min)
  {
    /* Switch: '<S86>/Switch' */
    VfLCCS_lateral_shift_width = rtb_Min;
  }
  else
  {
    VfLCCS_lateral_shift_width = rtb_Switch6_cvok;
  }

  /* End of Switch: '<S86>/Switch2' */

  /* SignalConversion: '<S8>/Signal Conversion' incorporates:
   *  Constant: '<S8>/Constant10'
   *  Constant: '<S8>/Constant7'
   *  Constant: '<S8>/Constant8'
   *  Constant: '<S8>/Constant9'
   *  MultiPortSwitch: '<S8>/Multiport Switch4'
   *  MultiPortSwitch: '<S8>/Multiport Switch5'
   *  MultiPortSwitch: '<S8>/Multiport Switch6'
   *  MultiPortSwitch: '<S8>/Multiport Switch7'
   *  Product: '<S8>/Product1'
   *  Sum: '<S8>/Add4'
   */
  VaLCCS_shifted_lane_center_line[0] = (VfLCCS_lateral_shift_width *
    VfLCCS_c0_scaling) + VaLCCS_raw_lane_center_line[1 - 1];
  VaLCCS_shifted_lane_center_line[1] = VaLCCS_raw_lane_center_line[2 - 1];
  VaLCCS_shifted_lane_center_line[2] = VaLCCS_raw_lane_center_line[3 - 1];
  VaLCCS_shifted_lane_center_line[3] = VaLCCS_raw_lane_center_line[4 - 1];

  /* Update for UnitDelay: '<S8>/Unit Delay2' */
  LCCS_subsystem_integrated_DW.UnitDelay2_DSTATE_ojf4 = VbLCCS_touched_new_lane;

  /* Update for UnitDelay: '<S8>/Unit Delay4' incorporates:
   *  Constant: '<S8>/Constant11'
   *  MultiPortSwitch: '<S8>/Multiport Switch2'
   */
  LCCS_subsystem_integrated_DW.UnitDelay4_DSTATE_m2on =
    VaLCCS_raw_lane_center_line[1 - 1];

  /* Update for UnitDelay: '<S8>/Unit Delay1' */
  LCCS_subsystem_integrated_DW.UnitDelay1_DSTATE_avtz = VbLCCS_touched_new_lane;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
