/*
 * File: lccs_signal_processing.c
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

#include "lccs_signal_processing.h"

/* Include model header file for global data */
#include "LCCS_subsystem_integrated.h"
#include "LCCS_subsystem_integrated_private.h"
#include "look2_iflf_binlca.h"

/* System initialize for atomic system: '<S2>/DtrmnLCCS_sensor_signal_processing' */
void DtrmnLCCS_sensor_signal_pr_Init(void)
{
  /* SystemInitialize for Iterator SubSystem: '<S10>/search_right_lanemark' */
  /* SystemInitialize for Enabled SubSystem: '<S114>/Enabled Subsystem2' */
  /* SystemInitialize for Outport: '<S129>/right_lanemark_index' */
  LCCS_subsystem_integrated_B.lanemark_index = (-1);

  /* End of SystemInitialize for SubSystem: '<S114>/Enabled Subsystem2' */
  /* End of SystemInitialize for SubSystem: '<S10>/search_right_lanemark' */

  /* SystemInitialize for Iterator SubSystem: '<S10>/search_left_lanemark' */
  /* SystemInitialize for Enabled SubSystem: '<S113>/Enabled Subsystem2' */
  /* SystemInitialize for Outport: '<S127>/left_lanemark_index' */
  LCCS_subsystem_integrated_B.lanemark_index_i2on = (-1);

  /* End of SystemInitialize for SubSystem: '<S113>/Enabled Subsystem2' */
  /* End of SystemInitialize for SubSystem: '<S10>/search_left_lanemark' */
}

