/*
 * File: EnablingManager_LDW.c
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

#include "EnablingManager_LDW.h"

/* Include model header file for global data */
#include "LDWS_subsystem_integrated.h"
#include "LDWS_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S1>/EnablingManager_LDW' */
void LDWS_subsys_EnablingManager_LDW(void)
{
  int32_T i;
  int32_T j;
  uint16_T rtb_CurrentTick;
  uint16_T rtb_CurrentTick_au0o;
  uint16_T rtb_CurrentTick_nopr;
  uint16_T rtb_CurrentTick_pb4t;
  uint16_T rtb_CurrentTick_jstu;
  uint16_T rtb_CurrentTick_f1sl;
  uint16_T rtb_CurrentTick_errd;
  uint16_T rtb_CurrentTick_h5vm;
  boolean_T rtb_Y_dtdo;

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant3'
   *  Inport: '<Root>/EGMO_DataBus'
   *  Inport: '<Root>/MPFU_DataBus'
   *  UnitDelay: '<S14>/Unit Delay'
   */
  VbLDWS_CurvValid = false;
  VbLDWS_WidthValid = false;
  VbLDWS_LnMkrValid = false;
  for (i = 0; i < 8; i++)
  {
    if (((VsMPFU_DataBus.lanes[i].id == 0) && (VsMPFU_DataBus.lanes[i].width <
          KfLDWS_d_LnWidthUprBnd)) && (VsMPFU_DataBus.lanes[i].width >
         KfLDWS_d_LnWidthLwrBnd))
    {
      VbLDWS_WidthValid = true;
    }
  }

  if (VsEGMO_DataBus.motion.linear_velocity < 17.0F)
  {
    VbLDWS_CurvValid = true;
  }

  if (((VsEGMO_DataBus.motion.linear_velocity > 17.0F) &&
       (VsEGMO_DataBus.motion.linear_velocity < 20.0F)) && (((real32_T)fabs
        ((real_T)VfLDWS_Curvature)) < KfLDWS_c_CurvUprBnd))
  {
    VbLDWS_CurvValid = true;
  }

  if ((VsEGMO_DataBus.motion.linear_velocity > 20.0F) && (((real32_T)fabs
        ((real_T)VfLDWS_Curvature)) < KfLDWS_c_CurvLwrBnd))
  {
    VbLDWS_CurvValid = true;
  }

  for (i = 0; i < 16; i++)
  {
    for (j = 0; j < 16; j++)
    {
      if ((VsMPFU_DataBus.lane_markers[i].id == 1) &&
          (VsMPFU_DataBus.lane_markers[j].id == 2))
      {
        VbLDWS_LnMkrValid = true;
      }

      if (LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_nlrv)
      {
        if (VsMPFU_DataBus.lane_markers[i].id == 1)
        {
          VbLDWS_LnMkrValid = true;
        }
        else
        {
          if (VsMPFU_DataBus.lane_markers[j].id == 2)
          {
            VbLDWS_LnMkrValid = true;
          }
        }
      }
    }
  }

  /* End of MATLAB Function: '<S3>/MATLAB Function' */

  /* Switch: '<S16>/Switch1' incorporates:
   *  Constant: '<S16>/Constant4'
   *  Logic: '<S12>/Logical Operator1'
   */
  if (!VbLDWS_LnMkrValid)
  {
    /* Sum: '<S16>/Sum' incorporates:
     *  Constant: '<S12>/Constant4'
     *  UnitDelay: '<S16>/UnitDelay'
     */
    rtb_CurrentTick = (uint16_T)(((uint32_T)
      LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_jukp) + ((uint32_T)
      KcLDWS_CntSample));

    /* Saturate: '<S16>/Saturation' */
    if (rtb_CurrentTick < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S16>/Saturation' */
  }
  else
  {
    rtb_CurrentTick = ((uint16_T)0U);
  }

  /* End of Switch: '<S16>/Switch1' */

  /* MATLAB Function: '<S3>/MATLAB Function1' incorporates:
   *  Constant: '<S3>/Constant4'
   *  Constant: '<S3>/Constant5'
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VbLDWS_SpdRngValid = false;
  if ((VsEGMO_DataBus.motion.linear_velocity < KfLDWS_v_SpdUprBnd) &&
      (VsEGMO_DataBus.motion.linear_velocity > KfLDWS_v_SpdLwrBnd))
  {
    VbLDWS_SpdRngValid = true;
  }

  /* End of MATLAB Function: '<S3>/MATLAB Function1' */

  /* Switch: '<S18>/Switch1' incorporates:
   *  Constant: '<S18>/Constant4'
   *  Logic: '<S12>/Logical Operator3'
   */
  if (!VbLDWS_SpdRngValid)
  {
    /* Sum: '<S18>/Sum' incorporates:
     *  Constant: '<S12>/Constant3'
     *  UnitDelay: '<S18>/UnitDelay'
     */
    rtb_CurrentTick_au0o = (uint16_T)(((uint32_T)
      LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_p1mq) + ((uint32_T)
      KcLDWS_CntSample));

    /* Saturate: '<S18>/Saturation' */
    if (rtb_CurrentTick_au0o < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick_au0o = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S18>/Saturation' */
  }
  else
  {
    rtb_CurrentTick_au0o = ((uint16_T)0U);
  }

  /* End of Switch: '<S18>/Switch1' */

  /* Switch: '<S15>/Switch1' incorporates:
   *  Constant: '<S15>/Constant4'
   *  Logic: '<S12>/Logical Operator2'
   */
  if (!VbLDWS_CurvValid)
  {
    /* Sum: '<S15>/Sum' incorporates:
     *  Constant: '<S12>/Constant1'
     *  UnitDelay: '<S15>/UnitDelay'
     */
    rtb_CurrentTick_nopr = (uint16_T)(((uint32_T)
      LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_g1ck) + ((uint32_T)
      KcLDWS_CntSample));

    /* Saturate: '<S15>/Saturation' */
    if (rtb_CurrentTick_nopr < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick_nopr = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S15>/Saturation' */
  }
  else
  {
    rtb_CurrentTick_nopr = ((uint16_T)0U);
  }

  /* End of Switch: '<S15>/Switch1' */

  /* Switch: '<S17>/Switch1' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Logic: '<S12>/Logical Operator5'
   */
  if (!VbLDWS_WidthValid)
  {
    /* Sum: '<S17>/Sum' incorporates:
     *  Constant: '<S12>/Constant2'
     *  UnitDelay: '<S17>/UnitDelay'
     */
    rtb_CurrentTick_pb4t = (uint16_T)(((uint32_T)
      LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_oro1) + ((uint32_T)
      KcLDWS_CntSample));

    /* Saturate: '<S17>/Saturation' */
    if (rtb_CurrentTick_pb4t < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick_pb4t = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S17>/Saturation' */
  }
  else
  {
    rtb_CurrentTick_pb4t = ((uint16_T)0U);
  }

  /* End of Switch: '<S17>/Switch1' */

  /* Switch: '<S19>/Switch1' incorporates:
   *  Constant: '<S19>/Constant4'
   */
  if (VbLDWS_SpdRngValid)
  {
    /* Sum: '<S19>/Sum' incorporates:
     *  Constant: '<S14>/Constant'
     *  UnitDelay: '<S19>/UnitDelay'
     */
    rtb_CurrentTick_jstu = (uint16_T)(((uint32_T)
      LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_oikr) + ((uint32_T)
      KcLDWS_CntSample));

    /* Saturate: '<S19>/Saturation' */
    if (rtb_CurrentTick_jstu < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick_jstu = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S19>/Saturation' */
  }
  else
  {
    rtb_CurrentTick_jstu = ((uint16_T)0U);
  }

  /* End of Switch: '<S19>/Switch1' */

  /* Switch: '<S20>/Switch1' incorporates:
   *  Constant: '<S20>/Constant4'
   */
  if (VbLDWS_CurvValid)
  {
    /* Sum: '<S20>/Sum' incorporates:
     *  Constant: '<S14>/Constant1'
     *  UnitDelay: '<S20>/UnitDelay'
     */
    rtb_CurrentTick_f1sl = (uint16_T)(((uint32_T)
      LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_o1j0) + ((uint32_T)
      KcLDWS_CntSample));

    /* Saturate: '<S20>/Saturation' */
    if (rtb_CurrentTick_f1sl < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick_f1sl = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S20>/Saturation' */
  }
  else
  {
    rtb_CurrentTick_f1sl = ((uint16_T)0U);
  }

  /* End of Switch: '<S20>/Switch1' */

  /* Switch: '<S21>/Switch1' incorporates:
   *  Constant: '<S21>/Constant4'
   */
  if (VbLDWS_WidthValid)
  {
    /* Sum: '<S21>/Sum' incorporates:
     *  Constant: '<S14>/Constant2'
     *  UnitDelay: '<S21>/UnitDelay'
     */
    rtb_CurrentTick_errd = (uint16_T)(((uint32_T)
      LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_cieb) + ((uint32_T)
      KcLDWS_CntSample));

    /* Saturate: '<S21>/Saturation' */
    if (rtb_CurrentTick_errd < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick_errd = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S21>/Saturation' */
  }
  else
  {
    rtb_CurrentTick_errd = ((uint16_T)0U);
  }

  /* End of Switch: '<S21>/Switch1' */

  /* Switch: '<S22>/Switch1' incorporates:
   *  Constant: '<S22>/Constant4'
   */
  if (VbLDWS_LnMkrValid)
  {
    /* Sum: '<S22>/Sum' incorporates:
     *  Constant: '<S14>/Constant3'
     *  UnitDelay: '<S22>/UnitDelay'
     */
    rtb_CurrentTick_h5vm = (uint16_T)(((uint32_T)
      LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_pduf) + ((uint32_T)
      KcLDWS_CntSample));

    /* Saturate: '<S22>/Saturation' */
    if (rtb_CurrentTick_h5vm < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick_h5vm = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S22>/Saturation' */
  }
  else
  {
    rtb_CurrentTick_h5vm = ((uint16_T)0U);
  }

  /* End of Switch: '<S22>/Switch1' */

  /* RelationalOperator: '<S22>/RelationalOperator1' incorporates:
   *  Constant: '<S14>/Constant9'
   */
  rtb_Y_dtdo = (rtb_CurrentTick_h5vm > KfLDWS_t_LnMkrValidTime);

  /* Logic: '<S13>/LogOp3' incorporates:
   *  Constant: '<S12>/Constant14'
   *  Constant: '<S12>/Constant15'
   *  Constant: '<S12>/Constant16'
   *  Constant: '<S12>/Constant20'
   *  Constant: '<S14>/Constant6'
   *  Constant: '<S14>/Constant7'
   *  Constant: '<S14>/Constant8'
   *  Logic: '<S12>/Logical Operator4'
   *  Logic: '<S13>/LogOp'
   *  Logic: '<S13>/LogOp2'
   *  Logic: '<S14>/Logical Operator'
   *  RelationalOperator: '<S15>/RelationalOperator1'
   *  RelationalOperator: '<S16>/RelationalOperator1'
   *  RelationalOperator: '<S17>/RelationalOperator1'
   *  RelationalOperator: '<S18>/RelationalOperator1'
   *  RelationalOperator: '<S19>/RelationalOperator1'
   *  RelationalOperator: '<S20>/RelationalOperator1'
   *  RelationalOperator: '<S21>/RelationalOperator1'
   *  UnitDelay: '<S13>/UnitDelay1'
   *
   * Block description for '<S13>/LogOp':
   *  _3p2p0.CLib.000_19_
   *
   * Block description for '<S13>/UnitDelay1':
   *  _3p2p0.CLib.000_22_
   */
  VbLDWS_EnabledLDW = (((((rtb_CurrentTick_jstu > KfLDWS_t_SpdRngValidTime) &&
    (rtb_CurrentTick_f1sl > KfLDWS_t_CurvValidTime)) && (rtb_CurrentTick_errd >
    KfLDWS_t_LnWidthValidTime)) && rtb_Y_dtdo) || ((!((((rtb_CurrentTick_au0o >
    KfLDWS_t_SpdRngNotValidTime) || (rtb_CurrentTick_nopr >
    KfLDWS_t_CurvNotValidTime)) || (rtb_CurrentTick_pb4t >
    KfLDWS_t_LnWidthNotValidTime)) || (rtb_CurrentTick >
    KfLDWS_t_LnMkrNotValidTime))) && VbLDWS_EnabledLDW));

  /* Update for UnitDelay: '<S14>/Unit Delay' */
  LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_nlrv = rtb_Y_dtdo;

  /* Update for UnitDelay: '<S16>/UnitDelay' */
  LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_jukp = rtb_CurrentTick;

  /* Update for UnitDelay: '<S18>/UnitDelay' */
  LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_p1mq = rtb_CurrentTick_au0o;

  /* Update for UnitDelay: '<S15>/UnitDelay' */
  LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_g1ck = rtb_CurrentTick_nopr;

  /* Update for UnitDelay: '<S17>/UnitDelay' */
  LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_oro1 = rtb_CurrentTick_pb4t;

  /* Update for UnitDelay: '<S19>/UnitDelay' */
  LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_oikr = rtb_CurrentTick_jstu;

  /* Update for UnitDelay: '<S20>/UnitDelay' */
  LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_o1j0 = rtb_CurrentTick_f1sl;

  /* Update for UnitDelay: '<S21>/UnitDelay' */
  LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_cieb = rtb_CurrentTick_errd;

  /* Update for UnitDelay: '<S22>/UnitDelay' */
  LDWS_subsystem_integrated_DW.UnitDelay_DSTATE_pduf = rtb_CurrentTick_h5vm;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
