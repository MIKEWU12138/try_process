/*
 * File: LCWS_subsystem_integrated_types.h
 *
 * Code generated for Simulink model 'LCWS_subsystem_integrated'.
 *
 * Model version                  : 1.375
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sun Apr 26 21:11:09 2020
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

#ifndef RTW_HEADER_LCWS_subsystem_integrated_types_h_
#define RTW_HEADER_LCWS_subsystem_integrated_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_EnumDCSN_adm_main_mode_
#define DEFINED_TYPEDEF_FOR_EnumDCSN_adm_main_mode_

typedef uint8_T EnumDCSN_adm_main_mode;/* 0 = ADM_OFF
                                          1 = ADM_STANDBY
                                          2 = ADM_READY
                                          3 = ADM_ACTIVE
                                          4 = ADM_STEER_OVRD
                                          5 = ADM_TAKEOVER_WARNING
                                          6 = ADM_FAULT_WARNING
                                          7 = ADM_FAULT_REACTION
                                          8 = ADM_FAULT_DETECTED */

#define ADM_OFF                        ((EnumDCSN_adm_main_mode)0) /* Default value */
#define ADM_STANDBY                    ((EnumDCSN_adm_main_mode)1)
#define ADM_READY                      ((EnumDCSN_adm_main_mode)2)
#define ADM_ACTIVE                     ((EnumDCSN_adm_main_mode)3)
#define ADM_STEER_OVRD                 ((EnumDCSN_adm_main_mode)4)
#define ADM_TAKEOVER_WARNING           ((EnumDCSN_adm_main_mode)5)
#define ADM_FAULT_WARNING              ((EnumDCSN_adm_main_mode)6)
#define ADM_FAULT_REACTION             ((EnumDCSN_adm_main_mode)7)
#define ADM_FAULT_DETECTED             ((EnumDCSN_adm_main_mode)8)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumDCSN_adm_hmi_msg_display_
#define DEFINED_TYPEDEF_FOR_EnumDCSN_adm_hmi_msg_display_

typedef uint8_T EnumDCSN_adm_hmi_msg_display;/* 0 = NO_MSG
                                                1 = ACTIVE
                                                2 = OVRD
                                                3 = TAKEOVER_REQ
                                                4 = FAULT */

#define NO_MSG                         ((EnumDCSN_adm_hmi_msg_display)0) /* Default value */
#define ACTIVE                         ((EnumDCSN_adm_hmi_msg_display)1)
#define OVRD                           ((EnumDCSN_adm_hmi_msg_display)2)
#define TAKEOVER_REQ                   ((EnumDCSN_adm_hmi_msg_display)3)
#define FAULT                          ((EnumDCSN_adm_hmi_msg_display)4)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumDCSN_adm_hmi_icon_display_
#define DEFINED_TYPEDEF_FOR_EnumDCSN_adm_hmi_icon_display_

typedef uint8_T EnumDCSN_adm_hmi_icon_display;/* 0 = NO_ICON
                                                 1 = GREY_SOLID
                                                 2 = GREEN_SOLID
                                                 3 = BLUE_SOLID
                                                 4 = RED_FLASH_SLOW
                                                 5 = RED_FLASH_FAST
                                                 6 = RED_SOLID */

#define NO_ICON                        ((EnumDCSN_adm_hmi_icon_display)0) /* Default value */
#define GREY_SOLID                     ((EnumDCSN_adm_hmi_icon_display)1)
#define GREEN_SOLID                    ((EnumDCSN_adm_hmi_icon_display)2)
#define BLUE_SOLID                     ((EnumDCSN_adm_hmi_icon_display)3)
#define RED_FLASH_SLOW                 ((EnumDCSN_adm_hmi_icon_display)4)
#define RED_FLASH_FAST                 ((EnumDCSN_adm_hmi_icon_display)5)
#define RED_SOLID                      ((EnumDCSN_adm_hmi_icon_display)6)
#endif

#ifndef DEFINED_TYPEDEF_FOR_DCSN_ADMGroup_
#define DEFINED_TYPEDEF_FOR_DCSN_ADMGroup_

typedef struct
{
  /* 0 = ADM_OFF
     1 = ADM_STANDBY
     2 = ADM_READY
     3 = ADM_ACTIVE
     4 = ADM_STEER_OVRD
     5 = ADM_TAKEOVER_WARNING
     6 = ADM_FAULT_WARNING
     7 = ADM_FAULT_REACTION
     8 = ADM_FAULT_DETECTED */
  EnumDCSN_adm_main_mode adm_main_mode;

  /* 0 = NO_MSG
     1 = ACTIVE
     2 = OVRD
     3 = TAKOVER_REQ
     4 = FAULT */
  EnumDCSN_adm_hmi_msg_display adm_hmi_msg_display;

  /* 0 = NO_ICON
     1 = GREY_SOLID
     2 = GREEN_SOLID
     3 = BLUE_SOLID
     4 = RED_FLASH_SLOW
     5 = RED_FLASH_FAST
     6 = RED_SOLID */
  EnumDCSN_adm_hmi_icon_display adm_hmi_icon_display;

  /* 0 = Deactivate
     1 = Activate
     2 = Hold */
  uint8_T usr_cmd_autodrive_activate;

  /* 0 = Not request resume
     1 = Request resume */
  boolean_T adm_accs_resume;
}
DCSN_ADMGroup;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumDCSN_autodrive_control_mode_
#define DEFINED_TYPEDEF_FOR_EnumDCSN_autodrive_control_mode_

typedef uint8_T EnumDCSN_autodrive_control_mode;/* 0 = AUTODRIVE_PASIV
                                                   1 = AUTODRIVE_DELAY
                                                   2 = AUTODRIVE_RE_ACTIV
                                                   3 = AUTODRIVE_ACTIVATING
                                                   4 = AUTODRIVE_ACTIVATED */

