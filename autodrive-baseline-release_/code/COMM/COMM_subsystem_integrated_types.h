/*
 * File: COMM_subsystem_integrated_types.h
 *
 * Code generated for Simulink model 'COMM_subsystem_integrated'.
 *
 * Model version                  : 1.1787
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Jun 10 09:20:56 2020
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

#ifndef RTW_HEADER_COMM_subsystem_integrated_types_h_
#define RTW_HEADER_COMM_subsystem_integrated_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_CAN_MESSAGE_BUS_
#define DEFINED_TYPEDEF_FOR_CAN_MESSAGE_BUS_

typedef struct
{
  uint8_T Extended;
  uint8_T Length;
  uint8_T Remote;
  uint8_T Error;
  uint32_T ID;
  real_T Timestamp;
  uint8_T Data[8];
}
CAN_MESSAGE_BUS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_CAN_Data_Receive_
#define DEFINED_TYPEDEF_FOR_COMM_CAN_Data_Receive_

typedef struct
{
  CAN_MESSAGE_BUS Config_1_Receive__CAN_2_ID__195;
  CAN_MESSAGE_BUS Config_1_Receive__CAN_0_ID_1640;
  CAN_MESSAGE_BUS Config_1_Receive__CAN_0_ID__421;
  CAN_MESSAGE_BUS Config_1_Receive__CAN_0_ID__603;
  CAN_MESSAGE_BUS Config_1_Receive__CAN_0_ID__304;
  CAN_MESSAGE_BUS Config_1_Receive__CAN_0_ID__810;
  CAN_MESSAGE_BUS Config_2_Receive__CAN_2_ID__195;
  CAN_MESSAGE_BUS Config_2_Receive__CAN_2_ID_1640;
  CAN_MESSAGE_BUS Config_2_Receive__CAN_2_ID__421;
  CAN_MESSAGE_BUS Config_2_Receive__CAN_2_ID_1659;
  CAN_MESSAGE_BUS Config_2_Receive__CAN_2_ID__603;
  CAN_MESSAGE_BUS Config_2_Receive__CAN_2_ID__304;
  CAN_MESSAGE_BUS Config_2_Receive__CAN_2_ID__810;
  CAN_MESSAGE_BUS Config_3_Receive__CAN_2_ID__520;
  CAN_MESSAGE_BUS Config_3_Receive__CAN_2_ID__280;
  CAN_MESSAGE_BUS Config_3_Receive__CAN_2_ID__273;
  CAN_MESSAGE_BUS Config_3_Receive__CAN_2_ID_1640;
  CAN_MESSAGE_BUS Config_3_Receive__CAN_2_ID_1560;
  CAN_MESSAGE_BUS Config_3_Receive__CAN_2_ID__530;
  CAN_MESSAGE_BUS Config_3_Receive__CAN_0_ID__717;
  CAN_MESSAGE_BUS Config_3_Receive__CAN_0_ID__421;
  CAN_MESSAGE_BUS Config_3_Receive__CAN_0_ID__570;
  CAN_MESSAGE_BUS Config_3_Receive__CAN_0_ID__517;
  CAN_MESSAGE_BUS Config_3_Receive__CAN_0_ID__810;
  CAN_MESSAGE_BUS Config_3_Receive__CAN_0_ID__683;
  CAN_MESSAGE_BUS Config_3_Receive__CAN_0_ID__419;
  CAN_MESSAGE_BUS Config_3_Receive__CAN_0_ID_1638;
  CAN_MESSAGE_BUS Config_6_Receive__CAN_4_ID_201443255;
  CAN_MESSAGE_BUS Config_6_Receive__CAN_4_ID_418384139;
  CAN_MESSAGE_BUS Config_6_Receive__CAN_4_ID_201434535;
  CAN_MESSAGE_BUS Config_6_Receive__CAN_4_ID_419348235;
  CAN_MESSAGE_BUS Config_7_Receive__CAN_2_ID__820;
  CAN_MESSAGE_BUS Config_7_Receive__CAN_2_ID__544;
  CAN_MESSAGE_BUS Config_7_Receive__CAN_2_ID__332;
  CAN_MESSAGE_BUS Config_7_Receive__CAN_2_ID__344;
  CAN_MESSAGE_BUS Config_7_Receive__CAN_2_ID__284;
  CAN_MESSAGE_BUS Config_7_Receive__CAN_2_ID__258;
}
COMM_CAN_Data_Receive;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R01_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R01_

typedef struct
{
  uint8_T VCU_Mode;
  uint8_T Manual_Brake_Switch;
  real32_T Manual_Accelerator_Pedal;
  uint16_T Auto_To_Manual_Tips;
}
COMM_VEH_RX_R01;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R02_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R02_

typedef struct
{
  int16_T Nominal_friction_percent_torque;
}
COMM_VEH_RX_R02;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R03_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R03_

typedef struct
{
  uint16_T Engine_Oil_Pressure;
}
COMM_VEH_RX_R03;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R07_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R07_

typedef struct
{
  int16_T Engine_coolant_temperature;
}
COMM_VEH_RX_R07;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R08_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R08_

typedef struct
{
  real32_T Catalyst_Tank_Level;
}
COMM_VEH_RX_R08;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R09_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R09_

typedef struct
{
  real32_T Output_Shaft_Speed;
  real32_T Input_Shaft_Speed;
}
COMM_VEH_RX_R09;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R10_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R10_

typedef struct
{
  real32_T Actual_Gear_Ratio;
  int16_T Current_Gear;
}
COMM_VEH_RX_R10;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R11_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R11_

typedef struct
{
  uint8_T Engine_Coolant_Level_Low_Lamp;
}
COMM_VEH_RX_R11;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R12_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R12_

typedef struct
{
  uint16_T Ser_Brake_Circuit_1_Air_Pressure;
  uint16_T Ser_Brake_Circuit_2_Air_Pressure;
}
COMM_VEH_RX_R12;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R13_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R13_

typedef struct
{
  uint8_T Engine_torque_mode;
  int16_T Driver_demand_percent_torque;
  int16_T Actua_engine_percent_torque;
  real32_T Engine_Speed;
}
COMM_VEH_RX_R13;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R14_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R14_

typedef struct
{
  uint8_T Parking_Brake_Switch;
  real32_T Wheel_based_vehicle_speed;
  uint8_T Brake_Switch;
}
COMM_VEH_RX_R14;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R15_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R15_

typedef struct
{
  real32_T High_Resolu_TotalVehDistance;
}
COMM_VEH_RX_R15;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R16_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R16_

typedef struct
{
  uint8_T ABS_active;
  uint8_T EBS_Brake_Switch;
  real32_T Brake_Pedal_Position;
  uint8_T EBS_Red_Warning_Signal;
  uint8_T ABS_EBSAmberWarningSig;
}
COMM_VEH_RX_R16;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R17_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R17_

typedef struct
{
  real32_T Front_Axle_Speed;
  real32_T Relative_Speed_FA_Leftwheel;
  real32_T Relative_Speed_RA_RightWheel;
  real32_T Relative_Speed_RA1_Leftwheel;
  real32_T Relative_Speed_RA1_Rightwheel;
  real32_T Relative_Speed_RA2_Leftwheel;
  real32_T Relative_Speed_RA2_Rightwheel;
}
COMM_VEH_RX_R17;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R19_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R19_

typedef struct
{
  real32_T Steer_Wheel_Angle;
  real32_T Yaw_Rate;
  real32_T Lateral_Accerleration;
  real32_T Longitudinal_Acceleration;
}
COMM_VEH_RX_R19;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R20_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R20_

typedef struct
{
  real32_T Column_Torque;
  real32_T Coulmn_Velocity;
  real32_T Pull_Compensation;
  boolean_T Column_Torque_QF;
  boolean_T Column_Velocity_QF;
  boolean_T Ignition_State;
  boolean_T Hands_off_Detected;
  boolean_T Hands_on_Detcted;
  uint8_T Column_Message_Checksum;
  uint8_T Column_Message_Counter;
}
COMM_VEH_RX_R20;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R21_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R21_

typedef struct
{
  real32_T Absolute_Steering_Position;
  real32_T External_Input_Command_Echo;
  uint8_T Status_Error;
  uint8_T Actual_Mode;
  uint8_T Request_Mode;
  boolean_T Absolute_Steering_Position_QF;
  uint8_T Steer_Message_Checksum;
  uint8_T Steer_Message_counter;
}
COMM_VEH_RX_R21;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R25_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R25_

typedef struct
{
  uint8_T EPB_Working_Mode;
  uint8_T Autohold_Working_Status;
  uint8_T EPB_Driverless_mode;
}
COMM_VEH_RX_R25;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R27_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R27_

typedef struct
{
  uint8_T Tractor_Front_Fog_LightsCommand;
  uint8_T Rear_Fog_Light_Command;
}
COMM_VEH_RX_R27;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R28_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R28_

typedef struct
{
  uint8_T Veh_running_state;
  uint8_T Low_beam_light_state;
  uint8_T High_beam_light_state;
  uint8_T Right_turnning_light_state;
  uint8_T Left_turnning_light_state;
  uint8_T Reversing_light_and_alarm_horn;
  uint8_T Position_lamp_state;
}
COMM_VEH_RX_R28;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R29_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R29_

typedef struct
{
  uint8_T BCM_response_status;
  uint8_T Rear_brake_lamp_status;
  uint8_T Horn_command_status;
}
COMM_VEH_RX_R29;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R30_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R30_

typedef struct
{
  uint8_T Front_Operator_Wiper_Switch;
  uint8_T Front_Operator_Washer_Switch;
}
COMM_VEH_RX_R30;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R32_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R32_

typedef struct
{
  uint8_T Tire_Location;
  uint16_T Tire_pressure;
  real32_T Tire_Temperature;
  uint8_T Tire_Status;
  uint8_T Extended_Tire_Pressure_Support;
  real32_T Tire_Air_Leakage_Rate;
  uint8_T Tire_Pressure_Thresh_Detection;
}
COMM_VEH_RX_R32;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R33_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R33_

typedef struct
{
  int8_T Tire_Location;
  uint16_T Tire_Pressure_Extended_Range;
  uint16_T Required_Tire_Pressure;
}
COMM_VEH_RX_R33;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R34_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R34_

typedef struct
{
  uint8_T Open_Status_of_Door_1_Driver;
  uint8_T OpenStatus_of_Door_2_Passenger;
}
COMM_VEH_RX_R34;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R35_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R35_

typedef struct
{
  real32_T Fuel_Level_1;
}
COMM_VEH_RX_R35;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R39_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R39_

typedef struct
{
  uint8_T ADV_Function_Switch_1;
  uint8_T ADV_Function_Switch_2;
}
COMM_VEH_RX_R39;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R40_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_R40_

typedef struct
{
  uint8_T Axle_Location;
  real32_T Axle_Weight;
}
COMM_VEH_RX_R40;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_VEH_RX_Data_
#define DEFINED_TYPEDEF_FOR_COMM_VEH_RX_Data_

typedef struct
{
  COMM_VEH_RX_R01 R01;
  COMM_VEH_RX_R02 R02;
  COMM_VEH_RX_R03 R03;
  COMM_VEH_RX_R07 R07;
  COMM_VEH_RX_R08 R08;
  COMM_VEH_RX_R09 R09;
  COMM_VEH_RX_R10 R10;
  COMM_VEH_RX_R11 R11;
  COMM_VEH_RX_R12 R12;
  COMM_VEH_RX_R13 R13;
  COMM_VEH_RX_R14 R14;
  COMM_VEH_RX_R15 R15;
  COMM_VEH_RX_R16 R16;
  COMM_VEH_RX_R17 R17;
  COMM_VEH_RX_R19 R19;
  COMM_VEH_RX_R20 R20;
  COMM_VEH_RX_R21 R21;
  COMM_VEH_RX_R25 R25;
  COMM_VEH_RX_R27 R27;
  COMM_VEH_RX_R28 R28;
  COMM_VEH_RX_R29 R29;
  COMM_VEH_RX_R30 R30;
  COMM_VEH_RX_R32 R32;
  COMM_VEH_RX_R33 R33;
  COMM_VEH_RX_R34 R34;
  COMM_VEH_RX_R35 R35;
  COMM_VEH_RX_R39 R39;
  COMM_VEH_RX_R40 R40;
}
COMM_VEH_RX_Data;

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

#ifndef DEFINED_TYPEDEF_FOR_COMM_Bus_VEH_Config_
#define DEFINED_TYPEDEF_FOR_COMM_Bus_VEH_Config_

typedef struct
{
  /* Minimum turning radius */
  real32_T VfCOMM_VEH_MinTurnRadius;

  /* This is the angle between origin to front axle and origin to front wheel */
  real32_T VfCOMM_VEH_AngOrigin2FrontWheel;

  /* Moment of inertia of the whole vehicle around z axis */
  real32_T VfCOMM_VEH_YawInertia_Z;

  /* This is the distance between the cordinate and the front wheel */
  real32_T VfCOMM_VEH_DisOrigin2FrontWheel;

  /* This is the distance between the cordinate origin and the rear surface */
  real32_T VfCOMM_VEH_DisOrigin2End;

  /* This is the distance between the cordinate origin and the rear axle */
  real32_T VfCOMM_VEH_DisOrigin2RearAxle;

  /* This is the distance between the coordinate origin and the front surface */
  real32_T VfCOMM_VEH_DisOrigin2Head;

  /* Vehicle's width */
  real32_T VfCOMM_VEH_Width;

  /* This is whell diameter */
  real32_T VfACCS_VEH_WheelDiameter;

  /* This is vehicle length */
  real32_T VfCOMM_VEH_Length;

  /* This is cornering stiffness of rear wheel */
  real32_T VfCOMM_VEH_StiffnessRear;

  /* This is cornering stiffness of front wheel */
  real32_T VfCOMM_VEH_StiffnessFront;

  /* This is the distance between left wheel and right wheel */
  real32_T VfCOMM_VEH_DisLeft2Right;

  /* This is the distance between Cetroid and Front surface */
  real32_T VfCOMM_VEH_DisCentorid2Front;

  /* Vehicle mass */
  real32_T VfCOMM_VEH_Mass;

  /* This is distance between two axes */
  real32_T VfCOMM_VEH_DisFront2Rear;
}
COMM_Bus_VEH_Config;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_RX_AutodriveMode_
#define DEFINED_TYPEDEF_FOR_COMM_RX_AutodriveMode_

