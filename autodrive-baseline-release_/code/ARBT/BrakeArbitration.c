/*
 * File: BrakeArbitration.c
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

#include "BrakeArbitration.h"

/* Include model header file for global data */
#include "ARBT_subsystem_integrated.h"
#include "ARBT_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S1>/BrakeArbitration' */
void ARBT_subsystem_BrakeArbitration(void)
{
  boolean_T rtb_LogicalOperator1;
  real32_T rtb_Switch1;
  real32_T rtb_Switch;

  /* Switch: '<S4>/Switch1' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Inport: '<Root>/ACCS_DataBus'
   *  Inport: '<Root>/DCSN_DataBus'
   *  Logic: '<S4>/Logical Operator2'
   */
  if (((VsACCS_DataBus.VbACCS_Lon_Accleration_req) &&
       (VsDCSN_DataBus.EnablingFlags_Group.acc_feature_enable)) && (((int32_T)
        VsDCSN_DataBus.ADM_Group.usr_cmd_autodrive_activate) != 0))
  {
    rtb_Switch1 = VsACCS_DataBus.VfACCS_Lon_Accleration;
  }
  else
  {
    rtb_Switch1 = 0.0001F;
  }

  /* End of Switch: '<S4>/Switch1' */

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant'
   *  Inport: '<Root>/AEBS_DataBus'
   *  Inport: '<Root>/DCSN_DataBus'
   *  Logic: '<S4>/Logical Operator3'
   */
  if ((VsAEBS_DataBus.AEB_Data.AEB_request) &&
      (VsDCSN_DataBus.EnablingFlags_Group.aeb_feature_enable))
  {
    rtb_Switch = VsAEBS_DataBus.AEB_Data.AEB_acceleration_req;
  }
  else
  {
    rtb_Switch = 0.0001F;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Logic: '<S4>/Logical Operator1' incorporates:
   *  Inport: '<Root>/DCSN_DataBus'
   *  Logic: '<S4>/Logical Operator'
   *  Logic: '<S4>/Logical Operator5'
   */
  rtb_LogicalOperator1 = ((VsDCSN_DataBus.EnablingFlags_Group.brake_ctrl_enable)
    && (((VsDCSN_DataBus.EnablingFlags_Group.acc_feature_enable) && (((int32_T)
    VsDCSN_DataBus.ADM_Group.usr_cmd_autodrive_activate) != 0)) ||
        (VsDCSN_DataBus.EnablingFlags_Group.aeb_feature_enable)));

  /* Switch: '<S4>/Switch4' incorporates:
   *  Constant: '<S4>/Constant5'
   */
  if (rtb_LogicalOperator1)
  {
    /* MinMax: '<S4>/MinMax' */
    if (rtb_Switch1 < rtb_Switch)
    {
      VfARBT_brake_req_lon_a_raw = rtb_Switch1;
    }
    else
    {
      VfARBT_brake_req_lon_a_raw = rtb_Switch;
    }

    /* End of MinMax: '<S4>/MinMax' */
  }
  else
  {
    VfARBT_brake_req_lon_a_raw = 0.0F;
  }

  /* End of Switch: '<S4>/Switch4' */

  /* Switch: '<S21>/Switch2' incorporates:
   *  Constant: '<S4>/Constant6'
   *  Constant: '<S4>/Constant7'
   *  RelationalOperator: '<S21>/LowerRelop1'
   *  RelationalOperator: '<S21>/UpperRelop'
   *  Switch: '<S21>/Switch'
   */
  if (VfARBT_brake_req_lon_a_raw > KfARBT_brake_req_lon_a_upperlimit)
  {
    VfARBT_brake_req_lon_a = KfARBT_brake_req_lon_a_upperlimit;
  }
  else if (VfARBT_brake_req_lon_a_raw < KfARBT_brake_req_lon_a_lowerlimit)
  {
    /* Switch: '<S21>/Switch' incorporates:
     *  Constant: '<S4>/Constant7'
     */
    VfARBT_brake_req_lon_a = KfARBT_brake_req_lon_a_lowerlimit;
  }
  else
  {
    VfARBT_brake_req_lon_a = VfARBT_brake_req_lon_a_raw;
  }

  /* End of Switch: '<S21>/Switch2' */

  /* Logic: '<S4>/Logical Operator4' incorporates:
   *  Constant: '<S20>/Constant'
   *  RelationalOperator: '<S20>/Compare'
   */
  VbARBT_brake_ctrl_enbl_to_comm = ((VfARBT_brake_req_lon_a <= (-0.01F)) &&
    rtb_LogicalOperator1);

  /* BusCreator: '<S4>/Bus Creator' incorporates:
   *  Constant: '<S4>/Constant8'
   *  Constant: '<S4>/Constant9'
   */
  ARBT_subsystem_integrated_B.BrakeGroup.brake_req_lon_a =
    VfARBT_brake_req_lon_a;
  ARBT_subsystem_integrated_B.BrakeGroup.brake_ctrl_enbl_to_comm =
    VbARBT_brake_ctrl_enbl_to_comm;
  ARBT_subsystem_integrated_B.BrakeGroup.brake_precharge_req = false;
  ARBT_subsystem_integrated_B.BrakeGroup.brake_priority_setting = false;

  /* Switch: '<S4>/Switch3' incorporates:
   *  Constant: '<S4>/Constant4'
   */
  if (VbARBT_brake_ctrl_enbl_to_comm)
  {
    /* Switch: '<S4>/Switch2' incorporates:
     *  Constant: '<S4>/Constant2'
     *  Constant: '<S4>/Constant3'
     *  RelationalOperator: '<S4>/Relational Operator'
     */
    if (rtb_Switch1 < rtb_Switch)
    {
      VeARBT_brake_arbt_winner = ACC;
    }
    else
    {
      VeARBT_brake_arbt_winner = AEB;
    }

    /* End of Switch: '<S4>/Switch2' */
  }
  else
  {
    VeARBT_brake_arbt_winner = ARBT_NO_REQ;
  }

  /* End of Switch: '<S4>/Switch3' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
