/*
 * File: ALCA_Dtrm_dcsn_info.c
 *
 * Code generated for Simulink model 'ALCA_subsystem_integrated'.
 *
 * Model version                  : 1.6591
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 17:34:22 2020
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

#include "ALCA_Dtrm_dcsn_info.h"

/* Include model header file for global data */
#include "ALCA_subsystem_integrated.h"
#include "ALCA_subsystem_integrated_private.h"

/* System initialize for atomic system: '<S12>/ALCA_Dtrm_dcsn_info' */
void ALCA_s_ALCA_Dtrm_dcsn_info_Init(void)
{
  /* InitializeConditions for Memory: '<S57>/Memory' */
  ALCA_subsystem_integrated_DW.Memory_PreviousInput = false;

  /* InitializeConditions for Memory: '<S56>/Memory' */
  ALCA_subsystem_integrated_DW.Memory_PreviousInput_h3op = false;

  /* InitializeConditions for UnitDelay: '<S47>/Unit Delay' */
  ALCA_subsystem_integrated_DW.change_lane_req_side = FORWARD;
}

/* System reset for atomic system: '<S12>/ALCA_Dtrm_dcsn_info' */
void ALCA__ALCA_Dtrm_dcsn_info_Reset(void)
{
  /* InitializeConditions for Memory: '<S57>/Memory' */
  ALCA_subsystem_integrated_DW.Memory_PreviousInput = false;

  /* InitializeConditions for Memory: '<S56>/Memory' */
  ALCA_subsystem_integrated_DW.Memory_PreviousInput_h3op = false;

  /* InitializeConditions for UnitDelay: '<S47>/Unit Delay' */
  ALCA_subsystem_integrated_DW.change_lane_req_side = FORWARD;
}

