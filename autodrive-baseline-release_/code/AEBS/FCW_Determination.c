/*
 * File: FCW_Determination.c
 *
 * Code generated for Simulink model 'AEBS_subsystem_integrated'.
 *
 * Model version                  : 1.3091
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 16:35:01 2020
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

#include "FCW_Determination.h"

/* Include model header file for global data */
#include "AEBS_subsystem_integrated.h"
#include "AEBS_subsystem_integrated_private.h"
#include "look1_iflf_binlc.h"

/* System initialize for atomic system: '<S3>/FCW_Determination' */
void AEBS_sub_FCW_Determination_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S219>/Unit Delay1' */
  AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_airs = ((uint16_T)60000U);

  /* SystemInitialize for Chart: '<S205>/Stop_Moving_Estimation' */
  AEB_Stop_Moving_Estimation_Init
    (&AEBS_subsystem_integrated_B.vehicle_standstill,
     &AEBS_subsystem_integrated_DW.sf_Stop_Moving_Estimation_licw);

  /* SystemInitialize for Chart: '<S213>/Chart' */
  AEBS_subsystem__Chart_k51z_Init(&AEBS_subsystem_integrated_DW.sf_Chart_avmp);

  /* SystemInitialize for Chart: '<S214>/Chart' */
  AEBS_subsystem__Chart_k51z_Init(&AEBS_subsystem_integrated_DW.sf_Chart_omyv);

  /* SystemInitialize for Atomic SubSystem: '<S10>/DetermineFCWStatus' */
  AEBS_su_DetermineFCWStatus_Init();

  /* End of SystemInitialize for SubSystem: '<S10>/DetermineFCWStatus' */
}

