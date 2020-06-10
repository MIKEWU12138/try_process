/*
 * File: DRIV_SignalInput.c
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

#include "DRIV_SignalInput.h"

/* Include model header file for global data */
#include "DRIV_subsystem_integrated.h"
#include "DRIV_subsystem_integrated_private.h"

/* Named constants for Chart: '<S16>/Chart' */
#define DRIV_subsyst_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define DRIV_subsystem_integr_IN_Raised ((uint8_T)3U)
#define DRIV_subsystem_integra_IN_Delay ((uint8_T)1U)
#define DRIV_subsystem_integrat_IN_INIT ((uint8_T)2U)

/* Named constants for Chart: '<S17>/Chart' */
#define DRIV_su_IN_NO_ACTIVE_CHILD_axcw ((uint8_T)0U)
#define DRIV_subsystem_i_IN_Raised_bfkr ((uint8_T)3U)
#define DRIV_subsystem_in_IN_Delay_jwiu ((uint8_T)1U)
#define DRIV_subsystem_int_IN_INIT_l3m0 ((uint8_T)2U)

/* Named constants for Chart: '<S18>/Chart' */
#define DRIV_su_IN_NO_ACTIVE_CHILD_iq5t ((uint8_T)0U)
#define DRIV_subsystem_i_IN_Raised_dp51 ((uint8_T)3U)
#define DRIV_subsystem_in_IN_Delay_g11m ((uint8_T)1U)
#define DRIV_subsystem_int_IN_INIT_gyir ((uint8_T)2U)

/* System initialize for atomic system: '<S16>/Chart' */
void DRIV_subsystem_integ_Chart_Init(void)
{
  DRIV_subsystem_integrated_DW.temporalCounter_i1_n4sm = 0U;
  DRIV_subsystem_integrated_DW.is_active_c6_DRIV_subsystem_int = 0U;
  DRIV_subsystem_integrated_DW.is_c6_DRIV_subsystem_integrated =
    DRIV_subsyst_IN_NO_ACTIVE_CHILD;
}

/* Output and update for atomic system: '<S16>/Chart' */
void DRIV_subsystem_integrated_Chart(void)
{
  uint8_T rtb_state;

  /* Chart: '<S16>/Chart' */
  if (((uint32_T)DRIV_subsystem_integrated_DW.temporalCounter_i1_n4sm) < 65535U)
  {
    DRIV_subsystem_integrated_DW.temporalCounter_i1_n4sm = (uint16_T)((int32_T)
      (((int32_T)DRIV_subsystem_integrated_DW.temporalCounter_i1_n4sm) + 1));
  }

  if (((uint32_T)DRIV_subsystem_integrated_DW.is_active_c6_DRIV_subsystem_int) ==
      0U)
  {
    DRIV_subsystem_integrated_DW.is_active_c6_DRIV_subsystem_int = 1U;
    DRIV_subsystem_integrated_DW.is_c6_DRIV_subsystem_integrated =
      DRIV_subsystem_integrat_IN_INIT;
    DRIV_subsystem_integrated_B.y_if0u = false;
    rtb_state = 1U;
  }
  else
  {
    switch (DRIV_subsystem_integrated_DW.is_c6_DRIV_subsystem_integrated)
    {
     case DRIV_subsystem_integra_IN_Delay:
      if (!DRIV_subsystem_integrated_B.VbDRIV_ACCCancelSwitch_juwt)
      {
        DRIV_subsystem_integrated_DW.is_c6_DRIV_subsystem_integrated =
          DRIV_subsystem_integrat_IN_INIT;
        DRIV_subsystem_integrated_B.y_if0u = false;
        rtb_state = 1U;
      }
      else if (DRIV_subsystem_integrated_DW.temporalCounter_i1_n4sm >=
               ((uint16_T)
                DRIV_subsystem_integrated_B.VfDRIV_ACCDriveSetSpeed_jz5o))
      {
        DRIV_subsystem_integrated_DW.is_c6_DRIV_subsystem_integrated =
          DRIV_subsystem_integr_IN_Raised;
        DRIV_subsystem_integrated_B.y_if0u = true;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_if0u = false;
        rtb_state = 2U;
      }
      break;

     case DRIV_subsystem_integrat_IN_INIT:
      if (DRIV_subsystem_integrated_B.VbDRIV_ACCCancelSwitch_juwt)
      {
        DRIV_subsystem_integrated_DW.is_c6_DRIV_subsystem_integrated =
          DRIV_subsystem_integra_IN_Delay;
        DRIV_subsystem_integrated_DW.temporalCounter_i1_n4sm = 0U;
        DRIV_subsystem_integrated_B.y_if0u = false;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_if0u = false;
        rtb_state = 1U;
      }
      break;

     default:
      if (!DRIV_subsystem_integrated_B.VbDRIV_ACCCancelSwitch_juwt)
      {
        DRIV_subsystem_integrated_DW.is_c6_DRIV_subsystem_integrated =
          DRIV_subsystem_integrat_IN_INIT;
        DRIV_subsystem_integrated_B.y_if0u = false;
        rtb_state = 1U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_if0u = true;
        rtb_state = 2U;
      }
      break;
    }
  }

  /* End of Chart: '<S16>/Chart' */
}

