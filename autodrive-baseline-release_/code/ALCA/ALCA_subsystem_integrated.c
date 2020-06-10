/*
 * File: ALCA_subsystem_integrated.c
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

#include "ALCA_subsystem_integrated.h"
#include "ALCA_subsystem_integrated_private.h"

const ALCA_DataBus ALCA_subsystem_integrated_rtZALCA_DataBus =
{
  ALCA_state_OFF,                      /* state */
  false,                               /* request */
  FORWARD,                             /* request_side */
  ALCA_not_fulfill_reason_no_request,  /* odd_not_fulfill_reason */
  0U,                                  /* fault */
  false,                               /* interrupt */
  ALCA_interrupt_type_no,              /* interrupt_type */
  false,                               /* inform_request */
  EnumALCA_inform_reason_accident_ahead,/* inform_reason */
  FORWARD,                             /* inform_side */
  0.0F                                 /* lateral_v */
} ;                                    /* ALCA_DataBus ground */

/* Exported block signals */
ALCA_DataBus VsALCA_DataBus;           /* '<S1>/Merge' */
real32_T VfALCA_v_LateralSpeedOutput;  /* '<S1>/Signal Conversion5'
                                        * ALCA outpurt.
                                        */
real32_T VfALCA_d_LateralDist2GoFromLCCS;/* '<S3>/Signal Conversion9'
                                          * Larteral distance to go from LCCS.
                                          */
real32_T VfALCA_RightLaneMarker_C0;    /* '<S52>/Signal Conversion22' */
real32_T VfALCA_RightLaneMarker_C1;    /* '<S52>/Signal Conversion23' */
real32_T VfALCA_RightLaneMarker_C2;    /* '<S52>/Signal Conversion24' */
real32_T VfALCA_RightLaneMarker_C3;    /* '<S52>/Signal Conversion25' */
real32_T VfALCA_RightDist2Host;        /* '<S52>/Signal Conversion26'
                                        * Distance-to-host of right lane marker.
                                        */
real32_T VfALCA_LeftLaneMarker_C0;     /* '<S52>/Signal Conversion14' */
real32_T VfALCA_LeftLaneMarker_C1;     /* '<S52>/Signal Conversion15' */
real32_T VfALCA_LeftLaneMarker_C2;     /* '<S52>/Signal Conversion16' */
real32_T VfALCA_LeftLaneMarker_C3;     /* '<S52>/Signal Conversion17' */
real32_T VfALCA_LeftDist2Host;         /* '<S52>/Signal Conversion18'
                                        * Distance-to-host of left lane marker.
                                        */
real32_T VfALCA_v_VehSpeed;            /* '<S49>/Switch'
                                        * Speed of ego veh.
                                        */
real32_T VfALCA_v_VehVx;               /* '<S49>/Signal Conversion1'
                                        * Speed of ego veh.
                                        */
real32_T VfALCA_v_VehVy;               /* '<S49>/Signal Conversion8'
                                        * Speed of ego veh.
                                        */
real32_T VfALCA_ObstacleNearest_x;     /* '<S21>/Signal Conversion1' */
real32_T VfALCA_ObstacleNearest_y;     /* '<S21>/Signal Conversion2' */
real32_T VfALCA_ObstacleCenter_x;      /* '<S21>/Signal Conversion3' */
real32_T VfALCA_v_Obstacle_Vx;         /* '<S21>/Signal Conversion4' */
real32_T VfALCA_v_Obstacle_Vy;         /* '<S21>/Signal Conversion5' */
real32_T VfALCA_ObstacleCenter_y;      /* '<S21>/Signal Conversion6' */
real32_T VfALCA_ObstacleLength;        /* '<S21>/Signal Conversion7' */
real32_T VfALCA_ObstacleWidth;         /* '<S21>/Signal Conversion8' */
real32_T VfALCA_ObstacleHeading;       /* '<S21>/Signal Conversion9' */
real32_T VfALCA_t_LCTime;              /* '<S8>/Switch' */
real32_T VfALCA_d_Host2TargetLaneCenter;/* '<S8>/CheckLCODD'
                                         * Distance of ost to target lane center.
                                         */
