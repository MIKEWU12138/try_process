/*
 * File: LnMkrFilter_LDW.c
 *
 * Code generated for Simulink model 'LDWS_subsystem_integrated'.
 *
 * Model version                  : 1.384
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 11:19:43 2020
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

#include "LnMkrFilter_LDW.h"

/* Include model header file for global data */
#include "LDWS_subsystem_integrated.h"
#include "LDWS_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S1>/LnMkrFilter_LDW' */
void LDWS_subsystem__LnMkrFilter_LDW(void)
{
  int32_T i;
  real32_T rtb_LeC2;
  real32_T rtb_RiC2;
  real32_T rtb_LeC0;
  real32_T rtb_RiC0;
  uint8_T rtb_RiQlt;

  /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
   *  Inport: '<Root>/MPFU_DataBus'
   */
  LDWS_subsystem_integrated_B.Switch1 = false;
  LDWS_subsystem_integrated_B.LeQlt = 0U;
  rtb_LeC0 = 0.0F;
  VfLDWS_LeC1Filtd = 0.0F;
  rtb_LeC2 = 0.0F;
  VfLDWS_BackToLeDist = 0.0F;
  LDWS_subsystem_integrated_B.Switch = false;
  rtb_RiQlt = 0U;
  rtb_RiC0 = 0.0F;
  VfLDWS_RiC1Filtd = 0.0F;
  rtb_RiC2 = 0.0F;
  LDWS_subsystem_integrated_B.RiDist = 0.0F;
  for (i = 0; i < 16; i++)
  {
    if (VsMPFU_DataBus.lane_markers[i].id == 1)
    {
      LDWS_subsystem_integrated_B.Switch1 = true;
      LDWS_subsystem_integrated_B.LeQlt = VsMPFU_DataBus.lane_markers[i].quality;
      rtb_LeC0 = VsMPFU_DataBus.lane_markers[i].c0_position;
      VfLDWS_LeC1Filtd = VsMPFU_DataBus.lane_markers[i].c1_heading;
      rtb_LeC2 = VsMPFU_DataBus.lane_markers[i].c2_curvature;
      VfLDWS_BackToLeDist = VsMPFU_DataBus.lane_markers[i].distance_to_host;
    }
  }

  for (i = 0; i < 16; i++)
  {
    if (VsMPFU_DataBus.lane_markers[i].id == 2)
    {
      LDWS_subsystem_integrated_B.Switch = true;
      rtb_RiQlt = VsMPFU_DataBus.lane_markers[i].quality;
      rtb_RiC0 = VsMPFU_DataBus.lane_markers[i].c0_position;
      VfLDWS_RiC1Filtd = VsMPFU_DataBus.lane_markers[i].c1_heading;
      rtb_RiC2 = VsMPFU_DataBus.lane_markers[i].c2_curvature;
      LDWS_subsystem_integrated_B.RiDist = VsMPFU_DataBus.lane_markers[i].
        distance_to_host;
    }
  }

  /* End of MATLAB Function: '<S4>/MATLAB Function' */

  /* Gain: '<S4>/Gain' incorporates:
   *  Gain: '<S4>/Gain1'
   *  Gain: '<S4>/Gain2'
   *  Sum: '<S4>/Add'
   */
  VfLDWS_Curvature = 0.5F * ((2.0F * rtb_LeC2) + (2.0F * rtb_RiC2));

  /* Gain: '<S23>/Gain1' incorporates:
   *  Gain: '<S24>/Gain1'
   *  Inport: '<Root>/EGMO_DataBus'
   */
  rtb_LeC2 = 0.01F * VsEGMO_DataBus.motion.velocity_rel.y;

  /* Sum: '<S23>/Add' incorporates:
   *  Constant: '<S23>/Constant'
   *  Constant: '<S23>/Constant1'
   *  Gain: '<S23>/Gain'
   *  Gain: '<S23>/Gain1'
   *  Inport: '<Root>/EGMO_DataBus'
   *  Product: '<S23>/Product'
   *  Product: '<S23>/Product1'
   *  Product: '<S23>/Product2'
   *  Sum: '<S23>/Subtract'
   *  UnitDelay: '<S23>/Unit Delay1'
   */
  rtb_RiC2 = (0.1F * ((VfLDWS_LeC0Filtd - (VfLDWS_LeC1Filtd * (0.01F *
    VsEGMO_DataBus.motion.velocity_rel.x))) - rtb_LeC2)) + (0.9F *
    VfLDWS_LeC0Filtd);

  /* Switch: '<S23>/Switch1' */
  if (LDWS_subsystem_integrated_B.Switch1)
  {
    /* Switch: '<S23>/Switch' incorporates:
     *  Constant: '<S23>/Constant2'
     *  Constant: '<S23>/Constant3'
     *  Product: '<S23>/Product3'
     *  Product: '<S23>/Product4'
     *  RelationalOperator: '<S23>/Relational Operator'
     *  Sum: '<S23>/Add1'
     *  UnitDelay: '<S23>/Unit Delay'
     *  UnitDelay: '<S23>/Unit Delay1'
     */
    if (rtb_LeC0 == LDWS_subsystem_integrated_DW.UnitDelay_DSTATE)
    {
      VfLDWS_LeC0Filtd = rtb_RiC2;
    }
    else
    {
      VfLDWS_LeC0Filtd = (0.1F * rtb_LeC0) + (0.9F * VfLDWS_LeC0Filtd);
    }

    /* End of Switch: '<S23>/Switch' */
  }
  else
  {
    VfLDWS_LeC0Filtd = rtb_RiC2;
  }

  /* End of Switch: '<S23>/Switch1' */

  /* Sum: '<S24>/Add' incorporates:
   *  Constant: '<S24>/Constant'
   *  Constant: '<S24>/Constant1'
   *  Gain: '<S24>/Gain'
   *  Inport: '<Root>/EGMO_DataBus'
   *  Product: '<S24>/Product'
   *  Product: '<S24>/Product1'
   *  Product: '<S24>/Product2'
   *  Sum: '<S24>/Subtract'
   *  UnitDelay: '<S24>/Unit Delay1'
   */
  rtb_RiC2 = (0.1F * ((VfLDWS_RiC0Filtd - (VfLDWS_RiC1Filtd * (0.01F *
    VsEGMO_DataBus.motion.velocity_rel.x))) - rtb_LeC2)) + (0.9F *
    VfLDWS_RiC0Filtd);

  /* Switch: '<S24>/Switch1' */
  if (LDWS_subsystem_integrated_B.Switch)
  {
    /* Switch: '<S24>/Switch' incorporates:
     *  Constant: '<S24>/Constant2'
     *  Constant: '<S24>/Constant3'
     *  Product: '<S24>/Product3'
     *  Product: '<S24>/Product4'
     *  RelationalOperator: '<S24>/Relational Operator'
     *  Sum: '<S24>/Add1'
     *  UnitDelay: '<S24>/Unit Delay'
     *  UnitDelay: '<S24>/Unit Delay1'
     */
    if (rtb_RiC0 == LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_jze2)
    {
      VfLDWS_RiC0Filtd = rtb_RiC2;
    }
    else
    {
      VfLDWS_RiC0Filtd = (0.1F * rtb_RiC0) + (0.9F * VfLDWS_RiC0Filtd);
    }

    /* End of Switch: '<S24>/Switch' */
  }
  else
  {
    VfLDWS_RiC0Filtd = rtb_RiC2;
  }

  /* End of Switch: '<S24>/Switch1' */

  /* Update for UnitDelay: '<S23>/Unit Delay' */
  LDWS_subsystem_integrated_DW.UnitDelay_DSTATE = rtb_LeC0;

  /* Update for UnitDelay: '<S24>/Unit Delay' */
  LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_jze2 = rtb_RiC0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