#define AUTODRIVE_PASIV                ((EnumDCSN_autodrive_control_mode)0) /* Default value */
#define AUTODRIVE_DELAY                ((EnumDCSN_autodrive_control_mode)1)
#define AUTODRIVE_RE_ACTIV             ((EnumDCSN_autodrive_control_mode)2)
#define AUTODRIVE_ACTIVATING           ((EnumDCSN_autodrive_control_mode)3)
#define AUTODRIVE_ACTIVATED            ((EnumDCSN_autodrive_control_mode)4)
#endif

#ifndef DEFINED_TYPEDEF_FOR_DCSN_EnablingFlagsGroup_
#define DEFINED_TYPEDEF_FOR_DCSN_EnablingFlagsGroup_

typedef struct
{
  /* Enable flag for acceleration (gas pedal) control */
  boolean_T power_ctrl_enable;

  /* Enable flag for brake control */
  boolean_T brake_ctrl_enable;

  /* Enable flag for steer control */
  boolean_T steer_ctrl_enable;

  /* Enable flag for gear control */
  boolean_T gear_ctrl_enable;

  /* Enable flag for electric parking brake control */
  boolean_T epb_ctrl_enable;
  boolean_T acc_feature_enable;
  boolean_T lcc_feature_enable;
  boolean_T alca_feature_enable;
  boolean_T aeb_feature_enable;
  boolean_T fcw_feature_enable;
  boolean_T lcw_feature_enable;
  boolean_T ldw_feature_enable;

  /* Enable flag for LKA feature. */
  boolean_T lka_feature_enable;

  /* 0 = AUTODRIVE_PASIV
     1 = AUTODRIVE_DELAY
     2 = AUTODRIVE_RE_ACTIV
     3 = AUTODRIVE_ACTIVATING
     4 = AUTODRIVE_ACTIVATED */
  EnumDCSN_autodrive_control_mode autodrive_control_mode;
}
DCSN_EnablingFlagsGroup;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumDCSN_stop_reason_
#define DEFINED_TYPEDEF_FOR_EnumDCSN_stop_reason_

typedef uint8_T EnumDCSN_stop_reason;  /* 0 = NO_STOP_REQUEST
                                          1 = STOP_FOR_DESTINATION
                                          2 = STOP_FOR_TRAFFIC_LIGHT
                                          3 = STOP_FOR_STOP_LINE
                                          4 = STOP_FOR_STOP_SIGN
                                          5 = STOP_FOR_CROSSWALK
                                          6 = STOP_FOR_KEEP_CLEAR */

#define NO_STOP_REQUEST                ((EnumDCSN_stop_reason)0) /* Default value */
#define STOP_FOR_DESTINATION           ((EnumDCSN_stop_reason)1)
#define STOP_FOR_TRAFFIC_LIGHT         ((EnumDCSN_stop_reason)2)
#define STOP_FOR_STOP_LINE             ((EnumDCSN_stop_reason)3)
#define STOP_FOR_STOP_SIGN             ((EnumDCSN_stop_reason)4)
#define STOP_FOR_CROSSWALK             ((EnumDCSN_stop_reason)5)
#define STOP_FOR_KEEP_CLEAR            ((EnumDCSN_stop_reason)6)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumDCSN_speed_limit_reason_
#define DEFINED_TYPEDEF_FOR_EnumDCSN_speed_limit_reason_

typedef uint8_T EnumDCSN_speed_limit_reason;/* 0 = NO_LIMIT
                                               1 = LIMIT_FOR_EGO_LANE
                                               1 = LIMIT_FOR_CROSSWALK
                                               2 = LIMIT_FOR_NUDGE */

#define NO_LIMIT                       ((EnumDCSN_speed_limit_reason)0) /* Default value */
#define LIMIT_FOR_EGO_LANE             ((EnumDCSN_speed_limit_reason)1)
#define LIMIT_FOR_CROSSWALK            ((EnumDCSN_speed_limit_reason)2)
#define LIMIT_FOR_NUDGE                ((EnumDCSN_speed_limit_reason)3)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumDCSN_driving_direction_
#define DEFINED_TYPEDEF_FOR_EnumDCSN_driving_direction_

typedef uint8_T EnumDCSN_driving_direction;

#define FORWARD                        ((EnumDCSN_driving_direction)0) /* Default value */
#define LEFT                           ((EnumDCSN_driving_direction)1)
#define RIGHT                          ((EnumDCSN_driving_direction)2)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumDCSN_change_lane_reason_
#define DEFINED_TYPEDEF_FOR_EnumDCSN_change_lane_reason_

typedef uint8_T EnumDCSN_change_lane_reason;

#define LC_NO_REQUEST                  ((EnumDCSN_change_lane_reason)0) /* Default value */
#define LC_USER_CMD                    ((EnumDCSN_change_lane_reason)1)
#define LC_NAVIGATION_CMD              ((EnumDCSN_change_lane_reason)2)
#define LC_FRONT_OBSTACLE              ((EnumDCSN_change_lane_reason)3)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumDCSN_change_lane_cancel_reason_
#define DEFINED_TYPEDEF_FOR_EnumDCSN_change_lane_cancel_reason_

typedef uint8_T EnumDCSN_change_lane_cancel_reason;/* 0 = LC_CANCEL_NO_REQUEST
                                                      1 = LC_CANCEL_USR_CMD */

#define LC_CANCEL_NO_REQUEST           ((EnumDCSN_change_lane_cancel_reason)0) /* Default value */
#define LC_CANCEL_USR_CMD              ((EnumDCSN_change_lane_cancel_reason)1)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumDCSN_inlane_nudge_reason_
#define DEFINED_TYPEDEF_FOR_EnumDCSN_inlane_nudge_reason_

typedef uint8_T EnumDCSN_inlane_nudge_reason;

#define NUDGE_NO_REQUEST               ((EnumDCSN_inlane_nudge_reason)0) /* Default value */
#define NUDGE_FRONT_OBSTACLE           ((EnumDCSN_inlane_nudge_reason)1)
#define NUDGE_SIDE_OBSTACLE            ((EnumDCSN_inlane_nudge_reason)2)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumDCSN_pull_over_reason_
#define DEFINED_TYPEDEF_FOR_EnumDCSN_pull_over_reason_

typedef uint8_T EnumDCSN_pull_over_reason;

