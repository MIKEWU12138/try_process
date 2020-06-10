/*
 * File: ALCA_InputDataProcess.c
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

#include "ALCA_InputDataProcess.h"

/* Include model header file for global data */
#include "ALCA_subsystem_integrated.h"
#include "ALCA_subsystem_integrated_private.h"

/*
 * Output and update for atomic system:
 *    '<S60>/DividByZero'
 *    '<S61>/DividByZero'
 */
void ALCA_subsystem_inte_DividByZero(real32_T rtu_u, real32_T *rty_y)
{
  if ((((real_T)rtu_u) < 1.0E-5) && (rtu_u >= 0.0F))
  {
    *rty_y = 1.0E-5F;
  }
  else if ((((real_T)rtu_u) > -1.0E-5) && (rtu_u < 0.0F))
  {
    *rty_y = -1.0E-5F;
  }
  else
  {
    *rty_y = rtu_u;
  }
}

/* System initialize for atomic system: '<S3>/ALCA_InputDataProcess' */
void ALCA_ALCA_InputDataProcess_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S50>/Unit Delay1' */
  ALCA_subsystem_integrated_DW.pre_egmo_timeStamp = 0U;

  /* InitializeConditions for UnitDelay: '<S50>/Unit Delay2' */
  ALCA_subsystem_integrated_DW.pre_mpfu_timeStamp = 0U;

  /* InitializeConditions for UnitDelay: '<S50>/Unit Delay' */
  ALCA_subsystem_integrated_DW.pre_obfu_timeStamp = 0U;

  /* SystemInitialize for Atomic SubSystem: '<S12>/ALCA_Dtrm_dcsn_info' */
  ALCA_s_ALCA_Dtrm_dcsn_info_Init();

  /* End of SystemInitialize for SubSystem: '<S12>/ALCA_Dtrm_dcsn_info' */

  /* SystemInitialize for Chart: '<S66>/Chart' */
  ALCA_subsystem_integ_Chart_Init(&ALCA_subsystem_integrated_DW.sf_Chart_gygf);

  /* SystemInitialize for Chart: '<S67>/Chart' */
  ALCA_subsystem_integ_Chart_Init(&ALCA_subsystem_integrated_DW.sf_Chart_acqd);

  /* SystemInitialize for Chart: '<S65>/Chart' */
  ALCA_subsystem_integ_Chart_Init(&ALCA_subsystem_integrated_DW.sf_Chart_i2is);
}

/* System reset for atomic system: '<S3>/ALCA_InputDataProcess' */
void ALC_ALCA_InputDataProcess_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S50>/Unit Delay1' */
  ALCA_subsystem_integrated_DW.pre_egmo_timeStamp = 0U;

  /* InitializeConditions for UnitDelay: '<S50>/Unit Delay2' */
  ALCA_subsystem_integrated_DW.pre_mpfu_timeStamp = 0U;

  /* InitializeConditions for UnitDelay: '<S50>/Unit Delay' */
  ALCA_subsystem_integrated_DW.pre_obfu_timeStamp = 0U;

  /* SystemReset for Atomic SubSystem: '<S12>/ALCA_Dtrm_dcsn_info' */
  ALCA__ALCA_Dtrm_dcsn_info_Reset();

  /* End of SystemReset for SubSystem: '<S12>/ALCA_Dtrm_dcsn_info' */

  /* SystemReset for Chart: '<S66>/Chart' */
  ALCA_subsystem_inte_Chart_Reset(&ALCA_subsystem_integrated_DW.sf_Chart_gygf);

  /* SystemReset for Chart: '<S67>/Chart' */
  ALCA_subsystem_inte_Chart_Reset(&ALCA_subsystem_integrated_DW.sf_Chart_acqd);

  /* SystemReset for Chart: '<S65>/Chart' */
  ALCA_subsystem_inte_Chart_Reset(&ALCA_subsystem_integrated_DW.sf_Chart_i2is);
}

/* Start for atomic system: '<S3>/ALCA_InputDataProcess' */
void ALC_ALCA_InputDataProcess_Start(void)
{
  /* Start for DataStoreMemory: '<S12>/KbALCA_EnblCheckMPFUFusionStatus' */
  ALCA_subsystem_integrated_DW.KbALCA_EnblCheckMPFUFusionStatu =
    KbALCA_EnblCheckMPFUFusionStatus ? 1.0F : 0.0F;
}

