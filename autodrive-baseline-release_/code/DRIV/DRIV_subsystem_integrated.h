/*
 * File: DRIV_subsystem_integrated.h
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

#ifndef RTW_HEADER_DRIV_subsystem_integrated_h_
#define RTW_HEADER_DRIV_subsystem_integrated_h_
#include <string.h>
#ifndef DRIV_subsystem_integrated_COMMON_INCLUDES_
# define DRIV_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DRIV_subsystem_integrated_COMMON_INCLUDES_ */

#include "DRIV_subsystem_integrated_types.h"

/* Child system includes */
#include "DRIV.h"

/* Macros for accessing real-time model data structure */

/* Block signals (auto storage) */
typedef struct
{
  DRIV_OverrideSteerData Merge;        /* '<S48>/Merge' */
  real32_T dist_to_ego_lane_center;    /* '<S53>/DtrmnLCParameter' */
  real32_T c0_position;                /* '<S53>/DtrmnLCParameter' */
  real32_T c2_curvature;               /* '<S53>/DtrmnLCParameter' */
  real32_T distance_to_host;           /* '<S53>/DtrmnLCParameter' */
  real32_T Switch2;                    /* '<S30>/Switch2' */
  real32_T Gain;                       /* '<S34>/Gain' */
  real32_T Gain_f5cc;                  /* '<S66>/Gain' */
  real32_T VfDRIV_ACCDriveSetSpeed_jz5o;/* '<S30>/Switch' */
  uint8_T VfDRIV_ACCTimeGap_a2ct;      /* '<S30>/Switch' */
  boolean_T y;                         /* '<S85>/Chart' */
  boolean_T y_aq4x;                    /* '<S71>/Chart' */
  boolean_T y_metc;                    /* '<S67>/Chart' */
  boolean_T y_d4by;                    /* '<S66>/Chart' */
  boolean_T y_kjv1;                    /* '<S58>/Chart' */
  boolean_T y_cby3;                    /* '<S57>/Chart' */
  boolean_T y_k4sv;                    /* '<S34>/Chart' */
  boolean_T y_ddol;                    /* '<S33>/Chart' */
  boolean_T y_iwrs;                    /* '<S32>/Chart' */
  boolean_T VbDRIV_ACCMainSwitch_nbff; /* '<S30>/Switch' */
  boolean_T VbDRIV_ACCResumeSwitch_i0xk;/* '<S30>/Switch' */
  boolean_T FinalSwitch;               /* '<S30>/SwitchDebounce5' */
  boolean_T FinalSwitch_a45b;          /* '<S30>/SwitchDebounce4' */
  boolean_T FinalSwitch_be4y;          /* '<S30>/SwitchDebounce3' */
  boolean_T SignalConversion1;         /* '<S3>/Signal Conversion1' */
  boolean_T y_n3mj;                    /* '<S18>/Chart' */
  boolean_T y_gdtp;                    /* '<S17>/Chart' */
  boolean_T y_if0u;                    /* '<S16>/Chart' */
  boolean_T VbLCC_ButtonActivate;      /* '<S28>/Signal Conversion1' */
  boolean_T VbDRIV_EnableAutoDrive;    /* '<S28>/Signal Conversion2' */
  boolean_T LogicalOperator1;          /* '<S52>/Logical Operator1' */
  boolean_T SignalConversion1_ckqc;    /* '<S61>/Signal Conversion1' */
  boolean_T VbACC_ButtonActivate;      /* '<S28>/Signal Conversion3' */
  boolean_T VbDRIV_ACCCancelSwitch_juwt;/* '<S30>/Switch' */
  EnumACCS_Mode SignalConversion;      /* '<S3>/Signal Conversion' */
}
B_DRIV_subsystem_integrated_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct
{
  real32_T Delay1_DSTATE[20];          /* '<S79>/Delay1' */
  real32_T Delay_DSTATE;               /* '<S53>/Delay' */
  real32_T Delay_DSTATE_okrl;          /* '<S63>/Delay' */
  real32_T UnitDelay19_DSTATE;         /* '<S30>/Unit Delay19' */
  real32_T UnitDelay25_DSTATE;         /* '<S30>/Unit Delay25' */
  real32_T Delay_DSTATE_dx3s[20];      /* '<S9>/Delay' */
  uint32_T UnitDelay_DSTATE;           /* '<S7>/Unit Delay' */
  uint32_T UnitDelay2_DSTATE;          /* '<S7>/Unit Delay2' */
  uint32_T UnitDelay1_DSTATE;          /* '<S7>/Unit Delay1' */
  real32_T KfDRIV_w_LaneWidthMax_cdo4; /* '<S48>/Data Store Memory' */
  real32_T KfDRIV_d_TouchedNewLaneDis_mmyg;/* '<S48>/KfDRIV_d_TouchedNewLaneDist' */
  uint32_T temporalCounter_i1;         /* '<S67>/Chart' */
  uint16_T temporalCounter_i1_oc2i;    /* '<S85>/Chart' */
  uint16_T temporalCounter_i1_b5vo;    /* '<S71>/Chart' */
  uint16_T temporalCounter_i1_clr5;    /* '<S66>/Chart' */
  uint16_T temporalCounter_i1_jygd;    /* '<S58>/Chart' */
  uint16_T temporalCounter_i1_oo45;    /* '<S57>/Chart' */
  uint16_T temporalCounter_i1_kn0e;    /* '<S34>/Chart' */
  uint16_T temporalCounter_i1_lw4o;    /* '<S33>/Chart' */
  uint16_T temporalCounter_i1_klcu;    /* '<S32>/Chart' */
  uint16_T temporalCounter_i1_c0ca;    /* '<S18>/Chart' */
  uint16_T temporalCounter_i1_giwk;    /* '<S17>/Chart' */
  uint16_T temporalCounter_i1_n4sm;    /* '<S16>/Chart' */
  uint8_T UnitDelay1_DSTATE_cjxq;      /* '<S30>/Unit Delay1' */
  uint8_T UnitDelay10_DSTATE;          /* '<S30>/Unit Delay10' */
  uint8_T UnitDelay9_DSTATE;           /* '<S30>/Unit Delay9' */
  uint8_T UnitDelay4_DSTATE;           /* '<S30>/Unit Delay4' */
  uint8_T UnitDelay7_DSTATE;           /* '<S30>/Unit Delay7' */
  uint8_T UnitDelay3_DSTATE;           /* '<S30>/Unit Delay3' */
  boolean_T UnitDelay13_DSTATE;        /* '<S30>/Unit Delay13' */
  boolean_T UnitDelay_DSTATE_hbb3;     /* '<S30>/Unit Delay' */
  boolean_T UnitDelay12_DSTATE;        /* '<S30>/Unit Delay12' */
  boolean_T UnitDelay17_DSTATE;        /* '<S30>/Unit Delay17' */
  boolean_T UnitDelay18_DSTATE;        /* '<S30>/Unit Delay18' */
  boolean_T UnitDelay15_DSTATE;        /* '<S30>/Unit Delay15' */
  boolean_T UnitDelay22_DSTATE;        /* '<S30>/Unit Delay22' */
  boolean_T UnitDelay23_DSTATE;        /* '<S30>/Unit Delay23' */
  boolean_T UnitDelay16_DSTATE;        /* '<S30>/Unit Delay16' */
  boolean_T UnitDelay24_DSTATE;        /* '<S30>/Unit Delay24' */
  boolean_T UnitDelay14_DSTATE;        /* '<S30>/Unit Delay14' */
  boolean_T UnitDelay23_DSTATE_j5wv;   /* '<S37>/Unit Delay23' */
  boolean_T UnitDelay2_DSTATE_gngc;    /* '<S37>/Unit Delay2' */
  uint8_T is_active_c9_DRIV_subsystem_int;/* '<S85>/Chart' */
  uint8_T is_c9_DRIV_subsystem_integrated;/* '<S85>/Chart' */
  uint8_T is_active_c4_DRIV_subsystem_int;/* '<S54>/DRIV_Status' */
  uint8_T is_c4_DRIV_subsystem_integrated;/* '<S54>/DRIV_Status' */
  uint8_T is_LeftTurn;                 /* '<S54>/DRIV_Status' */
  uint8_T is_RightTurn;                /* '<S54>/DRIV_Status' */
  uint8_T is_active_c13_DRIV_subsystem_in;/* '<S71>/Chart' */
  uint8_T is_c13_DRIV_subsystem_integrate;/* '<S71>/Chart' */
  uint8_T is_active_c14_DRIV_subsystem_in;/* '<S67>/Chart' */
  uint8_T is_c14_DRIV_subsystem_integrate;/* '<S67>/Chart' */
  uint8_T is_active_c26_DRIV_subsystem_in;/* '<S66>/Chart' */
  uint8_T is_c26_DRIV_subsystem_integrate;/* '<S66>/Chart' */
  uint8_T is_active_c12_DRIV_subsystem_in;/* '<S58>/Chart' */
  uint8_T is_c12_DRIV_subsystem_integrate;/* '<S58>/Chart' */
  uint8_T is_active_c11_DRIV_subsystem_in;/* '<S57>/Chart' */
  uint8_T is_c11_DRIV_subsystem_integrate;/* '<S57>/Chart' */
  uint8_T is_active_c15_DRIV_subsystem_in;/* '<S34>/Chart' */
  uint8_T is_c15_DRIV_subsystem_integrate;/* '<S34>/Chart' */
  uint8_T is_active_c2_DRIV_subsystem_int;/* '<S33>/Chart' */
  uint8_T is_c2_DRIV_subsystem_integrated;/* '<S33>/Chart' */
  uint8_T is_active_c1_DRIV_subsystem_int;/* '<S32>/Chart' */
  uint8_T is_c1_DRIV_subsystem_integrated;/* '<S32>/Chart' */
  uint8_T is_active_c8_DRIV_subsystem_int;/* '<S18>/Chart' */
  uint8_T is_c8_DRIV_subsystem_integrated;/* '<S18>/Chart' */
  uint8_T is_active_c7_DRIV_subsystem_int;/* '<S17>/Chart' */
  uint8_T is_c7_DRIV_subsystem_integrated;/* '<S17>/Chart' */
  uint8_T is_active_c6_DRIV_subsystem_int;/* '<S16>/Chart' */
  uint8_T is_c6_DRIV_subsystem_integrated;/* '<S16>/Chart' */
  boolean_T Memory_PreviousInput;      /* '<S61>/Memory' */
  boolean_T Memory_PreviousInput_mg0c; /* '<S68>/Memory' */
  boolean_T Memory_PreviousInput_o1pn; /* '<S74>/Memory' */
  boolean_T Memory_PreviousInput_jnq3; /* '<S73>/Memory' */
}
DW_DRIV_subsystem_integrated_T;

