/*
 * File: COMM_subsystem_integrated.c
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

#include "COMM_subsystem_integrated.h"
#include "COMM_subsystem_integrated_private.h"

const COMM_Bus_VEH_Config COMM_subsystem_integrated_rtZCOMM_Bus_VEH_Config =
{
  0.0F,                                /* VfCOMM_VEH_MinTurnRadius */
  0.0F,                                /* VfCOMM_VEH_AngOrigin2FrontWheel */
  0.0F,                                /* VfCOMM_VEH_YawInertia_Z */
  0.0F,                                /* VfCOMM_VEH_DisOrigin2FrontWheel */
  0.0F,                                /* VfCOMM_VEH_DisOrigin2End */
  0.0F,                                /* VfCOMM_VEH_DisOrigin2RearAxle */
  0.0F,                                /* VfCOMM_VEH_DisOrigin2Head */
  0.0F,                                /* VfCOMM_VEH_Width */
  0.0F,                                /* VfACCS_VEH_WheelDiameter */
  0.0F,                                /* VfCOMM_VEH_Length */
  0.0F,                                /* VfCOMM_VEH_StiffnessRear */
  0.0F,                                /* VfCOMM_VEH_StiffnessFront */
  0.0F,                                /* VfCOMM_VEH_DisLeft2Right */
  0.0F,                                /* VfCOMM_VEH_DisCentorid2Front */
  0.0F,                                /* VfCOMM_VEH_Mass */
  0.0F                                 /* VfCOMM_VEH_DisFront2Rear */
} ;                                    /* COMM_Bus_VEH_Config ground */

const COMM_CANR_Databus COMM_subsystem_integrated_rtZCOMM_CANR_Databus =
{
  {
    false,                             /* VCU_AutodriveMainSwitch */
    0U,                                /* VCU_AutoToManualTips */
    false                              /* VCU_AutodriveActiveStatus */
  },                                   /* COMM_RX_AutodriveMode */

  {
    false,                             /* BCM_CruiseSwValid */
    false,                             /* BCM_CruiseSwCancel */
    false,                             /* BCM_CruiseSwResume */
    false,                             /* BCM_CruiseSwSet */
    false,                             /* BCM_CruiseSwTimeGapPlus */
    false,                             /* BCM_CruiseSwTimeGapMinus */
    false,                             /* BCM_CruiseSwMain */
    false,                             /* BCM_CruiseSwLimitMain */
    0U,                                /* BCM_DriveMode */
    false,                             /* BCM_DriverSeatBelt */
    false,                             /* BCM_DriverSeatBeltValid */
    0U,                                /* BCM_CruiseControlStatus */
    false,                             /* BCM_TurningLightEcho */
    false,                             /* BCM_LowBeamSwitch */
    false,                             /* BCM_HighBeamSwitch */
    false,                             /* BCM_BrakeLightStatus */
    false,                             /* BCM_LeftTurningLightState */
    false,                             /* BCM_RightTurningLightState */
    false,                             /* BCM_IgnitionKeyState */
    false,                             /* BCM_DriverDoorStatus */
    false,                             /* BCM_PassengerDoorStatus */
    false,                             /* BCM_RearRightDoorStatus */
    false,                             /* BCM_RearLeftDoorStatus */
    false,                             /* BCM_FrontHoodStatus */
    false,                             /* BCM_BackTrunkStatus */
    false,                             /* BCM_WiperSwitch */
    false                              /* BCM_ControlResponse */
  },                                   /* COMM_RX_BCM */

  {
    false,                             /* ESP_TCSActive */
    false,                             /* ESP_ABSActive */
    0U,                                /* ESP_BrakeAirTankPressure */
    false,                             /* VCU_BrakePedalValid */
    false,                             /* ESP_BrakeControlResponse */
    0.0F,                              /* VCU_TargetBrakePedalEcho */
    0.0F,                              /* VCU_ActualBrakePedalPosition */
    false,                             /* VCU_ActualBrakePedalSwitch */
    0.0F,                              /* ESP_MasterCylinderPress */
    false,                             /* ESP_MasterCylinderPressValid */
    0U                                 /* ESP_SystemFaultStatus */
  },                                   /* COMM_RX_Brake */

  {
    false,                             /* EPB_AutoholdStatus */
    0U,                                /* EPB_ActualControlStatus */
    0U,                                /* EPB_SystemFaultStatus */
    false,                             /* EPB_ParkingControlResponse */
    false                              /* EPB_SwitchStatus */
  },                                   /* COMM_RX_Parking */

  {
    0U,                                /* EMS_StartStopStatus */
    false,                             /* EMS_EngineSpeedValid */
    0.0F,                              /* VCU_VirtualAccelPedalPosition */
    false,                             /* VCU_VirtualAccelPedalValid */
    false,                             /* VCU_AccelPedalOverride */
    0U,                                /* EMS_EngineState */
    0.0F,                              /* EMS_EngineSpeed */
    false,                             /* EMS_CoolantLevelLow */
    false,                             /* PCU_PowerControlResponse */
    0.0F,                              /* PCU_DriverDemandTorque */
    0.0F,                              /* PCU_ActualEngineTorque */
    0U,                                /* EMS_EngineOilPressure */
    0,                                 /* EMS_EngineCoolantTemperature */
    0.0F,                              /* EMS_CatalystTankLevel */
    false,                             /* VCU_AccelPedalValid */
    0.0F,                              /* VCU_TargetAccelPedalPostionEcho */
    0.0F,                              /* VCU_ActualAccelPedalPosition */
    0U,                                /* PCU_PowertrainFaultLevel */
    0.0F,                              /* PCU_BatterySOC */
    0.0F,                              /* PCU_MotorSpeed */
    0.0F,                              /* PCU_MotorActualTorque */
    0.0F                               /* PCU_EngineTorqueLoss */
  },                                   /* COMM_RX_Power */

  {
    false,                             /* EPS_SteeringWheelTorqueValid */
    false,                             /* EPS_SteeringControlResponse_LDW */
    false,                             /* EPS_SteeringControlResponse_LCC */
    0U,                                /* EPS_SteeringModeEcho */
    false,                             /* EPS_SteeringControlResponse */
    0.0F,                              /* EPS_TargetSteeringAngleEcho */
    0.0F,                              /* EPS_ActualSteeringAngle */
    0.0F,                              /* EPS_SteeringAngleRate */
    0U,                                /* EPS_FaultLevel */
    0.0F,                              /* EPS_SteeringWheelTorque */
    false,                             /* EPS_HandsOffWheelDetected */
    false                              /* EPS_HandsOnWheelDetected */
  },                                   /* COMM_RX_Steering */

  {
    0U,                                /* TCU_TargetGearPositionEcho */
    0U,                                /* TCU_ShiftLevelPosition */
    0U,                                /* TCU_ActualGearPosition */
    0.0F                               /* TCU_ActualGearRatio */
  },                                   /* COMM_RX_Transmission */

  {
    false,                             /* VDC_YawRateValid */
    false,                             /* VDC_LongAccelerationValid */
    false,                             /* VDC_LateralAccelerationValid */
    0.0F,                              /* VDC_YawRate */
    0.0F,                              /* VDC_VehicleSpeed */
    0.0F,                              /* VDC_LongAcceleration */
    0.0F,                              /* VDC_LateralAcceleration */
    0.0F,                              /* VDC_WheelSpeed_RR1 */
    0.0F,                              /* VDC_WheelSpeed_RR2 */
    0.0F,                              /* VDC_WheelSpeed_RL1 */
    0.0F,                              /* VDC_WheelSpeed_RL2 */
    0.0F,                              /* VDC_WheelSpeed_FR */
    0.0F,                              /* VDC_WheelSpeed_FL */
    false,                             /* VDC_WheelSpeed_RR1Valid */
    false,                             /* VDC_WheelSpeed_RR2Valid */
    false,                             /* VDC_WheelSpeed_RL1Valid */
    false,                             /* VDC_WheelSpeed_RL2Valid */
    false,                             /* VDC_WheelSpeed_FRValid */
    false,                             /* VDC_WheelSpeed_FLValid */
    0U,                                /* VDC_WheelEncoderCounter_RL */
    0U                                 /* VDC_WheelEncoderCounter_RR */
  }                                    /* COMM_RX_VehicleDynamics */
} ;                                    /* COMM_CANR_Databus ground */

