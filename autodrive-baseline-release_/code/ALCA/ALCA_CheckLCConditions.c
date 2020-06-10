/*
 * File: ALCA_CheckLCConditions.c
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

#include "ALCA_CheckLCConditions.h"

/* Include model header file for global data */
#include "ALCA_subsystem_integrated.h"
#include "ALCA_subsystem_integrated_private.h"

/* System initialize for atomic system: '<S3>/ALCA_CheckLCConditions' */
void ALC_ALCA_CheckLCConditions_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay' */
  ALCA_subsystem_integrated_DW.pre_distance_to_host = 0.0F;

  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay1' */
  ALCA_subsystem_integrated_DW.pre_lc_complete = false;

  /* InitializeConditions for Memory: '<S24>/Memory' */
  ALCA_subsystem_integrated_DW.Memory_PreviousInput_kxhj = false;

  /* SystemInitialize for Chart: '<S22>/Chart' */
  ALCA_subsystem_integ_Chart_Init(&ALCA_subsystem_integrated_DW.sf_Chart);

  /* SystemInitialize for Chart: '<S23>/Chart' */
  ALCA_subsystem_integ_Chart_Init(&ALCA_subsystem_integrated_DW.sf_Chart_hv4o);
}

/* System reset for atomic system: '<S3>/ALCA_CheckLCConditions' */
void AL_ALCA_CheckLCConditions_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay' */
  ALCA_subsystem_integrated_DW.pre_distance_to_host = 0.0F;

  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay1' */
  ALCA_subsystem_integrated_DW.pre_lc_complete = false;

  /* InitializeConditions for Memory: '<S24>/Memory' */
  ALCA_subsystem_integrated_DW.Memory_PreviousInput_kxhj = false;

  /* SystemReset for Chart: '<S22>/Chart' */
  ALCA_subsystem_inte_Chart_Reset(&ALCA_subsystem_integrated_DW.sf_Chart);

  /* SystemReset for Chart: '<S23>/Chart' */
  ALCA_subsystem_inte_Chart_Reset(&ALCA_subsystem_integrated_DW.sf_Chart_hv4o);
}

/* Start for atomic system: '<S3>/ALCA_CheckLCConditions' */
void AL_ALCA_CheckLCConditions_Start(void)
{
  /* Start for DataStoreMemory: '<S8>/KbALCA_EnblCheckMPFULaneMarkerType' */
  ALCA_subsystem_integrated_DW.KbALCA_EnblCheckMPFULaneMarkerT =
    KbALCA_EnblCheckMPFULaneMarkerType;

  /* Start for DataStoreMemory: '<S8>/KbALCA_EnblCheckObstacles' */
  ALCA_subsystem_integrated_DW.KbALCA_EnblCheckObstacles_odv1 =
    KbALCA_EnblCheckObstacles;

  /* Start for DataStoreMemory: '<S8>/KbALCA_EnblOvrdLaneLength' */
  ALCA_subsystem_integrated_DW.KbALCA_EnblOvrdLaneLength_mu5k =
    KbALCA_EnblOvrdLaneLength;

  /* Start for DataStoreMemory: '<S8>/KbALCA_EnblOvrdLaneWidth' */
  ALCA_subsystem_integrated_DW.KbALCA_EnblOvrdLaneWidth_czwz =
    KbALCA_EnblOvrdLaneWidth;

  /* Start for DataStoreMemory: '<S8>/KfALCA_d_DefaultLaneLength' */
  ALCA_subsystem_integrated_DW.KfALCA_d_DefaultLaneLength_pz0k =
    KfALCA_d_DefaultLaneLength;

  /* Start for DataStoreMemory: '<S8>/KfALCA_r_ComfortableVRatio' */
  ALCA_subsystem_integrated_DW.KfALCA_r_ComfortableVRatio_ldnz =
    KfALCA_r_ComfortableVRatio;

  /* Start for DataStoreMemory: '<S8>/KfALCA_r_EgoWidth2LaneWidthRation' */
  ALCA_subsystem_integrated_DW.KfALCA_r_EgoWidth2LaneWidthRati =
    KfALCA_r_EgoWidth2LaneWidthRation;

  /* Start for DataStoreMemory: '<S8>/KfALCA_v_SpeedLaneChangeEnblMax' */
  ALCA_subsystem_integrated_DW.KfALCA_v_SpeedLaneChangeEn_g0ux =
    KfALCA_v_SpeedLaneChangeEnblMax;

  /* Start for DataStoreMemory: '<S8>/KfALCA_v_SpeedLaneChangeEnblMin' */
  ALCA_subsystem_integrated_DW.KfALCA_v_SpeedLaneChangeEn_hgzb =
    KfALCA_v_SpeedLaneChangeEnblMin;

  /* Start for DataStoreMemory: '<S8>/KfAlCA_d_CheckObstacleDistMin' */
  ALCA_subsystem_integrated_DW.KfAlCA_d_CheckObstacleDist_aqcl =
    KfAlCA_d_CheckObstacleDistMin;
}

