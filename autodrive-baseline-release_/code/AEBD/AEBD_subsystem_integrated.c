/*
 * File: AEBD_subsystem_integrated.c
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

#include "AEBD_subsystem_integrated.h"
#include "AEBD_subsystem_integrated_private.h"

/* Exported block signals */
real32_T VfAEBD_AEB_a;                 /* '<S1>/Rate Transition3' */
uint16_T VcAEBD_ErrorCount;            /* '<S1>/Dtrmn_AEBD_Function' */
uint8_T VfAEBD_t_DelayTime;            /* '<S1>/Dtrmn_AEBD_Function' */
boolean_T VbAEBD_Error;                /* '<S1>/Dtrmn_AEBD_Function' */
boolean_T VbAEBD_Suppress;             /* '<S1>/Rate Transition' */
boolean_T VbAEBD_Pedoff;               /* '<S1>/Rate Transition1' */
boolean_T VbAEBD_AEBaError;            /* '<S1>/Rate Transition4' */
boolean_T VbAEBD_AEBrequest;           /* '<S1>/Rate Transition2' */
#pragma section ".cal" 
/* Exported block parameters */
real32_T KfAEBD_a_AccelDeviation = 1.0F;/* Variable: KfAEBD_a_AccelDeviation
                                         * Referenced by: '<S1>/Constant6'
                                         */
uint16_T KcAEBD_ErrorCountThrsh = 50U; /* Variable: KcAEBD_ErrorCountThrsh
                                        * Referenced by: '<S1>/Constant8'
                                        */
uint8_T KfAEBD_t_WaitTimeThrsh = 20U;  /* Variable: KfAEBD_t_WaitTimeThrsh
                                        * Referenced by: '<S1>/Constant7'
                                        */
boolean_T KbAEBD_ADCU_CANError = 0;    /* Variable: KbAEBD_ADCU_CANError
                                        * Referenced by: '<S1>/Constant10'
                                        */
boolean_T KbAEBD_AccelerationSensorError = 0;/* Variable: KbAEBD_AccelerationSensorError
                                              * Referenced by: '<S1>/Constant9'
                                              */
boolean_T KbAEBD_ESCError = 0;         /* Variable: KbAEBD_ESCError
                                        * Referenced by: '<S1>/Constant11'
                                        */
boolean_T KbAEBD_ErrorClear = 0;       /* Variable: KbAEBD_ErrorClear
                                        * Referenced by: '<S1>/Constant12'
                                        */
#pragma section 
/* Block states (auto storage) */
DW_AEBD_subsystem_integrated_T AEBD_subsystem_integrated_DW;