#define PULLOVER_NO_REQUEST            ((EnumDCSN_pull_over_reason)0) /* Default value */
#define PULLOVER_USER_CMD              ((EnumDCSN_pull_over_reason)1)
#define PULLOVER_POLICE                ((EnumDCSN_pull_over_reason)2)
#define PULLOVER_SYSTEM_FAULT          ((EnumDCSN_pull_over_reason)3)
#endif

#ifndef DEFINED_TYPEDEF_FOR_DCSN_TrafficDeciderGroup_
#define DEFINED_TYPEDEF_FOR_DCSN_TrafficDeciderGroup_

typedef struct
{
  boolean_T stop_request;
  real32_T stop_s_distance;

  /* 0 = NO_STOP_REQUEST
     1 = STOP_FOR_DESTINATION
     2 = STOP_FOR_TRAFFIC_LIGHT
     3 = STOP_FOR_STOP_LINE
     4 = STOP_FOR_STOP_SIGN
     5 = STOP_FOR_CROSSWALK
     6 = STOP_FOR_KEEP_CLEAR */
  EnumDCSN_stop_reason stop_reason;
  real32_T traffic_speed_limit;

  /* 0 = NO_LIMIT
     1 = LIMIT_FOR_EGO_LANE
     1 = LIMIT_FOR_CROSSWALK
     2 = LIMIT_FOR_NUDGE */
  EnumDCSN_speed_limit_reason speed_limit_reason;
  boolean_T change_lane_request;
  EnumDCSN_driving_direction change_lane_req_side;
  EnumDCSN_change_lane_reason change_lane_reason;
  real32_T change_lane_target_speed;
  boolean_T change_lane_cancel_request;

  /* 0 = LC_CANCEL_NO_REQUEST
     1 = LC_CANCEL_USR_CMD */
  EnumDCSN_change_lane_cancel_reason change_lane_cancel_reason;
  boolean_T inlane_nudge_request;

  /* 0 = FORWARD
     1 = LEFT
     2 = RIGHT */
  EnumDCSN_driving_direction inlane_nudge_side;
  EnumDCSN_inlane_nudge_reason inlane_nudge_reason;
  boolean_T pull_over_request;
  EnumDCSN_pull_over_reason pull_over_reason;

  /* 0 = Vehicle speed in range
     1 = Vehicle speed is over the maximal allowed speed */
  boolean_T over_speed_warning;
}
DCSN_TrafficDeciderGroup;

#endif

#ifndef DEFINED_TYPEDEF_FOR_DCSN_DataBus_
#define DEFINED_TYPEDEF_FOR_DCSN_DataBus_

typedef struct
{
  DCSN_ADMGroup ADM_Group;
  DCSN_EnablingFlagsGroup EnablingFlags_Group;
  DCSN_TrafficDeciderGroup TrafficDecider_Group;
}
DCSN_DataBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_FedBck_Drivemod_Req_
#define DEFINED_TYPEDEF_FOR_COMM_FedBck_Drivemod_Req_

typedef struct
{
  uint8_T DriverModeComd;
}
COMM_FedBck_Drivemod_Req;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_FedBck_Drivemod_
#define DEFINED_TYPEDEF_FOR_COMM_FedBck_Drivemod_

typedef struct
{
  /* Auto to manual tips feedback from VCU. */
  uint16_T VCU_AutoToManualTips;
  uint8_T VCU_ICPV_ATOModFb;
}
COMM_FedBck_Drivemod;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_FedBck_CruiseControl_
#define DEFINED_TYPEDEF_FOR_COMM_FedBck_CruiseControl_

typedef struct
{
  uint8_T CruiseControlSts;
  uint8_T CruiseSwitchSts;
}
COMM_FedBck_CruiseControl;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_FedBck_Steering_
#define DEFINED_TYPEDEF_FOR_COMM_FedBck_Steering_

typedef struct
{
  uint8_T EPS_St;
  uint8_T VCU1_ICPV_EPSMODE;
  real32_T VCU1_ICPV_StrAngleFb;
  real32_T VCU1_ICPV_StrAngle;
  real32_T VCU1_ICPV_StrAngleSpd;
  real32_T VCU1_ICPV_YawRate;
  uint8_T EPS_Faultlev;
  uint8_T TypeofSteeringTransmission;
  real32_T EPS_SteeringTorqueAct;

  /* Driver Hands Off Detected. */
  boolean_T EPS_HandsOffDetected;

  /* Driver Hands On Detected. */
  boolean_T EPS_HandsOnDetected;
}
COMM_FedBck_Steering;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_FedBck_Acceleration_
#define DEFINED_TYPEDEF_FOR_COMM_FedBck_Acceleration_

typedef struct
{
  uint8_T VCU_ICPV_VCUSta;
  uint8_T VCU_ICPV_AccPelSta;
  real32_T VCU_ICPV_AccPelPosFb;
  real32_T VUC_ICPV_AccPed;
  real32_T ActualacclerPedelRate;
}
COMM_FedBck_Acceleration;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_FedBck_Brake_
#define DEFINED_TYPEDEF_FOR_COMM_FedBck_Brake_

typedef struct
{
  uint8_T VCU_ICPV_BrkPelSta;
  uint8_T Decs_FedBck_ESCmod;
  real32_T VCU_ICPV_BrkPelPosFb;
  real32_T VUC_ICPV_BrkPed;
  uint8_T Decs_FedBck_BrkPedSts;
  uint8_T IBC_SystemStatus;
  real32_T IBC_MasterCylinderPress;
  uint8_T IBC_MasterCylinderPressValid;
  uint8_T PresHoldFish;
  uint8_T IBC_ControlStatus;

  /* ESC fault status. */
  uint16_T ESC_FaultStatus;
}
COMM_FedBck_Brake;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_FedBck_Gear_
#define DEFINED_TYPEDEF_FOR_COMM_FedBck_Gear_

typedef struct
{
  uint8_T VCU_ICPV_TgtSftFb;
  uint8_T VCU_ICPV_VCUGearLevPos;

  /* Actual Gear Ratio. */
  real32_T TCU_ActualGearRatio;
}
COMM_FedBck_Gear;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_FedBck_EPB_
#define DEFINED_TYPEDEF_FOR_COMM_FedBck_EPB_

