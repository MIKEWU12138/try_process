/*
 * File: AEBD_subsystem_integrated_types.h
 *
 * Code generated for Simulink model 'AEBD_subsystem_integrated'.
 *
 * Model version                  : 1.82
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sat May  9 18:53:22 2020
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

#ifndef RTW_HEADER_AEBD_subsystem_integrated_types_h_
#define RTW_HEADER_AEBD_subsystem_integrated_types_h_
#include "rtwtypes.h"
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

#ifndef DEFINED_TYPEDEF_FOR_EnumAEBS_EnblState_
#define DEFINED_TYPEDEF_FOR_EnumAEBS_EnblState_

typedef uint8_T EnumAEBS_EnblState;

#define AEBS_EnblState_OFF             ((EnumAEBS_EnblState)0)   /* Default value */
#define AEBS_EnblState_ON              ((EnumAEBS_EnblState)1)
#define AEBS_AEBState_Fault            ((EnumAEBS_EnblState)2)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumAEBS_FCWState_
#define DEFINED_TYPEDEF_FOR_EnumAEBS_FCWState_

typedef uint8_T EnumAEBS_FCWState;

#define AEBS_FCWState_StandBy          ((EnumAEBS_FCWState)0)    /* Default value */
#define AEBS_FCWState_Level1Actived    ((EnumAEBS_FCWState)1)
#define AEBS_FCWState_Level2Actived    ((EnumAEBS_FCWState)2)
#define AEBS_FCWState_Level3Actived    ((EnumAEBS_FCWState)3)
#define AEBS_FCWState_Level4Actived    ((EnumAEBS_FCWState)4)
#define AEBS_FCWState_Level5Actived    ((EnumAEBS_FCWState)5)
#endif

#ifndef DEFINED_TYPEDEF_FOR_AEBS_FCW_Data_
#define DEFINED_TYPEDEF_FOR_AEBS_FCW_Data_

typedef struct
{
  boolean_T FCW_request;
  uint8_T FCW_warn_level;
  EnumAEBS_EnblState FCW_enable_state;
  EnumAEBS_FCWState FCW_active_state;
  uint8_T FCW_error;
}
AEBS_FCW_Data;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumAEBS_AEBState_
#define DEFINED_TYPEDEF_FOR_EnumAEBS_AEBState_

typedef uint8_T EnumAEBS_AEBState;

#define AEBS_AEBState_StandBy          ((EnumAEBS_AEBState)0)    /* Default value */
#define AEBS_AEBState_PreBrakeActived  ((EnumAEBS_AEBState)1)
#define AEBS_AEBState_PartialBrakeActived ((EnumAEBS_AEBState)2)
#define AEBS_AEBState_FullBrakeActived ((EnumAEBS_AEBState)3)
#define AEBS_AEBState_ConfidenceConfirmed ((EnumAEBS_AEBState)4)
#define AEBS_AEBState_WaitForEPB       ((EnumAEBS_AEBState)5)
#define AEBS_AEBState_WaitForDealy     ((EnumAEBS_AEBState)6)
#endif

#ifndef DEFINED_TYPEDEF_FOR_AEBS_AEB_Data_
#define DEFINED_TYPEDEF_FOR_AEBS_AEB_Data_

typedef struct
{
  boolean_T AEB_request;
  boolean_T AEB_prebrake_req;
  real32_T AEB_acceleration_req;
  boolean_T AEB_brakeLight_req;
  EnumAEBS_EnblState AEB_enabled_state;
  EnumAEBS_AEBState AEB_actived_state;
  uint8_T AEB_error;
}
AEBS_AEB_Data;

#endif

#ifndef DEFINED_TYPEDEF_FOR_AEBS_DataBus_
#define DEFINED_TYPEDEF_FOR_AEBS_DataBus_

typedef struct
{
  AEBS_FCW_Data FCW_Data;
  AEBS_AEB_Data AEB_Data;
  boolean_T AEBS_brake_priority_setting;
  boolean_T AEBS_horn_ctrl_req;
  int32_T AEBS_obj_ID;
}
AEBS_DataBus;

#endif

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
#endif                                 /* RTW_HEADER_AEBD_subsystem_integrated_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
