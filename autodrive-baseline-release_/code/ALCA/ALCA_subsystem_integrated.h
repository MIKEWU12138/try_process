/*
 * File: ALCA_subsystem_integrated.h
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

#ifndef RTW_HEADER_ALCA_subsystem_integrated_h_
#define RTW_HEADER_ALCA_subsystem_integrated_h_
#include <string.h>
#ifndef ALCA_subsystem_integrated_COMMON_INCLUDES_
# define ALCA_subsystem_integrated_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* ALCA_subsystem_integrated_COMMON_INCLUDES_ */

#include "ALCA_subsystem_integrated_types.h"

/* Child system includes */
#include "ALCA.h"

/* Macros for accessing real-time model data structure */

/* Block signals (auto storage) */
typedef struct
{
  boolean_T Logic[2];                  /* '<S24>/Logic' */
  boolean_T LogicalOperator3;          /* '<S20>/Logical Operator3' */
  EnumALCA_interrupt_type Switch;      /* '<S20>/Switch' */
}
B_ALCA_subsystem_integrated_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct
{
  real_T data;
  real32_T pre_distance_to_host;       /* '<S8>/Unit Delay' */
  real32_T pre_lateral_v;              /* '<S14>/Unit Delay3' */
  uint32_T pre_egmo_timeStamp;         /* '<S50>/Unit Delay1' */
  uint32_T pre_mpfu_timeStamp;         /* '<S50>/Unit Delay2' */
  uint32_T pre_obfu_timeStamp;         /* '<S50>/Unit Delay' */
  real32_T KfALCA_d_EgoVehWidth_d0rj;  /* '<S3>/KfALCA_d_EgoVehWidth' */
  real32_T KfALCA_d_LaneWidthMax_a3am; /* '<S3>/KfALCA_d_LaneWidthMax' */
  real32_T KfALCA_d_TouchedNewLaneDis_lbrk;/* '<S3>/KfALCA_d_TouchedNewLaneDist' */
  real32_T KfALCA_t_LaneChangeTimeMax_lff2;/* '<S3>/KfALCA_t_LaneChangeTimeMax' */
  real32_T KfALCA_t_LaneChangeTimeMin_jj0b;/* '<S3>/KfALCA_t_LaneChangeTimeMin' */
  real32_T KbALCA_EnblCheckMPFUFusionStatu;/* '<S12>/KbALCA_EnblCheckMPFUFusionStatus' */
  real32_T time_wait;                  /* '<S10>/ALCA_StateFlow' */
  real32_T KfALCA_d_DefaultLaneLength_pz0k;/* '<S8>/KfALCA_d_DefaultLaneLength' */
  real32_T KfALCA_r_ComfortableVRatio_ldnz;/* '<S8>/KfALCA_r_ComfortableVRatio' */
  real32_T KfALCA_r_EgoWidth2LaneWidthRati;/* '<S8>/KfALCA_r_EgoWidth2LaneWidthRation' */
  real32_T KfALCA_v_SpeedLaneChangeEn_g0ux;/* '<S8>/KfALCA_v_SpeedLaneChangeEnblMax' */
  real32_T KfALCA_v_SpeedLaneChangeEn_hgzb;/* '<S8>/KfALCA_v_SpeedLaneChangeEnblMin' */
  real32_T KfAlCA_d_CheckObstacleDist_aqcl;/* '<S8>/KfAlCA_d_CheckObstacleDistMin' */
  boolean_T reset_change_lane_req;     /* '<S3>/Unit Delay1' */
  boolean_T touched_new_lane;          /* '<S3>/Unit Delay2' */
  boolean_T pre_lc_complete;           /* '<S8>/Unit Delay1' */
  EnumDCSN_driving_direction change_lane_req_side;/* '<S47>/Unit Delay' */
  EnumALCA_state prev_state;           /* '<S3>/Unit Delay' */
  int8_T If_ActiveSubsystem;           /* '<S1>/If' */
  uint8_T is_active_c1_ALCA_subsystem_int;/* '<S10>/ALCA_StateFlow' */
  uint8_T is_c1_ALCA_subsystem_integrated;/* '<S10>/ALCA_StateFlow' */
  uint8_T is_ON;                       /* '<S10>/ALCA_StateFlow' */
  boolean_T KbALCA_EnblOvrdInterruptAc_fnlg;/* '<S3>/KbALCA_EnblOvrdInterruptAction' */
  boolean_T KbALCA_UseNewAPI_Of_MPFU_jrss;/* '<S3>/KbALCA_UseNewAPI_Of_MPFU' */
  boolean_T Memory_PreviousInput;      /* '<S57>/Memory' */
  boolean_T Memory_PreviousInput_h3op; /* '<S56>/Memory' */
  boolean_T KbALCA_EnblInterrupt_hmoa; /* '<S10>/KbALCA_EnblInterrupt' */
  boolean_T Memory_PreviousInput_kxhj; /* '<S24>/Memory' */
  boolean_T KbALCA_EnblCheckMPFULaneMarkerT;/* '<S8>/KbALCA_EnblCheckMPFULaneMarkerType' */
  boolean_T KbALCA_EnblCheckObstacles_odv1;/* '<S8>/KbALCA_EnblCheckObstacles' */
  boolean_T KbALCA_EnblOvrdLaneLength_mu5k;/* '<S8>/KbALCA_EnblOvrdLaneLength' */
  boolean_T KbALCA_EnblOvrdLaneWidth_czwz;/* '<S8>/KbALCA_EnblOvrdLaneWidth' */
  DW_Chart_ALCA_subsystem_integ_T sf_Chart_acqd;/* '<S67>/Chart' */
  DW_Chart_ALCA_subsystem_integ_T sf_Chart_gygf;/* '<S66>/Chart' */
  DW_Chart_ALCA_subsystem_integ_T sf_Chart_i2is;/* '<S65>/Chart' */
  DW_Chart_ALCA_subsystem_integ_T sf_Chart_hv4o;/* '<S23>/Chart' */
  DW_Chart_ALCA_subsystem_integ_T sf_Chart;/* '<S22>/Chart' */
}
DW_ALCA_subsystem_integrated_T;

