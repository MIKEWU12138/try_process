/*
 * File: AEB_Determination.c
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

#include "AEB_Determination.h"

/* Include model header file for global data */
#include "AEBS_subsystem_integrated.h"
#include "AEBS_subsystem_integrated_private.h"
#include "look1_iflf_binlc.h"

/* Named constants for Chart: '<S101>/BrakeTimeState' */
#define AEBS_su_IN_NO_ACTIVE_CHILD_cyez ((uint8_T)0U)
#define AEBS_subsys_IN_NoBrakeTimeEval1 ((uint8_T)2U)
#define AEBS_subsyst_IN_BrakeTimeFreeze ((uint8_T)1U)
#define AEBS_subsyst_IN_BrakeTimeUpdate ((uint8_T)2U)
#define AEBS_subsystem_IN_BrakeTimeEval ((uint8_T)1U)

/* Named constants for Chart: '<S101>/SpeedReductionStates' */
#define AEBS_su_IN_NoSpeedReductionEval ((uint8_T)1U)
#define AEBS_su_IN_SpeedReductionFreeze ((uint8_T)1U)
#define AEBS_su_IN_SpeedReductionUpdate ((uint8_T)2U)
#define AEBS_subs_IN_SpeedReductionEval ((uint8_T)2U)

/* Named constants for Chart: '<S123>/Chart' */
#define AEBS_subsystem_int_IN_HighSpeed ((uint8_T)1U)
#define AEBS_subsystem_inte_IN_LowSpeed ((uint8_T)2U)

/* System initialize for atomic system: '<S3>/AEB_Determination' */
void AEBS_sub_AEB_Determination_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S142>/Unit Delay1' */
  AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_hiir = ((uint16_T)60000U);

  /* InitializeConditions for UnitDelay: '<S143>/Unit Delay1' */
  AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_otc1 = ((uint16_T)60000U);

  /* SystemInitialize for Chart: '<S123>/Chart' */
  AEBS_subsystem_integrated_DW.is_active_c6_AEBS_subsystem_int = 0U;
  AEBS_subsystem_integrated_DW.is_c6_AEBS_subsystem_integrated =
    AEBS_su_IN_NO_ACTIVE_CHILD_cyez;

  /* SystemInitialize for Chart: '<S79>/Stop_Moving_Estimation' */
  AEB_Stop_Moving_Estimation_Init(&VfAEBS_veh_standstill,
    &AEBS_subsystem_integrated_DW.sf_Stop_Moving_Estimation);

  /* SystemInitialize for MATLAB Function: '<S118>/VIPCloseLostTime' */
  AEBS_subsystem_integrated_DW.counter = 1000U;

  /* SystemInitialize for Chart: '<S85>/Chart' */
  AEBS_subsystem__Chart_k51z_Init(&AEBS_subsystem_integrated_DW.sf_Chart_fmkq);

  /* SystemInitialize for Chart: '<S139>/Chart' */
  AEBS_subsystem__Chart_k51z_Init(&AEBS_subsystem_integrated_DW.sf_Chart_h0r1);

  /* SystemInitialize for Chart: '<S132>/Chart' */
  AEBS_subsystem__Chart_k51z_Init(&AEBS_subsystem_integrated_DW.sf_Chart_cuaz);

  /* SystemInitialize for Chart: '<S97>/Chart' */
  AEBS_subsystem__Chart_k51z_Init(&AEBS_subsystem_integrated_DW.sf_Chart_izss);

  /* SystemInitialize for Chart: '<S101>/SpeedReductionStates' */
  AEBS_subsystem_integrated_DW.is_SpeedReductionEval =
    AEBS_su_IN_NO_ACTIVE_CHILD_cyez;
  AEBS_subsystem_integrated_DW.is_active_c24_AEBS_subsystem_in = 0U;
  AEBS_subsystem_integrated_DW.is_c24_AEBS_subsystem_integrate =
    AEBS_su_IN_NO_ACTIVE_CHILD_cyez;

  /* SystemInitialize for Chart: '<S101>/BrakeTimeState' */
  AEBS_subsystem_integrated_DW.is_BrakeTimeEval =
    AEBS_su_IN_NO_ACTIVE_CHILD_cyez;
  AEBS_subsystem_integrated_DW.is_active_c23_AEBS_subsystem_in = 0U;
  AEBS_subsystem_integrated_DW.is_c23_AEBS_subsystem_integrate =
    AEBS_su_IN_NO_ACTIVE_CHILD_cyez;

  /* SystemInitialize for Chart: '<S99>/Chart' */
  AEBS_subsystem__Chart_k51z_Init(&AEBS_subsystem_integrated_DW.sf_Chart_hwue);

  /* SystemInitialize for Chart: '<S96>/BrakeTimeState' */
  AEBS_subsystem_integrated_DW.is_active_c8_AEBS_subsystem_int = 0U;
  AEBS_subsystem_integrated_DW.is_c8_AEBS_subsystem_integrated =
    AEBS_su_IN_NO_ACTIVE_CHILD_cyez;

  /* SystemInitialize for Atomic SubSystem: '<S8>/DetermineAEBStatus' */
  AEBS_su_DetermineAEBStatus_Init();

  /* End of SystemInitialize for SubSystem: '<S8>/DetermineAEBStatus' */
}