const COMM_CANT_Databus COMM_subsystem_integrated_rtZCOMM_CANT_Databus =
{
  {
    false                              /* ADCU_AutodriveEnable */
  },                                   /* COMM_TX_AutodriveMode */

  {
    false,                             /* ADCU_BCMControlEnable */
    false,                             /* ADCU_BrakeLightRequest */
    false,                             /* ADCU_LowBeamRequest */
    false,                             /* ADCU_HighBeamRequest */
    false,                             /* ADCU_LeftTurningLightRequest */
    false,                             /* ADCU_RightTurningLightRequest */
    false,                             /* ADCU_FrontFogLightRequest */
    false,                             /* ADCU_BackFogLightRequest */
    false,                             /* ADCU_PositionLightRequest */
    false,                             /* ADCU_EmergencyLightRequest */
    false,                             /* ADCU_HornRequest */
    0U,                                /* ADCU_WiperControlRequest */
    false                              /* ADCU_WashingControlRequest */
  },                                   /* COMM_TX_BCM */

  {
    false,                             /* ADCU_BrakeEnable */
    0.0F,                              /* ADCU_BrakePressureValue */
    0.0F,                              /* ADCU_BrakeDecelValue */
    false                              /* ADCU_BrakePrechargeRequest */
  },                                   /* COMM_TX_Brake */

  {
    0.0F,                              /* ADCU_TargetVehicleSpeed */
    false,                             /* ADCU_SpeedUpIndicator */
    false,                             /* ADCU_SpeedDownIndicator */
    false,                             /* ADCU_OverSpeedWarning */
    0U                                 /* ADCU_FCW_Warning */
  },                                   /* COMM_TX_HMI */

  {
    false,                             /* ADCU_ParkingPressureRequest */
    0U,                                /* ADCU_ParkingControlValue */
    false                              /* ADCU_ParkingControlEnable */
  },                                   /* COMM_TX_Parking */

  {
    false,                             /* ADCU_PowerEnable */
    0.0F,                              /* ADCU_PowerTorqueValue */
    0.0F,                              /* ADCU_PowerAccelValue */
    false                              /* ADCU_LaunchRequest */
  },                                   /* COMM_TX_Power */

  {
    false,                             /* ADCU_SteeringTorqueEnable */
    0.0F,                              /* ADCU_SteeringTorqueValue */
    false,                             /* ADCU_SteeringAngleEnable */
    0.0F,                              /* ADCU_SteeringAngleValue */
    0.0F                               /* ADCU_SteeringAngleSpeed */
  },                                   /* COMM_TX_Steering */

  {
    false,                             /* ADCU_TargetGearEnable */
    0U                                 /* ADCU_TargetGearValue */
  }                                    /* COMM_TX_Transmission */
} ;                                    /* COMM_CANT_Databus ground */

const COMM_CAN_Data_Transmit COMM_subsystem_integrated_rtZCOMM_CAN_Data_Transmit
  =
{
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }
    /* Data */
  },                                   /* Config_1_Transmit_CAN_2_ID__193 */

  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }
    /* Data */
  },                                   /* Config_2_Transmit_CAN_2_ID__193 */

  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }
    /* Data */
  },                                   /* Config_3_Transmit_CAN_2_ID__550 */

  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }
    /* Data */
  },                                   /* Config_3_Transmit_CAN_0_ID__581 */

  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }
    /* Data */
  },                                   /* Config_6_Transmit_CAN_4_ID_201591594 */

  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }
    /* Data */
  },                                   /* Config_6_Transmit_CAN_4_ID_201439175 */

  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }
    /* Data */
  },                                   /* Config_6_Transmit_CAN_4_ID_201504711 */

  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }
    /* Data */
  }                                    /* Config_7_Transmit_CAN_2_ID_1586 */
} ;                                    /* COMM_CAN_Data_Transmit ground */

const COMM_ADCU_TX_Data COMM_subsystem_integrated_rtZCOMM_ADCU_TX_Data =
{
  {
    0U,                                /* ADV_Status */
    0.0F,                              /* Target_Speed */
    0U,                                /* Brake_Switch */
    0.0F                               /* XBR_External_Acc_Demand */
  },                                   /* T01 */

  {
    0                                  /* Transmission_Requested_Gear */
  },                                   /* T02 */

  {
    0U,                                /* Override_Control_Mode */
    0U,                                /* Override_Control_Mode_Priority */
    0,                                 /* Requested_Torque_Torque_Limit */
    0U,                                /* Message_Counter */
    0U                                 /* Message_Checksum */
  },                                   /* T03 */

  {
    0.0F,                              /* XBR1_External_Accleration_Demand */
    0U,                                /* XBR1_EBI_Mode */
    0U,                                /* XBR1_Priority */
    0U,                                /* XBR1_Control_Mode */
    0U,                                /* XBR1_Message_Counter */
    0U                                 /* XBR1_Message_Checksum */
  },                                   /* T05 */

  {
    0U,                                /* ReAX_Desired_operation_mode */
    0.0F,                              /* ReAX_Command_from_ext_controller */
    0U,                                /* ReAX_Message_counter */
    0U                                 /* ReAX_Message_Checksum */
  },                                   /* T08 */

  {
    0U,                                /* EPB_Control_mode */
    0U,                                /* EPB_Control_Command */
    0U,                                /* EPB_Message_Counter */
    0U                                 /* EPB_Message_Checksum */
  },                                   /* T13 */

  {
    0U,                                /* Running_Light_Command */
    0U,                                /* Low_Beam_Head_Light_Command */
    0U,                                /* High_Beam_Light_Command */
    0U,                                /* Tractor_Front_Fog_Lights_Command */
    0U,                                /* Right_Turn_Signal_Lights_Command */
    0U,                                /* Left_Turn_Signal_Lights_Command */
    0U,                                /* Alarm_Horn_Command */
    0U,                                /* Implement_Marker_Light_Command */
    0U                                 /* Rear_Fog_Light_Command */
  },                                   /* T15 */

  {
    0U,                                /* Wiper_switch_control_command */
    0U,                                /* Washing_switch_control_command */
    0U,                                /* BCM_control_by_ADV_state */
    0U,                                /* Rear_brake_switch_control */
    0U                                 /* Horn_control_command */
  }                                    /* T16 */
} ;                                    /* COMM_ADCU_TX_Data ground */

/* Exported block signals */
COMM_CAN_Data_Receive VsCOMM_CAN_Data_Receive;/* '<Root>/VsCOMM_CAN_Data_Receive' */
COMM_VEH_RX_Data VsCOMM_FAW_VEH_RX_Data;/* '<Root>/VsCOMM_FAW_VEH_RX_Data' */
boolean_T VbHWIO_DriverModeComd;       /* '<Root>/VbHWIO_DriverModeComd'
                                        * Drive Mode Command from HWIO.
                                        */
boolean_T VbHWIO_LeftTurningLightState;/* '<Root>/VbHWIO_LeftTurningLightState'
                                        * Left Turning Light State from HWIO.
                                        */
boolean_T VbHWIO_RightTurningLightState;/* '<Root>/VbHWIO_RightTurningLightState'
                                         * Right Turning Light State from HWIO.
                                         */
boolean_T VbHWIO_ACC_MainSwitch;       /* '<Root>/VbHWIO_ACC_MainSwitch'
                                        * ACC Main Switch from HWIO.
                                        */
boolean_T VbHWIO_ACC_ResumeSwitch;     /* '<Root>/VbHWIO_ACC_ResumeSwitch'
                                        * ACC Resume Switch from HWIO.
                                        */
boolean_T VbHWIO_ACC_SetSwitch;        /* '<Root>/VbHWIO_ACC_SetSwitch'
                                        * ACC Set Switch from HWIO.
                                        */
boolean_T VbHWIO_ACC_TimeGapPlus;      /* '<Root>/VbHWIO_ACC_TimeGapPlus'
                                        * ACC Time Gap Plus from HWIO.
                                        */
boolean_T VbHWIO_ACC_TimeGapMinus;     /* '<Root>/VbHWIO_ACC_TimeGapMinus'
                                        * ACC Time Gap Minus from HWIO.
                                        */
boolean_T VbHWIO_ACC_CancelSwitch;     /* '<Root>/VbHWIO_ACC_CancelSwitch'
                                        * ACC Cancel Switch from HWIO.
                                        */
