/*
 * File: LaneMarkerHandler.c
 *
 * Code generated for Simulink model 'LKAS_subsystem_integrated'.
 *
 * Model version                  : 1.102
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 11:05:35 2020
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

#include "LaneMarkerHandler.h"

/* Include model header file for global data */
#include "LKAS_subsystem_integrated.h"
#include "LKAS_subsystem_integrated_private.h"

/* System initialize for atomic system: '<S5>/LaneMarkerHandler' */
void LKAS_sub_LaneMarkerHandler_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S175>/Unit Delay3' */
  LKAS_subsystem_integrated_DW.UnitDelay3_DSTATE_omwh = LKAS_NoIntvTyp;

  /* InitializeConditions for UnitDelay: '<S175>/Unit Delay4' */
  LKAS_subsystem_integrated_DW.UnitDelay4_DSTATE = LKAS_NoIntvSide;
}

/* Outputs for atomic system: '<S5>/LaneMarkerHandler' */
void LKAS_subsyste_LaneMarkerHandler(void)
{
  real32_T rtb_Heading;
  int32_T i;
  boolean_T rtb_VectorConcatenate1_idx_0;
  boolean_T rtb_VectorConcatenate1_idx_1;
  uint8_T tmp;

  /* MATLAB Function: '<S181>/MATLAB Function1' incorporates:
   *  Inport: '<Root>/MPFU_DataBus'
   */
  VfLAKS_LeC0 = 0.0F;
  VfLAKS_LeC1 = 0.0F;
  VfLKAS_LeC2 = 0.0F;
  VfLKAS_LeLength = 0.0F;
  for (i = 0; i < 16; i++)
  {
    if (VsMPFU_DataBus.lane_markers[i].id == 1)
    {
      VfLAKS_LeC0 = VsMPFU_DataBus.lane_markers[i].c0_position;
      VfLAKS_LeC1 = VsMPFU_DataBus.lane_markers[i].c1_heading;
      VfLKAS_LeC2 = VsMPFU_DataBus.lane_markers[i].c2_curvature;
      VfLKAS_LeLength = VsMPFU_DataBus.lane_markers[i].end_rel.x -
        VsMPFU_DataBus.lane_markers[i].start_rel.x;
    }
  }

  /* End of MATLAB Function: '<S181>/MATLAB Function1' */

  /* Gain: '<S181>/Gain' */
  LKAS_subsystem_integrated_B.Gain = 2.0F * VfLKAS_LeC2;

  /* SignalConversion: '<S193>/Signal Conversion' */
  LKAS_subsystem_integrated_B.Out = LKAS_subsystem_integrated_B.Gain;

  /* MATLAB Function: '<S182>/MATLAB Function' incorporates:
   *  Inport: '<Root>/MPFU_DataBus'
   */
  VfLKAS_RiC0 = 0.0F;
  VfLKAS_RiC1 = 0.0F;
  VfLKAS_RiC2 = 0.0F;
  VfLKAS_Ri_Length = 0.0F;
  for (i = 0; i < 16; i++)
  {
    if (VsMPFU_DataBus.lane_markers[i].id == 2)
    {
      VfLKAS_RiC0 = VsMPFU_DataBus.lane_markers[i].c0_position;
      VfLKAS_RiC1 = VsMPFU_DataBus.lane_markers[i].c1_heading;
      VfLKAS_RiC2 = VsMPFU_DataBus.lane_markers[i].c2_curvature;
      VfLKAS_Ri_Length = VsMPFU_DataBus.lane_markers[i].end_rel.x -
        VsMPFU_DataBus.lane_markers[i].start_rel.x;
    }
  }

  /* End of MATLAB Function: '<S182>/MATLAB Function' */

  /* Gain: '<S182>/Gain' */
  LKAS_subsystem_integrated_B.Gain_l52z = 2.0F * VfLKAS_RiC2;

  /* SignalConversion: '<S209>/Signal Conversion' */
  LKAS_subsystem_integrated_B.Out_oslf = LKAS_subsystem_integrated_B.Gain_l52z;

  /* MATLAB Function: '<S180>/MATLAB Function' incorporates:
   *  Inport: '<Root>/MPFU_DataBus'
   */
  VfLKAS_QlyRi = 0U;
  VfLKAS_QlyLe = 0U;
  for (i = 0; i < 16; i++)
  {
    if (VsMPFU_DataBus.lane_markers[i].id == 1)
    {
      VfLKAS_QlyLe = VsMPFU_DataBus.lane_markers[i].quality;
    }

    if (VsMPFU_DataBus.lane_markers[i].id == 2)
    {
      VfLKAS_QlyRi = VsMPFU_DataBus.lane_markers[i].quality;
    }
  }

  /* End of MATLAB Function: '<S180>/MATLAB Function' */

  /* RelationalOperator: '<S180>/RELOP_1' incorporates:
   *  Constant: '<S180>/k_LKA_QlyVld'
   *
   * Block description for '<S180>/k_LKA_QlyVld':
   *  _V3p4.LDW2.000_394_
   */
  VbLKAS_QlyValidLe = (VfLKAS_QlyLe >= KfLKAS_r_QlyVld);

  /* Gain: '<S181>/G_3' incorporates:
   *  Trigonometry: '<S181>/ATAN_1'
   */
  rtb_Heading = (-1.0F) * ((real32_T)atan((real_T)VfLAKS_LeC1));

  /* Product: '<S181>/PROD_5' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   *  Trigonometry: '<S181>/SIN_1'
   */
  VfLKAS_V_Latleft = VsEGMO_DataBus.motion.velocity_rel.x * ((real32_T)sin
    ((real_T)rtb_Heading));

  /* Logic: '<S200>/LOGOP_4' incorporates:
   *  Abs: '<S200>/Abs'
   *  Constant: '<S190>/k_LKA_V_MaxStepForVLat1'
   *  RelationalOperator: '<S200>/RELOP_2'
   *  Sum: '<S200>/SUM_1'
   *  UnitDelay: '<S200>/UD_1'
   *
   * Block description for '<S200>/Abs':
   *  _V4p0.LDW2.000_66_
   *
   * Block description for '<S190>/k_LKA_V_MaxStepForVLat1':
   *  _V4p0.LDW2.000_68_
   *
   * Block description for '<S200>/RELOP_2':
   *  _V4p0.LDW2.000_69_
   *
   * Block description for '<S200>/SUM_1':
   *  _V3p4.LDW2.000_546_
   *
   * Block description for '<S200>/UD_1':
   *  _V3p4.LDW2.000_548_
   */
  VbLKAS_LeftVLatStep = (VbLKAS_QlyValidLe && (((real32_T)fabs((real_T)
    ((real32_T)(VfLKAS_V_Latleft - LKAS_subsystem_integrated_DW.UD_1_DSTATE)))) >
    KfLKAS_v_MaxStepForVLat));

  /* Logic: '<S198>/LOGOP_4' incorporates:
   *  Abs: '<S198>/Abs'
   *  Constant: '<S188>/k_LKA_Cr_MaxCurvStep1'
   *  RelationalOperator: '<S198>/RELOP_2'
   *  Sum: '<S198>/SUM_1'
   *  UnitDelay: '<S198>/UD_1'
   *
   * Block description for '<S198>/Abs':
   *  _V4p0.LDW2.000_66_
   *
   * Block description for '<S188>/k_LKA_Cr_MaxCurvStep1':
   *  _V4p0.LDW2.000_68_
   *
   * Block description for '<S198>/RELOP_2':
   *  _V4p0.LDW2.000_69_
   *
   * Block description for '<S198>/SUM_1':
   *  _V3p4.LDW2.000_546_
   *
   * Block description for '<S198>/UD_1':
   *  _V3p4.LDW2.000_548_
   */
  VbLKAS_LeftCurvStep = (VbLKAS_QlyValidLe && (((real32_T)fabs((real_T)
    ((real32_T)(LKAS_subsystem_integrated_B.Gain -
                LKAS_subsystem_integrated_DW.UD_1_DSTATE_hhbh)))) >
    KfLKAS_c_MaxCurvStep));

  /* Product: '<S181>/PROD_6' incorporates:
   *  Trigonometry: '<S181>/COS_1'
   */
  VfLKAS_L_OffstLeft = VfLAKS_LeC0 * ((real32_T)cos((real_T)rtb_Heading));

  /* Logic: '<S199>/LOGOP_4' incorporates:
   *  Abs: '<S199>/Abs'
   *  Constant: '<S189>/k_LKA_L_MaxOffstStep'
   *  RelationalOperator: '<S199>/RELOP_2'
   *  Sum: '<S199>/SUM_1'
   *  UnitDelay: '<S199>/UD_1'
   *
   * Block description for '<S199>/Abs':
   *  _V4p0.LDW2.000_66_
   *
   * Block description for '<S189>/k_LKA_L_MaxOffstStep':
   *  _V4p0.LDW2.000_68_
   *
   * Block description for '<S199>/RELOP_2':
   *  _V4p0.LDW2.000_69_
   *
   * Block description for '<S199>/SUM_1':
   *  _V3p4.LDW2.000_546_
   *
   * Block description for '<S199>/UD_1':
   *  _V3p4.LDW2.000_548_
   */
  VbLKAS_LeftOffstStep = (VbLKAS_QlyValidLe && (((real32_T)fabs((real_T)
    ((real32_T)(VfLKAS_L_OffstLeft -
                LKAS_subsystem_integrated_DW.UD_1_DSTATE_kf0u)))) >
    KfLKAS_d_MaxOffstStep));

  /* Switch: '<S181>/Switch2' incorporates:
   *  Constant: '<S186>/Constant'
   *  Constant: '<S187>/Constant'
   *  Logic: '<S181>/LOGOP_1'
   *  Logic: '<S181>/LOGOP_3'
   *  Logic: '<S181>/LOGOP_5'
   *  Logic: '<S181>/LOGOP_6'
   *  Logic: '<S181>/Logical Operator'
   */
  if (VbLKAS_QlyValidLe && (((!VbLKAS_LeftVLatStep) && (!VbLKAS_LeftCurvStep)) &&
       (!VbLKAS_LeftOffstStep)))
  {
    VeLKAS_LineLeftOk = VldForEnag;
  }
  else
  {
    VeLKAS_LineLeftOk = NotVld;
  }

  /* End of Switch: '<S181>/Switch2' */

  /* SignalConversion: '<S197>/Signal Conversion' */
  LKAS_subsystem_integrated_B.Out_cbrj = VeLKAS_LineLeftOk;

  /* RelationalOperator: '<S224>/Relational Operator3' incorporates:
   *  Constant: '<S227>/Constant'
   */
  rtb_VectorConcatenate1_idx_0 = (LKAS_subsystem_integrated_B.Out_cbrj ==
    VldForEnag);

  /* RelationalOperator: '<S180>/RELOP_5' incorporates:
   *  Constant: '<S180>/k_LKA_QlyVld'
   *
   * Block description for '<S180>/k_LKA_QlyVld':
   *  _V3p4.LDW2.000_394_
   */
  VbLKAS_QlyValidRi = (VfLKAS_QlyRi >= KfLKAS_r_QlyVld);

  /* Gain: '<S182>/G_3' incorporates:
   *  Trigonometry: '<S182>/ATAN_1'
   */
  VfLKAS_Heading = (-1.0F) * ((real32_T)atan((real_T)VfLKAS_RiC1));

  /* Product: '<S182>/PROD_1' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   *  Trigonometry: '<S182>/SIN_1'
   */
  VfLKAS_VLatRight = VsEGMO_DataBus.motion.velocity_rel.x * ((real32_T)sin
    ((real_T)VfLKAS_Heading));

  /* Logic: '<S215>/LOGOP_4' incorporates:
   *  Abs: '<S215>/Abs'
   *  Constant: '<S204>/k_LKA_V_MaxStepForVLat'
   *  RelationalOperator: '<S215>/RELOP_2'
   *  Sum: '<S215>/SUM_1'
   *  UnitDelay: '<S215>/UD_1'
   *
   * Block description for '<S215>/Abs':
   *  _V4p0.LDW2.000_66_
   *
   * Block description for '<S204>/k_LKA_V_MaxStepForVLat':
   *  _V4p0.LDW2.000_68_
   *
   * Block description for '<S215>/RELOP_2':
   *  _V4p0.LDW2.000_69_
   *
   * Block description for '<S215>/SUM_1':
   *  _V3p4.LDW2.000_546_
   *
   * Block description for '<S215>/UD_1':
   *  _V3p4.LDW2.000_548_
   */
  VbLKAS_RightVlatStep = (VbLKAS_QlyValidRi && (((real32_T)fabs((real_T)
    ((real32_T)(VfLKAS_VLatRight - LKAS_subsystem_integrated_DW.UD_1_DSTATE_ho3h))))
    > KfLKAS_v_MaxStepForVLat));

  /* Logic: '<S216>/LOGOP_4' incorporates:
   *  Abs: '<S216>/Abs'
   *  Constant: '<S213>/k_LKA_Cr_MaxCurvStep2'
   *  RelationalOperator: '<S216>/RELOP_2'
   *  Sum: '<S216>/SUM_1'
   *  UnitDelay: '<S216>/UD_1'
   *
   * Block description for '<S216>/Abs':
   *  _V4p0.LDW2.000_66_
   *
   * Block description for '<S213>/k_LKA_Cr_MaxCurvStep2':
   *  _V4p0.LDW2.000_68_
   *
   * Block description for '<S216>/RELOP_2':
   *  _V4p0.LDW2.000_69_
   *
   * Block description for '<S216>/SUM_1':
   *  _V3p4.LDW2.000_546_
   *
   * Block description for '<S216>/UD_1':
   *  _V3p4.LDW2.000_548_
   */
  VbLKAS_RightCurvStep = (VbLKAS_QlyValidRi && (((real32_T)fabs((real_T)
    ((real32_T)(LKAS_subsystem_integrated_B.Gain_l52z -
                LKAS_subsystem_integrated_DW.UD_1_DSTATE_cbx5)))) >
    KfLKAS_c_MaxCurvStep));

  /* Product: '<S182>/PROD_2' incorporates:
   *  Trigonometry: '<S182>/COS_1'
   */
  VfLKAS_OffstRi_sLKA = VfLKAS_RiC0 * ((real32_T)cos((real_T)VfLKAS_Heading));

  /* Logic: '<S217>/LOGOP_4' incorporates:
   *  Abs: '<S217>/Abs'
   *  Constant: '<S214>/k_LKA_L_MaxOffstStep'
   *  RelationalOperator: '<S217>/RELOP_2'
   *  Sum: '<S217>/SUM_1'
   *  UnitDelay: '<S217>/UD_1'
   *
   * Block description for '<S217>/Abs':
   *  _V4p0.LDW2.000_66_
   *
   * Block description for '<S214>/k_LKA_L_MaxOffstStep':
   *  _V4p0.LDW2.000_68_
   *
   * Block description for '<S217>/RELOP_2':
   *  _V4p0.LDW2.000_69_
   *
   * Block description for '<S217>/SUM_1':
   *  _V3p4.LDW2.000_546_
   *
   * Block description for '<S217>/UD_1':
   *  _V3p4.LDW2.000_548_
   */
  VbLKAS_RightOffstStep = (VbLKAS_QlyValidRi && (((real32_T)fabs((real_T)
    ((real32_T)(VfLKAS_OffstRi_sLKA -
                LKAS_subsystem_integrated_DW.UD_1_DSTATE_grud)))) >
    KfLKAS_d_MaxOffstStep));

  /* Switch: '<S182>/Switch2' incorporates:
   *  Constant: '<S202>/Constant'
   *  Constant: '<S203>/Constant'
   *  Logic: '<S182>/LOGOP_1'
   *  Logic: '<S182>/LOGOP_3'
   *  Logic: '<S182>/LOGOP_5'
   *  Logic: '<S182>/LOGOP_6'
   *  Logic: '<S182>/Logical Operator'
   */
  if (VbLKAS_QlyValidRi && (((!VbLKAS_RightVlatStep) && (!VbLKAS_RightCurvStep))
       && (!VbLKAS_RightOffstStep)))
  {
    VeLKAS_LineRightOK = VldForEnag;
  }
  else
  {
    VeLKAS_LineRightOK = NotVld;
  }

  /* End of Switch: '<S182>/Switch2' */

  /* SignalConversion: '<S212>/Signal Conversion' */
  LKAS_subsystem_integrated_B.Out_lr5f = VeLKAS_LineRightOK;

  /* RelationalOperator: '<S225>/Relational Operator3' incorporates:
   *  Constant: '<S228>/Constant'
   */
  rtb_VectorConcatenate1_idx_1 = (LKAS_subsystem_integrated_B.Out_lr5f ==
    VldForEnag);

  /* Sum: '<S223>/Sum of Elements' */
  i = (int32_T)((uint32_T)(((uint32_T)(rtb_VectorConcatenate1_idx_0 ? 1U : 0U))
    + (rtb_VectorConcatenate1_idx_1 ? 1U : 0U)));

  /* Switch: '<S221>/SWCH_1' incorporates:
   *  Constant: '<S221>/ZERO_1'
   *  Constant: '<S221>/ZERO_2'
   *  Product: '<S223>/DIV_1'
   *  Product: '<S223>/PROD_1'
   *  RelationalOperator: '<S221>/RELOP_1'
   *  SignalConversion: '<S221>/ConcatBufferAtVector ConcatenateIn1'
   *  SignalConversion: '<S221>/ConcatBufferAtVector ConcatenateIn2'
   *  Sum: '<S223>/Sum of Elements'
   *  Sum: '<S223>/Sum of Elements1'
   */
  if (((uint8_T)i) > ((uint8_T)0U))
  {
    /* Saturate: '<S223>/SAT_1' */
    if (((uint8_T)i) > ((uint8_T)1U))
    {
      tmp = (uint8_T)i;
    }
    else
    {
      tmp = ((uint8_T)1U);
    }

    /* End of Saturate: '<S223>/SAT_1' */
    VfLKAS_Cr_Road = ((rtb_VectorConcatenate1_idx_0 ?
                       LKAS_subsystem_integrated_B.Out : 0.0F) +
                      (rtb_VectorConcatenate1_idx_1 ?
                       LKAS_subsystem_integrated_B.Out_oslf : 0.0F)) /
      ((real32_T)tmp);
  }
  else
  {
    VfLKAS_Cr_Road = 0.0F;
  }

  /* End of Switch: '<S221>/SWCH_1' */

  /* SignalConversion: '<S226>/Signal Conversion' */
  LKAS_subsystem_integrated_B.Switch1_bjf2 = VfLKAS_Cr_Road;

  /* SignalConversion: '<S207>/Signal Conversion' */
  LKAS_subsystem_integrated_B.Out_mwpy = VfLKAS_OffstRi_sLKA;

  /* SignalConversion: '<S194>/Signal Conversion' */
  LKAS_subsystem_integrated_B.Out_hpcs = VfLKAS_L_OffstLeft;

  /* Sum: '<S220>/Subtract' */
  VfLKAS_LaneWidth = LKAS_subsystem_integrated_B.Out_hpcs -
    LKAS_subsystem_integrated_B.Out_mwpy;

  /* SignalConversion: '<S222>/Signal Conversion' */
  LKAS_subsystem_integrated_B.Gain_kbew = VfLKAS_LaneWidth;

  /* BusCreator: '<S173>/Bus Creator1' incorporates:
   *  Constant: '<S173>/VehicleWheelBase'
   *  Constant: '<S173>/VehicleWidth'
   */
  LKAS_subsystem_integrated_B.BusCreator1.VehicleWheelBase =
    KfLKAS_d_VehicleWheelBase;
  LKAS_subsystem_integrated_B.BusCreator1.VehicleWidth = KfLKAS_d_VehicleWidth;

  /* SignalConversion: '<S210>/Signal Conversion' */
  LKAS_subsystem_integrated_B.Out_kpwb = VfLKAS_VLatRight;

  /* MATLAB Function: '<S182>/DetermineDistToCross' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  if (((real_T)((real32_T)fabs((real_T)LKAS_subsystem_integrated_B.Out_kpwb))) >
      0.0001)
  {
    if (VfLKAS_OffstRi_sLKA < 0.0F)
    {
      rtb_Heading = -1.0F;
    }
    else if (VfLKAS_OffstRi_sLKA > 0.0F)
    {
      rtb_Heading = 1.0F;
    }
    else
    {
      rtb_Heading = VfLKAS_OffstRi_sLKA;
    }

    VfLKAS_L_DistToCrossRight = ((VfLKAS_OffstRi_sLKA - ((rtb_Heading *
      LKAS_subsystem_integrated_B.BusCreator1.VehicleWidth) * 0.5F)) /
      LKAS_subsystem_integrated_B.Out_kpwb) *
      VsEGMO_DataBus.motion.velocity_rel.x;
  }
  else
  {
    VfLKAS_L_DistToCrossRight = VsEGMO_DataBus.motion.velocity_rel.x;
  }

  /* End of MATLAB Function: '<S182>/DetermineDistToCross' */

  /* SignalConversion: '<S206>/Signal Conversion' */
  LKAS_subsystem_integrated_B.Out_hyrw = VfLKAS_L_DistToCrossRight;

  /* MATLAB Function: '<S181>/DetermineDistToDistToCross' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  if (((real_T)((real32_T)fabs((real_T)VfLKAS_V_Latleft))) > 0.0001)
  {
    if (VfLKAS_L_OffstLeft < 0.0F)
    {
      rtb_Heading = -1.0F;
    }
    else if (VfLKAS_L_OffstLeft > 0.0F)
    {
      rtb_Heading = 1.0F;
    }
    else
    {
      rtb_Heading = VfLKAS_L_OffstLeft;
    }

    VfLKAS_L_DisToCrossLeft = ((VfLKAS_L_OffstLeft - ((rtb_Heading *
      LKAS_subsystem_integrated_B.BusCreator1.VehicleWidth) * 0.5F)) /
      VfLKAS_V_Latleft) * VsEGMO_DataBus.motion.velocity_rel.x;
  }
  else
  {
    VfLKAS_L_DisToCrossLeft = VsEGMO_DataBus.motion.velocity_rel.x;
  }

  /* End of MATLAB Function: '<S181>/DetermineDistToDistToCross' */

  /* SignalConversion: '<S195>/Signal Conversion' */
  LKAS_subsystem_integrated_B.Out_db2w = VfLKAS_L_DisToCrossLeft;

  /* SignalConversion: '<S208>/Signal Conversion' */
  LKAS_subsystem_integrated_B.Out_psqn = VfLKAS_Heading;

  /* SignalConversion: '<S196>/Signal Conversion' */
  LKAS_subsystem_integrated_B.Out_kbqr = VfLKAS_V_Latleft;

  /* SignalConversion: '<S229>/Signal Conversion' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VfLKAS_Velocity_x = VsEGMO_DataBus.motion.velocity_rel.x;

  /* SignalConversion: '<S233>/Signal Conversion' */
  LKAS_subsystem_integrated_B.Out_axwp = VfLKAS_Velocity_x;

  /* SignalConversion: '<S230>/Signal Conversion' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VfLKAS_yaw_rate_utm = VsEGMO_DataBus.motion.yaw_rate_utm;

  /* SignalConversion: '<S234>/Signal Conversion' */
  LKAS_subsystem_integrated_B.Out_nmxc = VfLKAS_yaw_rate_utm;

  /* SignalConversion: '<S231>/Signal Conversion' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VfLKAS_Acceleration_x = VsEGMO_DataBus.motion.acceleration_rel.x;

  /* SignalConversion: '<S235>/Signal Conversion' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VfLKAS_Acce_y = VsEGMO_DataBus.motion.acceleration_rel.y;

  /* SignalConversion: '<S236>/Signal Conversion' */
  LKAS_subsystem_integrated_B.Out_g2pj = VfLKAS_Acce_y;

  /* UnitDelay: '<S175>/Unit Delay1' */
  VfLKAS_T_AftIntvStart_IntOut = LKAS_subsystem_integrated_DW.UnitDelay1_DSTATE;

  /* SignalConversion: '<S175>/Signal Conversion' */
  LKAS_subsystem_integrated_B.T_AftIntvStart = VfLKAS_T_AftIntvStart_IntOut;

  /* UnitDelay: '<S175>/Unit Delay3' */
  VeLKAS_IntvTyp_sLKA_IntOut =
    LKAS_subsystem_integrated_DW.UnitDelay3_DSTATE_omwh;

  /* SignalConversion: '<S175>/Signal Conversion1' */
  LKAS_subsystem_integrated_B.IntvTyp_sLKA_pzex = VeLKAS_IntvTyp_sLKA_IntOut;

  /* UnitDelay: '<S175>/Unit Delay2' */
  VeLKAS_CtrlRef_sLKA_IntOut =
    LKAS_subsystem_integrated_DW.UnitDelay2_DSTATE_mt2p;

  /* SignalConversion: '<S175>/Signal Conversion2' */
  LKAS_subsystem_integrated_B.CtrlRef_sLKA = VeLKAS_CtrlRef_sLKA_IntOut;

  /* UnitDelay: '<S175>/Unit Delay4' */
  VeLKAS_IntvSide_sLKA_IntOut = LKAS_subsystem_integrated_DW.UnitDelay4_DSTATE;

  /* SignalConversion: '<S175>/Signal Conversion3' */
  LKAS_subsystem_integrated_B.IntvSide_sLKA_k4lx = VeLKAS_IntvSide_sLKA_IntOut;

  /* UnitDelay: '<S175>/Unit Delay' */
  VbLKAS_IsIntvCompleted_sLKA_IntOut =
    LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_gtga;

  /* SignalConversion: '<S175>/Signal Conversion4' */
  LKAS_subsystem_integrated_B.IsIntvCompleted_sLKA =
    VbLKAS_IsIntvCompleted_sLKA_IntOut;
}

