/*
 * File: lccs_control_main.c
 *
 * Code generated for Simulink model 'LCCS_subsystem_integrated'.
 *
 * Model version                  : 1.2176
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Jun 10 09:42:58 2020
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

#include "lccs_control_main.h"

/* Include model header file for global data */
#include "LCCS_subsystem_integrated.h"
#include "LCCS_subsystem_integrated_private.h"
#include "look1_iflf_binlca.h"
#include "mrdivide_9C9aPutf.h"

/* System initialize for atomic system: '<S2>/CalcLCCS_lateral_control_main' */
void CalcLCCS_lateral_control_m_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S7>/lateral_control' */
  /* InitializeConditions for UnitDelay: '<S56>/UnitDelay2' */
  memcpy(&LCCS_subsystem_integrated_DW.UnitDelay2_DSTATE_ljaq[0],
         LCCS_subsystem_integrate_ConstP.UnitDelay2_InitialCondition, (sizeof
          (real32_T)) << 4U);

  /* End of SystemInitialize for SubSystem: '<S7>/lateral_control' */
}

/* Output and update for atomic system: '<S2>/CalcLCCS_lateral_control_main' */
void L_CalcLCCS_lateral_control_main(void)
{
  real32_T matrix_a_[16];
  static const int8_T b[16] =
  {
    1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1
  };

  real32_T AT[16];
  real32_T diff;
  real32_T P_next[16];
  real32_T sum_lateral_error;
  real32_T rtb_Switch_m0yq;
  real32_T rtb_Switch1_fdqv;
  real32_T rtb_UnitDelay1_jw5x;
  real32_T rtb_UnitDelay2_o4fj;
  real32_T rtb_UnitDelay3_g21h;
  real32_T rtb_UnitDelay4_by5g;
  real32_T rtb_UnitDelay6;
  real32_T rtb_UnitDelay7;
  real32_T rtb_UnitDelay8;
  real32_T rtb_UnitDelay9;
  real32_T rtb_Switch2;
  real32_T rtb_Switch2_bhdm;
  real32_T rtb_Product2;
  real32_T rtb_Product_gbzh;
  real32_T rtb_Product1_ngl4;
  real32_T rtb_KtLCCS_slowpath_steer_I_gai;
  int32_T rtb_Add2_pw3w;
  real32_T rtb_Gain1_cyf2;
  real32_T rtb_state2;
  real32_T rtb_Sum1_hhok;
  int32_T rtb_Switch2_gtgi;
  uint8_T rtb_FixPtSum1_n2em;
  real32_T rtb_lateral_error_history[101];
  real32_T rtb_matrix_b[4];
  real32_T rtb_matrix_a[16];
  real32_T rtb_P[16];
  real32_T rtb_K[4];
  real32_T diff_0[4];
  real32_T AT_0[16];
  real32_T AT_1[16];
  real32_T AT_2[16];
  real32_T AT_3[16];
  real32_T AT_4[16];
  real32_T rtb_state2_tmp;
  boolean_T exitg1;

  /* Outputs for Atomic SubSystem: '<S7>/lateral_control' */
  /* Switch: '<S67>/Switch1' incorporates:
   *  Abs: '<S67>/Abs'
   *  Constant: '<S67>/Constant6'
   *  Constant: '<S68>/Constant'
   *  Logic: '<S67>/Logical Operator1'
   *  RelationalOperator: '<S68>/Compare'
   */
  if ((LCCS_subsystem_integrated_B.VbLCCS_lateral_movement_en_ka3l) &&
      (((real32_T)fabs((real_T)VfLCCS_lateral_dist_to_go)) > 0.01F))
  {
    rtb_Switch1_fdqv = 0.0F;
  }
  else
  {
    rtb_Switch1_fdqv = VfLCCS_lateral_error;
  }

  /* End of Switch: '<S67>/Switch1' */

  /* UnitDelay: '<S67>/Unit Delay1' */
  rtb_UnitDelay1_jw5x = LCCS_subsystem_integrated_DW.UnitDelay1_DSTATE_g04w;

  /* UnitDelay: '<S67>/Unit Delay2' */
  rtb_UnitDelay2_o4fj = LCCS_subsystem_integrated_DW.UnitDelay2_DSTATE_o2ei;

  /* UnitDelay: '<S67>/Unit Delay3' */
  rtb_UnitDelay3_g21h = LCCS_subsystem_integrated_DW.UnitDelay3_DSTATE_p0ty;

  /* UnitDelay: '<S67>/Unit Delay4' */
  rtb_UnitDelay4_by5g = LCCS_subsystem_integrated_DW.UnitDelay4_DSTATE_b3pi;

  /* UnitDelay: '<S67>/Unit Delay6' */
  rtb_UnitDelay6 = LCCS_subsystem_integrated_DW.UnitDelay6_DSTATE;

  /* UnitDelay: '<S67>/Unit Delay7' */
  rtb_UnitDelay7 = LCCS_subsystem_integrated_DW.UnitDelay7_DSTATE;

  /* UnitDelay: '<S67>/Unit Delay8' */
  rtb_UnitDelay8 = LCCS_subsystem_integrated_DW.UnitDelay8_DSTATE;

  /* UnitDelay: '<S67>/Unit Delay9' */
  rtb_UnitDelay9 = LCCS_subsystem_integrated_DW.UnitDelay9_DSTATE;

  /* MATLAB Function: '<S67>/MATLAB Function' incorporates:
   *  Gain: '<S67>/Gain4'
   *  Sum: '<S67>/Add3'
   *  UnitDelay: '<S67>/Unit Delay1'
   *  UnitDelay: '<S67>/Unit Delay10'
   *  UnitDelay: '<S67>/Unit Delay2'
   *  UnitDelay: '<S67>/Unit Delay3'
   *  UnitDelay: '<S67>/Unit Delay4'
   *  UnitDelay: '<S67>/Unit Delay5'
   *  UnitDelay: '<S67>/Unit Delay6'
   *  UnitDelay: '<S67>/Unit Delay7'
   *  UnitDelay: '<S67>/Unit Delay8'
   *  UnitDelay: '<S67>/Unit Delay9'
   *  UnitDelay: '<S69>/Output'
   */
  memset(&rtb_lateral_error_history[0], 0, 101U * (sizeof(real32_T)));
  if (((int32_T)LCCS_subsystem_integrated_DW.Output_DSTATE) == 0)
  {
    rtb_lateral_error_history[0] = 0.1F * (((((((((rtb_Switch1_fdqv +
      LCCS_subsystem_integrated_DW.UnitDelay1_DSTATE_g04w) +
      LCCS_subsystem_integrated_DW.UnitDelay2_DSTATE_o2ei) +
      LCCS_subsystem_integrated_DW.UnitDelay3_DSTATE_p0ty) +
      LCCS_subsystem_integrated_DW.UnitDelay4_DSTATE_b3pi) +
      LCCS_subsystem_integrated_DW.UnitDelay6_DSTATE) +
      LCCS_subsystem_integrated_DW.UnitDelay7_DSTATE) +
      LCCS_subsystem_integrated_DW.UnitDelay8_DSTATE) +
      LCCS_subsystem_integrated_DW.UnitDelay9_DSTATE) +
      LCCS_subsystem_integrated_DW.UnitDelay10_DSTATE);
    memcpy(&rtb_lateral_error_history[1],
           &LCCS_subsystem_integrated_DW.UnitDelay5_DSTATE_fogd[0], 100U *
           (sizeof(real32_T)));
  }
  else
  {
    memcpy(&rtb_lateral_error_history[0],
           &LCCS_subsystem_integrated_DW.UnitDelay5_DSTATE_fogd[0], 101U *
           (sizeof(real32_T)));
  }

  /* End of MATLAB Function: '<S67>/MATLAB Function' */

  /* MATLAB Function: '<S56>/matrixAB' incorporates:
   *  Constant: '<S56>/Constant11'
   *  Constant: '<S56>/Constant16'
   *  Constant: '<S56>/Constant18'
   *  Constant: '<S56>/Constant19'
   *  Constant: '<S56>/Constant20'
   *  Constant: '<S56>/Constant6'
   */
  rtb_matrix_a[1] = 0.0F;
  rtb_Switch2_bhdm = KfLCCS_cf + KfLCCS_cr;
  rtb_matrix_a[5] = (-rtb_Switch2_bhdm) / KfLCCS_mass;
  rtb_matrix_a[9] = rtb_Switch2_bhdm / KfLCCS_mass;
  rtb_Switch2 = KfLCCS_d_lf * KfLCCS_cf;
  rtb_Sum1_hhok = KfLCCS_d_lr * KfLCCS_cr;
  rtb_Switch2_bhdm = rtb_Sum1_hhok - rtb_Switch2;
  rtb_matrix_a[13] = rtb_Switch2_bhdm / KfLCCS_mass;
  rtb_matrix_a[0] = 0.0F;
  rtb_matrix_a[2] = 0.0F;
  rtb_matrix_a[4] = 1.0F;
  rtb_matrix_a[6] = 0.0F;
  rtb_matrix_a[8] = 0.0F;
  rtb_matrix_a[10] = 0.0F;
  rtb_matrix_a[12] = 0.0F;
  rtb_matrix_a[14] = 1.0F;
  rtb_matrix_a[3] = 0.0F;
  rtb_matrix_a[7] = rtb_Switch2_bhdm / KfLCCS_iz;
  rtb_matrix_a[11] = (rtb_Switch2 - rtb_Sum1_hhok) / KfLCCS_iz;
  rtb_matrix_a[15] = (-(((KfLCCS_d_lf * KfLCCS_d_lf) * KfLCCS_cf) +
                        ((KfLCCS_d_lr * KfLCCS_d_lr) * KfLCCS_cr))) / KfLCCS_iz;
  rtb_matrix_b[0] = 0.0F;
  rtb_matrix_b[1] = (0.01F * KfLCCS_cf) / KfLCCS_mass;
  rtb_matrix_b[2] = 0.0F;
  rtb_matrix_b[3] = ((0.01F * KfLCCS_d_lf) * KfLCCS_cf) / KfLCCS_iz;

  /* Switch: '<S63>/Switch2' incorporates:
   *  RelationalOperator: '<S63>/Relational Operator11'
   *  UnitDelay: '<S56>/Unit Delay'
   */
  if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_frui))
  {
    /* Switch: '<S63>/Switch' incorporates:
     *  Constant: '<S63>/Constant'
     *  RelationalOperator: '<S63>/Relational Operator1'
     *  UnitDelay: '<S63>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_pmel))
    {
      rtb_Switch2_bhdm = 5.0F;
    }
    else
    {
      rtb_Switch2_bhdm = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_pmel;
    }

    /* End of Switch: '<S63>/Switch' */
  }
  else
  {
    rtb_Switch2_bhdm = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_frui;
  }

  /* End of Switch: '<S63>/Switch2' */

  /* MinMax: '<S56>/MinMax' incorporates:
   *  Constant: '<S56>/Constant7'
   */
  if ((VfLCCS_linear_velocity > 5.0F) || (rtIsNaNF(5.0F)))
  {
    rtb_Switch_m0yq = VfLCCS_linear_velocity;
  }
  else
  {
    rtb_Switch_m0yq = 5.0F;
  }

  /* End of MinMax: '<S56>/MinMax' */

  /* Switch: '<S64>/Switch2' incorporates:
   *  RelationalOperator: '<S64>/Relational Operator11'
   */
  if (rtIsNaNF(rtb_Switch_m0yq))
  {
    /* Switch: '<S64>/Switch' incorporates:
     *  Constant: '<S64>/Constant'
     *  RelationalOperator: '<S64>/Relational Operator1'
     *  UnitDelay: '<S64>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_k2bi))
    {
      rtb_Switch2 = 5.0F;
    }
    else
    {
      rtb_Switch2 = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_k2bi;
    }

    /* End of Switch: '<S64>/Switch' */
  }
  else
  {
    rtb_Switch2 = rtb_Switch_m0yq;
  }

  /* End of Switch: '<S64>/Switch2' */

  /* Sum: '<S58>/Sum1' incorporates:
   *  Constant: '<S56>/Constant21'
   *  Product: '<S58>/Product'
   *  Sum: '<S58>/Sum'
   */
  rtb_Sum1_hhok = ((rtb_Switch2 - rtb_Switch2_bhdm) * 0.1F) + rtb_Switch2_bhdm;

  /* MATLAB Function: '<S56>/UpdateMatrixA' */
  memcpy(&matrix_a_[0], &rtb_matrix_a[0], (sizeof(real32_T)) << 4U);
  if (((real_T)rtb_Sum1_hhok) > 0.1)
  {
    diff = rtb_Sum1_hhok;
  }
  else
  {
    diff = 0.1F;
  }

  matrix_a_[5] = rtb_matrix_a[5] / diff;
  if (((real_T)rtb_Sum1_hhok) > 0.1)
  {
    diff = rtb_Sum1_hhok;
  }
  else
  {
    diff = 0.1F;
  }

  matrix_a_[13] = rtb_matrix_a[13] / diff;
  if (((real_T)rtb_Sum1_hhok) > 0.1)
  {
    diff = rtb_Sum1_hhok;
  }
  else
  {
    diff = 0.1F;
  }

  matrix_a_[7] = rtb_matrix_a[7] / diff;
  if (((real_T)rtb_Sum1_hhok) > 0.1)
  {
    diff = rtb_Sum1_hhok;
  }
  else
  {
    diff = 0.1F;
  }

  matrix_a_[15] = rtb_matrix_a[15] / diff;
  for (rtb_Add2_pw3w = 0; rtb_Add2_pw3w < 16; rtb_Add2_pw3w++)
  {
    rtb_matrix_a[rtb_Add2_pw3w] = ((real32_T)b[rtb_Add2_pw3w]) + (0.005F *
      matrix_a_[rtb_Add2_pw3w]);
    AT[rtb_Add2_pw3w] = ((real32_T)b[rtb_Add2_pw3w]) - (0.005F *
      matrix_a_[rtb_Add2_pw3w]);
  }

  mrdivide_9C9aPutf(rtb_matrix_a, AT);

  /* End of MATLAB Function: '<S56>/UpdateMatrixA' */

  /* MATLAB Function: '<S56>/UpdateMatrixQ' incorporates:
   *  Lookup_n-D: '<S56>/KtLCCS_heading_err_gain_scheduler'
   *  Lookup_n-D: '<S56>/KtLCCS_heading_err_rate_gain_scheduler'
   *  Lookup_n-D: '<S56>/KtLCCS_lateral_err_gain_scheduler'
   *  Lookup_n-D: '<S56>/KtLCCS_lateral_err_rate_gain_scheduler'
   */
  memset(&matrix_a_[0], 0, (sizeof(real32_T)) << 4U);
  matrix_a_[0] = look1_iflf_binlca(rtb_Sum1_hhok, KtLCCS_AXIS_vehicle_speed,
    KtLCCS_lateral_err_gain_scheduler, 20U);
  matrix_a_[5] = look1_iflf_binlca(rtb_Sum1_hhok, KtLCCS_AXIS_vehicle_speed,
    KtLCCS_lateral_err_rate_gain_scheduler, 20U);
  matrix_a_[10] = look1_iflf_binlca(rtb_Sum1_hhok, KtLCCS_AXIS_vehicle_speed,
    KtLCCS_heading_err_gain_scheduler, 20U);
  matrix_a_[15] = look1_iflf_binlca(rtb_Sum1_hhok, KtLCCS_AXIS_vehicle_speed,
    KtLCCS_heading_err_rate_gain_scheduler, 20U);

  /* MATLAB Function: '<S56>/linear_quadratic_regulator' incorporates:
   *  Constant: '<S56>/Constant1'
   *  Constant: '<S56>/Constant3'
   *  Constant: '<S56>/Constant5'
   *  UnitDelay: '<S56>/UnitDelay2'
   */
  for (rtb_Add2_pw3w = 0; rtb_Add2_pw3w < 4; rtb_Add2_pw3w++)
  {
    AT[rtb_Add2_pw3w * 4] = rtb_matrix_a[rtb_Add2_pw3w];
    AT[1 + (rtb_Add2_pw3w * 4)] = rtb_matrix_a[rtb_Add2_pw3w + 4];
    AT[2 + (rtb_Add2_pw3w * 4)] = rtb_matrix_a[rtb_Add2_pw3w + 8];
    AT[3 + (rtb_Add2_pw3w * 4)] = rtb_matrix_a[rtb_Add2_pw3w + 12];
  }

  memcpy(&rtb_P[0], &LCCS_subsystem_integrated_DW.UnitDelay2_DSTATE_ljaq[0],
         (sizeof(real32_T)) << 4U);
  rtb_FixPtSum1_n2em = 0U;
  diff = 1.0E+6F;
  while ((((real32_T)rtb_FixPtSum1_n2em) < 30.0F) && (diff > KfLCCS_eps))
  {
    diff = (((0.0F * rtb_P[0]) + (rtb_matrix_b[1] * rtb_P[1])) + (0.0F * rtb_P[2]))
      + (rtb_matrix_b[3] * rtb_P[3]);
    sum_lateral_error = diff * rtb_matrix_b[0];
    for (rtb_Add2_pw3w = 0; rtb_Add2_pw3w < 3; rtb_Add2_pw3w++)
    {
      diff = (((0.0F * rtb_P[(rtb_Add2_pw3w + 1) * 4]) + (rtb_matrix_b[1] *
                rtb_P[1 + ((rtb_Add2_pw3w + 1) * 4)])) + (0.0F * rtb_P[2 +
               ((rtb_Add2_pw3w + 1) * 4)])) + (rtb_matrix_b[3] * rtb_P[3 +
        ((rtb_Add2_pw3w + 1) * 4)]);
      sum_lateral_error += diff * rtb_matrix_b[rtb_Add2_pw3w + 1];
    }

    diff = KfLCCS_WeightMatrixStates_R + sum_lateral_error;
    for (rtb_Add2_pw3w = 0; rtb_Add2_pw3w < 4; rtb_Add2_pw3w++)
    {
      sum_lateral_error = 0.0F;
      for (rtb_Switch2_gtgi = 0; rtb_Switch2_gtgi < 4; rtb_Switch2_gtgi++)
      {
        P_next[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] = 0.0F;
        AT_0[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] = 0.0F;
        P_next[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] += AT[rtb_Add2_pw3w] *
          rtb_P[rtb_Switch2_gtgi * 4];
        AT_0[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] += AT[rtb_Add2_pw3w] *
          rtb_P[rtb_Switch2_gtgi * 4];
        P_next[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] += AT[rtb_Add2_pw3w + 4] *
          rtb_P[1 + (rtb_Switch2_gtgi * 4)];
        AT_0[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] += AT[rtb_Add2_pw3w + 4] *
          rtb_P[1 + (rtb_Switch2_gtgi * 4)];
        P_next[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] += AT[rtb_Add2_pw3w + 8] *
          rtb_P[2 + (rtb_Switch2_gtgi * 4)];
        AT_0[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] += AT[rtb_Add2_pw3w + 8] *
          rtb_P[2 + (rtb_Switch2_gtgi * 4)];
        P_next[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] += AT[rtb_Add2_pw3w + 12]
          * rtb_P[3 + (rtb_Switch2_gtgi * 4)];
        AT_0[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] += AT[rtb_Add2_pw3w + 12] *
          rtb_P[3 + (rtb_Switch2_gtgi * 4)];
        sum_lateral_error += AT_0[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] *
          rtb_matrix_b[rtb_Switch2_gtgi];
      }

      rtb_Product2 = sum_lateral_error / diff;
      AT_1[rtb_Add2_pw3w] = rtb_Product2 * 0.0F;
      AT_1[rtb_Add2_pw3w + 4] = rtb_Product2 * rtb_matrix_b[1];
      AT_1[rtb_Add2_pw3w + 8] = rtb_Product2 * 0.0F;
      AT_1[rtb_Add2_pw3w + 12] = rtb_Product2 * rtb_matrix_b[3];
      for (rtb_Switch2_gtgi = 0; rtb_Switch2_gtgi < 4; rtb_Switch2_gtgi++)
      {
        AT_2[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] = 0.0F;
        AT_3[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] = 0.0F;
        AT_2[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] += AT_1[rtb_Add2_pw3w] *
          rtb_P[rtb_Switch2_gtgi * 4];
        AT_3[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] += P_next[rtb_Add2_pw3w] *
          rtb_matrix_a[rtb_Switch2_gtgi * 4];
        AT_2[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] += AT_1[rtb_Add2_pw3w + 4] *
          rtb_P[1 + (rtb_Switch2_gtgi * 4)];
        AT_3[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] += P_next[rtb_Add2_pw3w + 4]
          * rtb_matrix_a[1 + (rtb_Switch2_gtgi * 4)];
        AT_2[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] += AT_1[rtb_Add2_pw3w + 8] *
          rtb_P[2 + (rtb_Switch2_gtgi * 4)];
        AT_3[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] += P_next[rtb_Add2_pw3w + 8]
          * rtb_matrix_a[2 + (rtb_Switch2_gtgi * 4)];
        AT_2[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] += AT_1[rtb_Add2_pw3w + 12]
          * rtb_P[3 + (rtb_Switch2_gtgi * 4)];
        AT_3[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] += P_next[rtb_Add2_pw3w +
          12] * rtb_matrix_a[3 + (rtb_Switch2_gtgi * 4)];
      }

      for (rtb_Switch2_gtgi = 0; rtb_Switch2_gtgi < 4; rtb_Switch2_gtgi++)
      {
        AT_4[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] = 0.0F;
        AT_4[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] += AT_2[rtb_Add2_pw3w] *
          rtb_matrix_a[rtb_Switch2_gtgi * 4];
        AT_4[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] += AT_2[rtb_Add2_pw3w + 4] *
          rtb_matrix_a[1 + (rtb_Switch2_gtgi * 4)];
        AT_4[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] += AT_2[rtb_Add2_pw3w + 8] *
          rtb_matrix_a[2 + (rtb_Switch2_gtgi * 4)];
        AT_4[rtb_Add2_pw3w + (rtb_Switch2_gtgi * 4)] += AT_2[rtb_Add2_pw3w + 12]
          * rtb_matrix_a[3 + (rtb_Switch2_gtgi * 4)];
      }
    }

    for (rtb_Add2_pw3w = 0; rtb_Add2_pw3w < 4; rtb_Add2_pw3w++)
    {
      P_next[rtb_Add2_pw3w * 4] = (AT_3[rtb_Add2_pw3w * 4] - AT_4[rtb_Add2_pw3w *
        4]) + matrix_a_[rtb_Add2_pw3w * 4];
      P_next[1 + (rtb_Add2_pw3w * 4)] = (AT_3[1 + (rtb_Add2_pw3w * 4)] - AT_4[1
        + (rtb_Add2_pw3w * 4)]) + matrix_a_[1 + (rtb_Add2_pw3w * 4)];
      P_next[2 + (rtb_Add2_pw3w * 4)] = (AT_3[2 + (rtb_Add2_pw3w * 4)] - AT_4[2
        + (rtb_Add2_pw3w * 4)]) + matrix_a_[2 + (rtb_Add2_pw3w * 4)];
      P_next[3 + (rtb_Add2_pw3w * 4)] = (AT_3[3 + (rtb_Add2_pw3w * 4)] - AT_4[3
        + (rtb_Add2_pw3w * 4)]) + matrix_a_[3 + (rtb_Add2_pw3w * 4)];
    }

    for (rtb_Add2_pw3w = 0; rtb_Add2_pw3w < 16; rtb_Add2_pw3w++)
    {
      AT_3[rtb_Add2_pw3w] = (real32_T)fabs((real_T)((real32_T)
        (P_next[rtb_Add2_pw3w] - rtb_P[rtb_Add2_pw3w])));
    }

    rtb_Add2_pw3w = 1;
    diff = AT_3[0];
    if (rtIsNaNF(AT_3[0]))
    {
      rtb_Switch2_gtgi = 1;
      exitg1 = false;
      while ((!exitg1) && ((rtb_Switch2_gtgi + 1) <= 4))
      {
        rtb_Add2_pw3w = rtb_Switch2_gtgi + 1;
        if (!rtIsNaNF(AT_3[rtb_Switch2_gtgi]))
        {
          diff = AT_3[rtb_Switch2_gtgi];
          exitg1 = true;
        }
        else
        {
          rtb_Switch2_gtgi++;
        }
      }
    }

    if (rtb_Add2_pw3w < 4)
    {
      while ((rtb_Add2_pw3w + 1) <= 4)
      {
        if (AT_3[rtb_Add2_pw3w] > diff)
        {
          diff = AT_3[rtb_Add2_pw3w];
        }

        rtb_Add2_pw3w++;
      }
    }

    rtb_K[0] = diff;
    rtb_Add2_pw3w = 5;
    diff = AT_3[4];
    if (rtIsNaNF(AT_3[4]))
    {
      rtb_Switch2_gtgi = 5;
      exitg1 = false;
      while ((!exitg1) && ((rtb_Switch2_gtgi + 1) <= 8))
      {
        rtb_Add2_pw3w = rtb_Switch2_gtgi + 1;
        if (!rtIsNaNF(AT_3[rtb_Switch2_gtgi]))
        {
          diff = AT_3[rtb_Switch2_gtgi];
          exitg1 = true;
        }
        else
        {
          rtb_Switch2_gtgi++;
        }
      }
    }

    if (rtb_Add2_pw3w < 8)
    {
      while ((rtb_Add2_pw3w + 1) <= 8)
      {
        if (AT_3[rtb_Add2_pw3w] > diff)
        {
          diff = AT_3[rtb_Add2_pw3w];
        }

        rtb_Add2_pw3w++;
      }
    }

    rtb_K[1] = diff;
    rtb_Add2_pw3w = 9;
    diff = AT_3[8];
    if (rtIsNaNF(AT_3[8]))
    {
      rtb_Switch2_gtgi = 9;
      exitg1 = false;
      while ((!exitg1) && ((rtb_Switch2_gtgi + 1) <= 12))
      {
        rtb_Add2_pw3w = rtb_Switch2_gtgi + 1;
        if (!rtIsNaNF(AT_3[rtb_Switch2_gtgi]))
        {
          diff = AT_3[rtb_Switch2_gtgi];
          exitg1 = true;
        }
        else
        {
          rtb_Switch2_gtgi++;
        }
      }
    }

    if (rtb_Add2_pw3w < 12)
    {
      while ((rtb_Add2_pw3w + 1) <= 12)
      {
        if (AT_3[rtb_Add2_pw3w] > diff)
        {
          diff = AT_3[rtb_Add2_pw3w];
        }

        rtb_Add2_pw3w++;
      }
    }

    rtb_K[2] = diff;
    rtb_Add2_pw3w = 13;
    diff = AT_3[12];
    if (rtIsNaNF(AT_3[12]))
    {
      rtb_Switch2_gtgi = 13;
      exitg1 = false;
      while ((!exitg1) && ((rtb_Switch2_gtgi + 1) <= 16))
      {
        rtb_Add2_pw3w = rtb_Switch2_gtgi + 1;
        if (!rtIsNaNF(AT_3[rtb_Switch2_gtgi]))
        {
          diff = AT_3[rtb_Switch2_gtgi];
          exitg1 = true;
        }
        else
        {
          rtb_Switch2_gtgi++;
        }
      }
    }

    if (rtb_Add2_pw3w < 16)
    {
      while ((rtb_Add2_pw3w + 1) <= 16)
      {
        if (AT_3[rtb_Add2_pw3w] > diff)
        {
          diff = AT_3[rtb_Add2_pw3w];
        }

        rtb_Add2_pw3w++;
      }
    }

    rtb_K[3] = diff;
    rtb_Add2_pw3w = 1;
    diff = rtb_K[0];
    if (rtIsNaNF(rtb_K[0]))
    {
      rtb_Switch2_gtgi = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_Switch2_gtgi < 5))
      {
        rtb_Add2_pw3w = rtb_Switch2_gtgi;
        if (!rtIsNaNF(rtb_K[rtb_Switch2_gtgi - 1]))
        {
          diff = rtb_K[rtb_Switch2_gtgi - 1];
          exitg1 = true;
        }
        else
        {
          rtb_Switch2_gtgi++;
        }
      }
    }

    if (rtb_Add2_pw3w < 4)
    {
      while ((rtb_Add2_pw3w + 1) < 5)
      {
        if (rtb_K[rtb_Add2_pw3w] > diff)
        {
          diff = rtb_K[rtb_Add2_pw3w];
        }

        rtb_Add2_pw3w++;
      }
    }

    memcpy(&rtb_P[0], &P_next[0], (sizeof(real32_T)) << 4U);
    rtb_Add2_pw3w = (int32_T)((uint32_T)(((uint32_T)rtb_FixPtSum1_n2em) + 1U));
    if (((uint32_T)rtb_Add2_pw3w) > 255U)
    {
      rtb_Add2_pw3w = 255;
    }

    rtb_FixPtSum1_n2em = (uint8_T)rtb_Add2_pw3w;
  }

  diff = (((0.0F * rtb_P[0]) + (rtb_matrix_b[1] * rtb_P[1])) + (0.0F * rtb_P[2]))
    + (rtb_matrix_b[3] * rtb_P[3]);
  sum_lateral_error = diff * rtb_matrix_b[0];
  for (rtb_Add2_pw3w = 0; rtb_Add2_pw3w < 3; rtb_Add2_pw3w++)
  {
    diff = (((0.0F * rtb_P[(rtb_Add2_pw3w + 1) * 4]) + (rtb_matrix_b[1] * rtb_P
              [1 + ((rtb_Add2_pw3w + 1) * 4)])) + (0.0F * rtb_P[2 +
             ((rtb_Add2_pw3w + 1) * 4)])) + (rtb_matrix_b[3] * rtb_P[3 +
      ((rtb_Add2_pw3w + 1) * 4)]);
    sum_lateral_error += diff * rtb_matrix_b[rtb_Add2_pw3w + 1];
  }

  diff = 1.0F / (KfLCCS_WeightMatrixStates_R + sum_lateral_error);
  for (rtb_Add2_pw3w = 0; rtb_Add2_pw3w < 4; rtb_Add2_pw3w++)
  {
    rtb_Product2 = ((((diff * 0.0F) * rtb_P[rtb_Add2_pw3w * 4]) + ((diff *
      rtb_matrix_b[1]) * rtb_P[1 + (rtb_Add2_pw3w * 4)])) + ((diff * 0.0F) *
      rtb_P[2 + (rtb_Add2_pw3w * 4)])) + ((diff * rtb_matrix_b[3]) * rtb_P[3 +
      (rtb_Add2_pw3w * 4)]);
    diff_0[rtb_Add2_pw3w] = rtb_Product2;
  }

  for (rtb_Add2_pw3w = 0; rtb_Add2_pw3w < 4; rtb_Add2_pw3w++)
  {
    diff = (((diff_0[0] * rtb_matrix_a[rtb_Add2_pw3w * 4]) + (diff_0[1] *
              rtb_matrix_a[1 + (rtb_Add2_pw3w * 4)])) + (diff_0[2] *
             rtb_matrix_a[2 + (rtb_Add2_pw3w * 4)])) + (diff_0[3] *
      rtb_matrix_a[3 + (rtb_Add2_pw3w * 4)]);
    rtb_K[rtb_Add2_pw3w] = diff;
  }

  VcLCCS_num_iteration = rtb_FixPtSum1_n2em;

  /* End of MATLAB Function: '<S56>/linear_quadratic_regulator' */

  /* Gain: '<S56>/Gain2' incorporates:
   *  Gain: '<S56>/Gain1'
   *  Product: '<S56>/steer_angle_feedback'
   */
  rtb_state2 = (-1.0F) * rtb_K[0];
  rtb_matrix_b[0] = rtb_state2;
  sum_lateral_error = (-1.0F) * rtb_K[1];
  rtb_matrix_b[1] = sum_lateral_error;
  rtb_Gain1_cyf2 = (-1.0F) * rtb_K[2];
  rtb_matrix_b[2] = rtb_Gain1_cyf2;
  rtb_KtLCCS_slowpath_steer_I_gai = (-1.0F) * rtb_K[3];
  rtb_matrix_b[3] = rtb_KtLCCS_slowpath_steer_I_gai;

  /* Product: '<S56>/Product3' incorporates:
   *  Lookup_n-D: '<S56>/KtLCCS_lateral_err_correction'
   */
  diff = VfLCCS_lateral_error * look1_iflf_binlca(rtb_Sum1_hhok,
    KtLCCS_AXIS_vehicle_speed, KtLCCS_lateral_err_correction, 20U);

  /* Product: '<S56>/Product2' incorporates:
   *  Lookup_n-D: '<S56>/KtLCCS_lateral_err_rate_correction'
   */
  rtb_Product2 = VfLCCS_lateral_error_rate * look1_iflf_binlca(rtb_Sum1_hhok,
    KtLCCS_AXIS_vehicle_speed, KtLCCS_lateral_err_rate_correction, 20U);

  /* Product: '<S56>/Product' incorporates:
   *  Abs: '<S56>/Abs'
   *  Lookup_n-D: '<S56>/KtLCCS_heading_err_correction'
   */
  rtb_Product_gbzh = VfLCCS_heading_error * look1_iflf_binlca((real32_T)fabs
    ((real_T)VfLCCS_heading_error), KtLCCS_AXIS_heading_error,
    KtLCCS_heading_err_correction, 20U);

  /* Product: '<S56>/Product1' incorporates:
   *  Lookup_n-D: '<S56>/KtLCCS_heading_err_rate_correction'
   */
  rtb_Product1_ngl4 = VfLCCS_heading_error_rate * look1_iflf_binlca
    (rtb_Sum1_hhok, KtLCCS_AXIS_vehicle_speed,
     KtLCCS_heading_err_rate_correction, 20U);

  /* Product: '<S56>/steer_angle_feedback' incorporates:
   *  Reshape: '<S56>/Reshape'
   */
  VfLCCS_steer_angle_feedback = (((rtb_state2 * diff) + (sum_lateral_error *
    rtb_Product2)) + (rtb_Gain1_cyf2 * rtb_Product_gbzh)) +
    (rtb_KtLCCS_slowpath_steer_I_gai * rtb_Product1_ngl4);

  /* Switch: '<S56>/steer_angle_feedforward' incorporates:
   *  Constant: '<S56>/Constant12'
   *  Constant: '<S56>/gps_trace_x2'
   *  Constant: '<S59>/Constant'
   *  Constant: '<S59>/Constant1'
   *  Constant: '<S59>/Constant10'
   *  Constant: '<S59>/Constant11'
   *  Constant: '<S59>/Constant14'
   *  Constant: '<S59>/Constant15'
   *  Constant: '<S59>/Constant16'
   *  Constant: '<S59>/Constant17'
   *  Constant: '<S59>/Constant2'
   *  Constant: '<S59>/Constant3'
   *  Constant: '<S59>/Constant4'
   *  Constant: '<S59>/Constant7'
   *  Constant: '<S59>/Constant8'
   *  Constant: '<S59>/Constant9'
   *  Math: '<S59>/Math Function'
   *  MultiPortSwitch: '<S59>/Index Vector'
   *  Product: '<S59>/Product10'
   *  Product: '<S59>/Product4'
   *  Product: '<S59>/Product5'
   *  Product: '<S59>/Product6'
   *  Product: '<S59>/Product7'
   *  Product: '<S59>/Product8'
   *  Product: '<S59>/Product9'
   *  Sum: '<S59>/Add'
   *  Sum: '<S59>/Add1'
   *  Sum: '<S59>/Add3'
   */
  if (KbLCCS_UsePurePursuit)
  {
    VfLCCS_steer_angle_feedforward = 0.0F;
  }
  else
  {
    /* Product: '<S59>/Product5' incorporates:
     *  Constant: '<S59>/Constant5'
     *  Constant: '<S59>/Constant6'
     *  Product: '<S59>/Product8'
     */
    rtb_state2 = KfLCCS_d_lf * KfLCCS_mass;

    /* Math: '<S59>/Math Function' incorporates:
     *  Math: '<S59>/Math Function1'
     */
    sum_lateral_error = rtb_Sum1_hhok * rtb_Sum1_hhok;
    VfLCCS_steer_angle_feedforward = ((KfLCCS_d_wheel_base *
      VfLCCS_preview_curvature) + (((((((KfLCCS_d_lr * KfLCCS_mass) / 2.0F) /
      KfLCCS_cf) / KfLCCS_d_wheel_base) - (((rtb_state2 / 2.0F) / KfLCCS_cr) /
      KfLCCS_d_wheel_base)) * sum_lateral_error) * VfLCCS_preview_curvature)) -
      (((KfLCCS_d_lr * VfLCCS_preview_curvature) - (((((rtb_state2 *
             sum_lateral_error) * VfLCCS_preview_curvature) / 2.0F) / KfLCCS_cr)
         / KfLCCS_d_wheel_base)) * rtb_K[((int32_T)3.0F) - 1]);
  }

  /* End of Switch: '<S56>/steer_angle_feedforward' */

  /* Gain: '<S67>/Gain2' incorporates:
   *  Constant: '<S56>/Constant4'
   *  Gain: '<S67>/Gain5'
   */
  rtb_state2 = 2.0F * KfLCCS_Ang_slowpath_steer_limit;

  /* MinMax: '<S67>/MinMax4' incorporates:
   *  Constant: '<S67>/Constant10'
   *  Constant: '<S67>/Constant11'
   */
  if ((KfLCCS_t_SampleTime > 0.01F) || (rtIsNaNF(0.01F)))
  {
    sum_lateral_error = KfLCCS_t_SampleTime;
  }
  else
  {
    sum_lateral_error = 0.01F;
  }

  /* End of MinMax: '<S67>/MinMax4' */

  /* Sum: '<S67>/Add2' incorporates:
   *  Constant: '<S67>/Constant2'
   *  Constant: '<S67>/Constant5'
   *  Lookup_n-D: '<S56>/KtLCCS_t_lateral_oscillation_period'
   *  Product: '<S67>/Divide2'
   */
  rtb_Add2_pw3w = (int32_T)((real32_T)floor((real_T)((real32_T)(((real32_T)1) +
    ((look1_iflf_binlca(rtb_Sum1_hhok, KtLCCS_AXIS_vehicle_speed,
                        KtLCCS_t_lateral_oscillation_period, 20U) /
      sum_lateral_error) * 0.1F)))));

  /* Switch: '<S75>/Switch2' incorporates:
   *  Constant: '<S67>/Constant3'
   *  Constant: '<S67>/Constant4'
   *  RelationalOperator: '<S75>/LowerRelop1'
   *  RelationalOperator: '<S75>/UpperRelop'
   *  Switch: '<S75>/Switch'
   */
  if (rtb_Add2_pw3w > 101)
  {
    rtb_Switch2_gtgi = 101;
  }
  else if (rtb_Add2_pw3w < 1)
  {
    /* Switch: '<S75>/Switch' incorporates:
     *  Constant: '<S67>/Constant4'
     */
    rtb_Switch2_gtgi = 1;
  }
  else
  {
    rtb_Switch2_gtgi = rtb_Add2_pw3w;
  }

  /* End of Switch: '<S75>/Switch2' */

  /* MATLAB Function: '<S67>/MATLAB Function1' */
  sum_lateral_error = 0.0F;
  for (rtb_Add2_pw3w = 1; rtb_Add2_pw3w <= rtb_Switch2_gtgi; rtb_Add2_pw3w++)
  {
    sum_lateral_error += rtb_lateral_error_history[rtb_Add2_pw3w - 1];
  }

  if (rtb_Switch2_gtgi < -2147483647)
  {
    rtb_Add2_pw3w = MIN_int32_T;
  }
  else
  {
    rtb_Add2_pw3w = rtb_Switch2_gtgi - 1;
  }

  if (1 > rtb_Add2_pw3w)
  {
    rtb_Add2_pw3w = 1;
  }

  /* Gain: '<S67>/Gain1' incorporates:
   *  MATLAB Function: '<S67>/MATLAB Function1'
   */
  rtb_Gain1_cyf2 = (-1.0F) * (sum_lateral_error / ((real32_T)rtb_Add2_pw3w));

  /* Lookup_n-D: '<S56>/KtLCCS_slowpath_steer_P_gain' */
  rtb_KtLCCS_slowpath_steer_I_gai = look1_iflf_binlca(rtb_Sum1_hhok,
    KtLCCS_AXIS_vehicle_speed, KtLCCS_slowpath_steer_P_gain, 20U);

  /* Product: '<S67>/Product' */
  rtb_Switch_m0yq = rtb_Gain1_cyf2 * rtb_KtLCCS_slowpath_steer_I_gai;

  /* Gain: '<S67>/Gain' incorporates:
   *  Constant: '<S56>/Constant4'
   */
  sum_lateral_error = (-1.0F) * KfLCCS_Ang_slowpath_steer_limit;

  /* Gain: '<S67>/Gain3' incorporates:
   *  Gain: '<S67>/Gain6'
   */
  rtb_state2_tmp = 2.0F * sum_lateral_error;

  /* Switch: '<S73>/Switch2' incorporates:
   *  Gain: '<S67>/Gain2'
   *  Gain: '<S67>/Gain3'
   *  RelationalOperator: '<S73>/LowerRelop1'
   *  RelationalOperator: '<S73>/UpperRelop'
   *  Switch: '<S73>/Switch'
   */
  if (rtb_Switch_m0yq > rtb_state2)
  {
    VfLCCS_slowpath_steer_P = rtb_state2;
  }
  else if (rtb_Switch_m0yq < rtb_state2_tmp)
  {
    /* Switch: '<S73>/Switch' incorporates:
     *  Gain: '<S67>/Gain3'
     */
    VfLCCS_slowpath_steer_P = rtb_state2_tmp;
  }
  else
  {
    VfLCCS_slowpath_steer_P = rtb_Switch_m0yq;
  }

  /* End of Switch: '<S73>/Switch2' */

  /* Switch: '<S70>/Switch' incorporates:
   *  Constant: '<S67>/Constant7'
   *  RelationalOperator: '<S70>/u_GTE_up'
   */
  if (rtb_Gain1_cyf2 >= KfLCCS_d_LateralErrorDeadBand)
  {
    rtb_Switch_m0yq = KfLCCS_d_LateralErrorDeadBand;
  }
  else
  {
    /* Gain: '<S67>/Gain7' incorporates:
     *  Constant: '<S67>/Constant8'
     */
    rtb_Switch_m0yq = (-1.0F) * KfLCCS_d_LateralErrorDeadBand;

    /* Switch: '<S70>/Switch1' incorporates:
     *  RelationalOperator: '<S70>/u_GT_lo'
     */
    if (rtb_Gain1_cyf2 > rtb_Switch_m0yq)
    {
      rtb_Switch_m0yq = rtb_Gain1_cyf2;
    }

    /* End of Switch: '<S70>/Switch1' */
  }

  /* End of Switch: '<S70>/Switch' */

  /* Product: '<S67>/Product2' incorporates:
   *  Sum: '<S70>/Diff'
   */
  rtb_Switch_m0yq = rtb_KtLCCS_slowpath_steer_I_gai * (rtb_Gain1_cyf2 -
    rtb_Switch_m0yq);

  /* Switch: '<S67>/Switch' incorporates:
   *  Constant: '<S67>/Constant'
   */
  if (LCCS_subsystem_integrated_B.VbLCCS_steering_control_st_jgz4)
  {
    /* Switch: '<S76>/Switch2' incorporates:
     *  RelationalOperator: '<S76>/LowerRelop1'
     *  RelationalOperator: '<S76>/UpperRelop'
     *  Switch: '<S76>/Switch'
     */
    if (rtb_Switch_m0yq > rtb_state2)
    {
      rtb_Switch_m0yq = rtb_state2;
    }
    else
    {
      if (rtb_Switch_m0yq < rtb_state2_tmp)
      {
        /* Switch: '<S76>/Switch' */
        rtb_Switch_m0yq = rtb_state2_tmp;
      }
    }

    /* End of Switch: '<S76>/Switch2' */
  }
  else
  {
    rtb_Switch_m0yq = 0.0F;
  }

  /* End of Switch: '<S67>/Switch' */

  /* Sum: '<S67>/Add' incorporates:
   *  Constant: '<S67>/Constant1'
   *  Lookup_n-D: '<S56>/KtLCCS_slowpath_steer_I_gain'
   *  Product: '<S67>/Product1'
   *  UnitDelay: '<S67>/Unit Delay'
   */
  rtb_state2 = ((KfLCCS_t_SampleTime * rtb_Switch_m0yq) * look1_iflf_binlca
                (rtb_Sum1_hhok, KtLCCS_AXIS_vehicle_speed,
                 KtLCCS_slowpath_steer_I_gain, 20U)) + VfLCCS_slowpath_steer_I;

  /* Switch: '<S74>/Switch2' incorporates:
   *  Constant: '<S56>/Constant4'
   *  RelationalOperator: '<S74>/LowerRelop1'
   *  RelationalOperator: '<S74>/UpperRelop'
   *  Switch: '<S74>/Switch'
   */
  if (rtb_state2 > KfLCCS_Ang_slowpath_steer_limit)
  {
    VfLCCS_slowpath_steer_I = KfLCCS_Ang_slowpath_steer_limit;
  }
  else if (rtb_state2 < sum_lateral_error)
  {
    /* Switch: '<S74>/Switch' */
    VfLCCS_slowpath_steer_I = sum_lateral_error;
  }
  else
  {
    VfLCCS_slowpath_steer_I = rtb_state2;
  }

  /* End of Switch: '<S74>/Switch2' */

  /* Sum: '<S67>/Add1' */
  VfLCCS_slowpath_steer_PI = VfLCCS_slowpath_steer_P + VfLCCS_slowpath_steer_I;

  /* Sum: '<S56>/Add' */
  sum_lateral_error = (VfLCCS_steer_angle_feedforward +
                       VfLCCS_steer_angle_feedback) + VfLCCS_slowpath_steer_PI;

  /* Trigonometry: '<S56>/Atan2' incorporates:
   *  Constant: '<S56>/gps_trace_x1'
   *  Constant: '<S56>/gps_trace_x3'
   *  Math: '<S56>/Math Function'
   *  Product: '<S56>/Product6'
   */
  VfLCCS_frtwhl_angle_limit_lat_acc = (real32_T)atan((real_T)((real32_T)
    ((KfLCCS_a_max_lat_acc * KfLCCS_d_min_turn_radius) / (rtb_Sum1_hhok *
    rtb_Sum1_hhok))));

  /* Gain: '<S56>/Gain' */
  rtb_state2 = (-1.0F) * VfLCCS_frtwhl_angle_limit_lat_acc;

  /* Switch: '<S60>/Switch2' incorporates:
   *  RelationalOperator: '<S60>/LowerRelop1'
   *  RelationalOperator: '<S60>/UpperRelop'
   *  Switch: '<S60>/Switch'
   */
  if (sum_lateral_error > VfLCCS_frtwhl_angle_limit_lat_acc)
  {
    VfLCCS_veh_frtwhl_angle_des = VfLCCS_frtwhl_angle_limit_lat_acc;
  }
  else if (sum_lateral_error < rtb_state2)
  {
    /* Switch: '<S60>/Switch' */
    VfLCCS_veh_frtwhl_angle_des = rtb_state2;
  }
  else
  {
    VfLCCS_veh_frtwhl_angle_des = sum_lateral_error;
  }

  /* End of Switch: '<S60>/Switch2' */

  /* MultiPortSwitch: '<S56>/state3' incorporates:
   *  Constant: '<S56>/Constant23'
   */
  switch (3)
  {
   case 1:
    rtb_state2 = diff;
    break;

   case 2:
    rtb_state2 = rtb_Product2;
    break;

   case 3:
    rtb_state2 = rtb_Product_gbzh;
    break;

   case 4:
    rtb_state2 = rtb_Product1_ngl4;
    break;

   default:
    /* no actions */
    break;
  }

  /* End of MultiPortSwitch: '<S56>/state3' */

  /* Product: '<S56>/heading_error_contribution' incorporates:
   *  Constant: '<S56>/Constant8'
   *  MultiPortSwitch: '<S56>/K3'
   */
  VfLCCS_heading_error_contribution = rtb_matrix_b[3 - 1] * rtb_state2;

  /* MultiPortSwitch: '<S56>/state4' incorporates:
   *  Constant: '<S56>/Constant24'
   */
  switch (4)
  {
   case 1:
    rtb_state2 = diff;
    break;

   case 2:
    rtb_state2 = rtb_Product2;
    break;

   case 3:
    rtb_state2 = rtb_Product_gbzh;
    break;

   case 4:
    rtb_state2 = rtb_Product1_ngl4;
    break;

   default:
    /* no actions */
    break;
  }

  /* End of MultiPortSwitch: '<S56>/state4' */

  /* Product: '<S56>/heading_error_rate_contribution' incorporates:
   *  Constant: '<S56>/Constant9'
   *  MultiPortSwitch: '<S56>/K4'
   */
  VfLCCS_heading_error_rate_contribution = rtb_matrix_b[4 - 1] * rtb_state2;

  /* MultiPortSwitch: '<S56>/state1' incorporates:
   *  Constant: '<S56>/Constant2'
   */
  switch (1)
  {
   case 1:
    rtb_state2 = diff;
    break;

   case 2:
    rtb_state2 = rtb_Product2;
    break;

   case 3:
    rtb_state2 = rtb_Product_gbzh;
    break;

   case 4:
    rtb_state2 = rtb_Product1_ngl4;
    break;

   default:
    /* no actions */
    break;
  }

  /* End of MultiPortSwitch: '<S56>/state1' */

  /* Product: '<S56>/lateral_error_contribution' incorporates:
   *  Constant: '<S56>/Constant17'
   *  MultiPortSwitch: '<S56>/K1'
   */
  VfLCCS_lateral_error_contribution = rtb_matrix_b[1 - 1] * rtb_state2;

  /* MultiPortSwitch: '<S56>/state2' incorporates:
   *  Constant: '<S56>/Constant22'
   */
  switch (2)
  {
   case 1:
    rtb_state2 = diff;
    break;

   case 2:
    rtb_state2 = rtb_Product2;
    break;

   case 3:
    rtb_state2 = rtb_Product_gbzh;
    break;

   case 4:
    rtb_state2 = rtb_Product1_ngl4;
    break;

   default:
    /* no actions */
    break;
  }

  /* End of MultiPortSwitch: '<S56>/state2' */

  /* Product: '<S56>/lateral_error_rate_contribution' incorporates:
   *  Constant: '<S56>/Constant10'
   *  MultiPortSwitch: '<S56>/K2'
   */
  VfLCCS_lateral_error_rate_contribution = rtb_matrix_b[2 - 1] * rtb_state2;

  /* Sum: '<S77>/FixPt Sum1' incorporates:
   *  Constant: '<S77>/FixPt Constant'
   *  UnitDelay: '<S69>/Output'
   */
  rtb_FixPtSum1_n2em = (uint8_T)(((uint32_T)
    LCCS_subsystem_integrated_DW.Output_DSTATE) + ((uint32_T)((uint8_T)1U)));

  /* Update for UnitDelay: '<S67>/Unit Delay5' */
  memcpy(&LCCS_subsystem_integrated_DW.UnitDelay5_DSTATE_fogd[0],
         &rtb_lateral_error_history[0], 101U * (sizeof(real32_T)));

  /* Switch: '<S78>/FixPt Switch' */
  if (rtb_FixPtSum1_n2em > ((uint8_T)9U))
  {
    /* Update for UnitDelay: '<S69>/Output' incorporates:
     *  Constant: '<S78>/Constant'
     */
    LCCS_subsystem_integrated_DW.Output_DSTATE = ((uint8_T)0U);
  }
  else
  {
    /* Update for UnitDelay: '<S69>/Output' */
    LCCS_subsystem_integrated_DW.Output_DSTATE = rtb_FixPtSum1_n2em;
  }

  /* End of Switch: '<S78>/FixPt Switch' */

  /* Update for UnitDelay: '<S67>/Unit Delay1' */
  LCCS_subsystem_integrated_DW.UnitDelay1_DSTATE_g04w = rtb_Switch1_fdqv;

  /* Update for UnitDelay: '<S67>/Unit Delay2' */
  LCCS_subsystem_integrated_DW.UnitDelay2_DSTATE_o2ei = rtb_UnitDelay1_jw5x;

  /* Update for UnitDelay: '<S67>/Unit Delay3' */
  LCCS_subsystem_integrated_DW.UnitDelay3_DSTATE_p0ty = rtb_UnitDelay2_o4fj;

  /* Update for UnitDelay: '<S67>/Unit Delay4' */
  LCCS_subsystem_integrated_DW.UnitDelay4_DSTATE_b3pi = rtb_UnitDelay3_g21h;

  /* Update for UnitDelay: '<S67>/Unit Delay6' */
  LCCS_subsystem_integrated_DW.UnitDelay6_DSTATE = rtb_UnitDelay4_by5g;

  /* Update for UnitDelay: '<S67>/Unit Delay7' */
  LCCS_subsystem_integrated_DW.UnitDelay7_DSTATE = rtb_UnitDelay6;

  /* Update for UnitDelay: '<S67>/Unit Delay8' */
  LCCS_subsystem_integrated_DW.UnitDelay8_DSTATE = rtb_UnitDelay7;

  /* Update for UnitDelay: '<S67>/Unit Delay9' */
  LCCS_subsystem_integrated_DW.UnitDelay9_DSTATE = rtb_UnitDelay8;

  /* Update for UnitDelay: '<S67>/Unit Delay10' */
  LCCS_subsystem_integrated_DW.UnitDelay10_DSTATE = rtb_UnitDelay9;

  /* Update for UnitDelay: '<S56>/UnitDelay2' */
  memcpy(&LCCS_subsystem_integrated_DW.UnitDelay2_DSTATE_ljaq[0], &rtb_P[0],
         (sizeof(real32_T)) << 4U);

  /* Update for UnitDelay: '<S63>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_pmel = rtb_Switch2_bhdm;

  /* Update for UnitDelay: '<S56>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_frui = rtb_Sum1_hhok;

  /* Update for UnitDelay: '<S64>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_k2bi = rtb_Switch2;

  /* End of Outputs for SubSystem: '<S7>/lateral_control' */

  /* Outputs for Atomic SubSystem: '<S7>/steering_wheel_angle' */
  /* Switch: '<S79>/Switch' incorporates:
   *  UnitDelay: '<S79>/Unit Delay'
   */
  if (LCCS_subsystem_integrated_B.VbLCCS_steering_control_ac_byg4)
  {
    rtb_UnitDelay1_jw5x = VfLCCS_veh_frtwhl_angle_des_ramped;
  }
  else
  {
    rtb_UnitDelay1_jw5x = VfLCCS_veh_frtwhl_angle_act;
  }

  /* End of Switch: '<S79>/Switch' */

  /* Gain: '<S57>/rad_to_deg' */
  rtb_Switch1_fdqv = 57.2957802F * VfLCCS_veh_frtwhl_angle_des;

  /* Switch: '<S82>/Switch' incorporates:
   *  Lookup_n-D: '<S82>/KtLCCS_Ang_steering_angle_step'
   *  Lookup_n-D: '<S82>/KtLCCS_Ang_steering_angle_step_engaging'
   */
  if (LCCS_subsystem_integrated_B.VbLCCS_steering_control_en_pmot)
  {
    sum_lateral_error = look1_iflf_binlca(VfLCCS_linear_velocity,
      KtLCCS_AXIS_vehicle_speed, KtLCCS_Ang_steering_angle_step, 20U);
  }
  else
  {
    sum_lateral_error = look1_iflf_binlca(VfLCCS_linear_velocity,
      KtLCCS_AXIS_vehicle_speed, KtLCCS_Ang_steering_angle_step_engaging, 20U);
  }

  /* End of Switch: '<S82>/Switch' */

  /* Abs: '<S82>/Abs' incorporates:
   *  Constant: '<S82>/Constant'
   *  Constant: '<S82>/Constant2'
   *  Product: '<S82>/Product'
   *  Product: '<S82>/Product1'
   */
  rtb_UnitDelay2_o4fj = (real32_T)fabs((real_T)((real32_T)((sum_lateral_error *
    KfLCCS_t_SampleTime) / KfLCCS_r_veh_strwhl_2_frtwhl_ratio)));

  /* Switch: '<S81>/Switch5' incorporates:
   *  Constant: '<S81>/Constant'
   *  Constant: '<S81>/Constant1'
   *  Constant: '<S81>/Constant2'
   *  Logic: '<S81>/Logical Operator'
   *  Logic: '<S81>/Logical Operator1'
   *  Product: '<S81>/Product1'
   *  RelationalOperator: '<S81>/Relational Operator6'
   *  RelationalOperator: '<S81>/Relational Operator7'
   *  RelationalOperator: '<S81>/Relational Operator8'
   *  RelationalOperator: '<S81>/Relational Operator9'
   *  Switch: '<S81>/Switch6'
   */
  if ((rtb_Switch1_fdqv > rtb_UnitDelay1_jw5x) && (rtb_UnitDelay1_jw5x >= 0.0F))
  {
    VfLCCS_frtwhl_angle_step_limit = KfLCCS_r_steering_rate_forward_gain *
      rtb_UnitDelay2_o4fj;
  }
  else if ((rtb_Switch1_fdqv < rtb_UnitDelay1_jw5x) && (rtb_UnitDelay1_jw5x <
            0.0F))
  {
    /* Switch: '<S81>/Switch6' incorporates:
     *  Constant: '<S81>/Constant3'
     *  Product: '<S81>/Product'
     */
    VfLCCS_frtwhl_angle_step_limit = KfLCCS_r_steering_rate_forward_gain *
      rtb_UnitDelay2_o4fj;
  }
  else
  {
    /* Switch: '<S81>/Switch6' */
    VfLCCS_frtwhl_angle_step_limit = rtb_UnitDelay2_o4fj;
  }

  /* End of Switch: '<S81>/Switch5' */

  /* Switch: '<S81>/Switch1' incorporates:
   *  RelationalOperator: '<S81>/Relational Operator2'
   */
  if (rtb_Switch1_fdqv >= rtb_UnitDelay1_jw5x)
  {
    /* Sum: '<S81>/Add1' */
    rtb_UnitDelay1_jw5x += VfLCCS_frtwhl_angle_step_limit;

    /* Switch: '<S81>/Switch' incorporates:
     *  RelationalOperator: '<S81>/Relational Operator1'
     */
    if (rtb_Switch1_fdqv <= rtb_UnitDelay1_jw5x)
    {
      rtb_UnitDelay1_jw5x = rtb_Switch1_fdqv;
    }

    /* End of Switch: '<S81>/Switch' */
  }
  else
  {
    /* Sum: '<S81>/Add2' */
    rtb_UnitDelay1_jw5x -= VfLCCS_frtwhl_angle_step_limit;

    /* Switch: '<S81>/Switch2' incorporates:
     *  RelationalOperator: '<S81>/Relational Operator3'
     */
    if (rtb_Switch1_fdqv >= rtb_UnitDelay1_jw5x)
    {
      rtb_UnitDelay1_jw5x = rtb_Switch1_fdqv;
    }

    /* End of Switch: '<S81>/Switch2' */
  }

  /* End of Switch: '<S81>/Switch1' */

  /* Abs: '<S82>/Abs1' incorporates:
   *  Constant: '<S82>/Constant3'
   *  Lookup_n-D: '<S82>/KtLCCS_Ang_steering_angle_max'
   *  Product: '<S82>/Product4'
   */
  VfLCCS_frtwhl_angle_limit_manual = (real32_T)fabs((real_T)((real32_T)
    (look1_iflf_binlca(VfLCCS_linear_velocity, KtLCCS_AXIS_vehicle_speed,
                       KtLCCS_Ang_steering_angle_max, 20U) /
     KfLCCS_r_veh_strwhl_2_frtwhl_ratio)));

  /* Gain: '<S82>/Gain' */
  rtb_UnitDelay2_o4fj = (-1.0F) * VfLCCS_frtwhl_angle_limit_manual;

  /* Switch: '<S83>/Switch2' incorporates:
   *  RelationalOperator: '<S83>/LowerRelop1'
   *  RelationalOperator: '<S83>/UpperRelop'
   *  Switch: '<S83>/Switch'
   */
  if (rtb_UnitDelay1_jw5x > VfLCCS_frtwhl_angle_limit_manual)
  {
    VfLCCS_veh_frtwhl_angle_des_ramped = VfLCCS_frtwhl_angle_limit_manual;
  }
  else if (rtb_UnitDelay1_jw5x < rtb_UnitDelay2_o4fj)
  {
    /* Switch: '<S83>/Switch' */
    VfLCCS_veh_frtwhl_angle_des_ramped = rtb_UnitDelay2_o4fj;
  }
  else
  {
    VfLCCS_veh_frtwhl_angle_des_ramped = rtb_UnitDelay1_jw5x;
  }

  /* End of Switch: '<S83>/Switch2' */

  /* Sum: '<S80>/Add' incorporates:
   *  Constant: '<S80>/Constant1'
   *  Constant: '<S80>/Constant2'
   *  Product: '<S80>/Product'
   */
  VfLCCS_veh_strwhl_angle_des = (VfLCCS_veh_frtwhl_angle_des_ramped *
    KfLCCS_r_veh_strwhl_2_frtwhl_ratio) + KfLCCS_Ang_steering_center_position;

  /* Sum: '<S80>/Add1' incorporates:
   *  Constant: '<S80>/Constant3'
   *  Constant: '<S80>/Constant4'
   *  Product: '<S80>/Product1'
   */
  LCCS_subsystem_integrated_B.Add1 = (rtb_Switch1_fdqv *
    KfLCCS_r_veh_strwhl_2_frtwhl_ratio) + KfLCCS_Ang_steering_center_position;

  /* End of Outputs for SubSystem: '<S7>/steering_wheel_angle' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
