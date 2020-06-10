/*
 * File: AEBS_Input.c
 *
 * Code generated for Simulink model 'AEBS_subsystem_integrated'.
 *
 * Model version                  : 1.3091
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 16:35:01 2020
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

#include "AEBS_Input.h"

/* Include model header file for global data */
#include "AEBS_subsystem_integrated.h"
#include "AEBS_subsystem_integrated_private.h"

/* Named constants for Chart: '<S18>/Chart' */
#define AEBS_subsyst_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define AEBS_subsystem_integr_IN_Raised ((uint8_T)3U)
#define AEBS_subsystem_integra_IN_Delay ((uint8_T)1U)
#define AEBS_subsystem_integrat_IN_INIT ((uint8_T)2U)

/*
 * System initialize for atomic system:
 *    '<S18>/Chart'
 *    '<S19>/Chart'
 */
void AEBS_subsystem_integ_Chart_Init(DW_Chart_AEBS_subsystem_integ_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_AEBS_subsystem_in = 0U;
  localDW->is_c10_AEBS_subsystem_integrate = AEBS_subsyst_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S18>/Chart'
 *    '<S19>/Chart'
 */
void AEBS_subsystem_integrated_Chart(boolean_T rtu_in, real32_T rtu_delay_time,
  boolean_T *rty_y, uint8_T *rty_state, DW_Chart_AEBS_subsystem_integ_T *localDW)
{
  /* Chart: '<S18>/Chart' */
  if (((uint32_T)localDW->temporalCounter_i1) < 65535U)
  {
    localDW->temporalCounter_i1 = (uint16_T)((int32_T)(((int32_T)
      localDW->temporalCounter_i1) + 1));
  }

  if (((uint32_T)localDW->is_active_c10_AEBS_subsystem_in) == 0U)
  {
    localDW->is_active_c10_AEBS_subsystem_in = 1U;
    localDW->is_c10_AEBS_subsystem_integrate = AEBS_subsystem_integrat_IN_INIT;
    *rty_y = false;
    *rty_state = 1U;
  }
  else
  {
    switch (localDW->is_c10_AEBS_subsystem_integrate)
    {
     case AEBS_subsystem_integra_IN_Delay:
      if (!rtu_in)
      {
        localDW->is_c10_AEBS_subsystem_integrate =
          AEBS_subsystem_integrat_IN_INIT;
        *rty_y = false;
        *rty_state = 1U;
      }
      else if (localDW->temporalCounter_i1 >= ((uint16_T)rtu_delay_time))
      {
        localDW->is_c10_AEBS_subsystem_integrate =
          AEBS_subsystem_integr_IN_Raised;
        *rty_y = true;
        *rty_state = 2U;
      }
      else
      {
        *rty_y = false;
        *rty_state = 2U;
      }
      break;

     case AEBS_subsystem_integrat_IN_INIT:
      if (rtu_in)
      {
        localDW->is_c10_AEBS_subsystem_integrate =
          AEBS_subsystem_integra_IN_Delay;
        localDW->temporalCounter_i1 = 0U;
        *rty_y = false;
        *rty_state = 2U;
      }
      else
      {
        *rty_y = false;
        *rty_state = 1U;
      }
      break;

     default:
      if (!rtu_in)
      {
        localDW->is_c10_AEBS_subsystem_integrate =
          AEBS_subsystem_integrat_IN_INIT;
        *rty_y = false;
        *rty_state = 1U;
      }
      else
      {
        *rty_y = true;
        *rty_state = 2U;
      }
      break;
    }
  }

  /* End of Chart: '<S18>/Chart' */
}

/*
 * Output and update for atomic system:
 *    '<S22>/DividByZero'
 *    '<S23>/DividByZero'
 */
void AEBS_subsystem_inte_DividByZero(real32_T rtu_u, real32_T *rty_y)
{
  if ((((real_T)rtu_u) < 1.0E-5) && (rtu_u >= 0.0F))
  {
    *rty_y = 1.0E-5F;
  }
  else if ((((real_T)rtu_u) > -1.0E-5) && (rtu_u < 0.0F))
  {
    *rty_y = -1.0E-5F;
  }
  else
  {
    *rty_y = rtu_u;
  }
}

/* System initialize for atomic system: '<S3>/AEBS_Input' */
void AEBS_subsystem__AEBS_Input_Init(void)
{
  /* SystemInitialize for Chart: '<S18>/Chart' */
  AEBS_subsystem_integ_Chart_Init(&AEBS_subsystem_integrated_DW.sf_Chart);

  /* SystemInitialize for Chart: '<S19>/Chart' */
  AEBS_subsystem_integ_Chart_Init(&AEBS_subsystem_integrated_DW.sf_Chart_la5t);
}

/* Output and update for atomic system: '<S3>/AEBS_Input' */
void AEBS_subsystem_integ_AEBS_Input(void)
{
  boolean_T rtb_RelationalOperator_fyjq;
  uint8_T rtb_Switch1;
  boolean_T rtb_RelationalOperator;
  real32_T rtb_Gain;
  boolean_T rtb_RelationalOperator2;
  real32_T rtb_Gain_myhp;
  real32_T rtb_Divide;
  real32_T rtb_y;
  real32_T rtb_radius;
  boolean_T rtb_y_mqse;
  boolean_T rtb_y_prmf;
  uint8_T rtb_state_jqhj;
  uint8_T rtb_state;
  real32_T rtb_Gain_tmp;

  /* RelationalOperator: '<S12>/Relational Operator' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   *  UnitDelay: '<S12>/Unit Delay'
   */
  rtb_RelationalOperator = (VsOBFU_DataBus.timestamp_high ==
    AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_dinf);

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S12>/Constant7'
   *  Gain: '<S19>/Gain'
   */
  rtb_Gain_tmp = 100.0F * KfAEBS_t_Time_OBFUNReceivedThrsh;
  rtb_Gain = rtb_Gain_tmp;

  /* Chart: '<S18>/Chart' */
  AEBS_subsystem_integrated_Chart(rtb_RelationalOperator, rtb_Gain, &rtb_y_mqse,
    &rtb_state_jqhj, &AEBS_subsystem_integrated_DW.sf_Chart);

  /* Switch: '<S12>/Switch1' incorporates:
   *  Constant: '<S12>/Constant1'
   *  Constant: '<S12>/Constant6'
   *  DataTypeConversion: '<S14>/Data Type Conversion6'
   *  Inport: '<Root>/COMM_CANR_Databus'
   *  RelationalOperator: '<S12>/Relational Operator1'
   *  S-Function (sfix_bitop): '<S12>/Bitwise Operator2'
   *  Switch: '<S12>/Switch'
   */
  if ((VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveActiveStatus ? 1U :
       0U) != ((uint8_T)1U))
  {
    /* Switch: '<S12>/Switch' incorporates:
     *  Constant: '<S12>/Constant6'
     */
    if (rtb_y_mqse)
    {
      rtb_Switch1 = AEBS_subsystem_integrate_ConstB.BitwiseOperator1;
    }
    else
    {
      rtb_Switch1 = ((uint8_T)0U);
    }

    rtb_Switch1 |= AEBS_subsystem_integrate_ConstB.DataTypeConversion1_gzmk;
  }
  else if (rtb_y_mqse)
  {
    /* Switch: '<S12>/Switch' */
    rtb_Switch1 = AEBS_subsystem_integrate_ConstB.BitwiseOperator1;
  }
  else
  {
    rtb_Switch1 = ((uint8_T)0U);
  }

  /* End of Switch: '<S12>/Switch1' */

  /* RelationalOperator: '<S12>/Relational Operator2' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   *  UnitDelay: '<S12>/Unit Delay1'
   */
  rtb_RelationalOperator2 = (VsEGMO_DataBus.timestamp_high ==
    AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_mmx5);

  /* Gain: '<S19>/Gain' */
  rtb_Gain_myhp = rtb_Gain_tmp;

  /* Chart: '<S19>/Chart' */
  AEBS_subsystem_integrated_Chart(rtb_RelationalOperator2, rtb_Gain_myhp,
    &rtb_y_prmf, &rtb_state, &AEBS_subsystem_integrated_DW.sf_Chart_la5t);

  /* Switch: '<S6>/Switch3' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant31'
   */
  if (KbAEBS_Enable_Error)
  {
    /* Switch: '<S12>/Switch2' incorporates:
     *  S-Function (sfix_bitop): '<S12>/Bitwise Operator3'
     */
    if (rtb_y_prmf)
    {
      AEBS_subsystem_integrated_B.Switch1 = (uint8_T)
        (AEBS_subsystem_integrate_ConstB.DataTypeConversion2_o2r5 | rtb_Switch1);
    }
    else
    {
      AEBS_subsystem_integrated_B.Switch1 = rtb_Switch1;
    }

    /* End of Switch: '<S12>/Switch2' */
  }
  else
  {
    AEBS_subsystem_integrated_B.Switch1 = ((uint8_T)0U);
  }

  /* End of Switch: '<S6>/Switch3' */

  /* RelationalOperator: '<S6>/Relational Operator' incorporates:
   *  Constant: '<S6>/Constant4'
   *  S-Function (sfix_bitop): '<S6>/Bitwise Operator'
   */
  rtb_RelationalOperator_fyjq = ((AEBS_subsystem_integrated_B.Switch1 &
    AEBS_subsystem_integrate_ConstB.DataTypeConversion_axbm) != ((uint8_T)0U));

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant3'
   *  DataTypeConversion: '<S14>/Data Type Conversion1'
   *  Inport: '<Root>/COMM_CANR_Databus'
   *  Inport: '<Root>/EGMO_DataBus'
   *  Logic: '<S6>/Logical Operator'
   */
  if (KbAEBS_Use_CAN_VehSpeed || rtb_RelationalOperator_fyjq)
  {
    AEBS_subsystem_integrated_B.veh_speed =
      VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed;
  }
  else
  {
    AEBS_subsystem_integrated_B.veh_speed =
      VsEGMO_DataBus.motion.linear_velocity;
  }

  /* End of Switch: '<S6>/Switch' */

  /* SignalConversion: '<S14>/Signal Conversion6' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion1'
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  VfAEBS_FedBck_Vehspd =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed;

  /* Switch: '<S6>/Switch4' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion1'
   *  Inport: '<Root>/COMM_CANR_Databus'
   *  Inport: '<Root>/EGMO_DataBus'
   */
  if (rtb_RelationalOperator_fyjq)
  {
    AEBS_subsystem_integrated_B.veh_speed_rel_x =
      VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed;
  }
  else
  {
    AEBS_subsystem_integrated_B.veh_speed_rel_x =
      VsEGMO_DataBus.motion.velocity_rel.x;
  }

  /* End of Switch: '<S6>/Switch4' */

  /* Switch: '<S6>/Switch1' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion9'
   *  Inport: '<Root>/COMM_CANR_Databus'
   *  Inport: '<Root>/EGMO_DataBus'
   */
  if (rtb_RelationalOperator_fyjq)
  {
    AEBS_subsystem_integrated_B.veh_acceleration =
      VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAcceleration;
  }
  else
  {
    AEBS_subsystem_integrated_B.veh_acceleration =
      VsEGMO_DataBus.motion.linear_acceleration;
  }

  /* End of Switch: '<S6>/Switch1' */

  /* SignalConversion: '<S14>/Signal Conversion8' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion9'
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  VfAEBS_FedBck_AccLong =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAcceleration;

  /* DataTypeConversion: '<S14>/Data Type Conversion8' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  AEBS_subsystem_integrated_B.DataTypeConversion8 =
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle;

  /* Product: '<S13>/Divide' incorporates:
   *  Constant: '<S13>/Constant2'
   *  Gain: '<S13>/Gain'
   */
  rtb_Divide = (0.0174532924F * AEBS_subsystem_integrated_B.DataTypeConversion8)
    / KfAEBS_Veh_Strwhl2FrtwhlRatio;

  /* MATLAB Function: '<S22>/DividByZero' */
  AEBS_subsystem_inte_DividByZero(rtb_Divide, &rtb_y);

  /* Product: '<S13>/Divide2' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Constant: '<S13>/Constant5'
   *  Constant: '<S13>/Constant6'
   *  Product: '<S13>/Divide1'
   *  Sum: '<S13>/Add'
   */
  rtb_radius = (KfAEBS_Veh_WheelBase / rtb_y) / (1.0F +
    KfAEBS_CoeffStrwhl2Radius);

  /* MATLAB Function: '<S23>/DividByZero' */
  AEBS_subsystem_inte_DividByZero(rtb_radius, &rtb_y);

  /* Switch: '<S6>/Switch2' incorporates:
   *  Constant: '<S13>/Constant3'
   *  Inport: '<Root>/EGMO_DataBus'
   *  Product: '<S13>/Divide3'
   */
  if (rtb_RelationalOperator_fyjq)
  {
    AEBS_subsystem_integrated_B.veh_curvature = 1.0F / rtb_y;
  }
  else
  {
    AEBS_subsystem_integrated_B.veh_curvature = VsEGMO_DataBus.motion.curvature;
  }

  /* End of Switch: '<S6>/Switch2' */

  /* SignalConversion: '<S14>/Signal Conversion1' */
  VfAEBS_FedBck_StrAngle = AEBS_subsystem_integrated_B.DataTypeConversion8;

  /* Switch: '<S6>/Switch5' incorporates:
   *  Constant: '<S6>/Constant2'
   *  Inport: '<Root>/EGMO_DataBus'
   */
  if (rtb_RelationalOperator_fyjq)
  {
    AEBS_subsystem_integrated_B.veh_speed_rel_y = 0.0F;
  }
  else
  {
    AEBS_subsystem_integrated_B.veh_speed_rel_y =
      VsEGMO_DataBus.motion.velocity_rel.y;
  }

  /* End of Switch: '<S6>/Switch5' */

  /* SignalConversion: '<S14>/Signal Conversion' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion6'
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  VfAEBS_FedBck_Drivemode =
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveActiveStatus ? 1U :
    0U;

  /* SignalConversion: '<S14>/Signal Conversion12' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion10'
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  VfAEBS_FedBck_BrkLightState =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BrakeLightStatus ? 1U : 0U;

  /* DataTypeConversion: '<S14>/Data Type Conversion11' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  AEBS_subsystem_integrated_B.DataTypeConversion11 =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRate;

  /* SignalConversion: '<S14>/Signal Conversion15' */
  VfAEBS_FedBck_yawRate = AEBS_subsystem_integrated_B.DataTypeConversion11;

  /* DataTypeConversion: '<S14>/Data Type Conversion12' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  AEBS_subsystem_integrated_B.DataTypeConversion12 =
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch ? 1U : 0U;

  /* SignalConversion: '<S14>/Signal Conversion9' */
  VfAEBS_FedBck_BrkPedStatus = AEBS_subsystem_integrated_B.DataTypeConversion12;

  /* DataTypeConversion: '<S14>/Data Type Conversion2' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  AEBS_subsystem_integrated_B.DataTypeConversion2 =
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ActualControlStatus;

  /* SignalConversion: '<S14>/Signal Conversion5' */
  VfAEBS_FedBck_EPBstate = AEBS_subsystem_integrated_B.DataTypeConversion2;

  /* DataTypeConversion: '<S14>/Data Type Conversion3' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  AEBS_subsystem_integrated_B.DataTypeConversion3 =
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition;

  /* SignalConversion: '<S14>/Signal Conversion4' */
  VfAEBS_FedBck_GearValue = AEBS_subsystem_integrated_B.DataTypeConversion3;

  /* DataTypeConversion: '<S14>/Data Type Conversion4' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  AEBS_subsystem_integrated_B.DataTypeConversion4 = (uint8_T)
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalPosition;

  /* SignalConversion: '<S14>/Signal Conversion3' */
  VfAEBS_FedBck_BrkPedPos = AEBS_subsystem_integrated_B.DataTypeConversion4;

  /* DataTypeConversion: '<S14>/Data Type Conversion5' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  AEBS_subsystem_integrated_B.DataTypeConversion5 = (uint8_T)
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_ActualAccelPedalPosition;

  /* SignalConversion: '<S14>/Signal Conversion2' */
  VfAEBS_FedBck_AccPedPos = AEBS_subsystem_integrated_B.DataTypeConversion5;

  /* SignalConversion: '<S14>/Signal Conversion7' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion7'
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  VfAEBS_FedBck_AccLateral =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAcceleration;

  /* SignalConversion: '<S14>/Signal Conversion16' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  VfAEBS_FedBck_LeftLampState =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState;

  /* SignalConversion: '<S14>/Signal Conversion17' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  VfAEBS_FedBck_RightLampState =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState;

  /* Update for UnitDelay: '<S12>/Unit Delay' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  AEBS_subsystem_integrated_DW.UnitDelay_DSTATE_dinf =
    VsOBFU_DataBus.timestamp_high;

  /* Update for UnitDelay: '<S12>/Unit Delay1' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  AEBS_subsystem_integrated_DW.UnitDelay1_DSTATE_mmx5 =
    VsEGMO_DataBus.timestamp_high;
}

/* ConstCode for atomic system: '<S3>/AEBS_Input' */
void AEBS_subsystem_AEBS_Input_Const(void)
{
  /* ConstCode for SignalConversion: '<S14>/Signal Conversion11' */
  VfAEBS_FedBck_SmallLampState =
    AEBS_subsystem_integrate_ConstB.FedBck_SmallLampState;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