/* Can Receive data about AutodriveMode */
typedef struct
{
  /* Automatic driving master switch status (from driver) */
  boolean_T VCU_AutodriveMainSwitch;

  /* Reasons for not being able to enter automatic driving state£º
     Bit 1: comfort can bus off;
     Bit 2: power can bus off:
     Bit 3: adv control mode message timeout
     Bit 4: adv torque request message CS / LS fault;
     Bit 5: pull down the handbrake switch;
     Bit 6: The Trailer hand brake switch is pulled down;
     Bit 7: Cruise activation;
     Bit 8: when the accelerator is depressed, it is greater than a certain threshold;
     Bit 9: when the accelerator pedal fails;
     Bit 10: the brake pedal is depressed;
     Bit 11: brake pedal failure;
     Bit 12: intelligent driving function shielding. */
  uint16_T VCU_AutoToManualTips;

  /* Whether automatic driving is activated as feedback from VCU */
  boolean_T VCU_AutodriveActiveStatus;
}
COMM_RX_AutodriveMode;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_RX_BCM_
#define DEFINED_TYPEDEF_FOR_COMM_RX_BCM_

/* Can Receive data about BCM */
typedef struct
{
  /* Indicate the cruise switch */
  boolean_T BCM_CruiseSwValid;

  /* BCM_CruiseSwCancel */
  boolean_T BCM_CruiseSwCancel;

  /* Cruise Resume Switch,Speed Up */
  boolean_T BCM_CruiseSwResume;

  /* Cruise Set Switch,Speed Down */
  boolean_T BCM_CruiseSwSet;

  /* To increase the TimeGapSet */
  boolean_T BCM_CruiseSwTimeGapPlus;

  /* To decrease the TimeGapSet */
  boolean_T BCM_CruiseSwTimeGapMinus;

  /* BCM_ACC MainSwitchStatus */
  boolean_T BCM_CruiseSwMain;

  /* BCM_LIMMainSwitchSts */
  boolean_T BCM_CruiseSwLimitMain;

  /* BCM_DM_TargetModeReq£¨0£ºNormal£»1£ºSport£»2£ºEco£»other£ºReserve£© */
  uint8_T BCM_DriveMode;

  /* Signal from ACU for Driver seat belt warning indicator display on IPK */
  boolean_T BCM_DriverSeatBelt;

  /* Signal from ACU for Driver seat belt warning  is valid */
  boolean_T BCM_DriverSeatBeltValid;

  /* Cruise control status */
  uint8_T BCM_CruiseControlStatus;

  /* Turning signal request received from ADCU */
  boolean_T BCM_TurningLightEcho;

  /* Low beam status */
  boolean_T BCM_LowBeamSwitch;

  /* High beam status */
  boolean_T BCM_HighBeamSwitch;

  /* Brake light status */
  boolean_T BCM_BrakeLightStatus;

  /* Left turning signal status */
  boolean_T BCM_LeftTurningLightState;

  /* Right turning signal status */
  boolean_T BCM_RightTurningLightState;

  /* Ignition key door status */
  boolean_T BCM_IgnitionKeyState;

  /* Driver's door signal */
  boolean_T BCM_DriverDoorStatus;

  /* Copilot's door signal */
  boolean_T BCM_PassengerDoorStatus;

  /* Right rear door signal */
  boolean_T BCM_RearRightDoorStatus;

  /* Left rear door signal */
  boolean_T BCM_RearLeftDoorStatus;

  /* Signal of front hatch cover */
  boolean_T BCM_FrontHoodStatus;

  /* Signal of trunk */
  boolean_T BCM_BackTrunkStatus;

  /* Wiper Switch */
  boolean_T BCM_WiperSwitch;

  /* BCM controlled state */
  boolean_T BCM_ControlResponse;
}
COMM_RX_BCM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_RX_Brake_
#define DEFINED_TYPEDEF_FOR_COMM_RX_Brake_

