/*
 * File: comm_transmit.c
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

#include "comm_transmit.h"

/* Include model header file for global data */
#include "COMM_subsystem_integrated.h"
#include "COMM_subsystem_integrated_private.h"

/*
 * Output and update for action system:
 *    '<S41>/GearN'
 *    '<S41>/default'
 */
void COMM_subsystem_integrated_GearN(uint8_T *rty_Out1)
{
  /* SignalConversion: '<S63>/OutportBufferForOut1' incorporates:
   *  Constant: '<S63>/Constant'
   */
  *rty_Out1 = ((uint8_T)3U);
}

/* System initialize for atomic system: '<Root>/Transmit' */
void COMM_subsystem_in_Transmit_Init(void)
{
  /* SystemInitialize for IfAction SubSystem: '<S2>/ICPV New' */
  /* SystemInitialize for Merge: '<S41>/Merge1' */
  VfCOMM_max_gas_pedal_EPB = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S2>/ICPV New' */
}

/* Output and update for atomic system: '<Root>/Transmit' */
void COMM_subsystem_integra_Transmit(void)
{
  boolean_T rtb_DataTypeConversion19;
  int16_T rtb_Merge_h2gn;
  uint8_T rtb_DataTypeConversion13_idbb;
  real32_T u1;

  /* SignalConversion: '<S2>/Signal Conversion7' incorporates:
   *  Inport: '<Root>/VsARBT_DataBus'
   */
  VbCOMM_ADCU_HornRequest = VsARBT_DataBus.AccessoryGroup.horn_ctrl_req;

  /* SignalConversion: '<S2>/Signal Conversion5' incorporates:
   *  Inport: '<Root>/VsARBT_DataBus'
   */
  VbCOMM_ADCU_BrakeLightRequest =
    VsARBT_DataBus.BrakeGroup.brake_ctrl_enbl_to_comm;

  /* Logic: '<S2>/Logical Operator' incorporates:
   *  Constant: '<S38>/Constant'
   *  Constant: '<S39>/Constant'
   *  Inport: '<Root>/VsDCSN_DataBus'
   *  RelationalOperator: '<S2>/Relational Operator'
   *  RelationalOperator: '<S2>/Relational Operator1'
   */
  rtb_DataTypeConversion19 = ((AUTODRIVE_ACTIVATING ==
    VsDCSN_DataBus.EnablingFlags_Group.autodrive_control_mode) ||
    (VsDCSN_DataBus.EnablingFlags_Group.autodrive_control_mode ==
     AUTODRIVE_ACTIVATED));

  /* SignalConversion: '<S2>/Signal Conversion16' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion5'
   */
  VbCOMM_ADCU_AutodriveEnable = rtb_DataTypeConversion19;

  /* SignalConversion: '<S2>/Signal Conversion17' */
  VbCOMM_ADCU_BCMControlEnable = rtb_DataTypeConversion19;

  /* Switch: '<S2>/Switch9' incorporates:
   *  Constant: '<S2>/Constant26'
   */
  if (KcCOMM_Test_Decs_Breake_Value_ovr)
  {
    /* SignalConversion: '<S2>/Signal Conversion18' incorporates:
     *  Constant: '<S2>/Constant28'
     */
    VfCOMM_ADCU_BrakeDecelValue = KcCOMM_Test_Decs_Breake_Value;
  }
  else
  {
    /* SignalConversion: '<S2>/Signal Conversion18' incorporates:
     *  Inport: '<Root>/VsARBT_DataBus'
     */
    VfCOMM_ADCU_BrakeDecelValue = VsARBT_DataBus.BrakeGroup.brake_req_lon_a;
  }

  /* End of Switch: '<S2>/Switch9' */

  /* SignalConversion: '<S2>/Signal Conversion6' incorporates:
   *  Inport: '<Root>/VsARBT_DataBus'
   */
  VeCOMM_ADCU_TargetGearValue = VsARBT_DataBus.AccessoryGroup.gear_ctrl_req;

  /* Switch: '<S2>/Switch8' incorporates:
   *  Constant: '<S2>/Constant23'
   */
  if (KcCOMM_Test_Decs_Acc_Value_ovr)
  {
    /* SignalConversion: '<S2>/Signal Conversion19' incorporates:
     *  Constant: '<S2>/Constant24'
     */
    VfCOMM_ADCU_PowerAccelValue = KcCOMM_Test_Decs_Acc_Value;
  }
  else
  {
    /* SignalConversion: '<S2>/Signal Conversion19' incorporates:
     *  Inport: '<Root>/VsARBT_DataBus'
     */
    VfCOMM_ADCU_PowerAccelValue = VsARBT_DataBus.PowerGroup.power_req_lon_a;
  }

  /* End of Switch: '<S2>/Switch8' */

  /* Switch: '<S2>/Switch12' incorporates:
   *  Constant: '<S2>/Constant12'
   */
  if (KcCOMM_Test_Cmd_StrAngle_ovr)
  {
    /* SignalConversion: '<S2>/Signal Conversion20' incorporates:
     *  Constant: '<S2>/Constant32'
     */
    VfCOMM_ADCU_SteeringAngleValue = KcCOMM_Test_Cmd_StrAngle;
  }
  else
  {
    /* SignalConversion: '<S2>/Signal Conversion20' incorporates:
     *  Inport: '<Root>/VsARBT_DataBus'
     */
    VfCOMM_ADCU_SteeringAngleValue =
      VsARBT_DataBus.SteerGroup.steer_req_strwhl_angle;
  }

  /* End of Switch: '<S2>/Switch12' */

  /* SignalConversion: '<S2>/Signal Conversion21' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion6'
   *  Inport: '<Root>/VsARBT_DataBus'
   */
  VbCOMM_ADCU_TargetGearEnable =
    VsARBT_DataBus.AccessoryGroup.gear_ctrl_enbl_to_comm;

  /* Switch: '<S2>/Switch11' incorporates:
   *  Constant: '<S2>/Constant33'
   */
  if (KcCOMM_Test_Cmd_EPSXBW_En_ovr)
  {
    /* SignalConversion: '<S2>/Signal Conversion22' incorporates:
     *  Constant: '<S2>/Constant30'
     */
    VbCOMM_ADCU_SteeringAngleEnable = KcCOMM_Test_Cmd_EPSXBW_En;
  }
  else
  {
    /* SignalConversion: '<S2>/Signal Conversion22' incorporates:
     *  Inport: '<Root>/VsARBT_DataBus'
     */
    VbCOMM_ADCU_SteeringAngleEnable =
      VsARBT_DataBus.SteerGroup.steer_ctrl_enbl_to_comm;
  }

  /* End of Switch: '<S2>/Switch11' */

  /* SignalConversion: '<S2>/Signal Conversion23' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion11'
   *  Inport: '<Root>/VsARBT_DataBus'
   */
  VbCOMM_ADCU_ParkingPressureRequest =
    VsARBT_DataBus.AccessoryGroup.auto_hold_req;

  /* SignalConversion: '<S2>/Signal Conversion25' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion12'
   *  Inport: '<Root>/VsARBT_DataBus'
   */
  VbCOMM_ADCU_ParkingControlEnable =
    VsARBT_DataBus.AccessoryGroup.epb_ctrl_enbl_to_comm;

  /* SignalConversion: '<S2>/Signal Conversion26' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion13'
   *  Inport: '<Root>/VsARBT_DataBus'
   */
  VeCOMM_ADCU_ParkingControlValue =
    VsARBT_DataBus.AccessoryGroup.epb_switch_request ? 1U : 0U;

  /* Switch: '<S2>/Switch7' incorporates:
   *  Constant: '<S2>/Constant11'
   */
  if (KcCOMM_Test_Decs_Acc_Req_ovr)
  {
    /* SignalConversion: '<S2>/Signal Conversion27' incorporates:
     *  Constant: '<S2>/Constant18'
     */
    VbCOMM_ADCU_PowerEnable = (((int32_T)KcCOMM_Test_Decs_Acc_Req) != 0);
  }
  else
  {
    /* SignalConversion: '<S2>/Signal Conversion27' incorporates:
     *  Inport: '<Root>/VsARBT_DataBus'
     */
    VbCOMM_ADCU_PowerEnable = VsARBT_DataBus.PowerGroup.power_ctrl_enbl_to_comm;
  }

  /* End of Switch: '<S2>/Switch7' */

  /* Switch: '<S2>/Switch10' incorporates:
   *  Constant: '<S2>/Constant29'
   */
  if (KcCOMM_Test_Decs_Breake_Req_ovr)
  {
    /* SignalConversion: '<S2>/Signal Conversion28' incorporates:
     *  Constant: '<S2>/Constant31'
     */
    VbCOMM_ADCU_BrakeEnable = KcCOMM_Test_Decs_Breake_Req;
  }
  else
  {
    /* SignalConversion: '<S2>/Signal Conversion28' incorporates:
     *  Inport: '<Root>/VsARBT_DataBus'
     */
    VbCOMM_ADCU_BrakeEnable = VsARBT_DataBus.BrakeGroup.brake_ctrl_enbl_to_comm;
  }

  /* End of Switch: '<S2>/Switch10' */

  /* SignalConversion: '<S2>/Signal Conversion29' incorporates:
   *  Inport: '<Root>/VsDCSN_DataBus'
   */
  VfCOMM_ADCU_TargetVehicleSpeed =
    VsDCSN_DataBus.TrafficDecider_Group.target_speed_limit;

  /* SignalConversion: '<S2>/Signal Conversion30' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion9'
   *  Inport: '<Root>/VsARBT_DataBus'
   */
  VbCOMM_ADCU_SpeedDownIndicator =
    VsARBT_DataBus.BrakeGroup.brake_ctrl_enbl_to_comm;

  /* SignalConversion: '<S2>/Signal Conversion31' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion18'
   *  Inport: '<Root>/VsARBT_DataBus'
   */
  VbCOMM_ADCU_SpeedUpIndicator =
    VsARBT_DataBus.PowerGroup.power_ctrl_enbl_to_comm;

  /* SignalConversion: '<S2>/Signal Conversion33' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion19'
   *  Inport: '<Root>/VsDCSN_DataBus'
   */
  VbCOMM_ADCU_OverSpeedWarning =
    VsDCSN_DataBus.TrafficDecider_Group.over_speed_warning;

  /* SignalConversion: '<S2>/Signal Conversion4' incorporates:
   *  Inport: '<Root>/VsARBT_DataBus'
   */
  VfCOMM_ADCU_PowerTorqueValue = VsARBT_DataBus.PowerGroup.power_req_torque;

  /* Switch: '<S2>/Switch13' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment1'
   *  BusCreator: '<S42>/BusConversion_InsertedFor_Bus Creator1_at_inport_1'
   *  BusCreator: '<S42>/BusConversion_InsertedFor_Bus Creator1_at_inport_2'
   *  BusCreator: '<S42>/BusConversion_InsertedFor_Bus Creator1_at_inport_3'
   *  BusCreator: '<S42>/BusConversion_InsertedFor_Bus Creator1_at_inport_4'
   *  BusCreator: '<S42>/BusConversion_InsertedFor_Bus Creator1_at_inport_5'
   *  BusCreator: '<S42>/BusConversion_InsertedFor_Bus Creator1_at_inport_6'
   *  BusCreator: '<S42>/BusConversion_InsertedFor_Bus Creator1_at_inport_7'
   *  Constant: '<S2>/Constant34'
   *  Constant: '<S42>/Constant100'
   *  Constant: '<S42>/Constant101'
   *  Constant: '<S42>/Constant104'
   *  Constant: '<S42>/Constant107'
   *  Constant: '<S42>/Constant108'
   *  Constant: '<S42>/Constant24'
   *  Constant: '<S42>/Constant25'
   *  Constant: '<S42>/Constant26'
   *  Constant: '<S42>/Constant27'
   *  Constant: '<S42>/Constant28'
   *  Constant: '<S42>/Constant30'
   *  Constant: '<S42>/Constant32'
   *  Constant: '<S42>/Constant33'
   *  Constant: '<S42>/Constant34'
   *  Constant: '<S42>/Constant35'
   *  Constant: '<S42>/Constant36'
   *  Constant: '<S42>/Constant38'
   *  Constant: '<S42>/Constant39'
   *  Constant: '<S42>/Constant71'
   *  Constant: '<S42>/Constant74'
   *  Constant: '<S42>/Constant78'
   *  Constant: '<S42>/Constant79'
   *  Constant: '<S42>/Constant80'
   *  Constant: '<S42>/Constant83'
   *  Constant: '<S42>/Constant84'
   *  Constant: '<S42>/Constant85'
   *  Constant: '<S42>/Constant86'
   *  Constant: '<S42>/Constant87'
   *  Constant: '<S42>/Constant88'
   *  Constant: '<S42>/Constant89'
   *  Constant: '<S42>/Constant90'
   *  Constant: '<S42>/Constant91'
   *  Constant: '<S42>/Constant93'
   *  Constant: '<S42>/Constant95'
   *  Constant: '<S42>/Constant96'
   *  Constant: '<S42>/Constant98'
   *  Constant: '<S42>/Constant99'
   *  DataTypeConversion: '<S42>/Data Type Conversion'
   *  Inport: '<Root>/VsARBT_DataBus'
   *  SignalConversion: '<S2>/Signal Conversion32'
   */
  if (KcCOMM_Test_mode > ((uint8_T)0U))
  {
    VsCOMM_CANT_Databus.COMM_TX_AutodriveMode.ADCU_AutodriveEnable = (((int32_T)
      KcCOMM_Test_Cmd_ATOModEnable) != 0);
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_BCMControlEnable =
      KbCOMM_Test_Decs_iBCM_Req;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_BrakeLightRequest =
      KbCOMM_Test_Cmd_BrakeLightReq;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_LowBeamRequest =
      KbCOMM_Test_Decs_DippedBeam_Req;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_HighBeamRequest =
      KbCOMM_Test_Decs_HighBeam_Req;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_LeftTurningLightRequest =
      KbCOMM_Test_Decs_LftLmp_Req;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_RightTurningLightRequest =
      KbCOMM_Test_Decs_RihtLmp_Req;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_FrontFogLightRequest =
      KbCOMM_Test_FrontFogLamp_Req;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_BackFogLightRequest =
      KbCOMM_Test_BckFogLamp_Req;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_PositionLightRequest =
      KbCOMM_Test_Decs_Light_Req;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_EmergencyLightRequest =
      KbCOMM_Test_WarnLight_Req;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_HornRequest = KbCOMM_Test_Horn_Req;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_WiperControlRequest = ((uint8_T)0U);
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_WashingControlRequest = false;
    VsCOMM_CANT_Databus.COMM_TX_Brake.ADCU_BrakeEnable =
      KbCOMM_Test_Cmd_BrkPelEnable;
    VsCOMM_CANT_Databus.COMM_TX_Brake.ADCU_BrakePressureValue =
      KcCOMM_Test_Cmd_BrkPelPosAct;
    VsCOMM_CANT_Databus.COMM_TX_Brake.ADCU_BrakeDecelValue =
      KcCOMM_Test_Decs_Breake_Value;
    VsCOMM_CANT_Databus.COMM_TX_Brake.ADCU_BrakePrechargeRequest =
      KbCOMM_Test_BrakePrechargeRequest;
    VsCOMM_CANT_Databus.COMM_TX_HMI.ADCU_TargetVehicleSpeed =
      KcCOMM_Test_Tar_vehiclespd;
    VsCOMM_CANT_Databus.COMM_TX_HMI.ADCU_SpeedUpIndicator =
      KbCOMM_Test_SpeedUp_Indication;
    VsCOMM_CANT_Databus.COMM_TX_HMI.ADCU_SpeedDownIndicator =
      KbCOMM_Test_SlowDown_Indication;
    VsCOMM_CANT_Databus.COMM_TX_HMI.ADCU_OverSpeedWarning =
      KbCOMM_Test_Over_Speed;
    VsCOMM_CANT_Databus.COMM_TX_HMI.ADCU_FCW_Warning = ((uint8_T)0U);
    VsCOMM_CANT_Databus.COMM_TX_Parking.ADCU_ParkingPressureRequest =
      KbCOMM_Test_Stop_Request;
    VsCOMM_CANT_Databus.COMM_TX_Parking.ADCU_ParkingControlValue =
      KeCOMM_Test_Cmd_ParkingCtrlValue;
    VsCOMM_CANT_Databus.COMM_TX_Parking.ADCU_ParkingControlEnable =
      KbCOMM_Test_Cmd_ParkingCtrlEnable;
    VsCOMM_CANT_Databus.COMM_TX_Power.ADCU_PowerEnable =
      KbCOMM_Test_Cmd_AccPelEnable;
    VsCOMM_CANT_Databus.COMM_TX_Power.ADCU_PowerTorqueValue =
      KcCOMM_Test_Cmd_AccPelPosAct;
    VsCOMM_CANT_Databus.COMM_TX_Power.ADCU_PowerAccelValue =
      KcCOMM_Test_Decs_Acc_Value;
    VsCOMM_CANT_Databus.COMM_TX_Power.ADCU_LaunchRequest =
      KbCOMM_Test_driveoff_Req;
    VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringTorqueEnable = false;
    VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringTorqueValue = 0.0F;
    VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringAngleEnable =
      KcCOMM_Test_Cmd_EPSXBW_En;
    VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringAngleValue =
      KcCOMM_Test_Cmd_StrAngle;
    VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringAngleSpeed =
      KcCOMM_Test_Cmd_StrAngleSpd;
    VsCOMM_CANT_Databus.COMM_TX_Transmission.ADCU_TargetGearEnable =
      KbCOMM_Test_Cmd_TgtSftEnable;
    VsCOMM_CANT_Databus.COMM_TX_Transmission.ADCU_TargetGearValue =
      KcCOMM_Test_Cmd_TgtSft;
  }
  else
  {
    VsCOMM_CANT_Databus.COMM_TX_AutodriveMode.ADCU_AutodriveEnable =
      VbCOMM_ADCU_AutodriveEnable;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_BCMControlEnable =
      VbCOMM_ADCU_BCMControlEnable;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_BrakeLightRequest =
      VbCOMM_ADCU_BrakeLightRequest;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_LowBeamRequest =
      VbCOMM_ADCU_LowBeamRequest;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_HighBeamRequest =
      VbCOMM_ADCU_HighBeamRequest;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_LeftTurningLightRequest =
      VbCOMM_ADCU_LeftTurningLightRequest;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_RightTurningLightRequest =
      VbCOMM_ADCU_RightTurningLightRequest;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_FrontFogLightRequest =
      VbCOMM_ADCU_FrontFogLightRequest;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_BackFogLightRequest =
      VbCOMM_ADCU_BackFogLghtRequest;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_PositionLightRequest =
      VbCOMM_ADCU_PositionLightRequest;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_EmergencyLightRequest =
      VbCOMM_ADCU_EmergencyLightRequest;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_HornRequest = VbCOMM_ADCU_HornRequest;
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_WiperControlRequest = ((uint8_T)0U);
    VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_WashingControlRequest = false;
    VsCOMM_CANT_Databus.COMM_TX_Brake.ADCU_BrakeEnable = VbCOMM_ADCU_BrakeEnable;
    VsCOMM_CANT_Databus.COMM_TX_Brake.ADCU_BrakePressureValue =
      VfCOMM_ADCU_BrakePressureValue;
    VsCOMM_CANT_Databus.COMM_TX_Brake.ADCU_BrakeDecelValue =
      VfCOMM_ADCU_BrakeDecelValue;
    VsCOMM_CANT_Databus.COMM_TX_Brake.ADCU_BrakePrechargeRequest =
      VsARBT_DataBus.BrakeGroup.brake_precharge_req;
    VsCOMM_CANT_Databus.COMM_TX_HMI.ADCU_TargetVehicleSpeed =
      VfCOMM_ADCU_TargetVehicleSpeed;
    VsCOMM_CANT_Databus.COMM_TX_HMI.ADCU_SpeedUpIndicator =
      VbCOMM_ADCU_SpeedUpIndicator;
    VsCOMM_CANT_Databus.COMM_TX_HMI.ADCU_SpeedDownIndicator =
      VbCOMM_ADCU_SpeedDownIndicator;
    VsCOMM_CANT_Databus.COMM_TX_HMI.ADCU_OverSpeedWarning =
      VbCOMM_ADCU_OverSpeedWarning;
    VsCOMM_CANT_Databus.COMM_TX_HMI.ADCU_FCW_Warning = ((uint8_T)0U);
    VsCOMM_CANT_Databus.COMM_TX_Parking.ADCU_ParkingPressureRequest =
      VbCOMM_ADCU_ParkingPressureRequest;
    VsCOMM_CANT_Databus.COMM_TX_Parking.ADCU_ParkingControlValue =
      VeCOMM_ADCU_ParkingControlValue;
    VsCOMM_CANT_Databus.COMM_TX_Parking.ADCU_ParkingControlEnable =
      VbCOMM_ADCU_ParkingControlEnable;
    VsCOMM_CANT_Databus.COMM_TX_Power.ADCU_PowerEnable = VbCOMM_ADCU_PowerEnable;
    VsCOMM_CANT_Databus.COMM_TX_Power.ADCU_PowerTorqueValue =
      VfCOMM_ADCU_PowerTorqueValue;
    VsCOMM_CANT_Databus.COMM_TX_Power.ADCU_PowerAccelValue =
      VfCOMM_ADCU_PowerAccelValue;
    VsCOMM_CANT_Databus.COMM_TX_Power.ADCU_LaunchRequest =
      VbCOMM_ADCU_LaunchRequest;
    VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringTorqueEnable = false;
    VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringTorqueValue = 0.0F;
    VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringAngleEnable =
      VbCOMM_ADCU_SteeringAngleEnable;
    VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringAngleValue =
      VfCOMM_ADCU_SteeringAngleValue;
    VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringAngleSpeed =
      KcCOMM_Test_Cmd_StrAngleSpd;
    VsCOMM_CANT_Databus.COMM_TX_Transmission.ADCU_TargetGearEnable =
      VbCOMM_ADCU_TargetGearEnable;
    VsCOMM_CANT_Databus.COMM_TX_Transmission.ADCU_TargetGearValue =
      VeCOMM_ADCU_TargetGearValue;
  }

  /* End of Switch: '<S2>/Switch13' */

  /* SwitchCase: '<S2>/Switch Case1' incorporates:
   *  Constant: '<S2>/CTRL_VehicleCANbusConfig1'
   */
  switch (KeCOMM_VehicleCANbusConfig)
  {
   case 1:
    /* Outputs for IfAction SubSystem: '<S2>/iEV7S_New' incorporates:
     *  ActionPort: '<S44>/Action Port'
     */
    /* SwitchCase: '<S44>/Switch Case' */
    switch (VsCOMM_CANT_Databus.COMM_TX_Transmission.ADCU_TargetGearValue)
    {
     case 13:
      /* Outputs for IfAction SubSystem: '<S44>/GearR' incorporates:
       *  ActionPort: '<S69>/Action Port'
       */
      /* SignalConversion: '<S69>/OutportBufferForOut1' incorporates:
       *  Constant: '<S69>/Constant'
       */
      COMM_subsystem_integrated_B.Merge_lfml = ((uint8_T)0U);

      /* End of Outputs for SubSystem: '<S44>/GearR' */
      break;

     case 0:
      /* Outputs for IfAction SubSystem: '<S44>/GearN' incorporates:
       *  ActionPort: '<S68>/Action Port'
       */
      /* SignalConversion: '<S68>/OutportBufferForOut1' incorporates:
       *  Constant: '<S68>/Constant'
       */
      COMM_subsystem_integrated_B.Merge_lfml = ((uint8_T)1U);

      /* End of Outputs for SubSystem: '<S44>/GearN' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S44>/GearD' incorporates:
       *  ActionPort: '<S67>/Action Port'
       */
      /* SignalConversion: '<S67>/OutportBufferForOut1' incorporates:
       *  Constant: '<S67>/Constant'
       */
      COMM_subsystem_integrated_B.Merge_lfml = ((uint8_T)2U);

      /* End of Outputs for SubSystem: '<S44>/GearD' */
      break;

     default:
      /* Outputs for IfAction SubSystem: '<S44>/default' incorporates:
       *  ActionPort: '<S70>/Action Port'
       */
      /* SignalConversion: '<S70>/OutportBufferForOut1' incorporates:
       *  Constant: '<S70>/Constant'
       */
      COMM_subsystem_integrated_B.Merge_lfml = ((uint8_T)1U);

      /* End of Outputs for SubSystem: '<S44>/default' */
      break;
    }

    /* End of SwitchCase: '<S44>/Switch Case' */

    /* DataTypeConversion: '<S44>/Data Type Conversion7' */
    COMM_subsystem_integrated_B.Decs_Acc_Req_ewfe =
      VsCOMM_CANT_Databus.COMM_TX_Power.ADCU_PowerEnable;

    /* DataTypeConversion: '<S44>/Data Type Conversion6' */
    COMM_subsystem_integrated_B.Decs_Breake_Req_kolp =
      VsCOMM_CANT_Databus.COMM_TX_Brake.ADCU_BrakeEnable;

    /* Gain: '<S44>/Gain1' */
    COMM_subsystem_integrated_B.Decs_Breake_Value_jnah = (-1.0F) *
      VsCOMM_CANT_Databus.COMM_TX_Brake.ADCU_BrakeDecelValue;

    /* DataTypeConversion: '<S44>/Data Type Conversion5' */
    COMM_subsystem_integrated_B.Decs_Gear_Req_j1ga =
      VsCOMM_CANT_Databus.COMM_TX_Transmission.ADCU_TargetGearEnable;

    /* Gain: '<S44>/Gain' */
    COMM_subsystem_integrated_B.Decs_SteeringAngle = (-1.0F) *
      VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringAngleValue;

    /* DataTypeConversion: '<S44>/Data Type Conversion8' */
    COMM_subsystem_integrated_B.Decs_Steering_Req_bjr4 =
      VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringAngleEnable;

    /* Logic: '<S44>/Logical Operator' incorporates:
     *  Logic: '<S44>/Logical Operator1'
     */
    COMM_subsystem_integrated_B.Decs_iBCM_Req_prls =
      ((VsCOMM_CANT_Databus.COMM_TX_AutodriveMode.ADCU_AutodriveEnable) &&
       (!VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch));

    /* S-Function (scanpack): '<S44>/Config_1_Transmit_CAN_2_ID_193' incorporates:
     *  Constant: '<S44>/Constant12'
     */
    /* S-Function (scanpack): '<S44>/Config_1_Transmit_CAN_2_ID_193' */
    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.ID = 193U;
    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Length = 8U;
    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Extended = 0U;
    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Remote = 0;
    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data[0] = 0;
    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data[1] = 0;
    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data[2] = 0;
    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data[3] = 0;
    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data[4] = 0;
    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data[5] = 0;
    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data[6] = 0;
    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 45
       *  length                  = 4
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T) (((uint8_T)2U));

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (uint8_T)(15))
              {
                packedValue = (uint8_T) 15;
              }
              else if (packingValue < (uint8_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<7);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 3)) >> 3)<<0);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 6
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (COMM_subsystem_integrated_B.Decs_Acc_Req_ewfe);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [0] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<6);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 2 ------------------
       *  startBit                = 28
       *  length                  = 8
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 0.045
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real32_T outValue = 0;

          {
            real32_T result =
              VsCOMM_CANT_Databus.COMM_TX_Power.ADCU_PowerAccelValue;

            /* no offset to apply */
            result = result / 0.045F;
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real32_T)(255))
              {
                packedValue = (uint8_T) 255;
              }
              else if (outValue < (real32_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 3)) >> 3)<<7);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [2] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 4)) >> 4)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [2] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 5)) >> 5)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [2] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 6)) >> 6)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [2] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 7)) >> 7)<<3);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 3 ------------------
       *  startBit                = 49
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_BackFogLightRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [6] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [6] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<1);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 4 ------------------
       *  startBit                = 5
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (COMM_subsystem_integrated_B.Decs_Breake_Req_kolp);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [0] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<5);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 5 ------------------
       *  startBit                = 33
       *  length                  = 7
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 0.1
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real32_T outValue = 0;

          {
            real32_T result = COMM_subsystem_integrated_B.Decs_Breake_Value_jnah;

            /* no offset to apply */
            result = result / 0.1F;
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real32_T)(127))
              {
                packedValue = (uint8_T) 127;
              }
              else if (outValue < (real32_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<3);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 3)) >> 3)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 4)) >> 4)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 5)) >> 5)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 6)) >> 6)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 6 ------------------
       *  startBit                = 48
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_BrakeLightRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [6] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [6] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 7 ------------------
       *  startBit                = 42
       *  length                  = 2
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_AutodriveMode.ADCU_AutodriveEnable);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(3))
              {
                packedValue = (uint8_T) 3;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<3);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 8 ------------------
       *  startBit                = 63
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_LowBeamRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 9 ------------------
       *  startBit                = 62
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_FrontFogLightRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<6);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 10 ------------------
       *  startBit                = 4
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (COMM_subsystem_integrated_B.Decs_Gear_Req_j1ga);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [0] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<4);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 11 ------------------
       *  startBit                = 24
       *  length                  = 4
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T) (COMM_subsystem_integrated_B.Merge_lfml);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (uint8_T)(15))
              {
                packedValue = (uint8_T) 15;
              }
              else if (packingValue < (uint8_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 3)) >> 3)<<3);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 12 ------------------
       *  startBit                = 61
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_HighBeamRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<5);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 13 ------------------
       *  startBit                = 60
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_HornRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<4);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 14 ------------------
       *  startBit                = 59
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_LeftTurningLightRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<3);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 15 ------------------
       *  startBit                = 58
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_PositionLightRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<2);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 16 ------------------
       *  startBit                = 57
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_RightTurningLightRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<1);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 17 ------------------
       *  startBit                = 20
       *  length                  = 14
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 0.1
       *  offset                  = -550.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real32_T outValue = 0;

          {
            real32_T result = COMM_subsystem_integrated_B.Decs_SteeringAngle;

            /* full scaling operation */
            result = (result - -550.0F) / 0.1F;
            outValue = result;
          }

          {
            {
              uint16_T packedValue;
              if (outValue > (real32_T)(16383))
              {
                packedValue = (uint16_T) 16383;
              }
              else if (outValue < (real32_T)(0))
              {
                packedValue = (uint16_T) 0;
              }
              else
              {
                packedValue = (uint16_T) (outValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [2] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 0)) >> 0)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [2] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 1)) >> 1)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [2] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 2)) >> 2)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [2] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 3)) >> 3)<<7);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 4)) >> 4)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 5)) >> 5)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 6)) >> 6)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 7)) >> 7)<<3);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 8)) >> 8)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 9)) >> 9)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 10)) >> 10)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 11)) >> 11)<<7);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [0] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 12)) >> 12)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [0] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 13)) >> 13)<<1);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 18 ------------------
       *  startBit                = 7
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (COMM_subsystem_integrated_B.Decs_Steering_Req_bjr4);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [0] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 19 ------------------
       *  startBit                = 56
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_EmergencyLightRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 20 ------------------
       *  startBit                = 44
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (COMM_subsystem_integrated_B.Decs_iBCM_Req_prls);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<4);
                }
              }
            }
          }
        }
      }
    }

    /* End of Outputs for SubSystem: '<S2>/iEV7S_New' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S2>/iVISTA New' incorporates:
     *  ActionPort: '<S45>/Action Port'
     */
    /* SwitchCase: '<S45>/Switch Case' */
    switch (VsCOMM_CANT_Databus.COMM_TX_Transmission.ADCU_TargetGearValue)
    {
     case 13:
      /* Outputs for IfAction SubSystem: '<S45>/GearR' incorporates:
       *  ActionPort: '<S73>/Action Port'
       */
      /* SignalConversion: '<S73>/OutportBufferForOut1' incorporates:
       *  Constant: '<S73>/Constant'
       */
      COMM_subsystem_integrated_B.Merge = ((uint8_T)0U);

      /* End of Outputs for SubSystem: '<S45>/GearR' */
      break;

     case 0:
      /* Outputs for IfAction SubSystem: '<S45>/GearN' incorporates:
       *  ActionPort: '<S72>/Action Port'
       */
      /* SignalConversion: '<S72>/OutportBufferForOut1' incorporates:
       *  Constant: '<S72>/Constant'
       */
      COMM_subsystem_integrated_B.Merge = ((uint8_T)1U);

      /* End of Outputs for SubSystem: '<S45>/GearN' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S45>/GearD' incorporates:
       *  ActionPort: '<S71>/Action Port'
       */
      /* SignalConversion: '<S71>/OutportBufferForOut1' incorporates:
       *  Constant: '<S71>/Constant'
       */
      COMM_subsystem_integrated_B.Merge = ((uint8_T)2U);

      /* End of Outputs for SubSystem: '<S45>/GearD' */
      break;

     default:
      /* Outputs for IfAction SubSystem: '<S45>/default' incorporates:
       *  ActionPort: '<S74>/Action Port'
       */
      /* SignalConversion: '<S74>/OutportBufferForOut1' incorporates:
       *  Constant: '<S74>/Constant'
       */
      COMM_subsystem_integrated_B.Merge = ((uint8_T)1U);

      /* End of Outputs for SubSystem: '<S45>/default' */
      break;
    }

    /* End of SwitchCase: '<S45>/Switch Case' */

    /* DataTypeConversion: '<S45>/Data Type Conversion7' */
    COMM_subsystem_integrated_B.Decs_Acc_Req =
      VsCOMM_CANT_Databus.COMM_TX_Power.ADCU_PowerEnable;

    /* DataTypeConversion: '<S45>/Data Type Conversion6' */
    COMM_subsystem_integrated_B.Decs_Breake_Req =
      VsCOMM_CANT_Databus.COMM_TX_Brake.ADCU_BrakeEnable;

    /* Gain: '<S45>/Gain1' */
    COMM_subsystem_integrated_B.Decs_Breake_Value = (-1.0F) *
      VsCOMM_CANT_Databus.COMM_TX_Brake.ADCU_BrakeDecelValue;

    /* DataTypeConversion: '<S45>/Data Type Conversion5' */
    COMM_subsystem_integrated_B.Decs_Gear_Req =
      VsCOMM_CANT_Databus.COMM_TX_Transmission.ADCU_TargetGearEnable;

    /* DataTypeConversion: '<S45>/Data Type Conversion8' */
    COMM_subsystem_integrated_B.Decs_Steering_Req =
      VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringAngleEnable;

    /* Logic: '<S45>/Logical Operator' incorporates:
     *  Logic: '<S45>/Logical Operator1'
     */
    COMM_subsystem_integrated_B.Decs_iBCM_Req =
      ((VsCOMM_CANT_Databus.COMM_TX_AutodriveMode.ADCU_AutodriveEnable) &&
       (!VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch));

    /* S-Function (scanpack): '<S45>/Config_2_Transmit_CAN_2_ID_193' incorporates:
     *  Constant: '<S45>/Constant12'
     */
    /* S-Function (scanpack): '<S45>/Config_2_Transmit_CAN_2_ID_193' */
    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.ID = 193U;
    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Length = 8U;
    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Extended = 0U;
    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Remote = 0;
    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data[0] = 0;
    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data[1] = 0;
    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data[2] = 0;
    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data[3] = 0;
    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data[4] = 0;
    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data[5] = 0;
    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data[6] = 0;
    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 45
       *  length                  = 4
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T) (((uint8_T)2U));

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (uint8_T)(15))
              {
                packedValue = (uint8_T) 15;
              }
              else if (packingValue < (uint8_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<7);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 3)) >> 3)<<0);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 6
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (COMM_subsystem_integrated_B.Decs_Acc_Req);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [0] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<6);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 2 ------------------
       *  startBit                = 28
       *  length                  = 8
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 0.045
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real32_T outValue = 0;

          {
            real32_T result =
              VsCOMM_CANT_Databus.COMM_TX_Power.ADCU_PowerAccelValue;

            /* no offset to apply */
            result = result / 0.045F;
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real32_T)(255))
              {
                packedValue = (uint8_T) 255;
              }
              else if (outValue < (real32_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 3)) >> 3)<<7);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [2] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 4)) >> 4)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [2] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 5)) >> 5)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [2] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 6)) >> 6)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [2] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 7)) >> 7)<<3);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 3 ------------------
       *  startBit                = 49
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_BackFogLightRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [6] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [6] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<1);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 4 ------------------
       *  startBit                = 5
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (COMM_subsystem_integrated_B.Decs_Breake_Req);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [0] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<5);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 5 ------------------
       *  startBit                = 33
       *  length                  = 7
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 0.1
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real32_T outValue = 0;

          {
            real32_T result = COMM_subsystem_integrated_B.Decs_Breake_Value;

            /* no offset to apply */
            result = result / 0.1F;
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real32_T)(127))
              {
                packedValue = (uint8_T) 127;
              }
              else if (outValue < (real32_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<3);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 3)) >> 3)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 4)) >> 4)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 5)) >> 5)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 6)) >> 6)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 6 ------------------
       *  startBit                = 48
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_BrakeLightRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [6] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [6] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 7 ------------------
       *  startBit                = 42
       *  length                  = 2
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_AutodriveMode.ADCU_AutodriveEnable);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(3))
              {
                packedValue = (uint8_T) 3;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<3);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 8 ------------------
       *  startBit                = 63
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_LowBeamRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 9 ------------------
       *  startBit                = 62
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_FrontFogLightRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<6);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 10 ------------------
       *  startBit                = 4
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (COMM_subsystem_integrated_B.Decs_Gear_Req);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [0] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<4);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 11 ------------------
       *  startBit                = 24
       *  length                  = 4
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T) (COMM_subsystem_integrated_B.Merge);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (uint8_T)(15))
              {
                packedValue = (uint8_T) 15;
              }
              else if (packingValue < (uint8_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 3)) >> 3)<<3);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 12 ------------------
       *  startBit                = 61
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_HighBeamRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<5);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 13 ------------------
       *  startBit                = 60
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_HornRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<4);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 14 ------------------
       *  startBit                = 59
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_LeftTurningLightRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<3);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 15 ------------------
       *  startBit                = 58
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_PositionLightRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<2);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 16 ------------------
       *  startBit                = 57
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_RightTurningLightRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<1);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 17 ------------------
       *  startBit                = 20
       *  length                  = 14
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 0.1
       *  offset                  = -550.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real32_T outValue = 0;

          {
            real32_T result =
              VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringAngleValue;

            /* full scaling operation */
            result = (result - -550.0F) / 0.1F;
            outValue = result;
          }

          {
            {
              uint16_T packedValue;
              if (outValue > (real32_T)(16383))
              {
                packedValue = (uint16_T) 16383;
              }
              else if (outValue < (real32_T)(0))
              {
                packedValue = (uint16_T) 0;
              }
              else
              {
                packedValue = (uint16_T) (outValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [2] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 0)) >> 0)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [2] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 1)) >> 1)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [2] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 2)) >> 2)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [2] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 3)) >> 3)<<7);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 4)) >> 4)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 5)) >> 5)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 6)) >> 6)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 7)) >> 7)<<3);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 8)) >> 8)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 9)) >> 9)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 10)) >> 10)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 11)) >> 11)<<7);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [0] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 12)) >> 12)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [0] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 13)) >> 13)<<1);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 18 ------------------
       *  startBit                = 7
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (COMM_subsystem_integrated_B.Decs_Steering_Req);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [0] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 19 ------------------
       *  startBit                = 56
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_EmergencyLightRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 20 ------------------
       *  startBit                = 44
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (COMM_subsystem_integrated_B.Decs_iBCM_Req);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<4);
                }
              }
            }
          }
        }
      }
    }

    /* End of Outputs for SubSystem: '<S2>/iVISTA New' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S2>/ICPV New' incorporates:
     *  ActionPort: '<S41>/Action Port'
     */
    /* Abs: '<S41>/Abs' */
    COMM_subsystem_integrated_B.Abs = (real32_T)fabs((real_T)
      VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringAngleValue);

    /* Switch: '<S41>/Switch' incorporates:
     *  Constant: '<S41>/Constant'
     *  Constant: '<S41>/Constant1'
     */
    if (VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringAngleValue > 0.0F)
    {
      COMM_subsystem_integrated_B.Switch = true;
    }
    else
    {
      COMM_subsystem_integrated_B.Switch = false;
    }

    /* End of Switch: '<S41>/Switch' */

    /* DataTypeConversion: '<S41>/Data Type Conversion15' */
    COMM_subsystem_integrated_B.DataTypeConversion15 = (uint32_T)
      VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringAngleSpeed;

    /* S-Function (scanpack): '<S41>/Config_3_Transmit_CAN_0_ID_581' incorporates:
     *  Constant: '<S41>/Constant11'
     */
    /* S-Function (scanpack): '<S41>/Config_3_Transmit_CAN_0_ID_581' */
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.ID = 581U;
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Length = 8U;
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Extended = 0U;
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Remote = 0;
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data[0] = 0;
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data[1] = 0;
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data[2] = 0;
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data[3] = 0;
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data[4] = 0;
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data[5] = 0;
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data[6] = 0;
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 48
       *  length                  = 8
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (COMM_subsystem_integrate_ConstB.DataTypeConversion8);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (uint8_T)(255))
              {
                packedValue = (uint8_T) 255;
              }
              else if (packingValue < (uint8_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [6] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [6] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [6] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [6] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [6] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [6] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [6] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [6] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 3)) >> 3)<<3);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [6] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [6] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 4)) >> 4)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [6] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [6] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 5)) >> 5)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [6] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [6] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 6)) >> 6)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [6] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [6] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 7)) >> 7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 42
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T) (COMM_subsystem_integrated_B.Switch);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<2);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 2 ------------------
       *  startBit                = 40
       *  length                  = 2
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringAngleEnable);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(3))
              {
                packedValue = (uint8_T) 3;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<1);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 3 ------------------
       *  startBit                = 56
       *  length                  = 8
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (COMM_subsystem_integrate_ConstB.DataTypeConversion16);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (uint8_T)(255))
              {
                packedValue = (uint8_T) 255;
              }
              else if (packingValue < (uint8_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 3)) >> 3)<<3);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 4)) >> 4)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 5)) >> 5)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 6)) >> 6)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 7)) >> 7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 4 ------------------
       *  startBit                = 9
       *  length                  = 15
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 0.1
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real32_T outValue = 0;

          {
            real32_T result = COMM_subsystem_integrated_B.Abs;

            /* no offset to apply */
            result = result / 0.1F;
            outValue = result;
          }

          {
            {
              uint16_T packedValue;
              if (outValue > (real32_T)(32767))
              {
                packedValue = (uint16_T) 32767;
              }
              else if (outValue < (real32_T)(0))
              {
                packedValue = (uint16_T) 0;
              }
              else
              {
                packedValue = (uint16_T) (outValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 0)) >> 0)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 1)) >> 1)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 2)) >> 2)<<3);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 3)) >> 3)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 4)) >> 4)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 5)) >> 5)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 6)) >> 6)<<7);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [0] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 7)) >> 7)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [0] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 8)) >> 8)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [0] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 9)) >> 9)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [0] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 10)) >> 10)<<3);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [0] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 11)) >> 11)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [0] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 12)) >> 12)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [0] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 13)) >> 13)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [0] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 14)) >> 14)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 5 ------------------
       *  startBit                = 26
       *  length                  = 15
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 0.1
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real32_T outValue = 0;

          {
            real32_T result = 500.0F;

            /* no offset to apply */
            result = result / 0.1F;
            outValue = result;
          }

          {
            {
              uint16_T packedValue;
              if (outValue > (real32_T)(32767))
              {
                packedValue = (uint16_T) 32767;
              }
              else if (outValue < (real32_T)(0))
              {
                packedValue = (uint16_T) 0;
              }
              else
              {
                packedValue = (uint16_T) (outValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [3] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 0)) >> 0)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [3] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 1)) >> 1)<<3);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [3] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 2)) >> 2)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [3] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 3)) >> 3)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [3] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 4)) >> 4)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [3] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 5)) >> 5)<<7);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [2] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 6)) >> 6)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [2] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 7)) >> 7)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [2] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 8)) >> 8)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [2] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 9)) >> 9)<<3);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [2] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 10)) >> 10)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [2] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 11)) >> 11)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [2] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 12)) >> 12)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [2] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 13)) >> 13)<<7);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [1] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 14)) >> 14)<<0);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 6 ------------------
       *  startBit                = 43
       *  length                  = 15
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 4.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (COMM_subsystem_integrated_B.DataTypeConversion15);

            /* no offset to apply */
            result = (uint32_T) (result / 4U);
            packingValue = result;
          }

          {
            {
              uint16_T packedValue;
              if (packingValue > (uint32_T)(32767))
              {
                packedValue = (uint16_T) 32767;
              }
              else if (packingValue < (uint32_T)(0))
              {
                packedValue = (uint16_T) 0;
              }
              else
              {
                packedValue = (uint16_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [5] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 0)) >> 0)<<3);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [5] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 1)) >> 1)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [5] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 2)) >> 2)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [5] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 3)) >> 3)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [5] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 4)) >> 4)<<7);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [4] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 5)) >> 5)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [4] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 6)) >> 6)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [4] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 7)) >> 7)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [4] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 8)) >> 8)<<3);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [4] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 9)) >> 9)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [4] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 10)) >> 10)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [4] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 11)) >> 11)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [4] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 12)) >> 12)<<7);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [3] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 13)) >> 13)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581.Data
                    [3] | (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 14)) >> 14)<<1);
                }
              }
            }
          }
        }
      }
    }

    /* SwitchCase: '<S41>/Switch Case' */
    switch (VsCOMM_CANT_Databus.COMM_TX_Transmission.ADCU_TargetGearValue)
    {
     case 13:
      /* Outputs for IfAction SubSystem: '<S41>/GearR' incorporates:
       *  ActionPort: '<S65>/Action Port'
       */
      /* SignalConversion: '<S65>/OutportBufferForOut1' incorporates:
       *  Constant: '<S65>/Constant'
       */
      COMM_subsystem_integrated_B.veh_Gear_Value_des = ((uint8_T)2U);

      /* End of Outputs for SubSystem: '<S41>/GearR' */
      break;

     case 0:
      /* Outputs for IfAction SubSystem: '<S41>/GearN' incorporates:
       *  ActionPort: '<S63>/Action Port'
       */
      COMM_subsystem_integrated_GearN
        (&COMM_subsystem_integrated_B.veh_Gear_Value_des);

      /* End of Outputs for SubSystem: '<S41>/GearN' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S41>/GearD' incorporates:
       *  ActionPort: '<S62>/Action Port'
       */
      /* SignalConversion: '<S62>/OutportBufferForOut1' incorporates:
       *  Constant: '<S62>/Constant'
       */
      COMM_subsystem_integrated_B.veh_Gear_Value_des = ((uint8_T)4U);

      /* End of Outputs for SubSystem: '<S41>/GearD' */
      break;

     case 14:
      /* Outputs for IfAction SubSystem: '<S41>/GearP' incorporates:
       *  ActionPort: '<S64>/Action Port'
       */
      /* SignalConversion: '<S64>/OutportBufferForOut1' incorporates:
       *  Constant: '<S64>/Constant'
       */
      COMM_subsystem_integrated_B.veh_Gear_Value_des = ((uint8_T)1U);

      /* End of Outputs for SubSystem: '<S41>/GearP' */
      break;

     default:
      /* Outputs for IfAction SubSystem: '<S41>/default' incorporates:
       *  ActionPort: '<S66>/Action Port'
       */
      COMM_subsystem_integrated_GearN
        (&COMM_subsystem_integrated_B.veh_Gear_Value_des);

      /* End of Outputs for SubSystem: '<S41>/default' */
      break;
    }

    /* End of SwitchCase: '<S41>/Switch Case' */

    /* SwitchCase: '<S41>/Switch Case1' incorporates:
     *  Inport: '<Root>/VsARBT_DataBus'
     */
    switch (VsARBT_DataBus.AccessoryGroup.epb_control_mode)
    {
     case 0:
      /* Outputs for IfAction SubSystem: '<S41>/EPB_released' incorporates:
       *  ActionPort: '<S60>/Action Port'
       */
      /* Sum: '<S60>/Add' incorporates:
       *  Constant: '<S60>/Constant1'
       *  Gain: '<S60>/Gain'
       *  UnitDelay: '<S41>/Unit Delay1'
       */
      u1 = VfCOMM_max_gas_pedal_EPB + (0.05F * KcCOMM_GasPedalRampEPB);

      /* MinMax: '<S60>/Min' incorporates:
       *  Constant: '<S60>/Constant4'
       */
      if ((KcCOMM_GasPedalMax < u1) || (rtIsNaNF(u1)))
      {
        VfCOMM_max_gas_pedal_EPB = KcCOMM_GasPedalMax;
      }
      else
      {
        VfCOMM_max_gas_pedal_EPB = u1;
      }

      /* End of MinMax: '<S60>/Min' */
      /* End of Outputs for SubSystem: '<S41>/EPB_released' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S41>/EPB_clamped' incorporates:
       *  ActionPort: '<S59>/Action Port'
       */
      /* SignalConversion: '<S59>/OutportBufferForout' incorporates:
       *  Constant: '<S59>/Constant4'
       */
      VfCOMM_max_gas_pedal_EPB = KcCOMM_GasPedalMinEPB;

      /* End of Outputs for SubSystem: '<S41>/EPB_clamped' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S41>/EPB_releasing' incorporates:
       *  ActionPort: '<S61>/Action Port'
       */
      /* Sum: '<S61>/Add' incorporates:
       *  Constant: '<S61>/Constant1'
       *  Gain: '<S61>/Gain'
       *  UnitDelay: '<S41>/Unit Delay'
       */
      u1 = VfCOMM_max_gas_pedal_EPB + (0.01F * KcCOMM_GasPedalRampEPB);

      /* MinMax: '<S61>/Min' incorporates:
       *  Constant: '<S61>/Constant4'
       */
      if ((KcCOMM_GasPedalMaxEPB < u1) || (rtIsNaNF(u1)))
      {
        VfCOMM_max_gas_pedal_EPB = KcCOMM_GasPedalMaxEPB;
      }
      else
      {
        VfCOMM_max_gas_pedal_EPB = u1;
      }

      /* End of MinMax: '<S61>/Min' */
      /* End of Outputs for SubSystem: '<S41>/EPB_releasing' */
      break;

     default:
      /* no actions */
      break;
    }

    /* End of SwitchCase: '<S41>/Switch Case1' */

    /* Sum: '<S41>/Add' incorporates:
     *  Constant: '<S41>/Constant2'
     *  Constant: '<S41>/Constant4'
     *  Gain: '<S41>/Gain1'
     *  Product: '<S41>/Product2'
     *  Sum: '<S41>/Add2'
     */
    u1 = ((0.01F * VsCOMM_CANT_Databus.COMM_TX_Power.ADCU_PowerTorqueValue) *
          (KcCOMM_GasPedalMax - KcCOMM_GasPedalMin)) + KcCOMM_GasPedalMin;

    /* MinMax: '<S41>/Min' */
    if ((VfCOMM_max_gas_pedal_EPB < u1) || (rtIsNaNF(u1)))
    {
      u1 = VfCOMM_max_gas_pedal_EPB;
    }

    /* End of MinMax: '<S41>/Min' */

    /* DataTypeConversion: '<S41>/Data Type Conversion13' incorporates:
     *  Product: '<S41>/Product'
     */
    COMM_subsystem_integrated_B.DataTypeConversion13 = (uint8_T)((real32_T)(u1 *
      ((real32_T)(VsCOMM_CANT_Databus.COMM_TX_Power.ADCU_PowerEnable ? 1.0F :
                  0.0F))));

    /* Sum: '<S41>/Subtract1' incorporates:
     *  Constant: '<S41>/Constant8'
     */
    COMM_subsystem_integrated_B.Subtract1 = (uint8_T)(((uint8_T)100U) -
      COMM_subsystem_integrated_B.DataTypeConversion13);

    /* DataTypeConversion: '<S41>/Data Type Conversion11' incorporates:
     *  Constant: '<S41>/Constant6'
     *  Constant: '<S41>/Constant9'
     *  Gain: '<S41>/Gain'
     *  Product: '<S41>/Product1'
     *  Product: '<S41>/Product3'
     *  Sum: '<S41>/Add1'
     *  Sum: '<S41>/Add3'
     */
    COMM_subsystem_integrated_B.DataTypeConversion11 = (uint8_T)((real32_T)
      ((((0.01F * VsCOMM_CANT_Databus.COMM_TX_Brake.ADCU_BrakePressureValue) *
         (KcCOMM_BrakePedalMax - KcCOMM_BrakePedalMin)) + KcCOMM_BrakePedalMin) *
       ((real32_T)(VsCOMM_CANT_Databus.COMM_TX_Brake.ADCU_BrakeEnable ? 1.0F :
                   0.0F))));

    /* Sum: '<S41>/Subtract' incorporates:
     *  Constant: '<S41>/Constant7'
     */
    COMM_subsystem_integrated_B.Subtract = (uint8_T)(((uint8_T)100U) -
      COMM_subsystem_integrated_B.DataTypeConversion11);

    /* Switch: '<S41>/Switch1' incorporates:
     *  Constant: '<S41>/Constant3'
     *  Constant: '<S41>/Constant5'
     */
    if (VsCOMM_CANT_Databus.COMM_TX_Parking.ADCU_ParkingControlValue > ((uint8_T)
         0U))
    {
      COMM_subsystem_integrated_B.Switch1 = ((uint8_T)1U);
    }
    else
    {
      COMM_subsystem_integrated_B.Switch1 = ((uint8_T)2U);
    }

    /* End of Switch: '<S41>/Switch1' */

    /* DataTypeConversion: '<S41>/Data Type Conversion1' */
    COMM_subsystem_integrated_B.DataTypeConversion1 =
      VsCOMM_CANT_Databus.COMM_TX_Parking.ADCU_ParkingControlEnable ? 1U : 0U;

    /* S-Function (scanpack): '<S41>/Config_3_Transmit_CAN_1_ID_550' incorporates:
     *  Constant: '<S41>/Constant10'
     */
    /* S-Function (scanpack): '<S41>/Config_3_Transmit_CAN_1_ID_550' */
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.ID = 550U;
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Length = 8U;
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Extended = 0U;
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Remote = 0;
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data[0] = 0;
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data[1] = 0;
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data[2] = 0;
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data[3] = 0;
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data[4] = 0;
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data[5] = 0;
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data[6] = 0;
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 62
       *  length                  = 2
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_AutodriveMode.ADCU_AutodriveEnable);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(3))
              {
                packedValue = (uint8_T) 3;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 42
       *  length                  = 2
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_Power.ADCU_PowerEnable);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(3))
              {
                packedValue = (uint8_T) 3;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<3);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 2 ------------------
       *  startBit                = 0
       *  length                  = 8
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (COMM_subsystem_integrated_B.DataTypeConversion13);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (uint8_T)(255))
              {
                packedValue = (uint8_T) 255;
              }
              else if (packingValue < (uint8_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [0] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [0] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [0] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [0] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 3)) >> 3)<<3);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [0] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 4)) >> 4)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [0] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 5)) >> 5)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [0] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 6)) >> 6)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [0] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [0] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 7)) >> 7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 3 ------------------
       *  startBit                = 8
       *  length                  = 8
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T) (COMM_subsystem_integrated_B.Subtract1);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (uint8_T)(255))
              {
                packedValue = (uint8_T) 255;
              }
              else if (packingValue < (uint8_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [1] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [1] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [1] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [1] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 3)) >> 3)<<3);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [1] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 4)) >> 4)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [1] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 5)) >> 5)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [1] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 6)) >> 6)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [1] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [1] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 7)) >> 7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 4 ------------------
       *  startBit                = 44
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_BrakeLightRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<4);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 5 ------------------
       *  startBit                = 40
       *  length                  = 2
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_Brake.ADCU_BrakeEnable);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(3))
              {
                packedValue = (uint8_T) 3;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<1);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 6 ------------------
       *  startBit                = 16
       *  length                  = 8
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (COMM_subsystem_integrated_B.DataTypeConversion11);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (uint8_T)(255))
              {
                packedValue = (uint8_T) 255;
              }
              else if (packingValue < (uint8_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [2] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [2] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [2] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [2] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 3)) >> 3)<<3);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [2] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 4)) >> 4)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [2] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 5)) >> 5)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [2] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 6)) >> 6)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [2] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [2] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 7)) >> 7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 7 ------------------
       *  startBit                = 24
       *  length                  = 8
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T) (COMM_subsystem_integrated_B.Subtract);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (uint8_T)(255))
              {
                packedValue = (uint8_T) 255;
              }
              else if (packingValue < (uint8_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 3)) >> 3)<<3);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 4)) >> 4)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 5)) >> 5)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 6)) >> 6)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [3] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [3] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 7)) >> 7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 8 ------------------
       *  startBit                = 32
       *  length                  = 8
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T) (((uint8_T)0U));

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (uint8_T)(255))
              {
                packedValue = (uint8_T) 255;
              }
              else if (packingValue < (uint8_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 3)) >> 3)<<3);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 4)) >> 4)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 5)) >> 5)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 6)) >> 6)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [4] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [4] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 7)) >> 7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 9 ------------------
       *  startBit                = 45
       *  length                  = 3
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (COMM_subsystem_integrated_B.veh_Gear_Value_des);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (uint8_T)(7))
              {
                packedValue = (uint8_T) 7;
              }
              else if (packingValue < (uint8_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [5] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [5] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 10 ------------------
       *  startBit                = 60
       *  length                  = 2
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_Transmission.ADCU_TargetGearEnable);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(3))
              {
                packedValue = (uint8_T) 3;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<5);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 11 ------------------
       *  startBit                = 48
       *  length                  = 8
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T) (COMM_subsystem_integrated_B.Switch1);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (uint8_T)(255))
              {
                packedValue = (uint8_T) 255;
              }
              else if (packingValue < (uint8_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [6] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [6] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [6] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [6] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [6] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [6] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [6] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [6] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 3)) >> 3)<<3);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [6] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [6] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 4)) >> 4)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [6] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [6] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 5)) >> 5)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [6] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [6] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 6)) >> 6)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [6] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [6] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 7)) >> 7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 12 ------------------
       *  startBit                = 56
       *  length                  = 4
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (COMM_subsystem_integrated_B.DataTypeConversion1);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (uint8_T)(15))
              {
                packedValue = (uint8_T) 15;
              }
              else if (packingValue < (uint8_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [7] =
                    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550.Data
                    [7] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 3)) >> 3)<<3);
                }
              }
            }
          }
        }
      }
    }

    /* End of Outputs for SubSystem: '<S2>/ICPV New' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S2>/BUS New' incorporates:
     *  ActionPort: '<S37>/Action Port'
     */
    /* DataTypeConversion: '<S37>/Data Type Conversion9' */
    COMM_subsystem_integrated_B.DataTypeConversion9 = (((int32_T)
      VsCOMM_CANT_Databus.COMM_TX_Parking.ADCU_ParkingControlValue) != 0);

    /* S-Function (scanpack): '<S37>/EBS_Control' incorporates:
     *  Constant: '<S37>/XBR_EBI_mode'
     *  Constant: '<S37>/XBR_Priority'
     */
    /* S-Function (scanpack): '<S37>/EBS_Control' */
    COMM_subsystem_integrated_B.EBS_Control.ID = 201591594U;
    COMM_subsystem_integrated_B.EBS_Control.Length = 8U;
    COMM_subsystem_integrated_B.EBS_Control.Extended = 1U;
    COMM_subsystem_integrated_B.EBS_Control.Remote = 0;
    COMM_subsystem_integrated_B.EBS_Control.Data[0] = 0;
    COMM_subsystem_integrated_B.EBS_Control.Data[1] = 0;
    COMM_subsystem_integrated_B.EBS_Control.Data[2] = 0;
    COMM_subsystem_integrated_B.EBS_Control.Data[3] = 0;
    COMM_subsystem_integrated_B.EBS_Control.Data[4] = 0;
    COMM_subsystem_integrated_B.EBS_Control.Data[5] = 0;
    COMM_subsystem_integrated_B.EBS_Control.Data[6] = 0;
    COMM_subsystem_integrated_B.EBS_Control.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 20
       *  length                  = 2
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_Brake.ADCU_BrakeEnable);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(3))
              {
                packedValue = (uint8_T) 3;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.EBS_Control.Data[2] =
                    COMM_subsystem_integrated_B.EBS_Control.Data[2] | (uint8_T)
                    ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                        0)) >> 0)<<4);
                }

                {
                  COMM_subsystem_integrated_B.EBS_Control.Data[2] =
                    COMM_subsystem_integrated_B.EBS_Control.Data[2] | (uint8_T)
                    ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                        1)) >> 1)<<5);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 16
       *  length                  = 2
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T) (((uint8_T)3U));

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (uint8_T)(3))
              {
                packedValue = (uint8_T) 3;
              }
              else if (packingValue < (uint8_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.EBS_Control.Data[2] =
                    COMM_subsystem_integrated_B.EBS_Control.Data[2] | (uint8_T)
                    ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                        0)) >> 0)<<0);
                }

                {
                  COMM_subsystem_integrated_B.EBS_Control.Data[2] =
                    COMM_subsystem_integrated_B.EBS_Control.Data[2] | (uint8_T)
                    ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                        1)) >> 1)<<1);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 2 ------------------
       *  startBit                = 0
       *  length                  = 16
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 0.000488
       *  offset                  = -15.687
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real32_T outValue = 0;

          {
            real32_T result =
              VsCOMM_CANT_Databus.COMM_TX_Brake.ADCU_BrakeDecelValue;

            /* full scaling operation */
            result = (result - -15.687F) / 0.000488F;
            outValue = result;
          }

          {
            {
              uint16_T packedValue;
              if (outValue > (real32_T)(65535))
              {
                packedValue = (uint16_T) 65535;
              }
              else if (outValue < (real32_T)(0))
              {
                packedValue = (uint16_T) 0;
              }
              else
              {
                packedValue = (uint16_T) (outValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.EBS_Control.Data[0] =
                    COMM_subsystem_integrated_B.EBS_Control.Data[0] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 0)) >> 0)<<0);
                }

                {
                  COMM_subsystem_integrated_B.EBS_Control.Data[0] =
                    COMM_subsystem_integrated_B.EBS_Control.Data[0] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 1)) >> 1)<<1);
                }

                {
                  COMM_subsystem_integrated_B.EBS_Control.Data[0] =
                    COMM_subsystem_integrated_B.EBS_Control.Data[0] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 2)) >> 2)<<2);
                }

                {
                  COMM_subsystem_integrated_B.EBS_Control.Data[0] =
                    COMM_subsystem_integrated_B.EBS_Control.Data[0] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 3)) >> 3)<<3);
                }

                {
                  COMM_subsystem_integrated_B.EBS_Control.Data[0] =
                    COMM_subsystem_integrated_B.EBS_Control.Data[0] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 4)) >> 4)<<4);
                }

                {
                  COMM_subsystem_integrated_B.EBS_Control.Data[0] =
                    COMM_subsystem_integrated_B.EBS_Control.Data[0] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 5)) >> 5)<<5);
                }

                {
                  COMM_subsystem_integrated_B.EBS_Control.Data[0] =
                    COMM_subsystem_integrated_B.EBS_Control.Data[0] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 6)) >> 6)<<6);
                }

                {
                  COMM_subsystem_integrated_B.EBS_Control.Data[0] =
                    COMM_subsystem_integrated_B.EBS_Control.Data[0] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 7)) >> 7)<<7);
                }

                {
                  COMM_subsystem_integrated_B.EBS_Control.Data[1] =
                    COMM_subsystem_integrated_B.EBS_Control.Data[1] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 8)) >> 8)<<0);
                }

                {
                  COMM_subsystem_integrated_B.EBS_Control.Data[1] =
                    COMM_subsystem_integrated_B.EBS_Control.Data[1] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 9)) >> 9)<<1);
                }

                {
                  COMM_subsystem_integrated_B.EBS_Control.Data[1] =
                    COMM_subsystem_integrated_B.EBS_Control.Data[1] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 10)) >> 10)<<2);
                }

                {
                  COMM_subsystem_integrated_B.EBS_Control.Data[1] =
                    COMM_subsystem_integrated_B.EBS_Control.Data[1] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 11)) >> 11)<<3);
                }

                {
                  COMM_subsystem_integrated_B.EBS_Control.Data[1] =
                    COMM_subsystem_integrated_B.EBS_Control.Data[1] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 12)) >> 12)<<4);
                }

                {
                  COMM_subsystem_integrated_B.EBS_Control.Data[1] =
                    COMM_subsystem_integrated_B.EBS_Control.Data[1] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 13)) >> 13)<<5);
                }

                {
                  COMM_subsystem_integrated_B.EBS_Control.Data[1] =
                    COMM_subsystem_integrated_B.EBS_Control.Data[1] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 14)) >> 14)<<6);
                }

                {
                  COMM_subsystem_integrated_B.EBS_Control.Data[1] =
                    COMM_subsystem_integrated_B.EBS_Control.Data[1] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 15)) >> 15)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 3 ------------------
       *  startBit                = 18
       *  length                  = 2
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T) (((uint8_T)0U));

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (uint8_T)(3))
              {
                packedValue = (uint8_T) 3;
              }
              else if (packingValue < (uint8_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.EBS_Control.Data[2] =
                    COMM_subsystem_integrated_B.EBS_Control.Data[2] | (uint8_T)
                    ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                        0)) >> 0)<<2);
                }

                {
                  COMM_subsystem_integrated_B.EBS_Control.Data[2] =
                    COMM_subsystem_integrated_B.EBS_Control.Data[2] | (uint8_T)
                    ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                        1)) >> 1)<<3);
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanpack): '<S37>/Low_Voltage_Distribution_Control' */
    /* S-Function (scanpack): '<S37>/Low_Voltage_Distribution_Control' */
    COMM_subsystem_integrated_B.Low_Voltage_Distribution_Contro.ID = 201439175U;
    COMM_subsystem_integrated_B.Low_Voltage_Distribution_Contro.Length = 8U;
    COMM_subsystem_integrated_B.Low_Voltage_Distribution_Contro.Extended = 1U;
    COMM_subsystem_integrated_B.Low_Voltage_Distribution_Contro.Remote = 0;
    COMM_subsystem_integrated_B.Low_Voltage_Distribution_Contro.Data[0] = 0;
    COMM_subsystem_integrated_B.Low_Voltage_Distribution_Contro.Data[1] = 0;
    COMM_subsystem_integrated_B.Low_Voltage_Distribution_Contro.Data[2] = 0;
    COMM_subsystem_integrated_B.Low_Voltage_Distribution_Contro.Data[3] = 0;
    COMM_subsystem_integrated_B.Low_Voltage_Distribution_Contro.Data[4] = 0;
    COMM_subsystem_integrated_B.Low_Voltage_Distribution_Contro.Data[5] = 0;
    COMM_subsystem_integrated_B.Low_Voltage_Distribution_Contro.Data[6] = 0;
    COMM_subsystem_integrated_B.Low_Voltage_Distribution_Contro.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 2
       *  length                  = 1
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_BrakeLightRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Low_Voltage_Distribution_Contro.Data
                    [0] =
                    COMM_subsystem_integrated_B.Low_Voltage_Distribution_Contro.Data
                    [0] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<2);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 0
       *  length                  = 1
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_LeftTurningLightRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Low_Voltage_Distribution_Contro.Data
                    [0] =
                    COMM_subsystem_integrated_B.Low_Voltage_Distribution_Contro.Data
                    [0] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 2 ------------------
       *  startBit                = 1
       *  length                  = 1
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_RightTurningLightRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Low_Voltage_Distribution_Contro.Data
                    [0] =
                    COMM_subsystem_integrated_B.Low_Voltage_Distribution_Contro.Data
                    [0] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<1);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 3 ------------------
       *  startBit                = 3
       *  length                  = 1
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_HornRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Low_Voltage_Distribution_Contro.Data
                    [0] =
                    COMM_subsystem_integrated_B.Low_Voltage_Distribution_Contro.Data
                    [0] | (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<3);
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanpack): '<S37>/Vehicle_Control' */
    /* S-Function (scanpack): '<S37>/Vehicle_Control' */
    COMM_subsystem_integrated_B.Vehicle_Control.ID = 201504711U;
    COMM_subsystem_integrated_B.Vehicle_Control.Length = 8U;
    COMM_subsystem_integrated_B.Vehicle_Control.Extended = 1U;
    COMM_subsystem_integrated_B.Vehicle_Control.Remote = 0;
    COMM_subsystem_integrated_B.Vehicle_Control.Data[0] = 0;
    COMM_subsystem_integrated_B.Vehicle_Control.Data[1] = 0;
    COMM_subsystem_integrated_B.Vehicle_Control.Data[2] = 0;
    COMM_subsystem_integrated_B.Vehicle_Control.Data[3] = 0;
    COMM_subsystem_integrated_B.Vehicle_Control.Data[4] = 0;
    COMM_subsystem_integrated_B.Vehicle_Control.Data[5] = 0;
    COMM_subsystem_integrated_B.Vehicle_Control.Data[6] = 0;
    COMM_subsystem_integrated_B.Vehicle_Control.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 1
       *  length                  = 3
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_Brake.ADCU_BrakePrechargeRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(7))
              {
                packedValue = (uint8_T) 7;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Vehicle_Control.Data[0] =
                    COMM_subsystem_integrated_B.Vehicle_Control.Data[0] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Vehicle_Control.Data[0] =
                    COMM_subsystem_integrated_B.Vehicle_Control.Data[0] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Vehicle_Control.Data[0] =
                    COMM_subsystem_integrated_B.Vehicle_Control.Data[0] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<3);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 4
       *  length                  = 1
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_Brake.ADCU_BrakeEnable);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Vehicle_Control.Data[0] =
                    COMM_subsystem_integrated_B.Vehicle_Control.Data[0] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<4);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 2 ------------------
       *  startBit                = 0
       *  length                  = 1
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (COMM_subsystem_integrated_B.DataTypeConversion9);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Vehicle_Control.Data[0] =
                    COMM_subsystem_integrated_B.Vehicle_Control.Data[0] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 3 ------------------
       *  startBit                = 8
       *  length                  = 16
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real32_T outValue = 0;

          {
            real32_T result =
              VsCOMM_CANT_Databus.COMM_TX_HMI.ADCU_TargetVehicleSpeed;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              uint16_T packedValue;
              if (outValue > (real32_T)(65535))
              {
                packedValue = (uint16_T) 65535;
              }
              else if (outValue < (real32_T)(0))
              {
                packedValue = (uint16_T) 0;
              }
              else
              {
                packedValue = (uint16_T) (outValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.Vehicle_Control.Data[1] =
                    COMM_subsystem_integrated_B.Vehicle_Control.Data[1] |
                    (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 0)) >> 0)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Vehicle_Control.Data[1] =
                    COMM_subsystem_integrated_B.Vehicle_Control.Data[1] |
                    (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 1)) >> 1)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Vehicle_Control.Data[1] =
                    COMM_subsystem_integrated_B.Vehicle_Control.Data[1] |
                    (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 2)) >> 2)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Vehicle_Control.Data[1] =
                    COMM_subsystem_integrated_B.Vehicle_Control.Data[1] |
                    (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 3)) >> 3)<<3);
                }

                {
                  COMM_subsystem_integrated_B.Vehicle_Control.Data[1] =
                    COMM_subsystem_integrated_B.Vehicle_Control.Data[1] |
                    (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 4)) >> 4)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Vehicle_Control.Data[1] =
                    COMM_subsystem_integrated_B.Vehicle_Control.Data[1] |
                    (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 5)) >> 5)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Vehicle_Control.Data[1] =
                    COMM_subsystem_integrated_B.Vehicle_Control.Data[1] |
                    (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 6)) >> 6)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Vehicle_Control.Data[1] =
                    COMM_subsystem_integrated_B.Vehicle_Control.Data[1] |
                    (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 7)) >> 7)<<7);
                }

                {
                  COMM_subsystem_integrated_B.Vehicle_Control.Data[2] =
                    COMM_subsystem_integrated_B.Vehicle_Control.Data[2] |
                    (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 8)) >> 8)<<0);
                }

                {
                  COMM_subsystem_integrated_B.Vehicle_Control.Data[2] =
                    COMM_subsystem_integrated_B.Vehicle_Control.Data[2] |
                    (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 9)) >> 9)<<1);
                }

                {
                  COMM_subsystem_integrated_B.Vehicle_Control.Data[2] =
                    COMM_subsystem_integrated_B.Vehicle_Control.Data[2] |
                    (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 10)) >> 10)<<2);
                }

                {
                  COMM_subsystem_integrated_B.Vehicle_Control.Data[2] =
                    COMM_subsystem_integrated_B.Vehicle_Control.Data[2] |
                    (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 11)) >> 11)<<3);
                }

                {
                  COMM_subsystem_integrated_B.Vehicle_Control.Data[2] =
                    COMM_subsystem_integrated_B.Vehicle_Control.Data[2] |
                    (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 12)) >> 12)<<4);
                }

                {
                  COMM_subsystem_integrated_B.Vehicle_Control.Data[2] =
                    COMM_subsystem_integrated_B.Vehicle_Control.Data[2] |
                    (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 13)) >> 13)<<5);
                }

                {
                  COMM_subsystem_integrated_B.Vehicle_Control.Data[2] =
                    COMM_subsystem_integrated_B.Vehicle_Control.Data[2] |
                    (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 14)) >> 14)<<6);
                }

                {
                  COMM_subsystem_integrated_B.Vehicle_Control.Data[2] =
                    COMM_subsystem_integrated_B.Vehicle_Control.Data[2] |
                    (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                    (((uint16_T)(1)) << 15)) >> 15)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* End of Outputs for SubSystem: '<S2>/BUS New' */
    break;

   case 7:
    /* Outputs for IfAction SubSystem: '<S2>/USdemo New' incorporates:
     *  ActionPort: '<S43>/Action Port'
     */
    /* Gain: '<S43>/Gain' */
    COMM_subsystem_integrated_B.Gain = (-1.0F) *
      VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringAngleValue;

    /* Gain: '<S43>/Gain1' */
    COMM_subsystem_integrated_B.Gain1 = 3.6F *
      VsCOMM_CANT_Databus.COMM_TX_HMI.ADCU_TargetVehicleSpeed;

    /* S-Function (scanpack): '<S43>/CAN_Pack' */
    /* S-Function (scanpack): '<S43>/CAN_Pack' */
    COMM_subsystem_integrated_B.CAN_Pack.ID = 1586U;
    COMM_subsystem_integrated_B.CAN_Pack.Length = 8U;
    COMM_subsystem_integrated_B.CAN_Pack.Extended = 0U;
    COMM_subsystem_integrated_B.CAN_Pack.Remote = 0;
    COMM_subsystem_integrated_B.CAN_Pack.Data[0] = 0;
    COMM_subsystem_integrated_B.CAN_Pack.Data[1] = 0;
    COMM_subsystem_integrated_B.CAN_Pack.Data[2] = 0;
    COMM_subsystem_integrated_B.CAN_Pack.Data[3] = 0;
    COMM_subsystem_integrated_B.CAN_Pack.Data[4] = 0;
    COMM_subsystem_integrated_B.CAN_Pack.Data[5] = 0;
    COMM_subsystem_integrated_B.CAN_Pack.Data[6] = 0;
    COMM_subsystem_integrated_B.CAN_Pack.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 48
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringAngleEnable);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[6] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[6] | (uint8_T)
                    ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                        0)) >> 0)<<0);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 41
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_LeftTurningLightRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[5] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[5] | (uint8_T)
                    ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                        0)) >> 0)<<1);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 2 ------------------
       *  startBit                = 32
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_HMI.ADCU_OverSpeedWarning);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[4] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[4] | (uint8_T)
                    ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                        0)) >> 0)<<0);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 3 ------------------
       *  startBit                = 40
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_RightTurningLightRequest);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[5] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[5] | (uint8_T)
                    ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                        0)) >> 0)<<0);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 4 ------------------
       *  startBit                = 56
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_HMI.ADCU_SpeedDownIndicator);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[7] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[7] | (uint8_T)
                    ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                        0)) >> 0)<<0);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 5 ------------------
       *  startBit                = 57
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T)
              (VsCOMM_CANT_Databus.COMM_TX_HMI.ADCU_SpeedUpIndicator);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (boolean_T)(1))
              {
                packedValue = (uint8_T) 1;
              }
              else if (packingValue < (boolean_T)(0))
              {
                packedValue = (uint8_T) 0;
              }
              else
              {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[7] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[7] | (uint8_T)
                    ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                        0)) >> 0)<<1);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 6 ------------------
       *  startBit                = 24
       *  length                  = 14
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 0.1
       *  offset                  = -550.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real32_T outValue = 0;

          {
            real32_T result = COMM_subsystem_integrated_B.Gain;

            /* full scaling operation */
            result = (result - -550.0F) / 0.1F;
            outValue = result;
          }

          {
            {
              uint16_T packedValue;
              if (outValue > (real32_T)(16383))
              {
                packedValue = (uint16_T) 16383;
              }
              else if (outValue < (real32_T)(0))
              {
                packedValue = (uint16_T) 0;
              }
              else
              {
                packedValue = (uint16_T) (outValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[3] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[3] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 0)) >> 0)<<0);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[3] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[3] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 1)) >> 1)<<1);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[3] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[3] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 2)) >> 2)<<2);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[3] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[3] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 3)) >> 3)<<3);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[3] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[3] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 4)) >> 4)<<4);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[3] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[3] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 5)) >> 5)<<5);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[3] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[3] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 6)) >> 6)<<6);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[3] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[3] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 7)) >> 7)<<7);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[2] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[2] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 8)) >> 8)<<0);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[2] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[2] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 9)) >> 9)<<1);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[2] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[2] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 10)) >> 10)<<2);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[2] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[2] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 11)) >> 11)<<3);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[2] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[2] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 12)) >> 12)<<4);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[2] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[2] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 13)) >> 13)<<5);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 7 ------------------
       *  startBit                = 8
       *  length                  = 16
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 0.0078125
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real32_T outValue = 0;

          {
            real32_T result = COMM_subsystem_integrated_B.Gain1;

            /* no offset to apply */
            result = result / 0.0078125F;
            outValue = result;
          }

          {
            {
              uint16_T packedValue;
              if (outValue > (real32_T)(65535))
              {
                packedValue = (uint16_T) 65535;
              }
              else if (outValue < (real32_T)(0))
              {
                packedValue = (uint16_T) 0;
              }
              else
              {
                packedValue = (uint16_T) (outValue);
              }

              {
                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[1] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[1] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 0)) >> 0)<<0);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[1] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[1] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 1)) >> 1)<<1);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[1] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[1] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 2)) >> 2)<<2);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[1] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[1] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 3)) >> 3)<<3);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[1] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[1] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 4)) >> 4)<<4);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[1] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[1] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 5)) >> 5)<<5);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[1] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[1] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 6)) >> 6)<<6);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[1] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[1] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 7)) >> 7)<<7);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[0] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[0] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 8)) >> 8)<<0);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[0] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[0] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 9)) >> 9)<<1);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[0] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[0] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 10)) >> 10)<<2);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[0] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[0] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 11)) >> 11)<<3);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[0] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[0] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 12)) >> 12)<<4);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[0] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[0] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 13)) >> 13)<<5);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[0] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[0] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 14)) >> 14)<<6);
                }

                {
                  COMM_subsystem_integrated_B.CAN_Pack.Data[0] =
                    COMM_subsystem_integrated_B.CAN_Pack.Data[0] | (uint8_T)
                    ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                        << 15)) >> 15)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* End of Outputs for SubSystem: '<S2>/USdemo New' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S2>/FAW New' incorporates:
     *  ActionPort: '<S40>/Action Port'
     */
    /* Gain: '<S46>/Gain' incorporates:
     *  DataTypeConversion: '<S40>/Data Type Conversion15'
     */
    rtb_DataTypeConversion13_idbb = (uint8_T)((((uint32_T)((uint8_T)128U)) *
      (VsCOMM_CANT_Databus.COMM_TX_Power.ADCU_PowerEnable ? 1U : 0U)) >> 6);

    /* BusCreator: '<S46>/BusConversion_InsertedFor_buscreator_at_inport_2' */
    VsCOMM_FAW_ADCU_TX_Data.T03.Override_Control_Mode =
      rtb_DataTypeConversion13_idbb;

    /* Switch: '<S53>/Switch' */
    if (rtb_DataTypeConversion13_idbb > ((uint8_T)0U))
    {
      /* BusCreator: '<S46>/BusConversion_InsertedFor_buscreator_at_inport_2' incorporates:
       *  Constant: '<S53>/Constant'
       */
      VsCOMM_FAW_ADCU_TX_Data.T03.Override_Control_Mode_Priority =
        KcCOMM_TorqCtrlPriority_Active;
    }
    else
    {
      /* BusCreator: '<S46>/BusConversion_InsertedFor_buscreator_at_inport_2' incorporates:
       *  Constant: '<S53>/Constant_0'
       */
      VsCOMM_FAW_ADCU_TX_Data.T03.Override_Control_Mode_Priority =
        KcCOMM_TorqCtrlPriority_Default;
    }

    /* End of Switch: '<S53>/Switch' */

    /* MinMax: '<S40>/Max' incorporates:
     *  Constant: '<S40>/Constant1'
     *  Inport: '<Root>/VsCOMM_FAW_VEH_RX_Data'
     */
    if ((0.1F > VsCOMM_FAW_VEH_RX_Data.R10.Actual_Gear_Ratio) || (rtIsNaNF
         (VsCOMM_FAW_VEH_RX_Data.R10.Actual_Gear_Ratio)))
    {
      u1 = 0.1F;
    }
    else
    {
      u1 = VsCOMM_FAW_VEH_RX_Data.R10.Actual_Gear_Ratio;
    }

    /* End of MinMax: '<S40>/Max' */

    /* Sum: '<S40>/Add' incorporates:
     *  Constant: '<S40>/Constant6'
     *  Inport: '<Root>/VsCOMM_FAW_VEH_RX_Data'
     *  Product: '<S40>/Divide'
     */
    rtb_Merge_h2gn = (int16_T)(((int16_T)((real32_T)floor((real_T)((real32_T)
      (((real32_T)((int16_T)((real32_T)floor((real_T)((real32_T)
      (VsCOMM_CANT_Databus.COMM_TX_Power.ADCU_PowerTorqueValue *
       KcCOMM_FirstGearRatio)))))) / u1))))) +
      VsCOMM_FAW_VEH_RX_Data.R02.Nominal_friction_percent_torque);

    /* Saturate: '<S40>/Limit_0_to_100' */
    if (rtb_Merge_h2gn > 100)
    {
      /* BusCreator: '<S46>/BusConversion_InsertedFor_buscreator_at_inport_2' */
      VsCOMM_FAW_ADCU_TX_Data.T03.Requested_Torque_Torque_Limit = 100;
    }
    else if (rtb_Merge_h2gn < 0)
    {
      /* BusCreator: '<S46>/BusConversion_InsertedFor_buscreator_at_inport_2' */
      VsCOMM_FAW_ADCU_TX_Data.T03.Requested_Torque_Torque_Limit = 0;
    }
    else
    {
      /* BusCreator: '<S46>/BusConversion_InsertedFor_buscreator_at_inport_2' */
      VsCOMM_FAW_ADCU_TX_Data.T03.Requested_Torque_Torque_Limit = rtb_Merge_h2gn;
    }

    /* End of Saturate: '<S40>/Limit_0_to_100' */

    /* BusCreator: '<S46>/BusConversion_InsertedFor_buscreator_at_inport_2' incorporates:
     *  Constant: '<S53>/Message_Checksum'
     *  Constant: '<S53>/Message_Counter'
     */
    VsCOMM_FAW_ADCU_TX_Data.T03.Message_Counter = ((uint8_T)15U);
    VsCOMM_FAW_ADCU_TX_Data.T03.Message_Checksum = ((uint8_T)15U);

    /* BusCreator: '<S46>/BusConversion_InsertedFor_buscreator_at_inport_0' incorporates:
     *  DataTypeConversion: '<S40>/Data Type Conversion16'
     */
    VsCOMM_FAW_ADCU_TX_Data.T01.ADV_Status =
      VsCOMM_CANT_Databus.COMM_TX_AutodriveMode.ADCU_AutodriveEnable ? 1U : 0U;
    VsCOMM_FAW_ADCU_TX_Data.T01.Target_Speed = 0.0F;
    VsCOMM_FAW_ADCU_TX_Data.T01.Brake_Switch = 0U;
    VsCOMM_FAW_ADCU_TX_Data.T01.XBR_External_Acc_Demand = 0.0F;

    /* SwitchCase: '<S40>/Switch Case' */
    switch (VsCOMM_CANT_Databus.COMM_TX_Transmission.ADCU_TargetGearValue)
    {
     case 0:
      /* Outputs for IfAction SubSystem: '<S40>/GearN' incorporates:
       *  ActionPort: '<S48>/Action Port'
       */
      /* SignalConversion: '<S48>/OutportBufferForOut1' incorporates:
       *  Constant: '<S48>/Constant'
       */
      rtb_Merge_h2gn = 0;

      /* End of Outputs for SubSystem: '<S40>/GearN' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S40>/GearD' incorporates:
       *  ActionPort: '<S47>/Action Port'
       */
      /* SignalConversion: '<S47>/OutportBufferForOut1' incorporates:
       *  Constant: '<S47>/Constant'
       */
      rtb_Merge_h2gn = 127;

      /* End of Outputs for SubSystem: '<S40>/GearD' */
      break;

     case 13:
      /* Outputs for IfAction SubSystem: '<S40>/GearR' incorporates:
       *  ActionPort: '<S49>/Action Port'
       */
      /* SignalConversion: '<S49>/OutportBufferForOut1' incorporates:
       *  Constant: '<S49>/Constant'
       */
      rtb_Merge_h2gn = 98;

      /* End of Outputs for SubSystem: '<S40>/GearR' */
      break;

     default:
      /* Outputs for IfAction SubSystem: '<S40>/default' incorporates:
       *  ActionPort: '<S50>/Action Port'
       */
      /* SignalConversion: '<S50>/OutportBufferForOut1' incorporates:
       *  Constant: '<S50>/Constant'
       */
      rtb_Merge_h2gn = 0;

      /* End of Outputs for SubSystem: '<S40>/default' */
      break;
    }

    /* End of SwitchCase: '<S40>/Switch Case' */

    /* BusCreator: '<S46>/BusConversion_InsertedFor_buscreator_at_inport_1' */
    VsCOMM_FAW_ADCU_TX_Data.T02.Transmission_Requested_Gear = rtb_Merge_h2gn;

    /* BusCreator: '<S46>/BusConversion_InsertedFor_buscreator_at_inport_3' incorporates:
     *  Constant: '<S54>/XBR1_EBI_Mode'
     */
    VsCOMM_FAW_ADCU_TX_Data.T05.XBR1_External_Accleration_Demand =
      VsCOMM_CANT_Databus.COMM_TX_Brake.ADCU_BrakeDecelValue;
    VsCOMM_FAW_ADCU_TX_Data.T05.XBR1_EBI_Mode = ((uint8_T)0U);

    /* Switch: '<S54>/Switch' incorporates:
     *  DataTypeConversion: '<S40>/Data Type Conversion14'
     */
    if (((int32_T)(VsCOMM_CANT_Databus.COMM_TX_Brake.ADCU_BrakeEnable ? 1 : 0)) >
        ((int32_T)((uint8_T)0U)))
    {
      /* BusCreator: '<S46>/BusConversion_InsertedFor_buscreator_at_inport_3' incorporates:
       *  Constant: '<S54>/Constant'
       */
      VsCOMM_FAW_ADCU_TX_Data.T05.XBR1_Priority = ((uint8_T)2U);
    }
    else
    {
      /* BusCreator: '<S46>/BusConversion_InsertedFor_buscreator_at_inport_3' incorporates:
       *  Constant: '<S54>/Constant1'
       */
      VsCOMM_FAW_ADCU_TX_Data.T05.XBR1_Priority = ((uint8_T)3U);
    }

    /* End of Switch: '<S54>/Switch' */

    /* BusCreator: '<S46>/BusConversion_InsertedFor_buscreator_at_inport_3' incorporates:
     *  Constant: '<S54>/XBR1_Message_Checksum'
     *  Constant: '<S54>/XBR1_Message_Counter'
     *  DataTypeConversion: '<S40>/Data Type Conversion14'
     */
    VsCOMM_FAW_ADCU_TX_Data.T05.XBR1_Control_Mode =
      VsCOMM_CANT_Databus.COMM_TX_Brake.ADCU_BrakeEnable ? 1U : 0U;
    VsCOMM_FAW_ADCU_TX_Data.T05.XBR1_Message_Counter = ((uint8_T)15U);
    VsCOMM_FAW_ADCU_TX_Data.T05.XBR1_Message_Checksum = ((uint8_T)15U);

    /* Gain: '<S40>/Gain1' */
    VsCOMM_FAW_ADCU_TX_Data.T08.ReAX_Command_from_ext_controller = (-1.0F) *
      VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringAngleValue;

    /* BusCreator: '<S46>/BusConversion_InsertedFor_buscreator_at_inport_4' incorporates:
     *  Constant: '<S55>/ReAX_Message_Checksum'
     *  Constant: '<S55>/ReAX_Message_counter'
     *  DataTypeConversion: '<S40>/Data Type Conversion3'
     */
    VsCOMM_FAW_ADCU_TX_Data.T08.ReAX_Desired_operation_mode =
      VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringAngleEnable ? 1U : 0U;
    VsCOMM_FAW_ADCU_TX_Data.T08.ReAX_Message_counter = ((uint8_T)15U);
    VsCOMM_FAW_ADCU_TX_Data.T08.ReAX_Message_Checksum = ((uint8_T)15U);

    /* BusCreator: '<S46>/BusConversion_InsertedFor_buscreator_at_inport_5' incorporates:
     *  Constant: '<S56>/EPB_Message_Checksum'
     *  Constant: '<S56>/EPB_Message_Counter'
     *  DataTypeConversion: '<S40>/Data Type Conversion1'
     *  DataTypeConversion: '<S40>/Data Type Conversion2'
     */
    VsCOMM_FAW_ADCU_TX_Data.T13.EPB_Control_mode =
      VsCOMM_CANT_Databus.COMM_TX_Parking.ADCU_ParkingControlEnable ? 1U : 0U;
    VsCOMM_FAW_ADCU_TX_Data.T13.EPB_Control_Command =
      VsCOMM_CANT_Databus.COMM_TX_Parking.ADCU_ParkingControlValue;
    VsCOMM_FAW_ADCU_TX_Data.T13.EPB_Message_Counter = ((uint8_T)15U);
    VsCOMM_FAW_ADCU_TX_Data.T13.EPB_Message_Checksum = ((uint8_T)15U);

    /* DataTypeConversion: '<S40>/Data Type Conversion6' */
    VsCOMM_FAW_ADCU_TX_Data.T15.High_Beam_Light_Command =
      VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_HighBeamRequest ? 1U : 0U;

    /* DataTypeConversion: '<S40>/Data Type Conversion9' */
    VsCOMM_FAW_ADCU_TX_Data.T15.Tractor_Front_Fog_Lights_Command =
      VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_FrontFogLightRequest ? 1U : 0U;

    /* DataTypeConversion: '<S40>/Data Type Conversion8' */
    VsCOMM_FAW_ADCU_TX_Data.T15.Right_Turn_Signal_Lights_Command =
      VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_RightTurningLightRequest ? 1U : 0U;

    /* BusCreator: '<S46>/BusConversion_InsertedFor_buscreator_at_inport_6' incorporates:
     *  Constant: '<S46>/Constant41'
     *  DataTypeConversion: '<S40>/Data Type Conversion10'
     *  DataTypeConversion: '<S40>/Data Type Conversion11'
     *  DataTypeConversion: '<S40>/Data Type Conversion5'
     *  DataTypeConversion: '<S40>/Data Type Conversion7'
     *  DataTypeConversion: '<S46>/Data Type Conversion13'
     */
    VsCOMM_FAW_ADCU_TX_Data.T15.Running_Light_Command =
      KbCOMM_Test_Decs_iBCM_Req ? 1U : 0U;
    VsCOMM_FAW_ADCU_TX_Data.T15.Low_Beam_Head_Light_Command =
      VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_LowBeamRequest ? 1U : 0U;
    VsCOMM_FAW_ADCU_TX_Data.T15.Left_Turn_Signal_Lights_Command =
      VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_LeftTurningLightRequest ? 1U : 0U;
    VsCOMM_FAW_ADCU_TX_Data.T15.Alarm_Horn_Command =
      COMM_subsystem_integrate_ConstB.DataTypeConversion13;
    VsCOMM_FAW_ADCU_TX_Data.T15.Implement_Marker_Light_Command =
      VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_PositionLightRequest ? 1U : 0U;
    VsCOMM_FAW_ADCU_TX_Data.T15.Rear_Fog_Light_Command =
      VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_BackFogLightRequest ? 1U : 0U;

    /* BusCreator: '<S46>/BusConversion_InsertedFor_buscreator_at_inport_7' incorporates:
     *  Constant: '<S46>/Constant2'
     *  DataTypeConversion: '<S40>/Data Type Conversion12'
     *  DataTypeConversion: '<S40>/Data Type Conversion4'
     *  DataTypeConversion: '<S46>/Data Type Conversion1'
     */
    VsCOMM_FAW_ADCU_TX_Data.T16.Wiper_switch_control_command = 0U;
    VsCOMM_FAW_ADCU_TX_Data.T16.Washing_switch_control_command = 0U;
    VsCOMM_FAW_ADCU_TX_Data.T16.BCM_control_by_ADV_state =
      KbCOMM_Test_Decs_iBCM_Req ? 1U : 0U;
    VsCOMM_FAW_ADCU_TX_Data.T16.Rear_brake_switch_control =
      VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_BrakeLightRequest ? 1U : 0U;
    VsCOMM_FAW_ADCU_TX_Data.T16.Horn_control_command =
      VsCOMM_CANT_Databus.COMM_TX_BCM.ADCU_HornRequest ? 1U : 0U;

    /* End of Outputs for SubSystem: '<S2>/FAW New' */
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S2>/Switch Case1' */

  /* BusCreator: '<S2>/BusConversion_InsertedFor_Bus Creator1_at_inport_0' */
  VsCOMM_CAN_Data_Transmit.Config_1_Transmit_CAN_2_ID__193 =
    COMM_subsystem_integrated_B.Config_1_Transmit_CAN_2_ID_193;

  /* BusCreator: '<S2>/BusConversion_InsertedFor_Bus Creator1_at_inport_1' */
  VsCOMM_CAN_Data_Transmit.Config_2_Transmit_CAN_2_ID__193 =
    COMM_subsystem_integrated_B.Config_2_Transmit_CAN_2_ID_193;

  /* BusCreator: '<S2>/BusConversion_InsertedFor_Bus Creator1_at_inport_2' */
  VsCOMM_CAN_Data_Transmit.Config_3_Transmit_CAN_2_ID__550 =
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_1_ID_550;

  /* BusCreator: '<S2>/BusConversion_InsertedFor_Bus Creator1_at_inport_3' */
  VsCOMM_CAN_Data_Transmit.Config_3_Transmit_CAN_0_ID__581 =
    COMM_subsystem_integrated_B.Config_3_Transmit_CAN_0_ID_581;

  /* BusCreator: '<S2>/BusConversion_InsertedFor_Bus Creator1_at_inport_4' */
  VsCOMM_CAN_Data_Transmit.Config_6_Transmit_CAN_4_ID_201591594 =
    COMM_subsystem_integrated_B.EBS_Control;

  /* BusCreator: '<S2>/BusConversion_InsertedFor_Bus Creator1_at_inport_5' */
  VsCOMM_CAN_Data_Transmit.Config_6_Transmit_CAN_4_ID_201439175 =
    COMM_subsystem_integrated_B.Low_Voltage_Distribution_Contro;

  /* BusCreator: '<S2>/BusConversion_InsertedFor_Bus Creator1_at_inport_6' */
  VsCOMM_CAN_Data_Transmit.Config_6_Transmit_CAN_4_ID_201504711 =
    COMM_subsystem_integrated_B.Vehicle_Control;

  /* BusCreator: '<S2>/BusConversion_InsertedFor_Bus Creator1_at_inport_7' */
  VsCOMM_CAN_Data_Transmit.Config_7_Transmit_CAN_2_ID_1586 =
    COMM_subsystem_integrated_B.CAN_Pack;
}