COMM_CANR_Databus VsCOMM_CANR_Databus; /* '<S1>/Merge2' */
COMM_CAN_Data_Transmit VsCOMM_CAN_Data_Transmit;/* '<S2>/Bus Creator1' */
COMM_CANT_Databus VsCOMM_CANT_Databus; /* '<S2>/Switch13' */
COMM_ADCU_TX_Data VsCOMM_FAW_ADCU_TX_Data;/* '<S46>/buscreator' */
COMM_Bus_VEH_Config VsCOMM_VEH_Config; /* '<S1>/Switch' */
real32_T VfCOMM_ADCU_BrakeDecelValue;  /* '<S2>/Signal Conversion18' */
real32_T VfCOMM_ADCU_PowerAccelValue;  /* '<S2>/Signal Conversion19' */
real32_T VfCOMM_ADCU_SteeringAngleValue;/* '<S2>/Signal Conversion20' */
real32_T VfCOMM_ADCU_TargetVehicleSpeed;/* '<S2>/Signal Conversion29' */
real32_T VfCOMM_ADCU_PowerTorqueValue; /* '<S2>/Signal Conversion4' */
real32_T VfCOMM_ADCU_BrakePressureValue;/* '<S2>/Signal Conversion34' */
real32_T VfCOMM_max_gas_pedal_EPB;     /* '<S41>/Merge1' */
real32_T VfCOMM_TCU_ActualGearRatio;   /* '<S1>/Signal Conversion136' */
real32_T VfCOMM_VDC_YawRate;           /* '<S1>/Signal Conversion141' */
real32_T VfCOMM_VDC_VehicleSpeed;      /* '<S1>/Signal Conversion142' */
real32_T VfCOMM_VDC_WheelSpeed_RR1;    /* '<S1>/Signal Conversion143' */
real32_T VfCOMM_VDC_LongAcceleration;  /* '<S1>/Signal Conversion144' */
real32_T VfCOMM_VDC_LateralAcceleration;/* '<S1>/Signal Conversion145' */
real32_T VfCOMM_VDC_WheelSpeed_RR2;    /* '<S1>/Signal Conversion146' */
real32_T VfCOMM_VDC_WheelSpeed_RL1;    /* '<S1>/Signal Conversion147' */
real32_T VfCOMM_VDC_WheelSpeed_RL2;    /* '<S1>/Signal Conversion148' */
real32_T VfCOMM_EPS_TargetSteeringAngleEcho;/* '<S1>/Signal Conversion153' */
real32_T VfCOMM_EPS_ActualSteeringAngle;/* '<S1>/Signal Conversion154' */
real32_T VfCOMM_EPS_SteeringAngleRate; /* '<S1>/Signal Conversion155' */
real32_T VfCOMM_VDC_WheelSpeed_FR;     /* '<S1>/Signal Conversion156' */
real32_T VfCOMM_VDC_WheelSpeed_FL;     /* '<S1>/Signal Conversion157' */
real32_T VfCOMM_VCU_VirtualAccelPedalPosition;/* '<S1>/Signal Conversion205' */
real32_T VfCOMM_EMS_EngineSpeed;       /* '<S1>/Signal Conversion210' */
real32_T VfCOMM_PCU_DriverDemandTorque;/* '<S1>/Signal Conversion211' */
real32_T VfCOMM_PCU_ActualEngineTorque;/* '<S1>/Signal Conversion214' */
real32_T VfCOMM_EMS_CatalystTankLevel; /* '<S1>/Signal Conversion224' */
real32_T VfCOMM_VCU_ActualAccelPedalPosition;/* '<S1>/Signal Conversion225' */
real32_T VfCOMM_VCU_TargetAccelPedalPostionEcho;/* '<S1>/Signal Conversion227' */
real32_T VfCOMM_PCU_BatterySOC;        /* '<S1>/Signal Conversion229' */
real32_T VfCOMM_PCU_MotorSpeed;        /* '<S1>/Signal Conversion230' */
real32_T VfCOMM_PCU_MotorActualTorque; /* '<S1>/Signal Conversion231' */
real32_T VfCOMM_PCU_EngineTorqueLoss;  /* '<S1>/Signal Conversion232' */
real32_T VfCOMM_EPS_SteeringWheelTorque;/* '<S1>/Signal Conversion234' */
real32_T VfCOMM_VCU_TargetBrakePedalEcho;/* '<S1>/Signal Conversion82' */
real32_T VfCOMM_VCU_ActualBrakePedalPosition;/* '<S1>/Signal Conversion83' */
real32_T VfCOMM_ESP_MasterCylinderPress;/* '<S1>/Signal Conversion85' */
uint32_T VfCOMM_VDC_WheelEncoderCounter_RL;/* '<S1>/Signal Conversion164' */
uint32_T VfCOMM_VDC_WheelEncoderCounter_RR;/* '<S1>/Signal Conversion165' */
int16_T VfCOMM_EMS_EngineCoolantTemperature;/* '<S1>/Signal Conversion216' */
uint16_T VfCOMM_EMS_EngineOilPressure; /* '<S1>/Signal Conversion215' */
uint16_T VeCOMM_VCU_AutoToManualTips;  /* '<S1>/Signal Conversion30'
                                        * "Reason for not being able to enter automatic driving status (16 bits represent different conditions (starting from 1):

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

                                          Bit 12: intelligent driving function shielding. "
                                        */
uint16_T VfCOMM_ESP_BrakeAirTankPressure;/* '<S1>/Signal Conversion70' */
uint8_T VeCOMM_ADCU_TargetGearValue;   /* '<S2>/Signal Conversion6'
                                        * Target Gear (0:Neutral;1-12:ForwardGears;13:Reverse;14Park;15:Invalid)
                                        */
uint8_T VeCOMM_ADCU_ParkingControlValue;/* '<S2>/Signal Conversion26'
                                         * Park control status (0: release; 1: clamp)
                                         */
uint8_T VeCOMM_TCU_TargetGearPositionEcho;/* '<S1>/Signal Conversion133'
                                           * Target gear received by TCU from ADCU (0: neutral; 1-12: forwardgears; 13: reverse; 14park; 15: invalid)
                                           */
uint8_T VeCOMM_TCU_ShiftLevelPosition; /* '<S1>/Signal Conversion134'
                                        * ShiftLevelPosition��PRNDL����0��Park;1:Reverse;2:Neutral;3:Drive��
                                        */
uint8_T VeCOMM_TCU_ActualGearPosition; /* '<S1>/Signal Conversion135'
                                        * Actual gear(0:Neutral;1-12:ForwardGears;13:Reverse;14Park;15:Invalid)

                                        */
uint8_T VeCOMM_EPS_SteeringModeEcho;   /* '<S1>/Signal Conversion151'
                                        * Target corner status received by EPS from ADCU (0: driver; 1: steeringangle; 2: steeringwheeltorque)
                                        */
uint8_T VeCOMM_EMS_StartStopStatus;    /* '<S1>/Signal Conversion203'
                                        *
                                          0-Reset Start/Stop not active(any engine condition possible)

                                        */
uint8_T VeCOMM_EMS_EngineState;        /* '<S1>/Signal Conversion209'
                                        * Engine status (0: keyoff; 1: ACC; 2: Keyon; 3: crank; 4: run)
                                        */
uint8_T VeCOMM_PCU_PowertrainFaultLevel;/* '<S1>/Signal Conversion228'
                                         * Power system fault level (0: nofault)
                                         */
uint8_T VeCOMM_EPS_FaultLevel;         /* '<S1>/Signal Conversion233'
                                        * Steering performance fault level (0: nofault)
                                        */
uint8_T VeCOMM_BCM_CruiseControlStatus;/* '<S1>/Signal Conversion33'
                                        * Cruise control status
                                        */
uint8_T VeCOMM_BCM_DriveMode;          /* '<S1>/Signal Conversion57'
                                        *
                                          BCM_DM_TargetModeReq��0��Normal��1��Sport��2��Eco��other��Reserve��

                                        */
uint8_T VeCOMM_ESP_SystemFaultStatus;  /* '<S1>/Signal Conversion60'
                                        * ESP system fault status (0: normal)
                                        */
uint8_T VeCOMM_EPB_SystemFaultStatus;  /* '<S1>/Signal Conversion62'
                                        * ESP system fault status (0: normal)
                                        */
uint8_T VeCOMM_EPB_ActualControlStatus;/* '<S1>/Signal Conversion63'
                                        * EPB actual control status (0: release)
                                        */
