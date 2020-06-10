/*
 * File: lccs_lane_marker.c
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

#include "lccs_lane_marker.h"

/* Include model header file for global data */
#include "LCCS_subsystem_integrated.h"
#include "LCCS_subsystem_integrated_private.h"

/* Named constants for Chart: '<S97>/Chart' */
#define LCCS_su_IN_NO_ACTIVE_CHILD_fb2w ((uint8_T)0U)
#define LCCS_subsystem_integr_IN_Raised ((uint8_T)3U)
#define LCCS_subsystem_integra_IN_Delay ((uint8_T)1U)
#define LCCS_subsystem_integrat_IN_INIT ((uint8_T)2U)

/* System initialize for atomic system: '<S2>/CalcLCCS_virtual_lane_marker' */
void CalcLCCS_virtual_lane_mark_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay5' */
  LCCS_subsystem_integrated_DW.UnitDelay5_DSTATE = 3.0F;

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_c5xb = 3.0F;

  /* SystemInitialize for Chart: '<S97>/Chart' */
  LCCS_subsystem_integrated_DW.temporalCounter_i1 = 0U;
  LCCS_subsystem_integrated_DW.is_active_c14_LCCS_subsystem_in = 0U;
  LCCS_subsystem_integrated_DW.is_c14_LCCS_subsystem_integrate =
    LCCS_su_IN_NO_ACTIVE_CHILD_fb2w;

  /* SystemInitialize for IfAction SubSystem: '<S9>/If Action Subsystem1' */
  /* InitializeConditions for UnitDelay: '<S94>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_k1xa = 3.0F;

  /* End of SystemInitialize for SubSystem: '<S9>/If Action Subsystem1' */

  /* SystemInitialize for Merge: '<S9>/Merge' */
  VaLCCS_virtual_left_lanemark[0] = 0.0F;
  VaLCCS_virtual_left_lanemark[1] = 0.0F;
  VaLCCS_virtual_left_lanemark[2] = 0.0F;
  VaLCCS_virtual_left_lanemark[3] = 0.0F;

  /* SystemInitialize for Merge: '<S9>/Merge1' */
  VaLCCS_virtual_right_lanemark[0] = 0.0F;
  VaLCCS_virtual_right_lanemark[1] = 0.0F;
  VaLCCS_virtual_right_lanemark[2] = 0.0F;
  VaLCCS_virtual_right_lanemark[3] = 0.0F;
}

