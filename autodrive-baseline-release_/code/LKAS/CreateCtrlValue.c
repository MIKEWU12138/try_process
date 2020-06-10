/*
 * File: CreateCtrlValue.c
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

#include "CreateCtrlValue.h"

/* Include model header file for global data */
#include "LKAS_subsystem_integrated.h"
#include "LKAS_subsystem_integrated_private.h"
#include "look1_iflf_binlc.h"
#include "look1_iflf_binlx.h"
#include "look2_iflf_binlc.h"

/* System initialize for atomic system: '<S4>/CreateCtrlValue' */
void LKAS_subsy_CreateCtrlValue_Init(void)
{
  /* SystemInitialize for Enabled SubSystem: '<S21>/TargetDistCalc_2' */
  /* InitializeConditions for UnitDelay: '<S27>/Unit Delay2' */
  LKAS_subsystem_integrated_DW.UnitDelay2_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S27>/Unit Delay3' */
  LKAS_subsystem_integrated_DW.UnitDelay3_DSTATE = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S21>/TargetDistCalc_2' */

  /* SystemInitialize for Enabled SubSystem: '<S21>/TargetDistCalc_1' */
  /* InitializeConditions for UnitDelay: '<S26>/Unit Delay2' */
  LKAS_subsystem_integrated_DW.UnitDelay2_DSTATE_ki2g = 0.0F;

  /* InitializeConditions for UnitDelay: '<S26>/Unit Delay1' */
  LKAS_subsystem_integrated_DW.UnitDelay1_DSTATE_kq0m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S21>/TargetDistCalc_1' */
}