/* Invariant block signals (auto storage) */
typedef struct
{
  const uint8_T DataTypeConversion1;   /* '<S50>/Data Type Conversion1' */
  const uint8_T DataTypeConversion4;   /* '<S50>/Data Type Conversion4' */
  const uint8_T DataTypeConversion3;   /* '<S50>/Data Type Conversion3' */
  const uint8_T BitwiseOperator3;      /* '<S50>/Bitwise Operator3' */
  const uint8_T DataTypeConversion;    /* '<S49>/Data Type Conversion' */
  const EnumALCA_inform_reason Constant1;/* '<S19>/Constant1' */
}
ConstB_ALCA_subsystem_integra_T;

/* Constant parameters (auto storage) */
typedef struct
{
  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S24>/Logic'
   *   '<S56>/Logic'
   *   '<S57>/Logic'
   */
  boolean_T pooled8[16];
}
ConstP_ALCA_subsystem_integra_T;

/* Block signals (auto storage) */
extern B_ALCA_subsystem_integrated_T ALCA_subsystem_integrated_B;

/* Block states (auto storage) */
extern DW_ALCA_subsystem_integrated_T ALCA_subsystem_integrated_DW;

/* External data declarations for dependent source files */
extern const ALCA_DataBus ALCA_subsystem_integrated_rtZALCA_DataBus;/* ALCA_DataBus ground */
extern const ConstB_ALCA_subsystem_integra_T ALCA_subsystem_integrate_ConstB;/* constant block i/o */

/* Constant parameters (auto storage) */
extern const ConstP_ALCA_subsystem_integra_T ALCA_subsystem_integrate_ConstP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern ALCA_DataBus VsALCA_DataBus;    /* '<S1>/Merge' */
extern real32_T VfALCA_v_LateralSpeedOutput;/* '<S1>/Signal Conversion5'
                                             * ALCA outpurt.
                                             */
extern real32_T VfALCA_d_LateralDist2GoFromLCCS;/* '<S3>/Signal Conversion9'
                                                 * Larteral distance to go from LCCS.
                                                 */
extern real32_T VfALCA_RightLaneMarker_C0;/* '<S52>/Signal Conversion22' */
extern real32_T VfALCA_RightLaneMarker_C1;/* '<S52>/Signal Conversion23' */
extern real32_T VfALCA_RightLaneMarker_C2;/* '<S52>/Signal Conversion24' */
extern real32_T VfALCA_RightLaneMarker_C3;/* '<S52>/Signal Conversion25' */
extern real32_T VfALCA_RightDist2Host; /* '<S52>/Signal Conversion26'
                                        * Distance-to-host of right lane marker.
                                        */