/* Output and update for atomic system: '<S2>/CalcLCCS_virtual_lane_marker' */
void LC_CalcLCCS_virtual_lane_marker(void)
{
  boolean_T rtb_y;
  real32_T rtb_Switch_c3di;
  real32_T rtb_Divide_kmcg;

  /* Sum: '<S92>/Sum1' incorporates:
   *  Constant: '<S9>/Constant13'
   *  Product: '<S92>/Product'
   *  Sum: '<S92>/Sum'
   *  UnitDelay: '<S9>/Unit Delay'
   *  UnitDelay: '<S9>/Unit Delay5'
   */
  VfLCCS_smoothed_lane_width = ((LCCS_subsystem_integrated_DW.UnitDelay5_DSTATE
    - LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_c5xb) *
    KfLCCS_k_LaneWidthFilter) +
    LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_c5xb;

  /* MultiPortSwitch: '<S9>/Multiport Switch' incorporates:
   *  Constant: '<S9>/Constant'
   */
  VfLCCS_left_lanemark_confidence = VaLCCS_raw_left_lanemark[1 - 1];

  /* Chart: '<S97>/Chart' incorporates:
   *  Constant: '<S9>/Constant10'
   *  Constant: '<S9>/Constant11'
   *  Constant: '<S9>/Constant12'
   *  MinMax: '<S9>/MinMax4'
   *  Product: '<S9>/Divide2'
   *  RelationalOperator: '<S9>/Relational Operator6'
   *  UnitDelay: '<S9>/Unit Delay1'
   */
  if (LCCS_subsystem_integrated_DW.temporalCounter_i1 < MAX_uint32_T)
  {
    LCCS_subsystem_integrated_DW.temporalCounter_i1++;
  }

  if (((uint32_T)LCCS_subsystem_integrated_DW.is_active_c14_LCCS_subsystem_in) ==
      0U)
  {
    LCCS_subsystem_integrated_DW.is_active_c14_LCCS_subsystem_in = 1U;
    LCCS_subsystem_integrated_DW.is_c14_LCCS_subsystem_integrate =
      LCCS_subsystem_integrat_IN_INIT;
    rtb_y = false;
  }
  else
  {
    switch (LCCS_subsystem_integrated_DW.is_c14_LCCS_subsystem_integrate)
    {
     case LCCS_subsystem_integra_IN_Delay:
      if (!(LCCS_subsystem_integrated_DW.UnitDelay1_DSTATE ==
            VfLCCS_timestamp_MPFU))
      {
        LCCS_subsystem_integrated_DW.is_c14_LCCS_subsystem_integrate =
          LCCS_subsystem_integrat_IN_INIT;
        rtb_y = false;
      }
      else
      {
        if ((KfLCCS_t_SampleTime > 0.01F) || (rtIsNaNF(0.01F)))
        {
          /* MinMax: '<S9>/MinMax4' incorporates:
           *  Constant: '<S9>/Constant10'
           */
          rtb_Divide_kmcg = KfLCCS_t_SampleTime;
        }
        else
        {
          /* MinMax: '<S9>/MinMax4' incorporates:
           *  Constant: '<S9>/Constant11'
           */
          rtb_Divide_kmcg = 0.01F;
        }

        if (LCCS_subsystem_integrated_DW.temporalCounter_i1 >= ((uint32_T)
             ((real32_T)(1.0F / rtb_Divide_kmcg))))
        {
          LCCS_subsystem_integrated_DW.is_c14_LCCS_subsystem_integrate =
            LCCS_subsystem_integr_IN_Raised;
          rtb_y = true;
        }
        else
        {
          rtb_y = false;
        }
      }
      break;

     case LCCS_subsystem_integrat_IN_INIT:
      if (LCCS_subsystem_integrated_DW.UnitDelay1_DSTATE ==
          VfLCCS_timestamp_MPFU)
      {
        LCCS_subsystem_integrated_DW.is_c14_LCCS_subsystem_integrate =
          LCCS_subsystem_integra_IN_Delay;
        LCCS_subsystem_integrated_DW.temporalCounter_i1 = 0U;
        rtb_y = false;
      }
      else
      {
        rtb_y = false;
      }
      break;

     default:
      if (!(LCCS_subsystem_integrated_DW.UnitDelay1_DSTATE ==
            VfLCCS_timestamp_MPFU))
      {
        LCCS_subsystem_integrated_DW.is_c14_LCCS_subsystem_integrate =
          LCCS_subsystem_integrat_IN_INIT;
        rtb_y = false;
      }
      else
      {
        rtb_y = true;
      }
      break;
    }
  }

  /* End of Chart: '<S97>/Chart' */

  /* Logic: '<S9>/Logical Operator9' */
  rtb_y = !rtb_y;

  /* Logic: '<S9>/Logical Operator7' incorporates:
   *  Constant: '<S9>/Constant2'
   *  Constant: '<S9>/Constant8'
   *  RelationalOperator: '<S9>/Relational Operator'
   *  RelationalOperator: '<S9>/Relational Operator4'
   */
  VbLCCS_left_lanemark_valid = (((256.0F >= VfLCCS_left_lanemark_confidence) &&
    (VfLCCS_left_lanemark_confidence >= KfLCCS_LanemarkerQualityThrsh)) && rtb_y);

  /* MultiPortSwitch: '<S9>/Multiport Switch1' incorporates:
   *  Constant: '<S9>/Constant1'
   */
  VfLCCS_right_lanemark_confidence = VaLCCS_raw_right_lanemark[1 - 1];

  /* Logic: '<S9>/Logical Operator6' incorporates:
   *  Constant: '<S9>/Constant6'
   *  Constant: '<S9>/Constant7'
   *  RelationalOperator: '<S9>/Relational Operator1'
   *  RelationalOperator: '<S9>/Relational Operator3'
   */
  rtb_y = ((rtb_y && (256.0F >= VfLCCS_right_lanemark_confidence)) &&
           (VfLCCS_right_lanemark_confidence >= KfLCCS_LanemarkerQualityThrsh));

  /* Switch: '<S9>/Switch' incorporates:
   *  Abs: '<S9>/Abs1'
   *  Constant: '<S9>/Constant14'
   *  Constant: '<S9>/Constant15'
   *  Constant: '<S9>/Constant3'
   *  Constant: '<S9>/Constant4'
   *  Constant: '<S9>/Constant5'
   *  Gain: '<S9>/Gain'
   *  Logic: '<S9>/Logical Operator4'
   *  MultiPortSwitch: '<S9>/left_c0'
   *  MultiPortSwitch: '<S9>/left_c1'
   *  MultiPortSwitch: '<S9>/right_c0'
   *  MultiPortSwitch: '<S9>/right_c1'
   *  Product: '<S9>/Product'
   *  RelationalOperator: '<S9>/Relational Operator2'
   *  Sum: '<S9>/Add'
   *  Sum: '<S9>/Add1'
   *  Trigonometry: '<S9>/Cos'
   */
  if (VbLCCS_left_lanemark_valid && rtb_y)
  {
    VbLCCS_right_lanemark_valid = (((real32_T)fabs((real_T)((real32_T)
      ((VaLCCS_raw_left_lanemark[2 - 1] - VaLCCS_raw_right_lanemark[2 - 1]) *
       ((real32_T)cos((real_T)((real32_T)(0.5F * (VaLCCS_raw_left_lanemark[3 - 1]
      + VaLCCS_raw_right_lanemark[3 - 1]))))))))) < KfLCCS_d_ValidLaneWidthLimit);
  }
  else
  {
    VbLCCS_right_lanemark_valid = rtb_y;
  }

  /* End of Switch: '<S9>/Switch' */

  /* If: '<S9>/If' incorporates:
   *  Logic: '<S9>/Logical Operator'
   *  Logic: '<S9>/Logical Operator1'
   *  Logic: '<S9>/Logical Operator2'
   *  Logic: '<S9>/Logical Operator3'
   *  Logic: '<S9>/Logical Operator5'
   */
  if (VbLCCS_left_lanemark_valid && VbLCCS_right_lanemark_valid)
  {
    /* Outputs for IfAction SubSystem: '<S9>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S94>/Action Port'
     */
    /* Trigonometry: '<S94>/Cos' incorporates:
     *  Constant: '<S94>/Constant11'
     *  Constant: '<S94>/Constant12'
     *  Gain: '<S94>/Gain'
     *  MultiPortSwitch: '<S94>/Multiport Switch10'
     *  MultiPortSwitch: '<S94>/Multiport Switch11'
     *  Sum: '<S94>/Add1'
     */
    rtb_Divide_kmcg = (real32_T)cos((real_T)((real32_T)(0.5F *
      (VaLCCS_raw_left_lanemark[3 - 1] + VaLCCS_raw_right_lanemark[3 - 1]))));

    /* MinMax: '<S94>/Max1' incorporates:
     *  Constant: '<S94>/Constant13'
     *  Trigonometry: '<S94>/Cos'
     */
    if ((rtb_Divide_kmcg > 0.5F) || (rtIsNaNF(0.5F)))
    {
    }
    else
    {
      rtb_Divide_kmcg = 0.5F;
    }

    /* End of MinMax: '<S94>/Max1' */

    /* Product: '<S94>/Divide' incorporates:
     *  Constant: '<S94>/Constant14'
     */
    rtb_Divide_kmcg = 1.0F / rtb_Divide_kmcg;

    /* Switch: '<S94>/Switch' incorporates:
     *  Constant: '<S99>/Constant'
     *  RelationalOperator: '<S99>/Compare'
     *  UnitDelay: '<S94>/Unit Delay'
     */
    if (rtb_Divide_kmcg < 1.9F)
    {
      /* Product: '<S94>/Divide1' incorporates:
       *  Constant: '<S94>/Constant10'
       *  Constant: '<S94>/Constant9'
       *  MultiPortSwitch: '<S94>/Multiport Switch8'
       *  MultiPortSwitch: '<S94>/Multiport Switch9'
       *  Sum: '<S94>/Add'
       */
      rtb_Switch_c3di = (VaLCCS_raw_left_lanemark[2 - 1] -
                         VaLCCS_raw_right_lanemark[2 - 1]) / rtb_Divide_kmcg;

      /* Saturate: '<S94>/Limit_2p5m_to_6m' */
      if (rtb_Switch_c3di > 6.0F)
      {
        rtb_Switch_c3di = 6.0F;
      }
      else
      {
        if (rtb_Switch_c3di < 2.5F)
        {
          rtb_Switch_c3di = 2.5F;
        }
      }

      /* End of Saturate: '<S94>/Limit_2p5m_to_6m' */
    }
    else
    {
      rtb_Switch_c3di = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_k1xa;
    }

    /* End of Switch: '<S94>/Switch' */

    /* SignalConversion: '<S94>/OutportBufferForraw_lane_width' */
    VfLCCS_raw_lane_width = rtb_Switch_c3di;

    /* SignalConversion: '<S94>/OutportBufferForc0_scaling' */
    VfLCCS_c0_scaling = rtb_Divide_kmcg;

    /* MultiPortSwitch: '<S94>/Multiport Switch' incorporates:
     *  Constant: '<S94>/Constant1'
     */
    VaLCCS_virtual_left_lanemark[0] = VaLCCS_raw_left_lanemark[2 - 1];

    /* MultiPortSwitch: '<S94>/Multiport Switch1' incorporates:
     *  Constant: '<S94>/Constant2'
     */
    VaLCCS_virtual_left_lanemark[1] = VaLCCS_raw_left_lanemark[3 - 1];

    /* MultiPortSwitch: '<S94>/Multiport Switch2' incorporates:
     *  Constant: '<S94>/Constant3'
     */
    VaLCCS_virtual_left_lanemark[2] = VaLCCS_raw_left_lanemark[4 - 1];

    /* MultiPortSwitch: '<S94>/Multiport Switch3' incorporates:
     *  Constant: '<S94>/Constant4'
     */
    VaLCCS_virtual_left_lanemark[3] = VaLCCS_raw_left_lanemark[5 - 1];

    /* MultiPortSwitch: '<S94>/Multiport Switch4' incorporates:
     *  Constant: '<S94>/Constant5'
     */
    VaLCCS_virtual_right_lanemark[0] = VaLCCS_raw_right_lanemark[2 - 1];

    /* MultiPortSwitch: '<S94>/Multiport Switch5' incorporates:
     *  Constant: '<S94>/Constant6'
     */
    VaLCCS_virtual_right_lanemark[1] = VaLCCS_raw_right_lanemark[3 - 1];

    /* MultiPortSwitch: '<S94>/Multiport Switch6' incorporates:
     *  Constant: '<S94>/Constant7'
     */
    VaLCCS_virtual_right_lanemark[2] = VaLCCS_raw_right_lanemark[4 - 1];

    /* MultiPortSwitch: '<S94>/Multiport Switch7' incorporates:
     *  Constant: '<S94>/Constant8'
     */
    VaLCCS_virtual_right_lanemark[3] = VaLCCS_raw_right_lanemark[5 - 1];

    /* SignalConversion: '<S94>/OutportBufferForvalid_lane_marker' incorporates:
     *  Constant: '<S100>/Constant'
     */
    VeLCCS_valid_lane_marker = LCCS_BothLane;

    /* Update for UnitDelay: '<S94>/Unit Delay' */
    LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_k1xa = rtb_Switch_c3di;

    /* End of Outputs for SubSystem: '<S9>/If Action Subsystem1' */
  }
  else if ((!VbLCCS_left_lanemark_valid) && VbLCCS_right_lanemark_valid)
  {
    /* Outputs for IfAction SubSystem: '<S9>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S95>/Action Port'
     */
    /* Trigonometry: '<S95>/Cos5' incorporates:
     *  Constant: '<S95>/Constant12'
     *  MultiPortSwitch: '<S95>/Multiport Switch10'
     */
    rtb_Divide_kmcg = (real32_T)cos((real_T)VaLCCS_raw_right_lanemark[3 - 1]);

    /* MinMax: '<S95>/Max2' incorporates:
     *  Constant: '<S95>/Constant13'
     */
    if ((rtb_Divide_kmcg > 0.5F) || (rtIsNaNF(0.5F)))
    {
    }
    else
    {
      rtb_Divide_kmcg = 0.5F;
    }

    /* End of MinMax: '<S95>/Max2' */

    /* Product: '<S95>/Divide' incorporates:
     *  Constant: '<S95>/Constant14'
     */
    rtb_Divide_kmcg = 1.0F / rtb_Divide_kmcg;

    /* Sum: '<S95>/Add' incorporates:
     *  Constant: '<S95>/Constant1'
     *  MultiPortSwitch: '<S95>/Multiport Switch'
     *  Product: '<S95>/Product'
     */
    VaLCCS_virtual_left_lanemark[0] = (rtb_Divide_kmcg *
      VfLCCS_smoothed_lane_width) + VaLCCS_raw_right_lanemark[2 - 1];

    /* SignalConversion: '<S95>/OutportBufferForc0_scaling' */
    VfLCCS_c0_scaling = rtb_Divide_kmcg;

    /* MultiPortSwitch: '<S95>/Multiport Switch1' incorporates:
     *  Constant: '<S95>/Constant2'
     */
    VaLCCS_virtual_left_lanemark[1] = VaLCCS_raw_right_lanemark[3 - 1];

    /* MultiPortSwitch: '<S95>/Multiport Switch2' incorporates:
     *  Constant: '<S95>/Constant3'
     */
    VaLCCS_virtual_left_lanemark[2] = VaLCCS_raw_right_lanemark[4 - 1];

    /* MultiPortSwitch: '<S95>/Multiport Switch3' incorporates:
     *  Constant: '<S95>/Constant4'
     */
    VaLCCS_virtual_left_lanemark[3] = VaLCCS_raw_right_lanemark[5 - 1];

    /* MultiPortSwitch: '<S95>/Multiport Switch4' incorporates:
     *  Constant: '<S95>/Constant5'
     */
    VaLCCS_virtual_right_lanemark[0] = VaLCCS_raw_right_lanemark[2 - 1];

    /* MultiPortSwitch: '<S95>/Multiport Switch5' incorporates:
     *  Constant: '<S95>/Constant6'
     */
    VaLCCS_virtual_right_lanemark[1] = VaLCCS_raw_right_lanemark[3 - 1];

    /* MultiPortSwitch: '<S95>/Multiport Switch6' incorporates:
     *  Constant: '<S95>/Constant7'
     */
    VaLCCS_virtual_right_lanemark[2] = VaLCCS_raw_right_lanemark[4 - 1];

    /* MultiPortSwitch: '<S95>/Multiport Switch7' incorporates:
     *  Constant: '<S95>/Constant8'
     */
    VaLCCS_virtual_right_lanemark[3] = VaLCCS_raw_right_lanemark[5 - 1];

    /* SignalConversion: '<S95>/OutportBufferForvalid_lane_marker' incorporates:
     *  Constant: '<S101>/Constant'
     */
    VeLCCS_valid_lane_marker = LCCS_RightLane;

    /* End of Outputs for SubSystem: '<S9>/If Action Subsystem2' */
  }
  else if (VbLCCS_left_lanemark_valid && (!VbLCCS_right_lanemark_valid))
  {
    /* Outputs for IfAction SubSystem: '<S9>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S96>/Action Port'
     */
    /* Trigonometry: '<S96>/Cos5' incorporates:
     *  Constant: '<S96>/Constant12'
     *  MultiPortSwitch: '<S96>/Multiport Switch10'
     */
    rtb_Divide_kmcg = (real32_T)cos((real_T)VaLCCS_raw_left_lanemark[3 - 1]);

    /* MinMax: '<S96>/Max2' incorporates:
     *  Constant: '<S96>/Constant13'
     */
    if ((rtb_Divide_kmcg > 0.5F) || (rtIsNaNF(0.5F)))
    {
    }
    else
    {
      rtb_Divide_kmcg = 0.5F;
    }

    /* End of MinMax: '<S96>/Max2' */

    /* Product: '<S96>/Divide' incorporates:
     *  Constant: '<S96>/Constant14'
     */
    rtb_Divide_kmcg = 1.0F / rtb_Divide_kmcg;

    /* Sum: '<S96>/Add' incorporates:
     *  Constant: '<S96>/Constant1'
     *  MultiPortSwitch: '<S96>/Multiport Switch'
     *  Product: '<S96>/Product'
     */
    VaLCCS_virtual_right_lanemark[0] = VaLCCS_raw_left_lanemark[2 - 1] -
      (rtb_Divide_kmcg * VfLCCS_smoothed_lane_width);

    /* SignalConversion: '<S96>/OutportBufferForc0_scaling' */
    VfLCCS_c0_scaling = rtb_Divide_kmcg;

    /* MultiPortSwitch: '<S96>/Multiport Switch1' incorporates:
     *  Constant: '<S96>/Constant2'
     */
    VaLCCS_virtual_left_lanemark[1] = VaLCCS_raw_left_lanemark[3 - 1];

    /* MultiPortSwitch: '<S96>/Multiport Switch2' incorporates:
     *  Constant: '<S96>/Constant3'
     */
    VaLCCS_virtual_left_lanemark[2] = VaLCCS_raw_left_lanemark[4 - 1];

    /* MultiPortSwitch: '<S96>/Multiport Switch3' incorporates:
     *  Constant: '<S96>/Constant4'
     */
    VaLCCS_virtual_left_lanemark[3] = VaLCCS_raw_left_lanemark[5 - 1];

    /* MultiPortSwitch: '<S96>/Multiport Switch4' incorporates:
     *  Constant: '<S96>/Constant5'
     */
    VaLCCS_virtual_left_lanemark[0] = VaLCCS_raw_left_lanemark[2 - 1];

    /* MultiPortSwitch: '<S96>/Multiport Switch5' incorporates:
     *  Constant: '<S96>/Constant6'
     */
    VaLCCS_virtual_right_lanemark[1] = VaLCCS_raw_left_lanemark[3 - 1];

    /* MultiPortSwitch: '<S96>/Multiport Switch6' incorporates:
     *  Constant: '<S96>/Constant7'
     */
    VaLCCS_virtual_right_lanemark[2] = VaLCCS_raw_left_lanemark[4 - 1];

    /* MultiPortSwitch: '<S96>/Multiport Switch7' incorporates:
     *  Constant: '<S96>/Constant8'
     */
    VaLCCS_virtual_right_lanemark[3] = VaLCCS_raw_left_lanemark[5 - 1];

    /* SignalConversion: '<S96>/OutportBufferForvalid_lane_marker' incorporates:
     *  Constant: '<S102>/Constant'
     */
    VeLCCS_valid_lane_marker = LCCS_LeftLane;

    /* End of Outputs for SubSystem: '<S9>/If Action Subsystem3' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S9>/If Action Subsystem' incorporates:
     *  ActionPort: '<S93>/Action Port'
     */
    /* SignalConversion: '<S93>/OutportBufferForvirtual_left_lanemark' incorporates:
     *  Constant: '<S93>/Constant'
     *  Constant: '<S93>/Constant1'
     *  Constant: '<S93>/Constant2'
     *  Gain: '<S93>/Gain'
     */
    VaLCCS_virtual_left_lanemark[0] = 0.5F * VfLCCS_smoothed_lane_width;
    VaLCCS_virtual_left_lanemark[1] = 0.0F;
    VaLCCS_virtual_left_lanemark[2] = 0.0F;
    VaLCCS_virtual_left_lanemark[3] = 0.0F;

    /* SignalConversion: '<S93>/OutportBufferForvirtual_right_lanemark' incorporates:
     *  Constant: '<S93>/Constant3'
     *  Constant: '<S93>/Constant4'
     *  Constant: '<S93>/Constant5'
     *  Gain: '<S93>/Gain1'
     */
    VaLCCS_virtual_right_lanemark[0] = (-0.5F) * VfLCCS_smoothed_lane_width;
    VaLCCS_virtual_right_lanemark[1] = 0.0F;
    VaLCCS_virtual_right_lanemark[2] = 0.0F;
    VaLCCS_virtual_right_lanemark[3] = 0.0F;

    /* SignalConversion: '<S93>/OutportBufferForc0_scaling' incorporates:
     *  Constant: '<S93>/Constant9'
     */
    VfLCCS_c0_scaling = 1.0F;

    /* SignalConversion: '<S93>/OutportBufferForvalid_lane_marker' incorporates:
     *  Constant: '<S98>/Constant'
     */
    VeLCCS_valid_lane_marker = LCCS_NoLane;

    /* End of Outputs for SubSystem: '<S9>/If Action Subsystem' */
  }

  /* End of If: '<S9>/If' */

  /* Logic: '<S9>/Logical Operator8' */
  VbLCCS_both_lanemark_available = (VbLCCS_left_lanemark_valid && rtb_y);

  /* Update for UnitDelay: '<S9>/Unit Delay5' */
  LCCS_subsystem_integrated_DW.UnitDelay5_DSTATE = VfLCCS_raw_lane_width;

  /* Update for UnitDelay: '<S9>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_c5xb =
    VfLCCS_smoothed_lane_width;

  /* Update for UnitDelay: '<S9>/Unit Delay1' */
  LCCS_subsystem_integrated_DW.UnitDelay1_DSTATE = VfLCCS_timestamp_MPFU;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