real32_T VfALCA_d_EGOLaneCenter2Host;  /* '<S8>/CheckLCComplete'
                                        * Distance of ost to ego lane center.
                                        */
real32_T VfALCA_d_TargetSideLaneMarker2Host;/* '<S8>/CheckLCComplete'
                                             * Distance of host to request-side-lane-marker.
                                             */
int32_T VfALCA_ObstacleID;             /* '<S21>/Signal Conversion10' */
int8_T VfALCA_RightLaneMarkerFusionStatus;/* '<S52>/Signal Conversion20'
                                           * Right Lane Marker`s Fusion Status
                                           */
int8_T VfALCA_RightLaneMarkerType;     /* '<S52>/Signal Conversion21'
                                        * Right Lane Marker`s  type
                                        */
int8_T VfALCA_LeftLaneMarkerFusionStatus;/* '<S52>/Signal Conversion12'
                                          * Left Lane Marker`s Fusion Status
                                          */
int8_T VfALCA_LeftLaneMarkerType;      /* '<S52>/Signal Conversion13'
                                        * Left Lane Marker`s type.
                                        */
uint8_T VfALCA_FaultOutput;            /* '<S1>/Signal Conversion4'
                                        * ALCA outpurt.
                                        */
uint8_T VfALCA_FaultInit;              /* '<S50>/Switch1'
                                        * Fault before outpurt.
                                        */
uint8_T VfALCA_InterruptAction;        /* '<S10>/ALCA_Dtrmn_interrupt_action'
                                        * Interrupt action.
                                        */
boolean_T VbALCA_ALCAEnableFromDCSN;   /* '<S1>/Signal Conversion6'
                                        * ALCA enable from Dcsn.
                                        */
boolean_T VbALCA_RequestOutput;        /* '<S1>/Signal Conversion1'
                                        * ALCA outpurt.
                                        */
boolean_T VfALCA_v_InterruptOutput;    /* '<S1>/Signal Conversion7' */
boolean_T VbALCA_LC_CancelReqFromDCSN; /* '<S47>/Signal Conversion1'
                                        * Lane change cancel request from DCSN.
                                        */
boolean_T VbALCA_LC_ReqFromDCSN;       /* '<S47>/Signal Conversion3'
                                        * Lane change from DCSN.
                                        */
boolean_T VbALCA_LC_Req;               /* '<S47>/Signal Conversion7'
                                        * Lane change from DCSN.
                                        */
boolean_T VbALCA_LC_CancelReq;         /* '<S47>/Signal Conversion9'
                                        * Lane change cancel request from DCSN.
                                        */
boolean_T VbALCA_ResetLaneChangeReq;   /* '<S10>/ALCA_StateFlow'
                                        * Reset lane change request from DCSN.
                                        */
boolean_T VbALCA_LC_Complete;          /* '<S8>/Logical Operator'
                                        * Lane change complete flag.
                                        */
boolean_T VbALCA_TouchedNewLane;       /* '<S8>/CheckLCComplete'
                                        * Has touched new lane.
                                        */
EnumDCSN_driving_direction VeALCA_ReqSideOutput;/* '<S1>/Signal Conversion2'
                                                 * ALCA outpurt.
                                                 */
EnumDCSN_driving_direction VeALCA_ReqSideFromDCSN;/* '<S47>/Signal Conversion2'
                                                   * Request side from DCSN.
                                                   */
EnumDCSN_driving_direction VeALCA_ReqSide;/* '<S47>/Signal Conversion8'
                                           * Request side from DCSN.
                                           */
EnumALCA_state VeALCA_StateOutput;     /* '<S1>/Signal Conversion8'
                                        * ALCA outpurt.
                                        */
