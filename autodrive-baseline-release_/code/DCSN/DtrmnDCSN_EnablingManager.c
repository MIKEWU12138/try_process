/*
 * File: DtrmnDCSN_EnablingManager.c
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

#include "DtrmnDCSN_EnablingManager.h"

/* Include model header file for global data */
#include "DCSN_subsystem_integrated.h"
#include "DCSN_subsystem_integrated_private.h"

/* Named constants for Chart: '<S53>/autodrive_control_mode_manager' */
#define DCSN_su_IN_NO_ACTIVE_CHILD_k3w2 ((uint8_T)0U)
#define DCSN_subsy_IN_Autodrive_passive ((uint8_T)3U)
#define DCSN_subsy_IN_Autodrive_standby ((uint8_T)4U)
#define DCSN_subsys_IN_Autodrive_active ((uint8_T)1U)
#define DCSN_subsyst_IN_Autodrive_delay ((uint8_T)2U)

/* System initialize for atomic system: '<S1>/DtrmnDCSN_EnablingManager' */
void DtrmnDCSN_EnablingManager_Init(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S58>/Discrete-Time Integrator' */
  DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_Pre_bpg0 = 2;

  /* SystemInitialize for Chart: '<S53>/autodrive_control_mode_manager' */
  DCSN_subsystem_integrated_DW.temporalCounter_i1_lzql = 0U;
  DCSN_subsystem_integrated_DW.is_active_c5_DCSN_subsystem_int = 0U;
  DCSN_subsystem_integrated_DW.is_c5_DCSN_subsystem_integrated =
    DCSN_su_IN_NO_ACTIVE_CHILD_k3w2;
  DCSN_subsystem_integrated_DW.autodrive_wait_time = 0U;
  DCSN_subsystem_integrated_DW.time_count = 1U;
}