/* Invariant block signals (auto storage) */
typedef struct
{
  const real_T Gain;                   /* '<S67>/Gain' */
  const uint8_T DataTypeConversion2;   /* '<S7>/Data Type Conversion2' */
  const uint8_T BitwiseOperator1;      /* '<S7>/Bitwise Operator1' */
  const uint8_T BitwiseOperator4;      /* '<S7>/Bitwise Operator4' */
  const uint8_T DataTypeConversion1;   /* '<S7>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_m3xv;/* '<S3>/Data Type Conversion' */
  const boolean_T LogicalOperator7;    /* '<S80>/Logical Operator7' */
}
ConstB_DRIV_subsystem_integra_T;

/* Constant parameters (auto storage) */
typedef struct
{
  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S68>/Logic'
   *   '<S73>/Logic'
   *   '<S74>/Logic'
   */
  boolean_T pooled14[16];
}
ConstP_DRIV_subsystem_integra_T;

/* Block signals (auto storage) */
extern B_DRIV_subsystem_integrated_T DRIV_subsystem_integrated_B;

/* Block states (auto storage) */
extern DW_DRIV_subsystem_integrated_T DRIV_subsystem_integrated_DW;

/* External data declarations for dependent source files */
extern const DRIV_DataBus DRIV_subsystem_integrated_rtZDRIV_DataBus;/* DRIV_DataBus ground */
extern const ConstB_DRIV_subsystem_integra_T DRIV_subsystem_integrate_ConstB;/* constant block i/o */

