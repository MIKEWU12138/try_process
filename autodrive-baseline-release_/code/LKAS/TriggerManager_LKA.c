/*
 * File: TriggerManager_LKA.c
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

#include "TriggerManager_LKA.h"

/* Include model header file for global data */
#include "LKAS_subsystem_integrated.h"
#include "LKAS_subsystem_integrated_private.h"

/*
 * Output and update for action system:
 *    '<S149>/If Action Subsystem6'
 *    '<S150>/If Action Subsystem6'
 */
void LKAS_subsyst_IfActionSubsystem6(real32_T rtu_In1, real32_T rtu_In2,
  real32_T *rty_Out1)
{
  /* Product: '<S154>/Product' */
  *rty_Out1 = rtu_In1 * rtu_In2;
}

/* Output and update for atomic system: '<S124>/TriggerManager_LKA' */
void LKAS_subsyst_TriggerManager_LKA(void)
{
  real32_T T_left;
  real32_T T_right;
  real32_T theta_right;
  real32_T theta_new_right;
  real32_T rtb_Abs;
  boolean_T rtb_Switch_dles;
  boolean_T rtb_Switch1_fphx;
  real32_T rtb_Add_p0q2;
  real32_T rtb_Add1_cdqo;
  real32_T rtb_SignalConversion2;
  real32_T rtb_Merge2;
  real32_T rtb_Merge1_mygh;
  real32_T rtb_Add1_nd0i;
  boolean_T rtb_Switch_myhq;
  real32_T theta_new_right_tmp;

  /* Abs: '<S134>/Abs' */
  rtb_Abs = (real32_T)fabs((real_T)
    LKAS_subsystem_integrated_B.T_AftIntvStart_gady);

  /* MATLAB Function: '<S147>/theta_calculation' */
  T_left = (real32_T)fabs((real_T)((real32_T)(LKAS_subsystem_integrated_B.Add3 /
    ((real32_T)fabs((real_T)LKAS_subsystem_integrated_B.Switch1_bjf2)))));
  if (T_left > 1.0F)
  {
    T_left = 1.0F / T_left;
  }

  T_left = (real32_T)acos((real_T)T_left);
  T_right = (real32_T)fabs((real_T)((real32_T)(rtb_Abs / ((real32_T)fabs((real_T)
    LKAS_subsystem_integrated_B.Switch1)))));
  if (T_right > 1.0F)
  {
    T_right = 1.0F / T_right;
  }

  theta_right = (real32_T)acos((real_T)T_right);
  T_right = (real32_T)fabs((real_T)((real32_T)atan((real_T)
    LKAS_subsystem_integrated_B.LeC1)));
  theta_new_right = (real32_T)fabs((real_T)((real32_T)atan((real_T)
    LKAS_subsystem_integrated_B.RiC1)));
  if ((LKAS_subsystem_integrated_B.LeC1 < 0.0F) &&
      (LKAS_subsystem_integrated_B.RiC1 < 0.0F))
  {
    T_left = (T_left + theta_right) / 2.0F;
    T_right = (T_right + theta_new_right) / 2.0F;
  }
  else if ((LKAS_subsystem_integrated_B.LeC1 > 0.0F) &&
           (LKAS_subsystem_integrated_B.RiC1 > 0.0F))
  {
    T_left = (-(T_left + theta_right)) / 2.0F;
    T_right = (-(T_right + theta_new_right)) / 2.0F;
  }
  else
  {
    T_left = 0.0F;
    T_right = 0.0F;
  }

  /* End of MATLAB Function: '<S147>/theta_calculation' */

  /* Switch: '<S147>/Switch' incorporates:
   *  Constant: '<S147>/Constant'
   */
  if (true)
  {
  }
  else
  {
    T_right = T_left;
  }

  /* End of Switch: '<S147>/Switch' */

  /* Product: '<S161>/Product' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   *  Product: '<S159>/Product'
   *  SignalConversion: '<S134>/Signal Conversion'
   *  Trigonometry: '<S161>/Sin'
   */
  theta_new_right = VsEGMO_DataBus.motion.velocity_rel.x * ((real32_T)sin
    ((real_T)T_right));

  /* Product: '<S161>/Product1' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   *  Product: '<S159>/Product1'
   *  SignalConversion: '<S134>/Signal Conversion1'
   *  Trigonometry: '<S161>/Cos'
   */
  theta_new_right_tmp = ((real32_T)cos((real_T)T_right)) *
    VsEGMO_DataBus.motion.velocity_rel.y;

  /* Sum: '<S161>/Add' incorporates:
   *  Product: '<S161>/Product'
   *  Product: '<S161>/Product1'
   */
  rtb_Add_p0q2 = theta_new_right + theta_new_right_tmp;

  /* If: '<S149>/If2' incorporates:
   *  Constant: '<S149>/Constant1'
   *  Constant: '<S149>/Constant2'
   *  Constant: '<S149>/Constant3'
   *  Inport: '<S152>/In1'
   *  Inport: '<S153>/In1'
   */
  if (rtb_Add_p0q2 > 1.0F)
  {
    /* Outputs for IfAction SubSystem: '<S149>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S152>/Action Port'
     */
    rtb_Merge2 = KfLKAS_d_WarnLineLvlOne;

    /* End of Outputs for SubSystem: '<S149>/If Action Subsystem4' */
  }
  else if (rtb_Add_p0q2 < 0.5F)
  {
    /* Outputs for IfAction SubSystem: '<S149>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S153>/Action Port'
     */
    rtb_Merge2 = KfLKAS_d_WarnLineLvlThree;

    /* End of Outputs for SubSystem: '<S149>/If Action Subsystem5' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S149>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S154>/Action Port'
     */
    LKAS_subsyst_IfActionSubsystem6(rtb_Add_p0q2, KfLKAS_r_WarnLineLvlTwo,
      &rtb_Merge2);

    /* End of Outputs for SubSystem: '<S149>/If Action Subsystem6' */
  }

  /* End of If: '<S149>/If2' */

  /* MATLAB Function: '<S167>/Left_Edge_Calculation' incorporates:
   *  Constant: '<S148>/Constant2'
   *  Constant: '<S148>/Constant3'
   */
  if (T_right > 0.0F)
  {
    theta_right = LKAS_subsystem_integrated_B.Add3 - (KfLKAS_d_BkToFrtCnrDist *
      ((real32_T)sin((real_T)((real32_T)(T_right + KfLKAS_Ang_BkToCnrAng)))));
  }
  else
  {
    theta_right = LKAS_subsystem_integrated_B.Add3 + (KfLKAS_d_BkToFrtCnrDist *
      ((real32_T)sin((real_T)((real32_T)(((real32_T)fabs((real_T)T_right)) -
      KfLKAS_Ang_BkToCnrAng)))));
  }

  /* End of MATLAB Function: '<S167>/Left_Edge_Calculation' */

  /* Sum: '<S148>/Add' incorporates:
   *  Constant: '<S148>/Constant'
   */
  T_left = theta_right + KfLKAS_d_EdgBuff;

  /* Switch: '<S148>/Switch1' incorporates:
   *  Constant: '<S134>/Constant2'
   *  Constant: '<S148>/Constant6'
   *  Constant: '<S148>/Constant8'
   *  Product: '<S148>/Product'
   *  Sum: '<S148>/Add2'
   *  Switch: '<S148>/Switch'
   */
  if ((true) && (LKAS_subsystem_integrated_B.Gain_kbew > KfLKAS_c_CurvUprBnd))
  {
    T_left = (KfLKAS_r_CurvBuffCoe * KfLKAS_d_EdgBuff) + theta_right;
  }

  /* End of Switch: '<S148>/Switch1' */

  /* If: '<S160>/If' */
  if (T_left > 0.0F)
  {
    /* Outputs for IfAction SubSystem: '<S160>/If Action Subsystem' incorporates:
     *  ActionPort: '<S162>/Action Port'
     */
    /* Product: '<S162>/Divide' incorporates:
     *  Constant: '<S162>/Constant'
     *  Sum: '<S162>/Add'
     */
    theta_right = T_left / (rtb_Add_p0q2 + 2.22044605E-16F);

    /* End of Outputs for SubSystem: '<S160>/If Action Subsystem' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S160>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S163>/Action Port'
     */
    /* SignalConversion: '<S163>/OutportBufferForTLCLe' incorporates:
     *  Constant: '<S163>/Constant'
     */
    theta_right = 0.0F;

    /* End of Outputs for SubSystem: '<S160>/If Action Subsystem1' */
  }

  /* End of If: '<S160>/If' */

  /* Switch: '<S145>/Switch' incorporates:
   *  Constant: '<S145>/Constant'
   *  Constant: '<S145>/Constant1'
   *  Sum: '<S159>/Add'
   */
  if ((theta_new_right + theta_new_right_tmp) > 0.0F)
  {
    rtb_Switch_dles = true;
  }
  else
  {
    rtb_Switch_dles = false;
  }

  /* End of Switch: '<S145>/Switch' */

  /* Switch: '<S134>/Switch' incorporates:
   *  Constant: '<S134>/Constant'
   */
  if (LKAS_subsystem_integrated_B.IsIntvCompleted_sLKA_a1kj)
  {
    /* Switch: '<S149>/Switch1' incorporates:
     *  Constant: '<S149>/Constant'
     *  RelationalOperator: '<S149>/Relational Operator'
     */
    if (T_left >= 0.0F)
    {
      rtb_Switch1_fphx = (T_left <= rtb_Merge2);
    }
    else
    {
      rtb_Switch1_fphx = true;
    }

    /* End of Switch: '<S149>/Switch1' */

    /* Switch: '<S142>/Switch' incorporates:
     *  Constant: '<S142>/Constant'
     *  Constant: '<S149>/Constant4'
     *  Logic: '<S142>/Logical Operator'
     *  Logic: '<S149>/Logical Operator'
     *  RelationalOperator: '<S149>/Relational Operator1'
     *  Sum: '<S151>/Diff'
     *  Switch: '<S142>/Switch3'
     *  UnitDelay: '<S151>/UD'
     *
     * Block description for '<S151>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S151>/UD':
     *
     *  Store in Global RAM
     */
    if (rtb_Switch1_fphx && ((T_left - LKAS_subsystem_integrated_DW.UD_DSTATE) >
         0.0F))
    {
      rtb_Switch1_fphx = true;
    }
    else
    {
      if (theta_right > 0.0F)
      {
        /* Switch: '<S142>/Switch1' incorporates:
         *  Constant: '<S142>/Constant1'
         *  Constant: '<S142>/Constant2'
         *  Constant: '<S142>/Constant6'
         *  Sum: '<S142>/Add'
         *  Switch: '<S142>/Switch3'
         */
        if ((theta_right - KfLKAS_t_TLCThrsh) > 0.0F)
        {
          rtb_Switch1_fphx = false;
        }
        else
        {
          rtb_Switch1_fphx = true;
        }

        /* End of Switch: '<S142>/Switch1' */
      }
      else
      {
        /* Switch: '<S142>/Switch3' incorporates:
         *  Constant: '<S142>/Constant5'
         */
        rtb_Switch1_fphx = false;
      }

      /* Switch: '<S142>/Switch2' incorporates:
       *  Constant: '<S142>/Constant3'
       *  Constant: '<S142>/Constant4'
       */
      if (rtb_Switch_dles)
      {
        rtb_Switch_myhq = true;
      }
      else
      {
        rtb_Switch_myhq = false;
      }

      /* End of Switch: '<S142>/Switch2' */
      rtb_Switch1_fphx = (rtb_Switch1_fphx && rtb_Switch_myhq);
    }

    /* End of Switch: '<S142>/Switch' */
  }
  else
  {
    rtb_Switch1_fphx = false;
  }

  /* End of Switch: '<S134>/Switch' */

  /* Logic: '<S134>/Logical Operator' incorporates:
   *  Constant: '<S134>/Constant3'
   *  RelationalOperator: '<S134>/Relational Operator'
   */
  LKAS_subsystem_integrated_B.IsIntvCompleted_sLKA_a1kj = (rtb_Switch1_fphx &&
    (theta_right > ((real32_T)(false ? 1.0F : 0.0F))));

  /* MATLAB Function: '<S168>/Right_Edge_Calculation' incorporates:
   *  Constant: '<S148>/Constant1'
   *  Constant: '<S148>/Constant4'
   */
  if (T_right > 0.0F)
  {
    T_right = rtb_Abs + (KfLKAS_d_BkToFrtCnrDist * ((real32_T)sin((real_T)
      ((real32_T)(T_right - KfLKAS_Ang_BkToCnrAng)))));
  }
  else
  {
    T_right = rtb_Abs - (KfLKAS_d_BkToFrtCnrDist * ((real32_T)sin((real_T)
      ((real32_T)(((real32_T)fabs((real_T)T_right)) + KfLKAS_Ang_BkToCnrAng)))));
  }

  /* End of MATLAB Function: '<S168>/Right_Edge_Calculation' */

  /* Sum: '<S148>/Add1' incorporates:
   *  Constant: '<S148>/Constant5'
   */
  rtb_Abs = T_right + KfLKAS_d_EdgBuff;

  /* Switch: '<S148>/Switch3' incorporates:
   *  Constant: '<S134>/Constant2'
   *  Constant: '<S148>/Constant7'
   *  Constant: '<S148>/Constant9'
   *  Product: '<S148>/Product1'
   *  Sum: '<S148>/Add3'
   *  Switch: '<S148>/Switch2'
   */
  if ((true) && (!(LKAS_subsystem_integrated_B.Gain_kbew > (-KfLKAS_c_CurvUprBnd))))
  {
    rtb_Abs = (KfLKAS_r_CurvBuffCoe * KfLKAS_d_EdgBuff) + T_right;
  }

  /* End of Switch: '<S148>/Switch3' */

  /* Sum: '<S161>/Add1' incorporates:
   *  Product: '<S161>/Product'
   *  Product: '<S161>/Product1'
   */
  rtb_Add1_cdqo = (0.0F - theta_new_right) - theta_new_right_tmp;

  /* If: '<S160>/If1' */
  if (rtb_Abs > 0.0F)
  {
    /* Outputs for IfAction SubSystem: '<S160>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S164>/Action Port'
     */
    /* Product: '<S164>/Divide1' incorporates:
     *  Constant: '<S164>/Constant1'
     *  Sum: '<S164>/Add1'
     */
    T_right = rtb_Abs / (rtb_Add1_cdqo + 2.22044605E-16F);

    /* End of Outputs for SubSystem: '<S160>/If Action Subsystem2' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S160>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S165>/Action Port'
     */
    /* SignalConversion: '<S165>/OutportBufferForTCLRi' incorporates:
     *  Constant: '<S165>/Constant1'
     */
    T_right = 0.0F;

    /* End of Outputs for SubSystem: '<S160>/If Action Subsystem3' */
  }

  /* End of If: '<S160>/If1' */

  /* If: '<S150>/If1' incorporates:
   *  Constant: '<S150>/Constant1'
   *  Constant: '<S150>/Constant2'
   *  Constant: '<S150>/Constant3'
   *  Inport: '<S156>/In1'
   *  Inport: '<S157>/In1'
   */
  if (rtb_Add1_cdqo > 1.0F)
  {
    /* Outputs for IfAction SubSystem: '<S150>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S156>/Action Port'
     */
    rtb_Merge1_mygh = KfLKAS_d_WarnLineLvlOne;

    /* End of Outputs for SubSystem: '<S150>/If Action Subsystem4' */
  }
  else if (rtb_Add1_cdqo < 0.5F)
  {
    /* Outputs for IfAction SubSystem: '<S150>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S157>/Action Port'
     */
    rtb_Merge1_mygh = KfLKAS_d_WarnLineLvlThree;

    /* End of Outputs for SubSystem: '<S150>/If Action Subsystem5' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S150>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S158>/Action Port'
     */
    LKAS_subsyst_IfActionSubsystem6(rtb_Add1_cdqo, KfLKAS_r_WarnLineLvlTwo,
      &rtb_Merge1_mygh);

    /* End of Outputs for SubSystem: '<S150>/If Action Subsystem6' */
  }

  /* End of If: '<S150>/If1' */

  /* Switch: '<S134>/Switch1' incorporates:
   *  Constant: '<S134>/Constant1'
   */
  if (LKAS_subsystem_integrated_B.LogicalOperator1)
  {
    /* Switch: '<S150>/Switch2' incorporates:
     *  Constant: '<S150>/Constant'
     *  RelationalOperator: '<S150>/Relational Operator2'
     */
    if (rtb_Abs > 0.0F)
    {
      rtb_Switch1_fphx = (rtb_Abs <= rtb_Merge1_mygh);
    }
    else
    {
      rtb_Switch1_fphx = true;
    }

    /* End of Switch: '<S150>/Switch2' */

    /* Switch: '<S143>/Switch' incorporates:
     *  Constant: '<S143>/Constant'
     *  Constant: '<S150>/Constant4'
     *  Logic: '<S143>/Logical Operator'
     *  Logic: '<S150>/Logical Operator'
     *  RelationalOperator: '<S150>/Relational Operator1'
     *  Sum: '<S155>/Diff'
     *  Switch: '<S143>/Switch3'
     *  UnitDelay: '<S155>/UD'
     *
     * Block description for '<S155>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S155>/UD':
     *
     *  Store in Global RAM
     */
    if (rtb_Switch1_fphx && ((rtb_Abs -
          LKAS_subsystem_integrated_DW.UD_DSTATE_hwxw) > 0.0F))
    {
      rtb_Switch_dles = true;
    }
    else
    {
      if (T_right > 0.0F)
      {
        /* Switch: '<S143>/Switch1' incorporates:
         *  Constant: '<S143>/Constant1'
         *  Constant: '<S143>/Constant2'
         *  Constant: '<S143>/Constant6'
         *  Sum: '<S143>/Add'
         *  Switch: '<S143>/Switch3'
         */
        if ((T_right - KfLKAS_t_TLCThrsh) > 0.0F)
        {
          rtb_Switch1_fphx = false;
        }
        else
        {
          rtb_Switch1_fphx = true;
        }

        /* End of Switch: '<S143>/Switch1' */
      }
      else
      {
        /* Switch: '<S143>/Switch3' incorporates:
         *  Constant: '<S143>/Constant5'
         */
        rtb_Switch1_fphx = false;
      }

      /* Switch: '<S143>/Switch2' incorporates:
       *  Constant: '<S143>/Constant3'
       *  Constant: '<S143>/Constant4'
       */
      if (rtb_Switch_dles)
      {
        rtb_Switch_dles = false;
      }
      else
      {
        rtb_Switch_dles = true;
      }

      /* End of Switch: '<S143>/Switch2' */
      rtb_Switch_dles = (rtb_Switch1_fphx && rtb_Switch_dles);
    }

    /* End of Switch: '<S143>/Switch' */
  }
  else
  {
    rtb_Switch_dles = false;
  }

  /* End of Switch: '<S134>/Switch1' */

  /* Logic: '<S134>/Logical Operator1' incorporates:
   *  Constant: '<S134>/Constant4'
   *  RelationalOperator: '<S134>/Relational Operator1'
   */
  LKAS_subsystem_integrated_B.LogicalOperator1 = (rtb_Switch_dles && (T_right >
    ((real32_T)(false ? 1.0F : 0.0F))));

  /* Sum: '<S159>/Add1' */
  rtb_Add1_nd0i = (0.0F - theta_new_right) - theta_new_right_tmp;

  /* SignalConversion: '<S134>/Signal Conversion2' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  rtb_SignalConversion2 = VsEGMO_DataBus.motion.steer_angle_filtered;

  /* Update for UnitDelay: '<S151>/UD'
   *
   * Block description for '<S151>/UD':
   *
   *  Store in Global RAM
   */
  LKAS_subsystem_integrated_DW.UD_DSTATE = T_left;

  /* Update for UnitDelay: '<S155>/UD'
   *
   * Block description for '<S155>/UD':
   *
   *  Store in Global RAM
   */
  LKAS_subsystem_integrated_DW.UD_DSTATE_hwxw = rtb_Abs;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
