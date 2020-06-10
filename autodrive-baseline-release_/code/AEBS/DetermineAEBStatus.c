/*
 * File: DetermineAEBStatus.c
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

#include "DetermineAEBStatus.h"

/* Include model header file for global data */
#include "AEBS_subsystem_integrated.h"
#include "AEBS_subsystem_integrated_private.h"

/* Named constants for Chart: '<S39>/DtrmnAEB_State' */
#define AEBS_su_IN_NO_ACTIVE_CHILD_bkoy ((uint8_T)0U)
#define AEBS_sub_IN_ConfidenceConfirmed ((uint8_T)1U)
#define AEBS_subsystem__IN_PartialBrake ((uint8_T)3U)
#define AEBS_subsystem_in_IN_StandStill ((uint8_T)3U)
#define AEBS_subsystem_int_IN_FullBrake ((uint8_T)2U)
#define AEBS_subsystem_inte_IN_Prebrake ((uint8_T)4U)
#define AEBS_subsystem_integ_IN_Actived ((uint8_T)1U)
#define AEBS_subsystem_integ_IN_StandBy ((uint8_T)2U)
#define AEBS_subsystem_integra_IN_Fault ((uint8_T)1U)
#define AEBS_subsystem_integrate_IN_OFF ((uint8_T)2U)
#define AEBS_subsystem_integrated_IN_ON ((uint8_T)3U)

/* Forward declaration for local functions */
static void AEBS__enter_atomic_PartialBrake(void);
static void AEBS_sub_enter_atomic_FullBrake(void);
static void AEBS_subs_exit_internal_Actived(void);
static void AEBS_subsystem_integrat_Actived(void);
static void AEBS_subsy_enter_atomic_Actived(void);
static void AEBS_sub_enter_internal_Actived(void);

/* Output and update for atomic system: '<S39>/CheckAEBS_SystemOverride' */
void AEBS_s_CheckAEBS_SystemOverride(void)
{
  int32_T rowIdx;

  /* CombinatorialLogic: '<S72>/Logic' incorporates:
   *  Constant: '<S43>/LoPosValInCllsnRednByBrkg  '
   *  Constant: '<S43>/LoPosValInCllsnRednByBrkg  1'
   *  Logic: '<S43>/Logical Operator'
   *  Logic: '<S43>/Logical Operator2'
   *  Logic: '<S43>/Logical Operator3'
   *  Logic: '<S43>/Logical Operator4'
   *  Memory: '<S72>/Memory'
   *  RelationalOperator: '<S43>/Relational Operator'
   *  RelationalOperator: '<S43>/Relational Operator1'
   */
  rowIdx = (int32_T)((uint32_T)((((((uint32_T)
    (((AEBS_subsystem_integrated_B.Switch_eddh) &&
      (AEBS_subsystem_integrated_B.LogicalOperator_pqhk)) ? 1 : 0)) << 1) +
    ((uint32_T)(((!AEBS_subsystem_integrated_B.LogicalOperator_pqhk) ||
                 ((AEBS_subsystem_integrated_B.DataTypeConversion5 <
                   KfAEBS_LoPosValInCllsnRednByBrkg) && (VfAEBS_veh_speed_used >
    KfAEBS_SpdMinOvrdAccrResetInCllsnRednByBrkg))) ? 1 : 0))) << 1) +
    (AEBS_subsystem_integrated_DW.Memory_PreviousInput_ehjf ? 1U : 0U)));
  AEBS_subsystem_integrated_B.Logic_lzmf[0U] =
    AEBS_subsystem_integrate_ConstP.pooled22[(uint32_T)rowIdx];
  AEBS_subsystem_integrated_B.Logic_lzmf[1U] =
    AEBS_subsystem_integrate_ConstP.pooled22[((uint32_T)rowIdx) + 8U];

  /* Update for Memory: '<S72>/Memory' */
  AEBS_subsystem_integrated_DW.Memory_PreviousInput_ehjf =
    AEBS_subsystem_integrated_B.Logic_lzmf[0];
}

