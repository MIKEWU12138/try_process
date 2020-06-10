/*
 * File: ALCA.c
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

#include "ALCA.h"

/* Include model header file for global data */
#include "ALCA_subsystem_integrated.h"
#include "ALCA_subsystem_integrated_private.h"

/* System initialize for atomic system: '<Root>/ALCA' */
void ALCA_subsystem_integr_ALCA_Init(void)
{
  /* SystemInitialize for IfAction SubSystem: '<S1>/ALCA_Enabled' */
  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  ALCA_subsystem_integrated_DW.prev_state = ALCA_state_OFF;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay1' */
  ALCA_subsystem_integrated_DW.reset_change_lane_req = false;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay2' */
  ALCA_subsystem_integrated_DW.touched_new_lane = false;

  /* SystemInitialize for Atomic SubSystem: '<S3>/ALCA_InputDataProcess' */
  ALCA_ALCA_InputDataProcess_Init();

  /* End of SystemInitialize for SubSystem: '<S3>/ALCA_InputDataProcess' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/ALCA_CheckLCConditions' */
  ALC_ALCA_CheckLCConditions_Init();

  /* End of SystemInitialize for SubSystem: '<S3>/ALCA_CheckLCConditions' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/ALCA_DtrmnALCAState' */
  ALCA_s_ALCA_DtrmnALCAState_Init();

  /* End of SystemInitialize for SubSystem: '<S3>/ALCA_DtrmnALCAState' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/ALCA_CalcLateralV ' */
  ALCA_sub_ALCA_CalcLateralV_Init();

  /* End of SystemInitialize for SubSystem: '<S3>/ALCA_CalcLateralV ' */

  /* End of SystemInitialize for SubSystem: '<S1>/ALCA_Enabled' */
}

/* Start for atomic system: '<Root>/ALCA' */
void ALCA_subsystem_integ_ALCA_Start(void)
{
  /* Start for If: '<S1>/If' */
  ALCA_subsystem_integrated_DW.If_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S1>/ALCA_Enabled' */

  /* Start for Atomic SubSystem: '<S3>/ALCA_InputDataProcess' */
  ALC_ALCA_InputDataProcess_Start();

  /* End of Start for SubSystem: '<S3>/ALCA_InputDataProcess' */

  /* Start for Atomic SubSystem: '<S3>/ALCA_CheckLCConditions' */
  AL_ALCA_CheckLCConditions_Start();

  /* End of Start for SubSystem: '<S3>/ALCA_CheckLCConditions' */

  /* Start for Atomic SubSystem: '<S3>/ALCA_DtrmnALCAState' */
  ALCA__ALCA_DtrmnALCAState_Start();

  /* End of Start for SubSystem: '<S3>/ALCA_DtrmnALCAState' */

  /* Start for DataStoreMemory: '<S3>/KbALCA_EnblOvrdInterruptAction' */
  ALCA_subsystem_integrated_DW.KbALCA_EnblOvrdInterruptAc_fnlg =
    KbALCA_EnblOvrdInterruptAction;

  /* Start for DataStoreMemory: '<S3>/KbALCA_UseNewAPI_Of_MPFU' */
  ALCA_subsystem_integrated_DW.KbALCA_UseNewAPI_Of_MPFU_jrss =
    KbALCA_UseNewAPI_Of_MPFU;

  /* Start for DataStoreMemory: '<S3>/KfALCA_d_EgoVehWidth' */
  ALCA_subsystem_integrated_DW.KfALCA_d_EgoVehWidth_d0rj = KfALCA_d_EgoVehWidth;

  /* Start for DataStoreMemory: '<S3>/KfALCA_d_LaneWidthMax' */
  ALCA_subsystem_integrated_DW.KfALCA_d_LaneWidthMax_a3am =
    KfALCA_d_LaneWidthMax;

  /* Start for DataStoreMemory: '<S3>/KfALCA_d_TouchedNewLaneDist' */
  ALCA_subsystem_integrated_DW.KfALCA_d_TouchedNewLaneDis_lbrk =
    KfALCA_d_TouchedNewLaneDist;

  /* Start for DataStoreMemory: '<S3>/KfALCA_t_LaneChangeTimeMax' */
  ALCA_subsystem_integrated_DW.KfALCA_t_LaneChangeTimeMax_lff2 =
    KfALCA_t_LaneChangeTimeMax;

  /* Start for DataStoreMemory: '<S3>/KfALCA_t_LaneChangeTimeMin' */
  ALCA_subsystem_integrated_DW.KfALCA_t_LaneChangeTimeMin_jj0b =
    KfALCA_t_LaneChangeTimeMin;

  /* End of Start for SubSystem: '<S1>/ALCA_Enabled' */
}

