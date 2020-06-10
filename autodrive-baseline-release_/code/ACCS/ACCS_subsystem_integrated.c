/*
 * File: ACCS_subsystem_integrated.c
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

#include "ACCS_subsystem_integrated.h"
#include "ACCS_subsystem_integrated_private.h"

const ACCS_DataBus ACCS_subsystem_integrated_rtZACCS_DataBus =
{
  false,                               /* VbACCS_ExitStandbyToOn */
  false,                               /* VbACCS_InformDriverPressGasPedal */
  false,                               /* VbACCS_InformDriverPressResume */
  NoEnterStandby,                      /* VeACCS_EnterStandbyState */
  0.0F,                                /* VfACCS_Lon_Accleration */
  false,                               /* VbACCS_Lon_Torq_req */
  0.0F,                                /* VfACCS_Lon_Torq */
  0.0F,                                /* VfACCS_Lon_Speed_Tar */
  0.0F,                                /* VfACCS_Lon_Range_Act */
  false,                               /* VbACCS_Lon_Accleration_req */
  ACCS_mode_off,                       /* VeACCS_Mode */
  ACCS_status_off                      /* VeACCS_RunStatus */
} ;                                    /* ACCS_DataBus ground */

/* Exported block signals */
ACCS_DataBus VsACCS_DataBus;           /* '<S5>/Bus Creator' */
real32_T VfACCS_Range_Actual;          /* '<S16>/Signal Conversion2'
                                        * The actual range
                                        */
real32_T VfACCS_CombinedSpeedLimit;    /* '<S16>/Switch3'
                                        * Speed limit,consider with road and driver set
                                        */
real32_T VfACCS_StopTimer;             /* '<S138>/DtrmnACCS_RunStatusTransfer'
                                        * If enter stop model, this timer will increase
                                        */
real32_T VfACCS_SpdErrLim_CIPV;        /* '<S106>/max'
                                        * The speed error for speed PID control
                                        */
real32_T VfACCS_DrsdAccelFrmRngSped;   /* '<S106>/Switch'
                                        * The acceleration considers with range and speed error
                                        */
real32_T VfACCS_RangCtrCL_CIPV;        /* '<S105>/Signal Conversion'
                                        * CIPV object range closed loop out
                                        */
real32_T VfACCS_Lon_Torq_Req;          /* '<S114>/Sum3'
                                        * The ACCS final output torq(%)
                                        */
real32_T VfACCS_Lon_Accleration;       /* '<S113>/Sum3'
                                        * The ACCS final output acceleration
                                        */
real32_T VfACCS_DCSNStopAccel;         /* '<S103>/Sum1'
                                        * The acceleration is from DCSN stop requirement
                                        */
real32_T VfACCS_DrsdAccelWithDCSN;     /* '<S103>/Switch3'
                                        * The acceleration consider with DCSN stop requirement
                                        */
real32_T VfACCS_DrsdAccelWithPitch;    /* '<S103>/Add'
                                        * Before override desired acceleraton
                                        */
real32_T VfACCS_TargetDrsdLonAccel;    /* '<S109>/Sum'
                                        * Target desired acceleration
                                        */
real32_T VfACCS_FinalDrsdAcceleration_old;/* '<S103>/Unit Delay1'
                                           * Final desired acceleration pre loop value
                                           */
real32_T VfACCS_FinalDrsdAcceleration; /* '<S103>/Switch4'
                                        * Finale desired acceleration
                                        */
real32_T VfACCS_Acceleartion_RampUpStep;/* '<S111>/MATLAB Function'
                                         * Desired acceleration ramp up step
                                         */
real32_T VfACCS_Acceleartion_RampDownStep;/* '<S111>/MATLAB Function'
                                           * Desired acceleration ramp down step
                                           */
real32_T VfACCS_LaunchToSpdRampTimer;  /* '<S111>/MATLAB Function'
                                        * As from Launch to Speed control, this timer will increase.As this timer smaller than KfACCS_t_LaunchToSpdRampTimerThrsh,use KfACCS_a_LaunchToSpdRampUpStep or KfACCS_a_LaunchToSpdRampDownStep
                                        */
real32_T VfACCS_LaunchToFollowRampTimer;/* '<S111>/MATLAB Function'
                                         * As from launch to following control, this timer will increase.As this timer smaller than KfACCS_t_LaunchToFollowRampTimerThrsh,use KfACCS_a_LaunchToFollowRampUpStep or KfACCS_a_LaunchToFollowRampDownStep
                                         */
real32_T VfACCS_SpeedToFollowRampTimer;/* '<S111>/MATLAB Function'
                                        * As from Speed to following control, this timer will increase.As this timer smaller than KfACCS_t_SpeedToFollowRampTimerThrsh,use KfACCS_a_SpeedToFollowRampUpStep or KfACCS_a_SpeedToFollowRampDownStep
                                        */
real32_T VfACCS_FollowToSpdRampTimer;  /* '<S111>/MATLAB Function'
                                        * As from following to speed control, this timer will increase.As this timer smaller than KfACCS_t_FollowToSpdRampTimerThrsh,use KfACCS_a_FollowToSpdRampUpStep or KfACCS_a_FollowToSpdRampDownStep
                                        */
real32_T VfACCS_Obs_Lat_V_OBFU;        /* '<S38>/Add17'
                                        * obstacle's lateral speed before process
                                        */
real32_T VfACCS_Obs_Long_V_OBFU;       /* '<S38>/Add18'
                                        * obstacle's longitudinal speed before process
                                        */
real32_T VfACCS_Obs_Long_A_OBFU;       /* '<S38>/Add19'
                                        * obstacle's longitudinal acceleration before process
                                        */
real32_T VfACCS_Obs_Lat_A_OBFU;        /* '<S38>/Add20'
                                        * obstacle's lateral acceleration before process
                                        */
real32_T VfACCS_Obs_Long_OBFU;         /* '<S38>/Signal Conversion'
                                        * obstacle's longitudinal distacne before process
                                        */
real32_T VfACCS_Obs_Lat_OBFU;          /* '<S38>/Signal Conversion1'
                                        * obstacle's lateral distance before process
                                        */
real32_T VfACCS_Input_Obs_LinearAcc;   /* '<S48>/Switch6'
                                        * CIPV object linear speed
                                        */
real32_T VfACCS_Input_Obs_Range;       /* '<S48>/Switch'
                                        * CIPV object range
                                        */
real32_T VfACCS_Input_Obs_Rangerate;   /* '<S48>/Switch4'
                                        * CIPV object range rate
                                        */
real32_T VfACCS_Input_Obs_LatDis;      /* '<S48>/Switch1'
                                        * CIPV object lat distance
                                        */
real32_T VfACCS_Input_Obs_Long_VFiltered;/* '<S48>/Switch2'
                                          * CIPV object long velocity
                                          */
real32_T VfACCS_Input_Obs_Lat_VFiltered;/* '<S48>/Switch3'
                                         * CIPV object lat speed
                                         */
real32_T VfACCS_Input_Obs_LinearVelocity;/* '<S48>/Switch5'
                                          * CIPV object linear speed
                                          */
real32_T VfACCS_DriverTargetRange;     /* '<S34>/MinMax1'
                                        * Driver target following range
                                        */
real32_T VfACCS_FinalSpeedLimit;       /* '<S19>/CombinedSpeedLimit'
                                        * Final speed limit, consider with road limit
                                        */
real32_T VfACCS_FeedForwardAccel;      /* '<S18>/Merge1'
                                        * Acceleration open iterm
                                        */
real32_T VfACCS_OpenAccel_ForDCSNStop; /* '<S18>/Switch2'
                                        * This is open acceleration for DCSN stop
                                        */
real32_T VfACCS_VehSpeed_Tar;          /* '<S17>/Saturation'
                                        * The target vehicle speed
                                        */
real32_T VfACCS_DeltaSped_EGMOAndCan;  /* '<S9>/Subtract'
                                        * Speed error between Can and EGMO model
                                        */
real32_T VfACCS_Input_linear_velocity_EGMO;/* '<S9>/Switch'
                                            * Ego linear velocith from EGMO mode
                                            */
real32_T VfACCS_Input_EgoPitch_EGMO;   /* '<S9>/Switch3'
                                        * Ego pitch from EGMO model
                                        */
real32_T VfACCS_Input_longvelocity_EGMO;/* '<S9>/Signal Conversion5'
                                         * Ego vehilce V_x
                                         */
real32_T VfACCS_Input_latvelocity_EGMO;/* '<S9>/Signal Conversion6'
                                        * Ego vehicle V_y
                                        */
real32_T VfACCS_Input_linear_Acceleration_EGMO;/* '<S9>/Signal Conversion7'
                                                * Ego linear acceleration from EGMO model
                                                */
real32_T VfACCS_Input_stop_s_distance_DCSN;/* '<S8>/Switch2'
                                            * Stop distance from DCSN model
                                            */
real32_T VfACCS_Input_traffic_speed_limit_DCSN;/* '<S8>/Switch1'
                                                * Speed limit from DCSM model
                                                */
real32_T VfACCS_Input_PhyGasPedal_POWER;/* '<S7>/Switch6'
                                         * Observe the opening of the accelerator pedal
                                         */
int32_T VfACCS_Input_OBFUTimeStamp_high;/* '<S35>/Signal Conversion1'
                                         * OBFU timestamp high


                                         */
int32_T VfACCS_Input_Obs_ID;           /* '<S48>/Signal Conversion2'
                                        * CIPV object id
                                        */
int32_T VfACCS_Input_EGMOTimeStamp_high;/* '<S9>/Signal Conversion9'
                                         * EGMO timestamp high

                                         */
uint16_T VfACCS_Input_Obs_Num;         /* '<S35>/Signal Conversion'
                                        * Object num from OBFU
                                        */
int8_T VeACCS_CIPVobsType;             /* '<S48>/Signal Conversion4'
                                        * UNKNOWN=0;
                                          PEDESTRIAN=1;
                                          BICYCLE=2;
                                          MOTORCYCLE = 3;
                                          VEHICLE=4;
                                          BUS=5;
                                          TRUCK=6;
                                          ANIMAL =7;
                                          TRAFFIC_CONE = 8;
                                          FENCES = 9;
                                        */
boolean_T VbACCS_AEB_Active;           /* '<S16>/Constant11'
                                        * AEB active
                                        */
boolean_T VbACCS_MainSwitch;           /* '<S16>/Logical Operator2'
                                        * ACC main switch is ture
                                        */
boolean_T VbACCS_InformDriverPressResume;/* '<S16>/Signal Conversion'
                                          * Ture:Driver need press resume switch to active ACCS
                                          */
boolean_T VbACCS_InformDriverPressGasPedal;/* '<S16>/Signal Conversion1'
                                            * Ture:Driver need press gas pedal to active ACCS
                                            */
boolean_T VbACCS_SpdToLowSpeedCtr;     /* '<S150>/Logical Operator1'
                                        * The condtion:From speed to low speed control
                                        */
boolean_T VbACCS_HasCIPV_Object;       /* '<S150>/CIPV_object_valid'
                                        * Ture: There is following target object
                                        */
boolean_T VbACCS_LowSpdToSpeedCtr;     /* '<S150>/Logical Operator2'
                                        * The condition:From low speed to speed control
                                        */
boolean_T VbACCS_FollowingToSpeedCtrl; /* '<S150>/Logical Operator5'
                                        * The condition: from following control to speed control
                                        */
boolean_T VbACCS_SpeedToFollowingCtr;  /* '<S150>/Logical Operator'
                                        * The condition:From speed to following control
                                        */
boolean_T VbACCS_LowSpdToTempStop;     /* '<S150>/Logical Operator10'
                                        * The condition:From low speed to temp stop
                                        */
boolean_T VbACCS_LowSpdToFollowingCtrl;/* '<S150>/Logical Operator8'
                                        * The condition:From low speed to following control
                                        */
boolean_T VbACCS_TempStopToLaunch;     /* '<S150>/Logical Operator13'
                                        * The condition:From temp stop to launch
                                        */
boolean_T VbACCS_FollowingToLowSpdCtrl;/* '<S150>/Logical Operator6'
                                        * The condition: from following control to low speed control
                                        */
boolean_T VbACCS_StatusOnToSpeedCtrl;  /* '<S150>/Logical Operator11'
                                        * The condition:From  status on to speed control
                                        */
boolean_T VbACCS_StatusOnToStop;       /* '<S150>/Logical Operator12'
                                        * The condirion:From status on to Stop
                                        */
boolean_T VbACCS_EnterStandbyCommonCod;/* '<S150>/Logical Operator25'
                                        * Ture:enter standby common conditions meet
                                        */
boolean_T VbACCS_FromStopToStandby;    /* '<S150>/Logical Operator26'
                                        * The condition: from Stop to Standby
                                        */
boolean_T VbACCS_FromLowSpeedToStandby;/* '<S150>/Logical Operator22'
                                        * The condition: from Low Speed control to Standby
                                        */
boolean_T VbACCS_FromLaunchToStandby;  /* '<S150>/Logical Operator29'
                                        * The condition: from following control to Standby
                                        */
boolean_T VbACCS_FromFollowingCtrlToStandby;/* '<S150>/Logical Operator34'
                                             * The condition: from following control to Standby
                                             */
boolean_T VbACCS_FromSpeedCtrlToStandby;/* '<S150>/Logical Operator37'
                                         * The condition: from Speed control to Standby
                                         */
boolean_T VbACCS_EnterStopDueToCIP;    /* '<S150>/Logical Operator32'
                                        * Enter stop mode due to obstacle
                                        */