/* Function for Chart: '<S39>/DtrmnAEB_State' */
static void AEBS__enter_atomic_PartialBrake(void)
{
  AEBS_subsystem_integrated_B.actived_state_bp54 =
    AEBS_AEBState_PartialBrakeActived;
  VfAEBS_AEB_request_beforeSend = true;
  AEBS_subsystem_integrated_DW.exit_actived = ((VfAEBS_AEB_deactive ||
    (AEBS_subsystem_integrated_B.Logic_lzmf[0])) || (((VfAEBS_preBrake_dactive &&
    VfAEBS_partialBrk_dactive) && VfAEBS_fullBrk_dactive) &&
    (AEBS_subsystem_integrated_DW.time_threat_gr5h <
     AEBS_subsystem_integrated_DW.KfAEBS_t_TimeExitActide_ibk1)));
}

/* Function for Chart: '<S39>/DtrmnAEB_State' */
static void AEBS_sub_enter_atomic_FullBrake(void)
{
  AEBS_subsystem_integrated_B.actived_state_bp54 =
    AEBS_AEBState_FullBrakeActived;
  VfAEBS_AEB_request_beforeSend = true;
  AEBS_subsystem_integrated_DW.exit_actived = ((VfAEBS_AEB_deactive ||
    (AEBS_subsystem_integrated_B.Logic_lzmf[0])) || (((VfAEBS_preBrake_dactive &&
    VfAEBS_partialBrk_dactive) && VfAEBS_fullBrk_dactive) &&
    (AEBS_subsystem_integrated_DW.time_threat_gr5h <
     AEBS_subsystem_integrated_DW.KfAEBS_t_TimeExitActide_ibk1)));
}

/* Function for Chart: '<S39>/DtrmnAEB_State' */
static void AEBS_subs_exit_internal_Actived(void)
{
  AEBS_subsystem_integrated_DW.is_Actived_jiof = AEBS_su_IN_NO_ACTIVE_CHILD_bkoy;
}