/* Output and update for atomic system: '<Root>/ALCA' */
void ALCA_subsystem_integrated_ALCA(void)
{
  int8_T rtPrevAction;
  int8_T rtAction;
  boolean_T rtb_Switch_b4ii;
  uint8_T Switch3;
  boolean_T inform_req;
  real32_T rtb_lateral_v_nm11;
  boolean_T rtb_UnitDelay1;
  boolean_T rtb_UnitDelay2;
  EnumALCA_state UnitDelay;
  EnumALCA_state alca_state;
  EnumDCSN_driving_direction req_side;
  EnumALCA_not_fulfill_reason not_fulfill_reason;
  EnumDCSN_driving_direction inform_side;
  ALCA_DcsnInfo BusCreator_gzdb;
  ALCA_VehState BusCreator1;
  ALCA_MPFU_Info BusCreator;
  boolean_T y;
  real32_T v_lon;

  /* SignalConversion: '<S1>/Signal Conversion6' incorporates:
   *  Inport: '<Root>/DCSN_DataBus'
   */
  VbALCA_ALCAEnableFromDCSN =
    VsDCSN_DataBus.EnablingFlags_Group.alca_feature_enable;

  /* If: '<S1>/If' */
  rtPrevAction = ALCA_subsystem_integrated_DW.If_ActiveSubsystem;
  rtAction = (int8_T)((!VbALCA_ALCAEnableFromDCSN) ? 1 : 0);
  ALCA_subsystem_integrated_DW.If_ActiveSubsystem = rtAction;
  switch (rtAction)
  {
   case 0:
    if (rtAction != rtPrevAction)
    {
      /* InitializeConditions for IfAction SubSystem: '<S1>/ALCA_Enabled' incorporates:
       *  ActionPort: '<S3>/Action Port'
       */
      /* InitializeConditions for If: '<S1>/If' incorporates:
       *  UnitDelay: '<S3>/Unit Delay'
       *  UnitDelay: '<S3>/Unit Delay1'
       *  UnitDelay: '<S3>/Unit Delay2'
       */
      ALCA_subsystem_integrated_DW.prev_state = ALCA_state_OFF;
      ALCA_subsystem_integrated_DW.reset_change_lane_req = false;
      ALCA_subsystem_integrated_DW.touched_new_lane = false;

      /* End of InitializeConditions for SubSystem: '<S1>/ALCA_Enabled' */

      /* SystemReset for IfAction SubSystem: '<S1>/ALCA_Enabled' incorporates:
       *  ActionPort: '<S3>/Action Port'
       */

      /* SystemReset for Atomic SubSystem: '<S3>/ALCA_InputDataProcess' */

      /* SystemReset for If: '<S1>/If' */
      ALC_ALCA_InputDataProcess_Reset();

      /* End of SystemReset for SubSystem: '<S3>/ALCA_InputDataProcess' */

      /* SystemReset for Atomic SubSystem: '<S3>/ALCA_CheckLCConditions' */
      AL_ALCA_CheckLCConditions_Reset();

      /* End of SystemReset for SubSystem: '<S3>/ALCA_CheckLCConditions' */

      /* SystemReset for Atomic SubSystem: '<S3>/ALCA_DtrmnALCAState' */
      ALCA__ALCA_DtrmnALCAState_Reset();

      /* End of SystemReset for SubSystem: '<S3>/ALCA_DtrmnALCAState' */

      /* SystemReset for Atomic SubSystem: '<S3>/ALCA_CalcLateralV ' */
      ALCA_su_ALCA_CalcLateralV_Reset();

      /* End of SystemReset for SubSystem: '<S3>/ALCA_CalcLateralV ' */

      /* End of SystemReset for SubSystem: '<S1>/ALCA_Enabled' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/ALCA_Enabled' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* DataStoreWrite: '<S11>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn1' incorporates:
     *  Constant: '<S11>/Constant1'
     */
    ALCA_subsystem_integrated_DW.KfALCA_d_LaneWidthMax_a3am =
      KfALCA_d_LaneWidthMax;

    /* DataStoreWrite: '<S11>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn2' incorporates:
     *  Constant: '<S11>/Constant2'
     */
    ALCA_subsystem_integrated_DW.KfALCA_d_TouchedNewLaneDis_lbrk =
      KfALCA_d_TouchedNewLaneDist;

    /* DataStoreWrite: '<S11>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn4' incorporates:
     *  Constant: '<S11>/Constant3'
     */
    ALCA_subsystem_integrated_DW.KfALCA_t_LaneChangeTimeMin_jj0b =
      KfALCA_t_LaneChangeTimeMin;

    /* DataStoreWrite: '<S11>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn3' incorporates:
     *  Constant: '<S11>/Constant4'
     */
    ALCA_subsystem_integrated_DW.KfALCA_d_EgoVehWidth_d0rj =
      KfALCA_d_EgoVehWidth;

    /* DataStoreWrite: '<S11>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn5' incorporates:
     *  Constant: '<S11>/Constant5'
     */
    ALCA_subsystem_integrated_DW.KfALCA_t_LaneChangeTimeMax_lff2 =
      KfALCA_t_LaneChangeTimeMax;

    /* DataStoreWrite: '<S11>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn6' incorporates:
     *  Constant: '<S11>/Constant6'
     */
    ALCA_subsystem_integrated_DW.KbALCA_UseNewAPI_Of_MPFU_jrss =
      KbALCA_UseNewAPI_Of_MPFU;

    /* UnitDelay: '<S3>/Unit Delay' */
    UnitDelay = ALCA_subsystem_integrated_DW.prev_state;

    /* UnitDelay: '<S3>/Unit Delay1' */
    rtb_UnitDelay1 = ALCA_subsystem_integrated_DW.reset_change_lane_req;

    /* UnitDelay: '<S3>/Unit Delay2' */
    rtb_UnitDelay2 = ALCA_subsystem_integrated_DW.touched_new_lane;

    /* Outputs for Atomic SubSystem: '<S3>/ALCA_InputDataProcess' */
    ALCA_subs_ALCA_InputDataProcess(rtb_UnitDelay1, UnitDelay, rtb_UnitDelay2,
      &BusCreator_gzdb, &BusCreator1, &Switch3, &BusCreator);

    /* End of Outputs for SubSystem: '<S3>/ALCA_InputDataProcess' */

    /* Outputs for Atomic SubSystem: '<S3>/ALCA_CheckLCConditions' */
    ALCA_sub_ALCA_CheckLCConditions(&BusCreator_gzdb, &BusCreator1, UnitDelay,
      Switch3, &BusCreator, &y, &inform_req, &not_fulfill_reason, &inform_side,
      &req_side, &VfALCA_d_Host2TargetLaneCenter, &v_lon);

    /* End of Outputs for SubSystem: '<S3>/ALCA_CheckLCConditions' */

    /* DataStoreWrite: '<S11>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn7' incorporates:
     *  Constant: '<S11>/Constant7'
     */
    ALCA_subsystem_integrated_DW.KbALCA_EnblOvrdInterruptAc_fnlg =
      KbALCA_EnblOvrdInterruptAction;

    /* Outputs for Atomic SubSystem: '<S3>/ALCA_DtrmnALCAState' */
    ALCA_subsys_ALCA_DtrmnALCAState(&BusCreator_gzdb, y, not_fulfill_reason,
      ALCA_subsystem_integrated_B.Logic[0],
      ALCA_subsystem_integrated_B.LogicalOperator3,
      ALCA_subsystem_integrated_B.Switch, &BusCreator1, &BusCreator,
      &rtb_Switch_b4ii, &alca_state, &VbALCA_ResetLaneChangeReq,
      &VfALCA_InterruptAction);

    /* End of Outputs for SubSystem: '<S3>/ALCA_DtrmnALCAState' */

    /* SignalConversion: '<S3>/Signal Conversion9' incorporates:
     *  Inport: '<Root>/LCCS_DataBus'
     */
    VfALCA_d_LateralDist2GoFromLCCS = VsLCCS_DataBus.lateral_dist_to_go;

    /* Outputs for Atomic SubSystem: '<S3>/ALCA_CalcLateralV ' */
    rtb_lateral_v_nm11 = (real32_T) ALCA_subsyste_ALCA_CalcLateralV
      (rtb_Switch_b4ii, v_lon);

    /* End of Outputs for SubSystem: '<S3>/ALCA_CalcLateralV ' */

    /* BusCreator: '<S9>/Bus Creator' */
    VsALCA_DataBus.state = alca_state;
    VsALCA_DataBus.request = rtb_Switch_b4ii;
    VsALCA_DataBus.request_side = req_side;
    VsALCA_DataBus.odd_not_fulfill_reason = not_fulfill_reason;
    VsALCA_DataBus.fault = Switch3;
    VsALCA_DataBus.interrupt = ALCA_subsystem_integrated_B.LogicalOperator3;
    VsALCA_DataBus.interrupt_type = ALCA_subsystem_integrated_B.Switch;
    VsALCA_DataBus.inform_request = inform_req;
    VsALCA_DataBus.inform_reason = ALCA_subsystem_integrate_ConstB.Constant1;
    VsALCA_DataBus.inform_side = inform_side;
    VsALCA_DataBus.lateral_v = rtb_lateral_v_nm11;

    /* Update for UnitDelay: '<S3>/Unit Delay' */
    ALCA_subsystem_integrated_DW.prev_state = alca_state;

    /* Update for UnitDelay: '<S3>/Unit Delay1' */
    ALCA_subsystem_integrated_DW.reset_change_lane_req =
      VbALCA_ResetLaneChangeReq;

    /* Update for UnitDelay: '<S3>/Unit Delay2' */
    ALCA_subsystem_integrated_DW.touched_new_lane =
      ALCA_subsystem_integrated_B.Logic[0];

    /* End of Outputs for SubSystem: '<S1>/ALCA_Enabled' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/ALCA_Default' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* BusCreator: '<S2>/Bus Creator' incorporates:
     *  Constant: '<S2>/Constant'
     *  Constant: '<S2>/Constant1'
     *  Constant: '<S2>/Constant3'
     *  Constant: '<S2>/Constant4'
     *  Constant: '<S2>/Constant5'
     *  Constant: '<S2>/Constant6'
     *  Constant: '<S2>/Constant7'
     *  Constant: '<S2>/Constant9'
     *  Constant: '<S4>/Constant'
     *  Constant: '<S5>/Constant'
     *  Constant: '<S6>/Constant'
     */
    VsALCA_DataBus.state = ALCA_state_OFF;
    VsALCA_DataBus.request = false;
    VsALCA_DataBus.request_side = FORWARD;
    VsALCA_DataBus.odd_not_fulfill_reason = ALCA_not_fulfill_reason_no_request;
    VsALCA_DataBus.fault = ((uint8_T)0U);
    VsALCA_DataBus.interrupt = false;
    VsALCA_DataBus.interrupt_type = ALCA_interrupt_type_no;
    VsALCA_DataBus.inform_request = false;
    VsALCA_DataBus.inform_reason = EnumALCA_inform_reason_no;
    VsALCA_DataBus.inform_side = FORWARD;
    VsALCA_DataBus.lateral_v = 0.0F;

    /* End of Outputs for SubSystem: '<S1>/ALCA_Default' */
    break;

   default:
    /* no actions */
    break;
  }

  /* End of If: '<S1>/If' */

  /* SignalConversion: '<S1>/Signal Conversion1' */
  VbALCA_RequestOutput = VsALCA_DataBus.request;

  /* SignalConversion: '<S1>/Signal Conversion2' */
  VeALCA_ReqSideOutput = VsALCA_DataBus.request_side;

  /* SignalConversion: '<S1>/Signal Conversion3' */
  VeALCA_NotFulfillReasonOutput = VsALCA_DataBus.odd_not_fulfill_reason;

  /* SignalConversion: '<S1>/Signal Conversion4' */
  VfALCA_FaultOutput = VsALCA_DataBus.fault;

  /* SignalConversion: '<S1>/Signal Conversion5' */
  VfALCA_v_LateralSpeedOutput = VsALCA_DataBus.lateral_v;

  /* SignalConversion: '<S1>/Signal Conversion7' */
  VfALCA_v_InterruptOutput = VsALCA_DataBus.interrupt;

  /* SignalConversion: '<S1>/Signal Conversion8' */
  VeALCA_StateOutput = VsALCA_DataBus.state;

  /* SignalConversion: '<S1>/Signal Conversion9' */
  VfALCA_v_InterruptTypeOutput = VsALCA_DataBus.interrupt_type;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