/* Output and update for atomic system: '<S3>/ALCA_CheckLCConditions' */
void ALCA_sub_ALCA_CheckLCConditions(const ALCA_DcsnInfo *rtu_dcsn_info, const
  ALCA_VehState *rtu_veh_state, EnumALCA_state rtu_pre_state, uint8_T rtu_fault,
  const ALCA_MPFU_Info *rtu_mpfu_info, boolean_T *rty_lc_accept, boolean_T
  *rty_inform_req, EnumALCA_not_fulfill_reason *rty_odd_not_fulfill_reason,
  EnumDCSN_driving_direction *rty_inform_side, EnumDCSN_driving_direction
  *rty_req_side, real32_T *rty_dist_host_2_target_lane_cen, real32_T
  *rty_v_lon2lane_marker)
{
  int32_T rowIdx;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_complete_before;
  real32_T rtb_Gain_pzzc;
  real32_T rtb_Gain_ke2g;
  boolean_T rtb_y;
  real32_T rtb_pre_distance_to_host;
  real32_T lc_time;
  OBFU_Obstacle dangerous_obstacle;
  boolean_T lc_acceptable;
  uint8_T rtb_state_i2l4;
  uint8_T rtb_state;

  /* DataStoreWrite: '<S15>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn11' incorporates:
   *  Constant: '<S15>/Constant11'
   */
  ALCA_subsystem_integrated_DW.KbALCA_EnblOvrdLaneWidth_czwz =
    KbALCA_EnblOvrdLaneWidth;

  /* Logic: '<S16>/Logical Operator1' incorporates:
   *  Constant: '<S16>/Constant3'
   *  Constant: '<S16>/Constant8'
   *  Constant: '<S25>/Constant'
   *  RelationalOperator: '<S16>/Relational Operator1'
   *  RelationalOperator: '<S16>/Relational Operator2'
   *  RelationalOperator: '<S16>/Relational Operator3'
   */
  rtb_LogicalOperator1 = (((rtu_pre_state == ALCA_state_Activated) ||
    (rtu_pre_state == ALCA_state_Abort)) || (rtu_pre_state ==
    ALCA_state_Handover));

  /* UnitDelay: '<S8>/Unit Delay' */
  rtb_pre_distance_to_host = ALCA_subsystem_integrated_DW.pre_distance_to_host;

  /* MATLAB Function: '<S8>/CheckLCComplete' */
  ALCA_subsystem__CheckLCComplete(rtb_LogicalOperator1,
    rtu_dcsn_info->change_lane_req_side, rtu_mpfu_info, rtb_pre_distance_to_host,
    &VbALCA_TouchedNewLane, &VfALCA_d_EGOLaneCenter2Host,
    &VfALCA_d_TargetSideLaneMarker2Host);

  /* CombinatorialLogic: '<S24>/Logic' incorporates:
   *  Memory: '<S24>/Memory'
   *  UnitDelay: '<S8>/Unit Delay1'
   */
  rowIdx = (int32_T)((uint32_T)((((((uint32_T)(VbALCA_TouchedNewLane ? 1U : 0U))
    << 1) + (ALCA_subsystem_integrated_DW.pre_lc_complete ? 1U : 0U)) << 1) +
    (ALCA_subsystem_integrated_DW.Memory_PreviousInput_kxhj ? 1U : 0U)));
  ALCA_subsystem_integrated_B.Logic[0U] =
    ALCA_subsystem_integrate_ConstP.pooled8[(uint32_T)rowIdx];
  ALCA_subsystem_integrated_B.Logic[1U] =
    ALCA_subsystem_integrate_ConstP.pooled8[((uint32_T)rowIdx) + 8U];

  /* DataStoreWrite: '<S15>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn1' incorporates:
   *  Constant: '<S15>/Constant1'
   */
  ALCA_subsystem_integrated_DW.KfALCA_v_SpeedLaneChangeEn_g0ux =
    KfALCA_v_SpeedLaneChangeEnblMax;

  /* DataStoreWrite: '<S15>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn10' incorporates:
   *  Constant: '<S15>/Constant10'
   */
  ALCA_subsystem_integrated_DW.KfALCA_r_ComfortableVRatio_ldnz =
    KfALCA_r_ComfortableVRatio;

  /* DataStoreWrite: '<S15>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn2' incorporates:
   *  Constant: '<S15>/Constant2'
   */
  ALCA_subsystem_integrated_DW.KfALCA_v_SpeedLaneChangeEn_hgzb =
    KfALCA_v_SpeedLaneChangeEnblMin;

  /* DataStoreWrite: '<S15>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn4' incorporates:
   *  Constant: '<S15>/Constant3'
   */
  ALCA_subsystem_integrated_DW.KbALCA_EnblCheckMPFULaneMarkerT =
    KbALCA_EnblCheckMPFULaneMarkerType;

  /* DataStoreWrite: '<S15>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn3' incorporates:
   *  Constant: '<S15>/Constant4'
   */
  ALCA_subsystem_integrated_DW.KfAlCA_d_CheckObstacleDist_aqcl =
    KfAlCA_d_CheckObstacleDistMin;

  /* DataStoreWrite: '<S15>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn6' incorporates:
   *  Constant: '<S15>/Constant6'
   */
  ALCA_subsystem_integrated_DW.KfALCA_r_EgoWidth2LaneWidthRati =
    KfALCA_r_EgoWidth2LaneWidthRation;

  /* DataStoreWrite: '<S15>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn7' incorporates:
   *  Constant: '<S15>/Constant7'
   */
  ALCA_subsystem_integrated_DW.KbALCA_EnblOvrdLaneLength_mu5k =
    KbALCA_EnblOvrdLaneLength;

  /* DataStoreWrite: '<S15>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn8' incorporates:
   *  Constant: '<S15>/Constant8'
   */
  ALCA_subsystem_integrated_DW.KfALCA_d_DefaultLaneLength_pz0k =
    KfALCA_d_DefaultLaneLength;

  /* DataStoreWrite: '<S15>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn9' incorporates:
   *  Constant: '<S15>/Constant9'
   */
  ALCA_subsystem_integrated_DW.KbALCA_EnblCheckObstacles_odv1 =
    KbALCA_EnblCheckObstacles;

  /* MATLAB Function: '<S8>/CheckLCODD' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S8>/Constant10'
   *  Constant: '<S8>/Constant6'
   *  Constant: '<S8>/Constant7'
   *  Constant: '<S8>/Constant9'
   */
  ALCA_subsystem_integ_CheckLCODD(rtu_mpfu_info, rtu_dcsn_info, rtu_veh_state,
    false, rtu_fault, ALCA_subsystem_integrated_B.Logic[0], rtu_pre_state,
    KaALCA_AXIS_RelativeSpeedHost2Obstacle, KaALCA_AXIS_VehSpeed,
    KtALCA_d_RangeFrontOfCheckObstacle, KtALCA_d_RangeRearOfCheckObstacle,
    &lc_acceptable, rty_odd_not_fulfill_reason, rty_inform_req, rty_inform_side,
    rty_req_side, &lc_time, &dangerous_obstacle, rty_dist_host_2_target_lane_cen,
    rty_v_lon2lane_marker);

  /* SignalConversion: '<S21>/Signal Conversion1' */
  VfALCA_ObstacleNearest_x = dangerous_obstacle.nearest_point_rel.x;

  /* SignalConversion: '<S21>/Signal Conversion10' */
  VfALCA_ObstacleID = dangerous_obstacle.id;

  /* SignalConversion: '<S21>/Signal Conversion2' */
  VfALCA_ObstacleNearest_y = dangerous_obstacle.nearest_point_rel.y;

  /* SignalConversion: '<S21>/Signal Conversion3' */
  VfALCA_ObstacleCenter_x = dangerous_obstacle.center_point_rel.x;

  /* SignalConversion: '<S21>/Signal Conversion4' */
  VfALCA_v_Obstacle_Vx = dangerous_obstacle.velocity_rel.x;

  /* SignalConversion: '<S21>/Signal Conversion5' */
  VfALCA_v_Obstacle_Vy = dangerous_obstacle.velocity_rel.y;

  /* SignalConversion: '<S21>/Signal Conversion6' */
  VfALCA_ObstacleCenter_y = dangerous_obstacle.center_point_rel.y;

  /* SignalConversion: '<S21>/Signal Conversion7' */
  VfALCA_ObstacleLength = dangerous_obstacle.length;

  /* SignalConversion: '<S21>/Signal Conversion8' */
  VfALCA_ObstacleWidth = dangerous_obstacle.width;

  /* SignalConversion: '<S21>/Signal Conversion9' */
  VfALCA_ObstacleHeading = dangerous_obstacle.heading_rel;

  /* Logic: '<S20>/Logical Operator' incorporates:
   *  Constant: '<S27>/Constant'
   *  Logic: '<S20>/Logical Operator2'
   *  RelationalOperator: '<S20>/Relational Operator'
   */
  rtb_LogicalOperator = (((*rty_odd_not_fulfill_reason) ==
    ALCA_not_fulfill_reason_has_obstacle) &&
    (!ALCA_subsystem_integrated_B.Logic[0]));

  /* Logic: '<S20>/Logical Operator3' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S29>/Constant'
   *  Logic: '<S20>/Logical Operator1'
   *  Logic: '<S20>/Logical Operator4'
   *  RelationalOperator: '<S20>/Relational Operator1'
   *  RelationalOperator: '<S20>/Relational Operator2'
   */
  ALCA_subsystem_integrated_B.LogicalOperator3 =
    (((rtu_dcsn_info->change_lane_cancel) || rtb_LogicalOperator) &&
     ((rtu_pre_state == ALCA_state_Activated) || (rtu_pre_state ==
       ALCA_state_Handover)));

  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S30>/Constant'
   *  Constant: '<S31>/Constant'
   *  Switch: '<S20>/Switch1'
   */
  if (rtu_dcsn_info->change_lane_cancel)
  {
    ALCA_subsystem_integrated_B.Switch = ALCA_interrupt_type_driver_cancel;
  }
  else if (rtb_LogicalOperator)
  {
    /* Switch: '<S20>/Switch1' incorporates:
     *  Constant: '<S26>/Constant'
     */
    ALCA_subsystem_integrated_B.Switch = ALCA_interrupt_type_has_obstacle;
  }
  else
  {
    ALCA_subsystem_integrated_B.Switch = ALCA_interrupt_type_no;
  }

  /* End of Switch: '<S20>/Switch' */

  /* RelationalOperator: '<S8>/Relational Operator' incorporates:
   *  Constant: '<S8>/Constant'
   */
  rtb_complete_before = (VfALCA_d_EGOLaneCenter2Host <=
    KfALCA_d_Dist2LaneChangeFinish);

  /* Gain: '<S22>/Gain' incorporates:
   *  Constant: '<S8>/Constant1'
   */
  rtb_Gain_pzzc = 100.0F * KfALCA_t_HoldTimeForLCComplete;

  /* Chart: '<S22>/Chart' */
  ALCA_subsystem_integrated_Chart(rtb_complete_before, rtb_Gain_pzzc, &rtb_y,
    &rtb_state_i2l4, &ALCA_subsystem_integrated_DW.sf_Chart);

  /* Gain: '<S23>/Gain' incorporates:
   *  Constant: '<S8>/Constant2'
   */
  rtb_Gain_ke2g = 100.0F * KfALCA_t_HoldTimeForLCAccept;

  /* Chart: '<S23>/Chart' */
  ALCA_subsystem_integrated_Chart(lc_acceptable, rtb_Gain_ke2g, rty_lc_accept,
    &rtb_state, &ALCA_subsystem_integrated_DW.sf_Chart_hv4o);

  /* Logic: '<S8>/Logical Operator' */
  VbALCA_LC_Complete = ((ALCA_subsystem_integrated_B.Logic[0]) && rtb_y);

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant4'
   *  Constant: '<S8>/Constant5'
   */
  if (KbALCA_OvrdLaneChangeTime)
  {
    VfALCA_t_LCTime = KfALCA_t_LaneChangeTimeMax;
  }
  else
  {
    VfALCA_t_LCTime = lc_time;
  }

  /* End of Switch: '<S8>/Switch' */

  /* Update for UnitDelay: '<S8>/Unit Delay' */
  ALCA_subsystem_integrated_DW.pre_distance_to_host =
    VfALCA_d_TargetSideLaneMarker2Host;

  /* Update for UnitDelay: '<S8>/Unit Delay1' */
  ALCA_subsystem_integrated_DW.pre_lc_complete = VbALCA_LC_Complete;

  /* Update for Memory: '<S24>/Memory' */
  ALCA_subsystem_integrated_DW.Memory_PreviousInput_kxhj =
    ALCA_subsystem_integrated_B.Logic[0];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
