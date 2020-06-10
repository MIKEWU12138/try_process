/*
 * File: LnMkrFilter_LKA.c
 *
 * Code generated for Simulink model 'LKAS_subsystem_integrated'.
 *
 * Model version                  : 1.102
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 11:05:35 2020
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

#include "LnMkrFilter_LKA.h"

/* Include model header file for global data */
#include "LKAS_subsystem_integrated.h"
#include "LKAS_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S124>/LnMkrFilter_LKA' */
void LKAS_subsystem__LnMkrFilter_LKA(void)
{
  int32_T i;
  real32_T rtb_LeC2;
  real32_T rtb_RiC2;
  real32_T rtb_LeC0;
  real32_T rtb_RiC0;
  uint8_T rtb_RiQlt;
  real32_T rtb_RiC2_tmp;
  real32_T rtb_RiC2_tmp_0;

  /* MATLAB Function: '<S132>/MATLAB Function' incorporates:
   *  Inport: '<Root>/MPFU_DataBus'
   */
  LKAS_subsystem_integrated_B.IsIntvCompleted_sLKA_a1kj = false;
  LKAS_subsystem_integrated_B.LeQlt = 0U;
  rtb_LeC0 = 0.0F;
  LKAS_subsystem_integrated_B.LeC1 = 0.0F;
  rtb_LeC2 = 0.0F;
  LKAS_subsystem_integrated_B.Add3 = 0.0F;
  LKAS_subsystem_integrated_B.LogicalOperator1 = false;
  rtb_RiQlt = 0U;
  rtb_RiC0 = 0.0F;
  LKAS_subsystem_integrated_B.RiC1 = 0.0F;
  rtb_RiC2 = 0.0F;
  LKAS_subsystem_integrated_B.T_AftIntvStart_gady = 0.0F;
  for (i = 0; i < 16; i++)
  {
    if (VsMPFU_DataBus.lane_markers[i].id == 1)
    {
      LKAS_subsystem_integrated_B.IsIntvCompleted_sLKA_a1kj = true;
      LKAS_subsystem_integrated_B.LeQlt = VsMPFU_DataBus.lane_markers[i].quality;
      rtb_LeC0 = VsMPFU_DataBus.lane_markers[i].c0_position;
      LKAS_subsystem_integrated_B.LeC1 = VsMPFU_DataBus.lane_markers[i].
        c1_heading;
      rtb_LeC2 = VsMPFU_DataBus.lane_markers[i].c2_curvature;
      LKAS_subsystem_integrated_B.Add3 = VsMPFU_DataBus.lane_markers[i].
        distance_to_host;
    }
  }

  for (i = 0; i < 16; i++)
  {
    if (VsMPFU_DataBus.lane_markers[i].id == 2)
    {
      LKAS_subsystem_integrated_B.LogicalOperator1 = true;
      rtb_RiQlt = VsMPFU_DataBus.lane_markers[i].quality;
      rtb_RiC0 = VsMPFU_DataBus.lane_markers[i].c0_position;
      LKAS_subsystem_integrated_B.RiC1 = VsMPFU_DataBus.lane_markers[i].
        c1_heading;
      rtb_RiC2 = VsMPFU_DataBus.lane_markers[i].c2_curvature;
      LKAS_subsystem_integrated_B.T_AftIntvStart_gady =
        VsMPFU_DataBus.lane_markers[i].distance_to_host;
    }
  }

  /* End of MATLAB Function: '<S132>/MATLAB Function' */

  /* Gain: '<S132>/Gain' incorporates:
   *  Sum: '<S132>/Add'
   */
  LKAS_subsystem_integrated_B.Gain_kbew = 0.5F * (rtb_LeC2 + rtb_RiC2);

  /* UnitDelay: '<S135>/Unit Delay1' */
  rtb_LeC2 = LKAS_subsystem_integrated_DW.UnitDelay1_DSTATE_mdry;

  /* Product: '<S135>/Product2' incorporates:
   *  Constant: '<S135>/Constant1'
   *  Product: '<S135>/Product4'
   *  Switch: '<S135>/Switch'
   *  Switch: '<S135>/Switch1'
   */
  rtb_RiC2_tmp = 0.9F * rtb_LeC2;

  /* Gain: '<S135>/Gain1' incorporates:
   *  Gain: '<S136>/Gain1'
   *  Inport: '<Root>/EGMO_DataBus'
   */
  rtb_RiC2_tmp_0 = 0.01F * VsEGMO_DataBus.motion.velocity_rel.y;

  /* Sum: '<S135>/Add' incorporates:
   *  Constant: '<S135>/Constant'
   *  Gain: '<S135>/Gain'
   *  Gain: '<S135>/Gain1'
   *  Inport: '<Root>/EGMO_DataBus'
   *  Product: '<S135>/Product'
   *  Product: '<S135>/Product1'
   *  Product: '<S135>/Product2'
   *  Sum: '<S135>/Subtract'
   */
  rtb_RiC2 = (0.1F * ((rtb_LeC2 - (LKAS_subsystem_integrated_B.LeC1 * (0.01F *
    VsEGMO_DataBus.motion.velocity_rel.x))) - rtb_RiC2_tmp_0)) + rtb_RiC2_tmp;

  /* Switch: '<S135>/Switch1' */
  if (LKAS_subsystem_integrated_B.IsIntvCompleted_sLKA_a1kj)
  {
    /* Switch: '<S135>/Switch' incorporates:
     *  Constant: '<S135>/Constant2'
     *  Product: '<S135>/Product3'
     *  RelationalOperator: '<S135>/Relational Operator'
     *  Sum: '<S135>/Add1'
     *  UnitDelay: '<S135>/Unit Delay'
     */
    if (rtb_LeC0 == LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_p2ix)
    {
      LKAS_subsystem_integrated_B.Switch1_bjf2 = rtb_RiC2;
    }
    else
    {
      LKAS_subsystem_integrated_B.Switch1_bjf2 = (0.1F * rtb_LeC0) +
        rtb_RiC2_tmp;
    }
  }
  else
  {
    LKAS_subsystem_integrated_B.Switch1_bjf2 = rtb_RiC2;
  }

  /* Sum: '<S136>/Add' incorporates:
   *  Constant: '<S136>/Constant'
   *  Constant: '<S136>/Constant1'
   *  Gain: '<S136>/Gain'
   *  Inport: '<Root>/EGMO_DataBus'
   *  Product: '<S136>/Product'
   *  Product: '<S136>/Product1'
   *  Product: '<S136>/Product2'
   *  Sum: '<S136>/Subtract'
   *  UnitDelay: '<S136>/Unit Delay1'
   */
  rtb_RiC2 = (0.1F * ((LKAS_subsystem_integrated_B.Switch1 -
                       (LKAS_subsystem_integrated_B.RiC1 * (0.01F *
    VsEGMO_DataBus.motion.velocity_rel.x))) - rtb_RiC2_tmp_0)) + (0.9F *
    LKAS_subsystem_integrated_B.Switch1);

  /* Switch: '<S136>/Switch1' */
  if (LKAS_subsystem_integrated_B.LogicalOperator1)
  {
    /* Switch: '<S136>/Switch' incorporates:
     *  Constant: '<S136>/Constant2'
     *  Constant: '<S136>/Constant3'
     *  Product: '<S136>/Product3'
     *  Product: '<S136>/Product4'
     *  RelationalOperator: '<S136>/Relational Operator'
     *  Sum: '<S136>/Add1'
     *  UnitDelay: '<S136>/Unit Delay'
     *  UnitDelay: '<S136>/Unit Delay1'
     */
    if (rtb_RiC0 == LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_atjb)
    {
      LKAS_subsystem_integrated_B.Switch1 = rtb_RiC2;
    }
    else
    {
      LKAS_subsystem_integrated_B.Switch1 = (0.1F * rtb_RiC0) + (0.9F *
        LKAS_subsystem_integrated_B.Switch1);
    }

    /* End of Switch: '<S136>/Switch' */
  }
  else
  {
    LKAS_subsystem_integrated_B.Switch1 = rtb_RiC2;
  }

  /* End of Switch: '<S136>/Switch1' */

  /* Update for UnitDelay: '<S135>/Unit Delay1' */
  LKAS_subsystem_integrated_DW.UnitDelay1_DSTATE_mdry =
    LKAS_subsystem_integrated_B.Switch1_bjf2;

  /* Update for UnitDelay: '<S135>/Unit Delay' */
  LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_p2ix = rtb_LeC0;

  /* Update for UnitDelay: '<S136>/Unit Delay' */
  LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_atjb = rtb_RiC0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