extern real32_T VfALCA_LeftLaneMarker_C0;/* '<S52>/Signal Conversion14' */
extern real32_T VfALCA_LeftLaneMarker_C1;/* '<S52>/Signal Conversion15' */
extern real32_T VfALCA_LeftLaneMarker_C2;/* '<S52>/Signal Conversion16' */
extern real32_T VfALCA_LeftLaneMarker_C3;/* '<S52>/Signal Conversion17' */
extern real32_T VfALCA_LeftDist2Host;  /* '<S52>/Signal Conversion18'
                                        * Distance-to-host of left lane marker.
                                        */
extern real32_T VfALCA_v_VehSpeed;     /* '<S49>/Switch'
                                        * Speed of ego veh.
                                        */
extern real32_T VfALCA_v_VehVx;        /* '<S49>/Signal Conversion1'
                                        * Speed of ego veh.
                                        */
extern real32_T VfALCA_v_VehVy;        /* '<S49>/Signal Conversion8'
                                        * Speed of ego veh.
                                        */
extern real32_T VfALCA_ObstacleNearest_x;/* '<S21>/Signal Conversion1' */
extern real32_T VfALCA_ObstacleNearest_y;/* '<S21>/Signal Conversion2' */
extern real32_T VfALCA_ObstacleCenter_x;/* '<S21>/Signal Conversion3' */
extern real32_T VfALCA_v_Obstacle_Vx;  /* '<S21>/Signal Conversion4' */
extern real32_T VfALCA_v_Obstacle_Vy;  /* '<S21>/Signal Conversion5' */
extern real32_T VfALCA_ObstacleCenter_y;/* '<S21>/Signal Conversion6' */
extern real32_T VfALCA_ObstacleLength; /* '<S21>/Signal Conversion7' */
extern real32_T VfALCA_ObstacleWidth;  /* '<S21>/Signal Conversion8' */
extern real32_T VfALCA_ObstacleHeading;/* '<S21>/Signal Conversion9' */
extern real32_T VfALCA_t_LCTime;       /* '<S8>/Switch' */
extern real32_T VfALCA_d_Host2TargetLaneCenter;/* '<S8>/CheckLCODD'
                                                * Distance of ost to target lane center.
                                                */
extern real32_T VfALCA_d_EGOLaneCenter2Host;/* '<S8>/CheckLCComplete'
                                             * Distance of ost to ego lane center.
                                             */
extern real32_T VfALCA_d_TargetSideLaneMarker2Host;/* '<S8>/CheckLCComplete'
                                                    * Distance of host to request-side-lane-marker.
                                                    */
extern int32_T VfALCA_ObstacleID;      /* '<S21>/Signal Conversion10' */
extern int8_T VfALCA_RightLaneMarkerFusionStatus;/* '<S52>/Signal Conversion20'
                                                  * Right Lane Marker`s Fusion Status
                                                  */
extern int8_T VfALCA_RightLaneMarkerType;/* '<S52>/Signal Conversion21'
                                          * Right Lane Marker`s  type
                                          */
extern int8_T VfALCA_LeftLaneMarkerFusionStatus;/* '<S52>/Signal Conversion12'
                                                 * Left Lane Marker`s Fusion Status
                                                 */
extern int8_T VfALCA_LeftLaneMarkerType;/* '<S52>/Signal Conversion13'
                                         * Left Lane Marker`s type.
                                         */
extern uint8_T VfALCA_FaultOutput;     /* '<S1>/Signal Conversion4'
                                        * ALCA outpurt.
                                        */
extern uint8_T VfALCA_FaultInit;       /* '<S50>/Switch1'
                                        * Fault before outpurt.
                                        */
extern uint8_T VfALCA_InterruptAction; /* '<S10>/ALCA_Dtrmn_interrupt_action'
                                        * Interrupt action.
                                        */
extern boolean_T VbALCA_ALCAEnableFromDCSN;/* '<S1>/Signal Conversion6'
                                            * ALCA enable from Dcsn.
                                            */
extern boolean_T VbALCA_RequestOutput; /* '<S1>/Signal Conversion1'
                                        * ALCA outpurt.
                                        */
extern boolean_T VfALCA_v_InterruptOutput;/* '<S1>/Signal Conversion7' */
extern boolean_T VbALCA_LC_CancelReqFromDCSN;/* '<S47>/Signal Conversion1'
                                              * Lane change cancel request from DCSN.
                                              */
extern boolean_T VbALCA_LC_ReqFromDCSN;/* '<S47>/Signal Conversion3'
                                        * Lane change from DCSN.
                                        */
extern boolean_T VbALCA_LC_Req;        /* '<S47>/Signal Conversion7'
                                        * Lane change from DCSN.
                                        */
