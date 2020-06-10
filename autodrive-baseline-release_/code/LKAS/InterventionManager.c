/*
 * File: InterventionManager.c
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

#include "InterventionManager.h"

/* Include model header file for global data */
#include "LKAS_subsystem_integrated.h"
#include "LKAS_subsystem_integrated_private.h"

/* Named constants for Chart: '<S10>/sLKA' */
#define IN_Left_Intervention_Suppressed ((uint8_T)4U)
#define IN_Right_Intervention_Suppresse ((uint8_T)5U)
#define LKAS__IN_Intervention_Completed ((uint8_T)3U)
#define LKAS_su_IN_Intervention_Aborted ((uint8_T)2U)
#define LKAS_su_IN_NO_ACTIVE_CHILD_kz5b ((uint8_T)0U)
#define LKAS_subsystem__IN_Intervention ((uint8_T)1U)
#define LKAS_subsystem_inte_IN_Enabling ((uint8_T)2U)
#define LKAS_subsystem_inte_IN_sLKA_Off ((uint8_T)1U)
#define LKAS_subsystem_integ_IN_Enabled ((uint8_T)1U)
#define LKAS_subsystem_integ_IN_Standby ((uint8_T)6U)
#define LKAS_subsystem_integ_IN_sLKA_On ((uint8_T)2U)

/* Forward declaration for local functions */
static void LKAS_subsystem_integrat_Enabled(const EnumLKAS_IntvSide *Switch_l0uq,
  const EnumLKAS_CtrlRefTypVcc *Switch1_jd4m);

