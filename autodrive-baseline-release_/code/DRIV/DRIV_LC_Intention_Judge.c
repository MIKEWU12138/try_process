/*
 * File: DRIV_LC_Intention_Judge.c
 *
 * Code generated for Simulink model 'DRIV_subsystem_integrated'.
 *
 * Model version                  : 1.1200
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Jun 10 08:50:22 2020
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

#include "DRIV_LC_Intention_Judge.h"

/* Include model header file for global data */
#include "DRIV_subsystem_integrated.h"
#include "DRIV_subsystem_integrated_private.h"

/* Named constants for Chart: '<S57>/Chart' */
#define DRIV_su_IN_NO_ACTIVE_CHILD_oq1d ((uint8_T)0U)
#define DRIV_subsystem_i_IN_Raised_onak ((uint8_T)3U)
#define DRIV_subsystem_in_IN_Delay_cvbc ((uint8_T)1U)
#define DRIV_subsystem_int_IN_INIT_f2kc ((uint8_T)2U)

/* Named constants for Chart: '<S58>/Chart' */
#define DRIV_su_IN_NO_ACTIVE_CHILD_bsjp ((uint8_T)0U)
#define DRIV_subsystem_i_IN_Raised_bg2q ((uint8_T)3U)
#define DRIV_subsystem_in_IN_Delay_afpd ((uint8_T)1U)
#define DRIV_subsystem_int_IN_INIT_azo1 ((uint8_T)2U)

/* Named constants for Chart: '<S66>/Chart' */
#define DRIV_su_IN_NO_ACTIVE_CHILD_mhhz ((uint8_T)0U)
#define DRIV_subsystem_i_IN_Raised_a4an ((uint8_T)3U)
#define DRIV_subsystem_in_IN_Delay_mjcb ((uint8_T)1U)
#define DRIV_subsystem_int_IN_INIT_kdwe ((uint8_T)2U)

/* Named constants for Chart: '<S67>/Chart' */
#define DRIV_su_IN_NO_ACTIVE_CHILD_dgr5 ((uint8_T)0U)
#define DRIV_subsystem_i_IN_Raised_nqyb ((uint8_T)3U)
#define DRIV_subsystem_in_IN_Delay_babc ((uint8_T)1U)
#define DRIV_subsystem_int_IN_INIT_bp24 ((uint8_T)2U)

/* Named constants for Chart: '<S71>/Chart' */
#define DRIV_su_IN_NO_ACTIVE_CHILD_hjt1 ((uint8_T)0U)
#define DRIV_subsystem_i_IN_Raised_iws1 ((uint8_T)3U)
#define DRIV_subsystem_in_IN_Delay_k2dt ((uint8_T)1U)
#define DRIV_subsystem_int_IN_INIT_ojmt ((uint8_T)2U)

/* Named constants for Chart: '<S54>/DRIV_Status' */
#define DRIV_s_IN_LaneChangeFinish_oyxb ((uint8_T)2U)
#define DRIV_su_IN_LaneChangeReady_b1yo ((uint8_T)3U)
#define DRIV_su_IN_NO_ACTIVE_CHILD_fijb ((uint8_T)0U)
#define DRIV_subsys_IN_LaneChangeFinish ((uint8_T)1U)
#define DRIV_subsyst_IN_LaneChangeReady ((uint8_T)2U)
#define DRIV_subsystem_IN_DRIV_Straight ((uint8_T)1U)
#define DRIV_subsystem__IN_LaneChanging ((uint8_T)3U)
#define DRIV_subsystem_i_IN_LaneChaging ((uint8_T)1U)
#define DRIV_subsystem_int_IN_DRIV_Turn ((uint8_T)2U)
#define DRIV_subsystem_int_IN_RightTurn ((uint8_T)4U)
#define DRIV_subsystem_inte_IN_LeftTurn ((uint8_T)3U)

/* System initialize for atomic system: '<S57>/Chart' */
void DRIV_subsystem__Chart_ofih_Init(void)
{
  DRIV_subsystem_integrated_DW.temporalCounter_i1_oo45 = 0U;
  DRIV_subsystem_integrated_DW.is_active_c11_DRIV_subsystem_in = 0U;
  DRIV_subsystem_integrated_DW.is_c11_DRIV_subsystem_integrate =
    DRIV_su_IN_NO_ACTIVE_CHILD_oq1d;
}