EnumALCA_not_fulfill_reason VeALCA_NotFulfillReasonOutput;/* '<S1>/Signal Conversion3'
                                                           * ALCA outpurt.
                                                           */
EnumALCA_interrupt_type VfALCA_v_InterruptTypeOutput;/* '<S1>/Signal Conversion9' */

#pragma section ".cal"
/* Exported block parameters */
real32_T KaALCA_AXIS_LateralDist2Go[21] =
{
  0.0F, 0.2F, 0.4F, 0.6F, 0.8F, 1.0F, 1.2F, 1.4F, 1.6F, 1.8F, 2.0F, 2.2F, 2.4F,
  2.6F, 2.8F, 3.0F, 3.2F, 3.4F, 3.6F, 3.8F, 4.0F
} ;                                    /* Variable: KaALCA_AXIS_LateralDist2Go
                                        * Referenced by: '<S14>/1-D Lookup Table1'
                                        */

real32_T KaALCA_AXIS_RelativeSpeedHost2Obstacle[15] =
{
  -35.0F, -30.0F, -25.0F, -20.0F, -15.0F, -10.0F, -5.0F, 0.0F, 5.0F, 10.0F,
  15.0F, 20.0F, 25.0F, 30.0F, 35.0F
} ;                                    /* Variable: KaALCA_AXIS_RelativeSpeedHost2Obstacle
                                        * Referenced by:
                                        *   '<S8>/Constant6'
                                        *   '<S10>/Constant6'
                                        */

real32_T KaALCA_AXIS_VehLonSpeed[18] =
{
  0.0F, 2.0F, 4.0F, 6.0F, 8.0F, 10.0F, 12.0F, 14.0F, 16.0F, 18.0F, 20.0F, 22.0F,
  24.0F, 26.0F, 28.0F, 30.0F, 32.0F, 34.0F
} ;                                    /* Variable: KaALCA_AXIS_VehLonSpeed
                                        * Referenced by: '<S14>/1-D Lookup Table'
                                        */

real32_T KaALCA_AXIS_VehSpeed[8] =
{
  0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F
} ;                                    /* Variable: KaALCA_AXIS_VehSpeed
                                        * Referenced by:
                                        *   '<S8>/Constant7'
                                        *   '<S10>/Constant7'
                                        */

real32_T KfALCA_d_DefaultLaneLength = 60.0F;/* Variable: KfALCA_d_DefaultLaneLength
                                             * Referenced by:
                                             *   '<S8>/KfALCA_d_DefaultLaneLength'
                                             *   '<S15>/Constant8'
                                             */
real32_T KfALCA_d_Dist2LaneChangeFinish = 0.4F;/* Variable: KfALCA_d_Dist2LaneChangeFinish
                                                * Referenced by: '<S8>/Constant'
                                                * Max distance for determine lane change finished.
                                                */
real32_T KfALCA_d_EgoVehWheelBase = 3.2F;/* Variable: KfALCA_d_EgoVehWheelBase
                                          * Referenced by: '<S58>/Constant1'
                                          */
real32_T KfALCA_d_EgoVehWidth = 1.75F; /* Variable: KfALCA_d_EgoVehWidth
                                        * Referenced by:
                                        *   '<S3>/KfALCA_d_EgoVehWidth'
                                        *   '<S11>/Constant4'
                                        * The width of EGO.
                                        */
real32_T KfALCA_d_EnterSecondStageThrsh = 0.4F;/* Variable: KfALCA_d_EnterSecondStageThrsh
                                                * Referenced by: '<S7>/Constant1'
                                                */
real32_T KfALCA_d_LaneWidthMax = 3.75F;/* Variable: KfALCA_d_LaneWidthMax
                                        * Referenced by:
                                        *   '<S3>/KfALCA_d_LaneWidthMax'
                                        *   '<S11>/Constant1'
                                        * Max width of lane.
                                        */
