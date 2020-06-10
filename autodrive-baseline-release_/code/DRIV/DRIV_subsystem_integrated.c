/*
 * File: DRIV_subsystem_integrated.c
 *
 * Code generated for Simulink model 'DRIV_subsystem_integrated'.
 *
 * Model version                  : 1.1200
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Jun 10 08:50:22 2020
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

#include "DRIV_subsystem_integrated.h"
#include "DRIV_subsystem_integrated_private.h"

const DRIV_DataBus DRIV_subsystem_integrated_rtZDRIV_DataBus =
{
  {
    false,                             /* VbDIRV_Override_Steering */
    LeftLC_NOT,                        /* VeDRIV_LeftChangeLane */
    RightLC_NOT,                       /* VeDRIV_RightChangeLane */
    false                              /* VbDRIV_LaneKeepAssist */
  },                                   /* OverrideSteer */

  {
    false,                             /* VbDRIV_EnableAutoDrive */
    false,                             /* VbLCC_ButtonActivate */
    false                              /* VbACC_ButtonActivate */
  },                                   /* OverrideButton */
  DRIV_DriverDozeoff,                  /* VeDRIV_DriverStatus */
  false,                               /* VbDRIV_ModeStatus */

  {
    false,                             /* VbDRIV_ACCMainSwitch */
    false,                             /* VbDRIV_ACCResumeSwitch */
    false,                             /* VbDRIV_ACCCancelSwitch */
    0.0F,                              /* VfDRIV_ACCDriveSetSpeed */
    0U                                 /* VfDRIV_ACCTimeGap */
  }                                    /* DRIV_ACCS_Switch */
} ;                                    /* DRIV_DataBus ground */

/* Exported block signals */
DRIV_DataBus VsDRIV_DataBus;           /* '<S4>/Bus Creator' */
real32_T VfDRIV_Steer_Torque_Rate;     /* '<S79>/Divide1' */
real32_T VfDRIV_yawrate;               /* '<S52>/Signal Conversion2' */
real32_T VfDRIV_c1_heading;            /* '<S53>/DtrmnLCParameter' */
real32_T VfDRIV_ACCDriveSetSpeed;      /* '<S30>/DtrmnDRIV_TargetSpeed'
                                        * Driver set target speed(Consider with speed up/down switch)
                                        */
real32_T VfDRIV_steer_angle;           /* '<S3>/Signal Conversion2' */
real32_T VfDRIV_SteerAngleRate;        /* '<S9>/Divide' */
real32_T VfDRIV_Steer_Torque_Filter;   /* '<S8>/Add' */
uint8_T VfDRIV_ACCTimeGap;             /* '<S37>/Saturation'
                                        * Driver set time gap
                                        */
boolean_T VbDRIV_Norm_driving;         /* '<S79>/Logical Operator1' */
boolean_T VbDRIV_Driver_Take_Over;     /* '<S81>/Logical Operator4' */
boolean_T VbDRIV_Driver_Distracted;    /* '<S80>/Logical Operator5' */
boolean_T VbDIRV_Override_Steering;    /* '<S49>/Logical Operator2' */
boolean_T VbDRIV_LeftSide_LC_Req;      /* '<S56>/Logical Operator1' */
boolean_T VbDRIV_RightSide_LC_Req;     /* '<S56>/Logical Operator2' */
boolean_T VbDRIV_LaneChangeReady_Req;  /* '<S65>/Signal Conversion2' */
boolean_T VbDRIV_LaneChanging_Req;     /* '<S65>/Signal Conversion3' */
boolean_T VbDRIV_LaneChangeFinish_Req; /* '<S65>/Signal Conversion4' */
boolean_T VbDRIV_LC_Enable;            /* '<S52>/Logical Operator3' */
boolean_T VbDRIV_TurnType;             /* '<S55>/Relational Operator1' */
boolean_T VbDRIV_Update_Override_Steering;/* '<S75>/Signal Conversion3' */
boolean_T VbDRIV_LaneKeepAssist;       /* '<S54>/DRIV_Status' */
boolean_T VbDRIV_Touched_new_lane;     /* '<S53>/DtrmnLCParameter' */
boolean_T VbDRIV_ACCResumeSwitch;      /* '<S30>/SwitchDebounce2'
                                        * ACC resume switch status
                                        */