/* Output and update for atomic system: '<S1>/DtrmnDCSN_EnablingManager' */
void DCSN__DtrmnDCSN_EnablingManager(void)
{
  boolean_T rtb_RelationalOperator2_k0oc;
  boolean_T rtb_LogicalOperator1_n1en;
  boolean_T rtb_LogicalOperator_d5n3;
  boolean_T rtb_LogicalOperator_iod2;
  boolean_T rtb_LogicalOperator3_nblg;
  boolean_T rtb_Switch15;
  boolean_T rtb_Switch;
  EnumDCSN_autodrive_control_mode rtb_autodrive_control_mode;
  boolean_T rtb_RelationalOperator5_c5jc;
  uint32_T tmp;
  real32_T tmp_0;

  /* RelationalOperator: '<S52>/Relational Operator2' incorporates:
   *  Constant: '<S52>/Constant1'
   */
  rtb_RelationalOperator2_k0oc =
    (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode == ADM_ACTIVE);

  /* Logic: '<S52>/Logical Operator1' incorporates:
   *  Constant: '<S52>/Constant'
   *  Constant: '<S52>/Constant2'
   *  Constant: '<S52>/Constant3'
   *  Constant: '<S52>/Constant4'
   *  Constant: '<S52>/Constant5'
   *  Constant: '<S52>/Constant6'
   *  RelationalOperator: '<S52>/Relational Operator'
   *  RelationalOperator: '<S52>/Relational Operator1'
   *  RelationalOperator: '<S52>/Relational Operator3'
   *  RelationalOperator: '<S52>/Relational Operator4'
   *  RelationalOperator: '<S52>/Relational Operator5'
   *  RelationalOperator: '<S52>/Relational Operator6'
   */
  rtb_LogicalOperator1_n1en =
    (((((((DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode == ADM_STANDBY) ||
          (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode == ADM_READY)) ||
         rtb_RelationalOperator2_k0oc) ||
        (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode == ADM_STEER_OVRD))
       || (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode ==
           ADM_TAKEOVER_WARNING)) ||
      (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode == ADM_FAULT_WARNING))
     || (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode ==
         ADM_FAULT_REACTION));

  /* Switch: '<S61>/Switch2' incorporates:
   *  Constant: '<S61>/aeb_switch2'
   *  Constant: '<S61>/aeb_switch4'
   */
  if (KbDCSN_active_feature_man_ctrl)
  {
    VbDCSN_acc_feature_enable = KbDCSN_acc_man_enbl;
  }
  else
  {
    VbDCSN_acc_feature_enable = rtb_LogicalOperator1_n1en;
  }

  /* End of Switch: '<S61>/Switch2' */

  /* RelationalOperator: '<S58>/Relational Operator5' incorporates:
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  Inport: '<Root>/COMM_CANT_DataBus'
   */
  rtb_RelationalOperator5_c5jc =
    (VsCOMM_CANT_Databus.COMM_TX_Steering.ADCU_SteeringAngleEnable !=
     VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse);

  /* DiscreteIntegrator: '<S58>/Discrete-Time Integrator' */
  if ((rtb_RelationalOperator5_c5jc &&
       (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_Pre_bpg0 <= 0)) ||
      ((!rtb_RelationalOperator5_c5jc) &&
       (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_Pre_bpg0 == 1)))
  {
    DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_kkmj = ((uint16_T)0U);
  }

  if (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_kkmj >= ((uint16_T)
       3000U))
  {
    DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_kkmj = ((uint16_T)
      3000U);
  }
  else
  {
    if (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_kkmj <=
        ((uint16_T)0U))
    {
      DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_kkmj = ((uint16_T)
        0U);
    }
  }

  /* Switch: '<S58>/Switch' incorporates:
   *  Constant: '<S58>/Constant'
   *  Constant: '<S58>/Constant1'
   *  Constant: '<S58>/Constant2'
   *  Constant: '<S58>/Constant3'
   *  Constant: '<S58>/Constant4'
   *  Constant: '<S58>/Constant5'
   *  Constant: '<S58>/KfDCSN_t_max_eps_inhibit_power'
   *  DiscreteIntegrator: '<S58>/Discrete-Time Integrator'
   *  Gain: '<S58>/Gain'
   *  Logic: '<S58>/Logical Operator'
   *  RelationalOperator: '<S58>/Relational Operator'
   *  RelationalOperator: '<S58>/Relational Operator1'
   *  RelationalOperator: '<S58>/Relational Operator2'
   *  RelationalOperator: '<S58>/Relational Operator3'
   *  RelationalOperator: '<S58>/Relational Operator4'
   *  RelationalOperator: '<S58>/Relational Operator6'
   */
  if (((((DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode == ADM_ACTIVE) ||
         (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode == ADM_STEER_OVRD))
        || (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode ==
            ADM_TAKEOVER_WARNING)) ||
       (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode == ADM_FAULT_WARNING))
      || (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode ==
          ADM_FAULT_REACTION))
  {
    rtb_LogicalOperator_iod2 = (((real32_T)
      DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_kkmj) >= (100.0F *
      KfDCSN_t_max_eps_inhibit_power));
  }
  else
  {
    rtb_LogicalOperator_iod2 = false;
  }

  /* End of Switch: '<S58>/Switch' */

  /* Logic: '<S58>/Logical Operator1' incorporates:
   *  Constant: '<S58>/KbDCSN_inhibit_power_for_eps_enable'
   */
  VbDCSN_power_control_inhibit = (rtb_LogicalOperator_iod2 &&
    KbDCSN_inhibit_power_for_eps_enable);

  /* Switch: '<S61>/Switch15' incorporates:
   *  Constant: '<S61>/KbDCSN_SLEW_DriveModeComd_enbl'
   *  Constant: '<S61>/KbDCSN_SLEW_DriveModeComd_value'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   */
  if (KbDCSN_SLEW_DriveModeComd_enbl)
  {
    rtb_Switch15 = (((int32_T)KbDCSN_SLEW_DriveModeComd_value) != 0);
  }
  else
  {
    rtb_Switch15 =
      VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch;
  }

  /* End of Switch: '<S61>/Switch15' */

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Ready'
   *  Constant: '<S4>/aeb_switch16'
   *  Inport: '<Root>/EGMO_DataBus'
   */
  if (KbDCSN_use_EgmoReadyFlag)
  {
    rtb_Switch = VsEGMO_DataBus.is_ready;
  }
  else
  {
    rtb_Switch = true;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Switch: '<S61>/Switch7' incorporates:
   *  Constant: '<S59>/Constant'
   *  Constant: '<S59>/Constant1'
   *  Constant: '<S59>/Constant2'
   *  Constant: '<S59>/Constant3'
   *  Constant: '<S59>/Constant4'
   *  Constant: '<S61>/aeb_switch6'
   *  Constant: '<S61>/aeb_switch7'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  Logic: '<S59>/Logical Operator'
   *  Logic: '<S59>/Logical Operator1'
   *  Logic: '<S59>/Logical Operator2'
   *  Logic: '<S59>/Logical Operator3'
   *  Logic: '<S61>/Logical Operator'
   *  RelationalOperator: '<S59>/Relational Operator'
   *  RelationalOperator: '<S59>/Relational Operator1'
   *  RelationalOperator: '<S59>/Relational Operator2'
   *  RelationalOperator: '<S59>/Relational Operator3'
   *  RelationalOperator: '<S59>/Relational Operator4'
   */
  if (KbDCSN_power_ctrl_man_enbl)
  {
    VbDCSN_power_ctrl_enable = ((rtb_Switch15 && rtb_Switch) &&
      KbDCSN_power_ctrl_man_value);
  }
  else
  {
    VbDCSN_power_ctrl_enable =
      ((((((((DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode == ADM_ACTIVE)
             || (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode ==
                 ADM_STEER_OVRD)) ||
            (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode ==
             ADM_TAKEOVER_WARNING)) ||
           (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode ==
            ADM_FAULT_WARNING)) ||
          (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode ==
           ADM_FAULT_REACTION)) &&
         (!VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch)) &&
        (VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch)) &&
       (!VbDCSN_power_control_inhibit));
  }

  /* End of Switch: '<S61>/Switch7' */

  /* Logic: '<S4>/Logical Operator' incorporates:
   *  Constant: '<S4>/KbDCSN_aeb_usr_switch'
   *  Inport: '<Root>/AEBS_DataBus'
   */
  rtb_LogicalOperator_d5n3 = ((VsAEBS_DataBus.AEB_Data.AEB_request) &&
    KbDCSN_aeb_usr_switch);

  /* Switch: '<S61>/Switch8' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S54>/Constant1'
   *  Constant: '<S54>/Constant2'
   *  Constant: '<S54>/Constant3'
   *  Constant: '<S54>/Constant4'
   *  Constant: '<S61>/aeb_switch12'
   *  Constant: '<S61>/aeb_switch8'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  Logic: '<S54>/Logical Operator'
   *  Logic: '<S54>/Logical Operator1'
   *  Logic: '<S54>/Logical Operator2'
   *  Logic: '<S61>/Logical Operator5'
   *  RelationalOperator: '<S54>/Relational Operator'
   *  RelationalOperator: '<S54>/Relational Operator1'
   *  RelationalOperator: '<S54>/Relational Operator2'
   *  RelationalOperator: '<S54>/Relational Operator3'
   *  RelationalOperator: '<S54>/Relational Operator4'
   */
  if (KbDCSN_brake_ctrl_man_enbl)
  {
    rtb_LogicalOperator_iod2 = (rtb_Switch15 && KbDCSN_brake_ctrl_man_value);
  }
  else
  {
    rtb_LogicalOperator_iod2 =
      (((((((DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode == ADM_ACTIVE) ||
            (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode ==
             ADM_STEER_OVRD)) ||
           (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode ==
            ADM_TAKEOVER_WARNING)) ||
          (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode ==
           ADM_FAULT_WARNING)) ||
         (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode ==
          ADM_FAULT_REACTION)) &&
        (!VsCOMM_CANR_Databus.COMM_RX_Power.VCU_AccelPedalValid)) &&
       (VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch));
  }

  /* End of Switch: '<S61>/Switch8' */

  /* Logic: '<S61>/Logical Operator9' */
  VbDCSN_brake_ctrl_enable = (rtb_LogicalOperator_iod2 ||
    rtb_LogicalOperator_d5n3);

  /* Logic: '<S60>/Logical Operator' incorporates:
   *  Constant: '<S60>/Constant1'
   *  Constant: '<S60>/Constant2'
   *  Constant: '<S60>/Constant3'
   *  Constant: '<S60>/Constant4'
   *  Delay: '<S60>/Delay'
   *  Logic: '<S60>/Logical Operator1'
   *  Logic: '<S60>/Logical Operator2'
   *  RelationalOperator: '<S60>/Relational Operator1'
   *  RelationalOperator: '<S60>/Relational Operator2'
   *  RelationalOperator: '<S60>/Relational Operator3'
   *  RelationalOperator: '<S60>/Relational Operator4'
   */
  rtb_LogicalOperator_iod2 =
    ((((DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode == ADM_ACTIVE) ||
       (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode ==
        ADM_TAKEOVER_WARNING)) ||
      ((DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode == ADM_FAULT_WARNING)
       && (DCSN_subsystem_integrated_DW.Delay_DSTATE_a2ia))) ||
     ((DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode == ADM_FAULT_REACTION)
      && (DCSN_subsystem_integrated_DW.Delay_DSTATE_a2ia)));

  /* Switch: '<S60>/Switch14' incorporates:
   *  Constant: '<S60>/Constant5'
   *  Constant: '<S60>/aeb_switch17'
   *  Logic: '<S60>/Logical Operator5'
   *  Logic: '<S60>/Logical Operator6'
   *  Switch: '<S60>/Switch13'
   */
  if (KbDCSN_adm_main_mode_man_ctrl && KbDCSN_use_SLEW_override_logic)
  {
    rtb_LogicalOperator_iod2 = ((!VbDCSN_adm_steering_override) &&
      rtb_LogicalOperator_iod2);
  }

  /* End of Switch: '<S60>/Switch14' */

  /* Logic: '<S60>/Logical Operator3' incorporates:
   *  Inport: '<Root>/COMM_CANR_DataBus'
   */
  rtb_LogicalOperator3_nblg = (rtb_LogicalOperator_iod2 &&
    (VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch));

  /* Switch: '<S61>/Switch9' incorporates:
   *  Constant: '<S61>/aeb_switch13'
   *  Constant: '<S61>/aeb_switch9'
   *  Logic: '<S61>/Logical Operator4'
   */
  if (KbDCSN_steer_ctrl_man_enbl)
  {
    rtb_LogicalOperator_iod2 = ((rtb_Switch15 && rtb_Switch) &&
      KbDCSN_steer_ctrl_man_value);
  }
  else
  {
    rtb_LogicalOperator_iod2 = rtb_LogicalOperator3_nblg;
  }

  /* End of Switch: '<S61>/Switch9' */

  /* Logic: '<S4>/Logical Operator1' incorporates:
   *  Constant: '<S4>/KbDCSN_lka_usr_switch'
   *  Inport: '<Root>/LKAS_DataBus'
   */
  rtb_Switch = ((VsLKAS_DataBus.Intv_Request) && KbDCSN_lka_usr_switch);

  /* Logic: '<S61>/Logical Operator2' */
  VbDCSN_steer_ctrl_enable = (rtb_LogicalOperator_iod2 || rtb_Switch);

  /* Switch: '<S61>/Switch10' incorporates:
   *  Constant: '<S56>/KbDCSN_use_faw_l4_logic'
   *  Constant: '<S61>/aeb_switch10'
   *  Constant: '<S61>/aeb_switch14'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  Logic: '<S56>/Logical Operator1'
   *  Logic: '<S61>/Logical Operator7'
   *  Switch: '<S56>/Switch'
   */
  if (KbDCSN_gear_ctrl_man_enbl)
  {
    VbDCSN_gear_ctrl_enable = (rtb_Switch15 && KbDCSN_gear_ctrl_man_value);
  }
  else
  {
    if (KbDCSN_use_faw_l4_logic)
    {
      /* Switch: '<S56>/Switch' incorporates:
       *  Constant: '<S56>/Constant'
       *  Constant: '<S56>/Constant1'
       *  Constant: '<S56>/Constant2'
       *  Constant: '<S56>/Constant3'
       *  Constant: '<S56>/Constant4'
       *  Logic: '<S56>/Logical Operator'
       *  RelationalOperator: '<S56>/Relational Operator'
       *  RelationalOperator: '<S56>/Relational Operator1'
       *  RelationalOperator: '<S56>/Relational Operator2'
       *  RelationalOperator: '<S56>/Relational Operator3'
       *  RelationalOperator: '<S56>/Relational Operator4'
       */
      rtb_LogicalOperator_iod2 =
        (((((DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode == ADM_ACTIVE) ||
            (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode ==
             ADM_STEER_OVRD)) ||
           (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode ==
            ADM_TAKEOVER_WARNING)) ||
          (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode ==
           ADM_FAULT_WARNING)) ||
         (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode ==
          ADM_FAULT_REACTION));
    }
    else
    {
      /* Switch: '<S56>/Switch' incorporates:
       *  Constant: '<S56>/gear_ctrl_disabled'
       */
      rtb_LogicalOperator_iod2 = false;
    }

    VbDCSN_gear_ctrl_enable = (rtb_LogicalOperator_iod2 &&
      (VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch));
  }

  /* End of Switch: '<S61>/Switch10' */

  /* Switch: '<S61>/Switch11' incorporates:
   *  Constant: '<S55>/KbDCSN_use_faw_l4_logic'
   *  Constant: '<S61>/aeb_switch11'
   *  Constant: '<S61>/aeb_switch15'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  Logic: '<S55>/Logical Operator1'
   *  Logic: '<S61>/Logical Operator8'
   *  Switch: '<S55>/Switch'
   */
  if (KbDCSN_epb_ctrl_man_enbl)
  {
    VbDCSN_epb_ctrl_enable = (rtb_Switch15 && KbDCSN_epb_ctrl_man_value);
  }
  else
  {
    if (KbDCSN_use_faw_l4_logic)
    {
      /* Switch: '<S55>/Switch' incorporates:
       *  Constant: '<S55>/Constant'
       *  Constant: '<S55>/Constant1'
       *  Constant: '<S55>/Constant2'
       *  Constant: '<S55>/Constant3'
       *  Constant: '<S55>/Constant4'
       *  Logic: '<S55>/Logical Operator'
       *  RelationalOperator: '<S55>/Relational Operator'
       *  RelationalOperator: '<S55>/Relational Operator1'
       *  RelationalOperator: '<S55>/Relational Operator2'
       *  RelationalOperator: '<S55>/Relational Operator3'
       *  RelationalOperator: '<S55>/Relational Operator4'
       */
      rtb_LogicalOperator_iod2 =
        (((((DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode == ADM_ACTIVE) ||
            (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode ==
             ADM_STEER_OVRD)) ||
           (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode ==
            ADM_TAKEOVER_WARNING)) ||
          (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode ==
           ADM_FAULT_WARNING)) ||
         (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode ==
          ADM_FAULT_REACTION));
    }
    else
    {
      /* Switch: '<S55>/Switch' incorporates:
       *  Constant: '<S55>/epb_ctrl_disabled'
       */
      rtb_LogicalOperator_iod2 = false;
    }

    VbDCSN_epb_ctrl_enable = (rtb_LogicalOperator_iod2 &&
      (VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch));
  }

  /* End of Switch: '<S61>/Switch11' */

  /* Switch: '<S61>/Switch' incorporates:
   *  Constant: '<S61>/aeb_switch1'
   *  Constant: '<S61>/aeb_switch4'
   */
  if (KbDCSN_active_feature_man_ctrl)
  {
    VbDCSN_lcc_feature_enable = KbDCSN_lcc_man_enbl;
  }
  else
  {
    VbDCSN_lcc_feature_enable = rtb_LogicalOperator1_n1en;
  }

  /* End of Switch: '<S61>/Switch' */

  /* Switch: '<S61>/Switch1' incorporates:
   *  Constant: '<S52>/KbDCSN_acla_usr_switch'
   *  Constant: '<S61>/aeb_switch3'
   *  Constant: '<S61>/aeb_switch4'
   *  Logic: '<S52>/Logical Operator'
   */
  if (KbDCSN_active_feature_man_ctrl)
  {
    VbDCSN_alca_feature_enable = KbDCSN_alca_man_enbl;
  }
  else
  {
    VbDCSN_alca_feature_enable = (rtb_RelationalOperator2_k0oc &&
      KbDCSN_alca_usr_switch);
  }

  /* End of Switch: '<S61>/Switch1' */

  /* Switch: '<S61>/Switch3' incorporates:
   *  Constant: '<S4>/KbDCSN_aeb_usr_switch'
   *  Constant: '<S61>/aeb_switch'
   *  Constant: '<S61>/aeb_switch5'
   *  Logic: '<S57>/Logical Operator1'
   */
  if (KbDCSN_passive_feature_man_ctrl)
  {
    VbDCSN_aeb_feature_enable = KbDCSN_aeb_man_enbl;
  }
  else
  {
    VbDCSN_aeb_feature_enable = (KbDCSN_aeb_usr_switch &&
      VbDCSN_initialization_finished);
  }

  /* End of Switch: '<S61>/Switch3' */

  /* Switch: '<S61>/Switch4' incorporates:
   *  Constant: '<S4>/KbDCSN_aeb_usr_switch'
   *  Constant: '<S4>/KbDCSN_fcw_usr_switch'
   *  Constant: '<S61>/aeb_switch5'
   *  Constant: '<S61>/fcw_switch'
   *  Logic: '<S57>/Logical Operator'
   *  Logic: '<S57>/Logical Operator2'
   */
  if (KbDCSN_passive_feature_man_ctrl)
  {
    VbDCSN_fcw_feature_enable = KbDCSN_fcw_man_enbl;
  }
  else
  {
    VbDCSN_fcw_feature_enable = ((KbDCSN_aeb_usr_switch || KbDCSN_fcw_usr_switch)
      && VbDCSN_initialization_finished);
  }

  /* End of Switch: '<S61>/Switch4' */

  /* Switch: '<S61>/Switch5' incorporates:
   *  Constant: '<S4>/KbDCSN_lcw_usr_switch'
   *  Constant: '<S61>/aeb_switch5'
   *  Constant: '<S61>/lcw_switch'
   *  Logic: '<S57>/Logical Operator3'
   */
  if (KbDCSN_passive_feature_man_ctrl)
  {
    VbDCSN_lcw_feature_enable = KbDCSN_lcw_man_enbl;
  }
  else
  {
    VbDCSN_lcw_feature_enable = (KbDCSN_lcw_usr_switch &&
      VbDCSN_initialization_finished);
  }

  /* End of Switch: '<S61>/Switch5' */

  /* Switch: '<S61>/Switch6' incorporates:
   *  Constant: '<S4>/KbDCSN_ldw_usr_switch'
   *  Constant: '<S61>/aeb_switch5'
   *  Constant: '<S61>/ldw_switch'
   *  Logic: '<S57>/Logical Operator4'
   */
  if (KbDCSN_passive_feature_man_ctrl)
  {
    VbDCSN_ldw_feature_enable = KbDCSN_ldw_man_enbl;
  }
  else
  {
    VbDCSN_ldw_feature_enable = (KbDCSN_ldw_usr_switch &&
      VbDCSN_initialization_finished);
  }

  /* End of Switch: '<S61>/Switch6' */

  /* Switch: '<S61>/Switch13' incorporates:
   *  Constant: '<S4>/KbDCSN_lka_usr_switch'
   *  Constant: '<S57>/Constant'
   *  Constant: '<S57>/Constant1'
   *  Constant: '<S57>/Constant2'
   *  Constant: '<S57>/Constant4'
   *  Constant: '<S61>/aeb_switch5'
   *  Constant: '<S61>/ldw_switch3'
   *  Logic: '<S57>/Logical Operator5'
   *  Logic: '<S57>/Logical Operator6'
   *  RelationalOperator: '<S57>/Relational Operator'
   *  RelationalOperator: '<S57>/Relational Operator1'
   *  RelationalOperator: '<S57>/Relational Operator2'
   *  RelationalOperator: '<S57>/Relational Operator4'
   */
  if (KbDCSN_passive_feature_man_ctrl)
  {
    VbDCSN_lka_feature_enable = KbDCSN_lka_man_enbl;
  }
  else
  {
    VbDCSN_lka_feature_enable = ((KbDCSN_lka_usr_switch &&
      VbDCSN_initialization_finished) &&
      ((((DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode == ADM_OFF) ||
         (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode == ADM_STANDBY)) ||
        (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode == ADM_READY)) ||
       (DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode ==
        ADM_FAULT_DETECTED)));
  }

  /* End of Switch: '<S61>/Switch13' */

  /* Switch: '<S61>/Switch14' incorporates:
   *  Constant: '<S4>/KbDCSN_bsd_usr_switch'
   *  Constant: '<S61>/aeb_switch5'
   *  Constant: '<S61>/ldw_switch4'
   *  Logic: '<S57>/Logical Operator7'
   */
  if (KbDCSN_passive_feature_man_ctrl)
  {
    VbDCSN_bsd_feature_enable = KbDCSN_bsd_man_enbl;
  }
  else
  {
    VbDCSN_bsd_feature_enable = (KbDCSN_bsd_usr_switch &&
      VbDCSN_initialization_finished);
  }

  /* End of Switch: '<S61>/Switch14' */

  /* Switch: '<S61>/Switch17' incorporates:
   *  Constant: '<S4>/KbDCSN_lca_usr_switch'
   *  Constant: '<S61>/aeb_switch5'
   *  Constant: '<S61>/ldw_switch5'
   *  Logic: '<S57>/Logical Operator8'
   */
  if (KbDCSN_passive_feature_man_ctrl)
  {
    VbDCSN_lca_feature_enable = KbDCSN_lca_man_enbl;
  }
  else
  {
    VbDCSN_lca_feature_enable = (KbDCSN_lca_usr_switch &&
      VbDCSN_initialization_finished);
  }

  /* End of Switch: '<S61>/Switch17' */

  /* Switch: '<S61>/Switch18' incorporates:
   *  Constant: '<S4>/KbDCSN_rcta_usr_switch'
   *  Constant: '<S61>/aeb_switch5'
   *  Constant: '<S61>/ldw_switch6'
   *  Logic: '<S57>/Logical Operator9'
   */
  if (KbDCSN_passive_feature_man_ctrl)
  {
    VbDCSN_rcta_feature_enable = KbDCSN_rcta_man_enbl;
  }
  else
  {
    VbDCSN_rcta_feature_enable = (KbDCSN_rcta_usr_switch &&
      VbDCSN_initialization_finished);
  }

  /* End of Switch: '<S61>/Switch18' */

  /* Switch: '<S61>/Switch19' incorporates:
   *  Constant: '<S4>/KbDCSN_fcta_usr_switch'
   *  Constant: '<S61>/aeb_switch5'
   *  Constant: '<S61>/ldw_switch7'
   *  Logic: '<S57>/Logical Operator10'
   */
  if (KbDCSN_passive_feature_man_ctrl)
  {
    VbDCSN_fcta_feature_enable = KbDCSN_fcta_man_enbl;
  }
  else
  {
    VbDCSN_fcta_feature_enable = (KbDCSN_fcta_usr_switch &&
      VbDCSN_initialization_finished);
  }

  /* End of Switch: '<S61>/Switch19' */

  /* Switch: '<S61>/Switch20' incorporates:
   *  Constant: '<S4>/KbDCSN_dow_usr_switch'
   *  Constant: '<S61>/aeb_switch5'
   *  Constant: '<S61>/ldw_switch8'
   *  Logic: '<S57>/Logical Operator11'
   */
  if (KbDCSN_passive_feature_man_ctrl)
  {
    VbDCSN_dow_feature_enable = KbDCSN_dow_man_enbl;
  }
  else
  {
    VbDCSN_dow_feature_enable = (KbDCSN_dow_usr_switch &&
      VbDCSN_initialization_finished);
  }

  /* End of Switch: '<S61>/Switch20' */

  /* Switch: '<S64>/Switch1' incorporates:
   *  Constant: '<S64>/Constant3'
   *  Constant: '<S64>/Constant6'
   *  Constant: '<S64>/KbDCSN_use_faw_l4_logic1'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  RelationalOperator: '<S64>/Relational Operator2'
   */
  if (KbDCSN_use_faw_l4_logic)
  {
    rtb_RelationalOperator2_k0oc =
      (VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutoToManualTips ==
       ((uint16_T)0U));
  }
  else
  {
    rtb_RelationalOperator2_k0oc = true;
  }

  /* End of Switch: '<S64>/Switch1' */

  /* Chart: '<S53>/autodrive_control_mode_manager' incorporates:
   *  Constant: '<S53>/KfDCSN_t_autodrive_max_wait_time'
   *  Constant: '<S63>/KbDCSN_use_faw_l4_logic1'
   *  Gain: '<S53>/Gain1'
   *  Gain: '<S53>/Gain2'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  Switch: '<S63>/Switch'
   */
  if (((uint32_T)DCSN_subsystem_integrated_DW.temporalCounter_i1_lzql) < 65535U)
  {
    DCSN_subsystem_integrated_DW.temporalCounter_i1_lzql = (uint16_T)((int32_T)
      (((int32_T)DCSN_subsystem_integrated_DW.temporalCounter_i1_lzql) + 1));
  }

  if (((uint32_T)DCSN_subsystem_integrated_DW.is_active_c5_DCSN_subsystem_int) ==
      0U)
  {
    DCSN_subsystem_integrated_DW.is_active_c5_DCSN_subsystem_int = 1U;
    DCSN_subsystem_integrated_DW.is_c5_DCSN_subsystem_integrated =
      DCSN_subsy_IN_Autodrive_passive;
    rtb_autodrive_control_mode = AUTODRIVE_PASIV;
  }
  else
  {
    switch (DCSN_subsystem_integrated_DW.is_c5_DCSN_subsystem_integrated)
    {
     case DCSN_subsys_IN_Autodrive_active:
      rtb_autodrive_control_mode = AUTODRIVE_ACTIVATED;
      if (((((((uint32_T)DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode) ==
              ADM_OFF) || (((uint32_T)
                            DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode)
                           == ADM_STANDBY)) || (((uint32_T)
              DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode) == ADM_READY))
           || (((uint32_T)DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode) ==
               ADM_FAULT_DETECTED)) ||
          (!VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveActiveStatus))
      {
        DCSN_subsystem_integrated_DW.is_c5_DCSN_subsystem_integrated =
          DCSN_subsy_IN_Autodrive_passive;
        rtb_autodrive_control_mode = AUTODRIVE_PASIV;
      }
      break;

     case DCSN_subsyst_IN_Autodrive_delay:
      rtb_autodrive_control_mode = AUTODRIVE_DELAY;
      if (((((((uint32_T)DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode) ==
              ADM_OFF) || (((uint32_T)
                            DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode)
                           == ADM_STANDBY)) || (((uint32_T)
              DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode) == ADM_READY))
           || (((uint32_T)DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode) ==
               ADM_FAULT_DETECTED)) || (!rtb_RelationalOperator2_k0oc))
      {
        DCSN_subsystem_integrated_DW.is_c5_DCSN_subsystem_integrated =
          DCSN_subsy_IN_Autodrive_passive;
        rtb_autodrive_control_mode = AUTODRIVE_PASIV;
      }
      else
      {
        if (KbDCSN_use_faw_l4_logic)
        {
          /* Switch: '<S63>/Switch' incorporates:
           *  Constant: '<S63>/KfDCSN_t_autodrive_control_mode_delay'
           */
          tmp_0 = KfDCSN_t_autodrive_control_mode_delay;
        }
        else
        {
          /* Switch: '<S63>/Switch' incorporates:
           *  Constant: '<S63>/Other Project'
           */
          tmp_0 = 0.0F;
        }

        if (DCSN_subsystem_integrated_DW.temporalCounter_i1_lzql >= ((uint16_T)
             ((real32_T)(100.0F * tmp_0))))
        {
          DCSN_subsystem_integrated_DW.is_c5_DCSN_subsystem_integrated =
            DCSN_subsy_IN_Autodrive_standby;
          rtb_autodrive_control_mode = AUTODRIVE_ACTIVATING;
          DCSN_subsystem_integrated_DW.autodrive_wait_time = 0U;
        }
      }
      break;

     case DCSN_subsy_IN_Autodrive_passive:
      rtb_autodrive_control_mode = AUTODRIVE_PASIV;
      if ((((((((uint32_T)DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode) ==
               ADM_ACTIVE) || (((uint32_T)
                DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode) ==
               ADM_STEER_OVRD)) || (((uint32_T)
               DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode) ==
              ADM_TAKEOVER_WARNING)) || (((uint32_T)
              DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode) ==
             ADM_FAULT_WARNING)) || (((uint32_T)
             DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode) ==
            ADM_FAULT_REACTION)) && rtb_RelationalOperator2_k0oc)
      {
        DCSN_subsystem_integrated_DW.is_c5_DCSN_subsystem_integrated =
          DCSN_subsyst_IN_Autodrive_delay;
        DCSN_subsystem_integrated_DW.temporalCounter_i1_lzql = 0U;
        rtb_autodrive_control_mode = AUTODRIVE_DELAY;
      }
      break;

     default:
      rtb_autodrive_control_mode = AUTODRIVE_ACTIVATING;
      if (VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveActiveStatus)
      {
        DCSN_subsystem_integrated_DW.is_c5_DCSN_subsystem_integrated =
          DCSN_subsys_IN_Autodrive_active;
        rtb_autodrive_control_mode = AUTODRIVE_ACTIVATED;
      }
      else if (((real32_T)DCSN_subsystem_integrated_DW.autodrive_wait_time) >=
               (100.0F * KfDCSN_t_autodrive_max_wait_time))
      {
        DCSN_subsystem_integrated_DW.is_c5_DCSN_subsystem_integrated =
          DCSN_subsyst_IN_Autodrive_delay;
        DCSN_subsystem_integrated_DW.temporalCounter_i1_lzql = 0U;
        rtb_autodrive_control_mode = AUTODRIVE_DELAY;
      }
      else if (((((((uint32_T)
                    DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode) ==
                   ADM_OFF) || (((uint32_T)
                    DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode) ==
                   ADM_STANDBY)) || (((uint32_T)
                   DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode) ==
                  ADM_READY)) || (((uint32_T)
                  DCSN_subsystem_integrated_B.ADM_Group.adm_main_mode) ==
                 ADM_FAULT_DETECTED)) || (!rtb_RelationalOperator2_k0oc))
      {
        DCSN_subsystem_integrated_DW.is_c5_DCSN_subsystem_integrated =
          DCSN_subsy_IN_Autodrive_passive;
        rtb_autodrive_control_mode = AUTODRIVE_PASIV;
      }
      else
      {
        tmp = ((uint32_T)DCSN_subsystem_integrated_DW.autodrive_wait_time) +
          ((uint32_T)DCSN_subsystem_integrated_DW.time_count);
        if (tmp > 65535U)
        {
          tmp = 65535U;
        }

        DCSN_subsystem_integrated_DW.autodrive_wait_time = (uint16_T)tmp;
      }
      break;
    }
  }

  /* End of Chart: '<S53>/autodrive_control_mode_manager' */

  /* Switch: '<S61>/Switch16' incorporates:
   *  Constant: '<S53>/KbDCSN_use_SLEW_switch_control_mode'
   *  Constant: '<S61>/Constant'
   *  Constant: '<S61>/ldw_switch1'
   *  Logic: '<S61>/Logical Operator1'
   *  Switch: '<S53>/Switch1'
   *  Switch: '<S61>/Switch12'
   */
  if (rtb_LogicalOperator_d5n3 || rtb_Switch)
  {
    VeDCSN_autodrive_control_mode = AUTODRIVE_ACTIVATED;
  }
  else if (KbDCSN_control_mode_man_enbl)
  {
    /* Switch: '<S61>/Switch12' incorporates:
     *  Constant: '<S61>/ldw_switch2'
     *  DataTypeConversion: '<S61>/Data Type Conversion1'
     */
    VeDCSN_autodrive_control_mode = (EnumDCSN_autodrive_control_mode)
      KeDCSN_control_mode_man_value;
  }
  else if (((real32_T)(KbDCSN_use_SLEW_switch_control_mode ? 1.0F : 0.0F)) >
           0.0F)
  {
    /* Switch: '<S53>/Switch2' incorporates:
     *  Constant: '<S53>/Constant'
     *  Constant: '<S53>/Constant1'
     *  Inport: '<Root>/COMM_CANR_DataBus'
     *  Switch: '<S53>/Switch1'
     *  Switch: '<S61>/Switch12'
     */
    if (VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch)
    {
      VeDCSN_autodrive_control_mode = AUTODRIVE_ACTIVATING;
    }
    else
    {
      VeDCSN_autodrive_control_mode = AUTODRIVE_PASIV;
    }

    /* End of Switch: '<S53>/Switch2' */
  }
  else
  {
    VeDCSN_autodrive_control_mode = rtb_autodrive_control_mode;
  }

  /* End of Switch: '<S61>/Switch16' */

  /* BusCreator: '<S61>/Bus Creator' */
  DCSN_subsystem_integrated_B.EnablingFlags_Group.power_ctrl_enable =
    VbDCSN_power_ctrl_enable;
  DCSN_subsystem_integrated_B.EnablingFlags_Group.brake_ctrl_enable =
    VbDCSN_brake_ctrl_enable;
  DCSN_subsystem_integrated_B.EnablingFlags_Group.steer_ctrl_enable =
    VbDCSN_steer_ctrl_enable;
  DCSN_subsystem_integrated_B.EnablingFlags_Group.gear_ctrl_enable =
    VbDCSN_gear_ctrl_enable;
  DCSN_subsystem_integrated_B.EnablingFlags_Group.epb_ctrl_enable =
    VbDCSN_epb_ctrl_enable;
  DCSN_subsystem_integrated_B.EnablingFlags_Group.acc_feature_enable =
    VbDCSN_acc_feature_enable;
  DCSN_subsystem_integrated_B.EnablingFlags_Group.lcc_feature_enable =
    VbDCSN_lcc_feature_enable;
  DCSN_subsystem_integrated_B.EnablingFlags_Group.alca_feature_enable =
    VbDCSN_alca_feature_enable;
  DCSN_subsystem_integrated_B.EnablingFlags_Group.aeb_feature_enable =
    VbDCSN_aeb_feature_enable;
  DCSN_subsystem_integrated_B.EnablingFlags_Group.fcw_feature_enable =
    VbDCSN_fcw_feature_enable;
  DCSN_subsystem_integrated_B.EnablingFlags_Group.lcw_feature_enable =
    VbDCSN_lcw_feature_enable;
  DCSN_subsystem_integrated_B.EnablingFlags_Group.ldw_feature_enable =
    VbDCSN_ldw_feature_enable;
  DCSN_subsystem_integrated_B.EnablingFlags_Group.lka_feature_enable =
    VbDCSN_lka_feature_enable;
  DCSN_subsystem_integrated_B.EnablingFlags_Group.bsd_feature_enable =
    VbDCSN_bsd_feature_enable;
  DCSN_subsystem_integrated_B.EnablingFlags_Group.lca_feature_enable =
    VbDCSN_lca_feature_enable;
  DCSN_subsystem_integrated_B.EnablingFlags_Group.rcta_feature_enable =
    VbDCSN_rcta_feature_enable;
  DCSN_subsystem_integrated_B.EnablingFlags_Group.fcta_feature_enable =
    VbDCSN_fcta_feature_enable;
  DCSN_subsystem_integrated_B.EnablingFlags_Group.dow_feature_enable =
    VbDCSN_dow_feature_enable;
  DCSN_subsystem_integrated_B.EnablingFlags_Group.autodrive_control_mode =
    VeDCSN_autodrive_control_mode;

  /* Switch: '<S62>/Switch' incorporates:
   *  Constant: '<S62>/Constant5'
   *  Constant: '<S62>/Constant6'
   *  Constant: '<S62>/KbDCSN_use_faw_l4_logic1'
   *  Inport: '<Root>/COMM_CANR_DataBus'
   *  Logic: '<S62>/Logical Operator'
   *  Logic: '<S62>/Logical Operator1'
   *  Logic: '<S62>/Logical Operator2'
   *  RelationalOperator: '<S62>/Relational Operator2'
   *  UnitDelay: '<S62>/Unit Delay'
   */
  if ((rtb_autodrive_control_mode == AUTODRIVE_ACTIVATED) &&
      KbDCSN_use_faw_l4_logic)
  {
    DCSN_subsystem_integrated_B.Switch =
      ((VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_HighBeamSwitch) &&
       (!DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_bhq0));
  }
  else
  {
    DCSN_subsystem_integrated_B.Switch = false;
  }

  /* End of Switch: '<S62>/Switch' */

  /* Update for DiscreteIntegrator: '<S58>/Discrete-Time Integrator' */
  DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_kkmj = (uint16_T)
    (((uint32_T)DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_kkmj) +
     (rtb_RelationalOperator5_c5jc ? 1U : 0U));
  if (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_kkmj >= ((uint16_T)
       3000U))
  {
    DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_kkmj = ((uint16_T)
      3000U);
  }
  else
  {
    if (DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_kkmj <=
        ((uint16_T)0U))
    {
      DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_DST_kkmj = ((uint16_T)
        0U);
    }
  }

  DCSN_subsystem_integrated_DW.DiscreteTimeIntegrator_Pre_bpg0 = (int8_T)
    (rtb_RelationalOperator5_c5jc ? 1 : 0);

  /* End of Update for DiscreteIntegrator: '<S58>/Discrete-Time Integrator' */

  /* Update for Delay: '<S60>/Delay' */
  DCSN_subsystem_integrated_DW.Delay_DSTATE_a2ia = rtb_LogicalOperator3_nblg;

  /* Update for UnitDelay: '<S62>/Unit Delay' incorporates:
   *  Inport: '<Root>/COMM_CANR_DataBus'
   */
  DCSN_subsystem_integrated_DW.UnitDelay_DSTATE_bhq0 =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_HighBeamSwitch;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
