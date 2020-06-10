/*
 * File: WarningManager_LDW.c
 *
 * Code generated for Simulink model 'LDWS_subsystem_integrated'.
 *
 * Model version                  : 1.384
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 11:19:43 2020
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

#include "WarningManager_LDW.h"

/* Include model header file for global data */
#include "LDWS_subsystem_integrated.h"
#include "LDWS_subsystem_integrated_private.h"

/* Named constants for Chart: '<S9>/Warning_Machine' */
#define LDWS_subsyst_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define LDWS_subsyste_IN_suppress_right ((uint8_T)3U)
#define LDWS_subsystem_IN_suppress_left ((uint8_T)2U)
#define LDWS_subsystem_in_IN_warn_right ((uint8_T)5U)
#define LDWS_subsystem_int_IN_warn_left ((uint8_T)4U)
#define LDWS_subsystem_inte_IN_Enabling ((uint8_T)2U)
#define LDWS_subsystem_integ_IN_Enabled ((uint8_T)1U)
#define LDWS_subsystem_integ_IN_Standby ((uint8_T)1U)
#define LDWS_subsystem_integrate_IN_Off ((uint8_T)1U)
#define LDWS_subsystem_integrated_IN_On ((uint8_T)2U)

/* System initialize for atomic system: '<S1>/WarningManager_LDW' */
void LDWS_su_WarningManager_LDW_Init(void)
{
  /* SystemInitialize for Chart: '<S9>/Warning_Machine' */
  LDWS_subsystem_integrated_DW.is_On = LDWS_subsyst_IN_NO_ACTIVE_CHILD;
  LDWS_subsystem_integrated_DW.is_Enabled = LDWS_subsyst_IN_NO_ACTIVE_CHILD;
  LDWS_subsystem_integrated_DW.is_active_c16_LDWS_subsystem_in = 0U;
  LDWS_subsystem_integrated_DW.is_c16_LDWS_subsystem_integrate =
    LDWS_subsyst_IN_NO_ACTIVE_CHILD;
  LDWS_subsystem_integrated_DW.CntWarn = 0U;
  LDWS_subsystem_integrated_DW.CntOnTimer = 0U;
  LDWS_subsystem_integrated_B.Warn_Manager_Status = Avl;
  VeLDWS_SysSt = LDWS_Off;
  VeLDWS_OnStateSt = LDWS_Enabling;
}