boolean_T VbDRIV_ACCCancelSwitch;      /* '<S30>/SwitchDebounce1'
                                        * ACC cancel switch status
                                        */
boolean_T VbDRIV_ACCMainSwitch;        /* '<S30>/ACC_MainSwitch'
                                        * ACC main switch status
                                        */
EnumDRIV_LeftChangeLane VeDRIV_LeftChangeLane;/* '<S54>/DRIV_Status' */
EnumDRIV_RightChangeLane VeDRIV_RightChangeLane;/* '<S54>/DRIV_Status' */

/* Exported block parameters */
#pragma section ".cal"
real32_T KfACCS_t_SwitchLongPressThrsh = 2.0F;/* Variable: KfACCS_t_SwitchLongPressThrsh
                                               * Referenced by: '<S30>/DtrmnDRIV_TargetSpeed'
                                               * As press resume/set switch timer bigge than this calibration,tap up step will use KfACCS_v_TapUpDeltaLongPress
                                               */
real32_T KfACCS_v_TapDownDelta = 0.28F;/* Variable: KfACCS_v_TapDownDelta
                                        * Referenced by: '<S30>/DtrmnDRIV_TargetSpeed'
                                        * Tap down delta as press speed down switch
                                        */
real32_T KfACCS_v_TapDownDeltaLongPress = 0.83F;/* Variable: KfACCS_v_TapDownDeltaLongPress
                                                 * Referenced by: '<S30>/DtrmnDRIV_TargetSpeed'
                                                 * As press set switch timer bigge than KfACCS_t_SwitchLongPressThrsh,tap down step will use this calbiration
                                                 */
real32_T KfACCS_v_TapUpDelta = 0.28F;  /* Variable: KfACCS_v_TapUpDelta
                                        * Referenced by: '<S30>/DtrmnDRIV_TargetSpeed'
                                        * Tap up delta as press speed up switch
                                        */
real32_T KfACCS_v_TapUpDeltaLongPress = 0.83F;/* Variable: KfACCS_v_TapUpDeltaLongPress
                                               * Referenced by: '<S30>/DtrmnDRIV_TargetSpeed'
                                               * As press resume switch timer bigge than KfACCS_t_SwitchLongPressThrsh,tap up step will use this calibration
                                               */
real32_T KfDRIV_CoeffStrwhl2Radius = 2.0F;/* Variable: KfDRIV_CoeffStrwhl2Radius
                                           * Referenced by: '<S10>/Constant6'
                                           * When there's no EGMO, steer wheel angle is used to calculate Radius,
                                             Coefficent correction of radius.
                                           */
real32_T KfDRIV_Veh_Strwhl2FrtwhlRatio = 17.0F;/* Variable: KfDRIV_Veh_Strwhl2FrtwhlRatio
                                                * Referenced by: '<S10>/Constant2'
                                                * steer ratio =17
                                                */
real32_T KfDRIV_Veh_WheelBase = 3.2F;  /* Variable: KfDRIV_Veh_WheelBase
                                        * Referenced by: '<S10>/Constant1'
                                        * wheel base
                                        */
real32_T KfDRIV_d_Dist2LaneChangeFinish = 0.4F;/* Variable: KfDRIV_d_Dist2LaneChangeFinish
                                                * Referenced by: '<S61>/Constant5'
                                                * to lane_center distance < 0.4
                                                */
real32_T KfDRIV_d_TouchedNewLaneDist = 2.0F;/* Variable: KfDRIV_d_TouchedNewLaneDist
                                             * Referenced by:
                                             *   '<S48>/KfDRIV_d_TouchedNewLaneDist'
                                             *   '<S48>/Constant8'
                                             * when vehicle touched new lane ,the distance to lane can increase in one sample time
                                             */
