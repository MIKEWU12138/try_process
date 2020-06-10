/*
 * File: lccs_lane_center.c
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

#include "lccs_lane_center.h"

/* Include model header file for global data */
#include "LCCS_subsystem_integrated.h"
#include "LCCS_subsystem_integrated_private.h"
#include "look1_iflf_binlca.h"
#include "rt_powf_snf.h"

/*
 * Output and update for atomic system:
 *    '<S32>/kinematic_compensation'
 *    '<S33>/kinematic_compensation'
 */
void LCCS_sub_kinematic_compensation(real32_T rtu_dx, real32_T rtu_dy, real32_T
  rtu_final_lanemark_prev, real32_T rtu_final_lanemark_prev_hzxh, real32_T
  rtu_final_lanemark_prev_jcju, real32_T rtu_final_lanemark_prev_jq1g, real32_T
  rty_final_lanemark_compensated[4])
{
  real32_T tmp;
  rty_final_lanemark_compensated[0] = 0.0F;
  rty_final_lanemark_compensated[1] = 0.0F;
  rty_final_lanemark_compensated[2] = 0.0F;
  rty_final_lanemark_compensated[3] = 0.0F;
  tmp = rtu_dx * rtu_dx;

  /* SignalConversion: '<S48>/TmpSignal ConversionAt SFunction Inport3' */
  rty_final_lanemark_compensated[0] = (((rtu_final_lanemark_prev +
    (rtu_final_lanemark_prev_hzxh * rtu_dx)) + (rtu_final_lanemark_prev_jcju *
    tmp)) + (rtu_final_lanemark_prev_jq1g * rt_powf_snf(rtu_dx, 3.0F))) - rtu_dy;
  rty_final_lanemark_compensated[1] = (rtu_final_lanemark_prev_hzxh + ((2.0F *
    rtu_final_lanemark_prev_jcju) * rtu_dx)) + ((3.0F *
    rtu_final_lanemark_prev_jq1g) * tmp);
  rty_final_lanemark_compensated[2] = rtu_final_lanemark_prev_jcju + ((3.0F *
    rtu_final_lanemark_prev_jq1g) * rtu_dx);
  rty_final_lanemark_compensated[3] = rtu_final_lanemark_prev_jq1g;
}