boolean_T VbACCS_TempStpToStop;        /* '<S138>/DtrmnACCS_RunStatusTransfer'
                                        * The condition: From temp stop to stop
                                        */
boolean_T VbACCS_StopToLaunch;         /* '<S138>/DtrmnACCS_RunStatusTransfer'
                                        * The condition:From stop to launch
                                        */
boolean_T VbACCS_LaunchToTempStop;     /* '<S138>/DtrmnACCS_RunStatusTransfer'
                                        * The condition:From launch to temp stop
                                        */
boolean_T VbACCS_LaunchToSpeedCtrl;    /* '<S138>/DtrmnACCS_RunStatusTransfer'
                                        * The condition:From launch to speed control
                                        */
boolean_T VbACCS_LaunchToLowSpd;       /* '<S138>/DtrmnACCS_RunStatusTransfer'
                                        * The condition:From launch to low speed control
                                        */
boolean_T VbACCS_LaunchToFollowingCtrl;/* '<S138>/DtrmnACCS_RunStatusTransfer'
                                        * The condition:From launch to following control
                                        */
boolean_T VbACCS_ResumeSwitch;         /* '<S148>/Signal Conversion4'
                                        * Driver press resume switch
                                        */
boolean_T VbACCS_ResumeSwitchOld;      /* '<S148>/Unit Delay'
                                        * The previous loop resume switch state
                                        */
boolean_T VbACCS_GearPositionIsD;      /* '<S148>/Logical Operator7'
                                        * Gear position is D gear
                                        */
boolean_T VbACCS_SpeedOutRange;        /* '<S148>/Logical Operator1'
                                        * Ego speed is out of ACCS enable range
                                        */
boolean_T VbACCS_DriverModeAllowACCS;  /* '<S148>/Relational Operator32'
                                        * Under the current drive mode, can enable ACCS
                                        */
boolean_T VbACCS_DriverGasPedalOverride;/* '<S148>/Logical Operator8'
                                         * Driver gas pedal is bigger than ACC requirement
                                         */
boolean_T VbACCS_EgoLimit;             /* '<S148>/Signal Conversion3'
                                        * Ego vehicle has some features will limit ACCS
                                        */
boolean_T VbACCS_ExitStandbyCommonConds;/* '<S148>/Logical Operator4'
                                         * Exit stanby mode common conditions meet
                                         */
boolean_T VbACCS_ExitStandbyToOn;      /* '<S148>/Logical Operator6'
                                        * Ture: Will exit standby to RunstatusOn
                                        */
boolean_T VbACCS_Lon_Torq_Req;         /* '<S113>/Logical Operator1'
                                        * Ture means set positve torqerequirement
                                        */
boolean_T VbACCS_Lon_Accleration_Req;  /* '<S113>/Logical Operator3'
                                        * Only this flag is ture, the output acceleration is valid
                                        */
boolean_T VbACCS_EnableLaunchToSpdRamp;/* '<S111>/MATLAB Function'
                                        * Launch to Speed ramp enable
                                        */
boolean_T VbACCS_EnableLaunchToFollowRamp;/* '<S111>/MATLAB Function'
                                           * Launch to follow ramp enable
                                           */
boolean_T VbACCS_EnableSpeedToFollowRamp;/* '<S111>/MATLAB Function'
                                          * Speed to follow ramp enable
                                          */
boolean_T VbACCS_EnableFollowToSpeedRamp;/* '<S111>/MATLAB Function'
                                          * Follow to speed ramp enable
                                          */
boolean_T VbACCS_InputInfError;        /* '<S33>/Logical Operator13'
                                        * This will be true if input information has error
                                        */
boolean_T VbACCS_Obs_validBeforeDelay; /* '<S48>/Logical Operator'
                                        * Obs valid before delay
                                        */
boolean_T VbACCS_Input_Obs_valid;      /* '<S66>/Switch'
                                        * Has CIPV
                                        */
boolean_T VbACCS_CIPVObsRangeFlicker;  /* '<S48>/Signal Conversion1'
                                        * This is the flag to show whether the obstacle's range is changing abnormaly
                                        */
boolean_T VbACCS_BrakePedalPress;      /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0'
                                        * Driver press brake pedal
                                        */
boolean_T VbACCS_EPB_Engaged;          /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0'
                                        * EPB engaged
                                        */
boolean_T VbACCS_DriverHasSetSpeed;    /* '<S34>/Relational Operator1'
                                        * Driver has set speed for ACCS
                                        */
boolean_T VbACCS_NeedRespStopFrmDCSN;  /* '<S18>/Logical Operator'
                                        * Ture: ACCS need response DCSN stop requirement
                                        */
boolean_T VbACCS_Input_stop_request_DCSN;/* '<S8>/Switch'
                                          * Has Stop request from DCSN model
                                          */
boolean_T VbACCS_Input_NoSpdLimit;     /* '<S8>/Relational Operator'
                                        * If DCSN module speed limit reason is Nolimit, this flag will set true
                                        */
boolean_T VbACCS_Input_brake_ctrl_enable_DCSN;/* '<S8>/Signal Conversion1'
                                               * Brake control enable from DCSN
                                               */
boolean_T VbACCS_Input_acc_feature_enable_DCSN;/* '<S8>/Signal Conversion2'
                                                * ACC ffeature control enable from DCSN
                                                */
boolean_T VbACCS_Input_power_ctrl_enable_DCSN;/* '<S8>/Signal Conversion4'
                                               * Power control enable from DCSN module
                                               */
EnumACCS_StandbyType VeACCS_EnterStandbyType;/* '<S16>/Switch1'
                                              * 0:NoEnterStandby
                                                1:FromModeOffToStandby
                                                2:FromSpeedCtrlToStandby
                                                3:FromFollowingCtrlToStandby
                                                4:FromLowSpeedToStandby
                                                5:FromTempStopToStandby
                                                6:FromStopToStandby
                                                7:FromLaunchToStandby
                                                8:FromFaultToStandby
                                                9:DriverGasPedalOverride
                                                10:PressCancelSwitch
                                              */
EnumACCS_StandbyType VeACCS_EnterStandbyState;/* '<S137>/DtrmnACCS_ModeStateTransfer'
                                               * 0:NoEnterStandby
                                                 1:FromModeOffToStandby
                                                 2:FromSpeedCtrlToStandby
                                                 3:FromFollowingCtrlToStandby
                                                 4:FromLowSpeedToStandby
                                                 5:FromTempStopToStandby
                                                 6:FromStopToStandby
                                                 7:FromLaunchToStandby
                                                 8:FromFaultToStandby
                                                 9:DriverGasPedalOverride
                                                 10:PressCancelSwitch
                                               */
EnumACCS_Mode VeACCS_ModeState;        /* '<S137>/DtrmnACCS_ModeStateTransfer'
                                        * 0:ACCS_mode_off
                                          1:ACCS_mode_on
                                          2:ACCS_mode_standby
                                          3:ACCS_mode_fault

                                        */
EnumACCS_RunStatus VeACCS_RunStatus;   /* '<S16>/Switch'
                                        * 0:ACCS_status_off
                                          1:ACCS_status_on
                                          2:ACCS_status_Standby
                                          3:ACCS_status_SpeedCtrl
                                          4:ACCS_status_FollowingCtrl
                                          5:ACCS_status_TempStop
                                          6:ACCS_status_Stop
                                          7:ACCS_status_Launch
                                          8:ACCS_status_LowSpeed
                                          9:ACCS_status_Fault
                                        */
EnumACCS_RunStatus VeACCS_RunStatusFrmMode;/* '<S137>/DtrmnACCS_ModeStateTransfer'
                                            * 0:ACCS_status_off
                                              1:ACCS_status_on
                                              2:ACCS_status_Standby
                                              3:ACCS_status_SpeedCtrl
                                              4:ACCS_status_FollowingCtrl
                                              5:ACCS_status_TempStop
                                              6:ACCS_status_Stop
                                              7:ACCS_status_Launch
                                              8:ACCS_status_LowSpeed
                                              9:ACCS_status_Fault
                                            */
EnumACCS_RunStatus VeACCS_RunStatusBeforeFault;/* '<S137>/DtrmnACCS_ModeStateTransfer'
                                                * 0:ACCS_status_off
                                                  1:ACCS_status_on
                                                  2:ACCS_status_Standby
                                                  3:ACCS_status_SpeedCtrl
                                                  4:ACCS_status_FollowingCtrl
                                                  5:ACCS_status_TempStop
                                                  6:ACCS_status_Stop
                                                  7:ACCS_status_Launch
                                                  8:ACCS_status_LowSpeed
                                                  9:ACCS_status_Fault
                                                */
ACCS_CIPVChangedType VeACCS_CIPVChangedType;/* '<S48>/Signal Conversion3'
                                             * This is the signal to show the CIPV changed type
                                             */
EnumACCS_StatusTransferType VeACCS_StatusTransferType;/* '<S16>/Switch5'
                                                       * 0:NoTransfer
                                                         1:FromOnToStop
                                                         2:FromOnToSpeedCtrl
                                                         3:FromSpeedToLowSpeed
                                                         4:FromSpeedToFollowing
                                                         5:FromLowSpeedToFollowing
                                                         6:FromLowSpeedToTempStop
                                                         7:FromLowSpeedToSpeed
                                                         8:FromTempStopToStop
                                                         9:FromTempStopToLaunch
                                                         10:FromStopToLaunch
                                                         11:FromLaunchToFollowingCtrl
                                                         12:FromLaunchToLowSpeed
                                                         13:FromLaunchToSpeedCtrl
                                                         14:FromLaunchToTempStop
                                                         15:FromFollowingToSpeedCtrl
                                                         16:FromFollowingToLowSpeed
                                                       */
EnumACCS_FaultState VeACCS_FaultState; /* '<S136>/Switch'
                                        * 0:NoEnterFault
                                          1:FromStatusOnToFault
                                          2:FromSpeedCtrlToFault
                                          3:FromFollowingCtrlToFault
                                          4:FromLowSpeedToFault
                                          5:FromTempStopToFault
                                          6:FromStopToFault
                                          7:FromLaunchToFault
                                          8:FromStandbyToFault
                                        */
#pragma section ".cal"
/* Exported block parameters */
real_T KfACCS_v_SpdMinForCloseDisappear = 2.0;/* Variable: KfACCS_v_SpdMinForCloseDisappear
                                               * Referenced by: '<S56>/Constant24'
                                               * This minimum speed for selecting this type target
                                               */
real32_T KaACCS_t_TimeGapFrmDriver[4] =
{
  1.5F, 2.0F, 2.5F, 3.0F
} ;                                    /* Variable: KaACCS_t_TimeGapFrmDriver
                                        * Referenced by: '<S34>/KaACCS_t_TimeGapFrmDriver'
                                        * Time gap from driver
                                        */

real32_T KcACCS_ABSActvieCntDisableACCThrsh = 2000.0F;/* Variable: KcACCS_ABSActvieCntDisableACCThrsh
                                                       * Referenced by: '<S34>/Constant10'
                                                       * ABS active timer is bigger than this calibration, ACCS will enter standby
                                                       */
real32_T KcACCS_DtrmFlickerThresh = 6.0F;/* Variable: KcACCS_DtrmFlickerThresh
                                          * Referenced by: '<S47>/Constant6'
                                          * Rnage flicker count thresh
                                          */
real32_T KfACCS_Ang_DtrmSelfChangeLane = 0.3F;/* Variable: KfACCS_Ang_DtrmSelfChangeLane
                                               * Referenced by: '<S56>/Constant15'
                                               * Thie is the steering angle to determine whether vehicle is changing lane
                                               */
real32_T KfACCS_M_StandardTorqForPercent = 400.0F;/* Variable: KfACCS_M_StandardTorqForPercent
                                                   * Referenced by: '<S114>/Constant2'
                                                   * This is standard torr for calculate percent
                                                   */
real32_T KfACCS_Pct_DriverPressGasPedalThrsh = 5.0F;/* Variable: KfACCS_Pct_DriverPressGasPedalThrsh
                                                     * Referenced by: '<S155>/DtrmnACCS_WhetherPressGasPedal'
                                                     * If the gas pedal is bigger than this calibration,determine driver preee the pedal
                                                     */
real32_T KfACCS_Pct_GasPedalOverrideThrsh = 15.0F;/* Variable: KfACCS_Pct_GasPedalOverrideThrsh
                                                   * Referenced by: '<S148>/Constant25'
                                                   * As KbACCS_DirectlyUsePedalToJudgeOverride=True,if gas pedal is bigger than this calibration, ACCS will enter pedal override standby status
                                                   */
real32_T KfACCS_Pct_VirtualGasPedal = 0.0F;/* Variable: KfACCS_Pct_VirtualGasPedal
                                            * Referenced by: '<S7>/Constant13'
                                            * This is only for test.As KbACCS_UseVirtualPedal=True, use this calibration as the Gas pedal
                                            */
real32_T KfACCS_a_AccelCmdDeadZone = 0.02F;/* Variable: KfACCS_a_AccelCmdDeadZone
                                            * Referenced by: '<S113>/Constant7'
                                            * When want to accelerate, the acceleration must bigger than this cal.
                                            */
real32_T KfACCS_a_BrakeCmdDeadZone = -0.02F;/* Variable: KfACCS_a_BrakeCmdDeadZone
                                             * Referenced by: '<S113>/Constant5'
                                             * When want to decelerate, the acceleration must bigger than this cal.
                                             */
