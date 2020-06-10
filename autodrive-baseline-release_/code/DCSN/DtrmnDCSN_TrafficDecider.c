/*
 * File: DtrmnDCSN_TrafficDecider.c
 *
 * Code generated for Simulink model 'DCSN_subsystem_integrated'.
 *
 * Model version                  : 1.602
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 17:40:58 2020
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

#include "DtrmnDCSN_TrafficDecider.h"

/* Include model header file for global data */
#include "DCSN_subsystem_integrated.h"
#include "DCSN_subsystem_integrated_private.h"
#include "look1_iflf_binlx.h"
#include "plook_u32f_bincka.h"
#include "rt_powf_snf.h"

/* Named constants for Chart: '<S162>/DtrmnDCSN_StopModeManager' */
#define DCSN_s_IN_HoldForStopLineUpdate ((uint8_T)2U)
#define DCSN_su_IN_NO_ACTIVE_CHILD_abpi ((uint8_T)0U)
#define DCSN_su_IN_WaitForValidStopLine ((uint8_T)5U)
#define DCSN_sub_IN_StopRequestDisabled ((uint8_T)1U)
#define DCSN_subs_IN_SendStopReqMpfuDis ((uint8_T)3U)
#define DCSN_subs_IN_StopRequestEnabled ((uint8_T)2U)
#define DCSN_subsystem_IN_CheckStopCond ((uint8_T)1U)
#define DCSN_subsystem_IN_UpdateStopDis ((uint8_T)4U)

/*
 * System initialize for action system:
 *    '<S78>/If Action Subsystem'
 *    '<S79>/If Action Subsystem'
 */
void DCSN_sub_IfActionSubsystem_Init(DW_IfActionSubsystem_DCSN_sub_T *localDW)
{
  /* SystemInitialize for Iterator SubSystem: '<S101>/While Iterator Subsystem' */
  /* InitializeConditions for Delay: '<S103>/Delay' */
  localDW->icLoad = 1U;

  /* End of SystemInitialize for SubSystem: '<S101>/While Iterator Subsystem' */
}

/*
 * Outputs for action system:
 *    '<S78>/If Action Subsystem'
 *    '<S79>/If Action Subsystem'
 */
void DCSN_subsyste_IfActionSubsystem(real32_T rtu_timegap, real32_T rtu_para,
  real32_T rtu_para_ldlm, real32_T rtu_para_dgjl, real32_T rtu_para_lj5q,
  real32_T rtu_para_i1xy, real32_T rtu_para_pnkv, real32_T rtu_step_size, const
  real32_T rtu_sample_point[8], real32_T *rty_avg_curvature,
  B_IfActionSubsystem_DCSN_subs_T *localB, DW_IfActionSubsystem_DCSN_sub_T
  *localDW)
{
  int32_T s103_iter;
  real32_T rtb_Product9;
  real32_T rtb_MathFunction2;
  boolean_T rtb_RelationalOperator1_plfi;
  uint8_T rtb_Sum3;
  real32_T UnitDelay6_DSTATE;
  real32_T UnitDelay5_DSTATE;
  real32_T UnitDelay3_DSTATE;
  real32_T UnitDelay2_DSTATE;
  real32_T UnitDelay4_DSTATE;
  uint8_T UnitDelay7_DSTATE;
  real32_T UnitDelay1_DSTATE;
  real32_T Divide;
  real32_T DataTypeConversion;
  real32_T rtb_Product_nkhs_0;
  real32_T rtb_Product_nkhs_tmp;

  /* Outputs for Iterator SubSystem: '<S101>/While Iterator Subsystem' incorporates:
   *  WhileIterator: '<S103>/While Iterator'
   */
  s103_iter = 1;

  /* InitializeConditions for UnitDelay: '<S103>/Unit Delay6' */
  UnitDelay6_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S103>/Delay' */
  localDW->icLoad = 1U;

  /* InitializeConditions for UnitDelay: '<S103>/Unit Delay' */
  DataTypeConversion = 0.0F;

  /* InitializeConditions for UnitDelay: '<S103>/Unit Delay8' */
  rtb_Sum3 = ((uint8_T)0U);

  /* InitializeConditions for UnitDelay: '<S103>/Unit Delay5' */
  UnitDelay5_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S103>/Unit Delay3' */
  UnitDelay3_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S103>/Unit Delay2' */
  UnitDelay2_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S103>/Unit Delay4' */
  UnitDelay4_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S103>/Unit Delay7' */
  UnitDelay7_DSTATE = ((uint8_T)0U);

  /* InitializeConditions for UnitDelay: '<S103>/Unit Delay1' */
  UnitDelay1_DSTATE = 0.0F;
  do
  {
    rtb_Product_nkhs_tmp = ((real32_T)s103_iter) * rtu_step_size;
    rtb_MathFunction2 = rtb_Product_nkhs_tmp * rtb_Product_nkhs_tmp;
    rtb_Product9 = (((rtb_MathFunction2 * rtu_para) * 3.0F) +
                    ((rtb_Product_nkhs_tmp * rtu_para_ldlm) * 2.0F)) +
      rtu_para_dgjl;
    rtb_Product9 = (rtb_Product9 * rtb_Product9) + 1.0F;
    if ((rtb_Product9 < 0.0F) && (1.5F > ((real32_T)floor((real_T)1.5F))))
    {
      rtb_Product9 = -rt_powf_snf(-rtb_Product9, 1.5F);
    }
    else
    {
      rtb_Product9 = rt_powf_snf(rtb_Product9, 1.5F);
    }

    Divide = ((real32_T)fabs((real_T)((real32_T)(((rtb_Product_nkhs_tmp *
      rtu_para) * 6.0F) + (rtu_para_ldlm * 2.0F))))) / rtb_Product9;
    if ((rtb_Product_nkhs_tmp < 0.0F) && (3.0F > ((real32_T)floor((real_T)3.0F))))
    {
      rtb_Product_nkhs_0 = -rt_powf_snf(-rtb_Product_nkhs_tmp, 3.0F);
    }
    else
    {
      rtb_Product_nkhs_0 = rt_powf_snf(rtb_Product_nkhs_tmp, 3.0F);
    }

    rtb_Product_nkhs_0 = (((rtb_Product_nkhs_0 * rtu_para) + (rtb_MathFunction2 *
      rtu_para_ldlm)) + (rtb_Product_nkhs_tmp * rtu_para_dgjl)) + rtu_para_lj5q;
    if (((int32_T)localDW->icLoad) != 0)
    {
      localDW->Delay_DSTATE = rtb_Product_nkhs_0;
    }

    rtb_Product9 = rtb_Product_nkhs_0 - localDW->Delay_DSTATE;
    rtb_MathFunction2 = rtb_Product9 * rtb_Product9;
    if (s103_iter > 1)
    {
      rtb_Product9 = rtu_step_size;
    }
    else
    {
      rtb_Product9 = 0.0F;
    }

    rtb_Product9 = ((real32_T)sqrt((real_T)((real32_T)(rtb_MathFunction2 +
      (rtb_Product9 * rtb_Product9))))) + DataTypeConversion;
    DataTypeConversion = rtb_Product9;
    rtb_MathFunction2 = (1.0F - (0.01F * rtu_sample_point[((int32_T)((uint8_T)
      (((uint8_T)8U) - rtb_Sum3))) - 1])) * rtu_timegap;
    rtb_RelationalOperator1_plfi = ((((rtu_step_size * ((real32_T)s103_iter)) >=
      rtu_para_i1xy) && (rtb_Product9 >= rtb_MathFunction2)) &&
      (UnitDelay2_DSTATE < rtb_MathFunction2));
    if (rtb_RelationalOperator1_plfi)
    {
      if ((rtb_Product9 - rtb_MathFunction2) > (rtb_MathFunction2 -
           UnitDelay5_DSTATE))
      {
      }
      else
      {
        UnitDelay6_DSTATE = Divide;
      }

      rtb_Product9 = UnitDelay3_DSTATE + UnitDelay6_DSTATE;
    }
    else
    {
      rtb_Product9 = 0.0F + UnitDelay4_DSTATE;
    }

    rtb_Sum3 = (uint8_T)((((uint32_T)UnitDelay7_DSTATE) +
                          (rtb_RelationalOperator1_plfi ? 1U : 0U)) + ((uint32_T)
      (((DataTypeConversion > rtb_MathFunction2) && (UnitDelay1_DSTATE >
      rtb_MathFunction2)) ? 1 : 0)));
    localB->Divide2 = rtb_Product9 / ((real32_T)rtb_Sum3);
    rtb_RelationalOperator1_plfi = (((real32_T)s103_iter) < (rtu_timegap /
      rtu_step_size));
    UnitDelay6_DSTATE = Divide;
    localDW->icLoad = 0U;
    localDW->Delay_DSTATE = rtb_Product_nkhs_0;
    UnitDelay5_DSTATE = DataTypeConversion;
    UnitDelay3_DSTATE = rtb_Product9;
    UnitDelay2_DSTATE = DataTypeConversion;
    UnitDelay4_DSTATE = rtb_Product9;
    UnitDelay7_DSTATE = rtb_Sum3;
    UnitDelay1_DSTATE = DataTypeConversion;
    s103_iter++;
  }
  while ((((DataTypeConversion < rtu_timegap) && rtb_RelationalOperator1_plfi) &&
          (rtb_Product_nkhs_tmp < rtu_para_pnkv)) && (s103_iter <= 3500));

  /* End of Outputs for SubSystem: '<S101>/While Iterator Subsystem' */

  /* SignalConversion: '<S101>/OutportBufferForavg_curvature' */
  *rty_avg_curvature = localB->Divide2;
}

/*
 * Output and update for action system:
 *    '<S78>/If Action Subsystem1'
 *    '<S79>/If Action Subsystem1'
 */
void DCSN_subsyst_IfActionSubsystem1(real32_T *rty_largest_curvature)
{
  /* SignalConversion: '<S102>/OutportBufferForlargest_curvature' incorporates:
   *  Constant: '<S102>/Constant1'
   */
  *rty_largest_curvature = 0.0F;
}

/* System initialize for atomic system: '<S1>/DtrmnDCSN_TrafficDecider' */
void D_DtrmnDCSN_TrafficDecider_Init(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S172>/Discrete-Time Integrator' */
  DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S173>/Discrete-Time Integrator' */
  DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_Pre_jtbt = 2;

  /* SystemInitialize for IfAction SubSystem: '<S78>/If Action Subsystem' */
  DCSN_sub_IfActionSubsystem_Init
    (&DCSN_subsystem_integrated_DW.IfActionSubsystem);

  /* End of SystemInitialize for SubSystem: '<S78>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S79>/If Action Subsystem' */
  DCSN_sub_IfActionSubsystem_Init
    (&DCSN_subsystem_integrated_DW.IfActionSubsystem_j2my);

  /* End of SystemInitialize for SubSystem: '<S79>/If Action Subsystem' */

  /* SystemInitialize for Chart: '<S162>/DtrmnDCSN_StopModeManager' */
  DCSN_subsystem_integrated_DW.is_StopRequestEnabled =
    DCSN_su_IN_NO_ACTIVE_CHILD_abpi;
  DCSN_subsystem_integrated_DW.is_active_c3_DCSN_subsystem_int = 0U;
  DCSN_subsystem_integrated_DW.is_c3_DCSN_subsystem_integrated =
    DCSN_su_IN_NO_ACTIVE_CHILD_abpi;
  DCSN_subsystem_integrated_DW.distance_to_move = 0.0F;
  DCSN_subsystem_integrated_B.stop_distance = 0.0F;

  /* SystemInitialize for Enabled SubSystem: '<S161>/StopDis' */
  /* InitializeConditions for UnitDelay: '<S171>/Unit Delay' */
  DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_ezc1 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S161>/StopDis' */
}

