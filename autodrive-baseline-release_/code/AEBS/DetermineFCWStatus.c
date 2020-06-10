/*
 * File: DetermineFCWStatus.c
 *
 * Code generated for Simulink model 'AEBS_subsystem_integrated'.
 *
 * Model version                  : 1.3091
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 16:35:01 2020
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

#include "DetermineFCWStatus.h"

/* Include model header file for global data */
#include "AEBS_subsystem_integrated.h"
#include "AEBS_subsystem_integrated_private.h"

/* Named constants for Chart: '<S193>/DtrmnFCW_State' */
#define AEBS_su_IN_NO_ACTIVE_CHILD_jh2z ((uint8_T)0U)
#define AEBS_subsystem__IN_Actived_p1bp ((uint8_T)1U)
#define AEBS_subsystem__IN_StandBy_l5sd ((uint8_T)2U)
#define AEBS_subsystem_in_IN_Fault_jngt ((uint8_T)1U)
#define AEBS_subsystem_inte_IN_OFF_kwdp ((uint8_T)2U)
#define AEBS_subsystem_integ_IN_ON_gqw1 ((uint8_T)3U)
#define AEBS_subsystem_integr_IN_Level1 ((uint8_T)1U)
#define AEBS_subsystem_integr_IN_Level2 ((uint8_T)2U)
#define AEBS_subsystem_integr_IN_Level3 ((uint8_T)3U)

/* Forward declaration for local functions */
static void AEBS__enter_atomic_Actived_fugv(void);
static void AEBS_subsys_enter_atomic_Level1(void);
static void AEBS_subsys_enter_atomic_Level2(void);
static void AEBS_subsys_enter_atomic_Level3(void);
static void AEB_enter_internal_Actived_czhb(void);
static void AEBS_exit_internal_Actived_b1oz(void);
static void AEBS_subsystem_int_Actived_idq1(void);

/* Output and update for atomic system: '<S193>/CheckAEBS_SystemOverride' */
void A_CheckAEBS_SystemOverride_c3e4(void)
{
  int32_T rowIdx;

  /* CombinatorialLogic: '<S200>/Logic' incorporates:
   *  Constant: '<S194>/Constant3'
   *  Constant: '<S196>/LoPosValInCllsnRednByBrkg  '
   *  Constant: '<S196>/LoPosValInCllsnRednByBrkg  1'
   *  Logic: '<S196>/Logical Operator'
   *  Logic: '<S196>/Logical Operator2'
   *  Logic: '<S196>/Logical Operator3'
   *  Logic: '<S196>/Logical Operator4'
   *  Memory: '<S200>/Memory'
   *  RelationalOperator: '<S196>/Relational Operator'
   *  RelationalOperator: '<S196>/Relational Operator1'
   */
  rowIdx = (int32_T)((uint32_T)((((((uint32_T)(((false) &&
    (AEBS_subsystem_integrated_B.Switch_eddh)) ? 1 : 0)) << 1) + ((uint32_T)
    (((!AEBS_subsystem_integrated_B.Switch_eddh) ||
      ((AEBS_subsystem_integrated_B.DataTypeConversion5 <
        KfAEBS_LoPosValInCllsnRednByBrkg) && (VfAEBS_veh_speed_used >
    KfAEBS_SpdMinOvrdAccrResetInCllsnRednByBrkg))) ? 1 : 0))) << 1) +
    (AEBS_subsystem_integrated_DW.Memory_PreviousInput ? 1U : 0U)));
  AEBS_subsystem_integrated_B.Logic[0U] =
    AEBS_subsystem_integrate_ConstP.pooled22[(uint32_T)rowIdx];
  AEBS_subsystem_integrated_B.Logic[1U] =
    AEBS_subsystem_integrate_ConstP.pooled22[((uint32_T)rowIdx) + 8U];

  /* Update for Memory: '<S200>/Memory' */
  AEBS_subsystem_integrated_DW.Memory_PreviousInput =
    AEBS_subsystem_integrated_B.Logic[0];
}

/* Function for Chart: '<S193>/DtrmnFCW_State' */
static void AEBS__enter_atomic_Actived_fugv(void)
{
  AEBS_subsystem_integrated_DW.time_threat = 0.0F;
  AEBS_subsystem_integrated_DW.time_confidence = 0.0F;
}