/* Output and update for atomic system: '<S2>/CalcLCCS_lane_center_line' */
void LCCS__CalcLCCS_lane_center_line(void)
{
  real32_T rtb_Product3;
  real32_T rtb_Product2;
  real32_T rtb_Switch2_lm3u;
  real32_T rtb_Product4;
  real32_T rtb_Switch2_a5v1;
  real32_T rtb_Switch2_ak2k;
  real32_T rtb_Switch2_galy;
  real32_T rtb_Switch2_f55r;
  real32_T rtb_Switch2_ipzf;
  real32_T rtb_Switch2_ffxp;
  real32_T rtb_Switch2_a3lh;
  real32_T rtb_Switch2;
  real32_T rtb_Switch2_kemu;
  real32_T rtb_Switch2_dor5;
  real32_T rtb_Switch2_k3ke;
  real32_T rtb_Switch2_fzvi;
  real32_T rtb_Switch2_djco;
  real32_T rtb_Switch2_or5u;
  real32_T rtb_Switch2_hpiy;
  real32_T rtb_Switch2_bkkd;
  real32_T rtb_Switch2_iup5;
  real32_T rtb_Switch2_dx2w;
  real32_T rtb_Switch2_iz1e;
  real32_T rtb_final_lanemark_compens_e2pc[4];
  real32_T rtb_final_lanemark_compensated[4];
  real32_T VbLCCS_touched_new_lane_tmp;

  /* Product: '<S6>/Product3' incorporates:
   *  Constant: '<S6>/Constant6'
   */
  rtb_Product3 = VfLCCS_velocity_rel_x * KfLCCS_t_SampleTime;

  /* Switch: '<S44>/Switch2' incorporates:
   *  RelationalOperator: '<S44>/Relational Operator11'
   */
  if (rtIsNaNF(rtb_Product3))
  {
    /* Switch: '<S44>/Switch' incorporates:
     *  Constant: '<S44>/Constant'
     *  RelationalOperator: '<S44>/Relational Operator1'
     *  UnitDelay: '<S44>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_eoiv))
    {
      rtb_Switch2 = 0.0F;
    }
    else
    {
      rtb_Switch2 = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_eoiv;
    }

    /* End of Switch: '<S44>/Switch' */
  }
  else
  {
    rtb_Switch2 = rtb_Product3;
  }

  /* End of Switch: '<S44>/Switch2' */

  /* Product: '<S6>/Product2' incorporates:
   *  Constant: '<S6>/Constant6'
   */
  rtb_Product2 = KfLCCS_t_SampleTime * VfLCCS_velocity_rel_y;

  /* Switch: '<S42>/Switch2' incorporates:
   *  RelationalOperator: '<S42>/Relational Operator11'
   */
  if (rtIsNaNF(rtb_Product2))
  {
    /* Switch: '<S42>/Switch' incorporates:
     *  Constant: '<S42>/Constant'
     *  RelationalOperator: '<S42>/Relational Operator1'
     *  UnitDelay: '<S42>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_navt))
    {
      rtb_Switch2_kemu = 0.0F;
    }
    else
    {
      rtb_Switch2_kemu = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_navt;
    }

    /* End of Switch: '<S42>/Switch' */
  }
  else
  {
    rtb_Switch2_kemu = rtb_Product2;
  }

  /* End of Switch: '<S42>/Switch2' */

  /* Switch: '<S43>/Switch2' incorporates:
   *  RelationalOperator: '<S43>/Relational Operator11'
   *  UnitDelay: '<S6>/Unit Delay2'
   */
  if (rtIsNaNF(VaLCCS_final_left_lanemark[0]))
  {
    /* Switch: '<S43>/Switch' incorporates:
     *  Constant: '<S43>/Constant'
     *  RelationalOperator: '<S43>/Relational Operator1'
     *  UnitDelay: '<S43>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_o5zn))
    {
      rtb_Switch2_dor5 = 0.0F;
    }
    else
    {
      rtb_Switch2_dor5 = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_o5zn;
    }

    /* End of Switch: '<S43>/Switch' */
  }
  else
  {
    rtb_Switch2_dor5 = VaLCCS_final_left_lanemark[0];
  }

  /* End of Switch: '<S43>/Switch2' */

  /* Switch: '<S45>/Switch2' incorporates:
   *  RelationalOperator: '<S45>/Relational Operator11'
   *  UnitDelay: '<S6>/Unit Delay2'
   */
  if (rtIsNaNF(VaLCCS_final_left_lanemark[1]))
  {
    /* Switch: '<S45>/Switch' incorporates:
     *  Constant: '<S45>/Constant'
     *  RelationalOperator: '<S45>/Relational Operator1'
     *  UnitDelay: '<S45>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_jjbb))
    {
      rtb_Switch2_k3ke = 0.0F;
    }
    else
    {
      rtb_Switch2_k3ke = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_jjbb;
    }

    /* End of Switch: '<S45>/Switch' */
  }
  else
  {
    rtb_Switch2_k3ke = VaLCCS_final_left_lanemark[1];
  }

  /* End of Switch: '<S45>/Switch2' */

  /* Switch: '<S46>/Switch2' incorporates:
   *  RelationalOperator: '<S46>/Relational Operator11'
   *  UnitDelay: '<S6>/Unit Delay2'
   */
  if (rtIsNaNF(VaLCCS_final_left_lanemark[2]))
  {
    /* Switch: '<S46>/Switch' incorporates:
     *  Constant: '<S46>/Constant'
     *  RelationalOperator: '<S46>/Relational Operator1'
     *  UnitDelay: '<S46>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_hi5n))
    {
      rtb_Switch2_fzvi = 0.0F;
    }
    else
    {
      rtb_Switch2_fzvi = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_hi5n;
    }

    /* End of Switch: '<S46>/Switch' */
  }
  else
  {
    rtb_Switch2_fzvi = VaLCCS_final_left_lanemark[2];
  }

  /* End of Switch: '<S46>/Switch2' */

  /* Switch: '<S47>/Switch2' incorporates:
   *  RelationalOperator: '<S47>/Relational Operator11'
   *  UnitDelay: '<S6>/Unit Delay2'
   */
  if (rtIsNaNF(VaLCCS_final_left_lanemark[3]))
  {
    /* Switch: '<S47>/Switch' incorporates:
     *  Constant: '<S47>/Constant'
     *  RelationalOperator: '<S47>/Relational Operator1'
     *  UnitDelay: '<S47>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_ctwe))
    {
      rtb_Switch2_djco = 0.0F;
    }
    else
    {
      rtb_Switch2_djco = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_ctwe;
    }

    /* End of Switch: '<S47>/Switch' */
  }
  else
  {
    rtb_Switch2_djco = VaLCCS_final_left_lanemark[3];
  }

  /* End of Switch: '<S47>/Switch2' */

  /* MATLAB Function: '<S32>/kinematic_compensation' */
  LCCS_sub_kinematic_compensation(rtb_Switch2, rtb_Switch2_kemu,
    rtb_Switch2_dor5, rtb_Switch2_k3ke, rtb_Switch2_fzvi, rtb_Switch2_djco,
    rtb_final_lanemark_compens_e2pc);

  /* Switch: '<S38>/Switch2' incorporates:
   *  RelationalOperator: '<S38>/Relational Operator11'
   */
  if (rtIsNaNF(VaLCCS_virtual_left_lanemark[0]))
  {
    /* Switch: '<S38>/Switch' incorporates:
     *  Constant: '<S38>/Constant'
     *  RelationalOperator: '<S38>/Relational Operator1'
     *  UnitDelay: '<S38>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_bazq))
    {
      rtb_Switch2_a5v1 = 0.0F;
    }
    else
    {
      rtb_Switch2_a5v1 = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_bazq;
    }

    /* End of Switch: '<S38>/Switch' */
  }
  else
  {
    rtb_Switch2_a5v1 = VaLCCS_virtual_left_lanemark[0];
  }

  /* End of Switch: '<S38>/Switch2' */

  /* Switch: '<S39>/Switch2' incorporates:
   *  RelationalOperator: '<S39>/Relational Operator11'
   */
  if (rtIsNaNF(VaLCCS_virtual_left_lanemark[1]))
  {
    /* Switch: '<S39>/Switch' incorporates:
     *  Constant: '<S39>/Constant'
     *  RelationalOperator: '<S39>/Relational Operator1'
     *  UnitDelay: '<S39>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_o3lq))
    {
      rtb_Switch2_ak2k = 0.0F;
    }
    else
    {
      rtb_Switch2_ak2k = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_o3lq;
    }

    /* End of Switch: '<S39>/Switch' */
  }
  else
  {
    rtb_Switch2_ak2k = VaLCCS_virtual_left_lanemark[1];
  }

  /* End of Switch: '<S39>/Switch2' */

  /* Switch: '<S40>/Switch2' incorporates:
   *  RelationalOperator: '<S40>/Relational Operator11'
   */
  if (rtIsNaNF(VaLCCS_virtual_left_lanemark[2]))
  {
    /* Switch: '<S40>/Switch' incorporates:
     *  Constant: '<S40>/Constant'
     *  RelationalOperator: '<S40>/Relational Operator1'
     *  UnitDelay: '<S40>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_ht0x))
    {
      rtb_Switch2_galy = 0.0F;
    }
    else
    {
      rtb_Switch2_galy = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_ht0x;
    }

    /* End of Switch: '<S40>/Switch' */
  }
  else
  {
    rtb_Switch2_galy = VaLCCS_virtual_left_lanemark[2];
  }

  /* End of Switch: '<S40>/Switch2' */

  /* Switch: '<S41>/Switch2' incorporates:
   *  RelationalOperator: '<S41>/Relational Operator11'
   */
  if (rtIsNaNF(VaLCCS_virtual_left_lanemark[3]))
  {
    /* Switch: '<S41>/Switch' incorporates:
     *  Constant: '<S41>/Constant'
     *  RelationalOperator: '<S41>/Relational Operator1'
     *  UnitDelay: '<S41>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_bxva))
    {
      rtb_Switch2_f55r = 0.0F;
    }
    else
    {
      rtb_Switch2_f55r = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_bxva;
    }

    /* End of Switch: '<S41>/Switch' */
  }
  else
  {
    rtb_Switch2_f55r = VaLCCS_virtual_left_lanemark[3];
  }

  /* End of Switch: '<S41>/Switch2' */

  /* Switch: '<S6>/Switch2' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant10'
   *  Constant: '<S6>/Constant11'
   *  MinMax: '<S6>/MinMax4'
   *  RelationalOperator: '<S27>/FixPt Relational Operator'
   *  UnitDelay: '<S27>/Delay Input1'
   *
   * Block description for '<S27>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (VbLCCS_left_lanemark_valid !=
      LCCS_subsystem_integrated_DW.DelayInput1_DSTATE)
  {
    rtb_Switch2_lm3u = 0.0F;
  }
  else
  {
    if ((KfLCCS_t_SampleTime > 0.01F) || (rtIsNaNF(0.01F)))
    {
      /* MinMax: '<S6>/MinMax4' incorporates:
       *  Constant: '<S6>/Constant10'
       */
      VbLCCS_touched_new_lane_tmp = KfLCCS_t_SampleTime;
    }
    else
    {
      /* MinMax: '<S6>/MinMax4' incorporates:
       *  Constant: '<S6>/Constant11'
       */
      VbLCCS_touched_new_lane_tmp = 0.01F;
    }

    /* Product: '<S6>/Divide2' incorporates:
     *  Constant: '<S6>/Constant7'
     */
    rtb_Switch2_lm3u = 10.0F / VbLCCS_touched_new_lane_tmp;

    /* MinMax: '<S6>/MinMax3' incorporates:
     *  UnitDelay: '<S6>/Unit Delay4'
     */
    if ((rtb_Switch2_lm3u < LCCS_subsystem_integrated_DW.UnitDelay4_DSTATE_b0jj)
        || (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay4_DSTATE_b0jj)))
    {
    }
    else
    {
      rtb_Switch2_lm3u = LCCS_subsystem_integrated_DW.UnitDelay4_DSTATE_b0jj;
    }

    /* End of MinMax: '<S6>/MinMax3' */
  }

  /* End of Switch: '<S6>/Switch2' */

  /* Product: '<S6>/Product' incorporates:
   *  Constant: '<S6>/Constant2'
   */
  VfLCCS_left_lanemark_switch_time = rtb_Switch2_lm3u * KfLCCS_t_SampleTime;

  /* Gain: '<S6>/Gain1' incorporates:
   *  Gain: '<S6>/Gain3'
   *  Product: '<S6>/Product4'
   */
  VbLCCS_touched_new_lane_tmp = 0.5F * (VfLCCS_c0_scaling *
    VfLCCS_smoothed_lane_width);

  /* Logic: '<S6>/Logical Operator' incorporates:
   *  Abs: '<S6>/Abs'
   *  Abs: '<S6>/Abs1'
   *  Constant: '<S6>/Constant12'
   *  Constant: '<S6>/Constant13'
   *  Gain: '<S6>/Gain1'
   *  MultiPortSwitch: '<S6>/Multiport Switch1'
   *  MultiPortSwitch: '<S6>/Multiport Switch9'
   *  RelationalOperator: '<S6>/Relational Operator'
   *  RelationalOperator: '<S6>/Relational Operator2'
   *  Sum: '<S6>/Add1'
   *  Sum: '<S6>/Add2'
   *  UnitDelay: '<S6>/Unit Delay'
   *  UnitDelay: '<S6>/Unit Delay5'
   */
  VbLCCS_touched_new_lane = ((((real32_T)fabs((real_T)((real32_T)
    (VaLCCS_virtual_left_lanemark[1 - 1] -
     LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_kfnj)))) >
    VbLCCS_touched_new_lane_tmp) && (((real32_T)fabs((real_T)((real32_T)
    (VaLCCS_virtual_right_lanemark[1 - 1] -
     LCCS_subsystem_integrated_DW.UnitDelay5_DSTATE_n525)))) >
    VbLCCS_touched_new_lane_tmp));

  /* Switch: '<S6>/Switch' incorporates:
   *  Product: '<S24>/Product'
   *  Sum: '<S24>/Sum'
   *  Sum: '<S24>/Sum1'
   */
  if (VbLCCS_touched_new_lane)
  {
    VaLCCS_final_left_lanemark[0] = rtb_Switch2_a5v1;
    VaLCCS_final_left_lanemark[1] = rtb_Switch2_ak2k;
    VaLCCS_final_left_lanemark[2] = rtb_Switch2_galy;
    VaLCCS_final_left_lanemark[3] = rtb_Switch2_f55r;
  }
  else
  {
    /* Lookup_n-D: '<S6>/KtLCCS_k_LanemarkMergeCoef' */
    rtb_Product4 = look1_iflf_binlca(VfLCCS_left_lanemark_switch_time,
      KtLCCS_AXIS_lanemark_switch_time, KtLCCS_k_LanemarkMergeCoef, 20U);

    /* Saturate: '<S6>/Saturation1' */
    if (rtb_Product4 > 1.0F)
    {
      rtb_Product4 = 1.0F;
    }
    else
    {
      if (rtb_Product4 < 0.001F)
      {
        rtb_Product4 = 0.001F;
      }
    }

    /* End of Saturate: '<S6>/Saturation1' */
    VaLCCS_final_left_lanemark[0] = ((rtb_Switch2_a5v1 -
      rtb_final_lanemark_compens_e2pc[0]) * rtb_Product4) +
      rtb_final_lanemark_compens_e2pc[0];
    VaLCCS_final_left_lanemark[1] = ((rtb_Switch2_ak2k -
      rtb_final_lanemark_compens_e2pc[1]) * rtb_Product4) +
      rtb_final_lanemark_compens_e2pc[1];
    VaLCCS_final_left_lanemark[2] = ((rtb_Switch2_galy -
      rtb_final_lanemark_compens_e2pc[2]) * rtb_Product4) +
      rtb_final_lanemark_compens_e2pc[2];
    VaLCCS_final_left_lanemark[3] = ((rtb_Switch2_f55r -
      rtb_final_lanemark_compens_e2pc[3]) * rtb_Product4) +
      rtb_final_lanemark_compens_e2pc[3];
  }

  /* End of Switch: '<S6>/Switch' */

  /* Switch: '<S34>/Switch2' incorporates:
   *  RelationalOperator: '<S34>/Relational Operator11'
   */
  if (rtIsNaNF(VaLCCS_virtual_right_lanemark[0]))
  {
    /* Switch: '<S34>/Switch' incorporates:
     *  Constant: '<S34>/Constant'
     *  RelationalOperator: '<S34>/Relational Operator1'
     *  UnitDelay: '<S34>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_fqzd))
    {
      rtb_Product4 = 0.0F;
    }
    else
    {
      rtb_Product4 = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_fqzd;
    }

    /* End of Switch: '<S34>/Switch' */
  }
  else
  {
    rtb_Product4 = VaLCCS_virtual_right_lanemark[0];
  }

  /* End of Switch: '<S34>/Switch2' */

  /* Switch: '<S35>/Switch2' incorporates:
   *  RelationalOperator: '<S35>/Relational Operator11'
   */
  if (rtIsNaNF(VaLCCS_virtual_right_lanemark[1]))
  {
    /* Switch: '<S35>/Switch' incorporates:
     *  Constant: '<S35>/Constant'
     *  RelationalOperator: '<S35>/Relational Operator1'
     *  UnitDelay: '<S35>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_mur1))
    {
      rtb_Switch2_ipzf = 0.0F;
    }
    else
    {
      rtb_Switch2_ipzf = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_mur1;
    }

    /* End of Switch: '<S35>/Switch' */
  }
  else
  {
    rtb_Switch2_ipzf = VaLCCS_virtual_right_lanemark[1];
  }

  /* End of Switch: '<S35>/Switch2' */

  /* Switch: '<S36>/Switch2' incorporates:
   *  RelationalOperator: '<S36>/Relational Operator11'
   */
  if (rtIsNaNF(VaLCCS_virtual_right_lanemark[2]))
  {
    /* Switch: '<S36>/Switch' incorporates:
     *  Constant: '<S36>/Constant'
     *  RelationalOperator: '<S36>/Relational Operator1'
     *  UnitDelay: '<S36>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_exgu))
    {
      rtb_Switch2_ffxp = 0.0F;
    }
    else
    {
      rtb_Switch2_ffxp = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_exgu;
    }

    /* End of Switch: '<S36>/Switch' */
  }
  else
  {
    rtb_Switch2_ffxp = VaLCCS_virtual_right_lanemark[2];
  }

  /* End of Switch: '<S36>/Switch2' */

  /* Switch: '<S37>/Switch2' incorporates:
   *  RelationalOperator: '<S37>/Relational Operator11'
   */
  if (rtIsNaNF(VaLCCS_virtual_right_lanemark[3]))
  {
    /* Switch: '<S37>/Switch' incorporates:
     *  Constant: '<S37>/Constant'
     *  RelationalOperator: '<S37>/Relational Operator1'
     *  UnitDelay: '<S37>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_fuw4))
    {
      rtb_Switch2_a3lh = 0.0F;
    }
    else
    {
      rtb_Switch2_a3lh = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_fuw4;
    }

    /* End of Switch: '<S37>/Switch' */
  }
  else
  {
    rtb_Switch2_a3lh = VaLCCS_virtual_right_lanemark[3];
  }

  /* End of Switch: '<S37>/Switch2' */

  /* Switch: '<S51>/Switch2' incorporates:
   *  RelationalOperator: '<S51>/Relational Operator11'
   */
  if (rtIsNaNF(rtb_Product3))
  {
    /* Switch: '<S51>/Switch' incorporates:
     *  Constant: '<S51>/Constant'
     *  RelationalOperator: '<S51>/Relational Operator1'
     *  UnitDelay: '<S51>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_phrg))
    {
      rtb_Switch2_or5u = 0.0F;
    }
    else
    {
      rtb_Switch2_or5u = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_phrg;
    }

    /* End of Switch: '<S51>/Switch' */
  }
  else
  {
    rtb_Switch2_or5u = rtb_Product3;
  }

  /* End of Switch: '<S51>/Switch2' */

  /* Switch: '<S49>/Switch2' incorporates:
   *  RelationalOperator: '<S49>/Relational Operator11'
   */
  if (rtIsNaNF(rtb_Product2))
  {
    /* Switch: '<S49>/Switch' incorporates:
     *  Constant: '<S49>/Constant'
     *  RelationalOperator: '<S49>/Relational Operator1'
     *  UnitDelay: '<S49>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_of5p))
    {
      rtb_Switch2_hpiy = 0.0F;
    }
    else
    {
      rtb_Switch2_hpiy = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_of5p;
    }

    /* End of Switch: '<S49>/Switch' */
  }
  else
  {
    rtb_Switch2_hpiy = rtb_Product2;
  }

  /* End of Switch: '<S49>/Switch2' */

  /* Switch: '<S50>/Switch2' incorporates:
   *  RelationalOperator: '<S50>/Relational Operator11'
   *  UnitDelay: '<S6>/Unit Delay3'
   */
  if (rtIsNaNF(VaLCCS_final_right_lanemark[0]))
  {
    /* Switch: '<S50>/Switch' incorporates:
     *  Constant: '<S50>/Constant'
     *  RelationalOperator: '<S50>/Relational Operator1'
     *  UnitDelay: '<S50>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_cmzk))
    {
      rtb_Switch2_bkkd = 0.0F;
    }
    else
    {
      rtb_Switch2_bkkd = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_cmzk;
    }

    /* End of Switch: '<S50>/Switch' */
  }
  else
  {
    rtb_Switch2_bkkd = VaLCCS_final_right_lanemark[0];
  }

  /* End of Switch: '<S50>/Switch2' */

  /* Switch: '<S52>/Switch2' incorporates:
   *  RelationalOperator: '<S52>/Relational Operator11'
   *  UnitDelay: '<S6>/Unit Delay3'
   */
  if (rtIsNaNF(VaLCCS_final_right_lanemark[1]))
  {
    /* Switch: '<S52>/Switch' incorporates:
     *  Constant: '<S52>/Constant'
     *  RelationalOperator: '<S52>/Relational Operator1'
     *  UnitDelay: '<S52>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_l533))
    {
      rtb_Switch2_iup5 = 0.0F;
    }
    else
    {
      rtb_Switch2_iup5 = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_l533;
    }

    /* End of Switch: '<S52>/Switch' */
  }
  else
  {
    rtb_Switch2_iup5 = VaLCCS_final_right_lanemark[1];
  }

  /* End of Switch: '<S52>/Switch2' */

  /* Switch: '<S53>/Switch2' incorporates:
   *  RelationalOperator: '<S53>/Relational Operator11'
   *  UnitDelay: '<S6>/Unit Delay3'
   */
  if (rtIsNaNF(VaLCCS_final_right_lanemark[2]))
  {
    /* Switch: '<S53>/Switch' incorporates:
     *  Constant: '<S53>/Constant'
     *  RelationalOperator: '<S53>/Relational Operator1'
     *  UnitDelay: '<S53>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_h41r))
    {
      rtb_Switch2_dx2w = 0.0F;
    }
    else
    {
      rtb_Switch2_dx2w = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_h41r;
    }

    /* End of Switch: '<S53>/Switch' */
  }
  else
  {
    rtb_Switch2_dx2w = VaLCCS_final_right_lanemark[2];
  }

  /* End of Switch: '<S53>/Switch2' */

  /* Switch: '<S54>/Switch2' incorporates:
   *  RelationalOperator: '<S54>/Relational Operator11'
   *  UnitDelay: '<S6>/Unit Delay3'
   */
  if (rtIsNaNF(VaLCCS_final_right_lanemark[3]))
  {
    /* Switch: '<S54>/Switch' incorporates:
     *  Constant: '<S54>/Constant'
     *  RelationalOperator: '<S54>/Relational Operator1'
     *  UnitDelay: '<S54>/Unit Delay'
     */
    if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_khns))
    {
      rtb_Switch2_iz1e = 0.0F;
    }
    else
    {
      rtb_Switch2_iz1e = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_khns;
    }

    /* End of Switch: '<S54>/Switch' */
  }
  else
  {
    rtb_Switch2_iz1e = VaLCCS_final_right_lanemark[3];
  }

  /* End of Switch: '<S54>/Switch2' */

  /* MATLAB Function: '<S33>/kinematic_compensation' */
  LCCS_sub_kinematic_compensation(rtb_Switch2_or5u, rtb_Switch2_hpiy,
    rtb_Switch2_bkkd, rtb_Switch2_iup5, rtb_Switch2_dx2w, rtb_Switch2_iz1e,
    rtb_final_lanemark_compensated);

  /* Switch: '<S6>/Switch1' incorporates:
   *  Constant: '<S6>/Constant3'
   *  Constant: '<S6>/Constant4'
   *  Constant: '<S6>/Constant8'
   *  MinMax: '<S6>/MinMax2'
   *  RelationalOperator: '<S26>/FixPt Relational Operator'
   *  UnitDelay: '<S26>/Delay Input1'
   *
   * Block description for '<S26>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (VbLCCS_right_lanemark_valid !=
      LCCS_subsystem_integrated_DW.DelayInput1_DSTATE_kn4x)
  {
    rtb_Product3 = 0.0F;
  }
  else
  {
    if ((KfLCCS_t_SampleTime > 0.01F) || (rtIsNaNF(0.01F)))
    {
      /* MinMax: '<S6>/MinMax2' incorporates:
       *  Constant: '<S6>/Constant4'
       */
      VbLCCS_touched_new_lane_tmp = KfLCCS_t_SampleTime;
    }
    else
    {
      /* MinMax: '<S6>/MinMax2' incorporates:
       *  Constant: '<S6>/Constant8'
       */
      VbLCCS_touched_new_lane_tmp = 0.01F;
    }

    /* Product: '<S6>/Divide1' incorporates:
     *  Constant: '<S6>/Constant9'
     */
    rtb_Product3 = 10.0F / VbLCCS_touched_new_lane_tmp;

    /* MinMax: '<S6>/MinMax1' incorporates:
     *  UnitDelay: '<S6>/Unit Delay1'
     */
    if ((rtb_Product3 < LCCS_subsystem_integrated_DW.UnitDelay1_DSTATE_oid4) ||
        (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay1_DSTATE_oid4)))
    {
    }
    else
    {
      rtb_Product3 = LCCS_subsystem_integrated_DW.UnitDelay1_DSTATE_oid4;
    }

    /* End of MinMax: '<S6>/MinMax1' */
  }

  /* End of Switch: '<S6>/Switch1' */

  /* Product: '<S6>/Product1' incorporates:
   *  Constant: '<S6>/Constant5'
   */
  VfLCCS_right_lanemark_switch_time = rtb_Product3 * KfLCCS_t_SampleTime;

  /* Switch: '<S6>/Switch3' incorporates:
   *  Product: '<S25>/Product'
   *  Sum: '<S25>/Sum'
   *  Sum: '<S25>/Sum1'
   */
  if (VbLCCS_touched_new_lane)
  {
    VaLCCS_final_right_lanemark[0] = rtb_Product4;
    VaLCCS_final_right_lanemark[1] = rtb_Switch2_ipzf;
    VaLCCS_final_right_lanemark[2] = rtb_Switch2_ffxp;
    VaLCCS_final_right_lanemark[3] = rtb_Switch2_a3lh;
  }
  else
  {
    /* Lookup_n-D: '<S6>/KtLCCS_k_LanemarkMergeCoef1' */
    rtb_Product2 = look1_iflf_binlca(VfLCCS_right_lanemark_switch_time,
      KtLCCS_AXIS_lanemark_switch_time, KtLCCS_k_LanemarkMergeCoef, 20U);

    /* Saturate: '<S6>/Saturation' */
    if (rtb_Product2 > 1.0F)
    {
      rtb_Product2 = 1.0F;
    }
    else
    {
      if (rtb_Product2 < 0.001F)
      {
        rtb_Product2 = 0.001F;
      }
    }

    /* End of Saturate: '<S6>/Saturation' */
    VaLCCS_final_right_lanemark[0] = ((rtb_Product4 -
      rtb_final_lanemark_compensated[0]) * rtb_Product2) +
      rtb_final_lanemark_compensated[0];
    VaLCCS_final_right_lanemark[1] = ((rtb_Switch2_ipzf -
      rtb_final_lanemark_compensated[1]) * rtb_Product2) +
      rtb_final_lanemark_compensated[1];
    VaLCCS_final_right_lanemark[2] = ((rtb_Switch2_ffxp -
      rtb_final_lanemark_compensated[2]) * rtb_Product2) +
      rtb_final_lanemark_compensated[2];
    VaLCCS_final_right_lanemark[3] = ((rtb_Switch2_a3lh -
      rtb_final_lanemark_compensated[3]) * rtb_Product2) +
      rtb_final_lanemark_compensated[3];
  }

  /* End of Switch: '<S6>/Switch3' */

  /* Gain: '<S6>/Gain' incorporates:
   *  Sum: '<S6>/Add'
   */
  VaLCCS_raw_lane_center_line[0] = 0.5F * (VaLCCS_final_left_lanemark[0] +
    VaLCCS_final_right_lanemark[0]);
  VaLCCS_raw_lane_center_line[1] = 0.5F * (VaLCCS_final_left_lanemark[1] +
    VaLCCS_final_right_lanemark[1]);
  VaLCCS_raw_lane_center_line[2] = 0.5F * (VaLCCS_final_left_lanemark[2] +
    VaLCCS_final_right_lanemark[2]);
  VaLCCS_raw_lane_center_line[3] = 0.5F * (VaLCCS_final_left_lanemark[3] +
    VaLCCS_final_right_lanemark[3]);

  /* Update for UnitDelay: '<S44>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_eoiv = rtb_Switch2;

  /* Update for UnitDelay: '<S42>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_navt = rtb_Switch2_kemu;

  /* Update for UnitDelay: '<S43>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_o5zn = rtb_Switch2_dor5;

  /* Update for UnitDelay: '<S45>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_jjbb = rtb_Switch2_k3ke;

  /* Update for UnitDelay: '<S46>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_hi5n = rtb_Switch2_fzvi;

  /* Update for UnitDelay: '<S47>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_ctwe = rtb_Switch2_djco;

  /* Update for UnitDelay: '<S38>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_bazq = rtb_Switch2_a5v1;

  /* Update for UnitDelay: '<S39>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_o3lq = rtb_Switch2_ak2k;

  /* Update for UnitDelay: '<S40>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_ht0x = rtb_Switch2_galy;

  /* Update for UnitDelay: '<S41>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_bxva = rtb_Switch2_f55r;

  /* Update for UnitDelay: '<S27>/Delay Input1'
   *
   * Block description for '<S27>/Delay Input1':
   *
   *  Store in Global RAM
   */
  LCCS_subsystem_integrated_DW.DelayInput1_DSTATE = VbLCCS_left_lanemark_valid;

  /* Update for UnitDelay: '<S6>/Unit Delay4' incorporates:
   *  Constant: '<S29>/FixPt Constant'
   *  Sum: '<S29>/FixPt Sum1'
   */
  LCCS_subsystem_integrated_DW.UnitDelay4_DSTATE_b0jj = rtb_Switch2_lm3u + 1.0F;

  /* Update for UnitDelay: '<S6>/Unit Delay' incorporates:
   *  Constant: '<S6>/Constant12'
   *  MultiPortSwitch: '<S6>/Multiport Switch9'
   */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_kfnj =
    VaLCCS_virtual_left_lanemark[1 - 1];

  /* Update for UnitDelay: '<S6>/Unit Delay5' incorporates:
   *  Constant: '<S6>/Constant13'
   *  MultiPortSwitch: '<S6>/Multiport Switch1'
   */
  LCCS_subsystem_integrated_DW.UnitDelay5_DSTATE_n525 =
    VaLCCS_virtual_right_lanemark[1 - 1];

  /* Update for UnitDelay: '<S34>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_fqzd = rtb_Product4;

  /* Update for UnitDelay: '<S35>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_mur1 = rtb_Switch2_ipzf;

  /* Update for UnitDelay: '<S36>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_exgu = rtb_Switch2_ffxp;

  /* Update for UnitDelay: '<S37>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_fuw4 = rtb_Switch2_a3lh;

  /* Update for UnitDelay: '<S51>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_phrg = rtb_Switch2_or5u;

  /* Update for UnitDelay: '<S49>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_of5p = rtb_Switch2_hpiy;

  /* Update for UnitDelay: '<S50>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_cmzk = rtb_Switch2_bkkd;

  /* Update for UnitDelay: '<S52>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_l533 = rtb_Switch2_iup5;

  /* Update for UnitDelay: '<S53>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_h41r = rtb_Switch2_dx2w;

  /* Update for UnitDelay: '<S54>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_khns = rtb_Switch2_iz1e;

  /* Update for UnitDelay: '<S26>/Delay Input1'
   *
   * Block description for '<S26>/Delay Input1':
   *
   *  Store in Global RAM
   */
  LCCS_subsystem_integrated_DW.DelayInput1_DSTATE_kn4x =
    VbLCCS_right_lanemark_valid;

  /* Update for UnitDelay: '<S6>/Unit Delay1' incorporates:
   *  Constant: '<S28>/FixPt Constant'
   *  Sum: '<S28>/FixPt Sum1'
   */
  LCCS_subsystem_integrated_DW.UnitDelay1_DSTATE_oid4 = rtb_Product3 + 1.0F;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