/* Function for Chart: '<S39>/DtrmnAEB_State' */
static void AEBS_subsystem_integrat_Actived(void)
{
  if (VfAEBS_veh_standstill)
  {
    AEBS_subs_exit_internal_Actived();
    AEBS_subsystem_integrated_DW.is_ON_p2gh = AEBS_subsystem_in_IN_StandStill;
    VfAEBS_AEB_request_beforeSend = true;
    AEBS_subsystem_integrated_B.actived_state_bp54 = AEBS_AEBState_WaitForDealy;
    AEBS_subsystem_integrated_DW.time_wait_o23a = 0.0F;
    AEBS_subsystem_integrated_DW.time_brkPdl_depressed = 0.0F;
  }
  else if (AEBS_subsystem_integrated_DW.exit_actived)
  {
    AEBS_subs_exit_internal_Actived();
    AEBS_subsystem_integrated_DW.is_ON_p2gh = AEBS_subsystem_integ_IN_StandBy;
    AEBS_subsystem_integrated_B.actived_state_bp54 = AEBS_AEBState_StandBy;
    VfAEBS_AEB_request_beforeSend = false;
    AEBS_subsystem_integrated_B.BusCreator.AEB_prebrake_req = false;
  }
  else
  {
    AEBS_subsystem_integrated_DW.time_threat_gr5h +=
      AEBS_subsystem_integrated_DW.KfAEBS_CTRL_PeriodFunction_oryw;

    /* Constant: '<S8>/Constant1' */
    AEBS_subsystem_integrated_DW.time_confidence_d4b4 =
      (AEBS_subsystem_integrated_DW.time_confidence_d4b4 * 1.0F) +
      AEBS_subsystem_integrated_DW.KfAEBS_CTRL_PeriodFunction_oryw;
    switch (AEBS_subsystem_integrated_DW.is_Actived_jiof)
    {
     case AEBS_sub_IN_ConfidenceConfirmed:
      AEBS_subsystem_integrated_B.actived_state_bp54 =
        AEBS_AEBState_ConfidenceConfirmed;
      VfAEBS_AEB_request_beforeSend = true;
      AEBS_subsystem_integrated_DW.exit_actived = (VfAEBS_AEB_deactive ||
        (AEBS_subsystem_integrated_B.Logic_lzmf[0]));
      break;

     case AEBS_subsystem_int_IN_FullBrake:
      if (AEBS_subsystem_integrated_DW.time_confidence_d4b4 >
          AEBS_subsystem_integrated_DW.KfAEBS_t_TimeBrakeConfdConfirme)
      {
        AEBS_subsystem_integrated_DW.is_Actived_jiof =
          AEBS_sub_IN_ConfidenceConfirmed;
        AEBS_subsystem_integrated_B.actived_state_bp54 =
          AEBS_AEBState_ConfidenceConfirmed;
        VfAEBS_AEB_request_beforeSend = true;
        AEBS_subsystem_integrated_DW.exit_actived = (VfAEBS_AEB_deactive ||
          (AEBS_subsystem_integrated_B.Logic_lzmf[0]));
      }
      else if (VfAEBS_fullBrk_dactive && VfAEBS_partialBrk_active)
      {
        AEBS_subsystem_integrated_DW.is_Actived_jiof =
          AEBS_subsystem__IN_PartialBrake;
        AEBS__enter_atomic_PartialBrake();
      }
      else
      {
        AEBS_subsystem_integrated_B.actived_state_bp54 =
          AEBS_AEBState_FullBrakeActived;
        VfAEBS_AEB_request_beforeSend = true;
        AEBS_subsystem_integrated_DW.exit_actived = ((VfAEBS_AEB_deactive ||
          (AEBS_subsystem_integrated_B.Logic_lzmf[0])) ||
          (((VfAEBS_preBrake_dactive && VfAEBS_partialBrk_dactive) &&
            VfAEBS_fullBrk_dactive) &&
           (AEBS_subsystem_integrated_DW.time_threat_gr5h <
            AEBS_subsystem_integrated_DW.KfAEBS_t_TimeExitActide_ibk1)));
      }
      break;

     case AEBS_subsystem__IN_PartialBrake:
      if (VfAEBS_fullBrk_active)
      {
        AEBS_subsystem_integrated_DW.is_Actived_jiof =
          AEBS_subsystem_int_IN_FullBrake;
        AEBS_sub_enter_atomic_FullBrake();
      }
      else
      {
        AEBS_subsystem_integrated_B.actived_state_bp54 =
          AEBS_AEBState_PartialBrakeActived;
        VfAEBS_AEB_request_beforeSend = true;
        AEBS_subsystem_integrated_DW.exit_actived = ((VfAEBS_AEB_deactive ||
          (AEBS_subsystem_integrated_B.Logic_lzmf[0])) ||
          (((VfAEBS_preBrake_dactive && VfAEBS_partialBrk_dactive) &&
            VfAEBS_fullBrk_dactive) &&
           (AEBS_subsystem_integrated_DW.time_threat_gr5h <
            AEBS_subsystem_integrated_DW.KfAEBS_t_TimeExitActide_ibk1)));
      }
      break;

     default:
      if (VfAEBS_fullBrk_active)
      {
        AEBS_subsystem_integrated_DW.is_Actived_jiof =
          AEBS_subsystem_int_IN_FullBrake;
        AEBS_sub_enter_atomic_FullBrake();
      }
      else if (VfAEBS_partialBrk_active)
      {
        AEBS_subsystem_integrated_DW.is_Actived_jiof =
          AEBS_subsystem__IN_PartialBrake;
        AEBS__enter_atomic_PartialBrake();
      }
      else
      {
        AEBS_subsystem_integrated_B.actived_state_bp54 =
          AEBS_AEBState_PreBrakeActived;
        AEBS_subsystem_integrated_B.BusCreator.AEB_prebrake_req = true;
        AEBS_subsystem_integrated_DW.exit_actived =
          (((VbAEBS_deactive_preBrk_timeOut || VfAEBS_AEB_deactive) ||
            (AEBS_subsystem_integrated_B.Logic_lzmf[0])) ||
           (((VfAEBS_preBrake_dactive && VfAEBS_partialBrk_dactive) &&
             VfAEBS_fullBrk_dactive) &&
            (AEBS_subsystem_integrated_DW.time_threat_gr5h <
             AEBS_subsystem_integrated_DW.KfAEBS_t_TimeExitActide_ibk1)));
      }
      break;
    }
  }
}