/* Function for Chart: '<S193>/DtrmnFCW_State' */
static void AEBS_subsys_enter_atomic_Level1(void)
{
  AEBS_subsystem_integrated_B.warn_level = 1U;
  AEBS_subsystem_integrated_B.actived_state = AEBS_FCWState_Level1Actived;
  AEBS_subsystem_integrated_DW.exit_flag = ((VfAEBS_FCW_deacitve ||
    (AEBS_subsystem_integrated_B.Logic[0])) || (((VfAEBS_FCWLev1_dactive &&
    VfAEBS_FCWLev2_dactive) && VfAEBS_FCWLev3_dactive) &&
    (AEBS_subsystem_integrated_DW.time_threat <
     AEBS_subsystem_integrated_DW.KfAEBS_t_TimeExitActide_ibk1)));
}

/* Function for Chart: '<S193>/DtrmnFCW_State' */
static void AEBS_subsys_enter_atomic_Level2(void)
{
  AEBS_subsystem_integrated_B.warn_level = 2U;
  AEBS_subsystem_integrated_B.actived_state = AEBS_FCWState_Level2Actived;
  AEBS_subsystem_integrated_DW.exit_flag = ((VfAEBS_FCW_deacitve ||
    (AEBS_subsystem_integrated_B.Logic[0])) || (((VfAEBS_FCWLev1_dactive &&
    VfAEBS_FCWLev2_dactive) && VfAEBS_FCWLev3_dactive) &&
    (AEBS_subsystem_integrated_DW.time_threat <
     AEBS_subsystem_integrated_DW.KfAEBS_t_TimeExitActide_ibk1)));
}

/* Function for Chart: '<S193>/DtrmnFCW_State' */
static void AEBS_subsys_enter_atomic_Level3(void)
{
  AEBS_subsystem_integrated_B.warn_level = 3U;
  AEBS_subsystem_integrated_B.actived_state = AEBS_FCWState_Level3Actived;
  AEBS_subsystem_integrated_DW.exit_flag = ((VfAEBS_FCW_deacitve ||
    (AEBS_subsystem_integrated_B.Logic[0])) || (((VfAEBS_FCWLev1_dactive &&
    VfAEBS_FCWLev2_dactive) && VfAEBS_FCWLev3_dactive) &&
    (AEBS_subsystem_integrated_DW.time_threat <
     AEBS_subsystem_integrated_DW.KfAEBS_t_TimeExitActide_ibk1)));
}

/* Function for Chart: '<S193>/DtrmnFCW_State' */
static void AEB_enter_internal_Actived_czhb(void)
{
  if (VfAEBS_FCWLev3_active)
  {
    AEBS_subsystem_integrated_DW.is_Actived = AEBS_subsystem_integr_IN_Level3;
    AEBS_subsys_enter_atomic_Level3();
  }
  else if (VfAEBS_FCWLev2_active)
  {
    AEBS_subsystem_integrated_DW.is_Actived = AEBS_subsystem_integr_IN_Level2;
    AEBS_subsys_enter_atomic_Level2();
  }
  else
  {
    AEBS_subsystem_integrated_DW.is_Actived = AEBS_subsystem_integr_IN_Level1;
    AEBS_subsys_enter_atomic_Level1();
  }
}

/* Function for Chart: '<S193>/DtrmnFCW_State' */
static void AEBS_exit_internal_Actived_b1oz(void)
{
  AEBS_subsystem_integrated_DW.is_Actived = AEBS_su_IN_NO_ACTIVE_CHILD_jh2z;
}