real32_T KfACCS_a_FollowToSpdRampDownStep = 0.02F;/* Variable: KfACCS_a_FollowToSpdRampDownStep
                                                   * Referenced by: '<S111>/MATLAB Function'
                                                   * Ramp down step under VbACCS_EnableFollowToSpdRamp=True
                                                   */
real32_T KfACCS_a_FollowToSpdRampUpStep = 0.02F;/* Variable: KfACCS_a_FollowToSpdRampUpStep
                                                 * Referenced by: '<S111>/MATLAB Function'
                                                 * Ramp up step under VbACCS_EnableFollowToSpdRamp=True
                                                 */
real32_T KfACCS_a_LaunchToFollowRampDownStep = 0.02F;/* Variable: KfACCS_a_LaunchToFollowRampDownStep
                                                      * Referenced by: '<S111>/MATLAB Function'
                                                      * Ramp down under VbACCS_EnableLaunchToFollowRamp=True
                                                      */
real32_T KfACCS_a_LaunchToFollowRampUpStep = 0.02F;/* Variable: KfACCS_a_LaunchToFollowRampUpStep
                                                    * Referenced by: '<S111>/MATLAB Function'
                                                    * Ramp up under VbACCS_EnableLaunchToFollowRamp=True
                                                    */
real32_T KfACCS_a_LaunchToSpdRampDownStep = 0.02F;/* Variable: KfACCS_a_LaunchToSpdRampDownStep
                                                   * Referenced by: '<S111>/MATLAB Function'
                                                   * Ramp down step under VbACCS_EnableLaunchToSpdRamp=True
                                                   */
real32_T KfACCS_a_LaunchToSpdRampUpStep = 0.02F;/* Variable: KfACCS_a_LaunchToSpdRampUpStep
                                                 * Referenced by: '<S111>/MATLAB Function'
                                                 * Ramp up step under VbACCS_EnableLaunchToSpdRamp=True
                                                 */
real32_T KfACCS_a_LinearAcc_PreSet = 0.0F;/* Variable: KfACCS_a_LinearAcc_PreSet
                                           * Referenced by:
                                           *   '<S39>/Constant45'
                                           *   '<S40>/Constant45'
                                           *   '<S41>/Constant45'
                                           *   '<S42>/Constant45'
                                           *   '<S43>/Constant45'
                                           * when KbACCS_UseVirtualObject=true, object linearAcc is from this calibration
                                           */
real32_T KfACCS_a_LowSpdToTempStpAccelThrsh = 0.0F;/* Variable: KfACCS_a_LowSpdToTempStpAccelThrsh
                                                    * Referenced by: '<S150>/Constant31'
                                                    * If want from low speed to Temp stop, desired acceleration need bigger than thhi calibration
                                                    */
real32_T KfACCS_a_ObjectAccelUpdateThrsh = 0.05F;/* Variable: KfACCS_a_ObjectAccelUpdateThrsh
                                                  * Referenced by:
                                                  *   '<S44>/Constant47'
                                                  *   '<S68>/Constant47'
                                                  *   '<S75>/Constant47'
                                                  *   '<S82>/Constant47'
                                                  *   '<S89>/Constant47'
                                                  *   '<S96>/Constant47'
                                                  * Only object acceleration change is bigger than this calibration, set the new acceleration
                                                  */
real32_T KfACCS_a_OutAccelHiThrsh = 4.0F;/* Variable: KfACCS_a_OutAccelHiThrsh
                                          * Referenced by: '<S103>/Constant5'
                                          * The Max threshold for output acceleration
                                          */
real32_T KfACCS_a_OutAccelLoThrsh = -2.5F;/* Variable: KfACCS_a_OutAccelLoThrsh
                                           * Referenced by: '<S103>/Constant7'
                                           * The Min threshold for output acceleration
                                           */
real32_T KfACCS_a_SpeedToFollowRampDownStep = 0.02F;/* Variable: KfACCS_a_SpeedToFollowRampDownStep
                                                     * Referenced by: '<S111>/MATLAB Function'
                                                     * Ramp down under VbACCS_EnableSpeedToFollowRamp=True
                                                     */
real32_T KfACCS_a_SpeedToFollowRampUpStep = 0.02F;/* Variable: KfACCS_a_SpeedToFollowRampUpStep
                                                   * Referenced by: '<S111>/MATLAB Function'
                                                   * Ramp up under VbACCS_EnableSpeedToFollowRamp=True
                                                   */
real32_T KfACCS_a_StatusFollowAcceleRampDownStep = 0.02F;/* Variable: KfACCS_a_StatusFollowAcceleRampDownStep
                                                          * Referenced by: '<S111>/MATLAB Function'
                                                          * Acceleration Ramp down under Following control status
                                                          */
real32_T KfACCS_a_StatusFollowAcceleRampUpStep = 0.02F;/* Variable: KfACCS_a_StatusFollowAcceleRampUpStep
                                                        * Referenced by: '<S111>/MATLAB Function'
                                                        * Acceleration Ramp up under Following control status
                                                        */
real32_T KfACCS_a_StatusSpeedAcceleRampDownStep = 0.02F;/* Variable: KfACCS_a_StatusSpeedAcceleRampDownStep
                                                         * Referenced by: '<S111>/MATLAB Function'
                                                         * Ramp down step under Speed control status
                                                         */
real32_T KfACCS_a_StatusSpeedAcceleRampUpStep = 0.02F;/* Variable: KfACCS_a_StatusSpeedAcceleRampUpStep
                                                       * Referenced by: '<S111>/MATLAB Function'
                                                       * Ramp up step under Speed control status
                                                       */
real32_T KfACCS_a_TempStpToLaunchAccelThrsh = 0.0F;/* Variable: KfACCS_a_TempStpToLaunchAccelThrsh
                                                    * Referenced by: '<S150>/Constant29'
                                                    * If want to from temp stop to launch, the acceleration need bigger than this calibration
                                                    */
real32_T KfACCS_d_ChangedObsRangeLatDiff = 0.1F;/* Variable: KfACCS_d_ChangedObsRangeLatDiff
                                                 * Referenced by: '<S56>/Constant1'
                                                 * This is the lateral range difference to determine whether the target is a changed target
                                                 */
real32_T KfACCS_d_ChangedObsRangeLongDiff = 0.05F;/* Variable: KfACCS_d_ChangedObsRangeLongDiff
                                                   * Referenced by: '<S56>/Constant'
                                                   * This is the longitudinal range difference to determine whether the target is a changed target
                                                   */
real32_T KfACCS_d_ConsiderObsMaxLat = 6.0F;/* Variable: KfACCS_d_ConsiderObsMaxLat
                                            * Referenced by: '<S49>/Constant2'
                                            * If the vehicle's lateral distance is greater than this calibration, ACCS will not choose is as target
                                            */
real32_T KfACCS_d_CurvatureRadius_Max = 8000.0F;/* Variable: KfACCS_d_CurvatureRadius_Max
                                                 * Referenced by:
                                                 *   '<S45>/Constant7'
                                                 *   '<S45>/Constant9'
                                                 *   '<S69>/Constant7'
                                                 *   '<S69>/Constant9'
                                                 *   '<S76>/Constant7'
                                                 *   '<S76>/Constant9'
                                                 *   '<S83>/Constant7'
                                                 *   '<S83>/Constant9'
                                                 *   '<S90>/Constant7'
                                                 *   '<S90>/Constant9'
                                                 *   '<S97>/Constant7'
                                                 *   '<S97>/Constant9'
                                                 * If curvature radius is bigger than this calibration, the road is set straight roade
                                                 */
real32_T KfACCS_d_DisToLeadSur = 2.0F; /* Variable: KfACCS_d_DisToLeadSur
                                        * Referenced by:
                                        *   '<S45>/Constant8'
                                        *   '<S69>/Constant8'
                                        *   '<S76>/Constant8'
                                        *   '<S83>/Constant8'
                                        *   '<S90>/Constant8'
                                        *   '<S97>/Constant8'
                                        * The distance between the vehicle head and Rear axle center
                                        */
real32_T KfACCS_d_DisToSideSur = 1.25F;/* Variable: KfACCS_d_DisToSideSur
                                        * Referenced by:
                                        *   '<S45>/Constant10'
                                        *   '<S69>/Constant10'
                                        *   '<S76>/Constant10'
                                        *   '<S83>/Constant10'
                                        *   '<S90>/Constant10'
                                        *   '<S97>/Constant10'
                                        * The distance between the vehicle side and Rear axle center
                                        */
real32_T KfACCS_d_FlickerRangeDiffLimit = 5.0F;/* Variable: KfACCS_d_FlickerRangeDiffLimit
                                                * Referenced by: '<S47>/Constant8'
                                                * This is the range rate difference limit of last loop for detecting range flicker function
                                                */
real32_T KfACCS_d_FlickerRangeLatLimit = 5.0F;/* Variable: KfACCS_d_FlickerRangeLatLimit
                                               * Referenced by: '<S47>/Constant1'
                                               * This is the lateral range limit for detecting range flicker function
                                               */
real32_T KfACCS_d_FlickerRangeLongLimit = 110.0F;/* Variable: KfACCS_d_FlickerRangeLongLimit
                                                  * Referenced by: '<S47>/Constant7'
                                                  * This is the longitude range limit for detecting range flicker function
                                                  */
real32_T KfACCS_d_FollowingToLowSpdRRThrsh = 5.0F;/* Variable: KfACCS_d_FollowingToLowSpdRRThrsh
                                                   * Referenced by: '<S150>/Constant15'
                                                   * If want from following control to low speed mode ,the CIPV range rate need smaller than this calibration
                                                   */
real32_T KfACCS_d_LatRangeMaxForCloseDisappear = 1.5F;/* Variable: KfACCS_d_LatRangeMaxForCloseDisappear
                                                       * Referenced by: '<S56>/Constant25'
                                                       *
                                                         The maximum lateral range for selecting this type target

                                                       */
real32_T KfACCS_d_LatRangeMinForCloseDisappear = 0.0F;/* Variable: KfACCS_d_LatRangeMinForCloseDisappear
                                                       * Referenced by: '<S56>/Constant26'
                                                       * The minimum lateral range for selecting this type target
                                                       */
real32_T KfACCS_d_LonRangeMaxForCloseDisappear = 2.5F;/* Variable: KfACCS_d_LonRangeMaxForCloseDisappear
                                                       * Referenced by: '<S56>/Constant21'
                                                       * The maximum longitude range for selecting this type target
                                                       */
real32_T KfACCS_d_LonRangeMinForCloseDisappear = 1.5F;/* Variable: KfACCS_d_LonRangeMinForCloseDisappear
                                                       * Referenced by: '<S56>/Constant22'
                                                       * The minimum longitude range for selecting this type target
                                                       */
real32_T KfACCS_d_LowSpdToTempStpDisThrsh = 1.5F;/* Variable: KfACCS_d_LowSpdToTempStpDisThrsh
                                                  * Referenced by:
                                                  *   '<S150>/Constant21'
                                                  *   '<S150>/Constant23'
                                                  *   '<S150>/Constant38'
                                                  * If want from low speed to Temp stop, the stop distance need smaller than this calibration
                                                  */
real32_T KfACCS_d_MaxRange = 200.0F;   /* Variable: KfACCS_d_MaxRange
                                        * Referenced by: '<S34>/KfACCS_d_MaxRange'
                                        * CIPV target range will be limit by this cal
                                        */
real32_T KfACCS_d_MinimumRange = 5.0F; /* Variable: KfACCS_d_MinimumRange
                                        * Referenced by: '<S34>/KfACCS_d_MinimumRange'
                                        * The drive set target range and this cal to chose max as target range
                                        */
real32_T KfACCS_d_RangeForApproaching = 60.0F;/* Variable: KfACCS_d_RangeForApproaching
                                               * Referenced by: '<S56>/Constant9'
                                               * This is the range to determine the status of approaching
                                               */
real32_T KfACCS_d_RangeForAway = 60.0F;/* Variable: KfACCS_d_RangeForAway
                                        * Referenced by: '<S56>/Constant14'
                                        * This is the range to determine the status of away.
                                        */
real32_T KfACCS_d_RangePIDCtrl_RangeErrlimit = 20.0F;/* Variable: KfACCS_d_RangePIDCtrl_RangeErrlimit
                                                      * Referenced by:
                                                      *   '<S18>/Constant1'
                                                      *   '<S18>/Constant3'
                                                      * Range error limit for Range Pid control
                                                      */
real32_T KfACCS_d_Range_PreSet = 10.0F;/* Variable: KfACCS_d_Range_PreSet
                                        * Referenced by:
                                        *   '<S39>/Constant39'
                                        *   '<S40>/Constant39'
                                        *   '<S41>/Constant39'
                                        *   '<S42>/Constant39'
                                        *   '<S43>/Constant39'
                                        * when KbACCS_UseVirtualObject=true, object range is from this calibration
                                        */
real32_T KfACCS_d_TempStopToLaunchRRThrsh = 1.4F;/* Variable: KfACCS_d_TempStopToLaunchRRThrsh
                                                  * Referenced by: '<S150>/Constant34'
                                                  * Under Temp stop and there is CIPV, if want from Temp stop to launch ,the CIPV range rate
                                                    need bigger than this calibration
                                                  */
real32_T KfACCS_d_TempStpToLaunchDisThrsh = 1.5F;/* Variable: KfACCS_d_TempStpToLaunchDisThrsh
                                                  * Referenced by:
                                                  *   '<S150>/Constant28'
                                                  *   '<S150>/Constant33'
                                                  * If want from Temp stop to launch, the stop distance need bigger than this calibration
                                                  */