typedef struct
{
  uint8_T VCU_ICPV_EPBSysVCU;
  uint8_T EPB_SysFaultStatus;
  uint8_T EPB_FaultCode;
  uint8_T EPB_SwitchStatus;
}
COMM_FedBck_EPB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_FedBck_VehDynmc_
#define DEFINED_TYPEDEF_FOR_COMM_FedBck_VehDynmc_

typedef struct
{
  uint8_T PCU_ICPV_TMDirSts;
  real32_T VCU1_ICPV_VehSpd;
  real32_T VCU1_ICPV_LongAcc;
  real32_T VCU_ICPV_LateralAcc;
}
COMM_FedBck_VehDynmc;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_FedBck_WhlSpd_
#define DEFINED_TYPEDEF_FOR_COMM_FedBck_WhlSpd_

typedef struct
{
  real32_T VCU1_ICPV_ESCWhlRRSpd;
  real32_T VCU1_ICPV_ESCWhlRLSpd;
  real32_T VCU1_ICPV_ESCWhlFRSpd;
  real32_T VCU1_ICPV_ESCWhlFLSpd;
  real32_T WhlSpdReRiStatus;
  real32_T WhlSpdReLeStatus;
  real32_T WhlSpdFrntRiStatus;
  real32_T WhlSpdFrntLeStatus;

  /* Left rear wheel rolling counter. */
  uint32_T ESC_LRWheelRollingCounter;

  /* Right rear wheel rolling counter. */
  uint32_T ESC_RRWheelRollingCounter;
}
COMM_FedBck_WhlSpd;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_FedBck_Light_
#define DEFINED_TYPEDEF_FOR_COMM_FedBck_Light_

typedef struct
{
  uint8_T VCU1_ICPV_StrAngleSpdDir;
  uint8_T VCU1_ICPV_HeadLampLowBeam;
  uint8_T VCU1_ICPV_HeadLampHighBeam;
  uint8_T VCU_IPCV_BrkLgtSts;
  uint8_T VCU1_ICPV_EPSDir;
  uint8_T VCU1_ICPV_DirIndicationLH;
  uint8_T VCU1_ICPV_DirIndicationRH;
}
COMM_FedBck_Light;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_FedBck_KeyState_
#define DEFINED_TYPEDEF_FOR_COMM_FedBck_KeyState_

typedef struct
{
  uint8_T Decs_FedBck_KeyState;
}
COMM_FedBck_KeyState;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_FedBck_Door_
#define DEFINED_TYPEDEF_FOR_COMM_FedBck_Door_

typedef struct
{
  uint8_T VCU1_ICPV_DrvDoorStatus;
  uint8_T VCU1_ICPV_PsgDoorStatus;
  uint8_T VCU1_ICPV_RRDoorStatus;
  uint8_T VCU1_ICPV_RLDoorStatus;
  uint8_T Trunk_BackDoor_Sts;
}
COMM_FedBck_Door;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_FedBck_Motor_
#define DEFINED_TYPEDEF_FOR_COMM_FedBck_Motor_

typedef struct
{
  uint8_T MCU_MotorWorkMode;
  uint8_T ADS_VehiclePowertrainFltLevel;
  real32_T BMS_BattSOC;
  real32_T MCU_MotorSpeed;
  real32_T MCU_MotorActTrq;

  /* Engine friction torque in percentage. */
  int16_T EMS_FrictionPercentTorque;
}
COMM_FedBck_Motor;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_FedBck_Check_
#define DEFINED_TYPEDEF_FOR_COMM_FedBck_Check_

typedef struct
{
  real32_T Checksum_0x121;
  real32_T Rolling_counter_0x121;
  real32_T Checksum_0x122;
  real32_T Rolling_counter_0x122;
  real32_T Checksum_0x411;
  real32_T Rolling_counter_0x411;
  real32_T Checksum_0x390;
  real32_T Rolling_counter_0x390;
  real32_T Checksum_0x210;
  real32_T RollingCounter_0x210;
}
COMM_FedBck_Check;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_Bus_FedBck_in_
#define DEFINED_TYPEDEF_FOR_COMM_Bus_FedBck_in_

typedef struct
{
  COMM_FedBck_Drivemod_Req FedBck_Drivemod_Req;
  COMM_FedBck_Drivemod FedBck_Drivemod;
  COMM_FedBck_CruiseControl FedBck_CruiseControl;
  COMM_FedBck_Steering FedBck_Steering;
  COMM_FedBck_Acceleration FedBck_Acceleration;
  COMM_FedBck_Brake FedBck_Brake;
  COMM_FedBck_Gear FedBck_Gear;
  COMM_FedBck_EPB FedBck_EPB;
  COMM_FedBck_VehDynmc FedBck_VehDynmc;
  COMM_FedBck_WhlSpd FedBck_WhlSpd;
  COMM_FedBck_Light FedBck_Light;
  COMM_FedBck_KeyState FedBck_KeyState;
  COMM_FedBck_Door FedBck_Door;
  COMM_FedBck_Motor FedBck_Motor;
  COMM_FedBck_Check FedBck_Check;
}
COMM_Bus_FedBck_in;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Vector3d_
#define DEFINED_TYPEDEF_FOR_Vector3d_

typedef struct
{
  real_T x;
  real_T y;
  real_T z;
}
Vector3d;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Vector2f_
#define DEFINED_TYPEDEF_FOR_Vector2f_

typedef struct
{
  /* position_covariance of x */
  real32_T x;

  /* position covariance of y */
  real32_T y;
}
Vector2f;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EGMO_Pose_
#define DEFINED_TYPEDEF_FOR_EGMO_Pose_

