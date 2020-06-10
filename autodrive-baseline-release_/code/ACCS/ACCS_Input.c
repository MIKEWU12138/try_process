/*
 * File: ACCS_Input.c
 *
 * Code generated for Simulink model 'ACCS_subsystem_integrated'.
 *
 * Model version                  : 1.1217
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 17:55:27 2020
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

#include "ACCS_Input.h"

/* Include model header file for global data */
#include "ACCS_subsystem_integrated.h"
#include "ACCS_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S3>/CheckACCS_FaultState' */
void CheckACCS_FaultState(void)
{
  boolean_T tmp;

  /* Switch: '<S6>/Switch2' incorporates:
   *  Constant: '<S6>/Constant2'
   *  Constant: '<S6>/Constant4'
   *  Constant: '<S6>/Constant5'
   */
  if (KbACCS_CalFaultTypeOnlyForTest)
  {
    tmp = (((int32_T)KeACCS_CalFaultTypeOnlyForTest) != 0);
  }
  else
  {
    tmp = true;
  }

  /* End of Switch: '<S6>/Switch2' */

  /* RelationalOperator: '<S6>/Relational Operator' incorporates:
   *  Constant: '<S6>/Constant5'
   */
  ACCS_subsystem_integrated_B.LogicalOperator = (tmp != true);
}

/* Output and update for atomic system: '<S3>/DtrmnACCS_CAN_Information' */
void DtrmnACCS_CAN_Information(void)
{
  boolean_T tmp;

  /* SignalConversion: '<S7>/BusConversion_InsertedFor_ACCS_CAN_BUS_at_inport_0' incorporates:
   *  Inport: '<Root>/COMM_Bus_FedBck_in'
   */
  ACCS_subsystem_integrated_B.CalDriverSetSpeed =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed;

  /* SignalConversion: '<S7>/BusConversion_InsertedFor_ACCS_CAN_BUS_at_inport_0' incorporates:
   *  Inport: '<Root>/COMM_Bus_FedBck_in'
   */
  ACCS_subsystem_integrated_B.VeACCS_Input_Gear_TCU =
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition;

  /* Switch: '<S7>/Switch7' incorporates:
   *  Constant: '<S7>/Constant14'
   *  Constant: '<S7>/Constant15'
   *  Constant: '<S7>/Constant16'
   *  Inport: '<Root>/COMM_Bus_FedBck_in'
   *  RelationalOperator: '<S7>/Relational Operator'
   */
  if ((VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ParkingControlResponse ? 1U : 0U)
      == ((uint8_T)0U))
  {
    tmp = false;
  }
  else
  {
    tmp = true;
  }

  /* End of Switch: '<S7>/Switch7' */

  /* Logic: '<S7>/Logical Operator1' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  ACCS_subsystem_integrated_B.SignalConversion_a213 = (KbACCS_ConsiderWithEPB &&
    tmp);

  /* Switch: '<S7>/Switch6' incorporates:
   *  Constant: '<S7>/Constant12'
   *  Constant: '<S7>/Constant13'
   *  Inport: '<Root>/COMM_Bus_FedBck_in'
   */
  if (KbACCS_UseVirtualPedal)
  {
    VfACCS_Input_PhyGasPedal_POWER = KfACCS_Pct_VirtualGasPedal;
  }
  else
  {
    VfACCS_Input_PhyGasPedal_POWER =
      VsCOMM_CANR_Databus.COMM_RX_Power.VCU_ActualAccelPedalPosition;
  }

  /* End of Switch: '<S7>/Switch6' */

  /* Logic: '<S7>/Logical Operator' incorporates:
   *  Constant: '<S7>/Constant5'
   *  SignalConversion: '<S7>/Signal Conversion1'
   */
  ACCS_subsystem_integrated_B.Ego_LimitCondition = KbACCS_DriverDoorBeltState;

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/COMM_Bus_FedBck_in'
   */
  ACCS_subsystem_integrated_B.VbACCS_Input_DriverPresent =
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch;

  /* SignalConversion: '<S7>/Signal Conversion' */
  ACCS_subsystem_integrated_B.VbACCS_Input_Obs_R_valid =
    ACCS_subsystem_integrated_B.VbACCS_Input_resume_DCSN;
}