/* Constant parameters (auto storage) */
extern const ConstP_DRIV_subsystem_integra_T DRIV_subsystem_integrate_ConstP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern DRIV_DataBus VsDRIV_DataBus;    /* '<S4>/Bus Creator' */
extern real32_T VfDRIV_Steer_Torque_Rate;/* '<S79>/Divide1' */
extern real32_T VfDRIV_yawrate;        /* '<S52>/Signal Conversion2' */
extern real32_T VfDRIV_c1_heading;     /* '<S53>/DtrmnLCParameter' */
extern real32_T VfDRIV_ACCDriveSetSpeed;/* '<S30>/DtrmnDRIV_TargetSpeed'
                                         * Driver set target speed(Consider with speed up/down switch)
                                         */
extern real32_T VfDRIV_steer_angle;    /* '<S3>/Signal Conversion2' */
extern real32_T VfDRIV_SteerAngleRate; /* '<S9>/Divide' */
extern real32_T VfDRIV_Steer_Torque_Filter;/* '<S8>/Add' */
extern uint8_T VfDRIV_ACCTimeGap;      /* '<S37>/Saturation'
                                        * Driver set time gap
                                        */
extern boolean_T VbDRIV_Norm_driving;  /* '<S79>/Logical Operator1' */
extern boolean_T VbDRIV_Driver_Take_Over;/* '<S81>/Logical Operator4' */
extern boolean_T VbDRIV_Driver_Distracted;/* '<S80>/Logical Operator5' */
extern boolean_T VbDIRV_Override_Steering;/* '<S49>/Logical Operator2' */
extern boolean_T VbDRIV_LeftSide_LC_Req;/* '<S56>/Logical Operator1' */
extern boolean_T VbDRIV_RightSide_LC_Req;/* '<S56>/Logical Operator2' */
extern boolean_T VbDRIV_LaneChangeReady_Req;/* '<S65>/Signal Conversion2' */
extern boolean_T VbDRIV_LaneChanging_Req;/* '<S65>/Signal Conversion3' */
extern boolean_T VbDRIV_LaneChangeFinish_Req;/* '<S65>/Signal Conversion4' */
extern boolean_T VbDRIV_LC_Enable;     /* '<S52>/Logical Operator3' */
extern boolean_T VbDRIV_TurnType;      /* '<S55>/Relational Operator1' */
extern boolean_T VbDRIV_Update_Override_Steering;/* '<S75>/Signal Conversion3' */
extern boolean_T VbDRIV_LaneKeepAssist;/* '<S54>/DRIV_Status' */
extern boolean_T VbDRIV_Touched_new_lane;/* '<S53>/DtrmnLCParameter' */
extern boolean_T VbDRIV_ACCResumeSwitch;/* '<S30>/SwitchDebounce2'
                                         * ACC resume switch status
                                         */
