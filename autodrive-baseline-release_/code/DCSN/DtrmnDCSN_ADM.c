/*
 * File: DtrmnDCSN_ADM.c
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

#include "DtrmnDCSN_ADM.h"

/* Include model header file for global data */
#include "DCSN_subsystem_integrated.h"
#include "DCSN_subsystem_integrated_private.h"

/* Named constants for Chart: '<S8>/DtrmnDCSN_ADMManager' */
#define DCSN_su_IN_ADM_TAKEOVER_WARNING ((uint8_T)3U)
#define DCSN_subs_IN_ADM_FAULT_DETECTED ((uint8_T)1U)
#define DCSN_subs_IN_ADM_FAULT_REACTION ((uint8_T)2U)
#define DCSN_subsy_IN_ADM_FAULT_WARNING ((uint8_T)3U)
#define DCSN_subsyst_IN_ADM_ON_INACTIVE ((uint8_T)2U)
#define DCSN_subsyst_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define DCSN_subsyste_IN_ADM_STEER_OVRD ((uint8_T)2U)
#define DCSN_subsystem_IN_ADM_ON_ACTIVE ((uint8_T)1U)
#define DCSN_subsystem_i_IN_ADM_STANDBY ((uint8_T)2U)
#define DCSN_subsystem_in_IN_ADM_ACTIVE ((uint8_T)1U)
#define DCSN_subsystem_int_IN_ADM_FAULT ((uint8_T)1U)
#define DCSN_subsystem_int_IN_ADM_READY ((uint8_T)1U)
#define DCSN_subsystem_integ_IN_ADM_OFF ((uint8_T)2U)
#define DCSN_subsystem_integr_IN_ADM_ON ((uint8_T)3U)

/* Named constants for Chart: '<S9>/DtrmnDCSN_DrivIntention' */
#define DCSN__IN_driv_steering_resuming ((uint8_T)4U)
#define DCSN_s_IN_driv_steering_standby ((uint8_T)5U)
#define DCSN_subs_IN_driv_steering_ovrd ((uint8_T)1U)
#define DCS_IN_driv_steering_ovrd_delay ((uint8_T)2U)
#define D_IN_driv_steering_resume_delay ((uint8_T)3U)

/* Forward declaration for local functions */
static void DCSN_s_enter_internal_ADM_FAULT(void);
static void DCSN_subsystem_integrate_ADM_ON(const real32_T *Gain);

/* Function for Chart: '<S8>/DtrmnDCSN_ADMManager' */
static void DCSN_s_enter_internal_ADM_FAULT(void)
{
  if (DCSN_subsystem_integrated_DW.autodrive_engaged)
  {
    DCSN_subsystem_integrated_DW.is_ADM_FAULT = DCSN_subsy_IN_ADM_FAULT_WARNING;
    DCSN_subsystem_integrated_DW.temporalCounter_i1 = 0U;
    DCSN_subsystem_integrated_B.adm_main_mode = ADM_FAULT_WARNING;
    VeDCSN_hmi_icon_display = RED_FLASH_SLOW;
    VeDCSN_hmi_msg_display = FAULT;
  }
  else
  {
    DCSN_subsystem_integrated_DW.is_ADM_FAULT = DCSN_subs_IN_ADM_FAULT_DETECTED;
    DCSN_subsystem_integrated_B.adm_main_mode = ADM_FAULT_DETECTED;
    VeDCSN_hmi_icon_display = RED_SOLID;
    VeDCSN_hmi_msg_display = FAULT;
    DCSN_subsystem_integrated_DW.autodrive_resume_allowed = true;
  }
}