/* ConstCode for atomic system: '<Root>/Transmit' */
void COMM_subsystem_i_Transmit_Const(void)
{
  /* ConstCode for SignalConversion: '<S2>/Signal Conversion9' incorporates:
   *  Constant: '<S2>/Constant22'
   */
  VbCOMM_ADCU_EmergencyLightRequest = false;

  /* ConstCode for SignalConversion: '<S2>/Signal Conversion10' incorporates:
   *  Constant: '<S2>/Constant21'
   */
  VbCOMM_ADCU_RightTurningLightRequest = false;

  /* ConstCode for SignalConversion: '<S2>/Signal Conversion11' incorporates:
   *  Constant: '<S2>/Constant20'
   */
  VbCOMM_ADCU_PositionLightRequest = false;

  /* ConstCode for SignalConversion: '<S2>/Signal Conversion12' incorporates:
   *  Constant: '<S2>/Constant19'
   */
  VbCOMM_ADCU_LeftTurningLightRequest = false;

  /* ConstCode for SignalConversion: '<S2>/Signal Conversion13' incorporates:
   *  Constant: '<S2>/Constant17'
   */
  VbCOMM_ADCU_HighBeamRequest = false;

  /* ConstCode for SignalConversion: '<S2>/Signal Conversion8' incorporates:
   *  Constant: '<S2>/Constant16'
   */
  VbCOMM_ADCU_FrontFogLightRequest = false;

  /* ConstCode for SignalConversion: '<S2>/Signal Conversion14' incorporates:
   *  Constant: '<S2>/Constant15'
   */
  VbCOMM_ADCU_LowBeamRequest = false;

  /* ConstCode for SignalConversion: '<S2>/Signal Conversion15' incorporates:
   *  Constant: '<S2>/Constant9'
   */
  VbCOMM_ADCU_BackFogLghtRequest = false;

  /* ConstCode for SignalConversion: '<S2>/Signal Conversion24' */
  VbCOMM_ADCU_LaunchRequest =
    COMM_subsystem_integrate_ConstB.DataTypeConversion17;

  /* ConstCode for SignalConversion: '<S2>/Signal Conversion34' */
  VfCOMM_ADCU_BrakePressureValue = 0.0F;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