/* Output and update for atomic system: '<S57>/Chart' */
void DRIV_subsystem_integ_Chart_bqvx(void)
{
  uint8_T rtb_state;

  /* Chart: '<S57>/Chart' */
  if (((uint32_T)DRIV_subsystem_integrated_DW.temporalCounter_i1_oo45) < 65535U)
  {
    DRIV_subsystem_integrated_DW.temporalCounter_i1_oo45 = (uint16_T)((int32_T)
      (((int32_T)DRIV_subsystem_integrated_DW.temporalCounter_i1_oo45) + 1));
  }

  if (((uint32_T)DRIV_subsystem_integrated_DW.is_active_c11_DRIV_subsystem_in) ==
      0U)
  {
    DRIV_subsystem_integrated_DW.is_active_c11_DRIV_subsystem_in = 1U;
    DRIV_subsystem_integrated_DW.is_c11_DRIV_subsystem_integrate =
      DRIV_subsystem_int_IN_INIT_f2kc;
    DRIV_subsystem_integrated_B.y_cby3 = false;
    rtb_state = 1U;
  }
  else
  {
    switch (DRIV_subsystem_integrated_DW.is_c11_DRIV_subsystem_integrate)
    {
     case DRIV_subsystem_in_IN_Delay_cvbc:
      if (!DRIV_subsystem_integrated_B.LogicalOperator1)
      {
        DRIV_subsystem_integrated_DW.is_c11_DRIV_subsystem_integrate =
          DRIV_subsystem_int_IN_INIT_f2kc;
        DRIV_subsystem_integrated_B.y_cby3 = false;
        rtb_state = 1U;
      }
      else if (DRIV_subsystem_integrated_DW.temporalCounter_i1_oo45 >=
               ((uint16_T)DRIV_subsystem_integrated_B.Gain_f5cc))
      {
        DRIV_subsystem_integrated_DW.is_c11_DRIV_subsystem_integrate =
          DRIV_subsystem_i_IN_Raised_onak;
        DRIV_subsystem_integrated_B.y_cby3 = true;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_cby3 = false;
        rtb_state = 2U;
      }
      break;

     case DRIV_subsystem_int_IN_INIT_f2kc:
      if (DRIV_subsystem_integrated_B.LogicalOperator1)
      {
        DRIV_subsystem_integrated_DW.is_c11_DRIV_subsystem_integrate =
          DRIV_subsystem_in_IN_Delay_cvbc;
        DRIV_subsystem_integrated_DW.temporalCounter_i1_oo45 = 0U;
        DRIV_subsystem_integrated_B.y_cby3 = false;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_cby3 = false;
        rtb_state = 1U;
      }
      break;

     default:
      if (!DRIV_subsystem_integrated_B.LogicalOperator1)
      {
        DRIV_subsystem_integrated_DW.is_c11_DRIV_subsystem_integrate =
          DRIV_subsystem_int_IN_INIT_f2kc;
        DRIV_subsystem_integrated_B.y_cby3 = false;
        rtb_state = 1U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_cby3 = true;
        rtb_state = 2U;
      }
      break;
    }
  }

  /* End of Chart: '<S57>/Chart' */
}

/* System initialize for atomic system: '<S58>/Chart' */
void DRIV_subsystem__Chart_kkzj_Init(void)
{
  DRIV_subsystem_integrated_DW.temporalCounter_i1_jygd = 0U;
  DRIV_subsystem_integrated_DW.is_active_c12_DRIV_subsystem_in = 0U;
  DRIV_subsystem_integrated_DW.is_c12_DRIV_subsystem_integrate =
    DRIV_su_IN_NO_ACTIVE_CHILD_bsjp;
}

/* Output and update for atomic system: '<S58>/Chart' */
void DRIV_subsystem_integ_Chart_bq1z(void)
{
  uint8_T rtb_state;

  /* Chart: '<S58>/Chart' */
  if (((uint32_T)DRIV_subsystem_integrated_DW.temporalCounter_i1_jygd) < 65535U)
  {
    DRIV_subsystem_integrated_DW.temporalCounter_i1_jygd = (uint16_T)((int32_T)
      (((int32_T)DRIV_subsystem_integrated_DW.temporalCounter_i1_jygd) + 1));
  }

  if (((uint32_T)DRIV_subsystem_integrated_DW.is_active_c12_DRIV_subsystem_in) ==
      0U)
  {
    DRIV_subsystem_integrated_DW.is_active_c12_DRIV_subsystem_in = 1U;
    DRIV_subsystem_integrated_DW.is_c12_DRIV_subsystem_integrate =
      DRIV_subsystem_int_IN_INIT_azo1;
    DRIV_subsystem_integrated_B.y_kjv1 = false;
    rtb_state = 1U;
  }
  else
  {
    switch (DRIV_subsystem_integrated_DW.is_c12_DRIV_subsystem_integrate)
    {
     case DRIV_subsystem_in_IN_Delay_afpd:
      if (!DRIV_subsystem_integrated_B.SignalConversion1_ckqc)
      {
        DRIV_subsystem_integrated_DW.is_c12_DRIV_subsystem_integrate =
          DRIV_subsystem_int_IN_INIT_azo1;
        DRIV_subsystem_integrated_B.y_kjv1 = false;
        rtb_state = 1U;
      }
      else if (DRIV_subsystem_integrated_DW.temporalCounter_i1_jygd >=
               ((uint16_T)DRIV_subsystem_integrated_B.Gain_f5cc))
      {
        DRIV_subsystem_integrated_DW.is_c12_DRIV_subsystem_integrate =
          DRIV_subsystem_i_IN_Raised_bg2q;
        DRIV_subsystem_integrated_B.y_kjv1 = true;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_kjv1 = false;
        rtb_state = 2U;
      }
      break;

     case DRIV_subsystem_int_IN_INIT_azo1:
      if (DRIV_subsystem_integrated_B.SignalConversion1_ckqc)
      {
        DRIV_subsystem_integrated_DW.is_c12_DRIV_subsystem_integrate =
          DRIV_subsystem_in_IN_Delay_afpd;
        DRIV_subsystem_integrated_DW.temporalCounter_i1_jygd = 0U;
        DRIV_subsystem_integrated_B.y_kjv1 = false;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_kjv1 = false;
        rtb_state = 1U;
      }
      break;

     default:
      if (!DRIV_subsystem_integrated_B.SignalConversion1_ckqc)
      {
        DRIV_subsystem_integrated_DW.is_c12_DRIV_subsystem_integrate =
          DRIV_subsystem_int_IN_INIT_azo1;
        DRIV_subsystem_integrated_B.y_kjv1 = false;
        rtb_state = 1U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_kjv1 = true;
        rtb_state = 2U;
      }
      break;
    }
  }

  /* End of Chart: '<S58>/Chart' */
}

/* System initialize for atomic system: '<S66>/Chart' */
void DRIV_subsystem__Chart_agnq_Init(void)
{
  DRIV_subsystem_integrated_DW.temporalCounter_i1_clr5 = 0U;
  DRIV_subsystem_integrated_DW.is_active_c26_DRIV_subsystem_in = 0U;
  DRIV_subsystem_integrated_DW.is_c26_DRIV_subsystem_integrate =
    DRIV_su_IN_NO_ACTIVE_CHILD_mhhz;
}

