/*
 * File: AEBS.c
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

#include "AEBS.h"

/* Include model header file for global data */
#include "AEBS_subsystem_integrated.h"
#include "AEBS_subsystem_integrated_private.h"

/* System initialize for atomic system: '<Root>/AEBS' */
void AEBS_subsystem_integr_AEBS_Init(void)
{
  /* SystemInitialize for IfAction SubSystem: '<S1>/AEBS_Enabled' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/AEBS_Input' */
  AEBS_subsystem__AEBS_Input_Init();

  /* End of SystemInitialize for SubSystem: '<S3>/AEBS_Input' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/AEB_FCWVIPTargetSelection' */
  AEB_FCWVIPTargetSelection_Init();

  /* End of SystemInitialize for SubSystem: '<S3>/AEB_FCWVIPTargetSelection' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/FCW_Determination' */
  AEBS_sub_FCW_Determination_Init();

  /* End of SystemInitialize for SubSystem: '<S3>/FCW_Determination' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/AEB_Determination' */
  AEBS_sub_AEB_Determination_Init();

  /* End of SystemInitialize for SubSystem: '<S3>/AEB_Determination' */

  /* End of SystemInitialize for SubSystem: '<S1>/AEBS_Enabled' */
}

/* Start for atomic system: '<Root>/AEBS' */
void AEBS_subsystem_integ_AEBS_Start(void)
{
  /* Start for IfAction SubSystem: '<S1>/AEBS_Enabled' */

  /* Start for Atomic SubSystem: '<S3>/AEB_FCWVIPTargetSelection' */
  AEB_FCWVIPTargetSelection_Start();

  /* End of Start for SubSystem: '<S3>/AEB_FCWVIPTargetSelection' */

  /* Start for DataStoreMemory: '<S3>/KfAEBS_CTRL_PeriodFunctionCall' */
  AEBS_subsystem_integrated_DW.KfAEBS_CTRL_PeriodFunction_oryw =
    KfAEBS_CTRL_PeriodFunctionCall;

  /* Start for DataStoreMemory: '<S3>/KfAEBS_a_BrakeHold' */
  AEBS_subsystem_integrated_DW.KfAEBS_a_BrakeHold_ci33 = KfAEBS_a_BrakeHold;

  /* Start for DataStoreMemory: '<S3>/KfAEBS_t_BrkPdlDeprssd_Thrsh' */
  AEBS_subsystem_integrated_DW.KfAEBS_t_BrkPdlDeprssd_Thr_diax =
    KfAEBS_t_BrkPdlDeprssd_Thrsh;

  /* Start for DataStoreMemory: '<S3>/KfAEBS_t_TimeBrakeConfdConfirmed' */
  AEBS_subsystem_integrated_DW.KfAEBS_t_TimeBrakeConfdConfirme =
    KfAEBS_t_TimeBrakeConfdConfirmed;

  /* Start for DataStoreMemory: '<S3>/KfAEBS_t_TimeExitActide' */
  AEBS_subsystem_integrated_DW.KfAEBS_t_TimeExitActide_ibk1 =
    KfAEBS_t_TimeExitActide;

  /* Start for DataStoreMemory: '<S3>/KfAEBS_t_TimeWait2StandbyThrsh' */
  AEBS_subsystem_integrated_DW.KfAEBS_t_TimeWait2StandbyT_gpm0 =
    KfAEBS_t_TimeWait2StandbyThrsh;

  /* End of Start for SubSystem: '<S1>/AEBS_Enabled' */
}