real32_T KfALCA_d_TouchedNewLaneDist = 1.0F;/* Variable: KfALCA_d_TouchedNewLaneDist
                                             * Referenced by:
                                             *   '<S3>/KfALCA_d_TouchedNewLaneDist'
                                             *   '<S11>/Constant2'
                                             * Min jump distance for touched new lane.
                                             */
real32_T KfALCA_r_CoeffStrwhl2Radius = 2.0F;/* Variable: KfALCA_r_CoeffStrwhl2Radius
                                             * Referenced by: '<S58>/Constant6'
                                             */
real32_T KfALCA_r_ComfortableVRatio = 0.03F;/* Variable: KfALCA_r_ComfortableVRatio
                                             * Referenced by:
                                             *   '<S8>/KfALCA_r_ComfortableVRatio'
                                             *   '<S15>/Constant10'
                                             */
real32_T KfALCA_r_EgoVehStrwhl2FrtwhlRatio = 17.0F;/* Variable: KfALCA_r_EgoVehStrwhl2FrtwhlRatio
                                                    * Referenced by: '<S58>/Constant2'
                                                    */
real32_T KfALCA_r_EgoWidth2LaneWidthRation = 2.0F;/* Variable: KfALCA_r_EgoWidth2LaneWidthRation
                                                   * Referenced by:
                                                   *   '<S8>/KfALCA_r_EgoWidth2LaneWidthRation'
                                                   *   '<S15>/Constant6'
                                                   * Target lane width must > ego_veh_width * KfALCA_r_EgoWidth2LaneWidthRation.
                                                   */
real32_T KfALCA_r_OutputLarteralVRatioInterrupt = 0.2F;/* Variable: KfALCA_r_OutputLarteralVRatioInterrupt
                                                        * Referenced by: '<S14>/Constant7'
                                                        */
real32_T KfALCA_t_ExitFinishDelay = 0.3F;/* Variable: KfALCA_t_ExitFinishDelay
                                          * Referenced by: '<S10>/ALCA_StateFlow'
                                          * The time of wait for exit Finish state (Cooling time).
                                          */
real32_T KfALCA_t_ExitHandoverDelay = 10.0F;/* Variable: KfALCA_t_ExitHandoverDelay
                                             * Referenced by: '<S10>/ALCA_StateFlow'
                                             * The time of wait for exit Waitting state. ALCA will inform some info to driver In Waitting state.
                                             */
real32_T KfALCA_t_ExitWaitingDelay = 6.0F;/* Variable: KfALCA_t_ExitWaitingDelay
                                           * Referenced by: '<S10>/ALCA_StateFlow'
                                           * The time of wait for exit Waitting state. ALCA will inform some info to driver In Waitting state.
                                           */
real32_T KfALCA_t_HoldTimeForLCAccept = 0.2F;/* Variable: KfALCA_t_HoldTimeForLCAccept
                                              * Referenced by: '<S8>/Constant2'
                                              */
real32_T KfALCA_t_HoldTimeForLCComplete = 0.3F;/* Variable: KfALCA_t_HoldTimeForLCComplete
                                                * Referenced by: '<S8>/Constant1'
                                                */
real32_T KfALCA_t_LaneChangeTimeMax = 5.0F;/* Variable: KfALCA_t_LaneChangeTimeMax
                                            * Referenced by:
                                            *   '<S3>/KfALCA_t_LaneChangeTimeMax'
                                            *   '<S8>/Constant5'
                                            *   '<S11>/Constant5'
                                            * Max time of lane change (s).
                                            */
real32_T KfALCA_t_LaneChangeTimeMin = 3.0F;/* Variable: KfALCA_t_LaneChangeTimeMin
                                            * Referenced by:
                                            *   '<S3>/KfALCA_t_LaneChangeTimeMin'
                                            *   '<S11>/Constant3'
                                            * Min time of lane change (s).
                                            */
real32_T KfALCA_t_PeriodFunctionCall = 0.01F;/* Variable: KfALCA_t_PeriodFunctionCall
                                              * Referenced by: '<S10>/ALCA_StateFlow'
                                              * The time of Period-Function-Call.
                                              */