/* Function for Chart: '<S8>/DtrmnDCSN_ADMManager' */
static void DCSN_subsystem_integrate_ADM_ON(const real32_T *Gain)
{
  uint32_T tmp;

  /* Constant: '<S8>/KfDCSN_adm_temp_usr_cmd_autodrive_enabled' incorporates:
   *  Inport: '<Root>/LCCS_DataBus'
   */
  if (!KbDCSN_adm_temp_usr_cmd_autodrive_enabled)
  {
    if (((uint32_T)DCSN_subsystem_integrated_DW.is_ADM_ON) ==
        DCSN_subsystem_IN_ADM_ON_ACTIVE)
    {
      if (((uint32_T)DCSN_subsystem_integrated_DW.is_ADM_ON_ACTIVE) ==
          DCSN_su_IN_ADM_TAKEOVER_WARNING)
      {
        DCSN_subsystem_integrated_DW.warning_time = 0U;
        DCSN_subsystem_integrated_DW.is_ADM_ON_ACTIVE =
          DCSN_subsyst_IN_NO_ACTIVE_CHILD;
      }
      else
      {
        DCSN_subsystem_integrated_DW.is_ADM_ON_ACTIVE =
          DCSN_subsyst_IN_NO_ACTIVE_CHILD;
      }

      DCSN_subsystem_integrated_DW.is_ADM_ON = DCSN_subsyst_IN_NO_ACTIVE_CHILD;
    }
    else
    {
      DCSN_subsystem_integrated_DW.is_ADM_ON_INACTIVE =
        DCSN_subsyst_IN_NO_ACTIVE_CHILD;
      DCSN_subsystem_integrated_DW.is_ADM_ON = DCSN_subsyst_IN_NO_ACTIVE_CHILD;
    }

    DCSN_subsystem_integrated_DW.is_c4_DCSN_subsystem_integrated =
      DCSN_subsystem_integ_IN_ADM_OFF;
    DCSN_subsystem_integrated_B.adm_main_mode = ADM_OFF;
    VeDCSN_hmi_icon_display = NO_ICON;
    VeDCSN_hmi_msg_display = NO_MSG;
    DCSN_subsystem_integrated_DW.autodrive_engaged = false;
  }
  else if (VbDCSN_fault_detected)
  {
    if (((uint32_T)DCSN_subsystem_integrated_DW.is_ADM_ON) ==
        DCSN_subsystem_IN_ADM_ON_ACTIVE)
    {
      if (((uint32_T)DCSN_subsystem_integrated_DW.is_ADM_ON_ACTIVE) ==
          DCSN_su_IN_ADM_TAKEOVER_WARNING)
      {
        DCSN_subsystem_integrated_DW.warning_time = 0U;
        DCSN_subsystem_integrated_DW.is_ADM_ON_ACTIVE =
          DCSN_subsyst_IN_NO_ACTIVE_CHILD;
      }
      else
      {
        DCSN_subsystem_integrated_DW.is_ADM_ON_ACTIVE =
          DCSN_subsyst_IN_NO_ACTIVE_CHILD;
      }

      DCSN_subsystem_integrated_DW.is_ADM_ON = DCSN_subsyst_IN_NO_ACTIVE_CHILD;
    }
    else
    {
      DCSN_subsystem_integrated_DW.is_ADM_ON_INACTIVE =
        DCSN_subsyst_IN_NO_ACTIVE_CHILD;
      DCSN_subsystem_integrated_DW.is_ADM_ON = DCSN_subsyst_IN_NO_ACTIVE_CHILD;
    }

    DCSN_subsystem_integrated_DW.is_c4_DCSN_subsystem_integrated =
      DCSN_subsystem_int_IN_ADM_FAULT;
    DCSN_subsystem_integrated_DW.autodrive_resume_allowed = false;
    DCSN_s_enter_internal_ADM_FAULT();
  }
  else if (((uint32_T)DCSN_subsystem_integrated_DW.is_ADM_ON) ==
           DCSN_subsystem_IN_ADM_ON_ACTIVE)
  {
    if ((((((int32_T)VeDCSN_usr_cmd_autodrive_activate) == 0) || (((real32_T)
            DCSN_subsystem_integrated_DW.warning_time) >= (*Gain))) ||
         VbDCSN_autodrive_exit) || (VbDCSN_adm_steering_override && (((int32_T)
           DCSN_subsystem_integrated_DW.warning_time) > 0)))
    {
      if (((uint32_T)DCSN_subsystem_integrated_DW.is_ADM_ON_ACTIVE) ==
          DCSN_su_IN_ADM_TAKEOVER_WARNING)
      {
        DCSN_subsystem_integrated_DW.warning_time = 0U;
        DCSN_subsystem_integrated_DW.is_ADM_ON_ACTIVE =
          DCSN_subsyst_IN_NO_ACTIVE_CHILD;
      }
      else
      {
        DCSN_subsystem_integrated_DW.is_ADM_ON_ACTIVE =
          DCSN_subsyst_IN_NO_ACTIVE_CHILD;
      }

      DCSN_subsystem_integrated_DW.is_ADM_ON = DCSN_subsyst_IN_ADM_ON_INACTIVE;
      DCSN_subsystem_integrated_DW.autodrive_engaged = false;
      DCSN_subsystem_integrated_DW.is_ADM_ON_INACTIVE =
        DCSN_subsystem_i_IN_ADM_STANDBY;
      DCSN_subsystem_integrated_B.adm_main_mode = ADM_STANDBY;
      VeDCSN_hmi_icon_display = NO_ICON;
      VeDCSN_hmi_msg_display = NO_MSG;
      DCSN_subsystem_integrated_DW.autodrive_ready_to_engage = false;
    }
    else
    {
      switch (DCSN_subsystem_integrated_DW.is_ADM_ON_ACTIVE)
      {
       case DCSN_subsystem_in_IN_ADM_ACTIVE:
        DCSN_subsystem_integrated_B.adm_main_mode = ADM_ACTIVE;
        VeDCSN_hmi_icon_display = GREEN_SOLID;
        VeDCSN_hmi_msg_display = ACTIVE;
        if (VbDCSN_adm_steering_override)
        {
          DCSN_subsystem_integrated_DW.is_ADM_ON_ACTIVE =
            DCSN_subsyste_IN_ADM_STEER_OVRD;
          DCSN_subsystem_integrated_B.adm_main_mode = ADM_STEER_OVRD;
          VeDCSN_hmi_icon_display = BLUE_SOLID;
          VeDCSN_hmi_msg_display = OVRD;
        }
        else
        {
          if (VbDCSN_autodrive_warning)
          {
            DCSN_subsystem_integrated_DW.is_ADM_ON_ACTIVE =
              DCSN_su_IN_ADM_TAKEOVER_WARNING;
            DCSN_subsystem_integrated_DW.temporalCounter_i1 = 0U;
            DCSN_subsystem_integrated_B.adm_main_mode = ADM_TAKEOVER_WARNING;
            VeDCSN_hmi_icon_display = RED_FLASH_SLOW;
            VeDCSN_hmi_msg_display = TAKEOVER_REQ;
            DCSN_subsystem_integrated_DW.warning_time = 0U;
          }
        }
        break;

       case DCSN_subsyste_IN_ADM_STEER_OVRD:
        DCSN_subsystem_integrated_B.adm_main_mode = ADM_STEER_OVRD;
        VeDCSN_hmi_icon_display = BLUE_SOLID;
        VeDCSN_hmi_msg_display = OVRD;

        /* Constant: '<S8>/KbDCSN_lcc_usr_switch' */
        if (VbDCSN_adm_steering_resume && KbDCSN_lcc_usr_switch)
        {
          DCSN_subsystem_integrated_DW.is_ADM_ON_ACTIVE =
            DCSN_subsystem_in_IN_ADM_ACTIVE;
          DCSN_subsystem_integrated_B.adm_main_mode = ADM_ACTIVE;
          VeDCSN_hmi_icon_display = GREEN_SOLID;
          VeDCSN_hmi_msg_display = ACTIVE;
        }
        break;

       default:
        DCSN_subsystem_integrated_B.adm_main_mode = ADM_TAKEOVER_WARNING;
        VeDCSN_hmi_icon_display = RED_FLASH_SLOW;
        VeDCSN_hmi_msg_display = TAKEOVER_REQ;
        if ((!VbDCSN_autodrive_warning) && VbDCSN_autodrive_ready_to_engage)
        {
          DCSN_subsystem_integrated_DW.warning_time = 0U;
          DCSN_subsystem_integrated_DW.is_ADM_ON_ACTIVE =
            DCSN_subsystem_in_IN_ADM_ACTIVE;
          DCSN_subsystem_integrated_B.adm_main_mode = ADM_ACTIVE;
          VeDCSN_hmi_icon_display = GREEN_SOLID;
          VeDCSN_hmi_msg_display = ACTIVE;
        }
        else if ((DCSN_subsystem_integrated_DW.temporalCounter_i1 >= ((uint32_T)
                   ((real32_T)((*Gain) + 1.0F)))) ||
                 (VbDCSN_adm_steering_override &&
                  (VsLCCS_DataBus.LCC_ForceToDisengage)))
        {
          DCSN_subsystem_integrated_DW.warning_time = 0U;
          DCSN_subsystem_integrated_DW.is_ADM_ON_ACTIVE =
            DCSN_subsyste_IN_ADM_STEER_OVRD;
          DCSN_subsystem_integrated_B.adm_main_mode = ADM_STEER_OVRD;
          VeDCSN_hmi_icon_display = BLUE_SOLID;
          VeDCSN_hmi_msg_display = OVRD;
        }
        else
        {
          if (VbDCSN_autodrive_warning && (!VsLCCS_DataBus.LCC_ForceToDisengage))
          {
            tmp = ((uint32_T)DCSN_subsystem_integrated_DW.warning_time) +
              ((uint32_T)DCSN_subsystem_integrated_DW.time_count_agzm);
            if (tmp > 65535U)
            {
              tmp = 65535U;
            }

            DCSN_subsystem_integrated_DW.warning_time = (uint16_T)tmp;
          }
        }
        break;
      }
    }
  }
  else if (((((int32_T)VeDCSN_usr_cmd_autodrive_activate) == 1) &&
            (DCSN_subsystem_integrated_DW.autodrive_ready_to_engage)) ||
           VbDCSN_cond_activate_met)
  {
    DCSN_subsystem_integrated_DW.is_ADM_ON_INACTIVE =
      DCSN_subsyst_IN_NO_ACTIVE_CHILD;
    DCSN_subsystem_integrated_DW.is_ADM_ON = DCSN_subsystem_IN_ADM_ON_ACTIVE;
    DCSN_subsystem_integrated_DW.autodrive_engaged = true;

    /* Inport: '<Root>/LCCS_DataBus' incorporates:
     *  Constant: '<S8>/KbDCSN_lcc_usr_switch'
     */
    if (((VsLCCS_DataBus.LCC_ReadyToEngage) &&
         (!VsLCCS_DataBus.LCC_ForceToDisengage)) && KbDCSN_lcc_usr_switch)
    {
      DCSN_subsystem_integrated_DW.is_ADM_ON_ACTIVE =
        DCSN_subsystem_in_IN_ADM_ACTIVE;
      DCSN_subsystem_integrated_B.adm_main_mode = ADM_ACTIVE;
      VeDCSN_hmi_icon_display = GREEN_SOLID;
      VeDCSN_hmi_msg_display = ACTIVE;
    }
    else
    {
      DCSN_subsystem_integrated_DW.is_ADM_ON_ACTIVE =
        DCSN_subsyste_IN_ADM_STEER_OVRD;
      DCSN_subsystem_integrated_B.adm_main_mode = ADM_STEER_OVRD;
      VeDCSN_hmi_icon_display = BLUE_SOLID;
      VeDCSN_hmi_msg_display = OVRD;
    }
  }
  else if (((uint32_T)DCSN_subsystem_integrated_DW.is_ADM_ON_INACTIVE) ==
           DCSN_subsystem_int_IN_ADM_READY)
  {
    DCSN_subsystem_integrated_B.adm_main_mode = ADM_READY;
    VeDCSN_hmi_icon_display = GREY_SOLID;
    VeDCSN_hmi_msg_display = NO_MSG;
    if (!VbDCSN_autodrive_ready_to_engage)
    {
      DCSN_subsystem_integrated_DW.is_ADM_ON_INACTIVE =
        DCSN_subsystem_i_IN_ADM_STANDBY;
      DCSN_subsystem_integrated_B.adm_main_mode = ADM_STANDBY;
      VeDCSN_hmi_icon_display = NO_ICON;
      VeDCSN_hmi_msg_display = NO_MSG;
      DCSN_subsystem_integrated_DW.autodrive_ready_to_engage = false;
    }
  }
  else
  {
    DCSN_subsystem_integrated_B.adm_main_mode = ADM_STANDBY;
    VeDCSN_hmi_icon_display = NO_ICON;
    VeDCSN_hmi_msg_display = NO_MSG;
    if (VbDCSN_autodrive_ready_to_engage)
    {
      DCSN_subsystem_integrated_DW.is_ADM_ON_INACTIVE =
        DCSN_subsystem_int_IN_ADM_READY;
      DCSN_subsystem_integrated_B.adm_main_mode = ADM_READY;
      VeDCSN_hmi_icon_display = GREY_SOLID;
      VeDCSN_hmi_msg_display = NO_MSG;
      DCSN_subsystem_integrated_DW.autodrive_ready_to_engage = true;
    }
  }

  /* End of Constant: '<S8>/KfDCSN_adm_temp_usr_cmd_autodrive_enabled' */
}

/* System initialize for atomic system: '<S1>/DtrmnDCSN_ADM' */
void DCSN_subsyst_DtrmnDCSN_ADM_Init(void)
{
  /* InitializeConditions for Delay: '<S7>/Delay1' */
  DCSN_subsystem_integrated_DW.icLoad = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
  DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_Pre_np0h = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' */
  DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator1_PrevRes = 2;

  /* SystemInitialize for Chart: '<S9>/DtrmnDCSN_DrivIntention' */
  DCSN_subsystem_integrated_DW.temporalCounter_i1_gk3n = 0U;
  DCSN_subsystem_integrated_DW.is_active_c1_DCSN_subsystem_int = 0U;
  DCSN_subsystem_integrated_DW.is_c1_DCSN_subsystem_integrated =
    DCSN_subsyst_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<S8>/DtrmnDCSN_ADMManager' */
  DCSN_subsystem_integrated_DW.is_ADM_FAULT = DCSN_subsyst_IN_NO_ACTIVE_CHILD;
  DCSN_subsystem_integrated_DW.is_ADM_ON = DCSN_subsyst_IN_NO_ACTIVE_CHILD;
  DCSN_subsystem_integrated_DW.is_ADM_ON_ACTIVE =
    DCSN_subsyst_IN_NO_ACTIVE_CHILD;
  DCSN_subsystem_integrated_DW.temporalCounter_i1 = 0U;
  DCSN_subsystem_integrated_DW.is_ADM_ON_INACTIVE =
    DCSN_subsyst_IN_NO_ACTIVE_CHILD;
  DCSN_subsystem_integrated_DW.is_active_c4_DCSN_subsystem_int = 0U;
  DCSN_subsystem_integrated_DW.is_c4_DCSN_subsystem_integrated =
    DCSN_subsyst_IN_NO_ACTIVE_CHILD;
  DCSN_subsystem_integrated_DW.autodrive_engaged = false;
  DCSN_subsystem_integrated_DW.autodrive_ready_to_engage = false;
  DCSN_subsystem_integrated_DW.warning_time = 0U;
  DCSN_subsystem_integrated_DW.time_count_agzm = 1U;
  DCSN_subsystem_integrated_DW.autodrive_resume_allowed = false;
}