/* Output and update for atomic system: '<S1>/WarningManager_LDW' */
void LDWS_subsyst_WarningManager_LDW(void)
{
  boolean_T rtb_Switch_b1rf;
  int32_T tmp;
  uint32_T qY;

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Constant4'
   *  Constant: '<S9>/Constant5'
   */
  if (KbLDWS_EnableSwitch)
  {
    rtb_Switch_b1rf = true;
  }
  else
  {
    rtb_Switch_b1rf = VbLDWS_EnabledLDW;
  }

  /* End of Switch: '<S9>/Switch' */

  /* Chart: '<S9>/Warning_Machine' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   *  Constant: '<S9>/Constant2'
   *  Constant: '<S9>/Constant3'
   *  Inport: '<Root>/DCSN_DataBus'
   */
  if (((uint32_T)LDWS_subsystem_integrated_DW.is_active_c16_LDWS_subsystem_in) ==
      0U)
  {
    LDWS_subsystem_integrated_DW.is_active_c16_LDWS_subsystem_in = 1U;
    LDWS_subsystem_integrated_DW.is_c16_LDWS_subsystem_integrate =
      LDWS_subsystem_integrate_IN_Off;
    LDWS_subsystem_integrated_B.Warn_Manager_Status = NotAvl;
    VeLDWS_SysSt = LDWS_Off;
  }
  else if (((uint32_T)
            LDWS_subsystem_integrated_DW.is_c16_LDWS_subsystem_integrate) ==
           LDWS_subsystem_integrate_IN_Off)
  {
    LDWS_subsystem_integrated_B.Warn_Manager_Status = NotAvl;
    VeLDWS_SysSt = LDWS_Off;
    if (VsDCSN_DataBus.EnablingFlags_Group.ldw_feature_enable)
    {
      LDWS_subsystem_integrated_DW.is_c16_LDWS_subsystem_integrate =
        LDWS_subsystem_integrated_IN_On;
      VeLDWS_SysSt = LDWS_On;
      LDWS_subsystem_integrated_DW.is_On = LDWS_subsystem_inte_IN_Enabling;
      VeLDWS_OnStateSt = LDWS_Enabling;
    }
  }
  else
  {
    VeLDWS_SysSt = LDWS_On;
    if (!VsDCSN_DataBus.EnablingFlags_Group.ldw_feature_enable)
    {
      LDWS_subsystem_integrated_DW.is_Enabled = LDWS_subsyst_IN_NO_ACTIVE_CHILD;
      LDWS_subsystem_integrated_DW.is_On = LDWS_subsyst_IN_NO_ACTIVE_CHILD;
      LDWS_subsystem_integrated_DW.is_c16_LDWS_subsystem_integrate =
        LDWS_subsystem_integrate_IN_Off;
      LDWS_subsystem_integrated_B.Warn_Manager_Status = NotAvl;
      VeLDWS_SysSt = LDWS_Off;
    }
    else if (((uint32_T)LDWS_subsystem_integrated_DW.is_On) ==
             LDWS_subsystem_integ_IN_Enabled)
    {
      if (!rtb_Switch_b1rf)
      {
        LDWS_subsystem_integrated_DW.is_Enabled =
          LDWS_subsyst_IN_NO_ACTIVE_CHILD;
        LDWS_subsystem_integrated_DW.is_On = LDWS_subsystem_inte_IN_Enabling;
        VeLDWS_OnStateSt = LDWS_Enabling;
      }
      else
      {
        switch (LDWS_subsystem_integrated_DW.is_Enabled)
        {
         case LDWS_subsystem_integ_IN_Standby:
          LDWS_subsystem_integrated_B.Warn_Manager_Status = Avl;
          VeLDWS_OnStateSt = LDWS_Standby;
          if (LDWS_subsystem_integrated_B.Switch)
          {
            LDWS_subsystem_integrated_DW.is_Enabled =
              LDWS_subsystem_IN_suppress_left;
            LDWS_subsystem_integrated_B.Warn_Manager_Status = SuppLe;
            VeLDWS_OnStateSt = LDWS_Passive;
          }
          else if (LDWS_subsystem_integrated_B.Switch1)
          {
            LDWS_subsystem_integrated_DW.is_Enabled =
              LDWS_subsyste_IN_suppress_right;
            LDWS_subsystem_integrated_B.Warn_Manager_Status = SuppRi;
            VeLDWS_OnStateSt = LDWS_Passive;
          }
          else if (VbLDWS_ActRiLDW && (LDWS_subsystem_integrated_DW.CntOnTimer >
                    ((uint32_T)KfLDWS_t_CntOnHold)))
          {
            LDWS_subsystem_integrated_DW.is_Enabled =
              LDWS_subsystem_in_IN_warn_right;
            LDWS_subsystem_integrated_DW.CntWarn = 0U;
            LDWS_subsystem_integrated_B.Warn_Manager_Status = WarnRi;
            VeLDWS_OnStateSt = LDWS_Active;
          }
          else if (VbLDWS_ActLeLDW && (LDWS_subsystem_integrated_DW.CntOnTimer >
                    ((uint32_T)KfLDWS_t_CntOnHold)))
          {
            LDWS_subsystem_integrated_DW.is_Enabled =
              LDWS_subsystem_int_IN_warn_left;
            LDWS_subsystem_integrated_DW.CntWarn = 0U;
            LDWS_subsystem_integrated_B.Warn_Manager_Status = WarnLe;
            VeLDWS_OnStateSt = LDWS_Active;
          }
          else
          {
            qY = LDWS_subsystem_integrated_DW.CntOnTimer + /*MW:OvSatOk*/
              ((uint32_T)KcLDWS_CntSample);
            if (qY < LDWS_subsystem_integrated_DW.CntOnTimer)
            {
              qY = MAX_uint32_T;
            }

            LDWS_subsystem_integrated_DW.CntOnTimer = qY;
          }
          break;

         case LDWS_subsystem_IN_suppress_left:
          LDWS_subsystem_integrated_B.Warn_Manager_Status = SuppLe;
          VeLDWS_OnStateSt = LDWS_Passive;
          if (!LDWS_subsystem_integrated_B.Switch)
          {
            LDWS_subsystem_integrated_DW.is_Enabled =
              LDWS_subsystem_integ_IN_Standby;
            LDWS_subsystem_integrated_DW.CntOnTimer = 0U;
            LDWS_subsystem_integrated_B.Warn_Manager_Status = Avl;
            VeLDWS_OnStateSt = LDWS_Standby;
          }
          else
          {
            if (LDWS_subsystem_integrated_B.Switch1)
            {
              LDWS_subsystem_integrated_DW.is_Enabled =
                LDWS_subsyste_IN_suppress_right;
              LDWS_subsystem_integrated_B.Warn_Manager_Status = SuppRi;
              VeLDWS_OnStateSt = LDWS_Passive;
            }
          }
          break;

         case LDWS_subsyste_IN_suppress_right:
          LDWS_subsystem_integrated_B.Warn_Manager_Status = SuppRi;
          VeLDWS_OnStateSt = LDWS_Passive;
          if (!LDWS_subsystem_integrated_B.Switch1)
          {
            LDWS_subsystem_integrated_DW.is_Enabled =
              LDWS_subsystem_integ_IN_Standby;
            LDWS_subsystem_integrated_DW.CntOnTimer = 0U;
            LDWS_subsystem_integrated_B.Warn_Manager_Status = Avl;
            VeLDWS_OnStateSt = LDWS_Standby;
          }
          else
          {
            if (LDWS_subsystem_integrated_B.Switch)
            {
              LDWS_subsystem_integrated_DW.is_Enabled =
                LDWS_subsystem_IN_suppress_left;
              LDWS_subsystem_integrated_B.Warn_Manager_Status = SuppLe;
              VeLDWS_OnStateSt = LDWS_Passive;
            }
          }
          break;

         case LDWS_subsystem_int_IN_warn_left:
          LDWS_subsystem_integrated_B.Warn_Manager_Status = WarnLe;
          VeLDWS_OnStateSt = LDWS_Active;
          if ((LDWS_subsystem_integrated_B.Switch) &&
              (LDWS_subsystem_integrated_DW.CntWarn > KfLDWS_t_CntMinWarnHold))
          {
            LDWS_subsystem_integrated_DW.is_Enabled =
              LDWS_subsystem_IN_suppress_left;
            LDWS_subsystem_integrated_B.Warn_Manager_Status = SuppLe;
            VeLDWS_OnStateSt = LDWS_Passive;
          }
          else if (((!VbLDWS_ActLeLDW) && (LDWS_subsystem_integrated_DW.CntWarn >
                     KfLDWS_t_CntMinWarnHold)) ||
                   (LDWS_subsystem_integrated_DW.CntWarn >
                    KfLDWS_t_CntMaxWarnHold))
          {
            LDWS_subsystem_integrated_DW.is_Enabled =
              LDWS_subsystem_integ_IN_Standby;
            LDWS_subsystem_integrated_DW.CntOnTimer = 0U;
            LDWS_subsystem_integrated_B.Warn_Manager_Status = Avl;
            VeLDWS_OnStateSt = LDWS_Standby;
          }
          else
          {
            tmp = ((int32_T)LDWS_subsystem_integrated_DW.CntWarn) + ((int32_T)
              KcLDWS_CntSample);
            if (tmp > 65535)
            {
              tmp = 65535;
            }

            LDWS_subsystem_integrated_DW.CntWarn = (uint16_T)tmp;
          }
          break;

         default:
          LDWS_subsystem_integrated_B.Warn_Manager_Status = WarnRi;
          VeLDWS_OnStateSt = LDWS_Active;
          if ((LDWS_subsystem_integrated_B.Switch1) &&
              (LDWS_subsystem_integrated_DW.CntWarn > KfLDWS_t_CntMinWarnHold))
          {
            LDWS_subsystem_integrated_DW.is_Enabled =
              LDWS_subsyste_IN_suppress_right;
            LDWS_subsystem_integrated_B.Warn_Manager_Status = SuppRi;
            VeLDWS_OnStateSt = LDWS_Passive;
          }
          else if (((!VbLDWS_ActRiLDW) && (LDWS_subsystem_integrated_DW.CntWarn >
                     KfLDWS_t_CntMinWarnHold)) ||
                   (LDWS_subsystem_integrated_DW.CntWarn >
                    KfLDWS_t_CntMaxWarnHold))
          {
            LDWS_subsystem_integrated_DW.is_Enabled =
              LDWS_subsystem_integ_IN_Standby;
            LDWS_subsystem_integrated_DW.CntOnTimer = 0U;
            LDWS_subsystem_integrated_B.Warn_Manager_Status = Avl;
            VeLDWS_OnStateSt = LDWS_Standby;
          }
          else
          {
            tmp = ((int32_T)LDWS_subsystem_integrated_DW.CntWarn) + ((int32_T)
              KcLDWS_CntSample);
            if (tmp > 65535)
            {
              tmp = 65535;
            }

            LDWS_subsystem_integrated_DW.CntWarn = (uint16_T)tmp;
          }
          break;
        }
      }
    }
    else
    {
      VeLDWS_OnStateSt = LDWS_Enabling;
      if (rtb_Switch_b1rf)
      {
        LDWS_subsystem_integrated_DW.is_On = LDWS_subsystem_integ_IN_Enabled;
        LDWS_subsystem_integrated_DW.is_Enabled =
          LDWS_subsystem_integ_IN_Standby;
        LDWS_subsystem_integrated_DW.CntOnTimer = 0U;
        LDWS_subsystem_integrated_B.Warn_Manager_Status = Avl;
        VeLDWS_OnStateSt = LDWS_Standby;
      }
    }
  }

  /* End of Chart: '<S9>/Warning_Machine' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