boolean_T VbCOMM_ADCU_EmergencyLightRequest;/* '<S2>/Signal Conversion9' */
boolean_T VbCOMM_ADCU_RightTurningLightRequest;/* '<S2>/Signal Conversion10' */
boolean_T VbCOMM_ADCU_PositionLightRequest;/* '<S2>/Signal Conversion11' */
boolean_T VbCOMM_ADCU_LeftTurningLightRequest;/* '<S2>/Signal Conversion12' */
boolean_T VbCOMM_ADCU_HornRequest;     /* '<S2>/Signal Conversion7' */
boolean_T VbCOMM_ADCU_HighBeamRequest; /* '<S2>/Signal Conversion13' */
boolean_T VbCOMM_ADCU_FrontFogLightRequest;/* '<S2>/Signal Conversion8' */
boolean_T VbCOMM_ADCU_LowBeamRequest;  /* '<S2>/Signal Conversion14' */
boolean_T VbCOMM_ADCU_BrakeLightRequest;/* '<S2>/Signal Conversion5' */
boolean_T VbCOMM_ADCU_BackFogLghtRequest;/* '<S2>/Signal Conversion15' */
boolean_T VbCOMM_ADCU_AutodriveEnable; /* '<S2>/Signal Conversion16' */
boolean_T VbCOMM_ADCU_BCMControlEnable;/* '<S2>/Signal Conversion17' */
boolean_T VbCOMM_ADCU_TargetGearEnable;/* '<S2>/Signal Conversion21' */
boolean_T VbCOMM_ADCU_SteeringAngleEnable;/* '<S2>/Signal Conversion22' */
boolean_T VbCOMM_ADCU_ParkingPressureRequest;/* '<S2>/Signal Conversion23' */
boolean_T VbCOMM_ADCU_LaunchRequest;   /* '<S2>/Signal Conversion24' */
boolean_T VbCOMM_ADCU_ParkingControlEnable;/* '<S2>/Signal Conversion25' */
boolean_T VbCOMM_ADCU_PowerEnable;     /* '<S2>/Signal Conversion27' */
boolean_T VbCOMM_ADCU_BrakeEnable;     /* '<S2>/Signal Conversion28' */
boolean_T VbCOMM_ADCU_SpeedDownIndicator;/* '<S2>/Signal Conversion30' */
boolean_T VbCOMM_ADCU_SpeedUpIndicator;/* '<S2>/Signal Conversion31' */
boolean_T VbCOMM_ADCU_OverSpeedWarning;/* '<S2>/Signal Conversion33' */
boolean_T VbCOMM_VDC_YawRateValid;     /* '<S1>/Signal Conversion137' */
boolean_T VbCOMM_VDC_LongAccelerationValid;/* '<S1>/Signal Conversion138' */
boolean_T VbCOMM_EPS_SteeringWheelTorqueValid;/* '<S1>/Signal Conversion139' */
boolean_T VbCOMM_VDC_LateralAccelerationValid;/* '<S1>/Signal Conversion140' */
boolean_T VbCOMM_EPS_SteeringControlResponse_LDW;/* '<S1>/Signal Conversion149' */
boolean_T VbCOMM_EPS_SteeringControlResponse_LCC;/* '<S1>/Signal Conversion150' */
boolean_T VbCOMM_VDC_WheelSpeed_RR1Valid;/* '<S1>/Signal Conversion158' */
boolean_T VbCOMM_VDC_WheelSpeed_RR2Valid;/* '<S1>/Signal Conversion159' */
boolean_T VbCOMM_VDC_WheelSpeed_RL1Valid;/* '<S1>/Signal Conversion160' */
boolean_T VbCOMM_VDC_WheelSpeed_FLValid;/* '<S1>/Signal Conversion161' */
boolean_T VbCOMM_VDC_WheelSpeed_RL2Valid;/* '<S1>/Signal Conversion162' */
boolean_T VbCOMM_VDC_WheelSpeed_FRValid;/* '<S1>/Signal Conversion163' */
boolean_T VbCOMM_EMS_EngineSpeedValid; /* '<S1>/Signal Conversion204' */
boolean_T VbCOMM_VCU_VirtualAccelPedalValid;/* '<S1>/Signal Conversion206' */
boolean_T VbCOMM_VCU_AccelPedalOverride;/* '<S1>/Signal Conversion208' */
boolean_T VbCOMM_EMS_CoolantLevelLow;  /* '<S1>/Signal Conversion212' */
boolean_T VbCOMM_PCU_PowerControlResponse;/* '<S1>/Signal Conversion213' */
boolean_T VbCOMM_VCU_AccelPedalValid;  /* '<S1>/Signal Conversion226' */
boolean_T VbCOMM_EPS_HandsOnWheelDetected;/* '<S1>/Signal Conversion235' */
boolean_T VbCOMM_EPS_HandsOffWheelDetected;/* '<S1>/Signal Conversion236' */
boolean_T VbCOMM_VCU_AutodriveMainSwitch;/* '<S1>/Signal Conversion29' */
boolean_T VbCOMM_BCM_CruiseSwLimitMain;/* '<S1>/Signal Conversion31' */
boolean_T VbCOMM_BCM_DriverSeatBelt;   /* '<S1>/Signal Conversion32' */
boolean_T VbCOMM_BCM_DriverSeatBeltValid;/* '<S1>/Signal Conversion34' */
boolean_T VbCOMM_BCM_TurningLightEcho; /* '<S1>/Signal Conversion35' */
boolean_T VbCOMM_BCM_LowBeamSwitch;    /* '<S1>/Signal Conversion36' */
boolean_T VbCOMM_BCM_HighBeamSwitch;   /* '<S1>/Signal Conversion37' */
boolean_T VbCOMM_BCM_BrakeLightStatus; /* '<S1>/Signal Conversion38' */
boolean_T VbCOMM_BCM_LeftTurningLightState;/* '<S1>/Signal Conversion39' */
boolean_T VbCOMM_BCM_RightTurningLightState;/* '<S1>/Signal Conversion40' */
boolean_T VbCOMM_VCU_AutodriveActiveStatus;/* '<S1>/Signal Conversion41' */
boolean_T VbCOMM_BCM_IgnitionKeyState; /* '<S1>/Signal Conversion42' */
boolean_T VbCOMM_BCM_DriverDoorStatus; /* '<S1>/Signal Conversion43' */
boolean_T VbCOMM_BCM_PassengerDoorStatus;/* '<S1>/Signal Conversion44' */
boolean_T VbCOMM_BCM_FrontHoodStatus;  /* '<S1>/Signal Conversion45' */
boolean_T VbCOMM_BCM_RearRightDoorStatus;/* '<S1>/Signal Conversion46' */
boolean_T VbCOMM_BCM_RearLeftDoorStatus;/* '<S1>/Signal Conversion47' */
boolean_T VbCOMM_BCM_BackTrunkStatus;  /* '<S1>/Signal Conversion48' */
boolean_T VbCOMM_BCM_WiperSwitch;      /* '<S1>/Signal Conversion49' */
boolean_T VbCOMM_BCM_ControlResponse;  /* '<S1>/Signal Conversion50' */
boolean_T VbCOMM_BCM_CruiseSwValid;    /* '<S1>/Signal Conversion51' */
boolean_T VbCOMM_BCM_CruiseSwResume;   /* '<S1>/Signal Conversion52' */
boolean_T VbCOMM_BCM_CruiseSwSet;      /* '<S1>/Signal Conversion53' */
boolean_T VbCOMM_BCM_CruiseSwTimeGapPlus;/* '<S1>/Signal Conversion54' */
boolean_T VbCOMM_BCM_CruiseSwTimeGapMinus;/* '<S1>/Signal Conversion55' */
boolean_T VbCOMM_BCM_CruiseSwMain;     /* '<S1>/Signal Conversion56' */
boolean_T VbCOMM_ESP_TCSActive;        /* '<S1>/Signal Conversion58' */
boolean_T VbCOMM_ESP_ABSActive;        /* '<S1>/Signal Conversion59' */
boolean_T VbCOMM_EPB_AutoholdStatus;   /* '<S1>/Signal Conversion61' */
boolean_T VbCOMM_EPB_ParkingControlResponse;/* '<S1>/Signal Conversion64' */
boolean_T VbCOMM_EPB_SwitchStatus;     /* '<S1>/Signal Conversion65' */
boolean_T VbCOMM_VCU_BrakePedalValid;  /* '<S1>/Signal Conversion80' */
boolean_T VbCOMM_ESP_BrakeControlResponse;/* '<S1>/Signal Conversion81' */
boolean_T VbCOMM_VCU_ActualBrakePedalSwitch;/* '<S1>/Signal Conversion84' */
boolean_T VbCOMM_ESP_MasterCylinderPressValid;/* '<S1>/Signal Conversion86' */

#pragma section ".cal"
/* Exported block parameters */
real32_T KcCOMM_BrakePedalMax = 40.0F; /* Variable: KcCOMM_BrakePedalMax
                                        * Referenced by: '<S41>/Constant9'
                                        */
real32_T KcCOMM_BrakePedalMin = 0.0F;  /* Variable: KcCOMM_BrakePedalMin
                                        * Referenced by: '<S41>/Constant6'
                                        */
real32_T KcCOMM_FirstGearRatio = 12.189F;/* Variable: KcCOMM_FirstGearRatio
                                          * Referenced by: '<S40>/Constant6'
                                          * Gear ratio in 1st gear.
                                          */
real32_T KcCOMM_GasPedalMax = 100.0F;  /* Variable: KcCOMM_GasPedalMax
                                        * Referenced by:
                                        *   '<S41>/Constant4'
                                        *   '<S60>/Constant4'
                                        */
real32_T KcCOMM_GasPedalMaxEPB = 35.0F;/* Variable: KcCOMM_GasPedalMaxEPB
                                        * Referenced by: '<S61>/Constant4'
                                        */
real32_T KcCOMM_GasPedalMin = 25.0F;   /* Variable: KcCOMM_GasPedalMin
                                        * Referenced by: '<S41>/Constant2'
                                        */
real32_T KcCOMM_GasPedalMinEPB = 15.0F;/* Variable: KcCOMM_GasPedalMinEPB
                                        * Referenced by: '<S59>/Constant4'
                                        */
real32_T KcCOMM_GasPedalRampEPB = 5.0F;/* Variable: KcCOMM_GasPedalRampEPB
                                        * Referenced by:
                                        *   '<S60>/Constant1'
                                        *   '<S61>/Constant1'
                                        */