/* Outputs for atomic system: '<S1>/DtrmnDCSN_ADM' */
void DCSN_subsystem_in_DtrmnDCSN_ADM(void)
{
  boolean_T rtb_Switch3_ovxv;
  boolean_T rtb_UnitDelay4;
  real32_T rtb_Gain2;
  real_T rtb_Switch;
  real32_T rtb_Switch3;
  real32_T rtb_Switch3_hakn;
  real32_T rtb_Switch3_n4u0;
  int32_T i;
  boolean_T tmp;
  uint16_T u0;
  uint8_T tmp_0;
  boolean_T tmp_1;
  boolean_T LogicalOperator3_tmp;

  /* Delay: '<S7>/Delay1' incorporates:
   *  Inport: '<Root>/COMM_CANR_DataBus'
   */
  if (((int32_T)DCSN_subsystem_integrated_DW.icLoad) != 0)
  {
    for (i = 0; i < 100; i++)
    {
      DCSN_subsystem_integrated_DW.Delay1_DSTATE[i] =
        VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch;
    }
  }

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/KbDCSN_use_vehicle_activate_switch'
   *  Constant: '<S7>/KfDCSN_adm_temp_usr_cmd_autodrive_activated'
   */
  if (KbDCSN_use_vehicle_activate_switch)
  {
    /* Switch: '<S7>/Switch1' incorporates:
     *  Constant: '<S7>/Deactivate'
     *  Inport: '<Root>/COMM_CANR_DataBus'
     */
    if (VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch)
    {
      /* Delay: '<S7>/Delay1' incorporates:
       *  Constant: '<S7>/KcDCSN_t_usr_activate_cmd_send_count1'
       */
      if (((int32_T)KcDCSN_t_usr_activate_cmd_send_count) <= 0)
      {
        tmp = VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch;
      }
      else
      {
        if (((int32_T)KcDCSN_t_usr_activate_cmd_send_count) > 100)
        {
          tmp_0 = 100U;
        }
        else
        {
          tmp_0 = KcDCSN_t_usr_activate_cmd_send_count;
        }

        tmp = DCSN_subsystem_integrated_DW.Delay1_DSTATE[(uint8_T)(100U -
          ((uint32_T)tmp_0))];
      }

      /* Switch: '<S7>/Switch2' incorporates:
       *  Constant: '<S7>/Activate'
       *  Constant: '<S7>/Hold'
       *  Sum: '<S7>/Subtract1'
       */
      if (((uint8_T)((int32_T)
                     ((VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch
                       ? 1 : 0) - (tmp ? 1 : 0)))) > ((uint8_T)0U))
      {
        VeDCSN_usr_cmd_autodrive_activate = ((uint8_T)1U);
      }
      else
      {
        VeDCSN_usr_cmd_autodrive_activate = ((uint8_T)2U);
      }

      /* End of Switch: '<S7>/Switch2' */
    }
    else
    {
      VeDCSN_usr_cmd_autodrive_activate = ((uint8_T)0U);
    }

    /* End of Switch: '<S7>/Switch1' */
  }
  else
  {
    VeDCSN_usr_cmd_autodrive_activate = KeDCSN_usr_cmd_autodrive_activate_man;
  }

  /* End of Switch: '<S7>/Switch' */

  /* CombinatorialLogic: '<S43>/Logic' incorporates:
   *  Constant: '<S14>/Constant5'
   *  Constant: '<S37>/Constant'
   *  Constant: '<S38>/Constant'
   *  Constant: '<S39>/Constant'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  Logic: '<S14>/Logical Operator'
   *  Logic: '<S14>/Logical Operator1'
   *  Logic: '<S14>/Logical Operator2'
   *  Memory: '<S43>/Memory'
   *  RelationalOperator: '<S14>/Relational Operator7'
   *  RelationalOperator: '<S37>/Compare'
   *  RelationalOperator: '<S38>/Compare'
   *  RelationalOperator: '<S39>/Compare'
   *  UnitDelay: '<S14>/Unit Delay'
   *  UnitDelay: '<S14>/Unit Delay2'
   *  UnitDelay: '<S8>/Unit Delay'
   */
  i = (int32_T)((uint32_T)((((((uint32_T)
    (((((DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_k2di == ADM_STANDBY) &&
        ((VsCOMM_CANR_Databus.COMM_RX_Power.VCU_AccelPedalValid) ||
         (VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch))) &&
       (VeDCSN_usr_cmd_autodrive_activate == ((uint8_T)1U))) &&
      (DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_g2gu == ((uint8_T)0U))) ? 1
     : 0)) << 1) + ((uint32_T)(((VeDCSN_usr_cmd_autodrive_activate == ((uint8_T)
    0U)) || (DCSN_subsystem_integrated_DW.UnitDelay2_DSTATE_khwm)) ? 1 : 0))) <<
    1) + (DCSN_subsystem_integrated_DW.Memory_PreviousInput_nozl ? 1U : 0U)));
  DCSN_subsystem_integrated_B.Logic[0U] =
    DCSN_subsystem_integrate_ConstP.pooled30[(uint32_T)i];
  DCSN_subsystem_integrated_B.Logic[1U] =
    DCSN_subsystem_integrate_ConstP.pooled30[((uint32_T)i) + 8U];

  /* DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
  if (((DCSN_subsystem_integrated_B.Logic[0]) &&
       (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_Pre_np0h <= 0)) ||
      ((!DCSN_subsystem_integrated_B.Logic[0]) &&
       (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_Pre_np0h == 1)))
  {
    DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_brg5 = ((uint16_T)0U);
  }

  if (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_brg5 >= ((uint16_T)
       3000U))
  {
    DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_brg5 = ((uint16_T)
      3000U);
  }
  else
  {
    if (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_brg5 <=
        ((uint16_T)0U))
    {
      DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_brg5 = ((uint16_T)
        0U);
    }
  }

  /* Logic: '<S14>/Logical Operator3' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  Logic: '<S14>/Logical Operator8'
   */
  LogicalOperator3_tmp = ((VsCOMM_CANR_Databus.COMM_RX_Power.VCU_AccelPedalValid)
    || (VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch));
  DCSN_subsystem_integrated_B.LogicalOperator3 = LogicalOperator3_tmp;

  /* Logic: '<S14>/Logical Operator4' incorporates:
   *  Logic: '<S14>/Logical Operator5'
   *  UnitDelay: '<S14>/Unit Delay1'
   */
  rtb_Switch3_ovxv = ((!DCSN_subsystem_integrated_B.LogicalOperator3) &&
                      (DCSN_subsystem_integrated_DW.UnitDelay1_DSTATE_imjc));

  /* Outputs for Triggered SubSystem: '<S14>/CvrtDCSN_DataConvert' incorporates:
   *  TriggerPort: '<S41>/Trigger'
   */
  if (rtb_Switch3_ovxv && (((uint32_T)
        DCSN_subsystem_integrat_PrevZCX.CvrtDCSN_DataConvert_Trig_ZCE) !=
       POS_ZCSIG))
  {
    /* Inport: '<S41>/In1' incorporates:
     *  DiscreteIntegrator: '<S14>/Discrete-Time Integrator'
     */
    VfDCSN_C_cond_act_time =
      DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_brg5;
  }

  DCSN_subsystem_integrat_PrevZCX.CvrtDCSN_DataConvert_Trig_ZCE =
    rtb_Switch3_ovxv ? 1U : 0U;

  /* End of Outputs for SubSystem: '<S14>/CvrtDCSN_DataConvert' */

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S14>/Constant'
   *  RelationalOperator: '<S14>/Relational Operator'
   *  UnitDelay: '<S14>/Unit Delay5'
   */
  if (VfDCSN_C_cond_act_time != DCSN_subsystem_integrated_DW.UnitDelay5_DSTATE)
  {
    rtb_Switch = (real_T)VfDCSN_C_cond_act_time;
  }
  else
  {
    rtb_Switch = 0.0;
  }

  /* End of Switch: '<S14>/Switch' */

  /* CombinatorialLogic: '<S42>/Logic' incorporates:
   *  Constant: '<S14>/Constant1'
   *  Constant: '<S14>/Constant2'
   *  Constant: '<S14>/Constant3'
   *  Constant: '<S14>/KfDCSN_t_allowed_time_cond_activate1'
   *  Constant: '<S40>/Constant'
   *  Gain: '<S14>/Gain1'
   *  Logic: '<S14>/Logical Operator6'
   *  Logic: '<S14>/Logical Operator7'
   *  Memory: '<S42>/Memory'
   *  RelationalOperator: '<S14>/Relational Operator2'
   *  RelationalOperator: '<S14>/Relational Operator3'
   *  RelationalOperator: '<S14>/Relational Operator4'
   *  RelationalOperator: '<S14>/Relational Operator5'
   *  RelationalOperator: '<S40>/Compare'
   *  UnitDelay: '<S14>/Unit Delay3'
   *  UnitDelay: '<S8>/Unit Delay'
   */
  i = (int32_T)((uint32_T)((((((uint32_T)((((rtb_Switch <= ((real_T)((real32_T)
    (100.0F * KfDCSN_t_allowed_time_cond_activate)))) && (rtb_Switch > ((real_T)
    ((uint8_T)0U)))) && (VeDCSN_usr_cmd_autodrive_activate == ((uint8_T)2U))) ?
    1 : 0)) << 1) + ((uint32_T)
                     ((((DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_k2di ==
    ADM_ACTIVE) || (DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_k2di ==
                    ADM_STEER_OVRD)) ||
                       (DCSN_subsystem_integrated_DW.UnitDelay3_DSTATE_m0wa)) ?
                      1 : 0))) << 1) +
    (DCSN_subsystem_integrated_DW.Memory_PreviousInput_p5cx ? 1U : 0U)));
  DCSN_subsystem_integrated_B.Logic_mmx2[0U] =
    DCSN_subsystem_integrate_ConstP.pooled30[(uint32_T)i];
  DCSN_subsystem_integrated_B.Logic_mmx2[1U] =
    DCSN_subsystem_integrate_ConstP.pooled30[((uint32_T)i) + 8U];

  /* DataTypeConversion: '<S14>/Data Type Conversion' */
  VbDCSN_cond_activate_met = DCSN_subsystem_integrated_B.Logic_mmx2[0];

  /* RelationalOperator: '<S36>/Compare' incorporates:
   *  Constant: '<S36>/Constant'
   *  Constant: '<S8>/KeDCSN_adm_temp_diag_system_fault'
   */
  DCSN_subsystem_integrated_B.Compare = (KeDCSN_adm_temp_diag_system_fault >=
    ((uint8_T)3U));

  /* Logic: '<S12>/Logical Operator' incorporates:
   *  Delay: '<S12>/Delay'
   */
  VbDCSN_fault_detected = ((DCSN_subsystem_integrated_B.Compare) &&
    (DCSN_subsystem_integrated_DW.Delay_DSTATE_mze2[0]));

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/KbDCSN_use_faw_l4_logic1'
   *  Constant: '<S49>/Constant'
   *  Constant: '<S50>/Constant'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  RelationalOperator: '<S49>/Compare'
   *  RelationalOperator: '<S50>/Compare'
   */
  if (KbDCSN_use_faw_l4_logic)
  {
    tmp = (VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_IgnitionKeyState == true);
  }
  else
  {
    tmp = (VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_IgnitionKeyState == true);
  }

  /* End of Switch: '<S10>/Switch' */

  /* Switch: '<S51>/Switch1' incorporates:
   *  Constant: '<S51>/Constant4'
   */
  if (tmp)
  {
    /* Sum: '<S51>/Sum' incorporates:
     *  Constant: '<S51>/CallFrequencyOneLoop'
     *  UnitDelay: '<S51>/UnitDelay'
     */
    u0 = (uint16_T)(((uint32_T)
                     DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_jn5k) +
                    ((uint32_T)((uint16_T)1U)));

    /* Saturate: '<S51>/Saturation' */
    if (u0 < ((uint16_T)65534U))
    {
      DCSN_subsystem_integrated_B.CurrentTick = u0;
    }
    else
    {
      DCSN_subsystem_integrated_B.CurrentTick = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S51>/Saturation' */
  }
  else
  {
    DCSN_subsystem_integrated_B.CurrentTick = ((uint16_T)0U);
  }

  /* End of Switch: '<S51>/Switch1' */

  /* Logic: '<S10>/Logical Operator' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/KbDCSN_SLEW_initialization_finished'
   *  RelationalOperator: '<S51>/RelationalOperator1'
   */
  VbDCSN_initialization_finished = ((DCSN_subsystem_integrated_B.CurrentTick >
    ((uint16_T)100U)) || KbDCSN_SLEW_initialization_finished);

  /* Switch: '<S3>/Switch1' incorporates:
   *  Constant: '<S3>/aeb_switch1'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  Inport: '<Root>/EGMO_DataBus'
   */
  if (KbDCSN_use_EgmoLinearSpeed)
  {
    rtb_Gain2 = VsEGMO_DataBus.motion.linear_velocity;
  }
  else
  {
    rtb_Gain2 = VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed;
  }

  /* End of Switch: '<S3>/Switch1' */

  /* Logic: '<S6>/Logical Operator' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Inport: '<Root>/ACCS_DataBus'
   *  RelationalOperator: '<S6>/Relational Operator'
   *  RelationalOperator: '<S6>/Relational Operator1'
   */
  VbDCSN_ACC_ready_to_engage = ((VsACCS_DataBus.VeACCS_Mode == ACCS_mode_standby)
    || (VsACCS_DataBus.VeACCS_Mode == ACCS_mode_on));

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Ready'
   *  Constant: '<S3>/aeb_switch16'
   *  Inport: '<Root>/EGMO_DataBus'
   */
  if (KbDCSN_use_EgmoReadyFlag)
  {
    rtb_UnitDelay4 = VsEGMO_DataBus.is_ready;
  }
  else
  {
    rtb_UnitDelay4 = true;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Switch: '<S3>/Switch3' incorporates:
   *  Constant: '<S3>/Ready1'
   *  Constant: '<S3>/aeb_switch2'
   *  Inport: '<Root>/MPFU_DataBus'
   */
  if (KbDCSN_use_MpfuReadyFlag)
  {
    rtb_Switch3_ovxv = VsMPFU_DataBus.is_ready;
  }
  else
  {
    rtb_Switch3_ovxv = true;
  }

  /* End of Switch: '<S3>/Switch3' */

  /* Switch: '<S20>/Switch1' incorporates:
   *  Constant: '<S20>/KbDCSN_use_faw_l4_logic'
   *  Constant: '<S20>/epb_check_passed'
   *  Constant: '<S20>/epb_released'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  RelationalOperator: '<S20>/Relational Operator'
   */
  if (KbDCSN_use_faw_l4_logic)
  {
    tmp = true;
  }
  else
  {
    tmp = (VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ActualControlStatus ==
           ((uint8_T)0U));
  }

  /* End of Switch: '<S20>/Switch1' */

  /* Switch: '<S20>/Switch2' incorporates:
   *  Constant: '<S20>/KbDCSN_use_faw_l4_logic1'
   *  Constant: '<S20>/gear_D'
   *  Constant: '<S20>/gear_check_passed'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  RelationalOperator: '<S20>/Relational Operator1'
   */
  if (KbDCSN_use_faw_l4_logic)
  {
    tmp_1 = true;
  }
  else
  {
    tmp_1 = (VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition ==
             ((uint8_T)1U));
  }

  /* End of Switch: '<S20>/Switch2' */

  /* Sum: '<S20>/Sum' incorporates:
   *  Constant: '<S20>/KfDCSN_v_adm_active_extraspeed'
   *  Constant: '<S8>/KfDCSN_v_adm_temp_veh_setspeed'
   *  Sum: '<S34>/Sum'
   */
  rtb_Switch3 = KfDCSN_v_adm_temp_veh_setspeed + KfDCSN_v_adm_active_extraspeed;

  /* Logic: '<S15>/Logical Operator' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S20>/Constant5'
   *  Constant: '<S20>/KbDCSN_use_faw_l4_logic2'
   *  Constant: '<S20>/KfDCSN_v_setspeed_thrsh_hi'
   *  Constant: '<S8>/KfDCSN_v_adm_temp_veh_setspeed'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  Logic: '<S19>/Logical Operator'
   *  Logic: '<S20>/Logical Operator'
   *  Logic: '<S20>/Logical Operator1'
   *  Logic: '<S20>/Logical Operator2'
   *  Logic: '<S20>/Logical Operator3'
   *  RelationalOperator: '<S20>/Relational Operator2'
   *  RelationalOperator: '<S20>/Relational Operator3'
   *  RelationalOperator: '<S20>/Relational Operator6'
   *  Sum: '<S20>/Sum'
   */
  VbDCSN_autodrive_ready_to_engage = (((((((tmp && tmp_1) &&
    (!VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch)) &&
    (KfDCSN_v_adm_temp_veh_setspeed <= KfDCSN_v_setspeed_thrsh_hi)) &&
    (rtb_Gain2 <= rtb_Switch3)) && ((!KbDCSN_use_faw_l4_logic) ||
    (VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutoToManualTips ==
     ((uint16_T)0U)))) && ((VbDCSN_ACC_ready_to_engage && rtb_UnitDelay4) &&
    rtb_Switch3_ovxv)) && (true));

  /* Switch: '<S23>/Switch1' incorporates:
   *  Constant: '<S23>/KbDCSN_use_faw_l4_logic'
   *  Constant: '<S23>/epb_check_passed'
   *  Constant: '<S23>/epb_released'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  RelationalOperator: '<S23>/Relational Operator'
   */
  if (KbDCSN_use_faw_l4_logic)
  {
    tmp = false;
  }
  else
  {
    tmp = (VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ActualControlStatus !=
           ((uint8_T)0U));
  }

  /* End of Switch: '<S23>/Switch1' */

  /* Switch: '<S27>/Switch1' incorporates:
   *  Constant: '<S27>/Constant4'
   */
  if (tmp)
  {
    /* Sum: '<S27>/Sum' incorporates:
     *  Constant: '<S27>/CallFrequencyOneLoop'
     *  UnitDelay: '<S27>/UnitDelay'
     */
    u0 = (uint16_T)(((uint32_T)
                     DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_kv3i) +
                    ((uint32_T)((uint16_T)1U)));

    /* Saturate: '<S27>/Saturation' */
    if (u0 < ((uint16_T)65534U))
    {
      DCSN_subsystem_integrated_B.CurrentTick_cho5 = u0;
    }
    else
    {
      DCSN_subsystem_integrated_B.CurrentTick_cho5 = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S27>/Saturation' */
  }
  else
  {
    DCSN_subsystem_integrated_B.CurrentTick_cho5 = ((uint16_T)0U);
  }

  /* End of Switch: '<S27>/Switch1' */

  /* Switch: '<S23>/Switch2' incorporates:
   *  Constant: '<S23>/KbDCSN_use_faw_l4_logic1'
   *  Constant: '<S23>/gear_D'
   *  Constant: '<S23>/gear_check_passed'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  RelationalOperator: '<S23>/Relational Operator1'
   */
  if (KbDCSN_use_faw_l4_logic)
  {
    tmp = false;
  }
  else
  {
    tmp = (VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition !=
           ((uint8_T)1U));
  }

  /* End of Switch: '<S23>/Switch2' */

  /* Switch: '<S28>/Switch1' incorporates:
   *  Constant: '<S28>/Constant4'
   */
  if (tmp)
  {
    /* Sum: '<S28>/Sum' incorporates:
     *  Constant: '<S28>/CallFrequencyOneLoop'
     *  UnitDelay: '<S28>/UnitDelay'
     */
    u0 = (uint16_T)(((uint32_T)
                     DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_awwr) +
                    ((uint32_T)((uint16_T)1U)));

    /* Saturate: '<S28>/Saturation' */
    if (u0 < ((uint16_T)65534U))
    {
      DCSN_subsystem_integrated_B.CurrentTick_hcb0 = u0;
    }
    else
    {
      DCSN_subsystem_integrated_B.CurrentTick_hcb0 = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S28>/Saturation' */
  }
  else
  {
    DCSN_subsystem_integrated_B.CurrentTick_hcb0 = ((uint16_T)0U);
  }

  /* End of Switch: '<S28>/Switch1' */

  /* Switch: '<S29>/Switch1' incorporates:
   *  Constant: '<S23>/Constant1'
   *  Constant: '<S23>/Constant7'
   *  Constant: '<S29>/Constant4'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  Logic: '<S23>/Logical Operator2'
   *  RelationalOperator: '<S23>/Relational Operator4'
   */
  if (KbDCSN_adm_BrkPressDeactivateEnabled &&
      (VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch == true))
  {
    /* Sum: '<S29>/Sum' incorporates:
     *  Constant: '<S29>/CallFrequencyOneLoop'
     *  UnitDelay: '<S29>/UnitDelay'
     */
    u0 = (uint16_T)(((uint32_T)
                     DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_a5my) +
                    ((uint32_T)((uint16_T)1U)));

    /* Saturate: '<S29>/Saturation' */
    if (u0 < ((uint16_T)65534U))
    {
      DCSN_subsystem_integrated_B.CurrentTick_ilxy = u0;
    }
    else
    {
      DCSN_subsystem_integrated_B.CurrentTick_ilxy = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S29>/Saturation' */
  }
  else
  {
    DCSN_subsystem_integrated_B.CurrentTick_ilxy = ((uint16_T)0U);
  }

  /* End of Switch: '<S29>/Switch1' */

  /* Switch: '<S30>/Switch1' incorporates:
   *  Constant: '<S23>/KfDCSN_v_autodrive_max_speed'
   *  Constant: '<S30>/Constant4'
   *  RelationalOperator: '<S23>/Relational Operator2'
   */
  if (rtb_Gain2 > KfDCSN_v_autodrive_max_speed)
  {
    /* Sum: '<S30>/Sum' incorporates:
     *  Constant: '<S30>/CallFrequencyOneLoop'
     *  UnitDelay: '<S30>/UnitDelay'
     */
    u0 = (uint16_T)(((uint32_T)
                     DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_ivcp) +
                    ((uint32_T)((uint16_T)1U)));

    /* Saturate: '<S30>/Saturation' */
    if (u0 < ((uint16_T)65534U))
    {
      DCSN_subsystem_integrated_B.CurrentTick_k4pd = u0;
    }
    else
    {
      DCSN_subsystem_integrated_B.CurrentTick_k4pd = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S30>/Saturation' */
  }
  else
  {
    DCSN_subsystem_integrated_B.CurrentTick_k4pd = ((uint16_T)0U);
  }

  /* End of Switch: '<S30>/Switch1' */

  /* Switch: '<S31>/Switch1' incorporates:
   *  Constant: '<S23>/Constant2'
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant5'
   *  Constant: '<S23>/KbDCSN_use_faw_l4_logic2'
   *  Constant: '<S31>/Constant4'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  Logic: '<S23>/Logical Operator1'
   *  Logic: '<S23>/Logical Operator3'
   *  RelationalOperator: '<S23>/Relational Operator5'
   *  RelationalOperator: '<S23>/Relational Operator6'
   *  RelationalOperator: '<S23>/Relational Operator7'
   */
  if (KbDCSN_use_faw_l4_logic &&
      (((VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutoToManualTips !=
         ((uint16_T)0U)) &&
        (VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutoToManualTips !=
         ((uint16_T)128U))) &&
       (VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutoToManualTips !=
        ((uint16_T)512U))))
  {
    /* Sum: '<S31>/Sum' incorporates:
     *  Constant: '<S31>/CallFrequencyOneLoop'
     *  UnitDelay: '<S31>/UnitDelay'
     */
    u0 = (uint16_T)(((uint32_T)
                     DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_pet3) +
                    ((uint32_T)((uint16_T)1U)));

    /* Saturate: '<S31>/Saturation' */
    if (u0 < ((uint16_T)65534U))
    {
      DCSN_subsystem_integrated_B.CurrentTick_i1hg = u0;
    }
    else
    {
      DCSN_subsystem_integrated_B.CurrentTick_i1hg = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S31>/Saturation' */
  }
  else
  {
    DCSN_subsystem_integrated_B.CurrentTick_i1hg = ((uint16_T)0U);
  }

  /* End of Switch: '<S31>/Switch1' */

  /* Switch: '<S24>/Switch1' incorporates:
   *  Constant: '<S24>/Constant4'
   *  Logic: '<S22>/Logical Operator3'
   */
  if (!VbDCSN_ACC_ready_to_engage)
  {
    /* Sum: '<S24>/Sum' incorporates:
     *  Constant: '<S24>/CallFrequencyOneLoop'
     *  UnitDelay: '<S24>/UnitDelay'
     */
    u0 = (uint16_T)(((uint32_T)
                     DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_nbxp) +
                    ((uint32_T)((uint16_T)1U)));

    /* Saturate: '<S24>/Saturation' */
    if (u0 < ((uint16_T)65534U))
    {
      DCSN_subsystem_integrated_B.CurrentTick_ad1o = u0;
    }
    else
    {
      DCSN_subsystem_integrated_B.CurrentTick_ad1o = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S24>/Saturation' */
  }
  else
  {
    DCSN_subsystem_integrated_B.CurrentTick_ad1o = ((uint16_T)0U);
  }

  /* End of Switch: '<S24>/Switch1' */

  /* Switch: '<S25>/Switch1' incorporates:
   *  Constant: '<S25>/Constant4'
   *  Logic: '<S22>/Logical Operator1'
   */
  if (!rtb_UnitDelay4)
  {
    /* Sum: '<S25>/Sum' incorporates:
     *  Constant: '<S25>/CallFrequencyOneLoop'
     *  UnitDelay: '<S25>/UnitDelay'
     */
    u0 = (uint16_T)(((uint32_T)
                     DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_o4sd) +
                    ((uint32_T)((uint16_T)1U)));

    /* Saturate: '<S25>/Saturation' */
    if (u0 < ((uint16_T)65534U))
    {
      DCSN_subsystem_integrated_B.CurrentTick_hziy = u0;
    }
    else
    {
      DCSN_subsystem_integrated_B.CurrentTick_hziy = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S25>/Saturation' */
  }
  else
  {
    DCSN_subsystem_integrated_B.CurrentTick_hziy = ((uint16_T)0U);
  }

  /* End of Switch: '<S25>/Switch1' */

  /* Switch: '<S26>/Switch1' incorporates:
   *  Constant: '<S26>/Constant4'
   *  Logic: '<S22>/Logical Operator2'
   */
  if (!rtb_Switch3_ovxv)
  {
    /* Sum: '<S26>/Sum' incorporates:
     *  Constant: '<S26>/CallFrequencyOneLoop'
     *  UnitDelay: '<S26>/UnitDelay'
     */
    u0 = (uint16_T)(((uint32_T)
                     DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_pjhr) +
                    ((uint32_T)((uint16_T)1U)));

    /* Saturate: '<S26>/Saturation' */
    if (u0 < ((uint16_T)65534U))
    {
      DCSN_subsystem_integrated_B.CurrentTick_k0eg = u0;
    }
    else
    {
      DCSN_subsystem_integrated_B.CurrentTick_k0eg = ((uint16_T)65534U);
    }

    /* End of Saturate: '<S26>/Saturation' */
  }
  else
  {
    DCSN_subsystem_integrated_B.CurrentTick_k0eg = ((uint16_T)0U);
  }

  /* End of Switch: '<S26>/Switch1' */

  /* Logic: '<S16>/Logical Operator' incorporates:
   *  Constant: '<S21>/Constant'
   *  Constant: '<S22>/260msDebounce'
   *  Constant: '<S22>/260msDebounce1'
   *  Constant: '<S22>/260msDebounce2'
   *  Constant: '<S23>/Constant'
   *  Constant: '<S23>/Constant4'
   *  Constant: '<S23>/Constant6'
   *  Constant: '<S23>/Constant8'
   *  Constant: '<S23>/Constant9'
   *  Logic: '<S22>/Logical Operator'
   *  Logic: '<S23>/Logical Operator'
   *  RelationalOperator: '<S24>/RelationalOperator1'
   *  RelationalOperator: '<S25>/RelationalOperator1'
   *  RelationalOperator: '<S26>/RelationalOperator1'
   *  RelationalOperator: '<S27>/RelationalOperator1'
   *  RelationalOperator: '<S28>/RelationalOperator1'
   *  RelationalOperator: '<S29>/RelationalOperator1'
   *  RelationalOperator: '<S30>/RelationalOperator1'
   *  RelationalOperator: '<S31>/RelationalOperator1'
   */
  VbDCSN_autodrive_exit = (((((((DCSN_subsystem_integrated_B.CurrentTick_cho5 >
    ((uint16_T)6U)) || (DCSN_subsystem_integrated_B.CurrentTick_hcb0 >
                        ((uint16_T)6U))) ||
    (DCSN_subsystem_integrated_B.CurrentTick_ilxy > ((uint16_T)6U))) ||
    (DCSN_subsystem_integrated_B.CurrentTick_k4pd > ((uint16_T)6U))) ||
    (DCSN_subsystem_integrated_B.CurrentTick_i1hg > ((uint16_T)6U))) ||
    (((DCSN_subsystem_integrated_B.CurrentTick_ad1o > ((uint16_T)26U)) ||
      (DCSN_subsystem_integrated_B.CurrentTick_hziy > ((uint16_T)26U))) ||
     (DCSN_subsystem_integrated_B.CurrentTick_k0eg > ((uint16_T)26U)))) ||
    (false));

  /* Logic: '<S17>/Logical Operator' incorporates:
   *  Constant: '<S32>/Constant'
   *  Constant: '<S34>/KfDCSN_v_setspeed_thrsh_hi'
   *  Constant: '<S8>/KfDCSN_v_adm_temp_veh_setspeed'
   *  Inport: '<Root>/LCCS_DataBus'
   *  Logic: '<S34>/Logical Operator'
   *  RelationalOperator: '<S34>/Relational Operator2'
   *  RelationalOperator: '<S34>/Relational Operator3'
   */
  VbDCSN_autodrive_warning = ((((KfDCSN_v_adm_temp_veh_setspeed >
    KfDCSN_v_setspeed_thrsh_hi) || (rtb_Gain2 > rtb_Switch3)) ||
    (VsLCCS_DataBus.LCC_ForceToDisengage)) || (false));

  /* Gain: '<S8>/Gain' incorporates:
   *  Constant: '<S8>/KfDCSN_t_time_allowed_to_takeover'
   */
  rtb_Gain2 = 100.0F * KfDCSN_t_max_time_to_takeover;

  /* Switch: '<S45>/Switch3' incorporates:
   *  Abs: '<S9>/Abs1'
   *  Constant: '<S45>/Constant'
   *  Constant: '<S45>/KbDCSN_use_faw_l4_logic2'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   */
  if (KbDCSN_use_faw_l4_logic)
  {
    rtb_Switch3 = 1.0F;
  }
  else
  {
    rtb_Switch3 = (real32_T)fabs((real_T)
      VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorque);
  }

  /* End of Switch: '<S45>/Switch3' */

  /* Switch: '<S47>/Switch3' incorporates:
   *  Constant: '<S47>/Constant'
   *  Constant: '<S47>/KbDCSN_use_faw_l4_logic2'
   *  Constant: '<S47>/KfDCSN_M_adm_temp_steering_ovrd_torque'
   */
  if (KbDCSN_use_faw_l4_logic)
  {
    rtb_Switch3_hakn = 0.0F;
  }
  else
  {
    rtb_Switch3_hakn = KfDCSN_M_adm_temp_steering_ovrd_torque;
  }

  /* End of Switch: '<S47>/Switch3' */

  /* Switch: '<S48>/Switch3' incorporates:
   *  Constant: '<S48>/Constant'
   *  Constant: '<S48>/KbDCSN_use_faw_l4_logic2'
   *  Constant: '<S48>/KfDCSN_M_adm_temp_steering_resume_torque'
   */
  if (KbDCSN_use_faw_l4_logic)
  {
    rtb_Switch3_n4u0 = 2.0F;
  }
  else
  {
    rtb_Switch3_n4u0 = KfDCSN_M_adm_temp_steering_resume_torque;
  }

  /* End of Switch: '<S48>/Switch3' */

  /* Switch: '<S46>/Switch2' incorporates:
   *  Constant: '<S46>/Constant2'
   *  Constant: '<S46>/KbDCSN_use_faw_l4_logic1'
   */
  if (KbDCSN_use_faw_l4_logic)
  {
    /* Switch: '<S46>/Switch' incorporates:
     *  Constant: '<S46>/KbDCSN_use_faw_handoff_as_ovrd'
     *  Inport: '<Root>/COMM_CANR_DataBus'
     *  Logic: '<S46>/Logical Operator'
     */
    if (KbDCSN_use_faw_handoff_as_ovrd)
    {
      rtb_Switch3_ovxv =
        !VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_HandsOffWheelDetected;
    }
    else
    {
      rtb_Switch3_ovxv =
        VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_HandsOnWheelDetected;
    }

    /* End of Switch: '<S46>/Switch' */
  }
  else
  {
    rtb_Switch3_ovxv = true;
  }

  /* End of Switch: '<S46>/Switch2' */

  /* Switch: '<S46>/Switch3' incorporates:
   *  Constant: '<S46>/Constant1'
   *  Constant: '<S46>/KbDCSN_use_faw_l4_logic2'
   */
  if (KbDCSN_use_faw_l4_logic)
  {
    /* Switch: '<S46>/Switch1' incorporates:
     *  Constant: '<S46>/KbDCSN_use_faw_handoff_as_resume'
     *  Inport: '<Root>/COMM_CANR_DataBus'
     *  Logic: '<S46>/Logical Operator1'
     */
    if (KbDCSN_use_faw_handoff_as_resume)
    {
      rtb_UnitDelay4 =
        VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_HandsOffWheelDetected;
    }
    else
    {
      rtb_UnitDelay4 =
        !VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_HandsOnWheelDetected;
    }

    /* End of Switch: '<S46>/Switch1' */
  }
  else
  {
    rtb_UnitDelay4 = true;
  }

  /* End of Switch: '<S46>/Switch3' */

  /* Chart: '<S9>/DtrmnDCSN_DrivIntention' incorporates:
   *  Constant: '<S9>/KfDCSN_t_adm_temp_steering_ovrd_delay'
   *  Constant: '<S9>/KfDCSN_t_adm_temp_steering_resume_delay'
   *  Gain: '<S9>/Gain'
   *  Gain: '<S9>/Gain1'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  Inport: '<Root>/LCCS_DataBus'
   */
  if (((uint32_T)DCSN_subsystem_integrated_DW.temporalCounter_i1_gk3n) < 65535U)
  {
    DCSN_subsystem_integrated_DW.temporalCounter_i1_gk3n = (uint16_T)((int32_T)
      (((int32_T)DCSN_subsystem_integrated_DW.temporalCounter_i1_gk3n) + 1));
  }

  if (((uint32_T)DCSN_subsystem_integrated_DW.is_active_c1_DCSN_subsystem_int) ==
      0U)
  {
    DCSN_subsystem_integrated_DW.is_active_c1_DCSN_subsystem_int = 1U;
    DCSN_subsystem_integrated_DW.is_c1_DCSN_subsystem_integrated =
      DCSN_subs_IN_driv_steering_ovrd;
    VbDCSN_adm_steering_override = true;
    VbDCSN_adm_steering_resume = false;
  }
  else
  {
    switch (DCSN_subsystem_integrated_DW.is_c1_DCSN_subsystem_integrated)
    {
     case DCSN_subs_IN_driv_steering_ovrd:
      VbDCSN_adm_steering_override = true;
      VbDCSN_adm_steering_resume = false;
      if ((((rtb_Switch3 <= rtb_Switch3_n4u0) &&
            (VsLCCS_DataBus.LCC_ReadyToEngage)) &&
           (!VsLCCS_DataBus.LCC_ForceToDisengage)) && rtb_UnitDelay4)
      {
        DCSN_subsystem_integrated_DW.is_c1_DCSN_subsystem_integrated =
          D_IN_driv_steering_resume_delay;
        DCSN_subsystem_integrated_DW.temporalCounter_i1_gk3n = 0U;
        VbDCSN_adm_steering_override = true;
        VbDCSN_adm_steering_resume = false;
      }
      break;

     case DCS_IN_driv_steering_ovrd_delay:
      VbDCSN_adm_steering_override = false;
      VbDCSN_adm_steering_resume = false;
      if ((rtb_Switch3 <= rtb_Switch3_hakn) || (!rtb_Switch3_ovxv))
      {
        DCSN_subsystem_integrated_DW.is_c1_DCSN_subsystem_integrated =
          DCSN_s_IN_driv_steering_standby;
        VbDCSN_adm_steering_override = false;
        VbDCSN_adm_steering_resume = true;
      }
      else
      {
        if ((DCSN_subsystem_integrated_DW.temporalCounter_i1_gk3n >= ((uint16_T)
              ((real32_T)(100.0F * KfDCSN_t_adm_temp_steering_ovrd_delay)))) ||
            (!VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse))
        {
          DCSN_subsystem_integrated_DW.is_c1_DCSN_subsystem_integrated =
            DCSN_subs_IN_driv_steering_ovrd;
          VbDCSN_adm_steering_override = true;
          VbDCSN_adm_steering_resume = false;
        }
      }
      break;

     case D_IN_driv_steering_resume_delay:
      VbDCSN_adm_steering_override = true;
      VbDCSN_adm_steering_resume = false;
      if ((((rtb_Switch3 > rtb_Switch3_n4u0) ||
            (!VsLCCS_DataBus.LCC_ReadyToEngage)) ||
           (VsLCCS_DataBus.LCC_ForceToDisengage)) || (!rtb_UnitDelay4))
      {
        DCSN_subsystem_integrated_DW.is_c1_DCSN_subsystem_integrated =
          DCSN_subs_IN_driv_steering_ovrd;
        VbDCSN_adm_steering_override = true;
        VbDCSN_adm_steering_resume = false;
      }
      else if (DCSN_subsystem_integrated_DW.temporalCounter_i1_gk3n >=
               ((uint16_T)((real32_T)(100.0F *
                  KfDCSN_t_adm_temp_steering_resume_delay))))
      {
        DCSN_subsystem_integrated_DW.is_c1_DCSN_subsystem_integrated =
          DCSN__IN_driv_steering_resuming;
        VbDCSN_adm_steering_override = false;
        VbDCSN_adm_steering_resume = true;
      }
      else
      {
        if (VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse)
        {
          DCSN_subsystem_integrated_DW.is_c1_DCSN_subsystem_integrated =
            DCSN_s_IN_driv_steering_standby;
          VbDCSN_adm_steering_override = false;
          VbDCSN_adm_steering_resume = true;
        }
      }
      break;

     case DCSN__IN_driv_steering_resuming:
      VbDCSN_adm_steering_override = false;
      VbDCSN_adm_steering_resume = true;
      if (VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse)
      {
        DCSN_subsystem_integrated_DW.is_c1_DCSN_subsystem_integrated =
          DCSN_s_IN_driv_steering_standby;
        VbDCSN_adm_steering_override = false;
        VbDCSN_adm_steering_resume = true;
      }
      else
      {
        if ((((rtb_Switch3 > rtb_Switch3_hakn) && rtb_Switch3_ovxv) ||
             (!VsLCCS_DataBus.LCC_ReadyToEngage)) ||
            (VsLCCS_DataBus.LCC_ForceToDisengage))
        {
          DCSN_subsystem_integrated_DW.is_c1_DCSN_subsystem_integrated =
            DCSN_subs_IN_driv_steering_ovrd;
          VbDCSN_adm_steering_override = true;
          VbDCSN_adm_steering_resume = false;
        }
      }
      break;

     default:
      VbDCSN_adm_steering_override = false;
      VbDCSN_adm_steering_resume = true;
      if ((rtb_Switch3 > rtb_Switch3_hakn) && rtb_Switch3_ovxv)
      {
        DCSN_subsystem_integrated_DW.is_c1_DCSN_subsystem_integrated =
          DCS_IN_driv_steering_ovrd_delay;
        DCSN_subsystem_integrated_DW.temporalCounter_i1_gk3n = 0U;
        VbDCSN_adm_steering_override = false;
        VbDCSN_adm_steering_resume = false;
      }
      else
      {
        if ((!VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse) &&
            (VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveActiveStatus))
        {
          DCSN_subsystem_integrated_DW.is_c1_DCSN_subsystem_integrated =
            DCSN_subs_IN_driv_steering_ovrd;
          VbDCSN_adm_steering_override = true;
          VbDCSN_adm_steering_resume = false;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S9>/DtrmnDCSN_DrivIntention' */

  /* Chart: '<S8>/DtrmnDCSN_ADMManager' incorporates:
   *  Constant: '<S8>/KfDCSN_adm_temp_stop_finished'
   *  Constant: '<S8>/KfDCSN_adm_temp_usr_cmd_autodrive_enabled'
   *  Constant: '<S8>/KfDCSN_t_max_time_fault_warning'
   *  Gain: '<S8>/Gain2'
   */
  if (DCSN_subsystem_integrated_DW.temporalCounter_i1 < MAX_uint32_T)
  {
    DCSN_subsystem_integrated_DW.temporalCounter_i1++;
  }

  if (((uint32_T)DCSN_subsystem_integrated_DW.is_active_c4_DCSN_subsystem_int) ==
      0U)
  {
    DCSN_subsystem_integrated_DW.is_active_c4_DCSN_subsystem_int = 1U;
    DCSN_subsystem_integrated_DW.is_c4_DCSN_subsystem_integrated =
      DCSN_subsystem_integ_IN_ADM_OFF;
    DCSN_subsystem_integrated_B.adm_main_mode = ADM_OFF;
    VeDCSN_hmi_icon_display = NO_ICON;
    VeDCSN_hmi_msg_display = NO_MSG;
    DCSN_subsystem_integrated_DW.autodrive_engaged = false;
  }
  else
  {
    switch (DCSN_subsystem_integrated_DW.is_c4_DCSN_subsystem_integrated)
    {
     case DCSN_subsystem_int_IN_ADM_FAULT:
      if ((!VbDCSN_fault_detected) &&
          (DCSN_subsystem_integrated_DW.autodrive_resume_allowed))
      {
        DCSN_subsystem_integrated_DW.is_ADM_FAULT =
          DCSN_subsyst_IN_NO_ACTIVE_CHILD;
        DCSN_subsystem_integrated_DW.is_c4_DCSN_subsystem_integrated =
          DCSN_subsystem_integ_IN_ADM_OFF;
        DCSN_subsystem_integrated_B.adm_main_mode = ADM_OFF;
        VeDCSN_hmi_icon_display = NO_ICON;
        VeDCSN_hmi_msg_display = NO_MSG;
        DCSN_subsystem_integrated_DW.autodrive_engaged = false;
      }
      else
      {
        switch (DCSN_subsystem_integrated_DW.is_ADM_FAULT)
        {
         case DCSN_subs_IN_ADM_FAULT_DETECTED:
          DCSN_subsystem_integrated_B.adm_main_mode = ADM_FAULT_DETECTED;
          VeDCSN_hmi_icon_display = RED_SOLID;
          VeDCSN_hmi_msg_display = FAULT;
          break;

         case DCSN_subs_IN_ADM_FAULT_REACTION:
          DCSN_subsystem_integrated_B.adm_main_mode = ADM_FAULT_REACTION;
          VeDCSN_hmi_icon_display = RED_FLASH_FAST;
          VeDCSN_hmi_msg_display = FAULT;
          if (((VbDCSN_adm_steering_override || VbDCSN_autodrive_exit) ||
               (((int32_T)VeDCSN_usr_cmd_autodrive_activate) == 0)) ||
              KbDCSN_adm_temp_stop_finished)
          {
            DCSN_subsystem_integrated_DW.is_ADM_FAULT =
              DCSN_subs_IN_ADM_FAULT_DETECTED;
            DCSN_subsystem_integrated_B.adm_main_mode = ADM_FAULT_DETECTED;
            VeDCSN_hmi_icon_display = RED_SOLID;
            VeDCSN_hmi_msg_display = FAULT;
            DCSN_subsystem_integrated_DW.autodrive_resume_allowed = true;
          }
          break;

         default:
          DCSN_subsystem_integrated_B.adm_main_mode = ADM_FAULT_WARNING;
          VeDCSN_hmi_icon_display = RED_FLASH_SLOW;
          VeDCSN_hmi_msg_display = FAULT;
          if (DCSN_subsystem_integrated_DW.temporalCounter_i1 >= ((uint32_T)
               ((real32_T)(100.0F * KfDCSN_t_max_time_fault_warning))))
          {
            DCSN_subsystem_integrated_DW.is_ADM_FAULT =
              DCSN_subs_IN_ADM_FAULT_REACTION;
            DCSN_subsystem_integrated_B.adm_main_mode = ADM_FAULT_REACTION;
            VeDCSN_hmi_icon_display = RED_FLASH_FAST;
            VeDCSN_hmi_msg_display = FAULT;
          }
          else
          {
            if ((VbDCSN_adm_steering_override || VbDCSN_autodrive_exit) ||
                (((int32_T)VeDCSN_usr_cmd_autodrive_activate) == 0))
            {
              DCSN_subsystem_integrated_DW.is_ADM_FAULT =
                DCSN_subs_IN_ADM_FAULT_DETECTED;
              DCSN_subsystem_integrated_B.adm_main_mode = ADM_FAULT_DETECTED;
              VeDCSN_hmi_icon_display = RED_SOLID;
              VeDCSN_hmi_msg_display = FAULT;
              DCSN_subsystem_integrated_DW.autodrive_resume_allowed = true;
            }
          }
          break;
        }
      }
      break;

     case DCSN_subsystem_integ_IN_ADM_OFF:
      DCSN_subsystem_integrated_B.adm_main_mode = ADM_OFF;
      VeDCSN_hmi_icon_display = NO_ICON;
      VeDCSN_hmi_msg_display = NO_MSG;
      if (((!VbDCSN_fault_detected) && KbDCSN_adm_temp_usr_cmd_autodrive_enabled)
          && VbDCSN_initialization_finished)
      {
        DCSN_subsystem_integrated_DW.is_c4_DCSN_subsystem_integrated =
          DCSN_subsystem_integr_IN_ADM_ON;
        DCSN_subsystem_integrated_DW.is_ADM_ON = DCSN_subsyst_IN_ADM_ON_INACTIVE;
        DCSN_subsystem_integrated_DW.autodrive_engaged = false;
        DCSN_subsystem_integrated_DW.is_ADM_ON_INACTIVE =
          DCSN_subsystem_i_IN_ADM_STANDBY;
        DCSN_subsystem_integrated_B.adm_main_mode = ADM_STANDBY;
        VeDCSN_hmi_icon_display = NO_ICON;
        VeDCSN_hmi_msg_display = NO_MSG;
        DCSN_subsystem_integrated_DW.autodrive_ready_to_engage = false;
      }
      else
      {
        if (VbDCSN_fault_detected)
        {
          DCSN_subsystem_integrated_DW.is_c4_DCSN_subsystem_integrated =
            DCSN_subsystem_int_IN_ADM_FAULT;
          DCSN_subsystem_integrated_DW.autodrive_resume_allowed = false;
          DCSN_s_enter_internal_ADM_FAULT();
        }
      }
      break;

     default:
      DCSN_subsystem_integrate_ADM_ON(&rtb_Gain2);
      break;
    }
  }

  /* End of Chart: '<S8>/DtrmnDCSN_ADMManager' */

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant2'
   *  Constant: '<S8>/Constant3'
   *  DataTypeConversion: '<S8>/Data Type Conversion1'
   */
  if (KbDCSN_adm_main_mode_man_ctrl)
  {
    VeDCSN_adm_main_mode = (EnumDCSN_adm_main_mode)
      KeDCSN_adm_main_mode_man_value;
  }
  else
  {
    VeDCSN_adm_main_mode = DCSN_subsystem_integrated_B.adm_main_mode;
  }

  /* End of Switch: '<S8>/Switch' */

  /* RelationalOperator: '<S8>/Relational Operator' incorporates:
   *  Constant: '<S8>/Constant8'
   */
  DCSN_subsystem_integrated_B.ADM_Group.acoustic_warning_req =
    (VeDCSN_adm_main_mode == ADM_TAKEOVER_WARNING);

  /* Switch: '<S3>/Switch2' incorporates:
   *  Constant: '<S3>/aeb_switch12'
   *  Constant: '<S3>/aeb_switch8'
   *  RelationalOperator: '<S3>/Relational Operator'
   *  UnitDelay: '<S3>/Unit Delay'
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  if (KbDCSN_accs_resume_man_enbl)
  {
    VbDCSN_accs_resume = (KbDCSN_accs_resume_man_value !=
                          DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_cy03);
  }
  else
  {
    VbDCSN_accs_resume = DCSN_subsystem_integrated_DW.UnitDelay1_DSTATE_jlps;
  }

  /* End of Switch: '<S3>/Switch2' */

  /* BusCreator: '<S3>/Bus Creator2' */
  DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode = VeDCSN_adm_main_mode;
  DCSN_subsystem_integrated_B.ADM_Group.adm_hmi_msg_display =
    VeDCSN_hmi_msg_display;
  DCSN_subsystem_integrated_B.ADM_Group.adm_hmi_icon_display =
    VeDCSN_hmi_icon_display;
  DCSN_subsystem_integrated_B.ADM_Group.usr_cmd_autodrive_activate =
    VeDCSN_usr_cmd_autodrive_activate;
  DCSN_subsystem_integrated_B.ADM_Group.adm_accs_resume = VbDCSN_accs_resume;

  /* DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' */
  if (((DCSN_subsystem_integrated_B.Logic_mmx2[0]) &&
       (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator1_PrevRes <= 0)) ||
      ((!DCSN_subsystem_integrated_B.Logic_mmx2[0]) &&
       (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator1_PrevRes == 1)))
  {
    DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator1_DSTATE = ((uint16_T)0U);
  }

  if (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator1_DSTATE >= ((uint16_T)
       3000U))
  {
    DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator1_DSTATE = ((uint16_T)
      3000U);
  }
  else
  {
    if (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator1_DSTATE <=
        ((uint16_T)0U))
    {
      DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator1_DSTATE = ((uint16_T)
        0U);
    }
  }

  /* RelationalOperator: '<S14>/Relational Operator8' incorporates:
   *  Constant: '<S14>/KfDCSN_t_max_wait_cond_activate'
   *  DiscreteIntegrator: '<S14>/Discrete-Time Integrator1'
   *  Gain: '<S14>/Gain2'
   */
  DCSN_subsystem_integrated_B.RelationalOperator8 = (((real32_T)
    DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator1_DSTATE) > (100.0F *
    KfDCSN_t_max_wait_cond_activate));

  /* Logic: '<S14>/Logical Operator8' */
  DCSN_subsystem_integrated_B.LogicalOperator8 = LogicalOperator3_tmp;

  /* Logic: '<S14>/Logical Operator9' incorporates:
   *  Logic: '<S14>/Logical Operator10'
   *  UnitDelay: '<S14>/Unit Delay4'
   */
  DCSN_subsystem_integrated_B.LogicalOperator9 =
    ((!DCSN_subsystem_integrated_B.LogicalOperator8) &&
     (DCSN_subsystem_integrated_DW.UnitDelay4_DSTATE_oddz));
}

/* Update for atomic system: '<S1>/DtrmnDCSN_ADM' */
void DCSN_subsy_DtrmnDCSN_ADM_Update(void)
{
  int_T idxDelay;

  /* Update for UnitDelay: '<S8>/Unit Delay' */
  DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_k2di =
    DCSN_subsystem_integrated_B.adm_main_mode;

  /* Update for Delay: '<S7>/Delay1' incorporates:
   *  Inport: '<Root>/COMM_CANR_DataBus'
   */
  DCSN_subsystem_integrated_DW.icLoad = 0U;
  for (idxDelay = 0; idxDelay < 99; idxDelay++)
  {
    DCSN_subsystem_integrated_DW.Delay1_DSTATE[idxDelay] =
      DCSN_subsystem_integrated_DW.Delay1_DSTATE[idxDelay + 1];
  }

  DCSN_subsystem_integrated_DW.Delay1_DSTATE[99] =
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch;

  /* End of Update for Delay: '<S7>/Delay1' */

  /* Update for UnitDelay: '<S14>/Unit Delay' */
  DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_g2gu =
    VeDCSN_usr_cmd_autodrive_activate;

  /* Update for UnitDelay: '<S14>/Unit Delay2' */
  DCSN_subsystem_integrated_DW.UnitDelay2_DSTATE_khwm =
    DCSN_subsystem_integrated_B.LogicalOperator9;

  /* Update for Memory: '<S43>/Memory' */
  DCSN_subsystem_integrated_DW.Memory_PreviousInput_nozl =
    DCSN_subsystem_integrated_B.Logic[0];

  /* Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
  DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_brg5 = (uint16_T)
    (((uint32_T)DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_brg5) +
     (DCSN_subsystem_integrated_B.Logic[0] ? 1U : 0U));
  if (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_brg5 >= ((uint16_T)
       3000U))
  {
    DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_brg5 = ((uint16_T)
      3000U);
  }
  else
  {
    if (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_brg5 <=
        ((uint16_T)0U))
    {
      DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_brg5 = ((uint16_T)
        0U);
    }
  }

  DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_Pre_np0h = (int8_T)
    (DCSN_subsystem_integrated_B.Logic[0] ? 1 : 0);

  /* End of Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S14>/Unit Delay1' */
  DCSN_subsystem_integrated_DW.UnitDelay1_DSTATE_imjc =
    DCSN_subsystem_integrated_B.LogicalOperator3;

  /* Update for UnitDelay: '<S14>/Unit Delay5' */
  DCSN_subsystem_integrated_DW.UnitDelay5_DSTATE = VfDCSN_C_cond_act_time;

  /* Update for UnitDelay: '<S14>/Unit Delay3' */
  DCSN_subsystem_integrated_DW.UnitDelay3_DSTATE_m0wa =
    DCSN_subsystem_integrated_B.RelationalOperator8;

  /* Update for Memory: '<S42>/Memory' */
  DCSN_subsystem_integrated_DW.Memory_PreviousInput_p5cx =
    DCSN_subsystem_integrated_B.Logic_mmx2[0];

  /* Update for Delay: '<S12>/Delay' */
  DCSN_subsystem_integrated_DW.Delay_DSTATE_mze2[0] =
    DCSN_subsystem_integrated_DW.Delay_DSTATE_mze2[1];
  DCSN_subsystem_integrated_DW.Delay_DSTATE_mze2[1] =
    DCSN_subsystem_integrated_DW.Delay_DSTATE_mze2[2];
  DCSN_subsystem_integrated_DW.Delay_DSTATE_mze2[2] =
    DCSN_subsystem_integrated_B.Compare;

  /* Update for UnitDelay: '<S51>/UnitDelay' */
  DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_jn5k =
    DCSN_subsystem_integrated_B.CurrentTick;

  /* Update for UnitDelay: '<S27>/UnitDelay' */
  DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_kv3i =
    DCSN_subsystem_integrated_B.CurrentTick_cho5;

  /* Update for UnitDelay: '<S28>/UnitDelay' */
  DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_awwr =
    DCSN_subsystem_integrated_B.CurrentTick_hcb0;

  /* Update for UnitDelay: '<S29>/UnitDelay' */
  DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_a5my =
    DCSN_subsystem_integrated_B.CurrentTick_ilxy;

  /* Update for UnitDelay: '<S30>/UnitDelay' */
  DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_ivcp =
    DCSN_subsystem_integrated_B.CurrentTick_k4pd;

  /* Update for UnitDelay: '<S31>/UnitDelay' */
  DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_pet3 =
    DCSN_subsystem_integrated_B.CurrentTick_i1hg;

  /* Update for UnitDelay: '<S24>/UnitDelay' */
  DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_nbxp =
    DCSN_subsystem_integrated_B.CurrentTick_ad1o;

  /* Update for UnitDelay: '<S25>/UnitDelay' */
  DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_o4sd =
    DCSN_subsystem_integrated_B.CurrentTick_hziy;

  /* Update for UnitDelay: '<S26>/UnitDelay' */
  DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_pjhr =
    DCSN_subsystem_integrated_B.CurrentTick_k0eg;

  /* Update for UnitDelay: '<S3>/Unit Delay' incorporates:
   *  Constant: '<S3>/aeb_switch8'
   */
  DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_cy03 =
    KbDCSN_accs_resume_man_value;

  /* Update for UnitDelay: '<S3>/Unit Delay1' */
  DCSN_subsystem_integrated_DW.UnitDelay1_DSTATE_jlps =
    DCSN_subsystem_integrated_B.Switch;

  /* Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' */
  DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator1_DSTATE = (uint16_T)
    (((uint32_T)DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator1_DSTATE) +
     (DCSN_subsystem_integrated_B.Logic_mmx2[0] ? 1U : 0U));
  if (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator1_DSTATE >= ((uint16_T)
       3000U))
  {
    DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator1_DSTATE = ((uint16_T)
      3000U);
  }
  else
  {
    if (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator1_DSTATE <=
        ((uint16_T)0U))
    {
      DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator1_DSTATE = ((uint16_T)
        0U);
    }
  }

  DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    (DCSN_subsystem_integrated_B.Logic_mmx2[0] ? 1 : 0);

  /* End of Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S14>/Unit Delay4' */
  DCSN_subsystem_integrated_DW.UnitDelay4_DSTATE_oddz =
    DCSN_subsystem_integrated_B.LogicalOperator8;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