/* Output and update for atomic system: '<S3>/DtrmnACCS_DCSNInformation' */
void DtrmnACCS_DCSNInformation(void)
{
  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant2'
   *  Inport: '<Root>/DCSN_DataBus'
   *  SignalConversion: '<S8>/Signal Conversion3'
   */
  if (KbACCS_UseVitualDCSNInfo)
  {
    VbACCS_Input_stop_request_DCSN = KbACCS_VitualStopReqFrmDCSN;
  }
  else
  {
    VbACCS_Input_stop_request_DCSN =
      VsDCSN_DataBus.TrafficDecider_Group.stop_request;
  }

  /* End of Switch: '<S8>/Switch' */

  /* Switch: '<S8>/Switch2' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/Constant5'
   *  Inport: '<Root>/DCSN_DataBus'
   *  SignalConversion: '<S8>/Signal Conversion5'
   */
  if (KbACCS_UseVitualDCSNInfo)
  {
    VfACCS_Input_stop_s_distance_DCSN = KfACCS_d_VitualStopDisFrmDCSN;
  }
  else
  {
    VfACCS_Input_stop_s_distance_DCSN =
      VsDCSN_DataBus.TrafficDecider_Group.stop_s_distance;
  }

  /* End of Switch: '<S8>/Switch2' */

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<S8>/Constant3'
   *  Constant: '<S8>/Constant4'
   *  Inport: '<Root>/DCSN_DataBus'
   *  SignalConversion: '<S8>/Signal Conversion6'
   */
  if (KbACCS_UseVitualDCSNInfo)
  {
    VfACCS_Input_traffic_speed_limit_DCSN = KfACCS_v_VitualSpeedLimitFrmDCSN;
  }
  else
  {
    VfACCS_Input_traffic_speed_limit_DCSN =
      VsDCSN_DataBus.TrafficDecider_Group.lane_speed_limit;
  }

  /* End of Switch: '<S8>/Switch1' */

  /* RelationalOperator: '<S8>/Relational Operator' incorporates:
   *  Constant: '<S8>/Constant8'
   *  Inport: '<Root>/DCSN_DataBus'
   *  SignalConversion: '<S8>/Signal Conversion12'
   */
  VbACCS_Input_NoSpdLimit =
    (VsDCSN_DataBus.TrafficDecider_Group.speed_limit_reason == NO_LIMIT);

  /* SignalConversion: '<S8>/Signal Conversion1' incorporates:
   *  Inport: '<Root>/DCSN_DataBus'
   */
  VbACCS_Input_brake_ctrl_enable_DCSN =
    VsDCSN_DataBus.EnablingFlags_Group.brake_ctrl_enable;

  /* SignalConversion: '<S8>/Signal Conversion10' incorporates:
   *  Inport: '<Root>/DCSN_DataBus'
   */
  ACCS_subsystem_integrated_B.VbACCS_Input_NoSpdLimit_mvju =
    VsDCSN_DataBus.TrafficDecider_Group.pull_over_request;

  /* SignalConversion: '<S8>/Signal Conversion11' incorporates:
   *  Inport: '<Root>/DCSN_DataBus'
   */
  ACCS_subsystem_integrated_B.VeACCS_Input_autodrive_activate =
    VsDCSN_DataBus.ADM_Group.usr_cmd_autodrive_activate;

  /* SignalConversion: '<S8>/Signal Conversion13' incorporates:
   *  Inport: '<Root>/DCSN_DataBus'
   */
  ACCS_subsystem_integrated_B.VbACCS_Input_resume_DCSN =
    VsDCSN_DataBus.ADM_Group.adm_accs_resume;

  /* SignalConversion: '<S8>/Signal Conversion2' incorporates:
   *  Inport: '<Root>/DCSN_DataBus'
   */
  VbACCS_Input_acc_feature_enable_DCSN =
    VsDCSN_DataBus.EnablingFlags_Group.acc_feature_enable;

  /* SignalConversion: '<S8>/Signal Conversion4' incorporates:
   *  Inport: '<Root>/DCSN_DataBus'
   */
  VbACCS_Input_power_ctrl_enable_DCSN =
    VsDCSN_DataBus.EnablingFlags_Group.power_ctrl_enable;

  /* SignalConversion: '<S8>/Signal Conversion7' incorporates:
   *  Inport: '<Root>/DCSN_DataBus'
   */
  ACCS_subsystem_integrated_B.VfACCS_Input_linear_Accele_p235 =
    VsDCSN_DataBus.TrafficDecider_Group.change_lane_target_speed;

  /* SignalConversion: '<S8>/Signal Conversion8' incorporates:
   *  Inport: '<Root>/DCSN_DataBus'
   */
  ACCS_subsystem_integrated_B.VbACCS_Input_inlane_nudge_reque =
    VsDCSN_DataBus.TrafficDecider_Group.inlane_nudge_request;

  /* SignalConversion: '<S8>/Signal Conversion9' incorporates:
   *  Inport: '<Root>/DCSN_DataBus'
   */
  ACCS_subsystem_integrated_B.VfACCS_Input_inlane_nudge_side_ =
    VsDCSN_DataBus.TrafficDecider_Group.inlane_nudge_side;
}