/* Output and update for atomic system: '<S3>/ALCA_InputDataProcess' */
void ALCA_subs_ALCA_InputDataProcess(boolean_T rtu_reset_lc_req, EnumALCA_state
  rtu_pre_state, boolean_T rtu_touched_new_lane, ALCA_DcsnInfo *rty_dcsn_info,
  ALCA_VehState *rty_veh_state, uint8_T *rty_fault, ALCA_MPFU_Info
  *rty_mpfu_info)
{
  real32_T rtb_veh_curvature;
  boolean_T rtb_RelationalOperator_apdn;
  uint8_T rtb_Switch3_lalf;
  int8_T rtb_SignalConversion19;
  int8_T rtb_SignalConversion11;
  int8_T rtb_ego_lane_index;
  boolean_T rtb_has_ego_lane;
  int8_T rtb_left_lane_marker_index;
  int8_T rtb_right_lane_marker_index;
  boolean_T rtb_has_left_lane_marker;
  boolean_T rtb_has_right_lane_marker;
  int8_T rtb_target_lane_from_dcsn_index;
  boolean_T rtb_has_left_lane;
  boolean_T rtb_has_right_lane;
  real32_T rtb_Divide;
  real32_T rtb_y;
  real32_T rtb_radius;
  boolean_T rtb_RelationalOperator2_jfjw;
  real32_T rtb_Gain_mw05;
  boolean_T rtb_RelationalOperator3_ibon;
  real32_T rtb_Gain_gqz3;
  boolean_T rtb_RelationalOperator_cbyf;
  real32_T rtb_Gain_gvue;
  uint8_T rtb_DataTypeConversion12;
  uint8_T rtb_DataTypeConversion13;
  uint8_T rtb_DataTypeConversion14;
  uint8_T rtb_DataTypeConversion15;
  uint8_T rtb_DataTypeConversion16;
  uint8_T rtb_DataTypeConversion17;
  real32_T rtb_DataTypeConversion18;
  boolean_T rtb_y_fabi;
  boolean_T rtb_y_gjef;
  boolean_T rtb_y_hnng;
  MPFU_LaneMarker rtb_right_lane_marker;
  MPFU_LaneMarker rtb_left_lane_marker;
  uint8_T rtb_state;
  uint8_T rtb_state_fk3y;
  uint8_T rtb_state_icet;

  /* Constant: '<S51>/Constant5' incorporates:
   *  DataStoreWrite: '<S51>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn5'
   */
  ALCA_subsystem_integrated_DW.KbALCA_EnblCheckMPFUFusionStatu =
    KbALCA_EnblCheckMPFUFusionStatus ? 1.0F : 0.0F;

  /* Outputs for Atomic SubSystem: '<S12>/ALCA_Dtrm_dcsn_info' */
  ALCA_subsys_ALCA_Dtrm_dcsn_info(rtu_reset_lc_req, rtu_pre_state, rty_dcsn_info);

  /* End of Outputs for SubSystem: '<S12>/ALCA_Dtrm_dcsn_info' */

  /* MATLAB Function: '<S12>/ALCA_Dtrm_mpfu_info' */
  ALCA_subsys_ALCA_Dtrm_mpfu_info(rty_dcsn_info->change_lane_req_side,
    rtu_touched_new_lane, &rtb_ego_lane_index, &rtb_has_ego_lane,
    &rtb_left_lane_marker_index, &rtb_right_lane_marker_index,
    &rtb_has_left_lane_marker, &rtb_has_right_lane_marker,
    &rtb_target_lane_from_dcsn_index, &rtb_has_left_lane, &rtb_has_right_lane,
    &rtb_left_lane_marker, &rtb_right_lane_marker);

  /* SignalConversion: '<S52>/Signal Conversion19' */
  rtb_SignalConversion19 = rtb_right_lane_marker.id;

  /* SignalConversion: '<S52>/Signal Conversion20' */
  VfALCA_RightLaneMarkerFusionStatus = rtb_right_lane_marker.fusion_status;

  /* SignalConversion: '<S52>/Signal Conversion21' */
  VfALCA_RightLaneMarkerType = rtb_right_lane_marker.type;

  /* SignalConversion: '<S52>/Signal Conversion22' */
  VfALCA_RightLaneMarker_C0 = rtb_right_lane_marker.c0_position;

  /* SignalConversion: '<S52>/Signal Conversion23' */
  VfALCA_RightLaneMarker_C1 = rtb_right_lane_marker.c1_heading;

  /* SignalConversion: '<S52>/Signal Conversion24' */
  VfALCA_RightLaneMarker_C2 = rtb_right_lane_marker.c2_curvature;

  /* SignalConversion: '<S52>/Signal Conversion25' */
  VfALCA_RightLaneMarker_C3 = rtb_right_lane_marker.c3_curvature_derivative;

  /* SignalConversion: '<S52>/Signal Conversion26' */
  VfALCA_RightDist2Host = rtb_right_lane_marker.distance_to_host;

  /* SignalConversion: '<S52>/Signal Conversion11' */
  rtb_SignalConversion11 = rtb_left_lane_marker.id;

  /* SignalConversion: '<S52>/Signal Conversion12' */
  VfALCA_LeftLaneMarkerFusionStatus = rtb_left_lane_marker.fusion_status;

  /* SignalConversion: '<S52>/Signal Conversion13' */
  VfALCA_LeftLaneMarkerType = rtb_left_lane_marker.type;

  /* SignalConversion: '<S52>/Signal Conversion14' */
  VfALCA_LeftLaneMarker_C0 = rtb_left_lane_marker.c0_position;

  /* SignalConversion: '<S52>/Signal Conversion15' */
  VfALCA_LeftLaneMarker_C1 = rtb_left_lane_marker.c1_heading;

  /* SignalConversion: '<S52>/Signal Conversion16' */
  VfALCA_LeftLaneMarker_C2 = rtb_left_lane_marker.c2_curvature;

  /* SignalConversion: '<S52>/Signal Conversion17' */
  VfALCA_LeftLaneMarker_C3 = rtb_left_lane_marker.c3_curvature_derivative;

  /* SignalConversion: '<S52>/Signal Conversion18' */
  VfALCA_LeftDist2Host = rtb_left_lane_marker.distance_to_host;

  /* BusCreator: '<S12>/Bus Creator' */
  rty_mpfu_info->ego_lane_index = rtb_ego_lane_index;
  rty_mpfu_info->has_ego_lane = rtb_has_ego_lane;
  rty_mpfu_info->left_lane_marker_index = rtb_left_lane_marker_index;
  rty_mpfu_info->right_lane_marker_index = rtb_right_lane_marker_index;
  rty_mpfu_info->has_left_lane_marker = rtb_has_left_lane_marker;
  rty_mpfu_info->has_right_lane_marker = rtb_has_right_lane_marker;
  rty_mpfu_info->target_lane_from_dcsn_index = rtb_target_lane_from_dcsn_index;
  rty_mpfu_info->has_left_lane = rtb_has_left_lane;
  rty_mpfu_info->has_right_lane = rtb_has_right_lane;

  /* Product: '<S58>/Divide' incorporates:
   *  Constant: '<S58>/Constant2'
   *  DataTypeConversion: '<S59>/Data Type Conversion19'
   *  Gain: '<S58>/Gain'
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  rtb_Divide = (0.0174532924F *
                VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle) /
    KfALCA_r_EgoVehStrwhl2FrtwhlRatio;

  /* MATLAB Function: '<S60>/DividByZero' */
  ALCA_subsystem_inte_DividByZero(rtb_Divide, &rtb_y);

  /* Product: '<S58>/Divide2' incorporates:
   *  Constant: '<S58>/Constant1'
   *  Constant: '<S58>/Constant5'
   *  Constant: '<S58>/Constant6'
   *  Product: '<S58>/Divide1'
   *  Sum: '<S58>/Add'
   */
  rtb_radius = (KfALCA_d_EgoVehWheelBase / rtb_y) / (1.0F +
    KfALCA_r_CoeffStrwhl2Radius);

  /* MATLAB Function: '<S61>/DividByZero' */
  ALCA_subsystem_inte_DividByZero(rtb_radius, &rtb_y);

  /* RelationalOperator: '<S50>/Relational Operator2' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  rtb_RelationalOperator2_jfjw = (VsEGMO_DataBus.timestamp_low ==
    ALCA_subsystem_integrated_DW.pre_egmo_timeStamp);

  /* Gain: '<S66>/Gain' incorporates:
   *  Constant: '<S50>/Constant2'
   *  Gain: '<S65>/Gain'
   *  Gain: '<S67>/Gain'
   */
  rtb_veh_curvature = 100.0F * KfALCA_t_TimeNReceivedThrsh;
  rtb_Gain_mw05 = rtb_veh_curvature;

  /* Chart: '<S66>/Chart' */
  ALCA_subsystem_integrated_Chart(rtb_RelationalOperator2_jfjw, rtb_Gain_mw05,
    &rtb_y_fabi, &rtb_state, &ALCA_subsystem_integrated_DW.sf_Chart_gygf);

  /* RelationalOperator: '<S50>/Relational Operator3' incorporates:
   *  Inport: '<Root>/MPFU_DataBus'
   *  UnitDelay: '<S50>/Unit Delay2'
   */
  rtb_RelationalOperator3_ibon = (VsMPFU_DataBus.timestamp_low ==
    ALCA_subsystem_integrated_DW.pre_mpfu_timeStamp);

  /* Gain: '<S67>/Gain' */
  rtb_Gain_gqz3 = rtb_veh_curvature;

  /* Chart: '<S67>/Chart' */
  ALCA_subsystem_integrated_Chart(rtb_RelationalOperator3_ibon, rtb_Gain_gqz3,
    &rtb_y_gjef, &rtb_state_fk3y, &ALCA_subsystem_integrated_DW.sf_Chart_acqd);

  /* Switch: '<S50>/Switch3' incorporates:
   *  Constant: '<S50>/Constant11'
   *  S-Function (sfix_bitop): '<S50>/Bitwise Operator4'
   *  Switch: '<S50>/Switch2'
   */
  if (rtb_y_gjef)
  {
    /* Switch: '<S50>/Switch2' incorporates:
     *  Constant: '<S50>/Constant11'
     */
    if (rtb_y_fabi)
    {
      rtb_Switch3_lalf = ALCA_subsystem_integrate_ConstB.BitwiseOperator3;
    }
    else
    {
      rtb_Switch3_lalf = ((uint8_T)0U);
    }

    rtb_Switch3_lalf |= ALCA_subsystem_integrate_ConstB.DataTypeConversion3;
  }
  else if (rtb_y_fabi)
  {
    /* Switch: '<S50>/Switch2' */
    rtb_Switch3_lalf = ALCA_subsystem_integrate_ConstB.BitwiseOperator3;
  }
  else
  {
    rtb_Switch3_lalf = ((uint8_T)0U);
  }

  /* End of Switch: '<S50>/Switch3' */

  /* RelationalOperator: '<S50>/Relational Operator' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   *  UnitDelay: '<S50>/Unit Delay'
   */
  rtb_RelationalOperator_cbyf = (VsOBFU_DataBus.timestamp_low ==
    ALCA_subsystem_integrated_DW.pre_obfu_timeStamp);

  /* Gain: '<S65>/Gain' */
  rtb_Gain_gvue = rtb_veh_curvature;

  /* Chart: '<S65>/Chart' */
  ALCA_subsystem_integrated_Chart(rtb_RelationalOperator_cbyf, rtb_Gain_gvue,
    &rtb_y_hnng, &rtb_state_icet, &ALCA_subsystem_integrated_DW.sf_Chart_i2is);

  /* Switch: '<S50>/Switch' incorporates:
   *  S-Function (sfix_bitop): '<S50>/Bitwise Operator1'
   */
  if (rtb_y_hnng)
  {
    rtb_Switch3_lalf |= ALCA_subsystem_integrate_ConstB.DataTypeConversion4;
  }

  /* End of Switch: '<S50>/Switch' */

  /* Switch: '<S50>/Switch1' incorporates:
   *  Constant: '<S50>/Constant1'
   *  DataTypeConversion: '<S12>/Data Type Conversion6'
   *  Inport: '<Root>/COMM_CANR_Databus'
   *  RelationalOperator: '<S50>/Relational Operator1'
   *  S-Function (sfix_bitop): '<S50>/Bitwise Operator2'
   */
  if ((VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveActiveStatus ? 1U :
       0U) != ((uint8_T)1U))
  {
    VfALCA_FaultInit = (uint8_T)
      (ALCA_subsystem_integrate_ConstB.DataTypeConversion1 | rtb_Switch3_lalf);
  }
  else
  {
    VfALCA_FaultInit = rtb_Switch3_lalf;
  }

  /* End of Switch: '<S50>/Switch1' */

  /* Switch: '<S12>/Switch3' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S12>/Constant1'
   */
  if (KbALCA_EnblCheckTimestamp)
  {
    *rty_fault = VfALCA_FaultInit;
  }
  else
  {
    *rty_fault = ((uint8_T)0U);
  }

  /* End of Switch: '<S12>/Switch3' */

  /* RelationalOperator: '<S49>/Relational Operator' incorporates:
   *  Constant: '<S49>/Constant4'
   *  S-Function (sfix_bitop): '<S49>/Bitwise Operator'
   */
  rtb_RelationalOperator_apdn = (((*rty_fault) &
    ALCA_subsystem_integrate_ConstB.DataTypeConversion) != ((uint8_T)0U));

  /* Switch: '<S49>/Switch2' incorporates:
   *  Constant: '<S58>/Constant3'
   *  Inport: '<Root>/EGMO_DataBus'
   *  Product: '<S58>/Divide3'
   */
  if (rtb_RelationalOperator_apdn)
  {
    rtb_veh_curvature = 1.0F / rtb_y;
  }
  else
  {
    rtb_veh_curvature = VsEGMO_DataBus.motion.curvature;
  }

  /* End of Switch: '<S49>/Switch2' */

  /* Switch: '<S49>/Switch' incorporates:
   *  DataTypeConversion: '<S59>/Data Type Conversion11'
   *  Inport: '<Root>/COMM_CANR_Databus'
   *  Inport: '<Root>/EGMO_DataBus'
   */
  if (rtb_RelationalOperator_apdn)
  {
    VfALCA_v_VehSpeed =
      VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed;
  }
  else
  {
    VfALCA_v_VehSpeed = VsEGMO_DataBus.motion.linear_velocity;
  }

  /* End of Switch: '<S49>/Switch' */

  /* SignalConversion: '<S49>/Signal Conversion1' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VfALCA_v_VehVx = VsEGMO_DataBus.motion.velocity_rel.x;

  /* SignalConversion: '<S49>/Signal Conversion8' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VfALCA_v_VehVy = VsEGMO_DataBus.motion.velocity_rel.y;

  /* BusCreator: '<S49>/Bus Creator1' */
  rty_veh_state->veh_speed = VfALCA_v_VehSpeed;

  /* Switch: '<S49>/Switch1' */
  if (rtb_RelationalOperator_apdn)
  {
    /* BusCreator: '<S49>/Bus Creator1' incorporates:
     *  DataTypeConversion: '<S59>/Data Type Conversion20'
     *  Inport: '<Root>/COMM_CANR_Databus'
     */
    rty_veh_state->veh_acceleration =
      VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAcceleration;
  }
  else
  {
    /* BusCreator: '<S49>/Bus Creator1' incorporates:
     *  Inport: '<Root>/EGMO_DataBus'
     */
    rty_veh_state->veh_acceleration = VsEGMO_DataBus.motion.linear_acceleration;
  }

  /* End of Switch: '<S49>/Switch1' */

  /* BusCreator: '<S49>/Bus Creator1' */
  rty_veh_state->veh_curvature = rtb_veh_curvature;
  rty_veh_state->veh_vx = VfALCA_v_VehVx;
  rty_veh_state->veh_vy = VfALCA_v_VehVy;

  /* DataTypeConversion: '<S59>/Data Type Conversion12' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  rtb_DataTypeConversion12 =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BrakeLightStatus ? 1U : 0U;

  /* DataTypeConversion: '<S59>/Data Type Conversion13' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  rtb_DataTypeConversion13 =
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ActualControlStatus;

  /* DataTypeConversion: '<S59>/Data Type Conversion14' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  rtb_DataTypeConversion14 =
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition;

  /* DataTypeConversion: '<S59>/Data Type Conversion15' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  rtb_DataTypeConversion15 = (uint8_T)
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalPosition;

  /* DataTypeConversion: '<S59>/Data Type Conversion16' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  rtb_DataTypeConversion16 = (uint8_T)
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_ActualAccelPedalPosition;

  /* DataTypeConversion: '<S59>/Data Type Conversion17' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  rtb_DataTypeConversion17 =
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveActiveStatus ? 1U :
    0U;

  /* DataTypeConversion: '<S59>/Data Type Conversion18' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  rtb_DataTypeConversion18 =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAcceleration;

  /* Update for UnitDelay: '<S50>/Unit Delay1' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  ALCA_subsystem_integrated_DW.pre_egmo_timeStamp = VsEGMO_DataBus.timestamp_low;

  /* Update for UnitDelay: '<S50>/Unit Delay2' incorporates:
   *  Inport: '<Root>/MPFU_DataBus'
   */
  ALCA_subsystem_integrated_DW.pre_mpfu_timeStamp = VsMPFU_DataBus.timestamp_low;

  /* Update for UnitDelay: '<S50>/Unit Delay' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  ALCA_subsystem_integrated_DW.pre_obfu_timeStamp = VsOBFU_DataBus.timestamp_low;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
