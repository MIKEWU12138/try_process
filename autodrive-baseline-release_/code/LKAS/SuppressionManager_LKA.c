/*
 * File: SuppressionManager_LKA.c
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

#include "SuppressionManager_LKA.h"

/* Include model header file for global data */
#include "LKAS_subsystem_integrated.h"
#include "LKAS_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S4>/SuppressionManager_LKA' */
void LKAS_sub_SuppressionManager_LKA(void)
{
  /* SignalConversion: '<S115>/Signal Conversion' incorporates:
   *  Constant: '<S113>/Constant'
   *  RelationalOperator: '<S12>/Relational Operator'
   */
  VbLKAS_LeftChangeLane =
    (LKAS_subsystem_integrated_B.VsDRIV_DataBus.OverrideSteer.VeDRIV_LeftChangeLane
     != LeftLC_NOT);

  /* SignalConversion: '<S115>/Signal Conversion1' */
  VbLKAS_InnerCurvLe = LKAS_subsystem_integrated_B.LogicalOperator1;

  /* SignalConversion: '<S115>/Signal Conversion2' incorporates:
   *  Logic: '<S115>/Logical Operator2'
   */
  VbLKAS_NotQualDrpLeft = !VbLKAS_QlyValidLe;

  /* SignalConversion: '<S115>/Signal Conversion3' */
  VbLKAS_DlyAftAbort = VbLKAS_IsDelayAftAbort;

  /* Logic: '<S115>/Logical Operator' */
  VbLKAS_IsSuppLe = (((VbLKAS_LeftChangeLane || VbLKAS_InnerCurvLe) ||
                      VbLKAS_NotQualDrpLeft) || VbLKAS_DlyAftAbort);

  /* Switch: '<S115>/Switch' incorporates:
   *  Constant: '<S115>/Constant'
   *  Constant: '<S115>/Constant2'
   */
  if (KbLKAS_SuppSwitch_Temp)
  {
    LKAS_subsystem_integrated_B.Switch = false;
  }
  else
  {
    LKAS_subsystem_integrated_B.Switch = VbLKAS_IsSuppLe;
  }

  /* End of Switch: '<S115>/Switch' */

  /* SignalConversion: '<S115>/Signal Conversion4' incorporates:
   *  Constant: '<S114>/Constant'
   *  RelationalOperator: '<S12>/Relational Operator1'
   */
  VbLKAS_RightChangeLane =
    (LKAS_subsystem_integrated_B.VsDRIV_DataBus.OverrideSteer.VeDRIV_RightChangeLane
     != RightLC_NOT);

  /* SignalConversion: '<S115>/Signal Conversion5' */
  VbLKAS_InnerCurvRi = LKAS_subsystem_integrated_B.IsIntvCompleted_sLKA_a1kj;

  /* SignalConversion: '<S115>/Signal Conversion6' incorporates:
   *  Logic: '<S115>/Logical Operator3'
   */
  VbLKAS_NotQualDrpRight = !VbLKAS_QlyValidRi;

  /* Logic: '<S115>/Logical Operator1' incorporates:
   *  SignalConversion: '<S115>/Signal Conversion7'
   */
  VbLKAS_IsSuppRi = (((VbLKAS_RightChangeLane || VbLKAS_InnerCurvRi) ||
                      VbLKAS_NotQualDrpRight) || VbLKAS_IsDelayAftAbort);

  /* Switch: '<S115>/Switch1' incorporates:
   *  Constant: '<S115>/Constant1'
   *  Constant: '<S115>/Constant3'
   */
  if (KbLKAS_SuppSwitch_Temp)
  {
    LKAS_subsystem_integrated_B.Switch1_bgwd = false;
  }
  else
  {
    LKAS_subsystem_integrated_B.Switch1_bgwd = VbLKAS_IsSuppRi;
  }

  /* End of Switch: '<S115>/Switch1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