/* Can Receive data about Brake */
typedef struct
{
  /* Signal from TCS\ESC to indicate if TCS is activate or not */
  boolean_T ESP_TCSActive;

  /* ABS active */
  boolean_T ESP_ABSActive;

  /* Brake pressure (air circuit) */
  uint16_T ESP_BrakeAirTankPressure;

  /* Brake pedal effective */
  boolean_T VCU_BrakePedalValid;

  /* Whether ESP brake control responds */
  boolean_T ESP_BrakeControlResponse;

  /* Brake request received by VCU from ADCU */
  real32_T VCU_TargetBrakePedalEcho;

  /* Actual brake pedal position */
  real32_T VCU_ActualBrakePedalPosition;

  /* Actual brake switch signal */
  boolean_T VCU_ActualBrakePedalSwitch;

  /* Brake master cylinder pressure */
  real32_T ESP_MasterCylinderPress;

  /* Effective mark of brake master cylinder pressure */
  boolean_T ESP_MasterCylinderPressValid;

  /* ESP system fault status(0:Normal) */
  uint8_T ESP_SystemFaultStatus;
}
COMM_RX_Brake;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_RX_Parking_
#define DEFINED_TYPEDEF_FOR_COMM_RX_Parking_

/* Can Receive data about Parking */
typedef struct
{
  /* Auto Park status */
  boolean_T EPB_AutoholdStatus;

  /* EPB actual control status(0:Release) */
  uint8_T EPB_ActualControlStatus;

  /* EPB fault status(0:NoFault) */
  uint8_T EPB_SystemFaultStatus;

  /* Whether the EPB Park control respond */
  boolean_T EPB_ParkingControlResponse;

  /* EPB switch status */
  boolean_T EPB_SwitchStatus;
}
COMM_RX_Parking;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_RX_Power_
#define DEFINED_TYPEDEF_FOR_COMM_RX_Power_

