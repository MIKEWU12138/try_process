/*
 * File: lccs_control_error.c
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

#include "lccs_control_error.h"

/* Include model header file for global data */
#include "LCCS_subsystem_integrated.h"
#include "LCCS_subsystem_integrated_private.h"
#include "rt_atan2f_snf.h"
#include "rt_powf_snf.h"

/*
 * Output and update for atomic system:
 *    '<S13>/QueryNearestPointByVehPosition'
 *    '<S15>/QueryNearestPointByVehPosition'
 */
void QueryNearestPointByVehPosition(const real32_T rtu_trajectory_points[160],
  real32_T rtu_x, real32_T rtu_y, real32_T rty_proj_xy[2], int32_T *rty_index,
  real32_T *rty_fraction)
{
  real32_T dx;
  real32_T dy;
  real32_T d_min;
  int32_T index_min;
  int32_T i;
  real32_T b_dy__;
  real32_T c_dx__;
  real32_T c_dy__;
  real32_T d_dx__;
  real32_T d_dy__;
  dx = rtu_trajectory_points[1] - rtu_x;
  dy = rtu_trajectory_points[81] - rtu_y;
  d_min = (dx * dx) + (dy * dy);
  index_min = 1;
  for (i = 0; i < 78; i++)
  {
    dx = rtu_trajectory_points[i + 1] - rtu_x;
    dy = rtu_trajectory_points[i + 81] - rtu_y;
    dx = (dx * dx) + (dy * dy);
    if (dx < d_min)
    {
      d_min = dx;
      index_min = 1 + i;
    }
  }

  rty_proj_xy[0] = rtu_trajectory_points[index_min - 1];
  rty_proj_xy[0] += (rtu_trajectory_points[index_min] - rty_proj_xy[0]) * 0.0F;
  rty_proj_xy[1] = rtu_trajectory_points[index_min + 79];
  rty_proj_xy[1] += (rtu_trajectory_points[index_min + 80] - rty_proj_xy[1]) *
    0.0F;
  d_min = rty_proj_xy[0] - rtu_x;
  dx = rty_proj_xy[1] - rtu_y;
  rty_proj_xy[0] = rtu_trajectory_points[index_min];
  rty_proj_xy[0] += rtu_trajectory_points[index_min + 1] - rty_proj_xy[0];
  rty_proj_xy[1] = rtu_trajectory_points[index_min + 80];
  rty_proj_xy[1] += rtu_trajectory_points[index_min + 81] - rty_proj_xy[1];
  dy = rty_proj_xy[0] - rtu_x;
  b_dy__ = rty_proj_xy[1] - rtu_y;
  if (((d_min * d_min) + (dx * dx)) < ((dy * dy) + (b_dy__ * b_dy__)))
  {
  }
  else
  {
    index_min++;
  }

  rty_proj_xy[0] = rtu_trajectory_points[index_min - 1];
  rty_proj_xy[1] = rtu_trajectory_points[index_min + 79];
  d_min = 0.0F;
  dx = 1.0F;
  dy = 0.381966F;
  b_dy__ = 0.618034F;
  while (((real32_T)fabs((real_T)((real32_T)(dy - b_dy__)))) > 0.01F)
  {
    d_dx__ = rtu_trajectory_points[index_min] - rty_proj_xy[0];
    c_dx__ = (rty_proj_xy[0] + (d_dx__ * dy)) - rtu_x;
    d_dy__ = rtu_trajectory_points[index_min + 80] - rty_proj_xy[1];
    c_dy__ = (rty_proj_xy[1] + (d_dy__ * dy)) - rtu_y;
    d_dx__ = (rty_proj_xy[0] + (d_dx__ * b_dy__)) - rtu_x;
    d_dy__ = (rty_proj_xy[1] + (d_dy__ * b_dy__)) - rtu_y;
    if (((c_dx__ * c_dx__) + (c_dy__ * c_dy__)) < ((d_dx__ * d_dx__) + (d_dy__ *
          d_dy__)))
    {
      dx = b_dy__;
    }
    else
    {
      d_min = dy;
    }

    b_dy__ = (dx - d_min) / 1.61803401F;
    dy = dx - b_dy__;
    b_dy__ += d_min;
  }

  d_min = (d_min + dx) * 0.5F;
  rty_proj_xy[0] = (rty_proj_xy[0] * (1.0F - d_min)) +
    (rtu_trajectory_points[index_min] * d_min);
  rty_proj_xy[1] = (rty_proj_xy[1] * (1.0F - d_min)) +
    (rtu_trajectory_points[index_min + 80] * d_min);
  *rty_index = index_min;
  *rty_fraction = d_min;
}

