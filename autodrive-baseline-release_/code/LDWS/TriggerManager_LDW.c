/*
 * File: TriggerManager_LDW.c
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

#include "TriggerManager_LDW.h"

/* Include model header file for global data */
#include "LDWS_subsystem_integrated.h"
#include "LDWS_subsystem_integrated_private.h"

/*
 * Output and update for action system:
 *    '<S51>/If Action Subsystem6'
 *    '<S52>/If Action Subsystem6'
 */
void LDWS_subsyst_IfActionSubsystem6(real32_T rtu_In1, real32_T rtu_In2,
  real32_T *rty_Out1)
{
  /* Product: '<S55>/Product' */
  *rty_Out1 = rtu_In1 * rtu_In2;
}

/* Output and update for atomic system: '<S1>/TriggerManager_LDW' */
void LDWS_subsyst_TriggerManager_LDW(void)
{
  real32_T T_left;
  real32_T T_right;
  real32_T theta_right;
  real32_T theta_new_right;
  boolean_T rtb_Switch3_nfya;
  real32_T rtb_Merge2;
  real32_T rtb_Merge1;
  real32_T rtb_Add1_b0j1;
  boolean_T tmp;

  /* Abs: '<S8>/Abs' */
  VfLDWS_BackToRiDist = (real32_T)fabs((real_T)
    LDWS_subsystem_integrated_B.RiDist);

  /* MATLAB Function: '<S49>/theta_calculation' */
  T_left = (real32_T)fabs((real_T)((real32_T)(VfLDWS_BackToLeDist / ((real32_T)
    fabs((real_T)VfLDWS_LeC0Filtd)))));
  if (T_left > 1.0F)
  {
    T_left = 1.0F / T_left;
  }

  T_left = (real32_T)acos((real_T)T_left);
  T_right = (real32_T)fabs((real_T)((real32_T)(VfLDWS_BackToRiDist / ((real32_T)
    fabs((real_T)VfLDWS_RiC0Filtd)))));
  if (T_right > 1.0F)
  {
    T_right = 1.0F / T_right;
  }

  theta_right = (real32_T)acos((real_T)T_right);
  T_right = (real32_T)fabs((real_T)((real32_T)atan((real_T)VfLDWS_LeC1Filtd)));
  theta_new_right = (real32_T)fabs((real_T)((real32_T)atan((real_T)
    VfLDWS_RiC1Filtd)));
  if ((VfLDWS_LeC1Filtd < 0.0F) && (VfLDWS_RiC1Filtd < 0.0F))
  {
    T_left = (T_left + theta_right) / 2.0F;
    T_right = (T_right + theta_new_right) / 2.0F;
  }
  else if ((VfLDWS_LeC1Filtd > 0.0F) && (VfLDWS_RiC1Filtd > 0.0F))
  {
    T_left = (-(T_left + theta_right)) / 2.0F;
    T_right = (-(T_right + theta_new_right)) / 2.0F;
  }
  else
  {
    T_left = 0.0F;
    T_right = 0.0F;
  }

  /* End of MATLAB Function: '<S49>/theta_calculation' */

  /* Switch: '<S49>/Switch' incorporates:
   *  Constant: '<S49>/Constant'
   */
  if (KbLDWS_ThetaSwitch)
  {
    VfLDWS_Theta = T_right;
  }
  else
  {
    VfLDWS_Theta = T_left;
  }

  /* End of Switch: '<S49>/Switch' */

  /* SignalConversion: '<S8>/Signal Conversion' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VfLDWS_Vx = VsEGMO_DataBus.motion.velocity_rel.x;

  /* Product: '<S61>/Product' incorporates:
   *  Product: '<S59>/Product'
   *  Trigonometry: '<S61>/Sin'
   */
  T_left = VfLDWS_Vx * ((real32_T)sin((real_T)VfLDWS_Theta));

  /* SignalConversion: '<S8>/Signal Conversion1' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VfLDWS_Vy = VsEGMO_DataBus.motion.velocity_rel.y;

  /* Product: '<S61>/Product1' incorporates:
   *  Product: '<S59>/Product1'
   *  Trigonometry: '<S61>/Cos'
   */
  T_right = ((real32_T)cos((real_T)VfLDWS_Theta)) * VfLDWS_Vy;

  /* Sum: '<S61>/Add' incorporates:
   *  Product: '<S61>/Product'
   *  Product: '<S61>/Product1'
   */
  VfLDWS_VLatLe = T_left + T_right;

  /* If: '<S51>/If2' incorporates:
   *  Constant: '<S51>/Constant1'
   *  Constant: '<S51>/Constant2'
   *  Constant: '<S51>/Constant3'
   *  Inport: '<S53>/In1'
   *  Inport: '<S54>/In1'
   */
  if (VfLDWS_VLatLe > 1.0F)
  {
    /* Outputs for IfAction SubSystem: '<S51>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S53>/Action Port'
     */
    rtb_Merge2 = KfLDWS_d_WarnLineLvlOne;

    /* End of Outputs for SubSystem: '<S51>/If Action Subsystem4' */
  }
  else if (VfLDWS_VLatLe < 0.5F)
  {
    /* Outputs for IfAction SubSystem: '<S51>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S54>/Action Port'
     */
    rtb_Merge2 = KfLDWS_d_WarnLineLvlThree;

    /* End of Outputs for SubSystem: '<S51>/If Action Subsystem5' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S51>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S55>/Action Port'
     */
    LDWS_subsyst_IfActionSubsystem6(VfLDWS_VLatLe, KfLDWS_k_WarnLineLvlTwo,
      &rtb_Merge2);

    /* End of Outputs for SubSystem: '<S51>/If Action Subsystem6' */
  }

  /* End of If: '<S51>/If2' */

  /* MATLAB Function: '<S67>/Left_Edge_Calculation' incorporates:
   *  Constant: '<S50>/Constant2'
   *  Constant: '<S50>/Constant3'
   */
  if (VfLDWS_Theta > 0.0F)
  {
    theta_new_right = VfLDWS_BackToLeDist - (KfLDWS_d_BkToFrtCnrDist *
      ((real32_T)sin((real_T)((real32_T)(((real32_T)fabs((real_T)VfLDWS_Theta))
      + KfLDWS_Ang_BkToCnrAng)))));
  }
  else
  {
    theta_new_right = VfLDWS_BackToLeDist + (KfLDWS_d_BkToFrtCnrDist *
      ((real32_T)sin((real_T)((real32_T)(((real32_T)fabs((real_T)VfLDWS_Theta))
      - KfLDWS_Ang_BkToCnrAng)))));
  }

  /* End of MATLAB Function: '<S67>/Left_Edge_Calculation' */

  /* Sum: '<S50>/Add' incorporates:
   *  Constant: '<S50>/Constant'
   */
  theta_right = theta_new_right + KfLDWS_d_EdgBuff;

  /* Switch: '<S50>/Switch' incorporates:
   *  Constant: '<S8>/Constant2'
   */
  if (true)
  {
    /* Switch: '<S50>/Switch1' incorporates:
     *  Constant: '<S50>/Constant6'
     *  Constant: '<S50>/Constant8'
     *  Product: '<S50>/Product'
     *  Sum: '<S50>/Add2'
     */
    if (VfLDWS_Curvature > KfLDWS_c_CurvUprBnd)
    {
      VfLDWS_EdgeLaneLe = (KfLDWS_k_CurvBuffCoe * KfLDWS_d_EdgBuff) +
        theta_new_right;
    }
    else
    {
      VfLDWS_EdgeLaneLe = theta_right;
    }

    /* End of Switch: '<S50>/Switch1' */
  }
  else
  {
    VfLDWS_EdgeLaneLe = theta_right;
  }

  /* End of Switch: '<S50>/Switch' */

  /* If: '<S60>/If' */
  if (VfLDWS_EdgeLaneLe > 0.0F)
  {
    /* Outputs for IfAction SubSystem: '<S60>/If Action Subsystem' incorporates:
     *  ActionPort: '<S62>/Action Port'
     */
    /* Product: '<S62>/Divide' incorporates:
     *  Constant: '<S62>/Constant'
     *  Sum: '<S62>/Add'
     */
    VfLDWS_TLCLe = VfLDWS_EdgeLaneLe / (VfLDWS_VLatLe + 2.22044605E-16F);

    /* End of Outputs for SubSystem: '<S60>/If Action Subsystem' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S60>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S63>/Action Port'
     */
    /* SignalConversion: '<S63>/OutportBufferForTLCLe' incorporates:
     *  Constant: '<S63>/Constant'
     */
    VfLDWS_TLCLe = 0.0F;

    /* End of Outputs for SubSystem: '<S60>/If Action Subsystem1' */
  }

  /* End of If: '<S60>/If' */

  /* Switch: '<S51>/Switch1' incorporates:
   *  Constant: '<S51>/Constant'
   *  RelationalOperator: '<S51>/Relational Operator'
   */
  if (VfLDWS_EdgeLaneLe >= 0.0F)
  {
    VbLDWS_IsOnLeLine = (VfLDWS_EdgeLaneLe <= rtb_Merge2);
  }
  else
  {
    VbLDWS_IsOnLeLine = true;
  }

  /* End of Switch: '<S51>/Switch1' */

  /* Switch: '<S47>/Switch' incorporates:
   *  Constant: '<S47>/Constant'
   *  Constant: '<S47>/Constant1'
   *  Sum: '<S59>/Add'
   */
  if ((T_left + T_right) > 0.0F)
  {
    VbLDWS_LeadDrctn = true;
  }
  else
  {
    VbLDWS_LeadDrctn = false;
  }

  /* End of Switch: '<S47>/Switch' */

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant'
   */
  if (VbLDWS_RdEnblLe)
  {
    /* Switch: '<S44>/Switch' incorporates:
     *  Constant: '<S44>/Constant'
     *  Logic: '<S44>/Logical Operator'
     *  Switch: '<S44>/Switch3'
     */
    if (VbLDWS_IsOnLeLine)
    {
      rtb_Switch3_nfya = true;
    }
    else
    {
      if (VfLDWS_TLCLe > 0.0F)
      {
        /* Switch: '<S44>/Switch1' incorporates:
         *  Constant: '<S44>/Constant1'
         *  Constant: '<S44>/Constant2'
         *  Constant: '<S44>/Constant6'
         *  Sum: '<S44>/Add'
         *  Switch: '<S44>/Switch3'
         */
        if ((VfLDWS_TLCLe - KfLDWS_t_TLCThrsh) > 0.0F)
        {
          rtb_Switch3_nfya = false;
        }
        else
        {
          rtb_Switch3_nfya = true;
        }

        /* End of Switch: '<S44>/Switch1' */
      }
      else
      {
        /* Switch: '<S44>/Switch3' incorporates:
         *  Constant: '<S44>/Constant5'
         */
        rtb_Switch3_nfya = false;
      }

      /* Switch: '<S44>/Switch2' incorporates:
       *  Constant: '<S44>/Constant3'
       *  Constant: '<S44>/Constant4'
       */
      if (VbLDWS_LeadDrctn)
      {
        tmp = true;
      }
      else
      {
        tmp = false;
      }

      /* End of Switch: '<S44>/Switch2' */
      rtb_Switch3_nfya = (rtb_Switch3_nfya && tmp);
    }

    /* End of Switch: '<S44>/Switch' */
    VbLDWS_ActLeLDW = rtb_Switch3_nfya;
  }
  else
  {
    VbLDWS_ActLeLDW = false;
  }

  /* End of Switch: '<S8>/Switch' */

  /* MATLAB Function: '<S68>/Right_Edge_Calculation' incorporates:
   *  Constant: '<S50>/Constant1'
   *  Constant: '<S50>/Constant4'
   */
  if (VfLDWS_Theta > 0.0F)
  {
    theta_right = VfLDWS_BackToRiDist + (KfLDWS_d_BkToFrtCnrDist * ((real32_T)
      sin((real_T)((real32_T)(((real32_T)fabs((real_T)VfLDWS_Theta)) -
      KfLDWS_Ang_BkToCnrAng)))));
  }
  else
  {
    theta_right = VfLDWS_BackToRiDist - (KfLDWS_d_BkToFrtCnrDist * ((real32_T)
      sin((real_T)((real32_T)(((real32_T)fabs((real_T)VfLDWS_Theta)) +
      KfLDWS_Ang_BkToCnrAng)))));
  }

  /* End of MATLAB Function: '<S68>/Right_Edge_Calculation' */

  /* Sum: '<S50>/Add1' incorporates:
   *  Constant: '<S50>/Constant5'
   */
  theta_new_right = theta_right + KfLDWS_d_EdgBuff;

  /* Switch: '<S50>/Switch2' incorporates:
   *  Constant: '<S8>/Constant2'
   */
  if (true)
  {
    /* Switch: '<S50>/Switch3' incorporates:
     *  Constant: '<S50>/Constant7'
     *  Constant: '<S50>/Constant9'
     *  Product: '<S50>/Product1'
     *  Sum: '<S50>/Add3'
     */
    if (VfLDWS_Curvature > (-KfLDWS_c_CurvUprBnd))
    {
      VfLDWS_EdgeLaneRi = theta_new_right;
    }
    else
    {
      VfLDWS_EdgeLaneRi = (KfLDWS_k_CurvBuffCoe * KfLDWS_d_EdgBuff) +
        theta_right;
    }

    /* End of Switch: '<S50>/Switch3' */
  }
  else
  {
    VfLDWS_EdgeLaneRi = theta_new_right;
  }

  /* End of Switch: '<S50>/Switch2' */

  /* Sum: '<S61>/Add1' incorporates:
   *  Product: '<S61>/Product'
   *  Product: '<S61>/Product1'
   */
  VfLDWS_VLatRi = (0.0F - T_left) - T_right;

  /* If: '<S60>/If1' */
  if (VfLDWS_EdgeLaneRi > 0.0F)
  {
    /* Outputs for IfAction SubSystem: '<S60>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S64>/Action Port'
     */
    /* Product: '<S64>/Divide1' incorporates:
     *  Constant: '<S64>/Constant1'
     *  Sum: '<S64>/Add1'
     */
    VfLDWS_TLCRi = VfLDWS_EdgeLaneRi / (VfLDWS_VLatRi + 2.22044605E-16F);

    /* End of Outputs for SubSystem: '<S60>/If Action Subsystem2' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S60>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S65>/Action Port'
     */
    /* SignalConversion: '<S65>/OutportBufferForTCLRi' incorporates:
     *  Constant: '<S65>/Constant1'
     */
    VfLDWS_TLCRi = 0.0F;

    /* End of Outputs for SubSystem: '<S60>/If Action Subsystem3' */
  }

  /* End of If: '<S60>/If1' */

  /* If: '<S52>/If1' incorporates:
   *  Constant: '<S52>/Constant1'
   *  Constant: '<S52>/Constant2'
   *  Constant: '<S52>/Constant3'
   *  Inport: '<S56>/In1'
   *  Inport: '<S57>/In1'
   */
  if (VfLDWS_VLatRi > 1.0F)
  {
    /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S56>/Action Port'
     */
    rtb_Merge1 = KfLDWS_d_WarnLineLvlOne;

    /* End of Outputs for SubSystem: '<S52>/If Action Subsystem4' */
  }
  else if (VfLDWS_VLatRi < 0.5F)
  {
    /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S57>/Action Port'
     */
    rtb_Merge1 = KfLDWS_d_WarnLineLvlThree;

    /* End of Outputs for SubSystem: '<S52>/If Action Subsystem5' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S58>/Action Port'
     */
    LDWS_subsyst_IfActionSubsystem6(VfLDWS_VLatRi, KfLDWS_k_WarnLineLvlTwo,
      &rtb_Merge1);

    /* End of Outputs for SubSystem: '<S52>/If Action Subsystem6' */
  }

  /* End of If: '<S52>/If1' */

  /* Switch: '<S52>/Switch2' incorporates:
   *  Constant: '<S52>/Constant'
   *  RelationalOperator: '<S52>/Relational Operator2'
   */
  if (VfLDWS_EdgeLaneRi > 0.0F)
  {
    VbLDWS_IsOnRiLine = (VfLDWS_EdgeLaneRi <= rtb_Merge1);
  }
  else
  {
    VbLDWS_IsOnRiLine = true;
  }

  /* End of Switch: '<S52>/Switch2' */

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<S8>/Constant1'
   */
  if (VbLDWS_RdEnblRi)
  {
    /* Switch: '<S45>/Switch' incorporates:
     *  Constant: '<S45>/Constant'
     *  Logic: '<S45>/Logical Operator'
     *  Switch: '<S45>/Switch3'
     */
    if (VbLDWS_IsOnRiLine)
    {
      rtb_Switch3_nfya = true;
    }
    else
    {
      if (VfLDWS_TLCRi > 0.0F)
      {
        /* Switch: '<S45>/Switch1' incorporates:
         *  Constant: '<S45>/Constant1'
         *  Constant: '<S45>/Constant2'
         *  Constant: '<S45>/Constant6'
         *  Sum: '<S45>/Add'
         *  Switch: '<S45>/Switch3'
         */
        if ((VfLDWS_TLCRi - KfLDWS_t_TLCThrsh) > 0.0F)
        {
          rtb_Switch3_nfya = false;
        }
        else
        {
          rtb_Switch3_nfya = true;
        }

        /* End of Switch: '<S45>/Switch1' */
      }
      else
      {
        /* Switch: '<S45>/Switch3' incorporates:
         *  Constant: '<S45>/Constant5'
         */
        rtb_Switch3_nfya = false;
      }

      /* Switch: '<S45>/Switch2' incorporates:
       *  Constant: '<S45>/Constant3'
       *  Constant: '<S45>/Constant4'
       */
      if (VbLDWS_LeadDrctn)
      {
        tmp = false;
      }
      else
      {
        tmp = true;
      }

      /* End of Switch: '<S45>/Switch2' */
      rtb_Switch3_nfya = (rtb_Switch3_nfya && tmp);
    }

    /* End of Switch: '<S45>/Switch' */
    VbLDWS_ActRiLDW = rtb_Switch3_nfya;
  }
  else
  {
    VbLDWS_ActRiLDW = false;
  }

  /* End of Switch: '<S8>/Switch1' */

  /* Sum: '<S59>/Add1' */
  rtb_Add1_b0j1 = (0.0F - T_left) - T_right;

  /* SignalConversion: '<S8>/Signal Conversion2' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  VfLDWS_SteerAngle =
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