/* Can Receive data about Power */
typedef struct
{
  /* 0-Reset Start/Stop not active(any engine condition possible)... */
  uint8_T EMS_StartStopStatus;

  /* Invalid flag for EMS_EngineSpeedRPM */
  boolean_T EMS_EngineSpeedValid;

  /* Signal from EMS to indicate ACCelerate pedal position */
  real32_T VCU_VirtualAccelPedalPosition;

  /* EMS_AccelPedalPosition invalid flag */
  boolean_T VCU_VirtualAccelPedalValid;

  /* indicating the torque demanded by the driver is higher than the torque demanded by ESP-VLC. */
  boolean_T VCU_AccelPedalOverride;

  /* Engine status(0£ºKeyOff£»1£ºACC£»2£ºKeyOn£»3£ºCrank£»4£ºRun) */
  uint8_T EMS_EngineState;

  /* Engine speed */
  real32_T EMS_EngineSpeed;

  /* Less cooling water */
  boolean_T EMS_CoolantLevelLow;

  /* Whether torque control respond */
  boolean_T PCU_PowerControlResponse;

  /* Driver's desired torque */
  real32_T PCU_DriverDemandTorque;

  /* Actual engine torque */
  real32_T PCU_ActualEngineTorque;

  /* Oil pressure */
  uint16_T EMS_EngineOilPressure;

  /* Engine cooling water temperature */
  int16_T EMS_EngineCoolantTemperature;

  /* Status of urea tank */
  real32_T EMS_CatalystTankLevel;

  /* Accelerator pedal Valid */
  boolean_T VCU_AccelPedalValid;

  /* Acceleration request from adcu received by VCU */
  real32_T VCU_TargetAccelPedalPostionEcho;

  /* Actual pedal opening degree */
  real32_T VCU_ActualAccelPedalPosition;

  /* Power system fault level(0:NoFault) */
  uint8_T PCU_PowertrainFaultLevel;

  /* Power battery SOC */
  real32_T PCU_BatterySOC;

  /* Motor speed */
  real32_T PCU_MotorSpeed;

  /* Actual torque of motor */
  real32_T PCU_MotorActualTorque;

  /* Engine torque loss */
  real32_T PCU_EngineTorqueLoss;
}
COMM_RX_Power;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_RX_Steering_
#define DEFINED_TYPEDEF_FOR_COMM_RX_Steering_

