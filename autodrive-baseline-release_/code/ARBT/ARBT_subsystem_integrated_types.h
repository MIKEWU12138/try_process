/*
 * File: ARBT_subsystem_integrated_types.h
 *
 * Code generated for Simulink model 'ARBT_subsystem_integrated'.
 *
 * Model version                  : 1.644
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  2 11:29:36 2020
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

#ifndef RTW_HEADER_ARBT_subsystem_integrated_types_h_
#define RTW_HEADER_ARBT_subsystem_integrated_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_EnumACCS_StandbyType_
#define DEFINED_TYPEDEF_FOR_EnumACCS_StandbyType_

typedef uint8_T EnumACCS_StandbyType;  /* 0:NoEnterStandby
                                          1:FromModeOffToStandby
                                          2:FromSpeedCtrlToStandby
                                          3:FromFollowingCtrlToStandby
                                          4:FromLowSpeedToStandby
                                          5:FromTempStopToStandby
                                          6:FromStopToStandby
                                          7:FromLaunchToStandby
                                          8:FromFaultToStandby
                                          9:DriverGasPedalOverride
                                          10:PressCancelSwitch */

#define NoEnterStandby                 ((EnumACCS_StandbyType)0) /* Default value */
#define FromModeOffToStandby           ((EnumACCS_StandbyType)1)
#define FromSpeedCtrlToStandby         ((EnumACCS_StandbyType)2)
#define FromFollowingCtrlToStandby     ((EnumACCS_StandbyType)3)
#define FromLowSpeedToStandby          ((EnumACCS_StandbyType)4)
#define FromTempStopToStandby          ((EnumACCS_StandbyType)5)
#define FromStopToStandby              ((EnumACCS_StandbyType)6)
#define FromLaunchToStandby            ((EnumACCS_StandbyType)7)
#define FromFaultToStandby             ((EnumACCS_StandbyType)8)
#define DriverGasPedalOverride         ((EnumACCS_StandbyType)9)
#define PressCancelSwitch              ((EnumACCS_StandbyType)10)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumACCS_Mode_
#define DEFINED_TYPEDEF_FOR_EnumACCS_Mode_

typedef uint8_T EnumACCS_Mode;         /* 0:ACCS_mode_off
                                          1:ACCS_mode_on
                                          2:ACCS_mode_standby
                                          3:ACCS_mode_fault
                                        */

#define ACCS_mode_off                  ((EnumACCS_Mode)0)        /* Default value */
#define ACCS_mode_on                   ((EnumACCS_Mode)1)
#define ACCS_mode_standby              ((EnumACCS_Mode)2)
#define ACCS_mode_fault                ((EnumACCS_Mode)3)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumACCS_RunStatus_
#define DEFINED_TYPEDEF_FOR_EnumACCS_RunStatus_

typedef uint8_T EnumACCS_RunStatus;    /* 0:ACCS_status_off
                                          1:ACCS_status_Standby
                                          2:ACCS_status_on
                                          3:ACCS_status_SpeedCtrl
                                          4:ACCS_status_FollowingCtrl
                                          5:ACCS_status_LowSpeed
                                          6:ACCS_status_TempStop
                                          7:ACCS_status_Stop
                                          8:ACCS_status_Launch
                                          9:ACCS_status_Fault */

#define ACCS_status_off                ((EnumACCS_RunStatus)0)   /* Default value */
#define ACCS_status_Standby            ((EnumACCS_RunStatus)1)
#define ACCS_status_on                 ((EnumACCS_RunStatus)2)
#define ACCS_status_SpeedCtrl          ((EnumACCS_RunStatus)3)
#define ACCS_status_FollowingCtrl      ((EnumACCS_RunStatus)4)
#define ACCS_status_LowSpeed           ((EnumACCS_RunStatus)5)
#define ACCS_status_TempStop           ((EnumACCS_RunStatus)6)
#define ACCS_status_Stop               ((EnumACCS_RunStatus)7)
#define ACCS_status_Launch             ((EnumACCS_RunStatus)8)
#define ACCS_status_Fault              ((EnumACCS_RunStatus)9)
#endif

