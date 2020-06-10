/*
 * File: TrajectoryCalculation.c
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

#include "TrajectoryCalculation.h"

/* Include model header file for global data */
#include "LKAS_subsystem_integrated.h"
#include "LKAS_subsystem_integrated_private.h"

/* Named constants for MATLAB Function: '<S301>/SafeDivide' */
#define LKAS_subsystem_inte_DataTypeMax (1.8446743E+19F)
#define LKAS_subsystem_inte_DataTypeMin (-1.8446743E+19F)

/* Named constants for MATLAB Function: '<S296>/SafeDivide' */
#define LKAS_subsystem_DataTypeMax_matr (1.8446743E+19F)
#define LKAS_subsystem_DataTypeMin_dr0v (-1.8446743E+19F)

/*
 * System initialize for atomic system:
 *    '<S243>/Chart'
 *    '<S244>/Chart'
 */
void LKAS_subsystem_integ_Chart_Init(boolean_T *rty_out,
  DW_Chart_LKAS_subsystem_integ_T *localDW)
{
  localDW->flag = false;
  *rty_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S243>/Chart'
 *    '<S244>/Chart'
 */
void LKAS_subsystem_integrated_Chart(boolean_T rtu_in, boolean_T rtu_init_val,
  boolean_T *rty_out, DW_Chart_LKAS_subsystem_integ_T *localDW)
{
  /* Chart: '<S243>/Chart' */
  if (!localDW->flag)
  {
    *rty_out = rtu_init_val;
    localDW->flag = true;
  }
  else
  {
    *rty_out = rtu_in;
  }

  /* End of Chart: '<S243>/Chart' */
}

/*
 * Output and update for action system:
 *    '<S276>/calc_dt'
 *    '<S276>/calc_dt1'
 */
void LKAS_subsystem_integrat_calc_dt(real32_T rtu_am, real32_T rtu_a0, real32_T
  rtu_ae, real32_T rtu_dv, real32_T *rty_dt)
{
  real32_T rtb_G_1_og3i;
  real32_T rtb_ADD_1_gi1q;

  /* Sum: '<S299>/ADD_1' incorporates:
   *  Gain: '<S299>/G_2'
   */
  rtb_ADD_1_gi1q = (rtu_a0 + (2.0F * rtu_am)) + rtu_ae;

  /* Gain: '<S299>/G_1' */
  rtb_G_1_og3i = 2.0F * rtu_dv;

  /* Outputs for Atomic SubSystem: '<S299>/SafeDivide' */
  /* MATLAB Function: '<S301>/SafeDivide' */
  if (((real32_T)fabs((real_T)rtb_ADD_1_gi1q)) > (((real32_T)fabs((real_T)
         rtb_G_1_og3i)) * 5.42101151E-20F))
  {
    *rty_dt = rtb_G_1_og3i / rtb_ADD_1_gi1q;
  }
  else if (rtb_G_1_og3i > 0.0F)
  {
    *rty_dt = LKAS_subsystem_inte_DataTypeMax;
  }
  else if (rtb_G_1_og3i < 0.0F)
  {
    *rty_dt = LKAS_subsystem_inte_DataTypeMin;
  }
  else
  {
    *rty_dt = 0.0F;
  }

  /* End of MATLAB Function: '<S301>/SafeDivide' */
  /* End of Outputs for SubSystem: '<S299>/SafeDivide' */
}

/*
 * Output and update for action system:
 *    '<S305>/UseDefault'
 *    '<S277>/UseDefault'
 */
void LKAS_subsystem_integ_UseDefault(boolean_T *rty_TrajectoryFound, real32_T
  rty_ITC_dt[2], real32_T rty_ITC_cp[8], real32_T *rty_MaxLateralAcceleration,
  real32_T *rty_MaxLateralJerk)
{
  int32_T i;

  /* SignalConversion: '<S312>/OutportBufferForITC_cp' incorporates:
   *  Constant: '<S312>/Zero_2'
   */
  for (i = 0; i < 8; i++)
  {
    rty_ITC_cp[i] = LKAS_subsystem_integrate_ConstP.pooled14[(i)];
  }

  /* End of SignalConversion: '<S312>/OutportBufferForITC_cp' */

  /* SignalConversion: '<S312>/OutportBufferForITC_dt' incorporates:
   *  Constant: '<S312>/Zero_1'
   */
  rty_ITC_dt[0] = 0.0F;
  rty_ITC_dt[1] = 0.0F;

  /* SignalConversion: '<S312>/OutportBufferForTrajectoryFound' incorporates:
   *  Constant: '<S312>/false'
   */
  *rty_TrajectoryFound = false;

  /* SignalConversion: '<S312>/OutportBufferForMaxLateralAcceleration' incorporates:
   *  Constant: '<S312>/Zero_4'
   */
  *rty_MaxLateralAcceleration = 0.0F;

  /* SignalConversion: '<S312>/OutportBufferForMaxLateralJerk' incorporates:
   *  Constant: '<S312>/Zero_3'
   */
  *rty_MaxLateralJerk = 0.0F;
}

/* System initialize for atomic system: '<S5>/TrajectoryCalculation' */
void LKAS_TrajectoryCalculation_Init(void)
{
  boolean_T rtb_out_eyyi;
  boolean_T rtb_out_a5of;
  int32_T i;

  /* SystemInitialize for Enabled SubSystem: '<S259>/ITCWithAdditionalConditionForValidPath_sLKA' */
  /* SystemInitialize for Merge: '<S284>/Merge' */
  VfLKAS_Am1 = 0.0F;
  VfLKAS_Am2 = 0.0F;

  /* SystemInitialize for Merge: '<S284>/Merge1' */
  VbLKAS_SolutionFoundForAm = false;

  /* SystemInitialize for Atomic SubSystem: '<S270>/CalculateTrajectory' */
  /* SystemInitialize for Merge: '<S277>/Merge_1' */
  LKAS_subsystem_integrated_B.ITC_dt[0] = 0.0F;
  LKAS_subsystem_integrated_B.ITC_dt[1] = 0.0F;

  /* SystemInitialize for Merge: '<S277>/Merge_2' */
  VbLKAS_TrajectoryFound_sLKA = false;

  /* SystemInitialize for Merge: '<S277>/Merge_3' */
  VfLKAS_JerkNeeded_sLkA = 0.0F;

  /* SystemInitialize for Merge: '<S277>/Merge_4' */
  for (i = 0; i < 8; i++)
  {
    LKAS_subsystem_integrated_B.ITC_cp[i] = 0.0F;
  }

  /* End of SystemInitialize for Merge: '<S277>/Merge_4' */

  /* SystemInitialize for Merge: '<S277>/Merge_5' */
  VfLKAS_LatAccNeeded_sLKA = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S270>/CalculateTrajectory' */
  /* End of SystemInitialize for SubSystem: '<S259>/ITCWithAdditionalConditionForValidPath_sLKA' */

  /* SystemInitialize for Chart: '<S244>/Chart' */
  LKAS_subsystem_integ_Chart_Init(&rtb_out_eyyi,
    &LKAS_subsystem_integrated_DW.sf_Chart);

  /* SystemInitialize for Chart: '<S243>/Chart' */
  LKAS_subsystem_integ_Chart_Init(&rtb_out_a5of,
    &LKAS_subsystem_integrated_DW.sf_Chart_g1xu);

  /* SystemInitialize for Chart: '<S373>/Chart' */
  LKAS_subsystem_integrated_DW.flag = false;
}

/* Output and update for atomic system: '<S5>/TrajectoryCalculation' */
void LKAS_subs_TrajectoryCalculation(void)
{
  boolean_T rtb_RelationalOperator3_j4ur;
  boolean_T rtb_LOGOP_3_gb3p;
  real32_T rtb_Out_amt1;
  real32_T rtb_MSWCH_2;
  real32_T rtb_A_ALatRelLaneMkrLe;
  real32_T rtb_A_ALatRelLaneMkrRi;
  real32_T rtb_cp_sLKA[8];
  boolean_T rtb_out;
  real32_T rtb_a;
  int8_T rtAction;
  boolean_T rtb_B_VehHeadingLeft_LeftLaneMk;
  boolean_T rtb_out_eyyi;
  boolean_T rtb_out_a5of;
  real32_T rtb_dv;
  real32_T rtb_Out_mt3c;
  boolean_T rtb_UnitDelay_fm1k;
  boolean_T rtb_UnitDelay_oz1j;
  int32_T i;
  real32_T rtb_A_ALatRelLaneMkrLe_tmp;
  real32_T rtb_LOGOP_3_firm_tmp;
  real32_T tmp;

  /* RelationalOperator: '<S399>/Relational Operator3' incorporates:
   *  Constant: '<S401>/Constant'
   */
  rtb_RelationalOperator3_j4ur = (LKAS_subsystem_integrated_B.Out_cbrj ==
    VldForEnag);

  /* Logic: '<S395>/LOGOP_3' incorporates:
   *  Constant: '<S402>/Constant'
   *  RelationalOperator: '<S400>/Relational Operator3'
   */
  rtb_LOGOP_3_gb3p = !(LKAS_subsystem_integrated_B.Out_lr5f == VldForEnag);

  /* Switch: '<S394>/SWCH_2' incorporates:
   *  Constant: '<S398>/Constant'
   *  Logic: '<S395>/LOGOP_1'
   *  Logic: '<S395>/LOGOP_2'
   */
  if ((!rtb_RelationalOperator3_j4ur) && rtb_LOGOP_3_gb3p)
  {
    VeLKAS_IntvSideReq_sLKA = LKAS_NoIntvSide;
  }
  else
  {
    /* RelationalOperator: '<S394>/RELOP_3' incorporates:
     *  Constant: '<S394>/CONST_ZERO'
     */
    rtb_B_VehHeadingLeft_LeftLaneMk = (LKAS_subsystem_integrated_B.Out_kbqr >
      0.0F);

    /* Switch: '<S394>/SWCH_4' incorporates:
     *  Constant: '<S394>/CONST_ZERO'
     *  Constant: '<S397>/Constant'
     *  Logic: '<S394>/LOGOP_3'
     *  RelationalOperator: '<S394>/RELOP_6'
     *  Switch: '<S394>/SWCH_1'
     */
    if ((LKAS_subsystem_integrated_B.Out_kpwb > 0.0F) !=
        rtb_B_VehHeadingLeft_LeftLaneMk)
    {
      /* Switch: '<S394>/SWCH_3' incorporates:
       *  Abs: '<S395>/ABS_1'
       *  Abs: '<S395>/ABS_2'
       *  Constant: '<S396>/Constant'
       *  Constant: '<S397>/Constant'
       *  Logic: '<S395>/LOGOP_10'
       *  Logic: '<S395>/LOGOP_4'
       *  Logic: '<S395>/LOGOP_5'
       *  RelationalOperator: '<S395>/RELOP_1'
       */
      if ((rtb_RelationalOperator3_j4ur && (((real32_T)fabs((real_T)
              LKAS_subsystem_integrated_B.Out_mwpy)) >= ((real32_T)fabs((real_T)
              LKAS_subsystem_integrated_B.Out_hpcs)))) ||
          (rtb_RelationalOperator3_j4ur && rtb_LOGOP_3_gb3p))
      {
        VeLKAS_IntvSideReq_sLKA = LKAS_IntvSideLe;
      }
      else
      {
        VeLKAS_IntvSideReq_sLKA = LKAS_IntvSideRi;
      }

      /* End of Switch: '<S394>/SWCH_3' */
    }
    else if (rtb_B_VehHeadingLeft_LeftLaneMk)
    {
      /* Switch: '<S394>/SWCH_1' incorporates:
       *  Constant: '<S396>/Constant'
       */
      VeLKAS_IntvSideReq_sLKA = LKAS_IntvSideLe;
    }
    else
    {
      VeLKAS_IntvSideReq_sLKA = LKAS_IntvSideRi;
    }

    /* End of Switch: '<S394>/SWCH_4' */
  }

  /* End of Switch: '<S394>/SWCH_2' */

  /* SignalConversion: '<S377>/Signal Conversion' */
  LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.IntvSideReq_sLKA =
    VeLKAS_IntvSideReq_sLKA;

  /* MultiPortSwitch: '<S387>/MSWCH_1' incorporates:
   *  Constant: '<S387>/CONST_ZERO1'
   */
  switch (VeLKAS_IntvSideReq_sLKA)
  {
   case LKAS_IntvSideLe:
    VfLKAS_Vlat_sLKA = LKAS_subsystem_integrated_B.Out_kbqr;
    break;

   case LKAS_IntvSideRi:
    VfLKAS_Vlat_sLKA = LKAS_subsystem_integrated_B.Out_kpwb;
    break;

   default:
    VfLKAS_Vlat_sLKA = 0.0F;
    break;
  }

  /* End of MultiPortSwitch: '<S387>/MSWCH_1' */

  /* SignalConversion: '<S378>/Signal Conversion' */
  LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.Vlat_sLKA = VfLKAS_Vlat_sLKA;

  /* MultiPortSwitch: '<S387>/MSWCH_2' incorporates:
   *  Constant: '<S387>/CONST_ZERO1'
   */
  switch (VeLKAS_IntvSideReq_sLKA)
  {
   case LKAS_IntvSideLe:
    VfLKAS_L_DistToCross_sLKA = LKAS_subsystem_integrated_B.Out_db2w;
    break;

   case LKAS_IntvSideRi:
    VfLKAS_L_DistToCross_sLKA = LKAS_subsystem_integrated_B.Out_hyrw;
    break;

   default:
    VfLKAS_L_DistToCross_sLKA = 0.0F;
    break;
  }

  /* End of MultiPortSwitch: '<S387>/MSWCH_2' */

  /* SignalConversion: '<S379>/Signal Conversion' */
  LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.L_DistToCross_sLKA =
    VfLKAS_L_DistToCross_sLKA;

  /* MultiPortSwitch: '<S386>/MSWCH_1' incorporates:
   *  Constant: '<S391>/Constant'
   *  Constant: '<S392>/Constant'
   *  Constant: '<S393>/Constant'
   */
  switch (VeLKAS_IntvSideReq_sLKA)
  {
   case LKAS_IntvSideLe:
    VeLKAS_CtrlRefReq_sLKA = LKAS_LaneMkrToClsLe;
    break;

   case LKAS_IntvSideRi:
    VeLKAS_CtrlRefReq_sLKA = LKAS_LaneMkrToClsRi;
    break;

   default:
    VeLKAS_CtrlRefReq_sLKA = LKAS_NoRef;
    break;
  }

  /* End of MultiPortSwitch: '<S386>/MSWCH_1' */

  /* SignalConversion: '<S380>/Signal Conversion' */
  LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.CtrlRefReq_sLKA =
    VeLKAS_CtrlRefReq_sLKA;

  /* Constant: '<S240>/k_LKA_SatnOfAInpForPahCalcn1'
   *
   * Block description for '<S240>/k_LKA_SatnOfAInpForPahCalcn1':
   *  _V3p4.LDW2.000_676_
   */
  VfLKAS_L_ExtraMargin_sLKA = KfLKAS_d_ExtraMargin;

  /* SignalConversion: '<S381>/Signal Conversion' */
  LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.L_ExtraMargin_sLKA =
    VfLKAS_L_ExtraMargin_sLKA;

  /* Switch: '<S375>/Switch' incorporates:
   *  Constant: '<S375>/k_LKA_SatnOfAInpForPahCalcn1'
   *  Product: '<S375>/Product'
   *  Product: '<S375>/Product3'
   *  Trigonometry: '<S375>/Cos'
   *
   * Block description for '<S375>/k_LKA_SatnOfAInpForPahCalcn1':
   *  _V3p4.LDW2.000_676_
   */
  if (KbLKAS_A0Trigger_Temp)
  {
    rtb_Out_amt1 = LKAS_subsystem_integrated_B.Out_nmxc *
      LKAS_subsystem_integrated_B.Out_axwp;
  }
  else
  {
    rtb_Out_amt1 = ((real32_T)cos((real_T)LKAS_subsystem_integrated_B.Out_psqn))
      * LKAS_subsystem_integrated_B.Out_g2pj;
  }

  /* End of Switch: '<S375>/Switch' */

  /* Product: '<S375>/Product6' incorporates:
   *  Product: '<S237>/PROD_1'
   *  Product: '<S375>/Product8'
   */
  rtb_A_ALatRelLaneMkrLe_tmp = LKAS_subsystem_integrated_B.Out_axwp *
    LKAS_subsystem_integrated_B.Out_axwp;

  /* Sum: '<S375>/Subtract' incorporates:
   *  Product: '<S375>/Product5'
   *  Product: '<S375>/Product6'
   */
  rtb_A_ALatRelLaneMkrLe = rtb_Out_amt1 - (LKAS_subsystem_integrated_B.Out *
    rtb_A_ALatRelLaneMkrLe_tmp);

  /* Sum: '<S375>/Subtract1' incorporates:
   *  Product: '<S375>/Product7'
   */
  rtb_A_ALatRelLaneMkrRi = rtb_Out_amt1 - (LKAS_subsystem_integrated_B.Out_oslf *
    rtb_A_ALatRelLaneMkrLe_tmp);

  /* MultiPortSwitch: '<S375>/MSWCH_2' incorporates:
   *  Constant: '<S375>/CONST_ZERO2'
   */
  switch (VeLKAS_IntvSideReq_sLKA)
  {
   case LKAS_IntvSideLe:
    rtb_MSWCH_2 = rtb_A_ALatRelLaneMkrLe;
    break;

   case LKAS_IntvSideRi:
    rtb_MSWCH_2 = rtb_A_ALatRelLaneMkrRi;
    break;

   default:
    rtb_MSWCH_2 = 0.0F;
    break;
  }

  /* End of MultiPortSwitch: '<S375>/MSWCH_2' */

  /* Gain: '<S375>/Gain' incorporates:
   *  Constant: '<S375>/k_LKA_SatnOfAInpForPahCalcn'
   *
   * Block description for '<S375>/k_LKA_SatnOfAInpForPahCalcn':
   *  _V3p4.LDW2.000_676_
   */
  rtb_Out_amt1 = (-1.0F) * KfLKAS_a_SarnOfRelALatForPahCalcn;

  /* Switch: '<S388>/Switch2' incorporates:
   *  Constant: '<S375>/k_LKA_SatnOfAInpForPahCalcn'
   *  RelationalOperator: '<S388>/LowerRelop1'
   *  RelationalOperator: '<S388>/UpperRelop'
   *  Switch: '<S388>/Switch'
   *
   * Block description for '<S375>/k_LKA_SatnOfAInpForPahCalcn':
   *  _V3p4.LDW2.000_676_
   */
  if (rtb_MSWCH_2 > KfLKAS_a_SarnOfRelALatForPahCalcn)
  {
    VfLKAS_A_ALatRelLaneMkr_sLKA = KfLKAS_a_SarnOfRelALatForPahCalcn;
  }
  else if (rtb_MSWCH_2 < rtb_Out_amt1)
  {
    /* Switch: '<S388>/Switch' */
    VfLKAS_A_ALatRelLaneMkr_sLKA = rtb_Out_amt1;
  }
  else
  {
    VfLKAS_A_ALatRelLaneMkr_sLKA = rtb_MSWCH_2;
  }

  /* End of Switch: '<S388>/Switch2' */

  /* Switch: '<S389>/Switch2' incorporates:
   *  Constant: '<S375>/k_LKA_SatnOfAInpForPahCalcn'
   *  RelationalOperator: '<S389>/LowerRelop1'
   *  RelationalOperator: '<S389>/UpperRelop'
   *  Switch: '<S389>/Switch'
   *
   * Block description for '<S375>/k_LKA_SatnOfAInpForPahCalcn':
   *  _V3p4.LDW2.000_676_
   */
  if (rtb_A_ALatRelLaneMkrLe > KfLKAS_a_SarnOfRelALatForPahCalcn)
  {
    VfLKAS_A_ALatRelLaneMkrLe = KfLKAS_a_SarnOfRelALatForPahCalcn;
  }
  else if (rtb_A_ALatRelLaneMkrLe < rtb_Out_amt1)
  {
    /* Switch: '<S389>/Switch' */
    VfLKAS_A_ALatRelLaneMkrLe = rtb_Out_amt1;
  }
  else
  {
    VfLKAS_A_ALatRelLaneMkrLe = rtb_A_ALatRelLaneMkrLe;
  }

  /* End of Switch: '<S389>/Switch2' */

  /* Switch: '<S390>/Switch2' incorporates:
   *  Constant: '<S375>/k_LKA_SatnOfAInpForPahCalcn'
   *  RelationalOperator: '<S390>/LowerRelop1'
   *  RelationalOperator: '<S390>/UpperRelop'
   *  Switch: '<S390>/Switch'
   *
   * Block description for '<S375>/k_LKA_SatnOfAInpForPahCalcn':
   *  _V3p4.LDW2.000_676_
   */
  if (rtb_A_ALatRelLaneMkrRi > KfLKAS_a_SarnOfRelALatForPahCalcn)
  {
    VfLKAS_A_ALatRelLaneMkrRi = KfLKAS_a_SarnOfRelALatForPahCalcn;
  }
  else if (rtb_A_ALatRelLaneMkrRi < rtb_Out_amt1)
  {
    /* Switch: '<S390>/Switch' */
    VfLKAS_A_ALatRelLaneMkrRi = rtb_Out_amt1;
  }
  else
  {
    VfLKAS_A_ALatRelLaneMkrRi = rtb_A_ALatRelLaneMkrRi;
  }

  /* End of Switch: '<S390>/Switch2' */

  /* Product: '<S376>/Product' incorporates:
   *  Abs: '<S376>/Abs'
   *  Trigonometry: '<S376>/Cos'
   */
  VfLKAS_Vlong_sLKA = ((real32_T)cos((real_T)((real32_T)fabs((real_T)
    LKAS_subsystem_integrated_B.Out_psqn)))) *
    LKAS_subsystem_integrated_B.Out_axwp;

  /* BusCreator: '<S240>/Bus Creator' incorporates:
   *  SignalConversion: '<S382>/Signal Conversion'
   *  SignalConversion: '<S383>/Signal Conversion'
   *  SignalConversion: '<S384>/Signal Conversion'
   *  SignalConversion: '<S385>/Signal Conversion'
   */
  LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.A_ALatRelLaneMkr_sLKA =
    VfLKAS_A_ALatRelLaneMkr_sLKA;
  LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.A_ALatRelLaneMkrLe =
    VfLKAS_A_ALatRelLaneMkrLe;
  LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.A_ALatRelLaneMkrRi =
    VfLKAS_A_ALatRelLaneMkrRi;
  LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.Vlong_sLKA = VfLKAS_Vlong_sLKA;

  /* Sum: '<S264>/ADD_3' incorporates:
   *  Gain: '<S264>/G_1'
   */
  rtb_Out_amt1 = (0.5F * LKAS_subsystem_integrated_B.BusCreator1.VehicleWidth) +
    LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.L_ExtraMargin_sLKA;

  /* Sum: '<S268>/ADD_1' */
  rtb_A_ALatRelLaneMkrLe = LKAS_subsystem_integrated_B.Out_hpcs - rtb_Out_amt1;

  /* RelationalOperator: '<S265>/RELOP_2' incorporates:
   *  Constant: '<S269>/Constant'
   */
  rtb_RelationalOperator3_j4ur =
    (LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.IntvSideReq_sLKA ==
     LKAS_IntvSideLe);

  /* Sum: '<S268>/ADD_4' */
  rtb_A_ALatRelLaneMkrRi = LKAS_subsystem_integrated_B.Out_mwpy + rtb_Out_amt1;

  /* Switch: '<S268>/SWCH_4' incorporates:
   *  Constant: '<S268>/k_LKA_L_MinDeltaPosFirst'
   *  Constant: '<S268>/k_LKA_L_MinDeltaPosSec'
   *  Gain: '<S268>/G_1'
   *  Gain: '<S268>/G_3'
   *  Logic: '<S268>/LOGOP_1'
   *  Logic: '<S268>/LOGOP_6'
   *  Logic: '<S268>/Logical Operator'
   *  Logic: '<S268>/Logical Operator1'
   *  RelationalOperator: '<S268>/RELOP_1'
   *  RelationalOperator: '<S268>/RELOP_2'
   *  RelationalOperator: '<S268>/RELOP_3'
   *  RelationalOperator: '<S268>/RELOP_4'
   */
  if (rtb_RelationalOperator3_j4ur)
  {
    VbLKAS_zero_trajectory_found = !((rtb_A_ALatRelLaneMkrLe >
      KfLKAS_d_MinDeltaPosFirst) || (rtb_A_ALatRelLaneMkrLe < ((-1.0F) *
      KfLKAS_d_MinDeltaPosSec)));
  }
  else
  {
    VbLKAS_zero_trajectory_found = !((rtb_A_ALatRelLaneMkrRi < ((-1.0F) *
      KfLKAS_d_MinDeltaPosFirst)) || (rtb_A_ALatRelLaneMkrRi >
      KfLKAS_d_MinDeltaPosSec));
  }

  /* End of Switch: '<S268>/SWCH_4' */

  /* Gain: '<S267>/_2' */
  VfLKAS_vlat_0 = (-1.0F) *
    LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.Vlat_sLKA;

  /* Gain: '<S266>/_2' */
  VfLKAS_alat_0 = (-1.0F) *
    LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.A_ALatRelLaneMkr_sLKA;

  /* Switch: '<S268>/Switch2' incorporates:
   *  Constant: '<S268>/Constant2'
   *  Switch: '<S268>/SWCH_2'
   */
  if (VbLKAS_zero_trajectory_found)
  {
    rtb_A_ALatRelLaneMkrLe = 0.0F;
  }
  else if (rtb_RelationalOperator3_j4ur)
  {
  }
  else
  {
    rtb_A_ALatRelLaneMkrLe = rtb_A_ALatRelLaneMkrRi;
  }

  /* End of Switch: '<S268>/Switch2' */

  /* Gain: '<S268>/G_2' */
  VfLKAS_delta_pos_sLKA = (-1.0F) * rtb_A_ALatRelLaneMkrLe;

  /* Outputs for Enabled SubSystem: '<S259>/ITCWithAdditionalConditionForValidPath_sLKA' incorporates:
   *  EnablePort: '<S261>/Enable'
   */
  /* Logic: '<S259>/Logical Operator' */
  if (!VbLKAS_zero_trajectory_found)
  {
    if (!LKAS_subsystem_integrated_DW.ITCWithAdditionalConditionForVa)
    {
      LKAS_subsystem_integrated_DW.ITCWithAdditionalConditionForVa = true;
    }

    /* Switch: '<S356>/SWCH_1' incorporates:
     *  Abs: '<S356>/ABS_1'
     *  Constant: '<S356>/Constant'
     *  Constant: '<S359>/Constant'
     *  RelationalOperator: '<S359>/Compare'
     *  SignalConversion: '<S271>/Signal Conversion'
     */
    if (((real32_T)fabs((real_T)VfLKAS_vlat_0)) >= 0.001F)
    {
      rtb_A_ALatRelLaneMkrLe = VfLKAS_vlat_0;
    }
    else
    {
      rtb_A_ALatRelLaneMkrLe = 0.0F;
    }

    /* End of Switch: '<S356>/SWCH_1' */

    /* Switch: '<S357>/SWCH_1' incorporates:
     *  Abs: '<S357>/ABS_1'
     *  Constant: '<S357>/Constant'
     *  Constant: '<S360>/Constant'
     *  RelationalOperator: '<S360>/Compare'
     *  SignalConversion: '<S272>/Signal Conversion'
     */
    if (((real32_T)fabs((real_T)VfLKAS_alat_0)) >= 0.001F)
    {
      rtb_Out_mt3c = VfLKAS_alat_0;
    }
    else
    {
      rtb_Out_mt3c = 0.0F;
    }

    /* End of Switch: '<S357>/SWCH_1' */

    /* Gain: '<S281>/G_1' incorporates:
     *  SignalConversion: '<S273>/Signal Conversion'
     */
    rtb_a = (-4.0F) * VfLKAS_delta_pos_sLKA;

    /* Outputs for IfAction SubSystem: '<S284>/EquationSolver' incorporates:
     *  ActionPort: '<S285>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S285>/SafeDivide' */
    /* If: '<S284>/If' incorporates:
     *  Abs: '<S289>/Abs'
     *  MATLAB Function: '<S292>/SafeDivide'
     */
    rtb_LOGOP_3_firm_tmp = (real32_T)fabs((real_T)rtb_a);

    /* End of Outputs for SubSystem: '<S285>/SafeDivide' */
    /* End of Outputs for SubSystem: '<S284>/EquationSolver' */

    /* RelationalOperator: '<S289>/Relational Operator' incorporates:
     *  Abs: '<S289>/Abs'
     *  Constant: '<S284>/Constant'
     */
    rtb_LOGOP_3_gb3p = (rtb_LOGOP_3_firm_tmp < 1.0E-8F);

    /* Sum: '<S358>/ADD_1' incorporates:
     *  Constant: '<S270>/CONTS_ZERO'
     */
    rtb_dv = 0.0F - rtb_A_ALatRelLaneMkrLe;

    /* Product: '<S282>/PROD_1' incorporates:
     *  Product: '<S283>/PROD_1'
     *  Product: '<S283>/PROD_2'
     */
    rtb_MSWCH_2 = rtb_dv * rtb_dv;

    /* Sum: '<S282>/ADD_1' incorporates:
     *  Constant: '<S261>/Constant1'
     *  Gain: '<S282>/G_1'
     *  Gain: '<S282>/G_2'
     *  Gain: '<S282>/G_3'
     *  Gain: '<S282>/G_4'
     *  Product: '<S282>/PROD_1'
     *  Product: '<S282>/PROD_2'
     *  Product: '<S282>/PROD_3'
     *  Product: '<S282>/PROD_4'
     *  SignalConversion: '<S273>/Signal Conversion'
     */
    rtb_A_ALatRelLaneMkrRi = (((4.0F * rtb_MSWCH_2) + (8.0F * (rtb_dv *
      rtb_A_ALatRelLaneMkrLe))) + ((-4.0F) * (0.0F * VfLKAS_delta_pos_sLKA))) +
      ((-4.0F) * (VfLKAS_delta_pos_sLKA * rtb_Out_mt3c));

    /* Sum: '<S283>/ADD_1' incorporates:
     *  Constant: '<S261>/Constant1'
     *  Gain: '<S283>/G_1'
     *  Gain: '<S283>/G_2'
     *  Gain: '<S283>/G_3'
     *  Gain: '<S283>/G_4'
     *  Gain: '<S283>/G_5'
     *  Gain: '<S283>/G_6'
     *  Gain: '<S283>/G_7'
     *  Product: '<S283>/PROD_1'
     *  Product: '<S283>/PROD_14'
     *  Product: '<S283>/PROD_2'
     *  Product: '<S283>/PROD_3'
     *  Product: '<S283>/PROD_4'
     *  Product: '<S283>/PROD_5'
     *  Product: '<S283>/PROD_6'
     *  SignalConversion: '<S273>/Signal Conversion'
     */
    rtb_MSWCH_2 = ((((((3.4F * (rtb_MSWCH_2 * rtb_Out_mt3c)) + (0.6F *
      (rtb_MSWCH_2 * 0.0F))) + (4.0F * ((rtb_dv * rtb_Out_mt3c) *
      rtb_A_ALatRelLaneMkrLe))) + ((-1.0F) * ((0.0F * 0.0F) *
      VfLKAS_delta_pos_sLKA))) + (4.0F * ((rtb_dv * 0.0F) *
      rtb_A_ALatRelLaneMkrLe))) + ((-1.0F) * ((rtb_Out_mt3c * rtb_Out_mt3c) *
      VfLKAS_delta_pos_sLKA))) + ((-2.0F) * ((rtb_Out_mt3c * 0.0F) *
      VfLKAS_delta_pos_sLKA));

    /* Outputs for IfAction SubSystem: '<S284>/EquationSolver' incorporates:
     *  ActionPort: '<S285>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S285>/SafeDivide2' */
    /* If: '<S284>/If' incorporates:
     *  Abs: '<S288>/Abs'
     *  Constant: '<S284>/Constant'
     *  MATLAB Function: '<S292>/SafeDivide'
     *  MATLAB Function: '<S293>/SafeDivide'
     *  RelationalOperator: '<S288>/Relational Operator'
     */
    tmp = (real32_T)fabs((real_T)rtb_A_ALatRelLaneMkrRi);

    /* End of Outputs for SubSystem: '<S285>/SafeDivide2' */
    /* End of Outputs for SubSystem: '<S284>/EquationSolver' */
    if (rtb_LOGOP_3_gb3p && (tmp < 1.0E-8F))
    {
      /* Outputs for IfAction SubSystem: '<S284>/OutputConstant' incorporates:
       *  ActionPort: '<S287>/Action Port'
       */
      /* SignalConversion: '<S287>/Signal Conversion' incorporates:
       *  Constant: '<S287>/Constant1'
       *  Constant: '<S287>/Constant2'
       */
      VfLKAS_Am1 = 0.0F;
      VfLKAS_Am2 = 0.0F;

      /* RelationalOperator: '<S298>/Relational Operator' incorporates:
       *  Abs: '<S298>/Abs'
       *  Constant: '<S287>/Constant'
       */
      VbLKAS_SolutionFoundForAm = (((real32_T)fabs((real_T)rtb_MSWCH_2)) <
        1.0E-8F);

      /* End of Outputs for SubSystem: '<S284>/OutputConstant' */
    }
    else if (rtb_LOGOP_3_gb3p)
    {
      /* Outputs for IfAction SubSystem: '<S284>/FirstDegreeSolution' incorporates:
       *  ActionPort: '<S286>/Action Port'
       */
      /* Outputs for Atomic SubSystem: '<S286>/SafeDivide' */
      /* MATLAB Function: '<S296>/SafeDivide' incorporates:
       *  UnaryMinus: '<S286>/Unary Minus'
       */
      if (((real32_T)fabs((real_T)rtb_A_ALatRelLaneMkrRi)) > (((real32_T)fabs
            ((real_T)((real32_T)(-rtb_MSWCH_2)))) * 5.42101151E-20F))
      {
        rtb_A_ALatRelLaneMkrRi = (-rtb_MSWCH_2) / rtb_A_ALatRelLaneMkrRi;
      }
      else if ((-rtb_MSWCH_2) > 0.0F)
      {
        rtb_A_ALatRelLaneMkrRi = LKAS_subsystem_DataTypeMax_matr;
      }
      else if ((-rtb_MSWCH_2) < 0.0F)
      {
        rtb_A_ALatRelLaneMkrRi = LKAS_subsystem_DataTypeMin_dr0v;
      }
      else
      {
        rtb_A_ALatRelLaneMkrRi = 0.0F;
      }

      /* End of MATLAB Function: '<S296>/SafeDivide' */
      /* End of Outputs for SubSystem: '<S286>/SafeDivide' */

      /* SignalConversion: '<S286>/Signal Conversion' */
      VfLKAS_Am2 = rtb_A_ALatRelLaneMkrRi;

      /* SignalConversion: '<S286>/Signal Conversion1' */
      VfLKAS_Am1 = rtb_A_ALatRelLaneMkrRi;

      /* SignalConversion: '<S286>/OutportBufferForSolutionFound' incorporates:
       *  Constant: '<S286>/Constant'
       */
      VbLKAS_SolutionFoundForAm = true;

      /* End of Outputs for SubSystem: '<S284>/FirstDegreeSolution' */
    }
    else
    {
      /* Outputs for IfAction SubSystem: '<S284>/EquationSolver' incorporates:
       *  ActionPort: '<S285>/Action Port'
       */
      /* Outputs for Atomic SubSystem: '<S285>/SafeDivide' */
      if (rtb_LOGOP_3_firm_tmp > (((real32_T)fabs((real_T)rtb_MSWCH_2)) *
           5.42101151E-20F))
      {
        /* MATLAB Function: '<S292>/SafeDivide' */
        rtb_MSWCH_2 /= rtb_a;
      }
      else if (rtb_MSWCH_2 > 0.0F)
      {
        /* MATLAB Function: '<S292>/SafeDivide' */
        rtb_MSWCH_2 = LKAS_subsystem_DataTypeMax_matr;
      }
      else if (rtb_MSWCH_2 < 0.0F)
      {
        /* MATLAB Function: '<S292>/SafeDivide' */
        rtb_MSWCH_2 = LKAS_subsystem_DataTypeMin_dr0v;
      }
      else
      {
        /* MATLAB Function: '<S292>/SafeDivide' */
        rtb_MSWCH_2 = 0.0F;
      }

      /* End of Outputs for SubSystem: '<S285>/SafeDivide' */

      /* Product: '<S285>/Product' incorporates:
       *  Constant: '<S285>/Constant'
       *  MATLAB Function: '<S292>/SafeDivide'
       */
      rtb_a *= (-2.0F);

      /* Outputs for Atomic SubSystem: '<S285>/SafeDivide2' */
      if (((real32_T)fabs((real_T)rtb_a)) > (tmp * 5.42101151E-20F))
      {
        rtb_A_ALatRelLaneMkrRi /= rtb_a;
      }
      else if (rtb_A_ALatRelLaneMkrRi > 0.0F)
      {
        rtb_A_ALatRelLaneMkrRi = LKAS_subsystem_DataTypeMax_matr;
      }
      else if (rtb_A_ALatRelLaneMkrRi < 0.0F)
      {
        rtb_A_ALatRelLaneMkrRi = LKAS_subsystem_DataTypeMin_dr0v;
      }
      else
      {
        rtb_A_ALatRelLaneMkrRi = 0.0F;
      }

      /* End of Outputs for SubSystem: '<S285>/SafeDivide2' */

      /* Sum: '<S285>/Subtract' incorporates:
       *  Product: '<S285>/Product1'
       */
      rtb_MSWCH_2 = (rtb_A_ALatRelLaneMkrRi * rtb_A_ALatRelLaneMkrRi) -
        rtb_MSWCH_2;

      /* If: '<S285>/If' */
      if (rtb_MSWCH_2 < 0.0F)
      {
        /* Outputs for IfAction SubSystem: '<S285>/DefaultSolution' incorporates:
         *  ActionPort: '<S291>/Action Port'
         */
        /* SignalConversion: '<S285>/Signal Conversion2' incorporates:
         *  Constant: '<S291>/Constant'
         *  Constant: '<S291>/Constant2'
         *  SignalConversion: '<S291>/Signal Conversion'
         */
        VfLKAS_Am1 = 0.0F;
        VfLKAS_Am2 = 0.0F;

        /* SignalConversion: '<S285>/Signal Conversion1' incorporates:
         *  Constant: '<S291>/Constant1'
         *  SignalConversion: '<S291>/OutportBufferForSolutionFound'
         */
        VbLKAS_SolutionFoundForAm = false;

        /* End of Outputs for SubSystem: '<S285>/DefaultSolution' */
      }
      else
      {
        /* Outputs for IfAction SubSystem: '<S285>/ComputeSolution' incorporates:
         *  ActionPort: '<S290>/Action Port'
         */
        /* Sqrt: '<S290>/Sqrt' */
        rtb_MSWCH_2 = (real32_T)sqrt((real_T)rtb_MSWCH_2);

        /* SignalConversion: '<S285>/Signal Conversion2' incorporates:
         *  Sum: '<S290>/Add'
         *  Sum: '<S290>/Subtract'
         */
        VfLKAS_Am1 = rtb_A_ALatRelLaneMkrRi + rtb_MSWCH_2;
        VfLKAS_Am2 = rtb_A_ALatRelLaneMkrRi - rtb_MSWCH_2;

        /* SignalConversion: '<S285>/Signal Conversion1' incorporates:
         *  Constant: '<S290>/Constant'
         *  SignalConversion: '<S290>/OutportBufferForSolutionFound'
         */
        VbLKAS_SolutionFoundForAm = true;

        /* End of Outputs for SubSystem: '<S285>/ComputeSolution' */
      }

      /* End of If: '<S285>/If' */
      /* End of Outputs for SubSystem: '<S284>/EquationSolver' */
    }

    /* If: '<S276>/IfEnabled' incorporates:
     *  Constant: '<S261>/Constant1'
     */
    rtAction = -1;
    if (VbLKAS_SolutionFoundForAm)
    {
      rtAction = 0;
    }

    if (rtAction == 0)
    {
      /* Outputs for IfAction SubSystem: '<S276>/calc_dt' incorporates:
       *  ActionPort: '<S299>/Action Port'
       */
      LKAS_subsystem_integrat_calc_dt(VfLKAS_Am1, rtb_Out_mt3c, 0.0F, rtb_dv,
        &LKAS_subsystem_integrated_B.Quotient_aoh0);

      /* End of Outputs for SubSystem: '<S276>/calc_dt' */
    }

    /* End of If: '<S276>/IfEnabled' */

    /* Saturate: '<S276>/Saturation' */
    if (LKAS_subsystem_integrated_B.Quotient_aoh0 > 1.0E+10F)
    {
      VfLKAS_dt1 = 1.0E+10F;
    }
    else if (LKAS_subsystem_integrated_B.Quotient_aoh0 < (-1.0E+10F))
    {
      VfLKAS_dt1 = (-1.0E+10F);
    }
    else
    {
      VfLKAS_dt1 = LKAS_subsystem_integrated_B.Quotient_aoh0;
    }

    /* End of Saturate: '<S276>/Saturation' */

    /* If: '<S276>/IfEnabled1' incorporates:
     *  Constant: '<S261>/Constant1'
     */
    rtAction = -1;
    if (VbLKAS_SolutionFoundForAm)
    {
      rtAction = 0;
    }

    if (rtAction == 0)
    {
      /* Outputs for IfAction SubSystem: '<S276>/calc_dt1' incorporates:
       *  ActionPort: '<S300>/Action Port'
       */
      LKAS_subsystem_integrat_calc_dt(VfLKAS_Am2, rtb_Out_mt3c, 0.0F, rtb_dv,
        &LKAS_subsystem_integrated_B.Quotient);

      /* End of Outputs for SubSystem: '<S276>/calc_dt1' */
    }

    /* End of If: '<S276>/IfEnabled1' */

    /* Saturate: '<S276>/Saturation1' */
    if (LKAS_subsystem_integrated_B.Quotient > 1.0E+10F)
    {
      VfLKAS_dt2 = 1.0E+10F;
    }
    else if (LKAS_subsystem_integrated_B.Quotient < (-1.0E+10F))
    {
      VfLKAS_dt2 = (-1.0E+10F);
    }
    else
    {
      VfLKAS_dt2 = LKAS_subsystem_integrated_B.Quotient;
    }

    /* End of Saturate: '<S276>/Saturation1' */

    /* Outputs for Atomic SubSystem: '<S270>/CalculateTrajectory' */
    /* If: '<S277>/If' */
    if (VbLKAS_SolutionFoundForAm)
    {
      /* Outputs for IfAction SubSystem: '<S277>/IfSolutionFoundForAm' incorporates:
       *  ActionPort: '<S305>/Action Port'
       */
      /* Product: '<S325>/PROD_1' incorporates:
       *  Product: '<S325>/PROD_3'
       */
      rtb_A_ALatRelLaneMkrRi = VfLKAS_dt1 * VfLKAS_dt1;

      /* Product: '<S325>/PROD_5' incorporates:
       *  Constant: '<S323>/Constant'
       *  Product: '<S323>/PROD_1'
       *  Product: '<S326>/PROD_1'
       *  Sum: '<S323>/ADD_1'
       */
      rtb_a = VfLKAS_dt1 * ((((rtb_Out_mt3c + rtb_Out_mt3c) + VfLKAS_Am1) +
        VfLKAS_Am1) * 0.25F);

      /* Sum: '<S325>/ADD_3' incorporates:
       *  Constant: '<S261>/Constant1'
       *  Constant: '<S321>/Constant'
       *  Constant: '<S322>/Constant'
       *  Gain: '<S321>/G1'
       *  Gain: '<S321>/G2'
       *  Gain: '<S321>/G3'
       *  Gain: '<S322>/G1'
       *  Gain: '<S322>/G2'
       *  Gain: '<S322>/G3'
       *  Product: '<S321>/PROD_1'
       *  Product: '<S322>/PROD_1'
       *  Product: '<S325>/PROD_1'
       *  Product: '<S325>/PROD_2'
       *  Product: '<S325>/PROD_3'
       *  Product: '<S325>/PROD_4'
       *  Product: '<S325>/PROD_5'
       *  Sum: '<S321>/ADD_1'
       *  Sum: '<S322>/ADD_1'
       *  Sum: '<S325>/ADD_1'
       */
      VfLKAS_FirstEndPos = (((rtb_A_ALatRelLaneMkrRi * (((((4.0F * rtb_Out_mt3c)
        + (3.0F * rtb_Out_mt3c)) + (2.0F * VfLKAS_Am1)) + VfLKAS_Am1) * 0.05F))
        + (VfLKAS_dt1 * rtb_A_ALatRelLaneMkrLe)) + (rtb_A_ALatRelLaneMkrRi *
        (((((4.0F * VfLKAS_Am1) + (3.0F * VfLKAS_Am1)) + (2.0F * 0.0F)) + 0.0F) *
         0.05F))) + (VfLKAS_dt1 * (rtb_A_ALatRelLaneMkrLe + rtb_a));

      /* RelationalOperator: '<S307>/RELOP_2' incorporates:
       *  Abs: '<S307>/ABS_1'
       *  Constant: '<S261>/k_LKA_LoPosVal'
       *  SignalConversion: '<S273>/Signal Conversion'
       *  SignalConversion: '<S274>/Signal Conversion'
       *  Sum: '<S307>/ADD_1'
       *
       * Block description for '<S261>/k_LKA_LoPosVal':
       *  _V3p4.LDW2.000_676_
       */
      VbLKAS_FirstEndPositionOK = (((real32_T)fabs((real_T)((real32_T)
        (VfLKAS_FirstEndPos - VfLKAS_delta_pos_sLKA)))) < KfLKAS_d_PosVal);

      /* Sum: '<S326>/ADD_1' incorporates:
       *  Constant: '<S261>/Constant1'
       *  Constant: '<S324>/Constant'
       *  Product: '<S324>/PROD_1'
       *  Product: '<S326>/PROD_2'
       *  Sum: '<S324>/ADD_1'
       */
      VfLKAS_FirstEndVlat = (rtb_a + (VfLKAS_dt1 * ((((VfLKAS_Am1 + VfLKAS_Am1)
        + 0.0F) + 0.0F) * 0.25F))) + rtb_A_ALatRelLaneMkrLe;

      /* RelationalOperator: '<S307>/RELOP_1' incorporates:
       *  Abs: '<S307>/ABS_2'
       *  Constant: '<S261>/k_LKA_LoPosVal'
       *  Constant: '<S270>/CONTS_ZERO'
       *  SignalConversion: '<S274>/Signal Conversion'
       *  Sum: '<S307>/ADD_2'
       *
       * Block description for '<S261>/k_LKA_LoPosVal':
       *  _V3p4.LDW2.000_676_
       */
      VbLKAS_FirstEndVLatOK = (((real32_T)fabs((real_T)((real32_T)
        (VfLKAS_FirstEndVlat - 0.0F)))) < KfLKAS_d_PosVal);

      /* RelationalOperator: '<S317>/Compare' incorporates:
       *  Constant: '<S317>/Constant'
       */
      rtb_LOGOP_3_gb3p = (rtb_A_ALatRelLaneMkrLe >= 0.0F);

      /* Logic: '<S307>/LOGOP_1' incorporates:
       *  Constant: '<S315>/Constant'
       *  Constant: '<S316>/Constant'
       *  Constant: '<S318>/Constant'
       *  Logic: '<S307>/Logical Operator'
       *  RelationalOperator: '<S307>/Relational Operator1'
       *  RelationalOperator: '<S307>/Relational Operator2'
       *  RelationalOperator: '<S315>/Compare'
       *  RelationalOperator: '<S316>/Compare'
       *  RelationalOperator: '<S318>/Compare'
       *  SignalConversion: '<S273>/Signal Conversion'
       *  Sum: '<S307>/Add'
       */
      VbLKAS_TrajectoryFoundAm1 = (((((VfLKAS_dt1 >= 0.0F) &&
        VbLKAS_FirstEndPositionOK) && VbLKAS_FirstEndVLatOK) && (((int32_T)
        ((!((VfLKAS_Am1 - rtb_Out_mt3c) >= 0.0F)) ? 1 : 0)) == ((int32_T)
        (rtb_LOGOP_3_gb3p ? 1 : 0)))) && (((int32_T)(rtb_LOGOP_3_gb3p ? 1 : 0)) ==
        ((int32_T)((VfLKAS_delta_pos_sLKA >= 0.0F) ? 1 : 0))));

      /* Product: '<S335>/PROD_1' incorporates:
       *  Constant: '<S335>/Constant'
       *  Sum: '<S335>/ADD_1'
       */
      rtb_A_ALatRelLaneMkrRi = (((rtb_Out_mt3c + rtb_Out_mt3c) + VfLKAS_Am2) +
        VfLKAS_Am2) * 0.25F;

      /* Sum: '<S337>/ADD_3' incorporates:
       *  Constant: '<S261>/Constant1'
       *  Constant: '<S333>/Constant'
       *  Constant: '<S334>/Constant'
       *  Gain: '<S333>/G1'
       *  Gain: '<S333>/G2'
       *  Gain: '<S333>/G3'
       *  Gain: '<S334>/G1'
       *  Gain: '<S334>/G2'
       *  Gain: '<S334>/G3'
       *  Product: '<S333>/PROD_1'
       *  Product: '<S334>/PROD_1'
       *  Product: '<S337>/PROD_1'
       *  Product: '<S337>/PROD_2'
       *  Product: '<S337>/PROD_3'
       *  Product: '<S337>/PROD_4'
       *  Product: '<S337>/PROD_5'
       *  Sum: '<S333>/ADD_1'
       *  Sum: '<S334>/ADD_1'
       *  Sum: '<S337>/ADD_1'
       */
      VfLKAS_SecEndPos = ((((VfLKAS_dt2 * VfLKAS_dt2) * (((((4.0F * rtb_Out_mt3c)
        + (3.0F * rtb_Out_mt3c)) + (2.0F * VfLKAS_Am2)) + VfLKAS_Am2) * 0.05F))
                           + (VfLKAS_dt2 * rtb_A_ALatRelLaneMkrLe)) +
                          ((VfLKAS_dt2 * VfLKAS_dt2) * (((((4.0F * VfLKAS_Am2) +
        (3.0F * VfLKAS_Am2)) + (2.0F * 0.0F)) + 0.0F) * 0.05F))) + (VfLKAS_dt2 *
        (rtb_A_ALatRelLaneMkrLe + (VfLKAS_dt2 * rtb_A_ALatRelLaneMkrRi)));

      /* RelationalOperator: '<S308>/RELOP_2' incorporates:
       *  Abs: '<S308>/ABS_1'
       *  Constant: '<S261>/k_LKA_LoPosVal'
       *  SignalConversion: '<S273>/Signal Conversion'
       *  SignalConversion: '<S274>/Signal Conversion'
       *  Sum: '<S308>/ADD_1'
       *
       * Block description for '<S261>/k_LKA_LoPosVal':
       *  _V3p4.LDW2.000_676_
       */
      VbLKAS_SecEndPositionOK = (((real32_T)fabs((real_T)((real32_T)
        (VfLKAS_SecEndPos - VfLKAS_delta_pos_sLKA)))) < KfLKAS_d_PosVal);

      /* Sum: '<S338>/ADD_1' incorporates:
       *  Constant: '<S261>/Constant1'
       *  Constant: '<S336>/Constant'
       *  Product: '<S336>/PROD_1'
       *  Product: '<S338>/PROD_1'
       *  Product: '<S338>/PROD_2'
       *  Sum: '<S336>/ADD_1'
       */
      VfLKAS_SecEndVlat = ((VfLKAS_dt2 * rtb_A_ALatRelLaneMkrRi) + (VfLKAS_dt2 *
        ((((VfLKAS_Am2 + VfLKAS_Am2) + 0.0F) + 0.0F) * 0.25F))) +
        rtb_A_ALatRelLaneMkrLe;

      /* RelationalOperator: '<S308>/RELOP_1' incorporates:
       *  Abs: '<S308>/ABS_2'
       *  Constant: '<S261>/k_LKA_LoPosVal'
       *  Constant: '<S270>/CONTS_ZERO'
       *  SignalConversion: '<S274>/Signal Conversion'
       *  Sum: '<S308>/ADD_2'
       *
       * Block description for '<S261>/k_LKA_LoPosVal':
       *  _V3p4.LDW2.000_676_
       */
      VbLKAS_SecEndVLatOK = (((real32_T)fabs((real_T)((real32_T)
        (VfLKAS_SecEndVlat - 0.0F)))) < KfLKAS_d_PosVal);

      /* RelationalOperator: '<S329>/Compare' incorporates:
       *  Constant: '<S329>/Constant'
       */
      rtb_LOGOP_3_gb3p = (rtb_A_ALatRelLaneMkrLe >= 0.0F);

      /* Logic: '<S308>/LOGOP_1' incorporates:
       *  Constant: '<S327>/Constant'
       *  Constant: '<S328>/Constant'
       *  Constant: '<S330>/Constant'
       *  Logic: '<S308>/Logical Operator'
       *  RelationalOperator: '<S308>/Relational Operator1'
       *  RelationalOperator: '<S308>/Relational Operator2'
       *  RelationalOperator: '<S327>/Compare'
       *  RelationalOperator: '<S328>/Compare'
       *  RelationalOperator: '<S330>/Compare'
       *  SignalConversion: '<S273>/Signal Conversion'
       *  Sum: '<S308>/Add'
       */
      VbLKAS_TrajectoryFoundAm2 = (((((VfLKAS_dt2 >= 0.0F) &&
        VbLKAS_SecEndPositionOK) && VbLKAS_SecEndVLatOK) && (((int32_T)
        ((!((VfLKAS_Am2 - rtb_Out_mt3c) >= 0.0F)) ? 1 : 0)) == ((int32_T)
        (rtb_LOGOP_3_gb3p ? 1 : 0)))) && (((int32_T)(rtb_LOGOP_3_gb3p ? 1 : 0)) ==
        ((int32_T)((VfLKAS_delta_pos_sLKA >= 0.0F) ? 1 : 0))));

      /* Gain: '<S310>/G_2' incorporates:
       *  Sum: '<S310>/ADD_2'
       */
      rtb_A_ALatRelLaneMkrLe = 0.75F * (((VfLKAS_Am2 - rtb_Out_mt3c) -
        rtb_Out_mt3c) + VfLKAS_Am2);

      /* Outputs for Atomic SubSystem: '<S310>/SafeDivide' */
      /* Outputs for Atomic SubSystem: '<S310>/SafeDivide1' */
      /* MATLAB Function: '<S345>/SafeDivide' incorporates:
       *  Abs: '<S346>/Abs'
       *  MATLAB Function: '<S344>/SafeDivide'
       */
      tmp = (real32_T)fabs((real_T)VfLKAS_dt2);

      /* End of Outputs for SubSystem: '<S310>/SafeDivide' */
      if (tmp > (((real32_T)fabs((real_T)rtb_A_ALatRelLaneMkrLe)) *
                 5.42101151E-20F))
      {
        rtb_A_ALatRelLaneMkrLe /= VfLKAS_dt2;
      }
      else if (rtb_A_ALatRelLaneMkrLe > 0.0F)
      {
        rtb_A_ALatRelLaneMkrLe = LKAS_subsystem_DataTypeMax_matr;
      }
      else if (rtb_A_ALatRelLaneMkrLe < 0.0F)
      {
        rtb_A_ALatRelLaneMkrLe = LKAS_subsystem_DataTypeMin_dr0v;
      }
      else
      {
        rtb_A_ALatRelLaneMkrLe = 0.0F;
      }

      /* End of MATLAB Function: '<S345>/SafeDivide' */
      /* End of Outputs for SubSystem: '<S310>/SafeDivide1' */

      /* Gain: '<S310>/G_1' incorporates:
       *  Constant: '<S261>/Constant1'
       *  Sum: '<S310>/ADD_1'
       */
      rtb_A_ALatRelLaneMkrRi = 0.75F * (((0.0F - VfLKAS_Am2) - VfLKAS_Am2) +
        0.0F);

      /* Outputs for Atomic SubSystem: '<S310>/SafeDivide' */
      /* MATLAB Function: '<S344>/SafeDivide' */
      if (tmp > (((real32_T)fabs((real_T)rtb_A_ALatRelLaneMkrRi)) *
                 5.42101151E-20F))
      {
        rtb_A_ALatRelLaneMkrRi /= VfLKAS_dt2;
      }
      else if (rtb_A_ALatRelLaneMkrRi > 0.0F)
      {
        rtb_A_ALatRelLaneMkrRi = LKAS_subsystem_DataTypeMax_matr;
      }
      else if (rtb_A_ALatRelLaneMkrRi < 0.0F)
      {
        rtb_A_ALatRelLaneMkrRi = LKAS_subsystem_DataTypeMin_dr0v;
      }
      else
      {
        rtb_A_ALatRelLaneMkrRi = 0.0F;
      }

      /* End of Outputs for SubSystem: '<S310>/SafeDivide' */

      /* Switch: '<S310>/SWCH_1' incorporates:
       *  Constant: '<S310>/Constant'
       *  Constant: '<S346>/LimitSource'
       *  RelationalOperator: '<S346>/Relational Operator'
       */
      if (tmp > 1.0E-6F)
      {
        /* Switch: '<S310>/SWCH_2' incorporates:
         *  Abs: '<S310>/Abs_1'
         *  Abs: '<S310>/Abs_2'
         *  RelationalOperator: '<S310>/Relop_1'
         */
        if (((real32_T)fabs((real_T)rtb_A_ALatRelLaneMkrLe)) > ((real32_T)fabs
             ((real_T)rtb_A_ALatRelLaneMkrRi)))
        {
        }
        else
        {
          rtb_A_ALatRelLaneMkrLe = rtb_A_ALatRelLaneMkrRi;
        }

        /* End of Switch: '<S310>/SWCH_2' */
      }
      else
      {
        rtb_A_ALatRelLaneMkrLe = 0.0F;
      }

      /* End of Switch: '<S310>/SWCH_1' */

      /* Gain: '<S309>/G_2' incorporates:
       *  Sum: '<S309>/ADD_2'
       */
      rtb_A_ALatRelLaneMkrRi = 0.75F * (((VfLKAS_Am1 - rtb_Out_mt3c) -
        rtb_Out_mt3c) + VfLKAS_Am1);

      /* Outputs for Atomic SubSystem: '<S309>/SafeDivide1' */
      /* MATLAB Function: '<S340>/SafeDivide' */
      if (((real32_T)fabs((real_T)VfLKAS_dt1)) > (((real32_T)fabs((real_T)
             rtb_A_ALatRelLaneMkrRi)) * 5.42101151E-20F))
      {
        rtb_A_ALatRelLaneMkrRi /= VfLKAS_dt1;
      }
      else if (rtb_A_ALatRelLaneMkrRi > 0.0F)
      {
        rtb_A_ALatRelLaneMkrRi = LKAS_subsystem_DataTypeMax_matr;
      }
      else if (rtb_A_ALatRelLaneMkrRi < 0.0F)
      {
        rtb_A_ALatRelLaneMkrRi = LKAS_subsystem_DataTypeMin_dr0v;
      }
      else
      {
        rtb_A_ALatRelLaneMkrRi = 0.0F;
      }

      /* End of MATLAB Function: '<S340>/SafeDivide' */
      /* End of Outputs for SubSystem: '<S309>/SafeDivide1' */

      /* Gain: '<S309>/G_1' incorporates:
       *  Constant: '<S261>/Constant1'
       *  Sum: '<S309>/ADD_1'
       */
      rtb_MSWCH_2 = 0.75F * (((0.0F - VfLKAS_Am1) - VfLKAS_Am1) + 0.0F);

      /* Outputs for Atomic SubSystem: '<S309>/SafeDivide' */
      /* MATLAB Function: '<S339>/SafeDivide' */
      if (((real32_T)fabs((real_T)VfLKAS_dt1)) > (((real32_T)fabs((real_T)
             rtb_MSWCH_2)) * 5.42101151E-20F))
      {
        rtb_MSWCH_2 /= VfLKAS_dt1;
      }
      else if (rtb_MSWCH_2 > 0.0F)
      {
        rtb_MSWCH_2 = LKAS_subsystem_DataTypeMax_matr;
      }
      else if (rtb_MSWCH_2 < 0.0F)
      {
        rtb_MSWCH_2 = LKAS_subsystem_DataTypeMin_dr0v;
      }
      else
      {
        rtb_MSWCH_2 = 0.0F;
      }

      /* End of MATLAB Function: '<S339>/SafeDivide' */
      /* End of Outputs for SubSystem: '<S309>/SafeDivide' */

      /* Switch: '<S309>/SWCH_1' incorporates:
       *  Abs: '<S341>/Abs'
       *  Constant: '<S309>/Constant'
       *  Constant: '<S341>/LimitSource'
       *  RelationalOperator: '<S341>/Relational Operator'
       */
      if (((real32_T)fabs((real_T)VfLKAS_dt1)) > 1.0E-6F)
      {
        /* Switch: '<S309>/SWCH_2' incorporates:
         *  Abs: '<S309>/Abs_1'
         *  Abs: '<S309>/Abs_2'
         *  RelationalOperator: '<S309>/Relop_1'
         */
        if (((real32_T)fabs((real_T)rtb_A_ALatRelLaneMkrRi)) > ((real32_T)fabs
             ((real_T)rtb_MSWCH_2)))
        {
        }
        else
        {
          rtb_A_ALatRelLaneMkrRi = rtb_MSWCH_2;
        }

        /* End of Switch: '<S309>/SWCH_2' */
      }
      else
      {
        rtb_A_ALatRelLaneMkrRi = 0.0F;
      }

      /* End of Switch: '<S309>/SWCH_1' */

      /* If: '<S305>/If' incorporates:
       *  Logic: '<S311>/Logop_1'
       *  Logic: '<S311>/Logop_13'
       *  Logic: '<S311>/Logop_2'
       *  Logic: '<S311>/Logop_3'
       *  Logic: '<S311>/Logop_4'
       *  Logic: '<S311>/Logop_5'
       */
      if ((VbLKAS_TrajectoryFoundAm1 && (!VbLKAS_TrajectoryFoundAm2)) ||
          (VbLKAS_TrajectoryFoundAm1 && VbLKAS_TrajectoryFoundAm2))
      {
        /* Outputs for IfAction SubSystem: '<S305>/UseFirstRoot' incorporates:
         *  ActionPort: '<S313>/Action Port'
         */
        /* SignalConversion: '<S313>/OutportBufferForTrajectoryFound' incorporates:
         *  Constant: '<S313>/true'
         */
        VbLKAS_TrajectoryFound_sLKA = true;

        /* Switch: '<S313>/SWCH_1' incorporates:
         *  Abs: '<S313>/Abs_3'
         *  Abs: '<S313>/Abs_4'
         *  Constant: '<S261>/Constant1'
         *  RelationalOperator: '<S313>/Relop_2'
         */
        if (((real32_T)fabs((real_T)rtb_Out_mt3c)) > ((real32_T)fabs((real_T)
              0.0F)))
        {
          rtb_A_ALatRelLaneMkrLe = rtb_Out_mt3c;
        }
        else
        {
          rtb_A_ALatRelLaneMkrLe = 0.0F;
        }

        /* End of Switch: '<S313>/SWCH_1' */

        /* Switch: '<S313>/SWCH_2' incorporates:
         *  Abs: '<S313>/Abs_1'
         *  Abs: '<S313>/Abs_2'
         *  RelationalOperator: '<S313>/Relop_1'
         */
        if (((real32_T)fabs((real_T)rtb_A_ALatRelLaneMkrLe)) > ((real32_T)fabs
             ((real_T)VfLKAS_Am1)))
        {
          VfLKAS_LatAccNeeded_sLKA = rtb_A_ALatRelLaneMkrLe;
        }
        else
        {
          VfLKAS_LatAccNeeded_sLKA = VfLKAS_Am1;
        }

        /* End of Switch: '<S313>/SWCH_2' */

        /* SignalConversion: '<S350>/Signal Conversion' */
        LKAS_subsystem_integrated_B.ITC_dt[0] = VfLKAS_dt1;
        LKAS_subsystem_integrated_B.ITC_dt[1] = VfLKAS_dt1;

        /* SignalConversion: '<S351>/Signal Conversion' incorporates:
         *  Constant: '<S261>/Constant1'
         */
        LKAS_subsystem_integrated_B.ITC_cp[0] = rtb_Out_mt3c;
        LKAS_subsystem_integrated_B.ITC_cp[1] = rtb_Out_mt3c;
        LKAS_subsystem_integrated_B.ITC_cp[2] = VfLKAS_Am1;
        LKAS_subsystem_integrated_B.ITC_cp[3] = VfLKAS_Am1;
        LKAS_subsystem_integrated_B.ITC_cp[4] = VfLKAS_Am1;
        LKAS_subsystem_integrated_B.ITC_cp[5] = VfLKAS_Am1;
        LKAS_subsystem_integrated_B.ITC_cp[6] = 0.0F;
        LKAS_subsystem_integrated_B.ITC_cp[7] = 0.0F;

        /* SignalConversion: '<S352>/Signal Conversion' */
        VfLKAS_JerkNeeded_sLkA = rtb_A_ALatRelLaneMkrRi;

        /* End of Outputs for SubSystem: '<S305>/UseFirstRoot' */
      }
      else if ((!VbLKAS_TrajectoryFoundAm1) && VbLKAS_TrajectoryFoundAm2)
      {
        /* Outputs for IfAction SubSystem: '<S305>/UseSecondRoot' incorporates:
         *  ActionPort: '<S314>/Action Port'
         */
        /* SignalConversion: '<S314>/OutportBufferForTrajectoryFound' incorporates:
         *  Constant: '<S314>/true'
         */
        VbLKAS_TrajectoryFound_sLKA = true;

        /* Switch: '<S314>/SWCH_1' incorporates:
         *  Abs: '<S314>/Abs_3'
         *  Abs: '<S314>/Abs_4'
         *  Constant: '<S261>/Constant1'
         *  RelationalOperator: '<S314>/Relop_2'
         */
        if (((real32_T)fabs((real_T)rtb_Out_mt3c)) > ((real32_T)fabs((real_T)
              0.0F)))
        {
          rtb_A_ALatRelLaneMkrRi = rtb_Out_mt3c;
        }
        else
        {
          rtb_A_ALatRelLaneMkrRi = 0.0F;
        }

        /* End of Switch: '<S314>/SWCH_1' */

        /* Switch: '<S314>/SWCH_2' incorporates:
         *  Abs: '<S314>/Abs_1'
         *  Abs: '<S314>/Abs_2'
         *  RelationalOperator: '<S314>/Relop_1'
         */
        if (((real32_T)fabs((real_T)rtb_A_ALatRelLaneMkrRi)) > ((real32_T)fabs
             ((real_T)VfLKAS_Am2)))
        {
          VfLKAS_LatAccNeeded_sLKA = rtb_A_ALatRelLaneMkrRi;
        }
        else
        {
          VfLKAS_LatAccNeeded_sLKA = VfLKAS_Am2;
        }

        /* End of Switch: '<S314>/SWCH_2' */

        /* SignalConversion: '<S353>/Signal Conversion' */
        LKAS_subsystem_integrated_B.ITC_dt[0] = VfLKAS_dt2;
        LKAS_subsystem_integrated_B.ITC_dt[1] = VfLKAS_dt2;

        /* SignalConversion: '<S354>/Signal Conversion' incorporates:
         *  Constant: '<S261>/Constant1'
         */
        LKAS_subsystem_integrated_B.ITC_cp[0] = rtb_Out_mt3c;
        LKAS_subsystem_integrated_B.ITC_cp[1] = rtb_Out_mt3c;
        LKAS_subsystem_integrated_B.ITC_cp[2] = VfLKAS_Am2;
        LKAS_subsystem_integrated_B.ITC_cp[3] = VfLKAS_Am2;
        LKAS_subsystem_integrated_B.ITC_cp[4] = VfLKAS_Am2;
        LKAS_subsystem_integrated_B.ITC_cp[5] = VfLKAS_Am2;
        LKAS_subsystem_integrated_B.ITC_cp[6] = 0.0F;
        LKAS_subsystem_integrated_B.ITC_cp[7] = 0.0F;

        /* SignalConversion: '<S355>/Signal Conversion' */
        VfLKAS_JerkNeeded_sLkA = rtb_A_ALatRelLaneMkrLe;

        /* End of Outputs for SubSystem: '<S305>/UseSecondRoot' */
      }
      else
      {
        /* Outputs for IfAction SubSystem: '<S305>/UseDefault' incorporates:
         *  ActionPort: '<S312>/Action Port'
         */
        LKAS_subsystem_integ_UseDefault(&VbLKAS_TrajectoryFound_sLKA,
          LKAS_subsystem_integrated_B.ITC_dt, LKAS_subsystem_integrated_B.ITC_cp,
          &VfLKAS_LatAccNeeded_sLKA, &VfLKAS_JerkNeeded_sLkA);

        /* End of Outputs for SubSystem: '<S305>/UseDefault' */
      }

      /* End of If: '<S305>/If' */
      /* End of Outputs for SubSystem: '<S277>/IfSolutionFoundForAm' */
    }
    else
    {
      /* Outputs for IfAction SubSystem: '<S277>/UseDefault' incorporates:
       *  ActionPort: '<S306>/Action Port'
       */
      LKAS_subsystem_integ_UseDefault(&VbLKAS_TrajectoryFound_sLKA,
        LKAS_subsystem_integrated_B.ITC_dt, LKAS_subsystem_integrated_B.ITC_cp,
        &VfLKAS_LatAccNeeded_sLKA, &VfLKAS_JerkNeeded_sLkA);

      /* End of Outputs for SubSystem: '<S277>/UseDefault' */
    }

    /* End of If: '<S277>/If' */
    /* End of Outputs for SubSystem: '<S270>/CalculateTrajectory' */

    /* Sum: '<S270>/ADD_1' */
    LKAS_subsystem_integrated_B.TrajectoryTime =
      LKAS_subsystem_integrated_B.ITC_dt[0] +
      LKAS_subsystem_integrated_B.ITC_dt[1];
  }
  else
  {
    if (LKAS_subsystem_integrated_DW.ITCWithAdditionalConditionForVa)
    {
      LKAS_subsystem_integrated_DW.ITCWithAdditionalConditionForVa = false;
    }
  }

  /* End of Logic: '<S259>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S259>/ITCWithAdditionalConditionForValidPath_sLKA' */

  /* Switch: '<S262>/Switch2' incorporates:
   *  Constant: '<S262>/Zero_2'
   */
  for (i = 0; i < 8; i++)
  {
    if (VbLKAS_zero_trajectory_found)
    {
      rtb_cp_sLKA[i] = LKAS_subsystem_integrate_ConstP.pooled14[(i)];
    }
    else
    {
      rtb_cp_sLKA[i] = LKAS_subsystem_integrated_B.ITC_cp[i];
    }
  }

  /* End of Switch: '<S262>/Switch2' */

  /* Switch: '<S262>/Switch5' */
  if (VbLKAS_zero_trajectory_found)
  {
    VfLKAS_TimeNeeded_sLKA = LKAS_subsystem_integrate_ConstB.SumofElements;
  }
  else
  {
    VfLKAS_TimeNeeded_sLKA = LKAS_subsystem_integrated_B.TrajectoryTime;
  }

  /* End of Switch: '<S262>/Switch5' */

  /* Switch: '<S263>/Switch' incorporates:
   *  Switch: '<S263>/Switch1'
   */
  if (rtb_RelationalOperator3_j4ur)
  {
    /* Switch: '<S263>/Switch2' incorporates:
     *  Constant: '<S263>/k_LKA_L_OffsAtMinDeltaPos'
     *  Sum: '<S263>/Add'
     */
    if (VbLKAS_zero_trajectory_found)
    {
      VfLKAS_end_offst_sLKA = rtb_Out_amt1 + KfLKAS_d_OffsAtMinDeltaPos;
    }
    else
    {
      VfLKAS_end_offst_sLKA = rtb_Out_amt1;
    }

    /* End of Switch: '<S263>/Switch2' */
  }
  else if (VbLKAS_zero_trajectory_found)
  {
    /* Switch: '<S263>/Switch1' incorporates:
     *  Constant: '<S263>/k_LKA_L_OffsAtMinDeltaPos'
     *  Gain: '<S263>/G_3'
     *  Sum: '<S263>/Add1'
     */
    VfLKAS_end_offst_sLKA = ((-1.0F) * rtb_Out_amt1) -
      KfLKAS_d_OffsAtMinDeltaPos;
  }
  else
  {
    /* Switch: '<S263>/Switch1' incorporates:
     *  Gain: '<S263>/G_3'
     */
    VfLKAS_end_offst_sLKA = (-1.0F) * rtb_Out_amt1;
  }

  /* End of Switch: '<S263>/Switch' */

  /* BusCreator: '<S238>/Bus Creator2' incorporates:
   *  SignalConversion: '<S250>/Signal Conversion'
   *  SignalConversion: '<S254>/Signal Conversion'
   *  SignalConversion: '<S255>/Signal Conversion'
   *  SignalConversion: '<S256>/Signal Conversion'
   *  SignalConversion: '<S257>/Signal Conversion'
   *  SignalConversion: '<S258>/Signal Conversion'
   */
  LKAS_subsystem_integrated_B.TrajData.ZeroTrajectoryFound_sLKA =
    VbLKAS_zero_trajectory_found;
  LKAS_subsystem_integrated_B.TrajData.TrajectoryFound_sLKA =
    VbLKAS_TrajectoryFound_sLKA;
  LKAS_subsystem_integrated_B.TrajData.JerkNeeded_sLkA = VfLKAS_JerkNeeded_sLkA;
  LKAS_subsystem_integrated_B.TrajData.EndOffset_sLKA = VfLKAS_end_offst_sLKA;
  LKAS_subsystem_integrated_B.TrajData.TimeNeeded_sLKA = VfLKAS_TimeNeeded_sLKA;
  LKAS_subsystem_integrated_B.TrajData.LatAccNeeded_sLKA =
    VfLKAS_LatAccNeeded_sLKA;

  /* Switch: '<S262>/Switch1' */
  if (VbLKAS_zero_trajectory_found)
  {
    /* SignalConversion: '<S249>/Signal Conversion' incorporates:
     *  Constant: '<S262>/Zero_1'
     */
    VfLKAS_dt_sLKA = 0.5F;
  }
  else
  {
    /* SignalConversion: '<S249>/Signal Conversion' */
    VfLKAS_dt_sLKA = LKAS_subsystem_integrated_B.ITC_dt[0];
  }

  /* End of Switch: '<S262>/Switch1' */

  /* SignalConversion: '<S251>/Signal Conversion' */
  VfLKAS_A0_sLKA = rtb_cp_sLKA[0];

  /* SignalConversion: '<S252>/Signal Conversion' */
  VfLKAS_Am_sLKA = rtb_cp_sLKA[3];

  /* SignalConversion: '<S253>/Signal Conversion' */
  VfLKAS_Ae_sLKA = rtb_cp_sLKA[6];

  /* RelationalOperator: '<S366>/Relational Operator3' incorporates:
   *  Constant: '<S372>/Constant'
   */
  rtb_RelationalOperator3_j4ur = (LKAS_subsystem_integrated_B.Out_lr5f ==
    VldForEnag);

  /* RelationalOperator: '<S365>/Relational Operator3' incorporates:
   *  Constant: '<S371>/Constant'
   */
  rtb_LOGOP_3_gb3p = (LKAS_subsystem_integrated_B.Out_cbrj == VldForEnag);

  /* Logic: '<S367>/LOGOP_4' */
  rtb_B_VehHeadingLeft_LeftLaneMk = (rtb_LOGOP_3_gb3p &&
    rtb_RelationalOperator3_j4ur);

  /* UnitDelay: '<S244>/UnitDelay'
   *
   * Block description for '<S244>/UnitDelay':
   *  _V3p4.LDW2.000_1355_
   */
  rtb_UnitDelay_fm1k = VbLKAS_InnerCurvRi_sLKA;

  /* Chart: '<S244>/Chart' incorporates:
   *  Constant: '<S237>/CONST_2'
   */
  LKAS_subsystem_integrated_Chart(rtb_UnitDelay_fm1k, false, &rtb_out_eyyi,
    &LKAS_subsystem_integrated_DW.sf_Chart);

  /* UnitDelay: '<S243>/UnitDelay'
   *
   * Block description for '<S243>/UnitDelay':
   *  _V3p4.LDW2.000_1355_
   */
  rtb_UnitDelay_oz1j = VbLKAS_InnerCurvLe_sLKA;

  /* Chart: '<S243>/Chart' incorporates:
   *  Constant: '<S237>/CONST_2'
   */
  LKAS_subsystem_integrated_Chart(rtb_UnitDelay_oz1j, false, &rtb_out_a5of,
    &LKAS_subsystem_integrated_DW.sf_Chart_g1xu);

  /* Chart: '<S373>/Chart' incorporates:
   *  Constant: '<S367>/TRUE_1'
   *  UnitDelay: '<S373>/UnitDelay1'
   */
  if (!LKAS_subsystem_integrated_DW.flag)
  {
    rtb_out = true;
    LKAS_subsystem_integrated_DW.flag = true;
  }
  else
  {
    rtb_out = VbLKAS_LaneWidthEnbl;
  }

  /* End of Chart: '<S373>/Chart' */

  /* Logic: '<S373>/LogOp3' incorporates:
   *  Constant: '<S367>/k_LKA_L_MaxEnblLaneWidth'
   *  Constant: '<S367>/k_LKA_L_MinDisLaneWidthMargin'
   *  Constant: '<S367>/k_LKA_L_MinEnblLaneWidthMargin'
   *  Logic: '<S367>/LOGOP_1'
   *  Logic: '<S367>/LOGOP_10'
   *  Logic: '<S367>/LOGOP_5'
   *  Logic: '<S367>/LOGOP_9'
   *  Logic: '<S373>/LogOp'
   *  Logic: '<S373>/LogOp2'
   *  RelationalOperator: '<S367>/RELOP_1'
   *  RelationalOperator: '<S367>/RELOP_2'
   *  RelationalOperator: '<S367>/RELOP_3'
   *  RelationalOperator: '<S367>/RELOP_4'
   *  Sum: '<S367>/Add'
   *  Sum: '<S367>/Add1'
   */
  VbLKAS_LaneWidthEnbl = ((rtb_B_VehHeadingLeft_LeftLaneMk &&
    ((LKAS_subsystem_integrated_B.Gain_kbew < KfLKAS_d_MaxEnblLaneWidth) &&
     (LKAS_subsystem_integrated_B.Gain_kbew >
      (LKAS_subsystem_integrated_B.BusCreator1.VehicleWidth +
       KfLKAS_d_MinEnblLaneWidthMargin)))) ||
    ((!(rtb_B_VehHeadingLeft_LeftLaneMk &&
        ((LKAS_subsystem_integrated_B.Gain_kbew > KfLKAS_d_MaxEnblLaneWidth) ||
         (LKAS_subsystem_integrated_B.Gain_kbew <
          (LKAS_subsystem_integrated_B.BusCreator1.VehicleWidth +
           KfLKAS_d_MinDisLaneWidthMargin))))) && rtb_out));

  /* Switch: '<S369>/Switch1' incorporates:
   *  Constant: '<S369>/Constant2'
   *  Constant: '<S369>/Constant4'
   *  Logic: '<S364>/LOGOP_5'
   *  Sum: '<S369>/Sum'
   *  UnitDelay: '<S369>/UnitDelay'
   */
  if (VbLKAS_LaneWidthEnbl && rtb_RelationalOperator3_j4ur)
  {
    rtb_Out_amt1 = LKAS_subsystem_integrated_DW.UnitDelay_DSTATE + 1.0F;
  }
  else
  {
    rtb_Out_amt1 = 0.0F;
  }

  /* End of Switch: '<S369>/Switch1' */

  /* Product: '<S369>/Product' incorporates:
   *  Constant: '<S364>/c_LKA_CallFreq'
   *  Constant: '<S364>/k_LKA_T_RoadEnblOKHoldLow'
   *  Product: '<S368>/Product'
   *
   * Block description for '<S364>/c_LKA_CallFreq':
   *  _V3p4.LDW2.000_895_
   *
   * Block description for '<S364>/k_LKA_T_RoadEnblOKHoldLow':
   *  _V3p4.LDW2.000_311_
   */
  rtb_A_ALatRelLaneMkrLe = KfLKAS_t_RoadEnblOKHoldLow * KfLKAS_CallFreq;

  /* RelationalOperator: '<S369>/RelationalOperator1' incorporates:
   *  Product: '<S369>/Product'
   */
  VbLKAS_RoadEnblRi = (rtb_Out_amt1 > rtb_A_ALatRelLaneMkrLe);

  /* Switch: '<S368>/Switch1' incorporates:
   *  Constant: '<S368>/Constant2'
   *  Constant: '<S368>/Constant4'
   *  Logic: '<S364>/LOGOP_4'
   *  Sum: '<S368>/Sum'
   *  UnitDelay: '<S368>/UnitDelay'
   */
  if (rtb_LOGOP_3_gb3p && VbLKAS_LaneWidthEnbl)
  {
    rtb_A_ALatRelLaneMkrRi = LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_c5t2
      + 1.0F;
  }
  else
  {
    rtb_A_ALatRelLaneMkrRi = 0.0F;
  }

  /* End of Switch: '<S368>/Switch1' */

  /* RelationalOperator: '<S368>/RelationalOperator1' */
  VbLKAS_RoadEnblLe = (rtb_A_ALatRelLaneMkrRi > rtb_A_ALatRelLaneMkrLe);

  /* Switch: '<S364>/SWCH_1' incorporates:
   *  Constant: '<S370>/Constant'
   *  RelationalOperator: '<S364>/RELOP_1'
   */
  if (LKAS_subsystem_integrated_B.IntvTyp_sLKA_pzex == LKAS_SftyLaneKeepAid)
  {
    /* MultiPortSwitch: '<S364>/MSWCH_1' incorporates:
     *  Constant: '<S364>/FALSE'
     */
    switch (LKAS_subsystem_integrated_B.CtrlRef_sLKA)
    {
     case LKAS_LaneMkrToClsLe:
      VbLKAS__RoadEnbl = VbLKAS_RoadEnblLe;
      break;

     case LKAS_LaneMkrToClsRi:
      VbLKAS__RoadEnbl = VbLKAS_RoadEnblRi;
      break;

     default:
      VbLKAS__RoadEnbl = false;
      break;
    }

    /* End of MultiPortSwitch: '<S364>/MSWCH_1' */
  }
  else
  {
    /* MultiPortSwitch: '<S364>/MSWCH_2' incorporates:
     *  Constant: '<S364>/FALSE1'
     */
    switch (LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.IntvSideReq_sLKA)
    {
     case LKAS_IntvSideLe:
      VbLKAS__RoadEnbl = VbLKAS_RoadEnblLe;
      break;

     case LKAS_IntvSideRi:
      VbLKAS__RoadEnbl = VbLKAS_RoadEnblRi;
      break;

     default:
      VbLKAS__RoadEnbl = false;
      break;
    }

    /* End of MultiPortSwitch: '<S364>/MSWCH_2' */
  }

  /* End of Switch: '<S364>/SWCH_1' */

  /* SignalConversion: '<S363>/Signal Conversion' */
  LKAS_subsystem_integrated_B.Out_kk4i = VbLKAS_RoadEnblLe;

  /* SignalConversion: '<S361>/Signal Conversion' */
  LKAS_subsystem_integrated_B.Out_ezky = VbLKAS_RoadEnblRi;

  /* Product: '<S237>/PROD_1' */
  rtb_A_ALatRelLaneMkrLe = rtb_A_ALatRelLaneMkrLe_tmp;

  /* Switch: '<S246>/Switch' incorporates:
   *  Constant: '<S237>/CONST_1'
   *  Constant: '<S246>/Constant'
   *  Logic: '<S246>/Logical Operator'
   *  RelationalOperator: '<S246>/RELOP_1'
   *  RelationalOperator: '<S246>/RELOP_2'
   */
  if ((rtb_A_ALatRelLaneMkrLe_tmp > 0.0F) || (rtb_A_ALatRelLaneMkrLe_tmp < 0.0F))
  {
    rtb_a = rtb_A_ALatRelLaneMkrLe_tmp;
  }
  else
  {
    rtb_a = 0.01F;
  }

  /* End of Switch: '<S246>/Switch' */

  /* Product: '<S246>/Division' incorporates:
   *  Constant: '<S237>/k_LKA_A_CurveSuppOff'
   *
   * Block description for '<S237>/k_LKA_A_CurveSuppOff':
   *  _V3p4.LDW2.000_123_
   */
  rtb_MSWCH_2 = KfLKAS_a_CurveSuppOff / rtb_a;

  /* Logic: '<S243>/LogicalOperator4' incorporates:
   *  RelationalOperator: '<S243>/Rel1'
   *
   * Block description for '<S243>/LogicalOperator4':
   *  _V3p4.LDW2.000_1352_
   *
   * Block description for '<S243>/Rel1':
   *  _V3p4.LDW2.000_1354_
   */
  rtb_B_VehHeadingLeft_LeftLaneMk = !(LKAS_subsystem_integrated_B.Switch1_bjf2 <=
    rtb_MSWCH_2);

  /* Switch: '<S245>/Switch' incorporates:
   *  Constant: '<S237>/CONST_1'
   *  Constant: '<S245>/Constant'
   *  Logic: '<S245>/Logical Operator'
   *  RelationalOperator: '<S245>/RELOP_1'
   *  RelationalOperator: '<S245>/RELOP_2'
   */
  if ((rtb_A_ALatRelLaneMkrLe_tmp > 0.0F) || (rtb_A_ALatRelLaneMkrLe_tmp < 0.0F))
  {
  }
  else
  {
    rtb_A_ALatRelLaneMkrLe = 0.01F;
  }

  /* End of Switch: '<S245>/Switch' */

  /* Product: '<S245>/Division' incorporates:
   *  Constant: '<S237>/k_LKA_A_CurveSuppOn'
   *
   * Block description for '<S237>/k_LKA_A_CurveSuppOn':
   *  _V3p4.LDW2.000_125_
   */
  rtb_A_ALatRelLaneMkrLe = KfLKAS_a_CurveSuppOn / rtb_A_ALatRelLaneMkrLe;

  /* RelationalOperator: '<S243>/Rel'
   *
   * Block description for '<S243>/Rel':
   *  _V3p4.LDW2.000_1353_
   */
  rtb_RelationalOperator3_j4ur = (rtb_A_ALatRelLaneMkrLe <=
    LKAS_subsystem_integrated_B.Switch1_bjf2);

  /* Logic: '<S243>/LogicalOperator3' incorporates:
   *  Logic: '<S243>/LogicalOperator'
   *  Logic: '<S243>/LogicalOperator1'
   *  Logic: '<S243>/LogicalOperator2'
   *
   * Block description for '<S243>/LogicalOperator3':
   *  _V3p4.LDW2.000_1351_
   *
   * Block description for '<S243>/LogicalOperator':
   *  _V3p4.LDW2.000_1348_
   *
   * Block description for '<S243>/LogicalOperator1':
   *  _V3p4.LDW2.000_1349_
   *
   * Block description for '<S243>/LogicalOperator2':
   *  _V3p4.LDW2.000_1350_
   */
  VbLKAS_InnerCurvLe_sLKA = ((rtb_RelationalOperator3_j4ur &&
    rtb_B_VehHeadingLeft_LeftLaneMk) || (((!rtb_RelationalOperator3_j4ur) &&
    rtb_B_VehHeadingLeft_LeftLaneMk) && rtb_out_a5of));

  /* SignalConversion: '<S242>/Signal Conversion' */
  LKAS_subsystem_integrated_B.LogicalOperator1 = VbLKAS_InnerCurvLe_sLKA;

  /* Gain: '<S237>/Neg_3'
   *
   * Block description for '<S237>/Neg_3':
   *  _V3p4.LDW2.000_127_
   */
  rtb_a = (-1.0F) * LKAS_subsystem_integrated_B.Switch1_bjf2;

  /* RelationalOperator: '<S244>/Rel'
   *
   * Block description for '<S244>/Rel':
   *  _V3p4.LDW2.000_1353_
   */
  rtb_B_VehHeadingLeft_LeftLaneMk = (rtb_A_ALatRelLaneMkrLe <= rtb_a);

  /* Logic: '<S244>/LogicalOperator4' incorporates:
   *  RelationalOperator: '<S244>/Rel1'
   *
   * Block description for '<S244>/LogicalOperator4':
   *  _V3p4.LDW2.000_1352_
   *
   * Block description for '<S244>/Rel1':
   *  _V3p4.LDW2.000_1354_
   */
  rtb_RelationalOperator3_j4ur = !(rtb_a <= rtb_MSWCH_2);

  /* Logic: '<S244>/LogicalOperator3' incorporates:
   *  Logic: '<S244>/LogicalOperator'
   *  Logic: '<S244>/LogicalOperator1'
   *  Logic: '<S244>/LogicalOperator2'
   *
   * Block description for '<S244>/LogicalOperator3':
   *  _V3p4.LDW2.000_1351_
   *
   * Block description for '<S244>/LogicalOperator':
   *  _V3p4.LDW2.000_1348_
   *
   * Block description for '<S244>/LogicalOperator1':
   *  _V3p4.LDW2.000_1349_
   *
   * Block description for '<S244>/LogicalOperator2':
   *  _V3p4.LDW2.000_1350_
   */
  VbLKAS_InnerCurvRi_sLKA = ((rtb_B_VehHeadingLeft_LeftLaneMk &&
    rtb_RelationalOperator3_j4ur) || (((!rtb_B_VehHeadingLeft_LeftLaneMk) &&
    rtb_RelationalOperator3_j4ur) && rtb_out_eyyi));

  /* SignalConversion: '<S241>/Signal Conversion' */
  LKAS_subsystem_integrated_B.IsIntvCompleted_sLKA_a1kj =
    VbLKAS_InnerCurvRi_sLKA;

  /* Update for UnitDelay: '<S369>/UnitDelay' */
  LKAS_subsystem_integrated_DW.UnitDelay_DSTATE = rtb_Out_amt1;

  /* Update for UnitDelay: '<S368>/UnitDelay' */
  LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_c5t2 = rtb_A_ALatRelLaneMkrRi;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
