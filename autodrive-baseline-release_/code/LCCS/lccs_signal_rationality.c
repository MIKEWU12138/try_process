/*
 * File: lccs_signal_rationality.c
 *
 * Code generated for Simulink model 'LCCS_subsystem_integrated'.
 *
 * Model version                  : 1.2176
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Jun 10 09:42:58 2020
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

#include "lccs_signal_rationality.h"

/* Include model header file for global data */
#include "LCCS_subsystem_integrated.h"
#include "LCCS_subsystem_integrated_private.h"

/* Named constants for Chart: '<S11>/left_turn_signal' */
#define LCCS_su_IN_NO_ACTIVE_CHILD_pzc0 ((uint8_T)0U)
#define LCCS_subsystem_inte_IN_inactive ((uint8_T)2U)
#define LCCS_subsystem_integr_IN_active ((uint8_T)1U)

/* System initialize for atomic system: '<S2>/DtrmnLCCS_sensor_signal_rationality' */
void DtrmnLCCS_sensor_signal_ra_Init(void)
{
  /* SystemInitialize for Chart: '<S11>/left_turn_signal' */
  LCCS_subsystem_integrated_DW.temporalCounter_i1_guw3 = 0U;
  LCCS_subsystem_integrated_DW.is_active_c10_LCCS_subsystem_in = 0U;
  LCCS_subsystem_integrated_DW.is_c10_LCCS_subsystem_integrate =
    LCCS_su_IN_NO_ACTIVE_CHILD_pzc0;
  LCCS_subsystem_integrated_B.left_turn_signal = false;

  /* SystemInitialize for Chart: '<S11>/right_turn_signal' */
  LCCS_subsystem_integrated_DW.temporalCounter_i1_iexi = 0U;
  LCCS_subsystem_integrated_DW.is_active_c12_LCCS_subsystem_in = 0U;
  LCCS_subsystem_integrated_DW.is_c12_LCCS_subsystem_integrate =
    LCCS_su_IN_NO_ACTIVE_CHILD_pzc0;
  LCCS_subsystem_integrated_B.right_turn_signal = false;
}