real32_T KfDRIV_t_TimeEGMOReceivedThrsh = 4.0F;/* Variable: KfDRIV_t_TimeEGMOReceivedThrsh
                                                * Referenced by: '<S7>/Constant2'
                                                * TimeEGMOReceivedThrsh
                                                */
real32_T KfDRIV_t_TimeMPFUReceivedThrsh = 4.0F;/* Variable: KfDRIV_t_TimeMPFUReceivedThrsh
                                                * Referenced by: '<S7>/Constant8'
                                                * TimeMPFUReceivedThrsh
                                                */
real32_T KfDRIV_t_TimeOBFUNReceivedThrsh = 4.0F;/* Variable: KfDRIV_t_TimeOBFUNReceivedThrsh
                                                 * Referenced by: '<S7>/Constant7'
                                                 * TimeOBFUNReceivedThrsh
                                                 */
real32_T KfDRIV_t_WaitTimeDriverDistracted = 2.0F;/* Variable: KfDRIV_t_WaitTimeDriverDistracted
                                                   * Referenced by: '<S80>/Constant10'
                                                   * WaitTimeDriverDistracted
                                                   */
real32_T KfDRIV_t_WaitTimeLaneChangeFinish = 0.5F;/* Variable: KfDRIV_t_WaitTimeLaneChangeFinish
                                                   * Referenced by: '<S61>/Constant1'
                                                   * WaitTimeLaneChangeFinish
                                                   */
real32_T KfDRIV_w_LaneWidthMax = 3.5F; /* Variable: KfDRIV_w_LaneWidthMax
                                        * Referenced by:
                                        *   '<S48>/Data Store Memory'
                                        *   '<S48>/Constant5'
                                        * LaneWidthMax
                                        */
real32_T kfDRIV_M_TorqueOverrideThreshold = 0.3F;/* Variable: kfDRIV_M_TorqueOverrideThreshold
                                                  * Referenced by: '<S79>/Constant1'
                                                  * steer torque threshold
                                                  */
real32_T kfDRIV_M_TorqueOverrideThreshold_ACC = 3.0F;/* Variable: kfDRIV_M_TorqueOverrideThreshold_ACC
                                                      * Referenced by: '<S81>/Constant7'
                                                      * steer torque threshold ACC
                                                      */
real32_T kfDRIV_M_TorqueOverrideThreshold_Auto = 0.3F;/* Variable: kfDRIV_M_TorqueOverrideThreshold_Auto
                                                       * Referenced by: '<S80>/Constant8'
                                                       * TorqueOverrideThreshold_Auto
                                                       */
real32_T kfDRIV_M_TorqueOverrideThreshold_LCC = 3.0F;/* Variable: kfDRIV_M_TorqueOverrideThreshold_LCC
                                                      * Referenced by: '<S81>/Constant8'
                                                      * TorqueOverrideThreshold LCC driver  take over
                                                      */
real32_T kfDRIV_M_TorqueThreshold_Distracted = 0.3F;/* Variable: kfDRIV_M_TorqueThreshold_Distracted
                                                     * Referenced by: '<S80>/Constant1'
                                                     */
real32_T kfDRIV_SteerAngleRateThreshold = 0.1F;/* Variable: kfDRIV_SteerAngleRateThreshold
                                                * Referenced by: '<S63>/Constant7'
                                                * SteerAngleRateThreshold
                                                */
real32_T kfDRIV_SteerAngleThreshold = 0.1F;/* Variable: kfDRIV_SteerAngleThreshold
                                            * Referenced by:
                                            *   '<S56>/Constant1'
                                            *   '<S56>/Constant9'
                                            */
real32_T kfDRIV_TorqueRateThreshold = 0.0F;/* Variable: kfDRIV_TorqueRateThreshold
                                            * Referenced by: '<S79>/Constant6'
                                            * TorqueRateThreshold
                                            */
real32_T kfDRIV_TorqueRate_LC_Threshold = 0.1F;/* Variable: kfDRIV_TorqueRate_LC_Threshold
                                                * Referenced by: '<S63>/Constant9'
                                                * TorqueRate_LC_Threshold
                                                */