real32_T KfACCS_d_VitualStopDisFrmDCSN = 50.0F;/* Variable: KfACCS_d_VitualStopDisFrmDCSN
                                                * Referenced by: '<S8>/Constant1'
                                                * This is only for test
                                                  Vitual Stop distance as KbACCS_UseVitualDCSNInfo=True
                                                */
real32_T KfACCS_k_DrsdAccelFilter = 0.7F;/* Variable: KfACCS_k_DrsdAccelFilter
                                          * Referenced by: '<S103>/Constant1'
                                          * Filter for acceleration
                                          */
real32_T KfACCS_k_EgoPitchFilter = 0.5F;/* Variable: KfACCS_k_EgoPitchFilter
                                         * Referenced by: '<S103>/Constant6'
                                         * Filter for Pitch
                                         */
real32_T KfACCS_k_ObjectAccelFilter = 0.1F;/* Variable: KfACCS_k_ObjectAccelFilter
                                            * Referenced by:
                                            *   '<S44>/Constant46'
                                            *   '<S68>/Constant46'
                                            *   '<S75>/Constant46'
                                            *   '<S82>/Constant46'
                                            *   '<S89>/Constant46'
                                            *   '<S96>/Constant46'
                                            * Filter for object acceleration
                                            */
real32_T KfACCS_k_ObjectRangeFilter = 0.1F;/* Variable: KfACCS_k_ObjectRangeFilter
                                            * Referenced by:
                                            *   '<S45>/Constant15'
                                            *   '<S45>/Constant46'
                                            *   '<S69>/Constant15'
                                            *   '<S69>/Constant46'
                                            *   '<S76>/Constant15'
                                            *   '<S76>/Constant46'
                                            *   '<S83>/Constant15'
                                            *   '<S83>/Constant46'
                                            *   '<S90>/Constant15'
                                            *   '<S90>/Constant46'
                                            *   '<S97>/Constant15'
                                            *   '<S97>/Constant46'
                                            * Filter for object range
                                            */
real32_T KfACCS_k_ObjectSpdFilter = 0.1F;/* Variable: KfACCS_k_ObjectSpdFilter
                                          * Referenced by:
                                          *   '<S44>/Constant48'
                                          *   '<S44>/Constant50'
                                          *   '<S68>/Constant48'
                                          *   '<S68>/Constant50'
                                          *   '<S75>/Constant48'
                                          *   '<S75>/Constant50'
                                          *   '<S82>/Constant48'
                                          *   '<S82>/Constant50'
                                          *   '<S89>/Constant48'
                                          *   '<S89>/Constant50'
                                          *   '<S96>/Constant48'
                                          *   '<S96>/Constant50'
                                          * Filter for object speed
                                          */
real32_T KfACCS_t_CIPVChangedTypeDelay = 3.0F;/* Variable: KfACCS_t_CIPVChangedTypeDelay
                                               * Referenced by: '<S46>/Constant4'
                                               * This is the time to determin how long the state of the obstacle change will last
                                               */
real32_T KfACCS_t_CIPVDisappearDelay = 0.1F;/* Variable: KfACCS_t_CIPVDisappearDelay
                                             * Referenced by:
                                             *   '<S60>/Constant4'
                                             *   '<S61>/Constant4'
                                             *   '<S62>/Constant4'
                                             *   '<S63>/Constant4'
                                             *   '<S64>/Constant4'
                                             *   '<S65>/Constant4'
                                             *   '<S66>/Constant4'
                                             *   '<S67>/Constant4'
                                             * This is the time to determin how long the obstacle's information will last when it is disappeared
                                             */
real32_T KfACCS_t_DtrmSelfChangeLane = 1.0F;/* Variable: KfACCS_t_DtrmSelfChangeLane
                                             * Referenced by: '<S56>/Constant18'
                                             * If wheel steering bigger than KfACCS_Ang_DtrmSelfChangeLane,timer++, as timer>this calibration, sriver seft change lane
                                             */
real32_T KfACCS_t_DtrmSelfChangeLaneDelay = 3.0F;/* Variable: KfACCS_t_DtrmSelfChangeLaneDelay
                                                  * Referenced by: '<S56>/Constant17'
                                                  * This is delay time to determine whether vehicle is changing lane
                                                  */
real32_T KfACCS_t_EnterLowSpeedDelay = 1.0F;/* Variable: KfACCS_t_EnterLowSpeedDelay
                                             * Referenced by:
                                             *   '<S150>/Constant12'
                                             *   '<S150>/Constant5'
                                             * If the Ego speed is smaller than KfACCS_SpdToLowSpdCtrlSpdThrsh under Speed control or KfACCS_FollowingToLowSpdThrsh under following control, the timer will increase,
                                               as the timer is bingger than this calibration, will enter low speed mode.
                                             */
real32_T KfACCS_t_ExitLaunchTimer = 60.0F;/* Variable: KfACCS_t_ExitLaunchTimer
                                           * Referenced by: '<S138>/DtrmnACCS_RunStatusTransfer'
                                           * If at the launch mode timer than this calibration, will exit launch mode
                                           */
real32_T KfACCS_t_ExitLowSpeedDelay = 1.0F;/* Variable: KfACCS_t_ExitLowSpeedDelay
                                            * Referenced by:
                                            *   '<S150>/Constant17'
                                            *   '<S150>/Constant8'
                                            * If Ego speed is bigger than KfACCS_LowSpdToSpdCtrlSpdThrsh under speed control or KfACCS_LowSpdToFollowingSpdThrsh under following control,
                                              the timer will increase, and timer is bigger than this calibration,will exit low speed mode
                                            */
real32_T KfACCS_t_FollowToSpdRampTimerThrsh = 5.0F;/* Variable: KfACCS_t_FollowToSpdRampTimerThrsh
                                                    * Referenced by: '<S111>/MATLAB Function'
                                                    * Hold timer for VbACCS_EnableFollowToSpdRamp as from Follow to speed
                                                    */
real32_T KfACCS_t_LaunchToFollowRampTimerThrsh = 5.0F;/* Variable: KfACCS_t_LaunchToFollowRampTimerThrsh
                                                       * Referenced by: '<S111>/MATLAB Function'
                                                       * Hold timer for VbACCS_EnableLaunchToFollowRamp as from Launch to follow
                                                       */
real32_T KfACCS_t_LaunchToLowSpdTm = 60.0F;/* Variable: KfACCS_t_LaunchToLowSpdTm
                                            * Referenced by: '<S138>/DtrmnACCS_RunStatusTransfer'
                                            * Under launch mode,Ego_CurrentSpeed<=KfACCS_LaunchToLowSpdSpeedThrsh)and (Ego_CurrentSpeed>KfACCS_MovingMinSpeedThrsh,
                                              the timer will increase, when the timer is bigger than this calibration, will from launch change to Low speed
                                            */
real32_T KfACCS_t_LaunchToSpdRampTimerThrsh = 5.0F;/* Variable: KfACCS_t_LaunchToSpdRampTimerThrsh
                                                    * Referenced by: '<S111>/MATLAB Function'
                                                    * Hold timer for VbACCS_EnableLaunchToSpdRamp as from launch to speed
                                                    */
real32_T KfACCS_t_LaunchToTempStpTm = 15.0F;/* Variable: KfACCS_t_LaunchToTempStpTm
                                             * Referenced by: '<S138>/DtrmnACCS_RunStatusTransfer'
                                             * Under launch , if Ego_CurrentSpeed<=KfACCS_MovingMinSpeedThrsh, the timer will increase, if
                                               the timer is bigger than this calibration, will from launch to Temp stop
                                             */
real32_T KfACCS_t_MaxTimerAllowAutoResume = 10.0F;/* Variable: KfACCS_t_MaxTimerAllowAutoResume
                                                   * Referenced by: '<S138>/DtrmnACCS_RunStatusTransfer'
                                                   * When stop timer bigger than this timer, if the driver want to launch the vehicle, he need
                                                     Press resume switch
                                                   */
real32_T KfACCS_t_PressGasPedalHoldTm = 3.0F;/* Variable: KfACCS_t_PressGasPedalHoldTm
                                              * Referenced by: '<S155>/DtrmnACCS_WhetherPressGasPedal'
                                              * If driver has press the gas pedal, we think driver presss the gas pedal during this calibratin timer.
                                              */
real32_T KfACCS_t_PressResumeHoldTm = 3.0F;/* Variable: KfACCS_t_PressResumeHoldTm
                                            * Referenced by: '<S155>/DtrmnACCS_WhetherPressResume'
                                            * If driver has press the resume switch, we think driver presss the resume switch during this calibratin timer.
                                            */
real32_T KfACCS_t_SpeedToFollowRampTimerThrsh = 5.0F;/* Variable: KfACCS_t_SpeedToFollowRampTimerThrsh
                                                      * Referenced by: '<S111>/MATLAB Function'
                                                      * Hold timer for VbACCS_EnableSpeedToFollowRamp as from Speed to follow
                                                      */
real32_T KfACCS_t_StopTooLongThrsh = 600.0F;/* Variable: KfACCS_t_StopTooLongThrsh
                                             * Referenced by: '<S150>/Constant39'
                                             * If the stop timer is bigger than this calibration, will from stop to enter standby
                                             */
real32_T KfACCS_t_TempStpToStpDelay = 30.0F;/* Variable: KfACCS_t_TempStpToStpDelay
                                             * Referenced by: '<S138>/DtrmnACCS_RunStatusTransfer'
                                             * If the stop timer is bigger than this calibration, will from Temp stop to stop
                                             */
real32_T KfACCS_t_TimeGapToCalcRange = 2.5F;/* Variable: KfACCS_t_TimeGapToCalcRange
                                             * Referenced by: '<S34>/kfACCS_TimeGapToCalcRange'
                                             * This is only for logic test.When KbACCS_CalTimeGap=true,useing this calibration to calculate the range
                                             */
real32_T KfACCS_t_TimeOffset = 0.01F;  /* Variable: KfACCS_t_TimeOffset
                                        * Referenced by:
                                        *   '<S45>/Constant13'
                                        *   '<S45>/Constant14'
                                        *   '<S69>/Constant13'
                                        *   '<S69>/Constant14'
                                        *   '<S76>/Constant13'
                                        *   '<S76>/Constant14'
                                        *   '<S83>/Constant13'
                                        *   '<S83>/Constant14'
                                        *   '<S90>/Constant13'
                                        *   '<S90>/Constant14'
                                        *   '<S97>/Constant13'
                                        *   '<S97>/Constant14'
                                        * This is only for logic test.Please hold the default value
                                        */
real32_T KfACCS_v_CalDriverSetSpeed = 20.0F;/* Variable: KfACCS_v_CalDriverSetSpeed
                                             * Referenced by: '<S34>/KfACCS_v_CalDriverSetSpeed'
                                             * When KbACCS_CalDriverSetSpeed=True, the drive speed is from this calibration
                                             */
real32_T KfACCS_v_ChangedObsVelDiff = 0.0F;/* Variable: KfACCS_v_ChangedObsVelDiff
                                            * Referenced by: '<S56>/Constant2'
                                            * This is the velocity difference to determine whether the target is a changed target
                                            */
real32_T KfACCS_v_ChooseStationaryObsMaxSpd = 10.0F;/* Variable: KfACCS_v_ChooseStationaryObsMaxSpd
                                                     * Referenced by: '<S49>/Constant'
                                                     * This is the speed limit for considering stationary target. If the car speed is lower than the limit, ACCS will choose stationary vehicle as target.
                                                     */
real32_T KfACCS_v_DeltaSped_EGMOAndCanThrsh = 45.0F;/* Variable: KfACCS_v_DeltaSped_EGMOAndCanThrsh
                                                     * Referenced by: '<S9>/Constant3'
                                                     * If speed error beween EGMO and Can bigger than this calibration,ACCS will use Can vehilce speed
                                                     */
real32_T KfACCS_v_DriverSetSpeedMinThrsh = 8.0F;/* Variable: KfACCS_v_DriverSetSpeedMinThrsh
                                                 * Referenced by: '<S34>/KfACCS_v_DriverSetSpeedMinThrsh'
                                                 * Driver set speed need bigger than this calibration to enable ACCS control
                                                 */
real32_T KfACCS_v_EnableACCHiSpdThrsh = 36.0F;/* Variable: KfACCS_v_EnableACCHiSpdThrsh
                                               * Referenced by: '<S148>/Constant48'
                                               * The max speed for enable ACCS
                                               */
real32_T KfACCS_v_EnableACCLoSpdThrsh = 0.0F;/* Variable: KfACCS_v_EnableACCLoSpdThrsh
                                              * Referenced by: '<S148>/Constant46'
                                              * The min speed for ACCS
                                              */
real32_T KfACCS_v_ExitLaunchSpeedThrsh = 6.0F;/* Variable: KfACCS_v_ExitLaunchSpeedThrsh
                                               * Referenced by: '<S138>/DtrmnACCS_RunStatusTransfer'
                                               * If the Ego speed is bigger than this cal, will exit launch mode.
                                               */
real32_T KfACCS_v_FlickerRangeEgoSpd = 30.0F;/* Variable: KfACCS_v_FlickerRangeEgoSpd
                                              * Referenced by: '<S47>/Constant3'
                                              * This is the maximum speed of ego car for range flicker function
                                              */
real32_T KfACCS_v_FlickerRangeRRForReset = 10.0F;/* Variable: KfACCS_v_FlickerRangeRRForReset
                                                  * Referenced by: '<S47>/Constant4'
                                                  * This is the maximum range rate for reset range flicker function
                                                  */