#ifndef DEFINED_TYPEDEF_FOR_ACCS_DataBus_
#define DEFINED_TYPEDEF_FOR_ACCS_DataBus_

typedef struct
{
  boolean_T VbACCS_ExitStandbyToOn;
  boolean_T VbACCS_InformDriverPressGasPedal;
  boolean_T VbACCS_InformDriverPressResume;
  EnumACCS_StandbyType VeACCS_EnterStandbyState;
  real32_T VfACCS_Lon_Accleration;
  boolean_T VbACCS_Lon_Torq_req;
  real32_T VfACCS_Lon_Torq;
  real32_T VfACCS_Lon_Speed_Tar;
  real32_T VfACCS_Lon_Range_Act;
  boolean_T VbACCS_Lon_Accleration_req;
  EnumACCS_Mode VeACCS_Mode;
  EnumACCS_RunStatus VeACCS_RunStatus;
}
ACCS_DataBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumLCCS_ValidLane_
#define DEFINED_TYPEDEF_FOR_EnumLCCS_ValidLane_

typedef uint8_T EnumLCCS_ValidLane;

#define LCCS_NoLane                    ((EnumLCCS_ValidLane)0)   /* Default value */
#define LCCS_LeftLane                  ((EnumLCCS_ValidLane)1)
#define LCCS_RightLane                 ((EnumLCCS_ValidLane)2)
#define LCCS_BothLane                  ((EnumLCCS_ValidLane)3)
#endif

#ifndef DEFINED_TYPEDEF_FOR_LCCS_DataBus_
#define DEFINED_TYPEDEF_FOR_LCCS_DataBus_

/* LCCS databus. */
typedef struct
{
  /* Lane centering control is ready to engage. */
  boolean_T LCC_ReadyToEngage;

  /* Lane centering control is forced to disengage due to one of following reasons:
     1. EGMO and MPFU timestamp don't match.
     2. No valid lane marker. */
  boolean_T LCC_ForceToDisengage;

  /* Steering control has reached fully engaged state at least one time in this autodrive cycle. */
  boolean_T steering_control_engaged;

  /* Valid Lane Marker information. NoLane = 0, LeftLane = 1, RightLane = 2, BothLane = 3. */
  EnumLCCS_ValidLane valid_lane_marker;

  /* Desired steering wheel angle in degree. */
  real32_T veh_strwhl_angle_des;

  /* Lateral distance from shifted lane center to target lane center. */
  real32_T lateral_dist_to_go;
}
LCCS_DataBus;

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

#ifndef DEFINED_TYPEDEF_FOR_EnumLDWS_la_detec_st_
#define DEFINED_TYPEDEF_FOR_EnumLDWS_la_detec_st_

typedef uint8_T EnumLDWS_la_detec_st;  /* 0=LDWS_NotAAvl;
                                          1=LDWS_LeAvl;
                                          2=LDWS_RiAvl;
                                          3=LDWS_BothAvl;
                                        */

#define LDWS_BothAvl                   ((EnumLDWS_la_detec_st)3) /* Default value */
#define LDWS_LeAvl                     ((EnumLDWS_la_detec_st)1)
#define LDWS_RiAvl                     ((EnumLDWS_la_detec_st)2)
#define LDWS_NotAvl                    ((EnumLDWS_la_detec_st)0)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumLDWS_warn_side_
#define DEFINED_TYPEDEF_FOR_EnumLDWS_warn_side_

typedef uint8_T EnumLDWS_warn_side;    /* 0=LDWS_NoWarn;
                                          1=LDWS_WarnLe;
                                          2=LDWS_WarnRi; */

#define LDWS_WarnLe                    ((EnumLDWS_warn_side)1)
#define LDWS_WarnRi                    ((EnumLDWS_warn_side)2)
#define LDWS_NoWarn                    ((EnumLDWS_warn_side)0)   /* Default value */
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumLDWS_system_st_
#define DEFINED_TYPEDEF_FOR_EnumLDWS_system_st_

typedef uint8_T EnumLDWS_system_st;