real32_T kfDRIV_YawRateThreshold = 0.01F;/* Variable: kfDRIV_YawRateThreshold
                                          * Referenced by: '<S63>/Constant4'
                                          * YawRateThreshold
                                          */
real32_T kfDRIV_YawRateThreshold2 = 0.1F;/* Variable: kfDRIV_YawRateThreshold2
                                          * Referenced by: '<S62>/Constant9'
                                          * YawRateThreshold2
                                          */
real32_T kfDRIV_c1_threshold = 0.1F;   /* Variable: kfDRIV_c1_threshold
                                        * Referenced by: '<S62>/Constant2'
                                        * Lane Coefficient c1
                                        */
real32_T kfDRIV_k_FilterGain = 0.9F;   /* Variable: kfDRIV_k_FilterGain
                                        * Referenced by: '<S8>/Constant2'
                                        * steer torque  filter gain 0.9
                                        */
real32_T kfDRIV_t_PeriodFunctionCall = 0.01F;/* Variable: kfDRIV_t_PeriodFunctionCall
                                              * Referenced by:
                                              *   '<S9>/Constant'
                                              *   '<S28>/Constant1'
                                              *   '<S28>/Constant3'
                                              *   '<S28>/Constant6'
                                              *   '<S79>/Constant'
                                              *   '<S63>/Constant3'
                                              * model  sample time
                                              */
real32_T kfDRIV_t_TurnLightLeftOn_Time = 1.0F;/* Variable: kfDRIV_t_TurnLightLeftOn_Time
                                               * Referenced by: '<S56>/Constant12'
                                               * TurnLightLeftOn_Time
                                               */
real32_T kfDRIV_t_TurnLightOn_Time = 1.0F;/* Variable: kfDRIV_t_TurnLightOn_Time
                                           * Referenced by: '<S63>/Constant12'
                                           * TurnLightOn_Time
                                           */
real32_T kfDRIV_t_TurnLightRightOn_Time = 1.0F;/* Variable: kfDRIV_t_TurnLightRightOn_Time
                                                * Referenced by: '<S56>/Constant5'
                                                * TurnLightRightOn_Time
                                                */
uint8_T KcDRIV_ACCSCancelSwitchDebounceThrsh = 20U;/* Variable: KcDRIV_ACCSCancelSwitchDebounceThrsh
                                                    * Referenced by: '<S30>/Constant12'
                                                    * ACCS cancel switch debounce thresh.
                                                    */
uint8_T KcDRIV_ACCSMainSwitchDebounceThrsh = 20U;/* Variable: KcDRIV_ACCSMainSwitchDebounceThrsh
                                                  * Referenced by: '<S30>/Constant11'
                                                  * ACCS main switch debounce thresh.
                                                  */
uint8_T KcDRIV_ACCSResumeSwitchDebounceThrsh = 20U;/* Variable: KcDRIV_ACCSResumeSwitchDebounceThrsh
                                                    * Referenced by: '<S30>/Constant13'
                                                    * ACCS resume switch debounce thresh.
                                                    */
uint8_T KcDRIV_ACCSSetSwitchDebounceThrsh = 20U;/* Variable: KcDRIV_ACCSSetSwitchDebounceThrsh
                                                 * Referenced by: '<S30>/Constant14'
                                                 * ACCS set switch debounce thresh.
                                                 */
uint8_T KcDRIV_ACCSTimeGapMinusDebounceThrsh = 20U;/* Variable: KcDRIV_ACCSTimeGapMinusDebounceThrsh
                                                    * Referenced by: '<S30>/Constant16'
                                                    * ACCS time gap minus switch debounce thresh.
                                                    */
uint8_T KcDRIV_ACCSTimeGapPlusDebounceThrsh = 20U;/* Variable: KcDRIV_ACCSTimeGapPlusDebounceThrsh
                                                   * Referenced by: '<S30>/Constant15'
                                                   * ACCS time gap plus switch debounce thresh.
                                                   */
uint8_T kfDRIV_DelayLoopGain = 5U;     /* Variable: kfDRIV_DelayLoopGain
                                        * Referenced by:
                                        *   '<S28>/Constant2'
                                        *   '<S28>/Constant4'
                                        *   '<S28>/Constant7'
                                        * button delay loop gain
                                        */