/* Output and update for atomic system: '<S66>/Chart' */
void DRIV_subsystem_integ_Chart_drwl(void)
{
  uint8_T rtb_state;

  /* Chart: '<S66>/Chart' */
  if (((uint32_T)DRIV_subsystem_integrated_DW.temporalCounter_i1_clr5) < 65535U)
  {
    DRIV_subsystem_integrated_DW.temporalCounter_i1_clr5 = (uint16_T)((int32_T)
      (((int32_T)DRIV_subsystem_integrated_DW.temporalCounter_i1_clr5) + 1));
  }

  if (((uint32_T)DRIV_subsystem_integrated_DW.is_active_c26_DRIV_subsystem_in) ==
      0U)
  {
    DRIV_subsystem_integrated_DW.is_active_c26_DRIV_subsystem_in = 1U;
    DRIV_subsystem_integrated_DW.is_c26_DRIV_subsystem_integrate =
      DRIV_subsystem_int_IN_INIT_kdwe;
    DRIV_subsystem_integrated_B.y_d4by = false;
    rtb_state = 1U;
  }
  else
  {
    switch (DRIV_subsystem_integrated_DW.is_c26_DRIV_subsystem_integrate)
    {
     case DRIV_subsystem_in_IN_Delay_mjcb:
      if (!DRIV_subsystem_integrated_B.SignalConversion1_ckqc)
      {
        DRIV_subsystem_integrated_DW.is_c26_DRIV_subsystem_integrate =
          DRIV_subsystem_int_IN_INIT_kdwe;
        DRIV_subsystem_integrated_B.y_d4by = false;
        rtb_state = 1U;
      }
      else if (DRIV_subsystem_integrated_DW.temporalCounter_i1_clr5 >=
               ((uint16_T)DRIV_subsystem_integrated_B.Gain_f5cc))
      {
        DRIV_subsystem_integrated_DW.is_c26_DRIV_subsystem_integrate =
          DRIV_subsystem_i_IN_Raised_a4an;
        DRIV_subsystem_integrated_B.y_d4by = true;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_d4by = false;
        rtb_state = 2U;
      }
      break;

     case DRIV_subsystem_int_IN_INIT_kdwe:
      if (DRIV_subsystem_integrated_B.SignalConversion1_ckqc)
      {
        DRIV_subsystem_integrated_DW.is_c26_DRIV_subsystem_integrate =
          DRIV_subsystem_in_IN_Delay_mjcb;
        DRIV_subsystem_integrated_DW.temporalCounter_i1_clr5 = 0U;
        DRIV_subsystem_integrated_B.y_d4by = false;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_d4by = false;
        rtb_state = 1U;
      }
      break;

     default:
      if (!DRIV_subsystem_integrated_B.SignalConversion1_ckqc)
      {
        DRIV_subsystem_integrated_DW.is_c26_DRIV_subsystem_integrate =
          DRIV_subsystem_int_IN_INIT_kdwe;
        DRIV_subsystem_integrated_B.y_d4by = false;
        rtb_state = 1U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_d4by = true;
        rtb_state = 2U;
      }
      break;
    }
  }

  /* End of Chart: '<S66>/Chart' */
}

/* System initialize for atomic system: '<S67>/Chart' */
void DRIV_subsystem__Chart_cnal_Init(void)
{
  DRIV_subsystem_integrated_DW.temporalCounter_i1 = 0U;
  DRIV_subsystem_integrated_DW.is_active_c14_DRIV_subsystem_in = 0U;
  DRIV_subsystem_integrated_DW.is_c14_DRIV_subsystem_integrate =
    DRIV_su_IN_NO_ACTIVE_CHILD_dgr5;
}

/* Output and update for atomic system: '<S67>/Chart' */
void DRIV_subsystem_integ_Chart_fy0n(void)
{
  uint8_T rtb_state;

  /* Chart: '<S67>/Chart' */
  if (DRIV_subsystem_integrated_DW.temporalCounter_i1 < MAX_uint32_T)
  {
    DRIV_subsystem_integrated_DW.temporalCounter_i1++;
  }

  if (((uint32_T)DRIV_subsystem_integrated_DW.is_active_c14_DRIV_subsystem_in) ==
      0U)
  {
    DRIV_subsystem_integrated_DW.is_active_c14_DRIV_subsystem_in = 1U;
    DRIV_subsystem_integrated_DW.is_c14_DRIV_subsystem_integrate =
      DRIV_subsystem_int_IN_INIT_bp24;
    DRIV_subsystem_integrated_B.y_metc = false;
    rtb_state = 1U;
  }
  else
  {
    switch (DRIV_subsystem_integrated_DW.is_c14_DRIV_subsystem_integrate)
    {
     case DRIV_subsystem_in_IN_Delay_babc:
      if (!DRIV_subsystem_integrated_B.SignalConversion1_ckqc)
      {
        DRIV_subsystem_integrated_DW.is_c14_DRIV_subsystem_integrate =
          DRIV_subsystem_int_IN_INIT_bp24;
        DRIV_subsystem_integrated_B.y_metc = false;
        rtb_state = 1U;
      }
      else if (DRIV_subsystem_integrated_DW.temporalCounter_i1 >= ((uint32_T)
                DRIV_subsystem_integrate_ConstB.Gain))
      {
        DRIV_subsystem_integrated_DW.is_c14_DRIV_subsystem_integrate =
          DRIV_subsystem_i_IN_Raised_nqyb;
        DRIV_subsystem_integrated_B.y_metc = true;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_metc = false;
        rtb_state = 2U;
      }
      break;

     case DRIV_subsystem_int_IN_INIT_bp24:
      if (DRIV_subsystem_integrated_B.SignalConversion1_ckqc)
      {
        DRIV_subsystem_integrated_DW.is_c14_DRIV_subsystem_integrate =
          DRIV_subsystem_in_IN_Delay_babc;
        DRIV_subsystem_integrated_DW.temporalCounter_i1 = 0U;
        DRIV_subsystem_integrated_B.y_metc = false;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_metc = false;
        rtb_state = 1U;
      }
      break;

     default:
      if (!DRIV_subsystem_integrated_B.SignalConversion1_ckqc)
      {
        DRIV_subsystem_integrated_DW.is_c14_DRIV_subsystem_integrate =
          DRIV_subsystem_int_IN_INIT_bp24;
        DRIV_subsystem_integrated_B.y_metc = false;
        rtb_state = 1U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_metc = true;
        rtb_state = 2U;
      }
      break;
    }
  }

  /* End of Chart: '<S67>/Chart' */
}