real32_T KfALCA_t_TimeNReceivedThrsh = 0.5F;/* Variable: KfALCA_t_TimeNReceivedThrsh
                                             * Referenced by:
                                             *   '<S50>/Constant2'
                                             *   '<S50>/Constant3'
                                             *   '<S50>/Constant6'
                                             * The threshold of time that not received OBFU/MPFU/EGMO data.
                                             */
real32_T KfALCA_t_WaitForDriverActionMax = 3.0F;/* Variable: KfALCA_t_WaitForDriverActionMax
                                                 * Referenced by: '<S10>/ALCA_StateFlow'
                                                 * The time of wait for driver`s commond in Inform state.
                                                 */
real32_T KfALCA_v_LateralSpeedOfSecondStage = 0.1F;/* Variable: KfALCA_v_LateralSpeedOfSecondStage
                                                    * Referenced by: '<S7>/Constant3'
                                                    */
real32_T KfALCA_v_SpeedLaneChangeEnblMax = 33.0F;/* Variable: KfALCA_v_SpeedLaneChangeEnblMax
                                                  * Referenced by:
                                                  *   '<S8>/KfALCA_v_SpeedLaneChangeEnblMax'
                                                  *   '<S15>/Constant1'
                                                  * The veh_speed threshold for lane change enable. (high)
                                                  */
real32_T KfALCA_v_SpeedLaneChangeEnblMin = 3.0F;/* Variable: KfALCA_v_SpeedLaneChangeEnblMin
                                                 * Referenced by:
                                                 *   '<S8>/KfALCA_v_SpeedLaneChangeEnblMin'
                                                 *   '<S15>/Constant2'
                                                 * The veh_speed threshold for lane change enable. (low)
                                                 */
real32_T KfAlCA_d_CheckObstacleDistMin = 8.0F;/* Variable: KfAlCA_d_CheckObstacleDistMin
                                               * Referenced by:
                                               *   '<S8>/KfAlCA_d_CheckObstacleDistMin'
                                               *   '<S15>/Constant4'
                                               * The min distance for checking obstacle.
                                               */
real32_T KtALCA_d_RangeFrontOfCheckObstacle[120] =
{
  60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 50.0F, 60.0F, 60.0F,
  60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 40.0F, 50.0F, 50.0F, 50.0F, 50.0F, 50.0F,
  50.0F, 50.0F, 30.0F, 40.0F, 40.0F, 40.0F, 40.0F, 40.0F, 40.0F, 40.0F, 20.0F,
  30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 15.0F, 20.0F, 20.0F, 20.0F,
  20.0F, 20.0F, 20.0F, 20.0F, 10.0F, 15.0F, 20.0F, 20.0F, 20.0F, 20.0F, 20.0F,
  20.0F, 8.0F, 10.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 8.0F, 8.0F,
  10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F,
  8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F,
  8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F,
  8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F,
  8.0F, 8.0F, 8.0F
} ;                                    /* Variable: KtALCA_d_RangeFrontOfCheckObstacle
                                        * Referenced by:
                                        *   '<S8>/Constant9'
                                        *   '<S10>/Constant9'
                                        * The front distance of checking obstacles.
                                        */

real32_T KtALCA_d_RangeRearOfCheckObstacle[120] =
{
  8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F,
  8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F,
  8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 10.0F, 10.0F, 10.0F, 10.0F,
  10.0F, 10.0F, 8.0F, 10.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 10.0F,
  15.0F, 20.0F, 20.0F, 20.0F, 20.0F, 20.0F, 20.0F, 15.0F, 20.0F, 20.0F, 20.0F,
  20.0F, 20.0F, 20.0F, 20.0F, 20.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F,
  30.0F, 30.0F, 40.0F, 40.0F, 40.0F, 40.0F, 40.0F, 40.0F, 40.0F, 40.0F, 50.0F,
  50.0F, 50.0F, 50.0F, 50.0F, 50.0F, 50.0F, 50.0F, 60.0F, 60.0F, 60.0F, 60.0F,
  60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F,
  60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F,
  60.0F, 60.0F, 60.0F, 60.0F, 60.0F
} ;                                    /* Variable: KtALCA_d_RangeRearOfCheckObstacle
                                        * Referenced by:
                                        *   '<S8>/Constant10'
                                        *   '<S10>/Constant10'
                                        * The rear distance of checking obstacles.
                                        */