extern boolean_T VbALCA_LC_CancelReq;  /* '<S47>/Signal Conversion9'
                                        * Lane change cancel request from DCSN.
                                        */
extern boolean_T VbALCA_ResetLaneChangeReq;/* '<S10>/ALCA_StateFlow'
                                            * Reset lane change request from DCSN.
                                            */
extern boolean_T VbALCA_LC_Complete;   /* '<S8>/Logical Operator'
                                        * Lane change complete flag.
                                        */
extern boolean_T VbALCA_TouchedNewLane;/* '<S8>/CheckLCComplete'
                                        * Has touched new lane.
                                        */
extern EnumDCSN_driving_direction VeALCA_ReqSideOutput;/* '<S1>/Signal Conversion2'
                                                        * ALCA outpurt.
                                                        */
extern EnumDCSN_driving_direction VeALCA_ReqSideFromDCSN;/* '<S47>/Signal Conversion2'
                                                          * Request side from DCSN.
                                                          */
extern EnumDCSN_driving_direction VeALCA_ReqSide;/* '<S47>/Signal Conversion8'
                                                  * Request side from DCSN.
                                                  */
extern EnumALCA_state VeALCA_StateOutput;/* '<S1>/Signal Conversion8'
                                          * ALCA outpurt.
                                          */
extern EnumALCA_not_fulfill_reason VeALCA_NotFulfillReasonOutput;/* '<S1>/Signal Conversion3'
                                                                  * ALCA outpurt.
                                                                  */
extern EnumALCA_interrupt_type VfALCA_v_InterruptTypeOutput;/* '<S1>/Signal Conversion9' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T KaALCA_AXIS_LateralDist2Go[21];/* Variable: KaALCA_AXIS_LateralDist2Go
                                                * Referenced by: '<S14>/1-D Lookup Table1'
                                                */
extern real32_T KaALCA_AXIS_RelativeSpeedHost2Obstacle[15];/* Variable: KaALCA_AXIS_RelativeSpeedHost2Obstacle
                                                            * Referenced by:
                                                            *   '<S8>/Constant6'
                                                            *   '<S10>/Constant6'
                                                            */
extern real32_T KaALCA_AXIS_VehLonSpeed[18];/* Variable: KaALCA_AXIS_VehLonSpeed
                                             * Referenced by: '<S14>/1-D Lookup Table'
                                             */
extern real32_T KaALCA_AXIS_VehSpeed[8];/* Variable: KaALCA_AXIS_VehSpeed
                                         * Referenced by:
                                         *   '<S8>/Constant7'
                                         *   '<S10>/Constant7'
                                         */
extern real32_T KfALCA_d_DefaultLaneLength;/* Variable: KfALCA_d_DefaultLaneLength
                                            * Referenced by:
                                            *   '<S8>/KfALCA_d_DefaultLaneLength'
                                            *   '<S15>/Constant8'
                                            */
extern real32_T KfALCA_d_Dist2LaneChangeFinish;/* Variable: KfALCA_d_Dist2LaneChangeFinish
                                                * Referenced by: '<S8>/Constant'
                                                * Max distance for determine lane change finished.
                                                */
extern real32_T KfALCA_d_EgoVehWheelBase;/* Variable: KfALCA_d_EgoVehWheelBase
                                          * Referenced by: '<S58>/Constant1'
                                          */
extern real32_T KfALCA_d_EgoVehWidth;  /* Variable: KfALCA_d_EgoVehWidth
                                        * Referenced by:
                                        *   '<S3>/KfALCA_d_EgoVehWidth'
                                        *   '<S11>/Constant4'
                                        * The width of EGO.
                                        */
extern real32_T KfALCA_d_EnterSecondStageThrsh;/* Variable: KfALCA_d_EnterSecondStageThrsh
                                                * Referenced by: '<S7>/Constant1'
                                                */
extern real32_T KfALCA_d_LaneWidthMax; /* Variable: KfALCA_d_LaneWidthMax
                                        * Referenced by:
                                        *   '<S3>/KfALCA_d_LaneWidthMax'
                                        *   '<S11>/Constant1'
                                        * Max width of lane.
                                        */
extern real32_T KfALCA_d_TouchedNewLaneDist;/* Variable: KfALCA_d_TouchedNewLaneDist
                                             * Referenced by:
                                             *   '<S3>/KfALCA_d_TouchedNewLaneDist'
                                             *   '<S11>/Constant2'
                                             * Min jump distance for touched new lane.
                                             */