/* Output and update for atomic system: '<S1>/DtrmnDCSN_TrafficDecider' */
void DCSN_s_DtrmnDCSN_TrafficDecider(void)
{
  int32_T s80_iter;
  uint8_T rtb_Switch;
  uint8_T rtb_Switch_m3bd;
  uint16_T rtb_CurrentTick;
  uint8_T rtb_Switch_lp1h;
  boolean_T rtb_Compare_nkof;
  boolean_T rtb_Compare_lebe;
  real32_T rtb_Switch_mhao;
  boolean_T rtb_RelationalOperator_byg2;
  boolean_T rtb_RelationalOperator_l4uz;
  boolean_T rtb_RelationalOperator_g4mo;
  boolean_T rtb_RelationalOperator_f1ec;
  real32_T rtb_Switch_crnn;
  real32_T rtb_Switch_jvmn;
  real32_T rtb_Switch_lnuo;
  real32_T rtb_Switch_j1xp;
  real32_T rtb_Switch_oios;
  boolean_T rtb_RelationalOperator_elnv;
  boolean_T rtb_RelationalOperator_cwas;
  boolean_T rtb_RelationalOperator_njbi;
  boolean_T rtb_RelationalOperator_ehd0;
  real32_T rtb_Switch_eq4s;
  real32_T rtb_Switch_i5a0;
  real32_T rtb_Switch_hufc;
  real32_T rtb_Switch_o3ag;
  real32_T rtb_Switch_iesc;
  real32_T rtb_Switch_ng24;
  real32_T rtb_Switch_bcgx;
  real32_T rtb_Switch_by1p;
  real32_T rtb_Switch_k1o1;
  real32_T rtb_Switch_psiv;
  real32_T rtb_Switch_et0b;
  real32_T rtb_Switch_dyus;
  real32_T rtb_Switch_l3dh;
  real32_T rtb_Switch_nkom;
  real32_T rtb_Switch_g34g;
  uint16_T rtb_CurrentTick_bicj;
  uint16_T rtb_CurrentTick_glhk;
  EnumDCSN_driving_direction rtb_Switch4_exki;
  EnumDCSN_speed_limit_reason rtb_Switch_abos;
  real32_T quality;
  real32_T quality_flcq;
  real32_T end_x;
  real32_T start_x;
  real32_T quality_ksol;
  real32_T quality_htk5;
  real32_T end_x_lbop;
  real32_T start_x_ceng;
  real32_T rtb_Merge_mgdo;
  real32_T rtb_Abs;
  real32_T rtb_end_x;
  real32_T rtb_start_x;
  real32_T rtb_c3;
  real32_T rtb_c2;
  real32_T rtb_c1;
  real32_T rtb_c0;
  real32_T rtb_end_x_bssg;
  real32_T rtb_start_x_fksj;
  real32_T rtb_c3_a4vy;
  real32_T rtb_c2_ckxv;
  real32_T rtb_c1_dywv;
  real32_T rtb_c0_ifjz;

  /* Outputs for Iterator SubSystem: '<S74>/CalcDCSN_select_ego_road_edges_L' incorporates:
   *  WhileIterator: '<S80>/While Iterator'
   */
  s80_iter = 1;
  do
  {
    rtb_Compare_nkof = (VsMPFU_DataBus.road_edges[s80_iter - 1].id == 1);
    if (rtb_Compare_nkof)
    {
      DCSN_subsystem_integrated_B.road_edges_index_iogx = s80_iter;
    }

    s80_iter++;
  }
  while ((!rtb_Compare_nkof) && (s80_iter <= 8));

  /* End of Outputs for SubSystem: '<S74>/CalcDCSN_select_ego_road_edges_L' */

  /* RelationalOperator: '<S183>/Relational Operator' */
  VbDCSN_mpfu_num_edges_isNaN = false;

  /* Switch: '<S183>/Switch' incorporates:
   *  Inport: '<Root>/MPFU_DataBus'
   *  UnitDelay: '<S183>/Unit Delay'
   */
  if (VbDCSN_mpfu_num_edges_isNaN)
  {
    rtb_Switch = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_da3u;
  }
  else
  {
    rtb_Switch = VsMPFU_DataBus.num_road_edges;
  }

  /* End of Switch: '<S183>/Switch' */

  /* Logic: '<S74>/Logical Operator2' incorporates:
   *  Constant: '<S93>/Constant'
   *  Constant: '<S94>/Constant'
   *  RelationalOperator: '<S93>/Compare'
   *  RelationalOperator: '<S94>/Compare'
   */
  rtb_Compare_nkof = ((DCSN_subsystem_integrated_B.road_edges_index_iogx > 0) &&
                      (rtb_Switch > ((uint8_T)0U)));

  /* Outputs for Iterator SubSystem: '<S74>/CalcDCSN_select_ego_road_marker_L' incorporates:
   *  WhileIterator: '<S82>/While Iterator'
   */
  s80_iter = 1;
  do
  {
    rtb_Compare_lebe = (VsMPFU_DataBus.lane_markers[s80_iter - 1].id == 1);
    if (rtb_Compare_lebe)
    {
      DCSN_subsystem_integrated_B.lane_marker_index_o23e = s80_iter;
    }

    s80_iter++;
  }
  while ((!rtb_Compare_lebe) && (s80_iter <= 16));

  /* End of Outputs for SubSystem: '<S74>/CalcDCSN_select_ego_road_marker_L' */

  /* RelationalOperator: '<S181>/Relational Operator' */
  VbDCSN_mpfu_num_markers_isNaN = false;

  /* Switch: '<S181>/Switch' incorporates:
   *  Inport: '<Root>/MPFU_DataBus'
   *  UnitDelay: '<S181>/Unit Delay'
   */
  if (VbDCSN_mpfu_num_markers_isNaN)
  {
    rtb_Switch_m3bd = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_efss;
  }
  else
  {
    rtb_Switch_m3bd = VsMPFU_DataBus.num_lane_markers;
  }

  /* End of Switch: '<S181>/Switch' */

  /* Logic: '<S74>/Logical Operator3' incorporates:
   *  Constant: '<S96>/Constant'
   *  Constant: '<S97>/Constant'
   *  RelationalOperator: '<S96>/Compare'
   *  RelationalOperator: '<S97>/Compare'
   */
  VbDCSN_has_left_marker = ((DCSN_subsystem_integrated_B.lane_marker_index_o23e >
    0) && (rtb_Switch_m3bd > ((uint8_T)0U)));

  /* If: '<S74>/If1' */
  if (rtb_Compare_nkof)
  {
    /* Outputs for IfAction SubSystem: '<S74>/CalcDCSN_select_left_edge_para' incorporates:
     *  ActionPort: '<S84>/Action Port'
     */
    /* RelationalOperator: '<S115>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S84>/Selector'
     */
    rtb_Compare_lebe = rtIsNaNF
      (VsMPFU_DataBus.road_edges[DCSN_subsystem_integrated_B.road_edges_index_iogx
       - 1].c0_position);

    /* Switch: '<S115>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S84>/Selector'
     */
    if (rtb_Compare_lebe)
    {
      /* Switch: '<S115>/Switch1' incorporates:
       *  Constant: '<S115>/Constant'
       *  RelationalOperator: '<S115>/Relational Operator1'
       *  UnitDelay: '<S115>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_o5ry))
      {
        rtb_Switch_mhao = 0.0F;
      }
      else
      {
        rtb_Switch_mhao = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_o5ry;
      }

      /* End of Switch: '<S115>/Switch1' */
    }
    else
    {
      rtb_Switch_mhao =
        VsMPFU_DataBus.road_edges[DCSN_subsystem_integrated_B.road_edges_index_iogx
        - 1].c0_position;
    }

    /* End of Switch: '<S115>/Switch' */

    /* RelationalOperator: '<S116>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S84>/Selector'
     */
    rtb_RelationalOperator_byg2 = rtIsNaNF
      (VsMPFU_DataBus.road_edges[DCSN_subsystem_integrated_B.road_edges_index_iogx
       - 1].c1_heading);

    /* RelationalOperator: '<S117>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S84>/Selector'
     */
    rtb_RelationalOperator_l4uz = rtIsNaNF
      (VsMPFU_DataBus.road_edges[DCSN_subsystem_integrated_B.road_edges_index_iogx
       - 1].c2_curvature);

    /* RelationalOperator: '<S118>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S84>/Selector'
     */
    rtb_RelationalOperator_g4mo = rtIsNaNF
      (VsMPFU_DataBus.road_edges[DCSN_subsystem_integrated_B.road_edges_index_iogx
       - 1].c3_curvature_derivative);

    /* RelationalOperator: '<S119>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S84>/Selector'
     */
    rtb_RelationalOperator_f1ec = rtIsNaNF
      (VsMPFU_DataBus.road_edges[DCSN_subsystem_integrated_B.road_edges_index_iogx
       - 1].distance_to_host);

    /* Logic: '<S84>/Logical Operator' */
    VbDCSN_left_edge_para_isNaN = ((((rtb_Compare_lebe ||
      rtb_RelationalOperator_byg2) || rtb_RelationalOperator_l4uz) ||
      rtb_RelationalOperator_g4mo) || rtb_RelationalOperator_f1ec);

    /* Switch: '<S119>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S84>/Selector'
     */
    if (rtb_RelationalOperator_f1ec)
    {
      /* Switch: '<S119>/Switch1' incorporates:
       *  Constant: '<S119>/Constant'
       *  RelationalOperator: '<S119>/Relational Operator1'
       *  UnitDelay: '<S119>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_cxqx))
      {
        rtb_Switch_crnn = 0.0F;
      }
      else
      {
        rtb_Switch_crnn = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_cxqx;
      }

      /* End of Switch: '<S119>/Switch1' */
    }
    else
    {
      rtb_Switch_crnn =
        VsMPFU_DataBus.road_edges[DCSN_subsystem_integrated_B.road_edges_index_iogx
        - 1].distance_to_host;
    }

    /* End of Switch: '<S119>/Switch' */

    /* SignalConversion: '<S84>/BusConversion_InsertedFor_left_edge_para_at_inport_0' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S84>/Selector'
     *  Switch: '<S120>/Switch'
     */
    quality = (real32_T)
      VsMPFU_DataBus.road_edges[DCSN_subsystem_integrated_B.road_edges_index_iogx
      - 1].quality;

    /* Switch: '<S118>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S84>/Selector'
     */
    if (rtb_RelationalOperator_g4mo)
    {
      /* Switch: '<S118>/Switch1' incorporates:
       *  Constant: '<S118>/Constant'
       *  RelationalOperator: '<S118>/Relational Operator1'
       *  UnitDelay: '<S118>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_cwys))
      {
        rtb_Switch_jvmn = 0.0F;
      }
      else
      {
        rtb_Switch_jvmn = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_cwys;
      }

      /* End of Switch: '<S118>/Switch1' */
    }
    else
    {
      rtb_Switch_jvmn =
        VsMPFU_DataBus.road_edges[DCSN_subsystem_integrated_B.road_edges_index_iogx
        - 1].c3_curvature_derivative;
    }

    /* End of Switch: '<S118>/Switch' */

    /* Switch: '<S117>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S84>/Selector'
     */
    if (rtb_RelationalOperator_l4uz)
    {
      /* Switch: '<S117>/Switch1' incorporates:
       *  Constant: '<S117>/Constant'
       *  RelationalOperator: '<S117>/Relational Operator1'
       *  UnitDelay: '<S117>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_orr5))
      {
        rtb_Switch_lnuo = 0.0F;
      }
      else
      {
        rtb_Switch_lnuo = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_orr5;
      }

      /* End of Switch: '<S117>/Switch1' */
    }
    else
    {
      rtb_Switch_lnuo =
        VsMPFU_DataBus.road_edges[DCSN_subsystem_integrated_B.road_edges_index_iogx
        - 1].c2_curvature;
    }

    /* End of Switch: '<S117>/Switch' */

    /* Switch: '<S116>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S84>/Selector'
     */
    if (rtb_RelationalOperator_byg2)
    {
      /* Switch: '<S116>/Switch1' incorporates:
       *  Constant: '<S116>/Constant'
       *  RelationalOperator: '<S116>/Relational Operator1'
       *  UnitDelay: '<S116>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_k4as))
      {
        rtb_Switch_j1xp = 0.0F;
      }
      else
      {
        rtb_Switch_j1xp = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_k4as;
      }

      /* End of Switch: '<S116>/Switch1' */
    }
    else
    {
      rtb_Switch_j1xp =
        VsMPFU_DataBus.road_edges[DCSN_subsystem_integrated_B.road_edges_index_iogx
        - 1].c1_heading;
    }

    /* End of Switch: '<S116>/Switch' */

    /* SignalConversion: '<S84>/BusConversion_InsertedFor_left_edge_para_at_inport_0' */
    start_x = DCSN_subsystem_integrate_ConstB.TmpBufferAtConstantOut_dl2l;

    /* SignalConversion: '<S84>/BusConversion_InsertedFor_left_edge_para_at_inport_0' */
    end_x = DCSN_subsystem_integrate_ConstB.TmpBufferAtConstant2Ou_ijwj;

    /* Update for UnitDelay: '<S115>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_o5ry = rtb_Switch_mhao;

    /* Update for UnitDelay: '<S119>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_cxqx = rtb_Switch_crnn;

    /* Update for UnitDelay: '<S118>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_cwys = rtb_Switch_jvmn;

    /* Update for UnitDelay: '<S117>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_orr5 = rtb_Switch_lnuo;

    /* Update for UnitDelay: '<S116>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_k4as = rtb_Switch_j1xp;

    /* End of Outputs for SubSystem: '<S74>/CalcDCSN_select_left_edge_para' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S74>/CalcDCSN_simu_left_edge_para' incorporates:
     *  ActionPort: '<S88>/Action Port'
     */
    /* SignalConversion: '<S88>/TmpBufferAtConstant1Outport1' incorporates:
     *  Constant: '<S88>/Constant1'
     */
    rtb_Switch_mhao = 0.0F;

    /* SignalConversion: '<S88>/TmpBufferAtConstant10Outport1' incorporates:
     *  Constant: '<S88>/Constant10'
     */
    rtb_Switch_crnn = 0.0F;

    /* SignalConversion: '<S88>/TmpBufferAtConstant2Outport1' incorporates:
     *  Constant: '<S88>/Constant2'
     */
    rtb_Switch_j1xp = 0.0F;

    /* SignalConversion: '<S88>/TmpBufferAtConstant3Outport1' incorporates:
     *  Constant: '<S88>/Constant3'
     */
    rtb_Switch_lnuo = 0.0F;

    /* SignalConversion: '<S88>/TmpBufferAtConstant4Outport1' incorporates:
     *  Constant: '<S88>/Constant4'
     */
    rtb_Switch_jvmn = 0.0F;

    /* SignalConversion: '<S88>/TmpBufferAtConstant5Outport1' incorporates:
     *  Constant: '<S88>/Constant5'
     */
    start_x = 0.0F;

    /* SignalConversion: '<S88>/TmpBufferAtConstant7Outport1' incorporates:
     *  Constant: '<S88>/Constant7'
     */
    end_x = 0.0F;

    /* SignalConversion: '<S88>/TmpBufferAtConstant9Outport1' incorporates:
     *  Constant: '<S88>/Constant9'
     */
    quality = 0.0F;

    /* End of Outputs for SubSystem: '<S74>/CalcDCSN_simu_left_edge_para' */
  }

  /* End of If: '<S74>/If1' */

  /* If: '<S74>/If3' */
  if (VbDCSN_has_left_marker)
  {
    /* Outputs for IfAction SubSystem: '<S74>/CalcDCSN_select_left_marker_para' incorporates:
     *  ActionPort: '<S85>/Action Port'
     */
    /* RelationalOperator: '<S121>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S85>/Selector'
     */
    rtb_Compare_lebe = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index_o23e
       - 1].c0_position);

    /* Switch: '<S121>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S85>/Selector'
     */
    if (rtb_Compare_lebe)
    {
      /* Switch: '<S121>/Switch1' incorporates:
       *  Constant: '<S121>/Constant'
       *  RelationalOperator: '<S121>/Relational Operator1'
       *  UnitDelay: '<S121>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_ojmf))
      {
        rtb_Switch_oios = 0.0F;
      }
      else
      {
        rtb_Switch_oios = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_ojmf;
      }

      /* End of Switch: '<S121>/Switch1' */
    }
    else
    {
      rtb_Switch_oios =
        VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index_o23e
        - 1].c0_position;
    }

    /* End of Switch: '<S121>/Switch' */

    /* RelationalOperator: '<S122>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S85>/Selector'
     */
    rtb_RelationalOperator_byg2 = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index_o23e
       - 1].c1_heading);

    /* RelationalOperator: '<S123>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S85>/Selector'
     */
    rtb_RelationalOperator_l4uz = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index_o23e
       - 1].c2_curvature);

    /* RelationalOperator: '<S124>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S85>/Selector'
     */
    rtb_RelationalOperator_g4mo = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index_o23e
       - 1].c3_curvature_derivative);

    /* RelationalOperator: '<S129>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S85>/Selector'
     */
    rtb_RelationalOperator_f1ec = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index_o23e
       - 1].start_rel.x);

    /* RelationalOperator: '<S130>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S85>/Selector'
     */
    rtb_RelationalOperator_elnv = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index_o23e
       - 1].start_rel.y);

    /* RelationalOperator: '<S126>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S85>/Selector'
     */
    rtb_RelationalOperator_cwas = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index_o23e
       - 1].end_rel.x);

    /* RelationalOperator: '<S127>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S85>/Selector'
     */
    rtb_RelationalOperator_njbi = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index_o23e
       - 1].end_rel.y);

    /* RelationalOperator: '<S125>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S85>/Selector'
     */
    rtb_RelationalOperator_ehd0 = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index_o23e
       - 1].distance_to_host);

    /* Logic: '<S85>/Logical Operator' */
    VbDCSN_left_marker_para_isNaN = ((((((((rtb_Compare_lebe ||
      rtb_RelationalOperator_byg2) || rtb_RelationalOperator_l4uz) ||
      rtb_RelationalOperator_g4mo) || rtb_RelationalOperator_f1ec) ||
      rtb_RelationalOperator_elnv) || rtb_RelationalOperator_cwas) ||
      rtb_RelationalOperator_njbi) || rtb_RelationalOperator_ehd0);

    /* Switch: '<S125>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S85>/Selector'
     */
    if (rtb_RelationalOperator_ehd0)
    {
      /* Switch: '<S125>/Switch1' incorporates:
       *  Constant: '<S125>/Constant'
       *  RelationalOperator: '<S125>/Relational Operator1'
       *  UnitDelay: '<S125>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_jmmu))
      {
        rtb_Switch_eq4s = 0.0F;
      }
      else
      {
        rtb_Switch_eq4s = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_jmmu;
      }

      /* End of Switch: '<S125>/Switch1' */
    }
    else
    {
      rtb_Switch_eq4s =
        VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index_o23e
        - 1].distance_to_host;
    }

    /* End of Switch: '<S125>/Switch' */

    /* SignalConversion: '<S85>/BusConversion_InsertedFor_left_lane_marker_para_at_inport_0' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S85>/Selector'
     *  Switch: '<S128>/Switch'
     */
    quality_flcq = (real32_T)
      VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index_o23e
      - 1].quality;

    /* Switch: '<S127>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S85>/Selector'
     */
    if (rtb_RelationalOperator_njbi)
    {
      /* Switch: '<S127>/Switch1' incorporates:
       *  Constant: '<S127>/Constant'
       *  RelationalOperator: '<S127>/Relational Operator1'
       *  UnitDelay: '<S127>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_o5r3))
      {
        rtb_Switch_i5a0 = 0.0F;
      }
      else
      {
        rtb_Switch_i5a0 = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_o5r3;
      }

      /* End of Switch: '<S127>/Switch1' */
    }
    else
    {
      rtb_Switch_i5a0 =
        VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index_o23e
        - 1].end_rel.y;
    }

    /* End of Switch: '<S127>/Switch' */

    /* Switch: '<S126>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S85>/Selector'
     */
    if (rtb_RelationalOperator_cwas)
    {
      /* Switch: '<S126>/Switch1' incorporates:
       *  Constant: '<S126>/Constant'
       *  RelationalOperator: '<S126>/Relational Operator1'
       *  UnitDelay: '<S126>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_j4qc))
      {
        rtb_Switch_hufc = 0.0F;
      }
      else
      {
        rtb_Switch_hufc = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_j4qc;
      }

      /* End of Switch: '<S126>/Switch1' */
    }
    else
    {
      rtb_Switch_hufc =
        VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index_o23e
        - 1].end_rel.x;
    }

    /* End of Switch: '<S126>/Switch' */

    /* Switch: '<S130>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S85>/Selector'
     */
    if (rtb_RelationalOperator_elnv)
    {
      /* Switch: '<S130>/Switch1' incorporates:
       *  Constant: '<S130>/Constant'
       *  RelationalOperator: '<S130>/Relational Operator1'
       *  UnitDelay: '<S130>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_pxme))
      {
        rtb_Switch_o3ag = 0.0F;
      }
      else
      {
        rtb_Switch_o3ag = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_pxme;
      }

      /* End of Switch: '<S130>/Switch1' */
    }
    else
    {
      rtb_Switch_o3ag =
        VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index_o23e
        - 1].start_rel.y;
    }

    /* End of Switch: '<S130>/Switch' */

    /* Switch: '<S129>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S85>/Selector'
     */
    if (rtb_RelationalOperator_f1ec)
    {
      /* Switch: '<S129>/Switch1' incorporates:
       *  Constant: '<S129>/Constant'
       *  RelationalOperator: '<S129>/Relational Operator1'
       *  UnitDelay: '<S129>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_edmg))
      {
        rtb_Switch_iesc = 0.0F;
      }
      else
      {
        rtb_Switch_iesc = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_edmg;
      }

      /* End of Switch: '<S129>/Switch1' */
    }
    else
    {
      rtb_Switch_iesc =
        VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index_o23e
        - 1].start_rel.x;
    }

    /* End of Switch: '<S129>/Switch' */

    /* Switch: '<S124>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S85>/Selector'
     */
    if (rtb_RelationalOperator_g4mo)
    {
      /* Switch: '<S124>/Switch1' incorporates:
       *  Constant: '<S124>/Constant'
       *  RelationalOperator: '<S124>/Relational Operator1'
       *  UnitDelay: '<S124>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_cs2z))
      {
        rtb_Switch_ng24 = 0.0F;
      }
      else
      {
        rtb_Switch_ng24 = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_cs2z;
      }

      /* End of Switch: '<S124>/Switch1' */
    }
    else
    {
      rtb_Switch_ng24 =
        VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index_o23e
        - 1].c3_curvature_derivative;
    }

    /* End of Switch: '<S124>/Switch' */

    /* Switch: '<S123>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S85>/Selector'
     */
    if (rtb_RelationalOperator_l4uz)
    {
      /* Switch: '<S123>/Switch1' incorporates:
       *  Constant: '<S123>/Constant'
       *  RelationalOperator: '<S123>/Relational Operator1'
       *  UnitDelay: '<S123>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_jc32))
      {
        rtb_Switch_bcgx = 0.0F;
      }
      else
      {
        rtb_Switch_bcgx = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_jc32;
      }

      /* End of Switch: '<S123>/Switch1' */
    }
    else
    {
      rtb_Switch_bcgx =
        VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index_o23e
        - 1].c2_curvature;
    }

    /* End of Switch: '<S123>/Switch' */

    /* Switch: '<S122>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S85>/Selector'
     */
    if (rtb_RelationalOperator_byg2)
    {
      /* Switch: '<S122>/Switch1' incorporates:
       *  Constant: '<S122>/Constant'
       *  RelationalOperator: '<S122>/Relational Operator1'
       *  UnitDelay: '<S122>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_dqkl))
      {
        rtb_Switch_by1p = 0.0F;
      }
      else
      {
        rtb_Switch_by1p = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_dqkl;
      }

      /* End of Switch: '<S122>/Switch1' */
    }
    else
    {
      rtb_Switch_by1p =
        VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index_o23e
        - 1].c1_heading;
    }

    /* End of Switch: '<S122>/Switch' */

    /* Update for UnitDelay: '<S121>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_ojmf = rtb_Switch_oios;

    /* Update for UnitDelay: '<S125>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_jmmu = rtb_Switch_eq4s;

    /* Update for UnitDelay: '<S127>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_o5r3 = rtb_Switch_i5a0;

    /* Update for UnitDelay: '<S126>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_j4qc = rtb_Switch_hufc;

    /* Update for UnitDelay: '<S130>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_pxme = rtb_Switch_o3ag;

    /* Update for UnitDelay: '<S129>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_edmg = rtb_Switch_iesc;

    /* Update for UnitDelay: '<S124>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_cs2z = rtb_Switch_ng24;

    /* Update for UnitDelay: '<S123>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_jc32 = rtb_Switch_bcgx;

    /* Update for UnitDelay: '<S122>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_dqkl = rtb_Switch_by1p;

    /* End of Outputs for SubSystem: '<S74>/CalcDCSN_select_left_marker_para' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S74>/CalcDCSN_simu_left_marker_para' incorporates:
     *  ActionPort: '<S89>/Action Port'
     */
    /* SignalConversion: '<S89>/TmpBufferAtConstant1Outport1' incorporates:
     *  Constant: '<S89>/Constant1'
     */
    rtb_Switch_oios = 0.0F;

    /* SignalConversion: '<S89>/TmpBufferAtConstant10Outport1' incorporates:
     *  Constant: '<S89>/Constant10'
     */
    rtb_Switch_eq4s = 0.0F;

    /* SignalConversion: '<S89>/TmpBufferAtConstant2Outport1' incorporates:
     *  Constant: '<S89>/Constant2'
     */
    rtb_Switch_by1p = 0.0F;

    /* SignalConversion: '<S89>/TmpBufferAtConstant3Outport1' incorporates:
     *  Constant: '<S89>/Constant3'
     */
    rtb_Switch_bcgx = 0.0F;

    /* SignalConversion: '<S89>/TmpBufferAtConstant4Outport1' incorporates:
     *  Constant: '<S89>/Constant4'
     */
    rtb_Switch_ng24 = 0.0F;

    /* SignalConversion: '<S89>/TmpBufferAtConstant5Outport1' incorporates:
     *  Constant: '<S89>/Constant5'
     */
    rtb_Switch_iesc = 0.0F;

    /* SignalConversion: '<S89>/TmpBufferAtConstant6Outport1' incorporates:
     *  Constant: '<S89>/Constant6'
     */
    rtb_Switch_o3ag = 0.0F;

    /* SignalConversion: '<S89>/TmpBufferAtConstant7Outport1' incorporates:
     *  Constant: '<S89>/Constant7'
     */
    rtb_Switch_hufc = 0.0F;

    /* SignalConversion: '<S89>/TmpBufferAtConstant8Outport1' incorporates:
     *  Constant: '<S89>/Constant8'
     */
    rtb_Switch_i5a0 = 0.0F;

    /* SignalConversion: '<S89>/TmpBufferAtConstant9Outport1' incorporates:
     *  Constant: '<S89>/Constant9'
     */
    quality_flcq = 0.0F;

    /* End of Outputs for SubSystem: '<S74>/CalcDCSN_simu_left_marker_para' */
  }

  /* End of If: '<S74>/If3' */

  /* RelationalOperator: '<S74>/Relational Operator' */
  rtb_Compare_lebe = (rtb_Switch_crnn <= rtb_Switch_eq4s);

  /* Logic: '<S74>/Logical Operator6' */
  rtb_RelationalOperator_byg2 = (rtb_Compare_nkof && VbDCSN_has_left_marker);

  /* Switch: '<S74>/Switch' incorporates:
   *  Switch: '<S74>/Switch1'
   */
  if (rtb_RelationalOperator_byg2)
  {
    /* Switch: '<S74>/Switch3' */
    if (rtb_Compare_lebe)
    {
      rtb_Merge_mgdo = quality;
    }
    else
    {
      rtb_Merge_mgdo = quality_flcq;
    }
  }
  else if (rtb_Compare_nkof)
  {
    /* Switch: '<S74>/Switch1' */
    rtb_Merge_mgdo = quality;
  }
  else
  {
    rtb_Merge_mgdo = quality_flcq;
  }

  /* SignalConversion: '<S70>/Signal Conversion' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VfDCSN_vehicle_speed_egmo = VsEGMO_DataBus.motion.linear_velocity;

  /* Product: '<S74>/Product' incorporates:
   *  Lookup_n-D: '<S74>/1-D Lookup Table1'
   */
  VfDCSN_SpdLimt_look_ahead_dis = look1_iflf_binlx(VfDCSN_vehicle_speed_egmo,
    KtDCSN_v_ahead_timegap_speed_axis, KtDCSN_t_curvature_ahead_timegap, 9U) *
    VfDCSN_vehicle_speed_egmo;

  /* Switch: '<S74>/Switch' incorporates:
   *  Switch: '<S74>/Switch1'
   */
  if (rtb_RelationalOperator_byg2)
  {
    /* Switch: '<S74>/Switch3' */
    if (rtb_Compare_lebe)
    {
      rtb_end_x = end_x;
    }
    else
    {
      rtb_end_x = rtb_Switch_hufc;
    }
  }
  else if (rtb_Compare_nkof)
  {
    /* Switch: '<S74>/Switch1' */
    rtb_end_x = end_x;
  }
  else
  {
    rtb_end_x = rtb_Switch_hufc;
  }

  if (rtb_RelationalOperator_byg2)
  {
    /* Switch: '<S74>/Switch3' */
    if (rtb_Compare_lebe)
    {
      rtb_start_x = start_x;
    }
    else
    {
      rtb_start_x = rtb_Switch_iesc;
    }
  }
  else if (rtb_Compare_nkof)
  {
    /* Switch: '<S74>/Switch1' */
    rtb_start_x = start_x;
  }
  else
  {
    rtb_start_x = rtb_Switch_iesc;
  }

  if (rtb_RelationalOperator_byg2)
  {
    /* Switch: '<S74>/Switch3' */
    if (rtb_Compare_lebe)
    {
      rtb_c3 = rtb_Switch_jvmn;
    }
    else
    {
      rtb_c3 = rtb_Switch_ng24;
    }
  }
  else if (rtb_Compare_nkof)
  {
    /* Switch: '<S74>/Switch1' */
    rtb_c3 = rtb_Switch_jvmn;
  }
  else
  {
    rtb_c3 = rtb_Switch_ng24;
  }

  if (rtb_RelationalOperator_byg2)
  {
    /* Switch: '<S74>/Switch3' */
    if (rtb_Compare_lebe)
    {
      rtb_c2 = rtb_Switch_lnuo;
    }
    else
    {
      rtb_c2 = rtb_Switch_bcgx;
    }
  }
  else if (rtb_Compare_nkof)
  {
    /* Switch: '<S74>/Switch1' */
    rtb_c2 = rtb_Switch_lnuo;
  }
  else
  {
    rtb_c2 = rtb_Switch_bcgx;
  }

  if (rtb_RelationalOperator_byg2)
  {
    /* Switch: '<S74>/Switch3' */
    if (rtb_Compare_lebe)
    {
      rtb_c1 = rtb_Switch_j1xp;
    }
    else
    {
      rtb_c1 = rtb_Switch_by1p;
    }
  }
  else if (rtb_Compare_nkof)
  {
    /* Switch: '<S74>/Switch1' */
    rtb_c1 = rtb_Switch_j1xp;
  }
  else
  {
    rtb_c1 = rtb_Switch_by1p;
  }

  if (rtb_RelationalOperator_byg2)
  {
    /* Switch: '<S74>/Switch3' */
    if (rtb_Compare_lebe)
    {
      rtb_c0 = rtb_Switch_mhao;
    }
    else
    {
      rtb_c0 = rtb_Switch_oios;
    }
  }
  else if (rtb_Compare_nkof)
  {
    /* Switch: '<S74>/Switch1' */
    rtb_c0 = rtb_Switch_mhao;
  }
  else
  {
    rtb_c0 = rtb_Switch_oios;
  }

  /* If: '<S78>/If' incorporates:
   *  Constant: '<S74>/KfDCSN_a_curvature_sample_point'
   *  Constant: '<S74>/KfDCSN_d_arc_length_integration_step2'
   *  Constant: '<S78>/KfDCSN_Pct_lane_marker_valid_quality'
   *  Logic: '<S74>/Logical Operator'
   *  Logic: '<S78>/Logical Operator'
   *  RelationalOperator: '<S78>/Relational Operator'
   */
  if ((rtb_Compare_nkof || VbDCSN_has_left_marker) && (rtb_Merge_mgdo >=
       ((real32_T)KfDCSN_Pct_lane_marker_valid_quality)))
  {
    /* Outputs for IfAction SubSystem: '<S78>/If Action Subsystem' incorporates:
     *  ActionPort: '<S101>/Action Port'
     */
    DCSN_subsyste_IfActionSubsystem(VfDCSN_SpdLimt_look_ahead_dis, rtb_c3,
      rtb_c2, rtb_c1, rtb_c0, rtb_start_x, rtb_end_x,
      KfDCSN_d_arc_length_integration_step, KfDCSN_a_curvature_sample_point,
      &rtb_Abs, &DCSN_subsystem_integrated_B.IfActionSubsystem,
      &DCSN_subsystem_integrated_DW.IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S78>/If Action Subsystem' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S78>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S102>/Action Port'
     */
    DCSN_subsyst_IfActionSubsystem1(&rtb_Abs);

    /* End of Outputs for SubSystem: '<S78>/If Action Subsystem1' */
  }

  /* End of If: '<S78>/If' */

  /* Outputs for Iterator SubSystem: '<S74>/CalcDCSN_select_ego_road_edges_R' incorporates:
   *  WhileIterator: '<S81>/While Iterator'
   */
  s80_iter = 1;
  do
  {
    rtb_RelationalOperator_l4uz = (VsMPFU_DataBus.road_edges[s80_iter - 1].id ==
      2);
    if (rtb_RelationalOperator_l4uz)
    {
      DCSN_subsystem_integrated_B.road_edges_index = s80_iter;
    }

    s80_iter++;
  }
  while ((!rtb_RelationalOperator_l4uz) && (s80_iter <= 8));

  /* End of Outputs for SubSystem: '<S74>/CalcDCSN_select_ego_road_edges_R' */

  /* Logic: '<S74>/Logical Operator1' incorporates:
   *  Constant: '<S92>/Constant'
   *  Constant: '<S95>/Constant'
   *  RelationalOperator: '<S92>/Compare'
   *  RelationalOperator: '<S95>/Compare'
   */
  rtb_RelationalOperator_l4uz = ((DCSN_subsystem_integrated_B.road_edges_index >
    0) && (rtb_Switch > ((uint8_T)0U)));

  /* Outputs for Iterator SubSystem: '<S74>/CalcDCSN_select_ego_road_marker_R' incorporates:
   *  WhileIterator: '<S83>/While Iterator'
   */
  s80_iter = 1;
  do
  {
    rtb_RelationalOperator_g4mo = (VsMPFU_DataBus.lane_markers[s80_iter - 1].id ==
      2);
    if (rtb_RelationalOperator_g4mo)
    {
      DCSN_subsystem_integrated_B.lane_marker_index = s80_iter;
    }

    s80_iter++;
  }
  while ((!rtb_RelationalOperator_g4mo) && (s80_iter <= 16));

  /* End of Outputs for SubSystem: '<S74>/CalcDCSN_select_ego_road_marker_R' */

  /* Logic: '<S74>/Logical Operator4' incorporates:
   *  Constant: '<S98>/Constant'
   *  Constant: '<S99>/Constant'
   *  RelationalOperator: '<S98>/Compare'
   *  RelationalOperator: '<S99>/Compare'
   */
  VbDCSN_has_right_marker = ((DCSN_subsystem_integrated_B.lane_marker_index > 0)
    && (rtb_Switch_m3bd > ((uint8_T)0U)));

  /* If: '<S74>/If2' */
  if (rtb_RelationalOperator_l4uz)
  {
    /* Outputs for IfAction SubSystem: '<S74>/CalcDCSN_select_right_edge_para' incorporates:
     *  ActionPort: '<S86>/Action Port'
     */
    /* RelationalOperator: '<S131>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S86>/Selector'
     */
    rtb_RelationalOperator_g4mo = rtIsNaNF
      (VsMPFU_DataBus.road_edges[DCSN_subsystem_integrated_B.road_edges_index -
       1].c0_position);

    /* Switch: '<S131>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S86>/Selector'
     */
    if (rtb_RelationalOperator_g4mo)
    {
      /* Switch: '<S131>/Switch1' incorporates:
       *  Constant: '<S131>/Constant'
       *  RelationalOperator: '<S131>/Relational Operator1'
       *  UnitDelay: '<S131>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_bcxc))
      {
        rtb_Switch_k1o1 = 0.0F;
      }
      else
      {
        rtb_Switch_k1o1 = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_bcxc;
      }

      /* End of Switch: '<S131>/Switch1' */
    }
    else
    {
      rtb_Switch_k1o1 =
        VsMPFU_DataBus.road_edges[DCSN_subsystem_integrated_B.road_edges_index -
        1].c0_position;
    }

    /* End of Switch: '<S131>/Switch' */

    /* RelationalOperator: '<S132>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S86>/Selector'
     */
    rtb_RelationalOperator_f1ec = rtIsNaNF
      (VsMPFU_DataBus.road_edges[DCSN_subsystem_integrated_B.road_edges_index -
       1].c1_heading);

    /* RelationalOperator: '<S133>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S86>/Selector'
     */
    rtb_RelationalOperator_elnv = rtIsNaNF
      (VsMPFU_DataBus.road_edges[DCSN_subsystem_integrated_B.road_edges_index -
       1].c2_curvature);

    /* RelationalOperator: '<S134>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S86>/Selector'
     */
    rtb_RelationalOperator_cwas = rtIsNaNF
      (VsMPFU_DataBus.road_edges[DCSN_subsystem_integrated_B.road_edges_index -
       1].c3_curvature_derivative);

    /* RelationalOperator: '<S135>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S86>/Selector'
     */
    rtb_RelationalOperator_njbi = rtIsNaNF
      (VsMPFU_DataBus.road_edges[DCSN_subsystem_integrated_B.road_edges_index -
       1].distance_to_host);

    /* Logic: '<S86>/Logical Operator' */
    VbDCSN_right_edge_para_isNaN = ((((rtb_RelationalOperator_g4mo ||
      rtb_RelationalOperator_f1ec) || rtb_RelationalOperator_elnv) ||
      rtb_RelationalOperator_cwas) || rtb_RelationalOperator_njbi);

    /* Switch: '<S135>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S86>/Selector'
     */
    if (rtb_RelationalOperator_njbi)
    {
      /* Switch: '<S135>/Switch1' incorporates:
       *  Constant: '<S135>/Constant'
       *  RelationalOperator: '<S135>/Relational Operator1'
       *  UnitDelay: '<S135>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_hxfz))
      {
        quality = 0.0F;
      }
      else
      {
        quality = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_hxfz;
      }

      /* End of Switch: '<S135>/Switch1' */
    }
    else
    {
      quality =
        VsMPFU_DataBus.road_edges[DCSN_subsystem_integrated_B.road_edges_index -
        1].distance_to_host;
    }

    /* End of Switch: '<S135>/Switch' */

    /* SignalConversion: '<S86>/BusConversion_InsertedFor_right_edge_para_at_inport_0' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S86>/Selector'
     *  Switch: '<S136>/Switch'
     */
    quality_ksol = (real32_T)
      VsMPFU_DataBus.road_edges[DCSN_subsystem_integrated_B.road_edges_index - 1]
      .quality;

    /* Switch: '<S134>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S86>/Selector'
     */
    if (rtb_RelationalOperator_cwas)
    {
      /* Switch: '<S134>/Switch1' incorporates:
       *  Constant: '<S134>/Constant'
       *  RelationalOperator: '<S134>/Relational Operator1'
       *  UnitDelay: '<S134>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_fsl3))
      {
        rtb_Switch_psiv = 0.0F;
      }
      else
      {
        rtb_Switch_psiv = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_fsl3;
      }

      /* End of Switch: '<S134>/Switch1' */
    }
    else
    {
      rtb_Switch_psiv =
        VsMPFU_DataBus.road_edges[DCSN_subsystem_integrated_B.road_edges_index -
        1].c3_curvature_derivative;
    }

    /* End of Switch: '<S134>/Switch' */

    /* Switch: '<S133>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S86>/Selector'
     */
    if (rtb_RelationalOperator_elnv)
    {
      /* Switch: '<S133>/Switch1' incorporates:
       *  Constant: '<S133>/Constant'
       *  RelationalOperator: '<S133>/Relational Operator1'
       *  UnitDelay: '<S133>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_fmjv))
      {
        rtb_Switch_mhao = 0.0F;
      }
      else
      {
        rtb_Switch_mhao = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_fmjv;
      }

      /* End of Switch: '<S133>/Switch1' */
    }
    else
    {
      rtb_Switch_mhao =
        VsMPFU_DataBus.road_edges[DCSN_subsystem_integrated_B.road_edges_index -
        1].c2_curvature;
    }

    /* End of Switch: '<S133>/Switch' */

    /* Switch: '<S132>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S86>/Selector'
     */
    if (rtb_RelationalOperator_f1ec)
    {
      /* Switch: '<S132>/Switch1' incorporates:
       *  Constant: '<S132>/Constant'
       *  RelationalOperator: '<S132>/Relational Operator1'
       *  UnitDelay: '<S132>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_anes))
      {
        rtb_Switch_jvmn = 0.0F;
      }
      else
      {
        rtb_Switch_jvmn = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_anes;
      }

      /* End of Switch: '<S132>/Switch1' */
    }
    else
    {
      rtb_Switch_jvmn =
        VsMPFU_DataBus.road_edges[DCSN_subsystem_integrated_B.road_edges_index -
        1].c1_heading;
    }

    /* End of Switch: '<S132>/Switch' */

    /* SignalConversion: '<S86>/BusConversion_InsertedFor_right_edge_para_at_inport_0' */
    start_x_ceng = DCSN_subsystem_integrate_ConstB.TmpBufferAtConstantOutport1;

    /* SignalConversion: '<S86>/BusConversion_InsertedFor_right_edge_para_at_inport_0' */
    end_x_lbop = DCSN_subsystem_integrate_ConstB.TmpBufferAtConstant2Outport;

    /* Update for UnitDelay: '<S131>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_bcxc = rtb_Switch_k1o1;

    /* Update for UnitDelay: '<S135>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_hxfz = quality;

    /* Update for UnitDelay: '<S134>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_fsl3 = rtb_Switch_psiv;

    /* Update for UnitDelay: '<S133>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_fmjv = rtb_Switch_mhao;

    /* Update for UnitDelay: '<S132>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_anes = rtb_Switch_jvmn;

    /* End of Outputs for SubSystem: '<S74>/CalcDCSN_select_right_edge_para' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S74>/CalcDCSN_simu_right_edge_para' incorporates:
     *  ActionPort: '<S90>/Action Port'
     */
    /* SignalConversion: '<S90>/TmpBufferAtConstant1Outport1' incorporates:
     *  Constant: '<S90>/Constant1'
     */
    rtb_Switch_k1o1 = 0.0F;

    /* SignalConversion: '<S90>/TmpBufferAtConstant10Outport1' incorporates:
     *  Constant: '<S90>/Constant10'
     */
    quality = 0.0F;

    /* SignalConversion: '<S90>/TmpBufferAtConstant2Outport1' incorporates:
     *  Constant: '<S90>/Constant2'
     */
    rtb_Switch_jvmn = 0.0F;

    /* SignalConversion: '<S90>/TmpBufferAtConstant3Outport1' incorporates:
     *  Constant: '<S90>/Constant3'
     */
    rtb_Switch_mhao = 0.0F;

    /* SignalConversion: '<S90>/TmpBufferAtConstant4Outport1' incorporates:
     *  Constant: '<S90>/Constant4'
     */
    rtb_Switch_psiv = 0.0F;

    /* SignalConversion: '<S90>/TmpBufferAtConstant5Outport1' incorporates:
     *  Constant: '<S90>/Constant5'
     */
    start_x_ceng = 0.0F;

    /* SignalConversion: '<S90>/TmpBufferAtConstant7Outport1' incorporates:
     *  Constant: '<S90>/Constant7'
     */
    end_x_lbop = 0.0F;

    /* SignalConversion: '<S90>/TmpBufferAtConstant9Outport1' incorporates:
     *  Constant: '<S90>/Constant9'
     */
    quality_ksol = 0.0F;

    /* End of Outputs for SubSystem: '<S74>/CalcDCSN_simu_right_edge_para' */
  }

  /* End of If: '<S74>/If2' */

  /* If: '<S74>/If4' */
  if (VbDCSN_has_right_marker)
  {
    /* Outputs for IfAction SubSystem: '<S74>/CalcDCSN_select_right_marker_para' incorporates:
     *  ActionPort: '<S87>/Action Port'
     */
    /* RelationalOperator: '<S137>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S87>/Selector'
     */
    rtb_RelationalOperator_g4mo = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index
       - 1].c0_position);

    /* Switch: '<S137>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S87>/Selector'
     */
    if (rtb_RelationalOperator_g4mo)
    {
      /* Switch: '<S137>/Switch1' incorporates:
       *  Constant: '<S137>/Constant'
       *  RelationalOperator: '<S137>/Relational Operator1'
       *  UnitDelay: '<S137>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_nmi2))
      {
        rtb_Switch_et0b = 0.0F;
      }
      else
      {
        rtb_Switch_et0b = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_nmi2;
      }

      /* End of Switch: '<S137>/Switch1' */
    }
    else
    {
      rtb_Switch_et0b =
        VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index
        - 1].c0_position;
    }

    /* End of Switch: '<S137>/Switch' */

    /* RelationalOperator: '<S138>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S87>/Selector'
     */
    rtb_RelationalOperator_f1ec = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index
       - 1].c1_heading);

    /* RelationalOperator: '<S139>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S87>/Selector'
     */
    rtb_RelationalOperator_elnv = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index
       - 1].c2_curvature);

    /* RelationalOperator: '<S140>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S87>/Selector'
     */
    rtb_RelationalOperator_cwas = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index
       - 1].c3_curvature_derivative);

    /* RelationalOperator: '<S145>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S87>/Selector'
     */
    rtb_RelationalOperator_njbi = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index
       - 1].start_rel.x);

    /* RelationalOperator: '<S146>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S87>/Selector'
     */
    rtb_RelationalOperator_ehd0 = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index
       - 1].start_rel.y);

    /* RelationalOperator: '<S142>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S87>/Selector'
     */
    rtb_Compare_nkof = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index
       - 1].end_rel.x);

    /* RelationalOperator: '<S143>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S87>/Selector'
     */
    rtb_Compare_lebe = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index
       - 1].end_rel.y);

    /* RelationalOperator: '<S141>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S87>/Selector'
     */
    rtb_RelationalOperator_byg2 = rtIsNaNF
      (VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index
       - 1].distance_to_host);

    /* Logic: '<S87>/Logical Operator' */
    VbDCSN_right_marker_para_isNaN = ((((((((rtb_RelationalOperator_g4mo ||
      rtb_RelationalOperator_f1ec) || rtb_RelationalOperator_elnv) ||
      rtb_RelationalOperator_cwas) || rtb_RelationalOperator_njbi) ||
      rtb_RelationalOperator_ehd0) || rtb_Compare_nkof) || rtb_Compare_lebe) ||
      rtb_RelationalOperator_byg2);

    /* Switch: '<S141>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S87>/Selector'
     */
    if (rtb_RelationalOperator_byg2)
    {
      /* Switch: '<S141>/Switch1' incorporates:
       *  Constant: '<S141>/Constant'
       *  RelationalOperator: '<S141>/Relational Operator1'
       *  UnitDelay: '<S141>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_aygd))
      {
        rtb_Switch_dyus = 0.0F;
      }
      else
      {
        rtb_Switch_dyus = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_aygd;
      }

      /* End of Switch: '<S141>/Switch1' */
    }
    else
    {
      rtb_Switch_dyus =
        VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index
        - 1].distance_to_host;
    }

    /* End of Switch: '<S141>/Switch' */

    /* SignalConversion: '<S87>/BusConversion_InsertedFor_right_lane_marker_para_at_inport_0' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S87>/Selector'
     *  Switch: '<S144>/Switch'
     */
    quality_htk5 = (real32_T)
      VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index
      - 1].quality;

    /* Switch: '<S143>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S87>/Selector'
     */
    if (rtb_Compare_lebe)
    {
      /* Switch: '<S143>/Switch1' incorporates:
       *  Constant: '<S143>/Constant'
       *  RelationalOperator: '<S143>/Relational Operator1'
       *  UnitDelay: '<S143>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_e1pk))
      {
        rtb_Switch_l3dh = 0.0F;
      }
      else
      {
        rtb_Switch_l3dh = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_e1pk;
      }

      /* End of Switch: '<S143>/Switch1' */
    }
    else
    {
      rtb_Switch_l3dh =
        VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index
        - 1].end_rel.y;
    }

    /* End of Switch: '<S143>/Switch' */

    /* Switch: '<S142>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S87>/Selector'
     */
    if (rtb_Compare_nkof)
    {
      /* Switch: '<S142>/Switch1' incorporates:
       *  Constant: '<S142>/Constant'
       *  RelationalOperator: '<S142>/Relational Operator1'
       *  UnitDelay: '<S142>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_hrrg))
      {
        rtb_Switch_nkom = 0.0F;
      }
      else
      {
        rtb_Switch_nkom = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_hrrg;
      }

      /* End of Switch: '<S142>/Switch1' */
    }
    else
    {
      rtb_Switch_nkom =
        VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index
        - 1].end_rel.x;
    }

    /* End of Switch: '<S142>/Switch' */

    /* Switch: '<S146>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S87>/Selector'
     */
    if (rtb_RelationalOperator_ehd0)
    {
      /* Switch: '<S146>/Switch1' incorporates:
       *  Constant: '<S146>/Constant'
       *  RelationalOperator: '<S146>/Relational Operator1'
       *  UnitDelay: '<S146>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_mp0s))
      {
        rtb_Switch_g34g = 0.0F;
      }
      else
      {
        rtb_Switch_g34g = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_mp0s;
      }

      /* End of Switch: '<S146>/Switch1' */
    }
    else
    {
      rtb_Switch_g34g =
        VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index
        - 1].start_rel.y;
    }

    /* End of Switch: '<S146>/Switch' */

    /* Switch: '<S145>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S87>/Selector'
     */
    if (rtb_RelationalOperator_njbi)
    {
      /* Switch: '<S145>/Switch1' incorporates:
       *  Constant: '<S145>/Constant'
       *  RelationalOperator: '<S145>/Relational Operator1'
       *  UnitDelay: '<S145>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_h2o1))
      {
        rtb_Switch_eq4s = 0.0F;
      }
      else
      {
        rtb_Switch_eq4s = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_h2o1;
      }

      /* End of Switch: '<S145>/Switch1' */
    }
    else
    {
      rtb_Switch_eq4s =
        VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index
        - 1].start_rel.x;
    }

    /* End of Switch: '<S145>/Switch' */

    /* Switch: '<S140>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S87>/Selector'
     */
    if (rtb_RelationalOperator_cwas)
    {
      /* Switch: '<S140>/Switch1' incorporates:
       *  Constant: '<S140>/Constant'
       *  RelationalOperator: '<S140>/Relational Operator1'
       *  UnitDelay: '<S140>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_ldyw))
      {
        end_x = 0.0F;
      }
      else
      {
        end_x = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_ldyw;
      }

      /* End of Switch: '<S140>/Switch1' */
    }
    else
    {
      end_x =
        VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index
        - 1].c3_curvature_derivative;
    }

    /* End of Switch: '<S140>/Switch' */

    /* Switch: '<S139>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S87>/Selector'
     */
    if (rtb_RelationalOperator_elnv)
    {
      /* Switch: '<S139>/Switch1' incorporates:
       *  Constant: '<S139>/Constant'
       *  RelationalOperator: '<S139>/Relational Operator1'
       *  UnitDelay: '<S139>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_gmxm))
      {
        start_x = 0.0F;
      }
      else
      {
        start_x = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_gmxm;
      }

      /* End of Switch: '<S139>/Switch1' */
    }
    else
    {
      start_x =
        VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index
        - 1].c2_curvature;
    }

    /* End of Switch: '<S139>/Switch' */

    /* Switch: '<S138>/Switch' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S87>/Selector'
     */
    if (rtb_RelationalOperator_f1ec)
    {
      /* Switch: '<S138>/Switch1' incorporates:
       *  Constant: '<S138>/Constant'
       *  RelationalOperator: '<S138>/Relational Operator1'
       *  UnitDelay: '<S138>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_dvap))
      {
        rtb_Switch_crnn = 0.0F;
      }
      else
      {
        rtb_Switch_crnn = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_dvap;
      }

      /* End of Switch: '<S138>/Switch1' */
    }
    else
    {
      rtb_Switch_crnn =
        VsMPFU_DataBus.lane_markers[DCSN_subsystem_integrated_B.lane_marker_index
        - 1].c1_heading;
    }

    /* End of Switch: '<S138>/Switch' */

    /* Update for UnitDelay: '<S137>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_nmi2 = rtb_Switch_et0b;

    /* Update for UnitDelay: '<S141>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_aygd = rtb_Switch_dyus;

    /* Update for UnitDelay: '<S143>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_e1pk = rtb_Switch_l3dh;

    /* Update for UnitDelay: '<S142>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_hrrg = rtb_Switch_nkom;

    /* Update for UnitDelay: '<S146>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_mp0s = rtb_Switch_g34g;

    /* Update for UnitDelay: '<S145>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_h2o1 = rtb_Switch_eq4s;

    /* Update for UnitDelay: '<S140>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_ldyw = end_x;

    /* Update for UnitDelay: '<S139>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_gmxm = start_x;

    /* Update for UnitDelay: '<S138>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_dvap = rtb_Switch_crnn;

    /* End of Outputs for SubSystem: '<S74>/CalcDCSN_select_right_marker_para' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S74>/CalcDCSN_simu_right_marker_para' incorporates:
     *  ActionPort: '<S91>/Action Port'
     */
    /* SignalConversion: '<S91>/TmpBufferAtConstant1Outport1' incorporates:
     *  Constant: '<S91>/Constant1'
     */
    rtb_Switch_et0b = 0.0F;

    /* SignalConversion: '<S91>/TmpBufferAtConstant10Outport1' incorporates:
     *  Constant: '<S91>/Constant10'
     */
    rtb_Switch_dyus = 0.0F;

    /* SignalConversion: '<S91>/TmpBufferAtConstant2Outport1' incorporates:
     *  Constant: '<S91>/Constant2'
     */
    rtb_Switch_crnn = 0.0F;

    /* SignalConversion: '<S91>/TmpBufferAtConstant3Outport1' incorporates:
     *  Constant: '<S91>/Constant3'
     */
    start_x = 0.0F;

    /* SignalConversion: '<S91>/TmpBufferAtConstant4Outport1' incorporates:
     *  Constant: '<S91>/Constant4'
     */
    end_x = 0.0F;

    /* SignalConversion: '<S91>/TmpBufferAtConstant5Outport1' incorporates:
     *  Constant: '<S91>/Constant5'
     */
    rtb_Switch_eq4s = 0.0F;

    /* SignalConversion: '<S91>/TmpBufferAtConstant6Outport1' incorporates:
     *  Constant: '<S91>/Constant6'
     */
    rtb_Switch_g34g = 0.0F;

    /* SignalConversion: '<S91>/TmpBufferAtConstant7Outport1' incorporates:
     *  Constant: '<S91>/Constant7'
     */
    rtb_Switch_nkom = 0.0F;

    /* SignalConversion: '<S91>/TmpBufferAtConstant8Outport1' incorporates:
     *  Constant: '<S91>/Constant8'
     */
    rtb_Switch_l3dh = 0.0F;

    /* SignalConversion: '<S91>/TmpBufferAtConstant9Outport1' incorporates:
     *  Constant: '<S91>/Constant9'
     */
    quality_htk5 = 0.0F;

    /* End of Outputs for SubSystem: '<S74>/CalcDCSN_simu_right_marker_para' */
  }

  /* End of If: '<S74>/If4' */

  /* RelationalOperator: '<S74>/Relational Operator1' */
  rtb_RelationalOperator_g4mo = (quality <= rtb_Switch_dyus);

  /* Logic: '<S74>/Logical Operator7' */
  rtb_RelationalOperator_f1ec = (rtb_RelationalOperator_l4uz &&
    VbDCSN_has_right_marker);

  /* Switch: '<S74>/Switch4' incorporates:
   *  Switch: '<S74>/Switch5'
   */
  if (rtb_RelationalOperator_f1ec)
  {
    /* Switch: '<S74>/Switch6' */
    if (rtb_RelationalOperator_g4mo)
    {
    }
    else
    {
      quality_ksol = quality_htk5;
    }
  }
  else if (rtb_RelationalOperator_l4uz)
  {
  }
  else
  {
    quality_ksol = quality_htk5;
  }

  /* Constant: '<S79>/KfDCSN_Pct_lane_marker_valid_quality' */
  rtb_Merge_mgdo = (real32_T)KfDCSN_Pct_lane_marker_valid_quality;

  /* Switch: '<S74>/Switch4' incorporates:
   *  Switch: '<S74>/Switch5'
   */
  if (rtb_RelationalOperator_f1ec)
  {
    /* Switch: '<S74>/Switch6' */
    if (rtb_RelationalOperator_g4mo)
    {
      rtb_end_x_bssg = end_x_lbop;
    }
    else
    {
      rtb_end_x_bssg = rtb_Switch_nkom;
    }
  }
  else if (rtb_RelationalOperator_l4uz)
  {
    /* Switch: '<S74>/Switch5' */
    rtb_end_x_bssg = end_x_lbop;
  }
  else
  {
    rtb_end_x_bssg = rtb_Switch_nkom;
  }

  if (rtb_RelationalOperator_f1ec)
  {
    /* Switch: '<S74>/Switch6' */
    if (rtb_RelationalOperator_g4mo)
    {
      rtb_start_x_fksj = start_x_ceng;
    }
    else
    {
      rtb_start_x_fksj = rtb_Switch_eq4s;
    }
  }
  else if (rtb_RelationalOperator_l4uz)
  {
    /* Switch: '<S74>/Switch5' */
    rtb_start_x_fksj = start_x_ceng;
  }
  else
  {
    rtb_start_x_fksj = rtb_Switch_eq4s;
  }

  if (rtb_RelationalOperator_f1ec)
  {
    /* Switch: '<S74>/Switch6' */
    if (rtb_RelationalOperator_g4mo)
    {
      rtb_c3_a4vy = rtb_Switch_psiv;
    }
    else
    {
      rtb_c3_a4vy = end_x;
    }
  }
  else if (rtb_RelationalOperator_l4uz)
  {
    /* Switch: '<S74>/Switch5' */
    rtb_c3_a4vy = rtb_Switch_psiv;
  }
  else
  {
    rtb_c3_a4vy = end_x;
  }

  if (rtb_RelationalOperator_f1ec)
  {
    /* Switch: '<S74>/Switch6' */
    if (rtb_RelationalOperator_g4mo)
    {
      rtb_c2_ckxv = rtb_Switch_mhao;
    }
    else
    {
      rtb_c2_ckxv = start_x;
    }
  }
  else if (rtb_RelationalOperator_l4uz)
  {
    /* Switch: '<S74>/Switch5' */
    rtb_c2_ckxv = rtb_Switch_mhao;
  }
  else
  {
    rtb_c2_ckxv = start_x;
  }

  if (rtb_RelationalOperator_f1ec)
  {
    /* Switch: '<S74>/Switch6' */
    if (rtb_RelationalOperator_g4mo)
    {
      rtb_c1_dywv = rtb_Switch_jvmn;
    }
    else
    {
      rtb_c1_dywv = rtb_Switch_crnn;
    }
  }
  else if (rtb_RelationalOperator_l4uz)
  {
    /* Switch: '<S74>/Switch5' */
    rtb_c1_dywv = rtb_Switch_jvmn;
  }
  else
  {
    rtb_c1_dywv = rtb_Switch_crnn;
  }

  if (rtb_RelationalOperator_f1ec)
  {
    /* Switch: '<S74>/Switch6' */
    if (rtb_RelationalOperator_g4mo)
    {
      rtb_c0_ifjz = rtb_Switch_k1o1;
    }
    else
    {
      rtb_c0_ifjz = rtb_Switch_et0b;
    }
  }
  else if (rtb_RelationalOperator_l4uz)
  {
    /* Switch: '<S74>/Switch5' */
    rtb_c0_ifjz = rtb_Switch_k1o1;
  }
  else
  {
    rtb_c0_ifjz = rtb_Switch_et0b;
  }

  /* If: '<S79>/If' incorporates:
   *  Constant: '<S74>/KfDCSN_a_curvature_sample_point1'
   *  Constant: '<S74>/KfDCSN_d_arc_length_integration_step3'
   *  Logic: '<S74>/Logical Operator5'
   *  Logic: '<S79>/Logical Operator'
   *  RelationalOperator: '<S79>/Relational Operator'
   */
  if ((rtb_RelationalOperator_l4uz || VbDCSN_has_right_marker) && (quality_ksol >=
       rtb_Merge_mgdo))
  {
    /* Outputs for IfAction SubSystem: '<S79>/If Action Subsystem' incorporates:
     *  ActionPort: '<S104>/Action Port'
     */
    DCSN_subsyste_IfActionSubsystem(VfDCSN_SpdLimt_look_ahead_dis, rtb_c3_a4vy,
      rtb_c2_ckxv, rtb_c1_dywv, rtb_c0_ifjz, rtb_start_x_fksj, rtb_end_x_bssg,
      KfDCSN_d_arc_length_integration_step, KfDCSN_a_curvature_sample_point,
      &rtb_Merge_mgdo, &DCSN_subsystem_integrated_B.IfActionSubsystem_j2my,
      &DCSN_subsystem_integrated_DW.IfActionSubsystem_j2my);

    /* End of Outputs for SubSystem: '<S79>/If Action Subsystem' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S79>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S105>/Action Port'
     */
    DCSN_subsyst_IfActionSubsystem1(&rtb_Merge_mgdo);

    /* End of Outputs for SubSystem: '<S79>/If Action Subsystem1' */
  }

  /* End of If: '<S79>/If' */

  /* CombinatorialLogic: '<S190>/Logic' incorporates:
   *  Constant: '<S72>/KbDCSN_change_lane_enable'
   *  DataTypeConversion: '<S70>/Data Type Conversion'
   *  DataTypeConversion: '<S70>/Data Type Conversion1'
   *  Delay: '<S185>/Delay'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  Logic: '<S185>/Logical Operator'
   *  Logic: '<S185>/Logical Operator1'
   *  Logic: '<S185>/Logical Operator14'
   *  Logic: '<S185>/Logical Operator15'
   *  Logic: '<S185>/Logical Operator16'
   *  Logic: '<S185>/Logical Operator17'
   *  Logic: '<S185>/Logical Operator18'
   *  Logic: '<S185>/Logical Operator2'
   *  Logic: '<S185>/Logical Operator21'
   *  Logic: '<S185>/Logical Operator3'
   *  Logic: '<S185>/Logical Operator4'
   *  Logic: '<S185>/Logical Operator5'
   *  Logic: '<S185>/Logical Operator6'
   *  Logic: '<S185>/Logical Operator7'
   *  Logic: '<S185>/Logical Operator8'
   *  Logic: '<S72>/Logical Operator3'
   *  Memory: '<S190>/Memory'
   *  UnitDelay: '<S185>/Unit Delay'
   *  UnitDelay: '<S185>/Unit Delay1'
   *  UnitDelay: '<S185>/Unit Delay2'
   *  UnitDelay: '<S185>/Unit Delay3'
   *  UnitDelay: '<S185>/Unit Delay4'
   *  UnitDelay: '<S185>/Unit Delay5'
   *  UnitDelay: '<S185>/Unit Delay6'
   *  UnitDelay: '<S185>/Unit Delay7'
   *  UnitDelay: '<S185>/Unit Delay8'
   */
  rtb_RelationalOperator_l4uz = DCSN_subsystem_integrate_ConstP.pooled30
    [(((((uint32_T)
         ((((DCSN_subsystem_integrated_B.EnablingFlags_Group.alca_feature_enable)
            && KbDCSN_change_lane_enable) &&
           (((((((VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState) &&
                 (!DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_cb10)) &&
                (!VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState)) &&
               (!DCSN_subsystem_integrated_DW.UnitDelay1_DSTATE_a53f)) ||
              ((((VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState) &&
                 (!DCSN_subsystem_integrated_DW.UnitDelay3_DSTATE)) &&
                (!VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState)) &&
               (!DCSN_subsystem_integrated_DW.UnitDelay4_DSTATE))) ||
             ((((VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState) &&
                (DCSN_subsystem_integrated_DW.UnitDelay5_DSTATE_nwlx)) &&
               (!VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState)) &&
              (DCSN_subsystem_integrated_DW.UnitDelay6_DSTATE))) ||
            ((((VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState) &&
               (DCSN_subsystem_integrated_DW.UnitDelay7_DSTATE)) &&
              (!VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState)) &&
             (DCSN_subsystem_integrated_DW.UnitDelay8_DSTATE)))) ? 1 : 0)) << 1)
       + ((uint32_T)
          ((((VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState ==
              VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState) ||
             (DCSN_subsystem_integrated_DW.Delay_DSTATE[0])) ||
            (DCSN_subsystem_integrated_DW.UnitDelay2_DSTATE_nwfs)) ? 1 : 0))) <<
      1) + (DCSN_subsystem_integrated_DW.Memory_PreviousInput ? 1U : 0U)];

  /* Switch: '<S187>/Switch1' incorporates:
   *  Constant: '<S187>/Constant4'
   */
  if (rtb_RelationalOperator_l4uz)
  {
    /* Sum: '<S187>/Sum' incorporates:
     *  Constant: '<S187>/CallFrequencyOneLoop'
     *  UnitDelay: '<S187>/UnitDelay'
     */
    rtb_CurrentTick = (uint16_T)(((uint32_T)
      DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_ch4m) + ((uint32_T)
      ((uint16_T)1U)));

    /* Saturate: '<S187>/Saturation' */
    if (rtb_CurrentTick < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S187>/Saturation' */
  }
  else
  {
    rtb_CurrentTick = ((uint16_T)0U);
  }

  /* End of Switch: '<S187>/Switch1' */

  /* RelationalOperator: '<S187>/RelationalOperator1' incorporates:
   *  Constant: '<S185>/KfDCSN_t_usr_change_lane_delay'
   *  DataTypeConversion: '<S185>/Data Type Conversion'
   *  Gain: '<S185>/Gain'
   */
  VbDCSN_CL_delay_finished = (rtb_CurrentTick > ((uint16_T)((real32_T)(100.0F *
    KfDCSN_t_usr_change_lane_delay))));

  /* RelationalOperator: '<S185>/Relational Operator1' incorporates:
   *  Constant: '<S185>/Constant6'
   *  Inport: '<Root>/ALCA_DataBus'
   */
  rtb_RelationalOperator_elnv = (VsALCA_DataBus.state == ALCA_state_Standby);

  /* Switch: '<S185>/Switch4' incorporates:
   *  Constant: '<S185>/Constant3'
   *  Logic: '<S185>/Logical Operator9'
   */
  if (rtb_RelationalOperator_elnv && VbDCSN_CL_delay_finished)
  {
    /* Switch: '<S185>/Switch2' incorporates:
     *  Constant: '<S185>/Constant4'
     *  Constant: '<S185>/Constant5'
     *  DataTypeConversion: '<S70>/Data Type Conversion'
     *  Inport: '<Root>/COMM_CANR_DataBus'
     */
    if (VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState)
    {
      rtb_Switch4_exki = LEFT;
    }
    else
    {
      rtb_Switch4_exki = RIGHT;
    }

    /* End of Switch: '<S185>/Switch2' */
  }
  else
  {
    rtb_Switch4_exki = FORWARD;
  }

  /* End of Switch: '<S185>/Switch4' */

  /* Switch: '<S73>/Switch4' incorporates:
   *  Constant: '<S73>/Constant5'
   *  Constant: '<S73>/Constant7'
   *  DataTypeConversion: '<S73>/Data Type Conversion'
   */
  if (KbDCSN_change_lane_man_enbl)
  {
    VeDCSN_change_lane_req_side = (EnumDCSN_driving_direction)
      KeDCSN_change_lane_req_side_man_value;
  }
  else
  {
    VeDCSN_change_lane_req_side = rtb_Switch4_exki;
  }

  /* End of Switch: '<S73>/Switch4' */

  /* MinMax: '<S74>/MinMax' */
  if ((rtb_Abs > rtb_Merge_mgdo) || (rtIsNaNF(rtb_Merge_mgdo)))
  {
    VfDCSN_largest_curvature_ahead = rtb_Abs;
  }
  else
  {
    VfDCSN_largest_curvature_ahead = rtb_Merge_mgdo;
  }

  /* End of MinMax: '<S74>/MinMax' */

  /* Lookup_n-D: '<S74>/1-D Lookup Table' */
  VfDCSN_speed_limit_curvature = KtDCSN_v_speed_limit_curve[plook_u32f_bincka
    (VfDCSN_largest_curvature_ahead, KtDCSN_c_speed_limit_curve_axis, 20U)];

  /* Logic: '<S67>/Logical Operator1' incorporates:
   *  Constant: '<S76>/Constant'
   *  Constant: '<S77>/Constant'
   *  RelationalOperator: '<S76>/Compare'
   *  RelationalOperator: '<S77>/Compare'
   */
  rtb_RelationalOperator_cwas = ((VfDCSN_speed_limit_curvature > 0.0F) &&
    (VfDCSN_speed_limit_curvature < 38.89F));

  /* Logic: '<S72>/Logical Operator' incorporates:
   *  Constant: '<S72>/KbDCSN_speed_limit_enable'
   */
  VbDCSN_speed_limit_enabled = (KbDCSN_speed_limit_enable &&
    (DCSN_subsystem_integrated_B.EnablingFlags_Group.acc_feature_enable));

  /* Switch: '<S67>/Switch' incorporates:
   *  Constant: '<S67>/Constant3'
   */
  if (VbDCSN_speed_limit_enabled)
  {
    /* Switch: '<S67>/Switch9' incorporates:
     *  Constant: '<S67>/Constant8'
     *  Constant: '<S67>/Constant9'
     */
    if (rtb_RelationalOperator_cwas)
    {
      rtb_Switch_abos = LIMIT_FOR_CURVATURE;
    }
    else
    {
      rtb_Switch_abos = NO_LIMIT;
    }

    /* End of Switch: '<S67>/Switch9' */
  }
  else
  {
    rtb_Switch_abos = NO_LIMIT;
  }

  /* End of Switch: '<S67>/Switch' */

  /* Switch: '<S67>/Switch1' incorporates:
   *  Constant: '<S67>/Constant'
   */
  if (VbDCSN_speed_limit_enabled)
  {
    /* Switch: '<S67>/Switch7' incorporates:
     *  Constant: '<S67>/Constant6'
     */
    if (rtb_RelationalOperator_cwas)
    {
      start_x_ceng = VfDCSN_speed_limit_curvature;
    }
    else
    {
      start_x_ceng = 70.0F;
    }

    /* End of Switch: '<S67>/Switch7' */
  }
  else
  {
    start_x_ceng = 70.0F;
  }

  /* End of Switch: '<S67>/Switch1' */

  /* Switch: '<S66>/Switch' incorporates:
   *  Constant: '<S66>/Constant'
   *  Constant: '<S72>/Constant'
   *  Constant: '<S72>/KbDCSN_overspeed_warning_enable'
   *  Logic: '<S72>/Logical Operator2'
   */
  if ((true) && KbDCSN_overspeed_warning_enable)
  {
    /* Switch: '<S66>/Switch1' incorporates:
     *  Constant: '<S66>/Constant1'
     *  Constant: '<S66>/Constant2'
     *  Constant: '<S66>/KbDCSN_enable_warning_no_input'
     *  Constant: '<S66>/KfDCSN_v_overspeed_warning_extra'
     *  RelationalOperator: '<S66>/Relational Operator'
     *  RelationalOperator: '<S66>/Relational Operator1'
     *  Sum: '<S66>/Sum'
     *  Switch: '<S66>/Switch2'
     */
    if (NO_LIMIT != rtb_Switch_abos)
    {
      VbDCSN_overspeed_warning = (VfDCSN_vehicle_speed_egmo > (start_x_ceng +
        KfDCSN_v_overspeed_warning_extra));
    }
    else if (KbDCSN_enable_warning_no_input)
    {
      /* Switch: '<S66>/Switch2' incorporates:
       *  Constant: '<S66>/KfDCSN_v_default_warning_speed'
       *  Constant: '<S66>/KfDCSN_v_overspeed_warning_extra1'
       *  RelationalOperator: '<S66>/Relational Operator2'
       *  Sum: '<S66>/Sum1'
       */
      VbDCSN_overspeed_warning = (VfDCSN_vehicle_speed_egmo >
        (KfDCSN_v_default_warning_speed + KfDCSN_v_overspeed_warning_extra));
    }
    else
    {
      VbDCSN_overspeed_warning = false;
    }

    /* End of Switch: '<S66>/Switch1' */
  }
  else
  {
    VbDCSN_overspeed_warning = false;
  }

  /* End of Switch: '<S66>/Switch' */

  /* Outputs for Iterator SubSystem: '<S160>/CalcDCSN_select_ego_lane_stop_line' incorporates:
   *  WhileIterator: '<S163>/While Iterator'
   */
  s80_iter = 1;
  do
  {
    rtb_RelationalOperator_cwas = (VsMPFU_DataBus.stop_lines[s80_iter - 1].
      lane_index == ((uint8_T)0U));
    if (rtb_RelationalOperator_cwas)
    {
      DCSN_subsystem_integrated_B.stop_lines_index = s80_iter;
    }

    s80_iter++;
  }
  while ((!rtb_RelationalOperator_cwas) && (s80_iter <= 4));

  /* End of Outputs for SubSystem: '<S160>/CalcDCSN_select_ego_lane_stop_line' */

  /* RelationalOperator: '<S184>/Relational Operator' */
  VbDCSN_num_stop_lines_isNaN = false;

  /* Switch: '<S184>/Switch' incorporates:
   *  Inport: '<Root>/MPFU_DataBus'
   */
  if (VbDCSN_num_stop_lines_isNaN)
  {
  }
  else
  {
    VfDCSN_mpfu_num_stop_lines = VsMPFU_DataBus.num_stop_lines;
  }

  /* End of Switch: '<S184>/Switch' */

  /* Logic: '<S160>/Logical Operator2' incorporates:
   *  Constant: '<S164>/Constant'
   *  Constant: '<S165>/Constant'
   *  RelationalOperator: '<S164>/Compare'
   *  RelationalOperator: '<S165>/Compare'
   */
  VbDCSN_has_valid_stop_line = ((DCSN_subsystem_integrated_B.stop_lines_index >
    0) && (VfDCSN_mpfu_num_stop_lines > ((uint8_T)0U)));

  /* If: '<S160>/If1' */
  if (VbDCSN_has_valid_stop_line)
  {
    /* Outputs for IfAction SubSystem: '<S160>/select_stop_line_distance' incorporates:
     *  ActionPort: '<S166>/Action Port'
     */
    /* RelationalOperator: '<S170>/Relational Operator' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S166>/Selector'
     */
    rtb_RelationalOperator_cwas = rtIsNaNF
      (VsMPFU_DataBus.stop_lines[DCSN_subsystem_integrated_B.stop_lines_index -
       1].position_s);

    /* Switch: '<S170>/Switch' incorporates:
     *  Constant: '<S170>/KfDCSN_d_rearaxle_frontbump'
     *  Constant: '<S170>/KfDCSN_d_stop_distance_buffer'
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S166>/Selector'
     *  Sum: '<S170>/Add'
     */
    if (rtb_RelationalOperator_cwas)
    {
      /* Switch: '<S170>/Switch1' incorporates:
       *  Constant: '<S170>/Constant'
       *  RelationalOperator: '<S170>/Relational Operator1'
       *  UnitDelay: '<S170>/Unit Delay'
       */
      if (rtIsNaNF(DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_df2f))
      {
        end_x_lbop = 0.0F;
      }
      else
      {
        end_x_lbop = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_df2f;
      }

      /* End of Switch: '<S170>/Switch1' */
    }
    else
    {
      end_x_lbop =
        (VsMPFU_DataBus.stop_lines[DCSN_subsystem_integrated_B.stop_lines_index
         - 1].position_s - KfDCSN_d_stop_distance_buffer) -
        KfDCSN_d_rearaxle_frontbump;
    }

    /* End of Switch: '<S170>/Switch' */

    /* SignalConversion: '<S166>/OutportBufferForraw_stop_line_distance' */
    VfDCSN_raw_stop_line_distance = end_x_lbop;

    /* SignalConversion: '<S166>/OutportBufferForstop_line_distance_isNaN' */
    VbDCSN_stop_line_distance_isNaN = rtb_RelationalOperator_cwas;

    /* Update for UnitDelay: '<S170>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_df2f = end_x_lbop;

    /* End of Outputs for SubSystem: '<S160>/select_stop_line_distance' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S160>/simu_stop_line_distance' incorporates:
     *  ActionPort: '<S167>/Action Port'
     */
    /* SignalConversion: '<S167>/OutportBufferForraw_stop_sign_distance' incorporates:
     *  Constant: '<S167>/Constant'
     */
    VfDCSN_raw_stop_line_distance = 0.0F;

    /* SignalConversion: '<S167>/OutportBufferForstop_sign_distance_isNaN' incorporates:
     *  Constant: '<S167>/Constant1'
     */
    VbDCSN_stop_line_distance_isNaN = false;

    /* End of Outputs for SubSystem: '<S160>/simu_stop_line_distance' */
  }

  /* End of If: '<S160>/If1' */

  /* UnitDelay: '<S162>/Unit Delay' */
  rtb_Abs = DCSN_subsystem_integrated_B.stop_distance;

  /* Logic: '<S70>/Logical Operator' incorporates:
   *  Constant: '<S70>/Constant'
   *  Constant: '<S70>/Constant1'
   *  Inport: '<Root>/ACCS_DataBus'
   *  RelationalOperator: '<S70>/Relational Operator'
   *  RelationalOperator: '<S70>/Relational Operator1'
   */
  VbDCSN_accs_stop_finished = ((VsACCS_DataBus.VeACCS_RunStatus ==
    ACCS_status_TempStop) || (VsACCS_DataBus.VeACCS_RunStatus ==
    ACCS_status_Stop));

  /* Logic: '<S162>/Logical Operator1' incorporates:
   *  Constant: '<S162>/KfDCSN_d_stop_finished_dis'
   *  Constant: '<S175>/Constant'
   *  RelationalOperator: '<S162>/Relational Operator5'
   *  RelationalOperator: '<S175>/Compare'
   */
  VbDCSN_raw_stop_finished = (((rtb_Abs >= 0.0F) && (rtb_Abs <=
    KfDCSN_d_stop_finished_dis)) && VbDCSN_accs_stop_finished);

  /* DiscreteIntegrator: '<S172>/Discrete-Time Integrator' */
  if ((VbDCSN_raw_stop_finished &&
       (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_PrevRese <= 0)) ||
      ((!VbDCSN_raw_stop_finished) &&
       (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_PrevRese == 1)))
  {
    DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DSTATE = ((uint16_T)0U);
  }

  if (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DSTATE >= ((uint16_T)
       2000U))
  {
    DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DSTATE = ((uint16_T)
      2000U);
  }
  else
  {
    if (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DSTATE <= ((uint16_T)
         0U))
    {
      DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DSTATE = ((uint16_T)0U);
    }
  }

  /* Switch: '<S172>/Switch' incorporates:
   *  Constant: '<S172>/Constant'
   */
  if (VbDCSN_raw_stop_finished)
  {
    /* Switch: '<S172>/Switch1' incorporates:
     *  Constant: '<S172>/Constant1'
     *  Constant: '<S172>/Constant2'
     *  Constant: '<S172>/KfDCSN_t_stop_req_hold'
     *  DiscreteIntegrator: '<S172>/Discrete-Time Integrator'
     *  Gain: '<S172>/Gain'
     *  RelationalOperator: '<S172>/Relational Operator'
     */
    if (((real32_T)DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DSTATE) >=
        (100.0F * KfDCSN_t_stop_req_hold))
    {
      VbDCSN_hold_stop_finished = true;
    }
    else
    {
      VbDCSN_hold_stop_finished = false;
    }

    /* End of Switch: '<S172>/Switch1' */
  }
  else
  {
    VbDCSN_hold_stop_finished = false;
  }

  /* End of Switch: '<S172>/Switch' */

  /* Product: '<S162>/Product2' incorporates:
   *  Constant: '<S162>/Constant1'
   *  Constant: '<S162>/KfDCSN_d_stop_unsuccess_Thrsh1'
   *  Product: '<S162>/Product'
   */
  quality = KfDCSN_d_stop_unsuccess_Thrsh * (-1.0F);

  /* Logic: '<S162>/Logical Operator2' incorporates:
   *  Constant: '<S176>/Constant'
   *  Product: '<S162>/Product2'
   *  RelationalOperator: '<S162>/Relational Operator4'
   *  RelationalOperator: '<S176>/Compare'
   */
  VbDCSN_raw_stop_finished_late = (((rtb_Abs < 0.0F) && (rtb_Abs > quality)) &&
    VbDCSN_accs_stop_finished);

  /* DiscreteIntegrator: '<S173>/Discrete-Time Integrator' */
  if ((VbDCSN_raw_stop_finished_late &&
       (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_Pre_jtbt <= 0)) ||
      ((!VbDCSN_raw_stop_finished_late) &&
       (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_Pre_jtbt == 1)))
  {
    DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_ky0g = ((uint16_T)0U);
  }

  if (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_ky0g >= ((uint16_T)
       2000U))
  {
    DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_ky0g = ((uint16_T)
      2000U);
  }
  else
  {
    if (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_ky0g <=
        ((uint16_T)0U))
    {
      DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_ky0g = ((uint16_T)
        0U);
    }
  }

  /* Logic: '<S72>/Logical Operator1' incorporates:
   *  Constant: '<S72>/KbDCSN_stop_request_enable'
   */
  VbDCSN_stop_request_enabled =
    ((DCSN_subsystem_integrated_B.EnablingFlags_Group.acc_feature_enable) &&
     KbDCSN_stop_request_enable);

  /* Logic: '<S162>/Logical Operator' incorporates:
   *  Constant: '<S162>/KfDCSN_d_Thrsh_request_stop'
   *  Constant: '<S174>/Constant'
   *  RelationalOperator: '<S162>/Relational Operator'
   *  RelationalOperator: '<S174>/Compare'
   */
  VbDCSN_should_send_stop_req = ((VfDCSN_raw_stop_line_distance > 0.0F) &&
    (VfDCSN_raw_stop_line_distance <= KfDCSN_d_Thrsh_request_stop));

  /* Logic: '<S162>/Logical Operator3' incorporates:
   *  Constant: '<S162>/KfDCSN_d_stop_close_Thrsh'
   *  Constant: '<S177>/Constant'
   *  RelationalOperator: '<S162>/Relational Operator1'
   *  RelationalOperator: '<S177>/Compare'
   */
  VbDCSN_stop_line_is_close = ((VfDCSN_raw_stop_line_distance > 0.0F) &&
    (VfDCSN_raw_stop_line_distance <= KfDCSN_d_stop_close_Thrsh));

  /* RelationalOperator: '<S162>/Relational Operator2' */
  VbDCSN_stop_unsuccess = (rtb_Abs <= quality);

  /* Outputs for Enabled SubSystem: '<S161>/StopDis' incorporates:
   *  EnablePort: '<S171>/Enable'
   */
  /* Product: '<S162>/Product1' incorporates:
   *  Constant: '<S162>/KfDCSN_t_sample_time'
   *  Product: '<S171>/Product'
   */
  quality = VfDCSN_vehicle_speed_egmo * KfDCSN_t_sample_time;

  /* End of Outputs for SubSystem: '<S161>/StopDis' */

  /* Chart: '<S162>/DtrmnDCSN_StopModeManager' incorporates:
   *  Constant: '<S162>/Constant2'
   *  Constant: '<S162>/KfDCSN_d_stop_cleared_Thrsh'
   *  Product: '<S162>/Product1'
   *  Product: '<S162>/Product3'
   */
  if (((uint32_T)DCSN_subsystem_integrated_DW.is_active_c3_DCSN_subsystem_int) ==
      0U)
  {
    DCSN_subsystem_integrated_DW.is_active_c3_DCSN_subsystem_int = 1U;
    DCSN_subsystem_integrated_DW.is_c3_DCSN_subsystem_integrated =
      DCSN_sub_IN_StopRequestDisabled;
    VeDCSN_stop_request_mode = NotEnabled;
    rtb_RelationalOperator_njbi = false;
    DCSN_subsystem_integrated_B.stop_distance = 0.0F;
  }
  else if (((uint32_T)
            DCSN_subsystem_integrated_DW.is_c3_DCSN_subsystem_integrated) ==
           DCSN_sub_IN_StopRequestDisabled)
  {
    VeDCSN_stop_request_mode = NotEnabled;
    rtb_RelationalOperator_njbi = false;
    if (VbDCSN_stop_request_enabled)
    {
      DCSN_subsystem_integrated_DW.is_c3_DCSN_subsystem_integrated =
        DCSN_subs_IN_StopRequestEnabled;
      DCSN_subsystem_integrated_DW.is_StopRequestEnabled =
        DCSN_su_IN_WaitForValidStopLine;
      VeDCSN_stop_request_mode = WaitForValidStopLine;
      DCSN_subsystem_integrated_B.stop_distance = 0.0F;
    }
  }
  else if (!VbDCSN_stop_request_enabled)
  {
    DCSN_subsystem_integrated_DW.is_StopRequestEnabled =
      DCSN_su_IN_NO_ACTIVE_CHILD_abpi;
    DCSN_subsystem_integrated_DW.is_c3_DCSN_subsystem_integrated =
      DCSN_sub_IN_StopRequestDisabled;
    VeDCSN_stop_request_mode = NotEnabled;
    rtb_RelationalOperator_njbi = false;
    DCSN_subsystem_integrated_B.stop_distance = 0.0F;
  }
  else
  {
    switch (DCSN_subsystem_integrated_DW.is_StopRequestEnabled)
    {
     case DCSN_subsystem_IN_CheckStopCond:
      VeDCSN_stop_request_mode = CheckStopCond;
      rtb_RelationalOperator_njbi = false;
      if ((!VbDCSN_has_valid_stop_line) || VbDCSN_stop_line_distance_isNaN)
      {
        DCSN_subsystem_integrated_DW.is_StopRequestEnabled =
          DCSN_su_IN_WaitForValidStopLine;
        VeDCSN_stop_request_mode = WaitForValidStopLine;
        DCSN_subsystem_integrated_B.stop_distance = 0.0F;
      }
      else
      {
        if (VbDCSN_should_send_stop_req)
        {
          DCSN_subsystem_integrated_DW.is_StopRequestEnabled =
            DCSN_subs_IN_SendStopReqMpfuDis;
          VeDCSN_stop_request_mode = SendStopReqMpfuDis;
          rtb_RelationalOperator_njbi = true;
        }
      }
      break;

     case DCSN_s_IN_HoldForStopLineUpdate:
      VeDCSN_stop_request_mode = HoldForStopLineUpdate;
      rtb_RelationalOperator_njbi = false;
      if (DCSN_subsystem_integrated_DW.distance_to_move <
          (KfDCSN_d_stop_cleared_Thrsh * (-1.0F)))
      {
        DCSN_subsystem_integrated_DW.is_StopRequestEnabled =
          DCSN_su_IN_WaitForValidStopLine;
        VeDCSN_stop_request_mode = WaitForValidStopLine;
        DCSN_subsystem_integrated_B.stop_distance = 0.0F;
      }
      else
      {
        DCSN_subsystem_integrated_DW.distance_to_move -= quality;
      }
      break;

     case DCSN_subs_IN_SendStopReqMpfuDis:
      VeDCSN_stop_request_mode = SendStopReqMpfuDis;
      rtb_RelationalOperator_njbi = true;
      if (VbDCSN_stop_line_is_close || VbDCSN_stop_line_distance_isNaN)
      {
        DCSN_subsystem_integrated_DW.is_StopRequestEnabled =
          DCSN_subsystem_IN_UpdateStopDis;
        VeDCSN_stop_request_mode = UpdateStopDis;
      }
      else if (!VbDCSN_has_valid_stop_line)
      {
        DCSN_subsystem_integrated_DW.is_StopRequestEnabled =
          DCSN_su_IN_WaitForValidStopLine;
        VeDCSN_stop_request_mode = WaitForValidStopLine;
        rtb_RelationalOperator_njbi = false;
        DCSN_subsystem_integrated_B.stop_distance = 0.0F;
      }
      else
      {
        DCSN_subsystem_integrated_B.stop_distance =
          VfDCSN_raw_stop_line_distance;
      }
      break;

     case DCSN_subsystem_IN_UpdateStopDis:
      VeDCSN_stop_request_mode = UpdateStopDis;
      rtb_RelationalOperator_njbi = true;

      /* Switch: '<S173>/Switch' incorporates:
       *  Constant: '<S173>/Constant'
       */
      if (VbDCSN_raw_stop_finished_late)
      {
        /* Switch: '<S173>/Switch1' incorporates:
         *  Constant: '<S173>/Constant1'
         *  Constant: '<S173>/Constant2'
         *  Constant: '<S173>/KfDCSN_t_stop_req_hold'
         *  DiscreteIntegrator: '<S173>/Discrete-Time Integrator'
         *  Gain: '<S173>/Gain'
         *  RelationalOperator: '<S173>/Relational Operator'
         */
        if (((real32_T)
             DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_ky0g) >=
            (100.0F * KfDCSN_t_stop_req_hold))
        {
          rtb_RelationalOperator_cwas = true;
        }
        else
        {
          rtb_RelationalOperator_cwas = false;
        }

        /* End of Switch: '<S173>/Switch1' */
      }
      else
      {
        rtb_RelationalOperator_cwas = false;
      }

      /* End of Switch: '<S173>/Switch' */
      if (VbDCSN_stop_unsuccess || rtb_RelationalOperator_cwas)
      {
        DCSN_subsystem_integrated_DW.is_StopRequestEnabled =
          DCSN_su_IN_WaitForValidStopLine;
        VeDCSN_stop_request_mode = WaitForValidStopLine;
        rtb_RelationalOperator_njbi = false;
        DCSN_subsystem_integrated_B.stop_distance = 0.0F;
      }
      else if (VbDCSN_hold_stop_finished)
      {
        DCSN_subsystem_integrated_DW.is_StopRequestEnabled =
          DCSN_s_IN_HoldForStopLineUpdate;
        VeDCSN_stop_request_mode = HoldForStopLineUpdate;
        rtb_RelationalOperator_njbi = false;
        DCSN_subsystem_integrated_DW.distance_to_move =
          DCSN_subsystem_integrated_B.stop_distance;
        DCSN_subsystem_integrated_B.stop_distance = 0.0F;
      }
      else
      {
        DCSN_subsystem_integrated_B.stop_distance -= quality;
      }
      break;

     default:
      VeDCSN_stop_request_mode = WaitForValidStopLine;
      rtb_RelationalOperator_njbi = false;
      if (VbDCSN_has_valid_stop_line && (!VbDCSN_stop_line_distance_isNaN))
      {
        DCSN_subsystem_integrated_DW.is_StopRequestEnabled =
          DCSN_subsystem_IN_CheckStopCond;
        VeDCSN_stop_request_mode = CheckStopCond;
        DCSN_subsystem_integrated_B.stop_distance = 0.0F;
      }
      break;
    }
  }

  /* End of Chart: '<S162>/DtrmnDCSN_StopModeManager' */

  /* Switch: '<S73>/Switch' incorporates:
   *  Constant: '<S73>/Constant'
   *  Constant: '<S73>/Constant1'
   */
  if (KbDCSN_stop_man_enbl)
  {
    VbDCSN_stop_request = KbDCSN_stop_request_man_value;
  }
  else
  {
    VbDCSN_stop_request = rtb_RelationalOperator_njbi;
  }

  /* End of Switch: '<S73>/Switch' */

  /* Outputs for Enabled SubSystem: '<S161>/StopDis' incorporates:
   *  EnablePort: '<S171>/Enable'
   */
  /* Constant: '<S161>/Constant1' */
  if (KbDCSN_stop_request_man_value)
  {
    if (!DCSN_subsystem_integrated_DW.StopDis_MODE)
    {
      /* InitializeConditions for UnitDelay: '<S171>/Unit Delay' */
      DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_ezc1 = 0.0F;
      DCSN_subsystem_integrated_DW.StopDis_MODE = true;
    }

    /* Sum: '<S171>/Sum' incorporates:
     *  UnitDelay: '<S171>/Unit Delay'
     */
    end_x_lbop = quality + DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_ezc1;

    /* Sum: '<S171>/Add' incorporates:
     *  Constant: '<S171>/Constant2'
     */
    DCSN_subsystem_integrated_B.Add = KfDCSN_d_stop_s_distance_man_value -
      end_x_lbop;

    /* Update for UnitDelay: '<S171>/Unit Delay' */
    DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_ezc1 = end_x_lbop;
  }
  else
  {
    if (DCSN_subsystem_integrated_DW.StopDis_MODE)
    {
      DCSN_subsystem_integrated_DW.StopDis_MODE = false;
    }
  }

  /* End of Constant: '<S161>/Constant1' */
  /* End of Outputs for SubSystem: '<S161>/StopDis' */

  /* Switch: '<S73>/Switch1' incorporates:
   *  Constant: '<S73>/Constant'
   */
  if (KbDCSN_stop_man_enbl)
  {
    VfDCSN_stop_s_distance = DCSN_subsystem_integrated_B.Add;
  }
  else
  {
    VfDCSN_stop_s_distance = DCSN_subsystem_integrated_B.stop_distance;
  }

  /* End of Switch: '<S73>/Switch1' */

  /* Switch: '<S73>/Switch10' incorporates:
   *  Constant: '<S162>/Constant4'
   *  Constant: '<S73>/Constant'
   *  Constant: '<S73>/Constant15'
   *  DataTypeConversion: '<S73>/Data Type Conversion1'
   *  Switch: '<S162>/Switch'
   */
  if (KbDCSN_stop_man_enbl)
  {
    VeDCSN_stop_reason = (EnumDCSN_stop_reason)KeDCSN_stop_reason_man_value;
  }
  else if (rtb_RelationalOperator_njbi)
  {
    /* Switch: '<S162>/Switch' incorporates:
     *  Constant: '<S162>/Constant3'
     */
    VeDCSN_stop_reason = STOP_FOR_STOP_LINE;
  }
  else
  {
    VeDCSN_stop_reason = NO_STOP_REQUEST;
  }

  /* End of Switch: '<S73>/Switch10' */

  /* Switch: '<S73>/Switch2' incorporates:
   *  Constant: '<S73>/Constant3'
   *  Constant: '<S73>/Constant4'
   */
  if (KbDCSN_speed_limit_man_enbl)
  {
    VfDCSN_lane_speed_limit = KfDCSN_v_lane_speed_limit_man_value;
  }
  else
  {
    VfDCSN_lane_speed_limit = start_x_ceng;
  }

  /* End of Switch: '<S73>/Switch2' */

  /* Outputs for Iterator SubSystem: '<S75>/CalcDCSN_select_ego_lane' incorporates:
   *  WhileIterator: '<S151>/While Iterator'
   */
  s80_iter = 1;
  do
  {
    rtb_RelationalOperator_cwas = (VsMPFU_DataBus.lanes[s80_iter - 1].id == 0);
    if (rtb_RelationalOperator_cwas)
    {
      DCSN_subsystem_integrated_B.lane_index = s80_iter;
    }

    s80_iter++;
  }
  while ((!rtb_RelationalOperator_cwas) && (s80_iter <= 8));

  /* End of Outputs for SubSystem: '<S75>/CalcDCSN_select_ego_lane' */

  /* RelationalOperator: '<S182>/Relational Operator' */
  VbDCSN_num_lanes_isNaN = false;

  /* Switch: '<S182>/Switch' incorporates:
   *  Inport: '<Root>/MPFU_DataBus'
   *  UnitDelay: '<S182>/Unit Delay'
   */
  if (VbDCSN_num_lanes_isNaN)
  {
    rtb_Switch_lp1h = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_dsaz;
  }
  else
  {
    rtb_Switch_lp1h = VsMPFU_DataBus.num_lanes;
  }

  /* End of Switch: '<S182>/Switch' */

  /* Logic: '<S75>/Logical Operator' incorporates:
   *  Constant: '<S154>/Constant'
   *  Constant: '<S155>/Constant'
   *  RelationalOperator: '<S154>/Compare'
   *  RelationalOperator: '<S155>/Compare'
   */
  VbDCSN_has_ego_lane = ((DCSN_subsystem_integrated_B.lane_index > 0) &&
    (rtb_Switch_lp1h > ((uint8_T)0U)));

  /* If: '<S75>/If' */
  if (VbDCSN_has_ego_lane)
  {
    /* Outputs for IfAction SubSystem: '<S75>/CalcDCSN_select_lane_speed_limit_max' incorporates:
     *  ActionPort: '<S152>/Action Port'
     */
    /* SignalConversion: '<S152>/OutportBufferForego_speed_limit_max' incorporates:
     *  Inport: '<Root>/MPFU_DataBus'
     *  Selector: '<S152>/Selector'
     *  Switch: '<S159>/Switch'
     */
    start_x_ceng = (real32_T)
      VsMPFU_DataBus.lanes[DCSN_subsystem_integrated_B.lane_index - 1].
      speed_limit_max;

    /* SignalConversion: '<S152>/OutportBufferForego_speed_limt_max_isNaN' incorporates:
     *  RelationalOperator: '<S159>/Relational Operator'
     */
    VbDCSN_spd_limt_max_isNaN = false;

    /* End of Outputs for SubSystem: '<S75>/CalcDCSN_select_lane_speed_limit_max' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S75>/CalcDCSN_simu_speed_limit_max' incorporates:
     *  ActionPort: '<S153>/Action Port'
     */
    /* SignalConversion: '<S153>/OutportBufferForego_speed_limit_max' incorporates:
     *  Constant: '<S153>/Constant1'
     */
    start_x_ceng = 0.0F;

    /* SignalConversion: '<S153>/OutportBufferForego_speed_limt_max_isNaN' incorporates:
     *  Constant: '<S153>/Constant'
     */
    VbDCSN_spd_limt_max_isNaN = false;

    /* End of Outputs for SubSystem: '<S75>/CalcDCSN_simu_speed_limit_max' */
  }

  /* End of If: '<S75>/If' */

  /* Logic: '<S75>/Logical Operator1' */
  VbDCSN_speed_limit_input_isNaN = (VbDCSN_spd_limt_max_isNaN &&
    VbDCSN_num_lanes_isNaN);

  /* Outputs for Enabled SubSystem: '<S75>/Pass' incorporates:
   *  EnablePort: '<S156>/Enable'
   */
  /* Logic: '<S75>/Logical Operator2' incorporates:
   *  Inport: '<S156>/In1'
   *  Logic: '<S75>/Logical Operator3'
   */
  if ((!VbDCSN_speed_limit_input_isNaN) && VbDCSN_has_ego_lane)
  {
    VfDCSN_speed_limit_ego_lane = start_x_ceng;
  }

  /* End of Logic: '<S75>/Logical Operator2' */
  /* End of Outputs for SubSystem: '<S75>/Pass' */

  /* Switch: '<S73>/Switch16' incorporates:
   *  Constant: '<S67>/Constant10'
   *  Constant: '<S73>/Constant20'
   *  Constant: '<S73>/Constant3'
   *  Switch: '<S67>/Switch10'
   */
  if (KbDCSN_speed_limit_man_enbl)
  {
    VfDCSN_target_speed_limit = KfDCSN_v_target_speed_limit_man_value;
  }
  else if (VbDCSN_speed_limit_enabled)
  {
    /* Switch: '<S67>/Switch10' */
    VfDCSN_target_speed_limit = VfDCSN_speed_limit_ego_lane;
  }
  else
  {
    VfDCSN_target_speed_limit = 70.0F;
  }

  /* End of Switch: '<S73>/Switch16' */

  /* Switch: '<S73>/Switch17' incorporates:
   *  Constant: '<S73>/Constant21'
   *  Constant: '<S73>/Constant3'
   *  Switch: '<S67>/Switch4'
   */
  if (KbDCSN_speed_limit_man_enbl)
  {
    VfDCSN_speed_limit_distance = KfDCSN_d_speed_limit_distance_man_value;
  }
  else if (VbDCSN_speed_limit_enabled)
  {
    /* Switch: '<S67>/Switch4' incorporates:
     *  Constant: '<S67>/Constant1'
     *  Switch: '<S67>/Switch8'
     */
    VfDCSN_speed_limit_distance = 0.0F;
  }
  else
  {
    /* Switch: '<S67>/Switch4' incorporates:
     *  Constant: '<S67>/Constant2'
     */
    VfDCSN_speed_limit_distance = 0.0F;
  }

  /* End of Switch: '<S73>/Switch17' */

  /* Switch: '<S73>/Switch9' incorporates:
   *  Constant: '<S73>/Constant14'
   *  Constant: '<S73>/Constant3'
   *  DataTypeConversion: '<S73>/Data Type Conversion2'
   */
  if (KbDCSN_speed_limit_man_enbl)
  {
    VeDCSN_speed_limit_reason = (EnumDCSN_speed_limit_reason)
      KeDCSN_speed_limit_reason_man_value;
  }
  else
  {
    VeDCSN_speed_limit_reason = rtb_Switch_abos;
  }

  /* End of Switch: '<S73>/Switch9' */

  /* Switch: '<S185>/Switch3' incorporates:
   *  Constant: '<S185>/Constant'
   */
  if (rtb_RelationalOperator_elnv)
  {
    rtb_RelationalOperator_cwas = VbDCSN_CL_delay_finished;
  }
  else
  {
    rtb_RelationalOperator_cwas = false;
  }

  /* End of Switch: '<S185>/Switch3' */

  /* Switch: '<S73>/Switch3' incorporates:
   *  Constant: '<S73>/Constant5'
   *  Constant: '<S73>/Constant6'
   */
  if (KbDCSN_change_lane_man_enbl)
  {
    VbDCSN_change_lane_request = KbDCSN_change_lane_request_man_value;
  }
  else
  {
    VbDCSN_change_lane_request = rtb_RelationalOperator_cwas;
  }

  /* End of Switch: '<S73>/Switch3' */

  /* Switch: '<S73>/Switch11' incorporates:
   *  Constant: '<S185>/Constant1'
   *  Constant: '<S73>/Constant16'
   *  Constant: '<S73>/Constant5'
   *  DataTypeConversion: '<S73>/Data Type Conversion3'
   *  Logic: '<S185>/Logical Operator10'
   *  Switch: '<S185>/Switch5'
   */
  if (KbDCSN_change_lane_man_enbl)
  {
    VeDCSN_change_lane_reason = (EnumDCSN_change_lane_reason)
      KeDCSN_change_lane_reason_man_value;
  }
  else if (rtb_RelationalOperator_elnv && VbDCSN_CL_delay_finished)
  {
    /* Switch: '<S185>/Switch5' incorporates:
     *  Constant: '<S185>/Constant2'
     */
    VeDCSN_change_lane_reason = LC_USER_CMD;
  }
  else
  {
    VeDCSN_change_lane_reason = LC_NO_REQUEST;
  }

  /* End of Switch: '<S73>/Switch11' */

  /* Switch: '<S73>/Switch5' incorporates:
   *  Constant: '<S71>/Constant5'
   *  Constant: '<S73>/Constant5'
   *  Constant: '<S73>/Constant8'
   */
  if (KbDCSN_change_lane_man_enbl)
  {
    VfDCSN_change_lane_target_speed =
      KfDCSN_v_change_lane_target_speed_man_value;
  }
  else
  {
    VfDCSN_change_lane_target_speed = 0.0F;
  }

  /* End of Switch: '<S73>/Switch5' */

  /* Outputs for Enabled SubSystem: '<S185>/CvrtDCSN_DataConvert' incorporates:
   *  EnablePort: '<S186>/Enable'
   */
  if (rtb_RelationalOperator_cwas)
  {
    /* Inport: '<S186>/In1' */
    VeDCSN_CL_req_side_pre = rtb_Switch4_exki;
  }

  /* End of Outputs for SubSystem: '<S185>/CvrtDCSN_DataConvert' */

  /* Switch: '<S188>/Switch1' incorporates:
   *  Constant: '<S188>/Constant4'
   *  DataTypeConversion: '<S70>/Data Type Conversion'
   *  DataTypeConversion: '<S70>/Data Type Conversion1'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  Logic: '<S185>/Logical Operator11'
   *  Logic: '<S185>/Logical Operator12'
   */
  if ((!VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState) &&
      (VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState))
  {
    /* Sum: '<S188>/Sum' incorporates:
     *  Constant: '<S188>/CallFrequencyOneLoop'
     *  UnitDelay: '<S188>/UnitDelay'
     */
    rtb_CurrentTick_bicj = (uint16_T)(((uint32_T)
      DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_ctin) + ((uint32_T)
      ((uint16_T)1U)));

    /* Saturate: '<S188>/Saturation' */
    if (rtb_CurrentTick_bicj < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick_bicj = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S188>/Saturation' */
  }
  else
  {
    rtb_CurrentTick_bicj = ((uint16_T)0U);
  }

  /* End of Switch: '<S188>/Switch1' */

  /* Switch: '<S189>/Switch1' incorporates:
   *  Constant: '<S189>/Constant4'
   *  DataTypeConversion: '<S70>/Data Type Conversion'
   *  DataTypeConversion: '<S70>/Data Type Conversion1'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  Logic: '<S185>/Logical Operator19'
   *  Logic: '<S185>/Logical Operator22'
   */
  if ((VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState) &&
      (!VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState))
  {
    /* Sum: '<S189>/Sum' incorporates:
     *  Constant: '<S189>/CallFrequencyOneLoop'
     *  UnitDelay: '<S189>/UnitDelay'
     */
    rtb_CurrentTick_glhk = (uint16_T)(((uint32_T)
      DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_b5in) + ((uint32_T)
      ((uint16_T)1U)));

    /* Saturate: '<S189>/Saturation' */
    if (rtb_CurrentTick_glhk < ((uint16_T)65534U))
    {
    }
    else
    {
      rtb_CurrentTick_glhk = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S189>/Saturation' */
  }
  else
  {
    rtb_CurrentTick_glhk = ((uint16_T)0U);
  }

  /* End of Switch: '<S189>/Switch1' */

  /* Switch: '<S185>/Switch1' incorporates:
   *  Constant: '<S185>/Constant7'
   *  Constant: '<S185>/Constant8'
   *  Constant: '<S185>/Constant9'
   *  Logic: '<S185>/Logical Operator20'
   *  RelationalOperator: '<S185>/Relational Operator2'
   *  RelationalOperator: '<S185>/Relational Operator3'
   *  Switch: '<S185>/Switch6'
   */
  if (rtb_RelationalOperator_elnv || (VeDCSN_CL_req_side_pre == FORWARD))
  {
    rtb_RelationalOperator_elnv = false;
  }
  else if (VeDCSN_CL_req_side_pre == LEFT)
  {
    /* Switch: '<S185>/Switch6' incorporates:
     *  Constant: '<S185>/110msDebounce'
     *  RelationalOperator: '<S188>/RelationalOperator1'
     */
    rtb_RelationalOperator_elnv = (rtb_CurrentTick_bicj > ((uint16_T)11U));
  }
  else
  {
    /* Switch: '<S185>/Switch6' incorporates:
     *  Constant: '<S185>/110msDebounce1'
     *  RelationalOperator: '<S189>/RelationalOperator1'
     */
    rtb_RelationalOperator_elnv = (rtb_CurrentTick_glhk > ((uint16_T)11U));
  }

  /* End of Switch: '<S185>/Switch1' */

  /* Switch: '<S73>/Switch14' incorporates:
   *  Constant: '<S73>/Constant2'
   *  Constant: '<S73>/Constant5'
   */
  if (KbDCSN_change_lane_man_enbl)
  {
    VbDCSN_change_lane_cancel_request =
      KbDCSN_change_lane_cancel_request_man_value;
  }
  else
  {
    VbDCSN_change_lane_cancel_request = rtb_RelationalOperator_elnv;
  }

  /* End of Switch: '<S73>/Switch14' */

  /* Switch: '<S73>/Switch15' incorporates:
   *  Constant: '<S185>/Constant11'
   *  Constant: '<S73>/Constant19'
   *  Constant: '<S73>/Constant5'
   *  DataTypeConversion: '<S73>/Data Type Conversion7'
   *  Switch: '<S185>/Switch7'
   */
  if (KbDCSN_change_lane_man_enbl)
  {
    VeDCSN_change_lane_cancel_reason = (EnumDCSN_change_lane_cancel_reason)
      KeDCSN_change_lane_cancel_reason_man_value;
  }
  else if (rtb_RelationalOperator_elnv)
  {
    /* Switch: '<S185>/Switch7' incorporates:
     *  Constant: '<S185>/Constant10'
     */
    VeDCSN_change_lane_cancel_reason = LC_CANCEL_USR_CMD;
  }
  else
  {
    VeDCSN_change_lane_cancel_reason = LC_CANCEL_NO_REQUEST;
  }

  /* End of Switch: '<S73>/Switch15' */

  /* Switch: '<S73>/Switch6' incorporates:
   *  Constant: '<S5>/Constant4'
   *  Constant: '<S73>/Constant11'
   *  Constant: '<S73>/Constant9'
   */
  if (KbDCSN_inlane_nudge_man_enbl)
  {
    VbDCSN_inlane_nudge_request = KbDCSN_inlane_nudge_request_man_value;
  }
  else
  {
    VbDCSN_inlane_nudge_request = false;
  }

  /* End of Switch: '<S73>/Switch6' */

  /* Switch: '<S73>/Switch7' incorporates:
   *  Constant: '<S73>/Constant9'
   */
  if (KbDCSN_inlane_nudge_man_enbl)
  {
    /* DataTypeConversion: '<S73>/Data Type Conversion6' incorporates:
     *  Constant: '<S73>/Constant12'
     */
    VfDCSN_inlane_nudge_side = (EnumDCSN_driving_direction)
      KfDCSN_d_inlane_nudge_side_man_value;
  }
  else
  {
    /* DataTypeConversion: '<S73>/Data Type Conversion6' incorporates:
     *  Constant: '<S5>/Constant8'
     */
    VfDCSN_inlane_nudge_side = (EnumDCSN_driving_direction)((uint8_T)0U);
  }

  /* End of Switch: '<S73>/Switch7' */

  /* Switch: '<S73>/Switch12' incorporates:
   *  Constant: '<S73>/Constant17'
   *  Constant: '<S73>/Constant9'
   *  DataTypeConversion: '<S73>/Data Type Conversion4'
   */
  if (KbDCSN_inlane_nudge_man_enbl)
  {
    VeDCSN_inlane_nudge_reason = (EnumDCSN_inlane_nudge_reason)
      KeDCSN_inlane_nudge_reason_man_value;
  }
  else
  {
    VeDCSN_inlane_nudge_reason = NUDGE_NO_REQUEST;
  }

  /* End of Switch: '<S73>/Switch12' */

  /* Switch: '<S73>/Switch8' incorporates:
   *  Constant: '<S5>/Constant6'
   *  Constant: '<S73>/Constant10'
   *  Constant: '<S73>/Constant13'
   */
  if (KbDCSN_pull_over_man_enbl)
  {
    VbDCSN_pull_over_request = KbDCSN_pull_over_request_man_value;
  }
  else
  {
    VbDCSN_pull_over_request = false;
  }

  /* End of Switch: '<S73>/Switch8' */

  /* Switch: '<S73>/Switch13' incorporates:
   *  Constant: '<S73>/Constant10'
   *  Constant: '<S73>/Constant18'
   *  DataTypeConversion: '<S73>/Data Type Conversion5'
   */
  if (KbDCSN_pull_over_man_enbl)
  {
    VeDCSN_pull_over_reason = (EnumDCSN_pull_over_reason)
      KeDCSN_pull_over_reason_man_value;
  }
  else
  {
    VeDCSN_pull_over_reason = PULLOVER_NO_REQUEST;
  }

  /* End of Switch: '<S73>/Switch13' */

  /* BusCreator: '<S73>/Bus Creator' */
  VsDCSN_DataBus.TrafficDecider_Group.stop_request = VbDCSN_stop_request;
  VsDCSN_DataBus.TrafficDecider_Group.stop_s_distance = VfDCSN_stop_s_distance;
  VsDCSN_DataBus.TrafficDecider_Group.stop_reason = VeDCSN_stop_reason;
  VsDCSN_DataBus.TrafficDecider_Group.lane_speed_limit = VfDCSN_lane_speed_limit;
  VsDCSN_DataBus.TrafficDecider_Group.target_speed_limit =
    VfDCSN_target_speed_limit;
  VsDCSN_DataBus.TrafficDecider_Group.speed_limit_distance =
    VfDCSN_speed_limit_distance;
  VsDCSN_DataBus.TrafficDecider_Group.speed_limit_reason =
    VeDCSN_speed_limit_reason;
  VsDCSN_DataBus.TrafficDecider_Group.change_lane_request =
    VbDCSN_change_lane_request;
  VsDCSN_DataBus.TrafficDecider_Group.change_lane_req_side =
    VeDCSN_change_lane_req_side;
  VsDCSN_DataBus.TrafficDecider_Group.change_lane_reason =
    VeDCSN_change_lane_reason;
  VsDCSN_DataBus.TrafficDecider_Group.change_lane_target_speed =
    VfDCSN_change_lane_target_speed;
  VsDCSN_DataBus.TrafficDecider_Group.change_lane_cancel_request =
    VbDCSN_change_lane_cancel_request;
  VsDCSN_DataBus.TrafficDecider_Group.change_lane_cancel_reason =
    VeDCSN_change_lane_cancel_reason;
  VsDCSN_DataBus.TrafficDecider_Group.inlane_nudge_request =
    VbDCSN_inlane_nudge_request;
  VsDCSN_DataBus.TrafficDecider_Group.inlane_nudge_side =
    VfDCSN_inlane_nudge_side;
  VsDCSN_DataBus.TrafficDecider_Group.inlane_nudge_reason =
    VeDCSN_inlane_nudge_reason;
  VsDCSN_DataBus.TrafficDecider_Group.pull_over_request =
    VbDCSN_pull_over_request;
  VsDCSN_DataBus.TrafficDecider_Group.pull_over_reason = VeDCSN_pull_over_reason;
  VsDCSN_DataBus.TrafficDecider_Group.over_speed_warning =
    VbDCSN_overspeed_warning;

  /* Logic: '<S160>/Logical Operator3' */
  VbDCSN_stop_line_input_isNaN = (VbDCSN_stop_line_distance_isNaN ||
    VbDCSN_num_stop_lines_isNaN);

  /* UnitDelay: '<S74>/Unit Delay' */
  rtb_Abs = DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_fq2a;

  /* Sum: '<S74>/Add' incorporates:
   *  Constant: '<S74>/Constant'
   *  Constant: '<S74>/KfDCSN_k_largest_curvature_filter'
   *  Constant: '<S74>/KfDCSN_k_largest_curvature_filter1'
   *  Product: '<S74>/Product1'
   *  Product: '<S74>/Product2'
   *  Sum: '<S74>/Add1'
   */
  rtb_Abs = (VfDCSN_largest_curvature_ahead * (1.0F -
              KfDCSN_k_largest_curvature_filter)) +
    (KfDCSN_k_largest_curvature_filter * rtb_Abs);

  /* Update for UnitDelay: '<S74>/Unit Delay' incorporates:
   *  DataTypeConversion: '<S74>/Data Type Conversion'
   */
  DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_fq2a = rtb_Abs;

  /* SignalConversion: '<S100>/Signal Conversion9' */
  VfDCSN_right_marker_raw_c0 = rtb_Switch_et0b;

  /* Product: '<S150>/Product' incorporates:
   *  Constant: '<S150>/Constant'
   */
  rtb_Abs = rtb_Switch_crnn * 2.0F;

  /* Abs: '<S150>/Abs' */
  rtb_Abs = (real32_T)fabs((real_T)rtb_Abs);

  /* Sum: '<S150>/Add' incorporates:
   *  Constant: '<S150>/Constant1'
   *  Math: '<S150>/Math Function'
   */
  quality_ksol = 1.0F + (start_x * start_x);

  /* Math: '<S150>/Math Function1' incorporates:
   *  Constant: '<S150>/Constant2'
   *  Math: '<S147>/Math Function1'
   *  Math: '<S148>/Math Function1'
   *  Math: '<S149>/Math Function1'
   */
  quality = (real32_T)floor((real_T)1.5F);
  if ((quality_ksol < 0.0F) && (1.5F > quality))
  {
    quality_ksol = -rt_powf_snf(-quality_ksol, 1.5F);
  }
  else
  {
    quality_ksol = rt_powf_snf(quality_ksol, 1.5F);
  }

  /* End of Math: '<S150>/Math Function1' */

  /* Product: '<S150>/Divide' */
  VfDCSN_current_right_marker_cur = rtb_Abs / quality_ksol;

  /* SignalConversion: '<S100>/Signal Conversion10' */
  VfDCSN_right_marker_raw_c1 = rtb_Switch_crnn;

  /* Product: '<S148>/Product' incorporates:
   *  Constant: '<S148>/Constant'
   */
  rtb_Abs = rtb_Switch_jvmn * 2.0F;

  /* Abs: '<S148>/Abs' */
  rtb_Abs = (real32_T)fabs((real_T)rtb_Abs);

  /* Sum: '<S148>/Add' incorporates:
   *  Constant: '<S148>/Constant1'
   *  Math: '<S148>/Math Function'
   */
  quality_ksol = 1.0F + (rtb_Switch_mhao * rtb_Switch_mhao);

  /* Math: '<S148>/Math Function1' incorporates:
   *  Constant: '<S148>/Constant2'
   */
  if ((quality_ksol < 0.0F) && (1.5F > quality))
  {
    quality_ksol = -rt_powf_snf(-quality_ksol, 1.5F);
  }
  else
  {
    quality_ksol = rt_powf_snf(quality_ksol, 1.5F);
  }

  /* Product: '<S148>/Divide' */
  VfDCSN_current_right_edge_cur = rtb_Abs / quality_ksol;

  /* SignalConversion: '<S100>/Signal Conversion11' */
  VfDCSN_right_marker_raw_c2 = start_x;

  /* SignalConversion: '<S100>/Signal Conversion12' */
  VfDCSN_right_marker_raw_c3 = end_x;

  /* SignalConversion: '<S100>/Signal Conversion13' */
  VfDCSN_right_marker_raw_start_x = rtb_Switch_eq4s;

  /* SignalConversion: '<S100>/Signal Conversion15' */
  VfDCSN_right_marker_raw_end_x = rtb_Switch_nkom;

  /* SignalConversion: '<S100>/Signal Conversion14' */
  VfDCSN_right_marker_raw_start_y = rtb_Switch_g34g;

  /* SignalConversion: '<S100>/Signal Conversion16' */
  VfDCSN_right_marker_raw_end_y = rtb_Switch_l3dh;

  /* SignalConversion: '<S100>/Signal Conversion17' */
  VfDCSN_right_marker_raw_quality = quality_htk5;

  /* SignalConversion: '<S100>/Signal Conversion' */
  VfDCSN_left_marker_raw_c0 = rtb_Switch_oios;

  /* Product: '<S149>/Product' incorporates:
   *  Constant: '<S149>/Constant'
   */
  rtb_Abs = rtb_Switch_by1p * 2.0F;

  /* Abs: '<S149>/Abs' */
  rtb_Abs = (real32_T)fabs((real_T)rtb_Abs);

  /* Sum: '<S149>/Add' incorporates:
   *  Constant: '<S149>/Constant1'
   *  Math: '<S149>/Math Function'
   */
  quality_ksol = 1.0F + (rtb_Switch_bcgx * rtb_Switch_bcgx);

  /* Math: '<S149>/Math Function1' incorporates:
   *  Constant: '<S149>/Constant2'
   */
  if ((quality_ksol < 0.0F) && (1.5F > quality))
  {
    quality_ksol = -rt_powf_snf(-quality_ksol, 1.5F);
  }
  else
  {
    quality_ksol = rt_powf_snf(quality_ksol, 1.5F);
  }

  /* Product: '<S149>/Divide' */
  VfDCSN_current_left_marker_cur = rtb_Abs / quality_ksol;

  /* SignalConversion: '<S100>/Signal Conversion1' */
  VfDCSN_left_marker_raw_c1 = rtb_Switch_by1p;

  /* Product: '<S147>/Product' incorporates:
   *  Constant: '<S147>/Constant'
   */
  rtb_Abs = rtb_Switch_j1xp * 2.0F;

  /* Abs: '<S147>/Abs' */
  rtb_Abs = (real32_T)fabs((real_T)rtb_Abs);

  /* Sum: '<S147>/Add' incorporates:
   *  Constant: '<S147>/Constant1'
   *  Math: '<S147>/Math Function'
   */
  quality_ksol = 1.0F + (rtb_Switch_lnuo * rtb_Switch_lnuo);

  /* Math: '<S147>/Math Function1' incorporates:
   *  Constant: '<S147>/Constant2'
   */
  if ((quality_ksol < 0.0F) && (1.5F > quality))
  {
    quality_ksol = -rt_powf_snf(-quality_ksol, 1.5F);
  }
  else
  {
    quality_ksol = rt_powf_snf(quality_ksol, 1.5F);
  }

  /* Product: '<S147>/Divide' */
  VfDCSN_current_left_edge_cur = rtb_Abs / quality_ksol;

  /* SignalConversion: '<S100>/Signal Conversion2' */
  VfDCSN_left_marker_raw_c2 = rtb_Switch_bcgx;

  /* SignalConversion: '<S100>/Signal Conversion3' */
  VfDCSN_left_marker_raw_c3 = rtb_Switch_ng24;

  /* SignalConversion: '<S100>/Signal Conversion4' */
  VfDCSN_left_marker_raw_start_x = rtb_Switch_iesc;

  /* SignalConversion: '<S100>/Signal Conversion6' */
  VfDCSN_left_marker_raw_end_x = rtb_Switch_hufc;

  /* SignalConversion: '<S100>/Signal Conversion5' */
  VfDCSN_left_marker_raw_start_y = rtb_Switch_o3ag;

  /* SignalConversion: '<S100>/Signal Conversion7' */
  VfDCSN_left_marker_raw_end_y = rtb_Switch_i5a0;

  /* SignalConversion: '<S100>/Signal Conversion8' */
  VfDCSN_left_marker_raw_quality = quality_flcq;

  /* RelationalOperator: '<S179>/Compare' incorporates:
   *  Constant: '<S179>/Constant'
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VbDCSN_egmo_is_ready = (VsEGMO_DataBus.is_ready == true);

  /* RelationalOperator: '<S180>/Compare' incorporates:
   *  Constant: '<S180>/Constant'
   *  Inport: '<Root>/MPFU_DataBus'
   */
  VbDCSN_mpfu_is_ready = (VsMPFU_DataBus.is_ready == true);

  /* Logic: '<S69>/Logical Operator' */
  VbDCSN_input_is_ready = (VbDCSN_egmo_is_ready || VbDCSN_mpfu_is_ready);

  /* Update for UnitDelay: '<S183>/Unit Delay' */
  DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_da3u = rtb_Switch;

  /* Update for UnitDelay: '<S181>/Unit Delay' */
  DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_efss = rtb_Switch_m3bd;

  /* Update for UnitDelay: '<S185>/Unit Delay' incorporates:
   *  DataTypeConversion: '<S70>/Data Type Conversion'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   */
  DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_cb10 =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState;

  /* Update for UnitDelay: '<S185>/Unit Delay1' incorporates:
   *  DataTypeConversion: '<S70>/Data Type Conversion1'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   */
  DCSN_subsystem_integrated_DW.UnitDelay1_DSTATE_a53f =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState;

  /* Update for UnitDelay: '<S185>/Unit Delay3' incorporates:
   *  DataTypeConversion: '<S70>/Data Type Conversion1'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   */
  DCSN_subsystem_integrated_DW.UnitDelay3_DSTATE =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState;

  /* Update for UnitDelay: '<S185>/Unit Delay4' incorporates:
   *  DataTypeConversion: '<S70>/Data Type Conversion'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   */
  DCSN_subsystem_integrated_DW.UnitDelay4_DSTATE =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState;

  /* Update for UnitDelay: '<S185>/Unit Delay5' incorporates:
   *  DataTypeConversion: '<S70>/Data Type Conversion'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   */
  DCSN_subsystem_integrated_DW.UnitDelay5_DSTATE_nwlx =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState;

  /* Update for UnitDelay: '<S185>/Unit Delay6' incorporates:
   *  DataTypeConversion: '<S70>/Data Type Conversion1'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   */
  DCSN_subsystem_integrated_DW.UnitDelay6_DSTATE =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState;

  /* Update for UnitDelay: '<S185>/Unit Delay7' incorporates:
   *  DataTypeConversion: '<S70>/Data Type Conversion1'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   */
  DCSN_subsystem_integrated_DW.UnitDelay7_DSTATE =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState;

  /* Update for UnitDelay: '<S185>/Unit Delay8' incorporates:
   *  DataTypeConversion: '<S70>/Data Type Conversion'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   */
  DCSN_subsystem_integrated_DW.UnitDelay8_DSTATE =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState;

  /* Update for Delay: '<S185>/Delay' */
  DCSN_subsystem_integrated_DW.Delay_DSTATE[0] =
    DCSN_subsystem_integrated_DW.Delay_DSTATE[1];
  DCSN_subsystem_integrated_DW.Delay_DSTATE[1] =
    DCSN_subsystem_integrated_DW.Delay_DSTATE[2];
  DCSN_subsystem_integrated_DW.Delay_DSTATE[2] =
    DCSN_subsystem_integrated_DW.Delay_DSTATE[3];
  DCSN_subsystem_integrated_DW.Delay_DSTATE[3] =
    DCSN_subsystem_integrated_DW.Delay_DSTATE[4];
  DCSN_subsystem_integrated_DW.Delay_DSTATE[4] = VbDCSN_CL_delay_finished;

  /* Update for UnitDelay: '<S185>/Unit Delay2' */
  DCSN_subsystem_integrated_DW.UnitDelay2_DSTATE_nwfs =
    rtb_RelationalOperator_elnv;

  /* Update for Memory: '<S190>/Memory' */
  DCSN_subsystem_integrated_DW.Memory_PreviousInput =
    rtb_RelationalOperator_l4uz;

  /* Update for UnitDelay: '<S187>/UnitDelay' */
  DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_ch4m = rtb_CurrentTick;

  /* Update for DiscreteIntegrator: '<S172>/Discrete-Time Integrator' */
  DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DSTATE = (uint16_T)
    (((uint32_T)DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DSTATE) +
     (VbDCSN_raw_stop_finished ? 1U : 0U));
  if (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DSTATE >= ((uint16_T)
       2000U))
  {
    DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DSTATE = ((uint16_T)
      2000U);
  }
  else
  {
    if (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DSTATE <= ((uint16_T)
         0U))
    {
      DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DSTATE = ((uint16_T)0U);
    }
  }

  DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    (VbDCSN_raw_stop_finished ? 1 : 0);

  /* End of Update for DiscreteIntegrator: '<S172>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S173>/Discrete-Time Integrator' */
  DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_ky0g = (uint16_T)
    (((uint32_T)DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_ky0g) +
     (VbDCSN_raw_stop_finished_late ? 1U : 0U));
  if (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_ky0g >= ((uint16_T)
       2000U))
  {
    DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_ky0g = ((uint16_T)
      2000U);
  }
  else
  {
    if (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_ky0g <=
        ((uint16_T)0U))
    {
      DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_ky0g = ((uint16_T)
        0U);
    }
  }

  DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_Pre_jtbt = (int8_T)
    (VbDCSN_raw_stop_finished_late ? 1 : 0);

  /* End of Update for DiscreteIntegrator: '<S173>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S182>/Unit Delay' */
  DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_dsaz = rtb_Switch_lp1h;

  /* Update for UnitDelay: '<S188>/UnitDelay' */
  DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_ctin = rtb_CurrentTick_bicj;

  /* Update for UnitDelay: '<S189>/UnitDelay' */
  DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_b5in = rtb_CurrentTick_glhk;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