/* Output and update for atomic system: '<S3>/DtrmnACCS_EGMOInformation' */
void DtrmnACCS_EGMOInformation(void)
{
  real32_T rtb_VfACCS_Input_EgoPitch_EGMO;

  /* Sum: '<S9>/Subtract' incorporates:
   *  Inport: '<Root>/COMM_Bus_FedBck_in'
   *  Inport: '<Root>/EGMO_DataBus'
   *  SignalConversion: '<S9>/Signal Conversion4'
   */
  VfACCS_DeltaSped_EGMOAndCan =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed -
    VsEGMO_DataBus.motion.linear_velocity;

  /* Switch: '<S9>/Switch' incorporates:
   *  Abs: '<S9>/Abs'
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant3'
   *  Inport: '<Root>/COMM_Bus_FedBck_in'
   *  RelationalOperator: '<S9>/Relational Operator'
   *  Switch: '<S9>/Switch2'
   */
  if (KeACCS_VehicleSpeedSource > ((uint8_T)0U))
  {
    VfACCS_Input_linear_velocity_EGMO =
      VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed;
  }
  else if (((real32_T)fabs((real_T)VfACCS_DeltaSped_EGMOAndCan)) <=
           KfACCS_v_DeltaSped_EGMOAndCanThrsh)
  {
    /* Switch: '<S9>/Switch2' incorporates:
     *  Inport: '<Root>/EGMO_DataBus'
     *  SignalConversion: '<S9>/Signal Conversion4'
     */
    VfACCS_Input_linear_velocity_EGMO = VsEGMO_DataBus.motion.linear_velocity;
  }
  else
  {
    VfACCS_Input_linear_velocity_EGMO =
      VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed;
  }

  /* End of Switch: '<S9>/Switch' */

  /* Switch: '<S9>/Switch1' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Constant: '<S9>/Constant2'
   *  Inport: '<Root>/EGMO_DataBus'
   *  SignalConversion: '<S9>/Signal Conversion'
   */
  if (KeACCS_VehicleSpeedSource > ((uint8_T)0U))
  {
    rtb_VfACCS_Input_EgoPitch_EGMO = 0.0F;
  }
  else
  {
    rtb_VfACCS_Input_EgoPitch_EGMO = VsEGMO_DataBus.pose_utm.pitch;
  }

  /* End of Switch: '<S9>/Switch1' */

  /* Switch: '<S9>/Switch3' incorporates:
   *  Constant: '<S9>/Constant4'
   *  Gain: '<S9>/Gain'
   */
  if (KbACCS_EgoPitchTransfer)
  {
    VfACCS_Input_EgoPitch_EGMO = (-1.0F) * rtb_VfACCS_Input_EgoPitch_EGMO;
  }
  else
  {
    VfACCS_Input_EgoPitch_EGMO = rtb_VfACCS_Input_EgoPitch_EGMO;
  }

  /* End of Switch: '<S9>/Switch3' */

  /* SignalConversion: '<S9>/Signal Conversion1' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  ACCS_subsystem_integrated_B.VfACCS_Input_EgoPitch_EGMO_av3q =
    VsEGMO_DataBus.motion.curvature;

  /* SignalConversion: '<S9>/Signal Conversion10' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  ACCS_subsystem_integrated_B.VfACCS_Input_EGMOTimeStamp_low =
    VsEGMO_DataBus.timestamp_low;

  /* SignalConversion: '<S9>/Signal Conversion2' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  ACCS_subsystem_integrated_B.VfACCS_Input_Yawrate_EGMO =
    VsEGMO_DataBus.motion.yaw_rate_road;

  /* SignalConversion: '<S9>/Signal Conversion3' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  ACCS_subsystem_integrated_B.VfACCS_Input_linear_Acceleratio =
    VsEGMO_DataBus.motion.acceleration_rel.y;

  /* SignalConversion: '<S9>/Signal Conversion5' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VfACCS_Input_longvelocity_EGMO = VsEGMO_DataBus.motion.velocity_rel.x;

  /* SignalConversion: '<S9>/Signal Conversion6' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VfACCS_Input_latvelocity_EGMO = VsEGMO_DataBus.motion.velocity_rel.y;

  /* SignalConversion: '<S9>/Signal Conversion7' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VfACCS_Input_linear_Acceleration_EGMO =
    VsEGMO_DataBus.motion.linear_acceleration;

  /* SignalConversion: '<S9>/Signal Conversion8' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  ACCS_subsystem_integrated_B.VfACCS_Input_linear_Accele_dcwi =
    VsEGMO_DataBus.motion.acceleration_rel.x;

  /* SignalConversion: '<S9>/Signal Conversion9' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VfACCS_Input_EGMOTimeStamp_high = VsEGMO_DataBus.timestamp_high;
}

/* Output and update for atomic system: '<S3>/DtrmnACCS_MPFUInformation' */
void DtrmnACCS_MPFUInformation(void)
{
  int32_T i;
  boolean_T exitg1;

  /* SignalConversion: '<S10>/BusConversion_InsertedFor_ACCS_MPFU_BUS_at_inport_0' incorporates:
   *  Inport: '<Root>/MPFU_DataBus'
   */
  ACCS_subsystem_integrated_B.UnitDelay1 = VsMPFU_DataBus.is_ready;

  /* SignalConversion: '<S10>/BusConversion_InsertedFor_ACCS_MPFU_BUS_at_inport_0' incorporates:
   *  Inport: '<Root>/MPFU_DataBus'
   */
  ACCS_subsystem_integrated_B.is_valid = VsMPFU_DataBus.curvature.is_valid;

  /* SignalConversion: '<S10>/BusConversion_InsertedFor_ACCS_MPFU_BUS_at_inport_0' incorporates:
   *  Inport: '<Root>/MPFU_DataBus'
   */
  ACCS_subsystem_integrated_B.VfACCS_RangeErrlim_SIPV =
    VsMPFU_DataBus.curvature.value;

  /* MATLAB Function: '<S10>/LaneInfo' */
  ACCS_subsystem_integrated_B.VbACCS_Lane_MPFU_valid = false;
  ACCS_subsystem_integrated_B.VeACCS_RoadType_MPFU = 0;
  ACCS_subsystem_integrated_B.VfACCS_Input_Lane_speed_limit_M = 0U;
  ACCS_subsystem_integrated_B.VfACCS_Input_Lane_minspeed_limi = 0U;
  ACCS_subsystem_integrated_B.VfACCS_Input_Lane_width_MPFU = 0.0F;
  ACCS_subsystem_integrated_B.VfACCS_Input_Lane_length_MPFU = 0.0F;
  ACCS_subsystem_integrated_B.VfACCS_Input_Lane_type_MPFU = 0;
  ACCS_subsystem_integrated_B.VeACCS_Input_Lane_turntype_MPFU = 0;
  ACCS_subsystem_integrated_B.VeACCS_Input_Lane_direction_MPF = 0;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 8))
  {
    if (VsMPFU_DataBus.lanes[i].id == 0)
    {
      ACCS_subsystem_integrated_B.VbACCS_Lane_MPFU_valid = true;
      ACCS_subsystem_integrated_B.VeACCS_RoadType_MPFU = VsMPFU_DataBus.lanes[i]
        .type;
      ACCS_subsystem_integrated_B.VfACCS_Input_Lane_speed_limit_M =
        VsMPFU_DataBus.lanes[i].speed_limit_max;
      ACCS_subsystem_integrated_B.VfACCS_Input_Lane_minspeed_limi =
        VsMPFU_DataBus.lanes[i].speed_limit_max;
      ACCS_subsystem_integrated_B.VfACCS_Input_Lane_width_MPFU =
        VsMPFU_DataBus.lanes[i].width;
      ACCS_subsystem_integrated_B.VfACCS_Input_Lane_length_MPFU =
        VsMPFU_DataBus.lanes[i].length;
      ACCS_subsystem_integrated_B.VfACCS_Input_Lane_type_MPFU =
        VsMPFU_DataBus.lanes[i].type;
      ACCS_subsystem_integrated_B.VeACCS_Input_Lane_turntype_MPFU =
        VsMPFU_DataBus.lanes[i].turn_type;
      ACCS_subsystem_integrated_B.VeACCS_Input_Lane_direction_MPF =
        VsMPFU_DataBus.lanes[i].direction;
      exitg1 = true;
    }
    else
    {
      i++;
    }
  }

  /* MATLAB Function: '<S10>/LaneMark' incorporates:
   *  Inport: '<Root>/MPFU_DataBus'
   */
  ACCS_subsystem_integrated_B.VbACCS_Input_LaneMkL_MPFU_valid = false;
  ACCS_subsystem_integrated_B.VfACCS_Input_LaneMkL_quality_MP = 0U;
  ACCS_subsystem_integrated_B.VfACCS_Input_LaneMkL_Type_MPFU = 0;
  ACCS_subsystem_integrated_B.Switch = 0.0F;
  ACCS_subsystem_integrated_B.Product_cjbq = 0.0F;
  ACCS_subsystem_integrated_B.VfACCS_Input_LaneMkL_c2_MPFU = 0.0F;
  ACCS_subsystem_integrated_B.VfACCS_Input_LaneMkL_c3_MPFU = 0.0F;
  ACCS_subsystem_integrated_B.VeACCS_Input_LaneMkL_color_MPFU = 0;
  ACCS_subsystem_integrated_B.VbACCS_Input_LaneMkR_MPFU_valid = false;
  ACCS_subsystem_integrated_B.VfACCS_Input_LaneMkR_quality_MP = 0U;
  ACCS_subsystem_integrated_B.VfACCS_Input_LaneMkR_c0_MPFU = 0.0F;
  ACCS_subsystem_integrated_B.VfACCS_Input_LaneMkR_c1_MPFU = 0.0F;
  ACCS_subsystem_integrated_B.VfACCS_Input_LaneMkR_c2_MPFU = 0.0F;
  ACCS_subsystem_integrated_B.VfACCS_Input_LaneMkR_c3_MPFU = 0.0F;
  ACCS_subsystem_integrated_B.VeACCS_Input_LaneMkR_color_MPFU = 0;
  for (i = 0; i < 16; i++)
  {
    switch (VsMPFU_DataBus.lane_markers[i].id)
    {
     case 1:
      ACCS_subsystem_integrated_B.VbACCS_Input_LaneMkL_MPFU_valid = true;
      ACCS_subsystem_integrated_B.VfACCS_Input_LaneMkL_quality_MP =
        VsMPFU_DataBus.lane_markers[i].quality;
      ACCS_subsystem_integrated_B.VfACCS_Input_LaneMkL_Type_MPFU =
        VsMPFU_DataBus.lane_markers[i].type;
      ACCS_subsystem_integrated_B.Switch = VsMPFU_DataBus.lane_markers[i].
        c0_position;
      ACCS_subsystem_integrated_B.Product_cjbq = VsMPFU_DataBus.lane_markers[i].
        c1_heading;
      ACCS_subsystem_integrated_B.VfACCS_Input_LaneMkL_c2_MPFU =
        VsMPFU_DataBus.lane_markers[i].c2_curvature;
      ACCS_subsystem_integrated_B.VfACCS_Input_LaneMkL_c3_MPFU =
        VsMPFU_DataBus.lane_markers[i].c3_curvature_derivative;
      ACCS_subsystem_integrated_B.VeACCS_Input_LaneMkL_color_MPFU =
        VsMPFU_DataBus.lane_markers[i].color;
      break;

     case 2:
      ACCS_subsystem_integrated_B.VbACCS_Input_LaneMkR_MPFU_valid = true;
      ACCS_subsystem_integrated_B.VfACCS_Input_LaneMkR_quality_MP =
        VsMPFU_DataBus.lane_markers[i].quality;
      ACCS_subsystem_integrated_B.VfACCS_Input_LaneMkR_c0_MPFU =
        VsMPFU_DataBus.lane_markers[i].c0_position;
      ACCS_subsystem_integrated_B.VfACCS_Input_LaneMkR_c1_MPFU =
        VsMPFU_DataBus.lane_markers[i].c1_heading;
      ACCS_subsystem_integrated_B.VfACCS_Input_LaneMkR_c2_MPFU =
        VsMPFU_DataBus.lane_markers[i].c2_curvature;
      ACCS_subsystem_integrated_B.VfACCS_Input_LaneMkR_c3_MPFU =
        VsMPFU_DataBus.lane_markers[i].c3_curvature_derivative;
      ACCS_subsystem_integrated_B.VeACCS_Input_LaneMkR_color_MPFU =
        VsMPFU_DataBus.lane_markers[i].color;
      break;

     default:
      /* no actions */
      break;
    }
  }

  /* End of MATLAB Function: '<S10>/LaneMark' */
}