/* Output and update for atomic system: '<S2>/DtrmnLCCS_sensor_signal_processing' */
void DtrmnLCCS_sensor_signal_process(void)
{
  int32_T s114_iter;
  boolean_T rtb_Compare_muwp;
  boolean_T rtb_RelationalOperator11_glkh;
  boolean_T rtb_RelationalOperator11_hg4m;
  boolean_T rtb_RelationalOperator11_fg1h;
  boolean_T rtb_RelationalOperator11_o3su;
  boolean_T rtb_RelationalOperator11_hgea;
  real32_T rtb_Switch2;
  real32_T rtb_Switch2_fpqt;
  real32_T rtb_Switch2_b1ai;
  real32_T rtb_Switch2_p3pt;
  real32_T rtb_Switch2_idx5;
  real_T tmp;

  /* Sum: '<S10>/Add2' incorporates:
   *  Abs: '<S10>/Abs'
   *  Constant: '<S10>/wheel_base'
   *  Lookup_n-D: '<S10>/KtLCCS_d_lookahead_distance'
   */
  VfLCCS_lookahead_distance = look2_iflf_binlca((real32_T)fabs((real_T)
    LCCS_subsystem_integrated_B.Add1), VfLCCS_linear_velocity,
    KtLCCS_AXIS_route_curvature, KtLCCS_AXIS_vehicle_speed,
    KtLCCS_d_lookahead_distance,
    LCCS_subsystem_integrate_ConstP.KtLCCS_d_lookahead_distance_max, 5U) +
    KfLCCS_d_wheel_base;

  /* Product: '<S10>/Product' incorporates:
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S10>/Constant2'
   *  Sum: '<S10>/Add'
   */
  VfLCCS_veh_frtwhl_angle_act = (VfLCCS_EPS_ActualSteeringAngle -
    KfLCCS_Ang_steering_center_position) / KfLCCS_r_veh_strwhl_2_frtwhl_ratio;

  /* Switch: '<S10>/Switch11' incorporates:
   *  Constant: '<S10>/Constant10'
   *  Constant: '<S10>/Constant9'
   *  Inport: '<Root>/VsMPFU_DataBus'
   */
  if (VsMPFU_DataBus.timestamp_low > 0U)
  {
    tmp = 1.0;
  }
  else
  {
    tmp = (-1.0);
  }

  /* End of Switch: '<S10>/Switch11' */

  /* Sum: '<S10>/Add1' incorporates:
   *  Constant: '<S10>/Constant15'
   *  Gain: '<S10>/Gain1'
   *  Inport: '<Root>/VsMPFU_DataBus'
   *  Product: '<S10>/Product2'
   *  Product: '<S10>/Product3'
   */
  VfLCCS_timestamp_MPFU = (((((real_T)1125899907) * 8.8817841970012523E-16) *
    ((real_T)VsMPFU_DataBus.timestamp_high)) * tmp) + (4294.967296 * ((real_T)
    VsMPFU_DataBus.timestamp_low));

  /* Outputs for Iterator SubSystem: '<S10>/search_right_lanemark' incorporates:
   *  WhileIterator: '<S114>/While Iterator'
   */
  s114_iter = 1;
  do
  {
    rtb_Compare_muwp = (VsMPFU_DataBus.lane_markers[s114_iter - 1].id == 2);
    if (rtb_Compare_muwp)
    {
      if (!LCCS_subsystem_integrated_DW.EnabledSubsystem2_MODE)
      {
        LCCS_subsystem_integrated_DW.EnabledSubsystem2_MODE = true;
      }

      LCCS_subsystem_integrated_B.lanemark_index = s114_iter;
    }
    else
    {
      if (LCCS_subsystem_integrated_DW.EnabledSubsystem2_MODE)
      {
        LCCS_subsystem_integrated_B.lanemark_index = (-1);
        LCCS_subsystem_integrated_DW.EnabledSubsystem2_MODE = false;
      }
    }

    s114_iter++;
  }
  while ((!rtb_Compare_muwp) && (s114_iter <= 16));

  /* End of Outputs for SubSystem: '<S10>/search_right_lanemark' */

  /* Switch: '<S108>/Switch2' incorporates:
   *  Inport: '<Root>/VsMPFU_DataBus'
   */
  VfLCCS_num_lane_markers = VsMPFU_DataBus.num_lane_markers;

  /* If: '<S10>/If1' incorporates:
   *  Constant: '<S104>/Constant'
   *  Constant: '<S106>/Constant'
   *  Logic: '<S10>/Logical Operator1'
   *  RelationalOperator: '<S104>/Compare'
   *  RelationalOperator: '<S106>/Compare'
   */
  if ((LCCS_subsystem_integrated_B.lanemark_index > 0) &&
      (VfLCCS_num_lane_markers > ((uint8_T)0U)))
  {
    /* Outputs for IfAction SubSystem: '<S10>/received_right_lanemark' incorporates:
     *  ActionPort: '<S112>/Action Port'
     */
    /* RelationalOperator: '<S121>/Relational Operator11' incorporates:
     *  Inport: '<Root>/VsMPFU_DataBus'
     *  Selector: '<S112>/Selector'
     */
    rtb_Compare_muwp = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[LCCS_subsystem_integrated_B.lanemark_index -
       1].c0_position);

    /* Switch: '<S121>/Switch2' incorporates:
     *  Inport: '<Root>/VsMPFU_DataBus'
     *  Selector: '<S112>/Selector'
     */
    if (rtb_Compare_muwp)
    {
      /* Switch: '<S121>/Switch' incorporates:
       *  Constant: '<S121>/Constant'
       *  RelationalOperator: '<S121>/Relational Operator1'
       *  UnitDelay: '<S121>/Unit Delay'
       */
      if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_pmqa))
      {
        rtb_Switch2 = 0.0F;
      }
      else
      {
        rtb_Switch2 = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_pmqa;
      }

      /* End of Switch: '<S121>/Switch' */
    }
    else
    {
      rtb_Switch2 =
        VsMPFU_DataBus.lane_markers[LCCS_subsystem_integrated_B.lanemark_index -
        1].c0_position;
    }

    /* End of Switch: '<S121>/Switch2' */

    /* RelationalOperator: '<S123>/Relational Operator11' incorporates:
     *  Inport: '<Root>/VsMPFU_DataBus'
     *  Selector: '<S112>/Selector'
     */
    rtb_RelationalOperator11_glkh = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[LCCS_subsystem_integrated_B.lanemark_index -
       1].c1_heading);

    /* Switch: '<S123>/Switch2' incorporates:
     *  Inport: '<Root>/VsMPFU_DataBus'
     *  Selector: '<S112>/Selector'
     */
    if (rtb_RelationalOperator11_glkh)
    {
      /* Switch: '<S123>/Switch' incorporates:
       *  Constant: '<S123>/Constant'
       *  RelationalOperator: '<S123>/Relational Operator1'
       *  UnitDelay: '<S123>/Unit Delay'
       */
      if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_ft2i))
      {
        rtb_Switch2_fpqt = 0.0F;
      }
      else
      {
        rtb_Switch2_fpqt = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_ft2i;
      }

      /* End of Switch: '<S123>/Switch' */
    }
    else
    {
      rtb_Switch2_fpqt =
        VsMPFU_DataBus.lane_markers[LCCS_subsystem_integrated_B.lanemark_index -
        1].c1_heading;
    }

    /* End of Switch: '<S123>/Switch2' */

    /* RelationalOperator: '<S124>/Relational Operator11' incorporates:
     *  Inport: '<Root>/VsMPFU_DataBus'
     *  Selector: '<S112>/Selector'
     */
    rtb_RelationalOperator11_hg4m = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[LCCS_subsystem_integrated_B.lanemark_index -
       1].c2_curvature);

    /* Switch: '<S124>/Switch2' incorporates:
     *  Inport: '<Root>/VsMPFU_DataBus'
     *  Selector: '<S112>/Selector'
     */
    if (rtb_RelationalOperator11_hg4m)
    {
      /* Switch: '<S124>/Switch' incorporates:
       *  Constant: '<S124>/Constant'
       *  RelationalOperator: '<S124>/Relational Operator1'
       *  UnitDelay: '<S124>/Unit Delay'
       */
      if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_aayl))
      {
        rtb_Switch2_b1ai = 0.0F;
      }
      else
      {
        rtb_Switch2_b1ai = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_aayl;
      }

      /* End of Switch: '<S124>/Switch' */
    }
    else
    {
      rtb_Switch2_b1ai =
        VsMPFU_DataBus.lane_markers[LCCS_subsystem_integrated_B.lanemark_index -
        1].c2_curvature;
    }

    /* End of Switch: '<S124>/Switch2' */

    /* RelationalOperator: '<S125>/Relational Operator11' incorporates:
     *  Inport: '<Root>/VsMPFU_DataBus'
     *  Selector: '<S112>/Selector'
     */
    rtb_RelationalOperator11_fg1h = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[LCCS_subsystem_integrated_B.lanemark_index -
       1].c3_curvature_derivative);

    /* Switch: '<S125>/Switch2' incorporates:
     *  Inport: '<Root>/VsMPFU_DataBus'
     *  Selector: '<S112>/Selector'
     */
    if (rtb_RelationalOperator11_fg1h)
    {
      /* Switch: '<S125>/Switch' incorporates:
       *  Constant: '<S125>/Constant'
       *  RelationalOperator: '<S125>/Relational Operator1'
       *  UnitDelay: '<S125>/Unit Delay'
       */
      if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_bcwo))
      {
        rtb_Switch2_p3pt = 0.0F;
      }
      else
      {
        rtb_Switch2_p3pt = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_bcwo;
      }

      /* End of Switch: '<S125>/Switch' */
    }
    else
    {
      rtb_Switch2_p3pt =
        VsMPFU_DataBus.lane_markers[LCCS_subsystem_integrated_B.lanemark_index -
        1].c3_curvature_derivative;
    }

    /* End of Switch: '<S125>/Switch2' */

    /* RelationalOperator: '<S126>/Relational Operator11' incorporates:
     *  Inport: '<Root>/VsMPFU_DataBus'
     *  Selector: '<S112>/Selector'
     */
    rtb_RelationalOperator11_o3su = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[LCCS_subsystem_integrated_B.lanemark_index -
       1].distance_to_host);

    /* Switch: '<S126>/Switch2' incorporates:
     *  Inport: '<Root>/VsMPFU_DataBus'
     *  Selector: '<S112>/Selector'
     */
    if (rtb_RelationalOperator11_o3su)
    {
      /* Switch: '<S126>/Switch' incorporates:
       *  Constant: '<S126>/Constant'
       *  RelationalOperator: '<S126>/Relational Operator1'
       *  UnitDelay: '<S126>/Unit Delay'
       */
      if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_g4ms))
      {
        rtb_Switch2_idx5 = 0.0F;
      }
      else
      {
        rtb_Switch2_idx5 = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_g4ms;
      }

      /* End of Switch: '<S126>/Switch' */
    }
    else
    {
      rtb_Switch2_idx5 =
        VsMPFU_DataBus.lane_markers[LCCS_subsystem_integrated_B.lanemark_index -
        1].distance_to_host;
    }

    /* End of Switch: '<S126>/Switch2' */

    /* SignalConversion: '<S112>/OutportBufferForraw_right_lanemark' incorporates:
     *  DataTypeConversion: '<S112>/Data Type Conversion'
     *  Inport: '<Root>/VsMPFU_DataBus'
     *  Selector: '<S112>/Selector'
     */
    VaLCCS_raw_right_lanemark[0] = (real32_T)
      VsMPFU_DataBus.lane_markers[LCCS_subsystem_integrated_B.lanemark_index - 1]
      .quality;
    VaLCCS_raw_right_lanemark[1] = rtb_Switch2;
    VaLCCS_raw_right_lanemark[2] = rtb_Switch2_fpqt;
    VaLCCS_raw_right_lanemark[3] = rtb_Switch2_b1ai;
    VaLCCS_raw_right_lanemark[4] = rtb_Switch2_p3pt;
    VaLCCS_raw_right_lanemark[5] = rtb_Switch2_idx5;

    /* Logic: '<S112>/Logical Operator' */
    rtb_Compare_muwp = ((((rtb_Compare_muwp || rtb_RelationalOperator11_glkh) ||
                          rtb_RelationalOperator11_hg4m) ||
                         rtb_RelationalOperator11_fg1h) ||
                        rtb_RelationalOperator11_o3su);

    /* Update for UnitDelay: '<S121>/Unit Delay' */
    LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_pmqa = rtb_Switch2;

    /* Update for UnitDelay: '<S123>/Unit Delay' */
    LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_ft2i = rtb_Switch2_fpqt;

    /* Update for UnitDelay: '<S124>/Unit Delay' */
    LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_aayl = rtb_Switch2_b1ai;

    /* Update for UnitDelay: '<S125>/Unit Delay' */
    LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_bcwo = rtb_Switch2_p3pt;

    /* Update for UnitDelay: '<S126>/Unit Delay' */
    LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_g4ms = rtb_Switch2_idx5;

    /* End of Outputs for SubSystem: '<S10>/received_right_lanemark' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S10>/default_right_lanemark' incorporates:
     *  ActionPort: '<S110>/Action Port'
     */
    /* SignalConversion: '<S110>/OutportBufferForraw_right_lanemark' incorporates:
     *  Constant: '<S110>/Constant1'
     *  Constant: '<S110>/Constant2'
     *  Constant: '<S110>/Constant3'
     *  Constant: '<S110>/Constant4'
     *  Constant: '<S110>/Constant5'
     *  Constant: '<S110>/Constant6'
     */
    VaLCCS_raw_right_lanemark[0] = 0.0F;
    VaLCCS_raw_right_lanemark[1] = (-1.5F);
    VaLCCS_raw_right_lanemark[2] = 0.0F;
    VaLCCS_raw_right_lanemark[3] = 0.0F;
    VaLCCS_raw_right_lanemark[4] = 0.0F;
    VaLCCS_raw_right_lanemark[5] = (-1.5F);

    /* SignalConversion: '<S110>/OutportBufferForright_lanemark_isNaN' incorporates:
     *  Constant: '<S110>/Constant7'
     */
    rtb_Compare_muwp = false;

    /* End of Outputs for SubSystem: '<S10>/default_right_lanemark' */
  }

  /* End of If: '<S10>/If1' */

  /* Outputs for Iterator SubSystem: '<S10>/search_left_lanemark' incorporates:
   *  WhileIterator: '<S113>/While Iterator'
   */
  s114_iter = 1;
  do
  {
    rtb_RelationalOperator11_glkh = (VsMPFU_DataBus.lane_markers[s114_iter - 1].
      id == 1);
    if (rtb_RelationalOperator11_glkh)
    {
      if (!LCCS_subsystem_integrated_DW.EnabledSubsystem2_MODE_bijq)
      {
        LCCS_subsystem_integrated_DW.EnabledSubsystem2_MODE_bijq = true;
      }

      LCCS_subsystem_integrated_B.lanemark_index_i2on = s114_iter;
    }
    else
    {
      if (LCCS_subsystem_integrated_DW.EnabledSubsystem2_MODE_bijq)
      {
        LCCS_subsystem_integrated_B.lanemark_index_i2on = (-1);
        LCCS_subsystem_integrated_DW.EnabledSubsystem2_MODE_bijq = false;
      }
    }

    s114_iter++;
  }
  while ((!rtb_RelationalOperator11_glkh) && (s114_iter <= 16));

  /* End of Outputs for SubSystem: '<S10>/search_left_lanemark' */

  /* If: '<S10>/If' incorporates:
   *  Constant: '<S105>/Constant'
   *  Constant: '<S107>/Constant'
   *  Logic: '<S10>/Logical Operator2'
   *  RelationalOperator: '<S105>/Compare'
   *  RelationalOperator: '<S107>/Compare'
   */
  if ((LCCS_subsystem_integrated_B.lanemark_index_i2on > 0) &&
      (VfLCCS_num_lane_markers > ((uint8_T)0U)))
  {
    /* Outputs for IfAction SubSystem: '<S10>/received_left_lanemark' incorporates:
     *  ActionPort: '<S111>/Action Port'
     */
    /* RelationalOperator: '<S115>/Relational Operator11' incorporates:
     *  Inport: '<Root>/VsMPFU_DataBus'
     *  Selector: '<S111>/Selector'
     */
    rtb_RelationalOperator11_glkh = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[LCCS_subsystem_integrated_B.lanemark_index_i2on
       - 1].c0_position);

    /* Switch: '<S115>/Switch2' incorporates:
     *  Inport: '<Root>/VsMPFU_DataBus'
     *  Selector: '<S111>/Selector'
     */
    if (rtb_RelationalOperator11_glkh)
    {
      /* Switch: '<S115>/Switch' incorporates:
       *  Constant: '<S115>/Constant'
       *  RelationalOperator: '<S115>/Relational Operator1'
       *  UnitDelay: '<S115>/Unit Delay'
       */
      if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_ppsl))
      {
        rtb_Switch2 = 0.0F;
      }
      else
      {
        rtb_Switch2 = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_ppsl;
      }

      /* End of Switch: '<S115>/Switch' */
    }
    else
    {
      rtb_Switch2 =
        VsMPFU_DataBus.lane_markers[LCCS_subsystem_integrated_B.lanemark_index_i2on
        - 1].c0_position;
    }

    /* End of Switch: '<S115>/Switch2' */

    /* RelationalOperator: '<S117>/Relational Operator11' incorporates:
     *  Inport: '<Root>/VsMPFU_DataBus'
     *  Selector: '<S111>/Selector'
     */
    rtb_RelationalOperator11_hg4m = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[LCCS_subsystem_integrated_B.lanemark_index_i2on
       - 1].c1_heading);

    /* Switch: '<S117>/Switch2' incorporates:
     *  Inport: '<Root>/VsMPFU_DataBus'
     *  Selector: '<S111>/Selector'
     */
    if (rtb_RelationalOperator11_hg4m)
    {
      /* Switch: '<S117>/Switch' incorporates:
       *  Constant: '<S117>/Constant'
       *  RelationalOperator: '<S117>/Relational Operator1'
       *  UnitDelay: '<S117>/Unit Delay'
       */
      if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_cuw4))
      {
        rtb_Switch2_fpqt = 0.0F;
      }
      else
      {
        rtb_Switch2_fpqt = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_cuw4;
      }

      /* End of Switch: '<S117>/Switch' */
    }
    else
    {
      rtb_Switch2_fpqt =
        VsMPFU_DataBus.lane_markers[LCCS_subsystem_integrated_B.lanemark_index_i2on
        - 1].c1_heading;
    }

    /* End of Switch: '<S117>/Switch2' */

    /* RelationalOperator: '<S118>/Relational Operator11' incorporates:
     *  Inport: '<Root>/VsMPFU_DataBus'
     *  Selector: '<S111>/Selector'
     */
    rtb_RelationalOperator11_fg1h = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[LCCS_subsystem_integrated_B.lanemark_index_i2on
       - 1].c2_curvature);

    /* Switch: '<S118>/Switch2' incorporates:
     *  Inport: '<Root>/VsMPFU_DataBus'
     *  Selector: '<S111>/Selector'
     */
    if (rtb_RelationalOperator11_fg1h)
    {
      /* Switch: '<S118>/Switch' incorporates:
       *  Constant: '<S118>/Constant'
       *  RelationalOperator: '<S118>/Relational Operator1'
       *  UnitDelay: '<S118>/Unit Delay'
       */
      if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_labs))
      {
        rtb_Switch2_b1ai = 0.0F;
      }
      else
      {
        rtb_Switch2_b1ai = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_labs;
      }

      /* End of Switch: '<S118>/Switch' */
    }
    else
    {
      rtb_Switch2_b1ai =
        VsMPFU_DataBus.lane_markers[LCCS_subsystem_integrated_B.lanemark_index_i2on
        - 1].c2_curvature;
    }

    /* End of Switch: '<S118>/Switch2' */

    /* RelationalOperator: '<S119>/Relational Operator11' incorporates:
     *  Inport: '<Root>/VsMPFU_DataBus'
     *  Selector: '<S111>/Selector'
     */
    rtb_RelationalOperator11_o3su = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[LCCS_subsystem_integrated_B.lanemark_index_i2on
       - 1].c3_curvature_derivative);

    /* Switch: '<S119>/Switch2' incorporates:
     *  Inport: '<Root>/VsMPFU_DataBus'
     *  Selector: '<S111>/Selector'
     */
    if (rtb_RelationalOperator11_o3su)
    {
      /* Switch: '<S119>/Switch' incorporates:
       *  Constant: '<S119>/Constant'
       *  RelationalOperator: '<S119>/Relational Operator1'
       *  UnitDelay: '<S119>/Unit Delay'
       */
      if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_a3c0))
      {
        rtb_Switch2_p3pt = 0.0F;
      }
      else
      {
        rtb_Switch2_p3pt = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_a3c0;
      }

      /* End of Switch: '<S119>/Switch' */
    }
    else
    {
      rtb_Switch2_p3pt =
        VsMPFU_DataBus.lane_markers[LCCS_subsystem_integrated_B.lanemark_index_i2on
        - 1].c3_curvature_derivative;
    }

    /* End of Switch: '<S119>/Switch2' */

    /* RelationalOperator: '<S120>/Relational Operator11' incorporates:
     *  Inport: '<Root>/VsMPFU_DataBus'
     *  Selector: '<S111>/Selector'
     */
    rtb_RelationalOperator11_hgea = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[LCCS_subsystem_integrated_B.lanemark_index_i2on
       - 1].distance_to_host);

    /* Switch: '<S120>/Switch2' incorporates:
     *  Inport: '<Root>/VsMPFU_DataBus'
     *  Selector: '<S111>/Selector'
     */
    if (rtb_RelationalOperator11_hgea)
    {
      /* Switch: '<S120>/Switch' incorporates:
       *  Constant: '<S120>/Constant'
       *  RelationalOperator: '<S120>/Relational Operator1'
       *  UnitDelay: '<S120>/Unit Delay'
       */
      if (rtIsNaNF(LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_mobc))
      {
        rtb_Switch2_idx5 = 0.0F;
      }
      else
      {
        rtb_Switch2_idx5 = LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_mobc;
      }

      /* End of Switch: '<S120>/Switch' */
    }
    else
    {
      rtb_Switch2_idx5 =
        VsMPFU_DataBus.lane_markers[LCCS_subsystem_integrated_B.lanemark_index_i2on
        - 1].distance_to_host;
    }

    /* End of Switch: '<S120>/Switch2' */

    /* SignalConversion: '<S111>/OutportBufferForraw_left_lanemark' incorporates:
     *  DataTypeConversion: '<S111>/Data Type Conversion'
     *  Inport: '<Root>/VsMPFU_DataBus'
     *  Selector: '<S111>/Selector'
     */
    VaLCCS_raw_left_lanemark[0] = (real32_T)
      VsMPFU_DataBus.lane_markers[LCCS_subsystem_integrated_B.lanemark_index_i2on
      - 1].quality;
    VaLCCS_raw_left_lanemark[1] = rtb_Switch2;
    VaLCCS_raw_left_lanemark[2] = rtb_Switch2_fpqt;
    VaLCCS_raw_left_lanemark[3] = rtb_Switch2_b1ai;
    VaLCCS_raw_left_lanemark[4] = rtb_Switch2_p3pt;
    VaLCCS_raw_left_lanemark[5] = rtb_Switch2_idx5;

    /* Logic: '<S111>/Logical Operator' */
    rtb_RelationalOperator11_glkh = ((((rtb_RelationalOperator11_glkh ||
      rtb_RelationalOperator11_hg4m) || rtb_RelationalOperator11_fg1h) ||
      rtb_RelationalOperator11_o3su) || rtb_RelationalOperator11_hgea);

    /* Update for UnitDelay: '<S115>/Unit Delay' */
    LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_ppsl = rtb_Switch2;

    /* Update for UnitDelay: '<S117>/Unit Delay' */
    LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_cuw4 = rtb_Switch2_fpqt;

    /* Update for UnitDelay: '<S118>/Unit Delay' */
    LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_labs = rtb_Switch2_b1ai;

    /* Update for UnitDelay: '<S119>/Unit Delay' */
    LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_a3c0 = rtb_Switch2_p3pt;

    /* Update for UnitDelay: '<S120>/Unit Delay' */
    LCCS_subsystem_integrated_DW.UnitDelay_DSTATE_mobc = rtb_Switch2_idx5;

    /* End of Outputs for SubSystem: '<S10>/received_left_lanemark' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S10>/default_left_lanemark' incorporates:
     *  ActionPort: '<S109>/Action Port'
     */
    /* SignalConversion: '<S109>/OutportBufferForraw_left_lanemark' incorporates:
     *  Constant: '<S109>/Constant1'
     *  Constant: '<S109>/Constant2'
     *  Constant: '<S109>/Constant3'
     *  Constant: '<S109>/Constant4'
     *  Constant: '<S109>/Constant5'
     *  Constant: '<S109>/Constant6'
     */
    VaLCCS_raw_left_lanemark[0] = 0.0F;
    VaLCCS_raw_left_lanemark[1] = 1.5F;
    VaLCCS_raw_left_lanemark[2] = 0.0F;
    VaLCCS_raw_left_lanemark[3] = 0.0F;
    VaLCCS_raw_left_lanemark[4] = 0.0F;
    VaLCCS_raw_left_lanemark[5] = 1.5F;

    /* SignalConversion: '<S109>/OutportBufferForleft_lanemark_isNaN' incorporates:
     *  Constant: '<S109>/Constant7'
     */
    rtb_RelationalOperator11_glkh = false;

    /* End of Outputs for SubSystem: '<S10>/default_left_lanemark' */
  }

  /* End of If: '<S10>/If' */

  /* Logic: '<S10>/Logical Operator3' */
  VbLCCS_input_isNaN_MPFU = (rtb_RelationalOperator11_glkh || rtb_Compare_muwp);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