real32_T KtALCA_r_LateralDist2LateralV[21] =
{
  0.0F, 0.0975F, 0.19F, 0.2775F, 0.36F, 0.4375F, 0.51F, 0.5775F, 0.64F, 0.6975F,
  0.75F, 0.7975F, 0.84F, 0.8775F, 0.91F, 0.9375F, 0.96F, 0.9775F, 0.99F, 0.9975F,
  1.0F
} ;                                    /* Variable: KtALCA_r_LateralDist2LateralV
                                        * Referenced by: '<S14>/1-D Lookup Table1'
                                        */

real32_T KtALCA_v_VComfortable2VLon[18] =
{
  0.0F, 0.16F, 0.32F, 0.48F, 0.64F, 0.8F, 0.96F, 1.12F, 1.2F, 1.2F, 1.2F, 1.2F,
  1.2F, 1.2F, 1.2F, 1.2F, 1.2F, 1.2F
} ;                                    /* Variable: KtALCA_v_VComfortable2VLon
                                        * Referenced by: '<S14>/1-D Lookup Table'
                                        */

boolean_T KbALCA_EnblCalibrateLateralSpeed = 1;/* Variable: KbALCA_EnblCalibrateLateralSpeed
                                                * Referenced by: '<S14>/Constant8'
                                                * Enable calibration lateral speed.
                                                */
boolean_T KbALCA_EnblCheckMPFUFusionStatus = 1;/* Variable: KbALCA_EnblCheckMPFUFusionStatus
                                                * Referenced by:
                                                *   '<S12>/KbALCA_EnblCheckMPFUFusionStatus'
                                                *   '<S51>/Constant5'
                                                * Enable check MPFU fusion status.
                                                */
boolean_T KbALCA_EnblCheckMPFULaneMarkerType = 1;/* Variable: KbALCA_EnblCheckMPFULaneMarkerType
                                                  * Referenced by:
                                                  *   '<S8>/KbALCA_EnblCheckMPFULaneMarkerType'
                                                  *   '<S15>/Constant3'
                                                  * Enable check MPFU lane marker type.
                                                  */
boolean_T KbALCA_EnblCheckObstacles = 1;/* Variable: KbALCA_EnblCheckObstacles
                                         * Referenced by:
                                         *   '<S8>/KbALCA_EnblCheckObstacles'
                                         *   '<S15>/Constant9'
                                         */
boolean_T KbALCA_EnblCheckTimestamp = 0;/* Variable: KbALCA_EnblCheckTimestamp
                                         * Referenced by: '<S12>/Constant1'
                                         * Enable check timestamp of MPFU/EGMO/OBFU.
                                         */
boolean_T KbALCA_EnblInterrupt = 1;    /* Variable: KbALCA_EnblInterrupt
                                        * Referenced by:
                                        *   '<S10>/KbALCA_EnblInterrupt'
                                        *   '<S10>/ALCA_StateFlow'
                                        *   '<S37>/Constant11'
                                        *   '<S47>/Constant6'
                                        * Enable interrupt.
                                        */
boolean_T KbALCA_EnblOvrdInterruptAction = 1;/* Variable: KbALCA_EnblOvrdInterruptAction
                                              * Referenced by:
                                              *   '<S3>/KbALCA_EnblOvrdInterruptAction'
                                              *   '<S11>/Constant7'
                                              * Enable ovrride interrupt action.
                                              */