/* System initialize for atomic system: '<S2>/CalcLCCS_compute_lateral_errors' */
void CalcLCCS_compute_lateral_e_Init(void)
{
  int32_T i;

  /* InitializeConditions for S-Function (sfix_udelay): '<S14>/Trapped Delay' */
  for (i = 0; i < 50; i++)
  {
    LCCS_subsystem_integrated_DW.TrappedDelay_X[i] = 0.0F;
  }

  /* End of InitializeConditions for S-Function (sfix_udelay): '<S14>/Trapped Delay' */
}

/* Output and update for atomic system: '<S2>/CalcLCCS_compute_lateral_errors' */
void CalcLCCS_compute_lateral_errors(void)
{
  /* local block i/o variables */
  real32_T rtb_x2;
  real32_T rtb_y2;
  real32_T a;
  boolean_T rEQ0;
  real32_T q;
  real32_T rtb_Sum7[3];
  real32_T rtb_heading6;
  real32_T rtb_TrappedDelay[51];
  real32_T rtb_x3;
  real32_T rtb_y3;
  real32_T rtb_proj_xy[2];
  int32_T rtb_index;
  real32_T rtb_fraction;
  int32_T rtb_index_pqpa;
  real32_T rtb_fraction_dby5;
  int32_T u1;

  /* SignalConversion: '<S13>/Signal Conversion1' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S13>/rear_to_com_distance'
   */
  VaLCCS_com_point[0] = KfLCCS_d_lr;
  VaLCCS_com_point[1] = 0.0F;
  VaLCCS_com_point[2] = VfLCCS_veh_heading_rel;

  /* MultiPortSwitch: '<S15>/x2' incorporates:
   *  Constant: '<S15>/Constant1'
   *  Constant: '<S15>/Constant6'
   */
  switch (1)
  {
   case 1:
    rtb_x2 = VfLCCS_lookahead_distance;
    break;

   case 2:
    rtb_x2 = 0.0F;
    break;

   default:
    /* no actions */
    break;
  }

  /* End of MultiPortSwitch: '<S15>/x2' */

  /* MultiPortSwitch: '<S15>/y2' incorporates:
   *  Constant: '<S15>/Constant1'
   *  Constant: '<S15>/Constant7'
   */
  switch (2)
  {
   case 1:
    rtb_y2 = VfLCCS_lookahead_distance;
    break;

   case 2:
    rtb_y2 = 0.0F;
    break;

   default:
    /* no actions */
    break;
  }

  /* End of MultiPortSwitch: '<S15>/y2' */

  /* MATLAB Function: '<S15>/QueryNearestPointByVehPosition' */
  QueryNearestPointByVehPosition(LCCS_subsystem_integrated_B.lane_center_points,
    rtb_x2, rtb_y2, rtb_proj_xy, &rtb_index, &rtb_fraction);

  /* SignalConversion: '<S15>/Signal Conversion' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S15>/Constant43'
   *  Constant: '<S15>/Constant44'
   *  MultiPortSwitch: '<S15>/x9'
   *  MultiPortSwitch: '<S15>/y9'
   *  Reshape: '<S15>/Reshape'
   */
  VaLCCS_preview_proj_point[0] = rtb_proj_xy[1 - 1];
  VaLCCS_preview_proj_point[1] = rtb_proj_xy[2 - 1];
  VaLCCS_preview_proj_point[2] = 0.0F;

  /* Sum: '<S14>/Sum7' */
  rtb_Sum7[0] = VaLCCS_preview_proj_point[0] - VaLCCS_com_point[0];
  rtb_Sum7[1] = VaLCCS_preview_proj_point[1] - VaLCCS_com_point[1];
  rtb_Sum7[2] = VaLCCS_preview_proj_point[2] - VaLCCS_com_point[2];

  /* Trigonometry: '<S14>/Atan2' incorporates:
   *  Constant: '<S14>/Constant20'
   *  Constant: '<S14>/Constant21'
   *  MultiPortSwitch: '<S14>/x6'
   *  MultiPortSwitch: '<S14>/y6'
   */
  VfLCCS_lookahead_angle = rt_atan2f_snf(rtb_Sum7[2 - 1], rtb_Sum7[1 - 1]);

  /* MultiPortSwitch: '<S13>/x3' incorporates:
   *  Constant: '<S13>/Constant12'
   */
  rtb_x3 = VaLCCS_com_point[0];

  /* MultiPortSwitch: '<S13>/y3' incorporates:
   *  Constant: '<S13>/Constant13'
   */
  rtb_y3 = VaLCCS_com_point[1];

  /* MATLAB Function: '<S13>/QueryNearestPointByVehPosition' */
  QueryNearestPointByVehPosition(LCCS_subsystem_integrated_B.lane_center_points,
    rtb_x3, rtb_y3, rtb_proj_xy, &rtb_index_pqpa, &rtb_fraction_dby5);

  /* SignalConversion: '<S13>/Signal Conversion' incorporates:
   *  Constant: '<S13>/Constant14'
   *  Constant: '<S13>/Constant15'
   *  Constant: '<S13>/Constant8'
   *  MultiPortSwitch: '<S13>/c1_heading'
   *  MultiPortSwitch: '<S13>/x'
   *  MultiPortSwitch: '<S13>/y'
   *  Reshape: '<S13>/Reshape'
   *  Trigonometry: '<S13>/atan'
   */
  VaLCCS_com_proj_point[0] = rtb_proj_xy[0];
  VaLCCS_com_proj_point[1] = rtb_proj_xy[1];
  VaLCCS_com_proj_point[2] = (real32_T)atan((real_T)
    VaLCCS_shifted_lane_center_line[1]);

  /* Switch: '<S14>/Switch1' incorporates:
   *  Constant: '<S14>/Constant13'
   *  Constant: '<S14>/gps_trace_x5'
   *  MultiPortSwitch: '<S14>/heading8'
   */
  if (KbLCCS_UsePurePursuit)
  {
    rtb_heading6 = VfLCCS_lookahead_angle;
  }
  else
  {
    rtb_heading6 = VaLCCS_com_proj_point[3 - 1];
  }

  /* End of Switch: '<S14>/Switch1' */

  /* Sum: '<S14>/Sum10' incorporates:
   *  Constant: '<S14>/Constant22'
   *  MultiPortSwitch: '<S14>/heading4'
   */
  rtb_heading6 = VaLCCS_com_point[3 - 1] - rtb_heading6;

  /* MATLAB Function: '<S14>/NormalizeHeadingAngle' */
  if ((!rtIsInfF(rtb_heading6 + 3.14159274F)) && (!rtIsNaNF(rtb_heading6 +
        3.14159274F)))
  {
    if ((rtb_heading6 + 3.14159274F) == 0.0F)
    {
      a = 0.0F;
    }
    else
    {
      a = (real32_T)fmod((real_T)((real32_T)(rtb_heading6 + 3.14159274F)),
                         6.2831854820251465);
      rEQ0 = (a == 0.0F);
      if (!rEQ0)
      {
        q = (real32_T)fabs((real_T)((real32_T)((rtb_heading6 + 3.14159274F) /
          6.28318548F)));
        rEQ0 = (((real32_T)fabs((real_T)((real32_T)(q - ((real32_T)floor((real_T)
          ((real32_T)(q + 0.5F)))))))) <= (1.1920929E-7F * q));
      }

      if (rEQ0)
      {
        a = 0.0F;
      }
      else
      {
        if ((rtb_heading6 + 3.14159274F) < 0.0F)
        {
          a += 6.28318548F;
        }
      }
    }
  }
  else
  {
    a = (rtNaNF);
  }

  if (a < 0.0F)
  {
    a += 6.28318548F;
  }

  VfLCCS_heading_error = a - 3.14159274F;

  /* End of MATLAB Function: '<S14>/NormalizeHeadingAngle' */

  /* S-Function (sfix_udelay): '<S14>/Trapped Delay' */
  rtb_TrappedDelay[0] = VfLCCS_heading_error;
  memcpy(&rtb_TrappedDelay[1], &LCCS_subsystem_integrated_DW.TrappedDelay_X[0],
         50U * (sizeof(real32_T)));

  /* Sum: '<S14>/Sum5' */
  rtb_Sum7[0] = VaLCCS_com_point[0] - VaLCCS_com_proj_point[0];
  rtb_Sum7[1] = VaLCCS_com_point[1] - VaLCCS_com_proj_point[1];
  rtb_Sum7[2] = VaLCCS_com_point[2] - VaLCCS_com_proj_point[2];

  /* Sum: '<S14>/Sum6' incorporates:
   *  Constant: '<S14>/Constant17'
   *  Constant: '<S14>/Constant18'
   *  Constant: '<S14>/Constant9'
   *  MultiPortSwitch: '<S14>/heading2'
   *  MultiPortSwitch: '<S14>/x5'
   *  MultiPortSwitch: '<S14>/y5'
   *  Product: '<S14>/Product5'
   *  Product: '<S14>/Product8'
   *  Trigonometry: '<S14>/Cos4'
   *  Trigonometry: '<S14>/Cos5'
   */
  rtb_heading6 = (((real32_T)cos((real_T)VaLCCS_com_proj_point[3 - 1])) *
                  rtb_Sum7[2 - 1]) - (((real32_T)sin((real_T)
    VaLCCS_com_proj_point[3 - 1])) * rtb_Sum7[1 - 1]);

  /* Switch: '<S21>/Switch2' incorporates:
   *  Constant: '<S14>/Constant34'
   *  Constant: '<S14>/Constant35'
   *  RelationalOperator: '<S21>/LowerRelop1'
   *  RelationalOperator: '<S21>/UpperRelop'
   *  Switch: '<S21>/Switch'
   */
  if (rtb_heading6 > 2.0F)
  {
    VfLCCS_lateral_error = 2.0F;
  }
  else if (rtb_heading6 < (-2.0F))
  {
    /* Switch: '<S21>/Switch' incorporates:
     *  Constant: '<S14>/Constant35'
     */
    VfLCCS_lateral_error = (-2.0F);
  }
  else
  {
    VfLCCS_lateral_error = rtb_heading6;
  }

  /* End of Switch: '<S21>/Switch2' */

  /* MultiPortSwitch: '<S14>/heading1' incorporates:
   *  Constant: '<S14>/Constant1'
   *  Constant: '<S14>/Constant12'
   *  Constant: '<S14>/Constant2'
   *  MinMax: '<S14>/Max'
   *  Sum: '<S14>/Add1'
   */
  u1 = 1 + KcLCCS_HeadingErrorRateSmooth;
  if (51 < u1)
  {
    u1 = 51;
  }

  /* MinMax: '<S14>/MinMax4' incorporates:
   *  Constant: '<S14>/Constant11'
   *  Constant: '<S14>/Constant5'
   */
  if ((KfLCCS_t_SampleTime > 0.01F) || (rtIsNaNF(0.01F)))
  {
    rtb_heading6 = KfLCCS_t_SampleTime;
  }
  else
  {
    rtb_heading6 = 0.01F;
  }

  /* End of MinMax: '<S14>/MinMax4' */

  /* Product: '<S14>/Product' incorporates:
   *  Constant: '<S14>/Constant3'
   *  Constant: '<S14>/Constant4'
   *  MultiPortSwitch: '<S14>/heading1'
   *  MultiPortSwitch: '<S14>/heading3'
   *  Sum: '<S14>/Add'
   */
  rtb_heading6 = ((rtb_TrappedDelay[1 - 1] - rtb_TrappedDelay[u1 - 1]) /
                  rtb_heading6) / ((real32_T)KcLCCS_HeadingErrorRateSmooth);

  /* Switch: '<S14>/Switch3' incorporates:
   *  Abs: '<S14>/Abs'
   *  Constant: '<S17>/Constant'
   *  RelationalOperator: '<S17>/Compare'
   *  UnitDelay: '<S14>/Unit Delay'
   */
  if (((real32_T)fabs((real_T)rtb_heading6)) > KfLCCS_heading_error_rate_limit)
  {
    rtb_heading6 = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_mkfo;
  }

  /* End of Switch: '<S14>/Switch3' */

  /* MATLAB Function: '<S14>/MATLAB Function1' incorporates:
   *  Constant: '<S14>/Constant15'
   *  Constant: '<S14>/Constant16'
   *  Constant: '<S14>/Constant19'
   *  Constant: '<S14>/Constant23'
   *  MultiPortSwitch: '<S14>/c1_heading1'
   *  MultiPortSwitch: '<S14>/c2_curvature2'
   *  MultiPortSwitch: '<S14>/c3_curvature_derivative1'
   *  MultiPortSwitch: '<S14>/x1'
   */
  a = (VaLCCS_shifted_lane_center_line[1] + ((2.0F *
         VaLCCS_shifted_lane_center_line[2]) * VaLCCS_com_proj_point[0])) +
    (((3.0F * VaLCCS_shifted_lane_center_line[3]) * VaLCCS_com_proj_point[0]) *
     VaLCCS_com_proj_point[0]);
  a = rt_powf_snf(1.0F + (a * a), 1.5F);
  if (a != 0.0F)
  {
    a = (real32_T)fabs((real_T)((real32_T)(((2.0F *
      VaLCCS_shifted_lane_center_line[2]) + ((6.0F *
      VaLCCS_shifted_lane_center_line[3]) * VaLCCS_com_proj_point[0])) / a)));
  }
  else
  {
    a = (real32_T)fabs((real_T)((real32_T)(2.0F *
      VaLCCS_shifted_lane_center_line[2])));
  }

  /* End of MATLAB Function: '<S14>/MATLAB Function1' */

  /* Switch: '<S14>/Switch2' incorporates:
   *  Constant: '<S14>/gps_trace_x1'
   *  Product: '<S14>/Product13'
   *  Saturate: '<S14>/limit_minus0p2_to_0p1'
   *  Sum: '<S14>/Add4'
   */
  if (KbLCCS_UsePurePursuit)
  {
    VfLCCS_heading_error_rate = rtb_heading6;
  }
  else
  {
    if (a > 0.2F)
    {
      /* Saturate: '<S14>/limit_minus0p2_to_0p1' */
      a = 0.2F;
    }
    else
    {
      if (a < (-0.2F))
      {
        /* Saturate: '<S14>/limit_minus0p2_to_0p1' */
        a = (-0.2F);
      }
    }

    VfLCCS_heading_error_rate = VfLCCS_yaw_rate - (VfLCCS_linear_velocity * a);
  }

  /* End of Switch: '<S14>/Switch2' */

  /* Product: '<S14>/Product11' incorporates:
   *  Constant: '<S14>/Constant28'
   *  Constant: '<S14>/Constant29'
   *  MultiPortSwitch: '<S14>/heading5'
   *  MultiPortSwitch: '<S14>/heading6'
   *  Sum: '<S14>/Sum15'
   *  Trigonometry: '<S14>/Cos6'
   */
  VfLCCS_lateral_error_rate = VfLCCS_linear_velocity * ((real32_T)sin((real_T)
    ((real32_T)(VaLCCS_com_point[3 - 1] - VaLCCS_com_proj_point[3 - 1]))));

  /* MATLAB Function: '<S14>/MATLAB Function' incorporates:
   *  Constant: '<S14>/Constant10'
   *  Constant: '<S14>/Constant6'
   *  Constant: '<S14>/Constant7'
   *  Constant: '<S14>/Constant8'
   *  MultiPortSwitch: '<S14>/c1_heading'
   *  MultiPortSwitch: '<S14>/c2_curvature'
   *  MultiPortSwitch: '<S14>/c3_curvature_derivative'
   *  MultiPortSwitch: '<S14>/x'
   */
  a = (VaLCCS_shifted_lane_center_line[1] + ((2.0F *
         VaLCCS_shifted_lane_center_line[2]) * VaLCCS_preview_proj_point[0])) +
    (((3.0F * VaLCCS_shifted_lane_center_line[3]) * VaLCCS_preview_proj_point[0])
     * VaLCCS_preview_proj_point[0]);
  a = rt_powf_snf(1.0F + (a * a), 1.5F);
  if (a != 0.0F)
  {
    a = (real32_T)fabs((real_T)((real32_T)(((2.0F *
      VaLCCS_shifted_lane_center_line[2]) + ((6.0F *
      VaLCCS_shifted_lane_center_line[3]) * VaLCCS_preview_proj_point[0])) / a)));
  }
  else
  {
    a = (real32_T)fabs((real_T)((real32_T)(2.0F *
      VaLCCS_shifted_lane_center_line[2])));
  }

  /* End of MATLAB Function: '<S14>/MATLAB Function' */

  /* Saturate: '<S14>/limit_minus0p2_to_0p2' */
  if (a > 0.2F)
  {
    VfLCCS_preview_curvature = 0.2F;
  }
  else if (a < (-0.2F))
  {
    VfLCCS_preview_curvature = (-0.2F);
  }
  else
  {
    VfLCCS_preview_curvature = a;
  }

  /* End of Saturate: '<S14>/limit_minus0p2_to_0p2' */

  /* Update for S-Function (sfix_udelay): '<S14>/Trapped Delay' */
  for (u1 = 0; u1 < 49; u1++)
  {
    LCCS_subsystem_integrated_DW.TrappedDelay_X[49 - u1] =
      LCCS_subsystem_integrated_DW.TrappedDelay_X[48 - u1];
  }

  LCCS_subsystem_integrated_DW.TrappedDelay_X[0] = VfLCCS_heading_error;

  /* End of Update for S-Function (sfix_udelay): '<S14>/Trapped Delay' */

  /* Update for UnitDelay: '<S14>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_mkfo = rtb_heading6;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