/* Function for Chart: '<S10>/sLKA' */
static void LKAS_subsystem_integrat_Enabled(const EnumLKAS_IntvSide *Switch_l0uq,
  const EnumLKAS_CtrlRefTypVcc *Switch1_jd4m)
{
  if (!LKAS_subsystem_integrate_ConstB.Enabled_sLKA)
  {
    if (((uint32_T)LKAS_subsystem_integrated_DW.is_Enabled) ==
        LKAS_subsystem__IN_Intervention)
    {
      VeLKAS_IntvTyp_sLKA = LKAS_NoIntvTyp;
      VeLKAS_IntvSide_sLKA = LKAS_NoIntvSide;
      VeLKAS_CtrlRef_sLKA = LKAS_NoRef;
      LKAS_subsystem_integrated_DW.is_Enabled = LKAS_su_IN_NO_ACTIVE_CHILD_kz5b;
    }
    else
    {
      LKAS_subsystem_integrated_DW.is_Enabled = LKAS_su_IN_NO_ACTIVE_CHILD_kz5b;
    }

    LKAS_subsystem_integrated_DW.is_sLKA_On = LKAS_subsystem_inte_IN_Enabling;
    VeLKAS_OnStateSt_sLKA = LKAS_Enabling;
  }
  else
  {
    switch (LKAS_subsystem_integrated_DW.is_Enabled)
    {
     case LKAS_subsystem__IN_Intervention:
      VeLKAS_IntvMgrSt_sLKA = LKAS_Intv;
      VeLKAS_OnStateSt_sLKA = LKAS_Active;
      if (LKAS_subsystem_integrated_B.Switch_j4bm)
      {
        VeLKAS_IntvTyp_sLKA = LKAS_NoIntvTyp;
        VeLKAS_IntvSide_sLKA = LKAS_NoIntvSide;
        VeLKAS_CtrlRef_sLKA = LKAS_NoRef;
        LKAS_subsystem_integrated_DW.is_Enabled =
          LKAS_su_IN_Intervention_Aborted;
        VeLKAS_IntvMgrSt_sLKA = LKAS_abort;
        VeLKAS_OnStateSt_sLKA = LKAS_aborted;
      }
      else
      {
        if (LKAS_subsystem_integrated_B.IsIntvCompleted_sLKA)
        {
          VeLKAS_IntvTyp_sLKA = LKAS_NoIntvTyp;
          VeLKAS_IntvSide_sLKA = LKAS_NoIntvSide;
          VeLKAS_CtrlRef_sLKA = LKAS_NoRef;
          LKAS_subsystem_integrated_DW.is_Enabled =
            LKAS__IN_Intervention_Completed;
          VeLKAS_IntvMgrSt_sLKA = LKAS_Completed;
          VeLKAS_OnStateSt_sLKA = LKAS_completed;
        }
      }
      break;

     case LKAS_su_IN_Intervention_Aborted:
      LKAS_subsystem_integrated_DW.is_Enabled = LKAS_subsystem_integ_IN_Standby;
      VeLKAS_IntvTyp_sLKA = LKAS_NoIntvTyp;
      VeLKAS_IntvSide_sLKA = LKAS_NoIntvSide;
      VeLKAS_CtrlRef_sLKA = LKAS_NoRef;
      VeLKAS_IntvMgrSt_sLKA = LKAS_NoIntv;
      VeLKAS_OnStateSt_sLKA = LKAS_Standby;
      break;

     case LKAS__IN_Intervention_Completed:
      LKAS_subsystem_integrated_DW.is_Enabled = LKAS_subsystem_integ_IN_Standby;
      VeLKAS_IntvTyp_sLKA = LKAS_NoIntvTyp;
      VeLKAS_IntvSide_sLKA = LKAS_NoIntvSide;
      VeLKAS_CtrlRef_sLKA = LKAS_NoRef;
      VeLKAS_IntvMgrSt_sLKA = LKAS_NoIntv;
      VeLKAS_OnStateSt_sLKA = LKAS_Standby;
      break;

     case IN_Left_Intervention_Suppressed:
      VeLKAS_OnStateSt_sLKA = LKAS_Suppressed;
      if ((((uint32_T)(*Switch_l0uq)) == LKAS_IntvSideRi) &&
          (LKAS_subsystem_integrated_B.Switch1_bgwd))
      {
        LKAS_subsystem_integrated_DW.is_Enabled =
          IN_Right_Intervention_Suppresse;
        VeLKAS_OnStateSt_sLKA = LKAS_Suppressed;
      }
      else
      {
        if ((!VbLKAS_IsActivated_sLKA) || (!LKAS_subsystem_integrated_B.Switch))
        {
          LKAS_subsystem_integrated_DW.is_Enabled =
            LKAS_subsystem_integ_IN_Standby;
          VeLKAS_IntvTyp_sLKA = LKAS_NoIntvTyp;
          VeLKAS_IntvSide_sLKA = LKAS_NoIntvSide;
          VeLKAS_CtrlRef_sLKA = LKAS_NoRef;
          VeLKAS_IntvMgrSt_sLKA = LKAS_NoIntv;
          VeLKAS_OnStateSt_sLKA = LKAS_Standby;
        }
      }
      break;

     case IN_Right_Intervention_Suppresse:
      VeLKAS_OnStateSt_sLKA = LKAS_Suppressed;
      if ((((uint32_T)(*Switch_l0uq)) == LKAS_IntvSideLe) &&
          (LKAS_subsystem_integrated_B.Switch))
      {
        LKAS_subsystem_integrated_DW.is_Enabled =
          IN_Left_Intervention_Suppressed;
        VeLKAS_OnStateSt_sLKA = LKAS_Suppressed;
      }
      else
      {
        if ((!VbLKAS_IsActivated_sLKA) ||
            (!LKAS_subsystem_integrated_B.Switch1_bgwd))
        {
          LKAS_subsystem_integrated_DW.is_Enabled =
            LKAS_subsystem_integ_IN_Standby;
          VeLKAS_IntvTyp_sLKA = LKAS_NoIntvTyp;
          VeLKAS_IntvSide_sLKA = LKAS_NoIntvSide;
          VeLKAS_CtrlRef_sLKA = LKAS_NoRef;
          VeLKAS_IntvMgrSt_sLKA = LKAS_NoIntv;
          VeLKAS_OnStateSt_sLKA = LKAS_Standby;
        }
      }
      break;

     default:
      VeLKAS_IntvMgrSt_sLKA = LKAS_NoIntv;
      VeLKAS_OnStateSt_sLKA = LKAS_Standby;
      if (VbLKAS_IsActivated_sLKA && (((!LKAS_subsystem_integrated_B.Switch) &&
            (((uint32_T)(*Switch_l0uq)) == LKAS_IntvSideLe)) ||
           ((!LKAS_subsystem_integrated_B.Switch1_bgwd) && (((uint32_T)
              (*Switch_l0uq)) == LKAS_IntvSideRi))))
      {
        LKAS_subsystem_integrated_DW.is_Enabled =
          LKAS_subsystem__IN_Intervention;
        VeLKAS_IntvTyp_sLKA = LKAS_SftyLaneKeepAid;
        VeLKAS_IntvSide_sLKA = *Switch_l0uq;
        VeLKAS_CtrlRef_sLKA = *Switch1_jd4m;
        VeLKAS_IntvMgrSt_sLKA = LKAS_Intv;
        VeLKAS_OnStateSt_sLKA = LKAS_Active;
      }
      else if (((LKAS_subsystem_integrated_B.Switch) && VbLKAS_IsActivated_sLKA)
               && (((uint32_T)(*Switch_l0uq)) == LKAS_IntvSideLe))
      {
        LKAS_subsystem_integrated_DW.is_Enabled =
          IN_Left_Intervention_Suppressed;
        VeLKAS_OnStateSt_sLKA = LKAS_Suppressed;
      }
      else
      {
        if (((LKAS_subsystem_integrated_B.Switch1_bgwd) &&
             VbLKAS_IsActivated_sLKA) && (((uint32_T)(*Switch_l0uq)) ==
             LKAS_IntvSideRi))
        {
          LKAS_subsystem_integrated_DW.is_Enabled =
            IN_Right_Intervention_Suppresse;
          VeLKAS_OnStateSt_sLKA = LKAS_Suppressed;
        }
      }
      break;
    }
  }
}