/* Output and update for atomic system: '<S1>/DtrmnACCS_Input' */
void DtrmnACCS_Input(void)
{
  /* Outputs for Atomic SubSystem: '<S3>/DtrmnACCS_DCSNInformation' */
  DtrmnACCS_DCSNInformation();

  /* End of Outputs for SubSystem: '<S3>/DtrmnACCS_DCSNInformation' */

  /* Outputs for Atomic SubSystem: '<S3>/DtrmnACCS_CAN_Information' */
  DtrmnACCS_CAN_Information();

  /* End of Outputs for SubSystem: '<S3>/DtrmnACCS_CAN_Information' */

  /* Outputs for Atomic SubSystem: '<S3>/DtrmnACCS_MPFUInformation' */
  DtrmnACCS_MPFUInformation();

  /* End of Outputs for SubSystem: '<S3>/DtrmnACCS_MPFUInformation' */

  /* Outputs for Atomic SubSystem: '<S3>/DtrmnACCS_EGMOInformation' */
  DtrmnACCS_EGMOInformation();

  /* End of Outputs for SubSystem: '<S3>/DtrmnACCS_EGMOInformation' */

  /* Outputs for Atomic SubSystem: '<S3>/CheckACCS_FaultState' */
  CheckACCS_FaultState();

  /* End of Outputs for SubSystem: '<S3>/CheckACCS_FaultState' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