extern real32_T KfALCA_r_CoeffStrwhl2Radius;/* Variable: KfALCA_r_CoeffStrwhl2Radius
                                             * Referenced by: '<S58>/Constant6'
                                             */
extern real32_T KfALCA_r_ComfortableVRatio;/* Variable: KfALCA_r_ComfortableVRatio
                                            * Referenced by:
                                            *   '<S8>/KfALCA_r_ComfortableVRatio'
                                            *   '<S15>/Constant10'
                                            */
extern real32_T KfALCA_r_EgoVehStrwhl2FrtwhlRatio;/* Variable: KfALCA_r_EgoVehStrwhl2FrtwhlRatio
                                                   * Referenced by: '<S58>/Constant2'
                                                   */
extern real32_T KfALCA_r_EgoWidth2LaneWidthRation;/* Variable: KfALCA_r_EgoWidth2LaneWidthRation
                                                   * Referenced by:
                                                   *   '<S8>/KfALCA_r_EgoWidth2LaneWidthRation'
                                                   *   '<S15>/Constant6'
                                                   * Target lane width must > ego_veh_width * KfALCA_r_EgoWidth2LaneWidthRation.
                                                   */
extern real32_T KfALCA_r_OutputLarteralVRatioInterrupt;/* Variable: KfALCA_r_OutputLarteralVRatioInterrupt
                                                        * Referenced by: '<S14>/Constant7'
                                                        */
extern real32_T KfALCA_t_ExitFinishDelay;/* Variable: KfALCA_t_ExitFinishDelay
                                          * Referenced by: '<S10>/ALCA_StateFlow'
                                          * The time of wait for exit Finish state (Cooling time).
                                          */
extern real32_T KfALCA_t_ExitHandoverDelay;/* Variable: KfALCA_t_ExitHandoverDelay
                                            * Referenced by: '<S10>/ALCA_StateFlow'
                                            * The time of wait for exit Waitting state. ALCA will inform some info to driver In Waitting state.
                                            */
extern real32_T KfALCA_t_ExitWaitingDelay;/* Variable: KfALCA_t_ExitWaitingDelay
                                           * Referenced by: '<S10>/ALCA_StateFlow'
                                           * The time of wait for exit Waitting state. ALCA will inform some info to driver In Waitting state.
                                           */
extern real32_T KfALCA_t_HoldTimeForLCAccept;/* Variable: KfALCA_t_HoldTimeForLCAccept
                                              * Referenced by: '<S8>/Constant2'
                                              */
extern real32_T KfALCA_t_HoldTimeForLCComplete;/* Variable: KfALCA_t_HoldTimeForLCComplete
                                                * Referenced by: '<S8>/Constant1'
                                                */
extern real32_T KfALCA_t_LaneChangeTimeMax;/* Variable: KfALCA_t_LaneChangeTimeMax
                                            * Referenced by:
                                            *   '<S3>/KfALCA_t_LaneChangeTimeMax'
                                            *   '<S8>/Constant5'
                                            *   '<S11>/Constant5'
                                            * Max time of lane change (s).
                                            */
extern real32_T KfALCA_t_LaneChangeTimeMin;/* Variable: KfALCA_t_LaneChangeTimeMin
                                            * Referenced by:
                                            *   '<S3>/KfALCA_t_LaneChangeTimeMin'
                                            *   '<S11>/Constant3'
                                            * Min time of lane change (s).
                                            */
extern real32_T KfALCA_t_PeriodFunctionCall;/* Variable: KfALCA_t_PeriodFunctionCall
                                             * Referenced by: '<S10>/ALCA_StateFlow'
                                             * The time of Period-Function-Call.
                                             */
extern real32_T KfALCA_t_TimeNReceivedThrsh;/* Variable: KfALCA_t_TimeNReceivedThrsh
                                             * Referenced by:
                                             *   '<S50>/Constant2'
                                             *   '<S50>/Constant3'
                                             *   '<S50>/Constant6'
                                             * The threshold of time that not received OBFU/MPFU/EGMO data.
                                             */
extern real32_T KfALCA_t_WaitForDriverActionMax;/* Variable: KfALCA_t_WaitForDriverActionMax
                                                 * Referenced by: '<S10>/ALCA_StateFlow'
                                                 * The time of wait for driver`s commond in Inform state.
                                                 */
extern real32_T KfALCA_v_LateralSpeedOfSecondStage;/* Variable: KfALCA_v_LateralSpeedOfSecondStage
                                                    * Referenced by: '<S7>/Constant3'
                                                    */