/* System initialize for atomic system: '<S71>/Chart' */
void DRIV_subsystem__Chart_e245_Init(void)
{
  DRIV_subsystem_integrated_DW.temporalCounter_i1_b5vo = 0U;
  DRIV_subsystem_integrated_DW.is_active_c13_DRIV_subsystem_in = 0U;
  DRIV_subsystem_integrated_DW.is_c13_DRIV_subsystem_integrate =
    DRIV_su_IN_NO_ACTIVE_CHILD_hjt1;
}

/* Output and update for atomic system: '<S71>/Chart' */
void DRIV_subsystem_integ_Chart_fsje(void)
{
  uint8_T rtb_state;

  /* Chart: '<S71>/Chart' */
  if (((uint32_T)DRIV_subsystem_integrated_DW.temporalCounter_i1_b5vo) < 65535U)
  {
    DRIV_subsystem_integrated_DW.temporalCounter_i1_b5vo = (uint16_T)((int32_T)
      (((int32_T)DRIV_subsystem_integrated_DW.temporalCounter_i1_b5vo) + 1));
  }

  if (((uint32_T)DRIV_subsystem_integrated_DW.is_active_c13_DRIV_subsystem_in) ==
      0U)
  {
    DRIV_subsystem_integrated_DW.is_active_c13_DRIV_subsystem_in = 1U;
    DRIV_subsystem_integrated_DW.is_c13_DRIV_subsystem_integrate =
      DRIV_subsystem_int_IN_INIT_ojmt;
    DRIV_subsystem_integrated_B.y_aq4x = false;
    rtb_state = 1U;
  }
  else
  {
    switch (DRIV_subsystem_integrated_DW.is_c13_DRIV_subsystem_integrate)
    {
     case DRIV_subsystem_in_IN_Delay_k2dt:
      if (!DRIV_subsystem_integrated_B.LogicalOperator1)
      {
        DRIV_subsystem_integrated_DW.is_c13_DRIV_subsystem_integrate =
          DRIV_subsystem_int_IN_INIT_ojmt;
        DRIV_subsystem_integrated_B.y_aq4x = false;
        rtb_state = 1U;
      }
      else if (DRIV_subsystem_integrated_DW.temporalCounter_i1_b5vo >=
               ((uint16_T)DRIV_subsystem_integrated_B.Gain_f5cc))
      {
        DRIV_subsystem_integrated_DW.is_c13_DRIV_subsystem_integrate =
          DRIV_subsystem_i_IN_Raised_iws1;
        DRIV_subsystem_integrated_B.y_aq4x = true;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_aq4x = false;
        rtb_state = 2U;
      }
      break;

     case DRIV_subsystem_int_IN_INIT_ojmt:
      if (DRIV_subsystem_integrated_B.LogicalOperator1)
      {
        DRIV_subsystem_integrated_DW.is_c13_DRIV_subsystem_integrate =
          DRIV_subsystem_in_IN_Delay_k2dt;
        DRIV_subsystem_integrated_DW.temporalCounter_i1_b5vo = 0U;
        DRIV_subsystem_integrated_B.y_aq4x = false;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_aq4x = false;
        rtb_state = 1U;
      }
      break;

     default:
      if (!DRIV_subsystem_integrated_B.LogicalOperator1)
      {
        DRIV_subsystem_integrated_DW.is_c13_DRIV_subsystem_integrate =
          DRIV_subsystem_int_IN_INIT_ojmt;
        DRIV_subsystem_integrated_B.y_aq4x = false;
        rtb_state = 1U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_aq4x = true;
        rtb_state = 2U;
      }
      break;
    }
  }

  /* End of Chart: '<S71>/Chart' */
}

/* System initialize for action system: '<S48>/DRIV_LC_Intention_Judge' */
void DRIV_LC_Intention_Judge_Init(void)
{
  /* SystemInitialize for Chart: '<S57>/Chart' */
  DRIV_subsystem__Chart_ofih_Init();

  /* SystemInitialize for Chart: '<S58>/Chart' */
  DRIV_subsystem__Chart_kkzj_Init();

  /* SystemInitialize for Chart: '<S71>/Chart' */
  DRIV_subsystem__Chart_e245_Init();

  /* SystemInitialize for Chart: '<S66>/Chart' */
  DRIV_subsystem__Chart_agnq_Init();

  /* SystemInitialize for Chart: '<S67>/Chart' */
  DRIV_subsystem__Chart_cnal_Init();

  /* SystemInitialize for Chart: '<S54>/DRIV_Status' */
  DRIV_subsystem_integrated_DW.is_LeftTurn = DRIV_su_IN_NO_ACTIVE_CHILD_fijb;
  DRIV_subsystem_integrated_DW.is_RightTurn = DRIV_su_IN_NO_ACTIVE_CHILD_fijb;
  DRIV_subsystem_integrated_DW.is_active_c4_DRIV_subsystem_int = 0U;
  DRIV_subsystem_integrated_DW.is_c4_DRIV_subsystem_integrated =
    DRIV_su_IN_NO_ACTIVE_CHILD_fijb;
}

