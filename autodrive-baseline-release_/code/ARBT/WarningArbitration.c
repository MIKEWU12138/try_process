/*
 * File: WarningArbitration.c
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

#include "WarningArbitration.h"

/* Include model header file for global data */
#include "ARBT_subsystem_integrated.h"
#include "ARBT_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S1>/WarningArbitration' */
void ARBT_subsyst_WarningArbitration(void)
{
  boolean_T rtb_RelationalOperator_gqn0;
  boolean_T rtb_RelationalOperator3;

  /* RelationalOperator: '<S9>/Relational Operator' incorporates:
   *  Constant: '<S9>/Constant'
   *  Inport: '<Root>/AEBS_DataBus'
   */
  rtb_RelationalOperator_gqn0 = (true == VsAEBS_DataBus.FCW_Data.FCW_request);

  /* Logic: '<S9>/Logical Operator15' incorporates:
   *  Constant: '<S9>/Constant10'
   *  Inport: '<Root>/AEBS_DataBus'
   *  Inport: '<Root>/DCSN_DataBus'
   *  RelationalOperator: '<S9>/Relational Operator14'
   */
  VbARBT_FCW_level_three =
    (((VsDCSN_DataBus.EnablingFlags_Group.fcw_feature_enable) &&
      rtb_RelationalOperator_gqn0) && (((uint8_T)3U) ==
      VsAEBS_DataBus.FCW_Data.FCW_warn_level));

  /* Logic: '<S9>/Logical Operator' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Inport: '<Root>/AEBS_DataBus'
   *  Inport: '<Root>/DCSN_DataBus'
   *  RelationalOperator: '<S9>/Relational Operator1'
   */
  VbARBT_FCW_level_one =
    (((VsDCSN_DataBus.EnablingFlags_Group.fcw_feature_enable) &&
      rtb_RelationalOperator_gqn0) && (((uint8_T)1U) ==
      VsAEBS_DataBus.FCW_Data.FCW_warn_level));

  /* Logic: '<S9>/Logical Operator1' incorporates:
   *  Constant: '<S9>/Constant2'
   *  Inport: '<Root>/AEBS_DataBus'
   *  Inport: '<Root>/DCSN_DataBus'
   *  RelationalOperator: '<S9>/Relational Operator2'
   */
  VbARBT_FCW_level_two =
    (((VsDCSN_DataBus.EnablingFlags_Group.fcw_feature_enable) &&
      rtb_RelationalOperator_gqn0) && (((uint8_T)2U) ==
      VsAEBS_DataBus.FCW_Data.FCW_warn_level));

  /* RelationalOperator: '<S9>/Relational Operator3' incorporates:
   *  Constant: '<S9>/Constant3'
   *  Inport: '<Root>/LDWS_DataBus'
   */
  rtb_RelationalOperator3 = (true == VsLDWS_DataBus.LDWS_warn_st);

  /* Logic: '<S9>/Logical Operator2' incorporates:
   *  Constant: '<S9>/Constant4'
   *  Inport: '<Root>/DCSN_DataBus'
   *  Inport: '<Root>/LDWS_DataBus'
   *  RelationalOperator: '<S9>/Relational Operator4'
   */
  VbARBT_LDW_left = (((VsDCSN_DataBus.EnablingFlags_Group.ldw_feature_enable) &&
                      rtb_RelationalOperator3) && (VsLDWS_DataBus.LDWS_warn_side
    == LDWS_WarnLe));

  /* Logic: '<S9>/Logical Operator4' incorporates:
   *  Constant: '<S9>/Constant6'
   *  Inport: '<Root>/BSDS_DataBus'
   *  Inport: '<Root>/DCSN_DataBus'
   *  RelationalOperator: '<S9>/Relational Operator6'
   */
  VbARBT_BSD_left_low_raw =
    ((VsDCSN_DataBus.EnablingFlags_Group.bsd_feature_enable) &&
     (VsBSDS_DataBus.left_warning_status == BSDS_WARNING_LOW_LEVEL));

  /* Logic: '<S9>/Logical Operator5' incorporates:
   *  Constant: '<S9>/Constant6'
   *  Inport: '<Root>/BSDS_DataBus'
   *  Inport: '<Root>/DCSN_DataBus'
   *  RelationalOperator: '<S9>/Relational Operator7'
   */
  VbARBT_BSD_right_low_raw =
    ((VsDCSN_DataBus.EnablingFlags_Group.bsd_feature_enable) &&
     (VsBSDS_DataBus.right_warning_status == BSDS_WARNING_LOW_LEVEL));

  /* Logic: '<S9>/Logical Operator6' incorporates:
   *  Constant: '<S9>/Constant8'
   *  Inport: '<Root>/DCSN_DataBus'
   *  Inport: '<Root>/LCAS_DataBus'
   *  RelationalOperator: '<S9>/Relational Operator10'
   */
  VbARBT_LCA_left_low_raw =
    ((VsDCSN_DataBus.EnablingFlags_Group.lca_feature_enable) &&
     (VsLCAS_DataBus.left_warning_status == LCAS_WARNING_LOW_LEVEL));

  /* Logic: '<S9>/Logical Operator7' incorporates:
   *  Constant: '<S9>/Constant8'
   *  Inport: '<Root>/DCSN_DataBus'
   *  Inport: '<Root>/LCAS_DataBus'
   *  RelationalOperator: '<S9>/Relational Operator11'
   */
  VbARBT_LCA_right_low_raw =
    ((VsDCSN_DataBus.EnablingFlags_Group.lca_feature_enable) &&
     (VsLCAS_DataBus.right_warning_status == LCAS_WARNING_LOW_LEVEL));

  /* Logic: '<S9>/Logical Operator9' incorporates:
   *  Logic: '<S9>/Logical Operator18'
   */
  VbARBT_warn_lcw_left_req = (((((VbARBT_LDW_left || VbARBT_BSD_left_low_raw) ||
    VbARBT_LCA_left_low_raw) || VbARBT_BSD_right_low_raw) ||
    VbARBT_LCA_right_low_raw) || ((VbARBT_FCW_level_one || VbARBT_FCW_level_two)
    || VbARBT_FCW_level_three));

  /* Logic: '<S9>/Logical Operator3' incorporates:
   *  Constant: '<S9>/Constant5'
   *  Inport: '<Root>/DCSN_DataBus'
   *  Inport: '<Root>/LDWS_DataBus'
   *  RelationalOperator: '<S9>/Relational Operator5'
   */
  VbARBT_LDW_right = (((VsDCSN_DataBus.EnablingFlags_Group.ldw_feature_enable) &&
                       rtb_RelationalOperator3) &&
                      (VsLDWS_DataBus.LDWS_warn_side == LDWS_WarnRi));

  /* Logic: '<S9>/Logical Operator8' */
  VsARBT_DataBus.WarningGroup.warn_acoustic_req = (((((((VbARBT_FCW_level_one ||
    VbARBT_FCW_level_two) || VbARBT_LDW_left) || VbARBT_LDW_right) ||
    VbARBT_BSD_left_low_raw) || VbARBT_BSD_right_low_raw) ||
    VbARBT_LCA_left_low_raw) || VbARBT_LCA_right_low_raw);

  /* Logic: '<S9>/Logical Operator11' incorporates:
   *  Constant: '<S9>/Constant7'
   *  Inport: '<Root>/BSDS_DataBus'
   *  Inport: '<Root>/DCSN_DataBus'
   *  RelationalOperator: '<S9>/Relational Operator8'
   */
  VbARBT_BSD_left_high_raw =
    ((VsDCSN_DataBus.EnablingFlags_Group.bsd_feature_enable) &&
     (VsBSDS_DataBus.left_warning_status == BSDS_WARNING_HIGH_LEVEL));

  /* Logic: '<S9>/Logical Operator13' incorporates:
   *  Constant: '<S9>/Constant9'
   *  Inport: '<Root>/DCSN_DataBus'
   *  Inport: '<Root>/LCAS_DataBus'
   *  RelationalOperator: '<S9>/Relational Operator12'
   */
  VbARBT_LCA_left_high_raw =
    ((VsDCSN_DataBus.EnablingFlags_Group.lca_feature_enable) &&
     (VsLCAS_DataBus.left_warning_status == LCAS_WARNING_HIGH_LEVEL));

  /* Logic: '<S9>/Logical Operator12' incorporates:
   *  Constant: '<S9>/Constant7'
   *  Inport: '<Root>/BSDS_DataBus'
   *  Inport: '<Root>/DCSN_DataBus'
   *  RelationalOperator: '<S9>/Relational Operator9'
   */
  VbARBT_BSD_right_high_raw =
    ((VsDCSN_DataBus.EnablingFlags_Group.bsd_feature_enable) &&
     (VsBSDS_DataBus.right_warning_status == BSDS_WARNING_HIGH_LEVEL));

  /* Logic: '<S9>/Logical Operator14' incorporates:
   *  Constant: '<S9>/Constant9'
   *  Inport: '<Root>/DCSN_DataBus'
   *  Inport: '<Root>/LCAS_DataBus'
   *  RelationalOperator: '<S9>/Relational Operator13'
   */
  VbARBT_LCA_right_high_raw =
    ((VsDCSN_DataBus.EnablingFlags_Group.lca_feature_enable) &&
     (VsLCAS_DataBus.right_warning_status == LCAS_WARNING_HIGH_LEVEL));

  /* Logic: '<S9>/Logical Operator16' incorporates:
   *  Constant: '<S9>/Constant11'
   *  Inport: '<Root>/AEBS_DataBus'
   *  Inport: '<Root>/DCSN_DataBus'
   *  RelationalOperator: '<S9>/Relational Operator15'
   */
  VbARBT_FCW_level_four =
    (((VsDCSN_DataBus.EnablingFlags_Group.fcw_feature_enable) &&
      rtb_RelationalOperator_gqn0) && (((uint8_T)4U) ==
      VsAEBS_DataBus.FCW_Data.FCW_warn_level));

  /* Logic: '<S9>/Logical Operator17' incorporates:
   *  Constant: '<S9>/Constant12'
   *  Inport: '<Root>/AEBS_DataBus'
   *  Inport: '<Root>/DCSN_DataBus'
   *  RelationalOperator: '<S9>/Relational Operator16'
   */
  VbARBT_FCW_level_five =
    (((VsDCSN_DataBus.EnablingFlags_Group.fcw_feature_enable) &&
      rtb_RelationalOperator_gqn0) && (((uint8_T)5U) ==
      VsAEBS_DataBus.FCW_Data.FCW_warn_level));

  /* Logic: '<S9>/Logical Operator10' incorporates:
   *  Inport: '<Root>/DCSN_DataBus'
   *  Logic: '<S9>/Logical Operator19'
   */
  VbARBT_warn_lcw_right_req = ((((((VbARBT_LDW_right || VbARBT_BSD_left_high_raw)
    || VbARBT_LCA_left_high_raw) || VbARBT_BSD_right_high_raw) ||
    VbARBT_LCA_right_high_raw) || (VbARBT_FCW_level_four ||
    VbARBT_FCW_level_five)) || (VsDCSN_DataBus.ADM_Group.acoustic_warning_req));

  /* BusCreator: '<S9>/Bus Creator' */
  VsARBT_DataBus.WarningGroup.warn_haptic_req = false;
  VsARBT_DataBus.WarningGroup.warn_visual_lcw_left_req =
    VbARBT_warn_lcw_left_req;
  VsARBT_DataBus.WarningGroup.warn_visual_lcw_right_req =
    VbARBT_warn_lcw_right_req;
  VsARBT_DataBus.WarningGroup.warn_visual_ldw_left_req = false;
  VsARBT_DataBus.WarningGroup.warn_visual_ldw_right_req = false;
  VsARBT_DataBus.WarningGroup.warn_visual_fcw_req = false;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
