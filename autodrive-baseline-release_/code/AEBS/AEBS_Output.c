/*
 * File: AEBS_Output.c
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

#include "AEBS_Output.h"

/* Include model header file for global data */
#include "AEBS_subsystem_integrated.h"
#include "AEBS_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S3>/AEBS_Output' */
void AEBS_subsystem_inte_AEBS_Output(void)
{
  boolean_T rtb_LogicalOperator_it3m;
  boolean_T rtb_RelationalOperator;

  /* SignalConversion: '<S7>/Signal Conversion9' */
  VfAEBS_FCW_request = AEBS_subsystem_integrated_B.request;

  /* Logic: '<S27>/Logical Operator' incorporates:
   *  Constant: '<S30>/Constant'
   *  Constant: '<S33>/Constant'
   *  RelationalOperator: '<S27>/Relational Operator1'
   *  RelationalOperator: '<S27>/Relational Operator2'
   */
  rtb_LogicalOperator_it3m =
    ((AEBS_subsystem_integrated_B.BusCreator.AEB_actived_state ==
      AEBS_AEBState_FullBrakeActived) ||
     (AEBS_subsystem_integrated_B.BusCreator.AEB_actived_state ==
      AEBS_AEBState_ConfidenceConfirmed));

  /* RelationalOperator: '<S27>/Relational Operator' incorporates:
   *  Constant: '<S29>/Constant'
   */
  rtb_RelationalOperator =
    (AEBS_subsystem_integrated_B.BusCreator.AEB_actived_state ==
     AEBS_AEBState_PartialBrakeActived);

  /* Switch: '<S27>/Switch1' incorporates:
   *  Constant: '<S27>/Constant1'
   *  Switch: '<S27>/Switch'
   */
  if (rtb_LogicalOperator_it3m)
  {
    VfAEBS_FCW_warn_level = ((uint8_T)5U);
  }
  else if (rtb_RelationalOperator)
  {
    /* Switch: '<S27>/Switch' incorporates:
     *  Constant: '<S27>/Constant'
     */
    VfAEBS_FCW_warn_level = ((uint8_T)4U);
  }
  else
  {
    VfAEBS_FCW_warn_level = AEBS_subsystem_integrated_B.warn_level;
  }

  /* End of Switch: '<S27>/Switch1' */

  /* SignalConversion: '<S7>/Signal Conversion10' */
  VfAEBS_FCW_enable_state = AEBS_subsystem_integrated_B.enable_state;

  /* Switch: '<S27>/Switch3' incorporates:
   *  Constant: '<S32>/Constant'
   *  Switch: '<S27>/Switch2'
   */
  if (rtb_LogicalOperator_it3m)
  {
    VfAEBS_FCW_active_state = AEBS_FCWState_Level5Actived;
  }
  else if (rtb_RelationalOperator)
  {
    /* Switch: '<S27>/Switch2' incorporates:
     *  Constant: '<S31>/Constant'
     */
    VfAEBS_FCW_active_state = AEBS_FCWState_Level4Actived;
  }
  else
  {
    VfAEBS_FCW_active_state = AEBS_subsystem_integrated_B.actived_state;
  }

  /* End of Switch: '<S27>/Switch3' */

  /* SignalConversion: '<S7>/Signal Conversion11' */
  VfAEBS_FCW_error = AEBS_subsystem_integrated_B.FCW_error;

  /* SignalConversion: '<S7>/Signal Conversion2' */
  VfAEBS_AEB_request = AEBS_subsystem_integrated_B.BusCreator.AEB_request;

  /* SignalConversion: '<S7>/Signal Conversion1' */
  VfAEBS_AEB_prebrake_req =
    AEBS_subsystem_integrated_B.BusCreator.AEB_prebrake_req;

  /* SignalConversion: '<S7>/Signal Conversion3' */
  VfAEBS_AEB_acceleration_req =
    AEBS_subsystem_integrated_B.BusCreator.AEB_acceleration_req;

  /* SignalConversion: '<S7>/Signal Conversion4' */
  VfAEBS_brakeLight_req =
    AEBS_subsystem_integrated_B.BusCreator.AEB_brakeLight_req;

  /* SignalConversion: '<S7>/Signal Conversion6' */
  VeAEBS_AEB_enabled_state =
    AEBS_subsystem_integrated_B.BusCreator.AEB_enabled_state;

  /* SignalConversion: '<S7>/Signal Conversion7' */
  VeAEBS_AEB_actived_state =
    AEBS_subsystem_integrated_B.BusCreator.AEB_actived_state;

  /* SignalConversion: '<S7>/Signal Conversion8' */
  VfAEBS_AEB_error = AEBS_subsystem_integrated_B.BusCreator.AEB_error;

  /* SignalConversion: '<S7>/Signal Conversion5' */
  VfAEBS_AEBS_brake_priority_setting =
    AEBS_subsystem_integrated_B.BusCreator.AEB_request;

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S34>/Constant'
   *  Constant: '<S35>/Constant'
   *  Constant: '<S36>/Constant'
   *  Constant: '<S37>/Constant'
   *  Constant: '<S38>/Constant'
   *  Logic: '<S28>/Logical Operator'
   *  RelationalOperator: '<S28>/Relational Operator'
   *  RelationalOperator: '<S28>/Relational Operator1'
   *  RelationalOperator: '<S28>/Relational Operator2'
   *  RelationalOperator: '<S28>/Relational Operator3'
   *  RelationalOperator: '<S28>/Relational Operator4'
   */
  if (((((AEBS_subsystem_integrated_B.actived_state >=
          AEBS_FCWState_Level1Actived) ||
         (AEBS_subsystem_integrated_B.BusCreator.AEB_actived_state ==
          AEBS_AEBState_PreBrakeActived)) ||
        (AEBS_subsystem_integrated_B.BusCreator.AEB_actived_state ==
         AEBS_AEBState_PartialBrakeActived)) ||
       (AEBS_subsystem_integrated_B.BusCreator.AEB_actived_state ==
        AEBS_AEBState_FullBrakeActived)) ||
      (AEBS_subsystem_integrated_B.BusCreator.AEB_actived_state ==
       AEBS_AEBState_ConfidenceConfirmed))
  {
    VfAEBS_AEBS_obs_id = AEBS_subsystem_integrated_B.Switch.obs_id_VIP;
  }
  else
  {
    VfAEBS_AEBS_obs_id = 0;
  }

  /* End of Switch: '<S28>/Switch' */

  /* BusCreator: '<S7>/BusCreator' incorporates:
   *  BusCreator: '<S7>/BusConversion_InsertedFor_BusCreator_at_inport_0'
   *  BusCreator: '<S7>/BusConversion_InsertedFor_BusCreator_at_inport_1'
   */
  VsAEBS_DataBus.FCW_Data.FCW_request = VfAEBS_FCW_request;
  VsAEBS_DataBus.FCW_Data.FCW_warn_level = VfAEBS_FCW_warn_level;
  VsAEBS_DataBus.FCW_Data.FCW_enable_state = VfAEBS_FCW_enable_state;
  VsAEBS_DataBus.FCW_Data.FCW_active_state = VfAEBS_FCW_active_state;
  VsAEBS_DataBus.FCW_Data.FCW_error = VfAEBS_FCW_error;
  VsAEBS_DataBus.AEB_Data.AEB_request = VfAEBS_AEB_request;
  VsAEBS_DataBus.AEB_Data.AEB_prebrake_req = VfAEBS_AEB_prebrake_req;
  VsAEBS_DataBus.AEB_Data.AEB_acceleration_req = VfAEBS_AEB_acceleration_req;
  VsAEBS_DataBus.AEB_Data.AEB_brakeLight_req = VfAEBS_brakeLight_req;
  VsAEBS_DataBus.AEB_Data.AEB_enabled_state = VeAEBS_AEB_enabled_state;
  VsAEBS_DataBus.AEB_Data.AEB_actived_state = VeAEBS_AEB_actived_state;
  VsAEBS_DataBus.AEB_Data.AEB_error = VfAEBS_AEB_error;
  VsAEBS_DataBus.AEBS_brake_priority_setting =
    VfAEBS_AEBS_brake_priority_setting;
  VsAEBS_DataBus.AEBS_horn_ctrl_req = VfAEBS_AEBS_horn_ctrl_req;
  VsAEBS_DataBus.AEBS_obj_ID = VfAEBS_AEBS_obs_id;
}

/* ConstCode for atomic system: '<S3>/AEBS_Output' */
void AEBS_subsyste_AEBS_Output_Const(void)
{
  /* ConstCode for SignalConversion: '<S7>/Signal Conversion12' incorporates:
   *  Constant: '<S7>/Constant'
   */
  VfAEBS_AEBS_horn_ctrl_req = false;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