/* Function for Chart: '<S193>/DtrmnFCW_State' */
static void AEBS_subsystem_int_Actived_idq1(void)
{
  if ((AEBS_subsystem_integrated_DW.exit_flag) ||
      (AEBS_subsystem_integrated_B.vehicle_standstill))
  {
    AEBS_exit_internal_Actived_b1oz();
    AEBS_subsystem_integrated_DW.is_ON = AEBS_subsystem__IN_StandBy_l5sd;
    AEBS_subsystem_integrated_B.actived_state = AEBS_FCWState_StandBy;
  }
  else
  {
    AEBS_subsystem_integrated_B.request = true;
    AEBS_subsystem_integrated_DW.time_threat +=
      AEBS_subsystem_integrated_DW.KfAEBS_CTRL_PeriodFunction_oryw;

    /* Constant: '<S193>/Constant8' */
    AEBS_subsystem_integrated_DW.time_confidence =
      (AEBS_subsystem_integrated_DW.time_confidence * 1.0F) +
      AEBS_subsystem_integrated_DW.KfAEBS_CTRL_PeriodFunction_oryw;
    switch (AEBS_subsystem_integrated_DW.is_Actived)
    {
     case AEBS_subsystem_integr_IN_Level1:
      if (VfAEBS_FCWLev3_active)
      {
        AEBS_subsystem_integrated_DW.is_Actived =
          AEBS_subsystem_integr_IN_Level3;
        AEBS_subsys_enter_atomic_Level3();
      }
      else if (VfAEBS_FCWLev2_active)
      {
        AEBS_subsystem_integrated_DW.is_Actived =
          AEBS_subsystem_integr_IN_Level2;
        AEBS_subsys_enter_atomic_Level2();
      }
      else
      {
        AEBS_subsystem_integrated_B.warn_level = 1U;
        AEBS_subsystem_integrated_B.actived_state = AEBS_FCWState_Level1Actived;
        AEBS_subsystem_integrated_DW.exit_flag = ((VfAEBS_FCW_deacitve ||
          (AEBS_subsystem_integrated_B.Logic[0])) || (((VfAEBS_FCWLev1_dactive &&
          VfAEBS_FCWLev2_dactive) && VfAEBS_FCWLev3_dactive) &&
          (AEBS_subsystem_integrated_DW.time_threat <
           AEBS_subsystem_integrated_DW.KfAEBS_t_TimeExitActide_ibk1)));
      }
      break;

     case AEBS_subsystem_integr_IN_Level2:
      if (VfAEBS_FCWLev2_dactive)
      {
        AEBS_subsystem_integrated_DW.is_Actived =
          AEBS_subsystem_integr_IN_Level1;
        AEBS_subsys_enter_atomic_Level1();
      }
      else if (VfAEBS_FCWLev3_active)
      {
        AEBS_subsystem_integrated_DW.is_Actived =
          AEBS_subsystem_integr_IN_Level3;
        AEBS_subsys_enter_atomic_Level3();
      }
      else
      {
        AEBS_subsystem_integrated_B.warn_level = 2U;
        AEBS_subsystem_integrated_B.actived_state = AEBS_FCWState_Level2Actived;
        AEBS_subsystem_integrated_DW.exit_flag = ((VfAEBS_FCW_deacitve ||
          (AEBS_subsystem_integrated_B.Logic[0])) || (((VfAEBS_FCWLev1_dactive &&
          VfAEBS_FCWLev2_dactive) && VfAEBS_FCWLev3_dactive) &&
          (AEBS_subsystem_integrated_DW.time_threat <
           AEBS_subsystem_integrated_DW.KfAEBS_t_TimeExitActide_ibk1)));
      }
      break;

     default:
      if (VfAEBS_FCWLev3_dactive && VfAEBS_FCWLev2_dactive)
      {
        AEBS_subsystem_integrated_DW.is_Actived =
          AEBS_subsystem_integr_IN_Level1;
        AEBS_subsys_enter_atomic_Level1();
      }
      else if (VfAEBS_FCWLev3_dactive)
      {
        AEBS_subsystem_integrated_DW.is_Actived =
          AEBS_subsystem_integr_IN_Level2;
        AEBS_subsys_enter_atomic_Level2();
      }
      else
      {
        AEBS_subsystem_integrated_B.warn_level = 3U;
        AEBS_subsystem_integrated_B.actived_state = AEBS_FCWState_Level3Actived;
        AEBS_subsystem_integrated_DW.exit_flag = ((VfAEBS_FCW_deacitve ||
          (AEBS_subsystem_integrated_B.Logic[0])) || (((VfAEBS_FCWLev1_dactive &&
          VfAEBS_FCWLev2_dactive) && VfAEBS_FCWLev3_dactive) &&
          (AEBS_subsystem_integrated_DW.time_threat <
           AEBS_subsystem_integrated_DW.KfAEBS_t_TimeExitActide_ibk1)));
      }
      break;
    }
  }
}

/* System initialize for atomic system: '<S193>/DtrmnFCW_State' */
void AEBS_subsys_DtrmnFCW_State_Init(void)
{
  AEBS_subsystem_integrated_DW.is_ON = AEBS_su_IN_NO_ACTIVE_CHILD_jh2z;
  AEBS_subsystem_integrated_DW.is_Actived = AEBS_su_IN_NO_ACTIVE_CHILD_jh2z;
  AEBS_subsystem_integrated_DW.is_active_c21_AEBS_subsystem_in = 0U;
  AEBS_subsystem_integrated_DW.is_c21_AEBS_subsystem_integrate =
    AEBS_su_IN_NO_ACTIVE_CHILD_jh2z;
}