/* System initialize for atomic system: '<S4>/InterventionManager' */
void LKAS_s_InterventionManager_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S107>/Unit Delay' */
  LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_fbew = LKAS_NoIntvTyp;

  /* SystemInitialize for Chart: '<S10>/sLKA' */
  LKAS_subsystem_integrated_DW.is_sLKA_On = LKAS_su_IN_NO_ACTIVE_CHILD_kz5b;
  LKAS_subsystem_integrated_DW.is_Enabled = LKAS_su_IN_NO_ACTIVE_CHILD_kz5b;
  LKAS_subsystem_integrated_DW.is_active_c43_LKAS_subsystem_in = 0U;
  LKAS_subsystem_integrated_DW.is_c43_LKAS_subsystem_integrate =
    LKAS_su_IN_NO_ACTIVE_CHILD_kz5b;
}

/* Output and update for atomic system: '<S4>/InterventionManager' */
void LKAS_subsys_InterventionManager(void)
{
  boolean_T rtb_Compare;
  EnumLKAS_IntvSide Switch_l0uq;
  EnumLKAS_CtrlRefTypVcc Switch1_jd4m;

  /* RelationalOperator: '<S106>/Compare' incorporates:
   *  Constant: '<S106>/Constant'
   */
  rtb_Compare = (LKAS_subsystem_integrated_B.IntvTyp_sLKA_pzex ==
                 LKAS_SftyLaneKeepAid);

  /* Switch: '<S103>/Switch' */
  if (rtb_Compare)
  {
    Switch_l0uq = LKAS_subsystem_integrated_B.IntvSide_sLKA_k4lx;
  }
  else
  {
    Switch_l0uq =
      LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.IntvSideReq_sLKA;
  }

  /* End of Switch: '<S103>/Switch' */

  /* Switch: '<S103>/Switch1' */
  if (rtb_Compare)
  {
    Switch1_jd4m = LKAS_subsystem_integrated_B.CtrlRef_sLKA;
  }
  else
  {
    Switch1_jd4m =
      LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3.CtrlRefReq_sLKA;
  }

  /* End of Switch: '<S103>/Switch1' */

  /* Chart: '<S10>/sLKA' incorporates:
   *  Inport: '<Root>/DCSN_DataBus'
   */
  if (((uint32_T)LKAS_subsystem_integrated_DW.is_active_c43_LKAS_subsystem_in) ==
      0U)
  {
    LKAS_subsystem_integrated_DW.is_active_c43_LKAS_subsystem_in = 1U;
    LKAS_subsystem_integrated_DW.is_c43_LKAS_subsystem_integrate =
      LKAS_subsystem_inte_IN_sLKA_Off;
    VeLKAS_IntvTyp_sLKA = LKAS_NoIntvTyp;
    VeLKAS_IntvSide_sLKA = LKAS_NoIntvSide;
    VeLKAS_CtrlRef_sLKA = LKAS_NoRef;
    VeLKAS_IntvMgrSt_sLKA = LKAS_NoIntv;
    VeLKAS_SystemSt_sLKA = LKAS_Off;
  }
  else if (((uint32_T)
            LKAS_subsystem_integrated_DW.is_c43_LKAS_subsystem_integrate) ==
           LKAS_subsystem_inte_IN_sLKA_Off)
  {
    VeLKAS_IntvMgrSt_sLKA = LKAS_NoIntv;
    VeLKAS_SystemSt_sLKA = LKAS_Off;
    if (VsDCSN_DataBus.EnablingFlags_Group.lka_feature_enable)
    {
      LKAS_subsystem_integrated_DW.is_c43_LKAS_subsystem_integrate =
        LKAS_subsystem_integ_IN_sLKA_On;
      VeLKAS_SystemSt_sLKA = LKAS_On;
      LKAS_subsystem_integrated_DW.is_sLKA_On = LKAS_subsystem_inte_IN_Enabling;
      VeLKAS_OnStateSt_sLKA = LKAS_Enabling;
    }
  }
  else
  {
    VeLKAS_SystemSt_sLKA = LKAS_On;
    if (!VsDCSN_DataBus.EnablingFlags_Group.lka_feature_enable)
    {
      if (((uint32_T)LKAS_subsystem_integrated_DW.is_sLKA_On) ==
          LKAS_subsystem_integ_IN_Enabled)
      {
        if (((uint32_T)LKAS_subsystem_integrated_DW.is_Enabled) ==
            LKAS_subsystem__IN_Intervention)
        {
          VeLKAS_IntvTyp_sLKA = LKAS_NoIntvTyp;
          VeLKAS_IntvSide_sLKA = LKAS_NoIntvSide;
          VeLKAS_CtrlRef_sLKA = LKAS_NoRef;
          LKAS_subsystem_integrated_DW.is_Enabled =
            LKAS_su_IN_NO_ACTIVE_CHILD_kz5b;
        }
        else
        {
          LKAS_subsystem_integrated_DW.is_Enabled =
            LKAS_su_IN_NO_ACTIVE_CHILD_kz5b;
        }

        LKAS_subsystem_integrated_DW.is_sLKA_On =
          LKAS_su_IN_NO_ACTIVE_CHILD_kz5b;
      }
      else
      {
        LKAS_subsystem_integrated_DW.is_sLKA_On =
          LKAS_su_IN_NO_ACTIVE_CHILD_kz5b;
      }

      LKAS_subsystem_integrated_DW.is_c43_LKAS_subsystem_integrate =
        LKAS_subsystem_inte_IN_sLKA_Off;
      VeLKAS_IntvTyp_sLKA = LKAS_NoIntvTyp;
      VeLKAS_IntvSide_sLKA = LKAS_NoIntvSide;
      VeLKAS_CtrlRef_sLKA = LKAS_NoRef;
      VeLKAS_IntvMgrSt_sLKA = LKAS_NoIntv;
      VeLKAS_SystemSt_sLKA = LKAS_Off;
    }
    else if (((uint32_T)LKAS_subsystem_integrated_DW.is_sLKA_On) ==
             LKAS_subsystem_integ_IN_Enabled)
    {
      LKAS_subsystem_integrat_Enabled(&Switch_l0uq, &Switch1_jd4m);
    }
    else
    {
      VeLKAS_OnStateSt_sLKA = LKAS_Enabling;
      if (LKAS_subsystem_integrate_ConstB.Enabled_sLKA)
      {
        LKAS_subsystem_integrated_DW.is_sLKA_On =
          LKAS_subsystem_integ_IN_Enabled;
        LKAS_subsystem_integrated_DW.is_Enabled =
          LKAS_subsystem_integ_IN_Standby;
        VeLKAS_IntvTyp_sLKA = LKAS_NoIntvTyp;
        VeLKAS_IntvSide_sLKA = LKAS_NoIntvSide;
        VeLKAS_CtrlRef_sLKA = LKAS_NoRef;
        VeLKAS_IntvMgrSt_sLKA = LKAS_NoIntv;
        VeLKAS_OnStateSt_sLKA = LKAS_Standby;
      }
    }
  }

  /* End of Chart: '<S10>/sLKA' */

  /* SignalConversion: '<S10>/Signal Conversion' */
  LKAS_subsystem_integrated_B.IntvTyp_sLKA = VeLKAS_IntvTyp_sLKA;

  /* Switch: '<S109>/Switch' incorporates:
   *  Constant: '<S107>/Constant'
   *  Constant: '<S108>/Constant'
   *  Constant: '<S109>/Constant'
   *  Logic: '<S107>/Logical Operator'
   *  RelationalOperator: '<S107>/Relational Operator'
   *  RelationalOperator: '<S107>/Relational Operator1'
   *  Sum: '<S109>/Add'
   *  UnitDelay: '<S107>/Unit Delay'
   *  UnitDelay: '<S109>/Unit Delay'
   */
  if ((LKAS_subsystem_integrated_B.IntvTyp_sLKA !=
       LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_fbew) ||
      (LKAS_subsystem_integrated_B.IntvTyp_sLKA == LKAS_NoIntvTyp))
  {
    VfLKAS_T_AftIntvStart = 0.0F;
  }
  else
  {
    VfLKAS_T_AftIntvStart += 0.01F;
  }

  /* End of Switch: '<S109>/Switch' */

  /* SignalConversion: '<S107>/Signal Conversion' */
  LKAS_subsystem_integrated_B.T_AftIntvStart_gady = VfLKAS_T_AftIntvStart;

  /* SignalConversion: '<S10>/Signal Conversion1' */
  LKAS_subsystem_integrated_B.IntvSide_sLKA = VeLKAS_IntvSide_sLKA;

  /* SignalConversion: '<S10>/Signal Conversion2' */
  LKAS_subsystem_integrated_B.CtrlRef_sLKA_jpit = VeLKAS_CtrlRef_sLKA;

  /* SignalConversion: '<S10>/Signal Conversion3' */
  LKAS_subsystem_integrated_B.IntvMgrSt_sLKA = VeLKAS_IntvMgrSt_sLKA;

  /* Update for UnitDelay: '<S107>/Unit Delay' */
  LKAS_subsystem_integrated_DW.UnitDelay_DSTATE_fbew =
    LKAS_subsystem_integrated_B.IntvTyp_sLKA;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