/* System initialize for atomic system: '<S17>/Chart' */
void DRIV_subsystem__Chart_nymd_Init(void)
{
  DRIV_subsystem_integrated_DW.temporalCounter_i1_giwk = 0U;
  DRIV_subsystem_integrated_DW.is_active_c7_DRIV_subsystem_int = 0U;
  DRIV_subsystem_integrated_DW.is_c7_DRIV_subsystem_integrated =
    DRIV_su_IN_NO_ACTIVE_CHILD_axcw;
}

/* Output and update for atomic system: '<S17>/Chart' */
void DRIV_subsystem_integ_Chart_fth3(void)
{
  uint8_T rtb_state;

  /* Chart: '<S17>/Chart' */
  if (((uint32_T)DRIV_subsystem_integrated_DW.temporalCounter_i1_giwk) < 65535U)
  {
    DRIV_subsystem_integrated_DW.temporalCounter_i1_giwk = (uint16_T)((int32_T)
      (((int32_T)DRIV_subsystem_integrated_DW.temporalCounter_i1_giwk) + 1));
  }

  if (((uint32_T)DRIV_subsystem_integrated_DW.is_active_c7_DRIV_subsystem_int) ==
      0U)
  {
    DRIV_subsystem_integrated_DW.is_active_c7_DRIV_subsystem_int = 1U;
    DRIV_subsystem_integrated_DW.is_c7_DRIV_subsystem_integrated =
      DRIV_subsystem_int_IN_INIT_l3m0;
    DRIV_subsystem_integrated_B.y_gdtp = false;
    rtb_state = 1U;
  }
  else
  {
    switch (DRIV_subsystem_integrated_DW.is_c7_DRIV_subsystem_integrated)
    {
     case DRIV_subsystem_in_IN_Delay_jwiu:
      if (!DRIV_subsystem_integrated_B.VbDRIV_ACCCancelSwitch_juwt)
      {
        DRIV_subsystem_integrated_DW.is_c7_DRIV_subsystem_integrated =
          DRIV_subsystem_int_IN_INIT_l3m0;
        DRIV_subsystem_integrated_B.y_gdtp = false;
        rtb_state = 1U;
      }
      else if (DRIV_subsystem_integrated_DW.temporalCounter_i1_giwk >=
               ((uint16_T)
                DRIV_subsystem_integrated_B.VfDRIV_ACCDriveSetSpeed_jz5o))
      {
        DRIV_subsystem_integrated_DW.is_c7_DRIV_subsystem_integrated =
          DRIV_subsystem_i_IN_Raised_bfkr;
        DRIV_subsystem_integrated_B.y_gdtp = true;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_gdtp = false;
        rtb_state = 2U;
      }
      break;

     case DRIV_subsystem_int_IN_INIT_l3m0:
      if (DRIV_subsystem_integrated_B.VbDRIV_ACCCancelSwitch_juwt)
      {
        DRIV_subsystem_integrated_DW.is_c7_DRIV_subsystem_integrated =
          DRIV_subsystem_in_IN_Delay_jwiu;
        DRIV_subsystem_integrated_DW.temporalCounter_i1_giwk = 0U;
        DRIV_subsystem_integrated_B.y_gdtp = false;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_gdtp = false;
        rtb_state = 1U;
      }
      break;

     default:
      if (!DRIV_subsystem_integrated_B.VbDRIV_ACCCancelSwitch_juwt)
      {
        DRIV_subsystem_integrated_DW.is_c7_DRIV_subsystem_integrated =
          DRIV_subsystem_int_IN_INIT_l3m0;
        DRIV_subsystem_integrated_B.y_gdtp = false;
        rtb_state = 1U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_gdtp = true;
        rtb_state = 2U;
      }
      break;
    }
  }

  /* End of Chart: '<S17>/Chart' */
}