extern real32_T KfALCA_v_SpeedLaneChangeEnblMax;/* Variable: KfALCA_v_SpeedLaneChangeEnblMax
                                                 * Referenced by:
                                                 *   '<S8>/KfALCA_v_SpeedLaneChangeEnblMax'
                                                 *   '<S15>/Constant1'
                                                 * The veh_speed threshold for lane change enable. (high)
                                                 */
extern real32_T KfALCA_v_SpeedLaneChangeEnblMin;/* Variable: KfALCA_v_SpeedLaneChangeEnblMin
                                                 * Referenced by:
                                                 *   '<S8>/KfALCA_v_SpeedLaneChangeEnblMin'
                                                 *   '<S15>/Constant2'
                                                 * The veh_speed threshold for lane change enable. (low)
                                                 */
extern real32_T KfAlCA_d_CheckObstacleDistMin;/* Variable: KfAlCA_d_CheckObstacleDistMin
                                               * Referenced by:
                                               *   '<S8>/KfAlCA_d_CheckObstacleDistMin'
                                               *   '<S15>/Constant4'
                                               * The min distance for checking obstacle.
                                               */
extern real32_T KtALCA_d_RangeFrontOfCheckObstacle[120];/* Variable: KtALCA_d_RangeFrontOfCheckObstacle
                                                         * Referenced by:
                                                         *   '<S8>/Constant9'
                                                         *   '<S10>/Constant9'
                                                         * The front distance of checking obstacles.
                                                         */
extern real32_T KtALCA_d_RangeRearOfCheckObstacle[120];/* Variable: KtALCA_d_RangeRearOfCheckObstacle
                                                        * Referenced by:
                                                        *   '<S8>/Constant10'
                                                        *   '<S10>/Constant10'
                                                        * The rear distance of checking obstacles.
                                                        */
extern real32_T KtALCA_r_LateralDist2LateralV[21];/* Variable: KtALCA_r_LateralDist2LateralV
                                                   * Referenced by: '<S14>/1-D Lookup Table1'
                                                   */
extern real32_T KtALCA_v_VComfortable2VLon[18];/* Variable: KtALCA_v_VComfortable2VLon
                                                * Referenced by: '<S14>/1-D Lookup Table'
                                                */
extern boolean_T KbALCA_EnblCalibrateLateralSpeed;/* Variable: KbALCA_EnblCalibrateLateralSpeed
                                                   * Referenced by: '<S14>/Constant8'
                                                   * Enable calibration lateral speed.
                                                   */
extern boolean_T KbALCA_EnblCheckMPFUFusionStatus;/* Variable: KbALCA_EnblCheckMPFUFusionStatus
                                                   * Referenced by:
                                                   *   '<S12>/KbALCA_EnblCheckMPFUFusionStatus'
                                                   *   '<S51>/Constant5'
                                                   * Enable check MPFU fusion status.
                                                   */
extern boolean_T KbALCA_EnblCheckMPFULaneMarkerType;/* Variable: KbALCA_EnblCheckMPFULaneMarkerType
                                                     * Referenced by:
                                                     *   '<S8>/KbALCA_EnblCheckMPFULaneMarkerType'
                                                     *   '<S15>/Constant3'
                                                     * Enable check MPFU lane marker type.
                                                     */
extern boolean_T KbALCA_EnblCheckObstacles;/* Variable: KbALCA_EnblCheckObstacles
                                            * Referenced by:
                                            *   '<S8>/KbALCA_EnblCheckObstacles'
                                            *   '<S15>/Constant9'
                                            */
extern boolean_T KbALCA_EnblCheckTimestamp;/* Variable: KbALCA_EnblCheckTimestamp
                                            * Referenced by: '<S12>/Constant1'
                                            * Enable check timestamp of MPFU/EGMO/OBFU.
                                            */
extern boolean_T KbALCA_EnblInterrupt; /* Variable: KbALCA_EnblInterrupt
                                        * Referenced by:
                                        *   '<S10>/KbALCA_EnblInterrupt'
                                        *   '<S10>/ALCA_StateFlow'
                                        *   '<S37>/Constant11'
                                        *   '<S47>/Constant6'
                                        * Enable interrupt.
                                        */
extern boolean_T KbALCA_EnblOvrdInterruptAction;/* Variable: KbALCA_EnblOvrdInterruptAction
                                                 * Referenced by:
                                                 *   '<S3>/KbALCA_EnblOvrdInterruptAction'
                                                 *   '<S11>/Constant7'
                                                 * Enable ovrride interrupt action.
                                                 */