#define LDWS_Off                       ((EnumLDWS_system_st)0)   /* Default value */
#define LDWS_On                        ((EnumLDWS_system_st)1)
#define LDWS_Error                     ((EnumLDWS_system_st)2)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumLDWS_on_state_st_
#define DEFINED_TYPEDEF_FOR_EnumLDWS_on_state_st_

typedef uint8_T EnumLDWS_on_state_st;

#define LDWS_Enabling                  ((EnumLDWS_on_state_st)0) /* Default value */
#define LDWS_Standby                   ((EnumLDWS_on_state_st)1)
#define LDWS_Active                    ((EnumLDWS_on_state_st)2)
#define LDWS_Passive                   ((EnumLDWS_on_state_st)3)
#endif

#ifndef DEFINED_TYPEDEF_FOR_LDWS_DataBus_
#define DEFINED_TYPEDEF_FOR_LDWS_DataBus_

typedef struct
{
  EnumLDWS_la_detec_st LDWS_la_detect_st;
  EnumLDWS_warn_side LDWS_warn_side;
  boolean_T LDWS_warn_st;
  EnumLDWS_system_st LDWS_system_st;
  EnumLDWS_on_state_st LDWS_on_state_st;
}
LDWS_DataBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumBSDS_Active_Status_
#define DEFINED_TYPEDEF_FOR_EnumBSDS_Active_Status_

typedef uint8_T EnumBSDS_Active_Status;

#define BSDS_NONE                      ((EnumBSDS_Active_Status)0) /* Default value */
#define BSDS_OFF                       ((EnumBSDS_Active_Status)1)
#define BSDS_INACTIVE                  ((EnumBSDS_Active_Status)2)
#define BSDS_ERROR                     ((EnumBSDS_Active_Status)3)
#define BSDS_ACTIVE                    ((EnumBSDS_Active_Status)4)
#define BSDS_SELF_CHECK                ((EnumBSDS_Active_Status)5)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumBSDS_Warning_Status_
#define DEFINED_TYPEDEF_FOR_EnumBSDS_Warning_Status_

typedef uint8_T EnumBSDS_Warning_Status;

#define BSDS_NO_WARNING                ((EnumBSDS_Warning_Status)0) /* Default value */
#define BSDS_WARNING_LOW_LEVEL         ((EnumBSDS_Warning_Status)1)
#define BSDS_WARNING_HIGH_LEVEL        ((EnumBSDS_Warning_Status)2)
#endif

#ifndef DEFINED_TYPEDEF_FOR_BSDS_DataBus_
#define DEFINED_TYPEDEF_FOR_BSDS_DataBus_

typedef struct
{
  int32_T bswL_ID;
  int32_T bswR_ID;
  EnumBSDS_Active_Status active_status;
  EnumBSDS_Warning_Status left_warning_status;
  EnumBSDS_Warning_Status right_warning_status;
}
BSDS_DataBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumLCAS_Active_Status_
#define DEFINED_TYPEDEF_FOR_EnumLCAS_Active_Status_

typedef uint8_T EnumLCAS_Active_Status;

#define LCAS_NONE                      ((EnumLCAS_Active_Status)0) /* Default value */
#define LCAS_OFF                       ((EnumLCAS_Active_Status)1)
#define LCAS_INACTIVE                  ((EnumLCAS_Active_Status)2)
#define LCAS_ERROR                     ((EnumLCAS_Active_Status)3)
#define LCAS_ACTIVE                    ((EnumLCAS_Active_Status)4)
#define LCAS_SELF_CHECK                ((EnumLCAS_Active_Status)5)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumLCAS_Warning_Status_
#define DEFINED_TYPEDEF_FOR_EnumLCAS_Warning_Status_

typedef uint8_T EnumLCAS_Warning_Status;

#define LCAS_NO_WARNING                ((EnumLCAS_Warning_Status)0) /* Default value */
#define LCAS_WARNING_LOW_LEVEL         ((EnumLCAS_Warning_Status)1)
#define LCAS_WARNING_HIGH_LEVEL        ((EnumLCAS_Warning_Status)2)
#endif

