/*
 * File: InterventionCompletion.c
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

#include "InterventionCompletion.h"

/* Include model header file for global data */
#include "LKAS_subsystem_integrated.h"
#include "LKAS_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S4>/InterventionCompletion' */
void LKAS_sub_InterventionCompletion(void)
{
  boolean_T rtb_RelationalOperator;
  uint16_T rtb_CurrentTick;
  real32_T rtb_Switch_mwmn;
  boolean_T tmp;

  /* MultiPortSwitch: '<S90>/Multiport Switch' incorporates:
   *  Constant: '<S90>/Constant'
   */
  switch (LKAS_subsystem_integrated_B.CtrlRef_sLKA_jpit)
  {
   case LKAS_LaneMkrToClsLe:
    rtb_Switch_mwmn = LKAS_subsystem_integrated_B.Out_hpcs;
    break;

   case LKAS_LaneMkrToClsRi:
    rtb_Switch_mwmn = LKAS_subsystem_integrated_B.Out_mwpy;
    break;

   default:
    rtb_Switch_mwmn = 0.0F;
    break;
  }

  /* End of MultiPortSwitch: '<S90>/Multiport Switch' */

  /* RelationalOperator: '<S90>/Relational Operator' incorporates:
   *  Constant: '<S98>/Constant'
   */
  rtb_RelationalOperator = (LKAS_subsystem_integrated_B.IntvSide_sLKA ==
    LKAS_IntvSideLe);

  /* Switch: '<S90>/Switch' incorporates:
   *  Gain: '<S90>/Gain'
   *  Sum: '<S90>/Add'
   */
  if (rtb_RelationalOperator)
  {
    rtb_Switch_mwmn -= VfLKAS_DesiredDistToEdge;
  }
  else
  {
    rtb_Switch_mwmn = (-1.0F) * (rtb_Switch_mwmn - VfLKAS_DesiredDistToEdge);
  }

  /* End of Switch: '<S90>/Switch' */

  /* Switch: '<S90>/Switch3' incorporates:
   *  Constant: '<S90>/Constant1'
   *  Switch: '<S90>/Switch2'
   */
  if (KbLKAS_NotUseOffstForCmpl_Temp)
  {
    /* Switch: '<S90>/Switch1' incorporates:
     *  Constant: '<S100>/Constant'
     *  Constant: '<S101>/Constant'
     *  Constant: '<S102>/Constant'
     *  Constant: '<S99>/Constant'
     *  Gain: '<S90>/Gain1'
     *  Logic: '<S97>/Logical Operator'
     *  Logic: '<S97>/Logical Operator1'
     *  Logic: '<S97>/Logical Operator2'
     *  RelationalOperator: '<S97>/Relational Operator'
     *  RelationalOperator: '<S97>/Relational Operator1'
     *  RelationalOperator: '<S97>/Relational Operator2'
     *  RelationalOperator: '<S97>/Relational Operator3'
     */
    if (((LKAS_subsystem_integrated_B.IntvSide_sLKA == LKAS_IntvSideLe) &&
         (LKAS_subsystem_integrated_B.CtrlRef_sLKA_jpit == LKAS_LaneMkrToClsRi))
        || ((LKAS_subsystem_integrated_B.IntvSide_sLKA == LKAS_IntvSideRi) &&
            (LKAS_subsystem_integrated_B.CtrlRef_sLKA_jpit ==
             LKAS_LaneMkrToClsRi)))
    {
      rtb_Switch_mwmn *= (-1.0F);
    }

    /* End of Switch: '<S90>/Switch1' */
  }
  else if (rtb_RelationalOperator)
  {
    /* Switch: '<S90>/Switch2' */
    rtb_Switch_mwmn = VfLKAS_OffstError;
  }
  else
  {
    /* Switch: '<S90>/Switch2' incorporates:
     *  Gain: '<S90>/Gain2'
     */
    rtb_Switch_mwmn = (-1.0F) * VfLKAS_OffstError;
  }

  /* End of Switch: '<S90>/Switch3' */

  /* RelationalOperator: '<S87>/Relational Operator' incorporates:
   *  Constant: '<S87>/Constant'
   */
  VbLKAS_IsInsidePath = (rtb_Switch_mwmn > 0.0F);

  /* MultiPortSwitch: '<S91>/Multiport Switch' incorporates:
   *  Constant: '<S91>/Constant'
   */
  switch (LKAS_subsystem_integrated_B.CtrlRef_sLKA_jpit)
  {
   case LKAS_LaneMkrToClsLe:
    rtb_Switch_mwmn = LKAS_subsystem_integrated_B.Out_kbqr;
    break;

   case LKAS_LaneMkrToClsRi:
    rtb_Switch_mwmn = LKAS_subsystem_integrated_B.Out_kpwb;
    break;

   default:
    rtb_Switch_mwmn = 0.0F;
    break;
  }

  /* End of MultiPortSwitch: '<S91>/Multiport Switch' */

  /* Switch: '<S92>/Switch' incorporates:
   *  Constant: '<S92>/Constant'
   *  Constant: '<S92>/Constant1'
   *  Gain: '<S92>/Gain'
   *  RelationalOperator: '<S92>/Relational Operator'
   *  RelationalOperator: '<S92>/Relational Operator1'
   */
  if (rtb_RelationalOperator)
  {
    VbLKAS_IsVlatTowardsLaneCenter = (rtb_Switch_mwmn < KfLKAS_v_VlatMinForCmpl);
  }
  else
  {
    VbLKAS_IsVlatTowardsLaneCenter = (rtb_Switch_mwmn > ((-1.0F) *
      KfLKAS_v_VlatMinForCmpl));
  }

  /* End of Switch: '<S92>/Switch' */

  /* Switch: '<S93>/Switch' incorporates:
   *  Constant: '<S93>/Constant'
   *  Constant: '<S93>/Constant1'
   *  RelationalOperator: '<S93>/Relational Operator'
   *  RelationalOperator: '<S93>/Relational Operator1'
   */
  if (rtb_RelationalOperator)
  {
    VbLKAS_IsVmaxReached = (rtb_Switch_mwmn < KfLKAS_v_VlatMaxForCmpl);
  }
  else
  {
    VbLKAS_IsVmaxReached = (rtb_Switch_mwmn > KfLKAS_v_VlatMaxForCmpl);
  }

  /* End of Switch: '<S93>/Switch' */

  /* Switch: '<S89>/Switch1' incorporates:
   *  Constant: '<S89>/Constant2'
   *  Constant: '<S89>/Constant3'
   */
  if (KbLKAS_UseInsidePathForCmpl_Temp)
  {
    rtb_RelationalOperator = VbLKAS_IsInsidePath;
  }
  else
  {
    rtb_RelationalOperator = true;
  }

  /* End of Switch: '<S89>/Switch1' */

  /* Switch: '<S89>/Switch' incorporates:
   *  Constant: '<S89>/Constant'
   *  Constant: '<S89>/Constant1'
   */
  if (KbLKAS_UseVmaxForCmpl_Temp)
  {
    tmp = VbLKAS_IsVmaxReached;
  }
  else
  {
    tmp = false;
  }

  /* End of Switch: '<S89>/Switch' */

  /* Switch: '<S96>/Switch1' incorporates:
   *  Constant: '<S96>/Constant4'
   *  Logic: '<S89>/Logical Operator1'
   *  Logic: '<S89>/Logical Operator2'
   */
  if ((VbLKAS_IsVlatTowardsLaneCenter && rtb_RelationalOperator) || tmp)
  {
    /* Sum: '<S96>/Sum' incorporates:
     *  Constant: '<S95>/Constant'
     *  UnitDelay: '<S96>/UnitDelay'
     */
    rtb_CurrentTick = (uint16_T)(((uint32_T)
      LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_cghd) + ((uint32_T)
      KcLKAS_CntSample));

    /* Saturate: '<S96>/Saturation' */
    if (rtb_CurrentTick < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S96>/Saturation' */
  }
  else
  {
    rtb_CurrentTick = ((uint16_T)0U);
  }

  /* End of Switch: '<S96>/Switch1' */

  /* RelationalOperator: '<S96>/RelationalOperator1' incorporates:
   *  Constant: '<S95>/Constant1'
   */
  VbLKAS_IsIntvCompleted = (rtb_CurrentTick > KfLKAS_t_TDelayForCmpl_sLKA);

  /* Update for UnitDelay: '<S96>/UnitDelay' */
  LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_cghd = rtb_CurrentTick;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