typedef struct
{
  /* UTM coordinates (x,y,z) */
  Vector3d position;
  uint8_T position_quality;

  /* padding for communication data alignment, DO NOT USE */
  int8_T padding[3];
  Vector2f position_covariance;

  /* roll in UTM coorindates
     range = (-pi, pi) */
  real32_T roll;

  /* pitch in UTM coorindates
     range = (-pi, pi) */
  real32_T pitch;

  /* yaw in UTM coorindates
     range = (-pi, pi) */
  real32_T yaw;
  real32_T yaw_covariance;

  /* same as yaw in UTM coordinates */
  real32_T heading;
}
EGMO_Pose;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Vector3f_
#define DEFINED_TYPEDEF_FOR_Vector3f_

typedef struct
{
  real32_T x;
  real32_T y;
  real32_T z;
}
Vector3f;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EGMO_Motion_
#define DEFINED_TYPEDEF_FOR_EGMO_Motion_

typedef struct
{
  /* unit in m/s */
  Vector3f velocity_utm;

  /* scalar linear velocity with direction based on the gravity point movement */
  real32_T linear_velocity;
  real32_T roll_rate_utm;
  real32_T pitch_rate_utm;
  real32_T yaw_rate_utm;

  /* yaw rate from vehicle CAN */
  real32_T yaw_rate_road;

  /* yaw rate covariance from vehicle CAN */
  real32_T yaw_rate_road_covariance;

  /* unit in m/s2 */
  Vector3f acceleration_utm;
  real32_T linear_acceleration;

  /* steering wheel angle after filtering */
  real32_T steer_angle_filtered;

  /* instantaneous curvature of the ego vehicle */
  real32_T curvature;

  /* unit in m/s */
  Vector2f velocity_rel;

  /* unit in m/s */
  Vector2f velocity_rel_covariance;

  /* the angle between the direction of velocity and the direction which vehicle body faces, unit in rad */
  real32_T slip_angle;

  /* unit in m/s2 */
  Vector2f acceleration_rel;

  /* unit in m/s2 */
  Vector2f acceleration_rel_covariance;

  /* 0 = UNKNOWN
     1 = NONE
     2 = LEFT
     3 = RIGHT
     4 = EMERGENCY */
  int8_T turn_indicator;

  /* padding for communication data alignment, DO NOT USE */
  int8_T padding[7];
}
EGMO_Motion;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EGMO_DataBus_
#define DEFINED_TYPEDEF_FOR_EGMO_DataBus_

typedef struct
{
  int32_T timestamp_high;
  uint32_T timestamp_low;

  /* Coordinated universal time */
  int32_T time_utc_high;
  uint32_T time_utc_low;

  /* EgoMotion validity bit */
  boolean_T is_ready;

  /* padding for communication data alignment, DO NOT USE */
  int8_T padding[7];
  EGMO_Pose pose_utm;
  EGMO_Motion motion;
}
EGMO_DataBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_OBFU_Obstacle_
#define DEFINED_TYPEDEF_FOR_OBFU_Obstacle_

typedef struct
{
  int32_T id;
  Vector3f nearest_point_rel;
  Vector3f center_point_rel;
  real32_T heading_rel;
  Vector2f velocity_rel;
  Vector2f acceleration_rel;
  boolean_T is_velocity_valid;
  boolean_T is_acceleration_valid;

  /* padding for communication data alignment, DO NOT USE */
  int8_T padding_1[2];
  real32_T length;
  real32_T width;
  real32_T height;
  Vector3f polygon_points[8];
  uint8_T num_polygon_points;

  /* padding for communication data alignment, DO NOT USE */
  int8_T padding_2[3];
  int32_T tracking_time;

  /* UNKNOWN=0;
     PEDESTRIAN=1;
     BICYCLE=2;
     MOTORCYCLE = 3;
     VEHICLE=4;
     BUS=5;
     TRUCK=6;
     ANIMAL =7;
     TRAFFIC_CONE = 8;
     FENCES = 9; */
  int8_T type;

  /* 0 = UNKNOWN
     1 = MOVING
     2 = STATIONARY
     3 = STOPPED */
  int8_T motion_status;

  /* 0 = UNKNOWN
     1 = ONCOMING
     2 = CROSSING_LEFT
     3 = CROSSING_RIGHT
     4 = PRECEDING */
  int8_T motion_orientation;

  /* Confideng level between 0-100 */
  uint8_T confidence;

  /* UNKNOWN = 0,
     FRONT_LEFT = 1,
     FRONT = 2,
     FRONT_RIGHT = 3,
     LEFT = 4,
     RIGHT = 5,
     REAR_LEFT = 6,
     REAR = 7,
     REAR_LEFT = 8, */
  int8_T position_zone;

  /* 0 = UNKNOWN
     1 = NONE
     2 = LEFT
     3 = RIGHT
     4 = EMERGENCY */
  int8_T turn_indicator;

  /* 0 = UNKNOWN
     1 = OFF
     2 = ON */
  int8_T brake_indicator;

  /* 0 = INVALID
     1 = CREATE
     2 = UPDATE_NEW
     3 = UPDATE
     4 = UPDATE_STABLE
     5 = PREDICT_NEW
     6 = PREDICT */
  int8_T tracking_status;

  /* Obstacle source (sensor1 | sensor2 | ..)

     LIDAR = first bit;
     Radar = second bit;
     CMAERA = third bit;
     V2X = fourth bit;
     5-16 bit reserved */
  uint16_T source;

  /* is cipv (closest in-path vehicle) in the FRONT position */
  boolean_T is_cipv_front;

  /* is cipv (closest in-path vehicle) in the REAR position */
  boolean_T is_cipv_rear;

  /* is cipv (closest in-path vehicle) in the LEFT position */
  boolean_T is_cipv_left;

  /* is cipv (closest in-path vehicle) in the RIGHT position */
  boolean_T is_cipv_right;

  /* is a cut-in obstacle */
  boolean_T is_cutin;

  /* is a cut-out obstacle */
  boolean_T is_cutout;
}
OBFU_Obstacle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_OBFU_DataBus_
#define DEFINED_TYPEDEF_FOR_OBFU_DataBus_

typedef struct
{
  int32_T timestamp_high;
  uint32_T timestamp_low;
  OBFU_Obstacle obstacles[128];
  uint16_T num_obstacles;

  /* padding for communication data alignment, DO NOT USE */
  int8_T padding[6];
}
OBFU_DataBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MPFU_Pose_
#define DEFINED_TYPEDEF_FOR_MPFU_Pose_