boolean_T KbALCA_EnblOvrdLaneLength = 0;/* Variable: KbALCA_EnblOvrdLaneLength
                                         * Referenced by:
                                         *   '<S8>/KbALCA_EnblOvrdLaneLength'
                                         *   '<S15>/Constant7'
                                         */
boolean_T KbALCA_EnblOvrdLaneWidth = 0;/* Variable: KbALCA_EnblOvrdLaneWidth
                                        * Referenced by:
                                        *   '<S8>/KbALCA_EnblOvrdLaneWidth'
                                        *   '<S15>/Constant11'
                                        */
boolean_T KbALCA_OvrdLaneChangeTime = 0;/* Variable: KbALCA_OvrdLaneChangeTime
                                         * Referenced by: '<S8>/Constant4'
                                         */
boolean_T KbALCA_UseNewAPI_Of_MPFU = 0;/* Variable: KbALCA_UseNewAPI_Of_MPFU
                                        * Referenced by:
                                        *   '<S3>/KbALCA_UseNewAPI_Of_MPFU'
                                        *   '<S11>/Constant6'
                                        */
#pragma section
/* Exported block states */
real32_T VfALCA_TargetLaneLength;      /* Simulink.Signal object 'VfALCA_TargetLaneLength' */
real32_T VfALCA_TargetLaneWidth;       /* Simulink.Signal object 'VfALCA_TargetLaneWidth' */
real32_T VfALCA_d_EGOLaneLength;       /* Simulink.Signal object 'VfALCA_d_EGOLaneLength'
                                        * Length of ego lane.
                                        */
real32_T VfALCA_d_EGOLaneWidth;        /* Simulink.Signal object 'VfALCA_d_EGOLaneWidth'
                                        * Width of ego lane.
                                        */
real32_T VfALCA_v_VehLonSpeed2LaneMarker;/* Simulink.Signal object 'VfALCA_v_VehLonSpeed2LaneMarker' */
uint16_T VfALCA_ObstacleNum;           /* Simulink.Signal object 'VfALCA_ObstacleNum'
                                        * The number of obstacles.
                                        */
int8_T VfALCA_TargetLaneType;          /* Simulink.Signal object 'VfALCA_TargetLaneType' */
int8_T VfALCA_TargetSideLaneMarkerType;/* Simulink.Signal object 'VfALCA_TargetSideLaneMarkerType' */
boolean_T VfALCA_HasLeftLane;          /* Simulink.Signal object 'VfALCA_HasLeftLane'
                                        * Has left lane.
                                        */
boolean_T VfALCA_HasRightLane;         /* Simulink.Signal object 'VfALCA_HasRightLane'
                                        * Has right lane.
                                        */

/* Block signals (auto storage) */
B_ALCA_subsystem_integrated_T ALCA_subsystem_integrated_B;

/* Block states (auto storage) */
DW_ALCA_subsystem_integrated_T ALCA_subsystem_integrated_DW;

/* Model step function */
void ALCA_subsystem_integrated_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/ALCA' */
  ALCA_subsystem_integrated_ALCA();

  /* End of Outputs for SubSystem: '<Root>/ALCA' */
}