/* Output and update for atomic system: '<S3>/FCW_Determination' */
void AEBS_subsyste_FCW_Determination(void)
{
  boolean_T rtb_UnitDelay_depn;
  uint16_T rtb_Switch_ht3u;
  int32_T rtb_UnitDelay1_bsc4;
  uint32_T rtb_DataTypeConversion;
  boolean_T rtb_RelationalOperator;
  uint32_T rtb_DataTypeConversion_pilu;
  boolean_T rtb_y;
  boolean_T rtb_LogicalOperator1_c2mo;
  uint32_T rtb_DataTypeConversion1;
  uint8_T rtb_state;
  uint8_T rtb_state_p1u2;
  real32_T tmp;
  boolean_T VfAEBS_FCWLev1_active_tmp;
  boolean_T VbAEBS_FCW_inhibit_tmp;

  /* Logic: '<S206>/Logical Operator' incorporates:
   *  Constant: '<S206>/Constant4'
   *  Inport: '<Root>/DCSN_DataBus'
   *  Logic: '<S206>/Logical Operator1'
   *  RelationalOperator: '<S206>/Relational Operator'
   *  S-Function (sfix_bitop): '<S206>/Bitwise Operator'
   */
  VfAEBS_FCW_enabled = ((VsDCSN_DataBus.EnablingFlags_Group.fcw_feature_enable) &&
                        (!((AEBS_subsystem_integrated_B.Switch2 &
    AEBS_subsystem_integrate_ConstB.DataTypeConversion) != ((uint8_T)0U))));

  /* MinMax: '<S205>/MinMax' incorporates:
   *  Constant: '<S205>/Constant'
   *  Constant: '<S205>/Constant1'
   */
  if (KfAEBS_CTRL_PeriodFunctionCall > 0.001F)
  {
    tmp = KfAEBS_CTRL_PeriodFunctionCall;
  }
  else
  {
    tmp = 0.001F;
  }

  /* End of MinMax: '<S205>/MinMax' */

  /* DataTypeConversion: '<S205>/Data Type Conversion' incorporates:
   *  Constant: '<S205>/Constant8'
   *  Product: '<S205>/Divide'
   */
  rtb_DataTypeConversion = (uint32_T)((real32_T)(KfAEBS_t_Speed_DebounceTime /
    tmp));

  /* Chart: '<S205>/Stop_Moving_Estimation' incorporates:
   *  Constant: '<S205>/Constant6'
   *  Constant: '<S205>/Constant7'
   */
  AEBS_sub_Stop_Moving_Estimation(VfAEBS_veh_speed_used,
    KfAEBS_v_Speed_StandStillThrsh, KfAEBS_v_Speed_DeltaStStThrsh,
    rtb_DataTypeConversion, &AEBS_subsystem_integrated_B.vehicle_standstill,
    &AEBS_subsystem_integrated_DW.sf_Stop_Moving_Estimation_licw);

  /* RelationalOperator: '<S210>/Relational Operator1' incorporates:
   *  Constant: '<S210>/Constant2'
   */
  VbAEBS_FCW_inhbt_AccPedPos = (AEBS_subsystem_integrated_B.DataTypeConversion5 >=
    KfAEBS_AccPdl_InhbtDeact_thrshld);

  /* RelationalOperator: '<S210>/Relational Operator2' incorporates:
   *  Constant: '<S210>/Constant3'
   */
  VbAEBS_FCW_inhbt_VehAcc = (VfAEBS_veh_acc_used <=
    KfAEBS_VehAcc_inhbt_FCW_thrshld);

  /* UnitDelay: '<S10>/Unit Delay' */
  rtb_UnitDelay_depn = AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_m5j4;

  /* Switch: '<S219>/Switch' incorporates:
   *  Constant: '<S219>/Constant2'
   *  Constant: '<S219>/Constant3'
   *  Logic: '<S219>/Logical Operator'
   *  Logic: '<S219>/Logical Operator4'
   *  Sum: '<S219>/Add'
   *  UnitDelay: '<S219>/Unit Delay'
   *  UnitDelay: '<S219>/Unit Delay1'
   */
  if ((AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_j1ho) &&
      (!rtb_UnitDelay_depn))
  {
    rtb_Switch_ht3u = ((uint16_T)0U);
  }
  else
  {
    rtb_Switch_ht3u = (uint16_T)(((uint32_T)((uint16_T)1U)) + ((uint32_T)
      AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_airs));
  }

  /* End of Switch: '<S219>/Switch' */

  /* Saturate: '<S219>/Saturation' */
  if (rtb_Switch_ht3u < ((uint16_T)60000U))
  {
  }
  else
  {
    rtb_Switch_ht3u = ((uint16_T)60000U);
  }

  /* End of Saturate: '<S219>/Saturation' */

  /* RelationalOperator: '<S219>/Relational Operator' incorporates:
   *  Constant: '<S219>/Constant'
   *  Constant: '<S219>/Constant4'
   *  Product: '<S219>/Product'
   */
  VbAEBS_FCW_inhbt_DeactTime = ((((real32_T)rtb_Switch_ht3u) *
    KfAEBS_CTRL_PeriodFunctionCall) < KfAEBS_t_Time_TwiceFCWActive);

  /* Logic: '<S210>/Logical Operator2' incorporates:
   *  Logic: '<S204>/Logical Operator'
   */
  VbAEBS_FCW_inhibit_tmp = !AEBS_subsystem_integrated_B.Switch.has_obs_VIP;

  /* Logic: '<S210>/Logical Operator1' incorporates:
   *  Constant: '<S210>/Constant1'
   *  Logic: '<S210>/Logical Operator2'
   *  RelationalOperator: '<S210>/Relational Operator3'
   */
  VbAEBS_FCW_inhibit = (((((AEBS_subsystem_integrated_B.DataTypeConversion3 ==
    KfAEBS_Gear_Value_R) || VbAEBS_FCW_inhibit_tmp) ||
    VbAEBS_FCW_inhbt_AccPedPos) || VbAEBS_FCW_inhbt_VehAcc) ||
                        VbAEBS_FCW_inhbt_DeactTime);

  /* Logic: '<S207>/Logical Operator2' incorporates:
   *  Logic: '<S208>/Logical Operator2'
   *  Logic: '<S209>/Logical Operator2'
   */
  VfAEBS_FCWLev1_active_tmp = !AEBS_subsystem_integrated_B.vehicle_standstill;

  /* Logic: '<S207>/Logical Operator' incorporates:
   *  Logic: '<S207>/Logical Operator1'
   *  Logic: '<S207>/Logical Operator2'
   *  Lookup_n-D: '<S207>/Partial_FCWL1TTCThreshold_table'
   *  RelationalOperator: '<S207>/Relational Operator'
   */
  VfAEBS_FCWLev1_active = (((AEBS_subsystem_integrated_B.Switch.obs_ttc_VIP <=
    look1_iflf_binlc(AEBS_subsystem_integrated_B.Switch.obs_delta_speed_VIP,
                     KaAEBS_AXIS_DeltaSpeed_Vip, KtAEBS_FCWL1ActiveTTCThrshld,
                     12U)) && (!VbAEBS_FCW_inhibit)) &&
    VfAEBS_FCWLev1_active_tmp);

  /* Logic: '<S207>/Logical Operator3' incorporates:
   *  Constant: '<S207>/Constant1'
   *  RelationalOperator: '<S207>/Relational Operator1'
   */
  VfAEBS_FCWLev1_dactive = ((AEBS_subsystem_integrated_B.Switch.obs_ttc_VIP >=
    KfAEBS_t_TTC_FCWLevel1DeactThrsd) ||
    (AEBS_subsystem_integrated_B.vehicle_standstill));

  /* Logic: '<S208>/Logical Operator' incorporates:
   *  Logic: '<S208>/Logical Operator1'
   *  Lookup_n-D: '<S208>/Partial_FCWL2TTCThreshold_table'
   *  RelationalOperator: '<S208>/Relational Operator'
   */
  VfAEBS_FCWLev2_active = (((AEBS_subsystem_integrated_B.Switch.obs_ttc_VIP <=
    look1_iflf_binlc(AEBS_subsystem_integrated_B.Switch.obs_delta_speed_VIP,
                     KaAEBS_AXIS_DeltaSpeed_Vip, KtAEBS_FCWL2ActiveTTCThrshld,
                     12U)) && (!VbAEBS_FCW_inhibit)) &&
    VfAEBS_FCWLev1_active_tmp);

  /* Logic: '<S208>/Logical Operator3' incorporates:
   *  Constant: '<S208>/Constant1'
   *  RelationalOperator: '<S208>/Relational Operator1'
   */
  VfAEBS_FCWLev2_dactive = ((AEBS_subsystem_integrated_B.Switch.obs_ttc_VIP >=
    KfAEBS_t_TTC_FCWLevel2DeactThrsd) ||
    (AEBS_subsystem_integrated_B.vehicle_standstill));

  /* Logic: '<S209>/Logical Operator' incorporates:
   *  Logic: '<S209>/Logical Operator1'
   *  Lookup_n-D: '<S209>/Partial_FCWL3TTCThreshold_table'
   *  RelationalOperator: '<S209>/Relational Operator'
   */
  VfAEBS_FCWLev3_active = (((AEBS_subsystem_integrated_B.Switch.obs_ttc_VIP <=
    look1_iflf_binlc(AEBS_subsystem_integrated_B.Switch.obs_delta_speed_VIP,
                     KaAEBS_AXIS_DeltaSpeed_Vip, KtAEBS_FCWL3ActiveTTCThrshld,
                     12U)) && (!VbAEBS_FCW_inhibit)) &&
    VfAEBS_FCWLev1_active_tmp);

  /* Logic: '<S209>/Logical Operator3' incorporates:
   *  Constant: '<S209>/Constant1'
   *  RelationalOperator: '<S209>/Relational Operator1'
   */
  VfAEBS_FCWLev3_dactive = ((AEBS_subsystem_integrated_B.Switch.obs_ttc_VIP >=
    KfAEBS_t_TTC_FCWLevel3DeactThrsd) ||
    (AEBS_subsystem_integrated_B.vehicle_standstill));

  /* RelationalOperator: '<S204>/Relational Operator' incorporates:
   *  Constant: '<S204>/Constant2'
   */
  rtb_RelationalOperator = (AEBS_subsystem_integrated_B.Switch.obs_ttc_VIP >
    KfAEBS_t_TTC_DeactiveThrsh);

  /* MinMax: '<S204>/MinMax' incorporates:
   *  Constant: '<S204>/Constant'
   *  Constant: '<S204>/Constant4'
   */
  if (KfAEBS_CTRL_PeriodFunctionCall > 0.001F)
  {
    tmp = KfAEBS_CTRL_PeriodFunctionCall;
  }
  else
  {
    tmp = 0.001F;
  }

  /* End of MinMax: '<S204>/MinMax' */

  /* DataTypeConversion: '<S204>/Data Type Conversion' incorporates:
   *  Constant: '<S204>/Constant7'
   *  Product: '<S204>/Divide'
   */
  rtb_DataTypeConversion_pilu = (uint32_T)((real32_T)
    (KfAEBS_t_Time_TTCHLInhibitAEB / tmp));

  /* Chart: '<S213>/Chart' */
  AEBS_subsystem_integ_Chart_fmkq(rtb_RelationalOperator,
    rtb_DataTypeConversion_pilu, &rtb_y, &rtb_state,
    &AEBS_subsystem_integrated_DW.sf_Chart_avmp);

  /* UnitDelay: '<S211>/Unit Delay1' */
  rtb_UnitDelay1_bsc4 = AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_hjpc;

  /* Logic: '<S204>/Logical Operator1' incorporates:
   *  Abs: '<S212>/Abs'
   *  Abs: '<S212>/Abs1'
   *  Constant: '<S204>/Constant1'
   *  Constant: '<S211>/Constant1'
   *  Constant: '<S212>/Constant1'
   *  Constant: '<S212>/Constant2'
   *  Logic: '<S204>/Logical Operator2'
   *  Logic: '<S211>/Logical Operator2'
   *  Logic: '<S212>/Logical Operator'
   *  RelationalOperator: '<S204>/Relational Operator1'
   *  RelationalOperator: '<S211>/Relational Operator1'
   *  RelationalOperator: '<S211>/Relational Operator3'
   *  RelationalOperator: '<S212>/Relational Operator'
   *  RelationalOperator: '<S212>/Relational Operator1'
   *  Sum: '<S212>/Subtract'
   *  Sum: '<S212>/Subtract1'
   *  UnitDelay: '<S212>/Unit Delay'
   *  UnitDelay: '<S212>/Unit Delay1'
   */
  rtb_LogicalOperator1_c2mo = ((VbAEBS_FCW_inhibit_tmp ||
    ((((AEBS_subsystem_integrated_B.Switch.obs_id_VIP != rtb_UnitDelay1_bsc4) &&
       (rtb_UnitDelay1_bsc4 != ((int32_T)((uint8_T)0U)))) && ((((real32_T)fabs
    ((real_T)((real32_T)(AEBS_subsystem_integrated_B.Switch.obs_NP_y_VIP -
    AEBS_subsystem_integrated_DW.UnitDelay_DSTATE)))) >
    KfAEBS_Change_LateralPosThrsh) || (((real32_T)fabs((real_T)((real32_T)
    (AEBS_subsystem_integrated_B.Switch.obs_NP_x_VIP -
     AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE)))) >
    KfAEBS_Change_LonglPosThrsh))) &&
     (AEBS_subsystem_integrated_B.Switch.obs_ttc_VIP >
      KfAEBS_t_TTC_ObjChangThrsd))) || rtb_y);

  /* MinMax: '<S204>/MinMax1' incorporates:
   *  Constant: '<S204>/Constant5'
   *  Constant: '<S204>/Constant6'
   */
  if (KfAEBS_CTRL_PeriodFunctionCall > 0.001F)
  {
    tmp = KfAEBS_CTRL_PeriodFunctionCall;
  }
  else
  {
    tmp = 0.001F;
  }

  /* End of MinMax: '<S204>/MinMax1' */

  /* DataTypeConversion: '<S204>/Data Type Conversion1' incorporates:
   *  Constant: '<S204>/Constant3'
   *  Product: '<S204>/Divide1'
   */
  rtb_DataTypeConversion1 = (uint32_T)((real32_T)(KfAEBS_t_Time_HasNoVIPDelay /
    tmp));

  /* Chart: '<S214>/Chart' */
  AEBS_subsystem_integ_Chart_fmkq(rtb_LogicalOperator1_c2mo,
    rtb_DataTypeConversion1, &VfAEBS_FCW_deacitve, &rtb_state_p1u2,
    &AEBS_subsystem_integrated_DW.sf_Chart_omyv);

  /* Logic: '<S206>/Logical Operator2' incorporates:
   *  Inport: '<Root>/DCSN_DataBus'
   */
  VfAEBS_FCW_disabled = !VsDCSN_DataBus.EnablingFlags_Group.fcw_feature_enable;

  /* Outputs for Atomic SubSystem: '<S10>/DetermineFCWStatus' */
  AEBS_subsyst_DetermineFCWStatus();

  /* End of Outputs for SubSystem: '<S10>/DetermineFCWStatus' */

  /* Update for UnitDelay: '<S219>/Unit Delay' */
  AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_j1ho = rtb_UnitDelay_depn;

  /* Update for UnitDelay: '<S10>/Unit Delay' */
  AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_m5j4 =
    AEBS_subsystem_integrated_B.request;

  /* Update for UnitDelay: '<S219>/Unit Delay1' */
  AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_airs = rtb_Switch_ht3u;

  /* Update for UnitDelay: '<S211>/Unit Delay1' */
  AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_hjpc =
    AEBS_subsystem_integrated_B.Switch.obs_id_VIP;

  /* Update for UnitDelay: '<S212>/Unit Delay' */
  AEBS_subsystem_integrated_DW.UnitDelay_DSTATE =
    AEBS_subsystem_integrated_B.Switch.obs_NP_y_VIP;

  /* Update for UnitDelay: '<S212>/Unit Delay1' */
  AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE =
    AEBS_subsystem_integrated_B.Switch.obs_NP_x_VIP;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