/* unit in meter */
typedef struct
{
  boolean_T is_valid;
  int8_T padding[7];
  Vector3d position;

  /* range = (-pi, pi] */
  real32_T roll;

  /* range = (-pi, pi] */
  real32_T pitch;

  /* range = (-pi, pi] */
  real32_T yaw;

  /* range = (-pi, pi] */
  real32_T heading;
}
MPFU_Pose;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MPFU_Curvature_
#define DEFINED_TYPEDEF_FOR_MPFU_Curvature_

typedef struct
{
  boolean_T is_valid;
  int8_T padding[3];
  real32_T value;
}
MPFU_Curvature;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MPFU_Road_
#define DEFINED_TYPEDEF_FOR_MPFU_Road_

typedef struct
{
  /* road id convention:

     0 - EGO_ROAD   本车所在的road
     1 - PREV_ROAD    前接road
     2 - NEXT_ROAD    后继road */
  int8_T id;

  /* 0- UNKNOWN
     1- REGULAR
     2- OVERPASS
     3- HIGHWAY
     4- TUNNEL
     5- CITY_EXPRESS
     6- reserved
     7- reserved
     8- reserved */
  int8_T type;

  /* 0- UNKNOWN
     1- SAME_DIR
     2- OPPOSITE_DIR */
  int8_T direction;
  uint8_T road_edge_indices[8];
  uint8_T num_road_edges;
  uint8_T lane_indices[8];
  uint8_T num_lanes;
  int8_T padding[3];
}
MPFU_Road;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MPFU_RoadEdge_
#define DEFINED_TYPEDEF_FOR_MPFU_RoadEdge_

typedef struct
{
  /* 路沿id
     0 - UNKNOWN   未知
     1-  LEFT_FIRST_ROAD_EDGE   主车左边第1根路沿
     2 - RIGHT_FIRST_ROAD_EDGE   主车右边第1根路沿
     3-  LEFT_SECOND_ROAD_EDGE    主车左边第2根路沿
     4 - RIGHT_SECOND_ROAD_EDGE    主车右边第2根路沿
     5-  LEFT_THIRD_ROAD_EDGE     主车左边第3根路沿
     6 - RIGHT_THIRD_ROAD_EDGE     主车右边第3根路沿 */
  int8_T id;

  /* 0 - no vision and no hdmap
     1 - only vision
     2 - only hdmap
     3 - vision hdmap fused
     4 - vision hdmap object fused */
  int8_T fusion_status;

  /* 0- UNKNOWN
     1- LANE_MARK
     2- CURB_EDGE
     3- GUARDRAIL
     4- DITCH
     5- WALL
     6- NONE */
  int8_T type;

  /* 置信度 = [0,100] */
  uint8_T quality;
  real32_T c0_position;
  real32_T c1_heading;
  real32_T c2_curvature;
  real32_T c3_curvature_derivative;

  /* 所属道路id */
  uint8_T road_index;
  int8_T padding_1[3];

  /* 本车所在后轴中心点到该路沿线的横向距离 */
  real32_T distance_to_host;
  int8_T padding_2[4];
}
MPFU_RoadEdge;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MPFU_Lane_
#define DEFINED_TYPEDEF_FOR_MPFU_Lane_

typedef struct
{
  /* 0 - EGO_LANE
     1 - LEFT_FIRST_LANE
     2 - RIGHT_FIRST_LANE
     3 - LEFT_SECOND_LANE
     4 - RIGHT_SECOND_LANE
     5 - LEFT_THIRD_LANE
     6 - RIGHT_THIRD_LANE */
  int8_T id;

  /* 0 - no vision and no hdmap
     1 - only vision
     2 - only hdmap
     3 - vision hdmap fused
     4 - vision hdmap object fused */
  int8_T fusion_status;
  uint8_T num_prev_lanes;

  /* predecessor lane IDs, there could be more than one */
  uint8_T prev_lane_indices[8];
  uint8_T num_succ_lanes;

  /* predecessor lane id, there could be more than one */
  uint8_T succ_lane_indices[8];
  uint8_T speed_limit_max;
  uint8_T speed_limit_min;

  /* padding for communication data alignment, DO NOT USE */
  int8_T padding_1[2];

  /* Lane width: the average value of the staring and ending wdith */
  real32_T width;

  /* total length of the lane */
  real32_T length;

  /* 0- UNKNOWN
     1- REGULAR_LANE
     2- OFF_RAMP
     3- ON_RAMP
     4- CONNECT_RAMP
     5- EMERGENCY_LANE
     6- OTHERS
     7- RESERVED */
  int8_T type;

  /* 0 - UNKNOWN
     1 - ONLY_FORWARD
     2 - ONLY_LEFT_TURN
     3 - ONLY_RIGHT_TURN
     4 - FORWARD_LEFT_TURN
     5 - FORWARD_RIGHT_TURN
     6 - LEFT_RIGHT_TURN
     7 - U_TURN
     8 - NO_U_TURN
     9 - NO_LEFT_TURN
     10 - NO_RIGHT_TURN
     11 - NO_LEFT_RIGHT_TURN
     12 - RESERVED
     13 - RESERVED
     14 - RESERVED */
  int8_T turn_type;

  /* 0- UNKNOWN
     1- SAME_DIRECTION
     2- OPPOSITE_DIRECTION */
  int8_T direction;
  uint8_T road_index;

  /* -1 for none-exist */
  int8_T left_lane_marker_index;

  /* -1 for none-exist */
  int8_T right_lane_marker_index;

  /* padding for communication data alignment, DO NOT USE */
  int8_T padding_2[2];
}
MPFU_Lane;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MPFU_LaneMarker_
#define DEFINED_TYPEDEF_FOR_MPFU_LaneMarker_