/* System initialize for atomic system: '<S18>/Chart' */
void DRIV_subsystem__Chart_ntlf_Init(void)
{
  DRIV_subsystem_integrated_DW.temporalCounter_i1_c0ca = 0U;
  DRIV_subsystem_integrated_DW.is_active_c8_DRIV_subsystem_int = 0U;
  DRIV_subsystem_integrated_DW.is_c8_DRIV_subsystem_integrated =
    DRIV_su_IN_NO_ACTIVE_CHILD_iq5t;
}

/* Output and update for atomic system: '<S18>/Chart' */
void DRIV_subsystem_integ_Chart_gtd4(void)
{
  uint8_T rtb_state;

  /* Chart: '<S18>/Chart' */
  if (((uint32_T)DRIV_subsystem_integrated_DW.temporalCounter_i1_c0ca) < 65535U)
  {
    DRIV_subsystem_integrated_DW.temporalCounter_i1_c0ca = (uint16_T)((int32_T)
      (((int32_T)DRIV_subsystem_integrated_DW.temporalCounter_i1_c0ca) + 1));
  }

  if (((uint32_T)DRIV_subsystem_integrated_DW.is_active_c8_DRIV_subsystem_int) ==
      0U)
  {
    DRIV_subsystem_integrated_DW.is_active_c8_DRIV_subsystem_int = 1U;
    DRIV_subsystem_integrated_DW.is_c8_DRIV_subsystem_integrated =
      DRIV_subsystem_int_IN_INIT_gyir;
    DRIV_subsystem_integrated_B.y_n3mj = false;
    rtb_state = 1U;
  }
  else
  {
    switch (DRIV_subsystem_integrated_DW.is_c8_DRIV_subsystem_integrated)
    {
     case DRIV_subsystem_in_IN_Delay_g11m:
      if (!DRIV_subsystem_integrated_B.VbDRIV_ACCCancelSwitch_juwt)
      {
        DRIV_subsystem_integrated_DW.is_c8_DRIV_subsystem_integrated =
          DRIV_subsystem_int_IN_INIT_gyir;
        DRIV_subsystem_integrated_B.y_n3mj = false;
        rtb_state = 1U;
      }
      else if (DRIV_subsystem_integrated_DW.temporalCounter_i1_c0ca >=
               ((uint16_T)
                DRIV_subsystem_integrated_B.VfDRIV_ACCDriveSetSpeed_jz5o))
      {
        DRIV_subsystem_integrated_DW.is_c8_DRIV_subsystem_integrated =
          DRIV_subsystem_i_IN_Raised_dp51;
        DRIV_subsystem_integrated_B.y_n3mj = true;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_n3mj = false;
        rtb_state = 2U;
      }
      break;

     case DRIV_subsystem_int_IN_INIT_gyir:
      if (DRIV_subsystem_integrated_B.VbDRIV_ACCCancelSwitch_juwt)
      {
        DRIV_subsystem_integrated_DW.is_c8_DRIV_subsystem_integrated =
          DRIV_subsystem_in_IN_Delay_g11m;
        DRIV_subsystem_integrated_DW.temporalCounter_i1_c0ca = 0U;
        DRIV_subsystem_integrated_B.y_n3mj = false;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_n3mj = false;
        rtb_state = 1U;
      }
      break;

     default:
      if (!DRIV_subsystem_integrated_B.VbDRIV_ACCCancelSwitch_juwt)
      {
        DRIV_subsystem_integrated_DW.is_c8_DRIV_subsystem_integrated =
          DRIV_subsystem_int_IN_INIT_gyir;
        DRIV_subsystem_integrated_B.y_n3mj = false;
        rtb_state = 1U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_n3mj = true;
        rtb_state = 2U;
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
void DRIV_subsystem_inte_DividByZero(real32_T rtu_u, real32_T *rty_y)
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

/* System initialize for atomic system: '<S1>/CheckDRIV_SignalInput' */
void CheckDRIV_SignalInput_Init(void)
{
  /* SystemInitialize for Chart: '<S16>/Chart' */
  DRIV_subsystem_integ_Chart_Init();

  /* SystemInitialize for Chart: '<S18>/Chart' */
  DRIV_subsystem__Chart_ntlf_Init();

  /* SystemInitialize for Chart: '<S17>/Chart' */
  DRIV_subsystem__Chart_nymd_Init();
}

/* Output and update for atomic system: '<S1>/CheckDRIV_SignalInput' */
void CheckDRIV_SignalInput(void)
{
  int_T idxDelay;
  boolean_T rtb_RelationalOperator;
  uint8_T rtb_Switch;
  real32_T rtb_Divide;
  real32_T rtb_y;
  real32_T rtb_radius;
  uint8_T rtb_DataTypeConversion10;
  uint8_T rtb_DataTypeConversion2;
  uint8_T rtb_DataTypeConversion3;
  uint8_T rtb_DataTypeConversion4;
  uint8_T rtb_DataTypeConversion5;
  uint8_T rtb_DataTypeConversion6;
  real32_T rtb_DataTypeConversion7;
  real32_T rtb_veh_speed;
  real32_T rtb_veh_acc;
  real32_T rtb_veh_cur;

  /* RelationalOperator: '<S7>/Relational Operator' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   *  UnitDelay: '<S7>/Unit Delay'
   */
  DRIV_subsystem_integrated_B.VbDRIV_ACCCancelSwitch_juwt =
    (VsOBFU_DataBus.timestamp_low ==
     DRIV_subsystem_integrated_DW.UnitDelay_DSTATE);

  /* Gain: '<S16>/Gain' incorporates:
   *  Constant: '<S7>/Constant7'
   */
  DRIV_subsystem_integrated_B.VfDRIV_ACCDriveSetSpeed_jz5o = 100.0F *
    KfDRIV_t_TimeOBFUNReceivedThrsh;

  /* Chart: '<S16>/Chart' */
  DRIV_subsystem_integrated_Chart();

  /* RelationalOperator: '<S7>/Relational Operator3' incorporates:
   *  Inport: '<Root>/MPFU_DataBus'
   *  UnitDelay: '<S7>/Unit Delay2'
   */
  DRIV_subsystem_integrated_B.VbDRIV_ACCCancelSwitch_juwt =
    (VsMPFU_DataBus.timestamp_low ==
     DRIV_subsystem_integrated_DW.UnitDelay2_DSTATE);

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S7>/Constant8'
   */
  DRIV_subsystem_integrated_B.VfDRIV_ACCDriveSetSpeed_jz5o = 100.0F *
    KfDRIV_t_TimeMPFUReceivedThrsh;

  /* Chart: '<S18>/Chart' */
  DRIV_subsystem_integ_Chart_gtd4();

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Constant5'
   *  Switch: '<S7>/Switch3'
   */
  if (DRIV_subsystem_integrated_B.y_if0u)
  {
    rtb_Switch = DRIV_subsystem_integrate_ConstB.BitwiseOperator1;
  }
  else if (DRIV_subsystem_integrated_B.y_n3mj)
  {
    /* Switch: '<S7>/Switch3' */
    rtb_Switch = DRIV_subsystem_integrate_ConstB.BitwiseOperator4;
  }
  else
  {
    rtb_Switch = ((uint8_T)0U);
  }

  /* End of Switch: '<S7>/Switch' */

  /* RelationalOperator: '<S7>/Relational Operator2' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   *  UnitDelay: '<S7>/Unit Delay1'
   */
  DRIV_subsystem_integrated_B.VbDRIV_ACCCancelSwitch_juwt =
    (VsEGMO_DataBus.timestamp_low ==
     DRIV_subsystem_integrated_DW.UnitDelay1_DSTATE);

  /* Gain: '<S17>/Gain' incorporates:
   *  Constant: '<S7>/Constant2'
   */
  DRIV_subsystem_integrated_B.VfDRIV_ACCDriveSetSpeed_jz5o = 100.0F *
    KfDRIV_t_TimeEGMOReceivedThrsh;

  /* Chart: '<S17>/Chart' */
  DRIV_subsystem_integ_Chart_fth3();

  /* Switch: '<S7>/Switch2' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   *  S-Function (sfix_bitop): '<S7>/Bitwise Operator3'
   *  Switch: '<S7>/Switch1'
   */
  if (DRIV_subsystem_integrated_B.y_gdtp)
  {
    rtb_Switch |= DRIV_subsystem_integrate_ConstB.DataTypeConversion2;
  }
  else
  {
    if (VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch)
    {
      /* Switch: '<S7>/Switch1' incorporates:
       *  S-Function (sfix_bitop): '<S7>/Bitwise Operator2'
       */
      rtb_Switch |= DRIV_subsystem_integrate_ConstB.DataTypeConversion1;
    }
  }

  /* End of Switch: '<S7>/Switch2' */

  /* RelationalOperator: '<S3>/Relational Operator' incorporates:
   *  Constant: '<S3>/Constant4'
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator'
   */
  rtb_RelationalOperator = ((rtb_Switch &
    DRIV_subsystem_integrate_ConstB.DataTypeConversion_m3xv) != ((uint8_T)0U));

  /* Switch: '<S3>/Switch' incorporates:
   *  DataTypeConversion: '<S11>/Data Type Conversion1'
   *  Inport: '<Root>/COMM_CANR_Databus'
   *  Inport: '<Root>/EGMO_DataBus'
   */
  if (rtb_RelationalOperator)
  {
    rtb_veh_speed = VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed;
  }
  else
  {
    rtb_veh_speed = VsEGMO_DataBus.motion.linear_velocity;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Switch: '<S3>/Switch1' incorporates:
   *  DataTypeConversion: '<S11>/Data Type Conversion9'
   *  Inport: '<Root>/COMM_CANR_Databus'
   *  Inport: '<Root>/EGMO_DataBus'
   */
  if (rtb_RelationalOperator)
  {
    rtb_veh_acc =
      VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAcceleration;
  }
  else
  {
    rtb_veh_acc = VsEGMO_DataBus.motion.linear_acceleration;
  }

  /* End of Switch: '<S3>/Switch1' */

  /* Product: '<S10>/Divide' incorporates:
   *  Constant: '<S10>/Constant2'
   *  DataTypeConversion: '<S11>/Data Type Conversion8'
   *  Gain: '<S10>/Gain'
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  rtb_Divide = (0.0174532924F *
                VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_TargetSteeringAngleEcho)
    / KfDRIV_Veh_Strwhl2FrtwhlRatio;

  /* MATLAB Function: '<S22>/DividByZero' */
  DRIV_subsystem_inte_DividByZero(rtb_Divide, &rtb_y);

  /* Product: '<S10>/Divide2' incorporates:
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S10>/Constant5'
   *  Constant: '<S10>/Constant6'
   *  Product: '<S10>/Divide1'
   *  Sum: '<S10>/Add'
   */
  rtb_radius = (KfDRIV_Veh_WheelBase / rtb_y) / (1.0F +
    KfDRIV_CoeffStrwhl2Radius);

  /* MATLAB Function: '<S23>/DividByZero' */
  DRIV_subsystem_inte_DividByZero(rtb_radius, &rtb_y);

  /* Switch: '<S3>/Switch2' incorporates:
   *  Constant: '<S10>/Constant3'
   *  Inport: '<Root>/EGMO_DataBus'
   *  Product: '<S10>/Divide3'
   */
  if (rtb_RelationalOperator)
  {
    rtb_veh_cur = 1.0F / rtb_y;
  }
  else
  {
    rtb_veh_cur = VsEGMO_DataBus.motion.curvature;
  }

  /* End of Switch: '<S3>/Switch2' */

  /* SignalConversion: '<S3>/Signal Conversion2' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VfDRIV_steer_angle = VsEGMO_DataBus.motion.steer_angle_filtered;

  /* Product: '<S9>/Divide' incorporates:
   *  Abs: '<S9>/Abs'
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   *  Delay: '<S9>/Delay'
   *  Product: '<S9>/Product'
   *  Sum: '<S9>/Subtract'
   */
  VfDRIV_SteerAngleRate = ((real32_T)fabs((real_T)((real32_T)(VfDRIV_steer_angle
    - DRIV_subsystem_integrated_DW.Delay_DSTATE_dx3s[0])))) /
    (kfDRIV_t_PeriodFunctionCall * 20.0F);

  /* Sum: '<S8>/Add' incorporates:
   *  Constant: '<S8>/Constant2'
   *  Constant: '<S8>/Constant3'
   *  Delay: '<S8>/Delay1'
   *  Inport: '<Root>/COMM_CANR_Databus'
   *  Product: '<S8>/Product1'
   *  Product: '<S8>/Product2'
   *  Sum: '<S8>/Subtract1'
   */
  VfDRIV_Steer_Torque_Filter =
    (VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorque * (1.0F -
      kfDRIV_k_FilterGain)) + (kfDRIV_k_FilterGain * VfDRIV_Steer_Torque_Filter);

  /* DataTypeConversion: '<S11>/Data Type Conversion10' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  rtb_DataTypeConversion10 =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BrakeLightStatus ? 1U : 0U;

  /* DataTypeConversion: '<S11>/Data Type Conversion2' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  rtb_DataTypeConversion2 =
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ActualControlStatus;

  /* DataTypeConversion: '<S11>/Data Type Conversion3' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  rtb_DataTypeConversion3 =
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_TargetGearPositionEcho;

  /* DataTypeConversion: '<S11>/Data Type Conversion4' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  rtb_DataTypeConversion4 = (uint8_T)
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_TargetBrakePedalEcho;

  /* DataTypeConversion: '<S11>/Data Type Conversion5' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  rtb_DataTypeConversion5 = (uint8_T)
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_TargetAccelPedalPostionEcho;

  /* DataTypeConversion: '<S11>/Data Type Conversion6' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  rtb_DataTypeConversion6 =
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveActiveStatus ? 1U :
    0U;

  /* DataTypeConversion: '<S11>/Data Type Conversion7' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  rtb_DataTypeConversion7 =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAcceleration;

  /* SignalConversion: '<S3>/Signal Conversion1' incorporates:
   *  Inport: '<Root>/LCC_DataBus'
   */
  DRIV_subsystem_integrated_B.SignalConversion1 =
    VsLCCS_DataBus.steering_control_engaged;

  /* SignalConversion: '<S3>/Signal Conversion' incorporates:
   *  Inport: '<Root>/ACCS_DataBus'
   */
  DRIV_subsystem_integrated_B.SignalConversion = VsACCS_DataBus.VeACCS_Mode;

  /* Update for UnitDelay: '<S7>/Unit Delay' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  DRIV_subsystem_integrated_DW.UnitDelay_DSTATE = VsOBFU_DataBus.timestamp_low;

  /* Update for UnitDelay: '<S7>/Unit Delay2' incorporates:
   *  Inport: '<Root>/MPFU_DataBus'
   */
  DRIV_subsystem_integrated_DW.UnitDelay2_DSTATE = VsMPFU_DataBus.timestamp_low;

  /* Update for UnitDelay: '<S7>/Unit Delay1' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  DRIV_subsystem_integrated_DW.UnitDelay1_DSTATE = VsEGMO_DataBus.timestamp_low;

  /* Update for Delay: '<S9>/Delay' */
  for (idxDelay = 0; idxDelay < 19; idxDelay++)
  {
    DRIV_subsystem_integrated_DW.Delay_DSTATE_dx3s[idxDelay] =
      DRIV_subsystem_integrated_DW.Delay_DSTATE_dx3s[idxDelay + 1];
  }

  DRIV_subsystem_integrated_DW.Delay_DSTATE_dx3s[19] = VfDRIV_steer_angle;

  /* End of Update for Delay: '<S9>/Delay' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