extern boolean_T KbALCA_EnblOvrdLaneLength;/* Variable: KbALCA_EnblOvrdLaneLength
                                            * Referenced by:
                                            *   '<S8>/KbALCA_EnblOvrdLaneLength'
                                            *   '<S15>/Constant7'
                                            */
extern boolean_T KbALCA_EnblOvrdLaneWidth;/* Variable: KbALCA_EnblOvrdLaneWidth
                                           * Referenced by:
                                           *   '<S8>/KbALCA_EnblOvrdLaneWidth'
                                           *   '<S15>/Constant11'
                                           */
extern boolean_T KbALCA_OvrdLaneChangeTime;/* Variable: KbALCA_OvrdLaneChangeTime
                                            * Referenced by: '<S8>/Constant4'
                                            */
extern boolean_T KbALCA_UseNewAPI_Of_MPFU;/* Variable: KbALCA_UseNewAPI_Of_MPFU
                                           * Referenced by:
                                           *   '<S3>/KbALCA_UseNewAPI_Of_MPFU'
                                           *   '<S11>/Constant6'
                                           */

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern real32_T VfALCA_TargetLaneLength;/* Simulink.Signal object 'VfALCA_TargetLaneLength' */
extern real32_T VfALCA_TargetLaneWidth;/* Simulink.Signal object 'VfALCA_TargetLaneWidth' */
extern real32_T VfALCA_d_EGOLaneLength;/* Simulink.Signal object 'VfALCA_d_EGOLaneLength'
                                        * Length of ego lane.
                                        */
extern real32_T VfALCA_d_EGOLaneWidth; /* Simulink.Signal object 'VfALCA_d_EGOLaneWidth'
                                        * Width of ego lane.
                                        */
extern real32_T VfALCA_v_VehLonSpeed2LaneMarker;/* Simulink.Signal object 'VfALCA_v_VehLonSpeed2LaneMarker' */
extern uint16_T VfALCA_ObstacleNum;    /* Simulink.Signal object 'VfALCA_ObstacleNum'
                                        * The number of obstacles.
                                        */
extern int8_T VfALCA_TargetLaneType;   /* Simulink.Signal object 'VfALCA_TargetLaneType' */
extern int8_T VfALCA_TargetSideLaneMarkerType;/* Simulink.Signal object 'VfALCA_TargetSideLaneMarkerType' */
extern boolean_T VfALCA_HasLeftLane;   /* Simulink.Signal object 'VfALCA_HasLeftLane'
                                        * Has left lane.
                                        */
extern boolean_T VfALCA_HasRightLane;  /* Simulink.Signal object 'VfALCA_HasRightLane'
                                        * Has right lane.
                                        */