#ifndef DEFINED_TYPEDEF_FOR_LCAS_DataBus_
#define DEFINED_TYPEDEF_FOR_LCAS_DataBus_

typedef struct
{
  int32_T cvwL_ID;
  int32_T cvwR_ID;
  EnumLCAS_Active_Status active_status;
  EnumLCAS_Warning_Status left_warning_status;
  EnumLCAS_Warning_Status right_warning_status;
}
LCAS_DataBus;

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
  boolean_T acoustic_warning_req;
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

  /* Enable flag for BSD feature. */
  boolean_T bsd_feature_enable;

  /* Enable flag for LCA feature. */
  boolean_T lca_feature_enable;

  /* Enable flag for RCTA feature. */
  boolean_T rcta_feature_enable;

  /* Enable flag for FCTA feature. */
  boolean_T fcta_feature_enable;

  /* Enable flag for DOW feature. */
  boolean_T dow_feature_enable;

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
                                               1 = LIMIT_FOR_CROSSWALK
                                               2 = LIMIT_FOR_NUDGE
                                               3 = LIMIT_FOR_CURVATURE */

#define NO_LIMIT                       ((EnumDCSN_speed_limit_reason)0) /* Default value */
#define LIMIT_FOR_CROSSWALK            ((EnumDCSN_speed_limit_reason)1)
#define LIMIT_FOR_NUDGE                ((EnumDCSN_speed_limit_reason)2)
#define LIMIT_FOR_CURVATURE            ((EnumDCSN_speed_limit_reason)3)
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

  /* The speed limit of ego lane */
  real32_T lane_speed_limit;

  /* Target speed limit */
  real32_T target_speed_limit;
  real32_T speed_limit_distance;

  /* 0 = NO_LIMIT
     1 = LIMIT_FOR_CROSSWALK
     2 = LIMIT_FOR_NUDGE
     3 = LIMIT_FOR_CURVATURE */
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

#ifndef DEFINED_TYPEDEF_FOR_EnumLKAS_IntvTyp_
#define DEFINED_TYPEDEF_FOR_EnumLKAS_IntvTyp_

typedef uint8_T EnumLKAS_IntvTyp;

#define LKAS_NoIntvTyp                 ((EnumLKAS_IntvTyp)0)
#define LKAS_SftyLaneKeepAid           ((EnumLKAS_IntvTyp)1)     /* Default value */
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumLKAS_IntvSide_
#define DEFINED_TYPEDEF_FOR_EnumLKAS_IntvSide_

typedef uint8_T EnumLKAS_IntvSide;

#define LKAS_NoIntvSide                ((EnumLKAS_IntvSide)0)
#define LKAS_IntvSideLe                ((EnumLKAS_IntvSide)1)    /* Default value */
#define LKAS_IntvSideRi                ((EnumLKAS_IntvSide)2)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumLKAS_IntvMgrSt_
#define DEFINED_TYPEDEF_FOR_EnumLKAS_IntvMgrSt_

typedef uint8_T EnumLKAS_IntvMgrSt;

#define LKAS_NoIntv                    ((EnumLKAS_IntvMgrSt)0)   /* Default value */
#define LKAS_Intv                      ((EnumLKAS_IntvMgrSt)1)
#define LKAS_abort                     ((EnumLKAS_IntvMgrSt)2)
#define LKAS_Completed                 ((EnumLKAS_IntvMgrSt)3)
#endif

#ifndef DEFINED_TYPEDEF_FOR_LKAS_DataBus_
#define DEFINED_TYPEDEF_FOR_LKAS_DataBus_

typedef struct
{
  boolean_T Intv_Request;
  real32_T SteerData;
  EnumLKAS_IntvTyp IntvTyp_sLKA;
  EnumLKAS_IntvSide IntvSide_sLKA;
  EnumLKAS_IntvMgrSt IntvMgrSt_sLKA;
}
LKAS_DataBus;

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

#ifndef DEFINED_TYPEDEF_FOR_ARBT_BrakeGroup_
#define DEFINED_TYPEDEF_FOR_ARBT_BrakeGroup_