extern boolean_T VbDRIV_ACCCancelSwitch;/* '<S30>/SwitchDebounce1'
                                         * ACC cancel switch status
                                         */
extern boolean_T VbDRIV_ACCMainSwitch; /* '<S30>/ACC_MainSwitch'
                                        * ACC main switch status
                                        */
extern EnumDRIV_LeftChangeLane VeDRIV_LeftChangeLane;/* '<S54>/DRIV_Status' */
extern EnumDRIV_RightChangeLane VeDRIV_RightChangeLane;/* '<S54>/DRIV_Status' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T KfACCS_t_SwitchLongPressThrsh;/* Variable: KfACCS_t_SwitchLongPressThrsh
                                               * Referenced by: '<S30>/DtrmnDRIV_TargetSpeed'
                                               * As press resume/set switch timer bigge than this calibration,tap up step will use KfACCS_v_TapUpDeltaLongPress
                                               */
extern real32_T KfACCS_v_TapDownDelta; /* Variable: KfACCS_v_TapDownDelta
                                        * Referenced by: '<S30>/DtrmnDRIV_TargetSpeed'
                                        * Tap down delta as press speed down switch
                                        */
extern real32_T KfACCS_v_TapDownDeltaLongPress;/* Variable: KfACCS_v_TapDownDeltaLongPress
                                                * Referenced by: '<S30>/DtrmnDRIV_TargetSpeed'
                                                * As press set switch timer bigge than KfACCS_t_SwitchLongPressThrsh,tap down step will use this calbiration
                                                */
extern real32_T KfACCS_v_TapUpDelta;   /* Variable: KfACCS_v_TapUpDelta
                                        * Referenced by: '<S30>/DtrmnDRIV_TargetSpeed'
                                        * Tap up delta as press speed up switch
                                        */
extern real32_T KfACCS_v_TapUpDeltaLongPress;/* Variable: KfACCS_v_TapUpDeltaLongPress
                                              * Referenced by: '<S30>/DtrmnDRIV_TargetSpeed'
                                              * As press resume switch timer bigge than KfACCS_t_SwitchLongPressThrsh,tap up step will use this calibration
                                              */
extern real32_T KfDRIV_CoeffStrwhl2Radius;/* Variable: KfDRIV_CoeffStrwhl2Radius
                                           * Referenced by: '<S10>/Constant6'
                                           * When there's no EGMO, steer wheel angle is used to calculate Radius,
                                             Coefficent correction of radius.
                                           */
extern real32_T KfDRIV_Veh_Strwhl2FrtwhlRatio;/* Variable: KfDRIV_Veh_Strwhl2FrtwhlRatio
                                               * Referenced by: '<S10>/Constant2'
                                               * steer ratio =17
                                               */