/* Output and update for atomic system: '<S2>/DtrmnLCCS_sensor_signal_rationality' */
void DtrmnLCCS_sensor_signal_rationa(void)
{
  boolean_T rtb_RelationalOperator11_pp0v;
  boolean_T rtb_LogicalOperator5_bk2b;
  boolean_T rtb_RelationalOperator11_aflp;
  boolean_T rtb_RelationalOperator11_c2oq;
  boolean_T rtb_RelationalOperator11_hgud;
  boolean_T rtb_RelationalOperator11_c5xx;
  boolean_T rtb_RelationalOperator11_mhde;
  real32_T rtb_UnitDelay_chni;
  real32_T rtb_Switch2;
  real32_T rtb_Switch2_bkaf;
  real32_T rtb_UnitDelay_obn3;
  real_T tmp;

  /* Switch: '<S11>/Switch11' incorporates:
   *  Constant: '<S11>/Constant10'
   *  Constant: '<S11>/Constant9'
   *  Inport: '<Root>/VsEGMO_DataBus'
   */
  if (VsEGMO_DataBus.timestamp_low > 0U)
  {
    tmp = 1.0;
  }
  else
  {
    tmp = (-1.0);
  }

  /* End of Switch: '<S11>/Switch11' */

  /* Sum: '<S11>/Add1' incorporates:
   *  Constant: '<S11>/Constant15'
   *  Gain: '<S11>/Gain1'
   *  Inport: '<Root>/VsEGMO_DataBus'
   *  Product: '<S11>/Product2'
   *  Product: '<S11>/Product3'
   */
  VfLCCS_timestamp_EGMO = (((((real_T)1125899907) * 8.8817841970012523E-16) *
    ((real_T)VsEGMO_DataBus.timestamp_high)) * tmp) + (4294.967296 * ((real_T)
    VsEGMO_DataBus.timestamp_low));

  /* Switch: '<S149>/Switch2' incorporates:
   *  Inport: '<Root>/VsCOMM_CANR_Databus'
   */
  VcLCCS_EPS_SteeringControlResponse_LCC =
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse_LCC ? 1U :
    0U;

  /* RelationalOperator: '<S131>/Compare' incorporates:
   *  Constant: '<S131>/Constant'
   */
  rtb_RelationalOperator11_pp0v = (VcLCCS_EPS_SteeringControlResponse_LCC >
    ((uint8_T)0U));

  /* Logic: '<S11>/Logical Operator5' incorporates:
   *  Inport: '<Root>/VsCOMM_CANR_Databus'
   */
  rtb_LogicalOperator5_bk2b =
    ((VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState) &&
     rtb_RelationalOperator11_pp0v);

  /* Logic: '<S11>/Logical Operator6' incorporates:
   *  Inport: '<Root>/VsCOMM_CANR_Databus'
   */
  rtb_RelationalOperator11_pp0v = (rtb_RelationalOperator11_pp0v &&
    (VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState));

  /* Chart: '<S11>/left_turn_signal' incorporates:
   *  UnitDelay: '<S11>/Unit Delay'
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  if (((uint32_T)LCCS_subsystem_integrated_DW.temporalCounter_i1_guw3) < 1023U)
  {
    LCCS_subsystem_integrated_DW.temporalCounter_i1_guw3 = (uint16_T)((int32_T)
      (((int32_T)LCCS_subsystem_integrated_DW.temporalCounter_i1_guw3) + 1));
  }

  if (((uint32_T)LCCS_subsystem_integrated_DW.is_active_c10_LCCS_subsystem_in) ==
      0U)
  {
    LCCS_subsystem_integrated_DW.is_active_c10_LCCS_subsystem_in = 1U;
    LCCS_subsystem_integrated_DW.is_c10_LCCS_subsystem_integrate =
      LCCS_subsystem_inte_IN_inactive;
    LCCS_subsystem_integrated_B.left_turn_signal = false;
  }
  else if (((uint32_T)
            LCCS_subsystem_integrated_DW.is_c10_LCCS_subsystem_integrate) ==
           LCCS_subsystem_integr_IN_active)
  {
    /*   */
    if (rtb_RelationalOperator11_pp0v || ((((int32_T)
           LCCS_subsystem_integrated_DW.temporalCounter_i1_guw3) >= 1000) &&
         (!rtb_LogicalOperator5_bk2b)))
    {
      LCCS_subsystem_integrated_DW.is_c10_LCCS_subsystem_integrate =
        LCCS_subsystem_inte_IN_inactive;
      LCCS_subsystem_integrated_B.left_turn_signal = false;
    }
  }
  else
  {
    if ((((!LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_l0sm) &&
          rtb_LogicalOperator5_bk2b) && (!rtb_RelationalOperator11_pp0v)) &&
        (!LCCS_subsystem_integrated_B.right_turn_signal))
    {
      LCCS_subsystem_integrated_DW.is_c10_LCCS_subsystem_integrate =
        LCCS_subsystem_integr_IN_active;
      LCCS_subsystem_integrated_DW.temporalCounter_i1_guw3 = 0U;
      LCCS_subsystem_integrated_B.left_turn_signal = true;
    }
  }

  /* End of Chart: '<S11>/left_turn_signal' */

  /* Chart: '<S11>/right_turn_signal' incorporates:
   *  UnitDelay: '<S11>/Unit Delay1'
   *  UnitDelay: '<S11>/Unit Delay3'
   */
  if (((uint32_T)LCCS_subsystem_integrated_DW.temporalCounter_i1_iexi) < 1023U)
  {
    LCCS_subsystem_integrated_DW.temporalCounter_i1_iexi = (uint16_T)((int32_T)
      (((int32_T)LCCS_subsystem_integrated_DW.temporalCounter_i1_iexi) + 1));
  }

  if (((uint32_T)LCCS_subsystem_integrated_DW.is_active_c12_LCCS_subsystem_in) ==
      0U)
  {
    LCCS_subsystem_integrated_DW.is_active_c12_LCCS_subsystem_in = 1U;
    LCCS_subsystem_integrated_DW.is_c12_LCCS_subsystem_integrate =
      LCCS_subsystem_inte_IN_inactive;
    LCCS_subsystem_integrated_B.right_turn_signal = false;
  }
  else if (((uint32_T)
            LCCS_subsystem_integrated_DW.is_c12_LCCS_subsystem_integrate) ==
           LCCS_subsystem_integr_IN_active)
  {
    /*   */
    if (rtb_LogicalOperator5_bk2b || ((((int32_T)
           LCCS_subsystem_integrated_DW.temporalCounter_i1_iexi) >= 1000) &&
         (!rtb_RelationalOperator11_pp0v)))
    {
      LCCS_subsystem_integrated_DW.is_c12_LCCS_subsystem_integrate =
        LCCS_subsystem_inte_IN_inactive;
      LCCS_subsystem_integrated_B.right_turn_signal = false;
    }
  }
  else
  {
    if ((((!LCCS_subsystem_integrated_DW.UnitDelay1_DSTATE_lgx0) &&
          rtb_RelationalOperator11_pp0v) && (!rtb_LogicalOperator5_bk2b)) &&
        (!LCCS_subsystem_integrated_DW.UnitDelay3_DSTATE_nn4w))
    {
      LCCS_subsystem_integrated_DW.is_c12_LCCS_subsystem_integrate =
        LCCS_subsystem_integr_IN_active;
      LCCS_subsystem_integrated_DW.temporalCounter_i1_iexi = 0U;
      LCCS_subsystem_integrated_B.right_turn_signal = true;
    }
  }

  /* End of Chart: '<S11>/right_turn_signal' */

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S11>/Constant1'
   *  Constant: '<S11>/Constant4'
   *  Constant: '<S11>/Constant5'
   *  Switch: '<S11>/Switch8'
   */
  if (KbLCCS_lane_change_request_SLEW)
  {
    VbLCCS_lane_change_request = KbLCCS_lane_change_request_value;
  }
  else if (KbLCCS_lane_change_source_ALCA)
  {
    /* Switch: '<S11>/Switch8' incorporates:
     *  Inport: '<Root>/VsALCA_DataBus'
     *  Switch: '<S140>/Switch2'
     */
    VbLCCS_lane_change_request = VsALCA_DataBus.request;
  }
  else
  {
    /* Switch: '<S11>/Switch8' incorporates:
     *  Logic: '<S11>/Logical Operator3'
     */
    VbLCCS_lane_change_request = ((LCCS_subsystem_integrated_B.left_turn_signal)
      || (LCCS_subsystem_integrated_B.right_turn_signal));
  }

  /* End of Switch: '<S11>/Switch' */

  /* Switch: '<S11>/Switch3' incorporates:
   *  Constant: '<S11>/Constant13'
   *  Constant: '<S11>/Constant14'
   *  Inport: '<Root>/VsDCSN_DataBus'
   *  Switch: '<S145>/Switch2'
   */
  if (KbLCCS_inlane_nudge_request_SLEW)
  {
    VbLCCS_inlane_nudge_request = KbLCCS_inlane_nudge_request_value;
  }
  else
  {
    VbLCCS_inlane_nudge_request =
      VsDCSN_DataBus.TrafficDecider_Group.inlane_nudge_request;
  }

  /* End of Switch: '<S11>/Switch3' */

  /* Switch: '<S11>/Switch1' incorporates:
   *  Constant: '<S11>/Constant12'
   *  Constant: '<S11>/Constant6'
   *  Switch: '<S11>/Switch5'
   *  Switch: '<S11>/Switch6'
   */
  if (KbLCCS_lane_change_request_SLEW)
  {
    VeLCCS_shifting_direction_raw = KeLCCS_shifting_direction_value;
  }
  else if (VbLCCS_lane_change_request)
  {
    /* Switch: '<S11>/Switch7' incorporates:
     *  Constant: '<S11>/Constant2'
     *  Constant: '<S132>/Constant'
     *  Inport: '<Root>/VsALCA_DataBus'
     *  Switch: '<S11>/Switch2'
     *  Switch: '<S11>/Switch4'
     *  Switch: '<S11>/Switch5'
     *  Switch: '<S138>/Switch2'
     */
    if (KbLCCS_lane_change_source_ALCA)
    {
      VeLCCS_shifting_direction_raw = VsALCA_DataBus.request_side;
    }
    else if (LCCS_subsystem_integrated_B.left_turn_signal)
    {
      /* Switch: '<S11>/Switch2' incorporates:
       *  Constant: '<S133>/Constant'
       */
      VeLCCS_shifting_direction_raw = LEFT;
    }
    else if (LCCS_subsystem_integrated_B.right_turn_signal)
    {
      /* Switch: '<S11>/Switch4' incorporates:
       *  Constant: '<S134>/Constant'
       *  Switch: '<S11>/Switch2'
       */
      VeLCCS_shifting_direction_raw = RIGHT;
    }
    else
    {
      VeLCCS_shifting_direction_raw = FORWARD;
    }

    /* End of Switch: '<S11>/Switch7' */
  }
  else if (VbLCCS_inlane_nudge_request)
  {
    /* Switch: '<S11>/Switch6' incorporates:
     *  Inport: '<Root>/VsDCSN_DataBus'
     *  Switch: '<S11>/Switch5'
     *  Switch: '<S146>/Switch2'
     */
    VeLCCS_shifting_direction_raw =
      VsDCSN_DataBus.TrafficDecider_Group.inlane_nudge_side;
  }
  else
  {
    /* Switch: '<S11>/Switch5' incorporates:
     *  Constant: '<S135>/Constant'
     *  Switch: '<S11>/Switch6'
     */
    VeLCCS_shifting_direction_raw = FORWARD;
  }

  /* End of Switch: '<S11>/Switch1' */

  /* Logic: '<S11>/Logical Operator1' incorporates:
   *  RelationalOperator: '<S139>/Relational Operator11'
   */
  VbLCCS_input_isNaN_DCSN = false;

  /* Switch: '<S139>/Switch2' incorporates:
   *  Inport: '<Root>/VsDCSN_DataBus'
   */
  VbLCCS_lcc_feature_enable =
    VsDCSN_DataBus.EnablingFlags_Group.lcc_feature_enable;

  /* Switch: '<S147>/Switch2' incorporates:
   *  Inport: '<Root>/VsDCSN_DataBus'
   */
  VbLCCS_steer_control_enable =
    VsDCSN_DataBus.EnablingFlags_Group.steer_ctrl_enable;

  /* RelationalOperator: '<S141>/Relational Operator11' incorporates:
   *  Inport: '<Root>/VsALCA_DataBus'
   */
  rtb_RelationalOperator11_c5xx = rtIsNaNF(VsALCA_DataBus.lateral_v);

  /* Logic: '<S11>/Logical Operator4' */
  VbLCCS_input_isNaN_ALCA = rtb_RelationalOperator11_c5xx;

  /* Switch: '<S141>/Switch2' incorporates:
   *  Inport: '<Root>/VsALCA_DataBus'
   */
  if (rtb_RelationalOperator11_c5xx)
  {
    /* Switch: '<S141>/Switch' incorporates:
     *  Constant: '<S141>/Constant'
     *  RelationalOperator: '<S141>/Relational Operator1'
     *  UnitDelay: '<S141>/Unit Delay'
     */
    if (rtIsNaNF(VfLCCS_lateral_v_from_ALCA))
    {
      VfLCCS_lateral_v_from_ALCA = 0.1F;
    }

    /* End of Switch: '<S141>/Switch' */
  }
  else
  {
    VfLCCS_lateral_v_from_ALCA = VsALCA_DataBus.lateral_v;
  }

  /* End of Switch: '<S141>/Switch2' */

  /* RelationalOperator: '<S150>/Relational Operator11' incorporates:
   *  Inport: '<Root>/VsCOMM_CANR_Databus'
   */
  rtb_RelationalOperator11_c5xx = rtIsNaNF
    (VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle);

  /* RelationalOperator: '<S148>/Relational Operator11' incorporates:
   *  Inport: '<Root>/VsCOMM_CANR_Databus'
   */
  rtb_RelationalOperator11_hgud = rtIsNaNF
    (VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed);

  /* Logic: '<S11>/Logical Operator2' */
  VbLCCS_input_isNaN_COMM = (rtb_RelationalOperator11_c5xx ||
    rtb_RelationalOperator11_hgud);

  /* Switch: '<S148>/Switch2' incorporates:
   *  Inport: '<Root>/VsCOMM_CANR_Databus'
   */
  if (rtb_RelationalOperator11_hgud)
  {
    /* Switch: '<S148>/Switch' incorporates:
     *  Constant: '<S148>/Constant'
     *  RelationalOperator: '<S148>/Relational Operator1'
     *  UnitDelay: '<S148>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_mjzr))
    {
      rtb_UnitDelay_chni = 0.0F;
    }
    else
    {
      rtb_UnitDelay_chni = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_mjzr;
    }

    /* End of Switch: '<S148>/Switch' */
  }
  else
  {
    rtb_UnitDelay_chni =
      VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed;
  }

  /* End of Switch: '<S148>/Switch2' */

  /* RelationalOperator: '<S136>/Relational Operator11' incorporates:
   *  Inport: '<Root>/VsEGMO_DataBus'
   */
  rtb_RelationalOperator11_hgud = rtIsNaNF(VsEGMO_DataBus.motion.linear_velocity);

  /* Switch: '<S136>/Switch2' incorporates:
   *  Inport: '<Root>/VsEGMO_DataBus'
   */
  if (rtb_RelationalOperator11_hgud)
  {
    /* Switch: '<S136>/Switch' incorporates:
     *  Constant: '<S136>/Constant'
     *  RelationalOperator: '<S136>/Relational Operator1'
     */
    if (rtIsNaNF(rtb_UnitDelay_chni))
    {
      VfLCCS_linear_velocity = 0.0F;
    }
    else
    {
      VfLCCS_linear_velocity = rtb_UnitDelay_chni;
    }

    /* End of Switch: '<S136>/Switch' */
  }
  else
  {
    VfLCCS_linear_velocity = VsEGMO_DataBus.motion.linear_velocity;
  }

  /* End of Switch: '<S136>/Switch2' */

  /* RelationalOperator: '<S137>/Relational Operator11' incorporates:
   *  Inport: '<Root>/VsEGMO_DataBus'
   */
  rtb_RelationalOperator11_aflp = rtIsNaNF(VsEGMO_DataBus.motion.slip_angle);

  /* RelationalOperator: '<S143>/Relational Operator11' incorporates:
   *  Inport: '<Root>/VsEGMO_DataBus'
   */
  rtb_RelationalOperator11_c2oq = rtIsNaNF(VsEGMO_DataBus.motion.velocity_rel.x);

  /* RelationalOperator: '<S144>/Relational Operator11' incorporates:
   *  Inport: '<Root>/VsEGMO_DataBus'
   */
  rtb_RelationalOperator11_mhde = rtIsNaNF(VsEGMO_DataBus.motion.velocity_rel.y);

  /* Logic: '<S11>/Logical Operator' */
  VbLCCS_input_isNaN_EGMO = (((rtb_RelationalOperator11_hgud ||
    rtb_RelationalOperator11_aflp) || rtb_RelationalOperator11_c2oq) ||
    rtb_RelationalOperator11_mhde);

  /* Switch: '<S144>/Switch2' incorporates:
   *  Inport: '<Root>/VsEGMO_DataBus'
   */
  if (rtb_RelationalOperator11_mhde)
  {
    /* Switch: '<S144>/Switch' incorporates:
     *  Constant: '<S144>/Constant'
     *  RelationalOperator: '<S144>/Relational Operator1'
     *  UnitDelay: '<S144>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_kvve))
    {
      rtb_Switch2 = 0.0F;
    }
    else
    {
      rtb_Switch2 = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_kvve;
    }

    /* End of Switch: '<S144>/Switch' */
  }
  else
  {
    rtb_Switch2 = VsEGMO_DataBus.motion.velocity_rel.y;
  }

  /* End of Switch: '<S144>/Switch2' */

  /* Switch: '<S11>/Switch10' incorporates:
   *  Constant: '<S11>/Constant16'
   *  Constant: '<S11>/Constant7'
   */
  if (KbLCCS_WheelEncoderReady)
  {
    VfLCCS_velocity_rel_y = rtb_Switch2;
  }
  else
  {
    VfLCCS_velocity_rel_y = 0.0F;
  }

  /* End of Switch: '<S11>/Switch10' */

  /* Switch: '<S143>/Switch2' incorporates:
   *  Inport: '<Root>/VsEGMO_DataBus'
   */
  if (rtb_RelationalOperator11_c2oq)
  {
    /* Switch: '<S143>/Switch' incorporates:
     *  Constant: '<S143>/Constant'
     *  RelationalOperator: '<S143>/Relational Operator1'
     */
    if (rtIsNaNF(rtb_UnitDelay_chni))
    {
      VfLCCS_velocity_rel_x = 0.0F;
    }
    else
    {
      VfLCCS_velocity_rel_x = rtb_UnitDelay_chni;
    }

    /* End of Switch: '<S143>/Switch' */
  }
  else
  {
    VfLCCS_velocity_rel_x = VsEGMO_DataBus.motion.velocity_rel.x;
  }

  /* End of Switch: '<S143>/Switch2' */

  /* Switch: '<S137>/Switch2' incorporates:
   *  Inport: '<Root>/VsEGMO_DataBus'
   */
  if (rtb_RelationalOperator11_aflp)
  {
    /* Switch: '<S137>/Switch' incorporates:
     *  Constant: '<S137>/Constant'
     *  RelationalOperator: '<S137>/Relational Operator1'
     *  UnitDelay: '<S137>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_ik3u))
    {
      rtb_Switch2_bkaf = 0.0F;
    }
    else
    {
      rtb_Switch2_bkaf = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_ik3u;
    }

    /* End of Switch: '<S137>/Switch' */
  }
  else
  {
    rtb_Switch2_bkaf = VsEGMO_DataBus.motion.slip_angle;
  }

  /* End of Switch: '<S137>/Switch2' */

  /* Switch: '<S11>/Switch9' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/Constant3'
   */
  if (KbLCCS_WheelEncoderReady)
  {
    VfLCCS_veh_heading_rel = rtb_Switch2_bkaf;
  }
  else
  {
    VfLCCS_veh_heading_rel = 0.0F;
  }

  /* End of Switch: '<S11>/Switch9' */

  /* Switch: '<S150>/Switch2' incorporates:
   *  Inport: '<Root>/VsCOMM_CANR_Databus'
   */
  if (rtb_RelationalOperator11_c5xx)
  {
    /* Switch: '<S150>/Switch' incorporates:
     *  Constant: '<S150>/Constant'
     *  RelationalOperator: '<S150>/Relational Operator1'
     *  UnitDelay: '<S150>/Unit Delay'
     */
    if (rtIsNaNF(VfLCCS_EPS_ActualSteeringAngle))
    {
      VfLCCS_EPS_ActualSteeringAngle = 0.0F;
    }

    /* End of Switch: '<S150>/Switch' */
  }
  else
  {
    VfLCCS_EPS_ActualSteeringAngle =
      VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle;
  }

  /* End of Switch: '<S150>/Switch2' */

  /* Switch: '<S142>/Switch2' incorporates:
   *  Inport: '<Root>/VsCOMM_CANR_Databus'
   *  RelationalOperator: '<S142>/Relational Operator11'
   */
  if (rtIsNaNF(VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRate))
  {
    /* Switch: '<S142>/Switch' incorporates:
     *  Constant: '<S142>/Constant'
     *  RelationalOperator: '<S142>/Relational Operator1'
     *  UnitDelay: '<S142>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_cjmy))
    {
      rtb_UnitDelay_obn3 = 0.0F;
    }
    else
    {
      rtb_UnitDelay_obn3 = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_cjmy;
    }

    /* End of Switch: '<S142>/Switch' */
  }
  else
  {
    rtb_UnitDelay_obn3 = VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRate;
  }

  /* End of Switch: '<S142>/Switch2' */

  /* Product: '<S11>/Product' incorporates:
   *  Constant: '<S11>/Constant17'
   */
  VfLCCS_yaw_rate = rtb_UnitDelay_obn3 * KfLCCS_r_YawRateCorrection;

  /* Update for UnitDelay: '<S11>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_l0sm = rtb_LogicalOperator5_bk2b;

  /* Update for UnitDelay: '<S11>/Unit Delay1' */
  LCCS_subsystem_integrated_DW.UnitDelay1_DSTATE_lgx0 =
    rtb_RelationalOperator11_pp0v;

  /* Update for UnitDelay: '<S11>/Unit Delay3' */
  LCCS_subsystem_integrated_DW.UnitDelay3_DSTATE_nn4w =
    LCCS_subsystem_integrated_B.left_turn_signal;

  /* Update for UnitDelay: '<S148>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_mjzr = rtb_UnitDelay_chni;

  /* Update for UnitDelay: '<S144>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_kvve = rtb_Switch2;

  /* Update for UnitDelay: '<S137>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_ik3u = rtb_Switch2_bkaf;

  /* Update for UnitDelay: '<S142>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_cjmy = rtb_UnitDelay_obn3;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