real32_T KcCOMM_Test_Cmd_AccPelPosAct = 0.0F;/* Variable: KcCOMM_Test_Cmd_AccPelPosAct
                                              * Referenced by: '<S42>/Constant98'
                                              */
real32_T KcCOMM_Test_Cmd_BrkPelPosAct = 0.0F;/* Variable: KcCOMM_Test_Cmd_BrkPelPosAct
                                              * Referenced by: '<S42>/Constant95'
                                              */
real32_T KcCOMM_Test_Cmd_StrAngle = 0.0F;/* Variable: KcCOMM_Test_Cmd_StrAngle
                                          * Referenced by:
                                          *   '<S2>/Constant32'
                                          *   '<S42>/Constant104'
                                          */
real32_T KcCOMM_Test_Cmd_StrAngleSpd = 500.0F;/* Variable: KcCOMM_Test_Cmd_StrAngleSpd
                                               * Referenced by: '<S42>/Constant101'
                                               */
real32_T KcCOMM_Test_Decs_Acc_Value = 0.0F;/* Variable: KcCOMM_Test_Decs_Acc_Value
                                            * Referenced by:
                                            *   '<S2>/Constant24'
                                            *   '<S42>/Constant96'
                                            */
real32_T KcCOMM_Test_Decs_Breake_Value = 0.0F;/* Variable: KcCOMM_Test_Decs_Breake_Value
                                               * Referenced by:
                                               *   '<S2>/Constant28'
                                               *   '<S42>/Constant93'
                                               */
real32_T KcCOMM_Test_Tar_vehiclespd = 0.0F;/* Variable: KcCOMM_Test_Tar_vehiclespd
                                            * Referenced by: '<S42>/Constant34'
                                            */
real32_T KfACCS_d_VEH_WheelDiameter = 0.0F;/* Variable: KfACCS_d_VEH_WheelDiameter
                                            * Referenced by: '<S7>/Constant8'
                                            * This is whell diameter
                                            */
real32_T KfCOMM_Ang_VEH_AngOrigin2FrontWheel = 0.0F;/* Variable: KfCOMM_Ang_VEH_AngOrigin2FrontWheel
                                                     * Referenced by: '<S7>/Constant1'
                                                     * This is the angle between origin to front axle and origin to front wheel
                                                     */
real32_T KfCOMM_VEH_Mass = 0.0F;       /* Variable: KfCOMM_VEH_Mass
                                        * Referenced by: '<S7>/Constant14'
                                        * Vehicle mass
                                        */
real32_T KfCOMM_VEH_StiffnessFront = 0.0F;/* Variable: KfCOMM_VEH_StiffnessFront
                                           * Referenced by: '<S7>/Constant11'
                                           * This is cornering stiffness of front wheel
                                           */
real32_T KfCOMM_VEH_StiffnessRear = 0.0F;/* Variable: KfCOMM_VEH_StiffnessRear
                                          * Referenced by: '<S7>/Constant10'
                                          * This is cornering stiffness of rear wheel
                                          */
real32_T KfCOMM_VEH_YawInertia_Z = 0.0F;/* Variable: KfCOMM_VEH_YawInertia_Z
                                         * Referenced by: '<S7>/Constant2'
                                         * Moment of inertia of the whole vehicle around z axis
                                         */
real32_T KfCOMM_a_VCULongAccOffset = 0.0F;/* Variable: KfCOMM_a_VCULongAccOffset
                                           * Referenced by:
                                           *   '<S17>/CTRL_VehicleCANbusConfig3'
                                           *   '<S18>/CTRL_VehicleCANbusConfig3'
                                           * Offset to override Longitudinal Acceleration.
                                           */
real32_T KfCOMM_d_VEH_DisCentorid2Front = 0.0F;/* Variable: KfCOMM_d_VEH_DisCentorid2Front
                                                * Referenced by: '<S7>/Constant13'
                                                * This is the distance between Cetroid and Front surface
                                                */
real32_T KfCOMM_d_VEH_DisFront2Rear = 0.0F;/* Variable: KfCOMM_d_VEH_DisFront2Rear
                                            * Referenced by: '<S7>/Constant15'
                                            * This is distance between two axes
                                            */
real32_T KfCOMM_d_VEH_DisLeft2Right = 0.0F;/* Variable: KfCOMM_d_VEH_DisLeft2Right
                                            * Referenced by: '<S7>/Constant12'
                                            * This is the distance between left wheel and right wheel
                                            */
real32_T KfCOMM_d_VEH_DisOrigin2End = 0.0F;/* Variable: KfCOMM_d_VEH_DisOrigin2End
                                            * Referenced by: '<S7>/Constant4'
                                            * This is the distance between the cordinate origin and the rear surface
                                            */
real32_T KfCOMM_d_VEH_DisOrigin2FrontWheel = 0.0F;/* Variable: KfCOMM_d_VEH_DisOrigin2FrontWheel
                                                   * Referenced by: '<S7>/Constant3'
                                                   */
real32_T KfCOMM_d_VEH_DisOrigin2Head = 0.0F;/* Variable: KfCOMM_d_VEH_DisOrigin2Head
                                             * Referenced by: '<S7>/Constant6'
                                             * This is the distance between the coordinate origin and the front surface
                                             */
real32_T KfCOMM_d_VEH_DisOrigin2RearAxle = 0.0F;/* Variable: KfCOMM_d_VEH_DisOrigin2RearAxle
                                                 * Referenced by: '<S7>/Constant5'
                                                 * This is the distance between the cordinate origin and the rear axle
                                                 */
real32_T KfCOMM_d_VEH_Length = 0.0F;   /* Variable: KfCOMM_d_VEH_Length
                                        * Referenced by: '<S7>/Constant9'
                                        * This is vehicle length
                                        */
real32_T KfCOMM_d_VEH_MinTurnRadius = 0.0F;/* Variable: KfCOMM_d_VEH_MinTurnRadius
                                            * Referenced by: '<S7>/Constant'
                                            * Minimum turning radius
                                            */
real32_T KfCOMM_d_VEH_Width = 0.0F;    /* Variable: KfCOMM_d_VEH_Width
                                        * Referenced by: '<S7>/Constant7'
                                        * Vehicle's width
                                        */
real32_T KfCOMM_r_VCULongAccSlope = 1.0F;/* Variable: KfCOMM_r_VCULongAccSlope
                                          * Referenced by:
                                          *   '<S17>/CTRL_VehicleCANbusConfig2'
                                          *   '<S18>/CTRL_VehicleCANbusConfig2'
                                          * Slope to override Longitudinal Acceleration.
                                          */
uint8_T KcCOMM_Test_Cmd_ATOModEnable = 0U;/* Variable: KcCOMM_Test_Cmd_ATOModEnable
                                           * Referenced by: '<S42>/Constant99'
                                           */
uint8_T KcCOMM_Test_Cmd_TgtSft = 0U;   /* Variable: KcCOMM_Test_Cmd_TgtSft
                                        * Referenced by: '<S42>/Constant90'
                                        */
uint8_T KcCOMM_Test_Decs_Acc_Req = 0U; /* Variable: KcCOMM_Test_Decs_Acc_Req
                                        * Referenced by: '<S2>/Constant18'
                                        */
uint8_T KcCOMM_Test_mode = 0U;         /* Variable: KcCOMM_Test_mode
                                        * Referenced by: '<S2>/Constant34'
                                        */
uint8_T KcCOMM_TorqCtrlPriority_Active = 3U;/* Variable: KcCOMM_TorqCtrlPriority_Active
                                             * Referenced by: '<S53>/Constant'
                                             * The priority of the Torque Override Control Mode send to VCU in ADV active state.
                                               0 - Highest priority.
                                               1 - High priority.
                                               2 - Medium priority.
                                               3 - Low priority.
                                             */
uint8_T KcCOMM_TorqCtrlPriority_Default = 3U;/* Variable: KcCOMM_TorqCtrlPriority_Default
                                              * Referenced by: '<S53>/Constant_0'
                                              * The priority of the Torque Override Control Mode send to VCU in default state.
                                                0 - Highest priority.
                                                1 - High priority.
                                                2 - Medium priority.
                                                3 - Low priority.
                                              */
uint8_T KeCOMM_Test_Cmd_ParkingCtrlValue = 0U;/* Variable: KeCOMM_Test_Cmd_ParkingCtrlValue
                                               * Referenced by: '<S42>/Constant25'
                                               */
uint8_T KeCOMM_VehicleCANbusConfig = 1U;/* Variable: KeCOMM_VehicleCANbusConfig
                                         * Referenced by:
                                         *   '<S1>/CTRL_VehicleCANbusConfig1'
                                         *   '<S1>/Constant'
                                         *   '<S2>/CTRL_VehicleCANbusConfig1'
                                         * Vehicle Platform and CAN Bus Configuration.
                                           1 - JAC#1;
                                           2 - JAC#2 or iVISTA;
                                           3 - ICPV;
                                           4 - GLB;
                                           5 - FAW;
                                           6 - HZBus;
                                           7 - USdemo.
                                         */