extern real32_T KfDRIV_Veh_WheelBase;  /* Variable: KfDRIV_Veh_WheelBase
                                        * Referenced by: '<S10>/Constant1'
                                        * wheel base
                                        */
extern real32_T KfDRIV_d_Dist2LaneChangeFinish;/* Variable: KfDRIV_d_Dist2LaneChangeFinish
                                                * Referenced by: '<S61>/Constant5'
                                                * to lane_center distance < 0.4
                                                */
extern real32_T KfDRIV_d_TouchedNewLaneDist;/* Variable: KfDRIV_d_TouchedNewLaneDist
                                             * Referenced by:
                                             *   '<S48>/KfDRIV_d_TouchedNewLaneDist'
                                             *   '<S48>/Constant8'
                                             * when vehicle touched new lane ,the distance to lane can increase in one sample time
                                             */
extern real32_T KfDRIV_t_TimeEGMOReceivedThrsh;/* Variable: KfDRIV_t_TimeEGMOReceivedThrsh
                                                * Referenced by: '<S7>/Constant2'
                                                * TimeEGMOReceivedThrsh
                                                */
extern real32_T KfDRIV_t_TimeMPFUReceivedThrsh;/* Variable: KfDRIV_t_TimeMPFUReceivedThrsh
                                                * Referenced by: '<S7>/Constant8'
                                                * TimeMPFUReceivedThrsh
                                                */
extern real32_T KfDRIV_t_TimeOBFUNReceivedThrsh;/* Variable: KfDRIV_t_TimeOBFUNReceivedThrsh
                                                 * Referenced by: '<S7>/Constant7'
                                                 * TimeOBFUNReceivedThrsh
                                                 */
extern real32_T KfDRIV_t_WaitTimeDriverDistracted;/* Variable: KfDRIV_t_WaitTimeDriverDistracted
                                                   * Referenced by: '<S80>/Constant10'
                                                   * WaitTimeDriverDistracted
                                                   */
extern real32_T KfDRIV_t_WaitTimeLaneChangeFinish;/* Variable: KfDRIV_t_WaitTimeLaneChangeFinish
                                                   * Referenced by: '<S61>/Constant1'
                                                   * WaitTimeLaneChangeFinish
                                                   */
extern real32_T KfDRIV_w_LaneWidthMax; /* Variable: KfDRIV_w_LaneWidthMax
                                        * Referenced by:
                                        *   '<S48>/Data Store Memory'
                                        *   '<S48>/Constant5'
                                        * LaneWidthMax
                                        */
extern real32_T kfDRIV_M_TorqueOverrideThreshold;/* Variable: kfDRIV_M_TorqueOverrideThreshold
                                                  * Referenced by: '<S79>/Constant1'
                                                  * steer torque threshold
                                                  */
extern real32_T kfDRIV_M_TorqueOverrideThreshold_ACC;/* Variable: kfDRIV_M_TorqueOverrideThreshold_ACC
                                                      * Referenced by: '<S81>/Constant7'
                                                      * steer torque threshold ACC
                                                      */
extern real32_T kfDRIV_M_TorqueOverrideThreshold_Auto;/* Variable: kfDRIV_M_TorqueOverrideThreshold_Auto
                                                       * Referenced by: '<S80>/Constant8'
                                                       * TorqueOverrideThreshold_Auto
                                                       */
extern real32_T kfDRIV_M_TorqueOverrideThreshold_LCC;/* Variable: kfDRIV_M_TorqueOverrideThreshold_LCC
                                                      * Referenced by: '<S81>/Constant8'
                                                      * TorqueOverrideThreshold LCC driver  take over
                                                      */
extern real32_T kfDRIV_M_TorqueThreshold_Distracted;/* Variable: kfDRIV_M_TorqueThreshold_Distracted
                                                     * Referenced by: '<S80>/Constant1'
                                                     */
extern real32_T kfDRIV_SteerAngleRateThreshold;/* Variable: kfDRIV_SteerAngleRateThreshold
                                                * Referenced by: '<S63>/Constant7'
                                                * SteerAngleRateThreshold
                                                */
extern real32_T kfDRIV_SteerAngleThreshold;/* Variable: kfDRIV_SteerAngleThreshold
                                            * Referenced by:
                                            *   '<S56>/Constant1'
                                            *   '<S56>/Constant9'
                                            */
extern real32_T kfDRIV_TorqueRateThreshold;/* Variable: kfDRIV_TorqueRateThreshold
                                            * Referenced by: '<S79>/Constant6'
                                            * TorqueRateThreshold
                                            */