/* Can Receive data about Steering */
typedef struct
{
  /* Validation bit of measured torsion bar torque. */
  boolean_T EPS_SteeringWheelTorqueValid;

  /* EPS control status for LDW vibration */
  boolean_T EPS_SteeringControlResponse_LDW;

  /* EPS control status for LKS */
  boolean_T EPS_SteeringControlResponse_LCC;

  /* Target corner status received by EPS from ADCU£¨0£ºDriver£»1£ºSteeringAngle£»2£ºSteeringWheelTorque£© */
  uint8_T EPS_SteeringModeEcho;

  /* Whether the steering system respond */
  boolean_T EPS_SteeringControlResponse;

  /* Target corner signal received by EPS from ADCU */
  real32_T EPS_TargetSteeringAngleEcho;

  /* Actual steering wheel angle feedback */
  real32_T EPS_ActualSteeringAngle;

  /* Steering wheel angle change rate */
  real32_T EPS_SteeringAngleRate;

  /* Steering performance fault level(0:NoFault) */
  uint8_T EPS_FaultLevel;

  /* Torque applied by the driver to the steering wheel */
  real32_T EPS_SteeringWheelTorque;

  /* Driver hands off steering wheel */
  boolean_T EPS_HandsOffWheelDetected;

  /* Driver's hand on steering wheel */
  boolean_T EPS_HandsOnWheelDetected;
}
COMM_RX_Steering;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_RX_Transmission_
#define DEFINED_TYPEDEF_FOR_COMM_RX_Transmission_

/* Can Receive data about Transmission */
typedef struct
{
  /* Target gear received by TCU from ADCU(0:Neutral;1-12:ForwardGears;13:Reverse;14Park;15:Invalid) */
  uint8_T TCU_TargetGearPositionEcho;

  /* Lever position (PRNDL)£¨0£ºPark;1:Reverse;2:Neutral;3:Drive£© */
  uint8_T TCU_ShiftLevelPosition;

  /* Actual gear (0:Neutral;1-12:ForwardGears;13:Reverse;14Park;15:Invalid) */
  uint8_T TCU_ActualGearPosition;

  /* Actual gear ratio */
  real32_T TCU_ActualGearRatio;
}
COMM_RX_Transmission;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_RX_VehicleDynamics_
#define DEFINED_TYPEDEF_FOR_COMM_RX_VehicleDynamics_