/* Output and update for atomic system: '<S12>/ALCA_Dtrm_dcsn_info' */
void ALCA_subsys_ALCA_Dtrm_dcsn_info(boolean_T rtu_reset_lc_req, EnumALCA_state
  rtu_pre_state, ALCA_DcsnInfo *rty_dcsn_info)
{
  boolean_T rtb_LogicalOperator2_nutm;
  EnumDCSN_driving_direction rtb_Switch4;
  boolean_T rtb_Logic_izfb_idx_0;
  boolean_T rtb_Logic_idx_0;

  /* SignalConversion: '<S47>/Signal Conversion1' incorporates:
   *  Inport: '<Root>/DCSN_DataBus'
   */
  VbALCA_LC_CancelReqFromDCSN =
    VsDCSN_DataBus.TrafficDecider_Group.change_lane_cancel_request;

  /* SignalConversion: '<S47>/Signal Conversion3' incorporates:
   *  Inport: '<Root>/DCSN_DataBus'
   */
  VbALCA_LC_ReqFromDCSN =
    VsDCSN_DataBus.TrafficDecider_Group.change_lane_request;

  /* Logic: '<S47>/Logical Operator2' incorporates:
   *  Constant: '<S53>/Constant'
   *  RelationalOperator: '<S47>/Relational Operator'
   */
  rtb_LogicalOperator2_nutm = ((ALCA_state_Standby == rtu_pre_state) &&
    VbALCA_LC_ReqFromDCSN);

  /* CombinatorialLogic: '<S57>/Logic' incorporates:
   *  Logic: '<S47>/Logical Operator1'
   *  Memory: '<S57>/Memory'
   */
  rtb_Logic_idx_0 = ALCA_subsystem_integrate_ConstP.pooled8[(((((uint32_T)
    (VbALCA_LC_CancelReqFromDCSN ? 1U : 0U)) << 1) + ((uint32_T)
    ((rtu_reset_lc_req || rtb_LogicalOperator2_nutm) ? 1 : 0))) << 1) +
    (ALCA_subsystem_integrated_DW.Memory_PreviousInput ? 1U : 0U)];

  /* Switch: '<S47>/Switch5' incorporates:
   *  Constant: '<S47>/Constant6'
   *  Constant: '<S55>/Constant'
   *  Logic: '<S47>/Logical Operator4'
   *  RelationalOperator: '<S47>/Relational Operator2'
   */
  if (KbALCA_EnblInterrupt)
  {
    rtb_Logic_izfb_idx_0 = ((ALCA_state_Activated != rtu_pre_state) &&
      VbALCA_LC_CancelReqFromDCSN);
  }
  else
  {
    rtb_Logic_izfb_idx_0 = VbALCA_LC_CancelReqFromDCSN;
  }

  /* End of Switch: '<S47>/Switch5' */

  /* CombinatorialLogic: '<S56>/Logic' incorporates:
   *  Logic: '<S47>/Logical Operator'
   *  Memory: '<S56>/Memory'
   */
  rtb_Logic_izfb_idx_0 = ALCA_subsystem_integrate_ConstP.pooled8[(((((uint32_T)
    (rtb_LogicalOperator2_nutm ? 1U : 0U)) << 1) + ((uint32_T)
    ((rtb_Logic_izfb_idx_0 || rtu_reset_lc_req) ? 1 : 0))) << 1) +
    (ALCA_subsystem_integrated_DW.Memory_PreviousInput_h3op ? 1U : 0U)];

  /* SignalConversion: '<S47>/Signal Conversion2' incorporates:
   *  Inport: '<Root>/DCSN_DataBus'
   */
  VeALCA_ReqSideFromDCSN =
    VsDCSN_DataBus.TrafficDecider_Group.change_lane_req_side;

  /* Switch: '<S47>/Switch4' incorporates:
   *  Constant: '<S54>/Constant'
   *  Switch: '<S47>/Switch3'
   *  UnitDelay: '<S47>/Unit Delay'
   */
  if (rtu_reset_lc_req)
  {
    rtb_Switch4 = FORWARD;
  }
  else if (rtb_LogicalOperator2_nutm)
  {
    /* Switch: '<S47>/Switch3' */
    rtb_Switch4 = VeALCA_ReqSideFromDCSN;
  }
  else
  {
    rtb_Switch4 = ALCA_subsystem_integrated_DW.change_lane_req_side;
  }

  /* End of Switch: '<S47>/Switch4' */

  /* BusCreator: '<S47>/Bus Creator' incorporates:
   *  Inport: '<Root>/DCSN_DataBus'
   *  SignalConversion: '<S47>/Signal Conversion4'
   *  SignalConversion: '<S47>/Signal Conversion5'
   */
  rty_dcsn_info->alca_enable =
    VsDCSN_DataBus.EnablingFlags_Group.alca_feature_enable;
  rty_dcsn_info->change_lane_req = rtb_Logic_izfb_idx_0;
  rty_dcsn_info->change_lane_req_side = rtb_Switch4;
  rty_dcsn_info->change_lane_cancel = rtb_Logic_idx_0;
  rty_dcsn_info->change_lane_reason =
    VsDCSN_DataBus.TrafficDecider_Group.change_lane_reason;
  rty_dcsn_info->change_lane_cancel_reason =
    VsDCSN_DataBus.TrafficDecider_Group.change_lane_cancel_reason;

  /* SignalConversion: '<S47>/Signal Conversion7' */
  VbALCA_LC_Req = rty_dcsn_info->change_lane_req;

  /* SignalConversion: '<S47>/Signal Conversion8' */
  VeALCA_ReqSide = rty_dcsn_info->change_lane_req_side;

  /* SignalConversion: '<S47>/Signal Conversion9' */
  VbALCA_LC_CancelReq = rty_dcsn_info->change_lane_cancel;

  /* Update for Memory: '<S57>/Memory' */
  ALCA_subsystem_integrated_DW.Memory_PreviousInput = rtb_Logic_idx_0;

  /* Update for Memory: '<S56>/Memory' */
  ALCA_subsystem_integrated_DW.Memory_PreviousInput_h3op = rtb_Logic_izfb_idx_0;

  /* Update for UnitDelay: '<S47>/Unit Delay' */
  ALCA_subsystem_integrated_DW.change_lane_req_side = rtb_Switch4;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
