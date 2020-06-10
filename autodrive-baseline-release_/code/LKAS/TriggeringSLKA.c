/*
 * File: TriggeringSLKA.c
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

#include "TriggeringSLKA.h"

/* Include model header file for global data */
#include "LKAS_subsystem_integrated.h"
#include "LKAS_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S4>/TriggeringSLKA' */
void LKAS_subsystem_i_TriggeringSLKA(void)
{
  boolean_T rtb_Switch_jawi;
  uint16_T rtb_CurrentTick;
  real32_T tmp;

  /* Outputs for Atomic SubSystem: '<S124>/LnMkrFilter_LKA' */
  LKAS_subsystem__LnMkrFilter_LKA();

  /* End of Outputs for SubSystem: '<S124>/LnMkrFilter_LKA' */

  /* Outputs for Atomic SubSystem: '<S124>/Road_Enable_Estimator_LKA' */
  LKAS__Road_Enable_Estimator_LKA();

  /* End of Outputs for SubSystem: '<S124>/Road_Enable_Estimator_LKA' */

  /* Outputs for Atomic SubSystem: '<S124>/TriggerManager_LKA' */
  LKAS_subsyst_TriggerManager_LKA();

  /* End of Outputs for SubSystem: '<S124>/TriggerManager_LKA' */

  /* Logic: '<S124>/Logical Operator4' */
  VbLKAS_IsLDWSTriggered =
    ((LKAS_subsystem_integrated_B.IsIntvCompleted_sLKA_a1kj) ||
     (LKAS_subsystem_integrated_B.LogicalOperator1));

  /* RelationalOperator: '<S117>/Relational Operator' incorporates:
   *  Abs: '<S117>/Abs'
   *  Constant: '<S117>/Constant'
   */
  VbLKAS_IsPathAccPlausible = (((real32_T)fabs((real_T)
    LKAS_subsystem_integrated_B.TrajData.LatAccNeeded_sLKA)) <
    KfLKAS_a_AMaxInPathToTrig_sLKA);

  /* Logic: '<S120>/Logical Operator1' incorporates:
   *  Abs: '<S120>/Abs'
   *  Constant: '<S120>/Constant'
   *  Constant: '<S120>/Constant1'
   *  Logic: '<S120>/Logical Operator'
   *  RelationalOperator: '<S120>/Relational Operator'
   *  RelationalOperator: '<S120>/Relational Operator1'
   */
  VbLKAS_IsTrajInTrigZone = ((((real32_T)fabs((real_T)
    LKAS_subsystem_integrated_B.TrajData.JerkNeeded_sLkA)) <
    KfLKAS_j_MaxTrigJerk_sLKA) &&
    ((LKAS_subsystem_integrated_B.TrajData.TrajectoryFound_sLKA) &&
     (LKAS_subsystem_integrated_B.TrajData.TimeNeeded_sLKA <
      KfLKAS_t_TMaxNeeded_sLKA)));

  /* SignalConversion: '<S13>/Signal Conversion' */
  VbLKAS_IsTrajectoryFound =
    LKAS_subsystem_integrated_B.TrajData.TrajectoryFound_sLKA;

  /* Switch: '<S122>/Switch' incorporates:
   *  Abs: '<S122>/Abs'
   *  Abs: '<S122>/Abs1'
   *  Constant: '<S130>/Constant'
   *  RelationalOperator: '<S122>/Relational Operator'
   */
  if (LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.IntvSideReq_sLKA ==
      LKAS_IntvSideLe)
  {
    tmp = (real32_T)fabs((real_T)LKAS_subsystem_integrated_B.Out_kbqr);
  }
  else
  {
    tmp = (real32_T)fabs((real_T)LKAS_subsystem_integrated_B.Out_kpwb);
  }

  /* End of Switch: '<S122>/Switch' */

  /* RelationalOperator: '<S122>/Relational Operator1' incorporates:
   *  Constant: '<S122>/Constant'
   */
  VbLKAS_IsVlatOkForZeroPath = (tmp < KfLKAS_v_VMaxToTrigZeroPath_sLKA);

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/Constant'
   *  Logic: '<S13>/Logical Operator1'
   *  Switch: '<S13>/Switch1'
   */
  if (LKAS_subsystem_integrated_B.TrajData.ZeroTrajectoryFound_sLKA)
  {
    rtb_Switch_jawi = VbLKAS_IsVlatOkForZeroPath;
  }
  else
  {
    if (KbLKAS_TriggerLDWSwitch)
    {
      /* Switch: '<S13>/Switch1' */
      rtb_Switch_jawi = VbLKAS_IsLDWSTriggered;
    }
    else
    {
      /* Switch: '<S13>/Switch1' */
      rtb_Switch_jawi = LKAS_subsystem_integrate_ConstB.LogicalOperator2;
    }

    rtb_Switch_jawi = (((VbLKAS_IsPathAccPlausible && VbLKAS_IsTrajectoryFound) &&
                        VbLKAS_IsTrajInTrigZone) && rtb_Switch_jawi);
  }

  /* End of Switch: '<S13>/Switch' */

  /* Logic: '<S118>/Logical Operator2' incorporates:
   *  Constant: '<S126>/Constant'
   *  Constant: '<S127>/Constant'
   *  Logic: '<S118>/Logical Operator'
   *  Logic: '<S118>/Logical Operator1'
   *  RelationalOperator: '<S118>/Relational Operator'
   *  RelationalOperator: '<S118>/Relational Operator1'
   */
  VbLKAS_IsTrackingIntvSide = (((LKAS_subsystem_integrated_B.Out_kk4i) &&
    (LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.IntvSideReq_sLKA ==
     LKAS_IntvSideLe)) ||
    ((LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.IntvSideReq_sLKA ==
      LKAS_IntvSideRi) && (LKAS_subsystem_integrated_B.Out_ezky)));

  /* MultiPortSwitch: '<S121>/Multiport Switch' incorporates:
   *  Constant: '<S121>/Constant'
   *  Constant: '<S128>/Constant'
   *  Constant: '<S129>/Constant'
   *  RelationalOperator: '<S128>/Compare'
   *  RelationalOperator: '<S129>/Compare'
   */
  switch (LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.IntvSideReq_sLKA)
  {
   case LKAS_IntvSideLe:
    VbLKAS_IsVlatTowardsIntvSide =
      (LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.Vlat_sLKA > 0.0F);
    break;

   case LKAS_IntvSideRi:
    VbLKAS_IsVlatTowardsIntvSide =
      (LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.Vlat_sLKA < 0.0F);
    break;

   default:
    VbLKAS_IsVlatTowardsIntvSide = false;
    break;
  }

  /* End of MultiPortSwitch: '<S121>/Multiport Switch' */

  /* Switch: '<S131>/Switch1' incorporates:
   *  Constant: '<S131>/Constant4'
   *  Logic: '<S13>/Logical Operator'
   *  Logic: '<S13>/Logical Operator3'
   */
  if ((((LKAS_subsystem_integrate_ConstB.Enabled_sLKA) &&
        VbLKAS_IsTrackingIntvSide) && VbLKAS_IsVlatTowardsIntvSide) &&
      rtb_Switch_jawi)
  {
    /* Sum: '<S131>/Sum' incorporates:
     *  Constant: '<S123>/Constant'
     *  UnitDelay: '<S131>/UnitDelay'
     */
    rtb_CurrentTick = (uint16_T)(((uint32_T)
      LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_euv0) + ((uint32_T)
      KcLKAS_CntSample));

    /* Saturate: '<S131>/Saturation' */
    if (rtb_CurrentTick < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S131>/Saturation' */
  }
  else
  {
    rtb_CurrentTick = ((uint16_T)0U);
  }

  /* End of Switch: '<S131>/Switch1' */

  /* RelationalOperator: '<S131>/RelationalOperator1' incorporates:
   *  Constant: '<S123>/Constant1'
   */
  VbLKAS_IsActivated_sLKA = (rtb_CurrentTick > KfLKAS_t_TDelayForAct_sLKA);

  /* Update for UnitDelay: '<S131>/UnitDelay' */
  LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_euv0 = rtb_CurrentTick;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
