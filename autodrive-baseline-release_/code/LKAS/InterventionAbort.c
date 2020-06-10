/*
 * File: InterventionAbort.c
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

#include "InterventionAbort.h"

/* Include model header file for global data */
#include "LKAS_subsystem_integrated.h"
#include "LKAS_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S4>/InterventionAbort' */
void LKAS_subsyste_InterventionAbort(void)
{
  boolean_T rtb_LogicalOperator2_a3ru;
  boolean_T rtb_LogicalOperator2_lozd;
  boolean_T rtb_LogicalOperator5;
  boolean_T rtb_MultiportSwitch;
  uint16_T rtb_CurrentTick;

  /* Logic: '<S71>/Logical Operator2' incorporates:
   *  Constant: '<S79>/Constant'
   *  Constant: '<S80>/Constant'
   *  Logic: '<S71>/Logical Operator'
   *  Logic: '<S71>/Logical Operator1'
   *  RelationalOperator: '<S71>/Relational Operator'
   *  RelationalOperator: '<S71>/Relational Operator1'
   */
  rtb_LogicalOperator2_a3ru = (((LKAS_subsystem_integrated_B.IntvSide_sLKA_k4lx ==
    LKAS_IntvSideLe) && (LKAS_subsystem_integrated_B.LogicalOperator1)) ||
    ((LKAS_subsystem_integrated_B.IsIntvCompleted_sLKA_a1kj) &&
     (LKAS_subsystem_integrated_B.IntvSide_sLKA_k4lx == LKAS_IntvSideRi)));

  /* Logic: '<S72>/Logical Operator2' incorporates:
   *  Constant: '<S81>/Constant'
   *  Constant: '<S82>/Constant'
   *  Inport: '<Root>/COMM_CANR_Databus'
   *  Logic: '<S72>/Logical Operator'
   *  Logic: '<S72>/Logical Operator1'
   *  RelationalOperator: '<S72>/Relational Operator'
   *  RelationalOperator: '<S72>/Relational Operator1'
   */
  rtb_LogicalOperator2_lozd = (((LKAS_subsystem_integrated_B.IntvSide_sLKA_k4lx ==
    LKAS_IntvSideLe) &&
    (VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState)) ||
    ((VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState) &&
     (LKAS_subsystem_integrated_B.IntvSide_sLKA_k4lx == LKAS_IntvSideRi)));

  /* Logic: '<S74>/Logical Operator5' incorporates:
   *  Constant: '<S83>/Constant'
   *  Constant: '<S84>/Constant'
   *  Logic: '<S74>/Logical Operator1'
   *  Logic: '<S74>/Logical Operator2'
   *  Logic: '<S74>/Logical Operator3'
   *  Logic: '<S74>/Logical Operator4'
   *  RelationalOperator: '<S74>/Relational Operator'
   *  RelationalOperator: '<S74>/Relational Operator1'
   */
  rtb_LogicalOperator5 = (((LKAS_IntvSideLe ==
    LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.IntvSideReq_sLKA) &&
    (!LKAS_subsystem_integrated_B.Out_kk4i)) ||
    ((!LKAS_subsystem_integrated_B.Out_ezky) && (LKAS_IntvSideRi ==
    LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.IntvSideReq_sLKA)));

  /* MultiPortSwitch: '<S76>/Multiport Switch' incorporates:
   *  Constant: '<S76>/Constant'
   *  Constant: '<S76>/Constant1'
   *  RelationalOperator: '<S76>/Relational Operator'
   */
  if (((uint32_T)LKAS_subsystem_integrated_B.IntvTyp_sLKA_pzex) ==
      LKAS_SftyLaneKeepAid)
  {
    rtb_MultiportSwitch = (LKAS_subsystem_integrated_B.T_AftIntvStart >
      KfLKAS_t_MaxIntvTime);
  }
  else
  {
    rtb_MultiportSwitch = false;
  }

  /* End of MultiPortSwitch: '<S76>/Multiport Switch' */

  /* Logic: '<S77>/Logical Operator' */
  VbLKAS_IsAbortIntv = ((((rtb_LogicalOperator2_lozd || rtb_LogicalOperator5) ||
    (LKAS_subsystem_integrate_ConstB.LogicalOperator)) ||
    rtb_LogicalOperator2_a3ru) || rtb_MultiportSwitch);

  /* Switch: '<S77>/Switch' incorporates:
   *  Constant: '<S77>/Constant'
   *  Constant: '<S77>/Constant1'
   *  SignalConversion: '<S77>/Signal Conversion'
   */
  if (KbLKAS_AbortSwitch_Temp)
  {
    LKAS_subsystem_integrated_B.Switch_j4bm = false;
  }
  else
  {
    LKAS_subsystem_integrated_B.Switch_j4bm = VbLKAS_IsAbortIntv;
  }

  /* End of Switch: '<S77>/Switch' */

  /* Switch: '<S86>/Switch1' incorporates:
   *  Constant: '<S86>/Constant'
   */
  if (LKAS_subsystem_integrated_B.Switch_j4bm)
  {
    rtb_CurrentTick = ((uint16_T)0U);
  }
  else
  {
    /* Sum: '<S86>/Sum' incorporates:
     *  Constant: '<S78>/Constant'
     *  UnitDelay: '<S86>/UnitDelay'
     */
    rtb_CurrentTick = (uint16_T)(((uint32_T)KcLKAS_CntSample) + ((uint32_T)
      LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_de5t));

    /* Saturate: '<S86>/Saturation' */
    if (rtb_CurrentTick < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S86>/Saturation' */
  }

  /* End of Switch: '<S86>/Switch1' */

  /* Logic: '<S86>/Logical Operator' incorporates:
   *  Constant: '<S78>/Constant1'
   *  RelationalOperator: '<S86>/RelationalOperator1'
   */
  VbLKAS_IsDelayAftAbort = !(rtb_CurrentTick > KfLKAS_t_TimeDlyAbort);

  /* Sum: '<S85>/Add' incorporates:
   *  Gain: '<S85>/Gain'
   *  Gain: '<S85>/Gain2'
   *  Gain: '<S85>/Gain3'
   */
  VfLKAS_AbortID = (uint8_T)((((((((uint32_T)(rtb_LogicalOperator2_lozd ? 1U :
    0U)) << 6) + ((uint32_T)((int32_T)(rtb_LogicalOperator5 ? ((int32_T)
    ((uint8_T)128U)) : 0)))) + (((uint32_T)LKAS_subsystem_integrate_ConstB.Gain1)
    << 1)) + (((uint32_T)((int32_T)(rtb_LogicalOperator2_a3ru ? ((int32_T)
    ((uint8_T)128U)) : 0))) << 2)) + (((uint32_T)((int32_T)(rtb_MultiportSwitch ?
    ((int32_T)((uint8_T)128U)) : 0))) << 3)) >> 6);

  /* Update for UnitDelay: '<S86>/UnitDelay' */
  LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_de5t = rtb_CurrentTick;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