/* Can Receive data about VehicleDynamics */
typedef struct
{
  /* Valid flag bit of yaw */
  boolean_T VDC_YawRateValid;

  /* Effective mark position of longitudinal acceleration */
  boolean_T VDC_LongAccelerationValid;

  /* Effective sign bit of lateral acceleration */
  boolean_T VDC_LateralAccelerationValid;

  /* Yaw Rate from chassis */
  real32_T VDC_YawRate;

  /* Vehicle speed */
  real32_T VDC_VehicleSpeed;

  /* Longitudinal acceleration */
  real32_T VDC_LongAcceleration;

  /* Lateral acceleration */
  real32_T VDC_LateralAcceleration;

  /* Right wheel speed of rear axle 1 */
  real32_T VDC_WheelSpeed_RR1;

  /* Right wheel speed of rear axle 2 */
  real32_T VDC_WheelSpeed_RR2;

  /* Left wheel speed of rear axle 1 */
  real32_T VDC_WheelSpeed_RL1;

  /* Left wheel speed of rear axle 2 */
  real32_T VDC_WheelSpeed_RL2;

  /* Right front wheel speed */
  real32_T VDC_WheelSpeed_FR;

  /* Left front wheel speed */
  real32_T VDC_WheelSpeed_FL;

  /* Effective mark of right wheel speed of rear axle 1 */
  boolean_T VDC_WheelSpeed_RR1Valid;

  /* Effective mark of right wheel speed of rear axle 2 */
  boolean_T VDC_WheelSpeed_RR2Valid;

  /* Effective mark of left wheel speed of rear axle 1 */
  boolean_T VDC_WheelSpeed_RL1Valid;

  /* Effective mark of left wheel speed of rear axle 2 */
  boolean_T VDC_WheelSpeed_RL2Valid;

  /* Effective mark of right front wheel speed */
  boolean_T VDC_WheelSpeed_FRValid;

  /* Effective mark of left front wheel speed */
  boolean_T VDC_WheelSpeed_FLValid;

  /* Left rear wheel encoder */
  uint32_T VDC_WheelEncoderCounter_RL;

  /* Right rear wheel encoder */
  uint32_T VDC_WheelEncoderCounter_RR;
}
COMM_RX_VehicleDynamics;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_CANR_Databus_
#define DEFINED_TYPEDEF_FOR_COMM_CANR_Databus_

/* Can Receive data bus */
typedef struct
{
  COMM_RX_AutodriveMode COMM_RX_AutodriveMode;
  COMM_RX_BCM COMM_RX_BCM;
  COMM_RX_Brake COMM_RX_Brake;
  COMM_RX_Parking COMM_RX_Parking;
  COMM_RX_Power COMM_RX_Power;
  COMM_RX_Steering COMM_RX_Steering;
  COMM_RX_Transmission COMM_RX_Transmission;
  COMM_RX_VehicleDynamics COMM_RX_VehicleDynamics;
}
COMM_CANR_Databus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_TX_AutodriveMode_
#define DEFINED_TYPEDEF_FOR_COMM_TX_AutodriveMode_

/* Can Transmit data for AutodriveMode Control */
typedef struct
{
  /* Automatic driving enable request */
  boolean_T ADCU_AutodriveEnable;
}
COMM_TX_AutodriveMode;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_TX_BCM_
#define DEFINED_TYPEDEF_FOR_COMM_TX_BCM_

/* Can Transmit data for BCM Control */
typedef struct
{
  /* BCM control enable */
  boolean_T ADCU_BCMControlEnable;

  /* Brake light request */
  boolean_T ADCU_BrakeLightRequest;

  /* Low beam request */
  boolean_T ADCU_LowBeamRequest;

  /* High beam request */
  boolean_T ADCU_HighBeamRequest;

  /* Left turn signal request */
  boolean_T ADCU_LeftTurningLightRequest;

  /* Right turn signal request */
  boolean_T ADCU_RightTurningLightRequest;

  /* Front fog lamp request */
  boolean_T ADCU_FrontFogLightRequest;

  /* Rear fog lamp request */
  boolean_T ADCU_BackFogLightRequest;

  /* Marker lamp request */
  boolean_T ADCU_PositionLightRequest;

  /* Double flash request */
  boolean_T ADCU_EmergencyLightRequest;

  /* Horn request */
  boolean_T ADCU_HornRequest;

  /* Wiper control request */
  uint8_T ADCU_WiperControlRequest;

  /* Headlight cleaning control request */
  boolean_T ADCU_WashingControlRequest;
}
COMM_TX_BCM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_TX_Brake_
#define DEFINED_TYPEDEF_FOR_COMM_TX_Brake_

/* Can Transmit data for Brake Control */
typedef struct
{
  /* Brake enable */
  boolean_T ADCU_BrakeEnable;

  /* It could be brake pressure or percentage */
  real32_T ADCU_BrakePressureValue;

  /* Deceleration value (Usually negative) */
  real32_T ADCU_BrakeDecelValue;

  /* Brake system pre press request */
  boolean_T ADCU_BrakePrechargeRequest;
}
COMM_TX_Brake;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_TX_HMI_
#define DEFINED_TYPEDEF_FOR_COMM_TX_HMI_

