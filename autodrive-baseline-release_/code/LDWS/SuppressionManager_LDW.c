/*
 * File: SuppressionManager_LDW.c
 *
 * Code generated for Simulink model 'LDWS_subsystem_integrated'.
 *
 * Model version                  : 1.384
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 11:19:43 2020
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

#include "SuppressionManager_LDW.h"

/* Include model header file for global data */
#include "LDWS_subsystem_integrated.h"
#include "LDWS_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S1>/SuppressionManager_LDW' */
void LDWS_sub_SuppressionManager_LDW(void)
{
  uint16_T rtb_CurrentTick;
  uint16_T rtb_CurrentTick_imij;
  uint16_T rtb_CurrentTick_do4g;
  real32_T rtb_Product_jdea;
  uint16_T rtb_CurrentTick_pr5k;
  uint16_T rtb_CurrentTick_p2wq;
  uint16_T rtb_CurrentTick_iqxa;
  uint16_T rtb_CurrentTick_noci;
  uint16_T rtb_CurrentTick_biib;

  /* SignalConversion: '<S7>/Signal Conversion' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  VbLDWS_LeIndicatorSt =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState;

  /* Switch: '<S36>/Switch1' incorporates:
   *  Constant: '<S34>/Constant8'
   *  Constant: '<S36>/Constant4'
   *  RelationalOperator: '<S34>/Relational Operator4'
   */
  if (VbLDWS_LeIndicatorSt == true)
  {
    /* Sum: '<S36>/Sum' incorporates:
     *  Constant: '<S34>/Constant13'
     *  UnitDelay: '<S36>/UnitDelay'
     */
    rtb_CurrentTick = (uint16_T)(((uint32_T)
      LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_n2v1) + ((uint32_T)
      KcLDWS_CntSample));

    /* Saturate: '<S36>/Saturation' */
    if (rtb_CurrentTick < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S36>/Saturation' */
  }
  else
  {
    rtb_CurrentTick = ((uint16_T)0U);
  }

  /* End of Switch: '<S36>/Switch1' */

  /* Switch: '<S37>/Switch1' incorporates:
   *  Constant: '<S34>/Constant5'
   *  Constant: '<S37>/Constant4'
   *  Inport: '<Root>/COMM_CANR_Databus'
   *  RelationalOperator: '<S34>/Relational Operator3'
   */
  if (VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle >
      KfLDWS_Ang_SuppSteerAngThrsh)
  {
    /* Sum: '<S37>/Sum' incorporates:
     *  Constant: '<S34>/Constant7'
     *  UnitDelay: '<S37>/UnitDelay'
     */
    rtb_CurrentTick_imij = (uint16_T)(((uint32_T)
      LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_o5hd) + ((uint32_T)
      KcLDWS_CntSample));

    /* Saturate: '<S37>/Saturation' */
    if (rtb_CurrentTick_imij < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick_imij = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S37>/Saturation' */
  }
  else
  {
    rtb_CurrentTick_imij = ((uint16_T)0U);
  }

  /* End of Switch: '<S37>/Switch1' */

  /* Switch: '<S38>/Switch1' incorporates:
   *  Constant: '<S34>/Constant2'
   *  Constant: '<S38>/Constant4'
   *  RelationalOperator: '<S34>/Relational Operator2'
   */
  if (VfLDWS_SteerAngleRate > KfLDWS_v_SuppSteerRateThrsh)
  {
    /* Sum: '<S38>/Sum' incorporates:
     *  Constant: '<S34>/Constant3'
     *  UnitDelay: '<S38>/UnitDelay'
     */
    rtb_CurrentTick_do4g = (uint16_T)(((uint32_T)
      LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_czjk) + ((uint32_T)
      KcLDWS_CntSample));

    /* Saturate: '<S38>/Saturation' */
    if (rtb_CurrentTick_do4g < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick_do4g = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S38>/Saturation' */
  }
  else
  {
    rtb_CurrentTick_do4g = ((uint16_T)0U);
  }

  /* End of Switch: '<S38>/Switch1' */

  /* Switch: '<S7>/Switch2' incorporates:
   *  Constant: '<S7>/Constant4'
   *  Constant: '<S7>/Constant5'
   */
  if (VfLDWS_SteerAngleRate > 0.0F)
  {
    rtb_Product_jdea = 1.0F;
  }
  else
  {
    rtb_Product_jdea = (-1.0F);
  }

  /* End of Switch: '<S7>/Switch2' */

  /* Product: '<S7>/Product' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  rtb_Product_jdea *=
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorque;

  /* Switch: '<S39>/Switch1' incorporates:
   *  Constant: '<S34>/Constant1'
   *  Constant: '<S39>/Constant4'
   *  RelationalOperator: '<S34>/Relational Operator1'
   */
  if (rtb_Product_jdea > KfLDWS_M_SuppTorque)
  {
    /* Sum: '<S39>/Sum' incorporates:
     *  Constant: '<S34>/Constant9'
     *  UnitDelay: '<S39>/UnitDelay'
     */
    rtb_CurrentTick_pr5k = (uint16_T)(((uint32_T)
      LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_l5ms) + ((uint32_T)
      KcLDWS_CntSample));

    /* Saturate: '<S39>/Saturation' */
    if (rtb_CurrentTick_pr5k < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick_pr5k = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S39>/Saturation' */
  }
  else
  {
    rtb_CurrentTick_pr5k = ((uint16_T)0U);
  }

  /* End of Switch: '<S39>/Switch1' */

  /* Logic: '<S34>/Logical Operator' incorporates:
   *  Constant: '<S34>/Constant10'
   *  Constant: '<S34>/Constant12'
   *  Constant: '<S34>/Constant4'
   *  Constant: '<S34>/Constant6'
   *  RelationalOperator: '<S36>/RelationalOperator1'
   *  RelationalOperator: '<S37>/RelationalOperator1'
   *  RelationalOperator: '<S38>/RelationalOperator1'
   *  RelationalOperator: '<S39>/RelationalOperator1'
   */
  VbLDWS_SuppLe = ((((rtb_CurrentTick > KfLDWS_t_SuppIndiTime) ||
                     (rtb_CurrentTick_imij > KfLDWS_t_SuppSteerAngTime)) ||
                    (rtb_CurrentTick_do4g > KfLDWS_t_SuppSteerRateTime)) ||
                   (rtb_CurrentTick_pr5k > KfLDWS_t_SuppTorqueTime));

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   */
  if (KbLDWS_SuppLeSwitch)
  {
    LDWS_subsystem_integrated_B.Switch = false;
  }
  else
  {
    LDWS_subsystem_integrated_B.Switch = VbLDWS_SuppLe;
  }

  /* End of Switch: '<S7>/Switch' */

  /* SignalConversion: '<S7>/Signal Conversion2' */
  VfLDWS_SteerTorque = rtb_Product_jdea;

  /* Switch: '<S43>/Switch1' incorporates:
   *  Constant: '<S35>/Constant1'
   *  Constant: '<S43>/Constant4'
   *  Gain: '<S35>/Gain'
   *  RelationalOperator: '<S35>/Relational Operator1'
   */
  if (VfLDWS_SteerTorque < ((-1.0F) * KfLDWS_M_SuppTorque))
  {
    /* Sum: '<S43>/Sum' incorporates:
     *  Constant: '<S35>/Constant9'
     *  UnitDelay: '<S43>/UnitDelay'
     */
    rtb_CurrentTick_p2wq = (uint16_T)(((uint32_T)
      LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_kcwr) + ((uint32_T)
      KcLDWS_CntSample));

    /* Saturate: '<S43>/Saturation' */
    if (rtb_CurrentTick_p2wq < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick_p2wq = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S43>/Saturation' */
  }
  else
  {
    rtb_CurrentTick_p2wq = ((uint16_T)0U);
  }

  /* End of Switch: '<S43>/Switch1' */

  /* SignalConversion: '<S7>/Signal Conversion1' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  VbLDWS_RiIndicatorSt =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState;

  /* Switch: '<S41>/Switch1' incorporates:
   *  Constant: '<S35>/Constant8'
   *  Constant: '<S41>/Constant4'
   *  RelationalOperator: '<S35>/Relational Operator'
   */
  if (VbLDWS_RiIndicatorSt == true)
  {
    /* Sum: '<S41>/Sum' incorporates:
     *  Constant: '<S35>/Constant13'
     *  UnitDelay: '<S41>/UnitDelay'
     */
    rtb_CurrentTick_iqxa = (uint16_T)(((uint32_T)
      LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_evoy) + ((uint32_T)
      KcLDWS_CntSample));

    /* Saturate: '<S41>/Saturation' */
    if (rtb_CurrentTick_iqxa < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick_iqxa = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S41>/Saturation' */
  }
  else
  {
    rtb_CurrentTick_iqxa = ((uint16_T)0U);
  }

  /* End of Switch: '<S41>/Switch1' */

  /* Switch: '<S40>/Switch1' incorporates:
   *  Constant: '<S35>/Constant14'
   *  Constant: '<S40>/Constant4'
   *  Gain: '<S35>/Gain1'
   *  Inport: '<Root>/COMM_CANR_Databus'
   *  RelationalOperator: '<S35>/Relational Operator3'
   */
  if (VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle < ((-1.0F) *
       KfLDWS_Ang_SuppSteerAngThrsh))
  {
    /* Sum: '<S40>/Sum' incorporates:
     *  Constant: '<S35>/Constant3'
     *  UnitDelay: '<S40>/UnitDelay'
     */
    rtb_CurrentTick_noci = (uint16_T)(((uint32_T)
      LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_p1ve) + ((uint32_T)
      KcLDWS_CntSample));

    /* Saturate: '<S40>/Saturation' */
    if (rtb_CurrentTick_noci < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick_noci = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S40>/Saturation' */
  }
  else
  {
    rtb_CurrentTick_noci = ((uint16_T)0U);
  }

  /* End of Switch: '<S40>/Switch1' */

  /* Switch: '<S42>/Switch1' incorporates:
   *  Constant: '<S35>/Constant11'
   *  Constant: '<S42>/Constant4'
   *  Gain: '<S35>/Gain2'
   *  RelationalOperator: '<S35>/Relational Operator2'
   */
  if (VfLDWS_SteerAngleRate < ((-1.0F) * KfLDWS_v_SuppSteerRateThrsh))
  {
    /* Sum: '<S42>/Sum' incorporates:
     *  Constant: '<S35>/Constant7'
     *  UnitDelay: '<S42>/UnitDelay'
     */
    rtb_CurrentTick_biib = (uint16_T)(((uint32_T)
      LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_jqfz) + ((uint32_T)
      KcLDWS_CntSample));

    /* Saturate: '<S42>/Saturation' */
    if (rtb_CurrentTick_biib < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick_biib = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S42>/Saturation' */
  }
  else
  {
    rtb_CurrentTick_biib = ((uint16_T)0U);
  }

  /* End of Switch: '<S42>/Switch1' */

  /* Logic: '<S35>/Logical Operator1' incorporates:
   *  Constant: '<S35>/Constant10'
   *  Constant: '<S35>/Constant12'
   *  Constant: '<S35>/Constant4'
   *  Constant: '<S35>/Constant6'
   *  RelationalOperator: '<S40>/RelationalOperator1'
   *  RelationalOperator: '<S41>/RelationalOperator1'
   *  RelationalOperator: '<S42>/RelationalOperator1'
   *  RelationalOperator: '<S43>/RelationalOperator1'
   */
  VbLDWS_SuppRi = ((((rtb_CurrentTick_iqxa > KfLDWS_t_SuppIndiTime) ||
                     (rtb_CurrentTick_noci > KfLDWS_t_SuppSteerAngTime)) ||
                    (rtb_CurrentTick_biib > KfLDWS_t_SuppSteerRateTime)) ||
                   (rtb_CurrentTick_p2wq > KfLDWS_t_SuppTorqueTime));

  /* Switch: '<S7>/Switch1' incorporates:
   *  Constant: '<S7>/Constant2'
   *  Constant: '<S7>/Constant3'
   */
  if (KbLDWS_SuppRiSwitch)
  {
    LDWS_subsystem_integrated_B.Switch1 = false;
  }
  else
  {
    LDWS_subsystem_integrated_B.Switch1 = VbLDWS_SuppRi;
  }

  /* End of Switch: '<S7>/Switch1' */

  /* Update for UnitDelay: '<S36>/UnitDelay' */
  LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_n2v1 = rtb_CurrentTick;

  /* Update for UnitDelay: '<S37>/UnitDelay' */
  LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_o5hd = rtb_CurrentTick_imij;

  /* Update for UnitDelay: '<S38>/UnitDelay' */
  LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_czjk = rtb_CurrentTick_do4g;

  /* Update for UnitDelay: '<S39>/UnitDelay' */
  LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_l5ms = rtb_CurrentTick_pr5k;

  /* Update for UnitDelay: '<S43>/UnitDelay' */
  LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_kcwr = rtb_CurrentTick_p2wq;

  /* Update for UnitDelay: '<S41>/UnitDelay' */
  LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_evoy = rtb_CurrentTick_iqxa;

  /* Update for UnitDelay: '<S40>/UnitDelay' */
  LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_p1ve = rtb_CurrentTick_noci;

  /* Update for UnitDelay: '<S42>/UnitDelay' */
  LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_jqfz = rtb_CurrentTick_biib;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