typedef struct
{
  /* Fused Lane ID:
     0- INVALID
     1- LEFT_FIRST_LANEMARK
     2- RIGHT_FIRST_LANEMARK
     3- LEFT_SECOND_LANEMARK
     4- RIGHT_SECOND_LANEMARK
     5- LEFT_THIRD_LANEMARK
     6- RIGHT_THIRD_LANEMARK
     7- LEFT_FOURTH_LANEMARK
     8- RIGHT_FOURTH_LANEMARK */
  int8_T id;

  /* 0 - no vision and no hdmap
     1 - only vision
     2 - only hdmap
     3 - vision hdmap fused
     4 - vision hdmap object fused */
  int8_T fusion_status;

  /* UNKNOWN=0;
     SINGLE_DOTTED_LINE=1;
     SHORT_DOTTED_LINE=2;
     SHORT_THICK_DOTTED_LINE=3;
     DOUBLE_DOTTED_LINE=4;
     SINGLE_SOLID_LINE=5;
     DOUBLE_SOLID_LINE=6;
     LEFT_DOTTED_RIGHT_SOLID=7;
     LEFT_SOLID_RIGHT_DOTTED=8; */
  int8_T type;

  /* UNKNOWN = 0;
     WHITE = 1;
     YELLOW = 2;
     BLUE = 3;
     GREEN = 4;
     RED = 5; */
  int8_T color;

  /* confidence level = [0,100] */
  uint8_T quality;
  int8_T padding_1[3];
  real32_T c0_position;
  real32_T c1_heading;
  real32_T c2_curvature;
  real32_T c3_curvature_derivative;
  Vector2f start_rel;
  Vector2f end_rel;

  /* Distance from EGO origin point (center of rear axle) to the lane marker */
  real32_T distance_to_host;
  int8_T padding_2[4];
}
MPFU_LaneMarker;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MPFU_TrafficLight_
#define DEFINED_TYPEDEF_FOR_MPFU_TrafficLight_

typedef struct
{
  /* 0 - no vision and no hdmap
     1 - only vision
     2 - only hdmap
     3 - vision hdmap fused
     4 - vision hdmap object fused */
  int8_T fusion_status;
  uint8_T lane_index;

  /* 0-UKNOWN
     1-ROUND
     2-LEFT_TURN_ARROW
     3-RIGHT_TURN_ARROW
     4-FORWARD_ARROW
     5-X_SHAPE
     6-RECTANGLE
     7-PEDESTRIAN
     8-BICYCLE
     9-VECHCLE */
  int8_T type;

  /* 0- UNKNOWN
     1- HORIZONTAL
     2- VERTICAL */
  int8_T layout;

  /* 0- UNKNOWN
     1- RED
     2- YELLOW
     3- GREEN
     4- RED_FLASH
     5- YELLOW_FLASH */
  int8_T state;

  /* padding for communication data alignment, DO NOT USE */
  int8_T padding_1[3];
  Vector2f position_rel;
  int8_T count_down_time;

  /* padding for communication data alignment, DO NOT USE */
  int8_T padding_2[7];
}
MPFU_TrafficLight;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MPFU_TrafficSign_
#define DEFINED_TYPEDEF_FOR_MPFU_TrafficSign_

typedef struct
{
  /* 0 - no vision and no hdmap
     1 - only vision
     2 - only hdmap
     3 - vision hdmap fused
     4 - vision hdmap object fused */
  int8_T fusion_status;

  /* UNKNOWN = 0;
     SPEED_LIMIT = 1;
     STOP_SIGN = 2;
     RESERVED1 = 3;
     RESERVED2 = 4;
     RESERVED3 = 5;
     OTHER = 6; */
  int8_T type;
  uint8_T lane_index;

  /* padding for communication data alignment, DO NOT USE */
  int8_T padding_1;
  int32_T value;

  /* accumulated distance in SL coordinates */
  real32_T position_s;
  Vector2f position_rel;
  int8_T padding_2[4];
}
MPFU_TrafficSign;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MPFU_StopLine_
#define DEFINED_TYPEDEF_FOR_MPFU_StopLine_

typedef struct
{
  /* 0 - no vision and no hdmap
     1 - only vision
     2 - only hdmap
     3 - vision hdmap fused
     4 - vision hdmap object fused */
  int8_T fusion_status;
  uint8_T lane_index;
  int8_T padding[2];

  /* accumulated distance in SL coordinates */
  real32_T position_s;
  Vector2f start_rel;
  Vector2f end_rel;
}
MPFU_StopLine;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MPFU_Crosswalk_
#define DEFINED_TYPEDEF_FOR_MPFU_Crosswalk_

typedef struct
{
  /* 0 - no vision and no hdmap
     1 - only vision
     2 - only hdmap
     3 - vision hdmap fused
     4 - vision hdmap object fused */
  int8_T fusion_status;

  /* 置信度 = [0,100] */
  uint8_T quality;

  /* padding for communication data alignment, DO NOT USE */
  int8_T padding_1[2];
  Vector2f points[16];
  uint8_T num_vertices;

  /* padding for communication data alignment, DO NOT USE */
  int8_T padding_2[3];
}
MPFU_Crosswalk;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MPFU_Junction_
#define DEFINED_TYPEDEF_FOR_MPFU_Junction_

typedef struct
{
  /* 0 - no vision and no hdmap
     1 - only vision
     2 - only hdmap
     3 - vision hdmap fused
     4 - vision hdmap object fused */
  int8_T fusion_status;

  /* 0- UNKNOWN
     1- CROSSROADS
     2- T_SHAPE_JUNCTION
     3- ROUNDABOUT
     4- RAMP
     5- JUNCTION_WITH_TRAFFIC_LIGHTS
     6- MULTI_ROAD_JUNCTION
     7- OTHERS */
  int8_T shape;

  /* 0-UNKNOWN
     1-HIGHWAY_AND_HIGHWAY
     2-HIGHWAY_AND_REGULAR
     3- REGULAR_AND_REGULAR */
  int8_T type;
  int8_T padding_1;
  Vector2f vertices_rel[16];
  uint8_T num_vertices;

  /* padding for communication data alignment, DO NOT USE */
  int8_T padding_2[3];
}
MPFU_Junction;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MPFU_DataBus_
#define DEFINED_TYPEDEF_FOR_MPFU_DataBus_