/* Output and update for action system: '<S48>/DRIV_LC_Intention_Judge' */
void DRIV_LC_Intention_Judge(void)
{
  boolean_T rtb_LogicalOperator1_j2uf;
  real32_T rtb_SignalConversion;
  boolean_T rtb_Logic_idx_0;
  boolean_T rtb_Logic_h3kh_idx_0;

  /* DataTypeConversion: '<S52>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  DRIV_subsystem_integrated_B.LogicalOperator1 =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState;

  /* Gain: '<S57>/Gain' incorporates:
   *  Constant: '<S56>/Constant12'
   */
  DRIV_subsystem_integrated_B.Gain_f5cc = 100.0F * kfDRIV_t_TurnLightLeftOn_Time;

  /* Chart: '<S57>/Chart' */
  DRIV_subsystem_integ_Chart_bqvx();

  /* Logic: '<S56>/Logical Operator1' incorporates:
   *  Constant: '<S56>/Constant9'
   *  Inport: '<Root>/EGMO_DataBus'
   *  RelationalOperator: '<S56>/Relational Operator6'
   */
  VbDRIV_LeftSide_LC_Req = ((DRIV_subsystem_integrated_B.y_cby3) ||
    (VsEGMO_DataBus.motion.steer_angle_filtered > kfDRIV_SteerAngleThreshold));

  /* DataTypeConversion: '<S52>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  DRIV_subsystem_integrated_B.SignalConversion1_ckqc =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState;

  /* Gain: '<S58>/Gain' incorporates:
   *  Constant: '<S56>/Constant5'
   */
  DRIV_subsystem_integrated_B.Gain_f5cc = 100.0F *
    kfDRIV_t_TurnLightRightOn_Time;

  /* Chart: '<S58>/Chart' */
  DRIV_subsystem_integ_Chart_bq1z();

  /* Logic: '<S56>/Logical Operator2' incorporates:
   *  Constant: '<S56>/Constant1'
   *  Gain: '<S56>/Gain'
   *  Inport: '<Root>/EGMO_DataBus'
   *  RelationalOperator: '<S56>/Relational Operator1'
   */
  VbDRIV_RightSide_LC_Req = ((DRIV_subsystem_integrated_B.y_kjv1) ||
    (VsEGMO_DataBus.motion.steer_angle_filtered < ((-1.0F) *
    kfDRIV_SteerAngleThreshold)));

  /* Delay: '<S53>/Delay' */
  DRIV_subsystem_integrated_B.Gain_f5cc =
    DRIV_subsystem_integrated_DW.Delay_DSTATE;

  /* MATLAB Function: '<S53>/DtrmnLCParameter' */
  DtrmnLCParameter();

  /* CombinatorialLogic: '<S68>/Logic' incorporates:
   *  Memory: '<S61>/Memory'
   *  Memory: '<S68>/Memory'
   */
  rtb_Logic_idx_0 = DRIV_subsystem_integrate_ConstP.pooled14[(((((uint32_T)
    (VbDRIV_Touched_new_lane ? 1U : 0U)) << 1) +
    (DRIV_subsystem_integrated_DW.Memory_PreviousInput ? 1U : 0U)) << 1) +
    (DRIV_subsystem_integrated_DW.Memory_PreviousInput_mg0c ? 1U : 0U)];

  /* SignalConversion: '<S52>/Signal Conversion2' incorporates:
   *  Inport: '<Root>/EGMO_DataBus'
   */
  VfDRIV_yawrate = VsEGMO_DataBus.motion.yaw_rate_road;

  /* Logic: '<S62>/Logical Operator2' incorporates:
   *  Abs: '<S62>/Abs'
   *  Abs: '<S62>/Abs6'
   *  Constant: '<S62>/Constant2'
   *  Constant: '<S62>/Constant9'
   *  RelationalOperator: '<S62>/Relational Operator11'
   *  RelationalOperator: '<S62>/Relational Operator3'
   */
  rtb_LogicalOperator1_j2uf = ((((real32_T)fabs((real_T)VfDRIV_yawrate)) >
    kfDRIV_YawRateThreshold2) || (((real32_T)fabs((real_T)VfDRIV_c1_heading)) >
    kfDRIV_c1_threshold));

  /* Logic: '<S52>/Logical Operator1' */
  DRIV_subsystem_integrated_B.LogicalOperator1 =
    ((DRIV_subsystem_integrated_B.LogicalOperator1) ||
     (DRIV_subsystem_integrated_B.SignalConversion1_ckqc));

  /* Gain: '<S71>/Gain' incorporates:
   *  Constant: '<S63>/Constant12'
   */
  DRIV_subsystem_integrated_B.Gain_f5cc = 100.0F * kfDRIV_t_TurnLightOn_Time;

  /* Chart: '<S71>/Chart' */
  DRIV_subsystem_integ_Chart_fsje();

  /* RelationalOperator: '<S61>/Relational Operator7' incorporates:
   *  Constant: '<S61>/Constant5'
   */
  DRIV_subsystem_integrated_B.SignalConversion1_ckqc =
    (DRIV_subsystem_integrated_B.dist_to_ego_lane_center <=
     KfDRIV_d_Dist2LaneChangeFinish);

  /* Gain: '<S66>/Gain' incorporates:
   *  Constant: '<S61>/Constant1'
   */
  DRIV_subsystem_integrated_B.Gain_f5cc = 100.0F *
    KfDRIV_t_WaitTimeLaneChangeFinish;

  /* Chart: '<S66>/Chart' */
  DRIV_subsystem_integ_Chart_drwl();

  /* SignalConversion: '<S61>/Signal Conversion1' incorporates:
   *  Logic: '<S61>/Logical Operator2'
   */
  DRIV_subsystem_integrated_B.SignalConversion1_ckqc = (rtb_Logic_idx_0 &&
    (DRIV_subsystem_integrated_B.y_d4by));

  /* CombinatorialLogic: '<S74>/Logic' incorporates:
   *  DataTypeConversion: '<S65>/Data Type Conversion2'
   *  DataTypeConversion: '<S65>/Data Type Conversion3'
   *  Memory: '<S74>/Memory'
   */
  rtb_Logic_h3kh_idx_0 = DRIV_subsystem_integrate_ConstP.pooled14[(((((uint32_T)
    (rtb_LogicalOperator1_j2uf ? 1U : 0U)) << 1) +
    (DRIV_subsystem_integrated_B.SignalConversion1_ckqc ? 1U : 0U)) << 1) +
    (DRIV_subsystem_integrated_DW.Memory_PreviousInput_o1pn ? 1U : 0U)];

  /* Chart: '<S67>/Chart' */
  DRIV_subsystem_integ_Chart_fy0n();

  /* Logic: '<S65>/Logical Operator1' incorporates:
   *  Constant: '<S65>/Constant'
   *  Constant: '<S65>/Constant1'
   *  Logic: '<S65>/Logical Operator2'
   *  Logic: '<S65>/Logical Operator3'
   *  RelationalOperator: '<S65>/Relational Operator'
   *  RelationalOperator: '<S65>/Relational Operator1'
   */
  rtb_LogicalOperator1_j2uf = ((((rtb_LogicalOperator1_j2uf == false) &&
    (DRIV_subsystem_integrated_B.SignalConversion1_ckqc == false)) &&
    (DRIV_subsystem_integrated_B.y_metc)) || (rtb_LogicalOperator1_j2uf ||
    (DRIV_subsystem_integrated_B.SignalConversion1_ckqc)));

  /* CombinatorialLogic: '<S73>/Logic' incorporates:
   *  Abs: '<S63>/Abs1'
   *  Abs: '<S63>/Abs2'
   *  Abs: '<S63>/Abs3'
   *  Constant: '<S63>/Constant3'
   *  Constant: '<S63>/Constant4'
   *  Constant: '<S63>/Constant7'
   *  Constant: '<S63>/Constant9'
   *  Delay: '<S63>/Delay'
   *  Logic: '<S63>/Logical Operator'
   *  Logic: '<S63>/Logical Operator5'
   *  Memory: '<S73>/Memory'
   *  Product: '<S63>/Divide'
   *  RelationalOperator: '<S63>/Relational Operator4'
   *  RelationalOperator: '<S63>/Relational Operator6'
   *  RelationalOperator: '<S63>/Relational Operator8'
   *  Sum: '<S63>/Subtract1'
   */
  rtb_LogicalOperator1_j2uf = DRIV_subsystem_integrate_ConstP.pooled14
    [(((((uint32_T)(((((((real32_T)fabs((real_T)((real32_T)
    ((VfDRIV_Steer_Torque_Filter -
      DRIV_subsystem_integrated_DW.Delay_DSTATE_okrl) /
     kfDRIV_t_PeriodFunctionCall)))) >= kfDRIV_TorqueRate_LC_Threshold) ||
                       (((real32_T)fabs((real_T)VfDRIV_yawrate)) >=
                        kfDRIV_YawRateThreshold)) || (((real32_T)fabs((real_T)
    VfDRIV_SteerAngleRate)) >= kfDRIV_SteerAngleRateThreshold)) ||
                     (DRIV_subsystem_integrated_B.y_aq4x)) ? 1 : 0)) << 1) +
       (rtb_LogicalOperator1_j2uf ? 1U : 0U)) << 1) +
    (DRIV_subsystem_integrated_DW.Memory_PreviousInput_jnq3 ? 1U : 0U)];

  /* SignalConversion: '<S65>/Signal Conversion2' */
  VbDRIV_LaneChangeReady_Req = rtb_LogicalOperator1_j2uf;

  /* SignalConversion: '<S65>/Signal Conversion3' */
  VbDRIV_LaneChanging_Req = rtb_Logic_h3kh_idx_0;

  /* SignalConversion: '<S65>/Signal Conversion4' incorporates:
   *  DataTypeConversion: '<S65>/Data Type Conversion3'
   */
  VbDRIV_LaneChangeFinish_Req =
    DRIV_subsystem_integrated_B.SignalConversion1_ckqc;

  /* Logic: '<S52>/Logical Operator3' */
  VbDRIV_LC_Enable = ((VbDRIV_LaneChangeReady_Req || VbDRIV_LaneChanging_Req) ||
                      VbDRIV_LaneChangeFinish_Req);

  /* RelationalOperator: '<S55>/Relational Operator1' incorporates:
   *  Abs: '<S55>/Abs'
   *  Constant: '<S55>/Constant1'
   *  SignalConversion: '<S53>/Signal Conversion1'
   */
  VbDRIV_TurnType = (((real32_T)fabs((real_T)
    DRIV_subsystem_integrated_B.c2_curvature)) < 0.002F);

  /* Chart: '<S54>/DRIV_Status' */
  if (((uint32_T)DRIV_subsystem_integrated_DW.is_active_c4_DRIV_subsystem_int) ==
      0U)
  {
    DRIV_subsystem_integrated_DW.is_active_c4_DRIV_subsystem_int = 1U;
    DRIV_subsystem_integrated_DW.is_c4_DRIV_subsystem_integrated =
      DRIV_subsystem_IN_DRIV_Straight;
    VeDRIV_LeftChangeLane = LeftLC_NOT;
    VeDRIV_RightChangeLane = RightLC_NOT;
    VbDRIV_LaneKeepAssist = true;
  }
  else
  {
    switch (DRIV_subsystem_integrated_DW.is_c4_DRIV_subsystem_integrated)
    {
     case DRIV_subsystem_IN_DRIV_Straight:
      if (!VbDRIV_TurnType)
      {
        DRIV_subsystem_integrated_DW.is_c4_DRIV_subsystem_integrated =
          DRIV_subsystem_int_IN_DRIV_Turn;
        VeDRIV_LeftChangeLane = LeftLC_NOT;
        VeDRIV_RightChangeLane = RightLC_NOT;
        VbDRIV_LaneKeepAssist = true;
      }
      else if (VbDRIV_LC_Enable && VbDRIV_LeftSide_LC_Req)
      {
        DRIV_subsystem_integrated_DW.is_c4_DRIV_subsystem_integrated =
          DRIV_subsystem_inte_IN_LeftTurn;
        VeDRIV_RightChangeLane = RightLC_NOT;
        VbDRIV_LaneKeepAssist = false;
        DRIV_subsystem_integrated_DW.is_LeftTurn =
          DRIV_subsyst_IN_LaneChangeReady;
        VeDRIV_LeftChangeLane = LeftLC_Ready;
      }
      else if (VbDRIV_LC_Enable)
      {
        DRIV_subsystem_integrated_DW.is_c4_DRIV_subsystem_integrated =
          DRIV_subsystem_int_IN_RightTurn;
        VeDRIV_LeftChangeLane = LeftLC_NOT;
        VbDRIV_LaneKeepAssist = false;
        DRIV_subsystem_integrated_DW.is_RightTurn =
          DRIV_su_IN_LaneChangeReady_b1yo;
        VeDRIV_RightChangeLane = RightLC_Ready;
      }
      else
      {
        VeDRIV_LeftChangeLane = LeftLC_NOT;
        VeDRIV_RightChangeLane = RightLC_NOT;
        VbDRIV_LaneKeepAssist = true;
      }
      break;

     case DRIV_subsystem_int_IN_DRIV_Turn:
      if (VbDRIV_TurnType)
      {
        DRIV_subsystem_integrated_DW.is_c4_DRIV_subsystem_integrated =
          DRIV_subsystem_IN_DRIV_Straight;
        VeDRIV_LeftChangeLane = LeftLC_NOT;
        VeDRIV_RightChangeLane = RightLC_NOT;
        VbDRIV_LaneKeepAssist = true;
      }
      else if (VbDRIV_LC_Enable && VbDRIV_RightSide_LC_Req)
      {
        DRIV_subsystem_integrated_DW.is_c4_DRIV_subsystem_integrated =
          DRIV_subsystem_inte_IN_LeftTurn;
        VeDRIV_RightChangeLane = RightLC_NOT;
        VbDRIV_LaneKeepAssist = false;
        DRIV_subsystem_integrated_DW.is_LeftTurn =
          DRIV_subsyst_IN_LaneChangeReady;
        VeDRIV_LeftChangeLane = LeftLC_Ready;
      }
      else if (VbDRIV_LC_Enable)
      {
        DRIV_subsystem_integrated_DW.is_c4_DRIV_subsystem_integrated =
          DRIV_subsystem_int_IN_RightTurn;
        VeDRIV_LeftChangeLane = LeftLC_NOT;
        VbDRIV_LaneKeepAssist = false;
        DRIV_subsystem_integrated_DW.is_RightTurn =
          DRIV_su_IN_LaneChangeReady_b1yo;
        VeDRIV_RightChangeLane = RightLC_Ready;
      }
      else
      {
        VeDRIV_LeftChangeLane = LeftLC_NOT;
        VeDRIV_RightChangeLane = RightLC_NOT;
        VbDRIV_LaneKeepAssist = true;
      }
      break;

     case DRIV_subsystem_inte_IN_LeftTurn:
      if ((!VbDRIV_LC_Enable) && VbDRIV_TurnType)
      {
        DRIV_subsystem_integrated_DW.is_LeftTurn =
          DRIV_su_IN_NO_ACTIVE_CHILD_fijb;
        DRIV_subsystem_integrated_DW.is_c4_DRIV_subsystem_integrated =
          DRIV_subsystem_IN_DRIV_Straight;
        VeDRIV_LeftChangeLane = LeftLC_NOT;
        VeDRIV_RightChangeLane = RightLC_NOT;
        VbDRIV_LaneKeepAssist = true;
      }
      else if ((!VbDRIV_LC_Enable) && (!VbDRIV_TurnType))
      {
        DRIV_subsystem_integrated_DW.is_LeftTurn =
          DRIV_su_IN_NO_ACTIVE_CHILD_fijb;
        DRIV_subsystem_integrated_DW.is_c4_DRIV_subsystem_integrated =
          DRIV_subsystem_int_IN_DRIV_Turn;
        VeDRIV_LeftChangeLane = LeftLC_NOT;
        VeDRIV_RightChangeLane = RightLC_NOT;
        VbDRIV_LaneKeepAssist = true;
      }
      else
      {
        VeDRIV_RightChangeLane = RightLC_NOT;
        VbDRIV_LaneKeepAssist = false;
        switch (DRIV_subsystem_integrated_DW.is_LeftTurn)
        {
         case DRIV_subsys_IN_LaneChangeFinish:
          if (VbDRIV_LaneChangeReady_Req)
          {
            DRIV_subsystem_integrated_DW.is_LeftTurn =
              DRIV_subsyst_IN_LaneChangeReady;
            VeDRIV_LeftChangeLane = LeftLC_Ready;
          }
          else
          {
            VeDRIV_LeftChangeLane = LeftLC_Finish;
          }
          break;

         case DRIV_subsyst_IN_LaneChangeReady:
          if (VbDRIV_LaneChanging_Req)
          {
            DRIV_subsystem_integrated_DW.is_LeftTurn =
              DRIV_subsystem__IN_LaneChanging;
            VeDRIV_LeftChangeLane = LeftLC_Ing;
          }
          else
          {
            VeDRIV_LeftChangeLane = LeftLC_Ready;
          }
          break;

         default:
          if (VbDRIV_LaneChangeFinish_Req)
          {
            DRIV_subsystem_integrated_DW.is_LeftTurn =
              DRIV_subsys_IN_LaneChangeFinish;
            VeDRIV_LeftChangeLane = LeftLC_Finish;
          }
          else
          {
            VeDRIV_LeftChangeLane = LeftLC_Ing;
          }
          break;
        }
      }
      break;

     default:
      if ((!VbDRIV_LC_Enable) && VbDRIV_TurnType)
      {
        DRIV_subsystem_integrated_DW.is_RightTurn =
          DRIV_su_IN_NO_ACTIVE_CHILD_fijb;
        DRIV_subsystem_integrated_DW.is_c4_DRIV_subsystem_integrated =
          DRIV_subsystem_IN_DRIV_Straight;
        VeDRIV_LeftChangeLane = LeftLC_NOT;
        VeDRIV_RightChangeLane = RightLC_NOT;
        VbDRIV_LaneKeepAssist = true;
      }
      else if ((!VbDRIV_LC_Enable) && (!VbDRIV_TurnType))
      {
        DRIV_subsystem_integrated_DW.is_RightTurn =
          DRIV_su_IN_NO_ACTIVE_CHILD_fijb;
        DRIV_subsystem_integrated_DW.is_c4_DRIV_subsystem_integrated =
          DRIV_subsystem_int_IN_DRIV_Turn;
        VeDRIV_LeftChangeLane = LeftLC_NOT;
        VeDRIV_RightChangeLane = RightLC_NOT;
        VbDRIV_LaneKeepAssist = true;
      }
      else
      {
        VeDRIV_LeftChangeLane = LeftLC_NOT;
        VbDRIV_LaneKeepAssist = false;
        switch (DRIV_subsystem_integrated_DW.is_RightTurn)
        {
         case DRIV_subsystem_i_IN_LaneChaging:
          if (VbDRIV_LaneChangeFinish_Req)
          {
            DRIV_subsystem_integrated_DW.is_RightTurn =
              DRIV_s_IN_LaneChangeFinish_oyxb;
            VeDRIV_RightChangeLane = RightLC_Finish;
          }
          else
          {
            VeDRIV_RightChangeLane = RightLC_Ing;
          }
          break;

         case DRIV_s_IN_LaneChangeFinish_oyxb:
          if (VbDRIV_LaneChangeReady_Req)
          {
            DRIV_subsystem_integrated_DW.is_RightTurn =
              DRIV_su_IN_LaneChangeReady_b1yo;
            VeDRIV_RightChangeLane = RightLC_Ready;
          }
          else
          {
            VeDRIV_RightChangeLane = RightLC_Finish;
          }
          break;

         default:
          if (VbDRIV_LaneChanging_Req)
          {
            DRIV_subsystem_integrated_DW.is_RightTurn =
              DRIV_subsystem_i_IN_LaneChaging;
            VeDRIV_RightChangeLane = RightLC_Ing;
          }
          else
          {
            VeDRIV_RightChangeLane = RightLC_Ready;
          }
          break;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S54>/DRIV_Status' */

  /* SignalConversion: '<S75>/Signal Conversion3' incorporates:
   *  Constant: '<S75>/Constant1'
   */
  VbDRIV_Update_Override_Steering = KbDRIV_Update_Override_Steering;

  /* BusCreator: '<S75>/Bus Creator' incorporates:
   *  SignalConversion: '<S75>/Signal Conversion1'
   *  SignalConversion: '<S75>/Signal Conversion2'
   *  SignalConversion: '<S75>/Signal Conversion4'
   */
  DRIV_subsystem_integrated_B.Merge.VbDIRV_Override_Steering =
    VbDRIV_Update_Override_Steering;
  DRIV_subsystem_integrated_B.Merge.VeDRIV_LeftChangeLane =
    VeDRIV_LeftChangeLane;
  DRIV_subsystem_integrated_B.Merge.VeDRIV_RightChangeLane =
    VeDRIV_RightChangeLane;
  DRIV_subsystem_integrated_B.Merge.VbDRIV_LaneKeepAssist =
    VbDRIV_LaneKeepAssist;

  /* SignalConversion: '<S53>/Signal Conversion' */
  rtb_SignalConversion = DRIV_subsystem_integrated_B.c0_position;

  /* Update for Delay: '<S53>/Delay' */
  DRIV_subsystem_integrated_DW.Delay_DSTATE =
    DRIV_subsystem_integrated_B.distance_to_host;

  /* Update for Memory: '<S61>/Memory' */
  DRIV_subsystem_integrated_DW.Memory_PreviousInput =
    DRIV_subsystem_integrated_B.y_metc;

  /* Update for Memory: '<S68>/Memory' */
  DRIV_subsystem_integrated_DW.Memory_PreviousInput_mg0c = rtb_Logic_idx_0;

  /* Update for Memory: '<S74>/Memory' */
  DRIV_subsystem_integrated_DW.Memory_PreviousInput_o1pn = rtb_Logic_h3kh_idx_0;

  /* Update for Delay: '<S63>/Delay' */
  DRIV_subsystem_integrated_DW.Delay_DSTATE_okrl = VfDRIV_Steer_Torque_Filter;

  /* Update for Memory: '<S73>/Memory' */
  DRIV_subsystem_integrated_DW.Memory_PreviousInput_jnq3 =
    rtb_LogicalOperator1_j2uf;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
