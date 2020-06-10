/*
 * File: CalcAEBSAcceleration.c
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

#include "CalcAEBSAcceleration.h"

/* Include model header file for global data */
#include "AEBS_subsystem_integrated.h"
#include "AEBS_subsystem_integrated_private.h"
#include "look1_iflf_binlc.h"

/* Output and update for atomic system: '<S39>/CalcAEBSAcceleration' */
void AEBS_subsy_CalcAEBSAcceleration(void)
{
  /* local block i/o variables */
  real32_T rtb_Sum1_px0d;
  real32_T rtb_MinMax1;
  boolean_T rtb_LogicalOperator_orbq;
  real32_T rtb_Switch_e0mk;
  real32_T rtb_Product;
  real32_T rtb_UnitDelay_dzhw;
  real32_T rtb_BrakeValueLimit_Table;
  real32_T rtb_UnitDelay1_jsre;

  /* Logic: '<S42>/Logical Operator' incorporates:
   *  Constant: '<S42>/Constant1'
   *  RelationalOperator: '<S42>/Relational Operator1'
   */
  rtb_LogicalOperator_orbq = (VfAEBS_AEB_request_beforeSend &&
    (AEBS_subsystem_integrated_B.enable_state_dli2 == AEBS_EnblState_ON));

  /* Switch: '<S49>/Switch' incorporates:
   *  Constant: '<S49>/Constant4'
   *  Constant: '<S49>/Constant5'
   *  Constant: '<S49>/Constant6'
   *  Logic: '<S49>/Logical Operator1'
   *  Logic: '<S49>/Logical Operator2'
   *  RelationalOperator: '<S49>/Relational Operator'
   *  Sum: '<S49>/Add'
   *  UnitDelay: '<S49>/Unit Delay'
   */
  if ((AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_fchv >= ((real32_T)
        100000000U)) || (!rtb_LogicalOperator_orbq))
  {
    rtb_Switch_e0mk = 0.0F;
  }
  else
  {
    rtb_Switch_e0mk = ((real32_T)1U) +
      AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_fchv;
  }

  /* End of Switch: '<S49>/Switch' */

  /* Product: '<S49>/Product' incorporates:
   *  Constant: '<S49>/Constant'
   */
  rtb_Product = rtb_Switch_e0mk * KfAEBS_CTRL_PeriodFunctionCall;

  /* Product: '<S71>/Product' incorporates:
   *  Constant: '<S42>/Constant10'
   *  Constant: '<S42>/freq'
   *  Gain: '<S71>/Gain'
   */
  rtb_Sum1_px0d = 10.0F * (0.5F * KfAEBS_CTRL_PeriodFunctionCall);

  /* Product: '<S71>/Divide1' incorporates:
   *  Constant: '<S71>/Constant1'
   *  Sum: '<S71>/Add2'
   */
  rtb_Sum1_px0d /= rtb_Sum1_px0d + 1.0F;

  /* Sum: '<S51>/Sum' incorporates:
   *  UnitDelay: '<S51>/Unit Delay'
   */
  rtb_UnitDelay_dzhw = VfAEBS_areq +
    AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_hf5d;

  /* Product: '<S51>/Product1' */
  VfAEBS_AEB_acceleration_af_filter = rtb_Sum1_px0d * rtb_UnitDelay_dzhw;

  /* MATLAB Function: '<S42>/MATLAB Function' incorporates:
   *  Constant: '<S42>/Constant2'
   *  Constant: '<S42>/Constant3'
   *  Constant: '<S42>/Constant4'
   *  Constant: '<S42>/Constant5'
   *  Constant: '<S42>/Constant6'
   *  Constant: '<S42>/Constant7'
   *  Constant: '<S42>/Constant8'
   *  Constant: '<S42>/Constant9'
   *  DataStoreWrite: '<S42>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn1'
   *  DataStoreWrite: '<S42>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn2'
   *  DataStoreWrite: '<S42>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn27'
   *  DataStoreWrite: '<S42>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn3'
   *  DataStoreWrite: '<S42>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn4'
   *  DataStoreWrite: '<S42>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn5'
   *  DataStoreWrite: '<S42>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn6'
   *  DataStoreWrite: '<S42>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn7'
   */
  if (!rtb_LogicalOperator_orbq)
  {
    rtb_Product = 0.0F;
  }
  else if (rtb_Product < KfAEBS_t_Time_BrakeInit)
  {
    if (VfAEBS_AEB_acceleration_af_filter > KfAEBS_a_BrakeInit)
    {
      rtb_Product = VfAEBS_AEB_acceleration_af_filter;
    }
    else
    {
      rtb_Product = KfAEBS_a_BrakeInit;
    }
  }
  else
  {
    rtb_UnitDelay1_jsre = KfAEBS_t_Time_BrakeInit + KfAEBS_t_Time_BrakeRamp;
    if (rtb_Product > rtb_UnitDelay1_jsre)
    {
      if ((((uint32_T)AEBS_subsystem_integrated_B.actived_state_bp54) ==
           AEBS_AEBState_WaitForDealy) || (((uint32_T)
            AEBS_subsystem_integrated_B.actived_state_bp54) ==
           AEBS_AEBState_WaitForEPB))
      {
        rtb_Product = AEBS_subsystem_integrated_DW.KfAEBS_a_BrakeHold_ci33;
      }
      else if (((uint32_T)AEBS_subsystem_integrated_B.actived_state_bp54) ==
               AEBS_AEBState_PartialBrakeActived)
      {
        if (KfAEBS_a_PartialBrakeHi > VfAEBS_AEB_acceleration_af_filter)
        {
          rtb_Product = KfAEBS_a_PartialBrakeHi;
        }
        else
        {
          rtb_Product = VfAEBS_AEB_acceleration_af_filter;
        }

        if (KfAEBS_a_PartialBrakeLo < rtb_Product)
        {
          rtb_Product = KfAEBS_a_PartialBrakeLo;
        }
      }
      else
      {
        if (KfAEBS_a_FullBrakeHi > VfAEBS_AEB_acceleration_af_filter)
        {
          rtb_Product = KfAEBS_a_FullBrakeHi;
        }
        else
        {
          rtb_Product = VfAEBS_AEB_acceleration_af_filter;
        }

        if (KfAEBS_a_FullBrakeLo < rtb_Product)
        {
          rtb_Product = KfAEBS_a_FullBrakeLo;
        }
      }
    }
    else
    {
      rtb_Product = KfAEBS_a_BrakeInit - (((real32_T)fabs((real_T)((real32_T)
        (KfAEBS_a_BrakeMax - KfAEBS_a_BrakeInit)))) * ((rtb_Product -
        KfAEBS_t_Time_BrakeInit) / (rtb_UnitDelay1_jsre -
        KfAEBS_t_Time_BrakeInit)));
      if (VfAEBS_AEB_acceleration_af_filter > rtb_Product)
      {
        rtb_Product = VfAEBS_AEB_acceleration_af_filter;
      }
    }
  }

  /* End of MATLAB Function: '<S42>/MATLAB Function' */

  /* Product: '<S51>/Product4' incorporates:
   *  Constant: '<S71>/Constant2'
   *  Gain: '<S71>/Gain1'
   *  Sum: '<S71>/Add1'
   */
  rtb_UnitDelay_dzhw *= 1.0F - (2.0F * rtb_Sum1_px0d);

  /* Sum: '<S47>/Sum1' incorporates:
   *  Constant: '<S47>/Constant7'
   *  Constant: '<S47>/Constant9'
   *  Product: '<S47>/Product2'
   *  UnitDelay: '<S42>/Unit Delay'
   *
   * Block description for '<S47>/Sum1':
   *  _3p4p0p11.CMBB.000_57_
   */
  rtb_Sum1_px0d = VfAEBS_AEB_accReq_beforeSend + (KfAEBS_a_AreqRampRate *
    KfAEBS_CTRL_PeriodFunctionCall);

  /* UnitDelay: '<S42>/Unit Delay1' */
  rtb_UnitDelay1_jsre = AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_feaq;

  /* UnitDelay: '<S47>/Unit Delay1' */
  rtb_MinMax1 = AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_hdmk;

  /* Product: '<S47>/Product1' incorporates:
   *  Constant: '<S47>/Constant3'
   */
  rtb_MinMax1 *= 1.0F;

  /* MinMax: '<S47>/MinMax1' incorporates:
   *  UnitDelay: '<S42>/Unit Delay1'
   */
  if (AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_feaq < rtb_MinMax1)
  {
    rtb_MinMax1 = AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_feaq;
  }

  /* End of MinMax: '<S47>/MinMax1' */

  /* MinMax: '<S47>/MinMax2'
   *
   * Block description for '<S47>/MinMax2':
   *  _3p4p0p11.CMBB.000_54_
   */
  if (rtb_MinMax1 > rtb_Sum1_px0d)
  {
    VfAEBS_AEB_acceleration_bf_limit = rtb_MinMax1;
  }
  else
  {
    VfAEBS_AEB_acceleration_bf_limit = rtb_Sum1_px0d;
  }

  /* End of MinMax: '<S47>/MinMax2' */

  /* Lookup_n-D: '<S48>/BrakeValueLimit_Table' incorporates:
   *  Abs: '<S48>/Abs'
   */
  rtb_BrakeValueLimit_Table = look1_iflf_binlc((real32_T)fabs((real_T)
    VfAEBS_veh_cur_used), KaAEBS_AXIS_Veh_Curvature_vec,
    KtAEBS_a_BrakeValueLimit, 9U);

  /* Switch: '<S48>/Switch' incorporates:
   *  Constant: '<S48>/Constant1'
   */
  if (rtb_LogicalOperator_orbq)
  {
    /* Switch: '<S53>/Switch2' incorporates:
     *  Constant: '<S48>/Constant'
     *  RelationalOperator: '<S53>/LowerRelop1'
     *  RelationalOperator: '<S53>/UpperRelop'
     *  Switch: '<S53>/Switch'
     */
    if (VfAEBS_AEB_acceleration_bf_limit > 0.0F)
    {
      VfAEBS_AEB_accReq_beforeSend = 0.0F;
    }
    else if (VfAEBS_AEB_acceleration_bf_limit < rtb_BrakeValueLimit_Table)
    {
      /* Switch: '<S53>/Switch' */
      VfAEBS_AEB_accReq_beforeSend = rtb_BrakeValueLimit_Table;
    }
    else
    {
      VfAEBS_AEB_accReq_beforeSend = VfAEBS_AEB_acceleration_bf_limit;
    }

    /* End of Switch: '<S53>/Switch2' */
  }
  else
  {
    VfAEBS_AEB_accReq_beforeSend = 0.0F;
  }

  /* End of Switch: '<S48>/Switch' */
  /* Update for UnitDelay: '<S49>/Unit Delay' */
  AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_fchv = rtb_Switch_e0mk;

  /* Update for UnitDelay: '<S51>/Unit Delay' incorporates:
   *  Sum: '<S51>/Sum1'
   */
  AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_hf5d = VfAEBS_areq +
    rtb_UnitDelay_dzhw;

  /* Update for UnitDelay: '<S42>/Unit Delay1' */
  AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_feaq = rtb_Product;

  /* Update for UnitDelay: '<S47>/Unit Delay1' */
  AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_hdmk = rtb_UnitDelay1_jsre;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