/* Can Transmit data for HMI Control */
typedef struct
{
  /* Target vehicle speed */
  real32_T ADCU_TargetVehicleSpeed;

  /* Acceleration demand indicator£¨US Demo Only£© */
  boolean_T ADCU_SpeedUpIndicator;

  /* Deceleration demand indicator£¨US Demo Only£© */
  boolean_T ADCU_SpeedDownIndicator;

  /* Overspeed alarm */
  boolean_T ADCU_OverSpeedWarning;

  /* Forward collision warning */
  uint8_T ADCU_FCW_Warning;
}
COMM_TX_HMI;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_TX_Parking_
#define DEFINED_TYPEDEF_FOR_COMM_TX_Parking_

/* Can Transmit data for Parking Control */
typedef struct
{
  /* Pressure maintaining request */
  boolean_T ADCU_ParkingPressureRequest;

  /* Parking control status(0:Release;1:Clamp) */
  uint8_T ADCU_ParkingControlValue;

  /* Parking control enable */
  boolean_T ADCU_ParkingControlEnable;
}
COMM_TX_Parking;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_TX_Power_
#define DEFINED_TYPEDEF_FOR_COMM_TX_Power_

/* Can Transmit data for Power Control */
typedef struct
{
  /* Torque request enable */
  boolean_T ADCU_PowerEnable;

  /* Torque request value or percentage */
  real32_T ADCU_PowerTorqueValue;

  /* Acceleration value */
  real32_T ADCU_PowerAccelValue;

  /* Start request */
  boolean_T ADCU_LaunchRequest;
}
COMM_TX_Power;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_TX_Steering_
#define DEFINED_TYPEDEF_FOR_COMM_TX_Steering_

/* Can Transmit data for Steering Control */
typedef struct
{
  /* Steering wheel torque control enable */
  boolean_T ADCU_SteeringTorqueEnable;

  /* Steering wheel torque control value */
  real32_T ADCU_SteeringTorqueValue;

  /* Steering wheel angle enable */
  boolean_T ADCU_SteeringAngleEnable;

  /* Steering wheel angle value */
  real32_T ADCU_SteeringAngleValue;

  /* Steering wheel angle maximum speed */
  real32_T ADCU_SteeringAngleSpeed;
}
COMM_TX_Steering;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_TX_Transmission_
#define DEFINED_TYPEDEF_FOR_COMM_TX_Transmission_

/* Can Transmit data for Transmission Control */
typedef struct
{
  /* Gear control enable */
  boolean_T ADCU_TargetGearEnable;

  /* Target gear(0:Neutral;1-12:ForwardGears;13:Reverse;14Park;15:Invalid) */
  uint8_T ADCU_TargetGearValue;
}
COMM_TX_Transmission;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_CANT_Databus_
#define DEFINED_TYPEDEF_FOR_COMM_CANT_Databus_

/* Can Transmit data bus */
typedef struct
{
  COMM_TX_AutodriveMode COMM_TX_AutodriveMode;
  COMM_TX_BCM COMM_TX_BCM;
  COMM_TX_Brake COMM_TX_Brake;
  COMM_TX_HMI COMM_TX_HMI;
  COMM_TX_Parking COMM_TX_Parking;
  COMM_TX_Power COMM_TX_Power;
  COMM_TX_Steering COMM_TX_Steering;
  COMM_TX_Transmission COMM_TX_Transmission;
}
COMM_CANT_Databus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_CAN_Data_Transmit_
#define DEFINED_TYPEDEF_FOR_COMM_CAN_Data_Transmit_

typedef struct
{
  CAN_MESSAGE_BUS Config_1_Transmit_CAN_2_ID__193;
  CAN_MESSAGE_BUS Config_2_Transmit_CAN_2_ID__193;
  CAN_MESSAGE_BUS Config_3_Transmit_CAN_2_ID__550;
  CAN_MESSAGE_BUS Config_3_Transmit_CAN_0_ID__581;
  CAN_MESSAGE_BUS Config_6_Transmit_CAN_4_ID_201591594;
  CAN_MESSAGE_BUS Config_6_Transmit_CAN_4_ID_201439175;
  CAN_MESSAGE_BUS Config_6_Transmit_CAN_4_ID_201504711;
  CAN_MESSAGE_BUS Config_7_Transmit_CAN_2_ID_1586;
}
COMM_CAN_Data_Transmit;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_ADCU_TX_T01_
#define DEFINED_TYPEDEF_FOR_COMM_ADCU_TX_T01_

typedef struct
{
  uint8_T ADV_Status;
  real32_T Target_Speed;
  uint8_T Brake_Switch;
  real32_T XBR_External_Acc_Demand;
}
COMM_ADCU_TX_T01;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_ADCU_TX_T02_
#define DEFINED_TYPEDEF_FOR_COMM_ADCU_TX_T02_

