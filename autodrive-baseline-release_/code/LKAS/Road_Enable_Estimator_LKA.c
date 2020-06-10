/*
 * File: Road_Enable_Estimator_LKA.c
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

#include "Road_Enable_Estimator_LKA.h"

/* Include model header file for global data */
#include "LKAS_subsystem_integrated.h"
#include "LKAS_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S124>/Road_Enable_Estimator_LKA' */
void LKAS__Road_Enable_Estimator_LKA(void)
{
  boolean_T rtb_LogicalOperator3_np43;
  uint16_T rtb_CurrentTick;
  uint16_T rtb_CurrentTick_egcn;

  /* Logic: '<S138>/Logical Operator2' incorporates:
   *  Constant: '<S138>/KfLKAS_QlyVld'
   *  RelationalOperator: '<S138>/Relational Operator'
   *
   * Block description for '<S138>/KfLKAS_QlyVld':
   *  _V3p4.LDW2.000_394_
   */
  rtb_LogicalOperator3_np43 =
    ((LKAS_subsystem_integrated_B.IsIntvCompleted_sLKA_a1kj) &&
     (LKAS_subsystem_integrated_B.LeQlt >= KfLKAS_r_QlyVld));

  /* Switch: '<S140>/Switch1' incorporates:
   *  Constant: '<S140>/Constant4'
   *  Logic: '<S138>/Logical Operator'
   */
  if (!rtb_LogicalOperator3_np43)
  {
    /* Sum: '<S140>/Sum' incorporates:
     *  Constant: '<S138>/Constant9'
     *  UnitDelay: '<S140>/UnitDelay'
     */
    rtb_CurrentTick = (uint16_T)(((uint32_T)
      LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_evs3) + ((uint32_T)
      KcLKAS_CntSample));

    /* Saturate: '<S140>/Saturation' */
    if (rtb_CurrentTick < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S140>/Saturation' */
  }
  else
  {
    rtb_CurrentTick = ((uint16_T)0U);
  }

  /* End of Switch: '<S140>/Switch1' */

  /* Switch: '<S138>/Switch' incorporates:
   *  Constant: '<S138>/Constant'
   *  Logic: '<S138>/Logical Operator1'
   *  RelationalOperator: '<S140>/RelationalOperator1'
   */
  if (rtb_LogicalOperator3_np43)
  {
    LKAS_subsystem_integrated_B.IsIntvCompleted_sLKA_a1kj = true;
  }
  else
  {
    LKAS_subsystem_integrated_B.IsIntvCompleted_sLKA_a1kj = !(rtb_CurrentTick >
      KfLKAS_t_LnMkrMissThrsh);
  }

  /* End of Switch: '<S138>/Switch' */

  /* Logic: '<S139>/Logical Operator3' incorporates:
   *  Constant: '<S139>/KfLKAS_QlyVld'
   *  RelationalOperator: '<S139>/Relational Operator'
   *
   * Block description for '<S139>/KfLKAS_QlyVld':
   *  _V3p4.LDW2.000_394_
   */
  rtb_LogicalOperator3_np43 = ((LKAS_subsystem_integrated_B.LogicalOperator1) &&
    (LKAS_subsystem_integrated_B.LeQlt >= KfLKAS_r_QlyVld));

  /* Switch: '<S141>/Switch1' incorporates:
   *  Constant: '<S141>/Constant4'
   *  Logic: '<S139>/Logical Operator1'
   */
  if (!rtb_LogicalOperator3_np43)
  {
    /* Sum: '<S141>/Sum' incorporates:
     *  Constant: '<S139>/Constant9'
     *  UnitDelay: '<S141>/UnitDelay'
     */
    rtb_CurrentTick_egcn = (uint16_T)(((uint32_T)
      LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_exni) + ((uint32_T)
      KcLKAS_CntSample));

    /* Saturate: '<S141>/Saturation' */
    if (rtb_CurrentTick_egcn < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick_egcn = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S141>/Saturation' */
  }
  else
  {
    rtb_CurrentTick_egcn = ((uint16_T)0U);
  }

  /* End of Switch: '<S141>/Switch1' */

  /* Switch: '<S139>/Switch1' incorporates:
   *  Constant: '<S139>/Constant'
   *  Logic: '<S139>/Logical Operator2'
   *  RelationalOperator: '<S141>/RelationalOperator1'
   */
  if (rtb_LogicalOperator3_np43)
  {
    LKAS_subsystem_integrated_B.LogicalOperator1 = true;
  }
  else
  {
    LKAS_subsystem_integrated_B.LogicalOperator1 = !(rtb_CurrentTick_egcn >
      KfLKAS_t_LnMkrMissThrsh);
  }

  /* End of Switch: '<S139>/Switch1' */

  /* Update for UnitDelay: '<S140>/UnitDelay' */
  LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_evs3 = rtb_CurrentTick;

  /* Update for UnitDelay: '<S141>/UnitDelay' */
  LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_exni = rtb_CurrentTick_egcn;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