/* Model step function */
void AEBD_subsystem_integrated_step(void)
{
  boolean_T rtb_AEB_a_error;
  boolean_T rtb_Compare;
  boolean_T rtb_error_suppress_satisfy;
  int32_T tmp;
  uint32_T qY;

  /* Outputs for Atomic SubSystem: '<Root>/AEBD_Subsystem' */
  /* RelationalOperator: '<S1>/Relational Operator1' incorporates:
   *  Abs: '<S1>/Abs'
   *  Constant: '<S1>/Constant6'
   *  Inport: '<Root>/VsAEBS_DataBus'
   *  Inport: '<Root>/VsCOMM_JAC_Bus_FedBck_Data'
   *  Sum: '<S1>/Subtract'
   */
  rtb_AEB_a_error = (((real32_T)fabs((real_T)((real32_T)
    (VsCOMM_JAC_Bus_FedBck_Data.FedBck_VehDynmc.VCU1_ICPV_LongAcc -
     VsAEBS_DataBus.AEB_Data.AEB_acceleration_req)))) > KfAEBD_a_AccelDeviation);

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   *  Inport: '<Root>/VsCOMM_JAC_Bus_FedBck_Data'
   */
  rtb_Compare = (VsCOMM_JAC_Bus_FedBck_Data.FedBck_Brake.Decs_FedBck_BrkPedSts ==
                 ((uint8_T)1U));

  /* Logic: '<S1>/Logical Operator' incorporates:
   *  Constant: '<S1>/Constant10'
   *  Constant: '<S1>/Constant9'
   *  Inport: '<Root>/VsCOMM_JAC_Bus_FedBck_Data'
   */
  rtb_error_suppress_satisfy = ((KbAEBD_AccelerationSensorError ||
    KbAEBD_ADCU_CANError) || (((int32_T)
    VsCOMM_JAC_Bus_FedBck_Data.FedBck_Brake.ESC_FaultStatus) != 0));

  /* MATLAB Function: '<S1>/Dtrmn_AEBD_Function' incorporates:
   *  Constant: '<S1>/Constant12'
   *  Constant: '<S1>/Constant7'
   *  Constant: '<S1>/Constant8'
   *  Inport: '<Root>/VsAEBS_DataBus'
   *  Inport: '<Root>/VsDCSN_DataBus'
   */
  if (KbAEBD_ErrorClear)
  {
    AEBD_subsystem_integrated_DW.error_count = 0U;
    AEBD_subsystem_integrated_DW.delay_time = 0U;
    AEBD_subsystem_integrated_DW.AEBD_Error = false;
  }
  else if (rtb_error_suppress_satisfy)
  {
    AEBD_subsystem_integrated_DW.error_count = 0U;
    AEBD_subsystem_integrated_DW.delay_time = 0U;
  }
  else if (((VsAEBS_DataBus.AEB_Data.AEB_request) &&
            (VsDCSN_DataBus.EnablingFlags_Group.aeb_feature_enable)) &&
           rtb_Compare)
  {
    if (AEBD_subsystem_integrated_DW.delay_time > KfAEBD_t_WaitTimeThrsh)
    {
      if (rtb_AEB_a_error)
      {
        qY = ((uint32_T)AEBD_subsystem_integrated_DW.error_count) + 1U;
        if (qY > 65535U)
        {
          qY = 65535U;
        }

        if (((uint16_T)qY) < KcAEBD_ErrorCountThrsh)
        {
          AEBD_subsystem_integrated_DW.error_count = (uint16_T)qY;
        }
        else
        {
          AEBD_subsystem_integrated_DW.error_count = KcAEBD_ErrorCountThrsh;
        }
      }
      else if (((int32_T)AEBD_subsystem_integrated_DW.error_count) <= 1)
      {
        AEBD_subsystem_integrated_DW.error_count = 0U;
      }
      else
      {
        qY = ((uint32_T)AEBD_subsystem_integrated_DW.error_count) -
          /*MW:OvSatOk*/ 1U;
        if (qY > ((uint32_T)AEBD_subsystem_integrated_DW.error_count))
        {
          qY = 0U;
        }

        AEBD_subsystem_integrated_DW.error_count = (uint16_T)qY;
      }

      if (AEBD_subsystem_integrated_DW.AEBD_Error)
      {
        if (((int32_T)AEBD_subsystem_integrated_DW.error_count) == 0)
        {
          AEBD_subsystem_integrated_DW.AEBD_Error = false;
        }
      }
      else
      {
        if (AEBD_subsystem_integrated_DW.error_count >= KcAEBD_ErrorCountThrsh)
        {
          AEBD_subsystem_integrated_DW.AEBD_Error = true;
        }
      }
    }
    else
    {
      tmp = (int32_T)((uint32_T)(((uint32_T)
        AEBD_subsystem_integrated_DW.delay_time) + 1U));
      if (((uint32_T)tmp) > 255U)
      {
        tmp = 255;
      }

      AEBD_subsystem_integrated_DW.delay_time = (uint8_T)tmp;
    }
  }
  else
  {
    AEBD_subsystem_integrated_DW.delay_time = 0U;
  }

  VcAEBD_ErrorCount = AEBD_subsystem_integrated_DW.error_count;
  VfAEBD_t_DelayTime = AEBD_subsystem_integrated_DW.delay_time;

  /* SignalConversion: '<S1>/TmpBlkForSigObjICAtDtrmn_AEBD_FunctionOutport1' incorporates:
   *  MATLAB Function: '<S1>/Dtrmn_AEBD_Function'
   */
  VbAEBD_Error = AEBD_subsystem_integrated_DW.AEBD_Error;

  /* RateTransition: '<S1>/Rate Transition' */
  VbAEBD_Suppress = rtb_error_suppress_satisfy;

  /* RateTransition: '<S1>/Rate Transition1' */
  VbAEBD_Pedoff = rtb_Compare;

  /* RateTransition: '<S1>/Rate Transition4' */
  VbAEBD_AEBaError = rtb_AEB_a_error;

  /* RateTransition: '<S1>/Rate Transition2' incorporates:
   *  Inport: '<Root>/VsAEBS_DataBus'
   */
  VbAEBD_AEBrequest = VsAEBS_DataBus.AEB_Data.AEB_request;

  /* RateTransition: '<S1>/Rate Transition3' incorporates:
   *  Inport: '<Root>/VsAEBS_DataBus'
   */
  VfAEBD_AEB_a = VsAEBS_DataBus.AEB_Data.AEB_acceleration_req;

  /* End of Outputs for SubSystem: '<Root>/AEBD_Subsystem' */
}

/* Model initialize function */
void AEBD_subsystem_integrated_initialize(void)
{
  /* Registration code */

  /* block I/O */

  /* exported global signals */
  VfAEBD_AEB_a = 0.0F;
  VcAEBD_ErrorCount = 0U;
  VfAEBD_t_DelayTime = 0U;
  VbAEBD_Error = false;
  VbAEBD_Suppress = false;
  VbAEBD_Pedoff = true;
  VbAEBD_AEBaError = false;
  VbAEBD_AEBrequest = false;

  /* states (dwork) */
  (void) memset((void *)&AEBD_subsystem_integrated_DW, 0,
                sizeof(DW_AEBD_subsystem_integrated_T));

  /* SystemInitialize for Atomic SubSystem: '<Root>/AEBD_Subsystem' */
  /* SystemInitialize for MATLAB Function: '<S1>/Dtrmn_AEBD_Function' */
  AEBD_subsystem_integrated_DW.error_count = 0U;
  AEBD_subsystem_integrated_DW.delay_time = 0U;
  AEBD_subsystem_integrated_DW.AEBD_Error = false;

  /* End of SystemInitialize for SubSystem: '<Root>/AEBD_Subsystem' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
