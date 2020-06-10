/*
 * File: PowerArbitration.c
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

#include "PowerArbitration.h"

/* Include model header file for global data */
#include "ARBT_subsystem_integrated.h"
#include "ARBT_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S1>/PowerArbitration' */
void ARBT_subsystem_PowerArbitration(void)
{
  boolean_T rtb_LogicalOperator2_ajc4;

  /* Constant: '<S6>/Constant2' */
  VfARBT_power_req_mode = KbARBT_power_req_mode_man_ctrl_temp;

  /* Logic: '<S6>/Logical Operator2' incorporates:
   *  Constant: '<S23>/Constant'
   *  Inport: '<Root>/ACCS_DataBus'
   *  Inport: '<Root>/DCSN_DataBus'
   *  Logic: '<S6>/Logical Operator1'
   *  RelationalOperator: '<S23>/Compare'
   */
  rtb_LogicalOperator2_ajc4 =
    ((((VsDCSN_DataBus.EnablingFlags_Group.power_ctrl_enable) &&
       (VsDCSN_DataBus.EnablingFlags_Group.acc_feature_enable)) && (((int32_T)
        VsDCSN_DataBus.ADM_Group.usr_cmd_autodrive_activate) != 0)) &&
     ((VsACCS_DataBus.VbACCS_Lon_Accleration_req) &&
      (VsACCS_DataBus.VfACCS_Lon_Accleration >= 0.0F)));

  /* Switch: '<S6>/Switch2' incorporates:
   *  Constant: '<S6>/Constant3'
   *  Inport: '<Root>/ACCS_DataBus'
   */
  if (rtb_LogicalOperator2_ajc4)
  {
    VfARBT_power_req_lon_a_raw = VsACCS_DataBus.VfACCS_Lon_Accleration;
  }
  else
  {
    VfARBT_power_req_lon_a_raw = 0.0F;
  }

  /* End of Switch: '<S6>/Switch2' */

  /* Switch: '<S22>/Switch2' incorporates:
   *  Constant: '<S6>/Constant6'
   *  Constant: '<S6>/Constant7'
   *  RelationalOperator: '<S22>/LowerRelop1'
   *  RelationalOperator: '<S22>/UpperRelop'
   *  Switch: '<S22>/Switch'
   */
  if (VfARBT_power_req_lon_a_raw > KfARBT_power_req_lon_a_upperlimit)
  {
    VfARBT_power_req_lon_a = KfARBT_power_req_lon_a_upperlimit;
  }
  else if (VfARBT_power_req_lon_a_raw < KfARBT_power_req_lon_a_lowerlimit)
  {
    /* Switch: '<S22>/Switch' incorporates:
     *  Constant: '<S6>/Constant7'
     */
    VfARBT_power_req_lon_a = KfARBT_power_req_lon_a_lowerlimit;
  }
  else
  {
    VfARBT_power_req_lon_a = VfARBT_power_req_lon_a_raw;
  }

  /* End of Switch: '<S22>/Switch2' */

  /* Switch: '<S6>/Switch1' incorporates:
   *  Constant: '<S6>/Constant'
   *  Inport: '<Root>/ACCS_DataBus'
   */
  if (rtb_LogicalOperator2_ajc4)
  {
    VfARBT_power_req_torque = VsACCS_DataBus.VfACCS_Lon_Torq;
  }
  else
  {
    VfARBT_power_req_torque = 0.0F;
  }

  /* End of Switch: '<S6>/Switch1' */

  /* Switch: '<S6>/Switch3' incorporates:
   *  Constant: '<S6>/Constant5'
   */
  if (ARBT_subsystem_integrated_B.BrakeGroup.brake_ctrl_enbl_to_comm)
  {
    VbARBT_power_ctrl_enbl_to_comm = false;
  }
  else
  {
    VbARBT_power_ctrl_enbl_to_comm = rtb_LogicalOperator2_ajc4;
  }

  /* End of Switch: '<S6>/Switch3' */

  /* BusCreator: '<S6>/Bus Creator3' */
  ARBT_subsystem_integrated_B.PowerGroup.power_req_mode = VfARBT_power_req_mode;
  ARBT_subsystem_integrated_B.PowerGroup.power_req_lon_a =
    VfARBT_power_req_lon_a;
  ARBT_subsystem_integrated_B.PowerGroup.power_req_torque =
    VfARBT_power_req_torque;
  ARBT_subsystem_integrated_B.PowerGroup.power_ctrl_enbl_to_comm =
    VbARBT_power_ctrl_enbl_to_comm;

  /* Switch: '<S6>/Switch4' incorporates:
   *  Constant: '<S6>/Constant8'
   */
  if (ARBT_subsystem_integrated_B.BrakeGroup.brake_ctrl_enbl_to_comm)
  {
    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S6>/Constant1'
     *  Constant: '<S6>/Constant4'
     */
    if (rtb_LogicalOperator2_ajc4)
    {
      VeARBT_power_arbt_winner = ACC;
    }
    else
    {
      VeARBT_power_arbt_winner = ARBT_NO_REQ;
    }

    /* End of Switch: '<S6>/Switch' */
  }
  else
  {
    VeARBT_power_arbt_winner = BRAKE_OVRD;
  }

  /* End of Switch: '<S6>/Switch4' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