extern real32_T kfDRIV_TorqueRate_LC_Threshold;/* Variable: kfDRIV_TorqueRate_LC_Threshold
                                                * Referenced by: '<S63>/Constant9'
                                                * TorqueRate_LC_Threshold
                                                */
extern real32_T kfDRIV_YawRateThreshold;/* Variable: kfDRIV_YawRateThreshold
                                         * Referenced by: '<S63>/Constant4'
                                         * YawRateThreshold
                                         */
extern real32_T kfDRIV_YawRateThreshold2;/* Variable: kfDRIV_YawRateThreshold2
                                          * Referenced by: '<S62>/Constant9'
                                          * YawRateThreshold2
                                          */
extern real32_T kfDRIV_c1_threshold;   /* Variable: kfDRIV_c1_threshold
                                        * Referenced by: '<S62>/Constant2'
                                        * Lane Coefficient c1
                                        */
extern real32_T kfDRIV_k_FilterGain;   /* Variable: kfDRIV_k_FilterGain
                                        * Referenced by: '<S8>/Constant2'
                                        * steer torque  filter gain 0.9
                                        */
extern real32_T kfDRIV_t_PeriodFunctionCall;/* Variable: kfDRIV_t_PeriodFunctionCall
                                             * Referenced by:
                                             *   '<S9>/Constant'
                                             *   '<S28>/Constant1'
                                             *   '<S28>/Constant3'
                                             *   '<S28>/Constant6'
                                             *   '<S79>/Constant'
                                             *   '<S63>/Constant3'
                                             * model  sample time
                                             */
extern real32_T kfDRIV_t_TurnLightLeftOn_Time;/* Variable: kfDRIV_t_TurnLightLeftOn_Time
                                               * Referenced by: '<S56>/Constant12'
                                               * TurnLightLeftOn_Time
                                               */
extern real32_T kfDRIV_t_TurnLightOn_Time;/* Variable: kfDRIV_t_TurnLightOn_Time
                                           * Referenced by: '<S63>/Constant12'
                                           * TurnLightOn_Time
                                           */
extern real32_T kfDRIV_t_TurnLightRightOn_Time;/* Variable: kfDRIV_t_TurnLightRightOn_Time
                                                * Referenced by: '<S56>/Constant5'
                                                * TurnLightRightOn_Time
                                                */
extern uint8_T KcDRIV_ACCSCancelSwitchDebounceThrsh;/* Variable: KcDRIV_ACCSCancelSwitchDebounceThrsh
                                                     * Referenced by: '<S30>/Constant12'
                                                     * ACCS cancel switch debounce thresh.
                                                     */
extern uint8_T KcDRIV_ACCSMainSwitchDebounceThrsh;/* Variable: KcDRIV_ACCSMainSwitchDebounceThrsh
                                                   * Referenced by: '<S30>/Constant11'
                                                   * ACCS main switch debounce thresh.
                                                   */
extern uint8_T KcDRIV_ACCSResumeSwitchDebounceThrsh;/* Variable: KcDRIV_ACCSResumeSwitchDebounceThrsh
                                                     * Referenced by: '<S30>/Constant13'
                                                     * ACCS resume switch debounce thresh.
                                                     */
extern uint8_T KcDRIV_ACCSSetSwitchDebounceThrsh;/* Variable: KcDRIV_ACCSSetSwitchDebounceThrsh
                                                  * Referenced by: '<S30>/Constant14'
                                                  * ACCS set switch debounce thresh.
                                                  */
extern uint8_T KcDRIV_ACCSTimeGapMinusDebounceThrsh;/* Variable: KcDRIV_ACCSTimeGapMinusDebounceThrsh
                                                     * Referenced by: '<S30>/Constant16'
                                                     * ACCS time gap minus switch debounce thresh.
                                                     */
extern uint8_T KcDRIV_ACCSTimeGapPlusDebounceThrsh;/* Variable: KcDRIV_ACCSTimeGapPlusDebounceThrsh
                                                    * Referenced by: '<S30>/Constant15'
                                                    * ACCS time gap plus switch debounce thresh.
                                                    */
extern uint8_T kfDRIV_DelayLoopGain;   /* Variable: kfDRIV_DelayLoopGain
                                        * Referenced by:
                                        *   '<S28>/Constant2'
                                        *   '<S28>/Constant4'
                                        *   '<S28>/Constant7'
                                        * button delay loop gain
                                        */