typedef struct
{
  int16_T Transmission_Requested_Gear;
}
COMM_ADCU_TX_T02;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_ADCU_TX_T03_
#define DEFINED_TYPEDEF_FOR_COMM_ADCU_TX_T03_

typedef struct
{
  uint8_T Override_Control_Mode;
  uint8_T Override_Control_Mode_Priority;
  int16_T Requested_Torque_Torque_Limit;
  uint8_T Message_Counter;
  uint8_T Message_Checksum;
}
COMM_ADCU_TX_T03;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_ADCU_TX_T05_
#define DEFINED_TYPEDEF_FOR_COMM_ADCU_TX_T05_

typedef struct
{
  real32_T XBR1_External_Accleration_Demand;
  uint8_T XBR1_EBI_Mode;
  uint8_T XBR1_Priority;
  uint8_T XBR1_Control_Mode;
  uint8_T XBR1_Message_Counter;
  uint8_T XBR1_Message_Checksum;
}
COMM_ADCU_TX_T05;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_ADCU_TX_T08_
#define DEFINED_TYPEDEF_FOR_COMM_ADCU_TX_T08_

typedef struct
{
  uint8_T ReAX_Desired_operation_mode;
  real32_T ReAX_Command_from_ext_controller;
  uint8_T ReAX_Message_counter;
  uint8_T ReAX_Message_Checksum;
}
COMM_ADCU_TX_T08;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_ADCU_TX_T13_
#define DEFINED_TYPEDEF_FOR_COMM_ADCU_TX_T13_

typedef struct
{
  uint8_T EPB_Control_mode;
  uint8_T EPB_Control_Command;
  uint8_T EPB_Message_Counter;
  uint8_T EPB_Message_Checksum;
}
COMM_ADCU_TX_T13;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_ADCU_TX_T15_
#define DEFINED_TYPEDEF_FOR_COMM_ADCU_TX_T15_

typedef struct
{
  uint8_T Running_Light_Command;
  uint8_T Low_Beam_Head_Light_Command;
  uint8_T High_Beam_Light_Command;
  uint8_T Tractor_Front_Fog_Lights_Command;
  uint8_T Right_Turn_Signal_Lights_Command;
  uint8_T Left_Turn_Signal_Lights_Command;
  uint8_T Alarm_Horn_Command;
  uint8_T Implement_Marker_Light_Command;
  uint8_T Rear_Fog_Light_Command;
}
COMM_ADCU_TX_T15;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_ADCU_TX_T16_
#define DEFINED_TYPEDEF_FOR_COMM_ADCU_TX_T16_

typedef struct
{
  uint8_T Wiper_switch_control_command;
  uint8_T Washing_switch_control_command;
  uint8_T BCM_control_by_ADV_state;
  uint8_T Rear_brake_switch_control;
  uint8_T Horn_control_command;
}
COMM_ADCU_TX_T16;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COMM_ADCU_TX_Data_
#define DEFINED_TYPEDEF_FOR_COMM_ADCU_TX_Data_

typedef struct
{
  COMM_ADCU_TX_T01 T01;
  COMM_ADCU_TX_T02 T02;
  COMM_ADCU_TX_T03 T03;
  COMM_ADCU_TX_T05 T05;
  COMM_ADCU_TX_T08 T08;
  COMM_ADCU_TX_T13 T13;
  COMM_ADCU_TX_T15 T15;
  COMM_ADCU_TX_T16 T16;
}
COMM_ADCU_TX_Data;

#endif

#ifndef typedef_dsp_private_MedianFilterCG_CO_T
#define typedef_dsp_private_MedianFilterCG_CO_T

typedef struct
{
  int32_T isInitialized;
  real32_T pWinLen;
  real32_T pBuf[5];
  real32_T pHeap[5];
  real32_T pMidHeap;
  real32_T pIdx;
  real32_T pPos[5];
  real32_T pMinHeapLength;
  real32_T pMaxHeapLength;
}
dsp_private_MedianFilterCG_CO_T;

#endif                                 /*typedef_dsp_private_MedianFilterCG_CO_T*/

#ifndef typedef_cell_wrap_COMM_subsystem_inte_T
#define typedef_cell_wrap_COMM_subsystem_inte_T

typedef struct
{
  uint32_T f1[8];
}
cell_wrap_COMM_subsystem_inte_T;

#endif                                 /*typedef_cell_wrap_COMM_subsystem_inte_T*/

#ifndef typedef_dsp_MedianFilter_COMM_subsyst_T
#define typedef_dsp_MedianFilter_COMM_subsyst_T

typedef struct
{
  int32_T isInitialized;
  cell_wrap_COMM_subsystem_inte_T inputVarSize;
  int32_T NumChannels;
  dsp_private_MedianFilterCG_CO_T pMID;
}
dsp_MedianFilter_COMM_subsyst_T;

#endif                                 /*typedef_dsp_MedianFilter_COMM_subsyst_T*/
#endif                                 /* RTW_HEADER_COMM_subsystem_integrated_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
