/*
 * File: SteerArbitration.c
 *
 * Code generated for Simulink model 'ARBT_subsystem_integrated'.
 *
 * Model version                  : 1.644
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  2 11:29:36 2020
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

#include "SteerArbitration.h"

/* Include model header file for global data */
#include "ARBT_subsystem_integrated.h"
#include "ARBT_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S1>/SteerArbitration' */
void ARBT_subsystem_SteerArbitration(void)
{
  boolean_T rtb_LogicalOperator_aivz;
  boolean_T rtb_LogicalOperator3_evun;

  /* Logic: '<S8>/Logical Operator' incorporates:
   *  Inport: '<Root>/DCSN_DataBus'
   */
  rtb_LogicalOperator_aivz =
    (((VsDCSN_DataBus.EnablingFlags_Group.steer_ctrl_enable) &&
      (VsDCSN_DataBus.EnablingFlags_Group.lcc_feature_enable)) && (((int32_T)
       VsDCSN_DataBus.ADM_Group.usr_cmd_autodrive_activate) != 0));

  /* Logic: '<S8>/Logical Operator3' incorporates:
   *  Inport: '<Root>/DCSN_DataBus'
   *  Inport: '<Root>/LKAS_DataBus'
   */
  rtb_LogicalOperator3_evun = (((VsLKAS_DataBus.Intv_Request) &&
    (VsDCSN_DataBus.EnablingFlags_Group.steer_ctrl_enable)) &&
    (VsDCSN_DataBus.EnablingFlags_Group.lka_feature_enable));

  /* MATLAB Function: '<S8>/MATLAB Function' incorporates:
   *  Constant: '<S8>/Constant2'
   *  Constant: '<S8>/Constant8'
   */
  if (rtb_LogicalOperator_aivz)
  {
    VeARBT_steer_arbt_winner = LCC;

    /* Switch: '<S8>/Switch4' incorporates:
     *  Inport: '<Root>/LCCS_DataBus'
     */
    VfARBT_steer_req_strwhl_angle_raw = VsLCCS_DataBus.veh_strwhl_angle_des;
    VfARBT_steer_req_strwhl_torque = 0.0F;
  }
  else if (rtb_LogicalOperator3_evun)
  {
    VeARBT_steer_arbt_winner = LKA;

    /* Switch: '<S8>/Switch1' incorporates:
     *  Inport: '<Root>/LKAS_DataBus'
     */
    VfARBT_steer_req_strwhl_angle_raw = VsLKAS_DataBus.SteerData;
    VfARBT_steer_req_strwhl_torque = 0.0F;
  }
  else
  {
    VeARBT_steer_arbt_winner = ARBT_NO_REQ;
    VfARBT_steer_req_strwhl_angle_raw = 0.0F;
    VfARBT_steer_req_strwhl_torque = 0.0F;
  }

  /* End of MATLAB Function: '<S8>/MATLAB Function' */

  /* Switch: '<S29>/Switch2' incorporates:
   *  Constant: '<S8>/Constant6'
   *  Constant: '<S8>/Constant7'
   *  RelationalOperator: '<S29>/LowerRelop1'
   *  RelationalOperator: '<S29>/UpperRelop'
   *  Switch: '<S29>/Switch'
   */
  if (VfARBT_steer_req_strwhl_angle_raw >
      KfARBT_steer_req_strwhl_angle_upperlimit)
  {
    VfARBT_steer_req_strwhl_angle = KfARBT_steer_req_strwhl_angle_upperlimit;
  }
  else if (VfARBT_steer_req_strwhl_angle_raw <
           KfARBT_steer_req_strwhl_angle_lowerlimit)
  {
    /* Switch: '<S29>/Switch' incorporates:
     *  Constant: '<S8>/Constant7'
     */
    VfARBT_steer_req_strwhl_angle = KfARBT_steer_req_strwhl_angle_lowerlimit;
  }
  else
  {
    VfARBT_steer_req_strwhl_angle = VfARBT_steer_req_strwhl_angle_raw;
  }

  /* End of Switch: '<S29>/Switch2' */

  /* Logic: '<S8>/Logical Operator2' */
  VbARBT_steer_ctrl_enbl_to_comm = (rtb_LogicalOperator_aivz ||
    rtb_LogicalOperator3_evun);

  /* BusCreator: '<S8>/Bus Creator3' */
  VsARBT_DataBus.SteerGroup.steer_req_mode = VfARBT_steer_req_mode;
  VsARBT_DataBus.SteerGroup.steer_req_strwhl_angle =
    VfARBT_steer_req_strwhl_angle;
  VsARBT_DataBus.SteerGroup.steer_req_strwhl_torque =
    VfARBT_steer_req_strwhl_torque;
  VsARBT_DataBus.SteerGroup.steer_ctrl_enbl_to_comm =
    VbARBT_steer_ctrl_enbl_to_comm;
}

/* ConstCode for atomic system: '<S1>/SteerArbitration' */
void ARBT_sub_SteerArbitration_Const(void)
{
  /* ConstCode for Constant: '<S8>/Constant' */
  VfARBT_steer_req_mode = ((uint8_T)0U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