boolean_T KbCOMM_Test_BckFogLamp_Req = 0;/* Variable: KbCOMM_Test_BckFogLamp_Req
                                          * Referenced by: '<S42>/Constant86'
                                          */
boolean_T KbCOMM_Test_BrakePrechargeRequest = 0;/* Variable: KbCOMM_Test_BrakePrechargeRequest
                                                 * Referenced by: '<S42>/Constant39'
                                                 * Test mode value for brake boost precharge request.
                                                 */
boolean_T KbCOMM_Test_Cmd_AccPelEnable = 0;/* Variable: KbCOMM_Test_Cmd_AccPelEnable
                                            * Referenced by: '<S42>/Constant28'
                                            */
boolean_T KbCOMM_Test_Cmd_BrakeLightReq = 0;/* Variable: KbCOMM_Test_Cmd_BrakeLightReq
                                             * Referenced by: '<S42>/Constant78'
                                             */
boolean_T KbCOMM_Test_Cmd_BrkPelEnable = 0;/* Variable: KbCOMM_Test_Cmd_BrkPelEnable
                                            * Referenced by: '<S42>/Constant91'
                                            */
boolean_T KbCOMM_Test_Cmd_ParkingCtrlEnable = 0;/* Variable: KbCOMM_Test_Cmd_ParkingCtrlEnable
                                                 * Referenced by: '<S42>/Constant36'
                                                 */
boolean_T KbCOMM_Test_Cmd_TgtSftEnable = 0;/* Variable: KbCOMM_Test_Cmd_TgtSftEnable
                                            * Referenced by: '<S42>/Constant89'
                                            */
boolean_T KbCOMM_Test_Decs_DippedBeam_Req = 0;/* Variable: KbCOMM_Test_Decs_DippedBeam_Req
                                               * Referenced by: '<S42>/Constant79'
                                               */
boolean_T KbCOMM_Test_Decs_HighBeam_Req = 0;/* Variable: KbCOMM_Test_Decs_HighBeam_Req
                                             * Referenced by: '<S42>/Constant80'
                                             */
boolean_T KbCOMM_Test_Decs_LftLmp_Req = 0;/* Variable: KbCOMM_Test_Decs_LftLmp_Req
                                           * Referenced by: '<S42>/Constant83'
                                           */
boolean_T KbCOMM_Test_Decs_Light_Req = 0;/* Variable: KbCOMM_Test_Decs_Light_Req
                                          * Referenced by: '<S42>/Constant87'
                                          */
boolean_T KbCOMM_Test_Decs_RihtLmp_Req = 0;/* Variable: KbCOMM_Test_Decs_RihtLmp_Req
                                            * Referenced by: '<S42>/Constant84'
                                            */
boolean_T KbCOMM_Test_Decs_iBCM_Req = 0;/* Variable: KbCOMM_Test_Decs_iBCM_Req
                                         * Referenced by:
                                         *   '<S42>/Constant74'
                                         *   '<S46>/Constant2'
                                         *   '<S46>/Constant41'
                                         */
boolean_T KbCOMM_Test_FrontFogLamp_Req = 0;/* Variable: KbCOMM_Test_FrontFogLamp_Req
                                            * Referenced by: '<S42>/Constant85'
                                            */
boolean_T KbCOMM_Test_Horn_Req = 0;    /* Variable: KbCOMM_Test_Horn_Req
                                        * Referenced by: '<S42>/Constant71'
                                        */
boolean_T KbCOMM_Test_Over_Speed = 0;  /* Variable: KbCOMM_Test_Over_Speed
                                        * Referenced by: '<S42>/Constant26'
                                        * SLEW value for Over Speed.
                                        */
boolean_T KbCOMM_Test_SlowDown_Indication = 0;/* Variable: KbCOMM_Test_SlowDown_Indication
                                               * Referenced by: '<S42>/Constant27'
                                               * SLEW value for SpeedUp_Indication.
                                               */
boolean_T KbCOMM_Test_SpeedUp_Indication = 0;/* Variable: KbCOMM_Test_SpeedUp_Indication
                                              * Referenced by: '<S42>/Constant38'
                                              * SLEW value for SpeedUp_Indication.
                                              */
boolean_T KbCOMM_Test_Stop_Request = 0;/* Variable: KbCOMM_Test_Stop_Request
                                        * Referenced by: '<S42>/Constant35'
                                        */
boolean_T KbCOMM_Test_WarnLight_Req = 0;/* Variable: KbCOMM_Test_WarnLight_Req
                                         * Referenced by: '<S42>/Constant88'
                                         */
boolean_T KbCOMM_Test_driveoff_Req = 1;/* Variable: KbCOMM_Test_driveoff_Req
                                        * Referenced by: '<S42>/Constant32'
                                        */
boolean_T KbCOMM_VEH_UseNewConfig = 0; /* Variable: KbCOMM_VEH_UseNewConfig
                                        * Referenced by: '<S1>/Constant1'
                                        * This calibartion can change to a new vehicle configure which can be calibrated
                                        */
boolean_T KcCOMM_Test_Cmd_EPSXBW_En = 0;/* Variable: KcCOMM_Test_Cmd_EPSXBW_En
                                         * Referenced by:
                                         *   '<S2>/Constant30'
                                         *   '<S42>/Constant100'
                                         */
boolean_T KcCOMM_Test_Cmd_EPSXBW_En_ovr = 0;/* Variable: KcCOMM_Test_Cmd_EPSXBW_En_ovr
                                             * Referenced by: '<S2>/Constant33'
                                             */
boolean_T KcCOMM_Test_Cmd_StrAngle_ovr = 0;/* Variable: KcCOMM_Test_Cmd_StrAngle_ovr
                                            * Referenced by: '<S2>/Constant12'
                                            */
boolean_T KcCOMM_Test_Decs_Acc_Req_ovr = 0;/* Variable: KcCOMM_Test_Decs_Acc_Req_ovr
                                            * Referenced by: '<S2>/Constant11'
                                            */
boolean_T KcCOMM_Test_Decs_Acc_Value_ovr = 0;/* Variable: KcCOMM_Test_Decs_Acc_Value_ovr
                                              * Referenced by: '<S2>/Constant23'
                                              */
boolean_T KcCOMM_Test_Decs_Breake_Req = 0;/* Variable: KcCOMM_Test_Decs_Breake_Req
                                           * Referenced by: '<S2>/Constant31'
                                           */
boolean_T KcCOMM_Test_Decs_Breake_Req_ovr = 0;/* Variable: KcCOMM_Test_Decs_Breake_Req_ovr
                                               * Referenced by: '<S2>/Constant29'
                                               */
boolean_T KcCOMM_Test_Decs_Breake_Value_ovr = 0;/* Variable: KcCOMM_Test_Decs_Breake_Value_ovr
                                                 * Referenced by: '<S2>/Constant26'
                                                 */
#pragma section

/* Block signals (auto storage) */
B_COMM_subsystem_integrated_T COMM_subsystem_integrated_B;

/* Block states (auto storage) */
DW_COMM_subsystem_integrated_T COMM_subsystem_integrated_DW;
const COMM_CAN_Data_Receive COMM_subsystem_integrated_rtZCO =
{
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_1_Receive__CAN_2_ID__195 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_1_Receive__CAN_0_ID_1640 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_1_Receive__CAN_0_ID__421 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_1_Receive__CAN_0_ID__603 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_1_Receive__CAN_0_ID__304 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_1_Receive__CAN_0_ID__810 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_2_Receive__CAN_2_ID__195 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_2_Receive__CAN_2_ID_1640 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_2_Receive__CAN_2_ID__421 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_2_Receive__CAN_2_ID_1659 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_2_Receive__CAN_2_ID__603 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_2_Receive__CAN_2_ID__304 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_2_Receive__CAN_2_ID__810 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_3_Receive__CAN_2_ID__520 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_3_Receive__CAN_2_ID__280 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_3_Receive__CAN_2_ID__273 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_3_Receive__CAN_2_ID_1640 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_3_Receive__CAN_2_ID_1560 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_3_Receive__CAN_2_ID__530 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_3_Receive__CAN_0_ID__717 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_3_Receive__CAN_0_ID__421 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_3_Receive__CAN_0_ID__570 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_3_Receive__CAN_0_ID__517 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_3_Receive__CAN_0_ID__810 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_3_Receive__CAN_0_ID__683 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_3_Receive__CAN_0_ID__419 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_3_Receive__CAN_0_ID_1638 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_6_Receive__CAN_4_ID_201443255 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_6_Receive__CAN_4_ID_418384139 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_6_Receive__CAN_4_ID_201434535 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_6_Receive__CAN_4_ID_419348235 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_7_Receive__CAN_2_ID__820 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_7_Receive__CAN_2_ID__544 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_7_Receive__CAN_2_ID__332 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_7_Receive__CAN_2_ID__344 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  },                                   /* Config_7_Receive__CAN_2_ID__284 */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
    }                                  /* Data */
  }                                    /* Config_7_Receive__CAN_2_ID__258 */
};