/* Update for atomic system: '<S5>/LaneMarkerHandler' */
void LKAS_s_LaneMarkerHandler_Update(void)
{
  /* Update for UnitDelay: '<S200>/UD_1'
   *
   * Block description for '<S200>/UD_1':
   *  _V3p4.LDW2.000_548_
   */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE = VfLKAS_V_Latleft;

  /* Update for UnitDelay: '<S198>/UD_1'
   *
   * Block description for '<S198>/UD_1':
   *  _V3p4.LDW2.000_548_
   */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_hhbh =
    LKAS_subsystem_integrated_B.Gain;

  /* Update for UnitDelay: '<S199>/UD_1'
   *
   * Block description for '<S199>/UD_1':
   *  _V3p4.LDW2.000_548_
   */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_kf0u = VfLKAS_L_OffstLeft;

  /* Update for UnitDelay: '<S215>/UD_1'
   *
   * Block description for '<S215>/UD_1':
   *  _V3p4.LDW2.000_548_
   */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_ho3h = VfLKAS_VLatRight;

  /* Update for UnitDelay: '<S216>/UD_1'
   *
   * Block description for '<S216>/UD_1':
   *  _V3p4.LDW2.000_548_
   */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_cbx5 =
    LKAS_subsystem_integrated_B.Gain_l52z;

  /* Update for UnitDelay: '<S217>/UD_1'
   *
   * Block description for '<S217>/UD_1':
   *  _V3p4.LDW2.000_548_
   */
  LKAS_subsystem_integrated_DW.UD_1_DSTATE_grud = VfLKAS_OffstRi_sLKA;

  /* Update for UnitDelay: '<S175>/Unit Delay1' */
  LKAS_subsystem_integrated_DW.UnitDelay1_DSTATE =
    LKAS_subsystem_integrated_B.T_AftIntvStart_gady;

  /* Update for UnitDelay: '<S175>/Unit Delay3' */
  LKAS_subsystem_integrated_DW.UnitDelay3_DSTATE_omwh =
    LKAS_subsystem_integrated_B.IntvTyp_sLKA_pzex;

  /* Update for UnitDelay: '<S175>/Unit Delay2' */
  LKAS_subsystem_integrated_DW.UnitDelay2_DSTATE_mt2p =
    LKAS_subsystem_integrated_B.CtrlRef_sLKA_ly5n;

  /* Update for UnitDelay: '<S175>/Unit Delay4' */
  LKAS_subsystem_integrated_DW.UnitDelay4_DSTATE =
    LKAS_subsystem_integrated_B.IntvSide_sLKA_k4lx;

  /* Update for UnitDelay: '<S175>/Unit Delay' */
  LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_gtga =
    LKAS_subsystem_integrated_B.IsIntvCompleted_sLKA_a1kj;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