real32_T KfACCS_v_FlickerRangeRateLimit = 15.0F;/* Variable: KfACCS_v_FlickerRangeRateLimit
                                                 * Referenced by: '<S47>/Constant2'
                                                 * This is the range rate limit for detecting range flicker function
                                                 */
real32_T KfACCS_v_FollowingToLowSpdThrsh = 1.5F;/* Variable: KfACCS_v_FollowingToLowSpdThrsh
                                                 * Referenced by:
                                                 *   '<S150>/Constant13'
                                                 *   '<S150>/Constant14'
                                                 * If want from following control to low speed mode ,the Ego speed need smaller than this calibration
                                                 */
real32_T KfACCS_v_IgnoreObsSpdLimit = 0.2F;/* Variable: KfACCS_v_IgnoreObsSpdLimit
                                            * Referenced by: '<S49>/Constant4'
                                            * If the obstacle's speed is lower than the calibration, ACCS will take it as stationary target.
                                            */
real32_T KfACCS_v_LatSpdDeadband_Max = 1.0F;/* Variable: KfACCS_v_LatSpdDeadband_Max
                                             * Referenced by:
                                             *   '<S44>/Constant15'
                                             *   '<S44>/Constant17'
                                             *   '<S44>/Constant22'
                                             *   '<S68>/Constant15'
                                             *   '<S68>/Constant17'
                                             *   '<S68>/Constant22'
                                             *   '<S75>/Constant15'
                                             *   '<S75>/Constant17'
                                             *   '<S75>/Constant22'
                                             *   '<S82>/Constant15'
                                             *   '<S82>/Constant17'
                                             *   '<S82>/Constant22'
                                             *   '<S89>/Constant15'
                                             *   '<S89>/Constant17'
                                             *   '<S89>/Constant22'
                                             *   '<S96>/Constant15'
                                             *   '<S96>/Constant17'
                                             *   '<S96>/Constant22'
                                             * If the object latteral speed bigger than this calibration, use latteral speed
                                             */
real32_T KfACCS_v_LatSpdDeadband_Min = 0.5F;/* Variable: KfACCS_v_LatSpdDeadband_Min
                                             * Referenced by:
                                             *   '<S44>/Constant16'
                                             *   '<S44>/Constant18'
                                             *   '<S44>/Constant23'
                                             *   '<S68>/Constant16'
                                             *   '<S68>/Constant18'
                                             *   '<S68>/Constant23'
                                             *   '<S75>/Constant16'
                                             *   '<S75>/Constant18'
                                             *   '<S75>/Constant23'
                                             *   '<S82>/Constant16'
                                             *   '<S82>/Constant18'
                                             *   '<S82>/Constant23'
                                             *   '<S89>/Constant16'
                                             *   '<S89>/Constant18'
                                             *   '<S89>/Constant23'
                                             *   '<S96>/Constant16'
                                             *   '<S96>/Constant18'
                                             *   '<S96>/Constant23'
                                             * If the object latteral speed smaller than this calibration, set latteral speed to 0
                                             */
real32_T KfACCS_v_LatSpdUpdateThrsh = 0.2F;/* Variable: KfACCS_v_LatSpdUpdateThrsh
                                            * Referenced by:
                                            *   '<S44>/Constant26'
                                            *   '<S68>/Constant26'
                                            *   '<S75>/Constant26'
                                            *   '<S82>/Constant26'
                                            *   '<S89>/Constant26'
                                            *   '<S96>/Constant26'
                                            * Only object latteral speed change is bigger than this calibration, set the new latteral speed
                                            */
real32_T KfACCS_v_LaunchToLowSpdSpeedThrsh = 3.0F;/* Variable: KfACCS_v_LaunchToLowSpdSpeedThrsh
                                                   * Referenced by: '<S138>/DtrmnACCS_RunStatusTransfer'
                                                   * If want from launch to low speed, the ego speed need smaller tham this calibration
                                                   */
real32_T KfACCS_v_LinearVelocity_PreSet = 0.0F;/* Variable: KfACCS_v_LinearVelocity_PreSet
                                                * Referenced by:
                                                *   '<S39>/Constant42'
                                                *   '<S40>/Constant42'
                                                *   '<S41>/Constant42'
                                                *   '<S42>/Constant42'
                                                *   '<S43>/Constant42'
                                                * when KbACCS_UseVirtualObject=true, object LinearVelocity is from this calibration
                                                */
real32_T KfACCS_v_LowSpdToFollowingSpdThrsh = 3.0F;/* Variable: KfACCS_v_LowSpdToFollowingSpdThrsh
                                                    * Referenced by:
                                                    *   '<S150>/Constant18'
                                                    *   '<S150>/Constant19'
                                                    * If want from low speed to following control, the ego and CIPV speed need bigger than this calibration
                                                    */
real32_T KfACCS_v_LowSpdToSpdCtrlSpdThrsh = 3.0F;/* Variable: KfACCS_v_LowSpdToSpdCtrlSpdThrsh
                                                  * Referenced by: '<S150>/Constant9'
                                                  * If want from low speed to speed control, the ego current need bigger than this calibration
                                                  */
real32_T KfACCS_v_LowSpdToTempStpSpdThrsh = 0.2F;/* Variable: KfACCS_v_LowSpdToTempStpSpdThrsh
                                                  * Referenced by:
                                                  *   '<S150>/Constant20'
                                                  *   '<S150>/Constant22'
                                                  * If want from low speed to Temp stop, the ego speed need smaller than this calibration
                                                  */
real32_T KfACCS_v_MovingMinSpeedThrsh = 0.3F;/* Variable: KfACCS_v_MovingMinSpeedThrsh
                                              * Referenced by: '<S138>/DtrmnACCS_RunStatusTransfer'
                                              * If the Ego speed is bigger than this calibration, we think the vehicle is moving
                                              */
real32_T KfACCS_v_ObjectSpdUpdateThrsh = 0.5F;/* Variable: KfACCS_v_ObjectSpdUpdateThrsh
                                               * Referenced by:
                                               *   '<S44>/Constant25'
                                               *   '<S68>/Constant25'
                                               *   '<S75>/Constant25'
                                               *   '<S82>/Constant25'
                                               *   '<S89>/Constant25'
                                               *   '<S96>/Constant25'
                                               * Only object Long speed change is bigger than this calibration, set the new long speed
                                               */
real32_T KfACCS_v_OnToSpdCtrlSpdThrsh = 0.5F;/* Variable: KfACCS_v_OnToSpdCtrlSpdThrsh
                                              * Referenced by: '<S150>/Constant24'
                                              * If want from status_on to speed control,the ego current speed need bigger than this calibration
                                              */
real32_T KfACCS_v_RangeRateForApproaching = -0.1F;/* Variable: KfACCS_v_RangeRateForApproaching
                                                   * Referenced by: '<S56>/Constant10'
                                                   * This is the range rate to determine the status of approaching
                                                   */
real32_T KfACCS_v_RangeRateForAway = -0.1F;/* Variable: KfACCS_v_RangeRateForAway
                                            * Referenced by: '<S56>/Constant11'
                                            * This is the range rate to determine the status of away
                                            */
real32_T KfACCS_v_RangeRate_PreSet = 10.0F;/* Variable: KfACCS_v_RangeRate_PreSet
                                            * Referenced by:
                                            *   '<S39>/Constant37'
                                            *   '<S40>/Constant37'
                                            *   '<S41>/Constant37'
                                            *   '<S42>/Constant37'
                                            *   '<S43>/Constant37'
                                            * when KbACCS_UseVirtualObject=true, object range rate is from this calibration
                                            */
real32_T KfACCS_v_SpdMaxForCloseDisappear = 3.0F;/* Variable: KfACCS_v_SpdMaxForCloseDisappear
                                                  * Referenced by: '<S56>/Constant23'
                                                  * The maximum speed for selecting this type target
                                                  */
real32_T KfACCS_v_SpdPIDCtrl_SpdErrlimit = 3.0F;/* Variable: KfACCS_v_SpdPIDCtrl_SpdErrlimit
                                                 * Referenced by:
                                                 *   '<S106>/Constant1'
                                                 *   '<S106>/Constant3'
                                                 * Speed error limit for Speed Pid control
                                                 */
real32_T KfACCS_v_SpdToLowSpdCtrlSpdThrsh = 1.5F;/* Variable: KfACCS_v_SpdToLowSpdCtrlSpdThrsh
                                                  * Referenced by: '<S150>/Constant6'
                                                  * If want from speed control to low speed control, the ego speed need smaller than this calibration
                                                  */
real32_T KfACCS_v_TempStpToLaunchSpdThrsh = 1.0F;/* Variable: KfACCS_v_TempStpToLaunchSpdThrsh
                                                  * Referenced by:
                                                  *   '<S150>/Constant27'
                                                  *   '<S150>/Constant30'
                                                  * If want from Temp stop to launch, the driver speed need bigger than this calibration
                                                  */
real32_T KfACCS_v_VitualSpeedLimitFrmDCSN = 30.0F;/* Variable: KfACCS_v_VitualSpeedLimitFrmDCSN
                                                   * Referenced by: '<S8>/Constant3'
                                                   * This is only for test
                                                     Vitual Speed limit as KbACCS_UseVitualDCSNInfo=True
                                                   */
real32_T KtACCS_AXIS_AccelToGasPedal_Accel[17] =
{
  -4.0F, -3.5F, -3.0F, -2.5F, -2.0F, -1.5F, -1.0F, -0.5F, 0.0F, 0.5F, 1.0F, 1.5F,
  2.0F, 2.5F, 3.0F, 3.5F, 4.0F
} ;                                    /* Variable: KtACCS_AXIS_AccelToGasPedal_Accel
                                        * Referenced by: '<S114>/KtACCS_Pct_AccelToGasPedal '
                                        * This is acceleration axis for KtACCS_AccelToGasPedal
                                        */

real32_T KtACCS_AXIS_AccelToGasPedal_VehSpd[10] =
{
  0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 40.0F, 45.0F
} ;                                    /* Variable: KtACCS_AXIS_AccelToGasPedal_VehSpd
                                        * Referenced by: '<S114>/KtACCS_Pct_AccelToGasPedal '
                                        * This is vehicle speed for KtACCS_AccelToGasPedal
                                        */

real32_T KtACCS_AXIS_DCSNStopDisGain_d[13] =
{
  0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 30.0F, 40.0F, 50.0F, 60.0F, 70.0F, 80.0F,
  90.0F, 100.0F
} ;                                    /* Variable: KtACCS_AXIS_DCSNStopDisGain_d
                                        * Referenced by: '<S103>/KtACCS_r_DCSNStopDistanceGain '
                                        * This is distance axis for calibration KtACCS_r_DCSNStopDistanceGain
                                        */

real32_T KtACCS_AXIS_DCSNStopGainSpd_SpdErr[11] =
{
  -50.0F, -40.0F, -30.0F, -20.0F, -10.0F, 0.0F, 10.0F, 20.0F, 30.0F, 40.0F,
  50.0F
} ;                                    /* Variable: KtACCS_AXIS_DCSNStopGainSpd_SpdErr
                                        * Referenced by: '<S103>/KtACCS_r_DCSNStopSpdGain'
                                        * This is speed error for KtACCS_r_DCSNStopSpdGain
                                        */

real32_T KtACCS_AXIS_DCSNStopGain_VehSpd[11] =
{
  0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 40.0F, 45.0F, 50.0F
} ;                                    /* Variable: KtACCS_AXIS_DCSNStopGain_VehSpd
                                        * Referenced by:
                                        *   '<S103>/KtACCS_r_DCSNStopDistanceGain '
                                        *   '<S103>/KtACCS_r_DCSNStopSpdGain'
                                        * This is speed axis for KtACCS_r_DCSNStopDistanceGain and KtACCS_r_DCSNStopSpdGain
                                        */

real32_T KtACCS_AXIS_DCSNStopThrshHi_Spd[6] =
{
  0.0F, 10.0F, 20.0F, 30.0F, 40.0F, 50.0F
} ;                                    /* Variable: KtACCS_AXIS_DCSNStopThrshHi_Spd
                                        * Referenced by: '<S18>/KtACCS_d_RespDCSNStopThrshHi'
                                        * This is axis for KtACCS_d_RespDCSNStopThrshHi
                                        */

real32_T KtACCS_AXIS_OpenAccelFwCtrl_RR[7] =
{
  -15.0F, -10.0F, -5.0F, 0.0F, 5.0F, 10.0F, 15.0F
} ;                                    /* Variable: KtACCS_AXIS_OpenAccelFwCtrl_RR
                                        * Referenced by:
                                        *   '<S24>/KtACCS_a_OpenAccel_FollowCtrl'
                                        *   '<S24>/KtACCS_a_OpenAccel_FollowCtrl1'
                                        * This is speed error(Range rate) axis for KtACCS_OpenAccel_FollowCtrl
                                        */

real32_T KtACCS_AXIS_OpenAccelFwCtrl_RangeErr[9] =
{
  -40.0F, -30.0F, -20.0F, -10.0F, 0.0F, 10.0F, 20.0F, 30.0F, 40.0F
} ;                                    /* Variable: KtACCS_AXIS_OpenAccelFwCtrl_RangeErr
                                        * Referenced by:
                                        *   '<S24>/KtACCS_a_OpenAccel_FollowCtrl'
                                        *   '<S24>/KtACCS_a_OpenAccel_FollowCtrl1'
                                        * This is range error axis for KtACCS_OpenAccel_FollowCtrl
                                        */