const COMM_VEH_RX_Data COMM_subsystem_integrated_rtZ_0 =
{
  {
    0U,                                /* VCU_Mode */
    0U,                                /* Manual_Brake_Switch */
    0.0F,                              /* Manual_Accelerator_Pedal */
    0U                                 /* Auto_To_Manual_Tips */
  },                                   /* R01 */
  {
    0                                  /* Nominal_friction_percent_torque */
  },                                   /* R02 */
  {
    0U                                 /* Engine_Oil_Pressure */
  },                                   /* R03 */
  {
    0                                  /* Engine_coolant_temperature */
  },                                   /* R07 */
  {
    0.0F                               /* Catalyst_Tank_Level */
  },                                   /* R08 */
  {
    0.0F,                              /* Output_Shaft_Speed */
    0.0F                               /* Input_Shaft_Speed */
  },                                   /* R09 */
  {
    0.0F,                              /* Actual_Gear_Ratio */
    0                                  /* Current_Gear */
  },                                   /* R10 */
  {
    0U                                 /* Engine_Coolant_Level_Low_Lamp */
  },                                   /* R11 */
  {
    0U,                                /* Ser_Brake_Circuit_1_Air_Pressure */
    0U                                 /* Ser_Brake_Circuit_2_Air_Pressure */
  },                                   /* R12 */
  {
    0U,                                /* Engine_torque_mode */
    0,                                 /* Driver_demand_percent_torque */
    0,                                 /* Actua_engine_percent_torque */
    0.0F                               /* Engine_Speed */
  },                                   /* R13 */
  {
    0U,                                /* Parking_Brake_Switch */
    0.0F,                              /* Wheel_based_vehicle_speed */
    0U                                 /* Brake_Switch */
  },                                   /* R14 */
  {
    0.0F                               /* High_Resolu_TotalVehDistance */
  },                                   /* R15 */
  {
    0U,                                /* ABS_active */
    0U,                                /* EBS_Brake_Switch */
    0.0F,                              /* Brake_Pedal_Position */
    0U,                                /* EBS_Red_Warning_Signal */
    0U                                 /* ABS_EBSAmberWarningSig */
  },                                   /* R16 */
  {
    0.0F,                              /* Front_Axle_Speed */
    0.0F,                              /* Relative_Speed_FA_Leftwheel */
    0.0F,                              /* Relative_Speed_RA_RightWheel */
    0.0F,                              /* Relative_Speed_RA1_Leftwheel */
    0.0F,                              /* Relative_Speed_RA1_Rightwheel */
    0.0F,                              /* Relative_Speed_RA2_Leftwheel */
    0.0F                               /* Relative_Speed_RA2_Rightwheel */
  },                                   /* R17 */
  {
    0.0F,                              /* Steer_Wheel_Angle */
    0.0F,                              /* Yaw_Rate */
    0.0F,                              /* Lateral_Accerleration */
    0.0F                               /* Longitudinal_Acceleration */
  },                                   /* R19 */
  {
    0.0F,                              /* Column_Torque */
    0.0F,                              /* Coulmn_Velocity */
    0.0F,                              /* Pull_Compensation */
    false,                             /* Column_Torque_QF */
    false,                             /* Column_Velocity_QF */
    false,                             /* Ignition_State */
    false,                             /* Hands_off_Detected */
    false,                             /* Hands_on_Detcted */
    0U,                                /* Column_Message_Checksum */
    0U                                 /* Column_Message_Counter */
  },                                   /* R20 */
  {
    0.0F,                              /* Absolute_Steering_Position */
    0.0F,                              /* External_Input_Command_Echo */
    0U,                                /* Status_Error */
    0U,                                /* Actual_Mode */
    0U,                                /* Request_Mode */
    false,                             /* Absolute_Steering_Position_QF */
    0U,                                /* Steer_Message_Checksum */
    0U                                 /* Steer_Message_counter */
  },                                   /* R21 */
  {
    0U,                                /* EPB_Working_Mode */
    0U,                                /* Autohold_Working_Status */
    0U                                 /* EPB_Driverless_mode */
  },                                   /* R25 */
  {
    0U,                                /* Tractor_Front_Fog_LightsCommand */
    0U                                 /* Rear_Fog_Light_Command */
  },                                   /* R27 */
  {
    0U,                                /* Veh_running_state */
    0U,                                /* Low_beam_light_state */
    0U,                                /* High_beam_light_state */
    0U,                                /* Right_turnning_light_state */
    0U,                                /* Left_turnning_light_state */
    0U,                                /* Reversing_light_and_alarm_horn */
    0U                                 /* Position_lamp_state */
  },                                   /* R28 */
  {
    0U,                                /* BCM_response_status */
    0U,                                /* Rear_brake_lamp_status */
    0U                                 /* Horn_command_status */
  },                                   /* R29 */
  {
    0U,                                /* Front_Operator_Wiper_Switch */
    0U                                 /* Front_Operator_Washer_Switch */
  },                                   /* R30 */
  {
    0U,                                /* Tire_Location */
    0U,                                /* Tire_pressure */
    0.0F,                              /* Tire_Temperature */
    0U,                                /* Tire_Status */
    0U,                                /* Extended_Tire_Pressure_Support */
    0.0F,                              /* Tire_Air_Leakage_Rate */
    0U                                 /* Tire_Pressure_Thresh_Detection */
  },                                   /* R32 */
  {
    0,                                 /* Tire_Location */
    0U,                                /* Tire_Pressure_Extended_Range */
    0U                                 /* Required_Tire_Pressure */
  },                                   /* R33 */
  {
    0U,                                /* Open_Status_of_Door_1_Driver */
    0U                                 /* OpenStatus_of_Door_2_Passenger */
  },                                   /* R34 */
  {
    0.0F                               /* Fuel_Level_1 */
  },                                   /* R35 */
  {
    0U,                                /* ADV_Function_Switch_1 */
    0U                                 /* ADV_Function_Switch_2 */
  },                                   /* R39 */
  {
    0U,                                /* Axle_Location */
    0.0F                               /* Axle_Weight */
  }                                    /* R40 */
};

/* Model step function */
void COMM_subsystem_integrated_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/Receive' */
  COMM_subsystem_integrat_Receive();

  /* End of Outputs for SubSystem: '<Root>/Receive' */

  /* Outputs for Atomic SubSystem: '<Root>/Transmit' */
  COMM_subsystem_integra_Transmit();

  /* End of Outputs for SubSystem: '<Root>/Transmit' */
}