/* Output and update for atomic system: '<Root>/AEBS' */
void AEBS_subsystem_integrated_AEBS(void)
{
  /* SignalConversion: '<S4>/Signal Conversion1' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_timestamp_low = VsOBFU_DataBus.timestamp_low;

  /* SignalConversion: '<S4>/Signal Conversion10' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_1_a_x = VsOBFU_DataBus.obstacles[0].acceleration_rel.x;

  /* SignalConversion: '<S4>/Signal Conversion11' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_1_a_y = VsOBFU_DataBus.obstacles[0].acceleration_rel.y;

  /* SignalConversion: '<S4>/Signal Conversion12' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_1_length = VsOBFU_DataBus.obstacles[0].length;

  /* SignalConversion: '<S4>/Signal Conversion13' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_1_width = VsOBFU_DataBus.obstacles[0].width;

  /* SignalConversion: '<S4>/Signal Conversion14' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_1_type = VsOBFU_DataBus.obstacles[0].type;

  /* SignalConversion: '<S4>/Signal Conversion15' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_1_motion_status = VsOBFU_DataBus.obstacles[0].motion_status;

  /* SignalConversion: '<S4>/Signal Conversion16' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_1_position_zone = VsOBFU_DataBus.obstacles[0].position_zone;

  /* SignalConversion: '<S4>/Signal Conversion17' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_2_id = VsOBFU_DataBus.obstacles[1].id;

  /* SignalConversion: '<S4>/Signal Conversion18' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_2_NP_x = VsOBFU_DataBus.obstacles[1].nearest_point_rel.x;

  /* SignalConversion: '<S4>/Signal Conversion19' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_2_NP_y = VsOBFU_DataBus.obstacles[1].nearest_point_rel.y;

  /* SignalConversion: '<S4>/Signal Conversion2' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_num_obstacles = VsOBFU_DataBus.num_obstacles;

  /* SignalConversion: '<S4>/Signal Conversion20' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_2_position_zone = VsOBFU_DataBus.obstacles[1].position_zone;

  /* SignalConversion: '<S4>/Signal Conversion21' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_2_motion_status = VsOBFU_DataBus.obstacles[1].motion_status;

  /* SignalConversion: '<S4>/Signal Conversion22' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_3_id = VsOBFU_DataBus.obstacles[2].id;

  /* SignalConversion: '<S4>/Signal Conversion23' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_3_NP_x = VsOBFU_DataBus.obstacles[2].nearest_point_rel.x;

  /* SignalConversion: '<S4>/Signal Conversion24' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_3_NP_y = VsOBFU_DataBus.obstacles[2].nearest_point_rel.y;

  /* SignalConversion: '<S4>/Signal Conversion25' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_3_position_zone = VsOBFU_DataBus.obstacles[2].position_zone;

  /* SignalConversion: '<S4>/Signal Conversion26' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_3_motion_status = VsOBFU_DataBus.obstacles[2].motion_status;

  /* SignalConversion: '<S4>/Signal Conversion27' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_2_heading = VsOBFU_DataBus.obstacles[1].heading_rel;

  /* SignalConversion: '<S4>/Signal Conversion28' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_3_heading = VsOBFU_DataBus.obstacles[2].heading_rel;

  /* SignalConversion: '<S4>/Signal Conversion29' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_4_id = VsOBFU_DataBus.obstacles[3].id;

  /* SignalConversion: '<S4>/Signal Conversion3' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_1_id = VsOBFU_DataBus.obstacles[0].id;

  /* SignalConversion: '<S4>/Signal Conversion30' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_4_NP_x = VsOBFU_DataBus.obstacles[3].nearest_point_rel.x;

  /* SignalConversion: '<S4>/Signal Conversion31' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_4_NP_y = VsOBFU_DataBus.obstacles[3].nearest_point_rel.y;

  /* SignalConversion: '<S4>/Signal Conversion32' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_4_position_zone = VsOBFU_DataBus.obstacles[3].position_zone;

  /* SignalConversion: '<S4>/Signal Conversion33' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_4_motion_status = VsOBFU_DataBus.obstacles[3].motion_status;

  /* SignalConversion: '<S4>/Signal Conversion34' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_4_heading = VsOBFU_DataBus.obstacles[3].heading_rel;

  /* SignalConversion: '<S4>/Signal Conversion35' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_2_length = VsOBFU_DataBus.obstacles[1].length;

  /* SignalConversion: '<S4>/Signal Conversion36' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_2_width = VsOBFU_DataBus.obstacles[1].width;

  /* SignalConversion: '<S4>/Signal Conversion37' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_3_length = VsOBFU_DataBus.obstacles[2].length;

  /* SignalConversion: '<S4>/Signal Conversion38' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_3_width = VsOBFU_DataBus.obstacles[2].width;

  /* SignalConversion: '<S4>/Signal Conversion39' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_4_length = VsOBFU_DataBus.obstacles[3].length;

  /* SignalConversion: '<S4>/Signal Conversion4' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_1_NP_x = VsOBFU_DataBus.obstacles[0].nearest_point_rel.x;

  /* SignalConversion: '<S4>/Signal Conversion40' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_4_width = VsOBFU_DataBus.obstacles[3].width;

  /* SignalConversion: '<S4>/Signal Conversion41' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_1_confidence = VsOBFU_DataBus.obstacles[0].confidence;

  /* SignalConversion: '<S4>/Signal Conversion42' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_2_confidence = VsOBFU_DataBus.obstacles[1].confidence;

  /* SignalConversion: '<S4>/Signal Conversion43' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_3_confidence = VsOBFU_DataBus.obstacles[2].confidence;

  /* SignalConversion: '<S4>/Signal Conversion44' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_4_confidence = VsOBFU_DataBus.obstacles[3].confidence;

  /* SignalConversion: '<S4>/Signal Conversion5' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_1_NP_y = VsOBFU_DataBus.obstacles[0].nearest_point_rel.y;

  /* SignalConversion: '<S4>/Signal Conversion6' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_1_heading = VsOBFU_DataBus.obstacles[0].heading_rel;

  /* SignalConversion: '<S4>/Signal Conversion7' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_1_v_x = VsOBFU_DataBus.obstacles[0].velocity_rel.x;

  /* SignalConversion: '<S4>/Signal Conversion8' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_timestamp_high = VsOBFU_DataBus.timestamp_high;

  /* SignalConversion: '<S4>/Signal Conversion9' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfAEBS_m_1_v_y = VsOBFU_DataBus.obstacles[0].velocity_rel.y;

  /* SignalConversion: '<S5>/Signal Conversion1' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VfAEBS_m_EGMO_timestamp_l = VsEGMO_DataBus.timestamp_low;

  /* SignalConversion: '<S5>/Signal Conversion3' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VfAEBS_m_EGMO_timestamp_h = VsEGMO_DataBus.timestamp_high;

  /* SignalConversion: '<S5>/Signal Conversion5' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VfAEBS_m_EGMO_veh_speed = VsEGMO_DataBus.motion.linear_velocity;

  /* SignalConversion: '<S5>/Signal Conversion6' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VfAEBS_m_EGMO_veh_acc = VsEGMO_DataBus.motion.linear_acceleration;

  /* SignalConversion: '<S5>/Signal Conversion7' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VfAEBS_m_EGMO_v_cur = VsEGMO_DataBus.motion.curvature;

  /* SignalConversion: '<S5>/Signal Conversion8' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VfAEBS_m_EGMO_v_x = VsEGMO_DataBus.motion.velocity_rel.x;

  /* SignalConversion: '<S5>/Signal Conversion9' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VfAEBS_m_EGMO_v_y = VsEGMO_DataBus.motion.velocity_rel.y;

  /* If: '<S1>/If' incorporates:
   *  Constant: '<S1>/Constant27'
   *  Inport: '<Root>/DCSN_DataBus'
   *  Logic: '<S1>/Logical Operator'
   *  Logic: '<S1>/Logical Operator1'
   */
  switch ((int8_T)((!(((VsDCSN_DataBus.EnablingFlags_Group.fcw_feature_enable) ||
                       (VsDCSN_DataBus.EnablingFlags_Group.aeb_feature_enable)) &&
                      KbAEBS_Enable_AEB_feature)) ? 1 : 0))
  {
   case 0:
    /* Outputs for IfAction SubSystem: '<S1>/AEBS_Enabled' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */

    /* Outputs for Atomic SubSystem: '<S3>/AEBS_Input' */
    AEBS_subsystem_integ_AEBS_Input();

    /* End of Outputs for SubSystem: '<S3>/AEBS_Input' */

    /* DataStoreWrite: '<S3>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn5' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    AEBS_subsystem_integrated_DW.KfAEBS_t_TimeExitActide_ibk1 =
      KfAEBS_t_TimeExitActide;

    /* DataStoreWrite: '<S3>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn4' incorporates:
     *  Constant: '<S3>/Constant28'
     */
    AEBS_subsystem_integrated_DW.KfAEBS_t_TimeWait2StandbyT_gpm0 =
      KfAEBS_t_TimeWait2StandbyThrsh;

    /* DataStoreWrite: '<S3>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn2' incorporates:
     *  Constant: '<S3>/Constant9'
     */
    AEBS_subsystem_integrated_DW.KfAEBS_CTRL_PeriodFunction_oryw =
      KfAEBS_CTRL_PeriodFunctionCall;

    /* Outputs for Atomic SubSystem: '<S3>/AEB_FCWVIPTargetSelection' */
    AEBS__AEB_FCWVIPTargetSelection();

    /* End of Outputs for SubSystem: '<S3>/AEB_FCWVIPTargetSelection' */

    /* Outputs for Atomic SubSystem: '<S3>/FCW_Determination' */
    AEBS_subsyste_FCW_Determination();

    /* End of Outputs for SubSystem: '<S3>/FCW_Determination' */

    /* DataStoreWrite: '<S3>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn6' incorporates:
     *  Constant: '<S3>/Constant2'
     */
    AEBS_subsystem_integrated_DW.KfAEBS_a_BrakeHold_ci33 = KfAEBS_a_BrakeHold;

    /* DataStoreWrite: '<S3>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn3' incorporates:
     *  Constant: '<S3>/Constant27'
     */
    AEBS_subsystem_integrated_DW.KfAEBS_t_TimeBrakeConfdConfirme =
      KfAEBS_t_TimeBrakeConfdConfirmed;

    /* DataStoreWrite: '<S3>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn7' incorporates:
     *  Constant: '<S3>/Constant3'
     */
    AEBS_subsystem_integrated_DW.KfAEBS_t_BrkPdlDeprssd_Thr_diax =
      KfAEBS_t_BrkPdlDeprssd_Thrsh;

    /* Outputs for Atomic SubSystem: '<S3>/AEB_Determination' */
    AEBS_subsyste_AEB_Determination();

    /* End of Outputs for SubSystem: '<S3>/AEB_Determination' */

    /* Outputs for Atomic SubSystem: '<S3>/AEBS_Output' */
    AEBS_subsystem_inte_AEBS_Output();

    /* End of Outputs for SubSystem: '<S3>/AEBS_Output' */

    /* End of Outputs for SubSystem: '<S1>/AEBS_Enabled' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/AEBS_Default' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* BusCreator: '<S2>/BusCreator' incorporates:
     *  BusCreator: '<S2>/BusConversion_InsertedFor_BusCreator_at_inport_0'
     *  BusCreator: '<S2>/BusConversion_InsertedFor_BusCreator_at_inport_1'
     *  Constant: '<S2>/Constant'
     *  Constant: '<S2>/Constant1'
     *  Constant: '<S2>/Constant10'
     *  Constant: '<S2>/Constant11'
     *  Constant: '<S2>/Constant12'
     *  Constant: '<S2>/Constant13'
     *  Constant: '<S2>/Constant14'
     *  Constant: '<S2>/Constant2'
     *  Constant: '<S2>/Constant3'
     *  Constant: '<S2>/Constant4'
     *  Constant: '<S2>/Constant5'
     *  Constant: '<S2>/Constant6'
     *  Constant: '<S2>/Constant7'
     *  Constant: '<S2>/Constant8'
     *  Constant: '<S2>/Constant9'
     */
    VsAEBS_DataBus.FCW_Data.FCW_request = KbAEBS_Default_FCW_requset;
    VsAEBS_DataBus.FCW_Data.FCW_warn_level = KfAEBS_Default_FCW_warn_level;
    VsAEBS_DataBus.FCW_Data.FCW_enable_state = KfAEBS_Default_FCW_enable_state;
    VsAEBS_DataBus.FCW_Data.FCW_active_state = KfAEBS_Default_FCW_active_state;
    VsAEBS_DataBus.FCW_Data.FCW_error = KfAEBS_Default_FCW_error;
    VsAEBS_DataBus.AEB_Data.AEB_request = KbAEBS_Default_AEB_request;
    VsAEBS_DataBus.AEB_Data.AEB_prebrake_req = KbAEBS_Default_AEB_prebrake_req;
    VsAEBS_DataBus.AEB_Data.AEB_acceleration_req =
      KfAEBS_Default_AEB_acceleration_req;
    VsAEBS_DataBus.AEB_Data.AEB_brakeLight_req =
      KbAEBS_Default_AEB_brakeLight_req;
    VsAEBS_DataBus.AEB_Data.AEB_enabled_state = KfAEBS_Default_AEB_enabled_state;
    VsAEBS_DataBus.AEB_Data.AEB_actived_state = KfAEBS_Default_AEB_actived_state;
    VsAEBS_DataBus.AEB_Data.AEB_error = KfAEBS_Default_AEB_error;
    VsAEBS_DataBus.AEBS_brake_priority_setting = KfAEBS_Default_BrkPrioriy;
    VsAEBS_DataBus.AEBS_horn_ctrl_req = KfAEBS_Default_Horn_Req;
    VsAEBS_DataBus.AEBS_obj_ID = KfAEBS_Default_AEBS_obj_ID;

    /* End of Outputs for SubSystem: '<S1>/AEBS_Default' */
    break;

   default:
    /* no actions */
    break;
  }

  /* End of If: '<S1>/If' */
}

/* ConstCode for atomic system: '<Root>/AEBS' */
void AEBS_subsystem_integ_AEBS_Const(void)
{
  /* ConstCode for IfAction SubSystem: '<S1>/AEBS_Enabled' */

  /* ConstCode for Atomic SubSystem: '<S3>/AEBS_Input' */
  AEBS_subsystem_AEBS_Input_Const();

  /* End of ConstCode for SubSystem: '<S3>/AEBS_Input' */

  /* ConstCode for Atomic SubSystem: '<S3>/AEBS_Output' */
  AEBS_subsyste_AEBS_Output_Const();

  /* End of ConstCode for SubSystem: '<S3>/AEBS_Output' */

  /* End of ConstCode for SubSystem: '<S1>/AEBS_Enabled' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