real32_T KtACCS_AXIS_OpenAccelFwCtrl_TimeGapAcc[7] =
{
  1.5F, 2.5F, 3.0F, 3.5F, 4.0F, 4.5F, 5.0F
} ;                                    /* Variable: KtACCS_AXIS_OpenAccelFwCtrl_TimeGapAcc
                                        * Referenced by: '<S24>/1-D Lookup Table'
                                        * This is the axis of Open acceleration axis for feedforward control
                                        */

real32_T KtACCS_AXIS_OpenAccelFwCtrl_TimeGapDec[6] =
{
  0.0F, 0.75F, 1.5F, 3.5F, 5.0F, 6.5F
} ;                                    /* Variable: KtACCS_AXIS_OpenAccelFwCtrl_TimeGapDec
                                        * Referenced by: '<S24>/1-D Lookup Table1'
                                        * This is the axis of Open acceleration axis for feedforward control
                                        */

real32_T KtACCS_AXIS_OpenAccelLaunch_CurSpd[6] =
{
  0.0F, 1.0F, 2.0F, 3.0F, 4.0F, 5.0F
} ;                                    /* Variable: KtACCS_AXIS_OpenAccelLaunch_CurSpd
                                        * Referenced by: '<S26>/KtACCS_a_OpenAccel_Launch'
                                        * This is vehcile speed axis for KtACCS_OpenAccel_Launch
                                        */

real32_T KtACCS_AXIS_OpenAccelLowSpedCtrl_SpedErr[7] =
{
  -1.5F, -1.0F, -0.5F, 0.0F, 1.0F, 1.5F, 2.0F
} ;                                    /* Variable: KtACCS_AXIS_OpenAccelLowSpedCtrl_SpedErr
                                        * Referenced by: '<S27>/KtACCS_a_OpenAccel_LowSpeedCtrl'
                                        * This is speed error axis for KtACCS_a_OpenAccel_LowSpeedCtrl
                                        */

real32_T KtACCS_AXIS_OpenAccelSpedCtrl_SpedErr[7] =
{
  -15.0F, -10.0F, -5.0F, 0.0F, 5.0F, 10.0F, 15.0F
} ;                                    /* Variable: KtACCS_AXIS_OpenAccelSpedCtrl_SpedErr
                                        * Referenced by: '<S25>/KtACCS_a_OpenAccel_SpeedCtrl'
                                        * This is speed error axis for KtACCS_OpenAccel_SpeedCtrl
                                        */

real32_T KtACCS_AXIS_OpenAccelStop_StopDis[6] =
{
  0.0F, 10.0F, 20.0F, 30.0F, 40.0F, 50.0F
} ;                                    /* Variable: KtACCS_AXIS_OpenAccelStop_StopDis
                                        * Referenced by: '<S18>/KtACCS_t_CalOpenAccelForStopFrmDCSN'
                                        * The axis for the calibration KtACCS_t_CalOpenAccelForStopFrmDCSN
                                        */

real32_T KtACCS_AXIS_RangeCtrlPGain_Err[9] =
{
  -20.0F, -15.0F, -10.0F, -5.0F, 0.0F, 5.0F, 10.0F, 15.0F, 20.0F
} ;                                    /* Variable: KtACCS_AXIS_RangeCtrlPGain_Err
                                        * Referenced by:
                                        *   '<S129>/KtACCS_r_RangeCtrlPGain '
                                        *   '<S129>/KtACCS_r_RangeCtrlPGain 1'
                                        * This is range error axis for KtACCS_r_RangeCtrlPGain
                                        */

real32_T KtACCS_AXIS_RangeCtrlPGain_VehSpd[10] =
{
  0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 40.0F, 45.0F
} ;                                    /* Variable: KtACCS_AXIS_RangeCtrlPGain_VehSpd
                                        * Referenced by:
                                        *   '<S129>/KtACCS_r_RangeCtrlPGain '
                                        *   '<S129>/KtACCS_r_RangeCtrlPGain 1'
                                        *   '<S132>/KtACCS_r_SpeedCtrlPGain'
                                        *   '<S132>/KtACCS_r_SpeedCtrlPGain1'
                                        * This is vehicle speed axis for KtACCS_r_RangeCtrlPGain and KtACCS_r_SpeedCtrlPGain
                                        */

real32_T KtACCS_AXIS_SpeedCtrlPGain_Err[9] =
{
  -20.0F, -15.0F, -10.0F, -5.0F, 0.0F, 5.0F, 10.0F, 15.0F, 20.0F
} ;                                    /* Variable: KtACCS_AXIS_SpeedCtrlPGain_Err
                                        * Referenced by:
                                        *   '<S132>/KtACCS_r_SpeedCtrlPGain'
                                        *   '<S132>/KtACCS_r_SpeedCtrlPGain1'
                                        * This is vehicle speed error axis for KtACCS_r_SpeedCtrlPGain
                                        */

real32_T KtACCS_AXIS_StopStatus_Accel_Pitch[10] =
{
  0.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 40.0F, 50.0F, 60.0F
} ;                                    /* Variable: KtACCS_AXIS_StopStatus_Accel_Pitch
                                        * Referenced by: '<S103>/KtACCS_a_StopStatus_Accel'
                                        * This is Pitch axis for KtACCS_StopStatus_Accel
                                        */

real32_T KtACCS_AXIS_TargetRange_Speed[10] =
{
  0.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 40.0F, 50.0F, 60.0F
} ;                                    /* Variable: KtACCS_AXIS_TargetRange_Speed
                                        * Referenced by: '<S34>/KtACCS_d_CIPVTargtRange'
                                        * The CIPV speed axis for KtACCS_d_CIPVTargtRange
                                        */

real32_T KtACCS_AXIS_TargetZoneSpd[15] =
{
  0.0F, 3.0F, 6.0F, 9.0F, 12.0F, 15.0F, 18.0F, 21.0F, 24.0F, 27.0F, 30.0F, 33.0F,
  36.0F, 39.0F, 42.0F
} ;                                    /* Variable: KtACCS_AXIS_TargetZoneSpd
                                        * Referenced by: '<S49>/1-D Lookup Table'
                                        * This this the axis value for target zone
                                        */

real32_T KtACCS_AXIS_TargtRange_Timegap[4] =
{
  1.0F, 2.0F, 3.0F, 4.0F
} ;                                    /* Variable: KtACCS_AXIS_TargtRange_Timegap
                                        * Referenced by: '<S34>/KtACCS_d_CIPVTargtRange'
                                        * The time gap axis for KtACCS_d_CIPVTargtRange
                                        */

real32_T KtACCS_AXIS_TorqCtrlProp_DeltaAccel[9] =
{
  -2.0F, -1.5F, -1.0F, -0.5F, 0.0F, 0.5F, 1.0F, 1.5F, 2.0F
} ;                                    /* Variable: KtACCS_AXIS_TorqCtrlProp_DeltaAccel
                                        * Referenced by: '<S123>/KtACCS_r_TorqCtrlProp '
                                        * This is delta acceleration axis for KtACCS_r_TorqCtrlProp
                                        */

real32_T KtACCS_AXIS_TorqCtrlProp_EgoSpeed[10] =
{
  0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 40.0F, 45.0F
} ;                                    /* Variable: KtACCS_AXIS_TorqCtrlProp_EgoSpeed
                                        * Referenced by: '<S123>/KtACCS_r_TorqCtrlProp '
                                        * This is ego cunrrent speed axis for KtACCS_r_TorqCtrlProp

                                        */

real32_T KtACCS_Pct_AccelToGasPedal[170] =
{
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 4.0F,
  4.0F, 4.0F, 3.95048809F, 3.49187779F, 2.76314712F, 2.18906379F, 1.79008734F,
  1.6417979F, 1.59118879F, 5.0F, 5.0F, 5.0F, 6.03347301F, 5.3076539F,
  4.16630793F, 3.28359604F, 2.65198112F, 2.46269679F, 2.35731673F, 6.0F, 6.0F,
  6.0F, 7.54184103F, 6.56473F, 5.18090105F, 4.29393291F, 3.58017492F,
  3.22044969F, 3.18237758F, 7.0F, 7.0F, 7.0F, 8.61924744F, 7.40278101F,
  6.26025486F, 5.22007513F, 4.64096689F, 3.91505671F, 4.12530422F, 6.75F,
  6.25924206F, 9.94683743F, 9.87622F, 8.52018166F, 7.01580286F, 6.06202316F,
  5.43656206F, 4.54651737F, 4.83249903F, 7.5F, 6.66493416F, 11.755353F,
  10.9536257F, 9.21855831F, 7.77135086F, 6.9039712F, 6.36475515F, 5.17797804F,
  5.65756F, 8.25F, 8.6933918F, 12.6596107F, 12.2106F, 10.0566082F, 8.41896439F,
  7.66172409F, 7.42554808F, 5.74629259F, 6.60048676F, 13.5F, 12.1707478F,
  15.372385F, 13.4675732F, 11.0343342F, 9.71418858F, 9.26142406F, 12.066515F,
  6.94606829F, 10.725791F
} ;                                    /* Variable: KtACCS_Pct_AccelToGasPedal
                                        * Referenced by: '<S114>/KtACCS_Pct_AccelToGasPedal '
                                        * This cal is used to transfer acceleration to gas pedal or torq(percent)
                                        */

real32_T KtACCS_a_OpenAccel_FollowCtrl[63] =
{
  0.0F, 0.0F, 0.0F, 0.0F, -2.0F, -1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  -1.5F, -0.5F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -1.0F, -0.2F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
} ;                                    /* Variable: KtACCS_a_OpenAccel_FollowCtrl
                                        * Referenced by:
                                        *   '<S24>/KtACCS_a_OpenAccel_FollowCtrl'
                                        *   '<S24>/KtACCS_a_OpenAccel_FollowCtrl1'
                                        * This is open acceleration table under following control mode,it is the function of range error and speed error
                                        */

real32_T KtACCS_a_OpenAccel_Launch[6] =
{
  0.5F, 0.5F, 0.5F, 0.25F, 0.25F, 0.25F
} ;                                    /* Variable: KtACCS_a_OpenAccel_Launch
                                        * Referenced by: '<S26>/KtACCS_a_OpenAccel_Launch'
                                        * This is open acceleration table under launch control mode,it is the function of Ego current speed
                                        */

real32_T KtACCS_a_OpenAccel_LowSpeedCtrl[7] =
{
  -1.0F, -0.8F, -0.5F, 0.0F, 0.0F, 0.0F, 0.0F
} ;                                    /* Variable: KtACCS_a_OpenAccel_LowSpeedCtrl
                                        * Referenced by: '<S27>/KtACCS_a_OpenAccel_LowSpeedCtrl'
                                        * his is open acceleration table under low speed control mode,it is the function of speed error
                                        */

real32_T KtACCS_a_OpenAccel_SpeedCtrl[7] =
{
  0.0F, 0.0F, -0.3F, 0.0F, 0.3F, 0.0F, 0.0F
} ;                                    /* Variable: KtACCS_a_OpenAccel_SpeedCtrl
                                        * Referenced by: '<S25>/KtACCS_a_OpenAccel_SpeedCtrl'
                                        * This is open acceleration table under speed control mode,it is the function of speed error
                                        */

real32_T KtACCS_a_StopStatus_Accel[10] =
{
  -1.0F, -1.0F, -2.0F, -2.0F, -2.0F, -2.0F, -3.0F, -3.0F, -3.0F, -3.0F
} ;                                    /* Variable: KtACCS_a_StopStatus_Accel
                                        * Referenced by: '<S103>/KtACCS_a_StopStatus_Accel'
                                        * When KbACCS_UseStopStatus_Accel=true, accel will be form this cal during status is Stop.This cal is the function of pitch
                                        */

real32_T KtACCS_d_CIPVTargtRange[40] =
{
  4.0F, 5.0F, 9.0F, 12.0F, 20.0F, 24.0F, 28.0F, 24.0F, 36.0F, 44.0F, 4.0F, 5.0F,
  9.0F, 14.0F, 22.0F, 28.0F, 35.0F, 30.0F, 45.0F, 54.0F, 4.0F, 0.0F, 0.0F, 15.0F,
  25.0F, 32.0F, 39.0F, 42.0F, 63.0F, 76.0F, 4.0F, 5.0F, 9.0F, 16.0F, 26.0F,
  32.0F, 40.0F, 45.0F, 68.0F, 81.0F
} ;                                    /* Variable: KtACCS_d_CIPVTargtRange
                                        * Referenced by: '<S34>/KtACCS_d_CIPVTargtRange'
                                        * As keACCS_TargetRangeCalType =0, use this cal to define the target range
                                        */

real32_T KtACCS_d_RespDCSNStopThrshHi[6] =
{
  80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F
} ;                                    /* Variable: KtACCS_d_RespDCSNStopThrshHi
                                        * Referenced by: '<S18>/KtACCS_d_RespDCSNStopThrshHi'
                                        * Only when stop distance from DCSN smaller than this calibration, ACCS response this stop requirement
                                        */

real32_T KtACCS_d_TargetZoneLongDis[15] =
{
  10.0F, 20.0F, 30.0F, 40.0F, 50.0F, 60.0F, 70.0F, 80.0F, 90.0F, 100.0F, 110.0F,
  120.0F, 130.0F, 140.0F, 150.0F
} ;                                    /* Variable: KtACCS_d_TargetZoneLongDis
                                        * Referenced by: '<S49>/1-D Lookup Table'
                                        * This is the target zone longitude distance for different speed of ego car
                                        */