typedef struct
{
  real32_T brake_req_lon_a;
  boolean_T brake_ctrl_enbl_to_comm;
  boolean_T brake_precharge_req;
  boolean_T brake_priority_setting;
}
ARBT_BrakeGroup;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ARBT_SteerGroup_
#define DEFINED_TYPEDEF_FOR_ARBT_SteerGroup_

typedef struct
{
  /* 0 = steering wheel angle
     1 = steering wheel torque */
  uint8_T steer_req_mode;
  real32_T steer_req_strwhl_angle;
  real32_T steer_req_strwhl_torque;
  boolean_T steer_ctrl_enbl_to_comm;
}
ARBT_SteerGroup;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ARBT_PowerGroup_
#define DEFINED_TYPEDEF_FOR_ARBT_PowerGroup_

typedef struct
{
  /* 0 = acceleration (def)
     1 = torque */
  uint8_T power_req_mode;
  real32_T power_req_lon_a;
  real32_T power_req_torque;
  boolean_T power_ctrl_enbl_to_comm;
}
ARBT_PowerGroup;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ARBT_WarningGroup_
#define DEFINED_TYPEDEF_FOR_ARBT_WarningGroup_

typedef struct
{
  boolean_T warn_haptic_req;
  boolean_T warn_acoustic_req;
  boolean_T warn_visual_lcw_left_req;
  boolean_T warn_visual_lcw_right_req;
  boolean_T warn_visual_ldw_left_req;
  boolean_T warn_visual_ldw_right_req;
  boolean_T warn_visual_fcw_req;
}
ARBT_WarningGroup;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ARBT_AccessoryGroup_
#define DEFINED_TYPEDEF_FOR_ARBT_AccessoryGroup_

typedef struct
{
  boolean_T epb_ctrl_enbl_to_comm;
  boolean_T epb_switch_request;
  uint8_T epb_control_mode;
  boolean_T gear_ctrl_enbl_to_comm;
  uint8_T gear_ctrl_req;
  boolean_T auto_hold_req;

  /* request to activate the horn

     1 = horn on
     0 = horn off */
  boolean_T horn_ctrl_req;
}
ARBT_AccessoryGroup;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ARBT_RecTrigFlagGroup_
#define DEFINED_TYPEDEF_FOR_ARBT_RecTrigFlagGroup_

typedef struct
{
  boolean_T missed_aeb_flag;
  boolean_T false_aeb_flag;
  boolean_T driver_hard_braking_flag;
  boolean_T aeb_triggered_flag;
}
ARBT_RecTrigFlagGroup;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ARBT_DataBus_
#define DEFINED_TYPEDEF_FOR_ARBT_DataBus_

typedef struct
{
  ARBT_BrakeGroup BrakeGroup;
  ARBT_SteerGroup SteerGroup;
  ARBT_PowerGroup PowerGroup;
  ARBT_WarningGroup WarningGroup;
  ARBT_AccessoryGroup AccessoryGroup;
  ARBT_RecTrigFlagGroup RecTrigFlagGroup;
}
ARBT_DataBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumARBT_arbitration_winner_
#define DEFINED_TYPEDEF_FOR_EnumARBT_arbitration_winner_

typedef uint8_T EnumARBT_arbitration_winner;/* ARBT_NO_REQ = 0
                                               AEB = 1
                                               ACC = 2
                                               LCC = 3
                                               ALCA = 4
                                               BRAKE_OVRD = 5
                                               RSVD2 = 6 */

#define ARBT_NO_REQ                    ((EnumARBT_arbitration_winner)0) /* Default value */
#define AEB                            ((EnumARBT_arbitration_winner)1)
#define ACC                            ((EnumARBT_arbitration_winner)2)
#define LCC                            ((EnumARBT_arbitration_winner)3)
#define LKA                            ((EnumARBT_arbitration_winner)4)
#define BRAKE_OVRD                     ((EnumARBT_arbitration_winner)5)
#define RSVD2                          ((EnumARBT_arbitration_winner)6)
#endif
#endif                                 /* RTW_HEADER_ARBT_subsystem_integrated_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