/* Model entry point functions */
extern void ALCA_subsystem_integrated_initialize(void);
extern void ALCA_subsystem_integrated_step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ALCA_subsystem_integrated'
 * '<S1>'   : 'ALCA_subsystem_integrated/ALCA'
 * '<S2>'   : 'ALCA_subsystem_integrated/ALCA/ALCA_Default'
 * '<S3>'   : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled'
 * '<S4>'   : 'ALCA_subsystem_integrated/ALCA/ALCA_Default/Enumerated Constant'
 * '<S5>'   : 'ALCA_subsystem_integrated/ALCA/ALCA_Default/Enumerated Constant1'
 * '<S6>'   : 'ALCA_subsystem_integrated/ALCA/ALCA_Default/Enumerated Constant2'
 * '<S7>'   : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CalcLateralV '
 * '<S8>'   : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CheckLCConditions'
 * '<S9>'   : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_DtrmnALCAData'
 * '<S10>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_DtrmnALCAState'
 * '<S11>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_Init_global'
 * '<S12>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess'
 * '<S13>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CalcLateralV /CalcLateralV_1'
 * '<S14>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CalcLateralV /CalcLateralV_2'
 * '<S15>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CheckLCConditions/ALCA_Init_global3'
 * '<S16>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CheckLCConditions/CheckCompleteEnbl'
 * '<S17>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CheckLCConditions/CheckLCComplete'
 * '<S18>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CheckLCConditions/CheckLCODD'
 * '<S19>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CheckLCConditions/DtrmnLCInform'
 * '<S20>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CheckLCConditions/DtrmnLCInterrupt'
 * '<S21>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CheckLCConditions/MonitorOBFU'
 * '<S22>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CheckLCConditions/RaisingEdgeDelay'
 * '<S23>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CheckLCConditions/RaisingEdgeDelay1'
 * '<S24>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CheckLCConditions/SetResetFlipFlop'
 * '<S25>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CheckLCConditions/CheckCompleteEnbl/Enumerated Constant'
 * '<S26>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CheckLCConditions/DtrmnLCInterrupt/Enumerated Constant'
 * '<S27>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CheckLCConditions/DtrmnLCInterrupt/Enumerated Constant1'
 * '<S28>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CheckLCConditions/DtrmnLCInterrupt/Enumerated Constant2'
 * '<S29>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CheckLCConditions/DtrmnLCInterrupt/Enumerated Constant3'
 * '<S30>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CheckLCConditions/DtrmnLCInterrupt/Enumerated Constant4'
 * '<S31>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CheckLCConditions/DtrmnLCInterrupt/Enumerated Constant5'
 * '<S32>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CheckLCConditions/RaisingEdgeDelay/Chart'
 * '<S33>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_CheckLCConditions/RaisingEdgeDelay1/Chart'
 * '<S34>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_DtrmnALCAState/ALCA_DtrmnReq'
 * '<S35>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_DtrmnALCAState/ALCA_DtrmnWait'
 * '<S36>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_DtrmnALCAState/ALCA_Dtrmn_interrupt_action'
 * '<S37>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_DtrmnALCAState/ALCA_Init_global4'
 * '<S38>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_DtrmnALCAState/ALCA_StateFlow'
 * '<S39>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_DtrmnALCAState/ALCA_DtrmnWait/Enumerated Constant1'
 * '<S40>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_DtrmnALCAState/ALCA_DtrmnWait/Enumerated Constant10'
 * '<S41>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_DtrmnALCAState/ALCA_DtrmnWait/Enumerated Constant3'
 * '<S42>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_DtrmnALCAState/ALCA_DtrmnWait/Enumerated Constant4'
 * '<S43>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_DtrmnALCAState/ALCA_DtrmnWait/Enumerated Constant5'
 * '<S44>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_DtrmnALCAState/ALCA_DtrmnWait/Enumerated Constant6'
 * '<S45>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_DtrmnALCAState/ALCA_DtrmnWait/Enumerated Constant7'
 * '<S46>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_DtrmnALCAState/ALCA_DtrmnWait/Enumerated Constant8'
 * '<S47>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_Dtrm_dcsn_info'
 * '<S48>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_Dtrm_mpfu_info'
 * '<S49>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_Dtrm_veh_state'
 * '<S50>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_FaultDetection'
 * '<S51>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_Init_global2'
 * '<S52>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_MPFU_Montior'
 * '<S53>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_Dtrm_dcsn_info/Enumerated Constant'
 * '<S54>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_Dtrm_dcsn_info/Enumerated Constant1'
 * '<S55>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_Dtrm_dcsn_info/Enumerated Constant2'
 * '<S56>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_Dtrm_dcsn_info/SetResetFlipFlop'
 * '<S57>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_Dtrm_dcsn_info/SetResetFlipFlop1'
 * '<S58>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_Dtrm_veh_state/ALCA_adc_path_prediction'
 * '<S59>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_Dtrm_veh_state/ALCA_veh_FedBck_update'
 * '<S60>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_Dtrm_veh_state/ALCA_adc_path_prediction/evidezero'
 * '<S61>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_Dtrm_veh_state/ALCA_adc_path_prediction/evidezero1'
 * '<S62>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_Dtrm_veh_state/ALCA_adc_path_prediction/evidezero/DividByZero'
 * '<S63>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_Dtrm_veh_state/ALCA_adc_path_prediction/evidezero1/DividByZero'
 * '<S64>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_Dtrm_veh_state/ALCA_veh_FedBck_update/Init_veh_FedBck'
 * '<S65>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_FaultDetection/RaisingEdgeDelay'
 * '<S66>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_FaultDetection/RaisingEdgeDelay1'
 * '<S67>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_FaultDetection/RaisingEdgeDelay2'
 * '<S68>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_FaultDetection/RaisingEdgeDelay/Chart'
 * '<S69>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_FaultDetection/RaisingEdgeDelay1/Chart'
 * '<S70>'  : 'ALCA_subsystem_integrated/ALCA/ALCA_Enabled/ALCA_InputDataProcess/ALCA_FaultDetection/RaisingEdgeDelay2/Chart'
 */
#endif                                 /* RTW_HEADER_ALCA_subsystem_integrated_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
