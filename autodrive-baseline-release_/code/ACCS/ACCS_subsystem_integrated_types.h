/*
 * File: ACCS_subsystem_integrated_types.h
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

#ifndef RTW_HEADER_ACCS_subsystem_integrated_types_h_
#define RTW_HEADER_ACCS_subsystem_integrated_types_h_
#include "rtwtypes.h"
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

#ifndef DEFINED_TYPEDEF_FOR_COMM_RX_AutodriveMode_
#define DEFINED_TYPEDEF_FOR_COMM_RX_AutodriveMode_

/* Can Receive data about AutodriveMode */
typedef struct
{
  /* Automatic driving master switch status (from driver) */
  boolean_T VCU_AutodriveMainSwitch;

  /* Reasons for not being able to enter automatic driving state：
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

  /* BCM_DM_TargetModeReq（0：Normal；1：Sport；2：Eco；other：Reserve） */
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

  /* Engine status(0：KeyOff；1：ACC；2：KeyOn；3：Crank；4：Run) */
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

  /* Target corner status received by EPS from ADCU（0：Driver；1：SteeringAngle；2：SteeringWheelTorque） */
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

  /* Lever position (PRNDL)（0：Park;1:Reverse;2:Neutral;3:Drive） */
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

typedef uint8_T EnumDCSN_change_lane_cancel_reason;/* 0 = CL_CANCEL_NO_REQUEST
                                                      1 = CL_CANCEL_RESERVED */

#define CL_CANCEL_NO_REQUEST           ((EnumDCSN_change_lane_cancel_reason)0) /* Default value */
#define CL_CANCEL_RESERVED             ((EnumDCSN_change_lane_cancel_reason)1)
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
  Vector2f start_rel;
  Vector2f end_rel;

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

#ifndef DEFINED_TYPEDEF_FOR_EnumALCA_state_
#define DEFINED_TYPEDEF_FOR_EnumALCA_state_

typedef uint8_T EnumALCA_state;        /* 0: ALCA_state_OFF
                                          1: ALCA_state_Standby
                                          2: ALCA_state_Activated
                                          3: ALCA_state_Waiting
                                          4: ALCA_state_Inform
                                          5: ALCA_state_Finish
                                          6: ALCA_state_Handover
                                          7: ALCA_state_Abort */

#define ALCA_state_OFF                 ((EnumALCA_state)0)       /* Default value */
#define ALCA_state_Standby             ((EnumALCA_state)1)
#define ALCA_state_Activated           ((EnumALCA_state)2)
#define ALCA_state_Waiting             ((EnumALCA_state)3)
#define ALCA_state_Inform              ((EnumALCA_state)4)
#define ALCA_state_Finish              ((EnumALCA_state)5)
#define ALCA_state_Handover            ((EnumALCA_state)6)
#define ALCA_state_Abort               ((EnumALCA_state)7)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumALCA_not_fulfill_reason_
#define DEFINED_TYPEDEF_FOR_EnumALCA_not_fulfill_reason_

typedef uint8_T EnumALCA_not_fulfill_reason;/* 0: ALCA_not_fulfill_reason_no_request
                                               1: ALCA_not_fulfill_reason_no_lane
                                               2: ALCA_not_fulfill_reason_mpfu_reject
                                               3: ALCA_not_fulfill_reason_has_obstacle
                                               4: ALCA_not_fulfill_reason_low_speed
                                               5: ALCA_not_fulfill_reason_high_speed
                                               6: ALCA_not_fulfill_reason_dangerous_conditions
                                               7: ALCA_not_fulfill_reason_system_error
                                               8: ALCA_not_fulfill_reason_too_often
                                               9: ALCA_not_fulfill_reason_check_fulfilled */

#define ALCA_not_fulfill_reason_no_request ((EnumALCA_not_fulfill_reason)0) /* Default value */
#define ALCA_not_fulfill_reason_no_lane ((EnumALCA_not_fulfill_reason)1)
#define ALCA_not_fulfill_reason_mpfu_reject ((EnumALCA_not_fulfill_reason)2)
#define ALCA_not_fulfill_reason_has_obstacle ((EnumALCA_not_fulfill_reason)3)
#define ALCA_not_fulfill_reason_low_speed ((EnumALCA_not_fulfill_reason)4)
#define ALCA_not_fulfill_reason_high_speed ((EnumALCA_not_fulfill_reason)5)
#define ALCA_not_fulfill_reason_dangerous_conditions ((EnumALCA_not_fulfill_reason)6)
#define ALCA_not_fulfill_reason_system_error ((EnumALCA_not_fulfill_reason)7)
#define ALCA_not_fulfill_reason_too_often ((EnumALCA_not_fulfill_reason)8)
#define ALCA_not_fulfill_reason_check_fulfilled ((EnumALCA_not_fulfill_reason)9)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumALCA_interrupt_type_
#define DEFINED_TYPEDEF_FOR_EnumALCA_interrupt_type_

typedef uint8_T EnumALCA_interrupt_type;/* 0: ALCA_interrupt_type_no
                                           1: ALCA_interrupt_type_driver_cancel */

#define ALCA_interrupt_type_no         ((EnumALCA_interrupt_type)0) /* Default value */
#define ALCA_interrupt_type_driver_cancel ((EnumALCA_interrupt_type)1)
#define ALCA_interrupt_type_has_obstacle ((EnumALCA_interrupt_type)2)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumALCA_inform_reason_
#define DEFINED_TYPEDEF_FOR_EnumALCA_inform_reason_

typedef uint8_T EnumALCA_inform_reason;/* 0: EnumALCA_inform_reason_no
                                          1: EnumALCA_inform_reason_low_cipv
                                          2: EnumALCA_inform_reason_accident_ahead */

#define EnumALCA_inform_reason_no      ((EnumALCA_inform_reason)0)
#define EnumALCA_inform_reason_low_cipv ((EnumALCA_inform_reason)1)
#define EnumALCA_inform_reason_accident_ahead ((EnumALCA_inform_reason)2) /* Default value */
#endif

#ifndef DEFINED_TYPEDEF_FOR_ALCA_DataBus_
#define DEFINED_TYPEDEF_FOR_ALCA_DataBus_

typedef struct
{
  /* ALCA state:
     0: ALCA_state_OFF
     1: ALCA_state_Standby
     2: ALCA_state_Activated
     3: ALCA_state_Waiting
     4: ALCA_state_Inform
     5: ALCA_state_Finish
     6: ALCA_state_Handover
     7: ALCA_state_Abort */
  EnumALCA_state state;

  /* Lane change request. */
  boolean_T request;

  /* Request side:
     0: FORWARD
     1: LEFT
     2: RIGHT */
  EnumDCSN_driving_direction request_side;

  /* not_fulfill reason:
     0: ALCA_not_fulfill_reason_no_request
     1: ALCA_not_fulfill_reason_no_lane
     2: ALCA_not_fulfill_reason_mpfu_reject
     3: ALCA_not_fulfill_reason_has_obstacle
     4: ALCA_not_fulfill_reason_low_speed
     5: ALCA_not_fulfill_reason_high_speed
     6: ALCA_not_fulfill_reason_dangerous_conditions
     7: ALCA_not_fulfill_reason_system_error
     8: ALCA_not_fulfill_reason_too_often
     9: ALCA_not_fulfill_reason_check_fulfilled */
  EnumALCA_not_fulfill_reason odd_not_fulfill_reason;

  /* bit1:ALCA_fault_type_EGMO_notReceived
     bit2:ALCA_fault_type_MPFU_notReceived
     bit3:ALCA_fault_type_OBFU_notReceived
     bit4:ALCA_fault_type_CAN_notReceived */
  uint8_T fault;

  /* ALCA has interrupt. */
  boolean_T interrupt;

  /* Interrupt tupe:
     0: ALCA_interrupt_type_no
     1: ALCA_interrupt_type_driver_cancel */
  EnumALCA_interrupt_type interrupt_type;

  /* Inform request, dispalay on hmi or ... */
  boolean_T inform_request;

  /* 0: EnumALCA_inform_reason_no
     1: EnumALCA_inform_reason_low_cipv
     2: EnumALCA_inform_reason_accident_ahead */
  EnumALCA_inform_reason inform_reason;

  /* Inform side:
     0: FORWARD
     1: LEFT
     2: RIGHT */
  EnumDCSN_driving_direction inform_side;

  /* The laeral v for LCCS target line move. */
  real32_T lateral_v;
}
ALCA_DataBus;

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

#ifndef DEFINED_TYPEDEF_FOR_ACCS_CIPVChangedType_
#define DEFINED_TYPEDEF_FOR_ACCS_CIPVChangedType_

typedef uint8_T ACCS_CIPVChangedType;

#define Normal                         ((ACCS_CIPVChangedType)0) /* Default value */
#define SelfChangeLane                 ((ACCS_CIPVChangedType)1)
#define CutIn                          ((ACCS_CIPVChangedType)2)
#define CutOut                         ((ACCS_CIPVChangedType)3)
#define Approaching                    ((ACCS_CIPVChangedType)4)
#define Away                           ((ACCS_CIPVChangedType)5)
#define Unknown                        ((ACCS_CIPVChangedType)6)
#define CloseDisappearing              ((ACCS_CIPVChangedType)7)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumACCS_StatusTransferType_
#define DEFINED_TYPEDEF_FOR_EnumACCS_StatusTransferType_

typedef uint8_T EnumACCS_StatusTransferType;

#define NoTransfer                     ((EnumACCS_StatusTransferType)0) /* Default value */
#define FromOnToStop                   ((EnumACCS_StatusTransferType)1)
#define FromOnToSpeedCtrl              ((EnumACCS_StatusTransferType)2)
#define FromSpeedToLowSpeed            ((EnumACCS_StatusTransferType)3)
#define FromSpeedToFollowing           ((EnumACCS_StatusTransferType)4)
#define FromLowSpeedToFollowing        ((EnumACCS_StatusTransferType)5)
#define FromLowSpeedToTempStop         ((EnumACCS_StatusTransferType)6)
#define FromLowSpeedToSpeed            ((EnumACCS_StatusTransferType)7)
#define FromTempStopToStop             ((EnumACCS_StatusTransferType)8)
#define FromTempStopToLaunch           ((EnumACCS_StatusTransferType)9)
#define FromStopToLaunch               ((EnumACCS_StatusTransferType)10)
#define FromLaunchToFollowingCtrl      ((EnumACCS_StatusTransferType)11)
#define FromLaunchToLowSpeed           ((EnumACCS_StatusTransferType)12)
#define FromLaunchToSpeedCtrl          ((EnumACCS_StatusTransferType)13)
#define FromLaunchToTempStop           ((EnumACCS_StatusTransferType)14)
#define FromFollowingToSpeedCtrl       ((EnumACCS_StatusTransferType)15)
#define FromFollowingToLowSpeed        ((EnumACCS_StatusTransferType)16)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumACCS_FaultState_
#define DEFINED_TYPEDEF_FOR_EnumACCS_FaultState_

typedef uint8_T EnumACCS_FaultState;   /* 0:NoEnterFault
                                          1:FromStatusOnToFault
                                          2:FromSpeedCtrlToFault
                                          3:FromFollowingCtrlToFault
                                          4:FromLowSpeedToFault
                                          5:FromTempStopToFault
                                          6:FromStopToFault
                                          7:FromLaunchToFault
                                          8:FromStandbyToFault */

#define NoEnterFault                   ((EnumACCS_FaultState)0)  /* Default value */
#define FromStatusOnToFault            ((EnumACCS_FaultState)1)
#define FromSpeedCtrlToFault           ((EnumACCS_FaultState)2)
#define FromFollowingCtrlToFault       ((EnumACCS_FaultState)3)
#define FromLowSpeedToFault            ((EnumACCS_FaultState)4)
#define FromTempStopToFault            ((EnumACCS_FaultState)5)
#define FromStopToFault                ((EnumACCS_FaultState)6)
#define FromLaunchToFault              ((EnumACCS_FaultState)7)
#define FromStandbyToFault             ((EnumACCS_FaultState)8)
#endif
#endif                                 /* RTW_HEADER_ACCS_subsystem_integrated_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