extern boolean_T KbDRIV_DRIVEnable;    /* Variable: KbDRIV_DRIVEnable
                                        * Referenced by: '<S4>/Constant'
                                        * DRIV mode status is true
                                        */
extern boolean_T KbDRIV_Default_EnableAutoDrive;/* Variable: KbDRIV_Default_EnableAutoDrive
                                                 * Referenced by: '<S5>/Constant5'
                                                 * Default auto drive is false
                                                 */
extern boolean_T KbDRIV_Default_LaneKeepAssist;/* Variable: KbDRIV_Default_LaneKeepAssist
                                                * Referenced by: '<S51>/Constant2'
                                                * default vehicle is lanekeeping
                                                */
extern boolean_T KbDRIV_Default_Override_Steering;/* Variable: KbDRIV_Default_Override_Steering
                                                   * Referenced by: '<S51>/Constant1'
                                                   * default override steering  status is false
                                                   */
extern boolean_T KbDRIV_Update_Override_Steering;/* Variable: KbDRIV_Update_Override_Steering
                                                  * Referenced by: '<S75>/Constant1'
                                                  * update override steering status is true
                                                  */

/* Model entry point functions */
extern void DRIV_subsystem_integrated_initialize(void);
extern void DRIV_subsystem_integrated_step(void);

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
 * '<Root>' : 'DRIV_subsystem_integrated'
 * '<S1>'   : 'DRIV_subsystem_integrated/DRIV '
 * '<S2>'   : 'DRIV_subsystem_integrated/DocBlock'
 * '<S3>'   : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalInput'
 * '<S4>'   : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalOutput'
 * '<S5>'   : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus'
 * '<S6>'   : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalInput/Enumerated Constant2'
 * '<S7>'   : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalInput/Fault Detection'
 * '<S8>'   : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalInput/Subsystem'
 * '<S9>'   : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalInput/Subsystem1'
 * '<S10>'  : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalInput/adc_path_prediction'
 * '<S11>'  : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalInput/veh_FedBck_update'
 * '<S12>'  : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalInput/Fault Detection/Enumerated Constant'
 * '<S13>'  : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalInput/Fault Detection/Enumerated Constant1'
 * '<S14>'  : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalInput/Fault Detection/Enumerated Constant2'
 * '<S15>'  : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalInput/Fault Detection/Enumerated Constant3'
 * '<S16>'  : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalInput/Fault Detection/RaisingEdgeDelay'
 * '<S17>'  : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalInput/Fault Detection/RaisingEdgeDelay1'
 * '<S18>'  : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalInput/Fault Detection/RaisingEdgeDelay2'
 * '<S19>'  : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalInput/Fault Detection/RaisingEdgeDelay/Chart'
 * '<S20>'  : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalInput/Fault Detection/RaisingEdgeDelay1/Chart'
 * '<S21>'  : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalInput/Fault Detection/RaisingEdgeDelay2/Chart'
 * '<S22>'  : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalInput/adc_path_prediction/evidezero'
 * '<S23>'  : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalInput/adc_path_prediction/evidezero1'
 * '<S24>'  : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalInput/adc_path_prediction/evidezero/DividByZero'
 * '<S25>'  : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalInput/adc_path_prediction/evidezero1/DividByZero'
 * '<S26>'  : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalInput/veh_FedBck_update/Init_veh_FedBck'
 * '<S27>'  : 'DRIV_subsystem_integrated/DRIV /CheckDRIV_SignalOutput/Enumerated Constant'
 * '<S28>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdButtonStatus'
 * '<S29>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus'
 * '<S30>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdButtonStatus/DtrmnDRIV_ACC_Switch'
 * '<S31>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdButtonStatus/Enumerated Constant1'
 * '<S32>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdButtonStatus/RisingEdgeDelay'
 * '<S33>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdButtonStatus/RisingEdgeDelay1'
 * '<S34>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdButtonStatus/RisingEdgeDelay2'
 * '<S35>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdButtonStatus/DtrmnDRIV_ACC_Switch/ACC_MainSwitch'
 * '<S36>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdButtonStatus/DtrmnDRIV_ACC_Switch/DtrmnDRIV_TargetSpeed'
 * '<S37>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdButtonStatus/DtrmnDRIV_ACC_Switch/DtrmnDRIV_TargetTimeGap'
 * '<S38>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdButtonStatus/DtrmnDRIV_ACC_Switch/SwitchDebounce'
 * '<S39>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdButtonStatus/DtrmnDRIV_ACC_Switch/SwitchDebounce1'
 * '<S40>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdButtonStatus/DtrmnDRIV_ACC_Switch/SwitchDebounce2'
 * '<S41>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdButtonStatus/DtrmnDRIV_ACC_Switch/SwitchDebounce3'
 * '<S42>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdButtonStatus/DtrmnDRIV_ACC_Switch/SwitchDebounce4'
 * '<S43>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdButtonStatus/DtrmnDRIV_ACC_Switch/SwitchDebounce5'
 * '<S44>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdButtonStatus/DtrmnDRIV_ACC_Switch/DtrmnDRIV_TargetTimeGap/Enumerated Constant'
 * '<S45>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdButtonStatus/RisingEdgeDelay/Chart'
 * '<S46>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdButtonStatus/RisingEdgeDelay1/Chart'
 * '<S47>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdButtonStatus/RisingEdgeDelay2/Chart'
 * '<S48>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge'
 * '<S49>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_OverrideSteering'
 * '<S50>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge'
 * '<S51>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_OverrideSteer_DefaultData'
 * '<S52>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/CheckLCLogiCondition'
 * '<S53>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/CheckLCProcess'
 * '<S54>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/DtrmnDRIV_OverrideSteerStatus'
 * '<S55>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/CheckLCLogiCondition/CheckTurntype'
 * '<S56>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/CheckLCLogiCondition/lc_side_estimate'
 * '<S57>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/CheckLCLogiCondition/lc_side_estimate/RisingEdgeDelay'
 * '<S58>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/CheckLCLogiCondition/lc_side_estimate/RisingEdgeDelay1'
 * '<S59>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/CheckLCLogiCondition/lc_side_estimate/RisingEdgeDelay/Chart'
 * '<S60>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/CheckLCLogiCondition/lc_side_estimate/RisingEdgeDelay1/Chart'
 * '<S61>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/CheckLCProcess/CheckLCFinish'
 * '<S62>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/CheckLCProcess/CheckLCIng'
 * '<S63>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/CheckLCProcess/CheckLCReady'
 * '<S64>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/CheckLCProcess/DtrmnLCParameter'
 * '<S65>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/CheckLCProcess/Subsystem'
 * '<S66>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/CheckLCProcess/CheckLCFinish/RaisingEdgeDelay1'
 * '<S67>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/CheckLCProcess/CheckLCFinish/RisingEdgeDelay'
 * '<S68>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/CheckLCProcess/CheckLCFinish/SetResetFlipFlop1'
 * '<S69>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/CheckLCProcess/CheckLCFinish/RaisingEdgeDelay1/Chart'
 * '<S70>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/CheckLCProcess/CheckLCFinish/RisingEdgeDelay/Chart'
 * '<S71>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/CheckLCProcess/CheckLCReady/RisingEdgeDelay'
 * '<S72>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/CheckLCProcess/CheckLCReady/RisingEdgeDelay/Chart'
 * '<S73>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/CheckLCProcess/Subsystem/S-R Flip-Flop'
 * '<S74>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/CheckLCProcess/Subsystem/S-R Flip-Flop1'
 * '<S75>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/DtrmnDRIV_OverrideSteerStatus/DRIV_Out'
 * '<S76>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_LC_Intention_Judge/DtrmnDRIV_OverrideSteerStatus/DRIV_Status'
 * '<S77>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_OverrideSteer_DefaultData/Enumerated Constant'
 * '<S78>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_LaneChange_Judge/DRIV_OverrideSteer_DefaultData/Enumerated Constant1'
 * '<S79>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_OverrideSteering/driver_Normal_driving'
 * '<S80>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_OverrideSteering/driver_distracted'
 * '<S81>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_OverrideSteering/driver_take_over'
 * '<S82>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_OverrideSteering/driver_distracted/DriverStatus'
 * '<S83>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_OverrideSteering/driver_distracted/Enumerated Constant'
 * '<S84>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_OverrideSteering/driver_distracted/Enumerated Constant1'
 * '<S85>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_OverrideSteering/driver_distracted/RisingEdgeDelay'
 * '<S86>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_OverrideSteering/driver_distracted/RisingEdgeDelay/Chart'
 * '<S87>'  : 'DRIV_subsystem_integrated/DRIV /DtrmnDRIV_RunStatus/DtrmnDRIV_OvrdSteerStatus/DtrmnDRIV_OverrideSteering/driver_take_over/Enumerated Constant'
 */
#endif                                 /* RTW_HEADER_DRIV_subsystem_integrated_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