typedef struct
{
  int32_T timestamp_high;
  uint32_T timestamp_low;

  /* MapFusion validity bit */
  boolean_T is_ready;

  /* padding for communication data alignment, DO NOT USE */
  int8_T padding_1[7];
  MPFU_Pose pose_utm;
  MPFU_Curvature curvature;
  MPFU_Road roads[4];
  uint8_T num_roads;

  /* padding for communication data alignment, DO NOT USE */
  int8_T padding_2[7];
  MPFU_RoadEdge road_edges[8];
  uint8_T num_road_edges;
  int8_T padding_3[7];
  MPFU_Lane lanes[8];
  uint8_T num_lanes;
  int8_T padding_4[7];
  MPFU_LaneMarker lane_markers[16];
  uint8_T num_lane_markers;

  /* padding for communication data alignment, DO NOT USE */
  int8_T padding_5[7];
  MPFU_TrafficLight traffic_lights[16];
  uint8_T num_traffic_lights;

  /* padding for communication data alignment, DO NOT USE */
  int8_T padding_6[7];
  MPFU_TrafficSign traffic_signs[16];
  uint8_T num_traffic_signs;

  /* padding for communication data alignment, DO NOT USE */
  int8_T padding_7[7];
  MPFU_StopLine stop_lines[4];
  uint8_T num_stop_lines;

  /* padding for communication data alignment, DO NOT USE */
  int8_T padding_8[7];
  MPFU_Crosswalk cross_walks[4];
  uint8_T num_cross_walks;

  /* padding for communication data alignment, DO NOT USE */
  int8_T padding_9[7];
  MPFU_Junction junctions[8];
  uint8_T num_junctions;

  /* padding for communication data alignment, DO NOT USE */
  int8_T padding_10[7];
}
MPFU_DataBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumLCWS_Active_Status_
#define DEFINED_TYPEDEF_FOR_EnumLCWS_Active_Status_

typedef uint8_T EnumLCWS_Active_Status;

#define LCWS_OFF                       ((EnumLCWS_Active_Status)0) /* Default value */
#define LCWS_PASSIVE                   ((EnumLCWS_Active_Status)1)
#define LCWS_INACTIVE                  ((EnumLCWS_Active_Status)2)
#define LCWS_ACTIVE                    ((EnumLCWS_Active_Status)3)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumLCWS_Warning_Status_
#define DEFINED_TYPEDEF_FOR_EnumLCWS_Warning_Status_

typedef uint8_T EnumLCWS_Warning_Status;

#define LCWS_NO_WARNING                ((EnumLCWS_Warning_Status)0) /* Default value */
#define LCWS_WARNING_LOW_LEVEL         ((EnumLCWS_Warning_Status)1)
#define LCWS_WARNING_HIGH_LEVEL        ((EnumLCWS_Warning_Status)2)
#endif

#ifndef DEFINED_TYPEDEF_FOR_LCWS_DataBus_
#define DEFINED_TYPEDEF_FOR_LCWS_DataBus_

typedef struct
{
  int32_T bswL_ID;
  int32_T cvwL_ID;
  int32_T bswR_ID;
  int32_T cvwR_ID;
  boolean_T warning_left_low;
  boolean_T warning_left_high;
  boolean_T warning_right_low;
  boolean_T warning_right_high;
  EnumLCWS_Active_Status active_status;
  EnumLCWS_Warning_Status left_warning_status;
  EnumLCWS_Warning_Status right_warning_status;
}
LCWS_DataBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_LCWS_BSD_area_Bus_
#define DEFINED_TYPEDEF_FOR_LCWS_BSD_area_Bus_

typedef struct
{
  real32_T KfLCWS_d_BSDZone_NearDis;
  real32_T KfLCWS_d_BSDLargerZone_NearDis;
  real32_T KfLCWS_d_BSDZone_FarDis;
  real32_T KfLCWS_d_BSDLargerZone_FarDis;
  real32_T KfLCWS_d_BSDZone_FrontDis;
  real32_T KfLCWS_d_BSDLargerZone_FrontDis;
  real32_T KfLCWS_d_BSDZone_BackDis;
  real32_T KfLCWS_d_BSDLargerZone_BackDis;
  real32_T KfLCWS_d_BSDZone_Eye95Dis;
  real32_T KfLCWS_d_CVZone_FrontDis;
  real32_T KfLCWS_d_CVLargerZone_FrontDis;
  real32_T KfLCWS_t_TTCThrshLowLevel;
  real32_T KfLCWS_t_TTCLargerThrsh_LowLevel;
  real32_T KfLCWS_t_TTCThrshHiLevel;
  real32_T KfLCWS_d_NearDisHiLevel;
}
LCWS_BSD_area_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumLCWS_warningArea_
#define DEFINED_TYPEDEF_FOR_EnumLCWS_warningArea_

typedef uint8_T EnumLCWS_warningArea;

#define WARNING_HLEVEL_AREA            ((EnumLCWS_warningArea)0) /* Default value */
#define WARNING_S_AREA                 ((EnumLCWS_warningArea)1)
#define WARNING_L_AREA                 ((EnumLCWS_warningArea)2)
#define MAY_WARNING_AREA               ((EnumLCWS_warningArea)3)
#define NO_WARNING_AREA                ((EnumLCWS_warningArea)4)
#endif

#ifndef DEFINED_TYPEDEF_FOR_LCWS_EnbleCondBus_
#define DEFINED_TYPEDEF_FOR_LCWS_EnbleCondBus_

typedef struct
{
  boolean_T KbLCWS_Switch;
  real32_T KfLCWS_v_EnbleVehSpdThrshLo;
  real32_T KfLCWS_v_DisbleVehSpdThrshLo;
  real32_T KfLCWS_v_EnbleVehSpdThrshHi;
  real32_T KfLCWS_v_DisbleVehSpdThrshHi;
  real32_T KfLCWS_c_EnbleCurveThrshMax;
  real32_T KfLCWS_c_DisbleCurveThrshMax;
}
LCWS_EnbleCondBus;

#endif
#endif                                 /* RTW_HEADER_LCWS_subsystem_integrated_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