real32_T KtACCS_r_DCSNStopDistanceGain[143] =
{
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
} ;                                    /* Variable: KtACCS_r_DCSNStopDistanceGain
                                        * Referenced by: '<S103>/KtACCS_r_DCSNStopDistanceGain '
                                        * This gain is for stop distance from DCSN
                                        */

real32_T KtACCS_r_DCSNStopSpdGain[121] =
{
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F
} ;                                    /* Variable: KtACCS_r_DCSNStopSpdGain
                                        * Referenced by: '<S103>/KtACCS_r_DCSNStopSpdGain'
                                        * This gain is for stop speed error from DCSN
                                        */

real32_T KtACCS_r_OpenAccelFwCtrl_TimeGapAcc[7] =
{
  0.0F, 0.3125F, 0.3125F, 0.125F, 0.125F, 0.125F, 0.0F
} ;                                    /* Variable: KtACCS_r_OpenAccelFwCtrl_TimeGapAcc
                                        * Referenced by: '<S24>/1-D Lookup Table'
                                        * This the the table value of Open acceleration axis for feedforward control
                                        */

real32_T KtACCS_r_OpenAccelFwCtrl_TimeGapDec[6] =
{
  0.523F, 0.4375F, 0.375F, 0.0625F, 0.0F, 0.0F
} ;                                    /* Variable: KtACCS_r_OpenAccelFwCtrl_TimeGapDec
                                        * Referenced by: '<S24>/1-D Lookup Table1'
                                        * This the the table value of Open acceleration axis for feedforward control
                                        */

real32_T KtACCS_r_RangeCtrlPGain[90] =
{
  0.6F, 0.5F, 0.41F, 0.35F, 0.33F, 0.32F, 0.31F, 0.3F, 0.3F, 0.2F, 0.6F, 0.5F,
  0.41F, 0.35F, 0.33F, 0.32F, 0.31F, 0.3F, 0.3F, 0.2F, 0.6F, 0.5F, 0.41F, 0.35F,
  0.33F, 0.32F, 0.31F, 0.3F, 0.3F, 0.2F, 0.3F, 0.25F, 0.205F, 0.175F, 0.165F,
  0.16F, 0.155F, 0.15F, 0.15F, 0.1F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.3F, 0.25F, 0.205F, 0.175F, 0.165F, 0.16F, 0.155F, 0.15F,
  0.15F, 0.1F, 0.6F, 0.5F, 0.41F, 0.35F, 0.33F, 0.32F, 0.31F, 0.3F, 0.3F, 0.2F,
  0.6F, 0.5F, 0.41F, 0.35F, 0.33F, 0.32F, 0.31F, 0.3F, 0.3F, 0.2F, 0.6F, 0.5F,
  0.41F, 0.35F, 0.33F, 0.32F, 0.31F, 0.3F, 0.3F, 0.2F
} ;                                    /* Variable: KtACCS_r_RangeCtrlPGain
                                        * Referenced by:
                                        *   '<S129>/KtACCS_r_RangeCtrlPGain '
                                        *   '<S129>/KtACCS_r_RangeCtrlPGain 1'
                                        * This is Prop gain for Range PID contrl
                                        */

real32_T KtACCS_r_SpeedCtrlPGain[90] =
{
  0.78F, 0.65F, 0.533F, 0.455F, 0.429F, 0.416F, 0.43F, 0.39F, 0.39F, 0.39F,
  0.78F, 0.65F, 0.533F, 0.455F, 0.429F, 0.416F, 0.43F, 0.39F, 0.39F, 0.39F,
  0.78F, 0.65F, 0.533F, 0.455F, 0.429F, 0.416F, 0.43F, 0.39F, 0.39F, 0.39F,
  0.078F, 0.065F, 0.0533F, 0.0455F, 0.0429F, 0.0416F, 0.043F, 0.039F, 0.039F,
  0.039F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.078F,
  0.065F, 0.0533F, 0.0455F, 0.0429F, 0.0416F, 0.043F, 0.039F, 0.039F, 0.039F,
  0.78F, 0.65F, 0.533F, 0.455F, 0.429F, 0.416F, 0.43F, 0.39F, 0.39F, 0.39F,
  0.78F, 0.65F, 0.533F, 0.455F, 0.429F, 0.416F, 0.43F, 0.39F, 0.39F, 0.39F,
  0.78F, 0.65F, 0.533F, 0.455F, 0.429F, 0.416F, 0.43F, 0.39F, 0.39F, 0.39F
} ;                                    /* Variable: KtACCS_r_SpeedCtrlPGain
                                        * Referenced by:
                                        *   '<S132>/KtACCS_r_SpeedCtrlPGain'
                                        *   '<S132>/KtACCS_r_SpeedCtrlPGain1'
                                        * This is Prop gain for speed PID contrl
                                        */

real32_T KtACCS_r_TorqCtrlProp[90] =
{
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
} ;                                    /* Variable: KtACCS_r_TorqCtrlProp
                                        * Referenced by: '<S123>/KtACCS_r_TorqCtrlProp '
                                        * Torq control PID p gain
                                        */

real32_T KtACCS_t_CalOpenAccelForStopFrmDCSN[6] =
{
  0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F
} ;                                    /* Variable: KtACCS_t_CalOpenAccelForStopFrmDCSN
                                        * Referenced by: '<S18>/KtACCS_t_CalOpenAccelForStopFrmDCSN'
                                        * Want how long to stop the vehicle
                                        */

real32_T kfACCS_v_TargetVehicleSpeedHi = 35.0F;/* Variable: kfACCS_v_TargetVehicleSpeedHi
                                                * Referenced by: '<S17>/Saturation'
                                                * The max target speed will limit by this calibration
                                                */
real32_T kfACCS_v_TargetVehicleSpeedLo = 0.0F;/* Variable: kfACCS_v_TargetVehicleSpeedLo
                                               * Referenced by: '<S17>/Saturation'
                                               * The min target speed limit by this calibration
                                               */
uint32_T KfACCS_t_MaxTimeStampDiff = 1U;/* Variable: KfACCS_t_MaxTimeStampDiff
                                         * Referenced by:
                                         *   '<S33>/Constant1'
                                         *   '<S33>/Constant6'
                                         * This is the max acceptatble time difference between OBFU and EGMO
                                         */
uint8_T KcACCS_TimeStampErrLimit = 10U;/* Variable: KcACCS_TimeStampErrLimit
                                        * Referenced by:
                                        *   '<S33>/Constant12'
                                        *   '<S33>/Constant15'
                                        * This is the counter value for detect OBFU and EGMO error. If the EGMO's time
                                          stamp or OBFU's time stamp does not change for this loops, ACCS will enter
                                          standby.
                                        */
uint8_T KeACCS_CalFaultTypeOnlyForTest = 0U;/* Variable: KeACCS_CalFaultTypeOnlyForTest
                                             * Referenced by: '<S6>/Constant4'
                                             * This is only for logic test
                                             */
uint8_T KeACCS_DriverMode_AllowACCSNum = 0U;/* Variable: KeACCS_DriverMode_AllowACCSNum
                                             * Referenced by: '<S148>/Constant47'
                                             * This is only for logic test.Please hold the default value
                                             */
uint8_T KeACCS_GearDriveNum = 1U;      /* Variable: KeACCS_GearDriveNum
                                        * Referenced by: '<S148>/Constant45'
                                        * The cal need equal to the D gear value from Can bus
                                          At current period, it is only for logic test
                                        */
uint8_T KeACCS_OutPutControlSignal = 0U;/* Variable: KeACCS_OutPutControlSignal
                                         * Referenced by:
                                         *   '<S113>/Constant'
                                         *   '<S114>/Constant'
                                         * 0:Acceleration
                                           1:Torq
                                         */
uint8_T KeACCS_RRCalMetdType = 1U;     /* Variable: KeACCS_RRCalMetdType
                                        * Referenced by:
                                        *   '<S44>/Constant30'
                                        *   '<S68>/Constant30'
                                        *   '<S75>/Constant30'
                                        *   '<S82>/Constant30'
                                        *   '<S89>/Constant30'
                                        *   '<S96>/Constant30'
                                        * 0:Frist cal delta V_x and delta V_y, then cal range rate
                                          1:Directly use CIPV speed sub Ego speed
                                        */
uint8_T KeACCS_TargetRangeCalType = 0U;/* Variable: KeACCS_TargetRangeCalType
                                        * Referenced by: '<S34>/KeACCS_TargetRangeCalType'
                                        * 0:Use lookup table KtACCS_d_CIPVTargtRange
                                          1: Use CIPV velocity * Timegap
                                        */
uint8_T KeACCS_VehicleSpeedSource = 0U;/* Variable: KeACCS_VehicleSpeedSource
                                        * Referenced by:
                                        *   '<S9>/Constant'
                                        *   '<S9>/Constant1'
                                        * 0:Vehicle speed from EGMO
                                          1:Vehicle speed from Can bus
                                        */
boolean_T KbACCS_AEBStateFrmCal = 0;   /* Variable: KbACCS_AEBStateFrmCal
                                        * Referenced by: '<S16>/Constant11'
                                        * This cal is only for logic Test.Ture: AEB active for ACC,False: AEB inactive for ACC.
                                        */
boolean_T KbACCS_AllowEnterStopDueToCIP = 0;/* Variable: KbACCS_AllowEnterStopDueToCIP
                                             * Referenced by: '<S150>/Constant45'
                                             * Ture£º Allow enter stop from temp stop due to obstacle
                                             */
boolean_T KbACCS_AllowOnToStop = 1;    /* Variable: KbACCS_AllowOnToStop
                                        * Referenced by: '<S150>/Constant25'
                                        * True: Allow enable ACC during vehicle speed=0
                                        */
boolean_T KbACCS_CalCIPV_FlickState = 0;/* Variable: KbACCS_CalCIPV_FlickState
                                         * Referenced by: '<S16>/Constant1'
                                         * This cal is only for logic Test.True: Object fick, Run status woudle from following ctrl to Speeed ctrl
                                         */
boolean_T KbACCS_CalDriverSetSpeed = 1;/* Variable: KbACCS_CalDriverSetSpeed
                                        * Referenced by: '<S34>/KbACCS_CalDriverSetSpeed'
                                        * True: Driver set speed is from calibration KfACCS_CalDriverSetSpeed.
                                          False: Driver set speed is from can.
                                        */
boolean_T KbACCS_CalFaultTypeOnlyForTest = 0;/* Variable: KbACCS_CalFaultTypeOnlyForTest
                                              * Referenced by: '<S6>/Constant2'
                                              * This cal is only for logic Test.True: Has fault to ACCS.
                                              */
boolean_T KbACCS_CalTimeGap = 1;       /* Variable: KbACCS_CalTimeGap
                                        * Referenced by: '<S34>/KbACCS_CalTimeGap'
                                        * True: Time gap is from calibration kfACCS_TimeGapToCalcRange.
                                          False: Time gap is from can.
                                        */
boolean_T KbACCS_CancelSwitch = 0;     /* Variable: KbACCS_CancelSwitch
                                        * Referenced by: '<S34>/Constant1'
                                        * True: Cancel switch is set.

                                        */
boolean_T KbACCS_ConsiderSIPVforACC = 0;/* Variable: KbACCS_ConsiderSIPVforACC
                                         * Referenced by: '<S106>/Constant'
                                         * True:Will consider CIPV and SIPV as calculating acceleration.
                                           At current period, please hold False
                                         */
boolean_T KbACCS_ConsiderWithEPB = 0;  /* Variable: KbACCS_ConsiderWithEPB
                                        * Referenced by: '<S7>/Constant1'
                                        * 0: EPB allways Release status;
                                          1: Will use real EPB signal
                                        */
boolean_T KbACCS_ConsiderWithoutGear = 1;/* Variable: KbACCS_ConsiderWithoutGear
                                          * Referenced by: '<S148>/Constant23'
                                          * 0: Will consider Gear, only D can enable ACCS control;
                                            1: Will bypass Gear conditions.
                                          */
boolean_T KbACCS_DirectlyUsePedalToJudgeOverride = 1;/* Variable: KbACCS_DirectlyUsePedalToJudgeOverride
                                                      * Referenced by: '<S148>/Constant24'
                                                      * Ture:Use KfACCS_Pct_GasPedalOverrideThrsh to judge gas pedal override;
                                                        Flase:Use desird torq pct to judge gas pedal override
                                                      */
boolean_T KbACCS_DriverDoorBeltState = 1;/* Variable: KbACCS_DriverDoorBeltState
                                          * Referenced by: '<S7>/Constant5'
                                          * Ture:Door and belt is engaged
                                            False:Door open
                                            This is only for logic test
                                          */
boolean_T KbACCS_EgoPitchTransfer = 1; /* Variable: KbACCS_EgoPitchTransfer
                                        * Referenced by: '<S9>/Constant4'
                                        * If this calibration value is true, the ego pitch from EGMO will be producted -1.
                                        */
boolean_T KbACCS_EnableLowSpeedCtrl = 1;/* Variable: KbACCS_EnableLowSpeedCtrl
                                         * Referenced by:
                                         *   '<S150>/Constant10'
                                         *   '<S150>/Constant3'
                                         * True:Allow Low speed ctrl
                                         */
boolean_T KbACCS_EnblAccelerationRamp = 1;/* Variable: KbACCS_EnblAccelerationRamp
                                           * Referenced by: '<S103>/Constant10'
                                           * Ture: Enable desired acceleration ramp
                                           */
boolean_T KbACCS_EnblSlopeOfst = 0;    /* Variable: KbACCS_EnblSlopeOfst
                                        * Referenced by: '<S103>/Constant3'
                                        * True:Will consider with pitch as calculation acceleration.
                                        */