/* Model initialize function */
void ALCA_subsystem_integrated_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &ALCA_subsystem_integrated_B), 0,
                sizeof(B_ALCA_subsystem_integrated_T));

  {
    ALCA_subsystem_integrated_B.Switch = ALCA_interrupt_type_no;
  }

  /* exported global signals */
  VsALCA_DataBus = ALCA_subsystem_integrated_rtZALCA_DataBus;
  VfALCA_v_LateralSpeedOutput = 0.0F;
  VfALCA_d_LateralDist2GoFromLCCS = 0.0F;
  VfALCA_RightLaneMarker_C0 = 0.0F;
  VfALCA_RightLaneMarker_C1 = 0.0F;
  VfALCA_RightLaneMarker_C2 = 0.0F;
  VfALCA_RightLaneMarker_C3 = 0.0F;
  VfALCA_RightDist2Host = 0.0F;
  VfALCA_LeftLaneMarker_C0 = 0.0F;
  VfALCA_LeftLaneMarker_C1 = 0.0F;
  VfALCA_LeftLaneMarker_C2 = 0.0F;
  VfALCA_LeftLaneMarker_C3 = 0.0F;
  VfALCA_LeftDist2Host = 0.0F;
  VfALCA_v_VehSpeed = 0.0F;
  VfALCA_v_VehVx = 0.0F;
  VfALCA_v_VehVy = 0.0F;
  VfALCA_ObstacleNearest_x = 0.0F;
  VfALCA_ObstacleNearest_y = 0.0F;
  VfALCA_ObstacleCenter_x = 0.0F;
  VfALCA_v_Obstacle_Vx = 0.0F;
  VfALCA_v_Obstacle_Vy = 0.0F;
  VfALCA_ObstacleCenter_y = 0.0F;
  VfALCA_ObstacleLength = 0.0F;
  VfALCA_ObstacleWidth = 0.0F;
  VfALCA_ObstacleHeading = 0.0F;
  VfALCA_t_LCTime = 0.0F;
  VfALCA_d_Host2TargetLaneCenter = 0.0F;
  VfALCA_d_EGOLaneCenter2Host = 0.0F;
  VfALCA_d_TargetSideLaneMarker2Host = 0.0F;
  VfALCA_ObstacleID = 0;
  VfALCA_RightLaneMarkerFusionStatus = 0;
  VfALCA_RightLaneMarkerType = 0;
  VfALCA_LeftLaneMarkerFusionStatus = 0;
  VfALCA_LeftLaneMarkerType = 0;
  VfALCA_FaultOutput = 0U;
  VfALCA_FaultInit = 0U;
  VfALCA_InterruptAction = 0U;
  VbALCA_ALCAEnableFromDCSN = false;
  VbALCA_RequestOutput = false;
  VfALCA_v_InterruptOutput = false;
  VbALCA_LC_CancelReqFromDCSN = false;
  VbALCA_LC_ReqFromDCSN = false;
  VbALCA_LC_Req = false;
  VbALCA_LC_CancelReq = false;
  VbALCA_ResetLaneChangeReq = false;
  VbALCA_LC_Complete = false;
  VbALCA_TouchedNewLane = false;
  VeALCA_ReqSideOutput = FORWARD;
  VeALCA_ReqSideFromDCSN = FORWARD;
  VeALCA_ReqSide = FORWARD;
  VeALCA_StateOutput = ALCA_state_OFF;
  VeALCA_NotFulfillReasonOutput = ALCA_not_fulfill_reason_no_request;
  VfALCA_v_InterruptTypeOutput = ALCA_interrupt_type_no;

  /* states (dwork) */
  (void) memset((void *)&ALCA_subsystem_integrated_DW, 0,
                sizeof(DW_ALCA_subsystem_integrated_T));

  /* exported global states */
  VfALCA_TargetLaneLength = 0.0F;
  VfALCA_TargetLaneWidth = 0.0F;
  VfALCA_d_EGOLaneLength = 0.0F;
  VfALCA_d_EGOLaneWidth = 0.0F;
  VfALCA_v_VehLonSpeed2LaneMarker = 0.0F;
  VfALCA_ObstacleNum = 0U;
  VfALCA_TargetLaneType = 0;
  VfALCA_TargetSideLaneMarkerType = 0;
  VfALCA_HasLeftLane = false;
  VfALCA_HasRightLane = false;

  /* Machine initializer */
  ALCA_subsystem_integrated_DW.data = 0.0;

  /* Start for Atomic SubSystem: '<Root>/ALCA' */
  ALCA_subsystem_integ_ALCA_Start();

  /* End of Start for SubSystem: '<Root>/ALCA' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/ALCA' */
  ALCA_subsystem_integr_ALCA_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/ALCA' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