/* Output and update for atomic system: '<S4>/CreateCtrlValue' */
void LKAS_subsystem__CreateCtrlValue(void)
{
  boolean_T rtb_RelationalOperator;
  boolean_T rtb_Compare;
  boolean_T rtb_RelationalOperator1;
  real32_T rtb_uDLookupTable_o3xc;
  boolean_T rtb_RelationalOperator_njkr;
  real32_T rtb_Add6;
  boolean_T rtb_SWCH_1;
  boolean_T rtb_SWCH_1_d5lo;
  real32_T rtb_Add8;
  boolean_T rtb_RelationalOperator_kjqa;
  EnumLKAS_CtrlRefTypVcc rtb_Switch1_deys;
  EnumLKAS_IntvSide rtb_Compare_0;

  /* RelationalOperator: '<S14>/Relational Operator' incorporates:
   *  Constant: '<S20>/Constant'
   */
  rtb_RelationalOperator = (LKAS_subsystem_integrated_B.IntvTyp_sLKA !=
    LKAS_NoIntvTyp);

  /* Switch: '<S53>/SWCH_1' incorporates:
   *  Constant: '<S18>/Constant5'
   *  Logic: '<S53>/LOGOP_1'
   *  Logic: '<S53>/LOGOP_2'
   *  Logic: '<S63>/LOGOP_1'
   *  Logic: '<S63>/LOGOP_2'
   *  Logic: '<S64>/LOGOP_1'
   *  Logic: '<S64>/LOGOP_2'
   *  UnitDelay: '<S63>/UD_1'
   *  UnitDelay: '<S64>/UD_1'
   */
  if (((!rtb_RelationalOperator) || (rtb_RelationalOperator &&
        (!LKAS_subsystem_integrated_DW.UD_1_DSTATE_eh0l))) || ((false) &&
       (!LKAS_subsystem_integrated_DW.UD_1_DSTATE_oh3u)))
  {
    VfLKAS_dtFreezed_sLKA = VfLKAS_dt_sLKA;
  }

  /* End of Switch: '<S53>/SWCH_1' */

  /* RelationalOperator: '<S21>/Relational Operator1' incorporates:
   *  Gain: '<S21>/Gain'
   */
  rtb_RelationalOperator1 = (LKAS_subsystem_integrated_B.T_AftIntvStart_gady >=
    (2.0F * VfLKAS_dtFreezed_sLKA));

  /* Switch: '<S51>/SWCH_1' incorporates:
   *  Constant: '<S18>/Constant3'
   *  Logic: '<S51>/LOGOP_1'
   *  Logic: '<S51>/LOGOP_2'
   *  Logic: '<S59>/LOGOP_1'
   *  Logic: '<S59>/LOGOP_2'
   *  Logic: '<S60>/LOGOP_1'
   *  Logic: '<S60>/LOGOP_2'
   *  UnitDelay: '<S59>/UD_1'
   *  UnitDelay: '<S60>/UD_1'
   */
  if (((!rtb_RelationalOperator) || (rtb_RelationalOperator &&
        (!LKAS_subsystem_integrated_DW.UD_1_DSTATE_mfkr))) || ((false) &&
       (!LKAS_subsystem_integrated_DW.UD_1_DSTATE_o0s5)))
  {
    VfLKAS_AmFreezed_sLKA = VfLKAS_Am_sLKA;
  }

  /* End of Switch: '<S51>/SWCH_1' */

  /* Switch: '<S54>/SWCH_1' incorporates:
   *  Constant: '<S18>/Constant1'
   *  Gain: '<S18>/Gain'
   *  Logic: '<S54>/LOGOP_1'
   *  Logic: '<S54>/LOGOP_2'
   *  Logic: '<S65>/LOGOP_1'
   *  Logic: '<S65>/LOGOP_2'
   *  Logic: '<S66>/LOGOP_1'
   *  Logic: '<S66>/LOGOP_2'
   *  UnitDelay: '<S65>/UD_1'
   *  UnitDelay: '<S66>/UD_1'
   */
  if (((!rtb_RelationalOperator) || (rtb_RelationalOperator &&
        (!LKAS_subsystem_integrated_DW.UD_1_DSTATE_hgvk))) || ((false) &&
       (!LKAS_subsystem_integrated_DW.UD_1_DSTATE_nu3p)))
  {
    /* Switch: '<S39>/Switch2' incorporates:
     *  Constant: '<S39>/Constant'
     */
    if (LKAS_subsystem_integrated_B.TrajData.ZeroTrajectoryFound_sLKA)
    {
      rtb_uDLookupTable_o3xc = 0.0F;
    }
    else
    {
      rtb_uDLookupTable_o3xc =
        LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.Vlat_sLKA;
    }

    /* End of Switch: '<S39>/Switch2' */
    VfLKAS_V0Freezed_sLKA = (-1.0F) * rtb_uDLookupTable_o3xc;
  }

  /* End of Switch: '<S54>/SWCH_1' */

  /* Switch: '<S49>/SWCH_1' incorporates:
   *  Constant: '<S18>/Constant2'
   *  Logic: '<S49>/LOGOP_1'
   *  Logic: '<S49>/LOGOP_2'
   *  Logic: '<S55>/LOGOP_1'
   *  Logic: '<S55>/LOGOP_2'
   *  Logic: '<S56>/LOGOP_1'
   *  Logic: '<S56>/LOGOP_2'
   *  UnitDelay: '<S55>/UD_1'
   *  UnitDelay: '<S56>/UD_1'
   */
  if (((!rtb_RelationalOperator) || (rtb_RelationalOperator &&
        (!LKAS_subsystem_integrated_DW.UD_1_DSTATE_derr))) || ((false) &&
       (!LKAS_subsystem_integrated_DW.UD_1_DSTATE_mrje)))
  {
    VfLKAS_A0Freezed_sLKA = VfLKAS_A0_sLKA;
  }

  /* End of Switch: '<S49>/SWCH_1' */

  /* Switch: '<S52>/SWCH_1' incorporates:
   *  Constant: '<S18>/Constant4'
   *  Logic: '<S52>/LOGOP_1'
   *  Logic: '<S52>/LOGOP_2'
   *  Logic: '<S61>/LOGOP_1'
   *  Logic: '<S61>/LOGOP_2'
   *  Logic: '<S62>/LOGOP_1'
   *  Logic: '<S62>/LOGOP_2'
   *  UnitDelay: '<S61>/UD_1'
   *  UnitDelay: '<S62>/UD_1'
   */
  if (((!rtb_RelationalOperator) || (rtb_RelationalOperator &&
        (!LKAS_subsystem_integrated_DW.UD_1_DSTATE_axse))) || ((false) &&
       (!LKAS_subsystem_integrated_DW.UD_1_DSTATE_acl5)))
  {
    VfLKAS_AeFreezed_sLKA = VfLKAS_Ae_sLKA;
  }

  /* End of Switch: '<S52>/SWCH_1' */

  /* Sum: '<S24>/Add3' incorporates:
   *  Constant: '<S24>/Constant1'
   */
  rtb_uDLookupTable_o3xc = VfLKAS_dtFreezed_sLKA + 2.22044605E-16F;

  /* Product: '<S24>/Divide1' incorporates:
   *  Sum: '<S24>/Add1'
   */
  VfLKAS_Jerk2 = (VfLKAS_AeFreezed_sLKA - VfLKAS_AmFreezed_sLKA) /
    rtb_uDLookupTable_o3xc;

  /* RelationalOperator: '<S21>/Relational Operator' */
  VbLKAS_Trigger_Traj_2 = (LKAS_subsystem_integrated_B.T_AftIntvStart_gady >=
    VfLKAS_dtFreezed_sLKA);

  /* Outputs for Enabled SubSystem: '<S21>/TargetDistCalc_2' incorporates:
   *  EnablePort: '<S27>/Enable'
   */
  if (VbLKAS_Trigger_Traj_2)
  {
    if (!LKAS_subsystem_integrated_DW.TargetDistCalc_2_MODE)
    {
      /* InitializeConditions for UnitDelay: '<S27>/Unit Delay2' */
      LKAS_subsystem_integrated_DW.UnitDelay2_DSTATE = 0.0F;

      /* InitializeConditions for UnitDelay: '<S27>/Unit Delay3' */
      LKAS_subsystem_integrated_DW.UnitDelay3_DSTATE = 0.0F;
      LKAS_subsystem_integrated_DW.TargetDistCalc_2_MODE = true;
    }

    /* Sum: '<S27>/Add7' incorporates:
     *  Product: '<S27>/Product4'
     *  Sum: '<S27>/Add10'
     */
    VfLKAS_TargetA_2 = VfLKAS_AmFreezed_sLKA + (VfLKAS_Jerk2 *
      (LKAS_subsystem_integrated_B.T_AftIntvStart_gady - VfLKAS_dtFreezed_sLKA));

    /* Sum: '<S27>/Add6' incorporates:
     *  Constant: '<S27>/Constant2'
     *  Product: '<S27>/Product3'
     *  UnitDelay: '<S27>/Unit Delay2'
     */
    rtb_Add6 = (VfLKAS_TargetA_2 * 0.01F) +
      LKAS_subsystem_integrated_DW.UnitDelay2_DSTATE;

    /* Sum: '<S27>/Add8' incorporates:
     *  Gain: '<S29>/Gain'
     *  Product: '<S29>/Product6'
     *  Sum: '<S29>/Add11'
     *  Sum: '<S29>/Add12'
     */
    rtb_Add8 = (VfLKAS_V0Freezed_sLKA + (VfLKAS_dtFreezed_sLKA * (0.5F *
      (VfLKAS_A0Freezed_sLKA + VfLKAS_AmFreezed_sLKA)))) + rtb_Add6;

    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S27>/Constant1'
     *  Constant: '<S27>/Constant3'
     *  Product: '<S27>/Product5'
     *  Sum: '<S27>/Add9'
     *  UnitDelay: '<S27>/Unit Delay3'
     */
    if (LKAS_subsystem_integrated_B.T_AftIntvStart_gady > 0.0F)
    {
      VfLKAS_TargetDist_2 = (rtb_Add8 * 0.01F) +
        LKAS_subsystem_integrated_DW.UnitDelay3_DSTATE;
    }
    else
    {
      VfLKAS_TargetDist_2 = 0.0F;
    }

    /* End of Switch: '<S27>/Switch1' */

    /* Switch: '<S27>/Switch' incorporates:
     *  Constant: '<S27>/Constant'
     */
    if (LKAS_subsystem_integrated_B.T_AftIntvStart_gady > 0.0F)
    {
      VfLKAS_TargetV_2 = rtb_Add8;
    }
    else
    {
      VfLKAS_TargetV_2 = 0.0F;
    }

    /* End of Switch: '<S27>/Switch' */

    /* Update for UnitDelay: '<S27>/Unit Delay2' */
    LKAS_subsystem_integrated_DW.UnitDelay2_DSTATE = rtb_Add6;

    /* Update for UnitDelay: '<S27>/Unit Delay3' */
    LKAS_subsystem_integrated_DW.UnitDelay3_DSTATE = VfLKAS_TargetDist_2;
  }
  else
  {
    if (LKAS_subsystem_integrated_DW.TargetDistCalc_2_MODE)
    {
      LKAS_subsystem_integrated_DW.TargetDistCalc_2_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S21>/TargetDistCalc_2' */

  /* Switch: '<S22>/SWCH_1' incorporates:
   *  Constant: '<S21>/Constant1'
   *  Logic: '<S22>/LOGOP_1'
   *  Logic: '<S22>/LOGOP_2'
   *  Logic: '<S30>/LOGOP_1'
   *  Logic: '<S30>/LOGOP_2'
   *  Logic: '<S31>/LOGOP_1'
   *  Logic: '<S31>/LOGOP_2'
   *  UnitDelay: '<S30>/UD_1'
   *  UnitDelay: '<S31>/UD_1'
   */
  if (((!rtb_RelationalOperator1) || (rtb_RelationalOperator1 &&
        (!LKAS_subsystem_integrated_DW.UD_1_DSTATE_pnoz))) || ((false) &&
       (!LKAS_subsystem_integrated_DW.UD_1_DSTATE_gfb2)))
  {
    VfLKAS_TargetDist_Freezed2 = VfLKAS_TargetDist_2;
  }

  /* End of Switch: '<S22>/SWCH_1' */

  /* Product: '<S24>/Divide' incorporates:
   *  Sum: '<S24>/Add'
   */
  VfLKAS_Jerk1 = (VfLKAS_AmFreezed_sLKA - VfLKAS_A0Freezed_sLKA) /
    rtb_uDLookupTable_o3xc;

  /* Logic: '<S21>/Logical Operator' incorporates:
   *  Constant: '<S21>/Constant2'
   *  RelationalOperator: '<S21>/Relational Operator2'
   *  RelationalOperator: '<S21>/Relational Operator3'
   */
  VbLKAS_Trigger_Traj_1 = ((LKAS_subsystem_integrated_B.T_AftIntvStart_gady >
    ((real32_T)(false ? 1.0F : 0.0F))) &&
    (LKAS_subsystem_integrated_B.T_AftIntvStart_gady < VfLKAS_dtFreezed_sLKA));

  /* Outputs for Enabled SubSystem: '<S21>/TargetDistCalc_1' incorporates:
   *  EnablePort: '<S26>/Enable'
   */
  if (VbLKAS_Trigger_Traj_1)
  {
    if (!LKAS_subsystem_integrated_DW.TargetDistCalc_1_MODE)
    {
      /* InitializeConditions for UnitDelay: '<S26>/Unit Delay2' */
      LKAS_subsystem_integrated_DW.UnitDelay2_DSTATE_ki2g = 0.0F;

      /* InitializeConditions for UnitDelay: '<S26>/Unit Delay1' */
      LKAS_subsystem_integrated_DW.UnitDelay1_DSTATE_kq0m = 0.0F;
      LKAS_subsystem_integrated_DW.TargetDistCalc_1_MODE = true;
    }

    /* Sum: '<S26>/Add3' incorporates:
     *  Product: '<S26>/Product1'
     */
    VfLKAS_TargetA_1 = VfLKAS_A0Freezed_sLKA + (VfLKAS_Jerk1 *
      LKAS_subsystem_integrated_B.T_AftIntvStart_gady);

    /* Sum: '<S26>/Add2' incorporates:
     *  Constant: '<S26>/Constant'
     *  Product: '<S26>/Product'
     *  UnitDelay: '<S26>/Unit Delay2'
     */
    VfLKAS_V0Increment = (VfLKAS_TargetA_1 * 0.01F) +
      LKAS_subsystem_integrated_DW.UnitDelay2_DSTATE_ki2g;

    /* Sum: '<S26>/Add4' */
    rtb_uDLookupTable_o3xc = VfLKAS_V0Freezed_sLKA + VfLKAS_V0Increment;

    /* Switch: '<S26>/Switch1' incorporates:
     *  Constant: '<S26>/Constant1'
     *  Constant: '<S26>/Constant3'
     *  Product: '<S26>/Product2'
     *  Sum: '<S26>/Add5'
     *  UnitDelay: '<S26>/Unit Delay1'
     */
    if (LKAS_subsystem_integrated_B.T_AftIntvStart_gady > 0.0F)
    {
      VfLKAS_TargetDist_1 = (rtb_uDLookupTable_o3xc * 0.01F) +
        LKAS_subsystem_integrated_DW.UnitDelay1_DSTATE_kq0m;
    }
    else
    {
      VfLKAS_TargetDist_1 = 0.0F;
    }

    /* End of Switch: '<S26>/Switch1' */

    /* Switch: '<S26>/Switch' incorporates:
     *  Constant: '<S26>/Constant2'
     */
    if (LKAS_subsystem_integrated_B.T_AftIntvStart_gady > 0.0F)
    {
      VfLKAS_TargetV_1 = rtb_uDLookupTable_o3xc;
    }
    else
    {
      VfLKAS_TargetV_1 = 0.0F;
    }

    /* End of Switch: '<S26>/Switch' */

    /* Update for UnitDelay: '<S26>/Unit Delay2' */
    LKAS_subsystem_integrated_DW.UnitDelay2_DSTATE_ki2g = VfLKAS_V0Increment;

    /* Update for UnitDelay: '<S26>/Unit Delay1' */
    LKAS_subsystem_integrated_DW.UnitDelay1_DSTATE_kq0m = VfLKAS_TargetDist_1;
  }
  else
  {
    if (LKAS_subsystem_integrated_DW.TargetDistCalc_1_MODE)
    {
      LKAS_subsystem_integrated_DW.TargetDistCalc_1_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S21>/TargetDistCalc_1' */

  /* Switch: '<S23>/SWCH_1' incorporates:
   *  Constant: '<S21>/Constant'
   *  Logic: '<S23>/LOGOP_1'
   *  Logic: '<S23>/LOGOP_2'
   *  Logic: '<S32>/LOGOP_1'
   *  Logic: '<S32>/LOGOP_2'
   *  Logic: '<S33>/LOGOP_1'
   *  Logic: '<S33>/LOGOP_2'
   *  UnitDelay: '<S32>/UD_1'
   *  UnitDelay: '<S33>/UD_1'
   */
  if (((!VbLKAS_Trigger_Traj_2) || (VbLKAS_Trigger_Traj_2 &&
        (!LKAS_subsystem_integrated_DW.UD_1_DSTATE_dgmk))) || ((false) &&
       (!LKAS_subsystem_integrated_DW.UD_1_DSTATE_lq44)))
  {
    VfLKAS_TargetDist_Freezed1 = VfLKAS_TargetDist_1;
  }

  /* End of Switch: '<S23>/SWCH_1' */

  /* MATLAB Function: '<S21>/TargetCalculation' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S28>/Constant1'
   *  Constant: '<S28>/Constant2'
   */
  if (LKAS_subsystem_integrated_B.T_AftIntvStart_gady < VfLKAS_dtFreezed_sLKA)
  {
    VfLKAS_TargetDist = VfLKAS_TargetDist_1;
    rtb_uDLookupTable_o3xc = VfLKAS_TargetV_1;
    rtb_Add6 = VfLKAS_TargetA_1;
  }
  else if ((LKAS_subsystem_integrated_B.T_AftIntvStart_gady >=
            VfLKAS_dtFreezed_sLKA) &&
           (LKAS_subsystem_integrated_B.T_AftIntvStart_gady <
            (VfLKAS_dtFreezed_sLKA * 2.0F)))
  {
    VfLKAS_TargetDist = VfLKAS_TargetDist_Freezed1 + VfLKAS_TargetDist_2;
    rtb_uDLookupTable_o3xc = VfLKAS_TargetV_2;
    rtb_Add6 = VfLKAS_TargetA_2;
  }
  else
  {
    VfLKAS_TargetDist = (VfLKAS_TargetDist_Freezed1 + VfLKAS_TargetDist_Freezed2)
      + 0.0F;
    rtb_uDLookupTable_o3xc = 0.0F;
    rtb_Add6 = 0.0F;
  }

  /* End of MATLAB Function: '<S21>/TargetCalculation' */

  /* RelationalOperator: '<S34>/Relational Operator' incorporates:
   *  Constant: '<S40>/Constant'
   */
  rtb_RelationalOperator_njkr = (LKAS_subsystem_integrated_B.IntvTyp_sLKA !=
    LKAS_NoIntvTyp);

  /* Switch: '<S38>/SWCH_1' incorporates:
   *  Constant: '<S16>/Constant'
   *  Constant: '<S37>/Constant'
   *  Logic: '<S38>/LOGOP_1'
   *  Logic: '<S38>/LOGOP_2'
   *  Logic: '<S42>/LOGOP_1'
   *  Logic: '<S42>/LOGOP_2'
   *  Logic: '<S43>/LOGOP_1'
   *  Logic: '<S43>/LOGOP_2'
   *  RelationalOperator: '<S16>/Relational Operator1'
   *  UnitDelay: '<S38>/UD_2'
   *  UnitDelay: '<S42>/UD_1'
   *  UnitDelay: '<S43>/UD_1'
   */
  if (((!rtb_RelationalOperator_njkr) || (rtb_RelationalOperator_njkr &&
        (!LKAS_subsystem_integrated_DW.UD_1_DSTATE_mthg))) || ((false) &&
       (!LKAS_subsystem_integrated_DW.UD_1_DSTATE_hb12)))
  {
    rtb_SWCH_1 = (LKAS_subsystem_integrated_B.IntvSide_sLKA == LKAS_IntvSideLe);
  }
  else
  {
    rtb_SWCH_1 = LKAS_subsystem_integrated_DW.UD_2_DSTATE_gxj0;
  }

  /* End of Switch: '<S38>/SWCH_1' */

  /* Switch: '<S17>/Switch2' incorporates:
   *  Constant: '<S17>/Constant3'
   *  Gain: '<S17>/Gain2'
   */
  if (KbLKAS_TargetSwitch_Temp)
  {
    /* Switch: '<S17>/Switch1' incorporates:
     *  Gain: '<S17>/Gain2'
     */
    if (rtb_SWCH_1)
    {
      VfLKAS_TargetV = (-1.0F) * rtb_uDLookupTable_o3xc;
    }
    else
    {
      VfLKAS_TargetV = rtb_uDLookupTable_o3xc;
    }

    /* End of Switch: '<S17>/Switch1' */
  }
  else
  {
    VfLKAS_TargetV = (-1.0F) * rtb_uDLookupTable_o3xc;
  }

  /* End of Switch: '<S17>/Switch2' */

  /* Switch: '<S39>/Switch' */
  if (rtb_SWCH_1)
  {
    VfLKAS_Offst_Actual = LKAS_subsystem_integrated_B.Out_hpcs;
  }
  else
  {
    VfLKAS_Offst_Actual = LKAS_subsystem_integrated_B.Out_mwpy;
  }

  /* End of Switch: '<S39>/Switch' */

  /* Switch: '<S44>/SWCH_1' incorporates:
   *  Constant: '<S39>/Constant1'
   *  Logic: '<S44>/LOGOP_1'
   *  Logic: '<S44>/LOGOP_2'
   *  Logic: '<S45>/LOGOP_1'
   *  Logic: '<S45>/LOGOP_2'
   *  Logic: '<S46>/LOGOP_1'
   *  Logic: '<S46>/LOGOP_2'
   *  UnitDelay: '<S44>/UD_2'
   *  UnitDelay: '<S45>/UD_1'
   *  UnitDelay: '<S46>/UD_1'
   */
  if (((!rtb_RelationalOperator_njkr) || (rtb_RelationalOperator_njkr &&
        (!LKAS_subsystem_integrated_DW.UD_1_DSTATE_kstr))) || ((false) &&
       (!LKAS_subsystem_integrated_DW.UD_1_DSTATE_pd1w)))
  {
    rtb_SWCH_1_d5lo =
      LKAS_subsystem_integrated_B.TrajData.ZeroTrajectoryFound_sLKA;
  }
  else
  {
    rtb_SWCH_1_d5lo = LKAS_subsystem_integrated_DW.UD_2_DSTATE_cfd1;
  }

  /* End of Switch: '<S44>/SWCH_1' */

  /* Switch: '<S50>/SWCH_1' incorporates:
   *  Constant: '<S18>/Constant'
   *  Logic: '<S50>/LOGOP_1'
   *  Logic: '<S50>/LOGOP_2'
   *  Logic: '<S57>/LOGOP_1'
   *  Logic: '<S57>/LOGOP_2'
   *  Logic: '<S58>/LOGOP_1'
   *  Logic: '<S58>/LOGOP_2'
   *  UnitDelay: '<S57>/UD_1'
   *  UnitDelay: '<S58>/UD_1'
   */
  if (((!rtb_RelationalOperator) || (rtb_RelationalOperator &&
        (!LKAS_subsystem_integrated_DW.UD_1_DSTATE_a0xo))) || ((false) &&
       (!LKAS_subsystem_integrated_DW.UD_1_DSTATE_ftw4)))
  {
    /* Switch: '<S39>/Switch1' */
    if (rtb_SWCH_1_d5lo)
    {
      VfLKAS_Offst_start = LKAS_subsystem_integrated_B.TrajData.EndOffset_sLKA;
    }
    else
    {
      VfLKAS_Offst_start = VfLKAS_Offst_Actual;
    }

    /* End of Switch: '<S39>/Switch1' */
  }

  /* End of Switch: '<S50>/SWCH_1' */

  /* Sum: '<S17>/Add' */
  VfLKAS_DesiredDistToEdge = VfLKAS_Offst_start + VfLKAS_TargetDist;

  /* Sum: '<S17>/Add1' */
  VfLKAS_OffstError = VfLKAS_Offst_Actual - VfLKAS_DesiredDistToEdge;

  /* Sum: '<S17>/Add3' incorporates:
   *  UnitDelay: '<S17>/Unit Delay'
   */
  VfLKAS_Offst_ErrorDiff = VfLKAS_OffstError -
    LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_g0md;

  /* DeadZone: '<S17>/Dead Zone1' */
  if (VfLKAS_OffstError > KfLKAS_d_OffstCtrlr_DeadZone)
  {
    rtb_uDLookupTable_o3xc = VfLKAS_OffstError - KfLKAS_d_OffstCtrlr_DeadZone;
  }
  else if (VfLKAS_OffstError >= (-KfLKAS_d_OffstCtrlr_DeadZone))
  {
    rtb_uDLookupTable_o3xc = 0.0F;
  }
  else
  {
    rtb_uDLookupTable_o3xc = VfLKAS_OffstError - (-KfLKAS_d_OffstCtrlr_DeadZone);
  }

  /* End of DeadZone: '<S17>/Dead Zone1' */

  /* Sum: '<S17>/Add5' incorporates:
   *  Abs: '<S17>/Abs'
   *  Lookup_n-D: '<S17>/1-D Lookup Table'
   *  Lookup_n-D: '<S17>/1-D Lookup Table2'
   *  MATLAB Function: '<S17>/OffstController'
   */
  VfLKAS_Vlat_Desired = VfLKAS_TargetV + ((rtb_uDLookupTable_o3xc *
    look2_iflf_binlc((real32_T)fabs((real_T)
    LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.Vlat_sLKA),
                     LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.Vlong_sLKA,
                     KtLKAS_AXIS_OffstCtrlPropGain_Vlat,
                     KtLKAS_AXIS_OffstCtrlPropGain_Vlong,
                     KtLKAS_r_OffstCtrlPropGain,
                     LKAS_subsystem_integrate_ConstP.uDLookupTable_maxIndex, 6U))
    + (VfLKAS_Offst_ErrorDiff * look1_iflf_binlc
       (LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.Vlong_sLKA,
        KtLKAS_AXIS_OffstCtrlDiffGain_Vlong, KtLKAS_r_OffstCtrlDiffGain, 8U)));

  /* Sum: '<S17>/Sum' */
  VfLKAS_VlatError = VfLKAS_Vlat_Desired -
    LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.Vlat_sLKA;

  /* Sum: '<S17>/Add4' incorporates:
   *  UnitDelay: '<S17>/Unit Delay1'
   */
  VfLKAS_Vlat_ErrorDiff = VfLKAS_VlatError -
    LKAS_subsystem_integrated_DW.UnitDelay1_DSTATE_f4ht;

  /* Switch: '<S17>/Switch3' incorporates:
   *  Constant: '<S17>/Constant'
   *  Gain: '<S17>/Gain1'
   */
  if (KbLKAS_TargetSwitch_Temp)
  {
    /* Switch: '<S17>/Switch' incorporates:
     *  Gain: '<S17>/Gain1'
     */
    if (rtb_SWCH_1)
    {
      VfLKAS_TargetA = (-1.0F) * rtb_Add6;
    }
    else
    {
      VfLKAS_TargetA = rtb_Add6;
    }

    /* End of Switch: '<S17>/Switch' */
  }
  else
  {
    VfLKAS_TargetA = (-1.0F) * rtb_Add6;
  }

  /* End of Switch: '<S17>/Switch3' */

  /* DeadZone: '<S17>/Dead Zone2' */
  if (VfLKAS_VlatError > KfLKAS_v_VlatCtrlr_DeadZone)
  {
    rtb_uDLookupTable_o3xc = VfLKAS_VlatError - KfLKAS_v_VlatCtrlr_DeadZone;
  }
  else if (VfLKAS_VlatError >= (-KfLKAS_v_VlatCtrlr_DeadZone))
  {
    rtb_uDLookupTable_o3xc = 0.0F;
  }
  else
  {
    rtb_uDLookupTable_o3xc = VfLKAS_VlatError - (-KfLKAS_v_VlatCtrlr_DeadZone);
  }

  /* End of DeadZone: '<S17>/Dead Zone2' */

  /* Sum: '<S17>/Sum1' incorporates:
   *  Constant: '<S17>/Constant1'
   *  Constant: '<S17>/Constant4'
   *  MATLAB Function: '<S17>/VlatController'
   */
  VfLKAS_Alat_Desired = VfLKAS_TargetA + ((rtb_uDLookupTable_o3xc *
    KfLKAS_r_PGainForVlat) + (VfLKAS_Vlat_ErrorDiff * ((real32_T)0.0)));

  /* Sum: '<S17>/Add2' incorporates:
   *  Constant: '<S17>/Constant2'
   *  Sum: '<S19>/Add'
   */
  rtb_Add6 = LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.Vlong_sLKA +
    2.22044605E-16F;

  /* Product: '<S17>/Divide' incorporates:
   *  Sum: '<S17>/Add2'
   */
  VfLKAS_YawRateDesired = VfLKAS_Alat_Desired / rtb_Add6;

  /* MATLAB Function: '<S19>/TwoWheelModel' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S19>/Constant1'
   */
  rtb_uDLookupTable_o3xc = KfLKAS_C_CfForLatCtrl * KfLKAS_C_CrForLatCtrl;

  /* Gain: '<S19>/Gain' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S19>/Constant1'
   *  Constant: '<S19>/Constant2'
   *  Constant: '<S19>/Constant3'
   *  Constant: '<S19>/Constant4'
   *  Constant: '<S19>/Constant5'
   *  Constant: '<S19>/Constant6'
   *  MATLAB Function: '<S19>/TwoWheelModel'
   *  Product: '<S19>/Divide'
   *  Product: '<S19>/Product'
   *  Sum: '<S19>/Sum'
   */
  VfLKAS_SteerAngleRequest = 57.2957802F * (0.0F +
    ((((KfLKAS_r_StrRatioForLatCtrl * (((((((((-KfLKAS_C_CfForLatCtrl) *
    KfLKAS_m_MForLatCtrl) *
    LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.Vlong_sLKA) *
    LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.Vlong_sLKA) *
    KfLKAS_d_LfForLatCtrl) + ((((KfLKAS_C_CrForLatCtrl * KfLKAS_m_MForLatCtrl) *
    LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.Vlong_sLKA) *
    LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.Vlong_sLKA) *
    KfLKAS_d_LrForLatCtrl)) + ((rtb_uDLookupTable_o3xc * KfLKAS_d_LfForLatCtrl) *
    KfLKAS_d_LfForLatCtrl)) + ((((2.0F * KfLKAS_C_CfForLatCtrl) *
    KfLKAS_C_CrForLatCtrl) * KfLKAS_d_LfForLatCtrl) * KfLKAS_d_LrForLatCtrl)) +
    ((rtb_uDLookupTable_o3xc * KfLKAS_d_LrForLatCtrl) * KfLKAS_d_LrForLatCtrl)))
       / ((rtb_uDLookupTable_o3xc * (KfLKAS_d_LfForLatCtrl +
    KfLKAS_d_LrForLatCtrl)) + 2.22044605E-16F)) / rtb_Add6) *
     VfLKAS_YawRateDesired));

  /* Switch: '<S19>/Switch' incorporates:
   *  Constant: '<S67>/Constant11'
   *  Constant: '<S67>/Constant12'
   *  Inport: '<Root>/COMM_CANR_Databus'
   *  Logic: '<S67>/Logical Operator'
   *  RelationalOperator: '<S67>/Relational Operator'
   *  RelationalOperator: '<S67>/Relational Operator1'
   *  UnitDelay: '<S19>/Unit Delay'
   *  UnitDelay: '<S67>/Unit Delay1'
   */
  if ((rtb_RelationalOperator == true) &&
      (LKAS_subsystem_integrated_DW.UnitDelay1_DSTATE_mlnf == false))
  {
    rtb_Add6 = VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle;
  }
  else
  {
    rtb_Add6 = VfLKAS_StrAngFilted;
  }

  /* End of Switch: '<S19>/Switch' */

  /* Sum: '<S19>/Add1' incorporates:
   *  Constant: '<S19>/Constant10'
   *  Constant: '<S19>/Constant8'
   *  Constant: '<S19>/Constant9'
   *  Product: '<S19>/Product1'
   *  Product: '<S19>/Product2'
   *  Sum: '<S19>/Add2'
   */
  VfLKAS_StrAngFilted = (VfLKAS_SteerAngleRequest * (1.0F - KfLKAS_k_StrAngFilt))
    + (rtb_Add6 * KfLKAS_k_StrAngFilt);

  /* Lookup_n-D: '<S19>/1-D Lookup Table1' */
  rtb_Add6 = look1_iflf_binlx
    (LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.Vlong_sLKA,
     KtLKAS_AXIS_StrAngSaturation, KtLKAS_Ang_StrAngUpperSaturation, 8U);

  /* Lookup_n-D: '<S19>/1-D Lookup Table' */
  rtb_uDLookupTable_o3xc = look1_iflf_binlx
    (LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.Vlong_sLKA,
     KtLKAS_AXIS_StrAngSaturation, KtLKAS_Ang_StrAngLwrSaturation, 8U);

  /* Switch: '<S68>/Switch2' incorporates:
   *  RelationalOperator: '<S68>/LowerRelop1'
   *  RelationalOperator: '<S68>/UpperRelop'
   *  Switch: '<S68>/Switch'
   */
  if (VfLKAS_StrAngFilted > rtb_Add6)
  {
    VfLKAS_SteerAngleRequest_Saturated = rtb_Add6;
  }
  else if (VfLKAS_StrAngFilted < rtb_uDLookupTable_o3xc)
  {
    /* Switch: '<S68>/Switch' */
    VfLKAS_SteerAngleRequest_Saturated = rtb_uDLookupTable_o3xc;
  }
  else
  {
    VfLKAS_SteerAngleRequest_Saturated = VfLKAS_StrAngFilted;
  }

  /* End of Switch: '<S68>/Switch2' */

  /* Sum: '<S19>/Add3' incorporates:
   *  Constant: '<S19>/Constant11'
   */
  LKAS_subsystem_integrated_B.Add3 = VfLKAS_SteerAngleRequest_Saturated +
    KfLKAS_Ang_SteerOffset;

  /* RelationalOperator: '<S41>/Compare' incorporates:
   *  Constant: '<S41>/Constant'
   */
  rtb_Compare = (LKAS_subsystem_integrated_B.IntvTyp_sLKA_pzex ==
                 LKAS_SftyLaneKeepAid);

  /* Switch: '<S35>/Switch' */
  if (rtb_Compare)
  {
    rtb_Compare_0 = LKAS_subsystem_integrated_B.IntvSide_sLKA_k4lx;
  }
  else
  {
    rtb_Compare_0 =
      LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.IntvSideReq_sLKA;
  }

  /* End of Switch: '<S35>/Switch' */

  /* RelationalOperator: '<S16>/Relational Operator' incorporates:
   *  Constant: '<S36>/Constant'
   */
  rtb_RelationalOperator_kjqa = (rtb_Compare_0 == LKAS_IntvSideLe);

  /* Switch: '<S35>/Switch1' */
  if (rtb_Compare)
  {
    rtb_Switch1_deys = LKAS_subsystem_integrated_B.CtrlRef_sLKA;
  }
  else
  {
    rtb_Switch1_deys =
      LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.CtrlRefReq_sLKA;
  }

  /* End of Switch: '<S35>/Switch1' */

  /* Update for UnitDelay: '<S63>/UD_1' */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_eh0l = rtb_RelationalOperator;

  /* Update for UnitDelay: '<S64>/UD_1' incorporates:
   *  Constant: '<S18>/Constant5'
   */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_oh3u = false;

  /* Update for UnitDelay: '<S30>/UD_1' */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_pnoz = rtb_RelationalOperator1;

  /* Update for UnitDelay: '<S31>/UD_1' incorporates:
   *  Constant: '<S21>/Constant1'
   */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_gfb2 = false;

  /* Update for UnitDelay: '<S59>/UD_1' */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_mfkr = rtb_RelationalOperator;

  /* Update for UnitDelay: '<S60>/UD_1' incorporates:
   *  Constant: '<S18>/Constant3'
   */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_o0s5 = false;

  /* Update for UnitDelay: '<S65>/UD_1' */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_hgvk = rtb_RelationalOperator;

  /* Update for UnitDelay: '<S66>/UD_1' incorporates:
   *  Constant: '<S18>/Constant1'
   */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_nu3p = false;

  /* Update for UnitDelay: '<S55>/UD_1' */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_derr = rtb_RelationalOperator;

  /* Update for UnitDelay: '<S56>/UD_1' incorporates:
   *  Constant: '<S18>/Constant2'
   */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_mrje = false;

  /* Update for UnitDelay: '<S61>/UD_1' */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_axse = rtb_RelationalOperator;

  /* Update for UnitDelay: '<S62>/UD_1' incorporates:
   *  Constant: '<S18>/Constant4'
   */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_acl5 = false;

  /* Update for UnitDelay: '<S32>/UD_1' */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_dgmk = VbLKAS_Trigger_Traj_2;

  /* Update for UnitDelay: '<S33>/UD_1' incorporates:
   *  Constant: '<S21>/Constant'
   */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_lq44 = false;

  /* Update for UnitDelay: '<S42>/UD_1' */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_mthg = rtb_RelationalOperator_njkr;

  /* Update for UnitDelay: '<S43>/UD_1' incorporates:
   *  Constant: '<S16>/Constant'
   */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_hb12 = false;

  /* Update for UnitDelay: '<S38>/UD_2' */
  LKAS_subsystem_integrated_DW.UD_2_DSTATE_gxj0 = rtb_SWCH_1;

  /* Update for UnitDelay: '<S45>/UD_1' */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_kstr = rtb_RelationalOperator_njkr;

  /* Update for UnitDelay: '<S46>/UD_1' incorporates:
   *  Constant: '<S39>/Constant1'
   */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_pd1w = false;

  /* Update for UnitDelay: '<S44>/UD_2' */
  LKAS_subsystem_integrated_DW.UD_2_DSTATE_cfd1 = rtb_SWCH_1_d5lo;

  /* Update for UnitDelay: '<S57>/UD_1' */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_a0xo = rtb_RelationalOperator;

  /* Update for UnitDelay: '<S58>/UD_1' incorporates:
   *  Constant: '<S18>/Constant'
   */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_ftw4 = false;

  /* Update for UnitDelay: '<S17>/Unit Delay' */
  LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_g0md = VfLKAS_OffstError;

  /* Update for UnitDelay: '<S17>/Unit Delay1' */
  LKAS_subsystem_integrated_DW.UnitDelay1_DSTATE_f4ht = VfLKAS_VlatError;

  /* Update for UnitDelay: '<S67>/Unit Delay1' */
  LKAS_subsystem_integrated_DW.UnitDelay1_DSTATE_mlnf = rtb_RelationalOperator;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