boolean_T KbACCS_ForceExitStandby = 0; /* Variable: KbACCS_ForceExitStandby
                                        * Referenced by:
                                        *   '<S148>/Constant18'
                                        *   '<S148>/Constant19'
                                        * This is only for test
                                          If Ture, force exit standby mode
                                        */
boolean_T KbACCS_IgnoreOBFUTimeStampBug = 1;/* Variable: KbACCS_IgnoreOBFUTimeStampBug
                                             * Referenced by:
                                             *   '<S33>/Constant16'
                                             *   '<S33>/Constant17'
                                             * This is the calibration to avoid OBFU bug's infuluence
                                             */
boolean_T KbACCS_IgnoreTimeStampError = 1;/* Variable: KbACCS_IgnoreTimeStampError
                                           * Referenced by: '<S33>/Constant2'
                                           * This calibration can close time stamp diagnose function
                                           */
boolean_T KbACCS_MainSwitch = 0;       /* Variable: KbACCS_MainSwitch
                                        * Referenced by: '<S34>/Constant'
                                        * Ture:Main switch is on
                                        */
boolean_T KbACCS_NotAllowEnterStandbyForUSDemo = 0;/* Variable: KbACCS_NotAllowEnterStandbyForUSDemo
                                                    * Referenced by:
                                                    *   '<S16>/Constant40'
                                                    *   '<S148>/Constant40'
                                                    *   '<S150>/Constant40'
                                                    * This calibration is only for US demo.US demo should set 1;Other normal project should hold the default value 0.
                                                    */
boolean_T KbACCS_ResumeSwitch = 0;     /* Variable: KbACCS_ResumeSwitch
                                        * Referenced by: '<S34>/Constant3'
                                        * True:Resume switch is set
                                        */
boolean_T KbACCS_UseACCFromRadar = 0;  /* Variable: KbACCS_UseACCFromRadar
                                        * Referenced by: '<S44>/Constant1'
                                        * 0£º The accelatration value is from radar
                                          1: The accelaration value is from the differentiation of obstacle's velocity
                                        */
boolean_T KbACCS_UseCIPVAccelToCalOpenAccel = 1;/* Variable: KbACCS_UseCIPVAccelToCalOpenAccel
                                                 * Referenced by: '<S24>/Constant'
                                                 * True: Directly use CIPV acceleration as open acceleration
                                                 */
boolean_T KbACCS_UseIgnoreObsFcn = 0;  /* Variable: KbACCS_UseIgnoreObsFcn
                                        * Referenced by: '<S49>/Constant6'
                                        * This calibration will decide whether to use this function that ignore stationary vehicle.
                                        */
boolean_T KbACCS_UseStopStatus_Accel = 1;/* Variable: KbACCS_UseStopStatus_Accel
                                          * Referenced by: '<S103>/Constant4'
                                          * True:Set accel to the calibration during stop mode
                                          */
boolean_T KbACCS_UseVirtualObject = 0; /* Variable: KbACCS_UseVirtualObject
                                        * Referenced by:
                                        *   '<S39>/Constant36'
                                        *   '<S39>/Constant38'
                                        *   '<S39>/Constant41'
                                        *   '<S39>/Constant44'
                                        *   '<S40>/Constant36'
                                        *   '<S40>/Constant38'
                                        *   '<S40>/Constant41'
                                        *   '<S40>/Constant44'
                                        *   '<S41>/Constant36'
                                        *   '<S41>/Constant38'
                                        *   '<S41>/Constant41'
                                        *   '<S41>/Constant44'
                                        *   '<S42>/Constant36'
                                        *   '<S42>/Constant38'
                                        *   '<S42>/Constant41'
                                        *   '<S42>/Constant44'
                                        *   '<S43>/Constant36'
                                        *   '<S43>/Constant38'
                                        *   '<S43>/Constant41'
                                        *   '<S43>/Constant44'
                                        * This is noly for logic test.
                                          True: Use virtual object.
                                          False: Use the actual object.

                                        */
boolean_T KbACCS_UseVirtualPedal = 0;  /* Variable: KbACCS_UseVirtualPedal
                                        * Referenced by: '<S7>/Constant12'
                                        * This is only for test
                                          If Ture,the gas pedal is from the calibration KfACCS_Pct_VirtualGasPedal
                                        */
boolean_T KbACCS_UseVitualDCSNInfo = 1;/* Variable: KbACCS_UseVitualDCSNInfo
                                        * Referenced by:
                                        *   '<S8>/Constant'
                                        *   '<S8>/Constant4'
                                        *   '<S8>/Constant5'
                                        * This is only for test
                                          True: Use virtula information, not from DCSN
                                        */
boolean_T KbACCS_VitualStopReqFrmDCSN = 0;/* Variable: KbACCS_VitualStopReqFrmDCSN
                                           * Referenced by: '<S8>/Constant2'
                                           * This is only for test.
                                             True: Stop request is true
                                           */
#pragma section
/* Block signals (auto storage) */
B_ACCS_subsystem_integrated_T ACCS_subsystem_integrated_B;

/* Block states (auto storage) */
DW_ACCS_subsystem_integrated_T ACCS_subsystem_integrated_DW;

/* Model step function */
void ACCS_subsystem_integrated_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/ACCS' */
  DtrmnACCS_Task();

  /* End of Outputs for SubSystem: '<Root>/ACCS' */
}

/* Model initialize function */
void ACCS_subsystem_integrated_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &ACCS_subsystem_integrated_B), 0,
                sizeof(B_ACCS_subsystem_integrated_T));

  {
    ACCS_subsystem_integrated_B.VfACCS_Input_inlane_nudge_side_ = FORWARD;
    ACCS_subsystem_integrated_B.UnitDelay1_e3kh = NoEnterStandby;
    ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif = NoEnterStandby;
    ACCS_subsystem_integrated_B.UnitDelay1_iozd = NoEnterStandby;
    ACCS_subsystem_integrated_B.UnitDelay2 = ACCS_mode_off;
    ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu = ACCS_status_off;
    ACCS_subsystem_integrated_B.UnitDelay = ACCS_status_off;
    ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 = NoTransfer;
    ACCS_subsystem_integrated_B.Merge = NoEnterFault;
  }

  /* exported global signals */
  VsACCS_DataBus = ACCS_subsystem_integrated_rtZACCS_DataBus;
  VfACCS_Range_Actual = 0.0F;
  VfACCS_CombinedSpeedLimit = 0.0F;
  VfACCS_StopTimer = 0.0F;
  VfACCS_SpdErrLim_CIPV = 0.0F;
  VfACCS_DrsdAccelFrmRngSped = 0.0F;
  VfACCS_RangCtrCL_CIPV = 0.0F;
  VfACCS_Lon_Torq_Req = 0.0F;
  VfACCS_Lon_Accleration = 0.0F;
  VfACCS_DCSNStopAccel = 0.0F;
  VfACCS_DrsdAccelWithDCSN = 0.0F;
  VfACCS_DrsdAccelWithPitch = 0.0F;
  VfACCS_TargetDrsdLonAccel = 0.0F;
  VfACCS_FinalDrsdAcceleration_old = 0.0F;
  VfACCS_FinalDrsdAcceleration = 0.0F;
  VfACCS_Acceleartion_RampUpStep = 0.0F;
  VfACCS_Acceleartion_RampDownStep = 0.0F;
  VfACCS_LaunchToSpdRampTimer = 0.0F;
  VfACCS_LaunchToFollowRampTimer = 0.0F;
  VfACCS_SpeedToFollowRampTimer = 0.0F;
  VfACCS_FollowToSpdRampTimer = 0.0F;
  VfACCS_Obs_Lat_V_OBFU = 0.0F;
  VfACCS_Obs_Long_V_OBFU = 0.0F;
  VfACCS_Obs_Long_A_OBFU = 0.0F;
  VfACCS_Obs_Lat_A_OBFU = 0.0F;
  VfACCS_Obs_Long_OBFU = 0.0F;
  VfACCS_Obs_Lat_OBFU = 0.0F;
  VfACCS_Input_Obs_LinearAcc = 0.0F;
  VfACCS_Input_Obs_Range = 0.0F;
  VfACCS_Input_Obs_Rangerate = 0.0F;
  VfACCS_Input_Obs_LatDis = 0.0F;
  VfACCS_Input_Obs_Long_VFiltered = 0.0F;
  VfACCS_Input_Obs_Lat_VFiltered = 0.0F;
  VfACCS_Input_Obs_LinearVelocity = 0.0F;
  VfACCS_DriverTargetRange = 0.0F;
  VfACCS_FinalSpeedLimit = 0.0F;
  VfACCS_FeedForwardAccel = 0.0F;
  VfACCS_OpenAccel_ForDCSNStop = 0.0F;
  VfACCS_VehSpeed_Tar = 0.0F;
  VfACCS_DeltaSped_EGMOAndCan = 0.0F;
  VfACCS_Input_linear_velocity_EGMO = 0.0F;
  VfACCS_Input_EgoPitch_EGMO = 0.0F;
  VfACCS_Input_longvelocity_EGMO = 0.0F;
  VfACCS_Input_latvelocity_EGMO = 0.0F;
  VfACCS_Input_linear_Acceleration_EGMO = 0.0F;
  VfACCS_Input_stop_s_distance_DCSN = 0.0F;
  VfACCS_Input_traffic_speed_limit_DCSN = 0.0F;
  VfACCS_Input_PhyGasPedal_POWER = 0.0F;
  VfACCS_Input_OBFUTimeStamp_high = 0;
  VfACCS_Input_Obs_ID = 0;
  VfACCS_Input_EGMOTimeStamp_high = 0;
  VfACCS_Input_Obs_Num = 0U;
  VeACCS_CIPVobsType = 0;
  VbACCS_AEB_Active = false;
  VbACCS_MainSwitch = false;
  VbACCS_InformDriverPressResume = false;
  VbACCS_InformDriverPressGasPedal = false;
  VbACCS_SpdToLowSpeedCtr = false;
  VbACCS_HasCIPV_Object = false;
  VbACCS_LowSpdToSpeedCtr = false;
  VbACCS_FollowingToSpeedCtrl = false;
  VbACCS_SpeedToFollowingCtr = false;
  VbACCS_LowSpdToTempStop = false;
  VbACCS_LowSpdToFollowingCtrl = false;
  VbACCS_TempStopToLaunch = false;
  VbACCS_FollowingToLowSpdCtrl = false;
  VbACCS_StatusOnToSpeedCtrl = false;
  VbACCS_StatusOnToStop = false;
  VbACCS_EnterStandbyCommonCod = false;
  VbACCS_FromStopToStandby = false;
  VbACCS_FromLowSpeedToStandby = false;
  VbACCS_FromLaunchToStandby = false;
  VbACCS_FromFollowingCtrlToStandby = false;
  VbACCS_FromSpeedCtrlToStandby = false;
  VbACCS_EnterStopDueToCIP = false;
  VbACCS_TempStpToStop = false;
  VbACCS_StopToLaunch = false;
  VbACCS_LaunchToTempStop = false;
  VbACCS_LaunchToSpeedCtrl = false;
  VbACCS_LaunchToLowSpd = false;
  VbACCS_LaunchToFollowingCtrl = false;
  VbACCS_ResumeSwitch = false;
  VbACCS_ResumeSwitchOld = false;
  VbACCS_GearPositionIsD = false;
  VbACCS_SpeedOutRange = false;
  VbACCS_DriverModeAllowACCS = false;
  VbACCS_DriverGasPedalOverride = false;
  VbACCS_EgoLimit = false;
  VbACCS_ExitStandbyCommonConds = false;
  VbACCS_ExitStandbyToOn = false;
  VbACCS_Lon_Torq_Req = false;
  VbACCS_Lon_Accleration_Req = false;
  VbACCS_EnableLaunchToSpdRamp = false;
  VbACCS_EnableLaunchToFollowRamp = false;
  VbACCS_EnableSpeedToFollowRamp = false;
  VbACCS_EnableFollowToSpeedRamp = false;
  VbACCS_InputInfError = false;
  VbACCS_Obs_validBeforeDelay = false;
  VbACCS_Input_Obs_valid = false;
  VbACCS_CIPVObsRangeFlicker = false;
  VbACCS_BrakePedalPress = false;
  VbACCS_EPB_Engaged = false;
  VbACCS_DriverHasSetSpeed = false;
  VbACCS_NeedRespStopFrmDCSN = false;
  VbACCS_Input_stop_request_DCSN = false;
  VbACCS_Input_NoSpdLimit = false;
  VbACCS_Input_brake_ctrl_enable_DCSN = false;
  VbACCS_Input_acc_feature_enable_DCSN = false;
  VbACCS_Input_power_ctrl_enable_DCSN = false;
  VeACCS_EnterStandbyType = NoEnterStandby;
  VeACCS_EnterStandbyState = NoEnterStandby;
  VeACCS_ModeState = ACCS_mode_off;
  VeACCS_RunStatus = ACCS_status_off;
  VeACCS_RunStatusFrmMode = ACCS_status_off;
  VeACCS_RunStatusBeforeFault = ACCS_status_off;
  VeACCS_CIPVChangedType = Normal;
  VeACCS_StatusTransferType = NoTransfer;
  VeACCS_FaultState = NoEnterFault;

  /* states (dwork) */
  (void) memset((void *)&ACCS_subsystem_integrated_DW, 0,
                sizeof(DW_ACCS_subsystem_integrated_T));

  /* SystemInitialize for Atomic SubSystem: '<Root>/ACCS' */
  DtrmnACCS_Task_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/ACCS' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
