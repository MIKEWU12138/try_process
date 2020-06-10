/*
 * File: Road_Enable_Estimator_LDW.c
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

#include "Road_Enable_Estimator_LDW.h"

/* Include model header file for global data */
#include "LDWS_subsystem_integrated.h"
#include "LDWS_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S1>/Road_Enable_Estimator_LDW' */
void LDWS__Road_Enable_Estimator_LDW(void)
{
  boolean_T rtb_LogicalOperator3_kuwe;
  uint16_T rtb_CurrentTick;
  uint16_T rtb_CurrentTick_n1o5;

  /* Logic: '<S30>/Logical Operator2' incorporates:
   *  Constant: '<S30>/Constant2'
   *  RelationalOperator: '<S30>/Relational Operator'
   */
  rtb_LogicalOperator3_kuwe = ((LDWS_subsystem_integrated_B.Switch1) &&
    (LDWS_subsystem_integrated_B.LeQlt >= KfLDWS_r_LaMkrQlt));

  /* Switch: '<S32>/Switch1' incorporates:
   *  Constant: '<S32>/Constant4'
   *  Logic: '<S30>/Logical Operator'
   */
  if (!rtb_LogicalOperator3_kuwe)
  {
    /* Sum: '<S32>/Sum' incorporates:
     *  Constant: '<S30>/Constant9'
     *  UnitDelay: '<S32>/UnitDelay'
     */
    rtb_CurrentTick = (uint16_T)(((uint32_T)
      LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_fakt) + ((uint32_T)
      KcLDWS_CntSample));

    /* Saturate: '<S32>/Saturation' */
    if (rtb_CurrentTick < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S32>/Saturation' */
  }
  else
  {
    rtb_CurrentTick = ((uint16_T)0U);
  }

  /* End of Switch: '<S32>/Switch1' */

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Constant'
   *  Logic: '<S30>/Logical Operator1'
   *  RelationalOperator: '<S32>/RelationalOperator1'
   */
  if (rtb_LogicalOperator3_kuwe)
  {
    VbLDWS_RdEnblLe = true;
  }
  else
  {
    VbLDWS_RdEnblLe = !(rtb_CurrentTick > KfLDWS_t_LnMkrMissThrsh);
  }

  /* End of Switch: '<S30>/Switch' */

  /* Logic: '<S31>/Logical Operator3' incorporates:
   *  Constant: '<S31>/Constant2'
   *  RelationalOperator: '<S31>/Relational Operator'
   */
  rtb_LogicalOperator3_kuwe = ((LDWS_subsystem_integrated_B.Switch) &&
    (LDWS_subsystem_integrated_B.LeQlt >= KfLDWS_r_LaMkrQlt));

  /* Switch: '<S33>/Switch1' incorporates:
   *  Constant: '<S33>/Constant4'
   *  Logic: '<S31>/Logical Operator1'
   */
  if (!rtb_LogicalOperator3_kuwe)
  {
    /* Sum: '<S33>/Sum' incorporates:
     *  Constant: '<S31>/Constant9'
     *  UnitDelay: '<S33>/UnitDelay'
     */
    rtb_CurrentTick_n1o5 = (uint16_T)(((uint32_T)
      LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_fwdu) + ((uint32_T)
      KcLDWS_CntSample));

    /* Saturate: '<S33>/Saturation' */
    if (rtb_CurrentTick_n1o5 < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick_n1o5 = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S33>/Saturation' */
  }
  else
  {
    rtb_CurrentTick_n1o5 = ((uint16_T)0U);
  }

  /* End of Switch: '<S33>/Switch1' */

  /* Switch: '<S31>/Switch1' incorporates:
   *  Constant: '<S31>/Constant'
   *  Logic: '<S31>/Logical Operator2'
   *  RelationalOperator: '<S33>/RelationalOperator1'
   */
  if (rtb_LogicalOperator3_kuwe)
  {
    VbLDWS_RdEnblRi = true;
  }
  else
  {
    VbLDWS_RdEnblRi = !(rtb_CurrentTick_n1o5 > KfLDWS_t_LnMkrMissThrsh);
  }

  /* End of Switch: '<S31>/Switch1' */

  /* Update for UnitDelay: '<S32>/UnitDelay' */
  LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_fakt = rtb_CurrentTick;

  /* Update for UnitDelay: '<S33>/UnitDelay' */
  LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_fwdu = rtb_CurrentTick_n1o5;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