/* Function for Chart: '<S39>/DtrmnAEB_State' */
static void AEBS_subsy_enter_atomic_Actived(void)
{
  AEBS_subsystem_integrated_DW.time_threat_gr5h = 0.0F;
  AEBS_subsystem_integrated_DW.time_confidence_d4b4 = 0.0F;
  AEBS_subsystem_integrated_DW.exit_actived = false;
}

/* Function for Chart: '<S39>/DtrmnAEB_State' */
static void AEBS_sub_enter_internal_Actived(void)
{
  if (VfAEBS_fullBrk_active)
  {
    AEBS_subsystem_integrated_DW.is_Actived_jiof =
      AEBS_subsystem_int_IN_FullBrake;
    AEBS_sub_enter_atomic_FullBrake();
  }
  else if (VfAEBS_partialBrk_active)
  {
    AEBS_subsystem_integrated_DW.is_Actived_jiof =
      AEBS_subsystem__IN_PartialBrake;
    AEBS__enter_atomic_PartialBrake();
  }
  else
  {
    AEBS_subsystem_integrated_DW.is_Actived_jiof =
      AEBS_subsystem_inte_IN_Prebrake;
    AEBS_subsystem_integrated_B.actived_state_bp54 =
      AEBS_AEBState_PreBrakeActived;
    AEBS_subsystem_integrated_B.BusCreator.AEB_prebrake_req = true;
    AEBS_subsystem_integrated_DW.exit_actived =
      (((VbAEBS_deactive_preBrk_timeOut || VfAEBS_AEB_deactive) ||
        (AEBS_subsystem_integrated_B.Logic_lzmf[0])) ||
       (((VfAEBS_preBrake_dactive && VfAEBS_partialBrk_dactive) &&
         VfAEBS_fullBrk_dactive) &&
        (AEBS_subsystem_integrated_DW.time_threat_gr5h <
         AEBS_subsystem_integrated_DW.KfAEBS_t_TimeExitActide_ibk1)));
  }
}

/* System initialize for atomic system: '<S39>/DtrmnAEB_State' */
void AEBS_subsys_DtrmnAEB_State_Init(void)
{
  AEBS_subsystem_integrated_DW.is_ON_p2gh = AEBS_su_IN_NO_ACTIVE_CHILD_bkoy;
  AEBS_subsystem_integrated_DW.is_Actived_jiof = AEBS_su_IN_NO_ACTIVE_CHILD_bkoy;
  AEBS_subsystem_integrated_DW.is_active_c17_AEBS_subsystem_in = 0U;
  AEBS_subsystem_integrated_DW.is_c17_AEBS_subsystem_integrate =
    AEBS_su_IN_NO_ACTIVE_CHILD_bkoy;
}