boolean_T KbDRIV_DRIVEnable = 1;       /* Variable: KbDRIV_DRIVEnable
                                        * Referenced by: '<S4>/Constant'
                                        * DRIV mode status is true
                                        */
boolean_T KbDRIV_Default_EnableAutoDrive = 0;/* Variable: KbDRIV_Default_EnableAutoDrive
                                              * Referenced by: '<S5>/Constant5'
                                              * Default auto drive is false
                                              */
boolean_T KbDRIV_Default_LaneKeepAssist = 1;/* Variable: KbDRIV_Default_LaneKeepAssist
                                             * Referenced by: '<S51>/Constant2'
                                             * default vehicle is lanekeeping
                                             */
boolean_T KbDRIV_Default_Override_Steering = 0;/* Variable: KbDRIV_Default_Override_Steering
                                                * Referenced by: '<S51>/Constant1'
                                                * default override steering  status is false
                                                */
boolean_T KbDRIV_Update_Override_Steering = 1;/* Variable: KbDRIV_Update_Override_Steering
                                               * Referenced by: '<S75>/Constant1'
                                               * update override steering status is true
                                               */
#pragma section 
/* Block signals (auto storage) */
B_DRIV_subsystem_integrated_T DRIV_subsystem_integrated_B;

/* Block states (auto storage) */
DW_DRIV_subsystem_integrated_T DRIV_subsystem_integrated_DW;

/* Model step function */
void DRIV_subsystem_integrated_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/DRIV ' */
  DRIV_subsystem_integrated_DRIV();

  /* End of Outputs for SubSystem: '<Root>/DRIV ' */
}

/* Model initialize function */
void DRIV_subsystem_integrated_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &DRIV_subsystem_integrated_B), 0,
                sizeof(B_DRIV_subsystem_integrated_T));

  {
    DRIV_subsystem_integrated_B.SignalConversion = ACCS_mode_off;
  }

  /* exported global signals */
  VsDRIV_DataBus = DRIV_subsystem_integrated_rtZDRIV_DataBus;
  VfDRIV_Steer_Torque_Rate = 0.0F;
  VfDRIV_yawrate = 0.0F;
  VfDRIV_c1_heading = 0.0F;
  VfDRIV_ACCDriveSetSpeed = 0.0F;
  VfDRIV_steer_angle = 0.0F;
  VfDRIV_SteerAngleRate = 0.0F;
  VfDRIV_Steer_Torque_Filter = 0.0F;
  VfDRIV_ACCTimeGap = 0U;
  VbDRIV_Norm_driving = false;
  VbDRIV_Driver_Take_Over = false;
  VbDRIV_Driver_Distracted = false;
  VbDIRV_Override_Steering = false;
  VbDRIV_LeftSide_LC_Req = false;
  VbDRIV_RightSide_LC_Req = false;
  VbDRIV_LaneChangeReady_Req = false;
  VbDRIV_LaneChanging_Req = false;
  VbDRIV_LaneChangeFinish_Req = false;
  VbDRIV_LC_Enable = false;
  VbDRIV_TurnType = false;
  VbDRIV_Update_Override_Steering = false;
  VbDRIV_LaneKeepAssist = false;
  VbDRIV_Touched_new_lane = false;
  VbDRIV_ACCResumeSwitch = false;
  VbDRIV_ACCCancelSwitch = false;
  VbDRIV_ACCMainSwitch = false;
  VeDRIV_LeftChangeLane = LeftLC_NOT;
  VeDRIV_RightChangeLane = RightLC_NOT;

  /* states (dwork) */
  (void) memset((void *)&DRIV_subsystem_integrated_DW, 0,
                sizeof(DW_DRIV_subsystem_integrated_T));

  /* Start for Atomic SubSystem: '<Root>/DRIV ' */
  DRIV_subsystem_integ_DRIV_Start();

  /* End of Start for SubSystem: '<Root>/DRIV ' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/DRIV ' */
  DRIV_subsystem_integr_DRIV_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/DRIV ' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