/* Model initialize function */
void COMM_subsystem_integrated_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* block I/O */
  (void) memset(((void *) &COMM_subsystem_integrated_B), 0,
                sizeof(B_COMM_subsystem_integrated_T));

  /* exported global signals */
  VsCOMM_CANR_Databus = COMM_subsystem_integrated_rtZCOMM_CANR_Databus;
  VsCOMM_CAN_Data_Transmit = COMM_subsystem_integrated_rtZCOMM_CAN_Data_Transmit;
  VsCOMM_CANT_Databus = COMM_subsystem_integrated_rtZCOMM_CANT_Databus;
  VsCOMM_FAW_ADCU_TX_Data = COMM_subsystem_integrated_rtZCOMM_ADCU_TX_Data;
  VsCOMM_VEH_Config = COMM_subsystem_integrated_rtZCOMM_Bus_VEH_Config;
  VfCOMM_ADCU_BrakeDecelValue = 0.0F;
  VfCOMM_ADCU_PowerAccelValue = 0.0F;
  VfCOMM_ADCU_SteeringAngleValue = 0.0F;
  VfCOMM_ADCU_TargetVehicleSpeed = 0.0F;
  VfCOMM_ADCU_PowerTorqueValue = 0.0F;
  VfCOMM_ADCU_BrakePressureValue = 0.0F;
  VfCOMM_max_gas_pedal_EPB = 0.0F;
  VfCOMM_TCU_ActualGearRatio = 0.0F;
  VfCOMM_VDC_YawRate = 0.0F;
  VfCOMM_VDC_VehicleSpeed = 0.0F;
  VfCOMM_VDC_WheelSpeed_RR1 = 0.0F;
  VfCOMM_VDC_LongAcceleration = 0.0F;
  VfCOMM_VDC_LateralAcceleration = 0.0F;
  VfCOMM_VDC_WheelSpeed_RR2 = 0.0F;
  VfCOMM_VDC_WheelSpeed_RL1 = 0.0F;
  VfCOMM_VDC_WheelSpeed_RL2 = 0.0F;
  VfCOMM_EPS_TargetSteeringAngleEcho = 0.0F;
  VfCOMM_EPS_ActualSteeringAngle = 0.0F;
  VfCOMM_EPS_SteeringAngleRate = 0.0F;
  VfCOMM_VDC_WheelSpeed_FR = 0.0F;
  VfCOMM_VDC_WheelSpeed_FL = 0.0F;
  VfCOMM_VCU_VirtualAccelPedalPosition = 0.0F;
  VfCOMM_EMS_EngineSpeed = 0.0F;
  VfCOMM_PCU_DriverDemandTorque = 0.0F;
  VfCOMM_PCU_ActualEngineTorque = 0.0F;
  VfCOMM_EMS_CatalystTankLevel = 0.0F;
  VfCOMM_VCU_ActualAccelPedalPosition = 0.0F;
  VfCOMM_VCU_TargetAccelPedalPostionEcho = 0.0F;
  VfCOMM_PCU_BatterySOC = 0.0F;
  VfCOMM_PCU_MotorSpeed = 0.0F;
  VfCOMM_PCU_MotorActualTorque = 0.0F;
  VfCOMM_PCU_EngineTorqueLoss = 0.0F;
  VfCOMM_EPS_SteeringWheelTorque = 0.0F;
  VfCOMM_VCU_TargetBrakePedalEcho = 0.0F;
  VfCOMM_VCU_ActualBrakePedalPosition = 0.0F;
  VfCOMM_ESP_MasterCylinderPress = 0.0F;
  VfCOMM_VDC_WheelEncoderCounter_RL = 0U;
  VfCOMM_VDC_WheelEncoderCounter_RR = 0U;
  VfCOMM_EMS_EngineCoolantTemperature = 0;
  VfCOMM_EMS_EngineOilPressure = 0U;
  VeCOMM_VCU_AutoToManualTips = 0U;
  VfCOMM_ESP_BrakeAirTankPressure = 0U;
  VeCOMM_ADCU_TargetGearValue = 0U;
  VeCOMM_ADCU_ParkingControlValue = 0U;
  VeCOMM_TCU_TargetGearPositionEcho = 0U;
  VeCOMM_TCU_ShiftLevelPosition = 0U;
  VeCOMM_TCU_ActualGearPosition = 0U;
  VeCOMM_EPS_SteeringModeEcho = 0U;
  VeCOMM_EMS_StartStopStatus = 0U;
  VeCOMM_EMS_EngineState = 0U;
  VeCOMM_PCU_PowertrainFaultLevel = 0U;
  VeCOMM_EPS_FaultLevel = 0U;
  VeCOMM_BCM_CruiseControlStatus = 0U;
  VeCOMM_BCM_DriveMode = 0U;
  VeCOMM_ESP_SystemFaultStatus = 0U;
  VeCOMM_EPB_SystemFaultStatus = 0U;
  VeCOMM_EPB_ActualControlStatus = 0U;
  VbCOMM_ADCU_EmergencyLightRequest = false;
  VbCOMM_ADCU_RightTurningLightRequest = false;
  VbCOMM_ADCU_PositionLightRequest = false;
  VbCOMM_ADCU_LeftTurningLightRequest = false;
  VbCOMM_ADCU_HornRequest = false;
  VbCOMM_ADCU_HighBeamRequest = false;
  VbCOMM_ADCU_FrontFogLightRequest = false;
  VbCOMM_ADCU_LowBeamRequest = false;
  VbCOMM_ADCU_BrakeLightRequest = false;
  VbCOMM_ADCU_BackFogLghtRequest = false;
  VbCOMM_ADCU_AutodriveEnable = false;
  VbCOMM_ADCU_BCMControlEnable = false;
  VbCOMM_ADCU_TargetGearEnable = false;
  VbCOMM_ADCU_SteeringAngleEnable = false;
  VbCOMM_ADCU_ParkingPressureRequest = false;
  VbCOMM_ADCU_LaunchRequest = false;
  VbCOMM_ADCU_ParkingControlEnable = false;
  VbCOMM_ADCU_PowerEnable = false;
  VbCOMM_ADCU_BrakeEnable = false;
  VbCOMM_ADCU_SpeedDownIndicator = false;
  VbCOMM_ADCU_SpeedUpIndicator = false;
  VbCOMM_ADCU_OverSpeedWarning = false;
  VbCOMM_VDC_YawRateValid = false;
  VbCOMM_VDC_LongAccelerationValid = false;
  VbCOMM_EPS_SteeringWheelTorqueValid = false;
  VbCOMM_VDC_LateralAccelerationValid = false;
  VbCOMM_EPS_SteeringControlResponse_LDW = false;
  VbCOMM_EPS_SteeringControlResponse_LCC = false;
  VbCOMM_VDC_WheelSpeed_RR1Valid = false;
  VbCOMM_VDC_WheelSpeed_RR2Valid = false;
  VbCOMM_VDC_WheelSpeed_RL1Valid = false;
  VbCOMM_VDC_WheelSpeed_FLValid = false;
  VbCOMM_VDC_WheelSpeed_RL2Valid = false;
  VbCOMM_VDC_WheelSpeed_FRValid = false;
  VbCOMM_EMS_EngineSpeedValid = false;
  VbCOMM_VCU_VirtualAccelPedalValid = false;
  VbCOMM_VCU_AccelPedalOverride = false;
  VbCOMM_EMS_CoolantLevelLow = false;
  VbCOMM_PCU_PowerControlResponse = false;
  VbCOMM_VCU_AccelPedalValid = false;
  VbCOMM_EPS_HandsOnWheelDetected = false;
  VbCOMM_EPS_HandsOffWheelDetected = false;
  VbCOMM_VCU_AutodriveMainSwitch = false;
  VbCOMM_BCM_CruiseSwLimitMain = false;
  VbCOMM_BCM_DriverSeatBelt = false;
  VbCOMM_BCM_DriverSeatBeltValid = false;
  VbCOMM_BCM_TurningLightEcho = false;
  VbCOMM_BCM_LowBeamSwitch = false;
  VbCOMM_BCM_HighBeamSwitch = false;
  VbCOMM_BCM_BrakeLightStatus = false;
  VbCOMM_BCM_LeftTurningLightState = false;
  VbCOMM_BCM_RightTurningLightState = false;
  VbCOMM_VCU_AutodriveActiveStatus = false;
  VbCOMM_BCM_IgnitionKeyState = false;
  VbCOMM_BCM_DriverDoorStatus = false;
  VbCOMM_BCM_PassengerDoorStatus = false;
  VbCOMM_BCM_FrontHoodStatus = false;
  VbCOMM_BCM_RearRightDoorStatus = false;
  VbCOMM_BCM_RearLeftDoorStatus = false;
  VbCOMM_BCM_BackTrunkStatus = false;
  VbCOMM_BCM_WiperSwitch = false;
  VbCOMM_BCM_ControlResponse = false;
  VbCOMM_BCM_CruiseSwValid = false;
  VbCOMM_BCM_CruiseSwResume = false;
  VbCOMM_BCM_CruiseSwSet = false;
  VbCOMM_BCM_CruiseSwTimeGapPlus = false;
  VbCOMM_BCM_CruiseSwTimeGapMinus = false;
  VbCOMM_BCM_CruiseSwMain = false;
  VbCOMM_ESP_TCSActive = false;
  VbCOMM_ESP_ABSActive = false;
  VbCOMM_EPB_AutoholdStatus = false;
  VbCOMM_EPB_ParkingControlResponse = false;
  VbCOMM_EPB_SwitchStatus = false;
  VbCOMM_VCU_BrakePedalValid = false;
  VbCOMM_ESP_BrakeControlResponse = false;
  VbCOMM_VCU_ActualBrakePedalSwitch = false;
  VbCOMM_ESP_MasterCylinderPressValid = false;

  /* states (dwork) */
  (void) memset((void *)&COMM_subsystem_integrated_DW, 0,
                sizeof(DW_COMM_subsystem_integrated_T));

  /* external inputs */
  VsCOMM_CAN_Data_Receive = COMM_subsystem_integrated_rtZCO;
  VsCOMM_FAW_VEH_RX_Data = COMM_subsystem_integrated_rtZ_0;
  VbHWIO_DriverModeComd = false;
  VbHWIO_LeftTurningLightState = false;
  VbHWIO_RightTurningLightState = false;
  VbHWIO_ACC_MainSwitch = false;
  VbHWIO_ACC_ResumeSwitch = false;
  VbHWIO_ACC_SetSwitch = false;
  VbHWIO_ACC_TimeGapPlus = false;
  VbHWIO_ACC_TimeGapMinus = false;
  VbHWIO_ACC_CancelSwitch = false;

  /* Start for Atomic SubSystem: '<Root>/Receive' */
  COMM_subsystem_in_Receive_Start();

  /* End of Start for SubSystem: '<Root>/Receive' */

  /* ConstCode for Atomic SubSystem: '<Root>/Transmit' */
  COMM_subsystem_i_Transmit_Const();

  /* End of ConstCode for SubSystem: '<Root>/Transmit' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Receive' */
  COMM_subsystem_int_Receive_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/Receive' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Transmit' */
  COMM_subsystem_in_Transmit_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