/* Output and update for atomic system: '<S3>/AEB_Determination' */
void AEBS_subsyste_AEB_Determination(void)
{
  real32_T rtb_Constant3;
  boolean_T rtb_Memory_irgw;
  boolean_T rtb_FixPtRelationalOperator;
  uint16_T rtb_Switch_ksyt;
  uint16_T rtb_Saturation;
  int32_T rtb_UnitDelay1_n5kd;
  real32_T rtb_UnitDelay1_p4mm;
  real32_T rtb_Switch2_kneg;
  EnumAEBS_AEBState rtb_UnitDelay_hmcw;
  uint32_T rtb_DataTypeConversion;
  boolean_T rtb_RelationalOperator1_jw0x;
  uint32_T rtb_DataTypeConversion2;
  boolean_T rtb_y;
  boolean_T rtb_partialBrake_active;
  uint32_T rtb_DataTypeConversion2_fzvk;
  boolean_T rtb_LogicalOperator_b1oq;
  uint32_T rtb_DataTypeConversion2_ndu0;
  boolean_T rtb_RelationalOperator;
  uint32_T rtb_DataTypeConversion2_okwy;
  boolean_T rtb_LogicalOperator1_kg1r;
  uint32_T rtb_DataTypeConversion1;
  boolean_T rtb_y_doqv;
  boolean_T rtb_y_jcro;
  uint8_T rtb_state;
  uint8_T rtb_state_aafu;
  uint8_T rtb_state_lqoz;
  uint8_T rtb_state_fxdc;
  uint8_T rtb_state_na5o;
  boolean_T rtb_Logic_ggrp_idx_0;
  boolean_T rtb_Logic_idx_0;
  boolean_T rtb_Logic_efid_idx_0;
  boolean_T rtb_Logic_nekh_idx_0;
  boolean_T rtb_Logic_mwof_idx_0;
  boolean_T rtb_Logic_gaig_idx_0;
  boolean_T rtb_Logic_bh0v_idx_0;
  boolean_T rtb_Logic_adyt_idx_0;
  uint32_T tmp;
  boolean_T rtb_FixPtRelationalOperator_tmp;

  /* Abs: '<S135>/Abs' incorporates:
   *  Abs: '<S128>/Abs'
   */
  rtb_Switch2_kneg = (real32_T)fabs((real_T)
    AEBS_subsystem_integrated_B.DataTypeConversion11);

  /* CombinatorialLogic: '<S138>/Logic' incorporates:
   *  Abs: '<S135>/Abs'
   *  Constant: '<S135>/Constant5'
   *  Constant: '<S135>/Constant6'
   *  Memory: '<S138>/Memory'
   *  RelationalOperator: '<S135>/Relational Operator3'
   *  RelationalOperator: '<S135>/Relational Operator4'
   */
  rtb_Logic_idx_0 = AEBS_subsystem_integrate_ConstP.pooled22[(((((uint32_T)
    ((rtb_Switch2_kneg > KfAEBS_YawRate_Limit_hi) ? 1 : 0)) << 1) + ((uint32_T)
    ((rtb_Switch2_kneg < KfAEBS_YawRate_Limit_lo) ? 1 : 0))) << 1) +
    (AEBS_subsystem_integrated_DW.Memory_PreviousInput_l2t2 ? 1U : 0U)];

  /* CombinatorialLogic: '<S131>/Logic' incorporates:
   *  Constant: '<S128>/Constant5'
   *  Constant: '<S128>/Constant6'
   *  Memory: '<S131>/Memory'
   *  RelationalOperator: '<S128>/Relational Operator3'
   *  RelationalOperator: '<S128>/Relational Operator4'
   */
  rtb_Logic_nekh_idx_0 = AEBS_subsystem_integrate_ConstP.pooled22[(((((uint32_T)
    ((rtb_Switch2_kneg > KfAEBS_YawRate_Limit_hi) ? 1 : 0)) << 1) + ((uint32_T)
    ((rtb_Switch2_kneg < KfAEBS_YawRate_Limit_lo) ? 1 : 0))) << 1) +
    (AEBS_subsystem_integrated_DW.Memory_PreviousInput_bh05 ? 1U : 0U)];

  /* UnitDelay: '<S8>/Unit Delay' */
  rtb_UnitDelay_hmcw = AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_cm23;

  /* CombinatorialLogic: '<S112>/Logic' incorporates:
   *  Constant: '<S105>/Constant'
   *  Constant: '<S106>/Constant'
   *  Constant: '<S107>/Constant'
   *  Constant: '<S108>/Constant'
   *  Constant: '<S109>/Constant'
   *  Constant: '<S110>/Constant'
   *  Constant: '<S111>/Constant'
   *  Logic: '<S103>/Logical Operator'
   *  Logic: '<S103>/Logical Operator1'
   *  Memory: '<S112>/Memory'
   *  RelationalOperator: '<S103>/Relational Operator'
   *  RelationalOperator: '<S103>/Relational Operator1'
   *  RelationalOperator: '<S103>/Relational Operator2'
   *  RelationalOperator: '<S103>/Relational Operator3'
   *  RelationalOperator: '<S103>/Relational Operator4'
   *  RelationalOperator: '<S103>/Relational Operator5'
   *  RelationalOperator: '<S103>/Relational Operator6'
   *  UnitDelay: '<S8>/Unit Delay'
   */
  rtb_Logic_gaig_idx_0 = AEBS_subsystem_integrate_ConstP.pooled22[(((((uint32_T)
    ((((AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_cm23 ==
        AEBS_AEBState_ConfidenceConfirmed) ||
       (AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_cm23 ==
        AEBS_AEBState_FullBrakeActived)) ||
      (AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_cm23 ==
       AEBS_AEBState_PartialBrakeActived)) ? 1 : 0)) << 1) + ((uint32_T)
    (((((AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_cm23 !=
         AEBS_AEBState_PreBrakeActived) &&
        (AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_cm23 !=
         AEBS_AEBState_PartialBrakeActived)) &&
       (AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_cm23 !=
        AEBS_AEBState_FullBrakeActived)) &&
      (AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_cm23 !=
       AEBS_AEBState_ConfidenceConfirmed)) ? 1 : 0))) << 1) +
    (AEBS_subsystem_integrated_DW.Memory_PreviousInput_m5dr ? 1U : 0U)];

  /* Product: '<S135>/Product' incorporates:
   *  Constant: '<S135>/Constant3'
   *  Constant: '<S135>/Constant7'
   *  Product: '<S128>/Product'
   */
  rtb_Switch2_kneg = KfAEBS_CTRL_PeriodFunctionCall * 20.0F;

  /* Product: '<S135>/Divide' incorporates:
   *  Abs: '<S135>/Abs1'
   *  Delay: '<S135>/Delay'
   *  Product: '<S135>/Product'
   *  Sum: '<S135>/Subtract'
   */
  rtb_Constant3 = ((real32_T)fabs((real_T)((real32_T)
    (AEBS_subsystem_integrated_B.DataTypeConversion8 -
     AEBS_subsystem_integrated_DW.Delay_DSTATE[0])))) / rtb_Switch2_kneg;

  /* CombinatorialLogic: '<S137>/Logic' incorporates:
   *  Constant: '<S135>/Constant1'
   *  Constant: '<S135>/Constant4'
   *  Memory: '<S137>/Memory'
   *  RelationalOperator: '<S135>/Relational Operator1'
   *  RelationalOperator: '<S135>/Relational Operator2'
   */
  rtb_Logic_ggrp_idx_0 = AEBS_subsystem_integrate_ConstP.pooled22[(((((uint32_T)
    ((rtb_Constant3 > KfAEBS_SteerRate_Limit_hi) ? 1 : 0)) << 1) + ((uint32_T)
    ((rtb_Constant3 < KfAEBS_SteerRate_Limit_lo) ? 1 : 0))) << 1) +
    (AEBS_subsystem_integrated_DW.Memory_PreviousInput_k5se ? 1U : 0U)];

  /* Product: '<S128>/Divide' incorporates:
   *  Abs: '<S128>/Abs1'
   *  Delay: '<S128>/Delay'
   *  Sum: '<S128>/Subtract'
   */
  rtb_Constant3 = ((real32_T)fabs((real_T)((real32_T)
    (AEBS_subsystem_integrated_B.DataTypeConversion8 -
     AEBS_subsystem_integrated_DW.Delay_DSTATE_fido[0])))) / rtb_Switch2_kneg;

  /* CombinatorialLogic: '<S130>/Logic' incorporates:
   *  Constant: '<S128>/Constant1'
   *  Constant: '<S128>/Constant4'
   *  Memory: '<S130>/Memory'
   *  RelationalOperator: '<S128>/Relational Operator1'
   *  RelationalOperator: '<S128>/Relational Operator2'
   */
  rtb_Logic_efid_idx_0 = AEBS_subsystem_integrate_ConstP.pooled22[(((((uint32_T)
    ((rtb_Constant3 > KfAEBS_SteerRate_Limit_hi) ? 1 : 0)) << 1) + ((uint32_T)
    ((rtb_Constant3 < KfAEBS_SteerRate_Limit_lo) ? 1 : 0))) << 1) +
    (AEBS_subsystem_integrated_DW.Memory_PreviousInput_c1qe ? 1U : 0U)];

  /* Chart: '<S123>/Chart' incorporates:
   *  Constant: '<S123>/Constant1'
   *  Constant: '<S123>/Constant2'
   */
  if (((uint32_T)AEBS_subsystem_integrated_DW.is_active_c6_AEBS_subsystem_int) ==
      0U)
  {
    AEBS_subsystem_integrated_DW.is_active_c6_AEBS_subsystem_int = 1U;
    if (VfAEBS_veh_speed_used > KfAEBS_v_isInHighSpeed_HighThrshd)
    {
      AEBS_subsystem_integrated_DW.is_c6_AEBS_subsystem_integrated =
        AEBS_subsystem_int_IN_HighSpeed;
      VfAEBS_Vehicle_isInHighSpeed = true;
    }
    else
    {
      AEBS_subsystem_integrated_DW.is_c6_AEBS_subsystem_integrated =
        AEBS_subsystem_inte_IN_LowSpeed;
      VfAEBS_Vehicle_isInHighSpeed = false;
    }
  }
  else if (((uint32_T)
            AEBS_subsystem_integrated_DW.is_c6_AEBS_subsystem_integrated) ==
           AEBS_subsystem_int_IN_HighSpeed)
  {
    if (VfAEBS_veh_speed_used < KfAEBS_v_isInHighSpeed_LowThrshd)
    {
      AEBS_subsystem_integrated_DW.is_c6_AEBS_subsystem_integrated =
        AEBS_subsystem_inte_IN_LowSpeed;
      VfAEBS_Vehicle_isInHighSpeed = false;
    }
    else
    {
      VfAEBS_Vehicle_isInHighSpeed = true;
    }
  }
  else if (VfAEBS_veh_speed_used > KfAEBS_v_isInHighSpeed_HighThrshd)
  {
    AEBS_subsystem_integrated_DW.is_c6_AEBS_subsystem_integrated =
      AEBS_subsystem_int_IN_HighSpeed;
    VfAEBS_Vehicle_isInHighSpeed = true;
  }
  else
  {
    VfAEBS_Vehicle_isInHighSpeed = false;
  }

  /* End of Chart: '<S123>/Chart' */

  /* MinMax: '<S79>/MinMax' incorporates:
   *  Constant: '<S79>/Constant'
   *  Constant: '<S79>/Constant1'
   */
  if (KfAEBS_CTRL_PeriodFunctionCall > 0.001F)
  {
    rtb_Switch2_kneg = KfAEBS_CTRL_PeriodFunctionCall;
  }
  else
  {
    rtb_Switch2_kneg = 0.001F;
  }

  /* End of MinMax: '<S79>/MinMax' */

  /* DataTypeConversion: '<S79>/Data Type Conversion' incorporates:
   *  Constant: '<S79>/Constant8'
   *  Product: '<S79>/Divide'
   */
  rtb_DataTypeConversion = (uint32_T)((real32_T)(KfAEBS_t_Speed_DebounceTime /
    rtb_Switch2_kneg));

  /* Chart: '<S79>/Stop_Moving_Estimation' incorporates:
   *  Constant: '<S79>/Constant6'
   *  Constant: '<S79>/Constant7'
   */
  AEBS_sub_Stop_Moving_Estimation(VfAEBS_veh_speed_used,
    KfAEBS_v_Speed_StandStillThrsh, KfAEBS_v_Speed_DeltaStStThrsh,
    rtb_DataTypeConversion, &VfAEBS_veh_standstill,
    &AEBS_subsystem_integrated_DW.sf_Stop_Moving_Estimation);

  /* CombinatorialLogic: '<S115>/Logic' incorporates:
   *  Abs: '<S94>/Abs'
   *  Abs: '<S94>/Abs1'
   *  Abs: '<S94>/Abs2'
   *  Constant: '<S94>/Constant1'
   *  Constant: '<S94>/Constant4'
   *  Constant: '<S94>/Constant9'
   *  Logic: '<S94>/Logical Operator'
   *  Memory: '<S115>/Memory'
   *  RelationalOperator: '<S94>/Relational Operator'
   *  RelationalOperator: '<S94>/Relational Operator1'
   *  RelationalOperator: '<S94>/Relational Operator2'
   *  Sum: '<S94>/Add'
   *  UnitDelay: '<S94>/Unit Delay'
   *  UnitDelay: '<S94>/Unit Delay1'
   *  UnitDelay: '<S94>/Unit Delay2'
   *  UnitDelay: '<S94>/Unit Delay3'
   */
  rtb_Logic_adyt_idx_0 = AEBS_subsystem_integrate_ConstP.pooled22[(((((uint32_T)
    (((((((real32_T)fabs((real_T)((real32_T)
    (AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_fbz5 +
     AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_pqdg)))) <=
         KfAEBS_v_VipStationaryThrshld) && (((real32_T)fabs((real_T)
    AEBS_subsystem_integrated_DW.UnitDelay2_DSTATE)) <=
    KfAEBS_v_VipStationaryThrshld)) &&
       (AEBS_subsystem_integrated_DW.UnitDelay3_DSTATE)) && (((real32_T)fabs
    ((real_T)VfAEBS_veh_cur_used)) <= KfAEBS_Cur_LeftTurnThrshLo)) ? 1 : 0)) <<
    1) + (VfAEBS_veh_standstill ? 1U : 0U)) << 1) +
    (AEBS_subsystem_integrated_DW.Memory_PreviousInput_cd3i ? 1U : 0U)];

  /* UnitDelay: '<S95>/Unit Delay' */
  rtb_UnitDelay1_p4mm = AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_lyfp;

  /* RelationalOperator: '<S95>/Relational Operator' incorporates:
   *  Constant: '<S95>/Constant9'
   */
  rtb_FixPtRelationalOperator = (rtb_UnitDelay1_p4mm <=
    KfAEBS_d_long_max_lostClose);

  /* RelationalOperator: '<S95>/Relational Operator1' incorporates:
   *  Constant: '<S95>/Constant1'
   */
  rtb_Memory_irgw = (rtb_UnitDelay1_p4mm >= KfAEBS_d_long_min_lostClose);

  /* UnitDelay: '<S95>/Unit Delay1' */
  rtb_UnitDelay1_p4mm = AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_fg3i;

  /* Logic: '<S116>/Logical Operator1' incorporates:
   *  Logic: '<S77>/Logical Operator'
   *  Logic: '<S84>/Logical Operator2'
   */
  rtb_FixPtRelationalOperator_tmp =
    !AEBS_subsystem_integrated_B.Switch.has_obs_VIP;

  /* Logic: '<S95>/Logical Operator' incorporates:
   *  Constant: '<S95>/Constant11'
   *  Constant: '<S95>/Constant12'
   *  Constant: '<S95>/Constant13'
   *  Constant: '<S95>/Constant14'
   *  Constant: '<S95>/Constant15'
   *  Constant: '<S95>/Constant16'
   *  Constant: '<S95>/Constant2'
   *  Constant: '<S95>/Constant3'
   *  Constant: '<S95>/Constant4'
   *  Constant: '<S95>/Constant5'
   *  Gain: '<S95>/Gain'
   *  Gain: '<S95>/Gain1'
   *  Logic: '<S116>/Logical Operator'
   *  Logic: '<S116>/Logical Operator1'
   *  Logic: '<S95>/Logical Operator1'
   *  Logic: '<S95>/Logical Operator10'
   *  Logic: '<S95>/Logical Operator11'
   *  Logic: '<S95>/Logical Operator2'
   *  Logic: '<S95>/Logical Operator3'
   *  Logic: '<S95>/Logical Operator8'
   *  Logic: '<S95>/Logical Operator9'
   *  RelationalOperator: '<S95>/Relational Operator10'
   *  RelationalOperator: '<S95>/Relational Operator11'
   *  RelationalOperator: '<S95>/Relational Operator12'
   *  RelationalOperator: '<S95>/Relational Operator13'
   *  RelationalOperator: '<S95>/Relational Operator2'
   *  RelationalOperator: '<S95>/Relational Operator3'
   *  RelationalOperator: '<S95>/Relational Operator4'
   *  RelationalOperator: '<S95>/Relational Operator5'
   *  Sum: '<S95>/Subtract'
   *  Sum: '<S95>/Subtract1'
   *  UnitDelay: '<S116>/Unit Delay'
   */
  rtb_FixPtRelationalOperator = (((((rtb_FixPtRelationalOperator_tmp &&
    (AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_mgfe)) &&
    (rtb_FixPtRelationalOperator && rtb_Memory_irgw)) && ((rtb_UnitDelay1_p4mm <=
    KfAEBS_d_lateral_max_lostClose) && (rtb_UnitDelay1_p4mm >=
    KfAEBS_d_lateral_min_lostClose))) && ((VfAEBS_veh_speed_used <=
    KfAEBS_v_speed_max_lostClose) && (VfAEBS_veh_speed_used >=
    KfAEBS_v_speed_min_lostClose))) && (!(((((real_T)
    AEBS_subsystem_integrated_B.Switch.obs_NP_y_VIP) >= (((real_T)((real32_T)
    (0.5F * KfAEBS_Veh_Width))) - 0.2)) && (((real_T)
    AEBS_subsystem_integrated_B.Switch.obs_v_lateral_VIP) >= 1.0)) || ((((real_T)
    AEBS_subsystem_integrated_B.Switch.obs_NP_y_VIP) <= (((real_T)((real32_T)
    ((-0.5F) * KfAEBS_Veh_Width))) + 0.2)) && (((real_T)
    AEBS_subsystem_integrated_B.Switch.obs_v_lateral_VIP) <= (-1.0))))));

  /* MATLAB Function: '<S118>/VIPCloseLostTime' */
  if (rtb_FixPtRelationalOperator)
  {
    AEBS_subsystem_integrated_DW.counter = 0U;
  }
  else
  {
    tmp = ((uint32_T)AEBS_subsystem_integrated_DW.counter) + 1U;
    if (tmp > 65535U)
    {
      tmp = 65535U;
    }

    AEBS_subsystem_integrated_DW.counter = (uint16_T)tmp;
  }

  if (((int32_T)AEBS_subsystem_integrated_DW.counter) < 1000)
  {
  }
  else
  {
    AEBS_subsystem_integrated_DW.counter = 1000U;
  }

  /* CombinatorialLogic: '<S117>/Logic' incorporates:
   *  Constant: '<S118>/Constant'
   *  Constant: '<S118>/Constant1'
   *  Constant: '<S95>/Constant10'
   *  Constant: '<S95>/Constant6'
   *  Constant: '<S95>/Constant7'
   *  Constant: '<S95>/Constant8'
   *  Logic: '<S95>/Logical Operator4'
   *  Logic: '<S95>/Logical Operator5'
   *  Logic: '<S95>/Logical Operator6'
   *  Logic: '<S95>/Logical Operator7'
   *  MATLAB Function: '<S118>/VIPCloseLostTime'
   *  Memory: '<S117>/Memory'
   *  RelationalOperator: '<S118>/Relational Operator'
   *  RelationalOperator: '<S95>/Relational Operator6'
   *  RelationalOperator: '<S95>/Relational Operator7'
   *  RelationalOperator: '<S95>/Relational Operator8'
   *  RelationalOperator: '<S95>/Relational Operator9'
   */
  rtb_Logic_bh0v_idx_0 = AEBS_subsystem_integrate_ConstP.pooled22[(((((uint32_T)
    (rtb_FixPtRelationalOperator ? 1U : 0U)) << 1) + ((uint32_T)
    (((((KfAEBS_CTRL_PeriodFunctionCall * ((real32_T)
    AEBS_subsystem_integrated_DW.counter)) >= KfAEBS_t_VipCloseLostTimeOut) ||
       VfAEBS_veh_standstill) ||
      (((AEBS_subsystem_integrated_B.Switch.has_obs_VIP) &&
        ((AEBS_subsystem_integrated_B.Switch.obs_dis_long_VIP <=
          KfAEBS_d_long_max_lostClose) &&
         (AEBS_subsystem_integrated_B.Switch.obs_dis_long_VIP >=
          KfAEBS_d_long_min_lostClose))) &&
       ((AEBS_subsystem_integrated_B.Switch.obs_dis_lateral_VIP <=
         KfAEBS_d_lateral_max_lostClose) &&
        (AEBS_subsystem_integrated_B.Switch.obs_dis_lateral_VIP >=
         KfAEBS_d_lateral_min_lostClose)))) ? 1 : 0))) << 1) +
    (AEBS_subsystem_integrated_DW.Memory_PreviousInput_lbx1 ? 1U : 0U)];

  /* MultiPortSwitch: '<S122>/SwitchVRUObs' incorporates:
   *  Constant: '<S122>/Constant'
   *  Constant: '<S122>/Constant1'
   *  Constant: '<S122>/Constant2'
   */
  switch (AEBS_subsystem_integrated_B.Switch.obs_type_VIP)
  {
   case 0:
    VfAEBS_Obj_IsVRU = false;
    break;

   case 1:
    VfAEBS_Obj_IsVRU = true;
    break;

   case 2:
    VfAEBS_Obj_IsVRU = true;
    break;

   case 3:
    VfAEBS_Obj_IsVRU = true;
    break;

   case 4:
    VfAEBS_Obj_IsVRU = false;
    break;

   case 5:
    VfAEBS_Obj_IsVRU = false;
    break;

   case 6:
    VfAEBS_Obj_IsVRU = false;
    break;

   case 7:
    VfAEBS_Obj_IsVRU = false;
    break;

   case 8:
    VfAEBS_Obj_IsVRU = false;
    break;

   case 9:
    VfAEBS_Obj_IsVRU = false;
    break;

   default:
    VfAEBS_Obj_IsVRU = false;
    break;
  }

  /* End of MultiPortSwitch: '<S122>/SwitchVRUObs' */

  /* Logic: '<S78>/Logical Operator' incorporates:
   *  Constant: '<S78>/Constant2'
   *  Logic: '<S78>/Logical Operator1'
   */
  VfAEBS_use_VRU_Calibration = ((KbAEBS_Enable_VRU_Calibration &&
    VfAEBS_Obj_IsVRU) && (!VfAEBS_Vehicle_isInHighSpeed));

  /* Switch: '<S141>/Switch' incorporates:
   *  Lookup_n-D: '<S141>/Pre_BrakeActiveTTCThreshold_VRU_table'
   *  Lookup_n-D: '<S141>/Pre_BrakeActiveTTCThreshold_table'
   */
  if (VfAEBS_use_VRU_Calibration)
  {
    VfAEBS_Pre_BrakeActiveTTCThreshold = look1_iflf_binlc
      (AEBS_subsystem_integrated_B.Switch.obs_delta_speed_VIP,
       KaAEBS_AXIS_DeltaSpeed_Vip, KtAEBS_PreBrkActiveTTCThrshld_VRU, 12U);
  }
  else
  {
    VfAEBS_Pre_BrakeActiveTTCThreshold = look1_iflf_binlc
      (AEBS_subsystem_integrated_B.Switch.obs_delta_speed_VIP,
       KaAEBS_AXIS_DeltaSpeed_Vip, KtAEBS_PreBrkActiveTTCThrshld, 12U);
  }

  /* End of Switch: '<S141>/Switch' */

  /* Switch: '<S156>/Switch2' incorporates:
   *  Constant: '<S145>/Constant1'
   *  Constant: '<S145>/Constant4'
   *  RelationalOperator: '<S156>/LowerRelop1'
   *  RelationalOperator: '<S156>/UpperRelop'
   *  Switch: '<S156>/Switch'
   */
  if (AEBS_subsystem_integrated_B.Switch.obs_ttc_VIP >
      KfAEBS_t_Time_TTCHLInhibitAEB)
  {
    rtb_Switch2_kneg = KfAEBS_t_Time_TTCHLInhibitAEB;
  }
  else if (AEBS_subsystem_integrated_B.Switch.obs_ttc_VIP < ((real32_T)((uint8_T)
             0U)))
  {
    /* Switch: '<S156>/Switch' incorporates:
     *  Constant: '<S145>/Constant4'
     */
    rtb_Switch2_kneg = (real32_T)((uint8_T)0U);
  }
  else
  {
    rtb_Switch2_kneg = AEBS_subsystem_integrated_B.Switch.obs_ttc_VIP;
  }

  /* End of Switch: '<S156>/Switch2' */

  /* Logic: '<S145>/Logical Operator' incorporates:
   *  Constant: '<S145>/Constant2'
   *  Constant: '<S145>/Constant7'
   *  Product: '<S145>/Product'
   *  RelationalOperator: '<S145>/Relational Operator1'
   *  RelationalOperator: '<S145>/Relational Operator3'
   *  Sum: '<S145>/Sum'
   */
  VfAEBS_LowSpeed_InhibitAEB = ((VfAEBS_veh_speed_used <
    KfAEBS_v_Speed_MaxInhibitAEB) && ((VfAEBS_veh_speed_used +
    (VfAEBS_veh_acc_used * rtb_Switch2_kneg)) < KfAEBS_v_SpdCollisionInhibitAEB));

  /* RelationalOperator: '<S145>/Relational Operator2' incorporates:
   *  Constant: '<S145>/Constant3'
   */
  VfAEBS_HighSpeed_InhibitAEB = (VfAEBS_veh_speed_used >
    KfAEBS_v_Speed_High_InhibitAEB);

  /* MultiPortSwitch: '<S155>/SwitchVehicleObs' incorporates:
   *  Constant: '<S155>/Constant'
   *  Constant: '<S155>/Constant1'
   *  Constant: '<S155>/Constant2'
   */
  switch (AEBS_subsystem_integrated_B.Switch.obs_type_VIP)
  {
   case 0:
    rtb_Memory_irgw = false;
    break;

   case 1:
    rtb_Memory_irgw = false;
    break;

   case 2:
    rtb_Memory_irgw = false;
    break;

   case 3:
    rtb_Memory_irgw = false;
    break;

   case 4:
    rtb_Memory_irgw = true;
    break;

   case 5:
    rtb_Memory_irgw = true;
    break;

   case 6:
    rtb_Memory_irgw = true;
    break;

   case 7:
    rtb_Memory_irgw = false;
    break;

   case 8:
    rtb_Memory_irgw = false;
    break;

   case 9:
    rtb_Memory_irgw = false;
    break;

   default:
    rtb_Memory_irgw = false;
    break;
  }

  /* End of MultiPortSwitch: '<S155>/SwitchVehicleObs' */

  /* Logic: '<S145>/Logical Operator2' incorporates:
   *  Constant: '<S145>/Constant5'
   *  RelationalOperator: '<S145>/Relational Operator4'
   */
  VfAEBS_VehDeltaSpeed_InhibitAEB = (rtb_Memory_irgw &&
    (AEBS_subsystem_integrated_B.Switch.obs_delta_speed_VIP <
     KfAEBS_v_deltaSpeed_InhibitAEB));

  /* Logic: '<S145>/Logical Operator1' */
  VfAEBS_Speed_InhibitAEB = ((VfAEBS_LowSpeed_InhibitAEB ||
    VfAEBS_HighSpeed_InhibitAEB) || VfAEBS_VehDeltaSpeed_InhibitAEB);

  /* RelationalOperator: '<S84>/Relational Operator3' incorporates:
   *  Constant: '<S84>/Constant1'
   */
  VfAEBS_Gear_InhibitAEB = (AEBS_subsystem_integrated_B.DataTypeConversion3 ==
    KfAEBS_Gear_Value_R);

  /* Switch: '<S142>/Switch' incorporates:
   *  Constant: '<S142>/Constant2'
   *  Constant: '<S142>/Constant3'
   *  Constant: '<S147>/Constant'
   *  Constant: '<S148>/Constant'
   *  Constant: '<S149>/Constant'
   *  Constant: '<S150>/Constant'
   *  Constant: '<S151>/Constant'
   *  Constant: '<S152>/Constant'
   *  Logic: '<S142>/Logical Operator1'
   *  Logic: '<S142>/Logical Operator3'
   *  Logic: '<S142>/Logical Operator4'
   *  RelationalOperator: '<S142>/Relational Operator1'
   *  RelationalOperator: '<S142>/Relational Operator2'
   *  RelationalOperator: '<S142>/Relational Operator3'
   *  RelationalOperator: '<S142>/Relational Operator5'
   *  RelationalOperator: '<S142>/Relational Operator6'
   *  RelationalOperator: '<S142>/Relational Operator7'
   *  Sum: '<S142>/Add'
   *  UnitDelay: '<S142>/Unit Delay'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S8>/Unit Delay'
   */
  if ((((AEBS_AEBState_FullBrakeActived ==
         AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_epz0) ||
        (AEBS_AEBState_PartialBrakeActived ==
         AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_epz0)) ||
       (AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_epz0 ==
        AEBS_AEBState_ConfidenceConfirmed)) &&
      (((AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_cm23 !=
         AEBS_AEBState_PartialBrakeActived) &&
        (AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_cm23 !=
         AEBS_AEBState_FullBrakeActived)) &&
       (AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_cm23 !=
        AEBS_AEBState_ConfidenceConfirmed)))
  {
    rtb_Switch_ksyt = ((uint16_T)0U);
  }
  else
  {
    rtb_Switch_ksyt = (uint16_T)(((uint32_T)((uint16_T)1U)) + ((uint32_T)
      AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_hiir));
  }

  /* End of Switch: '<S142>/Switch' */

  /* Saturate: '<S142>/Saturation' */
  if (rtb_Switch_ksyt < ((uint16_T)60000U))
  {
    rtb_Saturation = rtb_Switch_ksyt;
  }
  else
  {
    rtb_Saturation = ((uint16_T)60000U);
  }

  /* End of Saturate: '<S142>/Saturation' */

  /* RelationalOperator: '<S142>/Relational Operator' incorporates:
   *  Constant: '<S142>/Constant'
   *  Constant: '<S142>/Constant4'
   *  Product: '<S142>/Product'
   */
  VbAEBS_AEB_inhbt_DeactTime = ((((real32_T)rtb_Saturation) *
    KfAEBS_CTRL_PeriodFunctionCall) < KfAEBS_t_Time_TwiceAEBActive);

  /* RelationalOperator: '<S84>/Relational Operator1' incorporates:
   *  Constant: '<S84>/Constant2'
   */
  VbAEBS_AEB_inhbt_AccPdl = (AEBS_subsystem_integrated_B.DataTypeConversion5 >=
    KfAEBS_AccPdl_InhbtDeact_thrshld);

  /* MinMax: '<S144>/MinMax2' incorporates:
   *  Constant: '<S144>/Constant7'
   *  Constant: '<S144>/Constant8'
   */
  if (KfAEBS_CTRL_PeriodFunctionCall > 0.001F)
  {
    rtb_Switch2_kneg = KfAEBS_CTRL_PeriodFunctionCall;
  }
  else
  {
    rtb_Switch2_kneg = 0.001F;
  }

  /* End of MinMax: '<S144>/MinMax2' */

  /* RelationalOperator: '<S144>/Relational Operator' incorporates:
   *  Constant: '<S144>/Constant1'
   *  Constant: '<S144>/Constant4'
   *  Delay: '<S144>/Delay'
   *  Gain: '<S144>/Gain'
   *  Product: '<S144>/Divide2'
   *  Sum: '<S144>/Subtract'
   */
  VbAEBS_AEB_inhbt_StrAngRte = ((0.0174532924F *
    (((AEBS_subsystem_integrated_B.DataTypeConversion8 -
       AEBS_subsystem_integrated_DW.Delay_DSTATE_igdy[0]) / rtb_Switch2_kneg) /
     20.0F)) > KfAEBS_StrAngRte_inhbt_AEB_trshd);

  /* RelationalOperator: '<S146>/Relational Operator' incorporates:
   *  Lookup_n-D: '<S146>/veh_acc_AEB_inhibit_thrhd_table'
   */
  VbAEBS_AEB_inhbt_veh_acc = (VfAEBS_veh_acc_used >= look1_iflf_binlc
    (VfAEBS_veh_speed_used, KaAEBS_AXIS_Veh_Speed_vec,
     KtAEBS_veh_acc_inhibit_AEB_thrhd, 8U));

  /* Logic: '<S84>/Logical Operator' incorporates:
   *  Constant: '<S84>/Constant3'
   */
  VfAEBS_AEB_inhibit = (((((((rtb_FixPtRelationalOperator_tmp ||
    VfAEBS_Speed_InhibitAEB) || VfAEBS_Gear_InhibitAEB) ||
    VbAEBS_AEB_inhbt_DeactTime) || VbAEBS_AEB_inhbt_AccPdl) || (0.0F != 0.0F)) ||
    VbAEBS_AEB_inhbt_StrAngRte) || VbAEBS_AEB_inhbt_veh_acc);

  /* Switch: '<S143>/Switch' incorporates:
   *  Constant: '<S143>/Constant2'
   *  Constant: '<S143>/Constant3'
   *  Constant: '<S153>/Constant'
   *  Constant: '<S154>/Constant'
   *  Logic: '<S143>/Logical Operator4'
   *  RelationalOperator: '<S143>/Relational Operator3'
   *  RelationalOperator: '<S143>/Relational Operator5'
   *  Sum: '<S143>/Add'
   *  UnitDelay: '<S143>/Unit Delay'
   *  UnitDelay: '<S143>/Unit Delay1'
   *  UnitDelay: '<S8>/Unit Delay'
   */
  if ((AEBS_AEBState_PreBrakeActived ==
       AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_ag4i) &&
      (AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_cm23 !=
       AEBS_AEBState_PreBrakeActived))
  {
    rtb_Switch_ksyt = ((uint16_T)0U);
  }
  else
  {
    rtb_Switch_ksyt = (uint16_T)(((uint32_T)((uint16_T)1U)) + ((uint32_T)
      AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_otc1));
  }

  /* End of Switch: '<S143>/Switch' */

  /* Saturate: '<S143>/Saturation' */
  if (rtb_Switch_ksyt < ((uint16_T)60000U))
  {
  }
  else
  {
    rtb_Switch_ksyt = ((uint16_T)60000U);
  }

  /* End of Saturate: '<S143>/Saturation' */

  /* RelationalOperator: '<S143>/Relational Operator' incorporates:
   *  Constant: '<S143>/Constant'
   *  Constant: '<S143>/Constant4'
   *  Product: '<S143>/Product'
   */
  VbAEBS_PreBrk_inhbt_deactTime = ((((real32_T)rtb_Switch_ksyt) *
    KfAEBS_CTRL_PeriodFunctionCall) < KfAEBS_t_Time_TwicePreBrkActive);

  /* Logic: '<S84>/Logical Operator1' incorporates:
   *  Constant: '<S84>/Constant4'
   *  Logic: '<S84>/Logical Operator3'
   */
  VbAEBS_preBrake_inhibit = (VbAEBS_PreBrk_inhbt_deactTime ||
    (!KbAEBS_enable_PreBrake));

  /* Logic: '<S83>/Logical Operator2' incorporates:
   *  Logic: '<S81>/Logical Operator2'
   *  Logic: '<S82>/Logical Operator2'
   */
  rtb_Memory_irgw = !VfAEBS_veh_standstill;

  /* Logic: '<S83>/Logical Operator' incorporates:
   *  Logic: '<S83>/Logical Operator1'
   *  Logic: '<S83>/Logical Operator2'
   *  Logic: '<S83>/Logical Operator4'
   *  RelationalOperator: '<S83>/Relational Operator'
   */
  VfAEBS_preBrake_active = ((((AEBS_subsystem_integrated_B.Switch.obs_ttc_VIP <=
    VfAEBS_Pre_BrakeActiveTTCThreshold) && (!VfAEBS_AEB_inhibit)) &&
    rtb_Memory_irgw) && (!VbAEBS_preBrake_inhibit));

  /* Switch: '<S134>/Switch' incorporates:
   *  Lookup_n-D: '<S134>/Partial_BrakeActiveTTCThreshold_VRU_table'
   *  Lookup_n-D: '<S134>/Partial_BrakeActiveTTCThreshold_table'
   */
  if (VfAEBS_use_VRU_Calibration)
  {
    VfAEBS_Partial_BrakeActiveTTCThreshold = look1_iflf_binlc
      (AEBS_subsystem_integrated_B.Switch.obs_delta_speed_VIP,
       KaAEBS_AXIS_DeltaSpeed_Vip, KtAEBS_PrtlBrkActiveTTCThrshld_VRU, 12U);
  }
  else
  {
    VfAEBS_Partial_BrakeActiveTTCThreshold = look1_iflf_binlc
      (AEBS_subsystem_integrated_B.Switch.obs_delta_speed_VIP,
       KaAEBS_AXIS_DeltaSpeed_Vip, KtAEBS_PrtlBrkActiveTTCThrshld, 12U);
  }

  /* End of Switch: '<S134>/Switch' */

  /* Sum: '<S76>/Add2' */
  VfAEBS_v_obj_absolute_speed = VfAEBS_veh_speed_used -
    AEBS_subsystem_integrated_B.Switch.obs_delta_speed_VIP;

  /* Sum: '<S76>/Add1' */
  VfAEBS_a_obj_absolute_acc = VfAEBS_veh_acc_used +
    AEBS_subsystem_integrated_B.Switch.obs_acc_long_VIP;

  /* MinMax: '<S76>/MinMax1' incorporates:
   *  Constant: '<S76>/Constant3'
   */
  if (VfAEBS_a_obj_absolute_acc > 0.01F)
  {
    rtb_Switch2_kneg = VfAEBS_a_obj_absolute_acc;
  }
  else
  {
    rtb_Switch2_kneg = 0.01F;
  }

  /* End of MinMax: '<S76>/MinMax1' */

  /* Sum: '<S76>/Add3' incorporates:
   *  Gain: '<S76>/Gain2'
   *  Math: '<S76>/Math Function2'
   *  Product: '<S76>/Divide1'
   */
  rtb_Constant3 = ((VfAEBS_v_obj_absolute_speed * VfAEBS_v_obj_absolute_speed) /
                   (2.0F * rtb_Switch2_kneg)) +
    AEBS_subsystem_integrated_B.Switch.obs_delta_dis_VIP;

  /* MinMax: '<S76>/MinMax3' incorporates:
   *  Constant: '<S76>/Constant4'
   */
  if (rtb_Constant3 > 0.01F)
  {
  }
  else
  {
    rtb_Constant3 = 0.01F;
  }

  /* End of MinMax: '<S76>/MinMax3' */

  /* Product: '<S76>/Divide2' incorporates:
   *  Gain: '<S76>/Gain4'
   *  Math: '<S76>/Math Function3'
   */
  VfAEBS_areq_withoutDelay_UrgentBrk = (VfAEBS_veh_speed_used *
    VfAEBS_veh_speed_used) / (2.0F * rtb_Constant3);

  /* RelationalOperator: '<S76>/Relational Operator1' incorporates:
   *  Constant: '<S76>/Constant5'
   */
  rtb_RelationalOperator1_jw0x = (VfAEBS_a_obj_absolute_acc <=
    KfAEBS_a_ObjUrgentBrake_Thrsh);

  /* MinMax: '<S76>/MinMax4' incorporates:
   *  Constant: '<S76>/Constant10'
   *  Constant: '<S76>/Constant9'
   */
  if (KfAEBS_CTRL_PeriodFunctionCall > 0.001F)
  {
    rtb_Switch2_kneg = KfAEBS_CTRL_PeriodFunctionCall;
  }
  else
  {
    rtb_Switch2_kneg = 0.001F;
  }

  /* End of MinMax: '<S76>/MinMax4' */

  /* DataTypeConversion: '<S76>/Data Type Conversion2' incorporates:
   *  Constant: '<S76>/Constant7'
   *  Product: '<S76>/Divide3'
   */
  rtb_DataTypeConversion2 = (uint32_T)((real32_T)(KfAEBS_t_Time_ObjUrgentBrk /
    rtb_Switch2_kneg));

  /* Chart: '<S85>/Chart' */
  AEBS_subsystem_integ_Chart_fmkq(rtb_RelationalOperator1_jw0x,
    rtb_DataTypeConversion2, &rtb_y, &rtb_state,
    &AEBS_subsystem_integrated_DW.sf_Chart_fmkq);

  /* Logic: '<S76>/Logical Operator' incorporates:
   *  Constant: '<S76>/Constant11'
   *  RelationalOperator: '<S76>/Relational Operator2'
   */
  rtb_FixPtRelationalOperator = (rtb_y && (VfAEBS_v_obj_absolute_speed <=
    KfAEBS_v_ObjUrgentBrk_speed_Thrsh));

  /* MinMax: '<S76>/MinMax' incorporates:
   *  Constant: '<S76>/Constant'
   */
  if (AEBS_subsystem_integrated_B.Switch.obs_delta_dis_VIP > 0.01F)
  {
    rtb_Switch2_kneg = AEBS_subsystem_integrated_B.Switch.obs_delta_dis_VIP;
  }
  else
  {
    rtb_Switch2_kneg = 0.01F;
  }

  /* End of MinMax: '<S76>/MinMax' */

  /* Gain: '<S76>/Gain1' incorporates:
   *  Gain: '<S76>/Gain3'
   *  Math: '<S76>/Math Function'
   *  Product: '<S76>/Divide'
   */
  VfAEBS_areq_withoutDelay = (-1.0F) *
    ((AEBS_subsystem_integrated_B.Switch.obs_delta_speed_VIP *
      AEBS_subsystem_integrated_B.Switch.obs_delta_speed_VIP) / (2.0F *
      rtb_Switch2_kneg));

  /* Switch: '<S76>/Switch1' */
  if (rtb_FixPtRelationalOperator)
  {
    rtb_Constant3 = VfAEBS_areq_withoutDelay_UrgentBrk;
  }
  else
  {
    rtb_Constant3 = VfAEBS_areq_withoutDelay;
  }

  /* End of Switch: '<S76>/Switch1' */

  /* Sum: '<S76>/Add' incorporates:
   *  Constant: '<S76>/Constant2'
   *  Gain: '<S76>/Gain'
   *  Math: '<S76>/Math Function1'
   *  Product: '<S76>/Product'
   *  Product: '<S76>/Product1'
   */
  VfAEBS_dis_delay = (AEBS_subsystem_integrated_B.Switch.obs_delta_speed_VIP *
                      KfAEBS_t_Time_BrakeDelay) + (0.5F *
    ((KfAEBS_t_Time_BrakeDelay * KfAEBS_t_Time_BrakeDelay) * VfAEBS_veh_acc_used));

  /* Switch: '<S76>/Switch3' incorporates:
   *  Constant: '<S76>/Constant12'
   *  Constant: '<S76>/Constant15'
   */
  if (VfAEBS_use_VRU_Calibration)
  {
    VfAEBS_dis_safe_used = KfAEBS_d_Dis_Safe_VRU;
  }
  else
  {
    VfAEBS_dis_safe_used = KfAEBS_d_Dis_Safe;
  }

  /* End of Switch: '<S76>/Switch3' */

  /* UnitDelay: '<S8>/Unit Delay1' */
  rtb_UnitDelay1_p4mm = AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_gojp;

  /* Switch: '<S76>/Switch' incorporates:
   *  Constant: '<S76>/Constant1'
   *  Constant: '<S76>/Constant8'
   *  RelationalOperator: '<S76>/Relational Operator'
   *  Switch: '<S76>/Switch2'
   */
  if (rtb_Constant3 < KfAEBS_a_FullBrakeHi)
  {
    rtb_UnitDelay1_p4mm = KfAEBS_a_FullBrakeHi;
  }
  else
  {
    if (rtb_FixPtRelationalOperator)
    {
      /* Switch: '<S76>/Switch2' */
      rtb_Switch2_kneg = VfAEBS_veh_speed_used;
    }
    else
    {
      /* Switch: '<S76>/Switch2' */
      rtb_Switch2_kneg = AEBS_subsystem_integrated_B.Switch.obs_delta_speed_VIP;
    }

    /* Math: '<S86>/Math Function3' incorporates:
     *  Math: '<S88>/Math Function2'
     *  Switch: '<S86>/Switch1'
     */
    rtb_Switch2_kneg *= rtb_Switch2_kneg;

    /* Switch: '<S86>/Switch1' incorporates:
     *  Abs: '<S86>/Abs'
     *  Constant: '<S86>/Constant10'
     *  Gain: '<S86>/Gain5'
     *  Gain: '<S88>/Gain2'
     *  Gain: '<S88>/Gain4'
     *  Math: '<S86>/Math Function3'
     *  Product: '<S86>/Divide2'
     *  Product: '<S88>/Divide1'
     *  RelationalOperator: '<S86>/Relational Operator1'
     *  Sum: '<S86>/Add1'
     */
    if (AEBS_subsystem_integrated_B.Switch.obs_delta_dis_VIP >
        ((VfAEBS_dis_delay + VfAEBS_dis_safe_used) + (rtb_Switch2_kneg / (2.0F *
           ((real32_T)fabs((real_T)KfAEBS_a_FullBrakeHi))))))
    {
      /* Sum: '<S88>/Subtract' */
      rtb_Constant3 = (AEBS_subsystem_integrated_B.Switch.obs_delta_dis_VIP -
                       VfAEBS_dis_delay) - VfAEBS_dis_safe_used;

      /* MinMax: '<S88>/MinMax1' incorporates:
       *  Constant: '<S88>/Constant4'
       */
      if (rtb_Constant3 > 0.01F)
      {
      }
      else
      {
        rtb_Constant3 = 0.01F;
      }

      /* End of MinMax: '<S88>/MinMax1' */
      rtb_UnitDelay1_p4mm = (-1.0F) * (rtb_Switch2_kneg / (2.0F * rtb_Constant3));
    }
    else
    {
      /* Sum: '<S89>/Add3' incorporates:
       *  Constant: '<S89>/Constant1'
       *  Sum: '<S89>/Add2'
       *  Switch: '<S89>/Switch2'
       *  Switch: '<S89>/Switch3'
       */
      rtb_Switch2_kneg = rtb_Constant3 + KfAEBS_a_Buffer;

      /* Switch: '<S89>/Switch2' incorporates:
       *  Constant: '<S89>/Constant7'
       *  RelationalOperator: '<S89>/Relational Operator2'
       *  RelationalOperator: '<S89>/Relational Operator3'
       *  Sum: '<S89>/Add3'
       *  Switch: '<S89>/Switch3'
       */
      if (rtb_UnitDelay1_p4mm < rtb_Switch2_kneg)
      {
      }
      else if (rtb_Constant3 == 0.0F)
      {
        /* Switch: '<S89>/Switch3' incorporates:
         *  Constant: '<S89>/Constant9'
         */
        rtb_UnitDelay1_p4mm = 0.0F;
      }
      else
      {
        /* Switch: '<S89>/Switch3' */
        rtb_UnitDelay1_p4mm = rtb_Switch2_kneg;
      }
    }
  }

  /* End of Switch: '<S76>/Switch' */

  /* MinMax: '<S76>/MinMax2' incorporates:
   *  Constant: '<S76>/Constant6'
   */
  if (rtb_UnitDelay1_p4mm > KfAEBS_a_FullBrakeHi)
  {
    VfAEBS_areq = rtb_UnitDelay1_p4mm;
  }
  else
  {
    VfAEBS_areq = KfAEBS_a_FullBrakeHi;
  }

  /* End of MinMax: '<S76>/MinMax2' */

  /* Logic: '<S82>/Logical Operator' incorporates:
   *  Constant: '<S82>/Constant2'
   *  Constant: '<S82>/Constant3'
   *  Logic: '<S82>/Logical Operator1'
   *  RelationalOperator: '<S82>/Relational Operator'
   *  RelationalOperator: '<S82>/Relational Operator2'
   *  RelationalOperator: '<S82>/Relational Operator4'
   */
  rtb_partialBrake_active = (((((AEBS_subsystem_integrated_B.Switch.obs_ttc_VIP <=
    VfAEBS_Partial_BrakeActiveTTCThreshold) && (VfAEBS_areq <=
    KfAEBS_a_Areq_PartialBrkActThrsd)) && (!VfAEBS_AEB_inhibit)) &&
    rtb_Memory_irgw) && (AEBS_subsystem_integrated_B.Switch.obs_confidence_VIP >=
    KfAEBS_Confdnc_PartialBrkActThrsd));

  /* MinMax: '<S136>/MinMax2' incorporates:
   *  Constant: '<S136>/Constant7'
   *  Constant: '<S136>/Constant8'
   */
  if (KfAEBS_CTRL_PeriodFunctionCall > 0.001F)
  {
    rtb_Switch2_kneg = KfAEBS_CTRL_PeriodFunctionCall;
  }
  else
  {
    rtb_Switch2_kneg = 0.001F;
  }

  /* End of MinMax: '<S136>/MinMax2' */

  /* DataTypeConversion: '<S136>/Data Type Conversion2' incorporates:
   *  Constant: '<S136>/Constant6'
   *  Product: '<S136>/Divide2'
   */
  rtb_DataTypeConversion2_fzvk = (uint32_T)((real32_T)
    (KfAEBS_t_pb_active_delay_turn / rtb_Switch2_kneg));

  /* Chart: '<S139>/Chart' */
  AEBS_subsystem_integ_Chart_fmkq(rtb_partialBrake_active,
    rtb_DataTypeConversion2_fzvk, &rtb_y_doqv, &rtb_state_aafu,
    &AEBS_subsystem_integrated_DW.sf_Chart_h0r1);

  /* Switch: '<S135>/Switch' incorporates:
   *  Constant: '<S135>/Constant2'
   */
  if (((real32_T)(KbAEBS_use_steerAngle ? 1.0F : 0.0F)) > 0.0F)
  {
    rtb_FixPtRelationalOperator = rtb_Logic_ggrp_idx_0;
  }
  else
  {
    rtb_FixPtRelationalOperator = rtb_Logic_idx_0;
  }

  /* End of Switch: '<S135>/Switch' */

  /* Switch: '<S82>/Switch' */
  if (rtb_FixPtRelationalOperator)
  {
    VfAEBS_partialBrk_active = rtb_y_doqv;
  }
  else
  {
    VfAEBS_partialBrk_active = rtb_partialBrake_active;
  }

  /* End of Switch: '<S82>/Switch' */

  /* Lookup_n-D: '<S126>/Full_BrkActiveAccThreshold_table' */
  VfAEBS_Full_BrkActiveACCThreshold = look1_iflf_binlc
    (AEBS_subsystem_integrated_B.Switch.obs_delta_speed_VIP,
     KaAEBS_AXIS_DeltaSpeed_Vip, KtAEBS_FullBrkActiveAccThrshld, 12U);

  /* Switch: '<S81>/Switch1' incorporates:
   *  Constant: '<S127>/Constant'
   *  Constant: '<S81>/Constant4'
   *  Logic: '<S81>/Logical Operator1'
   *  RelationalOperator: '<S81>/Relational Operator2'
   *  UnitDelay: '<S8>/Unit Delay'
   */
  if (AEBS_AEBState_PartialBrakeActived ==
      AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_cm23)
  {
    rtb_Switch2_kneg = 1.0F;
  }
  else
  {
    rtb_Switch2_kneg = (real32_T)((!VfAEBS_AEB_inhibit) ? 1 : 0);
  }

  /* End of Switch: '<S81>/Switch1' */

  /* Logic: '<S81>/Logical Operator' incorporates:
   *  Constant: '<S81>/Constant3'
   *  RelationalOperator: '<S81>/Relational Operator'
   *  RelationalOperator: '<S81>/Relational Operator4'
   */
  rtb_LogicalOperator_b1oq = ((((VfAEBS_areq <=
    VfAEBS_Full_BrkActiveACCThreshold) && (rtb_Switch2_kneg != 0.0F)) &&
    rtb_Memory_irgw) && (AEBS_subsystem_integrated_B.Switch.obs_confidence_VIP >=
    KfAEBS_Confdnc_FullBrkActThrsd));

  /* MinMax: '<S129>/MinMax2' incorporates:
   *  Constant: '<S129>/Constant7'
   *  Constant: '<S129>/Constant8'
   */
  if (KfAEBS_CTRL_PeriodFunctionCall > 0.001F)
  {
    rtb_Switch2_kneg = KfAEBS_CTRL_PeriodFunctionCall;
  }
  else
  {
    rtb_Switch2_kneg = 0.001F;
  }

  /* End of MinMax: '<S129>/MinMax2' */

  /* DataTypeConversion: '<S129>/Data Type Conversion2' incorporates:
   *  Constant: '<S129>/Constant6'
   *  Product: '<S129>/Divide2'
   */
  rtb_DataTypeConversion2_ndu0 = (uint32_T)((real32_T)
    (KfAEBS_t_fb_active_delay_turn / rtb_Switch2_kneg));

  /* Chart: '<S132>/Chart' */
  AEBS_subsystem_integ_Chart_fmkq(rtb_LogicalOperator_b1oq,
    rtb_DataTypeConversion2_ndu0, &rtb_y_jcro, &rtb_state_lqoz,
    &AEBS_subsystem_integrated_DW.sf_Chart_cuaz);

  /* Switch: '<S128>/Switch' incorporates:
   *  Constant: '<S128>/Constant2'
   */
  if (((real32_T)(KbAEBS_use_steerAngle ? 1.0F : 0.0F)) > 0.0F)
  {
    rtb_FixPtRelationalOperator = rtb_Logic_efid_idx_0;
  }
  else
  {
    rtb_FixPtRelationalOperator = rtb_Logic_nekh_idx_0;
  }

  /* End of Switch: '<S128>/Switch' */

  /* Switch: '<S81>/Switch' */
  if (rtb_FixPtRelationalOperator)
  {
    VfAEBS_fullBrk_active = rtb_y_jcro;
  }
  else
  {
    VfAEBS_fullBrk_active = rtb_LogicalOperator_b1oq;
  }

  /* End of Switch: '<S81>/Switch' */

  /* RelationalOperator: '<S41>/Relational Operator3' incorporates:
   *  Constant: '<S41>/Constant1'
   *  Logic: '<S8>/Logical Operator'
   */
  rtb_FixPtRelationalOperator = (((uint32_T)(((VfAEBS_preBrake_active ||
    VfAEBS_partialBrk_active) || VfAEBS_fullBrk_active) ? 1 : 0)) > ((uint32_T)
    ((uint8_T)0U)));

  /* Switch: '<S161>/Switch1' incorporates:
   *  Constant: '<S161>/Constant2'
   *  Constant: '<S161>/Constant4'
   *  Constant: '<S41>/Constant2'
   *  Logic: '<S157>/Logical Operator2'
   *  RelationalOperator: '<S41>/Relational Operator4'
   *  Sum: '<S161>/Sum'
   *  UnitDelay: '<S161>/UnitDelay'
   */
  if ((AEBS_subsystem_integrated_B.DataTypeConversion4 >= ((uint8_T)5U)) &&
      rtb_FixPtRelationalOperator)
  {
    rtb_Constant3 = AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_j1zq + 1.0F;
  }
  else
  {
    rtb_Constant3 = 0.0F;
  }

  /* End of Switch: '<S161>/Switch1' */

  /* RelationalOperator: '<S161>/RelationalOperator1' incorporates:
   *  Constant: '<S157>/Constant1'
   *  Constant: '<S157>/Constant2'
   *  Constant: '<S157>/Constant9'
   *  Product: '<S157>/Divide'
   *  Product: '<S161>/Product'
   */
  rtb_Memory_irgw = (rtb_Constant3 > (0.5F * (1.0F /
    KfAEBS_CTRL_PeriodFunctionCall)));

  /* CombinatorialLogic: '<S160>/Logic' incorporates:
   *  Memory: '<S160>/Memory'
   *  RelationalOperator: '<S158>/FixPt Relational Operator'
   *  RelationalOperator: '<S159>/FixPt Relational Operator'
   *  UnitDelay: '<S158>/Delay Input1'
   *  UnitDelay: '<S159>/Delay Input1'
   *
   * Block description for '<S158>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S159>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Logic_mwof_idx_0 = AEBS_subsystem_integrate_ConstP.pooled22[(((((uint32_T)
    ((((int32_T)(rtb_Memory_irgw ? 1 : 0)) > ((int32_T)
    (AEBS_subsystem_integrated_DW.DelayInput1_DSTATE ? 1 : 0))) ? 1 : 0)) << 1)
    + ((uint32_T)((((int32_T)(rtb_FixPtRelationalOperator ? 1 : 0)) < ((int32_T)
    (AEBS_subsystem_integrated_DW.DelayInput1_DSTATE_jg0j ? 1 : 0))) ? 1 : 0))) <<
    1) + (AEBS_subsystem_integrated_DW.Memory_PreviousInput_llaj ? 1U : 0U)];

  /* Switch: '<S41>/Switch' incorporates:
   *  Constant: '<S41>/Constant3'
   *  Constant: '<S41>/TiDlyDeactvnInCllsnRednByBrkg1'
   *  Constant: '<S41>/TiDlyDeactvnInCllsnRednByBrkg2'
   *  Constant: '<S41>/TiDlyDeactvnInCllsnRednByBrkg3'
   *  Constant: '<S41>/TiDlyDeactvnInCllsnRednByBrkg4'
   *  Logic: '<S41>/Logical Operator1'
   *  RelationalOperator: '<S41>/Relational Operator1'
   *  RelationalOperator: '<S41>/Relational Operator2'
   *  RelationalOperator: '<S41>/Relational Operator5'
   */
  if (KbAEBS_AllowOverride)
  {
    AEBS_subsystem_integrated_B.Switch_eddh =
      ((((AEBS_subsystem_integrated_B.DataTypeConversion5 >
          KfAEBS_AccPedelThrshOvrrd) &&
         (AEBS_subsystem_integrated_B.Switch.obs_v_long_VIP >
          KfAEBS_v_SpeedRelLThrshOvrrd)) && (VfAEBS_veh_speed_used <
         KfAEBS_v_SpeedLLThrshOvrrd)) && rtb_Logic_mwof_idx_0);
  }
  else
  {
    AEBS_subsystem_integrated_B.Switch_eddh = false;
  }

  /* End of Switch: '<S41>/Switch' */

  /* RelationalOperator: '<S90>/Relational Operator' incorporates:
   *  Constant: '<S90>/Constant2'
   */
  rtb_RelationalOperator = (AEBS_subsystem_integrated_B.Switch.obs_ttc_VIP >
    KfAEBS_t_TTC_DeactiveThrsh);

  /* MinMax: '<S90>/MinMax2' incorporates:
   *  Constant: '<S90>/Constant7'
   *  Constant: '<S90>/Constant8'
   */
  if (KfAEBS_CTRL_PeriodFunctionCall > 0.001F)
  {
    rtb_Switch2_kneg = KfAEBS_CTRL_PeriodFunctionCall;
  }
  else
  {
    rtb_Switch2_kneg = 0.001F;
  }

  /* End of MinMax: '<S90>/MinMax2' */

  /* DataTypeConversion: '<S90>/Data Type Conversion2' incorporates:
   *  Constant: '<S90>/Constant4'
   *  Product: '<S90>/Divide2'
   */
  rtb_DataTypeConversion2_okwy = (uint32_T)((real32_T)
    (KfAEBS_t_Time_TTCHLInhibitAEB / rtb_Switch2_kneg));

  /* Chart: '<S97>/Chart' */
  AEBS_subsystem_integ_Chart_fmkq(rtb_RelationalOperator,
    rtb_DataTypeConversion2_okwy, &VbAEBS_Deactive_R_HighTTC, &rtb_state_fxdc,
    &AEBS_subsystem_integrated_DW.sf_Chart_izss);

  /* Chart: '<S101>/SpeedReductionStates' incorporates:
   *  Constant: '<S101>/Constant'
   *  Constant: '<S101>/Constant1'
   */
  if (((uint32_T)AEBS_subsystem_integrated_DW.is_active_c24_AEBS_subsystem_in) ==
      0U)
  {
    AEBS_subsystem_integrated_DW.is_active_c24_AEBS_subsystem_in = 1U;
    AEBS_subsystem_integrated_DW.is_c24_AEBS_subsystem_integrate =
      AEBS_su_IN_NoSpeedReductionEval;
    AEBS_subsystem_integrated_B.SpeedReduction = 0.0F;
  }
  else if (((uint32_T)
            AEBS_subsystem_integrated_DW.is_c24_AEBS_subsystem_integrate) ==
           AEBS_su_IN_NoSpeedReductionEval)
  {
    if (rtb_Logic_gaig_idx_0)
    {
      AEBS_subsystem_integrated_DW.is_c24_AEBS_subsystem_integrate =
        AEBS_subs_IN_SpeedReductionEval;
      AEBS_subsystem_integrated_DW.SpeedRedPrevious = 0.0F;
      AEBS_subsystem_integrated_DW.is_SpeedReductionEval =
        AEBS_su_IN_SpeedReductionUpdate;
      AEBS_subsystem_integrated_DW.SpeedAtIntervention = VfAEBS_veh_speed_used;
    }
  }
  else if (((uint32_T)AEBS_subsystem_integrated_DW.is_SpeedReductionEval) ==
           AEBS_su_IN_SpeedReductionFreeze)
  {
    if (rtb_Logic_gaig_idx_0)
    {
      AEBS_subsystem_integrated_DW.is_SpeedReductionEval =
        AEBS_su_IN_SpeedReductionUpdate;
      AEBS_subsystem_integrated_DW.SpeedAtIntervention = VfAEBS_veh_speed_used;
    }
    else if (AEBS_subsystem_integrated_DW.TimeNoIntervention >
             KfAEBS_t_Time_ResetVeloRdctThrsd)
    {
      AEBS_subsystem_integrated_DW.is_SpeedReductionEval =
        AEBS_su_IN_NO_ACTIVE_CHILD_cyez;
      AEBS_subsystem_integrated_DW.is_c24_AEBS_subsystem_integrate =
        AEBS_su_IN_NoSpeedReductionEval;
      AEBS_subsystem_integrated_B.SpeedReduction = 0.0F;
    }
    else
    {
      AEBS_subsystem_integrated_DW.TimeNoIntervention +=
        KfAEBS_CTRL_PeriodFunctionCall;
    }
  }
  else if (!rtb_Logic_gaig_idx_0)
  {
    AEBS_subsystem_integrated_B.SpeedReduction =
      (AEBS_subsystem_integrated_DW.SpeedRedPrevious +
       AEBS_subsystem_integrated_DW.SpeedAtIntervention) - VfAEBS_veh_speed_used;
    AEBS_subsystem_integrated_DW.SpeedRedPrevious =
      AEBS_subsystem_integrated_B.SpeedReduction;
    AEBS_subsystem_integrated_DW.is_SpeedReductionEval =
      AEBS_su_IN_SpeedReductionFreeze;
    AEBS_subsystem_integrated_DW.TimeNoIntervention = 0.0F;
  }
  else
  {
    AEBS_subsystem_integrated_B.SpeedReduction =
      (AEBS_subsystem_integrated_DW.SpeedRedPrevious +
       AEBS_subsystem_integrated_DW.SpeedAtIntervention) - VfAEBS_veh_speed_used;
  }

  /* End of Chart: '<S101>/SpeedReductionStates' */

  /* Chart: '<S101>/BrakeTimeState' incorporates:
   *  Constant: '<S101>/Constant2'
   *  Constant: '<S101>/Constant3'
   */
  if (((uint32_T)AEBS_subsystem_integrated_DW.is_active_c23_AEBS_subsystem_in) ==
      0U)
  {
    AEBS_subsystem_integrated_DW.is_active_c23_AEBS_subsystem_in = 1U;
    AEBS_subsystem_integrated_DW.is_c23_AEBS_subsystem_integrate =
      AEBS_subsys_IN_NoBrakeTimeEval1;
    AEBS_subsystem_integrated_B.TimeBrake_orpa = 0.0F;
  }
  else if (((uint32_T)
            AEBS_subsystem_integrated_DW.is_c23_AEBS_subsystem_integrate) ==
           AEBS_subsystem_IN_BrakeTimeEval)
  {
    if (((uint32_T)AEBS_subsystem_integrated_DW.is_BrakeTimeEval) ==
        AEBS_subsyst_IN_BrakeTimeFreeze)
    {
      if (rtb_Logic_gaig_idx_0)
      {
        AEBS_subsystem_integrated_DW.is_BrakeTimeEval =
          AEBS_subsyst_IN_BrakeTimeUpdate;
        AEBS_subsystem_integrated_B.TimeBrake_orpa +=
          KfAEBS_CTRL_PeriodFunctionCall;
      }
      else if (AEBS_subsystem_integrated_DW.TimeNoIntervention_b1jh >
               KfAEBS_t_Time_ResetTimeBrkThrsd)
      {
        AEBS_subsystem_integrated_DW.is_BrakeTimeEval =
          AEBS_su_IN_NO_ACTIVE_CHILD_cyez;
        AEBS_subsystem_integrated_DW.is_c23_AEBS_subsystem_integrate =
          AEBS_subsys_IN_NoBrakeTimeEval1;
        AEBS_subsystem_integrated_B.TimeBrake_orpa = 0.0F;
      }
      else
      {
        AEBS_subsystem_integrated_DW.TimeNoIntervention_b1jh +=
          KfAEBS_CTRL_PeriodFunctionCall;
      }
    }
    else if (!rtb_Logic_gaig_idx_0)
    {
      AEBS_subsystem_integrated_DW.is_BrakeTimeEval =
        AEBS_subsyst_IN_BrakeTimeFreeze;
      AEBS_subsystem_integrated_DW.TimeNoIntervention_b1jh = 0.0F;
    }
    else
    {
      AEBS_subsystem_integrated_B.TimeBrake_orpa +=
        KfAEBS_CTRL_PeriodFunctionCall;
    }
  }
  else
  {
    if (rtb_Logic_gaig_idx_0)
    {
      AEBS_subsystem_integrated_DW.is_c23_AEBS_subsystem_integrate =
        AEBS_subsystem_IN_BrakeTimeEval;
      AEBS_subsystem_integrated_DW.is_BrakeTimeEval =
        AEBS_subsyst_IN_BrakeTimeUpdate;
      AEBS_subsystem_integrated_B.TimeBrake_orpa +=
        KfAEBS_CTRL_PeriodFunctionCall;
    }
  }

  /* End of Chart: '<S101>/BrakeTimeState' */

  /* Logic: '<S77>/Logical Operator' */
  VbAEBS_Deactive_R_NoVIP = rtb_FixPtRelationalOperator_tmp;

  /* SignalConversion: '<S95>/Signal Conversion' */
  VbAEBS_vipCloseLost = rtb_Logic_bh0v_idx_0;

  /* SignalConversion: '<S94>/Signal Conversion' */
  VbAEBS_vipStationary = rtb_Logic_adyt_idx_0;

  /* UnitDelay: '<S113>/Unit Delay1' */
  rtb_UnitDelay1_n5kd = AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_krs0;

  /* Logic: '<S93>/Logical Operator2' incorporates:
   *  Abs: '<S114>/Abs'
   *  Abs: '<S114>/Abs1'
   *  Constant: '<S113>/Constant1'
   *  Constant: '<S114>/Constant1'
   *  Constant: '<S114>/Constant2'
   *  Constant: '<S93>/Constant1'
   *  Logic: '<S113>/Logical Operator2'
   *  Logic: '<S114>/Logical Operator'
   *  RelationalOperator: '<S113>/Relational Operator1'
   *  RelationalOperator: '<S113>/Relational Operator3'
   *  RelationalOperator: '<S114>/Relational Operator'
   *  RelationalOperator: '<S114>/Relational Operator1'
   *  RelationalOperator: '<S93>/Relational Operator1'
   *  Sum: '<S114>/Subtract'
   *  Sum: '<S114>/Subtract1'
   *  UnitDelay: '<S114>/Unit Delay'
   *  UnitDelay: '<S114>/Unit Delay1'
   */
  VbAEBS_Deactive_R_VIPChanged =
    ((((AEBS_subsystem_integrated_B.Switch.obs_id_VIP != rtb_UnitDelay1_n5kd) &&
       (rtb_UnitDelay1_n5kd != ((int32_T)((uint8_T)0U)))) && ((((real32_T)fabs
         ((real_T)((real32_T)(AEBS_subsystem_integrated_B.Switch.obs_NP_y_VIP -
            AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_eswa)))) >
        KfAEBS_Change_LateralPosThrsh) || (((real32_T)fabs((real_T)((real32_T)
           (AEBS_subsystem_integrated_B.Switch.obs_NP_x_VIP -
            AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_eowt)))) >
        KfAEBS_Change_LonglPosThrsh))) && (VfAEBS_areq >
      KfAEBS_a_Areq_ObjChangThrsd));

  /* RelationalOperator: '<S92>/i' incorporates:
   *  Constant: '<S92>/VRednThdASILAInCllsnRednByBrkg'
   */
  VfAEBS_DeniedDueToSpdRed = (AEBS_subsystem_integrated_B.SpeedReduction >
    KfAEBS_VeloRectThrsdByBrkg);

  /* RelationalOperator: '<S92>/i1' incorporates:
   *  Constant: '<S92>/VRednThdASILAInCllsnRednByBrkg1'
   */
  VfAEBS_DeniedDueToTimeBrake = (AEBS_subsystem_integrated_B.TimeBrake_orpa >
    KfAEBS_t_TimeBrakeThrsd);

  /* RelationalOperator: '<S77>/Relational Operator1' incorporates:
   *  Constant: '<S77>/Constant1'
   */
  VbAEBS_Deactive_R_Confdnc =
    (AEBS_subsystem_integrated_B.Switch.obs_confidence_VIP <
     KfAEBS_Confidnc_Deact_thrshld);

  /* Logic: '<S77>/Logical Operator1' incorporates:
   *  Constant: '<S77>/Constant10'
   *  Constant: '<S77>/Constant9'
   *  Logic: '<S77>/Logical Operator2'
   *  Logic: '<S77>/Logical Operator3'
   *  Logic: '<S77>/Logical Operator4'
   *  RelationalOperator: '<S77>/Relational Operator2'
   */
  rtb_LogicalOperator1_kg1r = (((((((((VbAEBS_Deactive_R_NoVIP &&
    (!VbAEBS_vipCloseLost)) && (!VbAEBS_vipStationary)) ||
    VbAEBS_Deactive_R_VIPChanged) || VbAEBS_Deactive_R_HighTTC) ||
    VfAEBS_DeniedDueToSpdRed) || VfAEBS_DeniedDueToTimeBrake) ||
    (AEBS_subsystem_integrated_B.DataTypeConversion5 >=
     KfAEBS_AccPdl_InhbtDeact_thrshld)) || (0.0F != 0.0F)) ||
    VbAEBS_Deactive_R_Confdnc);

  /* MinMax: '<S91>/MinMax1' incorporates:
   *  Constant: '<S91>/Constant5'
   *  Constant: '<S91>/Constant6'
   */
  if (KfAEBS_CTRL_PeriodFunctionCall > 0.001F)
  {
    rtb_Switch2_kneg = KfAEBS_CTRL_PeriodFunctionCall;
  }
  else
  {
    rtb_Switch2_kneg = 0.001F;
  }

  /* End of MinMax: '<S91>/MinMax1' */

  /* DataTypeConversion: '<S91>/Data Type Conversion1' incorporates:
   *  Constant: '<S91>/Constant3'
   *  Product: '<S91>/Divide1'
   */
  rtb_DataTypeConversion1 = (uint32_T)((real32_T)(KfAEBS_t_Time_HasNoVIPDelay /
    rtb_Switch2_kneg));

  /* Chart: '<S99>/Chart' */
  AEBS_subsystem_integ_Chart_fmkq(rtb_LogicalOperator1_kg1r,
    rtb_DataTypeConversion1, &VfAEBS_AEB_deactive, &rtb_state_na5o,
    &AEBS_subsystem_integrated_DW.sf_Chart_hwue);

  /* Chart: '<S96>/BrakeTimeState' incorporates:
   *  Constant: '<S121>/Constant'
   *  Constant: '<S96>/Constant2'
   *  RelationalOperator: '<S96>/Relational Operator4'
   *  UnitDelay: '<S8>/Unit Delay'
   */
  if (((uint32_T)AEBS_subsystem_integrated_DW.is_active_c8_AEBS_subsystem_int) ==
      0U)
  {
    AEBS_subsystem_integrated_DW.is_active_c8_AEBS_subsystem_int = 1U;
    AEBS_subsystem_integrated_DW.is_c8_AEBS_subsystem_integrated =
      AEBS_su_IN_NoSpeedReductionEval;
    AEBS_subsystem_integrated_B.TimeBrake = 0.0F;
  }
  else if (((uint32_T)
            AEBS_subsystem_integrated_DW.is_c8_AEBS_subsystem_integrated) ==
           AEBS_su_IN_NoSpeedReductionEval)
  {
    if (AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_cm23 ==
        AEBS_AEBState_PreBrakeActived)
    {
      AEBS_subsystem_integrated_DW.is_c8_AEBS_subsystem_integrated =
        AEBS_su_IN_SpeedReductionUpdate;
      AEBS_subsystem_integrated_B.TimeBrake = 0.0F;
    }
  }
  else if (!(AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_cm23 ==
             AEBS_AEBState_PreBrakeActived))
  {
    AEBS_subsystem_integrated_DW.is_c8_AEBS_subsystem_integrated =
      AEBS_su_IN_NoSpeedReductionEval;
    AEBS_subsystem_integrated_B.TimeBrake = 0.0F;
  }
  else
  {
    AEBS_subsystem_integrated_B.TimeBrake += KfAEBS_CTRL_PeriodFunctionCall;
  }

  /* End of Chart: '<S96>/BrakeTimeState' */

  /* RelationalOperator: '<S96>/i1' incorporates:
   *  Constant: '<S96>/VRednThdASILAInCllsnRednByBrkg1'
   */
  VbAEBS_deactive_preBrk_timeOut = (AEBS_subsystem_integrated_B.TimeBrake >
    KfAEBS_t_TimePreBrkThrsd);

  /* Logic: '<S80>/Logical Operator3' incorporates:
   *  Constant: '<S80>/Constant1'
   *  Constant: '<S80>/Constant4'
   *  Inport: '<Root>/DCSN_DataBus'
   *  Logic: '<S80>/Logical Operator4'
   *  Logic: '<S80>/Logical Operator5'
   *  RelationalOperator: '<S80>/Relational Operator'
   *  RelationalOperator: '<S80>/Relational Operator1'
   *  S-Function (sfix_bitop): '<S80>/Bitwise Operator'
   *  S-Function (sfix_bitop): '<S80>/Bitwise Operator1'
   */
  VfAEBS_AEB_enabled = (((VsDCSN_DataBus.EnablingFlags_Group.aeb_feature_enable)
    && (!((AEBS_subsystem_integrated_B.Switch1 &
           AEBS_subsystem_integrate_ConstB.DataTypeConversion_fpa3) != ((uint8_T)
    0U)))) && (!((AEBS_subsystem_integrated_B.Switch1 &
                  AEBS_subsystem_integrate_ConstB.DataTypeConversion1_lo5n) !=
                 ((uint8_T)0U))));

  /* Logic: '<S83>/Logical Operator3' incorporates:
   *  Constant: '<S83>/Constant1'
   *  RelationalOperator: '<S83>/Relational Operator1'
   */
  VfAEBS_preBrake_dactive = ((AEBS_subsystem_integrated_B.Switch.obs_ttc_VIP >=
    KfAEBS_t_TTC_PreBrkDeactThrsd) || VfAEBS_veh_standstill);

  /* Logic: '<S82>/Logical Operator3' incorporates:
   *  Constant: '<S82>/Constant1'
   *  Constant: '<S82>/Constant4'
   *  RelationalOperator: '<S82>/Relational Operator1'
   *  RelationalOperator: '<S82>/Relational Operator3'
   */
  VfAEBS_partialBrk_dactive = (((AEBS_subsystem_integrated_B.Switch.obs_ttc_VIP >=
    KfAEBS_t_TTC_PartialBrkDeactiveThrsd) || (VfAEBS_areq >=
    KfAEBS_a_Areq_PartialBrkDeactThrsd)) || VfAEBS_veh_standstill);

  /* Logic: '<S81>/Logical Operator3' incorporates:
   *  Constant: '<S81>/Constant1'
   *  RelationalOperator: '<S81>/Relational Operator1'
   */
  VfAEBS_fullBrk_dactive = ((VfAEBS_areq >= KfAEBS_a_Areq_FullBrkDeactThrsd) ||
    VfAEBS_veh_standstill);

  /* RelationalOperator: '<S8>/Relational Operator' incorporates:
   *  Constant: '<S8>/Constant4'
   */
  AEBS_subsystem_integrated_B.RelationalOperator = (KfAEBS_EPB_Engaged_Value ==
    AEBS_subsystem_integrated_B.DataTypeConversion2);

  /* Logic: '<S80>/Logical Operator7' incorporates:
   *  Inport: '<Root>/DCSN_DataBus'
   */
  VfAEBS_AEB_disabled = !VsDCSN_DataBus.EnablingFlags_Group.aeb_feature_enable;

  /* Outputs for Atomic SubSystem: '<S8>/DetermineAEBStatus' */
  AEBS_subsyst_DetermineAEBStatus();

  /* End of Outputs for SubSystem: '<S8>/DetermineAEBStatus' */

  /* Update for Memory: '<S138>/Memory' */
  AEBS_subsystem_integrated_DW.Memory_PreviousInput_l2t2 = rtb_Logic_idx_0;

  /* Update for Memory: '<S131>/Memory' */
  AEBS_subsystem_integrated_DW.Memory_PreviousInput_bh05 = rtb_Logic_nekh_idx_0;

  /* Update for UnitDelay: '<S8>/Unit Delay' */
  AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_cm23 =
    AEBS_subsystem_integrated_B.BusCreator.AEB_actived_state;

  /* Update for Memory: '<S112>/Memory' */
  AEBS_subsystem_integrated_DW.Memory_PreviousInput_m5dr = rtb_Logic_gaig_idx_0;

  /* Update for Delay: '<S135>/Delay' */
  for (rtb_UnitDelay1_n5kd = 0; rtb_UnitDelay1_n5kd < 19; rtb_UnitDelay1_n5kd++)
  {
    AEBS_subsystem_integrated_DW.Delay_DSTATE[rtb_UnitDelay1_n5kd] =
      AEBS_subsystem_integrated_DW.Delay_DSTATE[rtb_UnitDelay1_n5kd + 1];
  }

  AEBS_subsystem_integrated_DW.Delay_DSTATE[19] =
    AEBS_subsystem_integrated_B.DataTypeConversion8;

  /* End of Update for Delay: '<S135>/Delay' */

  /* Update for Memory: '<S137>/Memory' */
  AEBS_subsystem_integrated_DW.Memory_PreviousInput_k5se = rtb_Logic_ggrp_idx_0;

  /* Update for Delay: '<S128>/Delay' */
  for (rtb_UnitDelay1_n5kd = 0; rtb_UnitDelay1_n5kd < 19; rtb_UnitDelay1_n5kd++)
  {
    AEBS_subsystem_integrated_DW.Delay_DSTATE_fido[rtb_UnitDelay1_n5kd] =
      AEBS_subsystem_integrated_DW.Delay_DSTATE_fido[rtb_UnitDelay1_n5kd + 1];
  }

  AEBS_subsystem_integrated_DW.Delay_DSTATE_fido[19] =
    AEBS_subsystem_integrated_B.DataTypeConversion8;

  /* End of Update for Delay: '<S128>/Delay' */

  /* Update for Memory: '<S130>/Memory' */
  AEBS_subsystem_integrated_DW.Memory_PreviousInput_c1qe = rtb_Logic_efid_idx_0;

  /* Update for UnitDelay: '<S94>/Unit Delay' */
  AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_fbz5 =
    AEBS_subsystem_integrated_B.Switch.obs_v_long_VIP;

  /* Update for UnitDelay: '<S94>/Unit Delay1' */
  AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_pqdg = VfAEBS_veh_speed_used;

  /* Update for UnitDelay: '<S94>/Unit Delay2' */
  AEBS_subsystem_integrated_DW.UnitDelay2_DSTATE =
    AEBS_subsystem_integrated_B.Switch.obs_v_lateral_VIP;

  /* Update for UnitDelay: '<S94>/Unit Delay3' */
  AEBS_subsystem_integrated_DW.UnitDelay3_DSTATE =
    AEBS_subsystem_integrated_B.Switch.has_obs_VIP;

  /* Update for Memory: '<S115>/Memory' */
  AEBS_subsystem_integrated_DW.Memory_PreviousInput_cd3i = rtb_Logic_adyt_idx_0;

  /* Update for UnitDelay: '<S116>/Unit Delay' */
  AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_mgfe =
    AEBS_subsystem_integrated_B.Switch.has_obs_VIP;

  /* Update for UnitDelay: '<S95>/Unit Delay' */
  AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_lyfp =
    AEBS_subsystem_integrated_B.Switch.obs_dis_long_VIP;

  /* Update for UnitDelay: '<S95>/Unit Delay1' */
  AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_fg3i =
    AEBS_subsystem_integrated_B.Switch.obs_dis_lateral_VIP;

  /* Update for Memory: '<S117>/Memory' */
  AEBS_subsystem_integrated_DW.Memory_PreviousInput_lbx1 = rtb_Logic_bh0v_idx_0;

  /* Update for UnitDelay: '<S161>/UnitDelay' */
  AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_j1zq = rtb_Constant3;

  /* Update for UnitDelay: '<S142>/Unit Delay' */
  AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_epz0 = rtb_UnitDelay_hmcw;

  /* Update for UnitDelay: '<S142>/Unit Delay1' */
  AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_hiir = rtb_Saturation;

  /* Update for Delay: '<S144>/Delay' */
  for (rtb_UnitDelay1_n5kd = 0; rtb_UnitDelay1_n5kd < 19; rtb_UnitDelay1_n5kd++)
  {
    AEBS_subsystem_integrated_DW.Delay_DSTATE_igdy[rtb_UnitDelay1_n5kd] =
      AEBS_subsystem_integrated_DW.Delay_DSTATE_igdy[rtb_UnitDelay1_n5kd + 1];
  }

  AEBS_subsystem_integrated_DW.Delay_DSTATE_igdy[19] =
    AEBS_subsystem_integrated_B.DataTypeConversion8;

  /* End of Update for Delay: '<S144>/Delay' */

  /* Update for UnitDelay: '<S143>/Unit Delay' */
  AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_ag4i = rtb_UnitDelay_hmcw;

  /* Update for UnitDelay: '<S143>/Unit Delay1' */
  AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_otc1 = rtb_Switch_ksyt;

  /* Update for UnitDelay: '<S8>/Unit Delay1' */
  AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_gojp =
    AEBS_subsystem_integrated_B.BusCreator.AEB_acceleration_req;

  /* Update for UnitDelay: '<S159>/Delay Input1'
   *
   * Block description for '<S159>/Delay Input1':
   *
   *  Store in Global RAM
   */
  AEBS_subsystem_integrated_DW.DelayInput1_DSTATE = rtb_Memory_irgw;

  /* Update for UnitDelay: '<S158>/Delay Input1'
   *
   * Block description for '<S158>/Delay Input1':
   *
   *  Store in Global RAM
   */
  AEBS_subsystem_integrated_DW.DelayInput1_DSTATE_jg0j =
    rtb_FixPtRelationalOperator;

  /* Update for Memory: '<S160>/Memory' */
  AEBS_subsystem_integrated_DW.Memory_PreviousInput_llaj = rtb_Logic_mwof_idx_0;

  /* Update for UnitDelay: '<S113>/Unit Delay1' */
  AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_krs0 =
    AEBS_subsystem_integrated_B.Switch.obs_id_VIP;

  /* Update for UnitDelay: '<S114>/Unit Delay' */
  AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_eswa =
    AEBS_subsystem_integrated_B.Switch.obs_NP_y_VIP;

  /* Update for UnitDelay: '<S114>/Unit Delay1' */
  AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_eowt =
    AEBS_subsystem_integrated_B.Switch.obs_NP_x_VIP;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