/* Output and update for atomic system: '<S193>/DtrmnFCW_State' */
void AEBS_subsystem_i_DtrmnFCW_State(void)
{
  /* Chart: '<S193>/DtrmnFCW_State' */
  if (((uint32_T)AEBS_subsystem_integrated_DW.is_active_c21_AEBS_subsystem_in) ==
      0U)
  {
    AEBS_subsystem_integrated_DW.is_active_c21_AEBS_subsystem_in = 1U;
    AEBS_subsystem_integrated_DW.is_c21_AEBS_subsystem_integrate =
      AEBS_subsystem_inte_IN_OFF_kwdp;
    AEBS_subsystem_integrated_B.enable_state = AEBS_EnblState_OFF;
    AEBS_subsystem_integrated_B.request = false;
  }
  else
  {
    switch (AEBS_subsystem_integrated_DW.is_c21_AEBS_subsystem_integrate)
    {
     case AEBS_subsystem_in_IN_Fault_jngt:
      if (!AEBS_subsystem_integrated_B.LogicalOperator)
      {
        AEBS_subsystem_integrated_DW.is_c21_AEBS_subsystem_integrate =
          AEBS_subsystem_integ_IN_ON_gqw1;
        AEBS_subsystem_integrated_DW.exit_flag = false;
        AEBS_subsystem_integrated_B.enable_state = AEBS_EnblState_ON;
        AEBS_subsystem_integrated_B.request = false;
        AEBS_subsystem_integrated_B.warn_level = 0U;
        AEBS_subsystem_integrated_DW.is_ON = AEBS_subsystem__IN_StandBy_l5sd;
        AEBS_subsystem_integrated_B.actived_state = AEBS_FCWState_StandBy;
      }
      else
      {
        AEBS_subsystem_integrated_B.enable_state = AEBS_AEBState_Fault;
        AEBS_subsystem_integrated_DW.time_wait +=
          AEBS_subsystem_integrated_DW.KfAEBS_CTRL_PeriodFunction_oryw;
        if (AEBS_subsystem_integrated_DW.time_wait >
            AEBS_subsystem_integrated_DW.KfAEBS_t_TimeWait2StandbyT_gpm0)
        {
          AEBS_subsystem_integrated_B.warn_level = 0U;
          AEBS_subsystem_integrated_B.request = false;
        }
      }
      break;

     case AEBS_subsystem_inte_IN_OFF_kwdp:
      if (AEBS_subsystem_integrated_B.LogicalOperator)
      {
        AEBS_subsystem_integrated_DW.is_c21_AEBS_subsystem_integrate =
          AEBS_subsystem_in_IN_Fault_jngt;
        AEBS_subsystem_integrated_DW.time_wait = 0.0F;
        AEBS_subsystem_integrated_B.enable_state = AEBS_AEBState_Fault;
      }
      else if (VfAEBS_FCW_enabled && (!VfAEBS_FCW_disabled))
      {
        AEBS_subsystem_integrated_DW.is_c21_AEBS_subsystem_integrate =
          AEBS_subsystem_integ_IN_ON_gqw1;
        AEBS_subsystem_integrated_DW.exit_flag = false;
        AEBS_subsystem_integrated_B.enable_state = AEBS_EnblState_ON;
        AEBS_subsystem_integrated_B.request = false;
        AEBS_subsystem_integrated_B.warn_level = 0U;
        AEBS_subsystem_integrated_DW.is_ON = AEBS_subsystem__IN_StandBy_l5sd;
        AEBS_subsystem_integrated_B.actived_state = AEBS_FCWState_StandBy;
      }
      else
      {
        AEBS_subsystem_integrated_B.enable_state = AEBS_EnblState_OFF;
        AEBS_subsystem_integrated_B.request = false;
      }
      break;

     default:
      if (VfAEBS_FCW_disabled)
      {
        AEBS_exit_internal_Actived_b1oz();
        AEBS_subsystem_integrated_DW.is_ON = AEBS_su_IN_NO_ACTIVE_CHILD_jh2z;
        AEBS_subsystem_integrated_DW.is_c21_AEBS_subsystem_integrate =
          AEBS_subsystem_inte_IN_OFF_kwdp;
        AEBS_subsystem_integrated_B.enable_state = AEBS_EnblState_OFF;
        AEBS_subsystem_integrated_B.request = false;
      }
      else if (AEBS_subsystem_integrated_B.LogicalOperator)
      {
        AEBS_exit_internal_Actived_b1oz();
        AEBS_subsystem_integrated_DW.is_ON = AEBS_su_IN_NO_ACTIVE_CHILD_jh2z;
        AEBS_subsystem_integrated_DW.is_c21_AEBS_subsystem_integrate =
          AEBS_subsystem_in_IN_Fault_jngt;
        AEBS_subsystem_integrated_DW.time_wait = 0.0F;
        AEBS_subsystem_integrated_B.enable_state = AEBS_AEBState_Fault;
      }
      else
      {
        AEBS_subsystem_integrated_B.enable_state = AEBS_EnblState_ON;
        AEBS_subsystem_integrated_B.request = false;
        AEBS_subsystem_integrated_B.warn_level = 0U;
        if (((uint32_T)AEBS_subsystem_integrated_DW.is_ON) ==
            AEBS_subsystem__IN_Actived_p1bp)
        {
          AEBS_subsystem_int_Actived_idq1();
        }
        else if ((VfAEBS_FCWLev1_active || VfAEBS_FCWLev2_active) ||
                 VfAEBS_FCWLev3_active)
        {
          AEBS_subsystem_integrated_DW.is_ON = AEBS_subsystem__IN_Actived_p1bp;
          AEBS__enter_atomic_Actived_fugv();
          AEB_enter_internal_Actived_czhb();
        }
        else
        {
          AEBS_subsystem_integrated_B.actived_state = AEBS_FCWState_StandBy;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S193>/DtrmnFCW_State' */
}

/* System initialize for atomic system: '<S10>/DetermineFCWStatus' */
void AEBS_su_DetermineFCWStatus_Init(void)
{
  /* SystemInitialize for Chart: '<S193>/DtrmnFCW_State' */
  AEBS_subsys_DtrmnFCW_State_Init();
}

/* Output and update for atomic system: '<S10>/DetermineFCWStatus' */
void AEBS_subsyst_DetermineFCWStatus(void)
{
  /* SignalConversion: '<S193>/BusConversion_InsertedFor_FCW_data_at_inport_0' */
  AEBS_subsystem_integrated_B.FCW_error = AEBS_subsystem_integrated_B.Switch2;

  /* Logic: '<S198>/Logical Operator' */
  AEBS_subsystem_integrated_B.Switch_eddh = ((VfAEBS_FCWLev1_active ||
    VfAEBS_FCWLev2_active) || VfAEBS_FCWLev3_active);

  /* Outputs for Atomic SubSystem: '<S193>/CheckAEBS_SystemOverride' */
  A_CheckAEBS_SystemOverride_c3e4();

  /* End of Outputs for SubSystem: '<S193>/CheckAEBS_SystemOverride' */

  /* Logic: '<S199>/Logical Operator' incorporates:
   *  RelationalOperator: '<S199>/Relational Operator'
   *  RelationalOperator: '<S199>/Relational Operator1'
   *  RelationalOperator: '<S199>/Relational Operator2'
   *  S-Function (sfix_bitop): '<S199>/Bitwise Operator'
   *  S-Function (sfix_bitop): '<S199>/Bitwise Operator1'
   *  S-Function (sfix_bitop): '<S199>/Bitwise Operator2'
   */
  AEBS_subsystem_integrated_B.LogicalOperator =
    ((((AEBS_subsystem_integrated_B.Switch2 &
        AEBS_subsystem_integrate_ConstB.DataTypeConversion_dfrt) ==
       AEBS_subsystem_integrate_ConstB.DataTypeConversion_dfrt) ||
      ((AEBS_subsystem_integrated_B.Switch2 &
        AEBS_subsystem_integrate_ConstB.DataTypeConversion1) ==
       AEBS_subsystem_integrate_ConstB.DataTypeConversion1)) ||
     ((AEBS_subsystem_integrated_B.Switch2 &
       AEBS_subsystem_integrate_ConstB.DataTypeConversion2) ==
      AEBS_subsystem_integrate_ConstB.DataTypeConversion2));

  /* Chart: '<S193>/DtrmnFCW_State' */
  AEBS_subsystem_i_DtrmnFCW_State();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