/* Output and update for atomic system: '<S39>/DtrmnAEB_State' */
void AEBS_subsystem_i_DtrmnAEB_State(void)
{
  /* Chart: '<S39>/DtrmnAEB_State' */
  if (((uint32_T)AEBS_subsystem_integrated_DW.is_active_c17_AEBS_subsystem_in) ==
      0U)
  {
    AEBS_subsystem_integrated_DW.is_active_c17_AEBS_subsystem_in = 1U;
    AEBS_subsystem_integrated_DW.is_c17_AEBS_subsystem_integrate =
      AEBS_subsystem_integrate_IN_OFF;
    AEBS_subsystem_integrated_B.enable_state_dli2 = AEBS_EnblState_OFF;
    AEBS_subsystem_integrated_B.actived_state_bp54 = AEBS_AEBState_StandBy;
    VfAEBS_AEB_request_beforeSend = false;
    AEBS_subsystem_integrated_B.BusCreator.AEB_prebrake_req = false;
  }
  else
  {
    switch (AEBS_subsystem_integrated_DW.is_c17_AEBS_subsystem_integrate)
    {
     case AEBS_subsystem_integra_IN_Fault:
      if (!AEBS_subsystem_integrated_B.LogicalOperator_j5b5)
      {
        AEBS_subsystem_integrated_DW.is_c17_AEBS_subsystem_integrate =
          AEBS_subsystem_integrated_IN_ON;
        AEBS_subsystem_integrated_B.enable_state_dli2 = AEBS_EnblState_ON;
        AEBS_subsystem_integrated_DW.is_ON_p2gh =
          AEBS_subsystem_integ_IN_StandBy;
        AEBS_subsystem_integrated_B.actived_state_bp54 = AEBS_AEBState_StandBy;
        VfAEBS_AEB_request_beforeSend = false;
        AEBS_subsystem_integrated_B.BusCreator.AEB_prebrake_req = false;
      }
      else
      {
        AEBS_subsystem_integrated_B.enable_state_dli2 = AEBS_AEBState_Fault;
      }
      break;

     case AEBS_subsystem_integrate_IN_OFF:
      if (AEBS_subsystem_integrated_B.LogicalOperator_j5b5)
      {
        AEBS_subsystem_integrated_DW.is_c17_AEBS_subsystem_integrate =
          AEBS_subsystem_integra_IN_Fault;
        AEBS_subsystem_integrated_B.enable_state_dli2 = AEBS_AEBState_Fault;
      }
      else if (VfAEBS_AEB_enabled && (!VfAEBS_AEB_disabled))
      {
        AEBS_subsystem_integrated_DW.is_c17_AEBS_subsystem_integrate =
          AEBS_subsystem_integrated_IN_ON;
        AEBS_subsystem_integrated_B.enable_state_dli2 = AEBS_EnblState_ON;
        AEBS_subsystem_integrated_DW.is_ON_p2gh =
          AEBS_subsystem_integ_IN_StandBy;
        AEBS_subsystem_integrated_B.actived_state_bp54 = AEBS_AEBState_StandBy;
        VfAEBS_AEB_request_beforeSend = false;
        AEBS_subsystem_integrated_B.BusCreator.AEB_prebrake_req = false;
      }
      else
      {
        AEBS_subsystem_integrated_B.enable_state_dli2 = AEBS_EnblState_OFF;
        AEBS_subsystem_integrated_B.actived_state_bp54 = AEBS_AEBState_StandBy;
        VfAEBS_AEB_request_beforeSend = false;
        AEBS_subsystem_integrated_B.BusCreator.AEB_prebrake_req = false;
      }
      break;

     default:
      if (VfAEBS_AEB_disabled)
      {
        AEBS_subs_exit_internal_Actived();
        AEBS_subsystem_integrated_DW.is_ON_p2gh =
          AEBS_su_IN_NO_ACTIVE_CHILD_bkoy;
        AEBS_subsystem_integrated_DW.is_c17_AEBS_subsystem_integrate =
          AEBS_subsystem_integrate_IN_OFF;
        AEBS_subsystem_integrated_B.enable_state_dli2 = AEBS_EnblState_OFF;
        AEBS_subsystem_integrated_B.actived_state_bp54 = AEBS_AEBState_StandBy;
        VfAEBS_AEB_request_beforeSend = false;
        AEBS_subsystem_integrated_B.BusCreator.AEB_prebrake_req = false;
      }
      else if (AEBS_subsystem_integrated_B.LogicalOperator_j5b5)
      {
        AEBS_subs_exit_internal_Actived();
        AEBS_subsystem_integrated_DW.is_ON_p2gh =
          AEBS_su_IN_NO_ACTIVE_CHILD_bkoy;
        AEBS_subsystem_integrated_DW.is_c17_AEBS_subsystem_integrate =
          AEBS_subsystem_integra_IN_Fault;
        AEBS_subsystem_integrated_B.enable_state_dli2 = AEBS_AEBState_Fault;
      }
      else
      {
        AEBS_subsystem_integrated_B.enable_state_dli2 = AEBS_EnblState_ON;
        switch (AEBS_subsystem_integrated_DW.is_ON_p2gh)
        {
         case AEBS_subsystem_integ_IN_Actived:
          AEBS_subsystem_integrat_Actived();
          break;

         case AEBS_subsystem_integ_IN_StandBy:
          if ((VfAEBS_preBrake_active || VfAEBS_partialBrk_active) ||
              VfAEBS_fullBrk_active)
          {
            AEBS_subsystem_integrated_DW.is_ON_p2gh =
              AEBS_subsystem_integ_IN_Actived;
            AEBS_subsy_enter_atomic_Actived();
            AEBS_sub_enter_internal_Actived();
          }
          else
          {
            AEBS_subsystem_integrated_B.actived_state_bp54 =
              AEBS_AEBState_StandBy;
            VfAEBS_AEB_request_beforeSend = false;
            AEBS_subsystem_integrated_B.BusCreator.AEB_prebrake_req = false;
          }
          break;

         default:
          if ((((AEBS_subsystem_integrated_DW.time_wait_o23a >
                 AEBS_subsystem_integrated_DW.KfAEBS_t_TimeWait2StandbyT_gpm0) ||
                (AEBS_subsystem_integrated_B.Logic_lzmf[0])) ||
               (AEBS_subsystem_integrated_B.RelationalOperator)) ||
              (AEBS_subsystem_integrated_DW.time_brkPdl_depressed >
               AEBS_subsystem_integrated_DW.KfAEBS_t_BrkPdlDeprssd_Thr_diax))
          {
            AEBS_subsystem_integrated_DW.is_ON_p2gh =
              AEBS_subsystem_integ_IN_StandBy;
            AEBS_subsystem_integrated_B.actived_state_bp54 =
              AEBS_AEBState_StandBy;
            VfAEBS_AEB_request_beforeSend = false;
            AEBS_subsystem_integrated_B.BusCreator.AEB_prebrake_req = false;
          }
          else
          {
            AEBS_subsystem_integrated_B.actived_state_bp54 =
              AEBS_AEBState_WaitForDealy;
            AEBS_subsystem_integrated_DW.time_wait_o23a +=
              AEBS_subsystem_integrated_DW.KfAEBS_CTRL_PeriodFunction_oryw;
            if (((int32_T)AEBS_subsystem_integrated_B.DataTypeConversion12) == 1)
            {
              AEBS_subsystem_integrated_DW.time_brkPdl_depressed +=
                AEBS_subsystem_integrated_DW.KfAEBS_CTRL_PeriodFunction_oryw;
            }
            else
            {
              AEBS_subsystem_integrated_DW.time_brkPdl_depressed = 0.0F;
            }
          }
          break;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S39>/DtrmnAEB_State' */
}

/* System initialize for atomic system: '<S8>/DetermineAEBStatus' */
void AEBS_su_DetermineAEBStatus_Init(void)
{
  /* SystemInitialize for Chart: '<S39>/DtrmnAEB_State' */
  AEBS_subsys_DtrmnAEB_State_Init();
}

/* Output and update for atomic system: '<S8>/DetermineAEBStatus' */
void AEBS_subsyst_DetermineAEBStatus(void)
{
  boolean_T rtb_Switch_hz1g;

  /* Logic: '<S39>/Logical Operator' */
  AEBS_subsystem_integrated_B.LogicalOperator_pqhk = (VfAEBS_partialBrk_active ||
    VfAEBS_fullBrk_active);

  /* Outputs for Atomic SubSystem: '<S39>/CheckAEBS_SystemOverride' */
  AEBS_s_CheckAEBS_SystemOverride();

  /* End of Outputs for SubSystem: '<S39>/CheckAEBS_SystemOverride' */

  /* Logic: '<S46>/Logical Operator' incorporates:
   *  RelationalOperator: '<S46>/Relational Operator'
   *  RelationalOperator: '<S46>/Relational Operator1'
   *  RelationalOperator: '<S46>/Relational Operator2'
   *  S-Function (sfix_bitop): '<S46>/Bitwise Operator'
   *  S-Function (sfix_bitop): '<S46>/Bitwise Operator1'
   *  S-Function (sfix_bitop): '<S46>/Bitwise Operator2'
   */
  AEBS_subsystem_integrated_B.LogicalOperator_j5b5 =
    ((((AEBS_subsystem_integrated_B.Switch1 &
        AEBS_subsystem_integrate_ConstB.DataTypeConversion_j4el) ==
       AEBS_subsystem_integrate_ConstB.DataTypeConversion_j4el) ||
      ((AEBS_subsystem_integrated_B.Switch1 &
        AEBS_subsystem_integrate_ConstB.DataTypeConversion1_bqey) ==
       AEBS_subsystem_integrate_ConstB.DataTypeConversion1_bqey)) ||
     ((AEBS_subsystem_integrated_B.Switch1 &
       AEBS_subsystem_integrate_ConstB.DataTypeConversion2_lua5) ==
      AEBS_subsystem_integrate_ConstB.DataTypeConversion2_lua5));

  /* Chart: '<S39>/DtrmnAEB_State' */
  AEBS_subsystem_i_DtrmnAEB_State();

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S39>/Constant1'
   *  Constant: '<S39>/Constant3'
   */
  if (KbAEBS_Enable_OutputAEB)
  {
    rtb_Switch_hz1g = VfAEBS_AEB_request_beforeSend;
  }
  else
  {
    rtb_Switch_hz1g = false;
  }

  /* End of Switch: '<S39>/Switch' */

  /* Outputs for Atomic SubSystem: '<S39>/CalcAEBSAcceleration' */
  AEBS_subsy_CalcAEBSAcceleration();

  /* End of Outputs for SubSystem: '<S39>/CalcAEBSAcceleration' */

  /* Switch: '<S39>/Switch1' incorporates:
   *  Constant: '<S39>/Constant2'
   *  Constant: '<S39>/Constant4'
   */
  if (KbAEBS_Enable_OutputAEB)
  {
    AEBS_subsystem_integrated_B.BusCreator.AEB_acceleration_req =
      VfAEBS_AEB_accReq_beforeSend;
  }
  else
  {
    AEBS_subsystem_integrated_B.BusCreator.AEB_acceleration_req = 0.0F;
  }

  /* End of Switch: '<S39>/Switch1' */

  /* BusCreator: '<S39>/Bus Creator' */
  AEBS_subsystem_integrated_B.BusCreator.AEB_request = rtb_Switch_hz1g;
  AEBS_subsystem_integrated_B.BusCreator.AEB_brakeLight_req = rtb_Switch_hz1g;
  AEBS_subsystem_integrated_B.BusCreator.AEB_enabled_state =
    AEBS_subsystem_integrated_B.enable_state_dli2;
  AEBS_subsystem_integrated_B.BusCreator.AEB_actived_state =
    AEBS_subsystem_integrated_B.actived_state_bp54;
  AEBS_subsystem_integrated_B.BusCreator.AEB_error =
    AEBS_subsystem_integrated_B.Switch1;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
